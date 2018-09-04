//=============================================================================
//  File Name: HapiCommon.h
//
//  Copyright 2009 Magnum Semiconductor Inc. All rights reserved.
//
//  Description:
//      HAPI common definitions.
//
//  Modification History:
//      $Id: $
//      $Log: $
//
//=============================================================================
#ifndef _HAPI_COMMON_H_
#define _HAPI_COMMON_H_

#include <stdint.h>

#define HAPI_MSG_MAX_PAD	(64)

// when compiling HapiHostApp on linux, gcc does not support using ifdef/ifndef to
// detect whether an item is defined by typedef
#ifndef __linux__

    #ifndef Uint32
        typedef uint32_t Uint32;
    #endif

    #ifndef Uint8
        typedef uint8_t Uint8;
    #endif

#endif

#define MAX_I2C_DATA_LENGTH         32
#define MAX_I2C_SUBADDR_LENGTH       8
#define MAX_MONITORED_VALUE_LENGTH  16//refer to HAPI specification_1_4_v2.2

#define MAX_LOGO_WIDTH     1200  //pixels:150*8
#define MAX_LOGO_HEIGHT     800  //pixels:100*8
#define MAX_LOGO_SIZE    120000  //150*100*8
#define BYTE_PER_PIXEL        4

typedef enum _HAPI_VIDEO_CODEC
{
    HAPI_VIDEO_CODEC_UNKNOWN = -1,
    HAPI_VIDEO_CODEC_H264,
    HAPI_VIDEO_CODEC_MPG2,
    HAPI_VIDEO_CODEC_VC1,
    HAPI_VIDEO_CODEC_MPEG2_TO_H264_SINGLE_ENGINE,
    HAPI_VIDEO_CODEC_H264_LIGHT_ENGINE,
    HAPI_VIDEO_CODEC_MAX,
}HAPI_VIDEO_CODEC;

typedef enum{
    HAPI_AUDIO_CODEC_UNKNOWN = -1,
    HAPI_AUDIO_CODEC_NONE,
    HAPI_AUDIO_CODEC_MPEG,
    HAPI_AUDIO_CODEC_AC3,
    HAPI_AUDIO_CODEC_AAC,
    HAPI_AUDIO_CODEC_AACHE,
    HAPI_AUDIO_CODEC_AACLC,
    HAPI_AUDIO_CODEC_MP3,
    HAPI_AUDIO_CODEC_DDP,
    HAPI_AUDIO_CODEC_PCM,
    HAPI_AUDIO_CODEC_PASSTHROUGH,
    HAPI_AUDIO_CODEC_OUTPUTPASSTHROUGH,
    HAPI_AUDIO_CODEC_INPUTPASSTHROUGH,
    HAPI_AUDIO_CODEC_AUTO,
    HAPI_AUDIO_ENCODING_MPEG2,       //13
    HAPI_AUDIO_ENCODING_302MPCM,     //14,
    HAPI_AUDIO_ENCODING_DOLBYE,      //15,
    HAPI_AUDIO_ENCODING_DOLBYPULSE,  //16,
    HAPI_AUDIO_ENCODING_DDPRO,       //17,
    HAPI_AUDIO_ENCODING_TESTTONE,    //18,      // only for audio decoder
    HAPI_AUDIO_ENCODING_MPEG4,       //19,
    HAPI_AUDIO_ENCODING_DTS,         //20,
    HAPI_AUDIO_CODEC_MAX,
}HAPI_AUDIO_CODEC;

#if 0
/** Resolution of video output*/
typedef enum _HAPI_VIDEO_OUTPUT_RESOLUTION
{
    HAPI_VIDEO_OUTPUT_RESOLUTION_1440_1080I = 0,
    HAPI_VIDEO_OUTPUT_RESOLUTION_1280_1080I,
    HAPI_VIDEO_OUTPUT_RESOLUTION_1080_720P,
    HAPI_VIDEO_OUTPUT_RESOLUTION_960_720P,
    HAPI_VIDEO_OUTPUT_RESOLUTION_1920_544P,
    HAPI_VIDEO_OUTPUT_RESOLUTION_1440_544P,
    HAPI_VIDEO_OUTPUT_RESOLUTION_1280_544P,
    HAPI_VIDEO_OUTPUT_RESOLUTION_640_480P,
}HAPI_VIDEO_OUTPUT_RESOLUTION;
#endif

/** Frame rate of video output*/
typedef enum _HAPI_VIDEO_OUTPUT_FRAME_RATE
{
    HAPI_VIDEO_OUTPUT_FRAME_RATE_INVALID = 0,
    HAPI_VIDEO_OUTPUT_FRAME_RATE_23_98,
    HAPI_VIDEO_OUTPUT_FRAME_RATE_24,
    HAPI_VIDEO_OUTPUT_FRAME_RATE_25,
    HAPI_VIDEO_OUTPUT_FRAME_RATE_29_97,
    HAPI_VIDEO_OUTPUT_FRAME_RATE_30,
    HAPI_VIDEO_OUTPUT_FRAME_RATE_50,
    HAPI_VIDEO_OUTPUT_FRAME_RATE_59_94,
    HAPI_VIDEO_OUTPUT_FRAME_RATE_60,
    HAPI_VIDEO_OUTPUT_FRAME_RATE_15,
    HAPI_VIDEO_OUTPUT_FRAME_RATE_12,
    HAPI_VIDEO_OUTPUT_FRAME_RATE_10,
    HAPI_VIDEO_OUTPUT_FRAME_RATE_8,
    HAPI_VIDEO_OUTPUT_FRAME_RATE_6,
    HAPI_VIDEO_OUTPUT_FRAME_RATE_4,
    HAPI_VIDEO_OUTPUT_FRAME_RATE_1,
    HAPI_VIDEO_OUTPUT_FRAME_RATE_12_5,  // frame rate 12.5
    HAPI_VIDEO_OUTPUT_FRAME_RATE_MAX,
} HAPI_VIDEO_OUTPUT_FRAME_RATE;

/** Video output mode*/
typedef enum _HAPI_VIDEO_OUTPUT_MODE
{
    HAPI_VIDEO_OUTPUT_MODE_INTERLACED,
    HAPI_VIDEO_OUTPUT_MODE_PROGRESSIVE,
    HAPI_VIDEO_OUTPUT_MODE_PSF,
    HAPI_VIDEO_OUTPUT_MODE_MAX,
}HAPI_VIDEO_OUTPUT_MODE;

/** Audio channles*/
typedef enum _HAPI_AUDIO_OUTPUT_MODE
{
    HAPI_AUDIO_CHANNELS_NONE = -1,
    HAPI_AUDIO_CHANNELS_DUALMONO = 0,
    HAPI_AUDIO_CHANNELS_STEREO,
    HAPI_AUDIO_CHANNELS_MONO,
    HAPI_AUDIO_CHANNELS_LEFTMONO,
    HAPI_AUDIO_CHANNELS_RIGHTMONO,
//  HAPI_AUDIO_CHANNELS_LEFTSTEREO,
//  HAPI_AUDIO_CHANNELS_RIGHTSTEREO,
    HAPI_AUDIO_CHANNELS_RANGE,
}HAPI_AUDIO_OUTPUT_MODE;

typedef enum _HAPI_AUDIO_SAMPLE_RATE
{
    HAPI_AUDIO_SAMPLE_RATE_FOLLOW_INPUT = -1,
    HAPI_AUDIO_SAMPLE_RATE_NONE,
    HAPI_AUDIO_SAMPLE_RATE_32_KHZ,
    HAPI_AUDIO_SAMPLE_RATE_44_1_KHZ,
    HAPI_AUDIO_SAMPLE_RATE_48_KHZ,
    HAPI_AUDIO_SAMPLE_RATE_96_KHZ,
    HAPI_AUDIO_SAMPLE_RATE_192_KHZ,
    HAPI_AUDIO_SAMPLE_RATE_16_KHZ
}HAPI_AUDIO_SAMPLE_RATE;

/** Audio transcode mode*/
typedef enum _HAPI_AUDIO_TRANSCODE_MODE
{
    HAPI_AUDIO_TRANSCODE_PASSTHROUGH = 0,
    HAPI_AUDIO_TRANSCODE_TRANSCODE,
}HAPI_AUDIO_TRANSCODE_MODE;


/** Rate control*/
typedef enum _HAPI_RATE_CONTROL
{
    HAPI_RATE_CONTROL_CBR = 0,
    HAPI_RATE_CONTROL_VBR,
    HAPI_RATE_CONTROL_CAPPED_VBR,
}HAPI_RATE_CONTROL;

/**File output format*/
typedef enum{
    HAPI_FILE_OUTPUT_FORMAT_NONE = 0,
    HAPI_FILE_OUTPUT_FORMAT_TS,
    HAPI_FILE_OUTPUT_FORMAT_ES,
    HAPI_FILE_OUTPUT_FORMAT_PS,
    HAPI_FILE_OUTPUT_FORMAT_MD4,
    HAPI_FILE_OUTPUT_FORMAT_RAWVIDEO,
    HAPI_FILE_OUTPUT_FORMAT_AVI,
    HAPI_FILE_OUTPUT_FORMAT_MP4,
    HAPI_FILE_OUTPUT_FORMAT_RAW_AUDIO,
    HAPI_FILE_OUTPUT_FORMAT_ASF,
    HAPI_FILE_OUTPUT_FORMAT_MAX,
} HAPI_FILE_OUTPUT_FORMAT;

/**ANC data transfer mode*/
typedef enum _HAPI_ANC_DATA_TRANSFER_MODE
{
    HAPI_ANC_DATA_TRANSFER_MODE_REINSERT = 0,
    HAPI_ANC_DATA_TRANSFER_MODE_DISCARD,
}HAPI_ANC_DATA_TRANSFER_MODE;

/**Encryption mode*/
typedef enum _HAPI_ENCRYPTION_MODE
{
    HAPI_ENCRYPTION_OFF = 0,
    HAPI_ENCRYPTION_ON,
}HAPI_ENCRYPTION_MODE;

typedef enum _HAPI_AUDIO_BITRATE
{
    HAPI_AUDIO_BITRATE_NONE = -1,
    HAPI_AUDIO_BITRATE_32_KBPS = 0,
    HAPI_AUDIO_BITRATE_48_KBPS,
    HAPI_AUDIO_BITRATE_56_KBPS,
    HAPI_AUDIO_BITRATE_64_KBPS,
    HAPI_AUDIO_BITRATE_80_KBPS,
    HAPI_AUDIO_BITRATE_96_KBPS,
    HAPI_AUDIO_BITRATE_112_KBPS,
    HAPI_AUDIO_BITRATE_128_KBPS,
    HAPI_AUDIO_BITRATE_160_KBPS,
    HAPI_AUDIO_BITRATE_192_KBPS,
    HAPI_AUDIO_BITRATE_224_KBPS, //10
    HAPI_AUDIO_BITRATE_256_KBPS,
    HAPI_AUDIO_BITRATE_320_KBPS,
    HAPI_AUDIO_BITRATE_384_KBPS,
    HAPI_AUDIO_BITRATE_448_KBPS,
    HAPI_AUDIO_BITRATE_576_KBPS,
    HAPI_AUDIO_BITRATE_16_KBPS,
    HAPI_AUDIO_BITRATE_8_KBPS,
    HAPI_AUDIO_BITRATE_640_KBPS, 
    HAPI_AUDIO_BITRATE_768_KBPS,
    HAPI_AUDIO_BITRATE_960_KBPS,  //20
    HAPI_AUDIO_BITRATE_1024_KBPS,
    HAPI_AUDIO_BITRATE_1152_KBPS,
    HAPI_AUDIO_BITRATE_1280_KBPS,
    HAPI_AUDIO_BITRATE_1344_KBPS,
    HAPI_AUDIO_BITRATE_1408_KBPS,
    HAPI_AUDIO_BITRATE_1411_KBPS,
    HAPI_AUDIO_BITRATE_1472_KBPS,
    HAPI_AUDIO_BITRATE_1536_KBPS,  //28
    HAPI_AUDIO_BITRATE_MAX,
}HAPI_AUDIO_BITRATE;


/**Coding mode*/
typedef enum _HAPI_CODING_MODE
{
    HAPI_CODING_MODE_FRAME = 0,
    HAPI_CODING_MODE_FIELD,
    HAPI_CODING_MODE_MBAFF,
    HAPI_CODING_MODE_PAFF
}HAPI_CODING_MODE;

/*** entropy coding mode ***/
typedef enum _HAPI_VIDEO_ENTROPY_MODE
{
    HAPI_VIDEO_ENTROPY_CAVLC = 0,
    HAPI_VIDEO_ENTROPY_CABAC = 1,
}HAPI_VIDEO_ENTROPY_MODE;

typedef enum _HAPI_VIDEO_PROFILE
{
    HAPI_VIDEO_PROFILE_BASELINE = 0,
    HAPI_VIDEO_PROFILE_MAIN  = 3,
    HAPI_VIDEO_PROFILE_HIGH  = 4
}HAPI_VIDEO_PROFILE;

typedef enum _HAPI_VIDEO_H264_LEVEL
{
  HAPI_H264_LEVEL_1     = 100,
  HAPI_H264_LEVEL_1B    = 105,
  HAPI_H264_LEVEL_1_1   = 110,
  HAPI_H264_LEVEL_1_2   = 120,
  HAPI_H264_LEVEL_1_3   = 130,
  HAPI_H264_LEVEL_2     = 200,
  HAPI_H264_LEVEL_2_1   = 210,
  HAPI_H264_LEVEL_2_2   = 220,
  HAPI_H264_LEVEL_3     = 300,
  HAPI_H264_LEVEL_3_1   = 310,
  HAPI_H264_LEVEL_3_2   = 320,
  HAPI_H264_LEVEL_4     = 400,
  HAPI_H264_LEVEL_4_1   = 410,
  HAPI_H264_LEVEL_4_2   = 420,
  HAPI_H264_LEVEL_5     = 500,
  HAPI_H264_LEVEL_5_1   = 510
}HAPI_VIDEO_H264_LEVEL;

typedef enum _HAPI_LATENCY
{
  HAPI_LATENCY_LOW  = 0,
  HAPI_LATENCY_HIGH = 1,
  HAPI_LATENCY_MEDIUM
}HAPI_LATENCY;

typedef enum _HAPI_FLOW_TYPE
{
    HAPI_FLOW_TYPE_NONE              = -1,
    HAPI_FLOW_TYPE_XCODE_SINGLE      = 1,  //2                 //one channel xcode
    HAPI_FLOW_TYPE_XCODE_DUAL        = 2,                    //two channels xcode
    HAPI_FLOW_TYPE_XCODE_MIRROR_COPY = 3,                    //two channels xcode (the second is a mirror of the first)
    HAPI_FLOW_TYPE_MULTICHIP_XCODE   = 4,                    //NOT IMPLEMENTED YET
    HAPI_FLOW_TYPE_MULTICHIP_ENCODE  = 5,                    //NOT IMPLEMENTED YET
    HAPI_FLOW_TYPE_DECODE            = 6,                    //NOT IMPLEMENTED YET decoder + rescaler
    HAPI_FLOW_TYPE_ENCODE            = 7,                    //NOT IMPLEMENTED YET rescaler + encoder
    HAPI_FLOW_TYPE_LOWLATENCY_ENCODE = 8,                    // encoder, no rescaler
} HAPI_FLOW_TYPE;


/**MV accuracy*/
typedef enum _HAPI_MV_ACCURACY_MODE
{
    HAPI_MV_ACCURACY_SINGLE = 0,
    HAPI_MV_ACCURACY_1DIV2,
    HAPI_MV_ACCURACY_1DIV4,
}HAPI_MV_ACCURACY_MODE;

/**Video output mode*/
typedef enum _HAPI_VIDEO_OUTPUT_SWITCHER
{
    HAPI_VIDEO_OUTPUT_ON = 0,
    HAPI_VIDEO_OUTPUT_OFF,
}HAPI_VIDEO_OUTPUT_SWITCHER;

/**Audio output mode*/
typedef enum _HAPI_AUDIO_OUTPUT_SWITCHER
{
    HAPI_AUDIO_OUTPUT_ON = 0,
    HAPI_AUDIO_OUTPUT_OFF,
}HAPI_AUDIO_OUTPUT_SWITCHER;

/**Mirror mode*/
typedef enum _HAPI_MIRROR_MODE
{
    HAPI_MIRROR_ON = 0,
    HAPI_MIRROR_OFF,
}HAPI_MIRROR_MODE;

/**Data byte order*/
typedef enum _HAPI_DATA_BYTE_ORDER
{
    HAPI_DATA_BYTE_BIG_ENDIAN_ORDER = 0,
    HAPI_DATA_BYTE_SMALL_ENDIAN_ORDER,
}HAPI_DATA_BYTE_ORDER;

typedef enum _HAPI_AUDIO_IN_PORT
{
    HAPI_AUDIO_IN_PORT_I2S = 0,
    HAPI_AUDIO_IN_PORT_TSIN,
    HAPI_AUDIO_IN_PORT_SBP,
    HAPI_AUDIO_IN_PORT_PCI,
    HAPI_AUDIO_IN_PORT_HOSTBUS,
    HAPI_AUDIO_IN_PORT_CAPTURE
}HAPI_AUDIO_IN_PORT;

typedef enum _HAPI_VIDEO_IN_PORT
{
    HAPI_VIDEO_IN_PORT_CODEC = 0,			// George: This defination seems strange, need to be clean out
    HAPI_VIDEO_IN_PORT_TSIN,
    HAPI_VIDEO_IN_PORT_SBP,
    HAPI_VIDEO_IN_PORT_PCI,
    HAPI_VIDEO_IN_PORT_HOSTBUS,
    HAPI_VIDEO_IN_PORT_CAPTURE
}HAPI_VIDEO_IN_PORT;

typedef enum _HAPI_AUDIO_OUT_PORT
{
    HAPI_AUDIO_OUT_PORT_AUD_OUT = 0,
    HAPI_AUDIO_OUT_PORT_TSOUT,
    HAPI_AUDIO_OUT_PORT_SBP,
    HAPI_AUDIO_OUT_PORT_PCI,
    HAPI_AUDIO_OUT_PORT_HOSTBUS
}HAPI_AUDIO_OUT_PORT;

typedef enum _HAPI_VIDEO_OUT_PORT
{
    HAPI_VIDEO_OUT_PORT_VID_OUT = 0,
    HAPI_VIDEO_OUT_PORT_TSOUT,
    HAPI_VIDEO_OUT_PORT_SBP,
    HAPI_VIDEO_OUT_PORT_PCI,
    HAPI_VIDEO_OUT_PORT_HOSTBUS
}HAPI_VIDEO_OUT_PORT;

typedef enum _HAPI_SET_PARAM_TYPE
{
    HAPI_SET_PARAM_TYPE_ENCODER =0,
    HAPI_SET_PARAM_TYPE_DECODER,
    HAPI_SET_PARAM_TYPE_TRANSCODER
}HAPI_SET_PARAM_TYPE;

/**Activity log*/
typedef enum _HAPI_ACTIVITY_LOG_MODE
{
    HAPI_ACTIVITY_LOG_OFF = 0,
    HAPI_ACTIVITY_LOG_ON,
}HAPI_ACTIVITY_LOG_MODE;

/**Error log*/
typedef enum _HAPI_ERROR_LOG_MODE
{
    HAPI_ERROR_LOG_OFF = 0,
    HAPI_ERROR_LOG_ON,
}HAPI_ERROR_LOG_MODE;

/**Error Print*/
typedef enum _HAPI_ERROR_PRINTING_MODE
{
    HAPI_ERROR_PRINTING_OFF = 0,
    HAPI_ERROR_PRINTING_ON,
}HAPI_ERROR_PRINTING_MODE;

/** Error Code*/
typedef enum _HapiErrCode
{
    HAPI_SUCCESS = 0,
    HAPI_FAIL ,
    HAPI_ERR_MEMORY,
    HAPI_ERR_PARAMETER,
}HapiErrCode;

typedef struct _HAPI_DECODE_PARAMS
{
	Uint8  ucPad[HAPI_MSG_MAX_PAD];
}HAPI_DECODE_PARAMS;


typedef enum _HAPI_VIDEO_CAPTURE_SOURCE
{
    HAPI_VIDEO_CAPTURE_SOURCE_CVBS = 0,
    HAPI_VIDEO_CAPTURE_SOURCE_COMPONENT,
    HAPI_VIDEO_CAPTURE_SOURCE_SDI,
    HAPI_VIDEO_CAPTURE_SOURCE_HDMI
} HAPI_VIDEO_CAPTURE_SOURCE;


typedef enum _HAPI_VIDEO_SAMPLE_FORMAT
{
    HAPI_VIDEO_SAMPLE_FORMAT_420 = 0,
    HAPI_VIDEO_SAMPLE_FORMAT_422,
    HAPI_VIDEO_SAMPLE_FORMAT_444
} HAPI_VIDEO_SAMPLE_FORMAT;


typedef enum _HAPI_VIDEO_CAPTURE_DITHER_MODE
{
    HAPI_VIDEO_CAPTURE_DITHER_MODE_TRUNCATE = 0,		//Truncate to 8 bits
    HAPI_VIDEO_CAPTURE_DITHER_MODE_10_BITS, 			//Keep 10 bits
    HAPI_VIDEO_CAPTURE_DITHER_MODE_0_3,				// See below comment(HAPI SAS 1.3)
    HAPI_VIDEO_CAPTURE_DITHER_MODE_0_7				// See below comment(HAPI SAS 1.3)
} HAPI_VIDEO_CAPTURE_DITHER_MODE;

//With enum HAPI_VIDEO_CAPTURE_DITHER_MODE_0_3 and HAPI_VIDEO_CAPTURE_DITHER_MODE_0_7,
//a random dither offset (0-3 or 0-7 respectively) is added to each 10-bit input value before discarding
//the two LSBs to produce an 8-bit value for the filters. Dither is used to reduce blocking artifacts.*/

typedef enum _HAPI_AUDIO_CAPTURE_SOURCE
{
    HAPI_AUDIO_CAPTURE_SOURCE_LR = 0,
    HAPI_AUDIO_CAPTURE_SOURCE_SPDIF,
    HAPI_AUDIO_CAPTURE_SOURCE_SDI,
    HAPI_AUDIO_CAPTURE_SOURCE_HDMI
} HAPI_AUDIO_CAPTURE_SOURCE;

typedef enum _HAPI_AUDIO_CAPTURE_MODE
{
    //Drop. No audio data is captured
    HAPI_AUDIO_CAPTURE_MODE_DROP = 0,
    //Frame. A single audio stream is captured in frame format.
    HAPI_AUDIO_CAPTURE_MODE_FRAME,
    // Frame - Frame. For the chip's AIN0 input, two audio streams are captured in frame format.
    //(only can be config with AEN encoder type MPEG-1 Layer II and AC3)
    HAPI_AUDIO_CAPTURE_MODE_FRAME_FRAME,
    //Sub-Frame. Two audio streams are captured in sub-frame format.
    //   (only can be config with AEN encoder type AAC)
    HAPI_AUDIO_CAPTURE_MODE_SUB_FRAME,
    // Sub-Frame - Sub-Frame. For the chip's AIN0 input, four audio streams are captured in
    // sub-frame format.  (will be enabled in the future)
    HAPI_AUDIO_CAPTURE_MODE_SUB_FRAME_SUB_FRAME,
    //Down mix. Down mix  5.1 channel audio to stereo format.
    HAPI_AUDIO_CAPTURE_MODE_DOWNMIX
} HAPI_AUDIO_CAPTURE_MODE;



typedef enum _HAPI_AUDIO_CAPTURE_SPDIF_INPUT
{
    HAPI_AUDIO_CAPTURE_SPDIF_INPUT_COAX = 0,
    HAPI_AUDIO_CAPTURE_SPDIF_INPUT_19977_IN,
    HAPI_AUDIO_CAPTURE_SPDIF_INPUT_AES_EBU,
    HAPI_AUDIO_CAPTURE_SPDIF_INPUT_OPTICAL
} HAPI_AUDIO_CAPTURE_SPDIF_INPUT;

typedef enum _HAPI_GPIO_PIN_ID
{	
    HAPI_GPIO_PIN_0 = 0,
    HAPI_GPIO_PIN_1,
    HAPI_GPIO_PIN_2,
    HAPI_GPIO_PIN_3,
    HAPI_GPIO_PIN_4,
    HAPI_GPIO_PIN_5,
    HAPI_GPIO_PIN_6,
    HAPI_GPIO_PIN_7,
    HAPI_GPIO_PIN_EXT_0,
    HAPI_GPIO_PIN_EXT_1,
    HAPI_GPIO_PIN_EXT_2,
    HAPI_GPIO_PIN_EXT_3,
    HAPI_GPIO_PIN_EXT_4,
    HAPI_GPIO_PIN_EXT_5,
    HAPI_GPIO_PIN_EXT_6,
    HAPI_GPIO_PIN_EXT_7,
    HAPI_GPIO_PIN_EXT_8,
    HAPI_GPIO_PIN_EXT_9,
    HAPI_GPIO_PIN_EXT_10,
    HAPI_GPIO_PIN_EXT_11,
    HAPI_GPIO_PIN_EXT_12,
    HAPI_GPIO_PIN_EXT_13,
    HAPI_GPIO_PIN_EXT_14,
    HAPI_GPIO_PIN_EXT_15,
    HAPI_GPIO_PIN_EXT_16,
    HAPI_GPIO_PIN_EXT_17,
    HAPI_GPIO_PIN_EXT_18,
    HAPI_GPIO_PIN_EXT_19,
    HAPI_GPIO_PIN_EXT_20,
    HAPI_GPIO_PIN_EXT_21,
    HAPI_GPIO_PIN_EXT_22,
    HAPI_GPIO_PIN_EXT_23,
    HAPI_GPIO_PIN_EXT_24,
    HAPI_GPIO_PIN_EXT_25,
    HAPI_GPIO_PIN_EXT_26,
    HAPI_GPIO_PIN_EXT_27,
    HAPI_GPIO_PIN_EXT_28,
    HAPI_GPIO_PIN_EXT_29,
    HAPI_GPIO_PIN_EXT_30,
    HAPI_GPIO_PIN_EXT_31,
    HAPI_GPIO_PIN_EXT_32,
    HAPI_GPIO_PIN_EXT_33,
    HAPI_GPIO_PIN_EXT_34,
    HAPI_GPIO_PIN_EXT_35,
    HAPI_GPIO_PIN_EXT_36,
    HAPI_GPIO_PIN_EXT_37,
    HAPI_GPIO_PIN_EXT_38,
    HAPI_GPIO_PIN_EXT_39,
    HAPI_GPIO_PIN_EXT_40,
    HAPI_GPIO_PIN_EXT_41,
    HAPI_GPIO_PIN_EXT_42,
    HAPI_GPIO_PIN_EXT_43,
    HAPI_GPIO_PIN_EXT_44,
    HAPI_GPIO_PIN_EXT_45,
    HAPI_GPIO_PIN_EXT_46,
    HAPI_GPIO_PIN_EXT_47,
    HAPI_GPIO_PIN_EXT_48,
    HAPI_GPIO_PIN_EXT_49,
    HAPI_GPIO_PIN_EXT_50,
    HAPI_GPIO_PIN_EXT_51,
    HAPI_GPIO_PIN_EXT_52,
    HAPI_GPIO_PIN_EXT_53,
    HAPI_GPIO_PIN_EXT_54,
    HAPI_GPIO_PIN_EXT_55,
    HAPI_GPIO_PIN_PCMCIA_0,
    HAPI_GPIO_PIN_PCMCIA_1,
    HAPI_GPIO_PIN_PCMCIA_2,
    HAPI_GPIO_PIN_PCMCIA_3,
    HAPI_GPIO_PIN_PCMCIA_4,
    HAPI_GPIO_PIN_PCMCIA_5,
    HAPI_GPIO_PIN_PCMCIA_6,
    HAPI_GPIO_PIN_PCMCIA_7,
    HAPI_GPIO_PIN_PCMCIA_8,
    HAPI_GPIO_PIN_PCMCIA_9,
    HAPI_GPIO_PIN_PCMCIA_10,
    HAPI_GPIO_PIN_PCMCIA_11,
    HAPI_GPIO_PIN_MAX		// Range only
} HAPI_GPIO_PIN_ID;


typedef enum _HAPI_AVL_DEVICE
{
    HAPI_AVL_INVALID = -1,    // Invalid AVL Device

    HAPI_AVL_CS5340 = 0,      // CS5340   : Stero Audio ADC
    HAPI_AVL_CS8416,          // CS8416   : SPDIF Receiver CS8416
    HAPI_AVL_TDA9955,         // TDA9955  : Triple 8 bit Video ADC
    HAPI_AVL_TDA19977,        // TDA19977 : Triple HDMI receiver
    HAPI_AVL_PCA9555_GS2970,  // PCA9555  : GPIO Expander for GS2970 SDI Input / ASI Receiver
    HAPI_AVL_PCA9555_GS2972,  // PCA9555  : GPIO Expander for GS2972 SDI Output / ASI Transmitter
    HAPI_AVL_THS8200,         // THS8200  : Video DAC - Do not use
    HAPI_AVL_SiI9134,         // SiI9134  : HDMI Tx - Do not use
    HAPI_AVL_PCA9555_AVMUX,   // PCA9555  : GPIO Expander for AV Muxer
    HAPI_AVL_PCA9555_AVMCTRL, // PCA9555  : GPIO Expander for AV Multi Control

    HAPI_AVL_SPI_GS2970,      // GS2970   : GS2970 SDI Input / ASI Receiver via SPI
    HAPI_AVL_SPI_GS2972,      // GS2972   : GS2972 SDI Output / ASI Transmitter via SPI

    HAPI_AVL_FPGA,            // FPGA     : FPGA device controlled by GPIO pins

    HAPI_AVL_DEVICE_MAX       // Range only.
} HAPI_AVL_DEVICE;

typedef enum _HAPI_ERROR_MSG_TYPE
{
    HAPI_ERR_PROC_ASSERT, 		       // DXT code asserted. This is an unexpected serious error that should not happen. If it is reported, host should reset DXT and board.
    HAPI_ERR_AUD_CODEC_MISMATCH, 	// Selected audio codec does not match actual incoming data format.
    HAPI_ERR_AUD_LEVEL_ALARM,		// Audio overflow or underflow on a specific channel (warning).
    HAPI_ERR_PCR_MISSING,		       // No PCR has been detected on  the configured PCR PID for  more than 500 ms.
    HAPI_ERR_UNSUPPORTED_CODEC,	// The actual encoded stream (video or audio) is coded in an unsupported codec.
    HAPI_ERR_FRAME_COUNTER_0,	       // The encoding or trnscoding flow frame counters is 0 in the past second after the encoding or transcoding flow is started.
    HAPI_ERR_MSG_MAX			       // Range only
} HAPI_ERROR_MSG_TYPE;

typedef enum _HAPI_ASPECT_RATIO
{
    HAPI_AR_UNKNOWN,			// Unknown
    HAPI_AR_4_BY_3,			    // 4:3
    HAPI_AR_14_BY_9,			// 14:9
    HAPI_AR_16_BY_9,			// 16:9
    HAPI_AR_GREATER_16_BY_9,    // Greater than 16:9
    HAPI_AR_MSG_MAX			// Range only
} HAPI_ASPECT_RATIO;

typedef enum _HAPI_AVL_DEVICE_CTRL_TYPE
{
    HAPI_AVL_DEVICE_CTRL_TYPE_I2C = 0,
    HAPI_AVL_DEVICE_CTRL_TYPE_SPI,
    HAPI_AVL_DEVICE_CTRL_TYPE_GPIO,
    HAPI_AVL_DEVICE_CTRL_TYPE_MAX
} HAPI_AVL_DEVICE_CTRL_TYPE;

typedef enum _HAPI_AVL_GPIO_CTRL_PIN
{
    HAPI_AVL_GPIO_CTRL_PIN_0 = 0,
    HAPI_AVL_GPIO_CTRL_PIN_1,
    HAPI_AVL_GPIO_CTRL_PIN_2,
    HAPI_AVL_GPIO_CTRL_PIN_3,
    HAPI_AVL_GPIO_CTRL_PIN_4,
    HAPI_AVL_GPIO_CTRL_PIN_5,
    HAPI_AVL_GPIO_CTRL_PIN_6,
    HAPI_AVL_GPIO_CTRL_PIN_7,
    HAPI_AVL_GPIO_CTRL_PIN_MAX
} HAPI_AVL_GPIO_CTRL_PIN;


typedef enum _HAPI_I2C_MONITOR_NUM
{
    HAPI_I2C_MONITOR_1 = 0,
    HAPI_I2C_MONITOR_2,
    HAPI_I2C_MONITOR_3,
    HAPI_I2C_MONITOR_4,
    HAPI_I2C_MONITOR_5,
    HAPI_I2C_MONITOR_6,
    HAPI_I2C_MONITOR_7,
    HAPI_I2C_MONITOR_8,
    HAPI_I2C_MONITOR_9,
    HAPI_I2C_MONITOR_10,
    HAPI_I2C_MONITOR_11,
    HAPI_I2C_MONITOR_12,
    HAPI_I2C_MONITOR_13,
    HAPI_I2C_MONITOR_14,
    HAPI_I2C_MONITOR_15,
    HAPI_I2C_MONITOR_16,
    HAPI_I2C_MONITOR_MAX		// Counter only. Not intended to be
					// used as a Monitor number.
} HAPI_I2C_MONITOR_NUM;

typedef enum _HAPI_I2C_MONITOR_ACTION
{
    HAPI_I2C_MONITOR_NO_ACTION = 0,	// No action
    HAPI_I2C_MONITOR_ACTION_STOP,	// Stop encoding flow.
    HAPI_I2C_MONITOR_ACTION_MAX	// Counter only. Not intended
						// to be used as an action.
} HAPI_I2C_MONITOR_ACTION;

typedef struct _XCODE_VIDEO_PARAMS
{
    Uint32 bitMask;
    Uint32 StreamID;
    Uint32 OutputPID;
    HAPI_VIDEO_CODEC VideoCodecInputFormat;
    HAPI_VIDEO_CODEC VideoCodecOutputFormat;
    Uint32 VideoOutputWidth;
    Uint32 VideoOutputHeight;
    HAPI_VIDEO_OUTPUT_MODE  VideoOutputMode;
    HAPI_VIDEO_OUTPUT_FRAME_RATE VideoOutputFrameRate;
    Uint32 VideoOutputBitrate;
    HAPI_RATE_CONTROL RateControl;
    Uint32 VBRMin;
    Uint32 VBRMax;
    HAPI_CODING_MODE CodingMode;
    HAPI_VIDEO_PROFILE Profile;
    Uint32 Level;

    Uint32 TSBitrate;
    HAPI_LATENCY Latency;
    Boolean    bInsertIFrame;
    Boolean    bCabacCoding;
    Boolean    bDeblockFilter;
    Boolean    bIasIDR;
    Uint32       PMTVersion;    
    Uint16  NumBFrames;					// Range[0,7]
    Uint16  reserved;
    Uint32  bAdaptiveSmoothing;                 // Boolean, whether to enable video smoothing before encoding.
    Int32   HorizontalSmoothingOffset;  // Range [-5, 2]. Unused when bAdaptiveSmoothing is 0. Additional filter coefficient index offset. The smaller the value, the smoother the prefilterred video.
    Int32   VerticalSmoothingOffset;      // Range [-5, 2]. Unused when bAdaptiveSmoothing is 0. Additional filter coefficient index offset. The smaller the value, the smoother the prefilterred video.
    Uint32  GOPSize;                                // GOP size in frames. For H.264 output only. No effect for MPEG2 output. If 0, default GOP size is used, which is 1.8 times frame rate.

    Uint8  ucPad[HAPI_MSG_MAX_PAD - 11*4];
}XCODE_VIDEO_PARAMS;

typedef struct _XCODE_AUDIO_PARAMS
{
    Uint32 bitMask;
    Uint32 StreamID;
    Uint32 OutputPID;
    HAPI_AUDIO_CODEC AudioCodecInputFormat;
    HAPI_AUDIO_CODEC AudioCodecOutputFormat;
    HAPI_AUDIO_OUTPUT_MODE AudioOutputMode;
    HAPI_AUDIO_SAMPLE_RATE AudioOutputSamplingRate;
    HAPI_AUDIO_BITRATE AudioOutputBitrate;
    Uint32  bAudioPassthru;//If true, audio is passthru; otherwise audio is transcoded
    Uint32  bAGCEnable;		// 0: disable Audio ouput AGC; 1: Enable Audio output AGC
    Uint16  MaxSample;
    Uint16  reserved;
    Uint8  ucPad[HAPI_MSG_MAX_PAD - 11*4];
}XCODE_AUDIO_PARAMS;


typedef struct _ENCODE_VIDEO_PARAMS
{
    Uint32	bitMask;		// Indicate which memeber variable following will be modified
    Uint32	StreamID;	// Video elementary stream ID
    Uint32	OutputPID;	// Video PID in output TS
    HAPI_VIDEO_CAPTURE_SOURCE	VideoCapSource;		// Indicate which is the video input source
    Uint32	VideoCapWidth;
    Uint32	VIdeoCapHeight;
    HAPI_VIDEO_OUTPUT_MODE	VideoCapFormat;		// interlaced, progressive or psf?
    HAPI_VIDEO_OUTPUT_FRAME_RATE	VideoCapFrameRate;
    HAPI_VIDEO_CODEC	VideoCodecOutputFormat;
    Uint32	VideoOutputWidth;
    Uint32	VideoOutputHeight;
    HAPI_VIDEO_OUTPUT_MODE	VideoOutputMode;
    HAPI_VIDEO_OUTPUT_FRAME_RATE	VideoOutputFrameRate;
    Uint32	VideoOutputBitrate;
    HAPI_RATE_CONTROL	RateControl;
    Uint32	VBRMin;
    
    Uint32	VBRMax;
    HAPI_CODING_MODE	CodingMode;					// Indicate videooutput stream is frame,field,mbaff or paff encoded.
    HAPI_VIDEO_PROFILE	Profile;						// Designate the codec profile
    HAPI_VIDEO_H264_LEVEL	Level;					// Designate the codec level
    Uint32	TSBitrate;								// Ts output bitrate
    HAPI_LATENCY	Latency;						// This parameter specifies the level of system delay from input
    Boolean    bInsertIFrame;
    Boolean    bCabacCoding;
    Boolean    bDeblockFilter;
    Boolean    bIasIDR;
    Uint32       PMTVersion;
    Uint16      NumBFrames;					// Range[0,7]
    Uint16      reserved;
    Uint32     bAdaptiveSmoothing;                 // Boolean, whether to enable video smoothing before encoding.
    Int32      HorizontalSmoothingOffset;  // Range [-5, 2]. Unused when bAdaptiveSmoothing is 0. Additional filter coefficient index offset. The smaller the value, the smoother the prefilterred video.
    Int32      VerticalSmoothingOffset;      // Range [-5, 2]. Unused when bAdaptiveSmoothing is 0. Additional filter coefficient index offset. The smaller the value, the smoother the prefilterred video.
    Uint32     GOPSize;                                // GOP size in frames. For H.264 output only. No effect for MPEG2 output. If 0, default GOP size is used, which is 1.8 times frame rate.

    Uint8  ucPad[HAPI_MSG_MAX_PAD - 15*4];
}ENCODE_VIDEO_PARAMS;


typedef struct _ENCODE_AUDIO_PARAMS
{
    Uint32	bitMask;
    Uint32	StreamID;		// Audio elementary stream ID
    Uint32	OutputPID;		// Audio PID in output TS

    Uint32	StreamID_1;		// Audio elementary stream ID for the second stream
    Uint32	OutputPID_1;		// Audio PID in output TS for the second stream

    HAPI_AUDIO_CAPTURE_SOURCE	AudioCapSource;
    HAPI_AUDIO_CAPTURE_SPDIF_INPUT	AudioCapSPDIFInput;
    HAPI_AUDIO_SAMPLE_RATE		AudioCapSampleRate;

    HAPI_AUDIO_CAPTURE_MODE	AudioCapMode;
    HAPI_AUDIO_CODEC	AudioCodecOutputFormat;
    HAPI_AUDIO_OUTPUT_MODE	AudioOutputMode;
    HAPI_AUDIO_SAMPLE_RATE	AudioOutputSamplingRate;
    HAPI_AUDIO_BITRATE	AudioOutputBitrate;

/*the following 5 parameters are for the second audio stream*/
    HAPI_AUDIO_CAPTURE_MODE	AudioCapMode_1;
    HAPI_AUDIO_CODEC	AudioCodecOutputFormat_1;
    HAPI_AUDIO_OUTPUT_MODE	AudioOutputMode_1;
    HAPI_AUDIO_SAMPLE_RATE	AudioOutputSamplingRate_1;
    HAPI_AUDIO_BITRATE	AudioOutputBitrate_1;
    
    Uint32 bAudioPassthru;//If true, audio is passthrough; otherwise audio is encoded
    Uint32 bAudioPassthru_1;
    Uint32 bAGCEnable;	  // 0: disable Audio ouput AGC; 1: Enable Audio output AGC
    Uint16  MaxSample;
    Uint16  reserved;

    Uint8  ucPad[HAPI_MSG_MAX_PAD - 12*4];//FGR - BUGBUG - padding didn't change??
}ENCODE_AUDIO_PARAMS;

typedef struct _SYS_LOG_PARAMS
{
    Uint32 bitMask;
	Uint32 errorLoggingEnable;

	Uint8  ucPad[HAPI_MSG_MAX_PAD - 2*4];
}SYS_LOG_PARAMS;

typedef struct _HAPI_TRANSCODE_PARAMS
{
    Uint32 bitMask;
    XCODE_VIDEO_PARAMS VideoParams;
    XCODE_AUDIO_PARAMS AudioParams;
    SYS_LOG_PARAMS     LogParams;

	Uint8  ucPad[HAPI_MSG_MAX_PAD - 1*4];
} HAPI_TRANSCODE_PARAMS;

typedef struct _HAPI_ENCODE_PARAMS
{
    Uint32 bitMask;
    ENCODE_VIDEO_PARAMS VideoParams;
    ENCODE_AUDIO_PARAMS AudioParams;
    SYS_LOG_PARAMS     LogParams;

    Uint8  ucPad[HAPI_MSG_MAX_PAD - 1*4];
}HAPI_ENCODE_PARAMS;

typedef struct _HAPI_AV_DATA_INFO
{
	Uint32 channel; // channel index
	Uint32 requestSize;
	Uint8 *buf;

	Uint8  ucPad[HAPI_MSG_MAX_PAD - 3*4];
}HAPI_AV_DATA_INFO ;

typedef struct _HAPI_SET_PARAM
{
    Uint32 bitMask;
    Uint32 index; //channel index
    Uint32 InputAudioPID;
    Uint32 InputVideoPID;
    Uint32 InputPCRPID;
    Uint32 OutputPCRPID;
    Uint32 SubtitlePID; // Not support now
    Uint32 TeletextPID; // Not support now
    Uint32 bTSSerial; // TS channel interface Serial/Parallel mode.
    Uint32 bChMsbFirst; // TS channel inter byte endianess.
    Uint32 ParamType; // Encode, decode or transcode parameters

    union _params
    {
        HAPI_ENCODE_PARAMS encodeParam;
        HAPI_DECODE_PARAMS decodeParam;
        HAPI_TRANSCODE_PARAMS transcodeParam;
    }params;

    Uint8  ucPad[HAPI_MSG_MAX_PAD - 11*4];
}HAPI_SET_PARAM, HAPI_GET_PARAM;

typedef struct _HAPI_FWUPGRADE_PARAM
{
	unsigned char filePath[256];	// The new target image file handler
	Uint32	bytesPerTransfer;		// define the bytes # per transfer.
	Uint32	targetAddress;			// The start address where to burn the image
	Uint32	swapMode;
}HAPI_FWUPGRADE_PARAM;

typedef struct _HAPI_LOGO_CONFIG_PARAM
{
    Uint32    chIndex;
    Uint32    logoIndex;
    Uint32    width;
    Uint32    height;
    Uint32    x;
    Uint32    y;
   // Uint16    reserved;  //in order to 32 bits align
    Uint8     logoData[MAX_LOGO_WIDTH*MAX_LOGO_HEIGHT*BYTE_PER_PIXEL];
}HAPI_LOGO_CONFIG_PARAM;

typedef struct _HAPI_I2C_WRITE_PARAM
{
    Uint16    addr;
    Uint16    subAddrLen;
    Uint8      pSubAddr[MAX_I2C_SUBADDR_LENGTH];
    Uint8      pData[MAX_I2C_DATA_LENGTH];
    Uint16    datalen;
    Uint16    reserved; // in order to 32 bits align
}HAPI_I2C_WRITE_PARAM;

typedef struct _HAPI_I2C_READ_PARAM
{
    Uint16    addr;
    Uint16    subAddrLen;
    Uint8      pSubAddr[MAX_I2C_SUBADDR_LENGTH];
    Uint8      pData[MAX_I2C_DATA_LENGTH];
    Uint16    datalen;
    Uint16    reserved;// in order to 32 bits align
}HAPI_I2C_READ_PARAM;

typedef struct _HAPI_I2C_CALLBACK_PARAM
{
    Uint16    addr;
    Uint16    subAddrLen;
    Uint8      pSubAddr[MAX_I2C_SUBADDR_LENGTH];
    Uint8      pData[MAX_I2C_DATA_LENGTH];
    Uint16    dataLen;
    Uint16    reserved;
    HAPI_I2C_MONITOR_ACTION action;
    Uint32    ch;
}HAPI_I2C_CALLBACK_PARAM;

typedef struct _HAPI_I2C_MONITOR_PARAM
{
    Uint16    addr;
    Uint16    subAddrLen;
    Uint8      pSubAddr[MAX_I2C_SUBADDR_LENGTH];
    Uint16    dataLen;
    Uint8      changeNotify;
    Uint8      reserved;
    Uint32    mask;
    Uint32    numMonitoredVal;
    Uint32    monitoredValues[MAX_MONITORED_VALUE_LENGTH];
    HAPI_I2C_MONITOR_ACTION action;
    Uint32    ch;
    HapiErrCode (*Callback)(HAPI_I2C_CALLBACK_PARAM *callbackParam);

}HAPI_I2C_MONITOR_PARAM;


typedef struct _HAPI_AVL_I2C_DEVICE
{
    Uint32  bus;
    Uint32  addr;
} HAPI_AVL_I2C_DEVICE;

typedef struct _HAPI_AVL_SPI_DEVICE
{
    Uint32  cs;
    Uint32  gpio;
} HAPI_AVL_SPI_DEVICE;

typedef struct _HAPI_AVL_GPIO_DEVICE
{
    Uint8   pin[HAPI_AVL_GPIO_CTRL_PIN_MAX];
} HAPI_AVL_GPIO_DEVICE;

typedef struct _HAPI_AVL_SUPPORT
{
    HAPI_AVL_DEVICE             dev; // AVIO device idendifier, e.g. for Llama HDIO: \ref CW_HDAVIOC_AVL_DEVICE "CW_HDAVIOC_AVL_DEVICE"
    HAPI_AVL_DEVICE_CTRL_TYPE   type; // AVIO device type to indicate which control i/f is used
    union {
        HAPI_AVL_I2C_DEVICE     i2c; // I2C device descriptor
        HAPI_AVL_SPI_DEVICE     spi; // SPI device descriptor
        HAPI_AVL_GPIO_DEVICE    gpio; // GPIO device descriptor
    } ctrl;
} HAPI_AVL_SUPPORT;

typedef struct _HAPI_SET_AVL_PARAM
{
    Uint16 nDevs;
    Uint16 i2cBus;
    Uint16 gpioSCL;
    Uint16 gpioSDA;
    HAPI_AVL_SUPPORT avlDev[HAPI_AVL_DEVICE_MAX];
} HAPI_SET_AVL_PARAM;

typedef struct _HAPI_QUERY_STRUCT
{
    Uint32 index;
    Uint32 bitMask;
    Uint16 state;
    Uint16 frameRate;
//    Uint16 isInterlaced;
//    Uint16 videoWidth;
//    Uint16 videoHeight;
    HAPI_ASPECT_RATIO ar;
    Uint64 pcr;
    Uint32 inFrameCount;
    Uint32 outFrameCount;        
//    Uint32 audioSamplingRate;
//    Uint32 audioBitrate;
}HAPI_QUERY_STRUCT;

typedef struct _HAPI_ERR_PARAM_ASSERT
{
    Uint8 text[56];
    Uint32 Reserved1;
    Uint32 Reserved2;
}HAPI_ERR_PARAM_ASSERT;

typedef struct _HAPI_ERR_PARAM_AUD_CODEC_MISMATCH
{
    HAPI_AUDIO_CODEC codecSelected;
    HAPI_AUDIO_CODEC codecReceived;
    Uint32 Reserved;
}HAPI_ERR_PARAM_AUD_CODEC_MISMATCH;

typedef struct _HAPI_ERR_PARAM_AUD_LEVEL
{
    Uint32 bOverflow;
    Uint32 Reserved1;
    Uint32 Reserved2;
}HAPI_ERR_PARAM_AUD_LEVEL;

typedef struct _HAPI_ERR_PARAM_PCR_MISSING
{
    Uint32 pcrPID;
    Uint32 Reserved1;
    Uint32 Reserved2;
}HAPI_ERR_PARAM_PCR_MISSING;

typedef struct _HAPI_ERR_PARAM_UNSUPPORTED_CODEC
{
    HAPI_AUDIO_CODEC audCodec;
    HAPI_VIDEO_CODEC vidCodec;
    Uint32 Reserved;
}HAPI_ERR_PARAM_UNSUPPORTED_CODEC;

typedef struct _HAPI_ERR_PARAM_FLOW_STALL
{
    Uint32 seconds;     // Seconds after start in which this frame counter 0 is detected. 
    Uint16 vInCount;    // In case of encoding, it is the number of video frames captured in the past second. In case of transcoding, it is the number of video frames decoded in the past second.
    Uint16 vResCount;   // Number of video frames rescaled in the past second.
    Uint16 vEncCount;   // Number of video frames encoded in the past second.
    Uint32 Reserved;
}HAPI_ERR_PARAM_FRAME_COUNTER_0;

typedef union _HAPI_ERR_PARAM
{
    HAPI_ERR_PARAM_ASSERT assertErr;
    HAPI_ERR_PARAM_AUD_CODEC_MISMATCH audCodecMismatch;
    HAPI_ERR_PARAM_AUD_LEVEL audLevel;
    HAPI_ERR_PARAM_PCR_MISSING pcrMiss;
    HAPI_ERR_PARAM_UNSUPPORTED_CODEC unSupportedCodec;    
    HAPI_ERR_PARAM_FRAME_COUNTER_0 frCounter0;
}HAPI_ERR_PARAM;

#ifndef HAUPPAUGE
typedef HapiErrCode (*HAPI_AVDataSend) (HAPI_AV_DATA_INFO *info);
typedef HapiErrCode (*HAPI_AVDataReceive) (HAPI_AV_DATA_INFO *info);

typedef HapiErrCode (*HAPI_I2CMonitorCallback)(HAPI_I2C_CALLBACK_PARAM *callbackParam);
#else
typedef HapiErrCode (*HAPI_AVDataSend) (HAPI_AV_DATA_INFO *info, void *context);
typedef HapiErrCode (*HAPI_AVDataReceive) (HAPI_AV_DATA_INFO *info, void *context);

typedef HapiErrCode (*HAPI_I2CMonitorCallback)(HAPI_I2C_CALLBACK_PARAM *callbackParam, void *context);
#endif
typedef HapiErrCode (*HAPI_ErrorMsgCallback)(HAPI_ERROR_MSG_TYPE errorType, void *contexts, HAPI_ERR_PARAM *param);
#endif
