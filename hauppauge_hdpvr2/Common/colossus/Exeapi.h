
#ifndef EXEAPI_H
#define EXEAPI_H


typedef enum
{
	CAR_UNDEFINED,
	CAR_4_3_FULL,
	CAR_4_3_LB,
	CAR_14_9_LB_CENTER,
	CAR_14_9_LB_TOP,
	CAR_16_9_LB_CENTER,
	CAR_16_9_LB_TOP,
	CAR_MORE_THAN_16_9_LB_CENTER,
	CAR_14_9_FULL_CENTER,
	CAR_16_9_FULL_ANAMORPHIC

} COL_ASPECT_RATIO;


#define	HAUP_RES_KEY_NAME			"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\hcwE5bda\\Parameters"
#define HAUP_SDI_BITRATE			"SDi"			
#define HAUP_SDI_PEAK_BITRATE		"SDi_peak"
#define HAUP_SDI_MODE				"SDi_mode"		
#define HAUP_SDP_BITRATE			"SDp"
#define HAUP_SDP_PEAK_BITRATE		"SDp_peak"
#define HAUP_SDP_MODE				"SDp_mode"
#define HAUP_HD720P_BITRATE			"HD720p"
#define HAUP_HD720P_PEAK_BITRATE	"HD720p_peak"
#define HAUP_HD720P_MODE			"HD720p_mode"
#define HAUP_HD1080I_BITRATE		"HD1080i"
#define HAUP_HD1080I_PEAK_BITRATE	"HD1080i_peak"
#define HAUP_HD1080I_MODE			"HD1080i_mode"


#define RES_SDI_DEFAULT_BITRATE				4000000	
#define RES_SDI_PEAK_DEFAULT_BITRATE		6000000
#define RES_SDP_DEFAULT_BITRATE				5000000	
#define RES_SDP_PEAK_DEFAULT_BITRATE		7500000
#define RES_HD720P_DEFAULT_BITRATE			8000000
#define RES_HD720P_PEAK_DEFAULT_BITRATE		12000000
#define RES_HD1080I_DEFAULT_BITRATE			9000000
#define RES_HD1080I_PEAK_DEFAULT_BITRATE	13500000

#define RES_OTHERS_DEFAULT_BITRATE			8000000
#define RES_OTHERS_PEAK_DEFAULT_BITRATE		12000000


#define HAUP_ASPECT_RATIO_MODE			"AspectRatioMode"
#define HAUP_ASPECT_RATIO_SDI			"AspectRatioSDI"
#define HAUP_ASPECT_RATIO_SDP			"AspectRatioSDP"
#define HAUP_PCM_AUDIO_MODE				"PCM_AudioMode"


#define HAUP_SCALER_MODE				"ScalerMode"
#define HAUP_SCALE_RES_1080I			"ScaleRes1080I"
#define HAUP_SCALE_RES_1080P			"ScaleRes1080P"
#define HAUP_SCALE_RES_720P				"ScaleRes720P"
#define HAUP_SCALE_RES_SDP				"ScaleResSDP"
#define HAUP_SCALE_RES_SDI				"ScaleResSDI"
#define HAUP_SCALE_FPS_1080I			"ScaleFps1080I"
#define HAUP_SCALE_FPS_1080P			"ScaleFps1080P"
#define HAUP_SCALE_FPS_720P				"ScaleFps720P"
#define HAUP_SCALE_FPS_SDP				"ScaleFpsSDP"
#define HAUP_SCALE_FPS_SDI				"ScaleFpsSDI"

#define HAUP_COMB_FILTER_MODE			"CombFilterMode"
#define HAUP_COMB_DOT_CRAWL				"CombDotCrawlDetect"
#define HAUP_COMB_LUMA_MOTION			"CombLumaMotion"
#define HAUP_COMB_CHROMA_MOTION			"CombChromaMotion"
#define HAUP_COMB_RESPONSE				"CombResponse"

#define HAUP_NOISE_FILTER_MODE			"NoiseFilterMode"
#define HAUP_NOISE_LUMA_MOTION			"TempLumaMotion"
#define HAUP_NOISE_CHROMA_MOTION		"TempChromaMotion"
#define HAUP_NOISE_LUMA_EDGE			"SpatialLumaEdge"
#define HAUP_NOISE_CHROMA_EDGE			"SpatialChromaEdge"
#define HAUP_NOISE_STRENGTH				"SpatialStrength"

#define HAUP_AUDIO_ENCODER_BIT_RATE		"AudioEncoderBitRate"
#define HAUP_AUDIO_ENC_SAMPLE_RATE_48	"AudioEncoderSampleRate48"
#define HAUP_AUDIO_ENC_SAMPLE_RATE_441	"AudioEncoderSampleRate441"
#define HAUP_AUDIO_BOOST_MODE			"AudioBoostMode"

#define HAUP_FILTER_REGISTRATION		"FilterRegistration"

#define HAUP_EDID_DATA					"EdidData"


typedef struct
{
//	AspectRatio aspect_ratio;
#ifdef HAUPPAUGE
//	PVR_MODE pvr_mode;
//	TBC_MODE tbc_mode;
	ScalerSettings scaler;
//	FilterSettings filter;
	AudEncSettings audioEncoder;
//	AUDBOOST_MODE audBoost_mode;
//	BYTE filterRegistration;
//	ResVideoBitRate bit_rates;
#endif

} ExtCapParams, *pExtCapParams;



#endif // EXEAPI_H
