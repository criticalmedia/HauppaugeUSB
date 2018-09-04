/**********************************************************************************************
*																						      *
* Copyright (c) 2012 Analog Devices, Inc.  All Rights Reserved.                               *
* This software is proprietary and confidential to Analog Devices, Inc. and its licensors.    *
*                                                                                             *
***********************************************************************************************/

#include "rx_lib.h"
#include "rx_isr.h"

/*==============================
 * Shared vars
 *=============================*/
RX_LIB_VARS RxLibVars[RX_NUM_OF_INSTANCES];

CONSTANT RX_DEV_ADDR RxDeviceAddress[RX_NUM_OF_DEVICES]= {
{
    RX_I2C_IO_MAP_ADDR,
    RX_I2C_SDP_VDP_MAP_ADDR,
    RX_I2C_AFE_DPLL_MAP_ADDR,
    RX_I2C_ESDP_MAP_ADDR,
    RX_I2C_SDP_IO_MAP_ADDR,
    RX_I2C_CP_MAP_ADDR,
    RX_I2C_VDP_MAP_ADDR,
    RX_I2C_TEST_MAP3_ADDR,
    RX_I2C_TEST_MAP1_ADDR,
    RX_I2C_TEST_MAP2_ADDR,
    RX_I2C_REPEATER_MAP_ADDR,
    RX_I2C_HDMI_MAP_ADDR,
    RX_I2C_EDID_MAP_ADDR,
    RX_I2C_DPP_MAP_ADDR,
    RX_I2C_INFOFRAME_MAP_ADDR,
    RX_I2C_CEC_MAP_ADDR,
    RX_I2C_SDP_MAP_ADDR,
    RX_I2C_AVLINK_MAP_ADDR,
    RX_I2C_OSD_MAP_ADDR,
    RX_I2C_VFE_MAP_ADDR,
    RX_I2C_AUDIO_CODEC_MAP_ADDR,
    RX_I2C_XMEM_MAP_ADDR,
    TX_I2C_PKT_MEM_MAP_ADDR,
    TX_I2C_EDID_MAP_ADDR
}
#if (RX_NUM_OF_DEVICES > 1)
,{
    RX2_I2C_IO_MAP_ADDR,
    RX2_I2C_SDP_VDP_MAP_ADDR,
    RX2_I2C_AFE_DPLL_MAP_ADDR,
    RX2_I2C_ESDP_MAP_ADDR,
    RX2_I2C_SDP_IO_MAP_ADDR,
    RX2_I2C_CP_MAP_ADDR,
    RX2_I2C_VDP_MAP_ADDR,
    RX2_I2C_TEST_MAP3_ADDR,
    RX2_I2C_TEST_MAP1_ADDR,
    RX2_I2C_TEST_MAP2_ADDR,
    RX2_I2C_REPEATER_MAP_ADDR,
    RX2_I2C_HDMI_MAP_ADDR,
    RX2_I2C_EDID_MAP_ADDR,
    RX2_I2C_DPP_MAP_ADDR,
    RX2_I2C_INFOFRAME_MAP_ADDR,
    RX2_I2C_CEC_MAP_ADDR,
    RX2_I2C_SDP_MAP_ADDR,
    RX2_I2C_AVLINK_MAP_ADDR,
    RX2_I2C_OSD_MAP_ADDR,
    RX2_I2C_VFE_MAP_ADDR,
    RX2_I2C_AUDIO_CODEC_MAP_ADDR,
    RX2_I2C_XMEM_GAMMA_MAP_ADDR,
    TX2_I2C_PKT_MEM_MAP_ADDR,
    TX2_I2C_EDID_MAP_ADDR
}
#endif
#if (RX_NUM_OF_DEVICES > 2)
,{
    RX3_I2C_IO_MAP_ADDR,
    RX3_I2C_SDP_VDP_MAP_ADDR,
    RX3_I2C_AFE_DPLL_MAP_ADDR,
    RX3_I2C_ESDP_MAP_ADDR,
    RX3_I2C_SDP_IO_MAP_ADDR,
    RX3_I2C_CP_MAP_ADDR,
    RX3_I2C_VDP_MAP_ADDR,
    RX3_I2C_TEST_MAP3_ADDR,
    RX3_I2C_TEST_MAP1_ADDR,
    RX3_I2C_TEST_MAP2_ADDR,
    RX3_I2C_REPEATER_MAP_ADDR,
    RX3_I2C_HDMI_MAP_ADDR,
    RX3_I2C_EDID_MAP_ADDR,
    RX3_I2C_DPP_MAP_ADDR,
    RX3_I2C_INFOFRAME_MAP_ADDR,
    RX3_I2C_CEC_MAP_ADDR,
    RX3_I2C_SDP_MAP_ADDR,
    RX3_I2C_AVLINK_MAP_ADDR,
    RX3_I2C_OSD_MAP_ADDR,
    RX3_I2C_VFE_MAP_ADDR,
    RX3_I2C_AUDIO_CODEC_MAP_ADDR,
    RX3_I2C_XMEM_GAMMA_MAP_ADDR,
    TX3_I2C_PKT_MEM_MAP_ADDR,
    TX3_I2C_EDID_MAP_ADDR
}
#endif
};

CONSTANT RX_DEV_ADDR *RxDevAddr = &(RxDeviceAddress[0]); /* I2C base addr of RX maps */
UCHAR RxCurrDevIdx = 0;
UCHAR RxActiveCecIdx = 0;

/*========================
 * Local prototypes
 *=======================*/
STATIC UCHAR HAL_RxFindCurrentMap (UCHAR Dev0Map);

/*===========================================================================
 *
 *==========================================================================*/
UCHAR HAL_RxGetIntIndex (void)
{
    UCHAR IntIdx;

    IntIdx = VRX_is_INT2_EN_true()? 1: 0;
    if (IntIdx)
    {
        IntIdx = VRX_is_EN_MUTE_OUT_INTRQ2_true()? 0: 1;
    }
    return(IntIdx);
}

#if (RX_NUM_OF_INSTANCES > 1)
/*==========================================================================
 *
 *
 *=========================================================================*/
ATV_ERR HAL_RxSetChipIndex (UCHAR ChipIdx)
{
    if (ChipIdx < RX_NUM_OF_INSTANCES)
    {
        RxCurrDevIdx = ChipIdx;
        if (RX_NUM_OF_DEVICES == 1)
        {
            RxDevAddr = &(RxDeviceAddress[0]);
        }
        else
        {
            RxDevAddr = &(RxDeviceAddress[RxCurrDevIdx]);
        }
        HAL_RxChipSelect(RxCurrDevIdx);
        return (ATVERR_OK);
    }
    return (ATVERR_INV_PARM);
}
#endif /* RX_NUM_OF_INSTANCES > 1) */

/*===========================================================================
 *
 *==========================================================================*/
void HAL_RxI2CWriteTable (UCHAR *Table, UCHAR EndVal)
{
    UCHAR CurrMap=0, LastDev0Map=0;
    UINT16 i=0;

    if ((RX_NUM_OF_DEVICES > 1) && RxCurrDevIdx)
    {
        while (Table[i]!= EndVal)
        {
            if (Table[i] != LastDev0Map)
            {
                LastDev0Map = Table[i];
                CurrMap = HAL_RxFindCurrentMap (LastDev0Map);
            }
            if (CurrMap)
            {
                HAL_I2CWriteByte (CurrMap, Table[i+1], Table[i+2]);
                i+=3;
            }
            else
            {
                RX_DBG("**** Fatal error: Couldn't find device I2C address (0x%x) ****\n\r", LastDev0Map);
            }
        }
    }
    else
    {
        ATV_I2CWriteTable (Table, EndVal);
    }
}

/*===========================================================================
 *
 *==========================================================================*/
void HAL_RxI2CWriteFields (UCHAR *Table, UCHAR EndVal)
{
    UCHAR CurrMap=0, LastDev0Map=0;
    UINT16 i=0;

    if ((RX_NUM_OF_DEVICES > 1) && RxCurrDevIdx)
    {
        while (Table[i]!= EndVal)
        {
            if (Table[i] != LastDev0Map)
            {
                LastDev0Map = Table[i];
                CurrMap = HAL_RxFindCurrentMap (LastDev0Map);
            }
            if (CurrMap)
            {
                ATV_I2CWriteField8(CurrMap, Table[i+1], Table[i+2], 0, Table[i+3]);
                i+= 4;
            }
            else
            {
                RX_DBG("**** Fatal error: Couldn't find device I2C address (0x%x) ****\n\r", LastDev0Map);
            }
        }
    }
    else
    {
        ATV_I2CWriteFields (Table, EndVal);
    }
}
                         
/*===========================================================================
 *
 *==========================================================================*/
STATIC UCHAR HAL_RxFindCurrentMap (UCHAR Dev0Map)
{
    UCHAR i=0;
    CONSTANT RX_DEV_ADDR *Dev0Ptr, *DevPtr;

    Dev0Ptr = &(RxDeviceAddress[0]);
    DevPtr  = &(RxDeviceAddress[RxCurrDevIdx]);

    if (Dev0Map == Dev0Ptr->Io)
    {
        i = DevPtr->Io;
    }
    else if (Dev0Map == Dev0Ptr->SdpVdp)
    {
        i = DevPtr->SdpVdp;
    }
    else if (Dev0Map == Dev0Ptr->AfeDpll)
    {
        i = DevPtr->AfeDpll;
    }
    else if (Dev0Map == Dev0Ptr->Esdp)
    {
        i = DevPtr->Esdp;
    }
    else if (Dev0Map == Dev0Ptr->SdpIo)
    {
        i = DevPtr->SdpIo;
    }
    else if (Dev0Map == Dev0Ptr->Cp)
    {
        i = DevPtr->Cp;
    }
    else if (Dev0Map == Dev0Ptr->Vdp)
    {
        i = DevPtr->Vdp;
    }
    else if (Dev0Map == Dev0Ptr->Test1)
    {
        i = DevPtr->Test1;
    }
    else if (Dev0Map == Dev0Ptr->Test2)
    {
        i = DevPtr->Test2;
    }
    else if (Dev0Map == Dev0Ptr->Test3)
    {
        i = DevPtr->Test3;
    }
    else if (Dev0Map == Dev0Ptr->Rep)
    {
        i = DevPtr->Rep;
    }
    else if (Dev0Map == Dev0Ptr->Hdmi)
    {
        i = DevPtr->Hdmi;
    }
    else if (Dev0Map == Dev0Ptr->Edid)
    {
        i = DevPtr->Edid;
    }
    else if (Dev0Map == Dev0Ptr->Dpp)
    {
        i = DevPtr->Dpp;
    }
    else if (Dev0Map == Dev0Ptr->Infoframe)
    {
        i = DevPtr->Infoframe;
    }
    else if (Dev0Map == Dev0Ptr->Cec)
    {
        i = DevPtr->Cec;
    }
    else if (Dev0Map == Dev0Ptr->Sdp)
    {
        i = DevPtr->Sdp;
    }
    else if (Dev0Map == Dev0Ptr->Avlink)
    {
        i = DevPtr->Avlink;
    }
    else if (Dev0Map == Dev0Ptr->Osd)
    {
        i = DevPtr->Osd;
    }
    else if (Dev0Map == Dev0Ptr->TxUdp)
    {
        i = DevPtr->TxUdp;
    }
    else if (Dev0Map == Dev0Ptr->TxEdid)
    {
        i = DevPtr->TxEdid;
    }
    return (i);
}
