#include "encoderDev_DXT.h"

#include "log.h"
#include "baseif.h"

#include "CHapi.h"
#include "Hapi_extra.h"

#include <string.h>
#include <math.h>

encoderDev_DXT_t::~encoderDev_DXT_t(){
	wrapLogInfo("encoderDev_DXT_t::~encoderDev_DXT_t()");
	USBBootMChip_t *mchip = (USBBootMChip_t*)m_mchip;
	CHapi *hapi = (CHapi*)m_hapi;

	hapi->powerDown();

	if(hapi) delete hapi;
	if(mchip) delete mchip;
}

bool encoderDev_DXT_t::init() {
	wrapLogInfo("encoderDev_DXT_t::init()");
	m_mchip = (void*)new USBBootMChip_t(m_fx2);
	m_hapi = (void*)new CHapi((USBBootMChip_t*)m_mchip);

	USBBootMChip_t *mchip = (USBBootMChip_t*)m_mchip;
	CHapi *hapi = (CHapi*)m_hapi;

	hapi->setDataTransfer(&m_dt);

	mchip->resetUsbPipes();
	if(!hapi->powerUp()) return false;

	return true;
}

bool encoderDev_DXT_t::showInfo() {
	wrapLogDebug("encoderDev_DXT_t::showInfo()");
	return true;
}

#define MEAN(A, B) ((A + B) / 2)
static HAPI_ASPECT_RATIO getNearestARNum(float ar) {
	const struct {
		HAPI_ASPECT_RATIO arNum;
		float ar_hb;
	} ars[] = {
		{HAPI_AR_4_BY_3, MEAN(4.0f/3, 14.0f/9)},
		{HAPI_AR_14_BY_9, MEAN(14.0f/9, 16.0f/9)}
	};
	unsigned i;
	for(i = 0; i < (sizeof(ars) / sizeof(ars[0])); ++i) {
		if(ar < ars[i].ar_hb) return ars[i].arNum;
	}
	return HAPI_AR_16_BY_9;
}

static unsigned getAudioCapSampleRateNum(float sr) {
// in kHz. 0: NONE, 1: 32, 2: 44.1, 3: 48, 4: 96, 5: 192, 6: 16
	switch((unsigned)roundf(sr)) {
		case(32000): return 1;
		case(44100): return 2;
		case(48000): return 3;
		case(96000): return 4;
		case(192000): return 5;
		case(16000): return 6;
		default: return 3;
	}
}

bool encoderDev_DXT_t::setInputFormat(encoderSource_t source, encoderAudioInFormat_t audioFormat,
		unsigned width, unsigned height, bool interlaced, float vFreq, float aspectRatio,
		float audioSampleRate) {
	wrapLogDebug("encoderDev_DXT_t::setInputFormat(params...)");
	wrapLogDebug("source: %d, %ux%u%c %fHz, AR: %f, audio: %s, SR: %fHz",
		source, width, height, interlaced ? 'i' : 'p', vFreq, aspectRatio,
		audioFormat == ENCAIF_AC3 ? "AC-3" : "PCM", audioSampleRate);

	CHapi *hapi = (CHapi*)m_hapi;
	HAPI_SET_PARAM _Param;
	memset(&_Param, 0, sizeof(_Param));
	_Param.index = HAPI_SET_PARAM_TYPE_ENCODER;

	hapi->setHDMIformat(TMDL_HDMITX_VFMT_CUSTOM);
	if(!hapi->get_custom_defaults(&_Param, width, height, interlaced, vFreq)) {
		wrapLogError(" get_custom_defaults() failed!!");
		return false;
	}

	switch(source) {
		case ENCS_CVBS:
			hapi->set_param(&_Param, "VideoCapSource", 0);
			hapi->set_param(&_Param, "AudioCapSource", 0); /* 0: LR, 1:SPDIF, 2:SDI, 3: HDMI */
			break;
		case ENCS_COMP:
			hapi->set_param(&_Param, "VideoCapSource", 1);
			hapi->set_param(&_Param, "AudioCapSource", 0); /* 0: LR, 1:SPDIF, 2:SDI, 3: HDMI */
			break;
		default:
			hapi->set_param(&_Param, "VideoCapSource", 3);
			hapi->set_param(&_Param, "AudioCapSource", 3); /* 0: LR, 1:SPDIF, 2:SDI, 3: HDMI */
	}

	switch(audioFormat) {
		case ENCAIF_AC3:
			hapi->set_param(&_Param, "AudioCapSource", 3);         /* HDMI/SPDIF */
			hapi->set_param(&_Param, "AudioPassthru", 1);
			hapi->set_param(&_Param, "AudioCodecOutputFormat", 2); /* AC3 */
			hapi->set_param(&_Param, "AudioStreamID", 189);        /* AC3/DTS */
			break;
		case ENCAIF_PCM:
		default:
			hapi->set_param(&_Param, "AudioPassthru", 0);
			hapi->set_param(&_Param, "AudioCodecOutputFormat", 3); /* AAC */
			hapi->set_param(&_Param, "AudioStreamID", 192);        /* AAC/MPEG */
			break;
	}

	if(audioSampleRate != 0) {
		hapi->set_param(&_Param, "AudioCapSampleRate", getAudioCapSampleRateNum(audioSampleRate));
	}

	if(!hapi->HapiParamSet(&_Param)) {
		wrapLogError(" HapiParamSet() failed!!");
		return false;
	}

	if(aspectRatio == 0) {
		hapi->HapiAspectSet(getNearestARNum((float)width / height));
	} else {
		hapi->HapiAspectSet(getNearestARNum(aspectRatio));
	}

	return true;
}

bool encoderDev_DXT_t::setHDMIFormat(int hdmi_fmt, float audioSampleRate) {
	wrapLogDebug("encoderDev_DXT_t::setHdmiFormat(id)");
	CHapi *hapi = (CHapi*)m_hapi;
	HAPI_SET_PARAM _Param;
	memset(&_Param, 0, sizeof(_Param));
	_Param.index = HAPI_SET_PARAM_TYPE_ENCODER;

	hapi->setHDMIformat(hdmi_fmt);
	if(!hapi->get_std_defaults(&_Param)) {
		wrapLogError(" get_std_defaults() failed!!");
		return false;
	}

//	hapi->set_param(&_Param, "VideoCodecOutputFormat", 4); // H.264 // as in driver
//	hapi->set_param(&_Param, "VideoCodecOutputFormat", 1); // MPEG2

//	hapi->set_param(&_Param, "CabacCoding", 1);
//	hapi->set_param(&_Param, "VideoProfile", 3); // as in driver // get_std_defaults() sets 4
//	hapi->set_param(&_Param, "VideoLevel", 310); // as in driver // get_std_defaults() sets 400
//	hapi->set_param(&_Param, "VideoLatency", 1);

	hapi->set_param(&_Param, "AudioCapSource", 3); // always HDMI for this design // 0: LR, 1:SPDIF, 2:SDI, 3: HDMI
	if(audioSampleRate != 0) {
		hapi->set_param(&_Param, "AudioCapSampleRate", getAudioCapSampleRateNum(audioSampleRate));
	}

	if(!hapi->HapiParamSet(&_Param)) {
		wrapLogError(" HapiParamSet() failed!!");
		return false;
	}

	hapi->HapiAspectSet(HAPI_AR_16_BY_9);

	return true;
}

bool encoderDev_DXT_t::setHDMIAR(float aspectRatio) {
	wrapLogDebug("encoderDev_DXT_t::setHDMIAR()");
	CHapi *hapi = (CHapi*)m_hapi;
	hapi->HapiAspectSet(getNearestARNum(aspectRatio));
	return true;
}

bool encoderDev_DXT_t::startCapture() {
	wrapLogInfo("encoderDev_DXT_t::startCapture()");
	CHapi *hapi = (CHapi*)m_hapi;
	if(!hapi->HapiStart()) return false;
	return true;
}

bool encoderDev_DXT_t::stopCapture() {
	wrapLogInfo("encoderDev_DXT_t::stopCapture()");
	CHapi *hapi = (CHapi*)m_hapi;
	if(!hapi->HapiStop()) return false;
	return true;
}
