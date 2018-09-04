/*+++ *******************************************************************\ 
* 
*  Copyright and Disclaimer: 
*  
*     --------------------------------------------------------------- 
*     This software is provided "AS IS" without warranty of any kind, 
*     either expressed or implied, including but not limited to the 
*     implied warranties of noninfringement, merchantability and/or 
*     fitness for a particular purpose.
*     --------------------------------------------------------------- 
*   
*     Copyright (c) 2011 Hauppauge Computer Works, Inc. 
*     All rights reserved. 
*
\******************************************************************* ---*/ 

#include <string.h>
#include "CHapi.h"

#ifdef OLD_DRIVER
//#include "Device.h"
#include "DataTransfer.h"
#else
#include "AVOutput.h"
#endif


#include "mchip_utils.h"
#include "HwapiUsb.h"
#include "HapiMsg.h"
//#include "usb_defines.h"

//#include "mchip_dram_bkv.h"
#include "SwapEndian.h"



//defined in bkv_init.c
extern DRAM_BKV_CONFIG BKV_24_320SYS_400DDR_CL6_DXTA3_LV_NOODT_v1;
extern DRAM_BKV_CONFIG BKV_24_375CL6_335T_285_12SYS_1P_DXTA3_LV_NOODT_v5;
extern DRAM_BKV_CONFIG BKV_375CL6_335T_285SYS_1P_MCHIPA3_LV_NOODT;
extern DRAM_BKV_CONFIG BKV_24_285_12CL6_400T_SYS_1P_DXTA3_LV_NOODT_v1;
extern DRAM_BKV_CONFIG BKV_DXT_C_Micron_425_optimal;
extern DRAM_BKV_CONFIG BKV_DXT_C_Hynix_425;
extern DRAM_BKV_CONFIG *BkvArray[];
extern DWORD BkvCount;

//typedef enum _PARAM_TYPE
//{
//    PARAM_encode = 0,
//    PARAM_decode = 1,
//    PARAM_xcode  = 2,
//    PARAM_MAX,
//} PARAM_TYPE;



static FIRMWARE_FILE		gFirmwareFile =
{
	NULL,
	0,
	0,
	NULL,
	0,
	0,
};

static HAPI_BOOT_CONFIG		gBootConfig [BOARD_MAX]=
{
    //Transcode (ala Plankton)
	{
		0,
		HAPI_AUDIO_IN_PORT_SBP,
		HAPI_VIDEO_IN_PORT_SBP,
		HAPI_AUDIO_OUT_PORT_SBP,
		HAPI_VIDEO_OUT_PORT_SBP,
    },
    //Encode to TS(ala llama)
    {
		0,
		HAPI_AUDIO_IN_PORT_CAPTURE,
		HAPI_VIDEO_IN_PORT_CAPTURE,
		HAPI_AUDIO_OUT_PORT_TSOUT,
		HAPI_VIDEO_OUT_PORT_TSOUT,
    },
    //Encode to USB(ala llama_usb, siena)
    {
        0,
        HAPI_AUDIO_IN_PORT_CAPTURE,
        HAPI_VIDEO_IN_PORT_CAPTURE,
        HAPI_AUDIO_OUT_PORT_SBP,
        HAPI_VIDEO_OUT_PORT_SBP,
    },
    //Encode to USB(siena)
    {
        0,
        HAPI_AUDIO_IN_PORT_CAPTURE,
        HAPI_VIDEO_IN_PORT_CAPTURE,
        HAPI_AUDIO_OUT_PORT_SBP,
        HAPI_VIDEO_OUT_PORT_SBP,
    }
#if 0//AV_ASI
    ,
	{
		0,
		HAPI_AUDIO_IN_PORT_TSIN,
		HAPI_VIDEO_IN_PORT_TSIN,
		HAPI_AUDIO_OUT_PORT_TSOUT,
		HAPI_VIDEO_OUT_PORT_TSOUT,
    }
#endif
};


static HAPI_AV_CALLBACK_FUNC	gCallbackFunc =
{
	CHapi::AVDataRequest,
	CHapi::AVDataTransfer,
};

static HAPI_SET_AVL_PARAM   AvlOffParam =
{
    0, // nDevs
    0, // i2cBus
    0xff, // gpioSCL - 0xff=no gpio connected
    0xff, // gpioSDA - 0xff=no gpio connected
    {  // avlDev[]
        { HAPI_AVL_INVALID, HAPI_AVL_DEVICE_CTRL_TYPE_I2C, { { 0, 0 } } }, // [0]
        { HAPI_AVL_INVALID, HAPI_AVL_DEVICE_CTRL_TYPE_I2C, { { 0, 0 } } }, // [1]
        { HAPI_AVL_INVALID, HAPI_AVL_DEVICE_CTRL_TYPE_I2C, { { 0, 0 } } }, // [2]
        { HAPI_AVL_INVALID, HAPI_AVL_DEVICE_CTRL_TYPE_I2C, { { 0, 0 } } }, // [3]
        { HAPI_AVL_INVALID, HAPI_AVL_DEVICE_CTRL_TYPE_I2C, { { 0, 0 } } }, // [4]
        { HAPI_AVL_INVALID, HAPI_AVL_DEVICE_CTRL_TYPE_I2C, { { 0, 0 } } }, // [5]
        { HAPI_AVL_INVALID, HAPI_AVL_DEVICE_CTRL_TYPE_I2C, { { 0, 0 } } }, // [6]
        { HAPI_AVL_INVALID, HAPI_AVL_DEVICE_CTRL_TYPE_I2C, { { 0, 0 } } }, // [7]
        { HAPI_AVL_INVALID, HAPI_AVL_DEVICE_CTRL_TYPE_I2C, { { 0, 0 } } }, // [8]
        { HAPI_AVL_INVALID, HAPI_AVL_DEVICE_CTRL_TYPE_I2C, { { 0, 0 } } }, // [9]
        { HAPI_AVL_INVALID, HAPI_AVL_DEVICE_CTRL_TYPE_I2C, { { 0, 0 } } }, // [10]
        { HAPI_AVL_INVALID, HAPI_AVL_DEVICE_CTRL_TYPE_I2C, { { 0, 0 } } }, // [11]
        { HAPI_AVL_INVALID, HAPI_AVL_DEVICE_CTRL_TYPE_I2C, { { 0, 0 } } }, // [12]
    },
};

//FGR - BUGBUG we would need to describe the Siena board, assuming we
// want Magnum to drive any part of it
static HAPI_SET_AVL_PARAM   AvlSienaParam =
{
    4, // nDevs
    0, // i2cBus
    0xff, // gpioSCL - 0xff=no gpio connected
    0xff, // gpioSDA - 0xff=no gpio connected
    {  // avlDev[]
        { HAPI_AVL_CS5340,   HAPI_AVL_DEVICE_CTRL_TYPE_I2C, { { 0, 0x00 } } }, // [0]
        { HAPI_AVL_CS8416,   HAPI_AVL_DEVICE_CTRL_TYPE_I2C, { { 0, 0x22 } } }, // [1]
        { HAPI_AVL_TDA9955,  HAPI_AVL_DEVICE_CTRL_TYPE_I2C, { { 0, 0x9C } } }, // [2]
        { HAPI_AVL_TDA19977, HAPI_AVL_DEVICE_CTRL_TYPE_I2C, { { 0, 0x98 } } }, // [3]
        { HAPI_AVL_INVALID,  HAPI_AVL_DEVICE_CTRL_TYPE_I2C, { { 0, 0 } } }, // [4]
        { HAPI_AVL_INVALID,  HAPI_AVL_DEVICE_CTRL_TYPE_I2C, { { 0, 0 } } }, // [5]
        { HAPI_AVL_INVALID,  HAPI_AVL_DEVICE_CTRL_TYPE_I2C, { { 0, 0 } } }, // [6]
        { HAPI_AVL_INVALID,  HAPI_AVL_DEVICE_CTRL_TYPE_I2C, { { 0, 0 } } }, // [7]
        { HAPI_AVL_INVALID,  HAPI_AVL_DEVICE_CTRL_TYPE_I2C, { { 0, 0 } } }, // [8]
        { HAPI_AVL_INVALID,  HAPI_AVL_DEVICE_CTRL_TYPE_I2C, { { 0, 0 } } }, // [9]
        { HAPI_AVL_INVALID,  HAPI_AVL_DEVICE_CTRL_TYPE_I2C, { { 0, 0 } } }, // [10]
        { HAPI_AVL_INVALID,  HAPI_AVL_DEVICE_CTRL_TYPE_I2C, { { 0, 0 } } }, // [11]
        { HAPI_AVL_INVALID,  HAPI_AVL_DEVICE_CTRL_TYPE_I2C, { { 0, 0 } } }, // [12]
    },
};

static HAPI_SET_AVL_PARAM   AvlSienaParam2 =
{
    1, // nDevs
    0, // i2cBus
    0xff, // gpioSCL - 0xff=no gpio connected
    0xff, // gpioSDA - 0xff=no gpio connected
    {  // avlDev[]
        { HAPI_AVL_TDA19977, HAPI_AVL_DEVICE_CTRL_TYPE_I2C, { { 0, 0x98 } } }, // [0]
        { HAPI_AVL_INVALID,  HAPI_AVL_DEVICE_CTRL_TYPE_I2C, { { 0, 0 } } }, // [1]
        { HAPI_AVL_INVALID,  HAPI_AVL_DEVICE_CTRL_TYPE_I2C, { { 0, 0 } } }, // [2]
        { HAPI_AVL_INVALID,  HAPI_AVL_DEVICE_CTRL_TYPE_I2C, { { 0, 0 } } }, // [3]
        { HAPI_AVL_INVALID,  HAPI_AVL_DEVICE_CTRL_TYPE_I2C, { { 0, 0 } } }, // [4]
        { HAPI_AVL_INVALID,  HAPI_AVL_DEVICE_CTRL_TYPE_I2C, { { 0, 0 } } }, // [5]
        { HAPI_AVL_INVALID,  HAPI_AVL_DEVICE_CTRL_TYPE_I2C, { { 0, 0 } } }, // [6]
        { HAPI_AVL_INVALID,  HAPI_AVL_DEVICE_CTRL_TYPE_I2C, { { 0, 0 } } }, // [7]
        { HAPI_AVL_INVALID,  HAPI_AVL_DEVICE_CTRL_TYPE_I2C, { { 0, 0 } } }, // [8]
        { HAPI_AVL_INVALID,  HAPI_AVL_DEVICE_CTRL_TYPE_I2C, { { 0, 0 } } }, // [9]
        { HAPI_AVL_INVALID,  HAPI_AVL_DEVICE_CTRL_TYPE_I2C, { { 0, 0 } } }, // [10]
        { HAPI_AVL_INVALID,  HAPI_AVL_DEVICE_CTRL_TYPE_I2C, { { 0, 0 } } }, // [11]
        { HAPI_AVL_INVALID,  HAPI_AVL_DEVICE_CTRL_TYPE_I2C, { { 0, 0 } } }, // [12]
    },
};

//static Uint16               I2cBus;
const int defaultPMTOutputPID   = 0x0100; //BUGBUG - no way to set PMT PID
const int defaultNITOutputPID   = 0x001F; //BUGBUG - no way to set NIT PID
const int defaultPCROutputPID   = 0x1001;
const int defaultVideoOutputPID = 0x1011;
const int defaultAudioOutputPID = 0x1100;

typedef struct _Parameter_Map_Item
{
    const char *str;
    Uint32 *addr ;
    int	type;  // 0-number, 1-string

#ifdef HAUPPAUGE
	//We will use the type to indicate the various formating options possible for each element
	//-1=do not display,  0=decimal number, 1=string(not used), 2=hex number, 3=PID, 4=HAPI_SET_PARAM_TYPE
	// 5=16bit decimal number, 6=16bit hex number

	//0x10=HAPI_VIDEO_CODEC, 0x11=HAPI_VIDEO_OUTPUT_MODE, 0x12=HAPI_VIDEO_OUTPUT_FRAME_RATE
	//0x13=HAPI_RATE_CONTROL 0x14=HAPI_CODING_MODE  0x15=HAPI_VIDEO_PROFILE
	//0x16=HAPI_LATENCY 0x17=HAPI_VIDEO_ENTROPY_MODE 
	//0x18=HAPI_VIDEO_CAPTURE_SOURCE 0x19=HAPI_VIDEO_H264_LEVEL

	//0x20=HAPI_AUDIO_CODEC 0x21=HAPI_AUDIO_SAMPLE_RATE
	//0x22=HAPI_AUDIO_BITRATE  0x23=HAPI_AUDIO_TRANSCODE_MODE 
	//0x24=HAPI_AUDIO_OUTPUT_MODE  0x25=HAPI_AUDIO_CAPTURE_SOURCE
	//0x26=HAPI_AUDIO_CAPTURE_MODE	0x27=HAPI_AUDIO_CAPTURE_SPDIF_INPUT
#endif
} Parameter_Map_Item;

typedef struct _Param_Bitmask_Item
{
    const char *str;
    Uint32 *addr ;
    Uint32	bitmask;
}Param_Bitmask_Item;

static HAPI_SET_PARAM gParam;//used for offset calc only, never directly assigned to

static Parameter_Map_Item EncodeParamMapTable[] = 
{
   //Params for encode
#ifndef DRIVER_BUILD
    {"OutputFileEnable",	&gFileIO.dump_output_file,	0},
    {"OutputFilePath",		(Uint32 *)gFileIO.output_av_file,	1},
	{"LogOutputEnable",		&gFileIO.enable_debug_log,	0},
	{"LogFilePath",		 	(Uint32 *)gFileIO.debug_log_file,		1},
    {"VideoLogoFilePath",   (Uint32 *)gFileIO.video_logo_file,1},
	{"CommBusType",			(Uint32 *)&gCommBusType,				0},
    {"AudioInputPort",  (Uint32 *)&gBootConfig.AudioInputPort,  0},
    {"AudioOutputPort", (Uint32 *)&gBootConfig.AudioOutputPort, 0},
    {"VideoInputPort",  (Uint32 *)&gBootConfig.VideoInputPort,  0},
    {"VideoOutputPort", (Uint32 *)&gBootConfig.VideoOutputPort, 0},
	{"EndianSwap",			&gEndianSwap,				0},
#endif
	{"OutputPCRPID",        (Uint32 *)&gParam.OutputPCRPID,       3},
	{"ParamType",			(Uint32 *)&gParam.ParamType,			4},
	{"VideoStreamID",	(Uint32 *)&gParam.params.encodeParam.VideoParams.StreamID,		3},

	{"VideoOutputPID",	(Uint32 *)&gParam.params.encodeParam.VideoParams.OutputPID,		3},
	{"VideoCapSource",	(Uint32 *)&gParam.params.encodeParam.VideoParams.VideoCapSource,		0x18},
	{"VideoCapWidth",	(Uint32 *)&gParam.params.encodeParam.VideoParams.VideoCapWidth,		0},
//	{"VIdeoCapHeight",	(Uint32 *)&gParam.params.encodeParam.VideoParams.VIdeoCapHeight,		-1},
#ifdef HAUPPAUGE// case error
	{"VideoCapHeight",	(Uint32 *)&gParam.params.encodeParam.VideoParams.VIdeoCapHeight,		0},
#endif
	{"VideoCapFormat",	(Uint32 *)&gParam.params.encodeParam.VideoParams.VideoCapFormat,		0x11},
	{"VideoCapFrameRate",	(Uint32 *)&gParam.params.encodeParam.VideoParams.VideoCapFrameRate,		0x12},
	{"VideoCodecOutputFormat",	(Uint32 *)&gParam.params.encodeParam.VideoParams.VideoCodecOutputFormat,		0x10},
	{"VideoOutputWidth",	(Uint32 *)&gParam.params.encodeParam.VideoParams.VideoOutputWidth,		0},
	{"VideoOutputHeight",	(Uint32 *)&gParam.params.encodeParam.VideoParams.VideoOutputHeight,		0},
	{"VideoOutputMode",	(Uint32 *)&gParam.params.encodeParam.VideoParams.VideoOutputMode,		0x11},
	{"VideoOutputFrameRate",	(Uint32 *)&gParam.params.encodeParam.VideoParams.VideoOutputFrameRate,		0x12},
	{"VideoOutputBitrate",	(Uint32 *)&gParam.params.encodeParam.VideoParams.VideoOutputBitrate,		0},
	{"RateControl",	(Uint32 *)&gParam.params.encodeParam.VideoParams.RateControl,		-1},
#ifdef HAUPPAUGE
	{"VideoRateControl",	(Uint32 *)&gParam.params.encodeParam.VideoParams.RateControl,		0x13},
#endif
	{"VBRMin",	(Uint32 *)&gParam.params.encodeParam.VideoParams.VBRMin,		0},
	{"VBRMax",	(Uint32 *)&gParam.params.encodeParam.VideoParams.VBRMax,		0},
	{"VideoCodingMode",	(Uint32 *)&gParam.params.encodeParam.VideoParams.CodingMode,		0x14},
	{"VideoProfile",	(Uint32 *)&gParam.params.encodeParam.VideoParams.Profile,		0x15},
	{"VideoLevel",	(Uint32 *)&gParam.params.encodeParam.VideoParams.Level,		0},
	{"VideoTSBitrate",	(Uint32 *)&gParam.params.encodeParam.VideoParams.TSBitrate,		0},
	{"VideoLatency",	(Uint32 *)&gParam.params.encodeParam.VideoParams.Latency,		0x16},
	{"InsertIFrame",	(Uint32 *)&gParam.params.encodeParam.VideoParams.bInsertIFrame,		0},
	{"CabacCoding",	    (Uint32 *)&gParam.params.encodeParam.VideoParams.bCabacCoding,		0},
	{"DeblockFilter",	(Uint32 *)&gParam.params.encodeParam.VideoParams.bDeblockFilter,		0},
	{"NumBFrames",	    (Uint32 *)&gParam.params.encodeParam.VideoParams.NumBFrames,		5},
    {"bIasIDR",          (Uint32 *)&gParam.params.encodeParam.VideoParams.bIasIDR,     0},

    {"PMTVersion",               (Uint32 *)&gParam.params.encodeParam.VideoParams.PMTVersion,       0},
    {"bAdaptiveSmoothing",       (Uint32 *)&gParam.params.encodeParam.VideoParams.bAdaptiveSmoothing,     0},
    {"HorizontalSmoothingOffset",(Uint32 *)&gParam.params.encodeParam.VideoParams.HorizontalSmoothingOffset,     0},
    {"VerticalSmoothingOffset",  (Uint32 *)&gParam.params.encodeParam.VideoParams.VerticalSmoothingOffset,     0},
    {"GOPSize",                  (Uint32 *)&gParam.params.encodeParam.VideoParams.GOPSize,     0},


	{"AudioCapSource",	(Uint32 *)&gParam.params.encodeParam.AudioParams.AudioCapSource,		0x25},
	{"AudioCapSampleRate",	(Uint32 *)&gParam.params.encodeParam.AudioParams.AudioCapSampleRate,		0x21},
	{"AudioCapSPDIFInput",	(Uint32 *)&gParam.params.encodeParam.AudioParams.AudioCapSPDIFInput,		0},
	{"AudioCapMode",	(Uint32 *)&gParam.params.encodeParam.AudioParams.AudioCapMode,		0},
	{"AudioStreamID",	(Uint32 *)&gParam.params.encodeParam.AudioParams.StreamID,		3},
	{"AudioOutputPID",	(Uint32 *)&gParam.params.encodeParam.AudioParams.OutputPID,		3},
	{"AudioCodecOutputFormat",	(Uint32 *)&gParam.params.encodeParam.AudioParams.AudioCodecOutputFormat,		0x20},
	{"AudioOutputMode",	(Uint32 *)&gParam.params.encodeParam.AudioParams.AudioOutputMode,		0x24},
	{"AudioOutputSamplingRate",	(Uint32 *)&gParam.params.encodeParam.AudioParams.AudioOutputSamplingRate,		0x21},
	{"AudioOutputBitrate",	(Uint32 *)&gParam.params.encodeParam.AudioParams.AudioOutputBitrate,		0x22},

    {"AudioCapMode_1",	  (Uint32 *)&gParam.params.encodeParam.AudioParams.AudioCapMode_1,		0},
    {"AudioStreamID_1",	  (Uint32 *)&gParam.params.encodeParam.AudioParams.StreamID_1,		3},
    {"AudioOutputPID_1",  (Uint32 *)&gParam.params.encodeParam.AudioParams.OutputPID_1,		3},
    {"AudioCodecOutputFormat_1",	(Uint32 *)&gParam.params.encodeParam.AudioParams.AudioCodecOutputFormat_1,		0x20},
    {"AudioOutputMode_1", (Uint32 *)&gParam.params.encodeParam.AudioParams.AudioOutputMode_1,		0x24},
    {"AudioOutputSamplingRate_1", (Uint32 *)&gParam.params.encodeParam.AudioParams.AudioOutputSamplingRate_1,		0x21},
    {"AudioOutputBitrate_1", (Uint32 *)&gParam.params.encodeParam.AudioParams.AudioOutputBitrate_1,		0x22},
        
    {"bAudioPassthru",	 (Uint32 *)&gParam.params.encodeParam.AudioParams.bAudioPassthru,	-1},
    {"bAudioPassthru_1", (Uint32 *)&gParam.params.encodeParam.AudioParams.bAudioPassthru_1,	-1},

    {"bAGCEnable",           (Uint32 *)&gParam.params.encodeParam.AudioParams.bAGCEnable,    -1},
#ifdef HAUPPAUGE
    {"AudioMaxSample",           (Uint32 *)&gParam.params.encodeParam.AudioParams.MaxSample,    5},
    {"AudioAGCEnable",           (Uint32 *)&gParam.params.encodeParam.AudioParams.bAGCEnable,    0},
    {"AudioPassthru",	(Uint32 *)&gParam.params.encodeParam.AudioParams.bAudioPassthru,		0},
    {"AudioPassthru_1",	(Uint32 *)&gParam.params.encodeParam.AudioParams.bAudioPassthru_1,		0},
#endif

	{"errorLoggingEnable",	(Uint32 *)&gParam.params.encodeParam.LogParams.errorLoggingEnable,		2},

#ifndef DRIVER_BUILD
        {"VideoLogoHeight", (Uint32 *)&logoParam.height, 0},
        {"VideoLogoIndex", (Uint32 *)&logoParam.logoIndex, 0},
        {"VideoLogowidth", (Uint32 *)&logoParam.width, 0},
        {"VideoLogoPosX", (Uint32 *)&logoParam.x, 0},
        {"VideoLogoPosY", (Uint32 *)&logoParam.y, 0},
        {"VideoLogoOnOff", (Uint32 *)&logoOnOff, 0},
        {"VideoLogoOnOffIndex", (Uint32 *)&VideoLogoIndex, 0},
    {"SleepTimer",          (Uint32 *)&gSleepTimer,               0},   
	{"UpGradeFWFilePath",	(Uint32 *)gUpGradeFWFile,			  1}, //FGR - BUGBUG used by HAPI_FWUpgrade
	{"TargetFlashAddress",	(Uint32 *)&gTargetAddress,			  0}, //FGR - BUGBUG used by HAPI_FWUpgrade
	{"SwapMode",			(Uint32 *)&gSwapMode,				  0}, //FGR - BUGBUG used by HAPI_FWUpgrade
	{"BytesPerTransfer",	(Uint32 *)&gBytesPerTransfer,		  0}, //FGR - BUGBUG used by HAPI_FWUpgrade
        {"GpioPinId", (Uint32 *)&GpiopinId},
        {"GpioPinVal", (Uint32 *)&GpioVal},
	{"MaxParams",&MaxParams, 0}//must be added at the end of the table
#else
	{"MaxParams", NULL, 0}//must be end of the table
#endif

};

static Parameter_Map_Item TranscodeParamMapTable[] = 
{
#ifndef DRIVER_BUILD//HAUPPAUGE
	{"InputFilePath",		(Uint32 *)gFileIO.input_av_file,		1},
	{"OutputFileEnable",	&gFileIO.dump_output_file,	0},
	{"OutputFilePath",		(Uint32 *)gFileIO.output_av_file,		1},
	{"LogOutputEnable",		&gFileIO.enable_debug_log,	0},
	{"LogFilePath",		 	(Uint32 *)gFileIO.debug_log_file,		1},

	{"CommBusType",			(Uint32 *)&gCommBusType,				0},

        {"AudioInputPort",      (Uint32 *)&gBootConfig.AudioInputPort,  0},
        {"AudioOutputPort",     (Uint32 *)&gBootConfig.AudioOutputPort, 0},
        {"VideoInputPort",      (Uint32 *)&gBootConfig.VideoInputPort,  0},
        {"VideoOutputPort",     (Uint32 *)&gBootConfig.VideoOutputPort, 0},
	{"EndianSwap",			&gEndianSwap,				0},
#endif
	
    {"InputAudioPID",           (Uint32 *)&gParam.InputAudioPID,      3},
    {"InputVideoPID",           (Uint32 *)&gParam.InputVideoPID,      3},
    {"InputPCRPID",             (Uint32 *)&gParam.InputPCRPID,        3},
    {"SubtitlePID",             (Uint32 *)&gParam.SubtitlePID,        3},
    {"TeletextPID",             (Uint32 *)&gParam.TeletextPID,        3},

    {"OutputPCRPID",            (Uint32 *)&gParam.OutputPCRPID,       3},

	{"ParamType",			    (Uint32 *)&gParam.ParamType,			4},
	{"VideoCodecInputFormat",	(Uint32 *)&gParam.params.transcodeParam.VideoParams.VideoCodecInputFormat,		0x10},
	{"VideoCodecOutputFormat",	(Uint32 *)&gParam.params.transcodeParam.VideoParams.VideoCodecOutputFormat,		0x10},
	{"VideoOutputWidth",		(Uint32 *)&gParam.params.transcodeParam.VideoParams.VideoOutputWidth,			0},
	{"VideoOutputHeight",		(Uint32 *)&gParam.params.transcodeParam.VideoParams.VideoOutputHeight,			0},
	{"VideoOutputMode",			(Uint32 *)&gParam.params.transcodeParam.VideoParams.VideoOutputMode,			0x11},
	{"VideoOutputFrameRate",	(Uint32 *)&gParam.params.transcodeParam.VideoParams.VideoOutputFrameRate,		0x12},
	{"VideoOutputBitrate",		(Uint32 *)&gParam.params.transcodeParam.VideoParams.VideoOutputBitrate,			0},
	{"VideoRateControlMode",    (Uint32 *)&gParam.params.transcodeParam.VideoParams.RateControl,    			-1},
#ifdef HAUPPAUGE
	{"VideoRateControl",    (Uint32 *)&gParam.params.transcodeParam.VideoParams.RateControl,    			0x13},
#endif
	{"VideoCodingMode",	    (Uint32 *)&gParam.params.transcodeParam.VideoParams.CodingMode,     0x14},
	{"VideoVBRMin",		    (Uint32 *)&gParam.params.transcodeParam.VideoParams.VBRMin,     0},
	{"VideoVBRMax",		    (Uint32 *)&gParam.params.transcodeParam.VideoParams.VBRMax,     0},
	{"VideoProfile",	    (Uint32 *)&gParam.params.transcodeParam.VideoParams.Profile,     0x15},
	{"VideoLevel",		    (Uint32 *)&gParam.params.transcodeParam.VideoParams.Level,       0x19},
	{"VideoOutputTSBitrate",	    (Uint32 *)&gParam.params.transcodeParam.VideoParams.TSBitrate,     0},	
	{"VideoLatency",				(Uint32 *)&gParam.params.transcodeParam.VideoParams.Latency,     0x16},	
    {"OutputVideoPID",          (Uint32 *)&gParam.params.transcodeParam.VideoParams.OutputPID,     -1},
    {"VideobInsertIFrame",  (Uint32 *)&gParam.params.transcodeParam.VideoParams.bInsertIFrame,     -1},
    {"VideobCabacCoding",   (Uint32 *)&gParam.params.transcodeParam.VideoParams.bCabacCoding,     -1},
    {"VideobDeblockFilter", (Uint32 *)&gParam.params.transcodeParam.VideoParams.bDeblockFilter,     -1},
    {"VideoNumBFrames",     (Uint32 *)&gParam.params.transcodeParam.VideoParams.NumBFrames,     -1},

#ifdef HAUPPAUGE
    {"VideoOutputPID",  (Uint32 *)&gParam.params.transcodeParam.VideoParams.OutputPID,     3},
	//FGR - rename these
	{"InsertIFrame",	(Uint32 *)&gParam.params.transcodeParam.VideoParams.bInsertIFrame,		0},
	{"CabacCoding",	    (Uint32 *)&gParam.params.transcodeParam.VideoParams.bCabacCoding,		0},
	{"DeblockFilter",	(Uint32 *)&gParam.params.transcodeParam.VideoParams.bDeblockFilter,		0},
	{"NumBFrames",		(Uint32 *)&gParam.params.transcodeParam.VideoParams.NumBFrames,		5},
    {"bIasIDR",         (Uint32 *)&gParam.params.transcodeParam.VideoParams.bIasIDR,     0},
#endif
    {"PMTVersion",               (Uint32 *)&gParam.params.transcodeParam.VideoParams.PMTVersion,       0},
    {"bAdaptiveSmoothing",       (Uint32 *)&gParam.params.transcodeParam.VideoParams.bAdaptiveSmoothing,     0},
    {"HorizontalSmoothingOffset",(Uint32 *)&gParam.params.transcodeParam.VideoParams.HorizontalSmoothingOffset,     0},
    {"VerticalSmoothingOffset",  (Uint32 *)&gParam.params.transcodeParam.VideoParams.VerticalSmoothingOffset,     0},
    {"GOPSize",                  (Uint32 *)&gParam.params.transcodeParam.VideoParams.GOPSize,     0},

	{"AudioCodecInputFormat",	(Uint32 *)&gParam.params.transcodeParam.AudioParams.AudioCodecInputFormat,		0x20},
	{"AudioOutputMode",         (Uint32 *)&gParam.params.transcodeParam.AudioParams.AudioOutputMode,			0x24},
	{"AudioOutputSamplingRate",	(Uint32 *)&gParam.params.transcodeParam.AudioParams.AudioOutputSamplingRate,	0x21},
	{"AudioOutputBitrate",		(Uint32 *)&gParam.params.transcodeParam.AudioParams.AudioOutputBitrate,			0x22},
	{"AudioCodecOutputFormat",	(Uint32 *)&gParam.params.transcodeParam.AudioParams.AudioCodecOutputFormat,		0x20},
    {"bAudioPassthru",	        (Uint32 *)&gParam.params.transcodeParam.AudioParams.bAudioPassthru,		-1},
    {"OutputAudioPID",          (Uint32 *)&gParam.params.transcodeParam.AudioParams.OutputPID,     -1},
#ifdef HAUPPAUGE
    {"AudioMaxSample",           (Uint32 *)&gParam.params.transcodeParam.AudioParams.MaxSample,    5},
    {"AudioPassthru",	(Uint32 *)&gParam.params.transcodeParam.AudioParams.bAudioPassthru,		0},
    {"AudioOutputPID",          (Uint32 *)&gParam.params.transcodeParam.AudioParams.OutputPID,     3},
#endif

#ifndef DRIVER_BUILD//HAUPPAUGE
        {"GpioPinId", (Uint32 *)&GpiopinId},
        {"GpioPinVal", (Uint32 *)&GpioVal},

    {"SleepTimer",          (Uint32 *)&gSleepTimer,               0},
	{"MaxParams",&MaxParams, 0}//must be added at the end of the table
#else
	{"MaxParams", NULL, 0}//must be end of the table
#endif
};

static Param_Bitmask_Item EncodeParamBitmaskTable[] = 
{
	//add for encode params
    {"OutputPCRPID",			(Uint32 *)&gParam.bitMask,		HWAPI_BM_MSG_SET_PARAM_OUTPUT_PCR_PID},
//  {"IoBoardType",	(Uint32 *)&gParam.params.encodeParam.bitMask,		HWAPI_BM_MSG_SET_PARAM_IO_BOARD_TYPE},
     // add encodeparams.video params
	{"VideoStreamID",		(Uint32 *)&gParam.params.encodeParam.VideoParams.bitMask,		HWAPI_BM_MSG_ENCODE_VIDEO_STREAM_ID},
	{"VideoOutputPID",		(Uint32 *)&gParam.params.encodeParam.VideoParams.bitMask,		HWAPI_BM_MSG_ENCODE_VIDEO_OUTPUT_PID},
	{"VideoCapSource",		(Uint32 *)&gParam.params.encodeParam.VideoParams.bitMask,		HWAPI_BM_MSG_ENCODE_VIDEO_CAPTURE_SOURCE},
	{"VideoCapWidth",		(Uint32 *)&gParam.params.encodeParam.VideoParams.bitMask,		HWAPI_BM_MSG_ENCODE_VIDEO_CAPTURE_WIDTH},
//	{"VIdeoCapHeight",		(Uint32 *)&gParam.params.encodeParam.VideoParams.bitMask,		HWAPI_BM_MSG_ENCODE_VIDEO_CAPTURE_HEIGHT},
	{"VideoCapHeight",		(Uint32 *)&gParam.params.encodeParam.VideoParams.bitMask,		HWAPI_BM_MSG_ENCODE_VIDEO_CAPTURE_HEIGHT},
	{"VideoCapFormat",		(Uint32 *)&gParam.params.encodeParam.VideoParams.bitMask,		HWAPI_BM_MSG_ENCODE_VIDEO_CAPTURE_FORMAT},
	{"VideoCapFrameRate",	(Uint32 *)&gParam.params.encodeParam.VideoParams.bitMask,		HWAPI_BM_MSG_ENCODE_VIDEO_CAPTURE_FRAME_RATE},
	{"VideoCodecOutputFormat",	(Uint32 *)&gParam.params.encodeParam.VideoParams.bitMask,		HWAPI_BM_MSG_ENCODE_VIDEO_CODEC_OUTPUT_FORMAT},
	{"VideoOutputWidth",	(Uint32 *)&gParam.params.encodeParam.VideoParams.bitMask,		HWAPI_BM_MSG_ENCODE_VIDEO_OUTPUT_WIDTH},
	{"VideoOutputHeight",	(Uint32 *)&gParam.params.encodeParam.VideoParams.bitMask,		HWAPI_BM_MSG_ENCODE_VIDEO_OUTPUT_HEIGHT},
	{"VideoOutputMode",		(Uint32 *)&gParam.params.encodeParam.VideoParams.bitMask,		HWAPI_BM_MSG_ENCODE_VIDEO_OUTPUT_MODE},
	{"VideoOutputFrameRate",(Uint32 *)&gParam.params.encodeParam.VideoParams.bitMask,		HWAPI_BM_MSG_ENCODE_VIDEO_OUTPUT_FRAME_RATE},
	{"VideoOutputBitrate",	(Uint32 *)&gParam.params.encodeParam.VideoParams.bitMask,		HWAPI_BM_MSG_ENCODE_VIDEO_OUTPUT_BIT_RATE},
	{"RateControl",			(Uint32 *)&gParam.params.encodeParam.VideoParams.bitMask,		HWAPI_BM_MSG_ENCODE_VIDEO_RATE_CONTROL},
#ifdef HAUPPAUGE
	{"VideoRateControl",	(Uint32 *)&gParam.params.encodeParam.VideoParams.bitMask,		HWAPI_BM_MSG_ENCODE_VIDEO_RATE_CONTROL},
#endif
	{"VBRMin",				(Uint32 *)&gParam.params.encodeParam.VideoParams.bitMask,		HWAPI_BM_MSG_ENCODE_VIDEO_VBR_MIN},
	{"VBRMax",				(Uint32 *)&gParam.params.encodeParam.VideoParams.bitMask,		HWAPI_BM_MSG_ENCODE_VIDEO_VBR_MAX},
	{"VideoCodingMode",		(Uint32 *)&gParam.params.encodeParam.VideoParams.bitMask,		HWAPI_BM_MSG_ENCODE_VIDEO_CODING_MODE},
	{"VideoProfile",		(Uint32 *)&gParam.params.encodeParam.VideoParams.bitMask,		HWAPI_BM_MSG_ENCODE_VIDEO_PROFILE},
	{"VideoLevel",			(Uint32 *)&gParam.params.encodeParam.VideoParams.bitMask,		HWAPI_BM_MSG_ENCODE_VIDEO_LEVEL},
	{"VideoTSBitrate",		(Uint32 *)&gParam.params.encodeParam.VideoParams.bitMask,		HWAPI_BM_MSG_ENCODE_VIDEO_TS_BITRATE},
	{"VideoLatency",		(Uint32 *)&gParam.params.encodeParam.VideoParams.bitMask,		HWAPI_BM_MSG_ENCODE_VIDEO_LATENCY},
//    {"LoopFilter",		(Uint32 *)&gParam.params.encodeParam.VideoParams.bitMask,		HWAPI_BM_MSG_ENCODE_VIDEO_LOOPFILTER},
    {"InsertIFrame",		(Uint32 *)&gParam.params.encodeParam.VideoParams.bitMask,		HWAPI_BM_MSG_ENCODE_INSERT_IFRAME},
    {"CabacCoding",			(Uint32 *)&gParam.params.encodeParam.VideoParams.bitMask,		HWAPI_BM_MSG_ENCODE_CABAC_CODING},
    {"DeblockFilter",		(Uint32 *)&gParam.params.encodeParam.VideoParams.bitMask,		HWAPI_BM_MSG_ENCODE_DEBLOCK_FILTER},
    {"NumBFrames",			(Uint32 *)&gParam.params.encodeParam.VideoParams.bitMask,		HWAPI_BM_MSG_ENCODE_NUM_BFRAMENUM},
    {"bIasIDR",             (Uint32 *)&gParam.params.encodeParam.VideoParams.bitMask,       HWAPI_BM_MSG_ENCODE_BIASIDR},

    {"PMTVersion",                (Uint32 *)&gParam.params.encodeParam.VideoParams.bitMask,    HWAPI_BM_MSG_ENCODE_PMT_VERSION},
    {"bAdaptiveSmoothing",        (Uint32 *)&gParam.params.encodeParam.VideoParams.bitMask,    HWAPI_BM_MSG_ENCODE_BSMOOTHING},
    {"HorizontalSmoothingOffset", (Uint32 *)&gParam.params.encodeParam.VideoParams.bitMask,    HWAPI_BM_MSG_ENCODE_HSMOOTHOFF},
    {"VerticalSmoothingOffset",   (Uint32 *)&gParam.params.encodeParam.VideoParams.bitMask,    HWAPI_BM_MSG_ENCODE_VSMOOTHOFF},
    {"GOPSize",                   (Uint32 *)&gParam.params.encodeParam.VideoParams.bitMask,    HWAPI_BM_MSG_ENCODE_GOPSIZE},
 // end add encodeparams.video params
	
// add encodeparams.audio params

	{"AudioStreamID",		(Uint32 *)&gParam.params.encodeParam.AudioParams.bitMask,		HWAPI_BM_MSG_ENCODE_AUDIO_STREAM_ID},
	{"AudioOutputPID",		(Uint32 *)&gParam.params.encodeParam.AudioParams.bitMask,		HWAPI_BM_MSG_ENCODE_AUDIO_OUTPUT_PID},
	{"AudioCapSource",		(Uint32 *)&gParam.params.encodeParam.AudioParams.bitMask,		HWAPI_BM_MSG_ENCODE_AUDIO_CAPTURE_SOURCE},
	{"AudioCapSampleRate",	(Uint32 *)&gParam.params.encodeParam.AudioParams.bitMask,		HWAPI_BM_MSG_ENCODE_AUDIO_CAPTURE_SAMPLE_RATE},
	{"AudioCapMode",		(Uint32 *)&gParam.params.encodeParam.AudioParams.bitMask,		HWAPI_BM_MSG_ENCODE_AUDIO_CAPTURE_MODE},
	{"AudioCapSPDIFInput",	(Uint32 *)&gParam.params.encodeParam.AudioParams.bitMask,		HWAPI_BM_MSG_ENCODE_AUDIO_CAPTURE_SPDIF_INPUT},
	{"AudioCodecOutputFormat",	(Uint32 *)&gParam.params.encodeParam.AudioParams.bitMask,		HWAPI_BM_MSG_ENCODE_AUDIO_CODEC_OUTPUT_FORMAT},
	{"AudioOutputMode",		(Uint32 *)&gParam.params.encodeParam.AudioParams.bitMask,		HWAPI_BM_MSG_ENCODE_AUDIO_OUTPUT_MODE},
	{"AudioOutputSamplingRate",	(Uint32 *)&gParam.params.encodeParam.AudioParams.bitMask,		HWAPI_BM_MSG_ENCODE_AUDIO_OUTPUT_SAMPLE_RATE},
	{"AudioOutputBitrate",	(Uint32 *)&gParam.params.encodeParam.AudioParams.bitMask,		HWAPI_BM_MSG_ENCODE_AUDIO_OUTPUT_BITRATE},

    {"bAudioPassthru",		(Uint32 *)&gParam.params.encodeParam.AudioParams.bitMask,		HWAPI_BM_MSG_ENCODE_AUDIO_ENCODE_MODE},
    {"bAudioPassthru_1",	(Uint32 *)&gParam.params.encodeParam.AudioParams.bitMask,		HWAPI_BM_MSG_ENCODE_AUDIO_ENCODE_MODE_1},

    {"AudioStreamID_1",	    (Uint32 *)&gParam.params.encodeParam.AudioParams.bitMask,		HWAPI_BM_MSG_ENCODE_AUDIO_STREAM_ID_1},
    {"AudioOutputPID_1",	(Uint32 *)&gParam.params.encodeParam.AudioParams.bitMask,		HWAPI_BM_MSG_ENCODE_AUDIO_OUTPUT_PID_1},
    {"AudioCapMode_1",	    (Uint32 *)&gParam.params.encodeParam.AudioParams.bitMask,		HWAPI_BM_MSG_ENCODE_AUDIO_CAPTURE_MODE_1},
    {"AudioCodecOutputFormat_1",	(Uint32 *)&gParam.params.encodeParam.AudioParams.bitMask,		 HWAPI_BM_MSG_ENCODE_AUDIO_CODEC_OUTPUT_FORMAT_1},
    {"AudioOutputMode_1",	(Uint32 *)&gParam.params.encodeParam.AudioParams.bitMask,		HWAPI_BM_MSG_ENCODE_AUDIO_OUTPUT_MODE_1},
    {"AudioOutputSamplingRate_1",	(Uint32 *)&gParam.params.encodeParam.AudioParams.bitMask,		HWAPI_BM_MSG_ENCODE_AUDIO_OUTPUT_SAMPLE_RATE_1},
    {"AudioOutputBitrate_1",(Uint32 *)&gParam.params.encodeParam.AudioParams.bitMask,		HWAPI_BM_MSG_ENCODE_AUDIO_OUTPUT_BITRATE_1},
        

#ifdef HAUPPAUGE
    {"AudioPassthru",		(Uint32 *)&gParam.params.encodeParam.AudioParams.bitMask,		HWAPI_BM_MSG_ENCODE_AUDIO_ENCODE_MODE},
    {"AudioPassthru_1",	    (Uint32 *)&gParam.params.encodeParam.AudioParams.bitMask,		HWAPI_BM_MSG_ENCODE_AUDIO_ENCODE_MODE_1},
    {"AudioAGCEnable",      (Uint32 *)&gParam.params.encodeParam.AudioParams.bitMask,       HWAPI_BM_MSG_ENCODE_AUDIO_AGC_ENABLE},
#endif
    {"bAGCEnable",           (Uint32 *)&gParam.params.encodeParam.AudioParams.bitMask,    HWAPI_BM_MSG_ENCODE_AUDIO_AGC_ENABLE},
    {"AudioMaxSample",      (Uint32 *)&gParam.params.encodeParam.AudioParams.bitMask,       HWAPI_BM_MSG_ENCODE_AUDIO_MAXSAMPLE},
	
// end add encodeparams.audio params

//TODO: (MAY SHOULD ADD SOMETHING ACCORDDING TO hapicommon.H)
	{"errorLoggingEnable",	(Uint32 *)&gParam.params.encodeParam.LogParams.bitMask,		HWAPI_BM_MSG_ENCODE_ERROR_LOG_ENABLE},
#ifndef DRIVER_BUILD
	{"MaxParams",&MaxParams, 0}//must be added at the end of the table
#else
	{"MaxParams", NULL, 0}//must be added at the end of the table
#endif
	//end add encode params
};

static Param_Bitmask_Item TranscodeParamBitmaskTable[] = 
{
    {"InputAudioPID",		(Uint32 *)&gParam.bitMask,	    HWAPI_BM_MSG_SET_PARAM_INPUT_AUDIO_PID},
	{"InputVideoPID",		(Uint32 *)&gParam.bitMask,		HWAPI_BM_MSG_SET_PARAM_INPUT_VIDEO_PID},
	{"InputPCRPID",			(Uint32 *)&gParam.bitMask,		HWAPI_BM_MSG_SET_PARAM_INPUT_PCR_PID},
	{"SubtitlePID",			(Uint32 *)&gParam.bitMask,		HWAPI_BM_MSG_SET_PARAM_SUBTITLE_PID},
	{"TeletextPID",			(Uint32 *)&gParam.bitMask,		HWAPI_BM_MSG_SET_PARAM_TELETEXT_PID},
    {"OutputPCRPID",		(Uint32 *)&gParam.bitMask,		HWAPI_BM_MSG_SET_PARAM_OUTPUT_PCR_PID},
//  {"bTSSerial",			&gParam.bitMask,		HWAPI_BM_MSG_SET_PARAM_B_TS_SERIAL},
//  {"bChMsbFirst",			&gParam.bitMask,		HWAPI_BM_MSG_SET_PARAM_B_CH_MSB_FIRST},

	{"VideoCodecInputFormat",	(Uint32 *)&gParam.params.transcodeParam.VideoParams.bitMask,	HWAPI_BM_MSG_TRANSCODE_VIDEO_CODEC_INPUT_FORMAT},
	{"VideoCodecOutputFormat",	(Uint32 *)&gParam.params.transcodeParam.VideoParams.bitMask,	HWAPI_BM_MSG_TRANSCODE_VIDEO_CODEC_OUTPUT_FORMAT},
	{"VideoOutputWidth",		(Uint32 *)&gParam.params.transcodeParam.VideoParams.bitMask,	HWAPI_BM_MSG_TRANSCODE_VIDEO_OUTPUT_WIDTH},
	{"VideoOutputHeight",		(Uint32 *)&gParam.params.transcodeParam.VideoParams.bitMask,	HWAPI_BM_MSG_TRANSCODE_VIDEO_OUTPUT_HEIGHT},
	{"VideoOutputMode",			(Uint32 *)&gParam.params.transcodeParam.VideoParams.bitMask,	HWAPI_BM_MSG_TRANSCODE_VIDEO_OUTPUT_MODE},
	{"VideoOutputFrameRate",	(Uint32 *)&gParam.params.transcodeParam.VideoParams.bitMask,	HWAPI_BM_MSG_TRANSCODE_VIDEO_OUTPUT_FRAME_RATE},
	{"VideoOutputBitrate",		(Uint32 *)&gParam.params.transcodeParam.VideoParams.bitMask,	HWAPI_BM_MSG_TRANSCODE_VIDEO_OUTPUT_BITRATE},
	{"VideoRateControlMode",    (Uint32 *)&gParam.params.transcodeParam.VideoParams.bitMask,    HWAPI_BM_MSG_TRANSCODE_RATE_CONTROL},
#ifdef HAUPPAUGE
	{"VideoRateControl",    (Uint32 *)&gParam.params.transcodeParam.VideoParams.bitMask,    HWAPI_BM_MSG_TRANSCODE_RATE_CONTROL},
#endif
	{"VideoCodingMode",	    (Uint32 *)&gParam.params.transcodeParam.VideoParams.bitMask,     HWAPI_BM_MSG_TRANSCODE_CODING_MODE},
	{"VideoVBRMin",		    (Uint32 *)&gParam.params.transcodeParam.VideoParams.bitMask,     HWAPI_BM_MSG_TRANSCODE_VBR_MIN},
	{"VideoVBRMax",		    (Uint32 *)&gParam.params.transcodeParam.VideoParams.bitMask,     HWAPI_BM_MSG_TRANSCODE_VBR_MAX},
	{"VideoProfile",	    (Uint32 *)&gParam.params.transcodeParam.VideoParams.bitMask,     HWAPI_BM_MSG_TRANSCODE_PROFILE},
	{"VideoLevel",		    (Uint32 *)&gParam.params.transcodeParam.VideoParams.bitMask,     HWAPI_BM_MSG_TRANSCODE_LEVEL},
	{"VideoOutputTSBitrate",(Uint32 *)&gParam.params.transcodeParam.VideoParams.bitMask,    HWAPI_BM_MSG_TRANSCODE_TS_BITRATE},	
	{"VideoLatency",	    (Uint32 *)&gParam.params.transcodeParam.VideoParams.bitMask,    HWAPI_BM_MSG_TRANSCODE_LATENCY},	
	{"OutputVideoPID",		(Uint32 *)&gParam.params.transcodeParam.VideoParams.bitMask, HWAPI_BM_MSG_TRANSCODE_VIDEO_PID},
	{"VideobInsertIFrame",  (Uint32 *)&gParam.params.transcodeParam.VideoParams.bitMask,    HWAPI_BM_MSG_TRANSCODE_INSERT_IFRAME},
	{"VideobCabacCoding",   (Uint32 *)&gParam.params.transcodeParam.VideoParams.bitMask,    HWAPI_BM_MSG_TRANSCODE_CABAC_CODING},
	{"VideobDeblockFilter", (Uint32 *)&gParam.params.transcodeParam.VideoParams.bitMask,    HWAPI_BM_MSG_TRANSCODE_DEBLOCK_FILTER},
	{"VideoNumBFrames",     (Uint32 *)&gParam.params.transcodeParam.VideoParams.bitMask,    HWAPI_BM_MSG_TRANSCODE_NUM_BFRAMENUM},
#ifdef HAUPPAUGE
	{"VideoOutputPID",		(Uint32 *)&gParam.params.transcodeParam.VideoParams.bitMask, HWAPI_BM_MSG_TRANSCODE_VIDEO_PID},
	//FGR - rename these
	{"InsertIFrame",	(Uint32 *)&gParam.params.transcodeParam.VideoParams.bitMask,	HWAPI_BM_MSG_TRANSCODE_INSERT_IFRAME},
	{"CabacCoding",	    (Uint32 *)&gParam.params.transcodeParam.VideoParams.bitMask,	HWAPI_BM_MSG_TRANSCODE_CABAC_CODING},
	{"DeblockFilter",	(Uint32 *)&gParam.params.transcodeParam.VideoParams.bitMask,	HWAPI_BM_MSG_TRANSCODE_DEBLOCK_FILTER},
	{"NumBFrames",		(Uint32 *)&gParam.params.transcodeParam.VideoParams.bitMask,	HWAPI_BM_MSG_TRANSCODE_NUM_BFRAMENUM},
    {"bIasIDR",         (Uint32 *)&gParam.params.transcodeParam.VideoParams.bitMask,    HWAPI_BM_MSG_TRANSCODE_BIASIDR},

    {"PMTVersion",               (Uint32 *)&gParam.params.transcodeParam.VideoParams.bitMask,    HWAPI_BM_MSG_TRANSCODE_PMT_VERSION},
    {"bAdaptiveSmoothing",       (Uint32 *)&gParam.params.transcodeParam.VideoParams.bitMask,    HWAPI_BM_MSG_TRANSCODE_BSMOOTHING},
    {"HorizontalSmoothingOffset",(Uint32 *)&gParam.params.transcodeParam.VideoParams.bitMask,    HWAPI_BM_MSG_TRANSCODE_HSMOOTHOFF},
    {"VerticalSmoothingOffset",  (Uint32 *)&gParam.params.transcodeParam.VideoParams.bitMask,    HWAPI_BM_MSG_TRANSCODE_VSMOOTHOFF},
    {"GOPSize",                  (Uint32 *)&gParam.params.transcodeParam.VideoParams.bitMask,    HWAPI_BM_MSG_TRANSCODE_GOPSIZE},
#endif

	{"AudioCodecInputFormat",	(Uint32 *)&gParam.params.transcodeParam.AudioParams.bitMask,	HWAPI_BM_MSG_TRANSCODE_AUDIO_CODEC_INPUT_FORMAT},
	{"AudioOutputMode",			(Uint32 *)&gParam.params.transcodeParam.AudioParams.bitMask,	HWAPI_BM_MSG_TRANSCODE_AUDIO_OUTPUT_MODE},
	{"AudioOutputSamplingRate",	(Uint32 *)&gParam.params.transcodeParam.AudioParams.bitMask,	HWAPI_BM_MSG_TRANSCODE_AUDIO_OUTPUT_SAMP_RATE},
	{"AudioOutputBitrate",		(Uint32 *)&gParam.params.transcodeParam.AudioParams.bitMask,	HWAPI_BM_MSG_TRANSCODE_AUDIO_OUTPUT_BITRATE},
	{"AudioCodecOutputFormat",	(Uint32 *)&gParam.params.transcodeParam.AudioParams.bitMask,	HWAPI_BM_MSG_TRANSCODE_AUDIO_CODEC_OUTPUT_FORMAT},
	{"OutputAudioPID",			(Uint32 *)&gParam.params.transcodeParam.AudioParams.bitMask,	HWAPI_BM_MSG_TRANSCODE_AUDIO_PID},
    {"bAudioPassthru",			(Uint32 *)&gParam.params.transcodeParam.AudioParams.bitMask,	HWAPI_BM_MSG_TRANSCODE_AUDIO_TRANSCODE_MODE},
#ifdef HAUPPAUGE
	{"AudioOutputPID",			(Uint32 *)&gParam.params.transcodeParam.AudioParams.bitMask,	HWAPI_BM_MSG_TRANSCODE_AUDIO_PID},
    {"AudioPassthru",			(Uint32 *)&gParam.params.transcodeParam.AudioParams.bitMask,	HWAPI_BM_MSG_TRANSCODE_AUDIO_TRANSCODE_MODE},
    {"AudioAGCEnable",          (Uint32 *)&gParam.params.transcodeParam.AudioParams.bitMask,    HWAPI_BM_MSG_TRANSCODE_AUDIO_AGC_ENABLE},
#endif
    {"bAGCEnable",           (Uint32 *)&gParam.params.transcodeParam.AudioParams.bitMask,    HWAPI_BM_MSG_TRANSCODE_AUDIO_AGC_ENABLE},
    {"AudioMaxSample",          (Uint32 *)&gParam.params.transcodeParam.AudioParams.bitMask,    HWAPI_BM_MSG_TRANSCODE_AUDIO_MAXSAMPLE},

#ifndef DRIVER_BUILD
	{"MaxParams",&MaxParams, 0}//must be added at the end of the table
#else
	{"MaxParams", NULL, 0}//must be added at the end of the table
#endif
};



CHapi::CHapi(USBBootMChip_t *pmchip) :
_p_data_transfer(NULL),
gHWapiHandle(NULL),
gHapi(NULL),
p_mchip(pmchip),
_hdmi_fmt(0),
_last_good_hdmi_fmt(0),
_last_PCR(0),
_isPaused(false),
_isStarted(false),
_API_ok(false),
_bling_count(0),
_LED_state(0),
_errCountdown(0),
_last_payload_time(0),
_last_payload_delta(0),
_first_payload_time(0),
_first_payload_delta(0),
_logo_mod_time(0),
_logo_used(0),
_logo_x_pos(-1),
_logo_y_pos(-1),
_serialNo(0)
{
	DbgLogInfo(("CHapi::CHapi(p_mchip=%p)\n", p_mchip));

	wrapMutexInit(&_mutex);

#ifdef HAPI_POWER_THREAD
	_polling_thread_object = NULL;
    KeInitializeEvent(
        &_polling_event_object,
        SynchronizationEvent,       // single wait satisfied resets it
        FALSE                       // not signaled 
    );

	_powered_up = FALSE;
	_power_down_delay = 10; //default to 10secs
	hcwGetRegistryDWORD("power_down_delay", &_power_down_delay);
	_power_time_left = _power_down_delay;
#endif
	_bling_options = p_mchip->getBling_Options();
	_bling_count = 0;

	gBoard_bus = siena;//plankton
	hcwGetRegistryDWORD("gBoard_bus", (LPDWORD)&gBoard_bus);

	memset(&m_extcapParams, 0, sizeof(m_extcapParams)); //reset Scaler, AudioEncoder APIs
	m_extcapParams.audioEncoder.sample_rate_441 = AUDIO_SAMPLE_RATE_44100;
	m_extcapParams.audioEncoder.sample_rate_48  = AUDIO_SAMPLE_RATE_48000;

	memset(&_lastParam, 0, sizeof(_lastParam)); //reset last committed encoder params
	_lastAR = (HAPI_ASPECT_RATIO)-1;

#if DBG
	verify_type_sizes();
#endif

#if DBG
	inFileHandle = NULL;
	outFileHandle = NULL;
#endif
	powerDownHW();
}

CHapi::~CHapi()
{
	_p_data_transfer = NULL;

#if DBG
	prv_close_file(inFileHandle);
	prv_close_file(outFileHandle);
#endif

#ifdef HAPI_POWER_THREAD
	stopPowerThread();
#endif
	lock();
	powerDownHW();
	unlock();
	
	p_mchip = NULL;
}

bool CHapi::powerUp()
{
	lock();
	if(gHapi){
		DbgLogInfo(("CHapi::powerUp() already powered up(hapiErr=%d _API_ok=%x)\n", hapiErr, _API_ok));
		if(hapiErr == HAPI_SUCCESS && _API_ok){
#ifdef HAPI_POWER_THREAD
			_powered_up = TRUE;
			//FGR - BUGBUG - do we want/need to reset default state of encoder somehow???
#endif
			unlock();
			return TRUE;
		}
		powerDownHW(); //force powerdown to reset previous Errors
	}
	hapiErr = HAPI_SUCCESS;
	p_mchip->UsbForceWFMode(0xFF);// was resetWFMode();
	p_mchip->resetUsbError();
	_LED_state = 0;

	memset(&_lastParam, 0, sizeof(_lastParam)); //reset last committed encoder params
	_lastAR = (HAPI_ASPECT_RATIO)-1;

	HapiAPIInit();
	if(gHapi && hapiErr == HAPI_SUCCESS)
		HapiFWDownload();
	if(gHapi && hapiErr == HAPI_SUCCESS)
		HapiFWBoot();
	if(gHapi && hapiErr == HAPI_SUCCESS){
		DbgLogInfo(("CHapi::powerUp() returns TRUE, gHapi=%p\n", gHapi));
#ifdef HAPI_POWER_THREAD
		_powered_up = TRUE;
#if DBG//allow us to change delay "on the fly" during debuging
		hcwGetRegistryDWORD("power_down_delay", &_power_down_delay);
#endif
		if(_power_down_delay){
			startPowerThread();
		}
#endif
		_API_ok = true;
		_LED_state = 0x04;//Power LED already on??

		unlock();
		return TRUE;
	}
	powerDownHW();
	DbgLogInfo(("CHapi::powerUp() returns FALSE\n"));
	unlock();
	return FALSE;
}

void CHapi::powerDown()
{
	lock();
	_last_PCR = 0;
	_isPaused = false;
	_isStarted = false;

#ifdef HAPI_POWER_THREAD
	DbgLogInfo(("CHapi::powerDown() _powered_up=%x\n", _powered_up));
	if(_powered_up){
		_powered_up = FALSE;
		if(hapiErr == HAPI_SUCCESS && _API_ok && !p_mchip->hadUsbError("CHapi::powerDown()")){
			DbgLogInfo(("CHapi::powerDown() waiting for %dsecs ...\n", _power_down_delay));
			if(_power_down_delay){
				unlock();
				return; //we will get called again when the time limit expires ...
			}
		}
	}

	_powered_up = TRUE;//make sure power thread won't call powerDownHW()
	unlock();//need to unlock while waiting for thread to die
	stopPowerThread();
	lock();
	_powered_up = FALSE;
#endif
	powerDownHW();
	unlock();
}

//NOTE: this should always be called with lock() held to avoid races with powerDown()
void CHapi::powerDownHW()
{
	DbgLogInfo(("CHapi::powerDownHW() gHapi=%p\n", gHapi));
#ifdef HAPI_POWER_THREAD
	_powered_up = FALSE;
#endif
	HapiExit();

	_logo_mod_time = 0;
	_logo_used = 0;
	_logo_x_pos = -1;
	_logo_y_pos = -1;

	memset(&_lastParam, 0, sizeof(_lastParam)); //reset last committed encoder params
	_lastAR = (HAPI_ASPECT_RATIO)-1;

	p_mchip->lock();
	p_mchip->resetUsbError();

	BYTE PortEvalue = 0;
	if(!p_mchip->UsbGetPortState(4, &PortEvalue)){
		DbgLogError(("CHapi::powerDownHW() UsbGetPortState() FAILED!!\n"));
	}
	PortEvalue |= 0x4; //disable Video bus to Magnum (DXT_VID_EN#=1)
	PortEvalue |= 0x1; //disable I2C bus to Magnum (DXT_PATH_EN=1)
	p_mchip->UsbSetPortState(4, PortEvalue);

	DbgLogInfo((" (disable bus to Encoder, DXT_VID_EN#=1)\n"));
	DbgLogInfo((" Cypress Port %d=0x%02x\n", 4, PortEvalue));

	//FGR - need to reset CS5340 at this point; due to switching of clocks
	p_mchip->resetCs5340();
	
	_LED_state = 0;
	p_mchip->MCHIP_PortA_Set_POWER_ENABLE_H(0);

	p_mchip->resetUsbError();
	p_mchip->resetBling_Options();

	DbgLogInfo(("CHapi::powerDownHW() power is OFF\n"));
	p_mchip->unlock();
}

bool CHapi::DeviceIsReady()
{
	bool isReady = false;
	lock();
	
	isReady = (hapiErr == HAPI_SUCCESS) && _API_ok && !p_mchip->hadUsbError("CHapi::DeviceIsReady()");
	
	if(isReady){
		BYTE PortAvalue = 0;
		if(!p_mchip->UsbGetPortState(0, &PortAvalue)){
			isReady = false;
		} else {
            #define PA_POWER_ENABLE_MSK 0x08 //BUGBUG, whole state check routine should probably be in mchip_port_a.c
			if((PortAvalue & PA_POWER_ENABLE_MSK) == 0){
				isReady = false;
			}
		}
	}
	unlock();
	return isReady;
}

void CHapi::HapiAPIInit()
{
	_API_ok = false;
	DbgLogInfo(("HapiAPIInit()\n"));

	if(gHWapiHandle || gHapi){
		DbgLogError(("HapiAPIInit() gHWapiHandle=%p gHapi=%p\n"));
		hapiErr = HAPI_FAIL;
		return;
	}
	_logo_mod_time = 0;
	_logo_used = 0;
	_logo_x_pos = -1;
	_logo_y_pos = -1;

	_last_payload_time = 0;
	_last_PCR = 0;
	_isPaused = false;
	_isStarted = false;

	//Set bus type
	CommBusType gCommBusType = CommBusType_USB;
	
	// Set HWAPI function pointers to HAPI. HAPI will call these HW dependent functions
	// to communicate with DXT.
	gHapiFunc.commBusInit = USB_CommBusInit;
	gHapiFunc.getBoardInfo = USB_GetBoardInfo;
	gHapiFunc.boardInit = USB_BoardInit;
	gHapiFunc.binaryDownload = USB_BinaryDownload;
	gHapiFunc.systemBootup = USB_SystemBootup;
	gHapiFunc.exit = USB_Exit;
	gHapiFunc.receive = USB_Receive;
	gHapiFunc.send = USB_Send;
	
	// Initialize Communication Bus
	gHwPortConfig.usb_port_config.sbp_freq = SBP_FREQ_30;   //set default value is 30MHz
	gHwPortConfig.usb_port_config.dxt_clk = DXT_CLK_48;   //set default value is 48MHz
	gHwPortConfig.usb_port_config.p_mchip = p_mchip;

	DbgLogInfo(("Calling HAPI_commBusInit\n"));
	gHWapiHandle = HAPI_commBusInit(0, gCommBusType, &gHapiFunc, &gHwPortConfig);
	DbgLogInfo((" HAPI_commBusInit gHWapiHandle=%p\n", gHWapiHandle));

	if(gHWapiHandle){
		memset(&gInitParam, 0, sizeof(gInitParam));

		gInitParam.context = (void *)this; //for callbacks
		gInitParam.chipID  = 0;
		gInitParam.cmdBus  = gHWapiHandle; // Command bus created by HAPI_commBusInit().
		gInitParam.dataBus = gHWapiHandle; // Data bus is the same as the Command bus.
		
		memset(&boardInfo,0,sizeof(BOARD_INFO));
		DbgLogInfo((" Calling HAPI_GetBoardInfo\n"));
		hapiErr = HAPI_GetBoardInfo(gHWapiHandle, &boardInfo);
		DbgLogInfo((" HAPI_GetBoardInfo hapiErr=0x%x\n", hapiErr));

		// Below code initializes BKV configuration parameters.
		{
			if(strncmp(boardInfo.mainCPU, "DX6225-L", 8) == 0)   //LP board)
			{
				if( boardInfo.dxt_clk != DXT_CLK_24)
				{
					DbgLogInfo(("LP mode 48!\n"));
					//MCHIP_DRAM_BKV_Load(MCHIP_BKV_INITIAL_LP_48,&gInitParam.bkvConfig);					
					memcpy(&gInitParam.bkvConfig, &BKV_375CL6_335T_285SYS_1P_MCHIPA3_LV_NOODT, sizeof(MCHIP_DRAM_BKV));
				}
				else
				{
					DbgLogInfo(("LP mode 24!\n"));
					//MCHIP_DRAM_BKV_Load(MCHIP_BKV_INITIAL_LP_24,&gInitParam.bkvConfig);
					memcpy(&gInitParam.bkvConfig, &BKV_24_375CL6_335T_285_12SYS_1P_DXTA3_LV_NOODT_v5, sizeof(MCHIP_DRAM_BKV));
				}
			}
			else if ((strncmp(boardInfo.boardID, "Plankton_T", 10) == 0)&&
					(strncmp(boardInfo.mainCPU, "DX6215-T", 8) == 0))     //Turbo board
			{
				DbgLogInfo(("Turbo mode!\n"));
				//MCHIP_DRAM_BKV_Load(MCHIP_BKV_INITIAL_TURBO,&gInitParam.bkvConfig);
				memcpy(&gInitParam.bkvConfig, &BKV_24_320SYS_400DDR_CL6_DXTA3_LV_NOODT_v1, sizeof(MCHIP_DRAM_BKV));
			}
			else if((strncmp(boardInfo.boardID, "Plankton_C", 10) == 0)&&
				(strncmp(boardInfo.mainCPU, "DX6225-C", 8) == 0))
			{
				DbgLogInfo(("DXT-C mode!\n"));
				//MCHIP_DRAM_BKV_Load(MCHIP_BKV_INITIAL_DXT_C,&gInitParam.bkvConfig);
				memcpy(&gInitParam.bkvConfig, &BKV_24_285_12CL6_400T_SYS_1P_DXTA3_LV_NOODT_v1, sizeof(MCHIP_DRAM_BKV));
			}
			else {
				DWORD dwDXT_BKV_config = 0; //BKV_DXT_C_Micron_425_optimal
				hcwGetRegistryDWORD("DXT_BKV_config", (LPDWORD)&dwDXT_BKV_config);
				if(dwDXT_BKV_config >= BkvCount){
					dwDXT_BKV_config = 0;
				}
				DbgLogInfo((" using BkvArray[%u] w/DXT_CLK_24\n", dwDXT_BKV_config));

				memcpy(&gInitParam.bkvConfig, BkvArray[dwDXT_BKV_config], sizeof(MCHIP_DRAM_BKV));
				boardInfo.dxt_clk = DXT_CLK_24;
			}

		}

#ifdef HAUPPAUGE
		{//FGR - make sure LED3 is not left on from the Cypress side of things
			BYTE value;
			p_mchip->lock();
			if(p_mchip->UsbGetPortState(USB_CTL_PORTS, &value)){
				BYTE new_value;
				new_value = value & ~0x08;//CTL3 low for LED3 Off
				if(new_value != value){
					p_mchip->UsbSetPortState(USB_CTL_PORTS, new_value);
				}
			}
			p_mchip->setSBPtimeout(250); //improve responsiveness when encoder is stopped

			p_mchip->unlock();
		}
	
		hcwGetRegistryDWORD("DXT_mem_pll", (LPDWORD)&gInitParam.bkvConfig.mem_pll);
		if(gInitParam.bkvConfig.mem_pll == 425){
			gInitParam.bkvConfig.mem_pll = 0x239d36cf;
			DbgLogRelease(("MCHIP: BKV MEM_PLL=425, using mem_pll=0x%08x\n", gInitParam.bkvConfig.mem_pll));
		} else if(gInitParam.bkvConfig.mem_pll == 400){
			gInitParam.bkvConfig.mem_pll = 0x23d70a3c;
			DbgLogRelease(("MCHIP: BKV MEM_PLL=400, using mem_pll=0x%08x\n", gInitParam.bkvConfig.mem_pll));
		} else if(gInitParam.bkvConfig.mem_pll == 355){
			gInitParam.bkvConfig.mem_pll = 0x2495c772;
			DbgLogRelease(("MCHIP: BKV MEM_PLL=355, using mem_pll=0x%08x\n", gInitParam.bkvConfig.mem_pll));
		} else {
			DbgLogInfo(("MCHIP: mem_pll=0x%08x\n", gInitParam.bkvConfig.mem_pll));
		}

		hcwGetRegistryDWORD("DXT_sys_pll", (LPDWORD)&gInitParam.bkvConfig.sys_pll);
		if(gInitParam.bkvConfig.sys_pll == 320){
			gInitParam.bkvConfig.sys_pll = 0x24cccccc;
			DbgLogRelease(("MCHIP: BKV sys_pll=320, using sys_pll=0x%08x\n", gInitParam.bkvConfig.sys_pll));
		} else if(gInitParam.bkvConfig.sys_pll == 285){
			gInitParam.bkvConfig.sys_pll = 0x25631fe3;
			DbgLogRelease(("MCHIP: BKV sys_pll=285, using sys_pll=0x%08x\n", gInitParam.bkvConfig.sys_pll));
		} else {
			DbgLogInfo(("MCHIP: sys_pll=0x%08x\n", gInitParam.bkvConfig.sys_pll));
		}

		hcwGetRegistryDWORD("DXT_dram_mr",                  (LPDWORD)&gInitParam.bkvConfig.dram_mr);
		hcwGetRegistryDWORD("DXT_dram_emr",                 (LPDWORD)&gInitParam.bkvConfig.dram_emr);
		hcwGetRegistryDWORD("DXT_mem_intf_timing_ctrl",     (LPDWORD)&gInitParam.bkvConfig.mem_intf_timing_ctrl);
		hcwGetRegistryDWORD("DXT_mem_intf_add_config",      (LPDWORD)&gInitParam.bkvConfig.mem_intf_add_config);
		hcwGetRegistryDWORD("DXT_mem_intf_rfsh_ctrl",       (LPDWORD)&gInitParam.bkvConfig.mem_intf_rfsh_ctrl);
		hcwGetRegistryDWORD("DXT_mem_intf_left_cmd_ctrl1",  (LPDWORD)&gInitParam.bkvConfig.mem_intf_left_cmd_ctrl1);
		hcwGetRegistryDWORD("DXT_mem_intf_left_cmd_ctrl2",  (LPDWORD)&gInitParam.bkvConfig.mem_intf_left_cmd_ctrl2);
		hcwGetRegistryDWORD("DXT_mem_intf_right_cmd_ctrl1", (LPDWORD)&gInitParam.bkvConfig.mem_intf_right_cmd_ctrl1);
		hcwGetRegistryDWORD("DXT_mem_intf_right_cmd_ctrl2", (LPDWORD)&gInitParam.bkvConfig.mem_intf_right_cmd_ctrl2);
		hcwGetRegistryDWORD("DXT_mem_intf_left_data_ctrl",  (LPDWORD)&gInitParam.bkvConfig.mem_intf_left_data_ctrl);
		hcwGetRegistryDWORD("DXT_mem_intf_right_data_ctrl", (LPDWORD)&gInitParam.bkvConfig.mem_intf_right_data_ctrl);
		hcwGetRegistryDWORD("DXT_mem_intf_dll1",            (LPDWORD)&gInitParam.bkvConfig.mem_intf_dll1);
		hcwGetRegistryDWORD("DXT_mem_intf_left_ls_dll2",    (LPDWORD)&gInitParam.bkvConfig.mem_intf_left_ls_dll2);
		hcwGetRegistryDWORD("DXT_mem_intf_left_ms_dll2",    (LPDWORD)&gInitParam.bkvConfig.mem_intf_left_ms_dll2);
		hcwGetRegistryDWORD("DXT_mem_intf_right_ls_dll2",   (LPDWORD)&gInitParam.bkvConfig.mem_intf_right_ls_dll2);
		hcwGetRegistryDWORD("DXT_mem_intf_right_ms_dll2",   (LPDWORD)&gInitParam.bkvConfig.mem_intf_right_ms_dll2);
		hcwGetRegistryDWORD("DXT_mem_intf_left_ls_ditrm",   (LPDWORD)&gInitParam.bkvConfig.mem_intf_left_ls_ditrm);
		hcwGetRegistryDWORD("DXT_mem_intf_left_ms_ditrm",   (LPDWORD)&gInitParam.bkvConfig.mem_intf_left_ms_ditrm);
		hcwGetRegistryDWORD("DXT_mem_intf_right_ls_ditrm",  (LPDWORD)&gInitParam.bkvConfig.mem_intf_right_ls_ditrm);
		hcwGetRegistryDWORD("DXT_mem_intf_right_ms_ditrm",  (LPDWORD)&gInitParam.bkvConfig.mem_intf_right_ms_ditrm);
 #if 0 //FGR - these are not actually used by any code
		hcwGetRegistryDWORD("DXT_left_ls_read_gate_guess",  (LPDWORD)&gInitParam.bkvConfig.left_ls_read_gate_guess);
		hcwGetRegistryDWORD("DXT_left_ms_read_gate_guess",  (LPDWORD)&gInitParam.bkvConfig.left_ms_read_gate_guess);
		hcwGetRegistryDWORD("DXT_right_ls_read_gate_guess", (LPDWORD)&gInitParam.bkvConfig.right_ls_read_gate_guess);
		hcwGetRegistryDWORD("DXT_right_ms_read_gate_guess", (LPDWORD)&gInitParam.bkvConfig.right_ms_read_gate_guess);
		hcwGetRegistryDWORD("DXT_left_ls_read_eye_guess",   (LPDWORD)&gInitParam.bkvConfig.left_ls_read_eye_guess);
		hcwGetRegistryDWORD("DXT_left_ms_read_eye_guess",   (LPDWORD)&gInitParam.bkvConfig.left_ms_read_eye_guess);
		hcwGetRegistryDWORD("DXT_right_ls_read_eye_guess",  (LPDWORD)&gInitParam.bkvConfig.right_ls_read_eye_guess);
		hcwGetRegistryDWORD("DXT_right_ms_read_eye_guess",  (LPDWORD)&gInitParam.bkvConfig.right_ms_read_eye_guess);
		hcwGetRegistryDWORD("DXT_mem_intf_dll2",            (LPDWORD)&gInitParam.bkvConfig.mem_intf_dll2);
		hcwGetRegistryDWORD("DXT_sys_pll_2",                (LPDWORD)&gInitParam.bkvConfig.sys_pll_2);                   
		hcwGetRegistryDWORD("DXT_mempll_workaround_attempt",(LPDWORD)&gInitParam.bkvConfig.mempll_workaround_attempt);
		hcwGetRegistryDWORD("DXT_mempll_workaround_wait",   (LPDWORD)&gInitParam.bkvConfig.mempll_workaround_wait);
		hcwGetRegistryDWORD("DXT_left_itm_read_delay",      (LPDWORD)&gInitParam.bkvConfig.left_itm_read_delay);
		hcwGetRegistryDWORD("DXT_right_itm_read_delay",     (LPDWORD)&gInitParam.bkvConfig.right_itm_read_delay);
		hcwGetRegistryDWORD("DXT_MCHIP_a2_gate_sweep",      (LPDWORD)&gInitParam.bkvConfig.MCHIP_a2_gate_sweep);
		hcwGetRegistryDWORD("DXT_MCHIP_a2_itm_sweep",       (LPDWORD)&gInitParam.bkvConfig.MCHIP_a2_itm_sweep);
		hcwGetRegistryDWORD("DXT_MCHIP_a2_dq_sweep",        (LPDWORD)&gInitParam.bkvConfig.MCHIP_a2_dq_sweep);
		hcwGetRegistryDWORD("DXT_MCHIP_a2_dqs_sweep",       (LPDWORD)&gInitParam.bkvConfig.MCHIP_a2_dqs_sweep);
		hcwGetRegistryDWORD("DXT_vp_boot_mode",             (LPDWORD)&gInitParam.bkvConfig.vp_boot_mode);
		hcwGetRegistryDWORD("DXT_memtest_mask",             (LPDWORD)&gInitParam.bkvConfig.memtest_mask);
		hcwGetRegistryDWORD("DXT_reserved1",                (LPDWORD)&gInitParam.bkvConfig.reserved1);
		hcwGetRegistryDWORD("DXT_reserved2",                (LPDWORD)&gInitParam.bkvConfig.reserved2);
		hcwGetRegistryDWORD("DXT_reserved3",                (LPDWORD)&gInitParam.bkvConfig.reserved3);
		hcwGetRegistryDWORD("DXT_reserved4",                (LPDWORD)&gInitParam.bkvConfig.reserved4);
		hcwGetRegistryDWORD("DXT_otp_config_flash",         (LPDWORD)&gInitParam.bkvConfig.otp_config_flash);
 #endif
#endif//HAUPPAUGE		
		
		DbgLogInfo((" Calling HAPI_Init\n"));
		gHapi = NULL;
		hapiErr = HAPI_Init(&gHapi, &gInitParam);
		DbgLogInfo((" HAPI_Init gHapi=%p hapiErr=0x%x\n", gHapi, hapiErr));

		if(hapiErr == HAPI_SUCCESS){
			Uint32 gEndianSwap = 1;
			DbgLogInfo((" Calling HAPI_SetEndianSwap\n"));
			hapiErr = HAPI_SetEndianSwap(gHapi, gEndianSwap);
			DbgLogInfo((" HAPI_SetEndianSwap hapiErr=0x%x\n", hapiErr));
		
		}
	}
}

void CHapi::HapiFWDownload()
{
	DbgLogInfo(("HapiFWDownload() gHapi=%p\n", gHapi));

	if(gHapi){
		//parse_binary_address(MIPS_ADDR, &gFirmwareFile.mipsBaseAddr, &gFirmwareFile.mipsEntryAddr);
		// [vx_host_slave] 
		// Load Address = 0x80010000
		// Entry Point Address = 0x80010000
//		gFirmwareFile.mipsFileName  = "mips_vx_host_slave.bin";
	        gFirmwareFile.mipsFileName  = "/lib/firmware/Hauppauge/mips_vx_host_slave.bin";
//		gFirmwareFile.mipsFileName  = "\\systemroot\\system32\\drivers\\mips_vx_host_slave.bin";
//		gFirmwareFile.mipsFileName  = "\\systemroot\\system32\\drivers\\HcwE5CPU_MIPS.bin";
		gFirmwareFile.mipsBaseAddr  = 0x80010000;
		gFirmwareFile.mipsEntryAddr = 0x80010000;

		//parse_binary_address(SPARC_ADDR, &gFirmwareFile.sparcBaseAddr, &gFirmwareFile.sparcEntryAddr);
		// [vx_host_slave_t22_24] 
		// Load Address = 0x00c05000
		// Entry Point Address = 0x00c05000

//FGR - BUGBUG needs to use Plankton FW for transcode; llama for encode!!
//		gFirmwareFile.sparcFileName  = "llama_usb_vx_host_slave_t22_24.bin";
		gFirmwareFile.sparcFileName  = "/lib/firmware/Hauppauge/llama_usb_vx_host_slave_t22_24.bin";
#if 0
		if(gBoard_bus != plankton){
			if( boardInfo.dxt_clk != DXT_CLK_24){
//				gFirmwareFile.sparcFileName = "llama_usb_vx_host_slave_t22_48.bin";
				gFirmwareFile.sparcFileName = "/lib/firmware/Hauppauge/llama_usb_vx_host_slave_t22_48.bin";
//				gFirmwareFile.sparcFileName = "\\systemroot\\system32\\drivers\\llama_usb_vx_host_slave_t22_48.bin";
//				gFirmwareFile.sparcFileName = "\\systemroot\\system32\\drivers\\HcwE5ENC_t22_48.bin";
			}
			{
//				gFirmwareFile.sparcFileName = "llama_usb_vx_host_slave_t22_24.bin";
			        gFirmwareFile.sparcFileName = "/lib/firmware/Hauppauge/llama_usb_vx_host_slave_t22_24.bin";
//				gFirmwareFile.sparcFileName = "\\systemroot\\system32\\drivers\\llama_usb_vx_host_slave_t22_24.bin";
//				gFirmwareFile.sparcFileName = "\\systemroot\\system32\\drivers\\HcwE5ENC_t22_24.bin";
			}
		} else {
			if( boardInfo.dxt_clk != DXT_CLK_24){ //FGR - BUGBUG - these FWs are the same, except for build time
//				gFirmwareFile.sparcFileName = "plankton_vx_host_slave_t22_48.bin";
				gFirmwareFile.sparcFileName = "/lib/firmware/Hauppauge/plankton_vx_host_slave_t22_48.bin";
//				gFirmwareFile.sparcFileName = "\\systemroot\\system32\\drivers\\plankton_vx_host_slave_t22_48.bin";
//				gFirmwareFile.sparcFileName = "\\systemroot\\system32\\drivers\\HcwE5XC_t22_48.bin";
			} else {
//				gFirmwareFile.sparcFileName = "plankton_vx_host_slave_t22_24.bin";
				gFirmwareFile.sparcFileName = "/lib/firmware/Hauppauge/plankton_vx_host_slave_t22_24.bin";
//				gFirmwareFile.sparcFileName = "\\systemroot\\system32\\drivers\\plankton_vx_host_slave_t22_24.bin";
//				gFirmwareFile.sparcFileName = "\\systemroot\\system32\\drivers\\HcwE5XC_t22_24.bin";
			}
		}
#endif

		gFirmwareFile.sparcBaseAddr  = 0x00c05000;
		gFirmwareFile.sparcEntryAddr = 0x00c05000;

		DbgLogInfo((" Calling HAPI_FWDownload\n"));
		hapiErr = HAPI_FWDownload(gHapi, &gFirmwareFile);
		DbgLogInfo((" HAPI_FWDownload hapiErr=0x%x\n", hapiErr));
	}
}

void CHapi::HapiFWBoot()
{
	DbgLogInfo(("HapiFWBoot() gHapi=%p hapiErr=%d\n", gHapi, hapiErr));
	if(gHapi == NULL){
		DbgLogError(("CHapi::HapiFWBoot() gHapi==NULL!!\n"));
		return;
	}
	BYTE PortEvalue = 0;

	if(hapiErr == HAPI_SUCCESS){
		DbgLogInfo((" Calling HAPI_BoardBootup gBoard_bus=%d\n", gBoard_bus));
		p_mchip->resetWFMode();
		hapiErr = HAPI_BoardBootup(gHapi, &gBootConfig[gBoard_bus]);
		DbgLogInfo((" HAPI_BoardBootup hapiErr=0x%x\n", hapiErr));
	}
	
	DWORD SetAVLtype = (gBoard_bus != plankton)?1:0;
	hcwGetRegistryDWORD("SetAVLtype", (LPDWORD)&SetAVLtype);
	if(hapiErr == HAPI_SUCCESS){
		{//note that cant enable DXT_PATH_EN before FW booted
			p_mchip->lock();
			if(!p_mchip->UsbGetPortState(4, &PortEvalue)){
				DbgLogError(("CHapi::HapiFWBoot() UsbGetPortState() FAILED@%d!!\n", __LINE__));
				p_mchip->unlock();
				return;
			}
			PortEvalue &= ~0x04; //PE.2 (DXT_VID_EN#=0) enable Video bus to Magnum
			
			//Setup PE.0 (DXT_PATH_EN=0) to allow Magnum to control I2C bus
			//Also, allow tweaking of PE.2 (PT_FUN_EN#/DXT_VID_EN#)
			DWORD DXT_PATH_EN = 1; //0=Magnum I2c enabled 1=disabled
			hcwGetRegistryDWORD("DXT_PATH_EN", (LPDWORD)&DXT_PATH_EN);
			if(DXT_PATH_EN != 1){
				DXT_PATH_EN &= 0x05;
				PortEvalue &= ~0x05; //PE.0, PE.2
				PortEvalue |= (BYTE)DXT_PATH_EN;
			}
			p_mchip->UsbSetPortState(4, PortEvalue);
			DbgLogInfo((" Cypress Port %d=0x%02x\n", 4, PortEvalue));
			DbgLogInfo(("   video bus to Encoder, DXT_VID_EN#=%d)\n", (PortEvalue&0x04)?1:0));
			DbgLogInfo(("   I2C bus to Encoder, DXT_PATH_EN#=%d)\n", PortEvalue&0x01));

			//FGR - need to reset CS5340 at this point; due to switching of clocks
			p_mchip->resetCs5340();

			p_mchip->unlock();
		}
		if(SetAVLtype == 1){
			DbgLogInfo((" Calling HAPI_SetAVLDriver (disable AVL)\n"));
			if((PortEvalue & 0x01) == 0){
				DbgLogError((" Disabling AVL with DXT_PATH_EN=0\n"));
			}
			hapiErr = HAPI_SetAVLDriver(gHapi, &AvlOffParam);
		} else if(SetAVLtype >= 2){
			DbgLogInfo((" Calling HAPI_SetAVLDriver (enable siena AVL)\n"));
			if((PortEvalue & 0x01) == 1){
				DbgLogError((" Enabling AVL with DXT_PATH_EN=1\n"));
			}
			if(SetAVLtype > 2){
				hapiErr = HAPI_SetAVLDriver(gHapi, &AvlSienaParam2);
			} else {
				hapiErr = HAPI_SetAVLDriver(gHapi, &AvlSienaParam);
			}
		}
		DbgLogInfo((" HAPI_SetAVLDriver hapiErr=0x%x\n", hapiErr));
#if DBG
//		wrapSleep_ms(1000);
#endif
	}

	if(hapiErr == HAPI_SUCCESS){
		DbgLogInfo((" Calling HAPI_AVDataCallbackInstall\n"));
		hapiErr = HAPI_AVDataCallbackInstall(gHapi, &gCallbackFunc);
		DbgLogInfo((" HAPI_AVDataCallbackInstall hapiErr=0x%x\n", hapiErr));
#if DBG
//		wrapSleep_ms(1000);
#endif
	}

#if 1
	if(hapiErr == HAPI_SUCCESS){
		DbgLogInfo((" Calling HAPI_ErrorMsgCallbackInstall\n"));
        hapiErr = HAPI_ErrorMsgCallbackInstall(gHapi, CHapi::ErrorMsgCallback);
		DbgLogInfo((" HAPI_ErrorMsgCallbackInstall hapiErr=0x%x\n", hapiErr));
	}
#endif			
#if DBG
	wrapSleep_ms(1000);
#endif
}

void CHapi::HapiExit()
{
	DbgLogInfo(("HapiExit() gHWapiHandle=%p gHapi=%p hapiErr=%d\n", gHWapiHandle, gHapi, hapiErr));
	_API_ok = false;

	if(gHapi){
		DbgLogInfo((" Calling HAPI_Exit(%p)\n", gHapi));
		hapiErr = HAPI_Exit(gHapi);
		DbgLogInfo((" HAPI_Exit() hapiErr=0x%x\n", hapiErr));

		gHapi = NULL;
	}

	if(gHWapiHandle){
		if(gHWapiHandle->device){
			MemFree2Heap(__FILE__, __LINE__, gHWapiHandle->device);
			gHWapiHandle->device = NULL;
		}
		MemFree2Heap(__FILE__, __LINE__, gHWapiHandle);
		gHWapiHandle = NULL;
	}
	
}

void CHapi::hapiResetHW()
{
	if(gHWapiHandle==NULL || gHapi==NULL)
		return;
	
	lock();
	DbgLogWarn(("hapiResetHW() gHWapiHandle=%p gHapi=%p hapiErr=%d _API_ok=%x\n", gHWapiHandle, gHapi, hapiErr, _API_ok));
	bool sav_isStarted = _isStarted;
	bool sav_isPaused  = _isPaused;
	
	//FGR - we will try and reset the Magnum, to allow the user to proceed going forward
	DWORD dwAllowEncoderRestart = 1;
	hcwGetRegistryDWORD("AllowEncoderRestart", &dwAllowEncoderRestart);
	if(dwAllowEncoderRestart){
		powerDownHW();
		powerUp();
		DbgLogInfo(("hapiResetHW() new gHWapiHandle=%p gHapi=%p\n", gHWapiHandle, gHapi));
		if(hapiErr == HAPI_SUCCESS && _API_ok){
			_isStarted = sav_isStarted;
			_isPaused  = sav_isPaused;
		}
	}
	unlock();
}

Uint32 CHapi::HapiAspectSet(HAPI_ASPECT_RATIO ar)
{
	lock();
	if(!_API_ok){
		DbgLogWarn(("CHapi::HapiAspectSet() _API_ok==false!!\n"));
		unlock();
		return 0;
	}
	if(gHapi == NULL){
		DbgLogError(("CHapi::HapiAspectSet() gHapi==NULL!!\n"));
		unlock();
		return 0;
	}
	
	DWORD value = ar;
	hcwGetRegistryDWORD("-VideoCapAspectRatio", &value);
	ar = (HAPI_ASPECT_RATIO)value;
	if(value >= HAPI_AR_MSG_MAX){
		DbgLogInfo(("CHapi::HapiAspectSet() skipping HAPI_ARSet for unknown ar=%x\n", ar));
		unlock();
		return 1;
	}
	if(_lastAR == ar){
		DbgLogInfo(("CHapi::HapiAspectSet() AR(%d) unchanged, skipping\n", ar));
		unlock();
		return 1;
	}

	DbgLogInfo(("CHapi::HapiAspectSet() ar=%d\n", ar));

	hapiErr = HAPI_ARSet(gHapi, 0, ar);
	if(hapiErr != HAPI_SUCCESS){
		DbgLogWarn((" HAPI_ARSet hapiErr=0x%x\n", hapiErr));
		unlock();
		return 0;
	}
	//save current AR for next time
	_lastAR = ar;

	unlock();
	return 1;
}

Uint32 CHapi::HapiParamSet(HAPI_SET_PARAM *pParam)
{
	if(pParam == NULL){
		DbgLogError(("CHapi::HapiParamSet(NULL)!!\n"));
		return 0;
	}
	lock();
	if(!_API_ok || hapiErr != HAPI_SUCCESS){
		hapiResetHW();
	}
	if(!_API_ok){
		DbgLogWarn(("CHapi::HapiParamSet() _API_ok==false!!\n"));
		unlock();
		return 0;
	}
	if(gHapi == NULL){
		DbgLogError(("CHapi::HapiParamSet() gHapi==NULL!!\n"));
		unlock();
		return 0;
	}

#if DBG
	DbgLogInfo(("CHapi::HapiParamSet() ParamType=%d _isStarted=%x _isPaused=%x _logo_x_pos=%d\n",
		pParam->ParamType, _isStarted, _isPaused, _logo_x_pos));
#endif

	bool isRunning = _isStarted && !_isPaused;
	if(isRunning){
		hapiStop();
	}
	if(hapiErr != HAPI_SUCCESS){
		DbgLogWarn(("CHapi::HapiParamSet() hapiErr=0x%x\n", hapiErr));
		_last_good_hdmi_fmt = 0;
		unlock();
		return 0;
	}
	//FGR - BUGBUG - the firmware forgets we have a logo during stop/start, so
	// for now we need to just disable the logo (and reset the _logo_x_pos state)
	// so it will be re-initialized on the next start
	//This is so very wasteful ....
#define LOGOBUGBUG 1
#if LOGOBUGBUG
	//Stop any existing Logo
	if(_logo_x_pos != -1){
		hapiErr = HAPI_LogoOnOff(gHapi, 0, 0, 0); //disable logo index=0
		if(hapiErr != HAPI_SUCCESS){
			DbgLogWarn((" HAPI_LogoOnOff hapiErr=0x%x\n", hapiErr));
			_last_good_hdmi_fmt = 0;
			unlock();
			return 0;
		}
	}
	_logo_x_pos = -1;
	_logo_y_pos = -1;
#endif
	//FGR - we skip all of this if we know that *pParam has not changed
	// since last call which will speed up stop/start a bit
	if(memcmp(&_lastParam, pParam, sizeof(_lastParam)) == 0){
		DbgLogInfo(("CHapi::HapiParamSet() params unchanged, skipping\n"));

	} else {

#if !LOGOBUGBUG
		//Stop any existing Logo
		if(_logo_x_pos != -1){
			hapiErr = HAPI_LogoOnOff(gHapi, 0, 0, 0); //disable logo index=0
			if(hapiErr != HAPI_SUCCESS){
				DbgLogWarn((" HAPI_LogoOnOff hapiErr=0x%x\n", hapiErr));
				_last_good_hdmi_fmt = 0;
				unlock();
				return 0;
			}
		}
		_logo_x_pos = -1;
		_logo_y_pos = -1;
#endif

	#if DBG
		printParam(pParam);
	#endif

		hapiErr = HAPI_ParamSet(gHapi, pParam);
		if(hapiErr != HAPI_SUCCESS){
			DbgLogWarn((" HAPI_ParamSet hapiErr=0x%x\n", hapiErr));
			_last_good_hdmi_fmt = 0;
			unlock();
			return 0;
		}
		//save current params for next time
		memcpy(&_lastParam, pParam, sizeof(_lastParam));
	}
	get_logo_data(pParam);
	if(!_API_ok){//did the FW hang during logo download?
		_last_good_hdmi_fmt = 0;
		unlock();
		return 0;
	}
	_last_good_hdmi_fmt = _hdmi_fmt;

#if 0//FGR - only resume via HapiResume() 
	if(_isStarted){
		_isPaused = false;
		hapiStart();
	}
#endif
	unlock();
	return 1;
}

Uint32 CHapi::HapiParamGet(HAPI_SET_PARAM *pParam)
{
	if(pParam == NULL){
		DbgLogError(("CHapi::HapiParamGet(NULL)!!\n"));
		return 0;
	}
	lock();
	if(!_API_ok){
		DbgLogWarn(("CHapi::HapiParamGet() _API_ok==false!!\n"));
		unlock();
		return 0;
	}
	if(gHapi == NULL){
		DbgLogError(("CHapi::HapiParamGet() gHapi==NULL!!\n"));
		unlock();
		return 0;
	}
	DbgLogInfo((" Calling HAPI_ParamGet ParamType=%d\n", pParam->ParamType));
    
	Uint32 savParamType = pParam->ParamType;
	memset(pParam, 0, sizeof(*pParam));
	pParam->ParamType = savParamType;			

    hapiErr = HAPI_ParamGet(gHapi, pParam);
	
	if(hapiErr == HAPI_SUCCESS){
#if DBG
		printParam(pParam);
		is_param_dirty(pParam);
#endif
		unlock();
		return 1;
	} else {
		DbgLogInfo((" HAPI_ParamGet hapiErr=0x%x\n", hapiErr));
		unlock();
		return 0;
	}
}


/*
set parameter bitmask
*/
void CHapi::set_param_bitmask(HAPI_SET_PARAM *pParam, const char* param_name)
{
//	DbgLogInfo(("set_param_bitmask(%p, %s) ParamType=%d\n", pParam, param_name, pParam->ParamType));
	
	Param_Bitmask_Item *p_bitmask = NULL;
	
	if(pParam->ParamType == HAPI_SET_PARAM_TYPE_ENCODER){
		p_bitmask = EncodeParamBitmaskTable;
	} else if(pParam->ParamType == HAPI_SET_PARAM_TYPE_TRANSCODER){
		p_bitmask = TranscodeParamBitmaskTable;
	} else if(pParam->ParamType == HAPI_SET_PARAM_TYPE_DECODER){
		p_bitmask = NULL;
	}
	if(p_bitmask == NULL){
		return;
	}
    //Special case, since ParamType has no bitmask per-se
	if(strcmp("ParamType", param_name) == 0){
		return;
	}
    for(; p_bitmask->addr != NULL; p_bitmask++)
    {
        if(strcmp(p_bitmask->str, param_name) == 0)
        {
            //get offset from start of HAPI_SET_PARAM struct, and add to base address of target struct
			BYTE *p = (BYTE *)pParam + (((BYTE *)(p_bitmask->addr)) - ((BYTE *)&gParam));
			
			*((Uint32 *)p) |= p_bitmask->bitmask;
            break;
        }
    }
}

Uint32 CHapi::get_param_bitmask(HAPI_SET_PARAM *pParam, const char* param_name)
{
//	DbgLogInfo(("get_param_bitmask(%p, %s) ParamType=%d\n", pParam, param_name, pParam->ParamType));
	
	Param_Bitmask_Item *p_bitmask = NULL;
	
	if(pParam->ParamType == HAPI_SET_PARAM_TYPE_ENCODER){
		p_bitmask = EncodeParamBitmaskTable;
	} else if(pParam->ParamType == HAPI_SET_PARAM_TYPE_TRANSCODER){
		p_bitmask = TranscodeParamBitmaskTable;
	} else if(pParam->ParamType == HAPI_SET_PARAM_TYPE_DECODER){
		p_bitmask = NULL;
	}
	if(p_bitmask == NULL){
		return 0;
	}
    //Special case, since ParamType has no bitmask per-se
	if(strcmp("ParamType", param_name) == 0){
		return 1;
	}
    for(; p_bitmask->addr != NULL; p_bitmask++)
    {
        if(strcmp(p_bitmask->str, param_name) == 0)
        {
            //get offset from start of HAPI_SET_PARAM struct, and add to base address of target struct
			BYTE *p = (BYTE *)pParam + (((BYTE *)(p_bitmask->addr)) - ((BYTE *)&gParam));
			
			return *((Uint32 *)p) & p_bitmask->bitmask;
            break;
        }
    }
	return 0;
}

void CHapi::clear_param_bitmasks(HAPI_SET_PARAM *pParam)
{
	DbgLogInfo(("clear_param_bitmasks() pParam->ParamType=%d\n", pParam->ParamType));
#if 1
	//FGR - just clear entire memory region; since we are going to do
	// memcmp against it for changes later
	memset(pParam, 0, sizeof(HAPI_SET_PARAM));
#else
	pParam->bitMask = 0;

	if (pParam->ParamType == HAPI_SET_PARAM_TYPE_TRANSCODER)
	{
		pParam->params.transcodeParam.bitMask = 0;
		pParam->params.transcodeParam.AudioParams.bitMask = 0;
		pParam->params.transcodeParam.VideoParams.bitMask = 0;
		pParam->params.transcodeParam.LogParams.bitMask = 0;
	}
    else if(pParam->ParamType == HAPI_SET_PARAM_TYPE_ENCODER)
	{
		pParam->params.encodeParam.bitMask = 0;
		pParam->params.encodeParam.AudioParams.bitMask = 0;
		pParam->params.encodeParam.VideoParams.bitMask = 0;
		pParam->params.encodeParam.LogParams.bitMask = 0;
	}
    else if(pParam->ParamType == HAPI_SET_PARAM_TYPE_DECODER)
	{
		//pParam->params.decodeParam.bitMask = 0;
		//pParam->params.decodeParam.AudioParams.bitMask = 0;
		//pParam->params.decodeParam.VideoParams.bitMask = 0;
		//pParam->params.decodeParam.LogParams.bitMask = 0;
	}
#endif
}

Uint32 CHapi::is_param_dirty(HAPI_SET_PARAM *pParam)
{
	if(pParam->bitMask){
		DbgLogInfo(("is_param_dirty() pParam->bitMask=0x%x\n", pParam->bitMask));
	}
	if (pParam->ParamType == HAPI_SET_PARAM_TYPE_TRANSCODER)
	{
		if((pParam->params.transcodeParam.bitMask
			  | pParam->params.transcodeParam.AudioParams.bitMask
			  | pParam->params.transcodeParam.VideoParams.bitMask
			  | pParam->params.transcodeParam.LogParams.bitMask)){
			DbgLogInfo(("is_param_dirty(TRANSCODER)\n"));
			DbgLogInfo((" transcodeParam.bitMask=0x%x\n", pParam->params.transcodeParam.bitMask));
			DbgLogInfo((" transcodeParam.AudioParams.bitMask=0x%x\n", pParam->params.transcodeParam.AudioParams.bitMask));
			DbgLogInfo((" transcodeParam.VideoParams.bitMask=0x%x\n", pParam->params.transcodeParam.VideoParams.bitMask));
			DbgLogInfo((" transcodeParam.LogParams.bitMask=0x%x\n", pParam->params.transcodeParam.LogParams.bitMask));
		} else {
			DbgLogInfo(("is_param_dirty(TRANSCODER) == %x\n", pParam->bitMask));
			return pParam->bitMask;
		}
		return (pParam->params.transcodeParam.bitMask
			  | pParam->params.transcodeParam.AudioParams.bitMask
			  | pParam->params.transcodeParam.VideoParams.bitMask
			  | pParam->params.transcodeParam.LogParams.bitMask);
	}
    else if(pParam->ParamType == HAPI_SET_PARAM_TYPE_ENCODER)
	{
		if((pParam->params.encodeParam.bitMask
			  | pParam->params.encodeParam.AudioParams.bitMask
			  | pParam->params.encodeParam.VideoParams.bitMask
			  | pParam->params.encodeParam.LogParams.bitMask)){
			DbgLogInfo(("is_param_dirty(ENCODER)\n"));
			DbgLogInfo((" encodeParam.bitMask=0x%x\n", pParam->params.encodeParam.bitMask));
			DbgLogInfo((" encodeParam.AudioParams.bitMask=0x%x\n", pParam->params.encodeParam.AudioParams.bitMask));
			DbgLogInfo((" encodeParam.VideoParams.bitMask=0x%x\n", pParam->params.encodeParam.VideoParams.bitMask));
			DbgLogInfo((" encodeParam.LogParams.bitMask=0x%x\n", pParam->params.encodeParam.LogParams.bitMask));
		} else {
			DbgLogInfo(("is_param_dirty(ENCODER) == %x\n", pParam->bitMask));
			return pParam->bitMask;
		}
		return (pParam->params.encodeParam.bitMask
			  | pParam->params.encodeParam.AudioParams.bitMask
			  | pParam->params.encodeParam.VideoParams.bitMask
			  | pParam->params.encodeParam.LogParams.bitMask);
	}
    else if(pParam->ParamType == HAPI_SET_PARAM_TYPE_DECODER)
	{
		DbgLogError(("is_param_dirty(PARAM_TYPE_DECODER) == 0 (not yet supported)\n"));
		return 0; //not yet supported, so never dirty
		//pParam->params.decodeParam.bitMask = 0;
		//pParam->params.decodeParam.AudioParams.bitMask = 0;
		//pParam->params.decodeParam.VideoParams.bitMask = 0;
		//pParam->params.decodeParam.LogParams.bitMask = 0;
	}
	DbgLogError(("is_param_dirty(bad param type=%d) == %x\n", pParam->ParamType, pParam->bitMask));
	return pParam->bitMask;
}

/*
set parameter
*/
void CHapi::set_param(HAPI_SET_PARAM *pParam, const char* param_name, Uint32 value)
{
	Parameter_Map_Item *p_map = NULL;
	Uint32 currentType = pParam->ParamType;

#if 0//DBG
	char param_dummy[64];
	param_dummy[0] = '-'; //reduce spew for unset overrides
	strcpy(&param_dummy[1], param_name);
	hcwGetRegistryDWORD(param_dummy, (LPDWORD)&value); //FGR BUGBUG - check for param override
	if(value == 0xFFFF0000){
		DbgLogInfo(("set_param(%p, %s, %u) IGNORED due to registry setting\n", pParam, param_name, value, currentType));
		return;
	}
#else
        // Use registered settings if they exist.
        Uint32 reg_value;
        if (hcwGetRegistryDWORD(param_name, (LPDWORD)&reg_value))
        {
            if (value != reg_value)
            {
                DbgLogInfo(("set_param(%p, %s, %u) override by registry %u\n", pParam, param_name, value, reg_value));
                value = reg_value;
            }
        }
#endif

    //Special case, since we need a valid ParamType to establish which table to use
	if(strcmp("ParamType", param_name) == 0){
		currentType = value;
	}
//	DbgLogInfo(("set_param(%p, %s, %u)\n", pParam, param_name, value));
	DbgLogInfo(("set_param(%s, %u)\n", param_name, value));

	if(currentType == HAPI_SET_PARAM_TYPE_ENCODER){
		p_map = EncodeParamMapTable;
	} else if(currentType == HAPI_SET_PARAM_TYPE_TRANSCODER){
		p_map = TranscodeParamMapTable;
	} else if(currentType == HAPI_SET_PARAM_TYPE_DECODER){
		p_map = NULL;
	}
	if(p_map == NULL){
		DbgLogError(("set_param(%p,%s) p_map==NULL for ParamType=%d\n", pParam,  param_name, currentType));
		return;
	}
    for(; p_map->addr != NULL; p_map++)
    {
        if(strcmp(p_map->str, param_name) == 0)
        {
            //get offset from start of HAPI_SET_PARAM struct, and add to base address of target struct
			BYTE *p = (BYTE *)pParam + (((BYTE *)(p_map->addr)) - ((BYTE *)&gParam));
			
			switch(p_map->type){
			case 0x05: //16bit types
			case 0x06:
				*((Uint16 *)p) = (Uint16)value;
				break;
			default:
				//everything else is 32bits
				*((Uint32 *)p) = value;
            }
			if(p_map->addr == &gParam.ParamType){
				//User is setting the parameter type, reset all the bitmap flags for the new type
				clear_param_bitmasks(pParam);
				pParam->ParamType = value;
            } else {
				//mark new change as pending
				set_param_bitmask(pParam, param_name);
			}
			return;
        }
    }
	DbgLogError(("set_param(%p,%s) unknown param name for ParamType=%d\n", pParam,  param_name, pParam->ParamType));
}

/*
get parameter
*/
Uint32 CHapi::get_param(HAPI_SET_PARAM *pParam, const char* param_name)
{
	Parameter_Map_Item *p_map = NULL;
	
	if(pParam->ParamType == HAPI_SET_PARAM_TYPE_ENCODER){
		p_map = EncodeParamMapTable;
	} else if(pParam->ParamType == HAPI_SET_PARAM_TYPE_TRANSCODER){
		p_map = TranscodeParamMapTable;
	} else if(pParam->ParamType == HAPI_SET_PARAM_TYPE_DECODER){
		p_map = NULL;
	}
	if(p_map == NULL){
		DbgLogError(("get_param(%p,%s) p_map==NULL for ParamType=%d\n", pParam,  param_name, pParam->ParamType));
		return -2;
	}
    //Special case, ParamType has no bitmask
	if(strcmp("ParamType", param_name) == 0){
		return (Uint32)pParam->ParamType;
	}
	if(get_param_bitmask(pParam, param_name) == 0){
		DbgLogTrace(("get_param(%p,%s) bitmask not set, value is not valid\n", pParam,  param_name));
		return -1;
	}
    for(; p_map->addr != NULL; p_map++)
    {
        if(strcmp(p_map->str, param_name) == 0)
        {
            //get offset from start of HAPI_SET_PARAM struct, and add to base address of target struct
			BYTE *p = (BYTE *)pParam + (((BYTE *)(p_map->addr)) - ((BYTE *)&gParam));

			switch(p_map->type){
			case 0x05: //16bit types
			case 0x06:
				return *((Uint16 *)p);
				break;
			default:
				//everything else is 32bits
				return *((Uint32 *)p);
            }	
        }
    }
	DbgLogError(("get_param(%p,'%s') unknown param name for ParamType=%d\n", pParam,  param_name, pParam->ParamType));
	return -2;
}

#if DBG
const char *CHapi::str_HAPI_SET_PARAM_TYPE(Uint32 value)
{
	switch(value){
	case HAPI_SET_PARAM_TYPE_ENCODER:    return "HAPI_SET_PARAM_TYPE_ENCODER";
	case HAPI_SET_PARAM_TYPE_DECODER:    return "HAPI_SET_PARAM_TYPE_DECODER";
	case HAPI_SET_PARAM_TYPE_TRANSCODER: return "HAPI_SET_PARAM_TYPE_TRANSCODER";
	}
	return "HAPI_SET_PARAM_TYPE_unknown";
}

const char *CHapi::str_HAPI_VIDEO_CODEC(Uint32 value)
{
	switch(value){
	case HAPI_VIDEO_CODEC_UNKNOWN: return "HAPI_VIDEO_CODEC_UNKNOWN";
	case HAPI_VIDEO_CODEC_H264:    return "HAPI_VIDEO_CODEC_H264";
	case HAPI_VIDEO_CODEC_MPG2:    return "HAPI_VIDEO_CODEC_MPG2";
	case HAPI_VIDEO_CODEC_VC1:     return "HAPI_VIDEO_CODEC_VC1";
	case HAPI_VIDEO_CODEC_MPEG2_TO_H264_SINGLE_ENGINE: return "HAPI_VIDEO_CODEC_MPEG2_TO_H264_SINGLE_ENGINE";
	case HAPI_VIDEO_CODEC_H264_LIGHT_ENGINE: return "HAPI_VIDEO_CODEC_H264_LIGHT_ENGINE";
	}
	return "HAPI_VIDEO_CODEC_unknown";
}

const char *CHapi::str_HAPI_VIDEO_OUTPUT_MODE(Uint32 value)
{
	switch(value){
	case HAPI_VIDEO_OUTPUT_MODE_INTERLACED:  return "HAPI_VIDEO_OUTPUT_MODE_INTERLACED";
	case HAPI_VIDEO_OUTPUT_MODE_PROGRESSIVE: return "HAPI_VIDEO_OUTPUT_MODE_PROGRESSIVE";
	case HAPI_VIDEO_OUTPUT_MODE_PSF:         return "HAPI_VIDEO_OUTPUT_MODE_PSF";
	}
	return "HAPI_VIDEO_OUTPUT_MODE_unknown";
}

const char *CHapi::str_HAPI_VIDEO_OUTPUT_FRAME_RATE(Uint32 value)
{
	switch(value){
	case HAPI_VIDEO_OUTPUT_FRAME_RATE_INVALID:return "HAPI_VIDEO_OUTPUT_FRAME_RATE_INVALID";
	case HAPI_VIDEO_OUTPUT_FRAME_RATE_1:      return "HAPI_VIDEO_OUTPUT_FRAME_RATE_1";
	case HAPI_VIDEO_OUTPUT_FRAME_RATE_4:      return "HAPI_VIDEO_OUTPUT_FRAME_RATE_4";
	case HAPI_VIDEO_OUTPUT_FRAME_RATE_6:      return "HAPI_VIDEO_OUTPUT_FRAME_RATE_6";
	case HAPI_VIDEO_OUTPUT_FRAME_RATE_8:      return "HAPI_VIDEO_OUTPUT_FRAME_RATE_8";
	case HAPI_VIDEO_OUTPUT_FRAME_RATE_10:     return "HAPI_VIDEO_OUTPUT_FRAME_RATE_10";
	case HAPI_VIDEO_OUTPUT_FRAME_RATE_12:     return "HAPI_VIDEO_OUTPUT_FRAME_RATE_12";
	case HAPI_VIDEO_OUTPUT_FRAME_RATE_12_5:   return "HAPI_VIDEO_OUTPUT_FRAME_RATE_12_5";	
	case HAPI_VIDEO_OUTPUT_FRAME_RATE_15:     return "HAPI_VIDEO_OUTPUT_FRAME_RATE_15";
	case HAPI_VIDEO_OUTPUT_FRAME_RATE_23_98:  return "HAPI_VIDEO_OUTPUT_FRAME_RATE_23_98";
	case HAPI_VIDEO_OUTPUT_FRAME_RATE_24:     return "HAPI_VIDEO_OUTPUT_FRAME_RATE_24";
	case HAPI_VIDEO_OUTPUT_FRAME_RATE_25:     return "HAPI_VIDEO_OUTPUT_FRAME_RATE_25";
	case HAPI_VIDEO_OUTPUT_FRAME_RATE_29_97:  return "HAPI_VIDEO_OUTPUT_FRAME_RATE_29_97";
	case HAPI_VIDEO_OUTPUT_FRAME_RATE_30:     return "HAPI_VIDEO_OUTPUT_FRAME_RATE_30";
	case HAPI_VIDEO_OUTPUT_FRAME_RATE_50:     return "HAPI_VIDEO_OUTPUT_FRAME_RATE_50";
	case HAPI_VIDEO_OUTPUT_FRAME_RATE_59_94:  return "HAPI_VIDEO_OUTPUT_FRAME_RATE_59_94";
	case HAPI_VIDEO_OUTPUT_FRAME_RATE_60:     return "HAPI_VIDEO_OUTPUT_FRAME_RATE_60";
	}
	return "HAPI_VIDEO_OUTPUT_FRAME_RATE_unknown";
}

const char *CHapi::str_HAPI_RATE_CONTROL(Uint32 value)
{
	switch(value){
	case HAPI_RATE_CONTROL_CBR: return "HAPI_RATE_CONTROL_CBR";
	case HAPI_RATE_CONTROL_VBR: return "HAPI_RATE_CONTROL_VBR";
	case HAPI_RATE_CONTROL_CAPPED_VBR: return "HAPI_RATE_CONTROL_CAPPED_VBR";
	}
	return "HAPI_RATE_CONTROL_unknown";
}

const char *CHapi::str_HAPI_CODING_MODE(Uint32 value)
{
	switch(value){
	case HAPI_CODING_MODE_FRAME: return "HAPI_CODING_MODE_FRAME";
	case HAPI_CODING_MODE_FIELD: return "HAPI_CODING_MODE_FIELD";
	case HAPI_CODING_MODE_MBAFF: return "HAPI_CODING_MODE_MBAFF";
	case HAPI_CODING_MODE_PAFF:  return "HAPI_CODING_MODE_PAFF";
	}
	return "HAPI_CODING_MODE_unknown";
}
    
const char *CHapi::str_HAPI_VIDEO_PROFILE(Uint32 value)
{
	switch(value){
	case HAPI_VIDEO_PROFILE_BASELINE: return "HAPI_VIDEO_PROFILE_BASELINE";
	case HAPI_VIDEO_PROFILE_MAIN:     return "HAPI_VIDEO_PROFILE_MAIN";
	case HAPI_VIDEO_PROFILE_HIGH:     return "HAPI_VIDEO_PROFILE_HIGH";
	}
	return "HAPI_VIDEO_PROFILE_unknown";
}

const char *CHapi::str_HAPI_LATENCY(Uint32 value)
{
	switch(value){
	case HAPI_LATENCY_LOW:    return "HAPI_LATENCY_LOW";
	case HAPI_LATENCY_HIGH:   return "HAPI_LATENCY_HIGH";
	case HAPI_LATENCY_MEDIUM: return "HAPI_LATENCY_MEDIUM";
	}
	return "HAPI_LATENCY_unknown";
}

const char *CHapi::str_HAPI_VIDEO_CAPTURE_SOURCE(Uint32 value)
{
	switch(value){
	case HAPI_VIDEO_CAPTURE_SOURCE_CVBS:      return "HAPI_VIDEO_CAPTURE_SOURCE_CVBS";
	case HAPI_VIDEO_CAPTURE_SOURCE_COMPONENT: return "HAPI_VIDEO_CAPTURE_SOURCE_COMPONENT";
	case HAPI_VIDEO_CAPTURE_SOURCE_SDI:       return "HAPI_VIDEO_CAPTURE_SOURCE_SDI";
	case HAPI_VIDEO_CAPTURE_SOURCE_HDMI:      return "HAPI_VIDEO_CAPTURE_SOURCE_HDMI";
	}
	return "HAPI_VIDEO_CAPTURE_SOURCE_unknown";
}

const char *CHapi::str_HAPI_H264_LEVEL(Uint32 value)
{
	switch(value){
	case HAPI_H264_LEVEL_1:   return "HAPI_H264_LEVEL_1";
	case HAPI_H264_LEVEL_1B:  return "HAPI_H264_LEVEL_1B";
	case HAPI_H264_LEVEL_1_1: return "HAPI_H264_LEVEL_1_1";
	case HAPI_H264_LEVEL_1_2: return "HAPI_H264_LEVEL_1_2";
	case HAPI_H264_LEVEL_1_3: return "HAPI_H264_LEVEL_1_3";
	case HAPI_H264_LEVEL_2:   return "HAPI_H264_LEVEL_2";
	case HAPI_H264_LEVEL_2_1: return "HAPI_H264_LEVEL_2_1";
	case HAPI_H264_LEVEL_2_2: return "HAPI_H264_LEVEL_2_2";
	case HAPI_H264_LEVEL_3:   return "HAPI_H264_LEVEL_3";
	case HAPI_H264_LEVEL_3_1: return "HAPI_H264_LEVEL_3_1";
	case HAPI_H264_LEVEL_3_2: return "HAPI_H264_LEVEL_3_2";
	case HAPI_H264_LEVEL_4:   return "HAPI_H264_LEVEL_4";
	case HAPI_H264_LEVEL_4_1: return "HAPI_H264_LEVEL_4_1";
	case HAPI_H264_LEVEL_4_2: return "HAPI_H264_LEVEL_4_2";
	case HAPI_H264_LEVEL_5:   return "HAPI_H264_LEVEL_5";
	case HAPI_H264_LEVEL_5_1: return "HAPI_H264_LEVEL_5_1";
	}
	return "HAPI_H264_LEVEL_unknown";
}

const char *CHapi::str_HAPI_AUDIO_CODEC(Uint32 value)
{
	switch(value){
	case HAPI_AUDIO_CODEC_UNKNOWN: return "HAPI_AUDIO_CODEC_UNKNOWN";
	case HAPI_AUDIO_CODEC_NONE:    return "HAPI_AUDIO_CODEC_NONE";
	case HAPI_AUDIO_CODEC_MPEG:    return "HAPI_AUDIO_CODEC_MPEG";
	case HAPI_AUDIO_CODEC_AC3:     return "HAPI_AUDIO_CODEC_AC3";
	case HAPI_AUDIO_CODEC_AAC:     return "HAPI_AUDIO_CODEC_AAC";
	case HAPI_AUDIO_CODEC_AACHE:   return "HAPI_AUDIO_CODEC_AACHE";
	case HAPI_AUDIO_CODEC_AACLC:   return "HAPI_AUDIO_CODEC_AACLC";
	case HAPI_AUDIO_CODEC_MP3:     return "HAPI_AUDIO_CODEC_MP3";
	case HAPI_AUDIO_CODEC_DDP:     return "HAPI_AUDIO_CODEC_DDP";
	case HAPI_AUDIO_CODEC_PCM:     return "HAPI_AUDIO_CODEC_PCM";
	case HAPI_AUDIO_CODEC_AUTO:    return "HAPI_AUDIO_CODEC_AUTO";
	case HAPI_AUDIO_ENCODING_MPEG2:      return "HAPI_AUDIO_ENCODING_MPEG2";
	case HAPI_AUDIO_ENCODING_302MPCM:    return "HAPI_AUDIO_ENCODING_302MPCM";
	case HAPI_AUDIO_ENCODING_DOLBYE:     return "HAPI_AUDIO_ENCODING_DOLBYE";
	case HAPI_AUDIO_ENCODING_DOLBYPULSE: return "HAPI_AUDIO_ENCODING_DOLBYPULSE";
	case HAPI_AUDIO_ENCODING_DDPRO:      return "HAPI_AUDIO_ENCODING_DDPRO";
	case HAPI_AUDIO_ENCODING_TESTTONE:   return "HAPI_AUDIO_ENCODING_TESTTONE";
	case HAPI_AUDIO_ENCODING_MPEG4:      return "HAPI_AUDIO_ENCODING_MPEG4";
	case HAPI_AUDIO_ENCODING_DTS:        return "HAPI_AUDIO_ENCODING_DTS";
	case HAPI_AUDIO_CODEC_MAX:           return "HAPI_AUDIO_CODEC_MAX";
	case HAPI_AUDIO_CODEC_PASSTHROUGH:   return "HAPI_AUDIO_CODEC_PASSTHROUGH";
	case HAPI_AUDIO_CODEC_OUTPUTPASSTHROUGH: return "HAPI_AUDIO_CODEC_OUTPUTPASSTHROUGH";
	case HAPI_AUDIO_CODEC_INPUTPASSTHROUGH:  return "HAPI_AUDIO_CODEC_INPUTPASSTHROUGH";
	}
	return "HAPI_AUDIO_CODEC_unknown";
}

const char *CHapi::str_HAPI_AUDIO_SAMPLE_RATE(Uint32 value)
{
	switch(value){
	case HAPI_AUDIO_SAMPLE_RATE_NONE:     return "HAPI_AUDIO_SAMPLE_RATE_NONE";
	case HAPI_AUDIO_SAMPLE_RATE_16_KHZ:   return "HAPI_AUDIO_SAMPLE_RATE_16_KHZ";
	case HAPI_AUDIO_SAMPLE_RATE_32_KHZ:   return "HAPI_AUDIO_SAMPLE_RATE_32_KHZ";
	case HAPI_AUDIO_SAMPLE_RATE_44_1_KHZ: return "HAPI_AUDIO_SAMPLE_RATE_44_1_KHZ";
	case HAPI_AUDIO_SAMPLE_RATE_48_KHZ:   return "HAPI_AUDIO_SAMPLE_RATE_48_KHZ";
	case HAPI_AUDIO_SAMPLE_RATE_96_KHZ:   return "HAPI_AUDIO_SAMPLE_RATE_96_KHZ";
	case HAPI_AUDIO_SAMPLE_RATE_192_KHZ:  return "HAPI_AUDIO_SAMPLE_RATE_192_KHZ";
	case HAPI_AUDIO_SAMPLE_RATE_FOLLOW_INPUT: return "HAPI_AUDIO_SAMPLE_RATE_FOLLOW_INPUT";
	}
	return "HAPI_AUDIO_SAMPLE_RATE_unknown";
}
    
const char *CHapi::str_HAPI_AUDIO_BITRATE(Uint32 value)
{
	switch(value){
	case HAPI_AUDIO_BITRATE_NONE:      return "HAPI_AUDIO_BITRATE_NONE";
	case HAPI_AUDIO_BITRATE_8_KBPS:    return "HAPI_AUDIO_BITRATE_8_KBPS";
	case HAPI_AUDIO_BITRATE_16_KBPS:   return "HAPI_AUDIO_BITRATE_16_KBPS";
	case HAPI_AUDIO_BITRATE_32_KBPS:   return "HAPI_AUDIO_BITRATE_32_KBPS";
	case HAPI_AUDIO_BITRATE_48_KBPS:   return "HAPI_AUDIO_BITRATE_48_KBPS";
	case HAPI_AUDIO_BITRATE_56_KBPS:   return "HAPI_AUDIO_BITRATE_56_KBPS";
	case HAPI_AUDIO_BITRATE_64_KBPS:   return "HAPI_AUDIO_BITRATE_64_KBPS";
	case HAPI_AUDIO_BITRATE_80_KBPS:   return "HAPI_AUDIO_BITRATE_80_KBPS";
	case HAPI_AUDIO_BITRATE_96_KBPS:   return "HAPI_AUDIO_BITRATE_96_KBPS";
	case HAPI_AUDIO_BITRATE_112_KBPS:  return "HAPI_AUDIO_BITRATE_112_KBPS";
	case HAPI_AUDIO_BITRATE_128_KBPS:  return "HAPI_AUDIO_BITRATE_128_KBPS";
	case HAPI_AUDIO_BITRATE_160_KBPS:  return "HAPI_AUDIO_BITRATE_160_KBPS";
	case HAPI_AUDIO_BITRATE_192_KBPS:  return "HAPI_AUDIO_BITRATE_192_KBPS";
	case HAPI_AUDIO_BITRATE_224_KBPS:  return "HAPI_AUDIO_BITRATE_224_KBPS";
	case HAPI_AUDIO_BITRATE_256_KBPS:  return "HAPI_AUDIO_BITRATE_256_KBPS";
	case HAPI_AUDIO_BITRATE_320_KBPS:  return "HAPI_AUDIO_BITRATE_320_KBPS";
	case HAPI_AUDIO_BITRATE_384_KBPS:  return "HAPI_AUDIO_BITRATE_384_KBPS";
	case HAPI_AUDIO_BITRATE_448_KBPS:  return "HAPI_AUDIO_BITRATE_448_KBPS";
	case HAPI_AUDIO_BITRATE_576_KBPS:  return "HAPI_AUDIO_BITRATE_576_KBPS";
	case HAPI_AUDIO_BITRATE_640_KBPS:  return "HAPI_AUDIO_BITRATE_640_KBPS";
	case HAPI_AUDIO_BITRATE_768_KBPS:  return "HAPI_AUDIO_BITRATE_768_KBPS";
	case HAPI_AUDIO_BITRATE_960_KBPS:  return "HAPI_AUDIO_BITRATE_960_KBPS";
	case HAPI_AUDIO_BITRATE_1024_KBPS: return "HAPI_AUDIO_BITRATE_1024_KBPS";
	case HAPI_AUDIO_BITRATE_1152_KBPS: return "HAPI_AUDIO_BITRATE_1152_KBPS";
	case HAPI_AUDIO_BITRATE_1280_KBPS: return "HAPI_AUDIO_BITRATE_1280_KBPS";
	case HAPI_AUDIO_BITRATE_1344_KBPS: return "HAPI_AUDIO_BITRATE_1344_KBPS";
	case HAPI_AUDIO_BITRATE_1408_KBPS: return "HAPI_AUDIO_BITRATE_1408_KBPS";
	case HAPI_AUDIO_BITRATE_1411_KBPS: return "HAPI_AUDIO_BITRATE_1411_KBPS";
	case HAPI_AUDIO_BITRATE_1472_KBPS: return "HAPI_AUDIO_BITRATE_1472_KBPS";
	case HAPI_AUDIO_BITRATE_1536_KBPS: return "HAPI_AUDIO_BITRATE_1536_KBPS";
	}
	return "HAPI_AUDIO_BITRATE_unknown";
}

const char *CHapi::str_HAPI_AUDIO_OUTPUT_MODE(Uint32 value)
{
	switch(value){
	case HAPI_AUDIO_CHANNELS_NONE:        return "HAPI_AUDIO_CHANNELS_NONE";
	case HAPI_AUDIO_CHANNELS_DUALMONO:    return "HAPI_AUDIO_CHANNELS_DUALMONO";
	case HAPI_AUDIO_CHANNELS_STEREO:      return "HAPI_AUDIO_CHANNELS_STEREO";
	case HAPI_AUDIO_CHANNELS_MONO:        return "HAPI_AUDIO_CHANNELS_MONO";
	case HAPI_AUDIO_CHANNELS_LEFTMONO:    return "HAPI_AUDIO_CHANNELS_LEFTMONO";
	case HAPI_AUDIO_CHANNELS_RIGHTMONO:   return "HAPI_AUDIO_CHANNELS_RIGHTMONO";
//	case HAPI_AUDIO_CHANNELS_LEFTSTEREO:  return "HAPI_AUDIO_CHANNELS_LEFTSTEREO";
//	case HAPI_AUDIO_CHANNELS_RIGHTSTEREO: return "HAPI_AUDIO_CHANNELS_RIGHTSTEREO";
	case HAPI_AUDIO_CHANNELS_RANGE:       return "HAPI_AUDIO_CHANNELS_RANGE";
	}
	return "HAPI_AUDIO_OUTPUT_MODE_unknown";
}

const char *CHapi::str_HAPI_AUDIO_CAPTURE_SOURCE(Uint32 value)
{
	switch(value){
	case HAPI_AUDIO_CAPTURE_SOURCE_LR:    return "HAPI_AUDIO_CAPTURE_SOURCE_LR";
	case HAPI_AUDIO_CAPTURE_SOURCE_SPDIF: return "HAPI_AUDIO_CAPTURE_SOURCE_SPDIF";
	case HAPI_AUDIO_CAPTURE_SOURCE_SDI:   return "HAPI_AUDIO_CAPTURE_SOURCE_SDI";
	case HAPI_AUDIO_CAPTURE_SOURCE_HDMI:  return "HAPI_AUDIO_CAPTURE_SOURCE_HDMI";
	}
	return "HAPI_AUDIO_CAPTURE_SOURCE_unknown";
}

void CHapi::printParam(HAPI_SET_PARAM *pParam)
{
	DbgLogInfo(("printParam(%p)\n", pParam));

	Parameter_Map_Item *p_map = NULL;
	if(pParam->ParamType == HAPI_SET_PARAM_TYPE_ENCODER){
		p_map = EncodeParamMapTable;
	} else if(pParam->ParamType == HAPI_SET_PARAM_TYPE_TRANSCODER){
		p_map = TranscodeParamMapTable;
	} else if(pParam->ParamType == HAPI_SET_PARAM_TYPE_DECODER){
		p_map = NULL;
	}
	if(p_map == NULL){
		DbgLogError(("printParam() p_map==NULL for ParamType=%d\n", pParam->ParamType));
		return;
	}
    for(; p_map->addr != NULL; p_map++)
    {
        //get offset from start of HAPI_SET_PARAM struct, and add to base address of target struct
		BYTE *p = (BYTE *)pParam + (((BYTE *)(p_map->addr)) - ((BYTE *)&gParam));
			
		Uint32 value = *((Uint32 *)p);
		Uint16 value16 = *((Uint16 *)p);

		if(get_param_bitmask(pParam, p_map->str) == 0){
			if(value16 != 0){
				DbgLogWarn((" '%s' bitmask not set, but value is (0x%x)\n", p_map->str, value16));
			} else {
			//	DbgLogTrace((" '%s' bitmask not set, skipping\n", p_map->str));
			}
			continue;
		}
		switch(p_map->type){
		case -1://Do not display - ignore older "non-standard" param names
			break;
		case 0x00://decimal number
			DbgLogInfo(("%s:  %d\n", p_map->str, value)); break;
		case 0x02://hex number
			DbgLogInfo(("%s:  0x%x\n", p_map->str, value)); break;
		case 0x03://PID
			DbgLogInfo(("%s:  0x%x(%d)\n", p_map->str, value, value)); break;
		case 0x04://HAPI_SET_PARAM_TYPE
			DbgLogInfo(("%s:  %d=%s\n", p_map->str, value, str_HAPI_SET_PARAM_TYPE(value) )); break;
		case 0x05://16bit decimal number
			DbgLogInfo(("%s:  %d\n", p_map->str, value16)); break;
		case 0x06://16bit hex number
			DbgLogInfo(("%s:  0x%x\n", p_map->str, value16)); break;
		

		case 0x10://HAPI_VIDEO_CODEC
			DbgLogInfo(("%s:  %d=%s\n", p_map->str, value, str_HAPI_VIDEO_CODEC(value) )); break;
		case 0x11://HAPI_VIDEO_OUTPUT_MODE
			DbgLogInfo(("%s:  %d=%s\n", p_map->str, value, str_HAPI_VIDEO_OUTPUT_MODE(value) )); break;
		case 0x12://HAPI_VIDEO_OUTPUT_FRAME_RATE
			DbgLogInfo(("%s:  %d=%s\n", p_map->str, value, str_HAPI_VIDEO_OUTPUT_FRAME_RATE(value) )); break;
		case 0x13://HAPI_RATE_CONTROL
			DbgLogInfo(("%s:  %d=%s\n", p_map->str, value, str_HAPI_RATE_CONTROL(value) )); break;
		case 0x14://HAPI_CODING_MODE
			DbgLogInfo(("%s:  %d=%s\n", p_map->str, value, str_HAPI_CODING_MODE(value) )); break;
		case 0x15://HAPI_VIDEO_PROFILE
			DbgLogInfo(("%s:  %d=%s\n", p_map->str, value, str_HAPI_VIDEO_PROFILE(value) )); break;
		case 0x16://HAPI_LATENCY
			DbgLogInfo(("%s:  %d=%s\n", p_map->str, value, str_HAPI_LATENCY(value) )); break;
		
		case 0x18://HAPI_VIDEO_CAPTURE_SOURCE
			DbgLogInfo(("%s:  %d=%s\n", p_map->str, value, str_HAPI_VIDEO_CAPTURE_SOURCE(value) )); break;
		case 0x19://HAPI_H264_LEVEL
			DbgLogInfo(("%s:  %d=%s\n", p_map->str, value, str_HAPI_H264_LEVEL(value) )); break;
		
		case 0x20://HAPI_AUDIO_CODEC
			DbgLogInfo(("%s:  %d=%s\n", p_map->str, value, str_HAPI_AUDIO_CODEC(value) )); break;
		case 0x21://HAPI_AUDIO_SAMPLE_RATE
			DbgLogInfo(("%s:  %d=%s\n", p_map->str, value, str_HAPI_AUDIO_SAMPLE_RATE(value) )); break;
		case 0x22://HAPI_AUDIO_BITRATE
			DbgLogInfo(("%s:  %d=%s\n", p_map->str, value, str_HAPI_AUDIO_BITRATE(value) )); break;
			

		case 0x24://HAPI_AUDIO_OUTPUT_MODE
			DbgLogInfo(("%s:  %d=%s\n", p_map->str, value, str_HAPI_AUDIO_OUTPUT_MODE(value) )); break;
		case 0x25://HAPI_AUDIO_CAPTURE_SOURCE
			DbgLogInfo(("%s:  %d=%s\n", p_map->str, value, str_HAPI_AUDIO_CAPTURE_SOURCE(value) )); break;

		default:
			DbgLogInfo(("%s:  %d(0x%x)\n", p_map->str, *((Uint32 *)p), *((Uint32 *)p)));
		}

	//0x16=HAPI_LATENCY 0x17=HAPI_VIDEO_ENTROPY_MODE 

	//0x23=HAPI_AUDIO_TRANSCODE_MODE
	//0x26=HAPI_AUDIO_CAPTURE_MODE	0x27=HAPI_AUDIO_CAPTURE_SPDIF_INPUT

    }
}
#endif//DBG

void CHapi::set_transcode_a7_1080i_to_h264_1920x544(HAPI_SET_PARAM *pParam)
{
	DbgLogInfo(("call set_transcode_a7_1080i_to_h264_1920x544()\n"));

	set_param(pParam, "ParamType" , 2);  // 0-encode, 1-decode, 2-transcode
	
//input stream
	set_param(pParam, "InputVideoPID", 0x31); // Input Video PID
	set_param(pParam, "InputPCRPID",   0x31); // Input PCR PID
	set_param(pParam, "InputAudioPID", 0x34); // Input Audio PID
	set_param(pParam, "SubtitlePID", 0);// Input Subtitle PID 
	set_param(pParam, "TeletextPID", 0);// Input teletext PID

//output stream
	//set_param(pParam, "OutputAudioPID", 53); // 0 - follow input
	//set_param(pParam, "OutputVideoPID", 49); // 0 - follow input
	set_param(pParam, "VideoOutputPID", 0x131); // 0 - follow input
	set_param(pParam, "OutputPCRPID",   0x131); // 0 - follow input
	set_param(pParam, "AudioOutputPID", 0x134); // 0 - follow input

//video
	set_param(pParam, "VideoCodecInputFormat", 1);// 0 - 264, 1 - MPEG2, 2 - VC1
	set_param(pParam, "VideoCodecOutputFormat", 4);  // 4 - 264, 2 - VC1
	set_param(pParam, "VideoOutputWidth", 720);  // output video width
	set_param(pParam, "VideoOutputHeight", 480);  // output video height
	set_param(pParam, "VideoOutputMode", 1);// 0 - interlaced, 1 - progressive
	set_param(pParam, "VideoOutputFrameRate", 4);     // 1 - 23.98, 2 - 24, 3 - 25, 4 - 29.97, 5 - 30, 6 - 50, 7 - 59.94, 8 - 60, 9 - 15, 10 - 10, 11 - 6, 12 - 5, 13 - 2, 14 - 1
	set_param(pParam, "VideoOutputBitrate", 2000000); // Output video bitrate
//	set_param(pParam, "VideoRateControlMode", 1);// CBR - 0, VBR - 1, CAPPED_VBR - 2
	set_param(pParam, "VideoRateControl", 1);// CBR - 0, VBR - 1, CAPPED_VBR - 2
	set_param(pParam, "VideoCodingMode", 0);// 0 - Frame, 1 - field, 2 - MBAFF, 3 - PAFF
	set_param(pParam, "VideoVBRMin", 1500000);
	set_param(pParam, "VideoVBRMax", 3000000);
	set_param(pParam, "VideoProfile", 0);// H264: 0 - Constrained baseline, 3 - Main, 4 - High  Mpg2: 0 - Simple, 3 - Main, 4 - High
	set_param(pParam, "VideoLevel", 400);
	set_param(pParam, "VideoOutputTSBitrate", 8000000);
	set_param(pParam, "VideoLatency", 1);// 0 - low latency, 1 - high latency

//audio
	set_param(pParam, "AudioCodecInputFormat", 9);  // 1 - MPEG, 2 - AC3,3 - AAC, 6 - MP3, 8 - PCM, 9 - PASSTHROUGH
	set_param(pParam, "AudioCodecOutputFormat", 2);  // 1 - MPEG, 2 - AC3,3 - AAC, 6 - MP3, 8 - PCM, 9 - PASSTHROUGH
	set_param(pParam, "AudioOutputMode", 1);// Stereo - 1, Mono - 2, refer to header file for more options
	set_param(pParam, "AudioOutputSamplingRate", 3);  // 1 - 32K, 2 - 44.1K, 3 - 48K
	set_param(pParam, "AudioOutputBitrate", 13);  // 13=384kbps: 0-32, 1-48, 2-56, 3-64, 4-80, 5-96, 6-112, 7-128, 8-160, 9-192, 10-224, 11-256, 
}

void CHapi::set_transcode_1080i_to_480i_h264(HAPI_SET_PARAM *pParam)
{
	DbgLogInfo(("call set_transcode_1080i_to_480i_h264()\n"));

	set_param(pParam, "ParamType" , 2);  // 0-encode, 1-decode, 2-transcode

	set_param(pParam, "InputAudioPID", 4113);	// Input Audio PID
	set_param(pParam, "InputVideoPID", 4112);	// Input Video PID
	set_param(pParam, "InputPCRPID", 511);	// Input PCR PID
	set_param(pParam, "SubtitlePID", 0);  // Input Subtitle PID 
	set_param(pParam, "TeletextPID", 0);  // Input teletext PID

//output stream
	set_param(pParam, "OutputAudioPID", 0);	// 0 - follow input
	set_param(pParam, "OutputVideoPID", 0);	// 0 - follow input
	set_param(pParam, "OutputPCRPID", 0);	// 0 - follow input

//video
	set_param(pParam, "VideoCodecInputFormat", 0);  // 0 - 264, 1 - MPEG2, 2 - VC1
	set_param(pParam, "VideoCodecOutputFormat", 4);  // 4 - 264, 2 - VC1
	set_param(pParam, "VideoOutputWidth", 720);  // output video width
	set_param(pParam, "VideoOutputHeight", 480);  // output video height
	set_param(pParam, "VideoOutputMode", 0);  // 0 - interlaced, 1 - progressive
	set_param(pParam, "VideoOutputFrameRate", 4);     // 1 - 23.98, 2 - 24, 3 - 25, 4 - 29.97, 5 - 30, 6 - 50, 7 - 59.94, 8 - 60, 9 - 15, 10 - 10, 11 - 6, 12 - 5, 13 - 2, 14 - 1
	set_param(pParam, "VideoOutputBitrate", 3000000); // Output video bitrate
	set_param(pParam, "VideoRateControlMode", 1);   // CBR - 0, VBR - 1, CAPPED_VBR - 2
	set_param(pParam, "VideoCodingMode", 1);   // 0 - Frame, 1 - field, 2 - MBAFF, 3 - PAFF
	set_param(pParam, "VideoVBRMin", 2000000);
	set_param(pParam, "VideoVBRMax", 6000000);
	set_param(pParam, "VideoProfile", 0);  // H264: 0 - Constrained baseline, 3 - Main, 4 - High  Mpg2: 0 - Simple, 3 - Main, 4 - High
	set_param(pParam, "VideoLevel", 400);
	set_param(pParam, "VideoOutputTSBitrate", 7000000);
	set_param(pParam, "VideoLatency", 1);  // 0 - low latency, 1 - high latency

//audio
	set_param(pParam, "AudioCodecInputFormat", 3);  // 1 - MPEG, 2 - AC3,3 - AAC, 6 - MP3, 8 - PCM, 9 - PASSTHROUGH
	set_param(pParam, "AudioCodecOutputFormat", 3);  // 1 - MPEG, 2 - AC3,3 - AAC, 6 - MP3, 8 - PCM, 9 - PASSTHROUGH
	set_param(pParam, "AudioOutputMode", 1);  // Stereo - 1, Mono - 2, refer to header file for more options
	set_param(pParam, "AudioOutputSamplingRate", 2);  // 1 - 32K, 2 - 44.1K, 3 - 48K
	set_param(pParam, "AudioOutputBitrate", 7);  // kbps: 0-32, 1-48, 2-56, 3-64, 4-80, 5-96, 6-112, 7-128, 8-160, 9-192, 10-224, 11-256, 
}

void CHapi::set_encode_1080i60_h264(HAPI_SET_PARAM *pParam)
{
	DbgLogInfo(("call set_encode_1080i60_h264()\n"));

	set_param(pParam, "ParamType" , 0);  // 0-encode, 1-decode, 2-transcode

	set_param(pParam, "OutputPCRPID", defaultPCROutputPID);        // 0 - follow input, invalid for encoder. Must be greater than 0x0F, Suggest to be greater than 0x1F.

	set_param(pParam, "VideoStreamID", 2);         
	set_param(pParam, "VideoOutputPID", defaultVideoOutputPID);        // Must be greater than 0x0F, Suggest to be greater than 0x1F. 
	set_param(pParam, "VideoCapSource", 3);         // 0:COMP, 1:YUV, 2:SDI, 3:HDMI
	set_param(pParam, "VideoCapWidth", 1920);  
	set_param(pParam, "VideoCapHeight", 1080);      // Frame height always
	set_param(pParam, "VideoCapFormat", 0);         // 0: interlaced, 1:progressive 2: psf
	set_param(pParam, "VideoCapFrameRate", 4);         // 1 - 23.98, 2 - 24, 3 - 25, 4 - 29.97, 5 - 30, 6 - 50, 7 - 59.94, 8 - 60, 9 - 15, 10 - 10, 11 - 6, 12 - 5, 13 - 2, 14 - 1
	set_param(pParam, "VideoCodecOutputFormat", 4);         // 1: MPEG2, 4: H.264
	set_param(pParam, "VideoOutputWidth", 1920); // 1280 // 720 // 1440 // 1920       // output video width
	set_param(pParam, "VideoOutputHeight", 1080); // 720  // 480 // 1080 // 1080       // output video frame height always
	set_param(pParam, "VideoOutputMode", 0); // 1 // 0         // 0: interlaced, 1:progressive 2: psf?
	set_param(pParam, "VideoOutputFrameRate", 4); // 7 // 4         // 1 - 23.98, 2 - 24, 3 - 25, 4 - 29.97, 5 - 30, 6 - 50, 7 - 59.94, 8 - 60, 9 - 15, 10 - 10, 11 - 6, 12 - 5, 13 - 2, 14 - 1
	set_param(pParam, "VideoOutputBitrate", 6000000);   // Output video bitrate in bps
	set_param(pParam, "VideoRateControl", 0);         // 0:CBR, 1: VBR, 2: CAPPED_VBR
	set_param(pParam, "VBRMin", 5000000);   // in bps
	set_param(pParam, "VBRMax", 7000000);   // in bps
	set_param(pParam, "VideoCodingMode", 1); // 4 // 1 // 0         // 0 - Frame, 1 - field, 2 - MBAFF, 3 - PAFF, 4 - INVALID(FOLLOW_INPUT)
	set_param(pParam, "VideoProfile", 4);         // H264: 0 - Constrained baseline, 3 - Main, 4 - High
	set_param(pParam, "VideoLevel", 400);       // 100-LEVEL_1, 105-LEVEL_1B, 110-LEVEL_1.1, 120-LEVEL_1.2, 130-LEVEL_1.3, 200-LEVEL_2, 210-LEVEL_2.1, 220-LEVEL_2.2, 300-LEVEL_3, 310-LEVEL_3.1, 320-LEVEL_3.2, 400-LEVEL_4, 410-LEVEL_4.1, 420-LEVEL_4.2, 500-LEVEL_5, 510-LEVEL_5.1
	set_param(pParam, "VideoTSBitrate", 9000000);  // in bps
	set_param(pParam, "VideoLatency", 1);         // 0 - low latency, 1 - high latency
	set_param(pParam, "NumBFrames", 3);
	set_param(pParam, "InsertIFrame", 0);
	set_param(pParam, "CabacCoding", 1);
	set_param(pParam, "DeblockFilter", 0);
    
// add audio params

	set_param(pParam, "AudioStreamID", 192);         
	set_param(pParam, "AudioOutputPID", defaultAudioOutputPID);       // Must be greater than 0x0F, Suggest to be greater than 0x1F.
//	set_param(pParam, "AudioCapSource", 3);         // 0: LR, 1:SPDIF, 2:SDI, 3: HDMI
	set_param(pParam, "AudioCapSampleRate", 3);         // in kHz. 0: NONE 1:32, 2: 44.1,3:48,4:96, 5:192, 6:16
	set_param(pParam, "AudioCapMode", 1);         // 0: drop, 1:Frame, 2: frame-frame, 3: AAC(Sub_frame), 5: Downmix               
	set_param(pParam, "AudioCapSPDIFInput", 0);         // 0:COAX, 1: 19977, 2: AES_EBU, 3: opTICAL
	set_param(pParam, "AudioCodecOutputFormat", 3);         // 1-MPEG, 2-AC3, 3-AAC, 6-MP3, 8-PCM, 9-PASSTHROUGH
	set_param(pParam, "AudioOutputMode", 1);         // Stereo - 1, Mono - 2, refer to header file for more options
	set_param(pParam, "AudioOutputSamplingRate", 3);         // 1 - 32K, 2 - 44.1K, 3 - 48K
	set_param(pParam, "AudioOutputBitrate", 9); // 7         // kbps: 0-32,1-48,2-56,3-64,4-80,5-96,6-112,7-128,8-160,9-192,10-224, 11-256, 
}

void CHapi::set_encode_1080p60_h264(HAPI_SET_PARAM *pParam)
{
	DbgLogInfo(("call set_encode_1080p60_h264()\n"));

	set_param(pParam, "ParamType" , 0);  // 0-encode, 1-decode, 2-transcode

	set_param(pParam, "OutputPCRPID", defaultPCROutputPID);        // 0 - follow input, invalid for encoder. Must be greater than 0x0F, Suggest to be greater than 0x1F.

	set_param(pParam, "VideoStreamID", 2);         
	set_param(pParam, "VideoOutputPID", defaultVideoOutputPID);        // Must be greater than 0x0F, Suggest to be greater than 0x1F. 
	set_param(pParam, "VideoCapSource", 3);         // 0:COMP, 1:YUV, 2:SDI, 3:HDMI
	set_param(pParam, "VideoCapWidth", 1920);  
	set_param(pParam, "VideoCapHeight", 1080);      // Frame height always
	set_param(pParam, "VideoCapFormat", 1);         // 0: interlaced, 1:progressive 2: psf
	set_param(pParam, "VideoCapFrameRate", 7);         // 1 - 23.98, 2 - 24, 3 - 25, 4 - 29.97, 5 - 30, 6 - 50, 7 - 59.94, 8 - 60, 9 - 15, 10 - 10, 11 - 6, 12 - 5, 13 - 2, 14 - 1
	set_param(pParam, "VideoCodecOutputFormat", 4);         // 1: MPEG2, 4: H.264
	set_param(pParam, "VideoOutputWidth", 1920); // 1280 // 720 // 1440 // 1920       // output video width
	set_param(pParam, "VideoOutputHeight", 1080); // 720  // 480 // 1080 // 1080       // output video frame height always
	set_param(pParam, "VideoOutputMode", 1); // 1 // 0         // 0: interlaced, 1:progressive 2: psf?
	set_param(pParam, "VideoOutputFrameRate", 4); // 7 // 4         // 1 - 23.98, 2 - 24, 3 - 25, 4 - 29.97, 5 - 30, 6 - 50, 7 - 59.94, 8 - 60, 9 - 15, 10 - 10, 11 - 6, 12 - 5, 13 - 2, 14 - 1
	set_param(pParam, "VideoOutputBitrate", 6000000);   // Output video bitrate in bps
	set_param(pParam, "VideoRateControl", 0);         // 0:CBR, 1: VBR, 2: CAPPED_VBR
	set_param(pParam, "VBRMin", 5000000);   // in bps
	set_param(pParam, "VBRMax", 7000000);   // in bps
	set_param(pParam, "VideoCodingMode", 0); // 4 // 1 // 0         // 0 - Frame, 1 - field, 2 - MBAFF, 3 - PAFF, 4 - INVALID(FOLLOW_INPUT)
	set_param(pParam, "VideoProfile", 4);         // H264: 0 - Constrained baseline, 3 - Main, 4 - High
	set_param(pParam, "VideoLevel", 400);       // 100-LEVEL_1, 105-LEVEL_1B, 110-LEVEL_1.1, 120-LEVEL_1.2, 130-LEVEL_1.3, 200-LEVEL_2, 210-LEVEL_2.1, 220-LEVEL_2.2, 300-LEVEL_3, 310-LEVEL_3.1, 320-LEVEL_3.2, 400-LEVEL_4, 410-LEVEL_4.1, 420-LEVEL_4.2, 500-LEVEL_5, 510-LEVEL_5.1
	set_param(pParam, "VideoTSBitrate", 9000000);  // in bps
	set_param(pParam, "VideoLatency", 1);         // 0 - low latency, 1 - high latency
	set_param(pParam, "NumBFrames", 3);
	set_param(pParam, "InsertIFrame", 0);
	set_param(pParam, "CabacCoding", 1);
	set_param(pParam, "DeblockFilter", 0);
    
// add audio params

	set_param(pParam, "AudioStreamID", 192);         
	set_param(pParam, "AudioOutputPID", defaultAudioOutputPID);       // Must be greater than 0x0F, Suggest to be greater than 0x1F.
//	set_param(pParam, "AudioCapSource", 3);         // 0: LR, 1:SPDIF, 2:SDI, 3: HDMI
	set_param(pParam, "AudioCapSampleRate", 3);         // in kHz. 0: NONE 1:32, 2: 44.1,3:48,4:96, 5:192, 6:16
	set_param(pParam, "AudioCapMode", 1);         // 0: drop, 1:Frame, 2: frame-frame, 3: AAC(Sub_frame), 5: Downmix               
	set_param(pParam, "AudioCapSPDIFInput", 0);         // 0:COAX, 1: 19977, 2: AES_EBU, 3: opTICAL
	set_param(pParam, "AudioCodecOutputFormat", 3);         // 1-MPEG, 2-AC3, 3-AAC, 6-MP3, 8-PCM, 9-PASSTHROUGH
	set_param(pParam, "AudioOutputMode", 1);         // Stereo - 1, Mono - 2, refer to header file for more options
	set_param(pParam, "AudioOutputSamplingRate", 3);         // 1 - 32K, 2 - 44.1K, 3 - 48K
	set_param(pParam, "AudioOutputBitrate", 9); // 7         // kbps: 0-32,1-48,2-56,3-64,4-80,5-96,6-112,7-128,8-160,9-192,10-224, 11-256, 
}

void CHapi::set_encode_720p60_h264(HAPI_SET_PARAM *pParam)
{
	DbgLogInfo(("call set_encode_720p60_h264()\n"));

	set_param(pParam, "ParamType" , 0);  // 0-encode, 1-decode, 2-transcode

	set_param(pParam, "OutputPCRPID", defaultPCROutputPID);        // 0 - follow input, invalid for encoder. Must be greater than 0x0F, Suggest to be greater than 0x1F.

	set_param(pParam, "VideoStreamID", 2);         
	set_param(pParam, "VideoOutputPID", defaultVideoOutputPID);        // Must be greater than 0x0F, Suggest to be greater than 0x1F. 
	set_param(pParam, "VideoCapSource", 3);         // 0:COMP, 1:YUV, 2:SDI, 3:HDMI
	set_param(pParam, "VideoCapWidth", 1280);  
	set_param(pParam, "VideoCapHeight", 720);      // Frame height always
	set_param(pParam, "VideoCapFormat", 1);         // 0: interlaced, 1:progressive 2: psf
	set_param(pParam, "VideoCapFrameRate", 7);         // 1 - 23.98, 2 - 24, 3 - 25, 4 - 29.97, 5 - 30, 6 - 50, 7 - 59.94, 8 - 60, 9 - 15, 10 - 10, 11 - 6, 12 - 5, 13 - 2, 14 - 1
	set_param(pParam, "VideoCodecOutputFormat", 4);         // 1: MPEG2, 4: H.264
	set_param(pParam, "VideoOutputWidth", 1280); // 1280 // 720 // 1440 // 1920       // output video width
	set_param(pParam, "VideoOutputHeight", 720); // 720  // 480 // 1080 // 1080       // output video frame height always
	set_param(pParam, "VideoOutputMode", 1); // 1 // 0         // 0: interlaced, 1:progressive 2: psf?
	set_param(pParam, "VideoOutputFrameRate", 7); // 7 // 4         // 1 - 23.98, 2 - 24, 3 - 25, 4 - 29.97, 5 - 30, 6 - 50, 7 - 59.94, 8 - 60, 9 - 15, 10 - 10, 11 - 6, 12 - 5, 13 - 2, 14 - 1
	set_param(pParam, "VideoOutputBitrate", 6000000);   // Output video bitrate in bps
	set_param(pParam, "VideoRateControl", 1);         // 0:CBR, 1: VBR, 2: CAPPED_VBR
	set_param(pParam, "VBRMin", 5000000);   // in bps
	set_param(pParam, "VBRMax", 7000000);   // in bps
	set_param(pParam, "VideoCodingMode", 0); // 4 // 1 // 0         // 0 - Frame, 1 - field, 2 - MBAFF, 3 - PAFF, 4 - INVALID(FOLLOW_INPUT)
	set_param(pParam, "VideoProfile", 4);         // H264: 0 - Constrained baseline, 3 - Main, 4 - High
	set_param(pParam, "VideoLevel", 400);       // 100-LEVEL_1, 105-LEVEL_1B, 110-LEVEL_1.1, 120-LEVEL_1.2, 130-LEVEL_1.3, 200-LEVEL_2, 210-LEVEL_2.1, 220-LEVEL_2.2, 300-LEVEL_3, 310-LEVEL_3.1, 320-LEVEL_3.2, 400-LEVEL_4, 410-LEVEL_4.1, 420-LEVEL_4.2, 500-LEVEL_5, 510-LEVEL_5.1
	set_param(pParam, "VideoTSBitrate", 9000000);  // in bps
	set_param(pParam, "VideoLatency", 1);         // 0 - low latency, 1 - high latency
	set_param(pParam, "NumBFrames", 3);
	set_param(pParam, "InsertIFrame", 0);
	set_param(pParam, "CabacCoding", 1);
	set_param(pParam, "DeblockFilter", 0);

// add audio params

	set_param(pParam, "AudioStreamID", 192);         
	set_param(pParam, "AudioOutputPID", defaultAudioOutputPID);       // Must be greater than 0x0F, Suggest to be greater than 0x1F.
//	set_param(pParam, "AudioCapSource", 0);         // 0: LR, 1:SPDIF, 2:SDI, 3: HDMI
	set_param(pParam, "AudioCapSampleRate", 3);         // in kHz. 0: NONE 1:32, 2: 44.1,3:48,4:96, 5:192, 6:16
	set_param(pParam, "AudioCapMode", 1);         // 0: drop, 1:Frame, 2: frame-frame, 3: AAC(Sub_frame), 5: Downmix               
	set_param(pParam, "AudioCapSPDIFInput", 0);         // 0:COAX, 1: 19977, 2: AES_EBU, 3: opTICAL
	set_param(pParam, "AudioCodecOutputFormat", 3);         // 1-MPEG, 2-AC3, 3-AAC, 6-MP3, 8-PCM, 9-PASSTHROUGH
	set_param(pParam, "AudioOutputMode", 1);         // Stereo - 1, Mono - 2, refer to header file for more options
	set_param(pParam, "AudioOutputSamplingRate", 3);         // 1 - 32K, 2 - 44.1K, 3 - 48K
	set_param(pParam, "AudioOutputBitrate", 9); // 7         // kbps: 0-32,1-48,2-56,3-64,4-80,5-96,6-112,7-128,8-160,9-192,10-224, 11-256, 
}

void CHapi::set_encode_480p60_h264(HAPI_SET_PARAM *pParam)
{
	DbgLogInfo(("call set_encode_480p60_h264()\n"));

	set_param(pParam, "ParamType" , 0);  // 0-encode, 1-decode, 2-transcode

	set_param(pParam, "OutputPCRPID", defaultPCROutputPID);        // 0 - follow input, invalid for encoder. Must be greater than 0x0F, Suggest to be greater than 0x1F.

	set_param(pParam, "VideoStreamID", 2);         
	set_param(pParam, "VideoOutputPID", defaultVideoOutputPID);        // Must be greater than 0x0F, Suggest to be greater than 0x1F. 
	set_param(pParam, "VideoCapSource", 3);         // 0:COMP, 1:YUV, 2:SDI, 3:HDMI
	set_param(pParam, "VideoCapWidth", 720);  
	set_param(pParam, "VideoCapHeight", 480);      // Frame height always
	set_param(pParam, "VideoCapFormat", 1);         // 0: interlaced, 1:progressive 2: psf
	set_param(pParam, "VideoCapFrameRate", 7);         // 1 - 23.98, 2 - 24, 3 - 25, 4 - 29.97, 5 - 30, 6 - 50, 7 - 59.94, 8 - 60, 9 - 15, 10 - 10, 11 - 6, 12 - 5, 13 - 2, 14 - 1
	set_param(pParam, "VideoCodecOutputFormat", 4);         // 1: MPEG2, 4: H.264
	set_param(pParam, "VideoOutputWidth", 720); // 1280 // 720 // 1440 // 1920       // output video width
	set_param(pParam, "VideoOutputHeight", 480); // 720  // 480 // 1080 // 1080       // output video frame height always
	set_param(pParam, "VideoOutputMode", 1); // 1 // 0         // 0: interlaced, 1:progressive 2: psf?
	set_param(pParam, "VideoOutputFrameRate", 7); // 7 // 4         // 1 - 23.98, 2 - 24, 3 - 25, 4 - 29.97, 5 - 30, 6 - 50, 7 - 59.94, 8 - 60, 9 - 15, 10 - 10, 11 - 6, 12 - 5, 13 - 2, 14 - 1
	set_param(pParam, "VideoOutputBitrate", 6000000);   // Output video bitrate in bps
	set_param(pParam, "VideoRateControl", 1);         // 0:CBR, 1: VBR, 2: CAPPED_VBR
	set_param(pParam, "VBRMin", 5000000);   // in bps
	set_param(pParam, "VBRMax", 7000000);   // in bps
	set_param(pParam, "VideoCodingMode", 0); // 0 - Frame, 1 - field, 2 - MBAFF, 3 - PAFF, 4 - INVALID(FOLLOW_INPUT)
	set_param(pParam, "VideoProfile", 4);   // H264: 0 - Constrained baseline, 3 - Main, 4 - High
	set_param(pParam, "VideoLevel", 400);       // 100-LEVEL_1, 105-LEVEL_1B, 110-LEVEL_1.1, 120-LEVEL_1.2, 130-LEVEL_1.3, 200-LEVEL_2, 210-LEVEL_2.1, 220-LEVEL_2.2, 300-LEVEL_3, 310-LEVEL_3.1, 320-LEVEL_3.2, 400-LEVEL_4, 410-LEVEL_4.1, 420-LEVEL_4.2, 500-LEVEL_5, 510-LEVEL_5.1
	set_param(pParam, "VideoTSBitrate", 9000000);  // in bps
	set_param(pParam, "VideoLatency", 1);         // 0 - low latency, 1 - high latency
	set_param(pParam, "NumBFrames", 3);
	set_param(pParam, "InsertIFrame", 0);
	set_param(pParam, "CabacCoding", 1);
	set_param(pParam, "DeblockFilter", 0);

// add audio params

	set_param(pParam, "AudioStreamID", 192);         
	set_param(pParam, "AudioOutputPID", defaultAudioOutputPID);       // Must be greater than 0x0F, Suggest to be greater than 0x1F.
//	set_param(pParam, "AudioCapSource", 0);         // 0: LR, 1:SPDIF, 2:SDI, 3: HDMI
	set_param(pParam, "AudioCapSampleRate", 3);         // in kHz. 0: NONE 1:32, 2: 44.1, 3:48, 4:96, 5:192, 6:16
	set_param(pParam, "AudioCapMode", 1);         // 0: drop, 1:Frame, 2: frame-frame, 3: AAC(Sub_frame), 5: Downmix               
	set_param(pParam, "AudioCapSPDIFInput", 0);         // 0:COAX, 1: 19977, 2: AES_EBU, 3: opTICAL
	set_param(pParam, "AudioCodecOutputFormat", 3);         // 1-MPEG, 2-AC3, 3-AAC, 6-MP3, 8-PCM, 9-PASSTHROUGH
	set_param(pParam, "AudioOutputMode", 1);         // Stereo - 1, Mono - 2, refer to header file for more options
	set_param(pParam, "AudioOutputSamplingRate", 3);         // 1 - 32K, 2 - 44.1K, 3 - 48K
	set_param(pParam, "AudioOutputBitrate", 9); // 7         // kbps: 0-32,1-48,2-56,3-64,4-80,5-96,6-112,7-128,8-160,9-192,10-224, 11-256, 
}

void CHapi::set_encode_480i60_h264(HAPI_SET_PARAM *pParam)
{
	DbgLogInfo(("call set_encode_480i60_h264()\n"));

	set_param(pParam, "ParamType" , 0);  // 0-encode, 1-decode, 2-transcode

	set_param(pParam, "OutputPCRPID", defaultPCROutputPID);        // 0 - follow input, invalid for encoder. Must be greater than 0x0F, Suggest to be greater than 0x1F.

	set_param(pParam, "VideoStreamID", 2);         
	set_param(pParam, "VideoOutputPID", defaultVideoOutputPID);        // Must be greater than 0x0F, Suggest to be greater than 0x1F. 
	set_param(pParam, "VideoCapSource", 0);         // 0:COMP, 1:YUV, 2:SDI, 3:HDMI
	set_param(pParam, "VideoCapWidth", 720);  
	set_param(pParam, "VideoCapHeight", 480);      // Frame height always
	set_param(pParam, "VideoCapFormat", 0);         // 0: interlaced, 1:progressive 2: psf
	set_param(pParam, "VideoCapFrameRate", 4);         // 1 - 23.98, 2 - 24, 3 - 25, 4 - 29.97, 5 - 30, 6 - 50, 7 - 59.94, 8 - 60, 9 - 15, 10 - 10, 11 - 6, 12 - 5, 13 - 2, 14 - 1
	set_param(pParam, "VideoCodecOutputFormat", 4);         // 1: MPEG2, 4: H.264
	set_param(pParam, "VideoOutputWidth", 720); // 1280 // 720 // 1440 // 1920       // output video width
	set_param(pParam, "VideoOutputHeight", 480); // 720  // 480 // 1080 // 1080       // output video frame height always
	set_param(pParam, "VideoOutputMode", 0); // 1 // 0         // 0: interlaced, 1:progressive 2: psf?
	set_param(pParam, "VideoOutputFrameRate", 4); // 7 // 4         // 1 - 23.98, 2 - 24, 3 - 25, 4 - 29.97, 5 - 30, 6 - 50, 7 - 59.94, 8 - 60, 9 - 15, 10 - 10, 11 - 6, 12 - 5, 13 - 2, 14 - 1
	set_param(pParam, "VideoOutputBitrate", 6000000);   // Output video bitrate in bps
	set_param(pParam, "VideoRateControl", 1);         // 0:CBR, 1: VBR, 2: CAPPED_VBR
	set_param(pParam, "VBRMin", 5000000);   // in bps
	set_param(pParam, "VBRMax", 7000000);   // in bps
	set_param(pParam, "VideoCodingMode", 1); // 4 // 1 // 0         // 0 - Frame, 1 - field, 2 - MBAFF, 3 - PAFF, 4 - INVALID(FOLLOW_INPUT)
	set_param(pParam, "VideoProfile", 4);         // H264: 0 - Constrained baseline, 3 - Main, 4 - High
	set_param(pParam, "VideoLevel", 400);       // 100-LEVEL_1, 105-LEVEL_1B, 110-LEVEL_1.1, 120-LEVEL_1.2, 130-LEVEL_1.3, 200-LEVEL_2, 210-LEVEL_2.1, 220-LEVEL_2.2, 300-LEVEL_3, 310-LEVEL_3.1, 320-LEVEL_3.2, 400-LEVEL_4, 410-LEVEL_4.1, 420-LEVEL_4.2, 500-LEVEL_5, 510-LEVEL_5.1
	set_param(pParam, "VideoTSBitrate", 9000000);  // in bps
	set_param(pParam, "VideoLatency", 1);         // 0 - low latency, 1 - high latency
	set_param(pParam, "NumBFrames", 3);
	set_param(pParam, "InsertIFrame", 0);
	set_param(pParam, "CabacCoding", 1);
	set_param(pParam, "DeblockFilter", 0);

// add audio params

	set_param(pParam, "AudioStreamID", 192);         
	set_param(pParam, "AudioOutputPID", defaultAudioOutputPID);       // Must be greater than 0x0F, Suggest to be greater than 0x1F.
//	set_param(pParam, "AudioCapSource", 0);         // 0: LR, 1:SPDIF, 2:SDI, 3: HDMI
	set_param(pParam, "AudioCapSampleRate", 3);         // in kHz. 0: NONE 1:32, 2: 44.1,3:48,4:96, 5:192, 6:16
	set_param(pParam, "AudioCapMode", 1);         // 0: drop, 1:Frame, 2: frame-frame, 3: AAC(Sub_frame), 5: Downmix               
	set_param(pParam, "AudioCapSPDIFInput", 0);         // 0:COAX, 1: 19977, 2: AES_EBU, 3: opTICAL
	set_param(pParam, "AudioCodecOutputFormat", 3);         // 1-MPEG, 2-AC3, 3-AAC, 6-MP3, 8-PCM, 9-PASSTHROUGH
	set_param(pParam, "AudioOutputMode", 1);         // Stereo - 1, Mono - 2, refer to header file for more options
	set_param(pParam, "AudioOutputSamplingRate", 3);         // 1 - 32K, 2 - 44.1K, 3 - 48K
	set_param(pParam, "AudioOutputBitrate", 9); // 7         // kbps: 0-32,1-48,2-56,3-64,4-80,5-96,6-112,7-128,8-160,9-192,10-224, 11-256, 
}


#if DBG
HANDLE CHapi::prv_open_file(char *filename, int mode, Uint32* size)
{
    NTSTATUS status = STATUS_SUCCESS;
    IO_STATUS_BLOCK status_block;

	HANDLE fileHandle = NULL;
    UNICODE_STRING u_file_name;

	if((filename==NULL) || (size==NULL)){
        DbgLogError(("prv_open_file: filename(%p)==NULL || size(%p)==NULL\n", filename, size));
        return NULL;
	}
	*size = 0;

    ANSI_STRING  a_file_name;
    
    RtlInitAnsiString(&a_file_name, filename);
    status = RtlAnsiStringToUnicodeString(&u_file_name, &a_file_name, TRUE);

    LARGE_INTEGER FilePos; 
    FILE_STANDARD_INFORMATION FileInformation; 


	OBJECT_ATTRIBUTES attributes;
	InitializeObjectAttributes(
        &attributes, 
        &u_file_name, 
        OBJ_CASE_INSENSITIVE | OBJ_KERNEL_HANDLE, 
        NULL, 
        NULL);

   	if(mode == 0){//Reading
		status = ZwCreateFile(
			&fileHandle,                                                 //FileHandle
			FILE_GENERIC_READ | SYNCHRONIZE,                        //DesiredAccess
			&attributes,                                            //ObjectAttributes
			&status_block,                                          //IoStatusBlock
			NULL,                                                   //AllocationSize
			0,                                                      //FileAttributes
			FILE_SHARE_READ,                                        //ShareAccess
			FILE_OPEN,                                              //CreateDisposition
			FILE_NON_DIRECTORY_FILE | FILE_SYNCHRONOUS_IO_NONALERT, //CreateOptions
			NULL,                                                   //EaBuffer
			0);                                                   //EaLength
	} else {
		status = ZwCreateFile(
			&fileHandle,                                                 //FileHandle
			/*FILE_APPEND_DATA |*/ FILE_WRITE_DATA,                        //DesiredAccess
			&attributes,                                            //ObjectAttributes
			&status_block,                                          //IoStatusBlock
			NULL,                                                   //AllocationSize
			FILE_ATTRIBUTE_NORMAL,                                                      //FileAttributes
			0,                                        //ShareAccess
			FILE_OPEN_IF,                                              //CreateDisposition
			FILE_SYNCHRONOUS_IO_NONALERT, //CreateOptions
			NULL,                                                   //EaBuffer
			0);                                                   //EaLength
	}
    RtlFreeUnicodeString( &u_file_name );

	if (!NT_SUCCESS(status)) { 
		DbgLogTrace(("prv_open_file(%s,...) returns 0x%x\n", filename, status));
		return NULL;
	} 
   	if(mode == 0){//Reading, get filesize
		ULONG  FileSize;
		status = ZwQueryInformationFile( 
				   fileHandle, 
				   &status_block, 
				   &FileInformation, 
				   sizeof (FileInformation), 
				   FileStandardInformation 
				   ); 

		if (!NT_SUCCESS(status)) 
		{ 
			DbgLogError(("prv_open_file: ZwQueryInformationFile failed with status 0x%x\n", status));
			return NULL;
		} 

		FileSize = FileInformation.EndOfFile.LowPart; 
		*size = FileSize;
		DbgLogInfo(("prv_open_file: file is %d bytes\n", FileSize));
	}
	DbgLogInfo(("prv_open_file: file '%s' opened as %p\n", filename, fileHandle));
	return fileHandle;
}

ULONG_PTR CHapi::prv_read_file(HANDLE fileHandle, BYTE *buf, Uint32 size)
{
    NTSTATUS status = STATUS_SUCCESS;
    IO_STATUS_BLOCK status_block;

	DbgLogInfo(("prv_read_file: reading %d bytes from %p\n", size, fileHandle));

    status = ZwReadFile(
            fileHandle,         //file handle
            NULL,               //event
            NULL,               //apc routine
            NULL,               //apc context
            &status_block,      // io status block
            buf,                //buffer
            size,	           //Size of buffer
            NULL,               //Offset in the file to read
            NULL);              //key
        
    if (!NT_SUCCESS(status)) 
    { 
        DbgLogError(("prv_read_file: failed with status 0x%x\n", status));
        return 0;
    } 
//	DbgLogInfo(("prv_read_file: read %d bytes OK\n", status_block.Information));
	return status_block.Information;
}

ULONG_PTR CHapi::prv_write_file(HANDLE fileHandle, BYTE *buf, Uint32 size)
{
    NTSTATUS status = STATUS_SUCCESS;
    IO_STATUS_BLOCK status_block;

	DbgLogInfo(("prv_write_file: writing %d bytes to %p\n", size, fileHandle));

    status = ZwWriteFile(
            fileHandle,         //file handle
            NULL,               //event
            NULL,               //apc routine
            NULL,               //apc context
            &status_block,      // io status block
            buf,                //buffer
            size,	           //Size of buffer
            NULL,               //Offset in the file to read
            NULL);              //key
        
    if (!NT_SUCCESS(status)) 
    { 
        DbgLogError(("prv_write_file: failed with status 0x%x\n", status));
        return 0;
    } 
//	DbgLogInfo(("prv_write_file: wrote %d bytes OK\n",  status_block.Information));
	return  status_block.Information;
}

void CHapi::prv_close_file(HANDLE &fileHandle)
{
	DbgLogInfo(("prv_close_file(%p)\n", fileHandle));
	if(fileHandle){   
		ZwClose(fileHandle);
		fileHandle = NULL;
	}
}

Uint64 CHapi::prv_get_mod_time(HANDLE fileHandle)
{
    NTSTATUS status = STATUS_SUCCESS;
    IO_STATUS_BLOCK status_block;
    FILE_BASIC_INFORMATION FileInformation; 

	status = ZwQueryInformationFile( 
			   fileHandle, 
			   &status_block, 
			   &FileInformation, 
			   sizeof (FileInformation), 
			   FileBasicInformation 
			   ); 

    if (!NT_SUCCESS(status)) 
    { 
        DbgLogError(("prv_read_file: failed with status 0x%x\n", status));
        return 0;
    } 
	DbgLogInfo(("prv_get_mod_time: LastWriteTime=%llu\n", FileInformation.LastWriteTime.QuadPart));//FileInformation.ChangeTime
	return (Uint64)FileInformation.LastWriteTime.QuadPart;
}

void CHapi::prv_init_transcode_files()
{
	Uint32 fileSize = 0;

	inFileHandle = prv_open_file("\\systemroot\\system32\\drivers\\transcode_in.ts", 0, &fileSize);
	if(inFileHandle){
		DbgLogInfo(("prv_init_transcode_files() input file is %u bytes long\n", fileSize));
		if(fileSize){
			outFileHandle = prv_open_file("\\systemroot\\system32\\drivers\\transcode_out.ts", 1, &fileSize);
			if(outFileHandle)
				return;
		}
		prv_close_file(inFileHandle);
	}
	DbgLogInfo(("prv_init_transcode_files() failed\n"));
}

void CHapi::prv_init_encode_outfile()
{
	Uint32 fileSize = 0;

	outFileHandle = prv_open_file("\\systemroot\\system32\\drivers\\encode_h264.ts", 1, &fileSize);
	if(outFileHandle)
		return;

	DbgLogInfo(("prv_init_encode_outfile() failed\n"));
}
#endif//DBG

#define TMDL_HDMITX_VFMT_ONLY
//#include "..\TDA19988_HdmiTx\comps\tmdlHdmiTx\inc\tmdlHdmiTx_Types.h" //for TMDL_HDMITX_VFMT_*
#include "Hapi_extra.h" // just yet

void CHapi::setHDMIformat(DWORD hdmi_fmt)
{
	lock();
	if(_hdmi_fmt != hdmi_fmt){
		if(!_API_ok){
			DbgLogWarn(("CHapi::setHDMIformat(%d) _API_ok==false!!\n", hdmi_fmt));
			unlock();
			return;
		}
#if 0//FGR - only resume via HapiResume()
		if(_hdmi_fmt == TMDL_HDMITX_VFMT_NULL){
			DbgLogInfo(("CHapi::setHDMIformat(%d) - Video SYNC restored\n", hdmi_fmt));
			//If we have already seen this format then start encoder, otherwise wait for
			// new encoder params to get sent ...
			if(_isStarted && _isPaused && (hdmi_fmt == _last_good_hdmi_fmt)){
				hapiStart();
			}
		} else
#endif
		if(hdmi_fmt == TMDL_HDMITX_VFMT_NULL){
			DbgLogInfo(("CHapi::setHDMIformat(%d) - Video SYNC lost\n", hdmi_fmt));
			if(!_isPaused){
				hapiStop();
			}
		}
		_hdmi_fmt = hdmi_fmt;
	}
	unlock();
}

Uint32 CHapi::HapiResume()
{
	Uint32 ret = HAPI_SUCCESS;
	lock();
	DbgLogInfo(("CHapi::HapiResume() fmt=%d\n", _hdmi_fmt));
	if(_hdmi_fmt){
		if(!_API_ok){
			DbgLogWarn(("CHapi::HapiResume() _hdmi_fmt=%d _API_ok==false!!\n", _hdmi_fmt));
			unlock();
			return 0;
		}
		DbgLogInfo((" Video SYNC restored\n"));
		//If we have set params for the current format then start encoder, otherwise wait for
		// new encoder params to get sent ...
		if(_isStarted && _isPaused && (_hdmi_fmt == _last_good_hdmi_fmt)){
			ret = hapiStart();
			
			if(!_API_ok || hapiErr != HAPI_SUCCESS){
				hapiResetHW();
			}
		}
	}
	unlock();
	return ret == HAPI_SUCCESS?1:0;
}

Uint32 CHapi::HapiStart()
{
	lock();
	
	_isStarted = true;
	_isPaused = false;
	_last_PCR = 0;
	_last_payload_time = 0;
	
	hapiStart();

	if(!_API_ok || hapiErr != HAPI_SUCCESS){
		_isStarted = false;
	}
	unlock();
	return _isStarted?1:0;
}

Uint32 CHapi::hapiStart()
{
	lock();
	DbgLogInfo(("hapiStart() gHapi=%p _last_PCR=0x%llx\n", gHapi, _last_PCR));

	if(!_API_ok){
		DbgLogWarn(("CHapi::hapiStart() _API_ok==false!!\n"));
		unlock();
		return 0;
	}
	if(_hdmi_fmt != TMDL_HDMITX_VFMT_NULL){
		_bling_options = p_mchip->getBling_Options();
		_bling_count = 0;
		_errCountdown = 0;

		_isPaused = false;
		if(gHapi){
#if DBG //test ParamGet to get defaults for APIs in Hapi 1.5.4
			HAPI_SET_PARAM	_GetParam;
			memset(&_GetParam, 0, sizeof(_GetParam));
			_GetParam.index = 0;
			HapiParamGet(&_GetParam);
#endif
			if(_last_PCR == 0){
				hapiErr = HAPI_PCRSet(gHapi, _last_PCR);
			}

			DbgLogTrace(("DataTransfer::static_BufferComplete(): start\n"));
			if(_p_data_transfer){
				//signal DISCONTINUITY on MPEG output pin
//#ifdef OLD_DRIVER
				DataTransfer::static_BufferComplete(_p_data_transfer, NULL, 0);
//#endif
			}

			_first_payload_delta = 0;
			_last_payload_delta = 0;

			hapiErr = HAPI_Start(gHapi, 0);
			_last_payload_time = 0;
			if(hapiErr == HAPI_SUCCESS){
				_last_payload_time = wrapGetTicks_ms();
				_first_payload_time = _last_payload_time;
			}
		} else {
			hapiErr = HAPI_FAIL;
		}
		DbgLogInfo((" HAPI_Start hapiErr=0x%x\n", hapiErr));
	} else {
		_isPaused = true;
		DbgLogInfo(("  HAPI_Start encoder is paused...\n"));
	}
	if(hapiErr != HAPI_SUCCESS){
		_API_ok = false;
	}

#if 0//BLING//BUGBUG - this won't work here; can't acquire Host Bus!!
	if(!_isPaused && (_bling_options&0x15)){
		p_mchip->lockBus();
		p_mchip->MCHIP_Host_Select();
		if(_bling_options & 0x01) p_mchip->MCHIP_LED_Set(55, 1);//Green Bling on
		if(_bling_options & 0x04) p_mchip->MCHIP_LED_Set(48, 1);//LED2 Power on
		if(_bling_options & 0x10) p_mchip->MCHIP_LED_Set(53, 1);//Blue Bling on
		p_mchip->unlockBus();
	}
#endif

	unlock();
	return hapiErr;
}

Uint32 CHapi::HapiStop()
{
	lock();	
	
	hapiStop();
	_isStarted = false;
	_last_PCR = 0;
	
#if 0//FGR - BUGBUG - it's apparently always disabled on stop
	if(_API_ok && _logo_x_pos != -1){
		hapiErr = HAPI_LogoOnOff(gHapi, 0, 0, 0); //disable logo index=0
	}
#endif
	_logo_x_pos = -1;
	_logo_y_pos = -1;

	unlock();
	return hapiErr == HAPI_SUCCESS?1:0;
}
	
bool CHapi::HapiRunning()
{
	lock();
	bool isRunning = _isStarted && !_isPaused;
	
//	DbgLogTrace(("HapiRunning() gHapi=%p isRunning=%x\n", gHapi, isRunning));
	if(!_API_ok){
		unlock();
		return false;
	}
	unlock();
	return isRunning;
}

Uint32 CHapi::hapiStop()
{
	lock();
	bool isRunning = _isStarted && !_isPaused;
	
	DbgLogInfo(("hapiStop() gHapi=%p isRunning=%x\n", gHapi, isRunning));
	if(!_API_ok){
		DbgLogWarn(("CHapi::hapiStop() _API_ok==false!!\n"));
		unlock();
		return 0;
	}

	if(isRunning){
		if(gHapi && !p_mchip->hadUsbError("CHapi::hapiStop")){
			_isPaused = true;

			DWORD stalled_time = wrapGetTicks_ms() - _last_payload_time;
			if(stalled_time > 1500){
				DbgLogWarn(("CHapi::hapiStop() stalled_time=%d, skipping HAPI_Stop()\n", stalled_time));
				hapiErr = HAPI_FAIL;
			} else {
#if 1//BLING
				if(_bling_options & 0x1717){
					p_mchip->lockBus();
					p_mchip->MCHIP_Host_Select();
					if(_bling_options & 0x0101){
						if(!p_mchip->MCHIP_LED_Set(55, 0)){//Green Bling off
							p_mchip->MCHIP_LED_Set(55, 0);//BUGBUG - why do we need this retry!!
						}
						_LED_state &= ~0x01;
					}
					if(_bling_options & 0x1010){
						if(!p_mchip->MCHIP_LED_Set(53, 0)){//Blue Bling off
							p_mchip->MCHIP_LED_Set(53, 0);//BUGBUG - why do we need this retry!!
						}
						_LED_state &= ~0x10;
					}
					if(_bling_options & 0x0202){
						if(!p_mchip->MCHIP_LED_Set(47, 0)){//LED1 Error off
							p_mchip->MCHIP_LED_Set(47, 0);//BUGBUG - why do we need this retry!!
						}
						_LED_state &= ~0x02;
					}
					if(_bling_options & 0x0404){
						if(!p_mchip->MCHIP_LED_Set(48, 1)){//LED2 Power on
							p_mchip->MCHIP_LED_Set(48, 1);//BUGBUG - why do we need this retry!!
						}
						_LED_state &= ~0x04;
					}
					p_mchip->unlockBus();
					_errCountdown = 0;
				}
#endif
				hapiErr = HAPI_Stop(gHapi, 0);
			}
		} else {
			hapiErr = HAPI_FAIL;
		}
		if(hapiErr != HAPI_SUCCESS){
			DbgLogError(("hapiStop() encoder returned hapiErr=0x%x\n", hapiErr));
			
			hapiResetHW();

			if(hapiErr != HAPI_SUCCESS || !_API_ok){
				_API_ok = false;
			} else {
				DbgLogRelease(("hapiStop() Recovery completed OK\n"));
			}
		} else {
#if 1//FGR - this takes extra time, but we are using it to detect a possible error case
			HAPI_QUERY_STRUCT status;
			if(gHapi)
				HapiStatusQuery(&status);
			
			if(hapiErr == HAPI_SUCCESS){
				//FGR - we have seen a case where the Magnum will only encode from 720p sources;
				// other formats result in "flow stalled", but switching back to 720p works ok
				//This code will force a complete HW reset if no input frames are seen
				// and the encoder had been running for at least 3 seconds
				if((status.inFrameCount == 0) && (status.outFrameCount > (Uint32)(status.frameRate*3)) ){
					DbgLogError(("hapiStop() flow stalled(out=%u, rate=%u)\n", status.outFrameCount, status.frameRate));
					
					hapiResetHW();

					if(hapiErr != HAPI_SUCCESS || !_API_ok){
						_API_ok = false;
					} else {
						DbgLogRelease(("hapiStop() flow stall Recovery OK\n"));
					}
				}
				_last_PCR = status.pcr; //remember last PCR for possible resume/restart
			}
#else
			_last_PCR = 1; //non-zero value
#endif
		}
	}
	unlock();
	return hapiErr;
}

static unsigned getFrameRateId(float freq)
{
	switch((unsigned)(freq * 10.0)) {
		case 239:
			return 1;
		case 240:
			return 2;
		case 249: // FGR - added, be tolerant of minor timing variations
		case 250:
			return 3;
		case 299:
			return 4;
		case 300:
			return 5;
		case 499: // FGR - added, be tolerant of minor timing variations
		case 500:
			return 6;
		case 599:
			return 7;
		case 600:
			return 8;
		case 149: // FGR - added, be tolerant of minor timing variations
		case 150:
			return 9;
		case 100:
			return 10;
	}
	DbgLogWarn(("CHapi::getFrameRateId(%f) UNKNOWN Rate!!", freq));//FGR - added
	return 0;
}

Uint32 CHapi::get_custom_defaults(HAPI_SET_PARAM *pParam, unsigned width, unsigned height, bool interlaced, float vFreq)
{
	if(pParam == NULL) {
		DbgLogWarn(("CHapi::get_custom_defaults(NULL)!!"));
		return 0;
	}
	memset(pParam, 0, sizeof(*pParam));

	unsigned iFreqId = getFrameRateId(vFreq / (interlaced ? 2.0 : 1.0));
	unsigned oFreqId = iFreqId;
//	if((height >= 768) && (vFreq >= 50.0)) {
	if((height >= 768) && (vFreq >= 31.0)) {//FGR - fix frame rate test
		oFreqId = getFrameRateId(vFreq / 2.0);
	}

	if((iFreqId == 0) || (oFreqId == 0)) {
		DbgLogWarn(("CHapi::get_custom_defaults(): bad params; ifreq=%d ofreq=%d", iFreqId, oFreqId));
		return 0;
	}

	if(interlaced) {
		set_encode_1080i60_h264(pParam);
	} else {
		set_encode_1080p60_h264(pParam);
	}

	set_param(pParam, "VideoCapWidth", width);
	set_param(pParam, "VideoCapHeight", height);
	set_param(pParam, "VideoCapFrameRate", iFreqId); // 1 - 23.98, 2 - 24, 3 - 25, 4 - 29.97, 5 - 30, 6 - 50, 7 - 59.94, 8 - 60, 9 - 15, 10 - 10, 11 - 6, 12 - 5, 13 - 2, 14 - 1
	set_param(pParam, "VideoOutputWidth", width); // 1280 // 720 // 1440 // 1920       // output video width
	set_param(pParam, "VideoOutputHeight", height); // 720  // 480 // 1080 // 1080       // output video frame height always
	set_param(pParam, "VideoOutputFrameRate", oFreqId); // 1 - 23.98, 2 - 24, 3 - 25, 4 - 29.97, 5 - 30, 6 - 50, 7 - 59.94, 8 - 60, 9 - 15, 10 - 10, 11 - 6, 12 - 5, 13 - 2, 14 - 1
	set_param(pParam, "VideoRateControl", ((height < 768) ? 1 : 0)); // 0:CBR, 1: VBR, 2: CAPPED_VBR

	get_audenc_defaults(pParam); //FGR - Colossus-like Audio sampling rates

	return 1;
}

Uint32 CHapi::get_std_defaults(HAPI_SET_PARAM *pParam)
{
	if(pParam == NULL){
		DbgLogInfo(("CHapi::get_std_defaults(NULL)!!\n"));
		return 0;
	}
	DWORD hdmi_fmt = _hdmi_fmt;
	DbgLogInfo(("CHapi::get_std_defaults(%p), hdmi_fmt=%d\n", pParam, hdmi_fmt));
	memset(pParam, 0, sizeof(*pParam));
	
#if DBG
	DWORD dwDefaultEncodeParams = hdmi_fmt;
	hcwGetRegistryDWORD("DefaultEncodeParams", &dwDefaultEncodeParams);
	hdmi_fmt = dwDefaultEncodeParams;
#endif

	switch(hdmi_fmt){
	case 640://hack for easier testing with "DefaultEncodeParams"
		hdmi_fmt = TMDL_HDMITX_VFMT_01_640x480p_60Hz;
	case TMDL_HDMITX_VFMT_01_640x480p_60Hz:
		set_encode_480p60_h264(pParam);
		set_param(pParam, "VideoCapWidth", 640);
		set_param(pParam, "VideoOutputWidth", 640);
		break;

	case 5761://hack for easier testing with "DefaultEncodeParams"
		hdmi_fmt = TMDL_HDMITX_VFMT_21_720x576i_50Hz;
	case TMDL_HDMITX_VFMT_21_720x576i_50Hz:
	case TMDL_HDMITX_VFMT_22_720x576i_50Hz:
	case TMDL_HDMITX_VFMT_25_720x576i_50Hz:
	case TMDL_HDMITX_VFMT_26_720x576i_50Hz:
		set_encode_480i60_h264(pParam);
		set_param(pParam, "VideoCapHeight", 576);
		set_param(pParam, "VideoOutputHeight", 576);
		set_param(pParam, "VideoCapFrameRate", 3); // 1 - 23.98, 2 - 24, 3 - 25, 4 - 29.97, 5 - 30, 6 - 50, 7 - 59.94, 8 - 60, 9 - 15, 10 - 10, 11 - 6, 12 - 5, 13 - 2, 14 - 1
		set_param(pParam, "VideoOutputFrameRate", 3);
		break;

	case 4801://hack for easier testing with "DefaultEncodeParams"
		hdmi_fmt = TMDL_HDMITX_VFMT_06_720x480i_60Hz;
	case TMDL_HDMITX_VFMT_06_720x480i_60Hz:
	case TMDL_HDMITX_VFMT_07_720x480i_60Hz:
	case TMDL_HDMITX_VFMT_10_720x480i_60Hz:
	case TMDL_HDMITX_VFMT_11_720x480i_60Hz:
		set_encode_480i60_h264(pParam);
		break;

	case 576://hack for easier testing with "DefaultEncodeParams"
		hdmi_fmt = TMDL_HDMITX_VFMT_18_720x576p_50Hz;
	case TMDL_HDMITX_VFMT_17_720x576p_50Hz:
	case TMDL_HDMITX_VFMT_18_720x576p_50Hz:
		set_encode_480p60_h264(pParam);
		set_param(pParam, "VideoCapHeight", 576);
		set_param(pParam, "VideoOutputHeight", 576);
		set_param(pParam, "VideoCapFrameRate", 6); // 1 - 23.98, 2 - 24, 3 - 25, 4 - 29.97, 5 - 30, 6 - 50, 7 - 59.94, 8 - 60, 9 - 15, 10 - 10, 11 - 6, 12 - 5, 13 - 2, 14 - 1
		set_param(pParam, "VideoOutputFrameRate", 6);
		break;
	
	case 480://hack for easier testing with "DefaultEncodeParams"
		hdmi_fmt = TMDL_HDMITX_VFMT_03_720x480p_60Hz;
	case TMDL_HDMITX_VFMT_02_720x480p_60Hz:
	case TMDL_HDMITX_VFMT_03_720x480p_60Hz:
		set_encode_480p60_h264(pParam);
		break;

	case 72024://hack for easier testing with "DefaultEncodeParams"
		hdmi_fmt = TMDL_HDMITX_VFMT_60_1280x720p_24Hz;
	case TMDL_HDMITX_VFMT_60_1280x720p_24Hz:
		set_encode_720p60_h264(pParam);
		set_param(pParam, "VideoCapFrameRate", 2); // 1 - 23.98, 2 - 24, 3 - 25, 4 - 29.97, 5 - 30, 6 - 50, 7 - 59.94, 8 - 60, 9 - 15, 10 - 10, 11 - 6, 12 - 5, 13 - 2, 14 - 1
		set_param(pParam, "VideoOutputFrameRate", 2);
		break;

	case 72025://hack for easier testing with "DefaultEncodeParams"
		hdmi_fmt = TMDL_HDMITX_VFMT_61_1280x720p_25Hz;
	case TMDL_HDMITX_VFMT_61_1280x720p_25Hz:
		set_encode_720p60_h264(pParam);
		set_param(pParam, "VideoCapFrameRate", 3); // 1 - 23.98, 2 - 24, 3 - 25, 4 - 29.97, 5 - 30, 6 - 50, 7 - 59.94, 8 - 60, 9 - 15, 10 - 10, 11 - 6, 12 - 5, 13 - 2, 14 - 1
		set_param(pParam, "VideoOutputFrameRate", 3);
		break;

	case 72030://hack for easier testing with "DefaultEncodeParams"
		hdmi_fmt = TMDL_HDMITX_VFMT_62_1280x720p_30Hz;
	case TMDL_HDMITX_VFMT_62_1280x720p_30Hz:
		set_encode_720p60_h264(pParam);
		set_param(pParam, "VideoCapFrameRate", 4); // 1 - 23.98, 2 - 24, 3 - 25, 4 - 29.97, 5 - 30, 6 - 50, 7 - 59.94, 8 - 60, 9 - 15, 10 - 10, 11 - 6, 12 - 5, 13 - 2, 14 - 1
		set_param(pParam, "VideoOutputFrameRate", 4);
		break;

	case 72050://hack for easier testing with "DefaultEncodeParams"
		hdmi_fmt = TMDL_HDMITX_VFMT_19_1280x720p_50Hz;
	case TMDL_HDMITX_VFMT_19_1280x720p_50Hz:
		set_encode_720p60_h264(pParam);
		set_param(pParam, "VideoCapFrameRate", 6); // 1 - 23.98, 2 - 24, 3 - 25, 4 - 29.97, 5 - 30, 6 - 50, 7 - 59.94, 8 - 60, 9 - 15, 10 - 10, 11 - 6, 12 - 5, 13 - 2, 14 - 1
		set_param(pParam, "VideoOutputFrameRate", 6);
		break;

	case 720://hack for easier testing with "DefaultEncodeParams"
		hdmi_fmt = TMDL_HDMITX_VFMT_04_1280x720p_60Hz;
	case TMDL_HDMITX_VFMT_04_1280x720p_60Hz:
		set_encode_720p60_h264(pParam);
		break;

	case 1080150://hack for easier testing with "DefaultEncodeParams"
		hdmi_fmt = TMDL_HDMITX_VFMT_20_1920x1080i_50Hz;
	case TMDL_HDMITX_VFMT_20_1920x1080i_50Hz:
		set_encode_1080i60_h264(pParam);
		set_param(pParam, "VideoCapFrameRate", 3); // 1 - 23.98, 2 - 24, 3 - 25, 4 - 29.97, 5 - 30, 6 - 50, 7 - 59.94, 8 - 60, 9 - 15, 10 - 10, 11 - 6, 12 - 5, 13 - 2, 14 - 1
		set_param(pParam, "VideoOutputFrameRate", 3);
		break;

	case 10801://hack for easier testing with "DefaultEncodeParams"
	case TMDL_HDMITX_VFMT_05_1920x1080i_60Hz:
		set_encode_1080i60_h264(pParam);
		break;

	case 108024://hack for easier testing with "DefaultEncodeParams"
		hdmi_fmt = TMDL_HDMITX_VFMT_32_1920x1080p_24Hz;
	case TMDL_HDMITX_VFMT_32_1920x1080p_24Hz:
		set_encode_1080p60_h264(pParam);
		set_param(pParam, "VideoCapFrameRate", 2); // 1 - 23.98, 2 - 24, 3 - 25, 4 - 29.97, 5 - 30, 6 - 50, 7 - 59.94, 8 - 60, 9 - 15, 10 - 10, 11 - 6, 12 - 5, 13 - 2, 14 - 1
		set_param(pParam, "VideoOutputFrameRate", 2);
		break;
		
	case 108025://hack for easier testing with "DefaultEncodeParams"
		hdmi_fmt = TMDL_HDMITX_VFMT_33_1920x1080p_25Hz;
	case TMDL_HDMITX_VFMT_33_1920x1080p_25Hz:
		set_encode_1080p60_h264(pParam);
		set_param(pParam, "VideoCapFrameRate", 3); // 1 - 23.98, 2 - 24, 3 - 25, 4 - 29.97, 5 - 30, 6 - 50, 7 - 59.94, 8 - 60, 9 - 15, 10 - 10, 11 - 6, 12 - 5, 13 - 2, 14 - 1
		set_param(pParam, "VideoOutputFrameRate", 3);
		break;
		
	case 108030://hack for easier testing with "DefaultEncodeParams"
		hdmi_fmt = TMDL_HDMITX_VFMT_34_1920x1080p_30Hz;
	case TMDL_HDMITX_VFMT_34_1920x1080p_30Hz:
		set_encode_1080p60_h264(pParam);
		set_param(pParam, "VideoCapFrameRate", 4); // 1 - 23.98, 2 - 24, 3 - 25, 4 - 29.97, 5 - 30, 6 - 50, 7 - 59.94, 8 - 60, 9 - 15, 10 - 10, 11 - 6, 12 - 5, 13 - 2, 14 - 1
		set_param(pParam, "VideoOutputFrameRate", 4);
		break;

	case 108050://hack for easier testing with "DefaultEncodeParams"
		hdmi_fmt = TMDL_HDMITX_VFMT_31_1920x1080p_50Hz;
	case TMDL_HDMITX_VFMT_31_1920x1080p_50Hz:
		set_encode_1080p60_h264(pParam);
		set_param(pParam, "VideoCapFrameRate", 6); // 1 - 23.98, 2 - 24, 3 - 25, 4 - 29.97, 5 - 30, 6 - 50, 7 - 59.94, 8 - 60, 9 - 15, 10 - 10, 11 - 6, 12 - 5, 13 - 2, 14 - 1
		set_param(pParam, "VideoOutputFrameRate", 3);//25fps
		break;

	case 108060://hack for easier testing with "DefaultEncodeParams"
		hdmi_fmt = TMDL_HDMITX_VFMT_16_1920x1080p_60Hz;
	case TMDL_HDMITX_VFMT_16_1920x1080p_60Hz:
		set_encode_1080p60_h264(pParam);
		break;

	case TMDL_HDMITX_VFMT_PC_1024x768p_60Hz:
		set_encode_720p60_h264(pParam);
		set_param(pParam, "VideoCapWidth", 1024);
		set_param(pParam, "VideoOutputWidth", 1024);
		set_param(pParam, "VideoCapHeight", 768);
		set_param(pParam, "VideoOutputHeight", 768);
		set_param(pParam, "VideoCapFrameRate", 8); //7 - 59.94, 8 - 60
		set_param(pParam, "VideoOutputFrameRate", 5);//4 - 29.97, 5 - 30
		break;

	case TMDL_HDMITX_VFMT_PC_1280x768p_60Hz:
		set_encode_720p60_h264(pParam);
		set_param(pParam, "VideoCapWidth", 1280);
		set_param(pParam, "VideoOutputWidth", 1280);
		set_param(pParam, "VideoCapHeight", 768);
		set_param(pParam, "VideoOutputHeight", 768);
		set_param(pParam, "VideoCapFrameRate", 8); //7 - 59.94, 8 - 60
		set_param(pParam, "VideoOutputFrameRate", 5);//4 - 29.97, 5 - 30
		break;

	case TMDL_HDMITX_VFMT_PC_1280x1024p_60Hz:
		set_encode_720p60_h264(pParam);
		set_param(pParam, "VideoCapWidth", 1280);
		set_param(pParam, "VideoOutputWidth", 1280);
		set_param(pParam, "VideoCapHeight", 1024);
		set_param(pParam, "VideoOutputHeight", 1024);
		set_param(pParam, "VideoCapFrameRate", 8); //7 - 59.94, 8 - 60
		set_param(pParam, "VideoOutputFrameRate", 5);//4 - 29.97, 5 - 30
		break;

	case TMDL_HDMITX_VFMT_PC_1360x768p_60Hz:
		set_encode_720p60_h264(pParam);
		set_param(pParam, "VideoCapWidth", 1360);
		set_param(pParam, "VideoOutputWidth", 1360);
		set_param(pParam, "VideoCapHeight", 768);
		set_param(pParam, "VideoOutputHeight", 768);
		set_param(pParam, "VideoCapFrameRate", 8); //7 - 59.94, 8 - 60
		set_param(pParam, "VideoOutputFrameRate", 5);//4 - 29.97, 5 - 30
		break;

	case TMDL_HDMITX_VFMT_PC_848x480p_60Hz:
		set_encode_720p60_h264(pParam);
		set_param(pParam, "VideoCapWidth", 848);
		set_param(pParam, "VideoOutputWidth", 848);
		set_param(pParam, "VideoCapHeight", 480);
		set_param(pParam, "VideoOutputHeight", 480);
		set_param(pParam, "VideoCapFrameRate", 8); //7 - 59.94, 8 - 60
		set_param(pParam, "VideoOutputFrameRate", 8);//7 - 59.94, 8 - 60
		break;

	case TMDL_HDMITX_VFMT_PC_1440x900p_60Hz:
		set_encode_720p60_h264(pParam);
		set_param(pParam, "VideoCapWidth", 1440);
		set_param(pParam, "VideoOutputWidth", 1440);
		set_param(pParam, "VideoCapHeight", 900);
		set_param(pParam, "VideoOutputHeight", 900);
		set_param(pParam, "VideoCapFrameRate", 8); //7 - 59.94, 8 - 60
		set_param(pParam, "VideoOutputFrameRate", 5);//4 - 29.97, 5 - 30
		break;

#if 0
	case TMDL_HDMITX_VFMT_PC_1680x1050p_60Hz:
		set_encode_720p60_h264(pParam);
		set_param(pParam, "VideoCapWidth", 1680);
		set_param(pParam, "VideoOutputWidth", 1680);
		set_param(pParam, "VideoCapHeight", 1050);
		set_param(pParam, "VideoOutputHeight", 1050);
		set_param(pParam, "VideoCapFrameRate", 8); //7 - 59.94, 8 - 60
		set_param(pParam, "VideoOutputFrameRate", 5);//4 - 29.97, 5 - 30
		break;
#endif//0

	default:
	case TMDL_HDMITX_VFMT_NULL:
		DbgLogWarn(("No available mapping for hdmi_fmt=%d, assuming 720p60\n", hdmi_fmt));
		hdmi_fmt = TMDL_HDMITX_VFMT_NULL;
		set_encode_720p60_h264(pParam);
		break;
	}
	if(hdmi_fmt != TMDL_HDMITX_VFMT_NULL){
		get_scaler_defaults(pParam); //FGR - Colossus-like scaler settings
		get_audenc_defaults(pParam); //FGR - Colossus-like Audio sampling rates
//		get_logo_data(pParam);
	}
	return 1;
}


#if DBG
void CHapi::HapiTest(DWORD hdmi_fmt)
{
	DbgLogInfo(("HapiTest(%d)\n", hdmi_fmt));
	
	DWORD dwRunInitTests = 0xFF;
//	hcwGetRegistryDWORD("RunInitTests", &dwRunInitTests);

	if(dwRunInitTests & 0x4){
		
		BYTE value;
		BYTE i;
#if 0	
		//Disable TDA19977 to avoid bus contention
		DWORD dwTDA19977_pd = 0;
		hcwGetRegistryDWORD("TDA19977_pd", &dwTDA19977_pd);
		if(dwTDA19977_pd & 0x02){
			if(!p_mchip->UsbGetPortState(4, &value)){
				DbgLogError(("UsbGetPortState() FAILED!!\n"));
				return;
			}
			p_mchip->UsbSetPortState(4, value | 0x40); //FGR - BUGBUG - disable TDA19977 for now
			
			DbgLogInfo((" (disabling TDA19977 via PD pin; see TDA19977_pd reg value)\n"));
		}

#endif
		
		
		p_mchip->UsbEEpSetAddr(0x51);//0xA2
#if 1
		BYTE buf[4];
		for(i=0; i<8; i+=4){
			if(!p_mchip->UsbEEpReadBytes(i, 4, buf))
				break;
			DbgLogInfo((" Cypress EEprom[%d]=0x%02x,0x%02x,0x%02x,0x%02x\n", i, buf[0], buf[1], buf[2], buf[3]));
		}
#endif

	}

	if(dwRunInitTests & 0x10){
		BOARD_BUS_TYPE savBoard_bus = gBoard_bus;
		if(dwRunInitTests & 0x20){
			gBoard_bus = plankton;//FGR - force plankton rather than siena for transcode tests
		}
		if(powerUp()){
			
			if(hapiErr == HAPI_SUCCESS){
				wrapSleep_ms(100);//BUGBUG - need this??

                HAPI_SET_PARAM	Param;
                memset(&Param, 0, sizeof(Param));
				Param.index = 0;
                
				if(gBoard_bus != plankton){
					setHDMIformat(hdmi_fmt);
					get_std_defaults(&Param);

				} else {
					set_transcode_a7_1080i_to_h264_1920x544(&Param);
	//				set_transcode_1080i_to_480i_h264(&Param);
					is_param_dirty(&Param);
				}
				
				HapiParamSet(&Param);

#if 1//FGR - BUGBUG HAPI_ParamGet was broken in 1.3; hopefully fixed in 1.4
				HapiParamGet(&Param);
#endif			

            }

			if(hapiErr == HAPI_SUCCESS){
				if((gBoard_bus == plankton)){
					if(dwRunInitTests & 0x20){
						prv_init_transcode_files();
					}
					if(inFileHandle){
						HapiStart();
						
						if(hapiErr == HAPI_SUCCESS){
							int retrys = 240; //240secs max
							hcwGetRegistryDWORD("TranscodeTimeLimit", (LPDWORD)&retrys);
							while(inFileHandle){
								if(p_mchip->hadUsbError("CHapi::HapiTest"))
									break;
								wrapSleep_ms(1000);
								if(retrys-- <= 0)
									break;

								int new_retrys = 0; //FGR - allow ABORT during long transcodecode
								hcwGetRegistryDWORD("TranscodeTimeLimit", (LPDWORD)&new_retrys);
								if(new_retrys < retrys){
									retrys = new_retrys;
								}
								DbgLogInfo((" Transcode Time remaining=%d\n", retrys));
							}
						}
					} else {
						DbgLogInfo((" Skipping HAPI_Start, no file to transcode\n"));
					}
				} else {
					if((dwRunInitTests & 0x20) && (gBoard_bus == siena)){
						prv_init_encode_outfile();
					}
					HapiStart();
					
					if(hapiErr == HAPI_SUCCESS){
						int retrys = 240; //240secs max
						hcwGetRegistryDWORD("EncodeTimeLimit", (LPDWORD)&retrys);
						while(1){
							if(p_mchip->hadUsbError("CHapi::HapiTest"))
								break;
							wrapSleep_ms(1000);
							if(retrys-- <= 0)
								break;
							
							int new_retrys = 0; //FGR - allow ABORT during long encode
							hcwGetRegistryDWORD("EncodeTimeLimit", (LPDWORD)&new_retrys);
							if(new_retrys < retrys){
								retrys = new_retrys;
							}
							DbgLogInfo((" Encode Time remaining=%d\n", retrys));
						}
					}
				}
			}
			powerDownHW();

			prv_close_file(inFileHandle);
			prv_close_file(outFileHandle);


		} else {
			DbgLogError((" powerUp() FAILED!!\n"));
		}
		gBoard_bus = savBoard_bus;
	}
}
#endif//DBG


HapiErrCode CHapi::AVDataRequest (HAPI_AV_DATA_INFO *info, void *context)
{
	CHapi *p_CHapi = (CHapi *)context;
	DbgLogInfo(("AVDataRequest(%p) chan=%d buf=%p size=%u\n", p_CHapi, info->channel, info->buf, info->requestSize));
	memset(info->buf, 0, info->requestSize);

#if DBG
	if(p_CHapi->inFileHandle){
		ULONG_PTR len = p_CHapi->prv_read_file(p_CHapi->inFileHandle, info->buf, info->requestSize);
		if(len > 0/*info->requestSize*/){
			if(len != info->requestSize){
				DbgLogInfo(("AVDataRequest EOF reached size=%u\n", len));
			}
			return HAPI_SUCCESS;
		}
		p_CHapi->prv_close_file(p_CHapi->inFileHandle);
	}
#else
	//BUGBUG - release code needs something here to support Transcode!!
#endif//DBG
	return HAPI_FAIL;
}

HapiErrCode CHapi::ErrorMsgCallback(HAPI_ERROR_MSG_TYPE errorType, void *context, HAPI_ERR_PARAM *param)
{
	CHapi *p_CHapi = (CHapi *)context;
	int hard_error = 0;

	switch(errorType){
	case HAPI_ERR_PROC_ASSERT:	// DXT code asserted. This is an unexpected serious error that should not happen.
								// If it is reported, host should reset DXT and board.
		p_CHapi->_API_ok = false;
		hard_error = 1;

		DbgLogError(("CHapi::ErrorMsgCallback(%p) HAPI_ERR_PROC_ASSERT param=%p Res1=0x%x Res2=0x%x\n",
			p_CHapi, param, param->assertErr.Reserved1, param->assertErr.Reserved2));
		
		param->assertErr.Reserved1 = 0; //do this before we print the possibly unterminated string
		DbgLogError((" text=\"%s\"\n", param->assertErr.text));
		break;
    case HAPI_ERR_FRAME_COUNTER_0:
        DbgLogError(("CHapi::ErrorMsgCallback(%p) HAPI_ERR_FRAME_COUNTER_0 Flow stalled at %us. vIn=%d vRes=%d vEnc=%d\n",
			p_CHapi, param->frCounter0.seconds, param->frCounter0.vInCount, param->frCounter0.vResCount, param->frCounter0.vEncCount));
		if((param->frCounter0.vInCount == 0) && (param->frCounter0.seconds <= 6)){
			hard_error = 1;
		}
		break;
	case HAPI_ERR_AUD_CODEC_MISMATCH: // Selected audio codec does not match actual incoming data format.
		DbgLogError(("CHapi::ErrorMsgCallback(%p) HAPI_ERR_AUD_CODEC_MISMATCH param=%p\n", p_CHapi, param));
		break;
	case HAPI_ERR_AUD_LEVEL_ALARM: // Audio overflow or underflow on a specific channel (warning).
		DbgLogError(("CHapi::ErrorMsgCallback(%p) HAPI_ERR_AUD_LEVEL_ALARM param=%p\n", p_CHapi, param));
		break;
	case HAPI_ERR_PCR_MISSING: // No PCR has been detected on the configured PCR PID for more than 500 ms.
		DbgLogError(("CHapi::ErrorMsgCallback(%p) HAPI_ERR_PCR_MISSING param=%p\n", p_CHapi,  param));
		break;
	case HAPI_ERR_UNSUPPORTED_CODEC: // The actual encoded stream (video or audio) is coded in an unsupported codec.
		DbgLogError(("CHapi::ErrorMsgCallback(%p) HAPI_ERR_UNSUPPORTED_CODEC param=%p\n", p_CHapi, param));
		break;
	default:
		DbgLogError(("CHapi::ErrorMsgCallback(%p) UNKNOWN errorType=%d param=%p\n", p_CHapi, errorType, param));
	}
#if 1//BLING, Error LED
	DWORD _bling_options = p_CHapi->_bling_options;
	if(!p_CHapi->_isPaused && (_bling_options & 0x1717)){
		USBBootMChip_t *p_mchip = p_CHapi->p_mchip;
		p_mchip->lockBus();
		p_mchip->MCHIP_Host_Select();
		if(_bling_options & 0x0202){
			p_mchip->MCHIP_LED_Set(47, 1);//LED1 Error on
			if((_bling_options & 0x020000) == 0){
				p_CHapi->_errCountdown = 15;
			}
			p_CHapi->_LED_state |= 0x02;
		}
		//FGR - only turn these off if they are in toggle mode, or they won't come back on
		// for a hard error turn them all off
		if(hard_error || _bling_options & 0x010000){
			p_mchip->MCHIP_LED_Set(55, 0);//Green Bling off
			p_CHapi->_LED_state &= ~0x01;
		}
		if(hard_error || _bling_options & 0x100000){
			p_mchip->MCHIP_LED_Set(53, 0);//Blue Bling off
			p_CHapi->_LED_state &= ~0x10;
		}
		if(hard_error || _bling_options & 0x040000){
			p_mchip->MCHIP_LED_Set(48, 0);//LED2 Power off
			p_CHapi->_LED_state &= ~0x04;
		}
		p_mchip->unlockBus();
	}
#endif
	return HAPI_SUCCESS;
}

HapiErrCode CHapi::AVDataTransfer (HAPI_AV_DATA_INFO *info, void *context)
{
	CHapi *p_CHapi = (CHapi *)context;
	DbgLogTrace(("AVDataTransfer(%p) chan=%d buf=%p size=%u\n", p_CHapi, info->channel, info->buf, info->requestSize));

#if DBG
	if(p_CHapi->outFileHandle){
		ULONG_PTR len = p_CHapi->prv_write_file(p_CHapi->outFileHandle, info->buf, info->requestSize);
	}
#endif//DBG
	DWORD now = wrapGetTicks_ms();
	if(p_CHapi->_first_payload_time){
		DWORD delta_t = now - p_CHapi->_first_payload_time;
		p_CHapi->_first_payload_time = 0;
		p_CHapi->_first_payload_delta = delta_t;
		p_CHapi->_last_payload_time = now;
		DbgLogInfo(("AVDataTransfer_startup=%u\n", delta_t));
	} else {
		DWORD delta_t = now - p_CHapi->_last_payload_time;
		p_CHapi->_last_payload_time = now;
		p_CHapi->_last_payload_delta = delta_t;
		DbgLogTrace(("AVDataTransfer_delta_t=%u\n", delta_t));
	}
	if(p_CHapi->_p_data_transfer){
//#ifdef OLD_DRIVER
		DataTransfer::static_BufferComplete(p_CHapi->_p_data_transfer, info->buf, info->requestSize);
//#endif
	}

#if 1//BLING
	USBBootMChip_t *p_mchip = p_CHapi->p_mchip;

	DWORD _bling_options = p_CHapi->_bling_options;
	DWORD new_bling_options = p_mchip->getBling_Options();

	if(_bling_options != new_bling_options){
		//_bling_options are changing, turn off any previous "in use" LEDs
		if(_bling_options & 0x1717){
			p_mchip->lockBus();
			p_mchip->MCHIP_Host_Select();
			if(_bling_options & 0x010101){
				if(!p_mchip->MCHIP_LED_Set(55, 0)){//Green Bling off
					p_mchip->MCHIP_LED_Set(55, 0);//BUGBUG - why do we need this retry!!
				}
				p_CHapi->_LED_state &= ~0x01;
			}
			if(_bling_options & 0x101010){
				if(!p_mchip->MCHIP_LED_Set(53, 0)){//Blue Bling off
					p_mchip->MCHIP_LED_Set(53, 0);//BUGBUG - why do we need this retry!!
				}
				p_CHapi->_LED_state &= ~0x10;
			}
			if(_bling_options & 0x040404){
				if(!p_mchip->MCHIP_LED_Set(48, 0)){//LED2 Power off
					p_mchip->MCHIP_LED_Set(48, 0);//BUGBUG - why do we need this retry!!
				}
				p_CHapi->_LED_state &= ~0x04;
			}
			p_mchip->unlockBus();
		}
		_bling_options = new_bling_options;
		p_CHapi->_bling_options = new_bling_options;
		p_CHapi->_bling_count = 0; //new options, so start with Turn On state
	}
	if(!p_CHapi->_isPaused && p_CHapi->_API_ok && (_bling_options & 0x151717)){

		if(p_CHapi->_errCountdown){
			p_CHapi->_errCountdown--;
			if(p_CHapi->_errCountdown == 0){
				p_mchip->lockBus();
				p_mchip->MCHIP_Host_Select();
				if(!p_mchip->MCHIP_LED_Set(47, 0)){//LED1 Error off
					p_mchip->MCHIP_LED_Set(47, 0);//BUGBUG - why do we need this retry!!
				}
				p_CHapi->_LED_state &= ~0x02;
				p_mchip->unlockBus();
			}
		}
		if((p_CHapi->_bling_count & 0x7) == 6){
			if(_bling_options & 0x150000){ //any toggles during encode?
				p_mchip->lockBus();
				p_mchip->MCHIP_Host_Select();
				if(_bling_options & 0x010000){
					if(!p_mchip->MCHIP_LED_Set(55, 0)){//Green Bling off
						p_mchip->MCHIP_LED_Set(55, 0);//BUGBUG - why do we need this retry!!
					}
					p_CHapi->_LED_state &= ~0x01;
				}
				if(_bling_options & 0x100000){
					if(!p_mchip->MCHIP_LED_Set(53, 0)){//Blue Bling off
						p_mchip->MCHIP_LED_Set(53, 0);//BUGBUG - why do we need this retry!!
					}
					p_CHapi->_LED_state &= ~0x10;
				}
				if(_bling_options & 0x040000){
					if(!p_mchip->MCHIP_LED_Set(48, 0)){//LED2 Power off
						p_mchip->MCHIP_LED_Set(48, 0);
					}
					p_CHapi->_LED_state &= ~0x04;
				}
				p_mchip->unlockBus();
			} else {
				p_CHapi->_bling_count = 0; //no toggles, so don't need to keep turning them on either
			}
		} else if((p_CHapi->_bling_count & 0x7) == 0){
			p_mchip->lockBus();
			p_mchip->MCHIP_Host_Select();
			if(_bling_options & 0x01){
				if(!p_mchip->MCHIP_LED_Set(55, 1)){//Green Bling on
					p_mchip->MCHIP_LED_Set(55, 1);//BUGBUG - why do we need this retry!!
				}
				p_CHapi->_LED_state |= 0x01;
			} else if(_bling_options & 0x0100){//Green Bling in use, but off
				if(!p_mchip->MCHIP_LED_Set(55, 0)){
					p_mchip->MCHIP_LED_Set(55, 0);//BUGBUG - why do we need this retry!!
				}
				p_CHapi->_LED_state &= ~0x01;
			}
			if(_bling_options & 0x10){
				if(!p_mchip->MCHIP_LED_Set(53, 1)){//Blue Bling on
					p_mchip->MCHIP_LED_Set(53, 1);//BUGBUG - why do we need this retry!!
				}
				p_CHapi->_LED_state |= 0x10;
			} else if(_bling_options & 0x1000){//Blue Bling in use, but off
				if(!p_mchip->MCHIP_LED_Set(53, 0)){
					p_mchip->MCHIP_LED_Set(53, 0);//BUGBUG - why do we need this retry!!
				}
				p_CHapi->_LED_state &= ~0x10;
			}
			if(_bling_options & 0x04){
				if(!p_mchip->MCHIP_LED_Set(48, 1)){//LED2 Power on
					p_mchip->MCHIP_LED_Set(48, 1);
				}
				p_CHapi->_LED_state |= 0x04;
			} else if(_bling_options & 0x0400){//LED2 in use, but off
				if(!p_mchip->MCHIP_LED_Set(48, 0)){//LED2 Power off
					p_mchip->MCHIP_LED_Set(48, 0);
				}
				p_CHapi->_LED_state &= ~0x04;
			}
			p_mchip->unlockBus();
		}
		p_CHapi->_bling_count++;
	}
#endif

	return HAPI_SUCCESS;
}


#if 1
Uint32 CHapi::HapiStatusQuery (HAPI_QUERY_STRUCT *p_status)
{
	lock();
	if(gHapi == NULL){
		DbgLogError(("CHapi::StatusQuery() gHapi==NULL!!\n"));
		unlock();
		return 0;
	}
	if(p_status == NULL){
		DbgLogError(("CHapi::StatusQuery() p_status==NULL!!\n"));
		unlock();
		return 0;
	}
	DbgLogInfo(("CHapi::StatusQuery(%p)\n", p_status));
	memset(p_status, 0, sizeof(HAPI_QUERY_STRUCT));

    HAPI_QUERY_STRUCT queriedStatus;
	queriedStatus.bitMask=0xffff;
    
	hapiErr = HAPI_StatusQuery(gHapi, &queriedStatus);
    if(hapiErr != HAPI_SUCCESS)
    {
		DbgLogWarn((" HAPI_StatusQuery hapiErr=0x%x\n", hapiErr));
		unlock();
		return 0;
    }

 #if 1//DBG
    if (queriedStatus.bitMask & HAPI_BM_STATUS_QUERY_STATE)
    {    
        DbgLogInfo(("STATUS_QUERY_STATE: %u\n", queriedStatus.state));
    }
    if (queriedStatus.bitMask & HAPI_BM_STATUS_QUERY_FRAMERATE)
    {    
        DbgLogRelease(("STATUS_QUERY_FRAMERATE: %u\n", queriedStatus.frameRate));
    }
    if (queriedStatus.bitMask & HAPI_BM_STATUS_QUERY_PCR)
    {    
        DbgLogInfo(("STATUS_QUERY_PCR: 0x%llx\n", queriedStatus.pcr));
    }
    if (queriedStatus.bitMask & HAPI_BM_STATUS_QUERY_INFRCOUNT)
    {    
        DbgLogRelease(("STATUS_QUERY_INFRCOUNT: %u\n", queriedStatus.inFrameCount));
    }
    if (queriedStatus.bitMask & HAPI_BM_STATUS_QUERY_OUTFRCOUNT)
    {    
        DbgLogRelease(("STATUS_QUERY_OUTFRCOUNT: %u\n", queriedStatus.outFrameCount));
    }
    if (queriedStatus.bitMask & HAPI_BM_STATUS_QUERY_AR)
    {    
        DbgLogInfo(("STATUS_QUERY_AR: %u\n", queriedStatus.ar));
    }
  #if 0
	if (queriedStatus.bitMask & HAPI_BM_STATUS_QUERY_INTERLACE)
    {    
        DbgLogInfo(("STATUS_QUERY_INTERLACE: %u\n", queriedStatus.isInterlaced));
    }
    if (queriedStatus.bitMask & HAPI_BM_STATUS_QUERY_WIDTH)
    {    
        DbgLogInfo(("STATUS_QUERY_WIDTH: %u\n", queriedStatus.videoWidth));
    }
    if (queriedStatus.bitMask & HAPI_BM_STATUS_QUERY_HEIGHT)
    {    
        DbgLogInfo(("STATUS_QUERY_HEIGHT: %u\n", queriedStatus.videoHeight));
    }
    if (queriedStatus.bitMask & HAPI_BM_STATUS_QUERY_AUDIO_SAMPLE_RATE)
    {    
        DbgLogInfo(("QUERY_AUDIO_SAMPLE_RATE: %u\n", queriedStatus.audioSamplingRate));
    }
    if (queriedStatus.bitMask & HAPI_BM_STATUS_QUERY_AUDIO_BIT_RATE)
    {    
        DbgLogInfo(("QUERY_AUDIO_BIT_RATE: %u\n", queriedStatus.audioBitrate));
    }
  #endif

 #endif//DBG
	//return the data
	*p_status = queriedStatus;
	unlock();
	return 1;
}
#endif


#if DBG
void CHapi::verify_type_sizes()
{

	DbgLogTrace(("sizeof(Boolean)                     =%d\n", sizeof(Boolean)));
	DbgLogTrace(("sizeof(HAPI_VIDEO_CODEC)            =%d\n", sizeof(HAPI_VIDEO_CODEC)));
	DbgLogTrace(("sizeof(HAPI_AUDIO_CODEC)            =%d\n", sizeof(HAPI_AUDIO_CODEC)));
//	DbgLogTrace(("sizeof(HAPI_VIDEO_OUTPUT_RESOLUTION)=%d\n", sizeof(HAPI_VIDEO_OUTPUT_RESOLUTION)));
	DbgLogTrace(("sizeof(HAPI_VIDEO_OUTPUT_FRAME_RATE)=%d\n", sizeof(HAPI_VIDEO_OUTPUT_FRAME_RATE)));
	DbgLogTrace(("sizeof(HAPI_VIDEO_OUTPUT_MODE)      =%d\n", sizeof(HAPI_VIDEO_OUTPUT_MODE)));
	DbgLogTrace(("sizeof(HAPI_AUDIO_OUTPUT_MODE)      =%d\n", sizeof(HAPI_AUDIO_OUTPUT_MODE)));
	DbgLogTrace(("sizeof(HAPI_AUDIO_SAMPLE_RATE)      =%d\n", sizeof(HAPI_AUDIO_SAMPLE_RATE)));
	DbgLogTrace(("sizeof(HAPI_AUDIO_TRANSCODE_MODE)   =%d\n", sizeof(HAPI_AUDIO_TRANSCODE_MODE)));
	DbgLogTrace(("sizeof(HAPI_RATE_CONTROL)           =%d\n", sizeof(HAPI_RATE_CONTROL)));
	DbgLogTrace(("sizeof(HAPI_FILE_OUTPUT_FORMAT)     =%d\n", sizeof(HAPI_FILE_OUTPUT_FORMAT)));
	DbgLogTrace(("sizeof(HAPI_ANC_DATA_TRANSFER_MODE) =%d\n", sizeof(HAPI_ANC_DATA_TRANSFER_MODE)));
	DbgLogTrace(("sizeof(HAPI_ENCRYPTION_MODE)        =%d\n", sizeof(HAPI_ENCRYPTION_MODE)));
	DbgLogTrace(("sizeof(HAPI_AUDIO_BITRATE)          =%d\n", sizeof(HAPI_AUDIO_BITRATE)));
	DbgLogTrace(("sizeof(HAPI_CODING_MODE)            =%d\n", sizeof(HAPI_CODING_MODE)));
	DbgLogTrace(("sizeof(HAPI_VIDEO_ENTROPY_MODE)     =%d\n", sizeof(HAPI_VIDEO_ENTROPY_MODE)));
	DbgLogTrace(("sizeof(HAPI_VIDEO_PROFILE)          =%d\n", sizeof(HAPI_VIDEO_PROFILE)));
	DbgLogTrace(("sizeof(HAPI_VIDEO_H264_LEVEL)       =%d\n", sizeof(HAPI_VIDEO_H264_LEVEL)));
	DbgLogTrace(("sizeof(HAPI_LATENCY)                =%d\n", sizeof(HAPI_LATENCY)));

	DbgLogTrace(("\n"));
	DbgLogTrace(("sizeof(HAPI_DECODE_PARAMS)   =%d\n", sizeof(HAPI_DECODE_PARAMS)));
	DbgLogTrace(("sizeof(XCODE_VIDEO_PARAMS)   =%d\n", sizeof(XCODE_VIDEO_PARAMS)));
	DbgLogTrace(("sizeof(XCODE_AUDIO_PARAMS)   =%d\n", sizeof(XCODE_AUDIO_PARAMS)));
	DbgLogTrace(("sizeof(ENCODE_VIDEO_PARAMS)  =%d\n", sizeof(ENCODE_VIDEO_PARAMS)));
	DbgLogTrace(("sizeof(ENCODE_AUDIO_PARAMS)  =%d\n", sizeof(ENCODE_AUDIO_PARAMS)));
	DbgLogTrace(("sizeof(SYS_LOG_PARAMS)       =%d\n", sizeof(SYS_LOG_PARAMS)));
	DbgLogTrace(("sizeof(HAPI_TRANSCODE_PARAMS)=%d\n", sizeof(HAPI_TRANSCODE_PARAMS)));
	DbgLogTrace(("sizeof(HAPI_ENCODE_PARAMS)   =%d\n", sizeof(HAPI_ENCODE_PARAMS)));
	DbgLogTrace(("sizeof(HAPI_AV_DATA_INFO)    =%d\n", sizeof(HAPI_AV_DATA_INFO)));
	DbgLogTrace(("sizeof(HAPI_SET_PARAM)       =%d\n", sizeof(HAPI_SET_PARAM)));
	
	DbgLogTrace(("\n"));
	DbgLogTrace(("sizeof(HWAPI_MSG_GET_PARAM_REQ)          =%d\n", sizeof(HWAPI_MSG_GET_PARAM_REQ)));
	DbgLogTrace(("sizeof(HWAPI_MSG_GET_PARAM_RSP)          =%d\n", sizeof(HWAPI_MSG_GET_PARAM_RSP)));
	DbgLogTrace(("sizeof(HWAPI_MSG_SET_PARAM)              =%d\n", sizeof(HWAPI_MSG_SET_PARAM)));
	DbgLogTrace(("sizeof(HWAPI_MSG_SET_PARAM_RSP)          =%d\n", sizeof(HWAPI_MSG_SET_PARAM_RSP)));

	DbgLogTrace(("sizeof(HWAPI_MSG_I2C_WRITE)              =%d\n", sizeof(HWAPI_MSG_I2C_WRITE)));
	DbgLogTrace(("sizeof(HWAPI_MSG_I2C_WRITE_RSP)          =%d\n", sizeof(HWAPI_MSG_I2C_WRITE_RSP)));
	DbgLogTrace(("sizeof(HWAPI_MSG_I2C_READ)               =%d\n", sizeof(HWAPI_MSG_I2C_READ)));
	DbgLogTrace(("sizeof(HWAPI_MSG_I2C_READ_RSP)           =%d\n", sizeof(HWAPI_MSG_I2C_READ_RSP)));
	DbgLogTrace(("sizeof(HWAPI_MSG_I2C_CLOCK_FREQ)         =%d\n", sizeof(HWAPI_MSG_I2C_CLOCK_FREQ)));
	DbgLogTrace(("sizeof(HWAPI_MSG_I2C_CLOCK_FREQ_RSP)     =%d\n", sizeof(HWAPI_MSG_I2C_CLOCK_FREQ_RSP)));
	DbgLogTrace(("sizeof(HWAPI_MSG_I2C_MONITOR_INSTALL)    =%d\n", sizeof(HWAPI_MSG_I2C_MONITOR_INSTALL)));
	DbgLogTrace(("sizeof(HWAPI_MSG_I2C_MONITOR_INSTALL_RSP)=%d\n", sizeof(HWAPI_MSG_I2C_MONITOR_INSTALL_RSP)));
	DbgLogTrace(("sizeof(HWAPI_MSG_I2C_OUTPUT_MONITOR_DATA)=%d\n", sizeof(HWAPI_MSG_I2C_OUTPUT_MONITOR_DATA)));
	DbgLogTrace(("sizeof(HWAPI_MSG_PCR_DATA)               =%d\n", sizeof(HWAPI_MSG_PCR_DATA)));
	DbgLogTrace(("sizeof(HWAPI_MSG_PCR_DATA_RSP)           =%d\n", sizeof(HWAPI_MSG_PCR_DATA_RSP)));
	DbgLogTrace(("sizeof(HWAPI_MSG_AR_DATA)                =%d\n", sizeof(HWAPI_MSG_AR_DATA)));
	DbgLogTrace(("sizeof(HWAPI_MSG_AR_DATA_RSP)            =%d\n", sizeof(HWAPI_MSG_AR_DATA_RSP)));
	
	DbgLogTrace(("sizeof(HWAPI_MSG_SET_AVL)                =%d\n", sizeof(HWAPI_MSG_SET_AVL)));
	DbgLogTrace(("sizeof(HWAPI_MSG_SET_AVL_RSP)            =%d\n", sizeof(HWAPI_MSG_SET_AVL_RSP)));
	DbgLogTrace(("sizeof(HWAPI_MSG_START)                  =%d\n", sizeof(HWAPI_MSG_START)));
	DbgLogTrace(("sizeof(HWAPI_MSG_START_RSP)              =%d\n", sizeof(HWAPI_MSG_START_RSP)));
	DbgLogTrace(("sizeof(HWAPI_MSG_STOP)                   =%d\n", sizeof(HWAPI_MSG_STOP)));
	DbgLogTrace(("sizeof(HWAPI_MSG_STOP_RSP)               =%d\n", sizeof(HWAPI_MSG_STOP_RSP)));
	DbgLogTrace(("sizeof(HWAPI_MSG_INIT)                   =%d\n", sizeof(HWAPI_MSG_INIT)));
	DbgLogTrace(("sizeof(HWAPI_MSG_INIT_RSP)               =%d\n", sizeof(HWAPI_MSG_INIT_RSP)));
	DbgLogTrace(("sizeof(HWAPI_MSG_EXIT)                   =%d\n", sizeof(HWAPI_MSG_EXIT)));
	DbgLogTrace(("sizeof(HWAPI_MSG_EXIT_RSP)               =%d\n", sizeof(HWAPI_MSG_EXIT_RSP)));

	DbgLogTrace(("sizeof(HWAPI_MSG_FWUPGRADE)              =%d\n", sizeof(HWAPI_MSG_FWUPGRADE)));
	DbgLogTrace(("sizeof(HWAPI_MSG_FWUPGRADE_RSP)          =%d\n", sizeof(HWAPI_MSG_FWUPGRADE_RSP)));
	
	DbgLogTrace(("sizeof(HWAPI_MSG_STREAM_INPUT_DATA)      =%d\n", sizeof(HWAPI_MSG_STREAM_INPUT_DATA)));
	DbgLogTrace(("sizeof(HWAPI_MSG_STREAM_INPUT_DATA_RSP)  =%d\n", sizeof(HWAPI_MSG_STREAM_INPUT_DATA_RSP)));
	DbgLogTrace(("sizeof(HWAPI_MSG_STREAM_INPUT_DATA_INF)  =%d\n", sizeof(HWAPI_MSG_STREAM_INPUT_DATA_INF)));
	DbgLogTrace(("sizeof(HWAPI_MSG_ERROR)                  =%d\n", sizeof(HWAPI_MSG_ERROR)));
	DbgLogTrace(("sizeof(HWAPI_MSG_STREAM_DATA_REQUEST)    =%d\n", sizeof(HWAPI_MSG_STREAM_DATA_REQUEST)));
	DbgLogTrace(("sizeof(HWAPI_MSG_STREAM_DATA_REQUEST_RSP)=%d\n", sizeof(HWAPI_MSG_STREAM_DATA_REQUEST_RSP)));
	DbgLogTrace(("sizeof(HWAPI_MSG_STREAM_OUTPUT_DATA)     =%d\n", sizeof(HWAPI_MSG_STREAM_OUTPUT_DATA)));
	DbgLogTrace(("sizeof(HWAPI_MSG_STREAM_OUTPUT_DATA_RSP) =%d\n", sizeof(HWAPI_MSG_STREAM_OUTPUT_DATA_RSP)));
	DbgLogTrace(("sizeof(HWAPI_MSG_STREAM_OUTPUT_DATA_INF) =%d\n", sizeof(HWAPI_MSG_STREAM_OUTPUT_DATA_INF)));
	DbgLogTrace(("sizeof(HWAPI_MSG_AV_UPDATE)              =%d\n", sizeof(HWAPI_MSG_AV_UPDATE)));

	DbgLogTrace(("sizeof(HWAPI_MSG_ERR_UPDATE)             =%d\n", sizeof(HWAPI_MSG_ERR_UPDATE)));
	DbgLogTrace(("sizeof(HWAPI_MSG_QUERY_STATUS)           =%d\n", sizeof(HWAPI_MSG_QUERY_STATUS)));
	DbgLogTrace(("sizeof(HWAPI_MSG_QUERY_STATUS_RSP)       =%d\n", sizeof(HWAPI_MSG_QUERY_STATUS_RSP)));

}
#endif//DBG


////////////////////////////////////////////////////////
VOID CHapi::lock()
{
    wrapMutexLock(&_mutex);
}

VOID CHapi::unlock()
{
    wrapMutexUnlock(&_mutex);
}


#ifdef HAPI_POWER_THREAD
VOID CHapi::static_doPowerChk(CHapi* p_CHapi)
{
    p_CHapi->doPowerChk();
}

VOID CHapi::doPowerChk()
{
	DbgLogInfo(("CHapi::doPowerChk() this=%p, _power_down_delay=%u\n", this, _power_down_delay));
	_power_time_left = _power_down_delay;

    while(true)
    {

        #define RELATIVE_WAIT(x)    (-1*(x))
        #define MICROSECONDS(x)     ((x)*10L)
        #define MILLISECONDS(x)     ((x)*10000L)
        #define SECONDS(x)          ((x)*10000000L)

        LARGE_INTEGER  timeout;
        timeout.QuadPart = RELATIVE_WAIT(SECONDS(1));

        // Wait until our thread is signalled or time has expired (whichever is shorter)
        NTSTATUS status = KeWaitForSingleObject(
            &_polling_event_object,
            Executive,
            KernelMode,
            FALSE,
            &timeout
            );

        if(STATUS_TIMEOUT != status){ // status == STATUS_SUCCES when signalled
			DbgLogInfo(("CHapi::doPowerChk() got status=%x\n", status));
            break;
        }
		lock(); //interlock with any ongoing CHapi powerDown()/powerUp() activities
		if(_powered_up){
			_power_time_left = _power_down_delay;
		} else {
			if(_power_time_left){
				_power_time_left--;
				if(_power_time_left == 0){
					powerDownHW();
#if DBG//allow us to change delay "on the fly" during debuging
					hcwGetRegistryDWORD("power_down_delay", &_power_down_delay);
#endif
				}
			}
		}
		unlock();
    }
	DbgLogInfo(("CHapi::doPowerChk() exiting, this=%p, _power_down_delay=%u, time_left=%u\n",
		this, _power_down_delay, _power_time_left));

    _polling_thread_object = NULL;
    //This will signal the wait on _polling_thread_object
	PsTerminateSystemThread(STATUS_SUCCESS);
}

/////////////////////////////////////////////////////////////////////////////////////////
NTSTATUS CHapi::startPowerThread()
{
	DbgLogInfo(("CHapi::startPowerThread() _polling_thread_object=%p\n", _polling_thread_object));
    if (_polling_thread_object)
    {
        return STATUS_UNSUCCESSFUL;
    }
	_polling_thread_object = (PVOID)((INT_PTR)0xbadbeef1);
	
	KeClearEvent(&_polling_event_object);

    HANDLE thread_handle;
    NTSTATUS status = PsCreateSystemThread(
        &thread_handle,
        THREAD_ALL_ACCESS,
        NULL,
        NULL,
        NULL,
        (PKSTART_ROUTINE) CHapi::static_doPowerChk,   // Thread routine
        this);                                    // Context

    if(!NT_SUCCESS(status)){
		_polling_thread_object = NULL;
		DbgLogError(("CHapi::startPowerThread() returns=%x\n", status));
        return status;
	}
    status = ObReferenceObjectByHandle(
            thread_handle,
            THREAD_ALL_ACCESS,
            NULL,
            KernelMode,
            &_polling_thread_object,
            NULL);

    ZwClose(thread_handle);

	wrapSleep_ms(20);
	DbgLogInfo(("CHapi::startPowerThread() returns=%x\n", status));
    return status;
}

VOID CHapi::stopPowerThread()
{
	DbgLogInfo(("CHapi::stopPowerThread() _polling_thread_object=%p\n", _polling_thread_object));

	//in case it's just starting ...
	while(_polling_thread_object == (PVOID)((INT_PTR)0xbadbeef1)){
		wrapSleep_ms(100);
	}
    void *thread_object = _polling_thread_object;

	//Don't try to stop the thread if it isn't started.
    if(!thread_object)
    {
        return;
    }
    // signal the thread
    LONG status = KeSetEvent(
        &_polling_event_object,
        IO_NO_INCREMENT,
        TRUE);

    _polling_thread_object = NULL;

    KeWaitForSingleObject(
        thread_object,
        Executive,
        KernelMode,
        FALSE,
        NULL);

	DbgLogInfo(("CHapi::stopPowerThread() returns\n"));
}

#endif//HAPI_POWER_THREAD


//Get/Set Colossus style API params for Scaler, Audio
Uint32 CHapi::setScalerSettings(ScalerSettings *pScaler)
{
	if(pScaler == NULL){
		DbgLogWarn(("CHapi::setScalerSettings(NULL)!!\n"));
		return 0;
	}
	DbgLogInfo(("CHapi::setScalerSettings(%p) scaler.mode=%d\n", pScaler, pScaler->mode));
	m_extcapParams.scaler = *pScaler;
	return 1;
}

Uint32 CHapi::setAudEncSettings(AudEncSettings *pAudEnc)
{
	if(pAudEnc == NULL){
		DbgLogWarn(("CHapi::setAudEncSettings(NULL)!!\n"));
		return 0;
	}
	DbgLogInfo(("CHapi::setAudEncSettings(%p) rate441=%d rate48=%d\n", pAudEnc, pAudEnc->sample_rate_441, pAudEnc->sample_rate_48));

	m_extcapParams.audioEncoder = *pAudEnc;
	return 1;
}


//FGR - these look up defaults based on Colossus style API params
Uint32 CHapi::get_audenc_defaults(HAPI_SET_PARAM *pParam)
{
	if(pParam == NULL){
		DbgLogWarn(("CHapi::get_audenc_defaults(NULL)!!\n"));
		return 0;
	}
	// in kHz. 0:NONE 1:32, 2:44.1, 3:48, 4:96, 5:192, 6:16
	HAPI_AUDIO_SAMPLE_RATE sampleRate = pParam->params.encodeParam.AudioParams.AudioCapSampleRate;
	DbgLogInfo(("CHapi::get_audenc_defaults(%p) sampleRate=%d\n", pParam, sampleRate));

    AUDIO_SAMPLE_RATES *p_orig_rate = NULL;
	AUDIO_SAMPLE_RATES new_rate = (AUDIO_SAMPLE_RATES)0;
	switch(sampleRate){
	default:
		DbgLogWarn(("  sampleRate unknown!!\n"));
		//fallthru
	case HAPI_AUDIO_SAMPLE_RATE_FOLLOW_INPUT:
	case HAPI_AUDIO_SAMPLE_RATE_NONE:
	case HAPI_AUDIO_SAMPLE_RATE_96_KHZ:
	case HAPI_AUDIO_SAMPLE_RATE_192_KHZ:
	case HAPI_AUDIO_SAMPLE_RATE_16_KHZ://TODO: is this a valid output sample rate??
		return 0; //nothing to do

	case HAPI_AUDIO_SAMPLE_RATE_32_KHZ:
		p_orig_rate = &m_extcapParams.audioEncoder.sample_rate_48;
		hcwGetRegistryDWORD(HAUP_AUDIO_ENC_SAMPLE_RATE_48, (LPDWORD)p_orig_rate);
		new_rate = *p_orig_rate;
		if(new_rate == AUDIO_SAMPLE_RATE_32000){
			new_rate = (AUDIO_SAMPLE_RATES)0;//no need to change
		}
		break;

	case HAPI_AUDIO_SAMPLE_RATE_44_1_KHZ:
		p_orig_rate = &m_extcapParams.audioEncoder.sample_rate_441;
		hcwGetRegistryDWORD(HAUP_AUDIO_ENC_SAMPLE_RATE_441, (LPDWORD)p_orig_rate);
		new_rate = *p_orig_rate;
		if(new_rate == AUDIO_SAMPLE_RATE_44100){
			new_rate = (AUDIO_SAMPLE_RATES)0;//no need to change
		}
		break;

	case HAPI_AUDIO_SAMPLE_RATE_48_KHZ:
		p_orig_rate = &m_extcapParams.audioEncoder.sample_rate_48;
		hcwGetRegistryDWORD(HAUP_AUDIO_ENC_SAMPLE_RATE_48, (LPDWORD)p_orig_rate);
		new_rate = *p_orig_rate;
		if(new_rate == AUDIO_SAMPLE_RATE_48000){
			new_rate = (AUDIO_SAMPLE_RATES)0;//no need to change
		}
		break;
	}
	if(new_rate == 0)
		return 0;//not really an error, but we didn't do anything either

	switch(new_rate){
	case AUDIO_SAMPLE_RATE_48000:
		sampleRate = HAPI_AUDIO_SAMPLE_RATE_48_KHZ;
		break;
	case AUDIO_SAMPLE_RATE_44100:
		sampleRate = HAPI_AUDIO_SAMPLE_RATE_44_1_KHZ;
		break;
	case AUDIO_SAMPLE_RATE_32000:
		sampleRate = HAPI_AUDIO_SAMPLE_RATE_32_KHZ;
		break;

	case AUDIO_SAMPLE_RATE_16000://TODO: is this a valid output sample rate??
	case AUDIO_SAMPLE_RATE_24000:
	case AUDIO_SAMPLE_RATE_8000:
		DbgLogWarn(("CHapi::get_audenc_defaults() new_rate=%u unsupported, 48000 assumed\n", new_rate));
		m_extcapParams.audioEncoder.sample_rate_48 = AUDIO_SAMPLE_RATE_48000;
		return 0;

	case AUDIO_SAMPLE_RATE_22050:
	case AUDIO_SAMPLE_RATE_12000:
	case AUDIO_SAMPLE_RATE_11025:
		DbgLogWarn(("CHapi::get_audenc_defaults() new_rate=%u unsupported, 44100 assumed\n", new_rate));
		m_extcapParams.audioEncoder.sample_rate_441 = AUDIO_SAMPLE_RATE_44100;
		return 0;

	default:
		DbgLogWarn(("CHapi::get_audenc_defaults() new_rate=%u unsupported\n", new_rate));
		return 0;
	}
	if(pParam->params.encodeParam.AudioParams.AudioOutputSamplingRate == sampleRate)
		return 0;

	set_param(pParam, "AudioOutputSamplingRate", sampleRate);

	switch(sampleRate){
	case HAPI_AUDIO_SAMPLE_RATE_32_KHZ:
		*p_orig_rate = AUDIO_SAMPLE_RATE_32000; break;
	case HAPI_AUDIO_SAMPLE_RATE_44_1_KHZ:
		*p_orig_rate = AUDIO_SAMPLE_RATE_44100; break;
	case HAPI_AUDIO_SAMPLE_RATE_48_KHZ:
		*p_orig_rate = AUDIO_SAMPLE_RATE_48000; break;
	}
	return 1;
}

//FGR - these look up defaults based on Colossus style API params
Uint32 CHapi::get_scaler_defaults(HAPI_SET_PARAM *pParam)
{
	if(pParam == NULL){
		DbgLogWarn(("CHapi::get_scaler_defaults(NULL)!!\n"));
		return 0;
	}
	DWORD hdmi_fmt = _hdmi_fmt;
	DbgLogInfo(("CHapi::get_scaler_defaults(%p), hdmi_fmt=%d\n", pParam, hdmi_fmt));
	
	//FGR - allow StreamEez testing via registry (but really should only use for testing)
	hcwGetRegistryDWORD(HAUP_SCALER_MODE,     (LPDWORD)&m_extcapParams.scaler.mode);
	if(m_extcapParams.scaler.mode == 0){
		return 1; //scaler API not enabled
	}

	hcwGetRegistryDWORD(HAUP_SCALE_RES_1080I, (LPDWORD)&m_extcapParams.scaler.res1080I);
	hcwGetRegistryDWORD(HAUP_SCALE_RES_1080P, (LPDWORD)&m_extcapParams.scaler.res1080P);
	hcwGetRegistryDWORD(HAUP_SCALE_RES_720P,  (LPDWORD)&m_extcapParams.scaler.res720P);
	hcwGetRegistryDWORD(HAUP_SCALE_RES_SDP,   (LPDWORD)&m_extcapParams.scaler.resSDP);
	hcwGetRegistryDWORD(HAUP_SCALE_RES_SDI,   (LPDWORD)&m_extcapParams.scaler.resSDI);
	hcwGetRegistryDWORD(HAUP_SCALE_FPS_1080I, (LPDWORD)&m_extcapParams.scaler.fps1080I);
	hcwGetRegistryDWORD(HAUP_SCALE_FPS_1080P, (LPDWORD)&m_extcapParams.scaler.fps1080P);
	hcwGetRegistryDWORD(HAUP_SCALE_FPS_720P,  (LPDWORD)&m_extcapParams.scaler.fps720P);
	hcwGetRegistryDWORD(HAUP_SCALE_FPS_SDP,   (LPDWORD)&m_extcapParams.scaler.fpsSDP);
	hcwGetRegistryDWORD(HAUP_SCALE_FPS_SDI,   (LPDWORD)&m_extcapParams.scaler.fpsSDI);

//	set_param(pParam, "VideoOutputWidth", 720);
//	set_param(pParam, "VideoOutputHeight", 480);
//	set_param(pParam, "VideoOutputFrameRate", 3); // 1 - 23.98, 2 - 24, 3 - 25, 4 - 29.97, 5 - 30, 6 - 50, 7 - 59.94, 8 - 60, 9 - 15, 10 - 10, 11 - 6, 12 - 5, 13 - 2, 14 - 1
//	set_param(pParam, "VideoOutputMode", 0);  // 0 - interlaced, 1 - progressive

	int progressive_ok = 0;
	DWORD disp_horz, disp_vert, video_out_frate;
	switch(hdmi_fmt){
	case TMDL_HDMITX_VFMT_01_640x480p_60Hz:
		disp_horz = 640;
		disp_vert = 480;
		if( m_extcapParams.scaler.resSDP == SCALE_RES_640x480 )
		{
			disp_horz = 640;// output horz resolution
			disp_vert = 480;// output vert resolution
		}
		else if( m_extcapParams.scaler.resSDP == SCALE_RES_640x360 )
		{
			disp_horz = 640;// output horz resolution
			disp_vert = 360;// output vert resolution
		}
		else if( m_extcapParams.scaler.resSDP == SCALE_RES_480x360 )
		{
			disp_horz = 480;// output horz resolution
			disp_vert = 360;// output vert resolution
		}
		else if( m_extcapParams.scaler.resSDP == SCALE_RES_480x270 )
		{
			disp_horz = 480;// output horz resolution
			disp_vert = 272;// output vert resolution
		}
		set_param(pParam, "VideoOutputWidth", disp_horz);
		set_param(pParam, "VideoOutputHeight", disp_vert);

		video_out_frate = 7;//59.94
		if( m_extcapParams.scaler.fpsSDP == SCALE_FPS_30 )
		{
			video_out_frate = 4;//29.97 
		}
		else if( m_extcapParams.scaler.fpsSDP == SCALE_FPS_15 )
		{
			video_out_frate = 9;//15 
		}
		set_param(pParam, "VideoOutputFrameRate", video_out_frate);
		break;

	case TMDL_HDMITX_VFMT_21_720x576i_50Hz:
	case TMDL_HDMITX_VFMT_22_720x576i_50Hz:
	case TMDL_HDMITX_VFMT_25_720x576i_50Hz:
	case TMDL_HDMITX_VFMT_26_720x576i_50Hz:
		//DbgLogWarn(("CHapi::get_scaler_defaults() No support for 720x576i_50Hz hdmi_fmt=%d\n", hdmi_fmt));
		disp_horz = 720;
		disp_vert = 576;
		if( m_extcapParams.scaler.resSDI == SCALE_RES_720x480 )
		{
			disp_horz = 720;// output horz resolution
			disp_vert = 480;// output vert resolution
		}
		else if( m_extcapParams.scaler.resSDI == SCALE_RES_640x480 )
		{
			disp_horz = 640;// output horz resolution
			disp_vert = 480;// output vert resolution
		}
		else if( m_extcapParams.scaler.resSDI == SCALE_RES_640x360 )
		{
			disp_horz = 640;// output horz resolution
			disp_vert = 360;// output vert resolution
		}
		else if( m_extcapParams.scaler.resSDI == SCALE_RES_480x360 )
		{
			disp_horz = 480;// output horz resolution
			disp_vert = 360;// output vert resolution
		}
		else if( m_extcapParams.scaler.resSDI == SCALE_RES_480x270 )
		{
			disp_horz = 480;// output horz resolution
			disp_vert = 272;// output vert resolution
		}
		set_param(pParam, "VideoOutputWidth", disp_horz);
		set_param(pParam, "VideoOutputHeight", disp_vert);

		video_out_frate = 3;//25
		if( m_extcapParams.scaler.fpsSDI == SCALE_FPS_25 )
		{
			video_out_frate = 3;//25 
		}
		set_param(pParam, "VideoOutputFrameRate", video_out_frate);
		break;

	case TMDL_HDMITX_VFMT_06_720x480i_60Hz:
	case TMDL_HDMITX_VFMT_07_720x480i_60Hz:
	case TMDL_HDMITX_VFMT_10_720x480i_60Hz:
	case TMDL_HDMITX_VFMT_11_720x480i_60Hz:
		disp_horz = 720;
		disp_vert = 480;
		if( m_extcapParams.scaler.resSDI == SCALE_RES_720x480 )
		{
			disp_horz = 720;// output horz resolution
			disp_vert = 480;// output vert resolution
		}
		else if( m_extcapParams.scaler.resSDI == SCALE_RES_640x480 )
		{
			disp_horz = 640;// output horz resolution
			disp_vert = 480;// output vert resolution
		}
		else if( m_extcapParams.scaler.resSDI == SCALE_RES_640x360 )
		{
			disp_horz = 640;// output horz resolution
			disp_vert = 360;// output vert resolution
		}
		else if( m_extcapParams.scaler.resSDI == SCALE_RES_480x360 )
		{
			disp_horz = 480;// output horz resolution
			disp_vert = 360;// output vert resolution
		}
		else if( m_extcapParams.scaler.resSDI == SCALE_RES_480x270 )
		{
			disp_horz = 480;// output horz resolution
			disp_vert = 272;// output vert resolution
		}
		set_param(pParam, "VideoOutputWidth", disp_horz);
		set_param(pParam, "VideoOutputHeight", disp_vert);

		video_out_frate = 4;//29.97
		if( m_extcapParams.scaler.fpsSDI == SCALE_FPS_30 )
		{
			video_out_frate = 4;//29.97 
		}
		else if( m_extcapParams.scaler.fpsSDI == SCALE_FPS_15 )
		{
			video_out_frate = 9;//15 
		}
		set_param(pParam, "VideoOutputFrameRate", video_out_frate);
		break;

	case TMDL_HDMITX_VFMT_17_720x576p_50Hz:
	case TMDL_HDMITX_VFMT_18_720x576p_50Hz:
		//DbgLogWarn(("CHapi::get_scaler_defaults() No support for 720x576p_50Hz hdmi_fmt=%d\n", hdmi_fmt));
		disp_horz = 720;
		disp_vert = 576;
		if( m_extcapParams.scaler.resSDP == SCALE_RES_720x480 )
		{
			disp_horz = 720;// output horz resolution
			disp_vert = 480;// output vert resolution
		}
		else if( m_extcapParams.scaler.resSDP == SCALE_RES_640x480 )
		{
			disp_horz = 640;// output horz resolution
			disp_vert = 480;// output vert resolution
		}
		else if( m_extcapParams.scaler.resSDP == SCALE_RES_640x360 )
		{
			disp_horz = 640;// output horz resolution
			disp_vert = 360;// output vert resolution
		}
		else if( m_extcapParams.scaler.resSDP == SCALE_RES_480x360 )
		{
			disp_horz = 480;// output horz resolution
			disp_vert = 360;// output vert resolution
		}
		else if( m_extcapParams.scaler.resSDP == SCALE_RES_480x270 )
		{
			disp_horz = 480;// output horz resolution
			disp_vert = 272;// output vert resolution
		}
		set_param(pParam, "VideoOutputWidth", disp_horz);
		set_param(pParam, "VideoOutputHeight", disp_vert);

		video_out_frate = 6;//50
		if( m_extcapParams.scaler.fps720P == SCALE_FPS_25 )
		{
			video_out_frate = 3;//25 
		}
		set_param(pParam, "VideoOutputFrameRate", video_out_frate);
		break;
	
	case TMDL_HDMITX_VFMT_02_720x480p_60Hz:
	case TMDL_HDMITX_VFMT_03_720x480p_60Hz:
		disp_horz = 720;
		disp_vert = 480;
		if( m_extcapParams.scaler.resSDP == SCALE_RES_720x480 )
		{
			disp_horz = 720;// output horz resolution
			disp_vert = 480;// output vert resolution
		}
		else if( m_extcapParams.scaler.resSDP == SCALE_RES_640x480 )
		{
			disp_horz = 640;// output horz resolution
			disp_vert = 480;// output vert resolution
		}
		else if( m_extcapParams.scaler.resSDP == SCALE_RES_640x360 )
		{
			disp_horz = 640;// output horz resolution
			disp_vert = 360;// output vert resolution
		}
		else if( m_extcapParams.scaler.resSDP == SCALE_RES_480x360 )
		{
			disp_horz = 480;// output horz resolution
			disp_vert = 360;// output vert resolution
		}
		else if( m_extcapParams.scaler.resSDP == SCALE_RES_480x270 )
		{
			disp_horz = 480;// output horz resolution
			disp_vert = 272;// output vert resolution
		}
		set_param(pParam, "VideoOutputWidth", disp_horz);
		set_param(pParam, "VideoOutputHeight", disp_vert);

		video_out_frate = 7;//59.94
		if( m_extcapParams.scaler.fpsSDP == SCALE_FPS_30 )
		{
			video_out_frate = 4;//29.97 
		}
		else if( m_extcapParams.scaler.fpsSDP == SCALE_FPS_15 )
		{
			video_out_frate = 9;//15 
		}
		set_param(pParam, "VideoOutputFrameRate", video_out_frate);
		break;

	case TMDL_HDMITX_VFMT_19_1280x720p_50Hz:
		disp_horz = 1280;
		disp_vert = 720;
		if( m_extcapParams.scaler.res720P == SCALE_RES_720x480 )
		{
			disp_horz = 720;// output horz resolution
			disp_vert = 480;// output vert resolution
		}
		else if( m_extcapParams.scaler.res720P == SCALE_RES_640x480 )
		{
			disp_horz = 640;// output horz resolution
			disp_vert = 480;// output vert resolution
		}
		else if( m_extcapParams.scaler.res720P == SCALE_RES_640x360 )
		{
			disp_horz = 640;// output horz resolution
			disp_vert = 360;// output vert resolution
		}
		else if( m_extcapParams.scaler.res720P == SCALE_RES_480x360 )
		{
			disp_horz = 480;// output horz resolution
			disp_vert = 360;// output vert resolution
		}
		else if( m_extcapParams.scaler.res720P == SCALE_RES_480x270 )
		{
			disp_horz = 480;// output horz resolution
			disp_vert = 272;// output vert resolution
		}
		set_param(pParam, "VideoOutputWidth", disp_horz);
		set_param(pParam, "VideoOutputHeight", disp_vert);

		video_out_frate = 6;//50
		if( m_extcapParams.scaler.fps720P == SCALE_FPS_25 )
		{
			video_out_frate = 3;//25 
		}
		set_param(pParam, "VideoOutputFrameRate", video_out_frate);
		break;

	case TMDL_HDMITX_VFMT_60_1280x720p_24Hz:
	case TMDL_HDMITX_VFMT_61_1280x720p_25Hz:
		disp_horz = 1280;
		disp_vert = 720;
		if( m_extcapParams.scaler.res720P == SCALE_RES_720x480 )
		{
			disp_horz = 720;// output horz resolution
			disp_vert = 480;// output vert resolution
		}
		else if( m_extcapParams.scaler.res720P == SCALE_RES_640x480 )
		{
			disp_horz = 640;// output horz resolution
			disp_vert = 480;// output vert resolution
		}
		else if( m_extcapParams.scaler.res720P == SCALE_RES_640x360 )
		{
			disp_horz = 640;// output horz resolution
			disp_vert = 360;// output vert resolution
		}
		else if( m_extcapParams.scaler.res720P == SCALE_RES_480x360 )
		{
			disp_horz = 480;// output horz resolution
			disp_vert = 360;// output vert resolution
		}
		else if( m_extcapParams.scaler.res720P == SCALE_RES_480x270 )
		{
			disp_horz = 480;// output horz resolution
			disp_vert = 272;// output vert resolution
		}
		set_param(pParam, "VideoOutputWidth", disp_horz);
		set_param(pParam, "VideoOutputHeight", disp_vert);

		video_out_frate = 2;//24
		if(hdmi_fmt == TMDL_HDMITX_VFMT_61_1280x720p_25Hz)
		{
			video_out_frate = 3;//25
		}
		set_param(pParam, "VideoOutputFrameRate", video_out_frate);
		break;

	case TMDL_HDMITX_VFMT_62_1280x720p_30Hz:
	case TMDL_HDMITX_VFMT_04_1280x720p_60Hz:
		disp_horz = 1280;
		disp_vert = 720;
		if( m_extcapParams.scaler.res720P == SCALE_RES_720x480 )
		{
			disp_horz = 720;// output horz resolution
			disp_vert = 480;// output vert resolution
		}
		else if( m_extcapParams.scaler.res720P == SCALE_RES_640x480 )
		{
			disp_horz = 640;// output horz resolution
			disp_vert = 480;// output vert resolution
		}
		else if( m_extcapParams.scaler.res720P == SCALE_RES_640x360 )
		{
			disp_horz = 640;// output horz resolution
			disp_vert = 360;// output vert resolution
		}
		else if( m_extcapParams.scaler.res720P == SCALE_RES_480x360 )
		{
			disp_horz = 480;// output horz resolution
			disp_vert = 360;// output vert resolution
		}
		else if( m_extcapParams.scaler.res720P == SCALE_RES_480x270 )
		{
			disp_horz = 480;// output horz resolution
			disp_vert = 272;// output vert resolution
		}
		set_param(pParam, "VideoOutputWidth", disp_horz);
		set_param(pParam, "VideoOutputHeight", disp_vert);

		video_out_frate = 7;//59.94
		if(hdmi_fmt == TMDL_HDMITX_VFMT_62_1280x720p_30Hz)
		{
			video_out_frate = 4;//29.97
		}
		if( m_extcapParams.scaler.fps720P == SCALE_FPS_30 )
		{
			video_out_frate = 4;//29.97 
		}
		else if( m_extcapParams.scaler.fps720P == SCALE_FPS_15 )
		{
			video_out_frate = 9;//15 
		}
		set_param(pParam, "VideoOutputFrameRate", video_out_frate);
		break;

	case TMDL_HDMITX_VFMT_20_1920x1080i_50Hz:
	case TMDL_HDMITX_VFMT_05_1920x1080i_60Hz:
		disp_horz = 1920;
		disp_vert = 1080;
		if( m_extcapParams.scaler.res1080I == SCALE_RES_960x540 )
		{
			disp_horz = 960;// output horz resolution
			disp_vert = 540;// output vert resolution
		}
		else if( m_extcapParams.scaler.res1080I == SCALE_RES_720x480 )
		{
			disp_horz = 720;// output horz resolution
			disp_vert = 480;// output vert resolution
		}
		else if( m_extcapParams.scaler.res1080I == SCALE_RES_640x480 )
		{
			disp_horz = 640;// output horz resolution
			disp_vert = 480;// output vert resolution
		}
		else if( m_extcapParams.scaler.res1080I == SCALE_RES_640x360 )
		{
			disp_horz = 640;// output horz resolution
			disp_vert = 360;// output vert resolution
		}
		else if( m_extcapParams.scaler.res1080I == SCALE_RES_480x360 )
		{
			disp_horz = 480;// output horz resolution
			disp_vert = 360;// output vert resolution
		}
		else if( m_extcapParams.scaler.res1080I == SCALE_RES_480x270 )
		{
			disp_horz = 480;// output horz resolution
			disp_vert = 272;// output vert resolution
		}
		set_param(pParam, "VideoOutputWidth", disp_horz);
		set_param(pParam, "VideoOutputHeight", disp_vert);

		video_out_frate = 4;//29.97
		progressive_ok = 0;
		if(hdmi_fmt == TMDL_HDMITX_VFMT_20_1920x1080i_50Hz)
		{
			video_out_frate = 3;//25
			if( m_extcapParams.scaler.fps1080I == SCALE_FPS_25 )
			{
				video_out_frate = 3;//25
				progressive_ok = 1;
			}
		} else {
			if( m_extcapParams.scaler.fps1080I == SCALE_FPS_30 )
			{
				video_out_frate = 4;//29.97 
				progressive_ok = 1;
			}
			else if( m_extcapParams.scaler.fps1080I == SCALE_FPS_15 )
			{
				video_out_frate = 9;//15
				progressive_ok = 1;
			}
		}
		set_param(pParam, "VideoOutputFrameRate", video_out_frate);
		if((disp_vert <= 540) && progressive_ok){
			set_param(pParam, "VideoOutputMode", 1); //FGR - we have lines<=540 and FPS<=30, so set progressive output
			set_param(pParam, "VideoCodingMode", 0); //0-Frame, 1-Field
		}
		break;

	case TMDL_HDMITX_VFMT_32_1920x1080p_24Hz:
	case TMDL_HDMITX_VFMT_33_1920x1080p_25Hz:
	case TMDL_HDMITX_VFMT_34_1920x1080p_30Hz:
	case TMDL_HDMITX_VFMT_31_1920x1080p_50Hz:
	case TMDL_HDMITX_VFMT_16_1920x1080p_60Hz:
		disp_horz = 1920;
		disp_vert = 1080;

		if( m_extcapParams.scaler.res1080P == SCALE_RES_1280x720 )
		{
			disp_horz = 1280;// output horz resolution
			disp_vert = 720;// output vert resolution
		}
		else if( m_extcapParams.scaler.res1080P == SCALE_RES_960x540 )
		{
			disp_horz = 960;// output horz resolution
			disp_vert = 540;// output vert resolution
		}
		else if( m_extcapParams.scaler.res1080P == SCALE_RES_720x480 )
		{
			disp_horz = 720;// output horz resolution
			disp_vert = 480;// output vert resolution
		}
		else if( m_extcapParams.scaler.res1080P == SCALE_RES_640x480 )
		{
			disp_horz = 640;// output horz resolution
			disp_vert = 480;// output vert resolution
		}
		else if( m_extcapParams.scaler.res1080P == SCALE_RES_640x360 )
		{
			disp_horz = 640;// output horz resolution
			disp_vert = 360;// output vert resolution
		}
		else if( m_extcapParams.scaler.res1080P == SCALE_RES_480x360 )
		{
			disp_horz = 480;// output horz resolution
			disp_vert = 360;// output vert resolution
		}
		else if( m_extcapParams.scaler.res1080P == SCALE_RES_480x270 )
		{
			disp_horz = 480;// output horz resolution
			disp_vert = 272;// output vert resolution
		}
		set_param(pParam, "VideoOutputWidth", disp_horz);
		set_param(pParam, "VideoOutputHeight", disp_vert);

		video_out_frate = 4;//29.97 FIX - 1080P60 is always output at half rate (or less)
		if(hdmi_fmt == TMDL_HDMITX_VFMT_31_1920x1080p_50Hz)
		{
			video_out_frate = 3;//25 FIX - 1080P50 is always output at half rate (or less)
			if( m_extcapParams.scaler.fps1080P == SCALE_FPS_25 )
			{
				video_out_frate = 3;//25 
			}
		}
		else if(hdmi_fmt == TMDL_HDMITX_VFMT_32_1920x1080p_24Hz)
		{
			video_out_frate = 2;//24
		}
		else if(hdmi_fmt == TMDL_HDMITX_VFMT_33_1920x1080p_25Hz)
		{
			video_out_frate = 3;//25
		}
		else if(hdmi_fmt == TMDL_HDMITX_VFMT_34_1920x1080p_30Hz)
		{
			video_out_frate = 4;//29.97
			if( m_extcapParams.scaler.fps1080P == SCALE_FPS_15 )
			{
				video_out_frate = 9;//15
			}
		}
		else { //TMDL_HDMITX_VFMT_16_1920x1080p_60Hz
			if( m_extcapParams.scaler.fps1080P == SCALE_FPS_30 )
			{
				video_out_frate = 4;//29.97 
			}
			else if( m_extcapParams.scaler.fps1080P == SCALE_FPS_15 )
			{
				video_out_frate = 9;//15 
			}
		}
		set_param(pParam, "VideoOutputFrameRate", video_out_frate);
		break;

	default:
		DbgLogWarn(("CHapi::get_scaler_defaults() No support for hdmi_fmt=%d\n", hdmi_fmt));
	case TMDL_HDMITX_VFMT_NULL:
		break;
	}
	return 1;
}


//FGR - See if we want to do a Logo Insertion, and if we have the proper data
Uint32 CHapi::get_logo_data(HAPI_SET_PARAM *pParam)
{
	lock();
	if(!_API_ok){
		DbgLogWarn(("get_logo_data() _API_ok==false!!\n"));
		unlock();
		return 0;
	}
	if(gHapi == NULL){
		DbgLogError(("get_logo_data() gHapi==NULL!!\n"));
		unlock();
		return 0;
	}
	if(pParam == NULL){
		DbgLogWarn(("get_logo_data(NULL)!!\n"));
		unlock();
		return 0;
	}
	DbgLogInfo(("get_logo_data(%p), output=%ux%u _logoUsed=%d\n",
		pParam,
		pParam->params.encodeParam.VideoParams.VideoOutputWidth,
		pParam->params.encodeParam.VideoParams.VideoOutputHeight,
		_logo_used));
	
    Int32 savLogo_x_pos = _logo_x_pos;
	Uint64 savModTime = _logo_mod_time;
	_logo_mod_time = read_logo_data();

	if(_logo_mod_time == 0){//no logo found
		//if we have ever had a logo, replace with 1x1 placeholder
		if(_logo_used){
//			hapiErr = HAPI_LogoOnOff(gHapi, 0, 0, 0); //disable logo index=0
			reset_logo_data();
		} else {
			//no previous logo, just return
		//	DbgLogInfo(("get_logo_data(%p) _logo_mod_time==0\n"));
			unlock();
			return 0;
		}
	}
	if( (_logo.width > pParam->params.encodeParam.VideoParams.VideoOutputWidth)
	 || (_logo.height> pParam->params.encodeParam.VideoParams.VideoOutputHeight)){
		DbgLogWarn(("get_logo_data() logo(%u,%u) exceeds VideoOutput size(%u,%u)\n",
			_logo.width, _logo.height,
			pParam->params.encodeParam.VideoParams.VideoOutputWidth,
			pParam->params.encodeParam.VideoParams.VideoOutputHeight));
		reset_logo_data();
	}
	Int32  x_pos;
	Int32  y_pos;

	x_pos = _logo.x;
	if(x_pos < 0){
		x_pos = pParam->params.encodeParam.VideoParams.VideoOutputWidth + x_pos;
	}
	if(x_pos < 0){
		DbgLogWarn(("get_logo_data() logo(%d,%d) x-origin is bad\n", _logo.x, _logo.y));
		reset_logo_data();
		x_pos = 0;
	}
	if((x_pos + _logo.width) > pParam->params.encodeParam.VideoParams.VideoOutputWidth){
		DbgLogWarn(("get_logo_data() logo(%d,%d) x-origin is bad\n", _logo.x, _logo.y));
		reset_logo_data();
		x_pos = 0;
	}

	y_pos = _logo.y;
	if(y_pos < 0){
		y_pos = pParam->params.encodeParam.VideoParams.VideoOutputHeight + y_pos;
	}
	if(y_pos < 0){
		DbgLogWarn(("get_logo_data() logo(%d,%d) y-origin is bad\n", _logo.x, _logo.y));
		reset_logo_data();
		y_pos = 0;
	}
	if((y_pos + _logo.height) > pParam->params.encodeParam.VideoParams.VideoOutputHeight){
		DbgLogWarn(("get_logo_data() logo(%d,%d) y-origin is bad\n", _logo.x, _logo.y));
		reset_logo_data();
		y_pos = 0;
	}
	if(_logo_mod_time == savModTime){
		//make sure the previous logo does not need to move
		if(_logo_x_pos == x_pos && _logo_y_pos == y_pos){
			DbgLogInfo(("get_logo_data() SKIPPING time=%llu x_pos=%d y_pos=%d\n",
				_logo_mod_time, x_pos, y_pos));

#if 0 //FGR - BUGBUG - it's not only disabled on stop; it's forgotten, so this is not enough;
	  //  we have to fully reload, sigh ...
			hapiErr = HAPI_LogoOnOff(gHapi, 0, 0, 1); //re-enable logo index=0
			if(hapiErr != HAPI_SUCCESS){
				DbgLogWarn(("get_logo_data() HAPI_LogoOnOff(, 1) failed\n"));
				unlock();
				return 0;
			}
#endif
			unlock();
			return 1;
		}
		DbgLogInfo(("get_logo_data() MOVING x_pos=%d->%d y_pos=%d->%d\n",
			_logo_x_pos, x_pos, _logo_y_pos, y_pos));
	}
	if(savLogo_x_pos != -1){
		hapiErr = HAPI_LogoOnOff(gHapi, 0, 0, 0); //disable logo index=0
		if(hapiErr != HAPI_SUCCESS){
			DbgLogWarn(("get_logo_data() HAPI_LogoOnOff(, 0) failed\n"));
			unlock();
			return 0;
		}
	}

	HAPI_LOGO_CONFIG_PARAM *hapiLogo;
    hapiLogo = (HAPI_LOGO_CONFIG_PARAM*)MemAllocFromHeap(__FILE__, __LINE__, sizeof(HAPI_LOGO_CONFIG_PARAM));
	if(!hapiLogo){
		unlock();
		return 0;
	}
	hapiLogo->chIndex = 0;
	hapiLogo->logoIndex = 0; //TODO: - we only use Index=0 for now
	hapiLogo->height = _logo.height;
	hapiLogo->width  = _logo.width;
	hapiLogo->x = (Uint32)x_pos;
	hapiLogo->y = (Uint32)y_pos;
	memcpy(&hapiLogo->logoData[0], &_logo.logoData[0], _logo.height*_logo.width*BYTE_PER_PIXEL);

	HapiErrCode myHapiErr = HAPI_LogoConfig(gHapi, hapiLogo);
	MemFree2Heap(__FILE__, __LINE__, hapiLogo);
	hapiLogo = NULL;

	if(myHapiErr == HAPI_FAIL){//hard error
		DbgLogWarn(("get_logo_data() HAPI_LogoConfig() failed\n"));
		hapiErr = myHapiErr;
		_API_ok = false; //FGR - BUGBUG - we are assuming the Magnum interface hung
		unlock();
		return 0;
	}
	if(myHapiErr != HAPI_SUCCESS){//param or other soft error
		DbgLogWarn(("get_logo_data() HAPI_LogoConfig() returned 0x%x\n", myHapiErr));
		unlock();
		return 0;
	}
	_logo_used = 1;

	hapiErr = HAPI_LogoOnOff(gHapi, 0, 0, 1); //enable logo index=0
	if(hapiErr != HAPI_SUCCESS){
		DbgLogWarn(("get_logo_data() HAPI_LogoOnOff(, 1) failed\n"));
		unlock();
		return 0;
	}
#if DBG//BUGBUG remove me
	DWORD dwHAPI_LogoOnOff_stress = 0;
	hcwGetRegistryDWORD("HAPI_LogoOnOff_stress", &dwHAPI_LogoOnOff_stress);
	if(dwHAPI_LogoOnOff_stress > 30){
		dwHAPI_LogoOnOff_stress = 30;
	}
	while(dwHAPI_LogoOnOff_stress){
		dwHAPI_LogoOnOff_stress--;
		hapiErr = HAPI_LogoOnOff(gHapi, 0, 0, 0); //enable logo index=0
		if(hapiErr != HAPI_SUCCESS){
			DbgLogWarn(("get_logo_data() HAPI_LogoOnOff(, 0) failed\n"));
			unlock();
			return 0;
		}
		hapiErr = HAPI_LogoOnOff(gHapi, 0, 0, 1); //enable logo index=0
		if(hapiErr != HAPI_SUCCESS){
			DbgLogWarn(("get_logo_data() HAPI_LogoOnOff(, 1) failed\n"));
			unlock();
			return 0;
		}
	}
#endif

	_logo_x_pos = x_pos;
	_logo_y_pos = y_pos;
	
	DbgLogInfo(("get_logo_data() time=%llu save x_pos=%d y_pos=%d\n",
				_logo_mod_time, _logo_x_pos, _logo_y_pos));
	unlock();
	return 1;
}

void CHapi::reset_logo_data()
{
	//initialize _logo as a 1x1 transparent logo
	memset((void *)&_logo, 0, sizeof(_logo));
	_logo.height=1;
	_logo.width=1;
	_logo_x_pos = -1;
	_logo_y_pos = -1;
}

Uint64 CHapi::read_logo_data()
{
#ifdef OLD_DRIVER
	//FGR - should we allow this?
	DWORD dwEnableLogoData = 1;
	hcwGetRegistryDWORD("EnableLogoData", &dwEnableLogoData);
	if(dwEnableLogoData == 0){
		return 0; //Logo not enabled
	}
    if(KeGetCurrentIrql() != PASSIVE_LEVEL){
        //Don't attempt file IO at raised IRQL; safety only, should never happen
		DbgLogWarn(("CHapi::read_logo_data() IRQL(%d) != PASSIVE_LEVEL\n", KeGetCurrentIrql()));
		return _logo_mod_time; //just return "no change"
    }
	DbgLogInfo(("CHapi::read_logo_data() Serial=%u\n", _serialNo));
	
	Uint32 fileSize = 0;
	HANDLE inFileHandle = NULL;

	if(_serialNo){
		sprintf(&_logo_name[0], "\\systemroot\\system32\\drivers\\hcwE5logo_%u.bin", _serialNo);
		inFileHandle = prv_open_file(_logo_name, 0, &fileSize);
	}
	if(inFileHandle == NULL){
		inFileHandle = prv_open_file("\\systemroot\\system32\\drivers\\hcwE5logo.bin", 0, &fileSize);
		if(inFileHandle == NULL){
			DbgLogInfo(("read_logo_data() no logofile!\n"));
			return 0;
		}
	}
	Uint64 modTime = prv_get_mod_time(inFileHandle);
	if(modTime==0 || modTime == _logo_mod_time){
		//nothing to do, logo data has not changed
		prv_close_file(inFileHandle);
		return modTime;
	}

	DbgLogInfo(("read_logo_data() input file is %u bytes long\n", fileSize));
	if(fileSize < 24 || fileSize > sizeof(HCW_LOGO_CONFIG_PARAM)){
		DbgLogWarn(("read_logo_data() file size %u is unreasonable[24,%u)\n", fileSize, sizeof(HCW_LOGO_CONFIG_PARAM)));
		prv_close_file(inFileHandle);
		return 0;
	}
		
	ULONG_PTR readLen = prv_read_file(inFileHandle, (BYTE*)&_logo, fileSize);
	prv_close_file(inFileHandle);
	
	if(readLen != fileSize){
		DbgLogWarn(("read_logo_data() logo file too small, wanted 0x%x got %p\n", fileSize, readLen));
		return 0;
	}

	if(_logo.magic != 'HCW1'){
		DbgLogWarn(("read_logo_data() the magic just isn't there(0x%x)\n", _logo.magic));
		return 0;
	}
	if((_logo.width>MAX_LOGO_WIDTH) || (_logo.height>MAX_LOGO_HEIGHT)){
		DbgLogWarn(("read_logo_data() logo(%u,%u) too big\n", _logo.width, _logo.height));
		return 0;
	}
	if((_logo.width*_logo.height>MAX_LOGO_SIZE)){
		DbgLogWarn(("read_logo_data() logo(%u,%u) too many pixels(%u>%u)\n",
			_logo.width, _logo.height, _logo.width*_logo.height, MAX_LOGO_SIZE));
		return 0;
	}
	
	return modTime;
#else
	return 0;
#endif
}

Uint32 CHapi::cvt_OUTPUT_FRAME_RATE(HAPI_VIDEO_OUTPUT_FRAME_RATE value)
{
	switch(value){
	case HAPI_VIDEO_OUTPUT_FRAME_RATE_INVALID:return    0;
	case HAPI_VIDEO_OUTPUT_FRAME_RATE_1:      return  100;
	case HAPI_VIDEO_OUTPUT_FRAME_RATE_4:      return  400;
	case HAPI_VIDEO_OUTPUT_FRAME_RATE_6:      return  600;
	case HAPI_VIDEO_OUTPUT_FRAME_RATE_8:      return  800;
	case HAPI_VIDEO_OUTPUT_FRAME_RATE_10:     return 1000;
	case HAPI_VIDEO_OUTPUT_FRAME_RATE_12:     return 1200;
	case HAPI_VIDEO_OUTPUT_FRAME_RATE_12_5:   return 1250;	
	case HAPI_VIDEO_OUTPUT_FRAME_RATE_15:     return 1500;
	case HAPI_VIDEO_OUTPUT_FRAME_RATE_23_98:  return 2398;
	case HAPI_VIDEO_OUTPUT_FRAME_RATE_24:     return 2400;
	case HAPI_VIDEO_OUTPUT_FRAME_RATE_25:     return 2500;
	case HAPI_VIDEO_OUTPUT_FRAME_RATE_29_97:  return 2997;
	case HAPI_VIDEO_OUTPUT_FRAME_RATE_30:     return 3000;
	case HAPI_VIDEO_OUTPUT_FRAME_RATE_50:     return 5000;
	case HAPI_VIDEO_OUTPUT_FRAME_RATE_59_94:  return 5994;
	case HAPI_VIDEO_OUTPUT_FRAME_RATE_60:     return 6000;
	}
	return 0;
}

Uint32 CHapi::cvt_AUDIO_SAMPLE_RATE(HAPI_AUDIO_SAMPLE_RATE value)
{
	switch(value){
	case HAPI_AUDIO_SAMPLE_RATE_NONE:     return      0;
	case HAPI_AUDIO_SAMPLE_RATE_16_KHZ:   return  16000;
	case HAPI_AUDIO_SAMPLE_RATE_32_KHZ:   return  32000;
	case HAPI_AUDIO_SAMPLE_RATE_44_1_KHZ: return  44100;
	case HAPI_AUDIO_SAMPLE_RATE_48_KHZ:   return  48000;
	case HAPI_AUDIO_SAMPLE_RATE_96_KHZ:   return  96000;
	case HAPI_AUDIO_SAMPLE_RATE_192_KHZ:  return 192000;
	case HAPI_AUDIO_SAMPLE_RATE_FOLLOW_INPUT: return 0xFFFFFFFF;
	}
	return 0;
}
    
Uint32 CHapi::cvt_AUDIO_BITRATE(HAPI_AUDIO_BITRATE value)
{
	switch(value){
	case HAPI_AUDIO_BITRATE_NONE:      return       0;
	case HAPI_AUDIO_BITRATE_8_KBPS:    return    8000;
	case HAPI_AUDIO_BITRATE_16_KBPS:   return   16000;
	case HAPI_AUDIO_BITRATE_32_KBPS:   return   32000;
	case HAPI_AUDIO_BITRATE_48_KBPS:   return   48000;
	case HAPI_AUDIO_BITRATE_56_KBPS:   return   56000;
	case HAPI_AUDIO_BITRATE_64_KBPS:   return   64000;
	case HAPI_AUDIO_BITRATE_80_KBPS:   return   80000;
	case HAPI_AUDIO_BITRATE_96_KBPS:   return   96000;
	case HAPI_AUDIO_BITRATE_112_KBPS:  return  112000;
	case HAPI_AUDIO_BITRATE_128_KBPS:  return  128000;
	case HAPI_AUDIO_BITRATE_160_KBPS:  return  160000;
	case HAPI_AUDIO_BITRATE_192_KBPS:  return  192000;
	case HAPI_AUDIO_BITRATE_224_KBPS:  return  224000;
	case HAPI_AUDIO_BITRATE_256_KBPS:  return  256000;
	case HAPI_AUDIO_BITRATE_320_KBPS:  return  320000;
	case HAPI_AUDIO_BITRATE_384_KBPS:  return  384000;
	case HAPI_AUDIO_BITRATE_448_KBPS:  return  448000;
	case HAPI_AUDIO_BITRATE_576_KBPS:  return  576000;
	case HAPI_AUDIO_BITRATE_640_KBPS:  return  640000;
	case HAPI_AUDIO_BITRATE_768_KBPS:  return  768000;
	case HAPI_AUDIO_BITRATE_960_KBPS:  return  960000;
	case HAPI_AUDIO_BITRATE_1024_KBPS: return 1024000;
	case HAPI_AUDIO_BITRATE_1152_KBPS: return 1152000;
	case HAPI_AUDIO_BITRATE_1280_KBPS: return 1280000;
	case HAPI_AUDIO_BITRATE_1344_KBPS: return 1344000;
	case HAPI_AUDIO_BITRATE_1408_KBPS: return 1408000;
	case HAPI_AUDIO_BITRATE_1411_KBPS: return 1411000;
	case HAPI_AUDIO_BITRATE_1472_KBPS: return 1472000;
	case HAPI_AUDIO_BITRATE_1536_KBPS: return 1536000;
	}
	return 0;
}


Uint32 CHapi::HapiGetEncStatus(pEncStatus pStatus)
{
	if(pStatus == NULL){
		DbgLogError(("CHapi::HapiGetEncStatus(pStatus==NULL)\n"));
		return 0;
    }
	lock();
	DbgLogInfo(("CHapi::HapiGetEncStatus(%p)\n", pStatus));

#ifdef HAPI_POWER_THREAD
	pStatus->power_time_left = _power_time_left;
#else
	pStatus->power_time_left = 0;
#endif

	bool isReady = false;
	isReady = (hapiErr == HAPI_SUCCESS) && _API_ok && !p_mchip->hadUsbError("CHapi::HapiGetEncStatus()");
	pStatus->isReady = isReady;

	pStatus->isStarted = _isStarted;
	pStatus->isPaused  = _isPaused;
	
	pStatus->bling_options = _bling_options;
	pStatus->LED_state     = _LED_state; //NOTE need Device::getLEDState(3) to get bit 0x08 status

	pStatus->last_PCR = _last_PCR;
	
	DWORD stalled_time = wrapGetTicks_ms() - _last_payload_time;
	if(stalled_time > _last_payload_delta){
		pStatus->payload_delta = stalled_time;
	} else {
		pStatus->payload_delta = _last_payload_delta;
	}
	pStatus->start_latency = _first_payload_delta;

	pStatus->hdmi_fmt = _hdmi_fmt;

	pStatus->cvbs_svid_detect = 0; //0=HW can't detect cable; 1=YPrPb or no cable, 2=CVBS/SVideo cable
						//must be filled in after calling this routine if suported in HW

	pStatus->logo_x_pos = _logo_x_pos;//-1 means no current logo
	pStatus->logo_y_pos = _logo_y_pos;
	pStatus->logo_width = _logo.width; 
	pStatus->logo_height= _logo.height;

//	HAPI_SET_PARAM         _lastParam;
	pStatus->AR = (ENC_ASPECT_RATIO)_lastAR;

	pStatus->VideoWidth  = _lastParam.params.encodeParam.VideoParams.VideoOutputWidth;
	pStatus->VideoHeight = _lastParam.params.encodeParam.VideoParams.VideoOutputHeight;
	pStatus->VideoMode   = _lastParam.params.encodeParam.VideoParams.VideoOutputMode;//0=Interlaced, 1=Progressive, 2=PSF
	pStatus->VideoFrameRate = cvt_OUTPUT_FRAME_RATE(_lastParam.params.encodeParam.VideoParams.VideoOutputFrameRate);//eg. 30fps = 3000, 29.97 = 2997
    
	pStatus->VideoBitrate  = _lastParam.params.encodeParam.VideoParams.VideoOutputBitrate;
	pStatus->RateControl   = _lastParam.params.encodeParam.VideoParams.RateControl;//0=CBR, 1=VBR
	pStatus->VBRMin = _lastParam.params.encodeParam.VideoParams.VBRMin;
	pStatus->VBRMax = _lastParam.params.encodeParam.VideoParams.VBRMax;

	pStatus->CodingMode  = _lastParam.params.encodeParam.VideoParams.CodingMode;//0=Frame, 1=Field, 2=MBAFF, 3=PAFF
	pStatus->Profile     = _lastParam.params.encodeParam.VideoParams.Profile;//0=Base, 3=Main, 4=High
	pStatus->Level       = _lastParam.params.encodeParam.VideoParams.Level;//eg 400 for 4.00
	pStatus->Latency     = _lastParam.params.encodeParam.VideoParams.Latency;//0=LOW, 1=HIGH, 2=MEDIUM
	pStatus->CabacCoding = _lastParam.params.encodeParam.VideoParams.bCabacCoding;//0=CAVLC, 1=CABAC
	pStatus->DeblockFilter = _lastParam.params.encodeParam.VideoParams.bDeblockFilter;//0=Off, 1=On
	pStatus->NumBFrames  = _lastParam.params.encodeParam.VideoParams.NumBFrames;	//Range[0,7]

	pStatus->AudioStreamID = _lastParam.params.encodeParam.AudioParams.StreamID; // Audio elementary stream ID
	pStatus->AudioFormat   = _lastParam.params.encodeParam.AudioParams.AudioCodecOutputFormat; //2=AC3, 3=AAC
	pStatus->AudioMode     = _lastParam.params.encodeParam.AudioParams.AudioOutputMode;//Stereo=1, Mono=2
	pStatus->AudioSampleRate = cvt_AUDIO_SAMPLE_RATE(_lastParam.params.encodeParam.AudioParams.AudioOutputSamplingRate);//eg 48000 or 44100
	if(pStatus->AudioSampleRate == 0xFFFFFFFF){//output follows input
		pStatus->AudioSampleRate = cvt_AUDIO_SAMPLE_RATE(_lastParam.params.encodeParam.AudioParams.AudioCapSampleRate);
	}
	pStatus->AudioBitrate  = cvt_AUDIO_BITRATE(_lastParam.params.encodeParam.AudioParams.AudioOutputBitrate);//eg 192000
	pStatus->AudioPassthru = _lastParam.params.encodeParam.AudioParams.bAudioPassthru; //1=audio is passthrough; 0=audio is encoded
	pStatus->AGCEnable     = _lastParam.params.encodeParam.AudioParams.bAGCEnable; // 0=disable Audio ouput AGC; 1=Enable AGC

	unlock();
	return 1;
}
