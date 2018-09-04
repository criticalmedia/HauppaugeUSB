/**********************************************************************************************
*																						      *
* Copyright (c) 2012 Analog Devices, Inc.  All Rights Reserved.                               *
* This software is proprietary and confidential to Analog Devices, Inc. and its licensors.    *
*                                                                                             *
***********************************************************************************************/

#include "rx_lib.h"

#if ((RX_DEVICE == 7604) || (RX_DEVICE == 7614) || (RX_DEVICE == 7840)\
    || (RX_DEVICE == 7844) || (RX_DEVICE == 7842)  || (RX_DEVICE == 7850)\
    || (RX_DEVICE == 7180))

#include "rx_cfg.h"

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
ATV_ERR  ADIAPI_RxSdpCfgAutoFormatDetect(RX_SDP_FORMAT SdpFormat, BOOL Enable)
{
    return (HAL_CfgSdpAutoFormatDetect(SdpFormat, Enable));
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
ATV_ERR  ADIAPI_RxSdpCfgFrmtPedStatus(RX_SDP_FORMAT SdpFormat, BOOL PedestalPresent)
{
    return (HAL_CfgSdpFormatPedestalStatus(SdpFormat, PedestalPresent));
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
ATV_ERR  ADIAPI_RxSdpEnableSFL(BOOL Enable)
{
    return (HAL_EnSdpSFL(Enable));
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
ATV_ERR  ADIAPI_RxSdpGetAutoFormatDetectResult(RX_SDP_FORMAT* SdpFormat)
{
    return (HAL_GetSdpAutoFormatDetectResult( SdpFormat));
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
ATV_ERR  ADIAPI_RxSdpGetVideoDetectStatus(BOOL* SdpVideoDetectStatus)
{
    return (HAL_GetSdpVideoDetectStatus(SdpVideoDetectStatus));
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
ATV_ERR  ADIAPI_RxSdpGetBurstLockedStatus(BOOL* BurstLockedStatus)
{
    return (HAL_GetSdpBurstLockedStatus(BurstLockedStatus));
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
ATV_ERR  ADIAPI_RxSdpGetFieldRateStatus(RX_SDP_FIELD_RATE* SdpFieldRate)
{
    return (HAL_GetSdpFieldRateStatus(SdpFieldRate));
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
ATV_ERR  ADIAPI_RxSdpGetStatus(RX_SDP_STATUS* SdpStatus)
{
    return (HAL_GetSdpStatus(SdpStatus));
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
ATV_ERR  ADIAPI_RxSdpGetMacrovisionStatus(RX_MCVS_STATUS* McvsStatus)
{
    return (HAL_GetSdpMcvsStatus(McvsStatus));
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
ATV_ERR  ADIAPI_RxSdpSetSaturation(UINT16 SdpSaturation)
{
    return (HAL_SetSdpSaturation(SdpSaturation));
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
ATV_ERR  ADIAPI_RxSdpSetBrightness(UINT16 SdpBrightness)
{
    return (HAL_SetSdpBrightness(SdpBrightness));
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
ATV_ERR  ADIAPI_RxSdpSetHue(UINT16 SdpHue)
{
    return (HAL_SetSdpHue(SdpHue));
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
ATV_ERR  ADIAPI_RxSdpSetLumaGainMode(RX_GAIN_MODE SdpLumaGainMode)
{
    return (HAL_SetSdpLumaGainMode(SdpLumaGainMode));
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
ATV_ERR  ADIAPI_RxSdpSetManLumaGain(UINT16 SdpLumaGain)
{
    return (HAL_SetSdpManLumaGain(SdpLumaGain));
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
ATV_ERR  ADIAPI_RxSdpGetLumaGain(UINT16* SdpLumaGainRb)
{
    return (HAL_GetSdpLumaGain(SdpLumaGainRb));
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
ATV_ERR  ADIAPI_RxSdpSetChromaGainMode(RX_GAIN_MODE SdpChromaGainMode)
{
    return (HAL_SetSdpChromaGainMode( SdpChromaGainMode));
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
ATV_ERR  ADIAPI_RxSdpSetChromaManGain(UINT16 SdpChromaGain)
{
    return (HAL_SetSdpManChromaGain(SdpChromaGain));
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
ATV_ERR  ADIAPI_RxSdpEn3dComb(BOOL Enable)
{
    return (HAL_EnSdp3dComb(Enable));
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
ATV_ERR  ADIAPI_RxSdpEn3dDnr(BOOL Enable)
{
    return (HAL_EnSdp3dDnr(Enable));
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
ATV_ERR  ADIAPI_RxSdpEnFrameTbc(BOOL Enable)
{
    return (HAL_EnSdpFrameTbc(Enable));
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
ATV_ERR  ADIAPI_RxSdpInitMemInterface(RX_SDP_MEM MemType)
{
    return (HAL_InitSdpMemInterface(MemType));
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
ATV_ERR  ADIAPI_RxSdpSetItoPMode(RX_ItoP_MODE ItoPMode)
{
    return (HAL_SetSdpItoPMode(ItoPMode));
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
ATV_ERR  ADIAPI_RxSdpEnItoP(BOOL Enable )
{
    return (HAL_EnSdpItoP(Enable ));
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
ATV_ERR  ADIAPI_RxSdpSetSdpClampSpeed(RX_CLAMP Clamp, UINT8 Speed)
{
    return (HAL_SetSdpClampSpeed(Clamp, Speed));
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
ATV_ERR ADIAPI_RxSdpForceFreeRun (BOOL Enable)
{
    return (HAL_SdpForceFreeRun (Enable));
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
ATV_ERR ADIAPI_RxSdpCfgColorKill(BOOL Enable, UINT8 HighThres, UINT8 LowThres)
{
    return (HAL_SdpCfgColorKill(Enable, HighThres, LowThres));
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
ATV_ERR ADIAPI_RxSdpSetPixClkFreq (RX_PIX_CLK_FREQ PixClkFreq, BOOL Enable)
{
    return ( HAL_SetSdpPixelClkFreq(PixClkFreq,Enable) );
}
/*==========================================================================
 *  Configure the SDP Primary Mode and SDP Video Standard for chips where 
 *  the SDP core is under seperate control. 
 *
 * Entry:   PrimaryMode: Sets the primary mode of operation of the Video Reciever
 *          VideoStandard: Set the Video Standard that is expected to be 
 *                         applied to the Video Reciever 
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxSdpSetVidStd (UINT8 VideoStandard)
{
    return (HAL_SetSdpVidStd(VideoStandard));
}
#endif
