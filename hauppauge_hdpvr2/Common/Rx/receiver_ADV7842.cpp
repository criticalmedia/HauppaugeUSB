#include "receiver_ADV7842.h"

#include "receiver_ADV7842_consts.h"
#include "HDMI_consts.h"

#include "I2Cif.h"
#include "rx_lib.h"

#include <math.h>

static bool getSSPD(RX_SSPD_INFO *SspdInfo) { // hack
	BOOL ready;
	unsigned t = 3;
	do {
		if(!t--) return false;
		ADIAPI_RxCpGetSspdStatus(&ready, RX_SYNC_CH1);
		if(ready)
			ready = (ADIAPI_RxCpGetSspdMsrmt(SspdInfo, RX_SYNC_CH1) == ATVERR_OK);
	} while(!ready);
	wrapLogDebug("SyncSrc %u; VsAct %u; PolVs %u; HsCsAct %u; PolHsCs %u",
		SspdInfo->SyncSrc,
		SspdInfo->VsAct,
		SspdInfo->PolVs,
		SspdInfo->HsCsAct,
		SspdInfo->PolHsCs
	);
	return true;
}

static bool getSTDI(RX_STDI_INFO *StdiInfo) { //hack
	BOOL ready;
	unsigned t = 3;
	do {
		if(!t--) return false;
		ADIAPI_RxCpGetStdiStatus(&ready, RX_SYNC_CH1);
		if(ready)
			ready = (ADIAPI_RxCpGetStdiMsrmt(StdiInfo, RX_SYNC_CH1) == ATVERR_OK);
	} while(!ready);
	wrapLogDebug("BL %u; LVS %u; LF %u; FL %u; I %u",
		StdiInfo->BlockLength,
		StdiInfo->LinesVsync,
		StdiInfo->LinesField,
		StdiInfo->FieldLength,
		StdiInfo->Interlaced
	);
	return true;
}

typedef struct {
	float vFreq;
	RX_VID_RES resNum;
	RX_VRT_FRQ vFreqNum;
	RX_OS_RATE overSmp;
} rx_CP_vidParams_t;

static bool calcCPParams(rx_CP_vidParams_t *params, RX_OP_MODE mode, const RX_STDI_INFO *StdiInfo) {
	switch(mode) {
		case RX_OPMODE_COMP:
			if(StdiInfo->Interlaced) {
				switch(StdiInfo->LinesField) {
					case 261:
					case 262:
					case 263:
						params->resNum = RX_525I;
						params->overSmp = RX_OS_2X1;
						goto end_res;
					case 311:
					case 312:
					case 313:
						params->resNum = RX_625I;
						params->overSmp = RX_OS_2X1;
						goto end_res;
					case 561:
					case 562:
					case 563:
						if(StdiInfo->BlockLength < 7000) {
							params->resNum = RX_1125I_274M;
							params->overSmp = RX_OS_2X1;
						} else {
							params->resNum = RX_1125I_240M;
							params->overSmp = RX_OS_2X1;
						}
						goto end_res;
					case 624:
					case 625:
						params->resNum = RX_1250I_295M;
						params->overSmp = RX_OS_2X1;
						goto end_res;
				}
			} else {
				switch(StdiInfo->LinesField) {
					case 524:
					case 525:
						params->resNum = RX_525P;
						params->overSmp = RX_OS_2X1;
						goto end_res;
					case 624:
					case 625:
						params->resNum = RX_625P;
						params->overSmp = RX_OS_2X1;
						goto end_res;
					case 749:
					case 750:
						params->resNum = RX_720P;
						params->overSmp = RX_OS_2X1;
						goto end_res;
					case 1124:
					case 1125:
						params->resNum = RX_1125P_274M;
						params->overSmp = RX_OS_1X1;
						goto end_res;
				}
			}
			wrapLogError("Unsupported resolution: %u%c",
				StdiInfo->LinesField, StdiInfo->Interlaced ? 'I' : 'P');
			return false;
		case RX_OPMODE_GR:
		default:
			wrapLogError("Unsupported mode");
			return false;
	}
end_res:
	params->vFreq = (28636360.0f / 256) / StdiInfo->FieldLength;
	wrapLogDebug("vFreq: %f", params->vFreq);
	switch((unsigned)roundf(params->vFreq)) {
		case 24:
			params->vFreqNum = RX_VFRQ_24HZ;
			break;
		case 25:
			params->vFreqNum = RX_VFRQ_25HZ;
			break;
		case 30:
			params->vFreqNum = RX_VFRQ_30HZ;
			break;
		case 50:
			params->vFreqNum = RX_VFRQ_50HZ;
			break;
		case 56:
			params->vFreqNum = RX_VFRQ_56HZ;
			break;
		case 59:
		case 60:
			params->vFreqNum = RX_VFRQ_60HZ;
			break;
		case 70:
			params->vFreqNum = RX_VFRQ_70HZ;
			break;
		case 72:
			params->vFreqNum = RX_VFRQ_72HZ;
			break;
		case 75:
			params->vFreqNum = RX_VFRQ_75HZ;
			break;
		case 80:
			params->vFreqNum = RX_VFRQ_80HZ;
			break;
		case 85:
			params->vFreqNum = RX_VFRQ_85HZ;
			break;
		default:
			wrapLogError("Unsupported vertical frequency: %f", params->vFreq);
			return false;
	}
	return true;
}

typedef struct {
	unsigned width;
	unsigned height;
	bool interlaced;
	float aspectRatio;
} rx_CP_outputVidRes_t;

static rx_CP_outputVidRes_t getCPVidResByNum(RX_VID_RES n) {
	switch(n) {
		case RX_525I: return {720, 480, true, 4.0f/3};
		case RX_625I: return {720, 576, true, 4.0f/3};
		case RX_525P: return {720, 480, false, 4.0f/3};
		case RX_625P: return {720, 576, false, 4.0f/3};
		case RX_720P: return {1280, 720, false, 16.0f/9};
		case RX_1125I_274M: return {1920, 1080, true, 16.0f/9};
		case RX_1125I_240M: return {1920, 1035, true, 16.0f/9};
		case RX_1250I_295M: return {1920, 1080, true, 16.0f/9};
		case RX_1920I_1152: return {1920, 1152, true, 15.0f/9};
		case RX_1125P_274M: return {1920, 1080, false, 16.0f/9};
		case RX_1250P_295M: return {1920, 1080, false, 16.0f/9};
		case RX_1125P_RB: return {1920, 1080, false, 16.0f/9};
		case RX_VGA:
		case RX_SVGA:
		case RX_XGA:
		case RX_SXGA:
		case RX_WXGA:
		case RX_WXGAR:
		case RX_WXGAP:
		case RX_WXGA_1360:
		case RX_WXGA_1366:
		case RX_SXGA_PLUS:
		case RX_SXGAR:
		case RX_UXGA:
		case RX_UXGAR:
		case RX_WSXGA:
		case RX_WUXGA:
		case RX_AUTOGR:
		default:
			return {0, 0, false};
	}
}

#define VFREQ(V) case RX_VFRQ_##V##HZ: return V##.0;
static float getCPVFreqByNum(RX_VRT_FRQ n) {
	switch(n) {
		VFREQ(24) VFREQ(25) VFREQ(30) VFREQ(50)
		VFREQ(56) VFREQ(60) VFREQ(70) VFREQ(72)
		VFREQ(75) VFREQ(80) VFREQ(85)
		default:
			return 0;
	}
}
#undef VFREQ

bool receiver_ADV7842_t::getOutputParams(receiverOutputParams_t *ret) {
	if(!_isInit) return false;
	RX_OP_MODE mode;
	ADIAPI_RxGetOperatingMode(&mode);
	switch(mode) {
		case RX_OPMODE_HDMI: {
			receiverHDMIParams_t ps;
			if(!getHDMIParams(&ps)) return false;
			ret->width = ps.width;
			ret->height = ps.height;
			ret->vFreq = ps.vFreq;
			ret->interlaced = ps.interlaced;
			ret->aspectRatio = ps.aspectRatio;
			return true;
		}
		case RX_OPMODE_SDP_COMP:
		case RX_OPMODE_SDP_CVBS:
		case RX_OPMODE_SDP_CVBS_HDMI_MON:
		case RX_OPMODE_SDP_CVBS_YC_AUTO:
		case RX_OPMODE_SDP_YC:
		case RX_OPMODE_SDP_SCART: {
			BOOL vds;
			RX_SDP_FIELD_RATE vFreq;
			ADIAPI_RxSdpGetVideoDetectStatus(&vds);
			if(!vds) return false;
			ADIAPI_RxSdpGetFieldRateStatus(&vFreq);
			ret->width = 720;
			ret->height = (vFreq == RX_50HZ) ? 576 : 480; // http://www.ni.com/white-paper/4750/en/#toc3
			ret->vFreq = (vFreq == RX_50HZ) ? 50.0 : 60.0;
			ret->interlaced = VRX_ret_SDP_INTERLACED();
			ret->aspectRatio = 4.0f/3;
			return true;
		}
		case RX_OPMODE_COMP:
		case RX_OPMODE_GR: {
			RX_SSPD_INFO SspdInfo;
			RX_STDI_INFO StdiInfo;
			if(!getSSPD(&SspdInfo) || !getSTDI(&StdiInfo)) return false;
			rx_CP_vidParams_t params;
			if(!calcCPParams(&params, mode, &StdiInfo)) return false;
			rx_CP_outputVidRes_t ovr = getCPVidResByNum(params.resNum);
			float vFreq = getCPVFreqByNum(params.vFreqNum);
			if((ovr.width == 0) || (vFreq == 0)) return false;

			if(ADIAPI_RxSetInpVidCfg(mode, params.resNum, params.vFreqNum, params.overSmp) != ATVERR_OK) return false;
			ADIAPI_RxTristatePin(RX_LLC_OUT_PIN, FALSE);
			ADIAPI_RxTristatePin(RX_SYNC_OUT_PINS, FALSE);
			ADIAPI_RxTristatePin(RX_PIX_OUT_PINS, FALSE);
			ADIAPI_RxTristatePin(RX_AUD_OUT_PINS, TRUE);
			_setOutputBusMode();

			ret->width = ovr.width;
			ret->height = ovr.height;
			ret->vFreq = vFreq;
			ret->interlaced = ovr.interlaced;
			ret->aspectRatio = ovr.aspectRatio;
			return true;
		}
		case RX_OPMODE_PWRDWN:
		default:
			return false;
	}
}

bool receiver_ADV7842_t::getAudioParams(receiverAudioParams_t *ret) {
	uint8_t buf[5];
	unsigned t = 3;
	while(ADIAPI_RxHdmiGetAudioChanStatus(buf) != ATVERR_OK) {
		if(!--t) return false;
	}
	switch(buf[3] & 0x0F) { // sample frequency
		case(0):
			ret->sampleRate = 44100;
			break;
		case(2):
			ret->sampleRate = 48000;
			break;
		case(3):
			ret->sampleRate = 32000;
			break;
		case(8):
			ret->sampleRate = 88200;
			break;
		case(10):
			ret->sampleRate = 96000;
			break;
		case(12):
			ret->sampleRate = 176000;
			break;
		case(14):
			ret->sampleRate = 192000;
			break;
		default:
			ret->sampleRate = 0;
	}
	return true;
}

bool receiver_ADV7842_t::getHDMIParams(receiverHDMIParams_t *ret) {
	UINT16 TMDSFreqInt;
	UCHAR TMDSFreqFrac, pixelRepeatFactor;
	ADIAPI_RxHdmiGetTmdsFreq(&TMDSFreqInt, &TMDSFreqFrac);
	ADIAPI_RxHdmiGetPixelRepeat(&pixelRepeatFactor);
	float TMDSFreq = (float)TMDSFreqInt + (float)TMDSFreqFrac / 128;
	RX_HDMI_HSYNC hsync;
	ADIAPI_RxHdmiGetHsyncInfo(&hsync);
	RX_HDMI_VSYNC vsync;
	ADIAPI_RxHdmiGetVsyncInfo(&vsync);
	unsigned vLinesTotal = vsync.LinesTotal + (vsync.Interlaced ? vsync.F1LinesTotal : 0);
	unsigned vLinesActive = vsync.LinesActive + (vsync.Interlaced ? vsync.F1LinesActive : 0);
	float hfreq = TMDSFreq / hsync.LinesTotal * 1000;
	float vfreq = hfreq / (vLinesTotal) * (vsync.Interlaced ? 2 : 1) * 1000;
	ret->width = hsync.LinesActive / pixelRepeatFactor;
	ret->height = vLinesActive;
	ret->hLinesTotal = hsync.LinesTotal;
	ret->vLinesTotal = vLinesTotal;
	ret->TMDSFreq = TMDSFreq;
	ret->hFreq = hfreq;
	ret->vFreq = vfreq;
	ret->interlaced = vsync.Interlaced;
	ret->pixelRepetitionFactor = pixelRepeatFactor;
	ret->aspectRatio = 0; // TODO: get from an InfoFrame if exists
	return true;
}

static int getHDMIVideoIDCode_IF() {
	UCHAR p[31]; // max InfoFrame size
	BOOL cse;
	ADIAPI_RxHdmiGetPacket(AVI_INFO_PACKET, p, &cse);
	if(cse) return -1;
//	int i;
//	for(i = 0; i < 31; ++i) WRAPLOG(WRAPLOGL_DEBUG, "0x%02X", p[i]);
	wrapLogDebug("AVI InfoFrame version: %u", p[1]);
	if((p[1] < 2) || (p[2] < 13)) return -1; // AVI InfoFrame version
	return p[6] & 0x7F; // Video Format Identification Code
}

#if 0
// We have no commonly defined codes for PC aka DMT modes, so guessing must not be placed here if so.
static int getHDMIVideoIDCode_guess() {
	receiverHDMIParams_t HDMIParams;
	getHDMIParams(&HDMIParams);
	wrapLogDebug("HDMI ID Code guessing: %ux%u %f", HDMIParams.width, HDMIParams.height, HDMIParams.vFreq);
	if(
		(HDMIParams.width == 1920) &&
		(HDMIParams.height == 1080) &&
		(HDMIParams.vFreq > 59.9) && (HDMIParams.vFreq <= 60.0)
	) {
		return 5;
	} else if(
		(HDMIParams.width == 1280) &&
		(HDMIParams.height == 720) &&
		(HDMIParams.vFreq > 59.9) && (HDMIParams.vFreq <= 60.0)
	) {
		return 4;
	}
	return -1;
}
#endif

int receiver_ADV7842_t::getHDMIFormat() {
	int ret;
	ret = getHDMIVideoIDCode_IF();
	if(ret > 0) return ret;
//	ret = getHDMIVideoIDCode_guess();
//	if(ret > 0) return ret;
	return 0;
}

bool receiver_ADV7842_t::_setOutputBusMode() {
	VRX_set_LLC_DLL_MUX(1);
	switch(_outputBusMode) {
		case RXOBM_422_10x2:
			HAL_I2CWriteByte(RX_I2C_IO_MAP_ADDR, 0x03, 0xC1); // 422 2x10-bit bus
			HAL_I2CWriteByte(RX_I2C_IO_MAP_ADDR, 0x04, 0x62);
			HAL_I2CWriteByte(RX_I2C_IO_MAP_ADDR, 0x05, 0x2E); // REPL_AV_CODE: SAV/EAV enabled, spread over all samples (see UG-206)
			HAL_I2CWriteByte(RX_I2C_IO_MAP_ADDR, 0x19, 0x83); // Normal Clock
			break;
		case RXOBM_656_10:
			HAL_I2CWriteByte(RX_I2C_IO_MAP_ADDR, 0x03, 0x01); // 656 10-bit bus
			HAL_I2CWriteByte(RX_I2C_IO_MAP_ADDR, 0x04, 0x42);
			HAL_I2CWriteByte(RX_I2C_IO_MAP_ADDR, 0x05, 0x2C); // REPL_AV_CODE: SAV/EAV enabled, spread over single samples (see UG-206)
			HAL_I2CWriteByte(RX_I2C_IO_MAP_ADDR, 0x19, 0x83); // Normal Clock
			break;
		case RXOBM_656_10_DC:
			HAL_I2CWriteByte(RX_I2C_IO_MAP_ADDR, 0x03, 0x01); // 656 10-bit bus
			HAL_I2CWriteByte(RX_I2C_IO_MAP_ADDR, 0x04, 0x42);
			HAL_I2CWriteByte(RX_I2C_IO_MAP_ADDR, 0x05, 0x2C); // REPL_AV_CODE: SAV/EAV enabled, spread over single samples (see UG-206)
			HAL_I2CWriteByte(RX_I2C_IO_MAP_ADDR, 0x19, 0xC2); // Doubled Clock
			break;
	}
	return true;
}

bool receiver_ADV7842_t::setOutputBusMode(receiverOutputBusMode_t mode) {
	_outputBusMode = mode;
	if(_isInit) {
		return _setOutputBusMode();
	}
	return true;
}

bool receiver_ADV7842_t::_setEDID() {
	HAL_RxEnableInternalEdid(PORT_ALL, FALSE);
	HAL_SetChipReset(RX_EDID_REP_MPU);
	HAL_RxPopulateEdidMap((UCHAR*)_EDIDPtr, _EDIDLen, 0);
	VRX_set_SPA_PORT_A(1);
	VRX_set_SPA_PORT_B(2);
	VRX_set_SPA_LOCATION(_EDIDSPAOffset);
	VRX_set_SPA_LOCATION_MSB(0);
	HAL_RxEnableInternalEdid(PORT_A, TRUE);
	HAL_RxEnableInternalEdid(PORT_B, TRUE);
	return true;
}

bool receiver_ADV7842_t::setEDID(const void *ptr, unsigned len, unsigned SPAOffset) {
	if(_isInit) return false; // can only be used before init() yet
	_EDIDPtr = ptr;
	_EDIDLen = len;
	_EDIDSPAOffset = SPAOffset;
	return true;
}

bool receiver_ADV7842_t::hasInputSignal() {
	if(!_isInit) return false;
	RX_OP_MODE mode;
	ADIAPI_RxGetOperatingMode(&mode);
	switch(mode) {
		case RX_OPMODE_HDMI: {
			RX_DEV_STATE st;
			ADIAPI_RxHdmiGetStatus(&st);
			if(st.HwSelPort > 3) return false;
			if(!st.Tmds[st.HwSelPort]) return false;
			return true;
		}
		case RX_OPMODE_SDP_COMP:
		case RX_OPMODE_SDP_CVBS:
		case RX_OPMODE_SDP_CVBS_HDMI_MON:
		case RX_OPMODE_SDP_CVBS_YC_AUTO:
		case RX_OPMODE_SDP_YC:
		case RX_OPMODE_SDP_SCART: {
			BOOL vds;
			ADIAPI_RxSdpGetVideoDetectStatus(&vds);
			if(!vds) return false;
			return true;
		}
		case RX_OPMODE_COMP:
		case RX_OPMODE_GR:
			return true;
		case RX_OPMODE_PWRDWN:
		default:
			return false;
	}
}

bool receiver_ADV7842_t::init() {
	m_fx2.setPortStateBits(FX2_PORT_C, 0, 0x10); // 0x69 // HPD off
	m_fx2.setPortStateBits(FX2_PORT_A, 0x02, 0);
	I2CWrapper_setCtx(&m_fx2);
	UINT16 rev;
	ADIAPI_RxGetChipRevision(&rev);
	wrapLogDebug("ADV7842 rev 0x%04X", rev);

	m_fx2.setPortStateBits(FX2_PORT_E, 0x40, 0); // 0x77

	return true;
}

bool receiver_ADV7842_t::setInput(receiverInput_t input) {
	_input = input;
	switch(input) {
		case RXI_COMP:
			return _initComp();
		case RXI_CVBS:
			return _initCVBS();
		default:
			return _initHDMI();
	}
}

bool receiver_ADV7842_t::_initHDMI() {
	ATV_ERR aret;
	wrapLogDebug("receiver_ADV7842_t::initHDMI()");

	aret = ADIAPI_RxInit(RX_OPMODE_HDMI);
	if(aret != ATVERR_OK) {
		wrapLogError("Rx: Cannot init");
	}

	ADIAPI_RxTristatePin(RX_LLC_OUT_PIN, FALSE);
	ADIAPI_RxTristatePin(RX_SYNC_OUT_PINS, FALSE);
	ADIAPI_RxTristatePin(RX_PIX_OUT_PINS, FALSE);
	ADIAPI_RxTristatePin(RX_AUD_OUT_PINS, FALSE);

	aret = ADIAPI_RxHdmiSetSelectedPort(PORT_B, TRUE);
	if(aret != ATVERR_OK) {
		wrapLogError("Rx: Cannot set HDMI port");
	}

//	ADIAPI_RxHdmiAssertHpd(PORT_ALL, 0); // RX chip HPD pins are not used

	_setOutputBusMode();
	HAL_I2CWriteByte(RX_I2C_CP_MAP_ADDR, 0x3E, 0x80); // VID_ADJ_EN / no pregain

	_setEDID();

	ADIAPI_RxSetCscMode(RX_CS_MAN_EN, RX_CP_CSC);
	ADIAPI_RxSetCscConfig(RX_CS_AUTO, RX_CP_CSC);
	ADIAPI_RxSetIpColorSpace(RX_CS_FOLLOW_INPUT, RX_RG_16_235, RX_CP_CSC);
	ADIAPI_RxSetOpColorSpace(RX_CS_YCrCb601, RX_CP_CSC);
//	ADIAPI_RxSetOpColorSpace(RX_CS_YCrCb709, RX_CP_CSC);
	ADIAPI_RxCpSetOpRange(RX_RG_16_235);
	ADIAPI_RxCpSetSaturator(RX_RG_16_235);

//	ADIAPI_RxHdmiAssertHpd(PORT_A, 1); // RX chip HPD pins are not used
//	ADIAPI_RxHdmiAssertHpd(PORT_B, 1); // RX chip HPD pins are not used

	m_fx2.setPortStateBits(FX2_PORT_C, 0x10, 0); // 0x79 // HPD on

	_isInit = true;

	return true;
}

bool receiver_ADV7842_t::_initCVBS() {
	ATV_ERR aret;
	wrapLogDebug("receiver_ADV7842_t::initCVBS()");

	aret = ADIAPI_RxInit(RX_OPMODE_SDP_CVBS);
	if(aret != ATVERR_OK) {
		wrapLogError("Rx: Cannot init");
	}

	ADIAPI_RxTristatePin(RX_LLC_OUT_PIN, FALSE);
	ADIAPI_RxTristatePin(RX_SYNC_OUT_PINS, FALSE);
	ADIAPI_RxTristatePin(RX_PIX_OUT_PINS, FALSE);
	ADIAPI_RxTristatePin(RX_AUD_OUT_PINS, TRUE);

	ADIAPI_RxAfeEnManAinMux(TRUE);
	ADIAPI_RxAfeManAinMux(RX_ADC0, RX_AIN11);

	/* From https://github.com/Xilinx/linux-xlnx/blob/master/drivers/media/i2c/adv7842.c#L1638 */
	/* set ADI recommended settings for digitizer */
	/* "ADV7842 Register Settings Recommendations
	 * (rev. 1.8, November 2010)" p. 9. */
//	HAL_I2CWriteByte(RX_I2C_AFE_DPLL_MAP_ADDR, 0x0c, 0x1f); /* ADC Range improvement */
//	HAL_I2CWriteByte(RX_I2C_AFE_DPLL_MAP_ADDR, 0x12, 0x63); /* ADC Range improvement */

	_enableColorMode();
	_setOutputBusMode();

	_isInit = true;

	return true;
}

bool receiver_ADV7842_t::_initComp() {
	ATV_ERR aret;
	wrapLogDebug("receiver_ADV7842_t::initComp()");

//	aret = ADIAPI_RxInit(RX_OPMODE_SDP_COMP);
	aret = ADIAPI_RxInit(RX_OPMODE_COMP);
	if(aret != ATVERR_OK) {
		wrapLogError("Rx: Cannot init");
	}

	ADIAPI_RxTristatePin(RX_LLC_OUT_PIN, FALSE);
	ADIAPI_RxTristatePin(RX_SYNC_OUT_PINS, FALSE);
	ADIAPI_RxTristatePin(RX_PIX_OUT_PINS, FALSE);
	ADIAPI_RxTristatePin(RX_AUD_OUT_PINS, TRUE);

	ADIAPI_RxAfeEnManAinMux(FALSE);
	ADIAPI_RxAfeAinAutoMuxModeSel(1); // AIN{4,5,6}, SYNC2

	/* From https://github.com/Xilinx/linux-xlnx/blob/master/drivers/media/i2c/adv7842.c#L1638 */
	/* set ADI recommended settings for digitizer */
	/* "ADV7842 Register Settings Recommendations
	 * (rev. 1.8, November 2010)" p. 9. */
//	HAL_I2CWriteByte(RX_I2C_AFE_DPLL_MAP_ADDR, 0x0c, 0x1f); /* ADC Range improvement */
//	HAL_I2CWriteByte(RX_I2C_AFE_DPLL_MAP_ADDR, 0x12, 0x63); /* ADC Range improvement */

//	ADIAPI_RxAfeSetSyncSlicerFilt(RX_SYNC_SLICER1, RX_SFILT_GR250NS);

	_setOutputBusMode();

	_isInit = true;

	return true;
}

bool receiver_ADV7842_t::showInfo() {
	RX_OP_MODE mode;
	ADIAPI_RxGetOperatingMode(&mode);
	WRAPLOG(WRAPLOGL_DEBUG, "Mode: %u", mode);

	switch(mode) {
		case RX_OPMODE_HDMI:
			return _showInfoHDMI();
		case RX_OPMODE_SDP_COMP:
		case RX_OPMODE_SDP_CVBS:
		case RX_OPMODE_SDP_CVBS_HDMI_MON:
		case RX_OPMODE_SDP_CVBS_YC_AUTO:
		case RX_OPMODE_SDP_YC:
		case RX_OPMODE_SDP_SCART:
			return _showInfoSDP();
		case RX_OPMODE_COMP:
		case RX_OPMODE_GR:
			return _showInfoCP();
		case RX_OPMODE_PWRDWN:
		default:
			return true;
	}
}

bool receiver_ADV7842_t::_showInfoHDMI() {
	RX_DEV_STATE st;
	ADIAPI_RxHdmiGetStatus(&st);
	wrapLogDebug("Active port: %X", st.HwSelPort);
	if(st.HwSelPort < 4) {
		wrapLogDebug("5V: %X, TMDS: %X", st.Detected5V[st.HwSelPort], st.Tmds[st.HwSelPort]);
	}

	receiverHDMIParams_t HDMIParams;
	getHDMIParams(&HDMIParams);

	wrapLogDebug("TMDS freq: %f MHz", HDMIParams.TMDSFreq);
	wrapLogDebug("HSync active lines: %u, freq: %f kHz", HDMIParams.width, HDMIParams.hFreq);
	wrapLogDebug("VSync active lines: %u, freq: %f Hz", HDMIParams.height, HDMIParams.vFreq);
	wrapLogDebug("Interlaced: %u", HDMIParams.interlaced);
	wrapLogDebug("Pixel repetition factor: %u", HDMIParams.pixelRepetitionFactor);

	int vm = getHDMIVideoIDCode_IF();
	if(vm < 0) {
		wrapLogDebug("Bad AVI InfoFrame");
	} else {
		wrapLogDebug("HDMI VIC: %d: %s", vm, HDMIVideoIDCodeStrs[vm]);
	}

	return true;
}

bool receiver_ADV7842_t::_showInfoSDP() {
	RX_SDP_STATUS st;
	ADIAPI_RxSdpGetStatus(&st);
	wrapLogDebug("Signal presence: %d", st.VideoDetect);
	wrapLogDebug("Is 50Hz: %d", st.Ad50_60Hz);
	uint8_t data;
	HAL_I2CReadByte(RX_I2C_SDP_MAP_ADDR, 0x54, &data);
	wrapLogDebug("SDP 0x54: 0x%02X", data);
	HAL_I2CReadByte(RX_I2C_SDP_MAP_ADDR, 0x56, &data);
	wrapLogDebug("SDP 0x56: 0x%02X", data);
	HAL_I2CReadByte(RX_I2C_SDP_MAP_ADDR, 0x57, &data);
	wrapLogDebug("SDP 0x57: 0x%02X", data);
	HAL_I2CReadByte(RX_I2C_SDP_MAP_ADDR, 0x58, &data);
	wrapLogDebug("SDP 0x58: 0x%02X", data);
	HAL_I2CReadByte(RX_I2C_SDP_MAP_ADDR, 0x59, &data);
	wrapLogDebug("SDP 0x59: 0x%02X", data);
	return true;
}

bool receiver_ADV7842_t::_enableColorMode() {
	// Enable PAL (0x01) in addition to NTSC (0x02)
	HAL_I2CWriteByte(RX_I2C_SDP_MAP_ADDR, 0x00, 0x03);
	return true;
}

bool receiver_ADV7842_t::_showInfoCP() {
	RX_SYNC_CH syncCh;
	ADIAPI_RxCpGetMainSyncCh(&syncCh);
	wrapLogDebug("CP sync channel: #%c", (syncCh == RX_SYNC_CH1) ? '1' : '2');
	return true;
}
