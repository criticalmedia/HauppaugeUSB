/**********************************************************************************************
*																						      *
* Copyright (c) 2012 Analog Devices, Inc.  All Rights Reserved.                               *
* This software is proprietary and confidential to Analog Devices, Inc. and its licensors.    *
*                                                                                             *
***********************************************************************************************/

#ifndef _RX_HAL_H_
#define _RX_HAL_H_


#include "wrapper.h"

#include "rx_defs.h"
#include "rx_cfg.h"

#if (RX_DEVICE == 7180)
#include "7180_hal.h"
#endif

#if (RX_DEVICE == 7604)
#include "7604_hal.h"
#endif

#if (RX_DEVICE == 7614)
#include "7604_hal.h"
#endif

#if (RX_DEVICE == 7840)
#include "7840_hal.h"
#endif

#if (RX_DEVICE == 7844)
#include "7844_hal.h"
#endif

#if (RX_DEVICE == 7850)
#include "7850_hal.h"
#endif

#if (RX_DEVICE == 7842)
#include "7842_hal.h"
#endif

#if (RX_DEVICE == 7612)
#include "7612_hal.h"
#endif

#if (RX_DEVICE == 7611)
#include "7611_hal.h"
#endif

#if (RX_DEVICE == 7619)
#include "7619_hal.h"
#endif

#if (RX_DEVICE == 7623) || (RX_DEVICE == 7622) || (RX_DEVICE == 76221)
#include "7623_rx_hal.h"
#endif

/*===============================================
 * Defines and macros
 *==============================================*/
#define RX_DBG                  if(RxUsrConfig&RX_ENABLE_DBG)DBG_MSG("-Rx: ");if(RxUsrConfig&RX_ENABLE_DBG)ATV_PrintTime(" ",1," ");if(RxUsrConfig&RX_ENABLE_DBG)DBG_MSG
#define RX_DEBUG                if(RxUsrConfig&RX_ENABLE_DBG)RX_DBG

#if RX_INCLUDE_CEC
#define CEC_I2C_MAP_BASE        VRX_CEC_MAP_ADDR
#if (RX_DEVICE == 7844)
    #define CEC_REG_RX_FRAME1_HDR              0x54
    #define CEC_REG_RX_FRAME1_DATA0            0x55
    #define CEC_REG_RX_FRAME2_HDR              0x66
    #define CEC_REG_RX_FRAME2_DATA0            0x67
    #define CEC_REG_RX_BUFFER_CONTROL          0x2c
    #define CEC_REG_RX_THREE_BUFFER_CONTROL    0x77
    #define CECREG_SET_CLR_RX_RDY1(val)        ATV_I2CWriteField8(CEC_I2C_MAP_BASE, CEC_REG_RX_BUFFER_CONTROL, 0x02, 0x1, val)
    #define CECREG_SET_CLR_RX_RDY2(val)        ATV_I2CWriteField8(CEC_I2C_MAP_BASE, CEC_REG_RX_BUFFER_CONTROL, 0x04, 0x2, val)
    #define CECREG_SET_CLR_RX_RDY3(val)        ATV_I2CWriteField8(CEC_I2C_MAP_BASE, CEC_REG_RX_BUFFER_CONTROL, 0x08, 0x3, val)
    #define CECREG_SET_NUM_RX_BUFFERS(val)     ATV_I2CWriteField8(CEC_I2C_MAP_BASE, CEC_REG_RX_THREE_BUFFER_CONTROL, 0x01, 0x0, val) 
#else    
    #define CECREG_SET_NUM_RX_BUFFERS(val)     NULL
#endif    
#endif

enum 
{
    INT_MASK_B1 = 0,
    INT_MASK_B2,
    INT_MASK_B3,
    INT_MASK_B4,
    INT_MASK_B5,
    INT_MASK_B6,
    LVL_MASK_B1,
    LVL_MASK_B2,
    LVL_MASK_B3,
    LVL_MASK_B4,
    LVL_MASK_B5,
    EDG_MASK_B1,
    EDG_MASK_B2,
    EDG_MASK_B3,
    EDG_MASK_B4,
    EDG_MASK_B5,
    SDP_MASK_B1,
    MV_MASK_B1,
    MV_MASK_B2,
    SDP_IO_MASK_B4,         /*Interrupt from SDP section of ADV7840*/
    NOF_RX_MASK_REGS             
};

typedef enum 
{
    RX_CS_COEFF = 1,
    RX_CS_ALT_COEFF,
    RX_CS_RB_COEFF,
    RX_CS_SDP_COEFF
} RX_CSC_COEFF;

/*===============================================
 * Structures
 *==============================================*/
typedef struct
{
    CONSTANT UCHAR Io;
    CONSTANT UCHAR SdpVdp;
    CONSTANT UCHAR AfeDpll;
    CONSTANT UCHAR Esdp;
    CONSTANT UCHAR SdpIo;
    CONSTANT UCHAR Cp;
    CONSTANT UCHAR Vdp;
    CONSTANT UCHAR Test1;
    CONSTANT UCHAR Test2;
    CONSTANT UCHAR Test3;
    CONSTANT UCHAR Rep;
    CONSTANT UCHAR Hdmi;
    CONSTANT UCHAR Edid;
    CONSTANT UCHAR Dpp;
    CONSTANT UCHAR Infoframe;
    CONSTANT UCHAR Cec;
    CONSTANT UCHAR Sdp;
    CONSTANT UCHAR Avlink;
    CONSTANT UCHAR Osd;
    CONSTANT UCHAR Vfe;
    CONSTANT UCHAR AudCodec;
    CONSTANT UCHAR DdrMem;
    CONSTANT UCHAR TxUdp;
    CONSTANT UCHAR TxEdid;
} RX_DEV_ADDR;

typedef struct
{
    BOOL TxReady;
    BOOL RxReady;
    BOOL ArbLost;
    BOOL Timeout;
    BOOL RxReady1;
    BOOL RxReady2;
    BOOL RxReady3;
    UCHAR RxFrameOrder[CEC_TRIPLE_NUMBER];            
} RX_CEC_INTS;

typedef struct
{
    BOOL AvIfValid;         /* RX_EVENT_HDMI_AVI_INFO       */
    BOOL AudIfValid;        /* RX_EVENT_HDMI_AUDIO_INFO     */
    BOOL SpdValid;          /* RX_EVENT_HDMI_SPD_INFO       */
    BOOL MsValid;           /* RX_EVENT_HDMI_MS_INFO        */
    BOOL VsValid;           /* RX_EVENT_HDMI_VS_INFO        */
    BOOL AcpValid;          /* RX_EVENT_HDMI_ACP_PCKT       */
    BOOL Isrc1Valid;        /* RX_EVENT_HDMI_ISRC1_PCKT     */
    BOOL Isrc2Valid;        /* RX_EVENT_HDMI_ISRC2_PCKT     */
    BOOL GamutValid;        /* RX_EVENT_HDMI_GAMUT_PCKT     */

    BOOL AvIfNotRec;        /* RX_EVENT_HDMI_NO_PCKT        */
    BOOL AudIfNotRec;       /* RX_EVENT_HDMI_NO_PCKT        */
    BOOL SpdNotRec;         /* RX_EVENT_HDMI_NO_PCKT        */
    BOOL MsNotRec;          /* RX_EVENT_HDMI_NO_PCKT        */
    BOOL VsNotRec;          /* RX_EVENT_HDMI_NO_PCKT        */
    BOOL AcpNotRec;         /* RX_EVENT_HDMI_NO_PCKT        */
    BOOL Isrc1NotRec;       /* RX_EVENT_HDMI_NO_PCKT        */
    BOOL Isrc2NotRec;       /* RX_EVENT_HDMI_NO_PCKT        */
    BOOL GamutNotRec;       /* RX_EVENT_HDMI_NO_PCKT        */

    BOOL AudModeChg;        /* RX_EVENT_HDMI_AUDIO_MODE_CHNG*/
    BOOL AudChanMode;       /* RX_EVENT_HDMI_AUDIO_CH_MD    */
    BOOL AvMute;            /* RX_EVENT_HDMI_AV_MUTE        */
    BOOL InternMute;        /* RX_EVENT_HDMI_INTERNAL_MUTE  */
    BOOL CsDataValid;       /* RX_EVENT_HDMI_CS_DATA_VALID  */

    BOOL HdmiModeChg;       /* RX_EVENT_HDMI_MODE_CHNG      */
    BOOL TmdsClkChg[RX_NOF_PORTS];    /* RX_EVENT_HDMI_TMDS_CLK_CHNG  */
    BOOL VidPllChg[RX_NOF_PORTS];     /* RX_EVENT_HDMI_VIDEO_PLL_LCK  */
    BOOL DeRegenLck;        /* RX_EVENT_HDMI_DE_REGEN_LCK   */
    BOOL VsyncLck;          /* RX_EVENT_HDMI_V_LOCKED       */

    BOOL EncChange[RX_NOF_PORTS];      /* RX_EVENT_HDMI_ENCR           */
    BOOL CableDetChg[RX_NOF_PORTS];    /* RX_EVENT_HDMI_CABLE_DET_D    */

    BOOL NChange;           /* RX_EVENT_HDMI_CHANGE_N       */
    BOOL CtsThresh;         /* RX_EVENT_HDMI_CTS_PASS_THRSH */
    BOOL AudFifoOv;         /* RX_EVENT_HDMI_FIFO_OVERFLO   */
    BOOL AudFifoUn;         /* RX_EVENT_HDMI_FIFO_UNDERFLO  */
    BOOL AudFifoNrOv;       /* RX_EVENT_HDMI_FIFO_NEAROVFL  */

    BOOL AudFifoNrUn;       /* RX_EVENT_HDMI_FIFO_NEARUFLO  */
    BOOL NewTmds;           /* RX_EVENT_HDMI_NEW_TMDS_FRQ   */
    BOOL AudFlatLine;       /* RX_EVENT_HDMI_AUDIO_FLT_LINE */
    BOOL AudSampChg;        /* RX_EVENT_HDMI_NEW_SAMP_RT    */
    BOOL AudPrtyErr;        /* RX_EVENT_HDMI_AUD_PARITY_ERR */
    BOOL AksvUpdate[RX_NOF_PORTS];     /* RX_EVENT_HDMI_AKSV_UPDATE    */
    BOOL BadTmdsClk;        /* RX_EVENT_HDMI_VCLK_CHNG      */
    BOOL DeepClrChg;        /* RX_EVENT_HDMI_DEEP_COLOR_CHNG */

    /*==============================
     * State of various events 
     *=============================*/
    BOOL CsValidRaw;
    BOOL TmdsClock[RX_NOF_PORTS]; 
    BOOL VidPllLock[RX_NOF_PORTS];
    BOOL CableDetect[RX_NOF_PORTS];
    BOOL Encrypted[RX_NOF_PORTS];
} RX_HDMI_INTERRUPTS;

typedef struct
{
    BOOL CpLckChng;         /*RX_EVENT_CP_LCK               */
    BOOL StdiLckChng;       /*RX_EVENT_CP_STDI_LCK          */
    BOOL CpCh1LckChng;      /*RX_EVENT_CP_LCK_SYNC_CH1      */
    BOOL StdiCh1LckChng;    /*RX_EVENT_CP_STDI_LCK_SYNC_CH1 */
    BOOL CpCh2LckChng;      /*RX_EVENT_CP_LCK_SYNC_CH2      */
    BOOL StdiCh2LckChng;    /*RX_EVENT_CP_STDI_LCK_SYNC_CH2 */
} RX_CP_INTERRUPTS;

typedef struct
{
    BOOL TtxtDet;               /*RX_EVENT_VDP_TTXT             */
    BOOL VitcDet;               /*RX_EVENT_VDP_VITC             */
    BOOL GsPdcVpsUtcDet;        /*RX_EVENT_VDP_GEMS_PDC_VPS_UTC */
    BOOL FastDataRbReady;		/*RX_EVENT_VDP_FAST_DATA_RDY*/
    BOOL CgmsWssDetected;       /*RX_EVENT_VDP_CGMS_WSS         */
    BOOL CcapDet;               /*RX_EVENT_VDP_CCAP             */ 
} RX_VDP_INTERRUPTS;

typedef struct
{
    BOOL BrstLckDet;         /*RX_EVENT_SDP_BURST_LCK*/
    BOOL VidSigDet;          /*RX_EVENT_SDP_VIDEO_DET*/
    BOOL StdChng;            /*RX_EVENT_SDP_STD_DET*/
} RX_SDP_INTERRUPTS;

typedef struct
{
	BOOL PSDet;				 /*RX_EVENT_MV_PS_DET*/
	BOOL AGCDet;			 /*RX_EVENT_MV_AGC_DET*/
	BOOL CSDet;				 /*RX_EVENT_MV_CS_DET*/
} RX_MV_INTERRUPTS;



typedef struct
{
    RX_EVENT    Event;
    UCHAR       Reg1;
    UCHAR       Mask1[2];
    UCHAR       Reg2;
    UCHAR       Mask2[2];
}MASK_INFO;

typedef struct
{ 
    RX_VID_RES      Res;
    UINT8           CVBSVidStdSet[2];       /*{RX_OS_2X1 Sup, RX_OS_4X1 Sup}*/
    UINT8           SCARTVidStdSet[2];      /*{RX_OS_2X1 Sup, RX_OS_4X1 Sup}*/
    UINT8           YCVidStdSet[2];         /*{RX_OS_2X1 Sup, RX_OS_4X1 Sup}*/
    UINT8           CVBS_YCVidStdSet[2];    /*{RX_OS_2X1 Sup, RX_OS_4X1 Sup}*/
    UINT8           CmpvidStdSet[2];        /*{RX_OS_2X1 Sup, RX_OS_4X1 Sup}*/
}RX_SDP_VIDSTD_INFO;

typedef struct
{ 
    RX_VID_RES      Res;
    UINT8           VidStdSet[5]; /*{RX_OS_1X1 Sup, RX_OS_2X1 Sup, RX_OS_4X1 Sup, RX_OS_2X2 Sup, RX_OS_4X2 Sup}*/
    BOOL            CmpVFreq[5];   /*{RX_VFRQ_24HZ Sup,RX_VFRQ_25HZ Sup,RX_VFRQ_30HZ Sup,RX_VFRQ_50HZ Sup,RX_VFRQ_56HZ Sup,RX_VFRQ_60HZ Sup}*/
    
}RX_CMP_VIDSTD_INFO;

typedef struct
{
    RX_VID_RES      Res;
    UINT8           VidStdSet[6]; /*{RX_VFRQ_56HZ Sup,RX_VFRQ_60HZ Sup,RX_VFRQ_70HZ Sup,RX_VFRQ_72HZ Sup,RX_VFRQ_75HZ Sup,RX_VFRQ_85HZ Sup}*/
}RX_GR_VIDSTD_INFO;

typedef struct
{
    UINT8           PrimMode;
    RX_VID_RES      Res;
    UINT8           GrVidStdSet[6];  /*{RX_VFRQ_56HZ Sup,RX_VFRQ_60HZ Sup,RX_VFRQ_70HZ Sup,RX_VFRQ_72HZ Sup,RX_VFRQ_75HZ Sup,RX_VFRQ_85HZ Sup}*/
    UINT8           CmpVidStdSet[5]; /*{RX_OS_1X1 Sup, RX_OS_2X1 Sup, RX_OS_4X1 Sup, RX_OS_2X2 Sup, RX_OS_4X2 Sup}*/
    BOOL            CmpVFreq[5];   /*{RX_VFRQ_24HZ Sup,RX_VFRQ_25HZ Sup,RX_VFRQ_30HZ Sup,RX_VFRQ_50HZ Sup,RX_VFRQ_56HZ Sup,RX_VFRQ_60HZ Sup}*/
}RX_HDMI_VIDSTD_INFO;

typedef struct 
{
    RX_SDP_FORMAT   SdpFormatIn;
    UINT8           _861IdOut;
    UINT8           *I2cTable; 
    UINT8           *I2cTable444;   
}SDP_861_INFO;

typedef struct
{
    UINT8             OpSelVal;
    RX_BUS_BIT_WIDTH  BitWidth;
    RX_BUS_OP_MODE    Format;
    RX_BUS_MODE       Mode;   
}RX_SDP_PIX_FORMAT_INFO;

/*===============================================
 * Shared variables
 *==============================================*/
EXTERNAL CONSTANT RX_DEV_ADDR RxDeviceAddress[];
EXTERNAL CONSTANT RX_DEV_ADDR *RxDevAddr;
EXTERNAL UCHAR RxCurrDevIdx;
EXTERNAL UCHAR RxActiveCecIdx;

/*===============================================
 * Shared constants
 *==============================================*/
EXTERNAL CONSTANT UCHAR RxHdmiMaskRegs[];
EXTERNAL CONSTANT UCHAR RxCpMaskRegs[];
EXTERNAL CONSTANT UCHAR RxSdpMaskRegs[];
EXTERNAL CONSTANT MASK_INFO RxMaskInfo[];
EXTERNAL CONSTANT UCHAR CeaVsyncPol[];

#ifdef __cplusplus
extern "C" {
#endif

/*===============================================
 * Shared prototypes by all devices
 *==============================================*/
void    HAL_RxI2CWriteTable (UCHAR *Table, UCHAR EndVal);
void    HAL_RxI2CWriteFields (UCHAR *Table, UCHAR EndVal);

#if (RX_NUM_OF_INSTANCES > 1)
ATV_ERR HAL_RxSetChipIndex (UCHAR ChipIdx);
#else
#define HAL_RxSetChipIndex(ChipIdx)     (ATVERR_NOT_AVAILABLE)
#endif

UCHAR   HAL_RxGetIntIndex (void);

/*==========================================
 * Prototypes that apply to all chips 
 * but have chip specific implementions
 *=========================================*/
ATV_ERR HAL_RxInit (RX_OP_MODE OperatingMode);
ATV_ERR HAL_SetI2cMapAddress(RX_I2C_MAP  Map, UINT8 Address);
ATV_ERR HAL_SetOperatingMode (RX_OP_MODE OperatingMode, RX_OP_MODE_CFG *OpModeCfg);
ATV_ERR HAL_SetManagePowerDown (RX_CHIP_SECTION Section, RX_PWRDN_MODE PowerDownMode);
ATV_ERR HAL_SetManagePower (RX_CHIP_SECTION Section, BOOL PowerUp);
ATV_ERR HAL_SetChipReset (RX_CHIP_SECTION Section);

ATV_ERR HAL_SetPinFunction (RX_PIN PinId, RX_PIN_FUNCTION PinFunction);
ATV_ERR HAL_SetTristatePin (RX_PIN Pin, BOOL Tristate);
ATV_ERR HAL_SetPinPolarity (RX_PIN Pin, BOOL PosPolarity);
ATV_ERR HAL_ConfigInt (RX_PIN IntPin, RX_INT_DURATION Duration, RX_PIN_LEVEL PinLevel);
ATV_ERR HAL_ForceIntLevel (RX_PIN IntPin, BOOL ForceLevel);
ATV_ERR HAL_SetDriveStrength (RX_PIN PinId,  RX_OP_DR_STR DriveLevel);
ATV_ERR HAL_RxSetPixelClkFreq (RX_PIX_CLK_FREQ PixClkFreq, BOOL Enable);
ATV_ERR HAL_SpiEdidEnable(BOOL Enable);

ATV_ERR HAL_RxCpSetSyncChSource (RX_SYNC_SRC SyncSrc, RX_SYNC_CH SyncCh);
ATV_ERR HAL_RxCpEnSyncChAutoMode (BOOL Enable);
ATV_ERR HAL_RxCpSetMainSyncCh (RX_SYNC_CH SyncCh);
ATV_ERR HAL_RxCpGetMainSyncCh (RX_SYNC_CH *SyncCh);
ATV_ERR HAL_RxCpSetSspdMode (RX_CP_MSRMT_MODE SspdMode, RX_SYNC_CH SyncCh);
ATV_ERR HAL_RxCpGetSspdMsrmt (RX_SSPD_INFO *SspdInfo, RX_SYNC_CH SyncCh);
ATV_ERR HAL_RxCpGetSspdStatus (BOOL *Locked, RX_SYNC_CH SyncCh);
ATV_ERR HAL_RxCpSetStdiMode (RX_CP_MSRMT_MODE StdiMode, RX_SYNC_CH SyncCh);
ATV_ERR HAL_RxCpGetStdiMsrmt (RX_STDI_INFO *StdiInfo, RX_SYNC_CH SyncCh);
ATV_ERR HAL_RxCpGetStdiStatus (BOOL *Locked, RX_SYNC_CH SyncCh);

/*==========================================
 * Prototypes that apply to all chips 
 * with an pixel output port but may have chip
 * specific implementions
 *=========================================*/
#if ((RX_DEVICE==7604) || (RX_DEVICE==7614) || (RX_DEVICE==7840) || (RX_DEVICE==7844)\
     || (RX_DEVICE==7842) || (RX_DEVICE==7612) || (RX_DEVICE==7611) || (RX_DEVICE==7180) || (RX_DEVICE==7619))
                       
ATV_ERR HAL_SetManSigPhase (RX_CLOCK_SIG Signal, UINT8 Phase);
ATV_ERR HAL_SetManSigPhaseEn (RX_CLOCK_SIG Signal, BOOL Enable);
ATV_ERR HAL_SetOpPixFormat (RX_PIX_BUS_INFO* PixBusInfo,  RX_OP_MODE* OpMode);

#endif
/*==========================================
 * Prototypes that apply to 7850 chips 
 * Only.
 * 7850 has no pixel Port and An audio Condec
 * It has a VDP dedicated SPI interface
 *=========================================*/
#if (RX_DEVICE ==7850)

ATV_ERR HAL_RxCpSetSignalPolarity(RX_PIN_FUNCTION Signal, BOOL PosPolarity);
ATV_ERR HAL_RxCdecConfig(RX_MCLK MclkRef);
ATV_ERR HAL_RxCdecRouteAudInToTx(RX_CDEC_IN AudLrIn, BOOL Enable);
ATV_ERR HAL_RxCdecRouteAudInToAudLoopback(RX_CDEC_IN OutL, RX_CDEC_IN OutR, BOOL Enable);
ATV_ERR HAL_RxCdecConfigAudioOut(RX_CDEC_OUT AudOut, RX_CDEC_IN DigAudIn);
ATV_ERR HAL_RxCdecSetVolume(RX_CDEC AudOut, UCHAR Factor);
ATV_ERR HAL_RxCdecSetMute(RX_CDEC AudOut, BOOL Mute);
ATV_ERR HAL_RxVdpCfgSpiInterface(BOOL Enable, RX_VBI_SPI_CFG* VbiSpiConfig);
ATV_ERR HAL_RxAfeSetVideoOutMux (RX_VOUT_CH VidOutChannel, RX_AIN_CH AinChannel);
ATV_ERR HAL_RxEdidCfgSpiInterface( RX_EDID_SPI_CFG* EdidSpiConfig, BOOL Enable);
ATV_ERR HAL_RxEdidCfgSpiHeader( RX_EDID_SPI_HEADER SpiEdidHeader);
#endif
/*===================================
 * Prototypes that apply to all chips 
 * with an AFE but may have chip
 * specific implementions
 *==================================*/
#if ((RX_DEVICE==7604) || (RX_DEVICE==7614) || (RX_DEVICE==7840)\
    || (RX_DEVICE==7844)|| (RX_DEVICE==7842) || (RX_DEVICE==7850)\
    || (RX_DEVICE==7180))
                       
ATV_ERR HAL_SetAinAutoMuxModeSel(UINT8 AinMode);
ATV_ERR HAL_SetManAinMux(RX_ADC ADC, RX_AIN_CH AinChannel);
ATV_ERR HAL_ConfigTriLevelSlicer(RX_TRI_SLICER TriSlicer, RX_TRI_SLICER_MODE SliceMode, RX_TRI_SLICE_LEVEL* SliceLevels );
ATV_ERR HAL_SetTriLevelSlicerEn(RX_TRI_SLICER TriSlicer, BOOL PowerUp);
ATV_ERR HAL_GetTriLevelSlicerStatus(RX_TRI_SLICER TriSlicer, RX_TRI_SLICER_STATUS* TriStatus);
ATV_ERR HAL_SetAntiAliasFiltEn(RX_ADC ADC, BOOL Enable);
ATV_ERR HAL_SelAntiAliasFilt(RX_AA_FILT_RESPONSE FiltResponse);
ATV_ERR HAL_SetSyncSlicerFilt(RX_SYNC_SLICER SyncSlicer, RX_SYNC_SLICER_FILTER SyncFilter);
ATV_ERR HAL_RxAfeCfgAfeSlicerEvent(RX_TRI_SLICER Slicer, RX_TRI_SLICER_LEVEL EnableLvl);

#endif

/*===================================
 * Prototypes that apply to all chips 
 * with an CP Core but may have chip
 * specific implementions
 *==================================*/
ATV_ERR HAL_CpRouteSyncToSyncCh (RX_HS_SEL Hsync, RX_VS_SEL Vsync, RX_EMBSYNC_SEL EmbSync, RX_SYNC_CH SyncCh);
ATV_ERR HAL_RxCpSetGain (UINT16 GainChA, UINT16 GainChB, UINT16 GainChC);
ATV_ERR HAL_RxSetCscCoeff(UINT8 CscScale, UINT8 *CoeffA, UINT8 *CoeffB, UINT8 *CoeffC, RX_CSC_COEFF CscCoeff);
ATV_ERR HAL_RxGetCscCoeff(UINT8 *CscScale, UINT8 *CoeffA, UINT8 *CoeffB, UINT8 *CoeffC, RX_CSC_COEFF CscCoeff);

void    HAL_RxCpGetInterrupts (RX_CP_INTERRUPTS *RxCpInts);
ATV_ERR HAL_RxSetInpVidCfg(RX_OP_MODE OpMode, RX_VID_RES Res, RX_VRT_FRQ Freq, RX_OS_RATE OvrSmplng);
ATV_ERR HAL_CpSet861RecSettings(UINT8 Vid861, RX_OP_MODE OpMode);

UCHAR   HAL_RxCpSetEnabledEvents (RX_EVENT *EventList, UCHAR ListSize, BOOL Enable);
ATV_ERR HAL_RxCpGetGainMode (RX_GAIN_MODE *GainMode);
void    HAL_RxCpHouseKeeping (void);

/*===================================
 * Prototypes that apply to all chips 
 * with an HDMI Rx but may have chip
 * specific implemenations
 *==================================*/
void    HAL_RxHdmiInit (void);
UCHAR   HAL_RxHdmiSetEnabledEvents (RX_EVENT *EventList, UCHAR ListSize, BOOL Enable);
void    HAL_RxHdmiGetInterrupts (RX_HDMI_INTERRUPTS *RxHdmiInts);
void    HAL_RxCecGetInterrupts (RX_CEC_INTS *RxCecInts);
void    HAL_RxHdmiHouseKeeping (void);

BOOL    HAL_RxSelPortTmdsDetected (void);
BOOL    HAL_RxVPllLocked (RX_HDMI_PORT Port);
BOOL    HAL_RxEncrypted (RX_HDMI_PORT Port);
ATV_ERR HAL_RxSetHdcpBcaps (RX_HDMI_PORT Port, UCHAR Bcaps);
ATV_ERR HAL_RxSetHdcpBstatus (RX_HDMI_PORT Port, UINT16 Bstatus);

void    HAL_RxSetBksvListReadyBit (BOOL On);
BOOL    HAL_RxGetAksvUpdate (RX_HDMI_PORT Port);
UCHAR   HAL_RxReadKsvList (UCHAR * KsvBuf);
ATV_ERR HAL_RxSetKsvFifo (UCHAR * BksvList, UCHAR  BksvCount);

ATV_ERR HAL_RxAssertHpd (RX_HDMI_PORT Port, BOOL Enable);
ATV_ERR HAL_RxIsHpdOn (RX_HDMI_PORT Port, BOOL *HpdOn);
BOOL    HAL_RxIntPending (UCHAR IntId);
void    HAL_RxPktDetectWorkaround (RX_PACKET_TYPE PktType);

ATV_ERR HAL_RxHdmiSetInternalEdid (UCHAR *EdidBuffer, UINT16 SpaOffset, 
                        UCHAR *SpaValues, UCHAR SegNum, BOOL DisableAutoEdid);

ATV_ERR HAL_RxGetHdmiOpColorSpace(RX_CS_COLOR * ColorSpace);
ATV_ERR HAL_RxGetHdmiOpRange(RX_RANGE * Range);

/*=========================================
 * Same implementations  across all chips  
 * with HDMI RX    
 * =======================================*/
UCHAR   HAL_RxGetPortIndex (RX_HDMI_PORT Port);
ATV_ERR HAL_RxEnableInternalEdid (RX_HDMI_PORT Port, BOOL Enable);
UCHAR   HAL_RxSetSpas (UINT16 SpaLoc, UCHAR *SpaPtr);
UCHAR   HAL_RxPopulateEdidMap (UCHAR *EdidPtr, UINT16 EdidSize, UCHAR SegNum);
UCHAR   HAL_RxReadEdidMap (UCHAR * data, UINT16 size, UCHAR SegNum);
ATV_ERR HAL_RxGetEnabledInternalEdid (RX_HDMI_PORT Port, BOOL * Enable);
void    HAL_RxToggleInternalEdid (void);
UCHAR   HAL_RxGetPixRepValue (void);

UINT32  HAL_GetN (void);
void    HAL_GetDetectedAudioType (RX_AUDIO_TYPE *AudioType);


/*===================================
 * HDMI Prototypes that apply to 
 * 4G and 5G
 * =================================*/
#if ((RX_DEVICE == 7844) || (RX_DEVICE == 7842) || (RX_DEVICE == 7623)\
    || (RX_DEVICE == 7612) || (RX_DEVICE == 7622)|| (RX_DEVICE == 7619)\
    || (RX_DEVICE == 7850) || (RX_DEVICE == 76221))

ATV_ERR HAL_RxSetFastSwitchPort (RX_HDMI_PORT Port, BOOL Enable);
ATV_ERR HAL_RxHdmiReqBgMeas (RX_HDMI_PORT Port);
ATV_ERR HAL_RxHdmiGetBgTmdsFreq (RX_HDMI_PORT Port, UINT16 * TmdsFreqMHz, UCHAR * TmdsFreqFrac);
ATV_ERR HAL_RxHdmiGetBgHsyncInfo (RX_HDMI_PORT Port, RX_HDMI_HSYNC * HsyncInfo);
ATV_ERR HAL_RxHdmiGetBgVsyncInfo (RX_HDMI_PORT Port, RX_HDMI_VSYNC * VsyncInfo);
ATV_ERR HAL_RxHdmiGetBgDeepColorMode (RX_HDMI_PORT Port, RX_COLOR_DEPTH * DeepColorMode);
ATV_ERR HAL_RxHdmiGetBgPixelRepeat (RX_HDMI_PORT Port, UCHAR * RepeatFactor);

#endif

/*===================================
 * Prototypes that apply to 
 * only ADV7844 and ADV7842
 *==================================*/
#if ((RX_DEVICE==7844) || (RX_DEVICE ==7842)|| (RX_DEVICE ==7850))
void    HAL_RxSdpGetInterrupts (RX_SDP_INTERRUPTS *RxSdpInts);
ATV_ERR HAL_RXLIB_SdpIsr (void);
ATV_ERR HAL_RXLIB_MvIsr (void);
ATV_ERR HAL_RxEnInternalVgaEdid (UCHAR * EdidBuffer, BOOL Enable);
#endif

/*===================================
 * Prototypes that apply to all chips 
 * with an SDP Core but may have chip
 * specific implemenations
 *==================================*/
#if ((RX_DEVICE==7840) || (RX_DEVICE==7844) || (RX_DEVICE==7842)\
     || (RX_DEVICE==7850) || (RX_DEVICE==7180))

UCHAR   HAL_RxSdpSetEnabledEvents (RX_EVENT *EventList, UCHAR ListSize, BOOL Enable);
UCHAR   HAL_RxMvSetEnabledEvents (RX_EVENT *EventList, UCHAR ListSize, BOOL Enable);
void    HAL_RxSdpHouseKeeping (void);
void    HAL_RxMvHouseKeeping (void);
void HAL_RxMvGetInterrupts(RX_MV_INTERRUPTS *RxMvInts);
ATV_ERR HAL_SetSdp861RecSettings(RX_SDP_FORMAT SdpFormatIn, UINT8 Vid861Out, RX_OP_MODE OpMode);
ATV_ERR HAL_EnSdpFrameTbc(BOOL Enable);  
ATV_ERR HAL_InitSdpMemInterface(RX_SDP_MEM MemType);
ATV_ERR HAL_EnSdpMemInterface(BOOL Enable);

/*===================================
 * Prototypes that apply to all chips 
 * with an SDP Core but have the same
 * implemention
 *==================================*/

ATV_ERR HAL_CfgSdpAutoFormatDetect(RX_SDP_FORMAT SDPFormat, BOOL Enable);
ATV_ERR HAL_CfgSdpFormatPedestalStatus(RX_SDP_FORMAT SDPFormat, BOOL PedestalPresent);
ATV_ERR HAL_GetSdpAutoFormatDetectResult(RX_SDP_FORMAT* SDPFormat);
ATV_ERR HAL_GetSdpVideoDetectStatus(BOOL* SDPVideoDetectedStatus);
ATV_ERR HAL_GetSdpBurstLockedStatus(BOOL* SDPBurstLockedStatus);
ATV_ERR HAL_EnSdpSFL(BOOL Enable);
ATV_ERR HAL_GetSdpAutoFormatDetectResult(RX_SDP_FORMAT* SDPFormat);
ATV_ERR HAL_GetSdpFieldRateStatus(RX_SDP_FIELD_RATE* FieldRate);
ATV_ERR HAL_GetSdpStatus(RX_SDP_STATUS* SDPStatus);
ATV_ERR HAL_GetSdpMcvsStatus(RX_MCVS_STATUS* MvStatus);
ATV_ERR HAL_SetSdpSaturation(UINT16 Saturation);
ATV_ERR HAL_SetSdpBrightness(UINT16 Brightness);
ATV_ERR HAL_SetSdpHue(UINT16 Hue);
ATV_ERR HAL_SetSdpLumaGainMode(RX_GAIN_MODE LumaGainMode);
ATV_ERR HAL_SetSdpManLumaGain(UINT16 LumaGain);
ATV_ERR HAL_GetSdpLumaGain(UINT16* LumaGainRB);
ATV_ERR HAL_SetSdpChromaGainMode(RX_GAIN_MODE ChromaGainMode);
ATV_ERR HAL_SetSdpManChromaGain(UINT16 ChromaGain);
ATV_ERR HAL_EnSdp3dComb(BOOL Enable);  
ATV_ERR HAL_SetSdpClampSpeed(RX_CLAMP Clamp, UINT8 Speed);
ATV_ERR HAL_SdpForceFreeRun (BOOL Enable);
ATV_ERR HAL_SdpCfgColorKill(BOOL Enable, UINT8 HighThres, UINT8 LowThres);
#if (RX_DEVICE !=7180  && RX_DEVICE !=7842  && RX_DEVICE !=7840)
ATV_ERR HAL_RxHdmiSetArcMode (RX_ARC_MODE Mode, RX_ARC_TX ArcTx);
#endif
#if (RX_DEVICE !=7850)
ATV_ERR HAL_SetSdpItoPMode(RX_ItoP_MODE ItoPMode);
ATV_ERR HAL_EnSdpItoP(BOOL Enable );
#endif
#endif

/*===================================
 * Prototypes that apply to all chips 
 * with an VDP Core but may have chip
 * specific implemenations
 *==================================*/
#if ((RX_DEVICE==7604) || (RX_DEVICE==7840) || (RX_DEVICE==7844)\
     || (RX_DEVICE==7842)|| (RX_DEVICE==7850) || (RX_DEVICE==7180))

#if RX_INCLUDE_VBI
ATV_ERR HAL_RXLIB_VdpIsr (void);
void  HAL_RxVdpGetInterrupts (RX_VDP_INTERRUPTS *RxVdpInts);
UCHAR HAL_RxVdpSetEnabledEvents (RX_EVENT *EventList, UCHAR ListSize, BOOL Enable);
#endif

ATV_ERR HAL_RxVdpEnable(BOOL Enable);
ATV_ERR HAL_RxVdpInit(RX_VBI_TYPE DataType);
ATV_ERR HAL_RxVdpSetLines(RX_VBI_TYPE *DataType, RX_VID_RES *VidRes, UCHAR *VbiLine);
ATV_ERR HAL_RxVdpForceDataType(RX_VBI_TYPE DataType, BOOL Enable);
ATV_ERR HAL_RxVdpIsTypeDetected(RX_VBI_TYPE DataType);
ATV_ERR HAL_RxVdpClearTypeDetected(RX_VBI_TYPE DataType);   
ATV_ERR HAL_RxVdpIsDataOnEvenField(RX_VBI_TYPE DataType);
ATV_ERR HAL_RxVdpGetData(RX_VBI_TYPE DataType, UCHAR* Data);
ATV_ERR HAL_RxVdpGetCrc(RX_VBI_TYPE DataType, UCHAR* Crc);
ATV_ERR HAL_RxVdpEnAutoDetect(RX_VBI_TYPE DataType, BOOL Enable);
ATV_ERR HAL_RxVdpEnAutoUpdate(RX_VBI_TYPE DataType, BOOL Enable);
/*==========================================
 * Prototypes that apply to 2G, 3G, 4G and 5G
 * These prototypes do not apply to 7850
 *=========================================*/
#if( RX_DEVICE !=7850)
ATV_ERR HAL_RxVdpInsertDataIn656Stream(BOOL Enable);
ATV_ERR HAL_RxVdpSet656Ident(UCHAR Identifier);
ATV_ERR HAL_RxVdpSetAux656Ident(UCHAR AuxIdentifier);
ATV_ERR HAL_RxVdpSpreadDataOnYAndC(BOOL SpreadData);
ATV_ERR HAL_RxVdpCfg656Data(RX_ADF_MODE Mode);
ATV_ERR HAL_RxVdpEnSerialOutput(RX_VBI_TYPE DataType, BOOL Enable);
#endif
#endif

#if ((RX_DEVICE==7840) || (RX_DEVICE==7180))

#if RX_INCLUDE_VBI

ATV_ERR HAL_RXLIB_SdpVdpIsr (void);
void  HAL_RxSdpVdpGetInterrupts (RX_VDP_INTERRUPTS *RxVdpInts);
UCHAR HAL_RxSdpVdpSetEnabledEvents (RX_EVENT *EventList, UCHAR ListSize, BOOL Enable);

#endif

#endif

/*==========================================
 * Prototypes that apply to ADV7840 Only 
 *=========================================*/
#if ((RX_DEVICE==7840) || (RX_DEVICE==7180))

ATV_ERR HAL_SetSdpPixelClkFreq(RX_PIX_CLK_FREQ PixClkFreq, BOOL Enable);
ATV_ERR HAL_SetSdpVidStd (UINT8 VideoStandard);
ATV_ERR HAL_SetSdpEnManAinMux(BOOL Enable);
ATV_ERR HAL_EnSdp3dDnr(BOOL Enable);  
ATV_ERR HAL_EnExtBiasing(BOOL Enable);

#endif

/*==========================================
 * Prototypes that apply to 3G, 4G and 5G
 * These prototypes do not apply to 2G
 *=========================================*/
#if (RX_DEVICE != 7180)
    
ATV_ERR HAL_RxSetCscMode (RX_CSC_MODE Mode, RX_CSC Csc);
ATV_ERR HAL_RxGetCscMode (RX_CSC_MODE *Mode, RX_CSC Csc);
ATV_ERR HAL_RxSetCscConfig (RX_CSC_CONFIG Config, RX_CSC Csc);
ATV_ERR HAL_RxGetCscConfig (RX_CSC_CONFIG *Config, RX_CSC Csc);
ATV_ERR HAL_RxSetIpColorSpace (RX_CS_COLOR ColorSpace, RX_RANGE Range, RX_CSC Csc);
ATV_ERR HAL_RxGetIpColorSpace (RX_CS_COLOR *ColorSpace, RX_RANGE *Range, RX_CSC Csc);
ATV_ERR HAL_RxSetOpColorSpace (RX_CS_COLOR ColorSpace, RX_CSC Csc);
ATV_ERR HAL_RxGetOpColorSpace (RX_CS_COLOR *ColorSpace, RX_CSC Csc);
ATV_ERR HAL_RxSetManCscCoeffs (UINT8 CscScale, UINT8* CoeffA, UINT8* CoeffB, UINT8* CoeffC, RX_CSC CSC);
ATV_ERR HAL_RxGetManCscCoeffs (UINT8 *CscScale, UINT8* CoeffA, UINT8* CoeffB, UINT8* CoeffC, RX_CSC CSC);

ATV_ERR HAL_RxSetAutoIpColorSpace(RX_CS_COLOR ColorSpace, RX_RANGE Range, RX_CSC Csc);
ATV_ERR HAL_RxGetAutoIpColorSpace(RX_CS_COLOR * ColorSpace, RX_RANGE * Range, RX_CSC Csc);
ATV_ERR HAL_RxSetAutoOpColorSpace(RX_CS_COLOR ColorSpace, RX_CSC Csc);
ATV_ERR HAL_RxGetAutoOpColorSpace(RX_CS_COLOR *ColorSpace, RX_CSC Csc);
ATV_ERR HAL_RxHdmiEnAudioClock (BOOL Enable);
#endif

/*===============================================
 * Prototypes that apply to ADV7604 & ADV7840
 * 2G DPP
 * =============================================*/
#if ((RX_DEVICE==7604) || (RX_DEVICE==7614) || (RX_DEVICE==7840))

ATV_ERR HAL_RxDppEnDcmStageManMode (BOOL Enable);
ATV_ERR HAL_RxDppEnDppStageManMode (BOOL Enable);
ATV_ERR HAL_RxDppEnChromaFiltManMode (BOOL Enable);
ATV_ERR HAL_RxDppSetDcmResponse (RX_FILT_RESPONSE FiltResponse);
ATV_ERR HAL_RxDppSetDppResponse (RX_FILT_RESPONSE FiltResponse);
ATV_ERR HAL_RxDppSetDppCoeffs (UINT16 *CoeffA, UINT16 *CoeffBC);
ATV_ERR HAL_RxDppSetChromaResponse (RX_FILT_RESPONSE FilterResponse);
ATV_ERR HAL_RxDppSetChromaBandwidth (RX_FILT_BANDWIDTH Bandwidth);


#endif
/*========================================================
 * Prototypes that apply to all chips with 2G or 3G DPP
 * =======================================================*/
#if ((RX_DEVICE!=7623) && (RX_DEVICE!=7622) && (RX_DEVICE!=76221) && (RX_DEVICE!=7850)&& (RX_DEVICE!=7180))
ATV_ERR HAL_RxDppFiltMode (RX_FILT_MODE FiltMode);
#endif
/*========================================================
 * Prototypes that apply to ADV7844 & ADV7842 & ADV7840
 * =======================================================*/
#if ((RX_DEVICE==7844) || (RX_DEVICE==7842) || (RX_DEVICE==7840))
ATV_ERR HAL_RxVdpEnFastI2cInterface(BOOL Enable);


#endif
#if ((RX_DEVICE==7844) || (RX_DEVICE==7842) || (RX_DEVICE==7840) || (RX_DEVICE==7850))
ATV_ERR HAL_RxVdpEnFastRbDataType(RX_VBI_TYPE DataType, BOOL Enable);
#endif
#if (RX_DEVICE == 7612)
ATV_ERR HAL_RxChipSelect(UCHAR DevIdx);
#endif

#ifdef __cplusplus
}
#endif

#endif
