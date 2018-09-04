
#pragma once

#ifndef ENCODERIF_H
#define ENCODERIF_H

#include <stdint.h>

// ~ 4

typedef enum
{
	STRMF_TS,
	STRMF_MP4,
	STRMF_BDAV

} STREAM_FORMAT;

typedef enum
{
	ENCM_CBR,
	ENCM_VBR

} ENCODE_MODE;

#ifndef HAUPPAUGE
typedef enum
{
	// AVC
	MP4P_EAVENC_MPV_PROFILE_BASE = 1,
	MP4P_EAVENC_MPV_PROFILE_MAIN, //2
	MP4P_EAVENC_MPV_PROFILE_HIGH, //3
	MP4P_EAVENC_MPV_PROFILE_422,  //4
	MP4P_EAVENC_MPV_PROFILE_HIGH10, //5
	MP4P_EAVENC_MPV_PROFILE_444 // 6

} MPEG4_PROFILE;

typedef enum
{
	// AVC
	MP4L_EAVENC_MPV_LEVEL_LOW		= 1,
	MP4L_EAVENC_MPV_LEVEL_MAIN 		= 2,
	MP4L_EAVENC_MPV_LEVEL_HIGH1440  = 3,
	MP4L_EAVENC_MPV_LEVEL_HIGH 		= 4,
	MP4L_EAVENC_MPV_LEVEL1 			= 1,
	MP4L_EAVENC_MPV_LEVEL1_B 		= 10,
	MP4L_EAVENC_MPV_LEVEL1_1 		= 11,
	MP4L_EAVENC_MPV_LEVEL1_2 		= 12,
	MP4L_EAVENC_MPV_LEVEL1_3 		= 13,
	MP4L_EAVENC_MPV_LEVEL2 			= 2,
	MP4L_EAVENC_MPV_LEVEL2_1 		= 21,
	MP4L_EAVENC_MPV_LEVEL2_2 		= 22,
	MP4L_EAVENC_MPV_LEVEL3 			= 3,
	MP4L_EAVENC_MPV_LEVEL3_1 		= 31,
	MP4L_EAVENC_MPV_LEVEL3_2 		= 32,
	MP4L_EAVENC_MPV_LEVEL4 			= 4,
	MP4L_EAVENC_MPV_LEVEL4_1 		= 41,
	MP4L_EAVENC_MPV_LEVEL4_2 		= 42,
	MP4L_EAVENC_MPV_LEVEL5 			= 5,
	MP4L_EAVENC_MPV_LEVEL5_1		= 51

} MPEG4_LEVEL;
#endif

typedef enum
{
	AUDF_AAC,
	AUDF_AC3_2CH,
	AUDF_AC3_PASSTHRU,
	AUDF_PCM

} AUDIO_FORMAT;

typedef enum
{
	ENCC_OUT_STREAM_FORMAT = 0,

	ENCC_OUT_VIDEO_BITRATE = 100,
	ENCC_OUT_VIDEO_PEAK_BITRATE = 101,
	ENCC_OUT_VIDEO_MODE = 102,
	ENCC_OUT_VIDEO_PROFILE = 103,
	ENCC_OUT_VIDEO_LEVEL = 104,

	ENCC_OUT_AUDIO_FORMAT = 200,
	ENCC_OUT_AUDIO_BITRATE = 201,

} ENCODERCAPS;


#ifdef HAUPPAUGE //moved here from CaptureIF.h and Exeapi.h

// {6337A7D7-9F2F-4ff7-8ECE-14A549D48C2E}
static const GUID HAUP_AUDIO_PROPERTY = 
{ 0x6337a7d7, 0x9f2f, 0x4ff7, { 0x8e, 0xce, 0x14, 0xa5, 0x49, 0xd4, 0x8c, 0x2e } };

// D08M04Y11
// {33438E86-2CA0-4428-8214-601E3496FF8D}
static const GUID HAUP_VIDEO_PROPERTY = 
{ 0x33438e86, 0x2ca0, 0x4428, { 0x82, 0x14, 0x60, 0x1e, 0x34, 0x96, 0xff, 0x8d } };

// {9BA6C1A9-D872-4e89-81F2-B3F9DA1F3E32}
static const GUID HAUP_SYSTEM_PROPERTY = 
{ 0x9ba6c1a9, 0xd872, 0x4e89, { 0x81, 0xf2, 0xb3, 0xf9, 0xda, 0x1f, 0x3e, 0x32 } };

//****************************
// Audio Properties
//****************************

#define DEFAULT_AUDIO_ENCODER_BITRATE		AUDIO_BITRATE_192000

typedef enum
{
	AUDIO_BITRATE_NULL = 0,
	AUDIO_BITRATE_256000 = 256000,
	AUDIO_BITRATE_192000 = 192000,
	AUDIO_BITRATE_160000 = 160000,
	AUDIO_BITRATE_128000 = 128000,
	AUDIO_BITRATE_96000  = 96000,
	AUDIO_BITRATE_64000  = 64000,

	//FGR - these also work on Siena
	AUDIO_BITRATE_32000  = 32000,
	AUDIO_BITRATE_48000  = 48000,
	AUDIO_BITRATE_56000  = 56000,
	AUDIO_BITRATE_80000  = 80000,
	AUDIO_BITRATE_112000 = 112000,
	AUDIO_BITRATE_224000 = 224000,
	AUDIO_BITRATE_320000 = 320000,
	AUDIO_BITRATE_384000 = 384000,

} AUDIO_BITRATES, *PAUDIO_BITRATES;

typedef enum
{
	AUDIO_SAMPLE_RATE_48000 = 48000,
	AUDIO_SAMPLE_RATE_44100 = 44100,
	AUDIO_SAMPLE_RATE_32000 = 32000,
	AUDIO_SAMPLE_RATE_24000 = 24000,
	AUDIO_SAMPLE_RATE_22050 = 22050,
	AUDIO_SAMPLE_RATE_16000 = 16000,
	AUDIO_SAMPLE_RATE_12000 = 12000,
	AUDIO_SAMPLE_RATE_11025 = 11025,
	AUDIO_SAMPLE_RATE_8000  = 8000

} AUDIO_SAMPLE_RATES, *PAUDIO_SAMPLE_RATES;

typedef struct
{
	AUDIO_BITRATES bit_rate;
	AUDIO_SAMPLE_RATES sample_rate_48;
	AUDIO_SAMPLE_RATES sample_rate_441;

} AudEncSettings, *pAudEncSettings;

typedef enum
{
	BOOST_OFF,
	BOOST_ON

} AUDBOOST_MODE, *PAUDBOOST_MODE;


#if 1//HCW_E5BDA
//FGR - extensions for Siena
#define AUDIO_CS_TYPE_MASK		0x8000700
#define AUDIO_CS_TYPE_ERROR		0x8000000
#define AUDIO_CS_TYPE_PCM			0x000
#define AUDIO_CS_TYPE_DIGITAL		0x100
#define AUDIO_CS_TYPE_DTS_LD		0x200
#define AUDIO_CS_TYPE_DTS_CD		0x400

#define AUDIO_CS_SUBTYPE_MASK			0x7FF
#define AUDIO_CS_SUBTYPE_PCM			0x000
#define AUDIO_CS_SUBTYPE_DIGITAL_NULL	0x100
#define AUDIO_CS_SUBTYPE_DIGITAL_AC3	0x101

typedef struct //Siena
{
	DWORD	i2s_rate; //IAudioMux::getAudioRates()
	DWORD	cs_rate;  //IAudioMux::getAudioRates(); Sample rate from SPDIF Channel Status eg. 44100, 48000, 32000
	DWORD	cs_type;  //IAudioMux::getAudioRates(); see AUDIO_CS_* defines
	
	DWORD	spdif_capable; //Device::isAC3capable()
	DWORD	ac3_enabled;   //Device::isAC3enabled()
	DWORD	ac3_supported; //Device::isAC3supported()

	DWORD	aux_audio_capable; //HW support for 2nd Audio channel (Mic In)
	DWORD	aux_audio_detect;  //Input jack detects plug present
	DWORD	aux_audio_enabled; //encoder will output 2nd audio stream
} AudStatus, *pAudStatus;

#endif//HCW_E5BDA

typedef enum
{
	KSPROPERTY_HAUP_AUDIO_ENCODER,
	KSPROPERTY_HAUP_AUDIO_BOOST_MODE,

	KSPROPERTY_HAUP_AUDIO_STATUS //Siena

} KSPROPERTY_HAUP_AUDIO;

//****************************
// Video Properties
//****************************

typedef enum
{
	AR_AUTO,
	AR_MANUAL

} ASPECT_RATIO_MODE, *PASPECT_RATIO_MODE;

typedef enum
{
	AR_4_3,
	AR_16_9

} ASPECT_RATIO_MANUAL, *PASPECT_RATIO_MANUAL;

typedef struct
{
	ASPECT_RATIO_MODE mode;
	ASPECT_RATIO_MANUAL sdi;
	ASPECT_RATIO_MANUAL sdp;

} AspectRatio, *pAspectRatio;

typedef enum
{
	PVR_OFF,
	PVR_ON

} PVR_MODE, *PPVR_MODE;

typedef enum
{
	TBC_OFF,
	TBC_ON

} TBC_MODE, *PTBC_MODE;

typedef enum
{
	SCALER_OFF,
	SCALER_ON

} SCALER_MODE, *PSCALER_MODE;

typedef enum
{
	SCALE_RES_NONE,
	SCALE_RES_960x540,
	SCALE_RES_720x480,
	SCALE_RES_640x480,
	SCALE_RES_640x360,
	SCALE_RES_480x360,
	SCALE_RES_480x270,
	SCALE_RES_1280x720,
	SCALE_RES_NULL	//must be last

} SCALE_RESOLUTION, *PSCALE_RESOLUTION;

typedef enum
{
	SCALE_FPS_NONE,
	SCALE_FPS_30,
	SCALE_FPS_25,
	SCALE_FPS_15,
	SCALE_FPS_NULL	//must be last

} SCALE_FPS, *PSCALE_FPS;

typedef struct
{
	SCALER_MODE mode;
	SCALE_RESOLUTION res1080I;
	SCALE_RESOLUTION res720P;
	SCALE_RESOLUTION resSDP;
	SCALE_RESOLUTION resSDI;
	SCALE_FPS fps1080I;
	SCALE_FPS fps720P;
	SCALE_FPS fpsSDP;
	SCALE_FPS fpsSDI;
	//FGR - everything below this point was added to the property after Colossus release;
	// make sure you don't change the orderings, and only add to the end of the struct
	SCALE_RESOLUTION res1080P;
	SCALE_FPS fps1080P;
} ScalerSettings, *pScalerSettings;

typedef enum
{
	COMB_OFF,
	COMB_ON

} COMB_FILTER_MODE, *PCOMB_FILTER_MODE;

typedef enum
{
	NOISE_OFF,
	NOISE_ON

} NOISE_FILTER_MODE, *PNOISE_FILTER_MODE;

typedef struct
{
	COMB_FILTER_MODE CombMode;
	int CombDotCrawlDetect;			//0: default, 1-100%
	int CombLumaMotion;
	int CombChromaMotion;
	int CombResponse;

	NOISE_FILTER_MODE NoiseMode;
	int TempLumaMotion;
	int TempChromaMotion;
	int SpatialLumaEdge;
	int SpatialChromaEdge;
	int SpatialStrength;

} FilterSettings, *pFilterSettings;

typedef struct
{
	DWORD Res_sdi;
	DWORD Res_sdi_peak;
	DWORD Res_sdi_mode;
	DWORD Res_sdp;
	DWORD Res_sdp_peak;
	DWORD Res_sdp_mode;
	DWORD Res_hd720p;
	DWORD Res_hd720p_peak;
	DWORD Res_hd720p_mode;
	DWORD Res_hd1080i;
	DWORD Res_hd1080i_peak;
	DWORD Res_hd1080i_mode;
#ifdef HCW_E5BDA
	DWORD Res_hd1080p;
	DWORD Res_hd1080p_peak;
	DWORD Res_hd1080p_mode;
#endif
} ResVideoBitRate, *pResVideoBitRate;

typedef enum
{
	SRC_ASPECT_UNKNOWN,
	SRC_ASPECT_4x3,
	SRC_ASPECT_16x9

} SRC_ASPECT;

typedef struct
{
	DWORD		srcWidth;
	DWORD		srcHeight;
	DWORD		srcFrameRate;
	BOOL		bSrcProgressive;
	SRC_ASPECT	srcAspectRatio;
	DWORD		srcVideoIdCode;

} SrcInfo, *pSrcInfo;

typedef enum
{
	H264_PROFILE_DEFAULT = 0,
	H264_PROFILE_BASE,
	H264_PROFILE_MAIN,
	H264_PROFILE_HIGH,

} H264_PROFILE;

typedef enum
{
	H264_LEVEL_DEFAULT = 0,
	H264_LEVEL_1,
	H264_LEVEL_1B,
	H264_LEVEL_1_1,
	H264_LEVEL_1_2,
	H264_LEVEL_1_3,
	H264_LEVEL_2,
	H264_LEVEL_2_1,
	H264_LEVEL_2_2,
	H264_LEVEL_3,
	H264_LEVEL_3_1,
	H264_LEVEL_3_2,
	H264_LEVEL_4,
	H264_LEVEL_4_1,
	H264_LEVEL_4_2,
	H264_LEVEL_5,
	H264_LEVEL_5_1

} H264_LEVEL;

typedef struct
{
	H264_PROFILE profile;
	H264_LEVEL   level;

} H264Settings, *pH264Settings;

typedef enum
{
	//These are defined to match CXFALCON_LATENCY in hcwE5bda\inc\CxBtrflyControl.h
	ENC_LATENCY_LOW  = 0,
	ENC_LATENCY_HIGH = 1,
	ENC_LATENCY_MED  = 2
} ENC_LATENCY;

typedef struct //Siena
{
	ENC_LATENCY latency;
} EncLatency, *pEncLatency;

typedef enum
{
	KSPROPERTY_HAUP_VIDEO_ASPECT_RATIO,
	KSPROPERTY_HAUP_VIDEO_TBC_MODE,
	KSPROPERTY_HAUP_VIDEO_SCALER,
	KSPROPERTY_HAUP_VIDEO_FILTER,
	KSPROPERTY_HAUP_VIDEO_BITRATE,
	KSPROPERTY_HAUP_VIDEO_SRC_INFO,
	KSPROPERTY_HAUP_VIDEO_H264_SETTINGS,

	KSPROPERTY_HAUP_VIDEO_ENC_LATENCY, //Siena

} KSPROPERTY_HAUP_VIDEO;

//****************************
// System  Properties
//****************************

typedef char HCW_REVISION[5];
typedef HCW_REVISION *PHCW_REVISION;

typedef struct
{
	BOOL	_1080P60;
	BOOL	_1080P50;
	BOOL	_1080P30;
	BOOL	_1080P25;
	BOOL	_1080P24;
	BOOL	_1080I60;
	BOOL	_1080I50;

	BOOL	_720P60;
	BOOL	_720P50;

	BOOL	_576P50_16x9;
	BOOL	_576P50_4x3;
	BOOL	_576I50_16x9;
	BOOL	_576I50_4x3;

	BOOL	_480P60_16x9;
	BOOL	_480P60_4x3;
	BOOL	_480I60_16x9;
	BOOL	_480I60_4x3;

} Edid_VideoFormats;

typedef struct
{
	BOOL	AC3_6Ch;
	BOOL	LPCM_2Ch;

} Edid_AudioFormats;

typedef	struct
{
	Edid_VideoFormats Video;
	Edid_AudioFormats Audio;

} Edid_Formats;

typedef struct
{
	Edid_Formats SupportedFormats;
	Edid_Formats AdvertisedFormats;

} EdidConfig, *pEdidConfig;


#if 1//HCW_E5BDA
typedef enum ENC_ASPECT_RATIO
{
    ENC_AR_UNKNOWN,			// Unknown
    ENC_AR_4_BY_3,			// 4:3
    ENC_AR_14_BY_9,			// 14:9
    ENC_AR_16_BY_9,			// 16:9
    ENC_AR_GREATER_16_BY_9, // Greater than 16:9
} ENC_ASPECT_RATIO;

typedef struct //Siena
{
	DWORD	power_time_left;//in Sec; 0=not powered up
	DWORD	isReady;
	DWORD	isStarted;
	DWORD	isPaused; //Note: Running = isStarted && !isPaused

	DWORD	bling_options;//current bling options, based on SetRecordLED()
	DWORD	LED_state; //Bitmask; 1=Green Bling Ring; 2=Red Error LED; 4=Green Power LED; 8=Blue LED; 0x10=Blue Bling Ring
				//Note: LED3 state needs to come from Device::getLEDState(3)

	DWORD	start_latency;//in ms (updated on encoder startup)
	DWORD	payload_delta;//in ms (updated on each data packet arrival)

	DWORD	hdmi_fmt;//0=No Input format configured; else it's the HDMI VIC for the input video format

	DWORD	cvbs_svid_detect; //0=HW can't detect CVBS cable, 1=YPrPb or no cable detected, 2=CVBS cable detected

	LONG    logo_x_pos;//-1 means no current logo
	LONG    logo_y_pos;
	DWORD	logo_width;
    DWORD	logo_height;

	uint64_t last_PCR;//updated on encoder stop, or change of encoding config
	ENC_ASPECT_RATIO  AR;
    DWORD	VideoWidth;//Output Video Width (could be scaled)
    DWORD	VideoHeight;//Output Video Height (could be scaled)
    DWORD	VideoMode;//0=Interlaced, 1=Progressive, 2=PSF
    DWORD	VideoFrameRate;//eg. 30fps = 3000, 29.97 = 2997; (could be scaled)
    
	DWORD	VideoBitrate;// in bps
    DWORD	RateControl;//0=CBR, 1=VBR
    DWORD	VBRMin;// in bps
    DWORD	VBRMax;// in bps

    DWORD	CodingMode;//0=Frame, 1=Field, 2=MBAFF, 3=PAFF
    DWORD	Profile;//0=Base, 3=Main, 4=High
    DWORD	Level;//eg 400 for 4.00
    DWORD	Latency;//0=LOW, 1=HIGH, 2=MEDIUM
    DWORD	CabacCoding;//0=CAVLC, 1=CABAC
    DWORD	DeblockFilter;//0=Off, 1=On
    DWORD	NumBFrames;	//Range[0,7]

    DWORD	AudioStreamID; // Audio elementary stream ID
    DWORD	AudioFormat; //2=AC3, 3=AAC
    DWORD	AudioMode;//Stereo=1, Mono=2
    DWORD	AudioSampleRate;//eg 48000 or 44100
    DWORD	AudioBitrate;//eg 192000
    DWORD	AudioPassthru; //1=audio is passthrough; 0=audio is encoded
    DWORD	AGCEnable; // 0=disable Audio AGC; 1=Enable AGC

} EncStatus, *pEncStatus;
#endif//HCW_E5BDA

typedef enum
{
	KSPROPERTY_HAUP_SYSTEM_MODEL_NUMBER,
	KSPROPERTY_HAUP_SYSTEM_SERIAL_NUMBER,
	KSPROPERTY_HAUP_SYSTEM_REVISION,
	KSPROPERTY_HAUP_SYSTEM_EDID_CONFIG,

	KSPROPERTY_HAUP_SYSTEM_ENC_STATUS //Siena
} KSPROPERTY_HAUP_SYSTEM;

#endif // HAUPPAUGE

#endif // ENCODERIF_H