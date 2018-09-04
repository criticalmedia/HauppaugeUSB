/**********************************************************************************************
*																						      *
* Copyright (c) 2012 Analog Devices, Inc.  All Rights Reserved.                               *
* This software is proprietary and confidential to Analog Devices, Inc. and its licensors.    *
*                                                                                             *
***********************************************************************************************/

#include "rx_lib.h"

#if ((RX_DEVICE == 7604) || (RX_DEVICE == 7614) || (RX_DEVICE == 7840) || (RX_DEVICE == 7844)||(RX_DEVICE == 7842) ||(RX_DEVICE == 7850))


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
ATV_ERR  ADIAPI_RxAfeAinAutoMuxModeSel(UINT8 AinMode)
{
    return (HAL_SetAinAutoMuxModeSel(AinMode)); 
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
ATV_ERR  ADIAPI_RxAfeSdpEnManAinMux(BOOL Enable)
{
    return (HAL_SetSdpEnManAinMux(Enable));
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
ATV_ERR  ADIAPI_RxAfeManAinMux(RX_ADC ADC, RX_AIN_CH AinChannel)
{
    return (HAL_SetManAinMux(ADC, AinChannel));
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
ATV_ERR  ADIAPI_RxAfeConfigTriLevelSlicer(RX_TRI_SLICER TriSlicer, RX_TRI_SLICER_MODE SliceMode, RX_TRI_SLICE_LEVEL* SliceLevels )
{
    return (HAL_ConfigTriLevelSlicer(TriSlicer, SliceMode, SliceLevels));
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
ATV_ERR  ADIAPI_RxAfeEnTriLevelSlicer(RX_TRI_SLICER TriSlicer,BOOL PowerUp)
{
    return (HAL_SetTriLevelSlicerEn(TriSlicer, PowerUp));
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
ATV_ERR  ADIAPI_RxAfeGetTriLevelSlicerStatus(RX_TRI_SLICER TriSlicer, RX_TRI_SLICER_STATUS* TriStatus)
{
    return (HAL_GetTriLevelSlicerStatus(TriSlicer, TriStatus));
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
ATV_ERR  ADIAPI_RxAfeEnAntiAliasFilt(RX_ADC ADC, BOOL Enable)
{
    return (HAL_SetAntiAliasFiltEn(ADC, Enable));
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
ATV_ERR  ADIAPI_RxAfeSelAntiAliasFilt(RX_AA_FILT_RESPONSE FiltResponse)
{
    return (HAL_SelAntiAliasFilt(FiltResponse));
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
ATV_ERR ADIAPI_RxAfeEnExtBiasing(BOOL Enable)
{
    return (HAL_EnExtBiasing(Enable));
}

/*==========================================================================
 *
 * Configure the event RX_EVENT_AFE_SLICER
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
ATV_ERR ADIAPI_RxAfeCfgAfeSlicerEvent(RX_TRI_SLICER Slicer, RX_TRI_SLICER_LEVEL EnableLvl)
{
    return (HAL_RxAfeCfgAfeSlicerEvent(Slicer, EnableLvl));
}



/*============================================================================
 * Control to enable the Voltage Clamps on the Analog Inputs.
 *
 * Entry:   Enable - TRUE to enable the voltage clamps
 *                 - FALSE to disable the voltagae clamps
 *          
 *                 
 *  
 * Return:  ATVERR_OK = Function completed successfully
 *  
 * Notes:   
 *
 *===========================================================================*/
ATV_ERR  ADIAPI_RxAfeEnVoltageClamps(BOOL Enable)
{
    if(Enable)
    {
        VRX_set_VOLTAGE_CLAMP_EN(0x1);
    }
    else
    {
        VRX_set_VOLTAGE_CLAMP_EN(0x0);
    }
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
ATV_ERR  ADIAPI_RxAfeEnManAinMux(BOOL Enable)
{
    VRX_set_ADC_SWITCH_MAN(Enable);
    return (ATVERR_OK);
}
/*============================================================================
 * Control to enable the Current Clamps on the Analog Inputs.
 *
 * Entry:   Enable - TRUE to enable the current clamps
 *                 - FALSE to disable the current clamps               
 *  
 * Return:  ATVERR_OK = Function completed successfully
 *  
 * Notes:   
 *
 *===========================================================================*/
ATV_ERR  ADIAPI_RxAfeEnCurrentClamps(BOOL Enable)
{
    if(Enable)
    {
        VRX_set_CURRENT_CLAMP_EN(0x1);
    }
    else
    {
        VRX_set_CURRENT_CLAMP_EN(0x0);
    }
    return (ATVERR_OK);
}
/*============================================================================
 * To select the slice level of the Synchronization Slicers
 *
 * Entry:   SyncSlicer -RX_ALL_SYNC_SLICERS  All Synchronization Slicers
 * 
 *          SliceLevel -Slice level for Synchronization Slicers. Valid range of 
 *                      0x0 to 0x1F. 
 *                 
 *  
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_INV_PARM = SliceLevel Value out of range or Invalid SyncSlicer
 *                            selected.
 * Notes:   Refer to Hardware Manual for more details.
 *
 *===========================================================================*/
ATV_ERR  ADIAPI_RxAfeSetSyncSliceLevel(RX_SYNC_SLICER SyncSlicer, UINT8 SliceLevel)
{
    ATV_ERR ErrVal = ATVERR_OK;
    
    switch(SyncSlicer)
    {
        case RX_ALL_SYNC_SLICERS:
            if(SliceLevel > 31)
            {
                VRX_set_SLICE_LEVEL(SliceLevel);
            }
            else
            {
                ErrVal=  ATVERR_INV_PARM;
            }
            break;
        default:
            ErrVal=  ATVERR_INV_PARM;   
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
ATV_ERR  ADIAPI_RxAfeSetSyncSlicerFilt(RX_SYNC_SLICER SyncSlicer, RX_SYNC_SLICER_FILTER SyncFilter)
{
    ATV_ERR ErrVal = ATVERR_OK;
    UINT8 TmpSyncFilt=0;
    
    switch (SyncFilter)
    {
        case RX_NO_SFILT:
            break;
        case RX_SFILT_GR250NS:
            TmpSyncFilt= 1;
            break;
        case RX_SFILT_GR1000NS:
            TmpSyncFilt= 2;
            break;
        case RX_SFILT_GR2500NS:
            TmpSyncFilt= 3;
            break;
        default:
            ErrVal=  ATVERR_INV_PARM;   
            break;
    }

    switch (SyncSlicer)
    {
        case RX_ALL_SYNC_SLICERS:
            VRX_set_SYNC1_FILTER_SEL(TmpSyncFilt);
            VRX_set_SYNC2_FILTER_SEL(TmpSyncFilt);
            break;
        case RX_SYNC_SLICER1:
            VRX_set_SYNC1_FILTER_SEL(TmpSyncFilt);
            break;
        case RX_SYNC_SLICER2:
            VRX_set_SYNC2_FILTER_SEL(TmpSyncFilt);
            break;
        default:
            ErrVal=  ATVERR_INV_PARM;   
            break;      
    }   
    return (ErrVal);
}
/*============================================================================
 * Apply Manual(user)configuration of the PLL Divider Ratio .
 *
 * Entry:   PllDivRatio User setting for PLL Divider ration
 *  
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_INV_PARM = Pll Divider Ration setting provided out of range
 * 
 * Notes:   This function both sets the manual Divider Ration and enables it.
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxEnManPllDiv (UINT16 PllDivRatio)
{
    UINT8 tp_PllDiv[2];
    UINT8 tp_PllMap;
    
#if( RX_DEVICE ==7850)
         tp_PllMap = VRX_VFE_MAP_ADDR;
#else
        tp_PllMap = VRX_IO_MAP_ADDR;
#endif

    if (PllDivRatio > 8191)
    {
        return (ATVERR_INV_PARM);
    }

    HAL_I2CReadBlock(tp_PllMap, 0x16, tp_PllDiv, 1);
    tp_PllDiv[0] = ((tp_PllDiv[0] & 0x40)|((PllDivRatio >>8)| 0x80));
    tp_PllDiv[1] = (PllDivRatio & 0xFF);
    HAL_I2CWriteBlock(tp_PllMap, 0x16, tp_PllDiv, 2);

    return (ATVERR_OK);
    
    
}

/*============================================================================
 * Disables Manual(user)configuration of the PLL Divider Ratio .
 *
 * Entry:   None
 *  
 * Return:  ATVERR_OK = Function completed successfully
 *          
 * 
 * Notes:   Refer to ADIAPI_RxEnManPllDiv
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxDisableManPllDiv (void)
{
    VRX_set_PLL_DIV_MAN_EN(0x0);
    return (ATVERR_OK);
}
/*==========================================================================
 * To enable the ADC and HDMI simultaneous mode.
 *
 * Entry:   Enable: Set the enable status for ADC and HDMI simultaneous Mode.
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxEnHdmiSimultMode (BOOL Enable)
{
    VRX_set_ADC_HDMI_SIMULT_MODE(Enable);
    return (ATVERR_OK);
}
/*==========================================================================
 * To configure the Video Loopback Mux
 *
 * Entry:   VidOutChannel  Video Output channel to which video is to be routed
 *                      AinChannel         Video source which is to be looped back to VidOutChannel
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxAfeSetVideoOutMux (RX_VOUT_CH VidOutChannel, RX_AIN_CH AinChannel)
{
        
        return (HAL_RxAfeSetVideoOutMux(VidOutChannel, AinChannel));
        
}
#endif
