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

#if ((RX_DEVICE == 7604) || (RX_DEVICE == 7614) || (RX_DEVICE == 7844) || (RX_DEVICE == 7842) || (RX_DEVICE == 7850))

#include "rx_isr.h"

CONSTANT UCHAR AfeCfgTable [] =
{
    /* Slicer,  Reg Addr,   Mask,   LsbPos*/
    (UCHAR)RX_TRI_SLICER1,  17, 0xC0,   6,
    (UCHAR)RX_TRI_SLICER2,  17, 0x30,   4,
    (UCHAR)RX_TRI_SLICER3,  17, 0x0C,   2,
    (UCHAR)RX_TRI_SLICER4,  17, 0x03,   0,
    (UCHAR)RX_TRI_SLICER5,  18, 0xC0,   6,
    (UCHAR)RX_TRI_SLICER6,  18, 0x30,   4,
    (UCHAR)RX_TRI_SLICER7,  18, 0x0C,   2,
    (UCHAR)RX_TRI_SLICER8,  18, 0x03,   0,
    0xff
};

CONSTANT UCHAR AntiAliasFiltCfg[] =
{
    /*FilterResponse, AA_FILT_HIGH_BW, AA_FILT_PROG_BW*/
    RX_AAF_FC_10MHZ,    0,      0,
    RX_AAF_FC_12MHZ,    0,      1,
    RX_AAF_FC_14MHZ,    0,      2,
    RX_AAF_FC_15MHZ,    0,      3,
    RX_AAF_FC_27MHZ,    1,      0,
    RX_AAF_FC_32MHZ,    1,      1,
    RX_AAF_FC_36MHZ,    1,      2,
    RX_AAF_FC_40MHZ,    1,      3,
    RX_AAF_FC_58MHZ,    2,      0,
    RX_AAF_FC_68MHZ,    2,      1,
    RX_AAF_FC_79MHZ,    2,      2,
    RX_AAF_FC_91MHZ,    2,      3,
    RX_AAF_FC_95MHZ,    3,      0,
    RX_AAF_FC_109MHZ,   3,      1,
    RX_AAF_FC_126MHZ,   3,      2,
    RX_AAF_FC_145MHZ,   3,      3,
    0xff
};

CONSTANT UCHAR HsyncChCfg[] =
{
    RX_HS_AUTO,     0,  0xff,
    RX_HS_IN1,      1,  1,
    RX_HS_IN2,      2,  0,
    RX_HS_HDMI,     3,  3,
    0xff
};

CONSTANT UCHAR VsyncChCfg[] =
{
    RX_VS_AUTO,     0,  0xff,
    RX_VS_IN1,      1,  1,
    RX_VS_IN2,      2,  0,
    RX_VS_HDMI,     3,  3,
    0xff
};

CONSTANT UCHAR EmbSyncChCfg[] =
{
    RX_SYNC_AUTO,   0,  0,      0xff,   0xff,   0xff,   0xff,
    RX_SYNC_1,      1,  1,      0,      0,      1,      0,
    RX_SYNC_2,      1,  1,      1,      0,      1,      1,
    RX_SYNC_3,      1,  1,      2,      0,      1,      2,
    RX_SYNC_4,      1,  1,      3,      0,      1,      3,
    RX_SYNC_LO,     3,  0xff,   0xff,   3,      0xff,   0xff,
    0xff
};

/*============================================================================
 *
 * Entry:   
 *  
 * Return:  ATVERR_OK
 *          ATVERR_INV_PARM
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR HAL_RxAfeCfgAfeSlicerEvent(RX_TRI_SLICER Slicer, RX_TRI_SLICER_LEVEL EnableLvl)
{
    UCHAR i;
    
    i = (UCHAR)(ATV_LookupValue8 ((UCHAR*)AfeCfgTable, (UCHAR)Slicer, 0xff, 4));
    if(AfeCfgTable[i+1] == 0xff)
    {
        return (ATVERR_INV_PARM);
    }
    ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, AfeCfgTable[i+1], 
                               AfeCfgTable[i+2], AfeCfgTable[i+3], 
                               (UCHAR)EnableLvl);
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
ATV_ERR HAL_ConfigTriLevelSlicer(RX_TRI_SLICER TriSlicer, RX_TRI_SLICER_MODE SliceMode, RX_TRI_SLICE_LEVEL* SliceLevels )
{
    ATV_ERR ErrVal = ATVERR_OK;
    UINT8 tp_uppLevel;
    UINT8 tp_lowLevel; 

    tp_lowLevel = *(SliceLevels);
    tp_uppLevel = *(SliceLevels+1);

    switch(TriSlicer)
    {
        case RX_TRI_SLICER1:
            switch(SliceMode)
            {
                case RX_BILEVEL:
                    VRX_set_TRI1_BILEVEL_SLICE_EN(0x0);
                    VRX_set_TRI1_LOWER_SLICE_LEVEL(tp_lowLevel); 
                    break;
                case RX_TRILEVEL:
                    VRX_set_TRI1_BILEVEL_SLICE_EN(0x1);
                    VRX_set_TRI1_LOWER_SLICE_LEVEL(tp_lowLevel);
                    VRX_set_TRI1_UPPER_SLICE_LEVEL(tp_uppLevel);
                    break;
                default:
                    ErrVal =ATVERR_INV_PARM;
                    break;
            }
            break;
        case RX_TRI_SLICER2:
            switch(SliceMode)
            {
                case RX_BILEVEL:
                    VRX_set_TRI2_BILEVEL_SLICE_EN(0x0);
                    VRX_set_TRI2_LOWER_SLICE_LEVEL(tp_lowLevel); 
                    break;
                case RX_TRILEVEL:
                    VRX_set_TRI2_BILEVEL_SLICE_EN(0x1);
                    VRX_set_TRI2_LOWER_SLICE_LEVEL(tp_lowLevel);
                    VRX_set_TRI2_UPPER_SLICE_LEVEL(tp_uppLevel);
                    break;
                default:
                    ErrVal =ATVERR_INV_PARM;
                    break;
            }
            break;
        case RX_TRI_SLICER3:
            switch(SliceMode)
            {
                case RX_BILEVEL:
                    VRX_set_TRI3_BILEVEL_SLICE_EN(0x0);
                    VRX_set_TRI3_LOWER_SLICE_LEVEL(tp_lowLevel); 
                    break;
                case RX_TRILEVEL:
                    VRX_set_TRI3_BILEVEL_SLICE_EN(0x1);
                    VRX_set_TRI3_LOWER_SLICE_LEVEL(tp_lowLevel);
                    VRX_set_TRI3_UPPER_SLICE_LEVEL(tp_uppLevel);
                    break;
                default:
                    ErrVal =ATVERR_INV_PARM;
                    break;
            }
            break;
        case RX_TRI_SLICER4:
            switch(SliceMode)
            {
                case RX_BILEVEL:
                    VRX_set_TRI4_BILEVEL_SLICE_EN(0x0);
                    VRX_set_TRI4_LOWER_SLICE_LEVEL(tp_lowLevel); 
                    break;
                case RX_TRILEVEL:
                    VRX_set_TRI4_BILEVEL_SLICE_EN(0x1);
                    VRX_set_TRI4_LOWER_SLICE_LEVEL(tp_lowLevel);
                    VRX_set_TRI4_UPPER_SLICE_LEVEL(tp_uppLevel);
                    break;
                default:
                    ErrVal =ATVERR_INV_PARM;
                    break;
            }
            break;
        case RX_TRI_SLICER5:
            switch(SliceMode)
            {
                case RX_BILEVEL:
                    VRX_set_TRI5_BILEVEL_SLICE_EN(0x0);
                    VRX_set_TRI5_LOWER_SLICE_LEVEL(tp_lowLevel); 
                    break;
                case RX_TRILEVEL:
                    VRX_set_TRI5_BILEVEL_SLICE_EN(0x1);
                    VRX_set_TRI5_LOWER_SLICE_LEVEL(tp_lowLevel);
                    VRX_set_TRI5_UPPER_SLICE_LEVEL(tp_uppLevel);
                    break;
                default:
                    ErrVal =ATVERR_INV_PARM;
                    break;
            }
            break;
        case RX_TRI_SLICER6:
            switch(SliceMode)
            {
                case RX_BILEVEL:
                    VRX_set_TRI6_BILEVEL_SLICE_EN(0x0);
                    VRX_set_TRI6_LOWER_SLICE_LEVEL(tp_lowLevel); 
                    break;
                case RX_TRILEVEL:
                    VRX_set_TRI6_BILEVEL_SLICE_EN(0x1);
                    VRX_set_TRI6_LOWER_SLICE_LEVEL(tp_lowLevel);
                    VRX_set_TRI6_UPPER_SLICE_LEVEL(tp_uppLevel);
                    break;
                default:
                    ErrVal =ATVERR_INV_PARM;
                    break;
            }
            break;
       case RX_TRI_SLICER7:
            switch(SliceMode)
            {
                case RX_BILEVEL:
                    VRX_set_TRI7_BILEVEL_SLICE_EN(0x0);
                    VRX_set_TRI7_LOWER_SLICE_LEVEL(tp_lowLevel); 
                    break;
                case RX_TRILEVEL:
                    VRX_set_TRI7_BILEVEL_SLICE_EN(0x1);
                    VRX_set_TRI7_LOWER_SLICE_LEVEL(tp_lowLevel);
                    VRX_set_TRI7_UPPER_SLICE_LEVEL(tp_uppLevel);
                    break;
                default:
                    ErrVal =ATVERR_INV_PARM;
                    break;
            }
            break;
         case RX_TRI_SLICER8:
            switch(SliceMode)
            {
                case RX_BILEVEL:
                    VRX_set_TRI8_BILEVEL_SLICE_EN(0x0);
                    VRX_set_TRI8_LOWER_SLICE_LEVEL(tp_lowLevel); 
                    break;
                case RX_TRILEVEL:
                    VRX_set_TRI8_BILEVEL_SLICE_EN(0x1);
                    VRX_set_TRI8_LOWER_SLICE_LEVEL(tp_lowLevel);
                    VRX_set_TRI8_UPPER_SLICE_LEVEL(tp_uppLevel);
                    break;
                default:
                    ErrVal =ATVERR_INV_PARM;
                    break;
            }
            break;
 
        default:
            ErrVal =ATVERR_INV_PARM;
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
ATV_ERR HAL_SetTriLevelSlicerEn(RX_TRI_SLICER TriSlicer, BOOL Enable)
{
    ATV_ERR ErrVal = ATVERR_OK;

    switch(TriSlicer)
    {
        case RX_TRI_SLICER1:
            VRX_set_TRI1_SLICER_PWRDN(!Enable);
            break;
        case RX_TRI_SLICER2:
            VRX_set_TRI2_SLICER_PWRDN(!Enable);
            break;
        case RX_TRI_SLICER3:
            VRX_set_TRI3_SLICER_PWRDN(!Enable);
            break;
        case RX_TRI_SLICER4:
            VRX_set_TRI4_SLICER_PWRDN(!Enable);
            break;
        case RX_TRI_SLICER5:
            VRX_set_TRI5_SLICER_PWRDN(!Enable);
            break;
        case RX_TRI_SLICER6:
            VRX_set_TRI6_SLICER_PWRDN(!Enable);
            break;
        case RX_TRI_SLICER7:
            VRX_set_TRI7_SLICER_PWRDN(!Enable);
            break;
        case RX_TRI_SLICER8:
            VRX_set_TRI8_SLICER_PWRDN(!Enable);
            break;
         
        default:
            ErrVal =ATVERR_INV_PARM;
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
ATV_ERR HAL_GetTriLevelSlicerStatus(RX_TRI_SLICER TriSlicer, RX_TRI_SLICER_STATUS* TriStatus)
{
    ATV_ERR ErrVal = ATVERR_OK;
    UINT16 tp_TriRb;


    switch(TriSlicer)
    {
        case RX_TRI_SLICER1:
            VRX_get_TRI1_READBACK( &tp_TriRb);
            break;
        case RX_TRI_SLICER2:
            VRX_get_TRI2_READBACK(&tp_TriRb);
            break;
        case RX_TRI_SLICER3:
            VRX_get_TRI3_READBACK(&tp_TriRb);
            break;
        case RX_TRI_SLICER4:
            VRX_get_TRI4_READBACK(&tp_TriRb);
            break;
        case RX_TRI_SLICER5:
            VRX_get_TRI5_READBACK(&tp_TriRb);
            break;
        case RX_TRI_SLICER6:
            VRX_get_TRI6_READBACK(&tp_TriRb);
            break;
        case RX_TRI_SLICER7:
            VRX_get_TRI7_READBACK(&tp_TriRb);
            break;
        case RX_TRI_SLICER8:
            VRX_get_TRI8_READBACK(&tp_TriRb);
            break;
        default:
            tp_TriRb =0x0;
            ErrVal =ATVERR_INV_PARM;
            break;
    }

    switch(tp_TriRb)
    {
        case 0x0:
            *TriStatus = RX_TRI_BELOW_LWR_LIMIT;
            break;
        case 0x1:
            *TriStatus = RX_TRI_ABOVE_LWR_LIMIT;
            break;
        case 0x2:
            *TriStatus = RX_TRI_ABOVE_UPPR_LIMIT;
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
ATV_ERR HAL_SelAntiAliasFilt(RX_AA_FILT_RESPONSE FiltResponse)
{
    UINT8 i;
    
    
    i = (UCHAR)(ATV_LookupValue8 ((UCHAR*)AntiAliasFiltCfg, 
                                        (UCHAR)FiltResponse, 0xff, 3));
    if(AntiAliasFiltCfg[i] == 0xff)
    {
        return (ATVERR_INV_PARM);
    }
    VRX_set_AA_FILT_HIGH_BW(AntiAliasFiltCfg[i+1]);
    VRX_set_AA_FILT_PROG_BW(AntiAliasFiltCfg[i+2]);
    return (ATVERR_OK);
}

/*============================================================================
 * Route the input syncs to a specific sync channel
 *
 * Entry:   Hsync: The hsync to route
 *          Vsync: The vsync to route
 *          EmbSync: The embedded sync to route
 *          SyncCh: The sync channel the input sync must be routed to
 *
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_INV_PARM = Invalid input parameter
 *          ATVERR_NOT_AVAILABLE = Function not yet supported
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR HAL_CpRouteSyncToSyncCh (RX_HS_SEL Hsync, RX_VS_SEL Vsync, RX_EMBSYNC_SEL EmbSync, RX_SYNC_CH SyncCh)
{
    UINT8 i, j, k;
    

    i = (UCHAR)(ATV_LookupValue8 ((UCHAR*)HsyncChCfg, (UCHAR)Hsync, 0xff, 3));
    j = (UCHAR)(ATV_LookupValue8 ((UCHAR*)VsyncChCfg, (UCHAR)Vsync, 0xff, 3));
    k = (UCHAR)(ATV_LookupValue8 ((UCHAR*)EmbSyncChCfg, (UCHAR)EmbSync, 0xff, 7));
    if((HsyncChCfg[i] == 0xff) || 
        (VsyncChCfg[j] == 0xff) ||  
        (EmbSyncChCfg[k] == 0xff))
    {
        return (ATVERR_INV_PARM);
    }
    switch(SyncCh)
    {
        case RX_SYNC_CH1:
            VRX_set_SYNC_CH1_HS_SEL(HsyncChCfg[i+1]);   
            VRX_set_SYNC_CH1_VS_SEL(VsyncChCfg[j+1]);
            VRX_set_SYNC_CH1_EMB_SYNC_SEL(EmbSyncChCfg[k+1]);
            if(EmbSyncChCfg[k+2] != 0xff)
            {
                VRX_set_EMB_SYNC_SEL_MAN_EN(EmbSyncChCfg[k+2]);
            }
            if(EmbSyncChCfg[k+3] != 0xff)
            {
                VRX_set_EMB_SYNC_1_SEL_MAN(EmbSyncChCfg[k+3]);
            }
            break;
        case RX_SYNC_CH2:
            if((HsyncChCfg[i+2] == 0xff) || (VsyncChCfg[j+2] == 0xff) || (EmbSyncChCfg[k+4] == 0xff))
            {
                return (ATVERR_INV_PARM);
            }
            VRX_set_SYNC_CH2_HS_SEL(HsyncChCfg[i+2]);
            VRX_set_SYNC_CH2_VS_SEL(VsyncChCfg[j+2]);
            VRX_set_SYNC_CH2_EMB_SYNC_SEL(EmbSyncChCfg[k+4]);
            if(EmbSyncChCfg[k+5] != 0xff)
            {
                VRX_set_EMB_SYNC_SEL_MAN_EN(EmbSyncChCfg[k+5]);
            }
            if(EmbSyncChCfg[k+6] != 0xff)
            {
                VRX_set_EMB_SYNC_2_SEL_MAN(EmbSyncChCfg[k+6]);
            }  
            break;
        default:
            return (ATVERR_INV_PARM);
    }
    return (ATVERR_OK);
}

#endif
