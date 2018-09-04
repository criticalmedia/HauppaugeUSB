/**********************************************************************************************
*																						      *
* Copyright (c) 2012 Analog Devices, Inc.  All Rights Reserved.                               *
* This software is proprietary and confidential to Analog Devices, Inc. and its licensors.    *
*                                                                                             *
***********************************************************************************************/

/*============================================================================
 * This file contains all functions that are common across all chip families
 * but can not (or should not) be implemented in the LIB layer
 *
 *===========================================================================*/
#include "rx_lib.h"

#if (RX_DEVICE == 7840)

#if RX_INCLUDE_VBI
#include "rx_isr.h"

#define VRX_BIT_SDP_TTXT_DETECTED_STATUS            0x80
#define VRX_BIT_SDP_GS_DATA_TYPE_DETECTED_STATUS    0x20

/*==========================================
 * Local variable
 *=========================================*/
CONSTANT MASK_INFO RxSdpVdpMaskInfo[] =
{
    { RX_EVENT_VDP_TTXT,
        SDP_IO_MASK_B4, {VRX_BIT_TTXT_AVL_MB1, VRX_BIT_TTXT_AVL_MB2},
        0xff, {0, 0}
    },    
    { RX_EVENT_VDP_VITC,
        SDP_IO_MASK_B4, {VRX_BIT_VITC_AVL_MB1, VRX_BIT_VITC_AVL_MB2},
        0xff, {0, 0}
    },
    { RX_EVENT_VDP_GPVUC,
        SDP_IO_MASK_B4, {VRX_BIT_GS_PDC_VPS_UTC_AVL_MB1, VRX_BIT_GS_PDC_VPS_UTC_AVL_MB2},
        SDP_IO_MASK_B4, {VRX_BIT_GS_DATA_TYPE_MB1, VRX_BIT_GS_DATA_TYPE_MB2}
    },
    { RX_EVENT_VDP_CGMS_WSS,
        SDP_IO_MASK_B4, {VRX_BIT_CGMS_WSS_AVL_MB1, VRX_BIT_CGMS_WSS_AVL_MB2},
        0xff, {0, 0}
    },
    { RX_EVENT_VDP_CCAP,
        SDP_IO_MASK_B4, {VRX_BIT_CCAP_AVL_MB1, VRX_BIT_CCAP_AVL_MB2},
        SDP_IO_MASK_B4, {VRX_BIT_CCAP_EVEN_FIELD_MB1, VRX_BIT_CCAP_EVEN_FIELD_MB2}
    },
    {
        (RX_EVENT)0xff, 
        0xff, {0, 0}, 
        0xff, {0, 0}
    }
};

/*==========================================
 * Local constants
 *=========================================*/
STATIC CONSTANT UCHAR RxSdpVdpMaskRegs[] = 
{
    VRX_REG_ENABLE_INTERRUPTS_4, 0, SDP_IO_MASK_B4,
    0, 0
};

/*============================================================================
 * This function is used to enable or disable Vdp events
 *
 * Entry:   EventList: A pointer to a list of RX events that should be enabled
 *                     or disable
 *          ListSize:  The number of event in the listed pointed by EvntList
 *          Enable:    TRUE = To enable the events pointed by EventList
 *                     FALSE = To disable the events pointed by EventList
 *  
 * Return:  Number or enabled/disabled events processed
 *
 * Notes:   None
 *
 *===========================================================================*/
UCHAR HAL_RxSdpVdpSetEnabledEvents (RX_EVENT *EventList, UCHAR ListSize, BOOL Enable)
{
    UINT8 i, j, IntCount=0, MaskVal[NOF_RX_MASK_REGS];


    /*=======================================
     * Get interrupt mask values
     *======================================*/
    for (i=0; RxSdpVdpMaskRegs[i]; i+=3)
    {
        HAL_I2CReadByte(VRX_SDP_IO_MAP_ADDR, RxSdpVdpMaskRegs[i], &(MaskVal[RxSdpVdpMaskRegs[i+2]]));
    }

    /*====================================
     * Enable/disable required events
     *===================================*/
    for (i=0; i<ListSize; i++)
    {
        for (j=0; RxSdpVdpMaskInfo[j].Event != 0xff; j++)
        {
            if (RxSdpVdpMaskInfo[j].Event == EventList[i])
            {
                MaskVal[RxSdpVdpMaskInfo[j].Reg1] &= ~(RxSdpVdpMaskInfo[j].Mask1[0]);
                RX_EVENT_DISABLE(EventList[i]);
                if (Enable)
                {
                    MaskVal[RxSdpVdpMaskInfo[j].Reg1] |= RxSdpVdpMaskInfo[j].Mask1[0];
                    RX_EVENT_ENABLE(EventList[i]);
                }
                if (RxSdpVdpMaskInfo[j].Reg2 != 0xff)
                {
                    MaskVal[RxSdpVdpMaskInfo[j].Reg2] &= ~(RxSdpVdpMaskInfo[j].Mask2[0]);
                    if (Enable)
                    {
                        MaskVal[RxSdpVdpMaskInfo[j].Reg2] |= RxSdpVdpMaskInfo[j].Mask2[0];
                    }
                }
                IntCount++;
                break;
            }
        }
    }

    /*=======================================
     * Update interrupt masks
     *======================================*/
    for (i=0; RxSdpVdpMaskRegs[i]; i+=3)
    {
        HAL_I2CWriteByte(VRX_SDP_IO_MAP_ADDR, RxSdpVdpMaskRegs[i], MaskVal[RxSdpVdpMaskRegs[i+2]]);
        HAL_I2CWriteByte(VRX_SDP_VDP_MAP_ADDR, RxSdpVdpMaskRegs[i], MaskVal[RxSdpVdpMaskRegs[i+2]]);
    }
    
    return(IntCount);
}

/*==========================================================================
 * Finds out all the active nad unmasked CP interrupts. It clears all the 
 * active interupts on return.
 *
 * Entry:   RxCpInts = is a BOOL array that contains status of all the HDMI
 *                      interrupts
 * 
 * Notes:  None
 *=========================================================================*/
void HAL_RxSdpVdpGetInterrupts(RX_VDP_INTERRUPTS *RxVdpInts)
{
    UINT8 IntStatus4;
        
    HAL_I2CReadByte(VRX_SDP_IO_MAP_ADDR, VRX_REG_STATUS_INTERRUPTS_4, &IntStatus4);

    /*==================================================================
     * Acknowledge all interrupts immediately so we don't lose any
     *=================================================================*/
    HAL_I2CWriteByte(VRX_SDP_IO_MAP_ADDR, VRX_REG_CLEAR_INTERRUPTS_4, IntStatus4);
  /*HAL_I2CWriteByte(VRX_SDP_VDP_MAP_ADDR, VRX_REG_VDP_STATUS_CLEAR, IntStatus4);*/     /*This line is not needed*/
    
     
    RxVdpInts->TtxtDet = (BOOL) (IntStatus4 & VRX_BIT_SDP_TTXT_DETECTED_STATUS);                               
    RxVdpInts->VitcDet = (BOOL) (IntStatus4 & VRX_BIT_SDP_VITC_DETECTED_STATUS);
    RxVdpInts->GsPdcVpsUtcDet = (BOOL) ((IntStatus4 & VRX_BIT_SDP_GS_VPS_UTC_DETECTED_STATUS) |
                                       (IntStatus4 & VRX_BIT_SDP_GS_DATA_TYPE_DETECTED_STATUS));
    RxVdpInts->CgmsWssDetected = (BOOL) (IntStatus4 & VRX_BIT_SDP_CGMS_WSS_DETECTED_STATUS);
    RxVdpInts->CcapDet = (BOOL) ((IntStatus4 & VRX_BIT_SDP_CC_DATA_DETECTED_STATUS) |
                               (IntStatus4 & VRX_BIT_SDP_CC_EVEN_FLD_DETECTED_STATUS));
}

/*==========================================================================
 * VDP ISR
 *
 * Entry:  None
 * 
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 * 
 * Notes:  None
 *=========================================================================*/
ATV_ERR HAL_RXLIB_SdpVdpIsr (void)
{
    RX_VDP_INTERRUPTS VdpInts;
    UINT8 ByteX; 
    UINT8  PktBuf[2];
    ATV_ERR RetVal = ATVERR_FAILED;
    RX_EVENT EventList;
    
    /*=======================================
     * Get asserted interrupts
     *======================================*/
    HAL_RxSdpVdpGetInterrupts (&VdpInts);
    
    /*==================================================
     * Teletext detection
     *=================================================*/
    if (VdpInts.TtxtDet)
    {
        EventList = RX_EVENT_VDP_TTXT;
        RX_NOTIFY_USER(RX_EVENT_VDP_TTXT, 0, NULL);
        RetVal = ATVERR_OK;
    }
    if (VdpInts.VitcDet)
    {
        EventList = RX_EVENT_VDP_VITC;     
        RX_NOTIFY_USER(RX_EVENT_VDP_VITC, 0, NULL);
        RetVal = ATVERR_OK;
    }
    if (VdpInts.GsPdcVpsUtcDet)
    {
        PktBuf[0] = (ADIAPI_RxVdpIsTypeDetected(RX_GEMS_1X) == (ATVERR_TRUE) ? 1 : 0);
        PktBuf[1] = (ADIAPI_RxVdpIsTypeDetected(RX_GEMS_2X) == (ATVERR_TRUE) ? 1 : 0);
        EventList = RX_EVENT_VDP_GPVUC;       
        RX_NOTIFY_USER(RX_EVENT_VDP_GPVUC, 0, PktBuf);
        RetVal = ATVERR_OK;
    }
    if (VdpInts.CgmsWssDetected)
    {
        EventList = RX_EVENT_VDP_CGMS_WSS;     
        RX_NOTIFY_USER(RX_EVENT_VDP_CGMS_WSS, 0, NULL);
        RetVal = ATVERR_OK;
    }
    if (VdpInts.CcapDet)
    {
        ByteX = (ADIAPI_RxVdpIsDataOnEvenField(RX_CCAP) == ATVERR_TRUE ? 1 : 0) ;
        EventList = RX_EVENT_VDP_CCAP;      
        RX_NOTIFY_USER(RX_EVENT_VDP_CCAP, 0, &ByteX);
        RetVal = ATVERR_OK;
    }
    return (RetVal);
}
#endif

#endif
