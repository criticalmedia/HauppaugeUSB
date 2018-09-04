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

#if (RX_DEVICE == 7842) 

#include "rx_cfg.h"
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
ATV_ERR HAL_SetManagePower(RX_CHIP_SECTION Section, BOOL PowerUp)
{
    ATV_ERR ErrVal;
    ErrVal = ATVERR_OK;
    
    switch(Section)
    {
        case RX_ALL_SECTIONS:
            VRX_set_POWER_DOWN(!PowerUp);
            break;
        case RX_CP:
            VRX_set_CP_PWRDN(!PowerUp);
            break;
        case RX_XTAL:
            VRX_set_XTAL_PDN(!PowerUp);
            break;
        case RX_ALL_CORES:
            VRX_set_CORE_PDN(!PowerUp);
            break;
        case RX_VDP:
            VRX_set_VDP_PDN(!PowerUp);
            break;
        case RX_ALL_ADC_CCT:
            VRX_set_PDN_ADC0(!PowerUp);
            VRX_set_PDN_ADC1(!PowerUp);
            VRX_set_PDN_ADC2(!PowerUp);
            VRX_set_PDN_ADC3(!PowerUp);
            break;
        case RX_ADC0_CCT:
            VRX_set_PDN_ADC0(!PowerUp);
            break;
        case RX_ADC1_CCT:
            VRX_set_PDN_ADC1(!PowerUp);
            break;
        case RX_ADC2_CCT:
            VRX_set_PDN_ADC2(!PowerUp);
            break;
        case RX_ADC3_CCT:
            VRX_set_PDN_ADC3(!PowerUp);
            break;
        case RX_CEC_CTRL:
            VRX_set_CEC_POWER_UP(PowerUp);
            break;
        case RX_AVLINK_CTRL:
            VRX_set_AVL_AVLINK_POWER_UP(PowerUp);
            break;
        default:
            ErrVal= ATVERR_INV_PARM;
            break;
    }
    return (ErrVal);
}
/*============================================================================
 * Enable/Disable fast switching on specified port
 *
 * Entry:   Port   = Port to set Bstatus for
 *          Enable = TRUE/FALSE to enable/disable fast switching
 *
 * Return:  ATVERR_OK = Indicates the function completed successfully
 *
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR HAL_RxSetFastSwitchPort (RX_HDMI_PORT Port, BOOL Enable)
{
    UCHAR En;
    ATV_ERR RetVal = ATVERR_OK;

    En = Enable? 1: 0;
    switch (Port)
    {
        case PORT_A:
            VRX_set_EN_BG_PORT_A(En);
            VRX_set_FULL_PWR_BG_PORT_A(En);
            break;
        case PORT_B:
            VRX_set_EN_BG_PORT_B(En);
            VRX_set_FULL_PWR_BG_PORT_B(En);
            break;
        case PORT_ALL:
            VRX_set_EN_BG_PORT_A(En);
            VRX_set_EN_BG_PORT_B(En);
            VRX_set_FULL_PWR_BG_PORT_A(En);
            VRX_set_FULL_PWR_BG_PORT_B(En);
            break;
        default:
            RetVal = ATVERR_INV_PARM;
            break;
    }
    VRX_set_FR_BG_PORTS(En);        /* If enabling fast switching-enable Freerun BG ports*/
    return (RetVal);
}


/*===========================================================================
 * Set and enable Rx internal EDID for all ports
 *
 * Entry:   EdidBuf   = Pointer to 256 byte buffer containing EDID data
 *          SpaOffset = Offset of SPA in the buffer. 0 to ignore spa seetings
 *                      in SpaValues
 *          SpaValues = Array of SPA values for port B, C and D (2 bytes/port)
 *                      First byte contains A.B, second contains C.D
 *                      if SpaOffset ise set to 0, this parameter is ignored
 *          Segment   = 0 or 1
 *
 * Return:  ATVERR_OK
 *
 * Notes:   This function DOES NOT change HPD state for any of the ports
 *
 *==========================================================================*/
 ATV_ERR HAL_RxHdmiSetInternalEdid (UCHAR *EdidBuffer, UINT16 SpaOffset, 
                        UCHAR *SpaValues, UCHAR SegNum, BOOL DisableAutoEdid)
{
    HAL_RxPopulateEdidMap (EdidBuffer, 256, SegNum);
    if (SpaOffset && SpaValues)
    {
        HAL_RxSetSpas(SpaOffset, SpaValues);
    }
    HAL_RxToggleInternalEdid();
    return (ATVERR_OK);
}

#endif
