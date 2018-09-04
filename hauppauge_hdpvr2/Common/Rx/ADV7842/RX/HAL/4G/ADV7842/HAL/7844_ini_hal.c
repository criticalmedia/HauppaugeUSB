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

#if (RX_DEVICE == 7844 || RX_DEVICE == 7842)

#include "rx_cfg.h"
#include "rx_isr.h"

/*===============================
 * External declarations
 *==============================*/

/*==========================================
 * Shared constants
 *=========================================*/
CONSTANT UCHAR RxPllInitTable[] = 
{
    /*===============================
     * PLL Recommendations
     *==============================*/  
    RX_I2C_HDMI_MAP_ADDR,      0x57, 0xB6, /*ADI Recommended PLL BW Setting- Use default- last updated 09/09/10*/  
    RX_I2C_HDMI_MAP_ADDR,      0x58, 0x03, /*ADI Recommended PLL BW Setting- Use default*/
    RX_I2C_HDMI_MAP_ADDR,      0x3D, 0x10, /*ADI Recommended TMDS Gear Inititialisation*/  
    RX_I2C_HDMI_MAP_ADDR,      0x60, 0x88, /*ADI Recommended TMDS Gear Inititialisation*/ 
    RX_I2C_HDMI_MAP_ADDR,      0x61, 0x88, /*ADI Recommended TMDS Gear Inititialisation*/ 
    /*RX_I2C_HDMI_MAP_ADDR,      0x67, 0x20*/ /*ADI Recommended TMDS Gear Inititialisation Not included in R1.3*/ 
    RX_I2C_HDMI_MAP_ADDR,      0x99, 0xA1, /*ADI Recommended PRC Setting*/
    RX_I2C_HDMI_MAP_ADDR,      0x9B, 0x09, /*ADI Recommended PCN Setting*/
    0
};

CONSTANT UCHAR RxEqInitTable[] = 
{
    /*===============================
     * Equaliser Recommendations
     *==============================*/
    RX_I2C_HDMI_MAP_ADDR,      0x85, 0x1F,
    RX_I2C_HDMI_MAP_ADDR,      0x87, 0x70,  /*- last updated 21/09/10*/
    RX_I2C_HDMI_MAP_ADDR,      0x89, 0x04,  /*- Added 09/09/10*/
    RX_I2C_HDMI_MAP_ADDR,      0x8A, 0x1E,  /*- last updated 09/09/10*/
    RX_I2C_HDMI_MAP_ADDR,      0x8D, 0x04,  /*- Added 09/09/10*/
    RX_I2C_HDMI_MAP_ADDR,      0x8E, 0x1E,  /*- last updated 09/09/10*/ 
    RX_I2C_HDMI_MAP_ADDR,      0x90, 0x04,  /*- Added 09/09/10*/
    RX_I2C_HDMI_MAP_ADDR,      0x91, 0x1E,  /*- last updated 09/09/10*/
    RX_I2C_HDMI_MAP_ADDR,      0x93, 0x04,  /*- Added 09/09/10*/
    RX_I2C_HDMI_MAP_ADDR,      0x94, 0x1E,  /*- last updated 09/09/10*/
    RX_I2C_HDMI_MAP_ADDR,      0x9D, 0x02,
    RX_I2C_HDMI_MAP_ADDR,      0xC0, 0xFF,
    RX_I2C_HDMI_MAP_ADDR,      0xC1, 0xFF,
    RX_I2C_HDMI_MAP_ADDR,      0xC2, 0xFF,
    RX_I2C_HDMI_MAP_ADDR,      0xC3, 0xFF,
    RX_I2C_HDMI_MAP_ADDR,      0xC4, 0xFF,
    RX_I2C_HDMI_MAP_ADDR,      0xC5, 0x00,
    RX_I2C_HDMI_MAP_ADDR,      0xC6, 0x00,
    

        
    0
};

CONSTANT UCHAR RxHdmiAdiRecSetTable[] = 
{
    /*===============================
     * HDMI ADI Recommended Settings
     *==============================*/

    RX_I2C_HDMI_MAP_ADDR,      0xCA, 0x60,      /*ADI Recommended setting for HEC function*/
    RX_I2C_HDMI_MAP_ADDR,      0x46, 0x1F,      /*ADI Recommended setting for Data Alignment Correction*/
    RX_I2C_HDMI_MAP_ADDR,      0x75, 0x10,      /*ADI Recommended setting for DDC line Drive Strength*/
    RX_I2C_HDMI_MAP_ADDR,      0x48, 0x06,      /*ADI Recommended setting for Audio Fifo Configuration*/

    RX_I2C_HDMI_MAP_ADDR,      0x6C, 0x10,      /* HDMI CTRL Decoding Setting*/
    RX_I2C_HDMI_MAP_ADDR,      0x14, 0x1D,      /* Remove audio mute mask for parity error        */
    RX_I2C_HDMI_MAP_ADDR,      0x1A, 0x42,      /* Allow audio packets with parity error          */
    RX_I2C_HDMI_MAP_ADDR,      0x50, 0x04,      /* Audio Channel Status validity after two frames */
    0
};
CONSTANT UCHAR RxHdmiCpCoreRecSetTable[] = 
{  
    RX_I2C_CP_MAP_ADDR,        0xC8, 0x08,      /* Set digital fine clamp setting for HDMI Mode*/  
    RX_I2C_CP_MAP_ADDR,        0x3E, 0x00,      /* Disable ADC gain Blocks*/  
    RX_I2C_IO_MAP_ADDR,        0x33, 0x43,      /* Adjust LLC duty cycle and enable Manual LLC Phase Adjustment */
    RX_I2C_IO_MAP_ADDR,        0x19, 0x80,      /* Manual LLC Phase Adjustment */ 
    RX_I2C_CP_MAP_ADDR,        0xC3, 0x39,      /* Default*/
    RX_I2C_CP_MAP_ADDR,        0x6C, 0x00,      /* Disable Auto Clamping*/
    0
};

CONSTANT UCHAR RxFsResetSetTable[] = 
{
    /*===================================
     * For Fast-Switch Modes
     * Reset Any Mode Specific Configurations
     * Back to default setting
     *===================================*/     
    RX_I2C_CP_MAP_ADDR,        0xC3, 0x39,      /* Default*/
    RX_I2C_CP_MAP_ADDR,        0x73, 0x10,      /* Default*/
    RX_I2C_CP_MAP_ADDR,        0x74, 0x04,      /* Default*/
    RX_I2C_CP_MAP_ADDR,        0x75, 0x01,      /* Default*/
    RX_I2C_CP_MAP_ADDR,        0x76, 0x00,      /* Default*/
    RX_I2C_CP_MAP_ADDR,        0x68, 0x00,      /* Default*/
    RX_I2C_IO_MAP_ADDR,        0xC2, 0x0E,     /* Default*/
    RX_I2C_IO_MAP_ADDR,        0xE0, 0x00,     /* Default*/
    RX_I2C_CP_MAP_ADDR,        0x6C, 0x10,     /*Default*/
    RX_I2C_CP_MAP_ADDR,        0x3E, 0x04,     /*Default*/ 
    RX_I2C_IO_MAP_ADDR,        0x06, 0xA0,     /*Default*/
    0
};

CONSTANT UCHAR RxCompAdiRecSetTable[] = 
{
    /*===================================
     * Component ADI Recommended Settings
     *===================================*/     
    RX_I2C_CP_MAP_ADDR,        0xC8, 0x00,    /* Analog Digital Fine Clamp enabled for ADC modes*/  
    RX_I2C_CP_MAP_ADDR,        0xC3, 0x33,    /* ADC Only tweaking*/
    RX_I2C_CP_MAP_ADDR,        0x68, 0xF7,    /* 422 mode CSC CrCb Channel Delay*/
    RX_I2C_AFE_DPLL_MAP_ADDR,  0x12, 0x63,    /* ADC Range Setting*/
    RX_I2C_AFE_DPLL_MAP_ADDR,  0x0C, 0x1F,    /* ADC Range Setting*/
    0
};

CONSTANT UCHAR RxGraphicsAdiRecSetTable[] = 
{
    /*==================================
     * Graphics ADI Recommended Settings
     *==================================*/

    RX_I2C_CP_MAP_ADDR,        0xC3, 0x39,    /* ADC Only tweaking*/ 
    RX_I2C_AFE_DPLL_MAP_ADDR,  0x12, 0x63,    /* ADC Range Setting*/
    RX_I2C_AFE_DPLL_MAP_ADDR,  0x0C, 0x1F,    /* ADC Range Setting*/
    0
};

CONSTANT UCHAR RxSDPAdiRecSetTable[] = 
{
    /*===================================
     * SDP Core ADI Recommended Settings
     *==================================*/
     RX_I2C_AFE_DPLL_MAP_ADDR,        0x0C, 0x1F,
     RX_I2C_AFE_DPLL_MAP_ADDR,        0x12, 0x63,
     RX_I2C_SDP_MAP_ADDR,             0x03, 0xE4,     /* Manual VCR gain*/
     RX_I2C_SDP_MAP_ADDR,             0x04, 0x0B,     /* Manual gain*/
     RX_I2C_SDP_MAP_ADDR,             0x05, 0xC3,     /* Manual chroma gain*/
     RX_I2C_SDP_MAP_ADDR,             0x06, 0xFE,     /* Manual chroma gain*/ 
     RX_I2C_SDP_MAP_ADDR,             0xA7, 0x00,     /* Disable 3D Coring*/  
    0
};

CONSTANT UCHAR RxSDPCompAdiRecSetTable[] = 
{
    /*==========================================
     * SDP Component ADI Recommended Settings
     *=========================================*/ 
    0
};

CONSTANT UCHAR RxSDPDecodeAdiRecSetTable[] = 
{
    /*=====================================
     * SDP Decoder ADI Recommended Settings
     *=====================================*/
    0
};

CONSTANT UCHAR RxSDPCvbsMonitorHdmiAdiRecSetTable[] = 
{
    /*==============================================
     * SDP Decoder & HDMI ADI Recommended Settings
     *=============================================*/
    0
};

/*===========================================================================
 * Initialise the part into a specific mode.
 *
 * Entry:   OperatingMode = Mode the part mus be set into
 *
 * Return:  ATVERR_OK
 *
 * Notes:   For the ADV7840 a hardware reset should be done 
 *          before this function is called         
 *
 *==========================================================================*/
ATV_ERR HAL_RxInit (RX_OP_MODE OperatingMode)
{
    UCHAR i;
    
    /*===============================================
     * Software init
     *==============================================*/    
    CurrVideoDetected = FALSE;
    CurrBurstLock     = FALSE;
    CurrMvAgcDetected    = FALSE;
    CurrMvPsDetected    = FALSE;
    CurrMvCsDetected    = FALSE;
    CurrSspdLock = FALSE;
    CurrSspdLockCh1 = FALSE;
    CurrSspdLockCh2 = FALSE;
    CurrSdpStdDetected = RX_NTSC;
    RxPrevOperatingMode = RX_OPMODE_PWRDWN;
    RxOperatingMode     = RX_OPMODE_PWRDWN;
    
    for (i=0; i<RX_ENABLE_EVENTS_SIZE; i++)
    {
        RxEnabledEvents[i] = 0;
    }
    
    /*===============================================
     * Apply Full SW reset
     *==============================================*/
     VRX_set_MAIN_RESET(0x1);
     HAL_DelayMs(5);

    /*===============================================
     * Set I2C address of I2C programmabled maps
     *==============================================*/
    HAL_SetI2cMapAddress(RX_SDP_MAP, VRX_SDP_MAP_ADDR);
    HAL_SetI2cMapAddress(RX_SDP_IO_MAP, VRX_SDP_IO_MAP_ADDR);
    HAL_SetI2cMapAddress(RX_AVLINK_MAP, VRX_AVLINK_MAP_ADDR);
    HAL_SetI2cMapAddress(RX_INFOFRAME_MAP, VRX_INFOFRAME_MAP_ADDR);
    HAL_SetI2cMapAddress(RX_CEC_MAP, VRX_CEC_MAP_ADDR);
    HAL_SetI2cMapAddress(RX_CP_MAP, VRX_CP_MAP_ADDR);
    HAL_SetI2cMapAddress(RX_VDP_MAP, VRX_VDP_MAP_ADDR);
    HAL_SetI2cMapAddress(RX_AFE_MAP, VRX_AFE_DPLL_MAP_ADDR);
    HAL_SetI2cMapAddress(RX_HDMI_MAP, VRX_HDMI_MAP_ADDR);
    HAL_SetI2cMapAddress(RX_REPEATER_MAP, VRX_REPEATER_MAP_ADDR);
    HAL_SetI2cMapAddress(RX_EDID_MAP, VRX_EDID_MAP_ADDR);


    /*===============================================
     * Configure the part into the requested
     * operating mode
     *==============================================*/    
    HAL_SetOperatingMode(OperatingMode, NULL);

#if RX_USER_INIT
    /*====================================
     * Set User-specified init values
     *===================================*/
    HAL_RxI2CWriteTable ((UINT8 *)UserRxRegInitTable, 0);
    HAL_RxI2CWriteFields ((UINT8 *)UserRxFieldInitTable, 0);
#endif
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
ATV_ERR HAL_SetI2cMapAddress(RX_I2C_MAP  Map, UINT8 Address)
{
    ATV_ERR ErrVal = ATVERR_OK;

    Address >>= 1;
    switch (Map)
    {
        case RX_SDP_MAP:
            VRX_set_SDP_SLAVE_ADDR(Address);
            break; 
        case RX_SDP_IO_MAP:
            VRX_set_SDP_IO_SLAVE_ADDR(Address);
            break; 
        case RX_CP_MAP:
            VRX_set_CP_SLAVE_ADDR(Address);
            break;
        case RX_VDP_MAP:
            VRX_set_VDP_SLAVE_ADDR(Address);
            break;
        case RX_AFE_MAP:
            VRX_set_AFE_SLAVE_ADDR(Address);
            break;
        case RX_HDMI_MAP:
            VRX_set_HDMI_SLAVE_ADDR(Address);
            break;
        case RX_REPEATER_MAP:
            VRX_set_KSV_SLAVE_ADDR(Address); 
            break;
        case RX_EDID_MAP:
            VRX_set_EDID_SLAVE_ADDR(Address);
            break;
        case RX_INFOFRAME_MAP:
            VRX_set_INFOFRAME_SLAVE_ADDR(Address);
            break;
        case RX_CEC_MAP:
            VRX_set_CEC_SLAVE_ADDR(Address);
            break;
        case RX_AVLINK_MAP:
            VRX_set_AVLINK_SLAVE_ADDR(Address);
            break;
        default:
            ErrVal = ATVERR_INV_PARM;
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
 * Notes:   Ideally the part should be reset before calling this function
 *
 *=========================================================================*/
ATV_ERR HAL_SetOperatingMode (RX_OP_MODE OperatingMode, RX_OP_MODE_CFG *OpModeCfg)
{
    BOOL DisPowerMgt;
    BOOL DisTriStateMgt;
    RX_OP_MODE TmpOperatingMode;

    if (OpModeCfg == NULL)
    {
       DisPowerMgt = FALSE;
       DisTriStateMgt = FALSE;
    }
    else
    {
        DisPowerMgt = OpModeCfg->DisPowerMgt;
        DisTriStateMgt = OpModeCfg->DisTriStateMgt;
    }

    switch(OperatingMode)
    {
        case RX_OPMODE_PWRDWN:
            if (!DisPowerMgt)
            {
                HAL_I2CWriteByte(VRX_HDMI_MAP_ADDR, 0xC0, 0x00);
                VRX_set_POWER_DOWN(0x1);
            }
            break;
        case RX_OPMODE_PWRUP:
            if(RxOperatingMode != RX_OPMODE_PWRDWN)
            {
                return (ATVERR_FAILED);
            }
            VRX_set_POWER_DOWN(0);
            HAL_I2CWriteByte(VRX_HDMI_MAP_ADDR, 0xC0, 0xFF);
            TmpOperatingMode = RxPrevOperatingMode;
            RxPrevOperatingMode = RxOperatingMode; 
            RxOperatingMode = TmpOperatingMode;
            return (ATVERR_OK);
        case RX_OPMODE_HDMI:
            if(!DisPowerMgt)
            {
                VRX_set_POWER_DOWN(0x0);
                VRX_set_PDN_ADC0(0x1);
                VRX_set_PDN_ADC1(0x1);
                VRX_set_PDN_ADC2(0x1);
                VRX_set_PDN_ADC3(0x1);
            }
            VRX_set_PRIM_MODE(0x6);
            VRX_set_VID_STD(0x2);
            if(!DisTriStateMgt)
            {
                VRX_set_SDP_SFL_EN(1); 
                VRX_set_TRI_PIX(0);
                VRX_set_TRI_LLC(0);
                VRX_set_TRI_SYNCS(0);
                VRX_set_TRI_AUDIO(0);
            }  
            HAL_RxI2CWriteTable((UCHAR *)RxFsResetSetTable,0);  
            HAL_RxI2CWriteTable((UCHAR *)RxPllInitTable,0);
            HAL_RxI2CWriteTable((UCHAR *)RxEqInitTable,0);
            HAL_RxI2CWriteTable((UCHAR *)RxHdmiAdiRecSetTable,0);
            HAL_RxI2CWriteTable((UCHAR *)RxHdmiCpCoreRecSetTable, 0);
            break;
        case RX_OPMODE_COMP:
            if(!DisPowerMgt)
            {
                VRX_set_POWER_DOWN(0x0);
                VRX_set_PDN_ADC0(0x0);
                VRX_set_PDN_ADC1(0x0);
                VRX_set_PDN_ADC2(0x0);
                VRX_set_PDN_ADC3(0x1);
            }
            VRX_set_PRIM_MODE(0x1);
            VRX_set_VID_STD(0x2);
            
            if(!DisTriStateMgt)
            {
                VRX_set_SDP_SFL_EN(1); 
                VRX_set_TRI_PIX(0);
                VRX_set_TRI_LLC(0);
                VRX_set_TRI_SYNCS(0);
            }
            HAL_RxI2CWriteTable((UCHAR *)RxFsResetSetTable,0);
            HAL_RxI2CWriteTable((UCHAR *)RxCompAdiRecSetTable,0);
            HAL_RxI2CWriteTable((UCHAR *)RxPllInitTable,0);
            HAL_RxI2CWriteTable((UCHAR *)RxEqInitTable,0);
            HAL_RxI2CWriteTable((UCHAR *)RxHdmiAdiRecSetTable,0);
            break;
        case RX_OPMODE_GR:  
            if(!DisPowerMgt)
            {
                VRX_set_POWER_DOWN(0x0);
                VRX_set_PDN_ADC0(0x0);
                VRX_set_PDN_ADC1(0x0);
                VRX_set_PDN_ADC2(0x0);
                VRX_set_PDN_ADC3(0x1);
            }
            VRX_set_PRIM_MODE(0x2);
            VRX_set_VID_STD(0x8);
            if(!DisTriStateMgt)
            {
                VRX_set_SDP_SFL_EN(0); 
                VRX_set_TRI_PIX(0);
                VRX_set_TRI_LLC(0);
                VRX_set_TRI_SYNCS(0);
            }
            HAL_RxI2CWriteTable((UCHAR *)RxFsResetSetTable,0);
            HAL_RxI2CWriteTable ((UCHAR *)RxGraphicsAdiRecSetTable, 0);
            HAL_RxI2CWriteTable((UCHAR *)RxPllInitTable,0);
            HAL_RxI2CWriteTable((UCHAR *)RxEqInitTable,0);
            HAL_RxI2CWriteTable((UCHAR *)RxHdmiAdiRecSetTable,0);
            break;
        case RX_OPMODE_SDP_COMP:
            if(!DisPowerMgt)
            {
                VRX_set_POWER_DOWN(0x0);
                VRX_set_PDN_ADC0(0x0);
                VRX_set_PDN_ADC1(0x0);
                VRX_set_PDN_ADC2(0x0);
                VRX_set_PDN_ADC3(0x1);
            }
            
            VRX_set_PRIM_MODE(0x0);
            VRX_set_VID_STD(0x11);
            if(!DisTriStateMgt)
            {
                VRX_set_SDP_SFL_EN(1); 
                VRX_set_TRI_LLC(1);
                VRX_set_TRI_SYNCS(1);
                VRX_set_TRI_AUDIO(1);
            }
            HAL_RxI2CWriteTable((UCHAR *)RxFsResetSetTable,0);
            HAL_RxI2CWriteTable((UCHAR *)RxSDPAdiRecSetTable,0);
            HAL_RxI2CWriteTable((UCHAR *)RxSDPCompAdiRecSetTable,0);
            HAL_RxI2CWriteTable((UCHAR *)RxPllInitTable,0);
            HAL_RxI2CWriteTable((UCHAR *)RxEqInitTable,0);
            HAL_RxI2CWriteTable((UCHAR *)RxHdmiAdiRecSetTable,0);
            break;
        case RX_OPMODE_SDP_CVBS:
            
            if(!DisPowerMgt)
            {
                VRX_set_POWER_DOWN(0x0);
                VRX_set_PDN_ADC0(0x0);
                VRX_set_PDN_ADC1(0x1);
                VRX_set_PDN_ADC2(0x1);
                VRX_set_PDN_ADC3(0x1);
            }       
            VRX_set_PRIM_MODE(0x0);
            VRX_set_VID_STD(0x1);
            if(!DisTriStateMgt)
            {
                VRX_set_SDP_SFL_EN(1); 
                VRX_set_TRI_PIX(0);
                VRX_set_TRI_LLC(0);
                VRX_set_TRI_SYNCS(0);
                VRX_set_TRI_AUDIO(1);
            }
            HAL_RxI2CWriteTable((UCHAR *)RxFsResetSetTable,0);
            HAL_RxI2CWriteTable((UCHAR *)RxSDPAdiRecSetTable,0);
            HAL_RxI2CWriteTable((UCHAR *)RxSDPDecodeAdiRecSetTable,0);
            HAL_RxI2CWriteTable((UCHAR *)RxPllInitTable,0);
            HAL_RxI2CWriteTable((UCHAR *)RxEqInitTable,0);
            HAL_RxI2CWriteTable((UCHAR *)RxHdmiAdiRecSetTable,0);
            break;

        case RX_OPMODE_SDP_YC:
            if(!DisPowerMgt)
            {
                VRX_set_POWER_DOWN(0x0);
                VRX_set_PDN_ADC0(0x0);
                VRX_set_PDN_ADC1(0x1);
                VRX_set_PDN_ADC2(0x0);
                VRX_set_PDN_ADC3(0x1);
            }
            
            VRX_set_PRIM_MODE(0x0);
            VRX_set_VID_STD(0x9);
            if(!DisTriStateMgt)
            {
                VRX_set_SDP_SFL_EN(1); 
                VRX_set_TRI_PIX(0);
                VRX_set_TRI_LLC(0);
                VRX_set_TRI_SYNCS(0);
                VRX_set_TRI_AUDIO(1);
            }
            HAL_RxI2CWriteTable((UCHAR *)RxFsResetSetTable,0);
            HAL_RxI2CWriteTable((UCHAR *)RxSDPAdiRecSetTable,0);
            HAL_RxI2CWriteTable((UCHAR *)RxSDPDecodeAdiRecSetTable,0);
            HAL_RxI2CWriteTable((UCHAR *)RxPllInitTable,0);
            HAL_RxI2CWriteTable((UCHAR *)RxEqInitTable,0);
            HAL_RxI2CWriteTable((UCHAR *)RxHdmiAdiRecSetTable,0);
            break;
        case RX_OPMODE_SDP_SCART:
          
            if(!DisPowerMgt)
            {
                VRX_set_POWER_DOWN(0x0);
                VRX_set_PDN_ADC0(0x0);
                VRX_set_PDN_ADC1(0x0);
                VRX_set_PDN_ADC2(0x0);
                VRX_set_PDN_ADC3(0x0);
            }
           
            VRX_set_PRIM_MODE(0x0);
            VRX_set_VID_STD(0x5);
            if(!DisTriStateMgt)
            {
                VRX_set_SDP_SFL_EN(1); 
                VRX_set_TRI_PIX(0);
                VRX_set_TRI_LLC(0);
                VRX_set_TRI_SYNCS(0);
                VRX_set_TRI_AUDIO(1);
            }
            HAL_RxI2CWriteTable((UCHAR *)RxFsResetSetTable,0);
            HAL_RxI2CWriteTable((UCHAR *)RxSDPAdiRecSetTable,0);
            HAL_RxI2CWriteTable((UCHAR *)RxSDPCompAdiRecSetTable,0);
            HAL_RxI2CWriteTable((UCHAR *)RxPllInitTable,0);
            HAL_RxI2CWriteTable((UCHAR *)RxEqInitTable,0);
            HAL_RxI2CWriteTable((UCHAR *)RxHdmiAdiRecSetTable,0);
            break;
        default:
            return (ATVERR_INV_PARM);
    }
    if(RxOperatingMode != OperatingMode)
    {
        RxPrevOperatingMode = RxOperatingMode;
        RxOperatingMode = OperatingMode;
        CurrSspdLock = FALSE;
    }
    return (ATVERR_OK);
}

#endif
