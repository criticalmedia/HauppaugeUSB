//=============================================================================
//  File Name: Hapi.h
//
//  Copyright 2009 Magnum Semiconductor Inc. All rights reserved.
//
//  Description:
//      HAPI interface definitions.
//
//  Modification History:
//      $Id: $
//      $Log: $
//
//=============================================================================

#ifndef _HAPI_H_
#define _HAPI_H_

#include "HapiBaseType.h"
#include "HapiCommon.h"
#include "Hwapi.h"

#ifdef  __cplusplus
extern  "C"
{
#endif

/******************************** CONSTANTS *********************************/

/********************************** MACROS **********************************/


#define MAX_FILE_NAME_LENGTH 256


/******************************* ENUMERATIONS *******************************/



/************************ STRUCTURE/UNION DATA TYPES ************************/
typedef struct _HAPI_INIT_PARAM
{
	Uint32 chipID; 
	HWAPIHandle cmdBus;
	HWAPIHandle dataBus;
	DRAM_BKV_CONFIG bkvConfig;
    hw_port_config pHwPortConfig;
#ifdef HAUPPAUGE
	void *context;
#endif

}HAPI_INIT_PARAM;

typedef struct _HAPI_BOOT_CONFIG
{
	Uint32 index; // channel index
	HAPI_AUDIO_IN_PORT AudioInputPort; //TS IN, I2S, SBP, PCI, etc.
	HAPI_VIDEO_IN_PORT VideoInputPort; //TS IN, 656, SBP, PCI, etc.
	HAPI_AUDIO_OUT_PORT AudioOutputPort; //TS out, SBP, PCI, etc.
	HAPI_VIDEO_OUT_PORT VideoOutputPort; //TS out, SBP, PCI, etc.
}HAPI_BOOT_CONFIG;

typedef struct _HAPI_AV_CALLBACK_FUNC
{
	HAPI_AVDataSend avDataSend;
	HAPI_AVDataReceive avDataReceive;
}HAPI_AV_CALLBACK_FUNC;



typedef void* HAPIHandle;

/**************************** FUNCTION PROTOTYPES ***************************/

HapiErrCode HAPI_Init(HAPIHandle *hChip, HAPI_INIT_PARAM *chipInit);
HWAPIHandle HAPI_commBusInit(Uint32 chipID, CommBusType busType, HWAPI_FUNCTIONS* pFunctions,hw_port_config *pHwPortConfig);
HapiErrCode HAPI_GetBoardInfo(HWAPIHandle hBus, BOARD_INFO *pBoardInfo);
HapiErrCode HAPI_SetEndianSwap(HAPIHandle hChip, Uint32 swap);
HapiErrCode HAPI_FWDownload(HAPIHandle hChip, FIRMWARE_FILE *fwFile);
HapiErrCode HAPI_BoardBootup(HAPIHandle hChip, HAPI_BOOT_CONFIG *config);
HapiErrCode HAPI_ParamSet(HAPIHandle hChip, HAPI_SET_PARAM *param);
HapiErrCode HAPI_ParamGet(HAPIHandle hChip, HAPI_GET_PARAM *param);
HapiErrCode HAPI_FWUpgrade(HAPIHandle hChip, HAPI_FWUPGRADE_PARAM *param);
HapiErrCode HAPI_Exit(HAPIHandle hChip);
HapiErrCode HAPI_Start (HAPIHandle hChip, Uint32 channel);
HapiErrCode HAPI_Stop (HAPIHandle hChip, Uint32 channel);

#ifndef DRIVER_BUILD//HAUPPAUGE
HapiErrCode HAPI_ErrorMsgCallbackInstall(HAPIHandle hChip, HAPI_ErrorMsgCallback func, void *context);
#else
HapiErrCode HAPI_ErrorMsgCallbackInstall(HAPIHandle hChip, HAPI_ErrorMsgCallback func);
#endif
HapiErrCode HAPI_AVDataCallbackInstall(HAPIHandle hChip, HAPI_AV_CALLBACK_FUNC *func);
HapiErrCode HAPI_StatusQuery(HAPIHandle hChip, HAPI_QUERY_STRUCT *status);
HapiErrCode HAPI_ARSet(HAPIHandle hChip, Uint32 ch, HAPI_ASPECT_RATIO ar);
HapiErrCode HAPI_PCRSet(HAPIHandle hChip, Uint64 pcr);

HapiErrCode HAPI_I2CClockFreq(HAPIHandle hChip, Uint16 f_khz);
HapiErrCode HAPI_I2CWrite(HAPIHandle * hChip, HAPI_I2C_WRITE_PARAM *writeParam);
HapiErrCode HAPI_I2CRead(HAPIHandle * hChip, HAPI_I2C_READ_PARAM *readParam);
HapiErrCode HAPI_GPIORead(HAPIHandle hChip, HAPI_GPIO_PIN_ID pin, Uint32 *pVal);
HapiErrCode HAPI_GPIOWrite(HAPIHandle hChip, HAPI_GPIO_PIN_ID pin, Uint32 val);
HapiErrCode HAPI_I2CMonitorInstall(HAPIHandle hChip, HAPI_I2C_MONITOR_NUM monitorNum, HAPI_I2C_MONITOR_PARAM *monitorParam);
HapiErrCode HAPI_SetAVLDriver(HAPIHandle hChip, HAPI_SET_AVL_PARAM *avl);
HapiErrCode HAPI_LogoConfig(HAPIHandle hChip, HAPI_LOGO_CONFIG_PARAM *config);
HapiErrCode HAPI_LogoOnOff(HAPIHandle hChip, Uint32 index, Uint16 logoIndex, Uint8 on);

#ifndef DRIVER_BUILD//HAUPPAUGE
Boolean isFractionalFrameRate(HAPI_VIDEO_OUTPUT_FRAME_RATE vfr);
Boolean isNonfractionalFrameRate(HAPI_VIDEO_OUTPUT_FRAME_RATE vfr);
HAPI_VIDEO_OUTPUT_FRAME_RATE getNonfractionalFrameRate(HAPI_VIDEO_OUTPUT_FRAME_RATE vfr);
HAPI_VIDEO_OUTPUT_FRAME_RATE getFractionalFrameRate(HAPI_VIDEO_OUTPUT_FRAME_RATE vfr);
Boolean adjustVideoFrameRate(ENCODE_VIDEO_PARAMS *pVideoParams, Boolean bInputFR);
#endif

#ifdef   __cplusplus
}
#endif

#endif //_HAPI_H_
