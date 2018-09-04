//=============================================================================
//  File Name: HapiMsg.h
//
//  Copyright 2009 Magnum Semiconductor Inc. All rights reserved.
//
//  Description:
//      HAPI message definitions.
//
//  Modification History:
//      $Id: $
//      $Log: $
//
//=============================================================================

#ifndef HAPI_MSG_H
#define HAPI_MSG_H

#include "HapiCommon.h"

/**
 * \ref HAPI media engine
 */

#define HAPI_MSG_TAG                    (0xabcd)
#define HAPI_RESPONSE_CODE_DEFAULT      (-1)
#define HAPI_MSG_VERSION                (0x01)
#define HAPI_MSG_RSV1                (0x00112233)
#define HAPI_MSG_RSV2                (0x44556677)

#define MAX_STREAM_AV_DATA_SIZE          (64*1024*3)

#define HAPI_MSG_COOKIE_START           0x00000000

#define HAPI_FWUPGRADE_MAXPAYLOADSIZE	512

typedef enum
{
    CHWAPI_ME_MEDIA_ENGINE = 0, /*!< Process input data with Sling MEAL engine */
    CHWAPI_HAPI_MEDIA_ENGINE, /*!< Process input data with HAPI engine */
    CHWAPI_MEDIA_ENGINE_RANGE /*!< output pin range. */
} CHWAPI_MEDIA_ENGINE_TYPE;

typedef enum
{
    // Host ->Slave
    HWAPI_MESSAGE_GET_PARAM_REQ = 0, // request from host , no data included
    HWAPI_MESSAGE_SET_PARAM,
    HWAPI_MESSAGE_START,
    HWAPI_MESSAGE_STOP,
    HWAPI_MESSAGE_INIT,
    HWAPI_MESSAGE_EXIT,
    HWAPI_MESSAGE_STREAM_INPUT_DATA,
    HWAPI_MESSAGE_FWUPGRADE,
    HWAPI_MESSAGE_I2C_READ,
    HWAPI_MESSAGE_I2C_WRITE,
    HWAPI_MESSAGE_GPIO_READ,
    HWAPI_MESSAGE_GPIO_WRITE,
    HWAPI_MESSAGE_I2C_SET_CLOCK_FREQ,
    HWAPI_MESSAGE_SET_AVL,
    HWAPI_MESSAGE_I2C_MONITOR_INSTALL,
    HWAPI_MESSAGE_SET_AR,
    HWAPI_MESSAGE_SET_PCR,
    HWAPI_MESSAGE_STATUS_QUERY,
    HWAPI_MESSAGE_LOGO_CONFIG,
    HWAPI_MESSAGE_LOGO_ON_OFF,
    // Slave->Host
    HWAPI_MESSAGE_ERROR,
    HWAPI_MESSAGE_STREAM_DATA_REQ,	// request from slave side, no data included
    HWAPI_MESSAGE_STREAM_OUTPUT_DATA,
    HWAPI_MESSAGE_AV_UPDATE, //FGR - what's this???
    HWAPI_MESSAGE_I2C_OUTPUT_MONITOR_DATA,

    HWAPI_MESSAGE_RANGE	
}HWAPI_MSG_TYPE;

typedef enum _HWAPI_MSG_START_REQ_BM
{
   HWAPI_MSG_BM_START_REQ_INDEX                       =  0x00000001,
   HWAPI_MSG_BM_START_REQ_ENCR_ENABLE                 =  0x00000002,
}HWAPI_MSG_START_REQ_BM;

typedef enum _HWAPI_MSG_FWUPGRADE_REQ_BM
{
	HWAPI_MSG_BM_FWUPGRADE_REQ_INDEX                	=  0x00000001,
   	HWAPI_MSG_BM_FWUPGRADE_REQ_ERROR 					=  0x00000002,
}HWAPI_MSG_FWUPGRADE_REQ_BM;

typedef enum _HWAPI_MSG_START_RSP_BM
{
   HWAPI_MSG_BM_START_RSP_INDEX                       =  0x00000001,
   HWAPI_MSG_BM_START_RSP_ERROR                       =  0x00000002,
}HWAPI_MSG_START_RSP_BM;

/**HWAPI_MSG_STREAM_DATA_REQUEST*/
typedef enum _HWAPI_MSG_STREAM_DATA_REQUEST_BM
{
   HWAPI_BM_MSG_STREAM_DATA_REQUEST_DATA_LENGTH   = 0x00000001
}HWAPI_MSG_STREAM_DATA_REQUEST_BM;

/** HWAPI_MSG_AV_UPDATE_BM*/
typedef enum _HWAPI_MSG_AV_UPDATE_BM
{
   HWAPI_BM_MSG_AV_UPDATE_VID_IN_WIDTH       = 0x00000001,
   HWAPI_BM_MSG_AV_UPDATE_VID_IN_HEIGHT      = 0x00000002,

   HWAPI_BM_MSG_AV_UPDATE_VID_OUT_WIDTH      = 0x00000004,
   HWAPI_BM_MSG_AV_UPDATE_VID_OUT_HEIGHT     = 0x00000008,

   HWAPI_BM_MSG_AV_UPDATE_VID_IN_FPS         = 0x00000010,
   HWAPI_BM_MSG_AV_UPDATE_VID_OUT_FPS        = 0x00000020,
   HWAPI_BM_MSG_AV_UPDATE_VID_IN_BITRATE     = 0x00000040,
   HWAPI_BM_MSG_AV_UPDATE_VID_OUT_BITRATE    = 0x00000080,
   HWAPI_BM_MSG_AV_UPDATE_AUD_IN_SAMPRATE    = 0x00000100,
   HWAPI_BM_MSG_AV_UPDATE_AUD_OUT_SAMPRATE   = 0x00000200,
   HWAPI_BM_MSG_AV_UPDATE_AUD_IN_BITRATE     = 0x00000400,
   HWAPI_BM_MSG_AV_UPDATE_AUD_OUT_BITRATE    = 0x00000800
}HWAPI_MSG_AV_UPDATE_BM;

/** HWAPI_MSG_SET_PARAM_BM*/
typedef enum _HWAPI_MSG_SET_PARAM_BM
{
    HWAPI_BM_MSG_SET_PARAM_INDEX                    = 0x00000001,

    HWAPI_BM_MSG_SET_PARAM_INPUT_AUDIO_PID          = 0x00000002,
    HWAPI_BM_MSG_SET_PARAM_INPUT_VIDEO_PID          = 0x00000004,
    HWAPI_BM_MSG_SET_PARAM_INPUT_PCR_PID            = 0x00000008,
    
    HWAPI_BM_MSG_SET_PARAM_SUBTITLE_PID             = 0x00000010,
    HWAPI_BM_MSG_SET_PARAM_TELETEXT_PID             = 0x00000020,
    HWAPI_BM_MSG_SET_PARAM_PARAM_TYPE               = 0x00000040,

    HWAPI_BM_MSG_SET_PARAM_OUTPUT_PCR_PID           = 0x00000080,

    HWAPI_BM_MSG_SET_PARAM_B_TS_SERIAL              = 0x00000100,
    HWAPI_BM_MSG_SET_PARAM_B_CH_MSB_FIRST           = 0x00000200,
}HWAPI_MSG_SET_PARAM_BM;

typedef enum _HAPI_TRANSCODE_VIDEO_PARAMS_BM
{
    HWAPI_BM_MSG_TRANSCODE_VIDEO_OUTPUT_ENABLE            = 0x00000001,
    HWAPI_BM_MSG_TRANSCODE_VIDEO_CODEC_INPUT_FORMAT       = 0x00000002,
    HWAPI_BM_MSG_TRANSCODE_VIDEO_CODEC_OUTPUT_FORMAT      = 0x00000004,
    HWAPI_BM_MSG_TRANSCODE_VIDEO_OUTPUT_WIDTH             = 0x00000008,
    HWAPI_BM_MSG_TRANSCODE_VIDEO_OUTPUT_HEIGHT            = 0x00000010,
    HWAPI_BM_MSG_TRANSCODE_VIDEO_OUTPUT_MODE              = 0x00000020,
    HWAPI_BM_MSG_TRANSCODE_VIDEO_OUTPUT_FRAME_RATE        = 0x00000040,
    HWAPI_BM_MSG_TRANSCODE_VIDEO_OUTPUT_BITRATE           = 0x00000080,
    HWAPI_BM_MSG_TRANSCODE_RATE_CONTROL                   = 0x00001000,
    HWAPI_BM_MSG_TRANSCODE_CODING_MODE                    = 0x00002000,
    HWAPI_BM_MSG_TRANSCODE_VIDEO_STREAM_ID                = 0x00004000,    
    HWAPI_BM_MSG_TRANSCODE_VIDEO_PID                      = 0x00008000,    
    HWAPI_BM_MSG_TRANSCODE_VBR_MIN                        = 0x00010000,    
    HWAPI_BM_MSG_TRANSCODE_VBR_MAX                        = 0x00020000,    
    HWAPI_BM_MSG_TRANSCODE_PROFILE                        = 0x00040000,    
    HWAPI_BM_MSG_TRANSCODE_LEVEL                          = 0x00080000,
    HWAPI_BM_MSG_TRANSCODE_TS_BITRATE                     = 0x00100000,   
    HWAPI_BM_MSG_TRANSCODE_LATENCY                        = 0x00200000,   
    HWAPI_BM_MSG_TRANSCODE_INSERT_IFRAME                  = 0x00400000,
    HWAPI_BM_MSG_TRANSCODE_CABAC_CODING                   = 0x00800000,
    HWAPI_BM_MSG_TRANSCODE_DEBLOCK_FILTER                 = 0x01000000,
    HWAPI_BM_MSG_TRANSCODE_NUM_BFRAMENUM                  = 0x02000000,
    HWAPI_BM_MSG_TRANSCODE_BIASIDR                        = 0x04000000,
    HWAPI_BM_MSG_TRANSCODE_PMT_VERSION                    = 0x08000000,
    HWAPI_BM_MSG_TRANSCODE_BSMOOTHING                     = 0x10000000,
    HWAPI_BM_MSG_TRANSCODE_HSMOOTHOFF                     = 0x20000000,
    HWAPI_BM_MSG_TRANSCODE_VSMOOTHOFF                     = 0x40000000,
    HWAPI_BM_MSG_TRANSCODE_GOPSIZE                        = 0x80000000,

}HAPI_TRANSCODE_VIDEO_PARAMS_BM;

typedef enum _HAPI_TRANSCODE_AUDIO_PARAMS_BM
{
    HWAPI_BM_MSG_TRANSCODE_AUDIO_OUTPUT_ENABLE            = 0x00000001,
    HWAPI_BM_MSG_TRANSCODE_AUDIO_CODEC_INPUT_FORMAT       = 0x00000002,
    HWAPI_BM_MSG_TRANSCODE_AUDIO_CODEC_OUTPUT_FORMAT      = 0x00000004,
    HWAPI_BM_MSG_TRANSCODE_AUDIO_OUTPUT_MODE              = 0x00000008,
    HWAPI_BM_MSG_TRANSCODE_AUDIO_OUTPUT_SAMP_RATE         = 0x00000010,
    HWAPI_BM_MSG_TRANSCODE_AUDIO_OUTPUT_BITRATE           = 0x00000020,
    HWAPI_BM_MSG_TRANSCODE_AUDIO_TRANSCODE_MODE           = 0x00000040,
    HWAPI_BM_MSG_TRANSCODE_AUDIO_STREAM_ID                = 0x00000080,    
    HWAPI_BM_MSG_TRANSCODE_AUDIO_PID                      = 0x00000100,    
    HWAPI_BM_MSG_TRANSCODE_AUDIO_AGC_ENABLE               = 0x00000200,
    HWAPI_BM_MSG_TRANSCODE_AUDIO_MAXSAMPLE                = 0x00000400,
}HAPI_TRANSCODE_AUDIO_PARAMS_BM;

typedef enum _HAPI_TRANSCODE_SYS_PARAMS_BM
{
    HWAPI_BM_MSG_TRANSCODE_OUTPUT_FILE_FORMAT             = 0x00000001,
    HWAPI_BM_MSG_TRANSCODE_ANC_DATA_TRANS_MODE            = 0x00000002,
    HWAPI_BM_MSG_TRANSCODE_MV_ACCURACY_MODE               = 0x00000004,
    HWAPI_BM_MSG_TRANSCODE_FLOW_TYPE                      = 0x00000008,
}HAPI_TRANSCODE_SYS_PARAMS_BM;

typedef enum _HAPI_TRANSCODE_LOG_PARAMS_BM
{
    HWAPI_BM_MSG_TRANSCODE_ACTIVITY_LOG_ENABLE            = 0x00000001,
    HWAPI_BM_MSG_TRANSCODE_ERROR_LOG_ENABLE               = 0x00000002,
    HWAPI_BM_MSG_TRANSCODE_ERROR_PRINTING_ENABLE          = 0x00000004,
}HAPI_TRANSCODE_LOG_BM;

typedef enum _HAPI_XCODE_PARAM_TYPE_BM
{
    HAPI_BM_XCODE_VIDEO_PARAMS                           = 0x00000001,
    HAPI_BM_XCODE_AUDIO_PARAMS                           = 0x00000002,
    HAPI_BM_XCODE_SYS_PARAMS                             = 0x00000004,
    HAPI_BM_XCODE_LOG_PARAMS                             = 0x00000008,
}HAPI_XCODE_PARAM_TYPE_BM;

typedef enum _HAPI_ENCODE_VIDEO_PARAMS_BM
{
	HWAPI_BM_MSG_ENCODE_VIDEO_STREAM_ID					=0x00000001,
	HWAPI_BM_MSG_ENCODE_VIDEO_OUTPUT_PID				=0x00000002,
  	HWAPI_BM_MSG_ENCODE_VIDEO_CAPTURE_SOURCE 			=0x00000004,
	HWAPI_BM_MSG_ENCODE_VIDEO_CAPTURE_WIDTH		 		=0x00000008,
	HWAPI_BM_MSG_ENCODE_VIDEO_CAPTURE_HEIGHT		 	=0x00000010,
	HWAPI_BM_MSG_ENCODE_VIDEO_CAPTURE_FORMAT		 	=0x00000020,
	HWAPI_BM_MSG_ENCODE_VIDEO_CAPTURE_FRAME_RATE	 	=0x00000040,
	HWAPI_BM_MSG_ENCODE_VIDEO_CODEC_OUTPUT_FORMAT		=0x00000080,
	HWAPI_BM_MSG_ENCODE_VIDEO_OUTPUT_WIDTH				=0x00000100,
	HWAPI_BM_MSG_ENCODE_VIDEO_OUTPUT_HEIGHT				=0x00000200,
	HWAPI_BM_MSG_ENCODE_VIDEO_OUTPUT_MODE				=0x00000400,
	HWAPI_BM_MSG_ENCODE_VIDEO_OUTPUT_FRAME_RATE			=0x00000800,
	HWAPI_BM_MSG_ENCODE_VIDEO_OUTPUT_BIT_RATE			=0x00001000,
	HWAPI_BM_MSG_ENCODE_VIDEO_RATE_CONTROL				=0x00002000,
	HWAPI_BM_MSG_ENCODE_VIDEO_VBR_MIN					=0x00004000,
	HWAPI_BM_MSG_ENCODE_VIDEO_VBR_MAX					=0x00008000,
	HWAPI_BM_MSG_ENCODE_VIDEO_CODING_MODE				=0x00010000,
	HWAPI_BM_MSG_ENCODE_VIDEO_PROFILE					=0x00020000,
	HWAPI_BM_MSG_ENCODE_VIDEO_LEVEL						=0x00040000,
	HWAPI_BM_MSG_ENCODE_VIDEO_TS_BITRATE				=0x00080000,
	HWAPI_BM_MSG_ENCODE_VIDEO_LATENCY					=0x00100000,
    HWAPI_BM_MSG_ENCODE_INSERT_IFRAME                   =0x00200000,
    HWAPI_BM_MSG_ENCODE_CABAC_CODING                    =0x00400000,
    HWAPI_BM_MSG_ENCODE_DEBLOCK_FILTER                  =0x00800000,
    HWAPI_BM_MSG_ENCODE_NUM_BFRAMENUM                   =0x01000000,
    HWAPI_BM_MSG_ENCODE_BIASIDR                         =0x02000000,
    HWAPI_BM_MSG_ENCODE_PMT_VERSION                     =0x04000000,
    HWAPI_BM_MSG_ENCODE_BSMOOTHING                      =0x08000000,
    HWAPI_BM_MSG_ENCODE_HSMOOTHOFF                      =0x10000000,
    HWAPI_BM_MSG_ENCODE_VSMOOTHOFF                      =0x20000000,
    HWAPI_BM_MSG_ENCODE_GOPSIZE                         =0x40000000,

}HAPI_ENCODE_VIDEO_PARAMS_BM;


typedef enum _HAPI_ENCODE_AUDIO_PARAMS_BM
{
	HWAPI_BM_MSG_ENCODE_AUDIO_STREAM_ID					=0x00000001,
	HWAPI_BM_MSG_ENCODE_AUDIO_OUTPUT_PID				=0x00000002,	
	HWAPI_BM_MSG_ENCODE_AUDIO_CAPTURE_SOURCE			=0x00000004,
	HWAPI_BM_MSG_ENCODE_AUDIO_CAPTURE_SAMPLE_RATE		=0x00000008,
	HWAPI_BM_MSG_ENCODE_AUDIO_CAPTURE_MODE				=0x00000010,
	HWAPI_BM_MSG_ENCODE_AUDIO_CAPTURE_SPDIF_INPUT		=0x00000020,
	HWAPI_BM_MSG_ENCODE_AUDIO_CODEC_OUTPUT_FORMAT		=0x00000040,
	HWAPI_BM_MSG_ENCODE_AUDIO_OUTPUT_MODE				=0x00000080,
	HWAPI_BM_MSG_ENCODE_AUDIO_OUTPUT_SAMPLE_RATE		=0x00000100,
	HWAPI_BM_MSG_ENCODE_AUDIO_OUTPUT_BITRATE			=0x00000200,
	HWAPI_BM_MSG_ENCODE_AUDIO_ENCODE_MODE			    =0x00000400,
	HWAPI_BM_MSG_ENCODE_AUDIO_AGC_ENABLE                =0x00000800,
	HWAPI_BM_MSG_ENCODE_AUDIO_MAXSAMPLE                 =0x00001000,	

    HWAPI_BM_MSG_ENCODE_AUDIO_STREAM_ID_1               =0x00002000,
	HWAPI_BM_MSG_ENCODE_AUDIO_OUTPUT_PID_1              =0x00004000,	
	HWAPI_BM_MSG_ENCODE_AUDIO_CAPTURE_MODE_1            =0x00008000,
	HWAPI_BM_MSG_ENCODE_AUDIO_CODEC_OUTPUT_FORMAT_1     =0x00010000,
	HWAPI_BM_MSG_ENCODE_AUDIO_OUTPUT_MODE_1             =0x00020000,
	HWAPI_BM_MSG_ENCODE_AUDIO_OUTPUT_SAMPLE_RATE_1      =0x00040000,
	HWAPI_BM_MSG_ENCODE_AUDIO_OUTPUT_BITRATE_1          =0x00080000,
    HWAPI_BM_MSG_ENCODE_AUDIO_ENCODE_MODE_1             =0x00100000,
       
}HAPI_ENCODE_AUDIO_PARAMS_BM;


typedef enum _HAPI_ENCODE_LOG_PARAMS_BM
{
    HWAPI_BM_MSG_ENCODE_ACTIVITY_LOG_ENABLE            	= 0x00000001,
    HWAPI_BM_MSG_ENCODE_ERROR_LOG_ENABLE               	= 0x00000002,
    HWAPI_BM_MSG_ENCODE_ERROR_PRINTING_ENABLE          	= 0x00000004,
}HAPI_ENCODE_LOG_BM;


typedef enum _HAPI_ENCODE_PARAM_TYPE_BM
{
    HAPI_BM_ENCODE_VIDEO_PARAMS                           	= 0x00000001,
    HAPI_BM_ENCODE_AUDIO_PARAMS                           	= 0x00000002,
    HAPI_BM_ENCODE_SYS_PARAMS                             	= 0x00000004,
    HAPI_BM_ENCODE_LOG_PARAMS                             	= 0x00000008,
}HAPI_ENCODE_PARAM_TYPE_BM;

typedef enum _HAPI_STATUS_QUERY_BM
{
    HAPI_BM_STATUS_QUERY_STATE                      =0x00000001,
    HAPI_BM_STATUS_QUERY_FRAMERATE                  =0x00000002,
    HAPI_BM_STATUS_QUERY_AR                         =0x00000004,
    HAPI_BM_STATUS_QUERY_PCR                        =0x00000010,
    HAPI_BM_STATUS_QUERY_INFRCOUNT                  =0x00000020,
    HAPI_BM_STATUS_QUERY_OUTFRCOUNT                 =0x00000040,
//    HAPI_BM_STATUS_QUERY_INTERLACE                =0x00000080,
//    HAPI_BM_STATUS_QUERY_WIDTH                    =0x00000100,
//    HAPI_BM_STATUS_QUERY_HEIGHT                   =0x00000200,
//    HAPI_BM_STATUS_QUERY_AUDIO_SAMPLE_RATE        =0x00000400,
//    HAPI_BM_STATUS_QUERY_AUDIO_BIT_RATE           =0x00000800,
}HAPI_STATUS_QUERY_BM;
/**
 * response code
 */
typedef enum
{
    HWAPI_MSG_REQ                         = 0xFFFFFFFF,
    HWAPI_MSG_RSP_PASS                    = 0x00000000,
    HWAPI_MSG_RSP_FAIL                    = 0x01000000,
    HWAPI_MSG_EVENT_AV_INPUT_DATA_REQ     = 0x10000000,
    HWAPI_MSG_EVENT_AV_INPUT_DATA         = 0x10000001,
    HWAPI_MSG_EVENT_AV_OUTPUT_DATA        = 0x10000002,
    HWAPI_MSG_EVENT_DEBUG_LOG             = 0x10000003,
    HWAPI_MSG_EVENT_ERROR                 = 0x10000004,
    HWAPI_MSG_EVENT_BAD_PARAM             = 0x10000004,
    
} HWAPI_MSG_RSP_CODE;

typedef struct
{
    Uint32 msgTag;
    Uint32 msgVersion;
	HWAPI_MSG_TYPE type;
	Uint32 cookie;
	Uint32 payloadSize;
    Uint32 responseCode;
	Uint32 reserved1;
	Uint32 reserved2;
}HWAPI_MSG_HEADER;

typedef struct
{
	HWAPI_MSG_HEADER header;
	
    Uint32 bitMask;
    Uint32 index;
    Uint32 ParamType; // Encode, decode or transcode parameters
	Uint32 checkCode;
	
	Uint8  ucPad[HAPI_MSG_MAX_PAD - 4*4 - sizeof(HWAPI_MSG_HEADER)];
}HWAPI_MSG_GET_PARAM_REQ;

typedef struct
{
	HWAPI_MSG_HEADER header;
	
    Uint32 bitMask;
    HAPI_GET_PARAM param;
    Uint32 errCode;
    Uint32 checkCode;
	
	Uint8  ucPad[HAPI_MSG_MAX_PAD - 3*4 - sizeof(HWAPI_MSG_HEADER)];
}HWAPI_MSG_GET_PARAM_RSP;


typedef struct
{
    HWAPI_MSG_HEADER header;
	
    //Uint32 bitMask;
    HAPI_SET_PARAM param;
	
    Uint32 checkCode;
	
	Uint8  ucPad[HAPI_MSG_MAX_PAD - 1*4 - sizeof(HWAPI_MSG_HEADER)];	
}HWAPI_MSG_SET_PARAM;

typedef struct
{
	HWAPI_MSG_HEADER header;
	
    //Uint32 bitMask;
    Uint32 errCode;
	Uint32 checkCode;

	Uint8  ucPad[HAPI_MSG_MAX_PAD - 2*4 - sizeof(HWAPI_MSG_HEADER)];
}HWAPI_MSG_SET_PARAM_RSP;

typedef struct
{
    HWAPI_MSG_HEADER header;
    Uint32 checkCode;
    Uint8 ucPad[HAPI_MSG_MAX_PAD -4-sizeof(HWAPI_MSG_HEADER)-24];    
    HAPI_LOGO_CONFIG_PARAM param;
}HWAPI_MSG_LOGO_CONFIG;

typedef struct
{
    HWAPI_MSG_HEADER header;
    Uint32 errorCode;
    Uint32 checkcode;
    Uint8  ucPad[HAPI_MSG_MAX_PAD-sizeof(HWAPI_MSG_HEADER)-2*4];
}HWAPI_MSG_LOGO_CONFIG_RSP;

typedef struct
{
    HWAPI_MSG_HEADER header;
    Uint32                        chIndex;
    Uint16                        logoIndex;
    Uint16                          on;    
    Uint32 checkCode;
    Uint8 ucPad[HAPI_MSG_MAX_PAD-12-sizeof(HWAPI_MSG_HEADER)];
}HWAPI_MSG_LOGO_ON_OFF;

typedef struct
{
    HWAPI_MSG_HEADER header;
    Uint32 errorCode;
    Uint32 checkcode;
    Uint8  ucPad[HAPI_MSG_MAX_PAD-sizeof(HWAPI_MSG_HEADER)-2*4];
}HWAPI_MSG_LOGO_ON_OFF_RSP;

typedef struct
{
    HWAPI_MSG_HEADER header;
    HAPI_I2C_WRITE_PARAM param;
    Uint32 checkCode;
    Uint8 ucPad[HAPI_MSG_MAX_PAD*2 -4-sizeof(HWAPI_MSG_HEADER)-sizeof(HAPI_I2C_WRITE_PARAM)];
}HWAPI_MSG_I2C_WRITE;

typedef struct
{
    HWAPI_MSG_HEADER header;
    Uint32 errCode;
    Uint32 checkCode;
    Uint8  ucPad[HAPI_MSG_MAX_PAD - 2*4 - sizeof(HWAPI_MSG_HEADER)];
}HWAPI_MSG_I2C_WRITE_RSP;

typedef struct
{
    HWAPI_MSG_HEADER header;
    HAPI_I2C_READ_PARAM param;
    Uint32 checkCode;
    Uint8 ucPad[HAPI_MSG_MAX_PAD*2 -4-sizeof(HWAPI_MSG_HEADER)-sizeof(HAPI_I2C_READ_PARAM)];
}HWAPI_MSG_I2C_READ;

typedef struct
{
    HWAPI_MSG_HEADER header;
    HAPI_I2C_READ_PARAM param;
    Uint32 errCode;
    Uint32 checkCode;
    Uint8 ucPad[HAPI_MSG_MAX_PAD*2 -2*4-sizeof(HWAPI_MSG_HEADER)-sizeof(HAPI_I2C_READ_PARAM)];
}HWAPI_MSG_I2C_READ_RSP;

typedef struct
{
    HWAPI_MSG_HEADER  header;
    HAPI_GPIO_PIN_ID     pin;
    Uint32                         val;
    Uint32 checkCode;
    Uint8 ucPad[HAPI_MSG_MAX_PAD-12-sizeof(HWAPI_MSG_HEADER)];
}HWAPI_MSG_GPIO_READ;

typedef struct
{
    HWAPI_MSG_HEADER header;
    Uint32 Val;
    Uint32 errCode;
    Uint32 checkCode;
    Uint8 ucPad[HAPI_MSG_MAX_PAD -12-sizeof(HWAPI_MSG_HEADER)];
}HWAPI_MSG_GPIO_READ_RSP;

typedef struct
{
    HWAPI_MSG_HEADER  header;
    HAPI_GPIO_PIN_ID     pin;
    Uint32                         val;
    Uint32 checkCode;
    Uint8 ucPad[HAPI_MSG_MAX_PAD-12-sizeof(HWAPI_MSG_HEADER)];
}HWAPI_MSG_GPIO_WRITE;

typedef struct
{
    HWAPI_MSG_HEADER header;
    Uint32 errCode;
    Uint32 checkCode;
    Uint8  ucPad[HAPI_MSG_MAX_PAD - 2*4 - sizeof(HWAPI_MSG_HEADER)];
}HWAPI_MSG_GPIO_WRITE_RSP;

typedef struct
{
    HWAPI_MSG_HEADER header;
    Uint16 f_khz;
    Uint16 reserved;
    Uint32 checkCode;
    Uint8 ucPad[HAPI_MSG_MAX_PAD -4-2-2-sizeof(HWAPI_MSG_HEADER)];
}HWAPI_MSG_I2C_CLOCK_FREQ;

typedef struct
{
    HWAPI_MSG_HEADER header;
    Uint16 f_khz;
    Uint16 reserved;
    Uint32 errCode;
    Uint32 checkCode;
    Uint8 ucPad[HAPI_MSG_MAX_PAD -2*4-2*2-sizeof(HWAPI_MSG_HEADER)];
}HWAPI_MSG_I2C_CLOCK_FREQ_RSP;

typedef struct
{
    HWAPI_MSG_HEADER header;
    HAPI_I2C_MONITOR_PARAM param;
    HAPI_I2C_MONITOR_NUM monitorNum;
    Uint32 checkcode;
    Uint8 ucPad[HAPI_MSG_MAX_PAD*3 -4*2-sizeof(HWAPI_MSG_HEADER)-sizeof(HAPI_I2C_MONITOR_PARAM)];
    
}HWAPI_MSG_I2C_MONITOR_INSTALL;

typedef struct
{
    HWAPI_MSG_HEADER header;
    Uint32 errCode;
    Uint32 checkCode;
    Uint8 ucPad[HAPI_MSG_MAX_PAD -4*2-sizeof(HWAPI_MSG_HEADER)];
}HWAPI_MSG_I2C_MONITOR_INSTALL_RSP;

typedef struct
{
    HWAPI_MSG_HEADER header;
    HAPI_I2C_CALLBACK_PARAM Param;
    Uint32 monitorNum;
    Uint32 checkcode;
    Uint8 ucPad[HAPI_MSG_MAX_PAD*2 -4*2-sizeof(HWAPI_MSG_HEADER)-sizeof(HAPI_I2C_CALLBACK_PARAM)];
}HWAPI_MSG_I2C_OUTPUT_MONITOR_DATA;

typedef struct
{
    HWAPI_MSG_HEADER header;
    Uint32 pcrHigh;
    Uint32 pcrLow;
    Uint8 ucPad[HAPI_MSG_MAX_PAD -8-sizeof(HWAPI_MSG_HEADER)];
}HWAPI_MSG_PCR_DATA;

typedef struct
{
    HWAPI_MSG_HEADER header;
    Uint32 errCode;
    Uint32 checkCode;
    Uint8  ucPad[HAPI_MSG_MAX_PAD - 2*4 - sizeof(HWAPI_MSG_HEADER)];
}HWAPI_MSG_PCR_DATA_RSP;

typedef struct
{
    HWAPI_MSG_HEADER header;
    Uint32 ch;
    HAPI_ASPECT_RATIO ar;
    Uint8 ucPad[HAPI_MSG_MAX_PAD-4*2-sizeof(HWAPI_MSG_HEADER)];
}HWAPI_MSG_AR_DATA;

typedef struct
{
    HWAPI_MSG_HEADER header;
    Uint32 errCode;
    Uint32 checkCode;
    Uint8  ucPad[HAPI_MSG_MAX_PAD - 2*4 - sizeof(HWAPI_MSG_HEADER)];
}HWAPI_MSG_AR_DATA_RSP;

typedef struct
{
    HWAPI_MSG_HEADER header;

    HAPI_SET_AVL_PARAM avl;
    Uint32 checkCode;

    Uint8  ucPad[4*HAPI_MSG_MAX_PAD - (1*4 + sizeof(HAPI_SET_AVL_PARAM))- sizeof(HWAPI_MSG_HEADER)]; //FIXME: 4*64 - ???
}HWAPI_MSG_SET_AVL;

typedef struct
{
    HWAPI_MSG_HEADER header;
    Uint32 errCode;
    Uint32 checkCode;

    Uint8  ucPad[HAPI_MSG_MAX_PAD - 2*4 - sizeof(HWAPI_MSG_HEADER)];
}HWAPI_MSG_SET_AVL_RSP;

typedef struct
{
	HWAPI_MSG_HEADER header;
	
    Uint32 bitMask;
    Uint32 index;
    Uint32 encryptionEnable;
	Uint32 checkCode;
	
	Uint8  ucPad[HAPI_MSG_MAX_PAD - 4*4 - sizeof(HWAPI_MSG_HEADER)];
}HWAPI_MSG_START;

typedef struct
{
	HWAPI_MSG_HEADER header;
	
    Uint32 bitMask;
    Uint32 index;
    Uint32 errCode;
	Uint32 checkCode;
	
	Uint8  ucPad[HAPI_MSG_MAX_PAD - 4*4 - sizeof(HWAPI_MSG_HEADER)];	
}HWAPI_MSG_START_RSP;

typedef struct
{
	HWAPI_MSG_HEADER header;
	
    Uint32 bitMask;
    Uint32 index;
	Uint32 checkCode;

	Uint8  ucPad[HAPI_MSG_MAX_PAD - 3*4 - sizeof(HWAPI_MSG_HEADER)];		
}HWAPI_MSG_STOP;

typedef struct
{
	HWAPI_MSG_HEADER header;
	
    Uint32 bitMask;
    Uint32 errCode;
	Uint32 checkCode;

	Uint8  ucPad[HAPI_MSG_MAX_PAD - 3*4 - sizeof(HWAPI_MSG_HEADER)];	
}HWAPI_MSG_STOP_RSP;

typedef struct
{
	HWAPI_MSG_HEADER header;
	
    Uint32 bitMask;
    Uint32 index;
    HAPI_AUDIO_IN_PORT inAudioPort;
    HAPI_VIDEO_IN_PORT inVideoPort;
    HAPI_AUDIO_OUT_PORT outAudioPort;
    HAPI_VIDEO_OUT_PORT outVideoPort;
    Uint32 checkCode;

	Uint8  ucPad[HAPI_MSG_MAX_PAD - 7*4 - sizeof(HWAPI_MSG_HEADER)];	
}HWAPI_MSG_INIT;

typedef struct
{
	HWAPI_MSG_HEADER header;
    Uint32 bitMask;
    Uint32 ProductID;
    Uint8  Description[64];
    Uint32 MajorVer;
    Uint32 MinorVer;
    Uint32 BuildVersion;
    Uint8  BuildDate[16];
    Uint8  BuildTime[16];
	Uint32 checkCode;

	Uint8  ucPad[HAPI_MSG_MAX_PAD - 6*4];	
}HWAPI_MSG_INIT_RSP;

typedef struct
{
	HWAPI_MSG_HEADER header;
	
    Uint32 index;
    Uint32 bitMask;
	Uint32 checkCode;
	
	Uint8  ucPad[HAPI_MSG_MAX_PAD - 3*4 - sizeof(HWAPI_MSG_HEADER)];	
}HWAPI_MSG_EXIT;

typedef struct
{
	HWAPI_MSG_HEADER header;
	
    Uint32 bitMask;
	Uint32 checkCode;
	
	Uint8  ucPad[HAPI_MSG_MAX_PAD - 2*4 - sizeof(HWAPI_MSG_HEADER)];	
}HWAPI_MSG_EXIT_RSP;

typedef struct
{
	HWAPI_MSG_HEADER header;
    Uint32 index;
    Uint32 bitMask;
	Uint32 addr;
	Uint32 length;
	unsigned char buff[HAPI_FWUPGRADE_MAXPAYLOADSIZE-20];
	Uint32 checkCode;
}HWAPI_MSG_FWUPGRADE;

typedef struct
{
	HWAPI_MSG_HEADER header;
    Uint32 index;
    Uint32 bitMask;	
	Uint32 checkCode;
}HWAPI_MSG_FWUPGRADE_RSP;

typedef struct
{
	HWAPI_MSG_HEADER header;
    Uint32 bitMask;
    Uint32 dataLength;
	Uint8  ucPad[HAPI_MSG_MAX_PAD - 2*4 - sizeof(HWAPI_MSG_HEADER)];
	
    Uint8  data[MAX_STREAM_AV_DATA_SIZE];
}HWAPI_MSG_STREAM_INPUT_DATA;

typedef struct
{
	HWAPI_MSG_HEADER header;
	
    Uint32 bitMask;
    Uint32 errCode;
	Uint32 checkCode;
	
	Uint8  ucPad[HAPI_MSG_MAX_PAD - 3*4 - sizeof(HWAPI_MSG_HEADER)];	
}HWAPI_MSG_STREAM_INPUT_DATA_RSP;

typedef struct
{
	HWAPI_MSG_HEADER header;
	
    Uint32 bitMask;
    Uint32 dataLength;
	
	Uint8  ucPad[HAPI_MSG_MAX_PAD - 2*4 - sizeof(HWAPI_MSG_HEADER)];	
}HWAPI_MSG_STREAM_INPUT_DATA_INF;

typedef struct
{
	HWAPI_MSG_HEADER header;
	
    Uint32 bitMask;
	Uint32 errorCode;
	Uint32 checkCode;
	
	Uint8  ucPad[HAPI_MSG_MAX_PAD - 3*4 - sizeof(HWAPI_MSG_HEADER)];		
}HWAPI_MSG_ERROR;

typedef struct
{
	HWAPI_MSG_HEADER header;
	
    Uint32 bitMask;
    Uint32 dataLength;
	Uint32 checkCode;
	
	Uint8  ucPad[HAPI_MSG_MAX_PAD - 3*4 - sizeof(HWAPI_MSG_HEADER)];	
}HWAPI_MSG_STREAM_DATA_REQUEST;

typedef struct
{
    HWAPI_MSG_HEADER header;
    Uint32 bitMask;
    Uint32 dataLength;
    Uint32 checkCode;
    Uint8  ucPad[HAPI_MSG_MAX_PAD - 3*4 - sizeof(HWAPI_MSG_HEADER)];	
}HWAPI_MSG_STREAM_DATA_REQUEST_RSP;

typedef struct
{
    HWAPI_MSG_HEADER header;
    Uint32 bitMask;
    Uint32 dataLength;
    Uint8  ucPad[HAPI_MSG_MAX_PAD - 2*4 - sizeof(HWAPI_MSG_HEADER)];	
    Uint8  data[MAX_STREAM_AV_DATA_SIZE];
}HWAPI_MSG_STREAM_OUTPUT_DATA;

typedef struct
{
    HWAPI_MSG_HEADER header;
    Uint32 bitMask;
    Uint32 errorCode;
    Uint32 checkCode;
    Uint8  ucPad[HAPI_MSG_MAX_PAD - 3*4 - sizeof(HWAPI_MSG_HEADER)];	
}HWAPI_MSG_STREAM_OUTPUT_DATA_RSP;

typedef struct
{
    HWAPI_MSG_HEADER header;
    Uint32 bitMask;
    Uint32 dataLength;
    Uint8  ucPad[HAPI_MSG_MAX_PAD - 2*4 - sizeof(HWAPI_MSG_HEADER)];	
}HWAPI_MSG_STREAM_OUTPUT_DATA_INF;

typedef struct
{
    HWAPI_MSG_HEADER header;
    Uint32 bitMask;
    Uint32 inVideoWidth;            /*!< Video input width */
    Uint32 inVideoHeight;           /*!< Video input height */
    Uint32 outVideoWidth;           /*!< Video output width */
    Uint32 outVideoHeight;          /*!< Video output height */
    Uint32 inFrameRate;             /*!< Input frame rate */
    Uint32 outFrameRate;            /*!< Output frame rate */
    Uint32 inVideoBitRate;          /*!< Input Video bit rate */

    Uint32 outVideoBitRate;         /*!< Output Video bit rate */
    Uint32 inAudioSampleRate;       /*!< Input audio sampling rate */
    Uint32 outAudioSampleRate;      /*!< Output audio sampling rate */
    Uint32 inAudioBitRate;          /*!< Input audio bit rate */
    Uint32 outAudioBitRate;         /*!< Output audio bit rate */
    Uint32 checkCode;

    Uint8  ucPad[HAPI_MSG_MAX_PAD - 6*4];
}HWAPI_MSG_AV_UPDATE;

typedef struct
{
    HWAPI_MSG_HEADER header;
    HAPI_ERROR_MSG_TYPE errType;
    HAPI_ERR_PARAM  params;
    Uint8  ucPad[HAPI_MSG_MAX_PAD*2 - sizeof(HAPI_ERROR_MSG_TYPE) - sizeof(HWAPI_MSG_HEADER)-sizeof(HAPI_ERR_PARAM)];
}HWAPI_MSG_ERR_UPDATE;

typedef struct
{
    HWAPI_MSG_HEADER header;
    HAPI_QUERY_STRUCT status;
    Uint8  ucPad[HAPI_MSG_MAX_PAD*2 - sizeof(HWAPI_MSG_HEADER)-sizeof(HAPI_QUERY_STRUCT)];
}HWAPI_MSG_QUERY_STATUS;

typedef struct
{
    HWAPI_MSG_HEADER header;
    HAPI_QUERY_STRUCT status;
    Uint32 errorCode;
    Uint32 checkCode;
    Uint8  ucPad[HAPI_MSG_MAX_PAD*2 -2*4 - sizeof(HWAPI_MSG_HEADER)-sizeof(HAPI_QUERY_STRUCT)];
}HWAPI_MSG_QUERY_STATUS_RSP;
#endif

