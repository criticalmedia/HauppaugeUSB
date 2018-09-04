#include "log.h"
#include "baseif.h"
#include "registryif.h"
#include "USBif.h"
#include "FX2Device.h"
#include "receiver_ADV7842.h"
#include "encoderDev_DXT.h"
#include "audio_CX2081x.h"
#include "audio_CS8416.h"

#include "device_EDID.h"

#include <stdint.h>
#include <unistd.h>
#include <signal.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>

/*
TODO:

145210
145410
157210
157220
157320

USB\VID_2040&PID_E500 ; Siena1 -01,-03
USB\VID_2040&PID_E501 ; Siena1 -05
USB\VID_2040&PID_E502 ; Siena1 -05b or later
USB\VID_2040&PID_E50A ; StreamEez
USB\VID_2040&PID_E504 ; Siena2-02 w/SPDIF, Green LEDs
USB\VID_2040&PID_E554 ; Siena2-02 w/SPDIF, Blue LEDs

USB\VID_2040&PID_E514 ; Siena2-02 w/SPDIF, Alt bling
USB\VID_2040&PID_E524 ; Siena2-02
USB\VID_2040&PID_E52C ; Siena2 StreamEez

USB\VID_2040&PID_E505 ; Siena2-05a w/SPDIF
USB\VID_2040&PID_E515 ; Siena2-05a w/SPDIF, Alt bling
USB\VID_2040&PID_E525 ; Siena2-05a
*/

#define kMyVendorID 0x2040
#define kMyProductID 0xE585

typedef enum {
	DEV_DONE,
	DEV_RESTART,
	DEV_ERROR
} dev_ret_t;

static bool showHelp = false;
static receiverInput_t rxInput = RXI_HDMI;
static const char *outputFile = NULL;
static bool usePipe = false;
static float enforceAR = 0;
static bool audioSPDIF = false;
static bool audioBoost = false;
static int audiorate = 44100;
static int outputFD = -1;

static const char *usage =
"\n"
"Usage: %s [-hcspb] [-a <aspect_ratio>] -f <output_file>\n"
"\n"
" Arguments:\n"
"   -h - this help\n"
"  Mode:\n"
"   default: HDMI\n"
"   -c - component\n"
"   -s - composite\n"
"  Audio source:\n"
"	default: auto, depending on mode\n"
"	-S - force S/PDIF input when recording from HDMI if supported by hardware\n"
"  Output:\n"
"   default: stdout\n"
"   -f <output_file> - file\n"
"   -p - use named pipe instead\n"
"   only MPEG-2 transport stream is available now\n"
"  Other options:\n"
"   -a <aspect_ratio> - enforce aspect ratio\n"
"     examples: '-a 1.33' or '-a 4/3'\n"
"   -b - increase audio input gain\n"
"   -r - audio rate: 16000, 32000, 44100, 48000, 96000, 192000 (only for component)"
"\n"
" Note:\n"
"Capture should be stopped by sending SIGINT (Ctrl-C from terminal).\n"
"\n";

static void evtInit() {
	sigset_t ss;
	sigemptyset(&ss);
	sigaddset(&ss, SIGINT);
	pthread_sigmask(SIG_BLOCK, &ss, NULL);
}

static int evtWait() {
	sigset_t ss;
	sigemptyset(&ss);
	sigaddset(&ss, SIGINT);
	int s;
	if(sigwait(&ss, &s) != 0) return 0;
	return s;
}

static int parseArgs(int argc, char * const argv[]) {
	int opt;
	while((opt = getopt(argc, argv, "hcsSf:pa:br:")) != -1) {
		switch(opt) {
			case 'h':
				showHelp = true;
				break;
			case 'c':
				rxInput = RXI_COMP;
				break;
			case 's':
				rxInput = RXI_CVBS;
				break;
			case 'S':
				audioSPDIF = true;
				break;
			case 'f':
				outputFile = optarg;
				break;
			case 'p':
				usePipe = true;
				break;
			case 'a': {
				float a, b;
				unsigned n = sscanf(optarg, "%f/%f", &a, &b);
				switch(n) {
					case 1:
						enforceAR = a;
						break;
					case 2:
						enforceAR = a / b;
						break;
					default:
						wrapLogError("Bad aspect ratio value: %s", optarg);
						exit(1);
				}
			} break;

			case 'r':{
				audiorate = atoi(optarg);
				break;
			}
			case 'b':
				audioBoost = true;
				break;
		}
	}
	return optind;
}

static dev_ret_t useDevice(USBWrapper_t &usb) {
	FX2Device_t fx2(usb);
	if(!fx2.isUSBHighSpeed()) {
		fx2.stopCPU();
		fx2.loadFirmware();
		fx2.startCPU();
		usb.close();
		wrapSleep_ms(1000);
		return DEV_RESTART;
	}

	wrapLogDebug("PORT_A: [%02X] %02X", fx2.getPortDir(FX2_PORT_A), fx2.getPortState(FX2_PORT_A));
	wrapLogDebug("PORT_B: [%02X] %02X", fx2.getPortDir(FX2_PORT_B), fx2.getPortState(FX2_PORT_B));
	wrapLogDebug("PORT_C: [%02X] %02X", fx2.getPortDir(FX2_PORT_C), fx2.getPortState(FX2_PORT_C));
	wrapLogDebug("PORT_D: [%02X] %02X", fx2.getPortDir(FX2_PORT_D), fx2.getPortState(FX2_PORT_D));
	wrapLogDebug("PORT_E: [%02X] %02X", fx2.getPortDir(FX2_PORT_E), fx2.getPortState(FX2_PORT_E));
	wrapLogDebug("CTL_PORTS: [%02X] %02X", fx2.getPortDir(FX2_CTL_PORTS), fx2.getPortState(FX2_CTL_PORTS));

	// reset CS5340, it will be set back by encDev.init()
	fx2.setPortStateBits(FX2_CTL_PORTS, 0, 0x10);

	encoderDev_DXT_t encDev(fx2);
	if(!encDev.init()) {
		wrapLogError("Encoder init FAILED");
		return DEV_DONE;
	}

	wrapLogDebug("PORT_A: %02X", fx2.getPortState(FX2_PORT_A));
	wrapLogDebug("PORT_E: %02X", fx2.getPortState(FX2_PORT_E));
	wrapSleep_ms(100);
	receiver_ADV7842_t rxDev(fx2);
	rxDev.setEDID(EDID_default, sizeof(EDID_default), EDID_default_SPAloc);
	rxDev.init();

	encDev.setOutputFD(outputFD);

	audio_CX2081x _audio_CX2081x(fx2);

	switch(rxInput) {

		case RXI_COMP: {

			if(audioBoost) {
				fx2.setPortStateBits(FX2_PORT_E, 0x18, 0x00);
			} else {
				fx2.setPortStateBits(FX2_PORT_E, 0x08, 0x10);
			}

			rxDev.setInput(rxInput);
			wrapSleep_ms(1000);
			rxDev.showInfo();
			encDev.showInfo();
			if(!rxDev.hasInputSignal()) {
				wrapLogError("No input signal");
				return DEV_DONE;
			}

			receiverOutputParams_t vp;
			if(!rxDev.getOutputParams(&vp)) {
				wrapLogError("Can't determine video mode");
				return DEV_DONE;
			}
			// rxDev.getOutputParams() changes a mode of the receiver
			// in case of a component signal
//			wrapSleep_ms(1000);

			float aspectRatio = vp.aspectRatio;
			if(enforceAR != 0) aspectRatio = enforceAR;
			if(!encDev.setInputFormat(ENCS_COMP, ENCAIF_AUTO, vp.width, vp.height, vp.interlaced, vp.vFreq, aspectRatio, audiorate)) {
				wrapLogError("Can't set video mode");
				return DEV_DONE;
			}
			if(
				(vp.height == 480) && (roundf(vp.vFreq) == 60) && vp.interlaced ||
				(vp.height == 576) && (roundf(vp.vFreq) == 50) && vp.interlaced
			) {
				rxDev.setOutputBusMode(RXOBM_656_10_DC);
			} else {
				rxDev.setOutputBusMode(RXOBM_422_10x2);
			}
			_audio_CX2081x.init();

		} break;

		case RXI_CVBS: {

			if(audioBoost) {
				fx2.setPortStateBits(FX2_PORT_E, 0x18, 0x00);
			} else {
				fx2.setPortStateBits(FX2_PORT_E, 0x08, 0x10);
			}

			rxDev.setInput(rxInput);
			wrapSleep_ms(1000);
			rxDev.showInfo();
			encDev.showInfo();
			if(!rxDev.hasInputSignal()) {
				wrapLogError("No input signal");
				return DEV_DONE;
			}

			receiverOutputParams_t vp;
			if(!rxDev.getOutputParams(&vp)) {
				wrapLogError("Can't determine video mode");
				return DEV_DONE;
			}

			float aspectRatio = vp.aspectRatio;
			if(enforceAR != 0) aspectRatio = enforceAR;
			if(!encDev.setInputFormat(ENCS_CVBS, ENCAIF_AUTO, vp.width, vp.height, vp.interlaced, vp.vFreq, aspectRatio, 0)) {
				wrapLogError("Can't set video mode");
				return DEV_DONE;
			}
			rxDev.setOutputBusMode(RXOBM_656_10);

		} break;

		default: {

			// check that CS8416 part is installed and supported by this device
			if (audioSPDIF) {
				try {
					audio_CS8416  _audio_CS8416(fx2);
					_audio_CS8416.reset(audio_CS8416::AudioInput::OPTICAL);
				}
				catch (std::runtime_error &e) {
					wrapLogDebug("Can't initialize CS8416 part. S/PDIF input won't be available");
					audioSPDIF = false;
				}
			}

			// init CS8416 optical receiver if detected
			if(audioSPDIF) {
				fx2.setPortStateBits(FX2_PORT_E, 0x10, 0x00); // switch audio mux to SPDIF
				wrapLogDebug("audio input set to S/PDIF");
			} else {
				fx2.setPortStateBits(FX2_PORT_E, 0x00, 0x18); // ... or to HDMI
				wrapLogDebug("audio input set to HDMI");
			}

			rxDev.setInput(RXI_HDMI);
			wrapLogDebug("PORT_A: %02X", fx2.getPortState(FX2_PORT_A));
			wrapLogDebug("PORT_E: %02X", fx2.getPortState(FX2_PORT_E));
			wrapSleep_ms(1000);
			rxDev.showInfo();
			encDev.showInfo();
			if(!rxDev.hasInputSignal()) {
				wrapLogError("No input signal");
				return DEV_DONE;
			}

			receiverAudioParams_t ap;
			ap.sampleRate = 0; // default
			rxDev.getAudioParams(&ap);

			int vic = rxDev.getHDMIFormat();
			if(vic <= 0 || !encDev.setHDMIFormat(vic, ap.sampleRate)) {
				receiverHDMIParams_t vp;
				if(!rxDev.getHDMIParams(&vp)) {
					wrapLogError("Can't determine video mode");
					return DEV_DONE;
				}
				if(!encDev.setInputFormat(ENCS_HDMI, audioSPDIF ? ENCAIF_AC3 : ENCAIF_AUTO, vp.width, vp.height, vp.interlaced, vp.vFreq, 16.0f/9, ap.sampleRate)) {
					wrapLogError("Can't set video mode");
					return DEV_DONE;
				}
				// there are should not be any such modes in DMT... Or maybe bad InfoFrame?
				rxDev.setOutputBusMode(RXOBM_422_10x2);
			} else {
				switch(vic) { // TODO: will be moved into device_t class soon
					case 6:
					case 7:
					case 21:
					case 22:
						rxDev.setOutputBusMode(RXOBM_656_10_DC);
						break;
					default:
						rxDev.setOutputBusMode(RXOBM_422_10x2);
				}
			}
			if(enforceAR != 0) encDev.setHDMIAR(enforceAR);

		}

	}

	if(!encDev.startCapture()) {
		wrapLogError("Encoder start capture FAILED");
		return DEV_DONE;
	}
	wrapLogDebug("PORT_A: [%02X] %02X", fx2.getPortDir(FX2_PORT_A), fx2.getPortState(FX2_PORT_A));
	wrapLogDebug("PORT_B: [%02X] %02X", fx2.getPortDir(FX2_PORT_B), fx2.getPortState(FX2_PORT_B));
	wrapLogDebug("PORT_C: [%02X] %02X", fx2.getPortDir(FX2_PORT_C), fx2.getPortState(FX2_PORT_C));
	wrapLogDebug("PORT_D: [%02X] %02X", fx2.getPortDir(FX2_PORT_D), fx2.getPortState(FX2_PORT_D));
	wrapLogDebug("PORT_E: [%02X] %02X", fx2.getPortDir(FX2_PORT_E), fx2.getPortState(FX2_PORT_E));
	wrapLogDebug("CTL_PORTS: [%02X] %02X", fx2.getPortDir(FX2_CTL_PORTS), fx2.getPortState(FX2_CTL_PORTS));
	evtWait();
	wrapLogDebug("PORT_A: [%02X] %02X", fx2.getPortDir(FX2_PORT_A), fx2.getPortState(FX2_PORT_A));
	wrapLogDebug("PORT_B: [%02X] %02X", fx2.getPortDir(FX2_PORT_B), fx2.getPortState(FX2_PORT_B));
	wrapLogDebug("PORT_C: [%02X] %02X", fx2.getPortDir(FX2_PORT_C), fx2.getPortState(FX2_PORT_C));
	wrapLogDebug("PORT_D: [%02X] %02X", fx2.getPortDir(FX2_PORT_D), fx2.getPortState(FX2_PORT_D));
	wrapLogDebug("PORT_E: [%02X] %02X", fx2.getPortDir(FX2_PORT_E), fx2.getPortState(FX2_PORT_E));
	wrapLogDebug("CTL_PORTS: [%02X] %02X", fx2.getPortDir(FX2_CTL_PORTS), fx2.getPortState(FX2_CTL_PORTS));
	encDev.stopCapture();

	return DEV_DONE;
}

int main(int argc, char *argv[]) {
	dev_ret_t r;
	parseArgs(argc, argv);
	if(showHelp) {
		printf(usage, argv[0]);
		return 0;
	}
	if(!outputFile) {
		outputFD = 1; // stdout
	} else {
		if(usePipe) {
			if(mkfifo(outputFile, 0666) != 0) {
				wrapLogError("Can't create named pipe %s");
				return 1;
			}
			outputFD = open(outputFile, O_WRONLY, 0666);
			if(outputFD < 0) {
				wrapLogError("Can't open named pipe %s");
				return 1;
			}
		} else {
			outputFD = open(outputFile, O_WRONLY | O_TRUNC | O_CREAT, 0666);
			if(outputFD < 0) {
				wrapLogError("Can't open file %s");
				return 1;
			}
		}
	}
	evtInit();
	wrapRegistryLoad("settings.cfg");
	int retries = 10;
	do {
		USBWrapper_t usb;
		while(1) {
			if(!retries--) {
				wrapLogError("Can't connect to the device");
				return 1;
			}
			int ret = usb.open(kMyVendorID, kMyProductID);
			if(ret == USBWRAP_SUCCESS) break;
			wrapSleep_ms(1000);
		}
		r = useDevice(usb);
	} while(r == DEV_RESTART);
	return 0;
}
