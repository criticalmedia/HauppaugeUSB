/**********************************************************************************************
*																						      *
* Copyright (c) 2012 Analog Devices, Inc.  All Rights Reserved.                               *
* This software is proprietary and confidential to Analog Devices, Inc. and its licensors.    *
*                                                                                             *
***********************************************************************************************/

/*============================================================================
 * This file contains all functions that are chip-specific
 *
 *===========================================================================*/
#include "rx_lib.h"

#if ((RX_DEVICE == 7840) || (RX_DEVICE == 7844) || (RX_DEVICE == 7842)\
    || (RX_DEVICE == 7850))

#include "rx_isr.h"

/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR HAL_CfgSdpAutoFormatDetect(RX_SDP_FORMAT SDPFormat, BOOL Enable)
{
    switch (SDPFormat)
    {
        case RX_SECAM:
            VRX_set_SDP_AD_SECAM_EN(Enable);
            return (ATVERR_OK);
        case RX_PAL:
            VRX_set_SDP_AD_PAL_EN(Enable);
            return (ATVERR_OK);
        case RX_NTSC:
            VRX_set_SDP_AD_NTSC_EN(Enable);
            return (ATVERR_OK);
        case RX_PALNC:
            VRX_set_SDP_AD_PALCN_EN(Enable);
            return (ATVERR_OK);
        case RX_PALM:
            VRX_set_SDP_AD_PALM_EN(Enable);
            return (ATVERR_OK);
        case RX_PAL60:
            VRX_set_SDP_AD_PAL60_EN(Enable);
            return (ATVERR_OK);
        case RX_N443:
            VRX_set_SDP_AD_N443_EN(Enable);
            return (ATVERR_OK);
        case RX_ALL_SDP_FORMATS:
            VRX_set_SDP_AD_SECAM_EN(Enable);
            VRX_set_SDP_AD_PAL_EN(Enable);
            VRX_set_SDP_AD_NTSC_EN(Enable);
            VRX_set_SDP_AD_PALCN_EN(Enable);
            VRX_set_SDP_AD_PALM_EN(Enable);
            VRX_set_SDP_AD_PAL60_EN(Enable);
            VRX_set_SDP_AD_N443_EN(Enable);
            return (ATVERR_OK);
        default:
            return (ATVERR_INV_PARM);
    }
}

/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR HAL_CfgSdpFormatPedestalStatus(RX_SDP_FORMAT SDPFormat, BOOL PedestalPresent)
{
    switch (SDPFormat)
    {
        case RX_SECAM:
            VRX_set_SDP_SECAM_PED_EN(PedestalPresent);
            return (ATVERR_OK);
        case RX_PAL:
            VRX_set_SDP_PAL_PED_EN(PedestalPresent);
            return (ATVERR_OK);
        case RX_NTSC:
            VRX_set_SDP_NTSC_PED_EN(PedestalPresent);
            return (ATVERR_OK);
        case RX_PALNC:
            VRX_set_SDP_PALCN_PED_EN(PedestalPresent);
            return (ATVERR_OK);
        case RX_PALM:
            VRX_set_SDP_PALM_PED_EN(PedestalPresent);
            return (ATVERR_OK);
        case RX_PAL60:
            VRX_set_SDP_PAL60_PED_EN(PedestalPresent);
            return (ATVERR_OK);
        case RX_N443:
            VRX_set_SDP_N443_PED_EN(PedestalPresent);
            return (ATVERR_OK);
        case RX_ALL_SDP_FORMATS:
            VRX_set_SDP_SECAM_PED_EN(PedestalPresent);
            VRX_set_SDP_PAL_PED_EN(PedestalPresent);
            VRX_set_SDP_NTSC_PED_EN(PedestalPresent);
            VRX_set_SDP_PALCN_PED_EN(PedestalPresent);
            VRX_set_SDP_PALM_PED_EN(PedestalPresent);
            VRX_set_SDP_PAL60_PED_EN(PedestalPresent);
            VRX_set_SDP_N443_PED_EN(PedestalPresent);
            return (ATVERR_OK);
        default:
             return (ATVERR_INV_PARM);  
    }
    
}

/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR HAL_SDPGetAutoFormatDetectResult(RX_SDP_FORMAT* SDPFormat)
{
    UINT16 value;

    VRX_get_SDP_STD(&value);
    switch (value)
    {
        case 0x0:
            *SDPFormat = RX_NTSC;
            return (ATVERR_OK);
        case 0x2:
            *SDPFormat = RX_N443;
            return (ATVERR_OK);
        case 0x4:
            *SDPFormat = RX_PALM;
            return (ATVERR_OK);
        case 0x6:
            *SDPFormat = RX_PAL60;
            return (ATVERR_OK);
        case 0xC:
            *SDPFormat = RX_PALNC;
            return (ATVERR_OK);
        case 0xE:
            *SDPFormat = RX_PAL; 
            return (ATVERR_OK);
        case 0xF:
            *SDPFormat = RX_SECAM;
            return (ATVERR_OK);
        default:
            return (ATVERR_FAILED);
    }
}

/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR HAL_SDPGetVideoDetectStatus(BOOL* SDPVideoDetectedStatus)
{
    VRX_get_SDP_VIDEO_DETECTED(SDPVideoDetectedStatus);
    return (ATVERR_OK); 
}

/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR HAL_SDPGetBurstLockedStatus(BOOL* SDPBurstLockedStatus)
{
    VRX_get_SDP_BURST_LOCKED_RB(SDPBurstLockedStatus);
    return (ATVERR_OK);
}

/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR HAL_GetSdpAutoFormatDetectResult(RX_SDP_FORMAT* SDPFormat)
{
    UINT8 value;

    VRX_get_SDP_STD(&value);
    switch (value)
    {
        case 0:
             *SDPFormat = RX_NTSC;
             return (ATVERR_OK);  
        case 2:
             *SDPFormat = RX_N443;
             return (ATVERR_OK);
        case 4:
             *SDPFormat = RX_PALM;
             return (ATVERR_OK);
        case 6:
             *SDPFormat = RX_PAL60;
             return (ATVERR_OK);
        case 12:
             *SDPFormat = RX_PALNC;
             return (ATVERR_OK);
        case 13:
             *SDPFormat = RX_SECAM;
             return (ATVERR_OK);
        case 14:
             *SDPFormat = RX_PAL;
             return (ATVERR_OK);
        case 15:
             *SDPFormat = RX_SECAM;
             return (ATVERR_OK);
        default:
             *SDPFormat = RX_UNDEF_SDP_FORMAT;
             return (ATVERR_FAILED);
      }
}

/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR HAL_GetSdpVideoDetectStatus(BOOL* SdpVideoDetectStatus)
{
    VRX_get_SDP_VIDEO_DETECTED(SdpVideoDetectStatus);
    return (ATVERR_OK); 
}

/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR HAL_GetSdpBurstLockedStatus(BOOL* SdpBurstLockedStatus)
{
    VRX_get_SDP_BURST_LOCKED_RB(SdpBurstLockedStatus);
    return (ATVERR_OK);
}

/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR HAL_GetSdpFieldRateStatus(RX_SDP_FIELD_RATE* FieldRate)
{
    ATV_ERR ErrVal = ATVERR_OK;
    UINT8 tp_fieldrate;

    VRX_get_SDP_AD_50_60_HZ(&tp_fieldrate);
    switch(tp_fieldrate)
    {
        case 0:
            *FieldRate = RX_60HZ;
            break;
        case 1:
            *FieldRate = RX_50HZ;
            break;
        default:
            ErrVal =ATVERR_FAILED;
            break;
    }
    return (ErrVal);
}

/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR HAL_GetSdpStatus(RX_SDP_STATUS* SdpStatus)
{
    
    SdpStatus->VideoDetect = VRX_is_SDP_VIDEO_DETECTED_true();
    SdpStatus->FreeRun = VRX_is_SDP_FREE_RUN_true();
    SdpStatus->AllowSlowPll = VRX_is_SDP_ALLOW_SLOW_PLL_true();
    SdpStatus->AllowMedPll = VRX_is_SDP_ALLOW_MED_PLL_true();
    SdpStatus->LcNstd = VRX_is_SDP_LC_NSTD_true();
    SdpStatus->FrmNstd =VRX_is_SDP_FRM_NSTD_true();
    SdpStatus->FldNstd =VRX_is_SDP_FLD_NSTD_true();
    SdpStatus->BlkNstd =VRX_is_SDP_BLK_NSTD_true();
    SdpStatus->HswitchPresent=VRX_is_SDP_HSWITCH_PRESENT_true();
    SdpStatus->ScmLocked = VRX_is_SDP_SCM_LOCKED_true();
    SdpStatus->FscFreqOk= VRX_is_SDP_FSC_FREQ_OK_true();
    SdpStatus->PalSwLocked = VRX_is_SDP_PAL_SW_LOCKED_true();
    SdpStatus->Ad50_60Hz=VRX_is_SDP_AD_50_60_HZ_true();
    SdpStatus->BurstLocked=VRX_is_SDP_BURST_LOCKED_RB_true();
    return (ATVERR_OK);
}

/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR HAL_GetSdpMcvsStatus(RX_MCVS_STATUS* McvsStatus)
{
    McvsStatus->CsDetected = VRX_is_SDP_MVCS_DETECT_true();
    if (VRX_is_SDP_MVCS_TYPE3_true())
    {
        McvsStatus->CsType3 = TRUE;
        McvsStatus->CsType2 = FALSE;
    }
    else
    {
        McvsStatus->CsType3 = FALSE;
        McvsStatus->CsType2 = TRUE;
    }
    McvsStatus->PsDetected = VRX_is_SDP_MV_PS_DETECTED_true();
    McvsStatus->AgcDetected = VRX_is_SDP_MV_AGC_DETECTED_true();
    /*VRX_get_SDP_BP_TOTAL_PULSES_END(&(McvsStatus->TotalBpPulsesEnd));*/
    /*VRX_get_SDP_BP_TOTAL_PULSE_BEG(&(McvsStatus->TotalBpPulsesBeg));*/
    
    return (ATVERR_OK);
}

/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR HAL_SetSdpSaturation(UINT16 Saturation)
{
    if(Saturation> 0x3FF)
    {
        return (ATVERR_INV_PARM);
    }
    VRX_set_SDP_SATURATION(Saturation);
    return (ATVERR_OK);
}

/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR HAL_SetSdpBrightness(UINT16 Brightness)
{
    if (Brightness> 0x3FF)
    {
        return (ATVERR_INV_PARM);
    }
    VRX_set_SDP_BRIGHTNESS(Brightness);
    return (ATVERR_OK);
}

/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR HAL_SetSdpHue(UINT16 Hue)
{
    if(Hue> 0x3FF)
    {
        return (ATVERR_INV_PARM);
    }
    VRX_set_SDP_HUE(Hue);
    return (ATVERR_OK);
}

/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR HAL_SetSdpLumaGainMode(RX_GAIN_MODE LumaGainMode)
{
    switch (LumaGainMode)
    {
        case RX_GAIN_AGC:
            VRX_set_SDP_Y_AGC_EN(0x01);
            return (ATVERR_OK);
        case RX_GAIN_MAN:
            VRX_set_SDP_Y_AGC_EN(0x00);
            return (ATVERR_OK);
        case RX_GAIN_AUTO:
        default:
            return (ATVERR_INV_PARM);
    }
}

/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR HAL_SetSdpManLumaGain(UINT16 LumaGain)
{
    if (LumaGain> 0x1FFF)
    {
        return (ATVERR_INV_PARM);
    }
    VRX_set_SDP_Y_GAIN_MAN(LumaGain&0x1FFF);
    return (ATVERR_OK);
}

/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR HAL_GetSdpLumaGain(UINT16* LumaGainRB)
{
    *LumaGainRB = VRX_ret_SDP_Y_GAIN_MAN_RB();
    return (ATVERR_OK);
}

/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR HAL_SetSdpChromaGainMode(RX_GAIN_MODE ChromaGainMode)
{
    switch (ChromaGainMode)
    {
        case RX_GAIN_AGC:
            VRX_set_SDP_C_AGC_EN(0x01);
            return (ATVERR_OK);
        case RX_GAIN_MAN:
            VRX_set_SDP_C_AGC_EN(0x00);
            return (ATVERR_OK);
        default:
            return (ATVERR_INV_PARM);
    }
}

/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR HAL_SetSdpManChromaGain(UINT16 ChromaGain)
{
    if (ChromaGain> 0x1FFF)
    {
        return (ATVERR_INV_PARM);
    }
    VRX_set_SDP_C_GAIN_ACT_MAN(ChromaGain);
    return (ATVERR_OK);
}


/*============================================================================
 *
 * Entry:   None
 *  
 * Return:  void
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR HAL_SdpCfgColorKill(BOOL Enable, UINT8 HighThres, UINT8 LowThres)
{
    VRX_set_SDP_CKILL_EN(Enable);
    if(Enable)
    {
        VRX_set_SDP_CK_HIGH_THR(HighThres);
        VRX_set_SDP_CK_LOW_THR(LowThres);
    }
    return (ATVERR_OK);
    
}

/*============================================================================
 *
 * Entry:   None
 *  
 * Return:  void
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR HAL_SdpForceFreeRun (BOOL Enable)
{
    Enable &= 1;
    VRX_set_SDP_FORCE_FREE_RUN(Enable);
    return (ATVERR_OK);
}


/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR HAL_SetSdpClampSpeed(RX_CLAMP Clamp, UINT8 Speed)
{
    ATV_ERR RetVal = ATVERR_OK;
    switch (Clamp)
    {
        case RX_DIGITAL_CLAMP:
            if (Speed>6)
            {
                RetVal = ATVERR_INV_PARM;
            }
            else
            {
                VRX_set_SDP_DCLP_SPEED(Speed);
            }
            break;
        case RX_ANALOG_CLAMP:
            if(Speed>6)
            {
                RetVal = ATVERR_INV_PARM;
            }
            else
            {
                VRX_set_SDP_ACLP_SPEED(Speed);
            }
            break;
        default:
            RetVal = ATVERR_INV_PARM;
            break;
    }
    return (RetVal);
}

/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR HAL_EnSdp3dComb(BOOL Enable)
{
    VRX_set_SDP_3D_COMB_EN(Enable);
    return (ATVERR_OK);
}
#if(RX_DEVICE != 7850)
/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR HAL_EnSdpItoP(BOOL Enable )
{
    VRX_set_SDP_SHIP_EN(Enable);
    return (ATVERR_OK);
}

/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  ATVERR_OK
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR HAL_SetSdpItoPMode(RX_ItoP_MODE ItoPMode)
{
    ATV_ERR RetVal = ATVERR_OK;

    switch (ItoPMode)
    {
        case RX_LINE_DOUBLING:
            VRX_set_SDP_SHIP_INT_EN(0);
            break;
        case RX_LINE_INTERPOLATION:
            VRX_set_SDP_SHIP_INT_EN(1);
            break;
        default:
            RetVal = ATVERR_INV_PARM;
            break;
    }
    return (RetVal);
}
#endif
#endif
