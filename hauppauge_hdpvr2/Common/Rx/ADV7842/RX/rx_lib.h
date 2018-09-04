/**********************************************************************************************
*																						      *
* Copyright (c) 2012 Analog Devices, Inc.  All Rights Reserved.                               *
* This software is proprietary and confidential to Analog Devices, Inc. and its licensors.    *
*                                                                                             *
***********************************************************************************************/

#ifndef _RX_LIB_H_
#define _RX_LIB_H_

#include "wrapper.h"
#include "rx_defs.h"

/*===================================
 * General Defines and Macros
 *==================================*/
#define RX_AUDIO_CTS_MAX_THRESHOLD      64

/*===================================
 * VDP Macros
 *==================================*/
#define RX_GEMS_1X_SIZE                 4
#define RX_GEMS_2X_SIZE                 RX_GEMS_1X_SIZE
#define RX_GEMS_SIZE                    RX_GEMS_1X_SIZE
#define RX_CGMS_SIZE                    3
#define RX_CGMS_B_SIZE                  17
#define RX_VITC_SIZE                    9
#define RX_CCAP_SIZE                    2
#define RX_VPS_SIZE                     13
#define RX_WSS_SIZE                     2
#define RX_PDC_SIZE                     13
#define RX_UTC_SIZE                     13
#define RX_VBI_MAX_SIZE                 17  

typedef enum
{
    RX_ENABLE_DBG           = 0x0001
} RX_CONFIG;

typedef enum
{
    RX_IO_MAP = 0,
    RX_SDP_IO_MAP,
    RX_SDP_MAP,
    RX_VDP_MAP,
    RX_ESDP_MAP,
    RX_DPP_MAP,
    RX_CP_MAP,
    RX_SDP_VDP_MAP,
    RX_AFE_MAP,
    RX_DPLL_MAP,
    RX_HDMI_MAP,
    RX_REPEATER_MAP,
    RX_EDID_MAP,
    RX_INFOFRAME_MAP,
    RX_CEC_MAP,
    RX_AVLINK_MAP,
    RX_TEST_MAP,
    RX_TEST_MAP1,
    RX_TEST_MAP2,
    RX_TEST_MAP3,
    RX_OSD_MAP,
    RX_TX_EDID_MAP,
    RX_TX_UDP_MAP,
    RX_XMEM_MAP,
    RX_VFE_MAP,
    RX_AUDIO_CODEC_MAP
} RX_I2C_MAP;

typedef enum 
{
    RX_OPMODE_PWRDWN = 0,
    RX_OPMODE_PWRUP,
    RX_OPMODE_HDMI,
    RX_OPMODE_COMP,
    RX_OPMODE_GR,
    RX_OPMODE_SDP_COMP,
    RX_OPMODE_SDP_CVBS,
    RX_OPMODE_SDP_CVBS_HDMI_MON,
    RX_OPMODE_SDP_CVBS_YC_AUTO,         /* Not available yet */
    RX_OPMODE_SDP_YC,
    RX_OPMODE_SDP_SCART
} RX_OP_MODE;

typedef struct 
{
    BOOL DisPowerMgt;
    BOOL DisTriStateMgt;
    BOOL ResetUsed;             /* Not used yet */ 
                                /* This tell the sw if a sw/hw reset is used to switch from one mode to another */
                                /* May be usefull for swithing between CP and HDMI without reset */
    RX_OP_MODE CurrOpMode;      /* Not used yet */
                                /* To tell the sw what is the current operating mode */
                                /* May be usefull for swithing between CP and HDMI without reset */
}RX_OP_MODE_CFG;   
    
typedef enum 
{
    RX_ALL_SECTIONS = 1,
    RX_ALL_CORES,
    RX_CP_HDMI_MAIN,
    RX_SDP_MAIN,
    RX_SDP_CORE,
    RX_CP,
    RX_XTAL,
    RX_DPP_CP_HDMI_DIG,
    RX_ESDP,
    RX_VDP,
    RX_SDP_XTAL,
    RX_SDP_PLL,
    RX_SDP_FB,
    RX_SDP_FUNCT1,
    RX_SDP_AOUT1,
    RX_SDP_AOUT2,
    RX_SDP_PADS,    
    RX_ALL_ADC_CCT,
    RX_ADC0_CCT,
    RX_ADC1_CCT,
    RX_ADC2_CCT,
    RX_ADC3_CCT,
    RX_SDP_ALL_ADC_CCT,
    RX_SDP_ADC0_CCT,
    RX_SDP_ADC1_CCT,
    RX_SDP_ADC2_CCT,
    RX_SDP_ADC3_CCT,
    RX_MEM,
    RX_EDID_REP_MPU,
    RX_CEC_CTRL,
    RX_AVLINK_CTRL,
    RX_ETH1,
    RX_ETH2,
    RX_HEC1,
    RX_HEC2,
    RX_CDEC_ADC0_CCT,
    RX_CDEC_DAC0_CCT,
    RX_CDEC_ALL_CCT
} RX_CHIP_SECTION;

typedef enum 
{
    RX_PWRDN_MODE0 = 0,
    RX_PWRDN_MODE1,
    RX_PWRSV_MODE
} RX_PWRDN_MODE;

typedef enum
{
    RX_VS_OUT_PIN = 1,
    RX_HS_OUT_PIN,
    RX_SYNC_OUT_PIN,
    RX_DE_OUT_PIN,
    RX_HS_IN1_PIN,
    RX_VS_IN1_PIN,
    RX_HS_IN2_PIN,
    RX_VS_IN2_PIN,
    RX_SDP_VS_OUT_PIN,
    RX_SDP_HS_OUT_PIN,
    RX_SDP_FIELD_OUT_PIN,
    RX_FIELD_OUT_PIN,
    RX_INT_OUT_PIN,
    RX_INT1_OUT_PIN,
    RX_INT2_OUT_PIN,
    RX_INT3_OUT_PIN,
    RX_CABLE_DET_PINS,
    RX_HPA_PINS,
    RX_HPA_A_PIN,
    RX_POWERDNB_PIN,
    RX_OUT_PINS,
    RX_LLC_OUT_PIN,
    RX_SYNC_OUT_PINS,   
    RX_PIX_OUT_PINS,
    RX_AUD_OUT_PINS,
    RX_SDP_OUT_PINS,
    RX_SDP_LLC_OUT_PIN,
    RX_MEM_IF_PINS,
    RX_SDP_PIX_OUT_PINS,
    RX_SDP_SYNC_OUT_PINS,
    RX_SPI_EPROM_PINS,
    RX_SPI_VDP_PINS,
    RX_MCLK_PIN,
    RX_SCLK_PIN,
    RX_TRI1_PIN,
    RX_TRI2_PIN,
    RX_TRI3_PIN,
    RX_TRI4_PIN,
    RX_TRI5_PIN,
    RX_TRI6_PIN,
    RX_TRI7_PIN,
    RX_TRI8_PIN
    
} RX_PIN;
typedef enum
{
    RX_8BIT = 0,
    RX_9BIT,
    RX_16BIT

} RX_ADDRSNG;
typedef struct
{
    RX_ADDRSNG   AddrScheme;     
} RX_EDID_SPI_CFG;

typedef struct
{
   BOOL  Spa16Bit;
   BOOL  VgaEdidPresent;
   BOOL  AssertHpaPowerOff;
   UINT8 NumBlocksPresent;
} RX_EDID_SPI_HEADER;

typedef enum
{
    RX_DISABLE_PIN = 0,
    RX_ENABLE_PIN,
    RX_VS_SIG,  
    RX_HS_SIG,
    RX_SFL_SIG,
    RX_DE_SIG,
    RX_CS_SIG,
    RX_INT_SIG,
    RX_AUDIO_MUTE_SIG,
    RX_FIELD_SIG,   
    RX_TRILEVEL_SIG,
    RX_SYNC_OUT_SIG,
    RX_HP_SIG,
    RX_SCLK_SIG,
    RX_MCLK_SIG,
    RX_FB_SIG
} RX_PIN_FUNCTION;

typedef enum
{
    RX_3_XTAL_CLK = 1,
    RX_15_XTAL_CLK,
    RX_63_XTAL_CLK,
    RX_ACT_UNTIL_CLR
} RX_INT_DURATION;

typedef enum
{
    RX_OPEN_DRAIN = 1,
    RX_LOW_LEVEL,
    RX_HIGH_LEVEL
} RX_PIN_LEVEL;

typedef enum
{
    RX_SAMP_CLK_SIG = 1,
    RX_SDP_SAMP_CLK_SIG,
    RX_LLC_SIG,
    RX_SDP_LLC_SIG
} RX_CLOCK_SIG;

typedef enum 
{
    RX_DR_STR_2X = 0,
    RX_DR_STR_3X,
    RX_DR_STR_4X,
    RX_DR_STR_1X
} RX_OP_DR_STR; 

typedef enum
{
    RX_1X_CLK = 1,
    RX_2X_CLK,
    RX_0Dot5_CLK,
    RX_90Deg_1X_CLK
} RX_PIX_CLK_FREQ;

typedef enum 
{
    RX_BUS_BITS_8 = 0,
    RX_BUS_BITS_10,
    RX_BUS_BITS_12
} RX_BUS_BIT_WIDTH;

typedef enum 
{
    RX_BUS_MODE0 = 0,
    RX_BUS_MODE1,
    RX_BUS_MODE2,
    RX_BUS_MODE3,
    RX_BUS_MODE4,
    RX_BUS_MODE5
} RX_BUS_MODE;

typedef enum 
{
    RX_BUS_OP_MODE_422PSDR = 0,
    RX_BUS_OP_MODE_422DDR,
    RX_BUS_OP_MODE_444SDR,
    RX_BUS_OP_MODE_444DDR,
    RX_BUS_OP_MODE_422SDR,
    RX_BUS_OP_MODE_ADI_CM
} RX_BUS_OP_MODE;

typedef enum 
{
    RX_BUS_OP_CH_GBR = 0,
    RX_BUS_OP_CH_GRB,
    RX_BUS_OP_CH_BGR,
    RX_BUS_OP_CH_RGB,
    RX_BUS_OP_CH_BRG,
    RX_BUS_OP_CH_RBG
} RX_BUS_OP_CH;

typedef struct
{
    RX_BUS_BIT_WIDTH  BitWidth;
    RX_BUS_OP_MODE    Format;
    RX_BUS_MODE       Mode;
    RX_BUS_OP_CH      ChOrder;
    BOOL              CrCbSwap;
    BOOL              BitReorder;   
} RX_PIX_BUS_INFO;

typedef enum 
{
    RX_525I = 0,
    RX_625I,
    RX_525P,
    RX_625P,
    RX_720P,
    RX_1125I_274M,
    RX_1125I_240M,
    RX_1250I_295M,
    RX_1920I_1152,
    RX_1125P_274M,
    RX_1250P_295M,
    RX_1125P_RB,
    RX_VGA,
    RX_SVGA,
    RX_XGA,
    RX_SXGA,
    RX_WXGA,
    RX_WXGAR,
    RX_WXGAP,
    RX_WXGA_1360, 
    RX_WXGA_1366,
    RX_SXGA_PLUS,
    RX_SXGAR,
    RX_UXGA,
    RX_UXGAR,
    RX_WSXGA,
    RX_WUXGA,
    RX_AUTOGR
} RX_VID_RES;

typedef enum 
{
    RX_OS_1X1 = 0,
    RX_OS_2X1,
    RX_OS_4X1,
    RX_OS_8X1,
    RX_OS_2X2,
    RX_OS_4X2
} RX_OS_RATE;

typedef enum 
{
    RX_VFRQ_24HZ = 0,
    RX_VFRQ_25HZ,
    RX_VFRQ_30HZ,
    RX_VFRQ_50HZ,
    RX_VFRQ_56HZ,
    RX_VFRQ_60HZ,
    RX_VFRQ_70HZ,
    RX_VFRQ_72HZ,
    RX_VFRQ_75HZ,
    RX_VFRQ_80HZ,
    RX_VFRQ_85HZ
} RX_VRT_FRQ;

typedef enum
{
    PORT_A      = 0,                /* The value of the port is also    */
    PORT_B      = 1,                /* the port index (0-3)             */
    PORT_C      = 2,
    PORT_D      = 3,
    PORT_NONE   = 0xFE,
    PORT_ALL    = 0xFF
} RX_HDMI_PORT;

typedef struct
{
    UINT16  LinesTotal;
    UINT16  LinesActive; 
    UINT16  FrontPorch;
    UINT16  SyncPulse;
    UINT16  BackPorch;
    BOOL    Polarity;
} RX_HDMI_HSYNC;

typedef struct
{
    UINT16  LinesTotal;
    UINT16  LinesActive; 
    UINT16  FrontPorch;
    UINT16  SyncPulse;
    UINT16  BackPorch;
    UINT16  F1LinesTotal;
    UINT16  F1LinesActive; 
    UINT16  F1FrontPorch;
    UINT16  F1SyncPulse;
    UINT16  F1BackPorch;
    BOOL    Interlaced;
    BOOL    Polarity;
} RX_HDMI_VSYNC;

typedef enum
{
    RX_FS_32KHz = 1,
    RX_FS_44KHz,
    RX_FS_48KHz,
    RX_FS_88KHz,
    RX_FS_96KHz,
    RX_FS_176KHz,
    RX_FS_192KHz,
    RX_FS_UNDEFINED
} RX_AUDIO_FS;

typedef enum
{
    RX_CD_24 = 0,
    RX_CD_30,
    RX_CD_36,
    RX_CD_48
} RX_COLOR_DEPTH;

typedef enum
{
    RX_AUDIO_SAMPLE_PACKET = 0,
    RX_AUDIO_DSD,
    RX_AUDIO_DST,
    RX_AUDIO_HBR,
    RX_ANALOG_STEREO,
    RX_AUDIO_UNDEFINED
} RX_AUDIO_TYPE;

typedef enum
{
    RX_I2S_MODE = 0,
    RX_I2S_RIGHT,
    RX_I2S_LEFT,   
    RX_I2S_RAW
} RX_I2S_OUT_MODE;

typedef enum
{
    RX_DST_SDR = 0,
    RX_DST_DDR
} RX_DST_MODE;

typedef enum
{
    RX_AUD_IF_I2S,
    RX_AUD_IF_SPDIF,
    RX_AUD_IF_DSD,
    RX_AUD_IF_DST,
    RX_AUD_IF_AUTO
} RX_AUD_INTERFACE;


typedef enum
{
    RX_MCLK_128Fs = 0,
    RX_MCLK_256Fs,
    RX_MCLK_384Fs,
    RX_MCLK_512Fs,
    RX_MCLK_640Fs,
    RX_MCLK_768Fs,
    RX_MCLK_64Fs
} RX_MCLK;

typedef enum
{
    VS_INFO_PACKET = 0,
    AVI_INFO_PACKET,
    SPD_INFO_PACKET,
    AUDIO_INFO_PACKET,
    MPEG_INFO_PACKET,
    ACP_PACKET,
    ISRC1_PACKET,
    ISRC2_PACKET,
    GAMUT_PACKET
} RX_PACKET_TYPE;

typedef enum
{
    RX_ARC_OFF = 0,
    RX_ARC_SINGLE,
    RX_ARC_COMMON
} RX_ARC_MODE;

typedef enum
{
    RX_ARC_TX1      = 0,               
    RX_ARC_TX2,
    RX_ARC_TX3,
    RX_ARC_TX4,
    RX_ARC_NONE     
} RX_ARC_TX;

typedef struct
{
    BOOL    DeRegenLock;
    BOOL    VLocked;
    BOOL    StdiDvalidCh1;
    BOOL    AvMute;
    BOOL    InternalMute;
    BOOL    HdmiMode;
    BOOL    Tmds[RX_NOF_PORTS];
    BOOL    Detected5V[RX_NOF_PORTS];
    BOOL    VidPllLocked[RX_NOF_PORTS];
    BOOL    Encrypted[RX_NOF_PORTS];
    BOOL    AudMultiChan;
    UCHAR   HwSelPort;
    RX_COLOR_DEPTH ColorDepth;
    RX_AUDIO_TYPE AudioType;
} RX_DEV_STATE;

/*========================================
 * Analog Front End Defines and Macros
 *========================================*/
 
typedef enum 
{
    RX_AIN1 = 1,
    RX_AIN2,
    RX_AIN3,
    RX_AIN4,
    RX_AIN5,
    RX_AIN6,
    RX_AIN7,
    RX_AIN8,
    RX_AIN9,
    RX_AIN10,
    RX_AIN11,
    RX_AIN12,
    RX_AIN13,
    RX_AIN_NONE
} RX_AIN_CH;

typedef enum 
{
    RX_VOUT_1 = 1,
    RX_VOUT_2
}RX_VOUT_CH;

typedef enum 
{
    RX_SYNC_SLICER1 = 1,
    RX_SYNC_SLICER2,
    RX_ALL_SYNC_SLICERS
} RX_SYNC_SLICER;

typedef enum 
{
    RX_BILEVEL = 1,
    RX_TRILEVEL
}RX_TRI_SLICER_MODE ;

typedef enum 
{
    RX_NO_SFILT = 1,
    RX_SFILT_GR250NS,
    RX_SFILT_GR1000NS,
    RX_SFILT_GR2500NS
} RX_SYNC_SLICER_FILTER;

typedef enum 
{
    RX_TRI_SLICER1 = 1,
    RX_TRI_SLICER2,
    RX_TRI_SLICER3,
    RX_TRI_SLICER4,
    RX_TRI_SLICER5,
    RX_TRI_SLICER6,
    RX_TRI_SLICER7,
    RX_TRI_SLICER8,
    RX_ALL_TRI_SLICER
} RX_TRI_SLICER;

typedef enum 
{
    RX_TRI_BELOW_LWR_LIMIT = 1,
    RX_TRI_ABOVE_LWR_LIMIT,
    RX_TRI_ABOVE_UPPR_LIMIT
} RX_TRI_SLICER_STATUS;

typedef enum
{
    RX_TRI_NO_LEVEL = 0,
    RX_TRI_LOWR_LEVEL = 1,
    RX_TRI_UPPR_LEVEL = 2,
    RX_TRI_ALL_LEVELS = 3
} RX_TRI_SLICER_LEVEL;

typedef enum 
{
    RX_ADC0 = 0,
    RX_ADC1,
    RX_ADC2,
    RX_ADC3,
    RX_SDP_ADC0,
    RX_SDP_ADC1,
    RX_SDP_ADC2,
    RX_SDP_ADC3,
    RX_ALL_ADCS
} RX_ADC;


typedef enum
{
    RX_CDEC_LR_IN1,
    RX_CDEC_LR_IN2,
    RX_CDEC_LR_IN3,
    RX_CDEC_LR_IN4,
    RX_CDEC_LR_IN5,
    RX_CDEC_I2S_IN1,
    RX_CDEC_NONE_IN
} RX_CDEC_IN;

typedef enum
{
    RX_CDEC_LR_OUT1,
    RX_CDEC_DAC_HP_OUT1,
    RX_CDEC_DAC_LR_OUT1,
    RX_CDEC_DAC_OUT_ALL,
    RX_CDEC_OUT_NONE
} RX_CDEC_OUT;


typedef enum 
{
    RX_CDEC_ADC0_L = 0,
    RX_CDEC_ADC0_R,
    RX_CDEC_DAC0_L,
    RX_CDEC_DAC0_R,
    RX_CDEC_DAC0_HP,
    RX_CDEC_ALL_ADC_DAC  
} RX_CDEC;


typedef enum 
{
    RX_75mV = 0,
    RX_225mV,
    RX_375mV,
    RX_525mV,
    RX_675mV,
    RX_825mV,
    RX_975mV,
    RX_1125mV
} RX_TRI_SLICE_LEVEL;

typedef enum
{
    RX_AAF_FC_10MHZ = 0,
    RX_AAF_FC_12MHZ,
    RX_AAF_FC_14MHZ,
    RX_AAF_FC_15MHZ,
    RX_AAF_FC_27MHZ,
    RX_AAF_FC_32MHZ,
    RX_AAF_FC_36MHZ,
    RX_AAF_FC_40MHZ,
    RX_AAF_FC_58MHZ,
    RX_AAF_FC_68MHZ,
    RX_AAF_FC_79MHZ,
    RX_AAF_FC_91MHZ,
    RX_AAF_FC_95MHZ,
    RX_AAF_FC_109MHZ,
    RX_AAF_FC_126MHZ,
    RX_AAF_FC_145MHZ,
    RX_SDP_AAF_FC_6_9MHZ,
    RX_SDP_AAF_FC_10_5MHZ,
    RX_SDP_AAF_FC_13_4MHZ,
    RX_SDP_AAF_FC_21MHZ
} RX_AA_FILT_RESPONSE;

/*===================================
 * Standard Definition Processor
 * Defines and Macros
 *==================================*/
 
typedef enum
{
    RX_PAL = 0,
    RX_NTSC,
    RX_PALNC,
    RX_PALM,
    RX_PALN,
    RX_PAL60,
    RX_N443,    
    RX_SECAM,
    RX_SECAM60,
    RX_240P,
    RX_288P,
    RX_UNDEF_SDP_FORMAT,
    RX_ALL_SDP_FORMATS
} RX_SDP_FORMAT;

typedef enum
{
    RX_50HZ = 0,
    RX_60HZ
} RX_SDP_FIELD_RATE;

typedef enum
{
    RX_SDR_MEM = 0,
    RX_DDR_MEM 
} RX_SDP_MEM;

typedef enum
{
    RX_LINE_DOUBLING = 1,
    RX_LINE_INTERPOLATION 
}RX_ItoP_MODE;

typedef enum 
{
    RX_DIGITAL_CLAMP = 1,
    RX_ANALOG_CLAMP
} RX_CLAMP;

typedef struct
{
    BOOL    VideoDetect;
    BOOL    FreeRun;
    BOOL    AllowSlowPll;
    BOOL    AllowMedPll;
    BOOL    LcNstd;
    BOOL    FrmNstd;
    BOOL    FldNstd;
    BOOL    BlkNstd;
    BOOL    HswitchPresent;
    BOOL    ScmLocked;
    BOOL    FscFreqOk;
    BOOL    PalSwLocked;
    BOOL    Ad50_60Hz;
    BOOL    BurstLocked;
} RX_SDP_STATUS;

typedef struct
{
    BOOL    AgcDetected;
    BOOL    CsDetected; 
    BOOL    PsDetected;    
    BOOL    CsType2;
    BOOL    CsType3; 
} RX_MCVS_STATUS;



/*===================================
 * Component Processor
 * Defines and Macros
 *==================================*/
 
typedef enum 
{
    RX_GAIN_AUTO = 1,
    RX_GAIN_AGC,
    RX_GAIN_MAN
}RX_GAIN_MODE;

typedef enum {
    RX_RG_16_235,
    RX_RG_0_255,
    RX_RG_EXTENDED,
    RX_RG_AUTO
}RX_RANGE;

typedef enum
{
    RX_SYNC_CH1 = 0,
    RX_SYNC_CH2
} RX_SYNC_CH;

typedef enum 
{
    RX_HS_AUTO = 0,
    RX_HS_IN1,
    RX_HS_IN2,
    RX_HS_HDMI
} RX_HS_SEL;

typedef enum
{
    RX_VS_AUTO = 0,
    RX_VS_IN1,
    RX_VS_IN2,
    RX_VS_HDMI
} RX_VS_SEL;

typedef enum 
{
    RX_SYNC_AUTO = 0,
    RX_SYNC_1,
    RX_SYNC_2,
    RX_SYNC_3,
    RX_SYNC_4,
    RX_SOY,
    RX_SOG,
    RX_SYNC_LO
} RX_EMBSYNC_SEL;

typedef enum 
{
    RX_CP_ONE_SHOT = 1,
    RX_CP_CONTINUOUS,
    RX_CP_REAL_TIME
} RX_CP_MSRMT_MODE;

typedef enum 
{
    RX_HS_VS = 1,
    RX_HS_CS,
    RX_EMB_SYNC,
    RX_AUTO_SYNC
} RX_SYNC_SRC;

typedef struct 
{
    RX_SYNC_SRC SyncSrc;
    BOOL        VsAct;
    BOOL        PolVs;
    BOOL        HsCsAct;
    BOOL        PolHsCs;
} RX_SSPD_INFO;

typedef struct 
{
    UINT16  BlockLength;
    UINT8   LinesVsync;
    UINT16  LinesField;
    UINT16  FieldLength;
    BOOL    Interlaced;
} RX_STDI_INFO;

typedef enum 
{
    RX_LEAD_EDGE_HS = 0,
    RX_TRAIL_EDGE_HS,
    RX_LEAD_EDGE_VS,
    RX_TRAIL_EDGE_VS,
    RX_EVEN_FIELD_START,
    RX_ODD_FIELD_START,
    RX_LEAD_EDGE_DE,
    RX_TRAIL_EDGE_DE,
    RX_VBI_START,
    RX_VBI_END
} RX_SYNC_SIG_ADJ;

typedef struct 
{
    BOOL FreeRun;
    BOOL CpLock;
    BOOL MvAgcDetected;
    BOOL MvPseudoDetected;
    BOOL OpInterlace;
    BOOL InterlaceDetected;
} RX_CP_STATUS;

typedef enum
{
    RX_AUTO_SYNC_POS = 0,
    RX_SEMI_AUTO_SYNC_POS,
    RX_MAN_SYNC_POS
} RX_SYNC_POS_SEL;

typedef struct 
{
    UINT16          TotalSamplesLine;
    BOOL            Interlaced;
    UINT16          TotalLinesFrameCh1;
    UINT16          TotalLinesFrameCh2;
    UINT16          TotalXtalsLineCh1;
    UINT16          TotalXtalsLineCh2;
    RX_SYNC_POS_SEL SyncPosSel;
    UINT16          PixelsDeHStart;
    UINT16          PixelsDeHEnd;
    UINT8           PixelsDeVStart;
    UINT8           PixelsDeVEnd;
    UINT16          LinesStartVbi;
    UINT16          LinesEndVbi;
    UINT16          LinesStartVbiEvenF;
    UINT16          LinesEndVbiEvenF;
    UINT8           PixelsVsStartClamp;
    UINT8           PixelsVsEndClamp;    
} RX_AUTO_GR_PARM;

typedef enum
{
    RX_16_LLC_CYCLES = 0,
    RX_32_LLC_CYCLES,
    RX_64_LLC_CYCLES,
    RX_128_LLC_CYCLES,
    RX_0_LINES,
    RX_128_LINES,
    RX_256_LINES,
    RX_512_LINES,
    RX_1K_LINES,
    RX_2K_LINES,
    RX_4K_LINES,
    RX_8K_LINES,
    RX_16K_LINES,
    RX_32K_LINES,
    RX_64K_LINES,
    RX_128K_LINES
} RX_CP_DURATION;

/*===================================
 * Data Pre-Processor and Color Space
 * Converter Defines and Macros
 *==================================*/
 
typedef enum 
{
    RX_CP_CSC = 1,
    RX_DPP_CSC,
    RX_SDP_CSC
} RX_CSC;

typedef enum 
{
    RX_CS_AUTO_EN = 1,
    RX_CS_MAN_EN,
    RX_CS_MAN_DIS
} RX_CSC_MODE;

typedef enum 
{
    RX_CS_AUTO = 1,
    RX_CS_MAN
} RX_CSC_CONFIG;

typedef enum 
{
    RX_CS_RGB = 1,
    RX_CS_YCrCb601,
    RX_CS_YCrCb709,
    RX_CS_XVYCC601,
    RX_CS_XVYCC709,
    RX_CS_SYCC601,
    RX_CS_ADOBE_YCC601,
    RX_CS_ADOBE_RGB,
    RX_CS_FOLLOW_INPUT
} RX_CS_COLOR;

typedef enum 
{
    RX_FILT_AUTO = 1,
    RX_FILT_BYPASS,
    RX_FILT_MAN_COEFF,
    RX_FILT_0DOT2_FsOVER2,
    RX_FILT_0DOT3_FsOVER2,
    RX_FILT_0DOT4_FsOVER2,
    RX_FILT_0DOT5_FsOVER2,
    RX_FILT_0DOT6_FsOVER2,
    RX_FILT_0DOT7_FsOVER2,
    RX_FILT_0DOT8_FsOVER2,
    RX_FILT_0DOT26_FsOVER2,
    RX_FILT_0DOT43_FsOVER2,
    RX_FILT_0DOT66_FsOVER2
} RX_FILT_RESPONSE;

typedef enum 
{
    RX_FILT_HIGH_BANDWIDTH = 0,        /*add Rx prefix*/
    RX_FILT_REDUCED_BANDWIDTH          /*add Rx prefix*/
} RX_FILT_BANDWIDTH;

typedef enum 
{
    RX_FILTER_DOWNSAMPLE = 0,          /*add Rx prefix*/
    RX_DOWNSAMPLE_ONLY                 /*add Rx prefix*/
} RX_FILT_MODE;

/*===================================
 * VDP Defines and Macros
 *==================================*/
 
typedef enum{
    RX_GEMS_1X = 0,
    RX_GEMS_2X,
    RX_GEMS,       /*RX_GEMS designates Gemstar 1X or 2X*/
    RX_TTXT_A,
    RX_TTXT_B,
    RX_TTXT_C,
    RX_TTXT_D,
    RX_TTXT,        /*RX_TTXT designates teletext Type A, B, C or D*/
    RX_CGMS,
    RX_CGMS_B,
    RX_VITC,
    RX_CCAP,
    RX_VPS,
    RX_WSS,
    RX_PDC,
    RX_UTC,
    RX_NO_VBI = 0xFF
} RX_VBI_TYPE;

typedef enum{
    RX_NIBBLE_MODE = 0,
    RX_BYTE_MODE_NO_RESTRICT,
    RX_BYTE_MODE_WITH_RESTRICT
} RX_ADF_MODE;

typedef struct
{
    BOOL    Master;         /*Master or Slave Mode*/
    BOOL    Burst;          /*Single Byte mode or Burst Mode, Slave mode Only*/
    BOOL    Cpolarity;      /*Configure SPI interface C polarity*/
    UCHAR   PacketSize;     /*Packet Size in Master Mode*/
    BOOL    AutoClearMode;  /*Auto Clear of data registers in Master Mode*/ 
} RX_VBI_SPI_CFG;

typedef enum
{
    /*=======================================================
     * The enum value given to each of the events is used to
     * locate the event control bit in a 16-byte array
     * bits 0-2 = Bit location in the byte (0-7)
     * bits 3-6 = Byte offset in the array (0-15)
     *======================================================*/
    RX_EVENT_HDMI_AVI_INFO,
    RX_EVENT_HDMI_AUDIO_INFO,
    RX_EVENT_HDMI_SPD_INFO,
    RX_EVENT_HDMI_MS_INFO,
    RX_EVENT_HDMI_VS_INFO,
    RX_EVENT_HDMI_ACP_PCKT,
    RX_EVENT_HDMI_ISRC1_PCKT,
    RX_EVENT_HDMI_ISRC2_PCKT,
    RX_EVENT_HDMI_GAMUT_PCKT,
    RX_EVENT_HDMI_NO_PACKET,
    RX_EVENT_HDMI_N_CHNG,
    RX_EVENT_HDMI_CTS_PASS_THRSH,
    RX_EVENT_HDMI_FIFO_OVERFLO,
    RX_EVENT_HDMI_FIFO_UNDERFLO,
    RX_EVENT_HDMI_FIFO_NEAROVFL,
    RX_EVENT_HDMI_FIFO_NEARUFLO,
    RX_EVENT_HDMI_AUDIO_MODE_CHNG,
    RX_EVENT_HDMI_AUDIO_CH_MODE_CHNG,
    RX_EVENT_HDMI_AV_MUTE,
    RX_EVENT_HDMI_INTERNAL_MUTE,
    RX_EVENT_HDMI_CS_DATA_VALID,
    RX_EVENT_HDMI_AUDIO_FLT_LINE,
    RX_EVENT_HDMI_NEW_SAMP_RT,
    RX_EVENT_HDMI_TMDS_CLK_CHNG,
    RX_EVENT_HDMI_CABLE_DETECT,
    RX_EVENT_HDMI_VIDEO_PLL_LCK,
    RX_EVENT_HDMI_DE_REGEN_LCK,
    RX_EVENT_HDMI_V_LOCKED,
    RX_EVENT_HDMI_ENC_CHNG,
    RX_EVENT_HDMI_MODE_CHNG,
    RX_EVENT_HDMI_NEW_TMDS_FRQ,
    RX_EVENT_HDMI_PARITY_ERR,
    RX_EVENT_HDMI_AKSV_UPDATE,
    RX_EVENT_HDMI_VCLK_CHNG,
    RX_EVENT_HDMI_DEEP_COLOR_CHNG,
    RX_EVENT_HDMI_AUX_MEAS_CHNG,
    RX_EVENT_CEC_RX_MSG,
    RX_EVENT_CEC_TX_DONE,
    RX_EVENT_CEC_TX_TIMEOUT,
    RX_EVENT_CEC_TX_ARB_LOST,
    RX_EVENT_CEC_LOG_ADDR_ALLOC,
    RX_EVENT_CEC_LOG_ADDR_LIST,
    RX_EVENT_CEC_RX_MSG_RESPOND,    
    RX_EVENT_CP_STDI_LCK,
    RX_EVENT_CP_STDI_LCK_SYNC_CH1,
    RX_EVENT_CP_STDI_LCK_SYNC_CH2,
    RX_EVENT_CP_LCK,
    RX_EVENT_CP_LCK_SYNC_CH1,
    RX_EVENT_CP_LCK_SYNC_CH2,
    RX_EVENT_SDP_VIDEO_DET,
    RX_EVENT_SDP_BURST_LCK,
    RX_EVENT_MV_AGC_DET,
    RX_EVENT_MV_PS_DET,
    RX_EVENT_MV_CS_DET,
    RX_EVENT_AFE_SLICER,
    RX_EVENT_VDP_TTXT,
    RX_EVENT_VDP_VITC,
    RX_EVENT_VDP_GPVUC,
    RX_EVENT_VDP_CGMS_WSS,
    RX_EVENT_VDP_CCAP,
    RX_EVENT_VDP_FAST_DATARB_RDY,
    RX_EVENT_HDMI_3D_PACKET,
    RX_EVENT_HDMI_NO_3D_PACKET
} RX_EVENT;

#include "rx_hal.h"

/*===================================
 * Funtions prototypes
 *==================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*===================================
 * General Prototypes
 *==================================*/
ATV_ERR ADIAPI_RxSetDeviceIndex (UCHAR DevIdx);
ATV_ERR ADIAPI_RxGetDeviceIndex (UCHAR *DevIdx);
ATV_ERR ADIAPI_RxGetChipRevision (UINT16 *RxRev);
ATV_ERR ADIAPI_RxInit (RX_OP_MODE OperatingMode);
ATV_ERR ADIAPI_RxSetEnabledEvents (RX_EVENT *EventList, UCHAR ListSize, BOOL Enable);
ATV_ERR ADIAPI_RxIsr (void);
ATV_ERR ADIAPI_RxIntPending (UCHAR IntId);

ATV_ERR ADIAPI_RxHouseKeeping (void);
ATV_ERR ADIAPI_RxSetConfig (RX_CONFIG UserConfig, BOOL Set);

ATV_ERR ADIAPI_RxSetI2cMapAddress (RX_I2C_MAP  Map, UINT8 Address);
ATV_ERR ADIAPI_RxSetOperatingMode (RX_OP_MODE OperatingMode, RX_OP_MODE_CFG *OpModeCfg);
ATV_ERR ADIAPI_RxGetOperatingMode (RX_OP_MODE *OperatingMode);
ATV_ERR ADIAPI_RxManagePower (RX_CHIP_SECTION Section, BOOL PowerUp);
ATV_ERR ADIAPI_RxManagePowerDown (RX_CHIP_SECTION Section, RX_PWRDN_MODE PowerDownMode); /*Note: not supported on any Rx Device As yet*/
ATV_ERR ADIAPI_RxChipReset (RX_CHIP_SECTION Section);
ATV_ERR ADIAPI_RxSetPinFunction (RX_PIN PinId, RX_PIN_FUNCTION PinFunction);
ATV_ERR ADIAPI_RxTristatePin (RX_PIN Pin, BOOL Tristate);
ATV_ERR ADIAPI_RxSetPinPolarity (RX_PIN Pin, BOOL PosPolarity);
ATV_ERR ADIAPI_RxConfigInt (RX_PIN IntPin, RX_INT_DURATION Duration, RX_PIN_LEVEL PinLevel);
ATV_ERR ADIAPI_RxForceIntLevel (RX_PIN IntPin, BOOL ForceLevel);
ATV_ERR ADIAPI_RxSetDriveStrength (RX_PIN PinId,  RX_OP_DR_STR DriveLevel);
ATV_ERR ADIAPI_RxEnManPllDiv (UINT16 PllDivRatio);
ATV_ERR ADIAPI_RxDisableManPllDiv (void);
ATV_ERR ADIAPI_RxSetManSigPhase (RX_CLOCK_SIG Signal, UINT8 Phase);
ATV_ERR ADIAPI_RxManSigPhaseEn (RX_CLOCK_SIG Signal, UINT8 Enable);
ATV_ERR ADIAPI_RxSetPixelClkFreq (RX_PIX_CLK_FREQ PixClkFreq, BOOL Enable);
ATV_ERR ADIAPI_RxSetOpPixFormat (RX_PIX_BUS_INFO* PixBusInfo, RX_OP_MODE* OpMode);
ATV_ERR ADIAPI_RxEnAvCode (BOOL Enable);
ATV_ERR ADIAPI_RxSetPrimModVidStd (UINT8  PrimaryMode, UINT8 VideoStandard);
ATV_ERR ADIAPI_RxSdpSetVidStd (UINT8 VideoStandard);
ATV_ERR ADIAPI_RxSetVertFreq (RX_VRT_FRQ VertFreq);
ATV_ERR ADIAPI_RxEnHdmiSimultMode (BOOL Enable);
ATV_ERR ADIAPI_RxSetInpVidCfg (RX_OP_MODE VidFormat, RX_VID_RES Res, RX_VRT_FRQ Freq, RX_OS_RATE OvrSmplng);
ATV_ERR ADIAPI_RxSet861RecSettings (RX_SDP_FORMAT *SdpFormatIn, UINT8 Vid861Out, RX_OP_MODE *OperatingMode);
ATV_ERR ADIAPI_RxSetAudioPassThrough (BOOL Set);
ATV_ERR ADIAPI_RxSetAudioInterface (RX_AUD_INTERFACE AudInterface);
ATV_ERR ADIAPI_RxEnInternalVgaEdid (UCHAR * EdidBuffer, BOOL Enable);
ATV_ERR ADIAPI_RxEdidCfgSpiInterface( RX_EDID_SPI_CFG* EdidSpiConfig, BOOL Enable);
ATV_ERR ADIAPI_RxEdidCfgSpiHeader( RX_EDID_SPI_HEADER SpiEdidHeader);
/*===================================
 * HDMI Prototypes
 *==================================*/

ATV_ERR ADIAPI_RxHdmiSetManualTmdsTerm (RX_HDMI_PORT Port, BOOL Enable);
ATV_ERR ADIAPI_RxHdmiGetTmdsTerm (RX_HDMI_PORT Port, BOOL *Enable);
ATV_ERR ADIAPI_RxHdmiTmdsDetected (RX_HDMI_PORT Port, BOOL * TmdsDetected);
ATV_ERR ADIAPI_RxHdmiGetTmdsFreq (UINT16 * TmdsFreqMHz, UCHAR * TmdsFreqFrac);
ATV_ERR ADIAPI_RxHdmiSetAutoTmdsTerm (void);
ATV_ERR ADIAPI_RxHdmiGetVideoPllStatus (RX_HDMI_PORT Port, BOOL *Locked);
ATV_ERR ADIAPI_RxHdmiInputIsDvi (BOOL *Mode);
ATV_ERR ADIAPI_RxHdmiAssertHpd (RX_HDMI_PORT Port, BOOL Enable);
ATV_ERR ADIAPI_RxHdmiIsHpdOn (RX_HDMI_PORT Port, BOOL *HpdOn);
ATV_ERR ADIAPI_RxHdmiConfig5VDetect (BOOL Detect5VFilterDisable, UCHAR Detected5VFilterTimer, BOOL Detected5VResetDisable);
ATV_ERR ADIAPI_RxHdmi5VDetected (RX_HDMI_PORT Port, BOOL * Detected5V);
ATV_ERR ADIAPI_RxHdmiGet5VDetected (RX_HDMI_PORT * ActivePort, RX_HDMI_PORT * RxPortDetectPriority);
ATV_ERR ADIAPI_RxHdmiGetDeepColorMode (RX_COLOR_DEPTH * DeepColorMode); 
ATV_ERR ADIAPI_RxHdmiSetDeepColorMode (BOOL ManualMode, RX_COLOR_DEPTH DeepColorMode); 
ATV_ERR ADIAPI_RxHdmiSetInternalEdid (UCHAR * EdidBuffer, UINT16 SpaOffset, UCHAR * SpaValue, UCHAR Segment, BOOL DisableAutoEdid);
ATV_ERR ADIAPI_RxHdmiEnableInternalEdid (RX_HDMI_PORT Port, BOOL Enable);
ATV_ERR ADIAPI_RxHdmiGetInternalEdidState (RX_HDMI_PORT Port, BOOL * EdidEnabled, UCHAR * EdidBuf, UCHAR Segment);
ATV_ERR ADIAPI_RxHdmiWriteEdidToProm (void); 
ATV_ERR ADIAPI_RxHdmiReadEdidFromProm (void);
ATV_ERR ADIAPI_RxHdmiSetSelectedPort (RX_HDMI_PORT Port, BOOL TermEn);
ATV_ERR ADIAPI_RxHdmiGetSelectedPort (RX_HDMI_PORT * Port);
ATV_ERR ADIAPI_RxHdmiSetFastSwitchingPort (RX_HDMI_PORT Port, BOOL Enable);
ATV_ERR ADIAPI_RxHdmiSetPixelRepeatMode (BOOL AutoRepeat, UCHAR RepeatFactor);
ATV_ERR ADIAPI_RxHdmiGetPixelRepeat(UCHAR * RepeatFactor);
ATV_ERR ADIAPI_RxHdmiSetHdcpI2CBase (UCHAR Base);
ATV_ERR ADIAPI_RxHdmiSetVisibleRepMap (RX_HDMI_PORT Port);
ATV_ERR ADIAPI_RxHdmiIsContentEncrypted (RX_HDMI_PORT Port, BOOL *Encrypted);
ATV_ERR ADIAPI_RxHdmiGetHdcpKeyStatus (BOOL * KeyRead, BOOL * KeyErr);
ATV_ERR ADIAPI_RxHdmiGetHsyncInfo (RX_HDMI_HSYNC * HsyncInfo);
ATV_ERR ADIAPI_RxHdmiGetVsyncInfo (RX_HDMI_VSYNC * VsyncInfo);
ATV_ERR ADIAPI_RxHdmiGetAudioPllStatus (BOOL * Locked);
ATV_ERR ADIAPI_RxHdmiGetAudioChanStatus (UCHAR * AudioCsData);
ATV_ERR ADIAPI_RxHdmiSetCsCopyright (BOOL Copyright);
ATV_ERR ADIAPI_RxHdmiGetAudioChanCount (BOOL * MultiCHAudio);
ATV_ERR ADIAPI_RxHdmiGetAudioType (RX_AUDIO_TYPE * AudioType);
ATV_ERR ADIAPI_RxHdmiGetDstMode (RX_DST_MODE *DstMode);
ATV_ERR ADIAPI_RxHdmiConfigI2SOutput (RX_I2S_OUT_MODE I2SMode, UCHAR * I2SBitWidth);
ATV_ERR ADIAPI_RxHdmiSetAudioMclk (RX_MCLK MCLK);
ATV_ERR ADIAPI_RxHdmiSetCtsRange (UCHAR CtsRange);
ATV_ERR ADIAPI_RxHdmiGetAcrInfo (UINT32 * N, UINT32 * CTS);
ATV_ERR ADIAPI_RxHdmiIgnorePacketChksumErr (BOOL IFAlwaysStore);
ATV_ERR ADIAPI_RxHdmiChangePacketID (RX_PACKET_TYPE PacketType, UCHAR NewPacketID);
ATV_ERR ADIAPI_RxHdmiGetPacket (RX_PACKET_TYPE PackeType, UCHAR * Packet, BOOL * ChecksumErr);
ATV_ERR ADIAPI_RxHdmiSetHdcpBcaps (RX_HDMI_PORT Port, UCHAR Bcaps);
ATV_ERR ADIAPI_RxHdmiSetHdcpBstatus (RX_HDMI_PORT Port, UINT16 Bstatus);
ATV_ERR ADIAPI_RxHdmiGetHdcpBcaps (RX_HDMI_PORT Port, UCHAR * Bcaps);
ATV_ERR ADIAPI_RxHdmiGetHdcpBstatus (RX_HDMI_PORT Port, UINT16 * Bstatus);
ATV_ERR ADIAPI_RxHdmiClearKsvFifo (void);
ATV_ERR ADIAPI_RxHdmiSetKsvFifo (UCHAR * BksvList, UCHAR BksvCount);
ATV_ERR ADIAPI_RxHdmiSetKsvListReadyBit (BOOL KsvListReady);
ATV_ERR ADIAPI_RxHdmiAksvReceived (RX_HDMI_PORT Port, BOOL * AksvReady);
ATV_ERR ADIAPI_RxHdmiGetStatus (RX_DEV_STATE *DevState);
ATV_ERR ADIAPI_RxHdmiEnAudioClock (BOOL Enable);
ATV_ERR ADIAPI_RxHdmiReqBgMeas (RX_HDMI_PORT Port);
ATV_ERR ADIAPI_RxHdmiGetBgTmdsFreq (RX_HDMI_PORT Port, UINT16 * TmdsFreqMHz, UCHAR * TmdsFreqFrac);
ATV_ERR ADIAPI_RxHdmiGetBgHsyncInfo (RX_HDMI_PORT Port, RX_HDMI_HSYNC * HsyncInfo);
ATV_ERR ADIAPI_RxHdmiGetBgVsyncInfo (RX_HDMI_PORT Port, RX_HDMI_VSYNC * VsyncInfo);
ATV_ERR ADIAPI_RxHdmiGetBgDeepColorMode (RX_HDMI_PORT Port, RX_COLOR_DEPTH * DeepColorMode);
ATV_ERR ADIAPI_RxHdmiGetBgPixelRepeat (RX_HDMI_PORT Port, UCHAR * RepeatFactor);
ATV_ERR ADIAPI_RxHdmiSetSyncPolarity (UCHAR Hsync, UCHAR Vsync, UCHAR Llc);
ATV_ERR ADIAPI_RxHdmiSetArcMode (RX_ARC_MODE Mode, RX_ARC_TX ArcTx);
ATV_ERR ADIAPI_RxHdmiSetEthernetPath (RX_CHIP_SECTION EThPort, RX_CHIP_SECTION HecPort, BOOL Enable);

/*===================================
 * CEC Prototypes
 *==================================*/
ATV_ERR ADIAPI_RxCecSetActiveDevice (UCHAR DevIndex);
ATV_ERR ADIAPI_RxCecEnable (BOOL Enable);
ATV_ERR ADIAPI_RxCecReset (void);
ATV_ERR ADIAPI_RxCecSendMessage (UCHAR *MsgPtr, UCHAR MsgLen);
ATV_ERR ADIAPI_RxCecSendMessageOut(void);
ATV_ERR ADIAPI_RxCecResendLastMessage (void);
ATV_ERR ADIAPI_RxCecReadMessage (UCHAR *MsgPtr, UCHAR *MsgLen);
ATV_ERR ADIAPI_RxCecSetLogicalAddr (UCHAR LogAddr, UCHAR DevId, BOOL Enable);
ATV_ERR ADIAPI_RxCecAllocateLogAddr (UCHAR *LogAddrList);
ATV_ERR ADIAPI_RxCecGetLogAddrList (UCHAR SrcLogAddr);
ATV_ERR ADIAPI_RxCecGetStatus (UCHAR *Status);

/*===================================
 * Analog Front End Prototypes
 *==================================*/

/*Video Analog Frontend and Video ADC Configuration*/
ATV_ERR ADIAPI_RxAfeAinAutoMuxModeSel (UINT8 AinMode);
ATV_ERR ADIAPI_RxAfeEnManAinMux (BOOL Enable);
ATV_ERR ADIAPI_RxAfeSdpEnManAinMux (BOOL Enable);
ATV_ERR ADIAPI_RxAfeManAinMux (RX_ADC ADC, RX_AIN_CH AinChannel);
ATV_ERR ADIAPI_RxAfeSetVideoOutMux (RX_VOUT_CH VidOutChannel, RX_AIN_CH AinChannel);
ATV_ERR ADIAPI_RxAfeEnVoltageClamps (BOOL Enable);
ATV_ERR ADIAPI_RxAfeEnCurrentClamps (BOOL Enable);
ATV_ERR ADIAPI_RxAfeSetSyncSliceLevel (RX_SYNC_SLICER SyncSlicer, UINT8 SliceLevel);
ATV_ERR ADIAPI_RxAfeSetSyncSlicerFilt (RX_SYNC_SLICER SyncSlicer, RX_SYNC_SLICER_FILTER SyncFilter);
ATV_ERR ADIAPI_RxAfeConfigTriLevelSlicer (RX_TRI_SLICER TriSlicer, RX_TRI_SLICER_MODE SliceMode,  RX_TRI_SLICE_LEVEL* SliceLevels);
ATV_ERR ADIAPI_RxAfeEnTriLevelSlicer (RX_TRI_SLICER TriSlicer,BOOL PowerUp);
ATV_ERR ADIAPI_RxAfeGetTriLevelSlicerStatus (RX_TRI_SLICER TriSlicer, RX_TRI_SLICER_STATUS* TriStatus);
ATV_ERR ADIAPI_RxAfeEnAntiAliasFilt (RX_ADC ADC, BOOL Enable);
ATV_ERR ADIAPI_RxAfeSelAntiAliasFilt (RX_AA_FILT_RESPONSE FiltResponse);
ATV_ERR ADIAPI_RxAfeEnExtBiasing (BOOL Enable);
ATV_ERR ADIAPI_RxAfeCfgAfeSlicerEvent (RX_TRI_SLICER Slicer, RX_TRI_SLICER_LEVEL EnableLvl);

/*Audio Analog Frontend and Analog CODEC Configuration*/
ATV_ERR ADIAPI_RxCdecConfig(RX_MCLK MclkRef);
ATV_ERR ADIAPI_RxCdecRouteAudInToTx(RX_CDEC_IN AudLrIn, BOOL Enable);
ATV_ERR ADIAPI_RxCdecRouteAudInToAudLoopback(RX_CDEC_IN OutL, RX_CDEC_IN OutR, BOOL Enable);
ATV_ERR ADIAPI_RxCdecConfigAudioOut(RX_CDEC_OUT AudOut, RX_CDEC_IN DigAudIn);
ATV_ERR ADIAPI_RxCdecSetVolume(RX_CDEC AudOut, UCHAR Factor);
ATV_ERR ADIAPI_RxCdecSetMute(RX_CDEC AudOut, BOOL Mute);




/*================================================
 * Standard Definition Processor Prototypes
 *================================================*/

ATV_ERR ADIAPI_RxSdpCfgAutoFormatDetect (RX_SDP_FORMAT SdpFormat, BOOL Enable);
ATV_ERR ADIAPI_RxSdpCfgFrmtPedStatus (RX_SDP_FORMAT SdpFormat, BOOL PedestalPresent);
ATV_ERR ADIAPI_RxSdpEnSFL (BOOL Enable);
ATV_ERR ADIAPI_RxSdpGetAutoFormatDetectResult (RX_SDP_FORMAT* SdpFormat);
ATV_ERR ADIAPI_RxSdpGetVideoDetectStatus (BOOL* SdpVideoDetectStatus);
ATV_ERR ADIAPI_RxSdpGetBurstLockedStatus (BOOL* SdpVideoLockedStatus);
ATV_ERR ADIAPI_RxSdpGetFieldRateStatus (RX_SDP_FIELD_RATE* SdpFieldRate);
ATV_ERR ADIAPI_RxSdpGetStatus (RX_SDP_STATUS* SdpStatus);
ATV_ERR ADIAPI_RxSdpGetMacrovisionStatus (RX_MCVS_STATUS* MvStatus);
ATV_ERR ADIAPI_RxSdpSetSaturation (UINT16 Saturation);
ATV_ERR ADIAPI_RxSdpSetBrightness (UINT16 Brightness);
ATV_ERR ADIAPI_RxSdpSetHue (UINT16 Hue);
ATV_ERR ADIAPI_RxSdpSetLumaGainMode (RX_GAIN_MODE LumaGainMode);
ATV_ERR ADIAPI_RxSdpSetLumaManGain (UINT16 LumaGain);
ATV_ERR ADIAPI_RxSdpGetLumaGain (UINT16* LumaGainRB);
ATV_ERR ADIAPI_RxSdpSetChromaGainMode (RX_GAIN_MODE ChromaGainMode);
ATV_ERR ADIAPI_RxSdpSetManChromaGain (UINT16 ChromaGain);
ATV_ERR ADIAPI_RxSdpEn3dComb (BOOL Enable);
ATV_ERR ADIAPI_RxSdpEn3dDnr (BOOL Enable);  
ATV_ERR ADIAPI_RxSdpEnFrameTbc (BOOL Enable);  
ATV_ERR ADIAPI_RxSdpInitMemInterface(RX_SDP_MEM MemType);
ATV_ERR ADIAPI_RxSdpSetItoPMode (RX_ItoP_MODE ItoPMode);
ATV_ERR ADIAPI_RxSdpEnItoP (BOOL Enable);
ATV_ERR ADIAPI_RxSdpSetClampSpeed (RX_CLAMP Clamp, UINT8 Speed);
ATV_ERR ADIAPI_RxSdpForceFreeRun (BOOL Enable);
ATV_ERR ADIAPI_RxSdpCfgColorKill (BOOL Enable, UINT8 HighThres, UINT8 LowThres);
ATV_ERR ADIAPI_RxSdpSetPixClkFreq (RX_PIX_CLK_FREQ PixClkFreq, BOOL Enable);

/*===================================
 * CSC and DPP Funtions prototypes
 *==================================*/

ATV_ERR ADIAPI_RxSetCscMode (RX_CSC_MODE Mode, RX_CSC Csc);
ATV_ERR ADIAPI_RxGetCscMode (RX_CSC_MODE *Mode, RX_CSC Csc);
ATV_ERR ADIAPI_RxSetCscConfig (RX_CSC_CONFIG Config, RX_CSC Csc);
ATV_ERR ADIAPI_RxGetCscConfig (RX_CSC_CONFIG *Config, RX_CSC Csc);
ATV_ERR ADIAPI_RxSetIpColorSpace (RX_CS_COLOR ColorSpace, RX_RANGE Range, RX_CSC Csc);
ATV_ERR ADIAPI_RxGetIpColorSpace (RX_CS_COLOR *ColorSpace, RX_RANGE *Range, RX_CSC Csc);
ATV_ERR ADIAPI_RxSetOpColorSpace (RX_CS_COLOR ColorSpace, RX_CSC Csc);
ATV_ERR ADIAPI_RxGetOpColorSpace (RX_CS_COLOR *ColorSpace, RX_CSC Csc);
ATV_ERR ADIAPI_RxSetManCscCoeffs (UINT8 CscScale, UINT8* CoeffA, UINT8* CoeffB, UINT8* CoeffC, RX_CSC CSC);
ATV_ERR ADIAPI_RxGetManCscCoeffs (UINT8 *CscScale, UINT8* CoeffA, UINT8* CoeffB, UINT8* CoeffC, RX_CSC CSC);
ATV_ERR ADIAPI_RxDppEn (BOOL Enable);
ATV_ERR ADIAPI_RxDppEnDcmStageManMode (BOOL Enable);
ATV_ERR ADIAPI_RxDppEnDppStageManMode (BOOL Enable);
ATV_ERR ADIAPI_RxDppEnChromaFiltManMode (BOOL Enable);
ATV_ERR ADIAPI_RxDppSetDcmResponse (RX_FILT_RESPONSE FiltResponse);
ATV_ERR ADIAPI_RxDppSetDppResponse (RX_FILT_RESPONSE FiltResponse);
ATV_ERR ADIAPI_RxDppSetDppCoeffs (UINT16 *CoeffA, UINT16 *CoeffBC);
ATV_ERR ADIAPI_RxDppSetChromaResponse (RX_FILT_RESPONSE FilterResponse);
ATV_ERR ADIAPI_RxDppSetChromaBandwidth (RX_FILT_BANDWIDTH Bandwidth);
ATV_ERR ADIAPI_RxDppFiltMode (RX_FILT_MODE FiltMode);

/*===================================
 * CP Funtions prototypes
 *==================================*/

ATV_ERR ADIAPI_RxCpEnPreGain (BOOL Enable);
ATV_ERR ADIAPI_RxCpSetPreGain (UINT8 Value);
ATV_ERR ADIAPI_RxCpEnManClamp (BOOL ManChAEnable, BOOL ManChBCEnable);
ATV_ERR ADIAPI_RxCpSetClamp (UINT16 ClmpChA, UINT16 ClmpChBC);
ATV_ERR ADIAPI_RxCpSetGainMode (RX_GAIN_MODE GainMode);
ATV_ERR ADIAPI_RxCpSetManGainFilter(RX_CP_DURATION Lines);
ATV_ERR ADIAPI_RxCpSetGain (UINT16 GainChA, UINT16 GainChB, UINT16 GainChC);
ATV_ERR ADIAPI_RxCpGetGain (UINT16 *GainChA, UINT16 *GainChB, UINT16 *GainChC);
ATV_ERR ADIAPI_RxCpGetHsyncDepthMsrmt (UINT16 *HsdChA, UINT16 *HsdChB, UINT16 *HsdChC);
ATV_ERR ADIAPI_RxCpGetGainedHsyncDepthMsrmt (UINT16 *HsdChA);
ATV_ERR ADIAPI_RxCpGetVideoPeakValue (UINT16 *PkvChA, UINT16 *PkvChB, UINT16 *PkvChC);
ATV_ERR ADIAPI_RxCpSetOpRange (RX_RANGE Range);
ATV_ERR ADIAPI_RxCpEnAutoOffset (BOOL ChAEn, BOOL ChBEn, BOOL ChCEn);
ATV_ERR ADIAPI_RxCpSetOffset (UINT16 OffsetChA, UINT16 OffsetChB, UINT16 OffsetChC);
ATV_ERR ADIAPI_RxCpSetSaturator (RX_RANGE Range);
ATV_ERR ADIAPI_RxCpConfigHsyncLckMsrmt (UINT8 Threshold, RX_CP_DURATION Lines);
ATV_ERR ADIAPI_RxCpSetNoiseCalibWindow (UINT16 Start, RX_CP_DURATION Length);
ATV_ERR ADIAPI_RxCpGetNoiseCalibMsmt (UINT16 *Noise, UINT16 *Calib);
ATV_ERR ADIAPI_RxCpEnColorControls (BOOL Enable);
ATV_ERR ADIAPI_RxCpSetContrast (UINT8 Contrast);
ATV_ERR ADIAPI_RxCpSetBrightness (UINT8 Brightness);
ATV_ERR ADIAPI_RxCpSetSaturation (UINT8 Saturation);
ATV_ERR ADIAPI_RxCpSetHue (UINT8 Hue);
ATV_ERR ADIAPI_RxCpRouteSyncToSyncCh (RX_HS_SEL Hsync, RX_VS_SEL Vsync, RX_EMBSYNC_SEL EmbSync, RX_SYNC_CH SyncCh);
ATV_ERR ADIAPI_RxCpSetSyncChSource (RX_SYNC_SRC SyncSrc, RX_SYNC_CH SyncCh);
ATV_ERR ADIAPI_RxCpEnSyncChAutoMode (BOOL Enable);
ATV_ERR ADIAPI_RxCpSetMainSyncCh (RX_SYNC_CH SyncCh);
ATV_ERR ADIAPI_RxCpGetMainSyncCh (RX_SYNC_CH *SyncCh);
ATV_ERR ADIAPI_RxCpSetSyncOnAllChComp (BOOL SyncOnAll);
ATV_ERR ADIAPI_RxCpSetSspdMode (RX_CP_MSRMT_MODE SspdMode, RX_SYNC_CH SyncCh);
ATV_ERR ADIAPI_RxCpGetSspdMsrmt (RX_SSPD_INFO *SspdInfo, RX_SYNC_CH SyncCh);
ATV_ERR ADIAPI_RxCpGetSspdStatus (BOOL *Locked, RX_SYNC_CH SyncCh);
ATV_ERR ADIAPI_RxCpSetStdiMode (RX_CP_MSRMT_MODE StdiMode, RX_SYNC_CH SyncCh);
ATV_ERR ADIAPI_RxCpGetStdiMsrmt (RX_STDI_INFO *StdiInfo, RX_SYNC_CH SyncCh);
ATV_ERR ADIAPI_RxCpGetStdiStatus (BOOL *Locked, RX_SYNC_CH SyncCh);
ATV_ERR ADIAPI_RxCpAdjustOpSync (RX_SYNC_SIG_ADJ SyncToAdjust, UINT16 NumbOfUnits);
ATV_ERR ADIAPI_RxCpSetFreeRunVic (UCHAR Vic, RX_OP_MODE *OperatingMode);
ATV_ERR ADIAPI_RxCpEnManFreeRunColor (BOOL Enable);
ATV_ERR ADIAPI_RxCpSetFreeRunColor (UINT8 ChA, UINT8 ChB, UINT8 ChC);
ATV_ERR ADIAPI_RxCpForceFreeRun (BOOL Enable);
ATV_ERR ADIAPI_RxCpEnHdmiFreeRun (BOOL Enable);
ATV_ERR ADIAPI_RxCpSetHdmiFreeRunMode (UINT8 FreeRunMode);
ATV_ERR ADIAPI_RxConfigAutoGrMode (RX_AUTO_GR_PARM *AutoGrParm);
ATV_ERR ADIAPI_RxCpGetStatus (RX_CP_STATUS *CpStatus);
ATV_ERR ADIAPI_RxCpGetMacrovisionStatus (RX_MCVS_STATUS *MvStatus);
ATV_ERR ADIAPI_RxCpSetSignalPolarity (RX_PIN_FUNCTION Pin, BOOL PosPolarity);

/*===================================
 * VDP Funtions prototypes
 *==================================*/
 /* VBI Data Processor Configuration*/
ATV_ERR ADIAPI_RxVdpEnable(BOOL Enable);
ATV_ERR ADIAPI_RxVdpInit (RX_VBI_TYPE DataType);
ATV_ERR ADIAPI_RxVdpSetLines (RX_VBI_TYPE *DataType, RX_VID_RES *VidRes, UCHAR *VbiLine);
ATV_ERR ADIAPI_RxVdpForceDataType (RX_VBI_TYPE TeleTextType, BOOL Enable);
ATV_ERR ADIAPI_RxVdpIsTypeDetected (RX_VBI_TYPE DataType);
ATV_ERR ADIAPI_RxVdpClearTypeDetected (RX_VBI_TYPE DataType);
ATV_ERR ADIAPI_RxVdpGetCrc (RX_VBI_TYPE DataType, UCHAR* Crc);
ATV_ERR ADIAPI_RxVdpEnAutoDetect (RX_VBI_TYPE DataType, BOOL Enable);
ATV_ERR ADIAPI_RxVdpEnAutoUpdate (RX_VBI_TYPE DataType, BOOL Enable);

/* VBI Data Extraction over  Standard I2C*/
ATV_ERR ADIAPI_RxVdpIsDataOnEvenField (RX_VBI_TYPE DataType);
ATV_ERR ADIAPI_RxVdpGetData (RX_VBI_TYPE DataType, UCHAR* Data);

 /*VBI Data transmission Configuration in 656 Stream*/
ATV_ERR ADIAPI_RxVdpInsertDataIn656Stream (BOOL Enable);
ATV_ERR ADIAPI_RxVdpSet656Ident (UCHAR Identifier);
ATV_ERR ADIAPI_RxVdpSetAux656Ident (UCHAR AuxIdentifier);
ATV_ERR ADIAPI_RxVdpSpreadDataOnYAndC (BOOL SpreadData);
ATV_ERR ADIAPI_RxVdpCfg656Data (RX_ADF_MODE Mode);
ATV_ERR ADIAPI_RxVdpEnSerialOutput (RX_VBI_TYPE DataType, BOOL Enable);

/*VBI Fast Data Readback over dedicated I2C or SPI interface*/
ATV_ERR ADIAPI_RxVdpCfgSpiInterface(BOOL Enable, RX_VBI_SPI_CFG* VbiSpiConfig); 
ATV_ERR ADIAPI_RxVdpEnFastI2cInterface(BOOL Enable); 
ATV_ERR ADIAPI_RxVdpEnFastRbDataType(RX_VBI_TYPE DataType, BOOL Enable);

#ifdef __cplusplus
}
#endif

#endif
