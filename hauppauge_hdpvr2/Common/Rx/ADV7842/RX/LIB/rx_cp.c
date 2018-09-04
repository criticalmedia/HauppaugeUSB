/**********************************************************************************************
*																						      *
* Copyright (c) 2012 Analog Devices, Inc.  All Rights Reserved.                               *
* This software is proprietary and confidential to Analog Devices, Inc. and its licensors.    *
*                                                                                             *
***********************************************************************************************/

/*============================================================================
 * This file contains two sections:
 *
 * - CP APIs that apply to all devices
 * - CP APIs that apply to specific devices
 *
 *===========================================================================*/
#include "rx_lib.h"
#include "rx_isr.h"

STATIC CONSTANT UCHAR FrunVidStd[NUM_OF_VICS] = {
    0xff, 0xff, 0x0a, 0x0a, 0x13, 0x14, 0x00, 0x00, 0xff, 0xff, 
    0x00, 0x00, 0xff, 0xff, 0x0a, 0x0a, 0x1e, 0x0b, 0x0b, 0x13, 
    0x14, 0x01, 0x01, 0xff, 0xff, 0x01, 0x01, 0xff, 0xff, 0x0a, 
    0x0a, 0x1e, 0x1e, 0x1e, 0xff, 0x0a, 0x0a, 0x0a, 0x0a, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x13, 0x13, 0x13, 0xff, 0xff 
};

STATIC CONSTANT UCHAR FrunVFreq[NUM_OF_VICS] = {
    0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 
    0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
    0x01, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 
    0x00, 0x01, 0x04, 0x03, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0x04, 0x03, 0x02, 0xff, 0xff 
};

#define CP_DEVICES ((RX_DEVICE == 7604) || (RX_DEVICE == 7614) || (RX_DEVICE == 7840)\
                    || (RX_DEVICE == 7844)|| (RX_DEVICE == 7842) || (RX_DEVICE == 7612)\
                    || (RX_DEVICE == 7611) || (RX_DEVICE == 7619) || (RX_DEVICE == 7850))
#define ADC_DEVICES ((RX_DEVICE == 7604) || (RX_DEVICE == 7614) || (RX_DEVICE == 7840)\
                    || (RX_DEVICE == 7844)|| (RX_DEVICE == 7842) || (RX_DEVICE == 7850))
#if CP_DEVICES

#define PRIM_MODE_AUTO_GR   0x2
#define VID_STD_AUTO_GR     0x7

CONSTANT UCHAR ManGainFilterCfg[] =
{
    RX_0_LINES,     0,
    RX_128_LINES,   1,
    RX_256_LINES,   2,
    RX_512_LINES,   3,
    RX_1K_LINES,    4,
    RX_2K_LINES,    5,
    RX_4K_LINES,    6,
    RX_8K_LINES,    7,
    RX_16K_LINES,   8,
    0xff
};
#endif
CONSTANT UCHAR GainModeCfg[] =
{
    RX_GAIN_AUTO,   0,  0,
    RX_GAIN_AGC,    1,  0,
    RX_GAIN_MAN,    1,  1,
    0xff
};

CONSTANT UCHAR SspdModeCfg[] =
{
     RX_CP_ONE_SHOT,    0,
     RX_CP_CONTINUOUS,  1,
     0xff
};

CONSTANT UCHAR StdiModeCfg[] =
{
    RX_CP_ONE_SHOT,     0,  0,
    RX_CP_CONTINUOUS,   1,  0,
    RX_CP_REAL_TIME,    1,  1,
    0xff
};

#if ADC_DEVICES
CONSTANT UCHAR NoiseCalibWindowCfg[] = 
{
    RX_16_LLC_CYCLES,   3,
    RX_32_LLC_CYCLES,   2,
    RX_64_LLC_CYCLES,   1,
    RX_128_LLC_CYCLES,  0,
    0xff
};

CONSTANT UCHAR SyncChSourceCfg[] =
{
    RX_AUTO_SYNC,   0,
    RX_HS_VS,       1,
    RX_HS_CS,       2,
    RX_EMB_SYNC,    3,
    0xff
};
#endif

CONSTANT UCHAR CeaVsyncPol[NUM_OF_VICS] = 
{  /* +Ve= 4, 5, 16, 19, 20, 31, 32, 33, 34, 40, 41, 46, 47, 60-64 */
    0, 0, 0, 0, 1 ,1, 0, 0,         /*  0 -  7 */
    0, 0, 0, 0, 0 ,0, 0, 0,         /*  8 - 15 */
    1, 0, 0, 1, 1 ,0, 0, 0,         /* 16 - 23 */
    0, 0, 0, 0, 0 ,0, 0, 1,         /* 24 - 31 */
    1, 1, 1, 0, 0 ,0, 0, 0,         /* 32 - 39 (39 Hsync is +Ve) */
    1, 1, 0, 0, 0 ,0, 1, 1,         /* 40 - 47 */
    0, 0, 0, 0, 0 ,0, 0, 0,         /* 48 - 55 */
    0, 0, 0, 0, 1, 1, 1, 1,         /* 56 - 63 */
    1                               /* 64 */
};
                        
/*============================================================================
 * Set the video mode that will be used during free run. 
 * The required free-run video mode will be lost when the part exits free-run 
 * and must be manually set again if the part re-enters free-run.
 *
 * Entry:   Vic = The VIC that should be used during free-run. Not all VIC
 *                codes can be used. Only the following VIC values can be 
 *                used:
 *                2-7, 10, 11, 14-22, 25, 26, 29-33, 35-38
 *                The special VIC value of 0xff is used to instruct the part
 *                to use the last locked HDMI video mode whenever it enters 
 *                free-run.
 *          OperatingMode = Set this variable to NULL
 * 
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_INV_PARM = Invalid VIC code provided
 *
 * Notes:   This function will not enter free-run mode, it will only set the
 *          video standard to be used for free-run. 
 *          Any subsequent call to ADIAPI_RxSetPrimModVidStd() will override 
 *          the video mode used for free-run.
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpSetFreeRunVic (UCHAR Vic, RX_OP_MODE *OperatingMode)
{
    ATV_ERR RetVal = ATVERR_INV_PARM;

    if ((Vic <= MAX_VIC_VALUE) && (FrunVidStd[Vic] != 0xff))
    {
        ADIAPI_RxSetPrimModVidStd (5, FrunVidStd[Vic]);
        if (FrunVFreq[Vic] != 0xff)
        {
            VRX_set_V_FREQ(FrunVFreq[Vic]);
        }
        VRX_set_DIS_AUTO_PARAM_BUFF(1);
        RetVal =  ATVERR_OK;
    }
    else if (Vic == 0xff)
    {
        VRX_set_DIS_AUTO_PARAM_BUFF(0);
        RetVal =  ATVERR_OK;
    }
    return (RetVal);
}

/*============================================================================
 * Enable free run for HDMI mode
 *
 * Entry:   Enable: ATV_TRUE = Enable free run in HDMI mode
 *                  ATV_FALSE = Disable free run in HDMI mode
 *  
 * Return:  ATVERR_OK = Function completed successfully
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpEnHdmiFreeRun (BOOL Enable)
{
    Enable &= 1;
    VRX_set_HDMI_FRUN_EN((UINT8)Enable);
    return (ATVERR_OK);
}

/*============================================================================
 * Configure manual free run color configuration
 *
 * Entry:   Enable: ATV_TRUE = Enable manual color configuration for free run
 *                  ATV_FALSE = Enable automatic color configuration for 
 *                              free run
 * 
 * Return:  ATVERR_OK = Function completed successfully
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpEnManFreeRunColor (BOOL Enable)
{
    Enable &= 1;
    VRX_set_CP_DEF_COL_AUTO((UINT8)Enable);
    return (ATVERR_OK);
}

/*============================================================================
 * Set the color used for free run
 *
 * Entry:   ChA = Color value for channel component A
 *          ChB = Color value for channel component B
 *          ChC = Color value for channel component C
 *  
 * Return:  ATVERR_OK = Function completed successfully
 *
 * Notes:   See also ADIAPI_RxCpEnManFreeRunColor
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpSetFreeRunColor (UINT8 ChA, UINT8 ChB, UINT8 ChC)
{
    VRX_set_DEF_COL_CHA(ChA);
    VRX_set_DEF_COL_CHB(ChB);
    VRX_set_DEF_COL_CHC(ChC);
    return (ATVERR_OK);
}

/*============================================================================
 * Force the part in or out of free run
 *
 * Entry:   Enable: ATV_TRUE = Force free run
 *                  ATV_FALSE = Do not force free run
 *  
 * Return:  ATVERR_OK = Function completed successfully
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpForceFreeRun (BOOL Enable)
{
    Enable &= 1;
    VRX_set_CP_FORCE_FREERUN((UINT8)Enable);
    return (ATVERR_OK);
}

/*============================================================================
 * Set the polarity of the sync signals output by the CP section
 *
 * Entry:   Signal: Output signal which polarity must be set
 *                  RX_VS_SIG
 *                  RX_HS_SIG
 *                  RX_DE_SIG
 *          PosPolarity: 
 *                  TRUE
 *                  FALSE
 *  
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_INV_PARM =  Invalid input parameter
 * 
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpSetSignalPolarity (RX_PIN_FUNCTION Signal, BOOL PosPolarity)
{
    return (HAL_RxCpSetSignalPolarity(Signal, PosPolarity));
}

/*============================================================================
 * Section 2:
 *
 * CP APIs that apply to specific devices
 *
 *===========================================================================*/

#if CP_DEVICES

/*============================================================================
 * Enable the pre-gain block in the CP section
 *
 * Entry:   Enable: Enable the CP PreGain
 *
 * Return:  ATVERR_OK = Function completed successfully
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpEnPreGain(BOOL Enable)
{
    Enable &= 1;
    VRX_set_CP_MODE_GAIN_ADJ_EN((UINT8)Enable);
    return (ATVERR_OK);
}

/*============================================================================
 * Set the pre-gain value of the CP section
 *
 * Entry:   PreGain: PreGain value
 *
 * Return:  ATVERR_OK = Function completed successfully
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpSetPreGain(UINT8 PreGain)
{
    VRX_set_CP_MODE_GAIN_ADJ(PreGain);
    return (ATVERR_OK);
}

/*============================================================================
 * Configure clamps for channels A , B and C
 *
 * Entry:   ManChAEnable: ATV_TRUE = Enable manual clamp for channel A
 *                        ATV_FALSE = Disable manual clamp for channel A
 *          ManChBCEnable : ATV_TRUE = Enable manual clamp for channel B and C
 *                          ATV_FALSE = Disable manual clamp for channel B and C
 *
 * Return:  ATVERR_OK = Function completed successfully
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpEnManClamp(BOOL ManChAEnable, BOOL ManChBCEnable)
{
    ManChAEnable &= 1;
    ManChBCEnable &= 1;
    VRX_set_CLMP_A_MAN((UINT8)ManChAEnable);
    VRX_set_CLMP_BC_MAN((UINT8)ManChBCEnable);
    return (ATVERR_OK);
}

/*============================================================================
 * Set manual clamp values for channels A, B and C.
 *
 * Entry:   ClmpChA: Manual clamp value for channel A. 
 *          ClmpChBC : Manual clamp value for channels B and C.
 *
 * Return:  ATVERR_OK = Function completed successfully
 *
 * Notes:   Only the 12 LSBs or ClmpChA and ClmpChBC are used
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpSetClamp (UINT16 ClmpChA, UINT16 ClmpChBC)
{
    VRX_set_CLMP_A((UINT32)(ClmpChA & 0xFFF));
    VRX_set_CLMP_B((UINT32)(ClmpChBC & 0xFFF));
    VRX_set_CLMP_C((UINT32)(ClmpChBC & 0xFFF));
    return (ATVERR_OK);
}

/*============================================================================
 * Set the gain mode
 *
 * Entry:   GainMode: RX_GAIN_AUTO = Gain automatically computed and dependant
 *                                   the output range
 *                    RX_GAIN_AGC =  Gain generated by the AGC section
 *                    RX_GAIN_MAN = Gain manually set by user
 *
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_INV_PARM = Invalid input parameter
 *
 * Notes:   See also ADIAPI_RxCpGetGain
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpSetGainMode (RX_GAIN_MODE GainMode)
{
    UINT8 i;
    
      
    i = (UCHAR)(ATV_LookupValue8 ((UCHAR*)GainModeCfg, 
                                                (UCHAR)GainMode, 0xff, 3));
    if(GainModeCfg[i] != 0xff)
    {
        VRX_set_AGC_MODE_MAN(GainModeCfg[i+1]);
        VRX_set_GAIN_MAN(GainModeCfg[i+2]);
        return (ATVERR_OK);
    }
    return (ATVERR_INV_PARM);
}

/*============================================================================
 * Retun the gain mode
 *
 * Entry:   GainMode: RX_GAIN_AUTO = Gain automatically computed and dependant
 *                                   the output range
 *                    RX_GAIN_AGC =  Gain generated by the AGC section
 *                    RX_GAIN_MAN = Gain manually set by user
 *
 * Return:  ATVERR_OK = Function completed successfully
 *
 * Notes:   See also ADIAPI_RxCpSetGain
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpGetGainMode (RX_GAIN_MODE *GainMode)
{
    return (HAL_RxCpGetGainMode (GainMode));
}

/*============================================================================
 * Set the averaging filter used for manual gain
 *
 * Entry:   Lines: Number of lines over which programmed manual gain value are 
 *                 averaged before being applied to the video data
 *
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_INV_PARM = Invalid input parameter
 *
 * Notes:   See also ADIAPI_RxCpSetGainMode, ADIAPI_RxCpSetGain
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpSetManGainFilter(RX_CP_DURATION Lines)
{
    UINT8 i;
    
    
    i = (UCHAR)(ATV_LookupValue8 ((UCHAR*)ManGainFilterCfg, 
                                                (UCHAR)Lines, 0xff, 2));
    if(ManGainFilterCfg[i] != 0xff)
    {
        VRX_set_CP_GAIN_FILT(ManGainFilterCfg[i+1]);
        return (ATVERR_OK);
    }
    return (ATVERR_INV_PARM);
}

/*============================================================================
 * Set the manual gain factors
 *
 * Entry:   GainMode: GainChA = Manual gain for channel A in 2.8 binary format
 *                    GainChB = Manual gain for channel B in 2.8 binary format
 *                    GainChC = Manual gain for channel C in 2.8 binary format
 *
 * Return:  ATVERR_OK = Function completed successfully
 *
 * Notes:   Only the 10 LSBs or GainChA, GainChB and GainChC are used
 *          See also ADIAPI_RxCpSetGainMode
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpSetGain (UINT16 GainChA, UINT16 GainChB, UINT16 GainChC)
{
    HAL_RxCpSetGain (GainChA, GainChB, GainChC);
    return (ATVERR_OK);
}

/*============================================================================
 * Return the gain used for the manual gain mode.
 *
 * Entry:   GainMode: GainChA = Manual gain for channel A in 2.8 binary format
 *                    GainChB = Manual gain for channel B in 2.8 binary format
 *                    GainChC = Manual gain for channel C in 2.8 binary format
 *
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_FALSE = The Gain value read are not applied to the video
 *                         data as manual gain is not active
 *          
 *
 * Notes:   See also ADIAPI_RxCpGetGain
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpGetGain (UINT16 *GainChA, UINT16 *GainChB, UINT16 *GainChC)
{
    RX_GAIN_MODE GainMode;
    
    VRX_get_A_GAIN((UINT32*)GainChA);
    VRX_get_A_GAIN((UINT32*)GainChB);
    VRX_get_A_GAIN((UINT32*)GainChC);
    HAL_RxCpGetGainMode (&GainMode);
    if(GainMode != RX_GAIN_MAN)
    {
        return (ATVERR_FALSE);
    }
    return (ATVERR_OK); 
}

/*============================================================================
 * Set the output range of the video data output by the CP core
 *
 * Entry:   Range : Range of the data output by the CP section
 *                  RX_RG_16_235 = Range is 16 to 235 for channel A
 *                                 Range is 16 to 240 for channels B and C
 *                  RX_RG_0_255 = Range is 0 to 255 for channel A, B and C
 *
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_INV_PARM = Invalid input parameter
 *
 * Notes:   See also ADIAPI_RxCpSetGain and ADIAPI_RxCpSetGainMode
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpSetOpRange (RX_RANGE Range)
{
    switch(Range)
    {
        case RX_RG_16_235:
            VRX_set_OP_656_RANGE(1);
            break;
        case RX_RG_0_255:
            VRX_set_OP_656_RANGE(0);
            break;
        default:
            return (ATVERR_INV_PARM);
    }
    return (ATVERR_OK);
}



/*============================================================================
 * Set the offset mode
 *
 * Entry:   ChAEn : ATV_TRUE =  Enable automatic offset for channel A
 *                  ATV_FALSE =  Do nothing. Manual offset is enabled if 
 *                               offset for channel A is set to a value 
 *                               other than 0x3FF
 *          ChBEn : ATV_TRUE =  Enable automatic offset for channel B
 *                  ATV_FALSE =  Do nothing. Manua offset is enabled if 
 *                               offset for channel B is set to a value 
 *                               other than 0x3FF
 *          ChCEn : ATV_TRUE =  Enable automatic offset for channel C
 *                  ATV_FALSE =  Do nothing. Manua offset is enabled if 
 *                               offset for channel C is set to a value 
 *                               other than 0x3FF
 *
 * Return:  ATVERR_OK = Function completed successfully
 *
 * Notes:   See also ADIAPI_RxCpSetOffset
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpEnAutoOffset (BOOL ChAEn, BOOL ChBEn, BOOL ChCEn)
{
    if(ChAEn)
    {
        VRX_set_A_OFFSET(0x3FF);
    }
    if(ChBEn)
    {
        VRX_set_B_OFFSET(0x3FF);
    }
    if(ChCEn)
    {
        VRX_set_C_OFFSET(0x3FF);
    }
    return (ATVERR_OK);
}

/*============================================================================
 * Set the offset for channels A, B and C
 *
 * Entry:   OffsetChA : offset value for channel A
 *          OffsetChB : offset value for channel B
 *          OffsetChC : offset value for channel C
 *
 * Return:  ATVERR_OK = Function completed successfully 
 *
 * Notes:   Setting the offset of a channel to 0x3FFF effectively set the 
 *          offset for that channel in automatic mode 
 *          See also ADIAPI_RxCpEnAutoOffset
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpSetOffset (UINT16 OffsetChA, UINT16 OffsetChB, UINT16 OffsetChC)
{
    VRX_set_A_OFFSET((UINT32)OffsetChA);
    VRX_set_B_OFFSET((UINT32)OffsetChB);
    VRX_set_C_OFFSET((UINT32)OffsetChC);
    return (ATVERR_OK);
}

/*============================================================================
 * Set the range of the output Saturator
 *
 * Entry:   Range: range the staurator must be set to
 *
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_INV_PARM = Invalid input parameter
 *
 * Notes:   This function should always be called after setting the output
 *          range via ADIAPI_RxCpSetOpRange
 *          See also ADIAPI_RxCpSetOpRange
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpSetSaturator (RX_RANGE Range)
{
    UINT8 Op656Range;
    UINT8 AltSat;
    
    
    Op656Range = VRX_ret_OP_656_RANGE(); /*0 select full, 1 means limited*/
    switch(Range)
    {
        case RX_RG_16_235:
            if(Op656Range == 0) /*Full Range*/
            {
                AltSat = 1;     /*Invert Full range to limited*/
            }
            else
            {
                AltSat = 0;  /*Do not invert, keep at limited*/
            }
            break;
        case RX_RG_0_255:
            if(Op656Range == 0) /*Full Range*/
            {
                AltSat = 0;     /*Do not invert, keep at Full*/
            }
            else
            {
                AltSat = 1;     /*Invert keep to full range*/
            }
            break;
        default:
            return (ATVERR_INV_PARM);
    }
    VRX_set_ALT_DATA_SAT(AltSat);
    return (ATVERR_OK);
}


/*============================================================================
 * Enable/Disable the color controls
 *
 * Entry:   Enable: Enable/Disable the color controls
 *
 * Return:  ATVERR_OK = Function completed successfully
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpEnColorControls(BOOL Enable)
{
    Enable &= 1;
    VRX_set_VID_ADJ_EN(Enable);
    return (ATVERR_OK); 
}

/*============================================================================
 * Set the contrast
 *
 * Entry:   Contrast: Contrast in 1.7 binary format
 *               0x80 = Luma gain set to 1
 *               0x00 = Luma gain set to 0
 *               0xFF = Luma gain set to 1.99
 *
 * Return:  ATVERR_OK = Function completed successfully
 *
 * Notes:   See also ADIAPI_RxCpEnColorCtrls
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpSetContrast(UINT8 Contrast)
{
    VRX_set_CP_CONTRAST(Contrast);
    return (ATVERR_OK);
}

/*============================================================================
 * Set the saturation
 *
 * Entry:   Saturation: Saturation in 1.7 binary format
 *               0x80 = Chroma gain set to 1
 *               0x00 = Chroma gain set to 0
 *               0xFF = Chroma gain set to 1.99
 *
 * Return:  ATVERR_OK = Function completed successfully
 *
 * Notes:   See also ADIAPI_RxCpEnColorCtrls
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpSetSaturation(UINT8 Saturation)
{
    VRX_set_CP_SATURATION(Saturation);
    return (ATVERR_OK);
}

/*============================================================================
 * Set the brightness
 *
 * Entry:   Brightness: Brightness. The applied gain is this signed number 
 *                      gained by 4.
 *               0x00 = Offset on Luma channel is 0
 *               0x70 =  Offset on Luma channel is 508
 *               0xFF =  Offset on Luma channel is -512
 *
 * Return:  ATVERR_OK = Function completed successfully
 *
 * Notes:   See also ADIAPI_RxCpEnColorCtrls
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpSetBrightness(UINT8 Brightness)
{
    VRX_set_CP_BRIGHTNESS(Brightness);
    return (ATVERR_OK);
}

/*============================================================================
 * Set the Hue
 *
 * Entry:   Hue: Hue value
 *               0x00 = -90 degrees
 *               0x0F = 0 degree
 *               0xFF = 90 degrees
 *
 * Return:  ATVERR_OK = Function completed successfully
 *
 * Notes:   See also ADIAPI_RxCpEnColorCtrls
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpSetHue(UINT8 Hue)
{
    VRX_set_CP_HUE(Hue);
    return (ATVERR_OK);
}

/*============================================================================
 * Return the Hue
 *
 * Entry:   Hue: Hue value
 *               0x00 = -90 degrees
 *               0x0F = 0 degree
 *               0xFF = 90 degrees
 *
 * Return:  ATVERR_OK = Function completed successfully
 *
 * Notes:   See also ADIAPI_RxCpEnColorCtrls
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpGetHue(UINT8 *Hue)
{
    VRX_get_CP_HUE(Hue);
    return (ATVERR_OK);
}
/*============================================================================
 * Adjust a selected sync parameter
 *
 * Entry:   SyncToAdjust: The sync parameter to adjust
 *          NumbOfUnits: The number of paremeters (e.g. number of pixels, 
 *                       number of lines) by which the selected sync paremeter
 *                       must be adjsuted by
 * 
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_INV_PARM = Invalid input parameter
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpAdjustOpSync (RX_SYNC_SIG_ADJ SyncToAdjust, UINT16 NumbOfUnits)
{
    switch(SyncToAdjust)
    {
        case RX_LEAD_EDGE_HS:
            VRX_set_START_HS((UINT32)(NumbOfUnits & 0x3FF));
            break;
        case RX_TRAIL_EDGE_HS:
            VRX_set_END_HS((UINT32)(NumbOfUnits & 0x3FF));
            break;
        case RX_LEAD_EDGE_VS:
            VRX_set_START_VS((UINT8)(NumbOfUnits & 0xF));
            break;
        case RX_TRAIL_EDGE_VS:
            VRX_set_END_VS((UINT8)(NumbOfUnits & 0xF));
            break;
        case RX_EVEN_FIELD_START:
            VRX_set_START_FE((UINT8)(NumbOfUnits & 0xF));
            break;
        case RX_ODD_FIELD_START:
            VRX_set_START_FO((UINT8)(NumbOfUnits & 0xF));
            break;
        case RX_LEAD_EDGE_DE:
            VRX_set_DE_H_START((UINT32)(NumbOfUnits & 0x3FF));
            break;
        case RX_TRAIL_EDGE_DE:
            VRX_set_DE_H_END((UINT32)(NumbOfUnits & 0x3FF));
            break;
        case RX_VBI_START:
            VRX_set_DE_V_START((UINT8)(NumbOfUnits & 0xF));
            break;
        case RX_VBI_END:
            VRX_set_DE_V_END((UINT8)(NumbOfUnits & 0xF));
            break;
        default:
            return (ATVERR_INV_PARM);
    }
    return (ATVERR_OK);
}

/*============================================================================
 * Configure free run for HDMI mode
 *
 * Entry:   FreeRunMode: 0 = Free run mode 0
 *                       1 = Free run mode 1
 *  
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_INV_PARM = Invalid input parameter
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpSetHdmiFreeRunMode (UINT8 FreeRunMode)
{
    if(FreeRunMode<2)
    {
        VRX_set_HDMI_FRUN_MODE(FreeRunMode);
    }
    else
    {
        return (ATVERR_INV_PARM);
    }
    return (ATVERR_OK);
}

/*============================================================================
 * Return Information status from the CP section
 *
 * Entry:   CpStatus: Information status from the CP section
 *  
 * Return:  ATVERR_OK = Function completed successfully
 * 
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpGetStatus (RX_CP_STATUS *CpStatus)
{
    CpStatus->FreeRun = VRX_is_CP_FREE_RUN_true();
    CpStatus->CpLock = VRX_is_CP_LOCK_RAW_true();
    CpStatus->MvAgcDetected = VRX_is_MV_AGC_DET_true();
    CpStatus->MvPseudoDetected = VRX_is_MV_PS_DET_true();
    CpStatus->OpInterlace = VRX_is_CP_INTERLACED_true();
    CpStatus->InterlaceDetected = VRX_is_CP_FORCE_INTERLACED_true();
    return (ATVERR_OK);
}

/*============================================================================
 * Routes input syncs (i.e. VS, HS and Emb_Sync) to a specific sync channel
 *
 * Entry:   Hsync: Input Hsync to rout to sync channel SyncCh
 *          Vsync: Input Vsync to route to sync channel SyncCh
 *          EmbSync: Embedded sync to route to sync channel SyncCh
 *          SyncCh: Sync channel to which sync must be routed to        
 * 
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_INV_PARM = Invalid input parameter
 *
 * Notes:   See also ADIAPI_RxCpEnSyncChAutoMode, ADIAPI_RxCpSetMainSyncCh
 *          ADIAPI_RxCpGetMainSyncCh
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpRouteSyncToSyncCh (RX_HS_SEL Hsync, RX_VS_SEL Vsync, RX_EMBSYNC_SEL EmbSync, RX_SYNC_CH SyncCh)
{
    return (HAL_CpRouteSyncToSyncCh (Hsync, Vsync, EmbSync, SyncCh));
}

/*============================================================================
 * Select the type of sync that is used by a specific syn channel
 *
 * Entry:   SyncSrc: type of sync processed by the sync channel SyncCh 
 *          SyncCh: Sync channel to which sync must be routed to        
 * 
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_INV_PARM = Invalid input parameter
 *
 * Notes:   See also ADIAPI_RxCpEnSyncChAutoMode, ADIAPI_RxCpSetMainSyncCh
 *          ADIAPI_RxCpGetMainSyncCh
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpSetSyncChSource (RX_SYNC_SRC SyncSrc, RX_SYNC_CH SyncCh)
{
   
    return (HAL_RxCpSetSyncChSource (SyncSrc, SyncCh));
}

/*============================================================================
 * Set the selection mode of the sync channel processed by the CP section
 *
 * Entry:   Enable : ATV_TRUE =  Enable automatic selection of the sync 
 *                               channel processed by the CP section
 *                   ATV_FALSE =  Enable manual selection of the sync 
 *                               channel processed by the CP section        
 * 
 * Return:  ATVERR_OK = Function completed successfully
 *
 * Notes:   See also ADIAPI_RxCpRouteSyncToSyncCh, ADIAPI_RxCpSetMainSyncCh
 *          ADIAPI_RxCpGetMainSyncCh
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpEnSyncChAutoMode (BOOL Enable)
{
  
    return (HAL_RxCpEnSyncChAutoMode (Enable));
}

/*============================================================================
 * Set the sync channel that is proccesed in manual sync selection mode.
 * Set the priority order of the sync processed by the CP section in automatic 
 * sync selection mode. 
 *
 * Entry:   SyncCh : The CP section processes channel SyncCh in 
 *                   manual sync selection mode.
 *                   The CP section prioritarily processes channel SyncCh in 
 *                   automatic sync selection mode.     
 * 
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_INV_PARM = Invalid input parameter
 *
 * Notes:   See also ADIAPI_RxCpRouteSyncToSyncCh, ADIAPI_RxCpEnSyncChAutoMode,
 *          ADIAPI_RxCpGetMainSyncCh
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpSetMainSyncCh (RX_SYNC_CH SyncCh)
{
   
    return (HAL_RxCpSetMainSyncCh (SyncCh));
}

/*============================================================================
 * Return the sync channel that is being processed by the CP section
 *
 * Entry:   SyncCh : The CP section is currently processing channel SyncCh  
 * 
 * Return:  ATVERR_OK = Function completed successfully
 *
 * Notes:   See also ADIAPI_RxCpRouteSyncToSyncCh, ADIAPI_RxCpEnSyncChAutoMode,
 *          ADIAPI_RxCpSetMainSyncCh
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpGetMainSyncCh (RX_SYNC_CH *SyncCh)
{
   
    return (HAL_RxCpGetMainSyncCh (SyncCh));
}

/*============================================================================
 * Set the SSPD measurement mode
 *
 * Entry:   SspdMode: Sets the SSPD measurement mode
 *          SyncCh: Sync channel for which the SSPD measurement mode must be 
 *                  set
 * 
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_INV_PARM = Invalid input parameter
 *
 * Notes:   See also ADIAPI_RxCPGetSspdMsrmt
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpSetSspdMode (RX_CP_MSRMT_MODE SspdMode, RX_SYNC_CH SyncCh)
{
    
    return (HAL_RxCpSetSspdMode (SspdMode, SyncCh));
}

/*============================================================================
 * Return the SSPD measurement for a selected sync channel
 *
 * Entry:   SspdInfo: SSPD measurement
 *          SyncCh: Sync channel for which the SSPD measurement must be 
 *                  returned
 * 
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_FAILED = Valid SSPD measurement not available
 *          ATVERR_INV_PARM = Invalid input parameter
 *
 * Notes:   See also ADIAPI_RxCpSetSspdMode
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpGetSspdMsrmt (RX_SSPD_INFO *SspdInfo, RX_SYNC_CH SyncCh)
{
   
    return (HAL_RxCpGetSspdMsrmt (SspdInfo, SyncCh));
}

/*============================================================================
 * Returns the lock status of the SSPD for a selected sync channel
 *
 * Entry:   Locked: lock status of the SSPD in sync channel SyncCh
 *          SyncCh: Sync channel for which the STDI lock status must be 
 *                  returned           
 *
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_INV_PARM = Invalid input parameter
 *
 * Notes:
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpGetSspdStatus (BOOL *Locked, RX_SYNC_CH SyncCh)
{
    return(HAL_RxCpGetSspdStatus (Locked, SyncCh));
}

/*============================================================================
 * Set the STDI measurement mode
 *
 * Entry:   StdiMode: Sets the STDI measurement mode
 *          SyncCh: Sync channel for which the STDI measurement mode must be 
 *                  set
 * 
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_INV_PARM = Invalid input parameter
 *
 * Notes:   See also ADIAPI_RxCpGetStdiMsrmt
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpSetStdiMode (RX_CP_MSRMT_MODE StdiMode, RX_SYNC_CH SyncCh)
{

   return (HAL_RxCpSetStdiMode (StdiMode, SyncCh));
}

/*============================================================================
 * Return the STDI measurement for a selected sync channel
 *
 * Entry:   StdiInfo: STDI measurement
 *          SyncCh: Sync channel for which the STDI measurement must be 
 *                  returned
 * 
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_FAILED = Valid SSPD measurement not available
 *          ATVERR_INV_PARM = Invalid input parameter
 *
 * Notes:   See also ADIAPI_RxCpSetStdiMode
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpGetStdiMsrmt (RX_STDI_INFO *StdiInfo, RX_SYNC_CH SyncCh)
{
    return (HAL_RxCpGetStdiMsrmt (StdiInfo, SyncCh));
}

/*============================================================================
 * Returns the lock status of the STDI for a selected sync channel
 *
 * Entry:   Locked: lock status of the STDI in sync channel SyncCh
 *          SyncCh: Sync channel for which the STDI lock status must be 
 *                  returned           
 *
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_INV_PARM = Invalid input parameter
 *
 * Notes:
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpGetStdiStatus (BOOL *Locked, RX_SYNC_CH SyncCh)
{
    return (HAL_RxCpGetStdiStatus (Locked, SyncCh));
}

#if ADC_DEVICES
/*============================================================================
 * Configure AGC for sync on all 3 channel components
 *
 * Entry:   SyncOnAll: ATV_TRUE = sync present on all 3 channel component A, B
 *                     and C
 *                     ATV_FALSE = sync only  present on the Luma channel
 *                     component
 * 
 * Return:  ATVERR_OK = Function completed successfully
 *
 * Notes:   See also ADIAPI_RxCpSetGainMode
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpSetSyncOnAllChComp (BOOL SyncOnAll)
{
    SyncOnAll &= 1;
    VRX_set_EMB_SYNC_ON_ALL((UINT8)SyncOnAll);
    return (ATVERR_OK);
}

/*============================================================================
 * Return macrovision status from the CP section
 *
 * Entry:   MvStatus: Macrovision status from the CP section
 *  
 * Return:  ATVERR_OK = Function completed successfully
 * 
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpGetMacrovisionStatus(RX_MCVS_STATUS *MvStatus)
{
    MvStatus->CsType3 = FALSE;
    MvStatus->CsType2 = FALSE;
    /*MvStatus->PsDetected = VRX_is_MV_PS_DET_true();*/
    MvStatus->AgcDetected = VRX_is_MV_AGC_DET_true();
    MvStatus->CsDetected = FALSE;
    /*MvStatus->TotalBpPulsesEnd = 0;
    MvStatus->TotalBpPulsesBeg = 0;*/
    return (ATVERR_OK);
}
/*============================================================================
 * Return the hsync depth measurement done before aftet the DPP CP and before
 * the gain multiplier.
 *
 * Entry:   HsdChA : Readback value of measured horizontal synchronization 
 *                   depth on channel A (before gain multiplier). the value is
 *                   in 1.9 binary fomat
 *          HsdChC : Readback value of measured horizontal synchronization 
 *                   depth on channel B (before gain multiplier). the value is
 *                   in 1.9 binary fomat
 *          HsdChC : Readback value of measured horizontal synchronization 
 *                   depth on channel C (before gain multiplier). the value is
 *                   in 1.9 binary fomat
 *
 * Return:  ATVERR_OK = Function completed successfully
 *
 * Notes:   See also ADIAPI_RxCpGetGainedHsyncDepthMsrmt
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpGetHsyncDepthMsrmt(UINT16 *HsdChA, UINT16 *HsdChB, UINT16 *HsdChC)
{
    VRX_get_HSD_CHA(HsdChA);
    VRX_get_HSD_CHA(HsdChB);
    VRX_get_HSD_CHA(HsdChC);        
    return (ATVERR_OK);
}

/*============================================================================
 * Return the hsync depth measurement done before aftet the DPP CP and after
 * the gain multiplier.
 *
 * Entry:   HsdChA : Readback value of measured horizontal synchronization 
 *                   depth on channel A (after gain multiplier). the value is
 *                   in 1.9 binary fomat   
 *
 * Return:  ATVERR_OK = Function completed successfully
 *
 * Notes:
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpGetGainedHsyncDepthMsrmt(UINT16 *HsdChA)
{
    VRX_get_HSD_FB(HsdChA);      
    return (ATVERR_OK);
}

/*============================================================================
 * Return the maximum value measured during the active video on each channel
 * component A, B and C. The values returned are unsigned.
 *
 * Entry:   PkvChA: Value for the channel component A
 *          PkvChB: Value for the channel component B
 *          PkvChC: Value for the channel component C
 *
 * Return:  ATVERR_OK = Function completed successfully
 *
 * Notes:
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpGetVideoPeakValue (UINT16 *PkvChA, UINT16 *PkvChB, UINT16 *PkvChC)
{
    VRX_get_PKV_CHA(PkvChA);
#if 0       /*these functions are incorrect in the low level library*/
    VRX_get_PKV_CHB(PkvChB);
    VRX_get_PKV_CHC(PkvChC);
#endif
    return (ATVERR_OK);
}
/*============================================================================
 * Set the threshold used to measure the hsync lock robustness measurement
 *
 * Entry:   Threshold: The threshold is set to
 *                     (level of hsync tip) +0.5*(hsync depth)
 *                     The theshold is automatically set if Threshold is set to
 *                     zero.
 *          Lines: Number of lines used to average the hsync depght measurement
 *                 RX_128_LINES = 128 lines are used
 *                 RX_256_LINES = 256 lines are used
 *  
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_INV_PARM = Invalid input parameter
 *
 * Notes:   See also ADIAPI_RxCpGetHsyncDepthMsrmt,
 *          ADIAPI_RxCpGetGainedHsyncDepthMsrmt 
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpConfigHsyncLckMsrmt(UINT8 Threshold, RX_CP_DURATION Lines)
{
    VRX_set_ISD_THR(Threshold);
    switch(Lines)
    {
        case RX_128_LINES:
            VRX_set_IFSD_AVG(0);
            break;
        case RX_256_LINES:
            VRX_set_IFSD_AVG(1);
            break;
        default:
            return (ATVERR_INV_PARM);            
    }
    return (ATVERR_OK);
}

/*============================================================================
 * Set the measurement window used for noise and calibration
 *
 * Entry:   WindowStart: Start value (in LLC clock cycles) of measurement 
 *                       window. Value of 0 positions window at trailing 
 *                       edge of incoming Hsync.
 *                       Only the 12 LSBs are used of WindowsStart are used
 *          WindowLength: Window meansurement length
 *                        - RX_CP_16_LLC_CYCLES = 16 LLC clock cycles
 *                        - RX_CP_32_LLC_CYCLES = 32 LLC clock cycles
 *                        - RX_CP_64_LLC_CYCLES = 64 LLC clock cycles
 *                        - RX_CP_128_LLC_CYCLES = 128 LLC clock cycles 
 *
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_INV_PARM = Invalid input parameter
 *
 * Notes: See also ADIAPI_RxCpGetNoiseCalibMsrmt
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpSetNoiseCalibWindow (UINT16 WindowStart, RX_CP_DURATION WindowLength)
{
    UINT8 i;
    
    VRX_set_MEAS_WS(WindowStart & 0xFFF);  
    i = (UCHAR)(ATV_LookupValue8 ((UCHAR*)NoiseCalibWindowCfg, 
                                                (UCHAR)WindowStart, 0xff, 2));
    if(NoiseCalibWindowCfg[i] != 0xff)
    {
        VRX_set_MEAS_WL(NoiseCalibWindowCfg[i+1]);
        return (ATVERR_OK);
    }
    return (ATVERR_INV_PARM);
}

/*============================================================================
 * Return noise and calibration measurements
 *
 * Entry:   Noise: Unsigned number representing the difference between the
 *                 maximum and the minimum value video signal measured
 *                 during the last video data line.
 *          Calib: Average signal level oer the extent of the measurement 
 *                 window
 *
 * Return:  ATVERR_OK = Function completed successfully
 *
 * Notes:   See also ADIAPI_RxCpSetNoiseCalibWindow
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxCpGetNoiseCalibMsrmt (UINT16 *Noise, UINT16 *Calib)
{
    *Noise = (UINT16)(VRX_ret_NOISE());
#if 0
    *calib = VRX_ret_CALIB();
#endif
    return (ATVERR_OK);
}
/*============================================================================
 * Configure the part into auto graphic mode
 *
 * Entry:   AutoGrParm: A pointer to the the set of auto graphic mode 
 *                      parameters the part must be set with
 *                      The auto-graphic mode is disabled if a NULL pointer
 *                      is passed. in that case the function configure all auto
 *                      grahic registers as follow:
 *                          - The PLL Divider Ratio is set in automatic mode
 *                          - All other auto-graphic related registers are set 
 *                            to 0
 *                      When the pointer is not a NULL pointer, the following 
 *                      auto-graphic parameters should be set to a non zero 
 *                      value. The function returns ATVERR_INV_PARM if these
 *                      paremeters are not set to a non zero value. All other 
 *                      parameters can be set to zero if the user doesn't want 
 *                      to specify them.
 *                              - TotalSamplesLine
 *                              - TotalLinesFrameCh1
 *                              - TotalXtalsLineCh1
 *                       When the pointer is not a NULL pointer, PRIM_MODE
 *                       and VID_STD registers are set to auto graphic mode
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_INV_PARM = Invalid input parameter
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxConfigAutoGrMode(RX_AUTO_GR_PARM *AutoGrParm)
{
    if(AutoGrParm == NULL)
    {
        ADIAPI_RxDisableManPllDiv();
        VRX_set_INTERLACED(1);
        VRX_set_CH1_FR_LL(0);
        VRX_set_CH2_FR_LL(0);
        VRX_set_CP_LCOUNT_MAX(0);
        VRX_set_CH2_FR_FIELD_LENGTH(0);
        VRX_set_AV_POS_SEL(1);
        VRX_set_CP_START_SAV(0);
        VRX_set_CP_START_EAV(0);
        VRX_set_CP_START_VBI(0);
        VRX_set_CP_END_VBI(0);
        VRX_set_CP_START_VBI_EVEN(0);
        VRX_set_CP_END_VBI_EVEN(0);
        VRX_set_IGNR_CLMP_VS_MAR_START(4);
        VRX_set_IGNR_CLMP_VS_MAR_END(4);    
        return (ATVERR_OK);
    }
    if(AutoGrParm->TotalSamplesLine == 0)
    {
        return (ATVERR_INV_PARM);
    }
    if(AutoGrParm->TotalLinesFrameCh1 == 0)
    {
        return (ATVERR_INV_PARM);
    }
    if(AutoGrParm->TotalXtalsLineCh1 == 0)
    {
        return (ATVERR_INV_PARM);
    }
    ADIAPI_RxSetPrimModVidStd(PRIM_MODE_AUTO_GR, VID_STD_AUTO_GR);
    if(ADIAPI_RxEnManPllDiv(AutoGrParm->TotalSamplesLine) != ATVERR_OK)
    {
        return (ATVERR_INV_PARM);
    }
    VRX_set_INTERLACED((UINT8)((AutoGrParm->Interlaced) & 1));
    VRX_set_CH1_FR_LL(AutoGrParm->TotalLinesFrameCh1);
    VRX_set_CH2_FR_LL(AutoGrParm->TotalLinesFrameCh2);
    VRX_set_CP_LCOUNT_MAX(AutoGrParm->TotalXtalsLineCh1);
    VRX_set_CH2_FR_FIELD_LENGTH(AutoGrParm->TotalXtalsLineCh2);
    if(AutoGrParm->SyncPosSel == RX_AUTO_SYNC_POS)
    {   
        return (ATVERR_OK);
    }
    else if((AutoGrParm->SyncPosSel == RX_SEMI_AUTO_SYNC_POS) 
             || (AutoGrParm->SyncPosSel == RX_MAN_SYNC_POS))
    {
        VRX_set_DE_H_START(AutoGrParm->PixelsDeHStart);
        VRX_set_DE_H_END(AutoGrParm->PixelsDeHEnd);
        VRX_set_DE_V_START(AutoGrParm->PixelsDeVStart);
        VRX_set_DE_V_END(AutoGrParm->PixelsDeVEnd);
        
        VRX_set_CP_START_VBI(AutoGrParm->LinesStartVbi);
        VRX_set_CP_END_VBI(AutoGrParm->LinesEndVbi);
        VRX_set_CP_START_VBI_EVEN(AutoGrParm->LinesStartVbiEvenF);
        VRX_set_CP_END_VBI_EVEN(AutoGrParm->LinesEndVbiEvenF);
        
        /*VRX_set_IGNR_CLMP_VS_MAR_START(AutoGrParm->PixelsVsStartClamp);
        VRX_set_IGNR_CLMP_VS_MAR_END(AutoGrParm->PixelsVsEndClamp); */       
    }
    else
    {
        return (ATVERR_INV_PARM);
    }
    return (ATVERR_OK);
}

#endif
#endif


#if (RX_DEVICE == 7622) || (RX_DEVICE == 7623) || (RX_DEVICE == 76221)
/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7623 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxConfigAutoGrMode(RX_AUTO_GR_PARM *AutoGrParm)
{
   return(ATVERR_NOT_AVAILABLE); 
}

#endif
