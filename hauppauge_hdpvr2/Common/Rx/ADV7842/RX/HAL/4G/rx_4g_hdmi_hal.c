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

#if ((RX_DEVICE == 7844) || (RX_DEVICE == 7842) \
    || (RX_DEVICE == 7623) || (RX_DEVICE == 7622) || (RX_DEVICE == 7850) || (RX_DEVICE == 76221))

#include "rx_isr.h"

#define TMDSFRAQ_SHIFT      0
#define GMD_VALID           ((LvlStatus2 | EdgStatus2) & LvlRaw2 & VRX_BIT_GAMUT_MDATA_ST)
#define GMD_NOT_REC         (LvlStatus2 & (~LvlRaw2) & VRX_BIT_GAMUT_MDATA_ST)
#define BAD_ES2_PKTS        (VRX_BIT_AUDIO_INFO_ST | VRX_BIT_SPD_INFO_ST   |  \
                             VRX_BIT_MS_INFO_ST    | VRX_BIT_ISRC1_PCKT_ST |  \
                             VRX_BIT_ISRC2_PCKT_ST | VRX_BIT_VS_INFO_ST)

CONSTANT UCHAR RxHdmiMaskRegs[] = 
{
    VRX_REG_HDMI_LVL_INT_MASKB_1,   VRX_REG_HDMI_LVL_INT2_MASKB_1, LVL_MASK_B1,
    VRX_REG_HDMI_LVL_INT_MASKB_2,   VRX_REG_HDMI_LVL_INT2_MASKB_2, LVL_MASK_B2,
    VRX_REG_HDMI_LVL_INT_MASKB_3,   VRX_REG_HDMI_LVL_INT2_MASKB_3, LVL_MASK_B3,
    VRX_REG_HDMI_LVL_INT_MASKB_4,   VRX_REG_HDMI_LVL_INT2_MASKB_4, LVL_MASK_B4,
    VRX_REG_HDMI_LVL_INT_MASKB_5,   VRX_REG_HDMI_LVL_INT2_MASKB_5, LVL_MASK_B5,
    VRX_REG_HDMI_EDG_INT_MASKB_1,   VRX_REG_HDMI_EDG_INT2_MASKB_1, EDG_MASK_B1,
    VRX_REG_HDMI_EDG_INT_MASKB_2,   VRX_REG_HDMI_EDG_INT2_MASKB_2, EDG_MASK_B2,
    VRX_REG_HDMI_EDG_INT_MASKB_3,   VRX_REG_HDMI_EDG_INT2_MASKB_3, EDG_MASK_B3,
    VRX_REG_HDMI_EDG_INT_MASKB_4,   VRX_REG_HDMI_EDG_INT2_MASKB_4, EDG_MASK_B4,
#if (RX_DEVICE !=7850)
    VRX_REG_CEC_STATUS1_INT1_MASKB, VRX_REG_CEC_STATUS1_INT2_MASKB, INT_MASK_B3,
#endif
    0, 0
};

/*==========================================
 * Local constants
 *=========================================*/
STATIC CONSTANT UCHAR IntBits[] = 
{
    VRX_BIT_TMDS_CLK_A_ST, VRX_BIT_TMDSPLL_LCK_A_ST, VRX_BIT_CABLE_DET_A_ST, VRX_BIT_HDMI_ENCRPT_A_ST, VRX_BIT_AKSV_UPDATE_A_ST,
    VRX_BIT_TMDS_CLK_B_ST, VRX_BIT_TMDSPLL_LCK_B_ST, VRX_BIT_CABLE_DET_B_ST, VRX_BIT_HDMI_ENCRPT_B_ST, VRX_BIT_AKSV_UPDATE_B_ST,
    VRX_BIT_TMDS_CLK_C_ST, VRX_BIT_TMDSPLL_LCK_C_ST, VRX_BIT_CABLE_DET_C_ST, VRX_BIT_HDMI_ENCRPT_C_ST, VRX_BIT_AKSV_UPDATE_C_ST,
    VRX_BIT_TMDS_CLK_D_ST, VRX_BIT_TMDSPLL_LCK_D_ST, VRX_BIT_CABLE_DET_D_ST, VRX_BIT_HDMI_ENCRPT_D_ST, VRX_BIT_AKSV_UPDATE_D_ST,
};

/*==========================================================================
 * Finds out all the active nad unmasked HDMI interrupts. It clears all the 
 * active interupts on return.
 *
 * Entry:   RxHdmiInts = is a BOOL array that contains status of all the HDMI
 *                      interrupts
 * 
 * Notes:  None
 *=========================================================================*/
void HAL_RxHdmiGetInterrupts (RX_HDMI_INTERRUPTS *HdmiInts)
{
    UCHAR i, Port, LvlRaw1, LvlRaw2, LvlRaw3, LvlRaw4;
    UCHAR LvlStatus1, LvlStatus2, LvlStatus3, LvlStatus4, LvlStatus5;
    UCHAR EdgStatus1, EdgStatus2, EdgStatus3, EdgStatus4;
    UCHAR PktValid, PktNotRec;
    UINT16 j;

    /*===================================================================
     * VRX_REG_HDMI_RAW_STATUS_1   0x60    RAW  status
     * VRX_REG_HDMI_INT_STATUS_1   0x61    INT  status
     * VRX_REG_HDMI_INT_CLEAR_1    0x62    INT  clear
     * VRX_REG_HDMI_INT2_MASKB_1   0x63    INT1 mask 
     * VRX_REG_HDMI_INT_MASKB_1    0x64    INT2 mask
     *
     * Raw = 1 -> New (or same) packet was received
     *       0 -> No packets were received after n vsync from last packet
     * Int = Raw bit changed state. This does not mean new packet is available
     * Clr = Clear Int bit
     * New = New packet arrived (different from last packet)
     *
     * A packet is thus valid when:
     *  - Packet is available (Raw == 1) AND
     *  - New packet OR Same packet resumed (New == 1 OR Int == 1)
     *
     * A packet is not received when:
     *  - Packet is not available (Raw == 0) AND
     *  - Packet has just changed status to not available (Int == 1)
     *
     * NOTE: Possible errors can result from the following scenario:
     *  1- Packet is not received, Raw bit=0 and Int bit=1
     *  2- S/W reads Raw and Int registers to local variables
     *  3- The packet is received again and the Int and Raw bit is now 1
     *  4- S/W clears the Int bit, but the Raw bit stored locally is still 0
     *  The Raw bit change from 0->1 interrupt is missed. The Raw bits thus
     *  must be read AFTER the interrupt is cleared. 
     *  Note however that for new packets edge interrupts, the raw status must
     *  be read BEFORE the interrupt is cleared, since clearing the interrupt 
     *  will also clear the Raw bit.
     *
     * Group 1 and 2 are always valid as long as TMDS clock is detected:
     *  - TMDS_CLK_x_ST       Group 1
     *  - INTERNAL_MUTE       Group 2
     *  - VIDEO_PLL_LOCK      Group 2
     *  - AKSV                Group 2
     *
     * Group 3 is all remaining interrupts and are valid if:
     *  - TMDS clock is detected      0x6A[4:2] = 1
     *  - Video PLL is locked         0x6A[6]   = 1
     *
     * In addition, the following interrupts are valid if 0x66[7] = 1
     *  - Audio channel mode        0x66[4]
     *  - Audio mode change         0x66[3]
     *  - New audio sampling rate   0x7A[3]
     *  
     *===================================================================*/

    HAL_I2CReadByte(VRX_IO_MAP_ADDR, VRX_REG_HDMI_LVL_INT_STATUS_1, &LvlStatus1);
    HAL_I2CReadByte(VRX_IO_MAP_ADDR, VRX_REG_HDMI_LVL_INT_STATUS_2, &LvlStatus2);
    HAL_I2CReadByte(VRX_IO_MAP_ADDR, VRX_REG_HDMI_LVL_INT_STATUS_3, &LvlStatus3);
    HAL_I2CReadByte(VRX_IO_MAP_ADDR, VRX_REG_HDMI_LVL_INT_STATUS_4, &LvlStatus4);
    HAL_I2CReadByte(VRX_IO_MAP_ADDR, VRX_REG_HDMI_LVL_INT_STATUS_5, &LvlStatus5);
    HAL_I2CReadByte(VRX_IO_MAP_ADDR, VRX_REG_HDMI_EDG_INT_STATUS_1, &EdgStatus1);
    HAL_I2CReadByte(VRX_IO_MAP_ADDR, VRX_REG_HDMI_EDG_INT_STATUS_2, &EdgStatus2);
    HAL_I2CReadByte(VRX_IO_MAP_ADDR, VRX_REG_HDMI_EDG_STATUS_3,     &EdgStatus3);
    HAL_I2CReadByte(VRX_IO_MAP_ADDR, VRX_REG_HDMI_EDG_STATUS_4,     &EdgStatus4);

    /*==================================================================
     * Acknowledge all interrupts immediately so we don't lose any
     * See note above for why LvlRawx is read after clearing
     * the LvStatusx interrupts, but not for EdgRawx
     *=================================================================*/
    HAL_I2CWriteByte(VRX_IO_MAP_ADDR, VRX_REG_HDMI_LVL_INT_CLR_1, LvlStatus1);
    HAL_I2CWriteByte(VRX_IO_MAP_ADDR, VRX_REG_HDMI_LVL_INT_CLR_2, LvlStatus2);
    HAL_I2CWriteByte(VRX_IO_MAP_ADDR, VRX_REG_HDMI_LVL_INT_CLR_3, LvlStatus3);
    HAL_I2CWriteByte(VRX_IO_MAP_ADDR, VRX_REG_HDMI_LVL_INT_CLR_4, LvlStatus4);
    HAL_I2CWriteByte(VRX_IO_MAP_ADDR, VRX_REG_HDMI_LVL_INT_CLR_5, LvlStatus5);

    HAL_I2CReadByte(VRX_IO_MAP_ADDR, VRX_REG_HDMI_LVL_RAW_STATUS_1, &LvlRaw1);
    HAL_I2CReadByte(VRX_IO_MAP_ADDR, VRX_REG_HDMI_LVL_RAW_STATUS_2, &LvlRaw2);
    HAL_I2CReadByte(VRX_IO_MAP_ADDR, VRX_REG_HDMI_LVL_RAW_STATUS_3, &LvlRaw3);
    HAL_I2CReadByte(VRX_IO_MAP_ADDR, VRX_REG_HDMI_LVL_RAW_STATUS_4, &LvlRaw4);

    HAL_I2CWriteByte(VRX_IO_MAP_ADDR, VRX_REG_HDMI_EDG_INT_CLR_1, EdgStatus1);
    HAL_I2CWriteByte(VRX_IO_MAP_ADDR, VRX_REG_HDMI_EDG_INT_CLR_2, EdgStatus2);
    HAL_I2CWriteByte(VRX_IO_MAP_ADDR, VRX_REG_HDMI_EDG_INT_CLR_3, EdgStatus3);
    HAL_I2CWriteByte(VRX_IO_MAP_ADDR, VRX_REG_HDMI_EDG_INT_CLR_4, EdgStatus4);

    Port = VRX_ret_HDMI_PORT_SELECT();
    j = 0;
    for (i=0; i<RX_NOF_PORTS; i++)
    {
        HdmiInts->TmdsClkChg[i] = (BOOL) (LvlStatus3 & IntBits[j]);
        HdmiInts->VidPllChg[i]  = (BOOL) (LvlStatus3 & IntBits[j+1]);
        HdmiInts->CableDetChg[i]= (BOOL) (LvlStatus4 & IntBits[j+2]);
        HdmiInts->EncChange[i]  = (BOOL) (LvlStatus4 & IntBits[j+3]);
        HdmiInts->AksvUpdate[i] = (BOOL) (EdgStatus4 & IntBits[j+4]);

        HdmiInts->TmdsClock[i]  = (BOOL) (LvlRaw3 & IntBits[j]);
        HdmiInts->VidPllLock[i] = (BOOL) (LvlRaw3 & IntBits[j+1]);
        HdmiInts->CableDetect[i]= (BOOL) (LvlRaw4 & IntBits[j+2]);
        HdmiInts->Encrypted[i]  = (BOOL) (LvlRaw4 & IntBits[j+3]);
        j+= 5;
    }
    
    HdmiInts->AudChanMode  = (BOOL) (LvlStatus2 & VRX_BIT_AUDIO_CH_MD_ST);
    HdmiInts->AvMute       = (BOOL) (LvlStatus2 & VRX_BIT_AV_MUTE_ST);
    HdmiInts->InternMute   = (BOOL) (LvlStatus2 & VRX_BIT_INTERNAL_MUTE_ST);
    HdmiInts->CsDataValid  = (BOOL) (LvlStatus2 & VRX_BIT_CS_DATA_VALID_ST);
    HdmiInts->HdmiModeChg  = (BOOL) (LvlStatus2 & VRX_BIT_HDMI_MODE_ST);

    HdmiInts->DeRegenLck   = (BOOL) (LvlStatus5 & VRX_BIT_DE_REGEN_LCK_ST);
    HdmiInts->VsyncLck     = (BOOL) (LvlStatus5 & VRX_BIT_V_LOCKED_ST);

    HdmiInts->NChange      = (BOOL) (EdgStatus2 & VRX_BIT_CHANGE_N_ST);
    HdmiInts->CtsThresh    = (BOOL) (EdgStatus2 & VRX_BIT_CTS_PASS_THRSH_ST);
    HdmiInts->AudFifoOv    = (BOOL) (EdgStatus2 & VRX_BIT_FIFO_OVERFLO_ST);
    HdmiInts->AudFifoUn    = (BOOL) (EdgStatus2 & VRX_BIT_FIFO_UNDERFLO_ST);
    HdmiInts->AudFifoNrOv  = (BOOL) (EdgStatus2 & VRX_BIT_FIFO_NEAR_OVFL_ST);

    HdmiInts->AudModeChg   = (BOOL) (EdgStatus3 & VRX_BIT_AUDIO_MODE_CHANGE_ST);
    HdmiInts->AudFifoNrUn  = (BOOL) (EdgStatus3 & VRX_BIT_FIFO_NEAR_UFLO_ST);
    HdmiInts->NewTmds      = (BOOL) (EdgStatus3 & VRX_BIT_NEW_TMDS_FRQ_ST);
    HdmiInts->AudFlatLine  = (BOOL) (EdgStatus3 & VRX_BIT_AUDIO_FLT_LINE_ST);
    HdmiInts->AudSampChg   = (BOOL) (EdgStatus3 & VRX_BIT_NEW_SAMP_RT_ST);
    HdmiInts->AudPrtyErr   = (BOOL) (EdgStatus3 & VRX_BIT_PARITY_ERROR_ST);
    HdmiInts->BadTmdsClk   = (BOOL) (EdgStatus3 & VRX_BIT_VCLK_CHNG_ST);
    HdmiInts->DeepClrChg   = (BOOL) (EdgStatus3 & VRX_BIT_DEEP_COLOR_CHNG_ST);

    /*=======================================================
     * Reset packet detection when mode changes to DVI
     *======================================================*/
    if (HdmiInts->HdmiModeChg && ((LvlRaw2 & VRX_BIT_HDMI_MODE_RAW) == 0))
    {
        ATV_I2CWriteField8 (VRX_HDMI_MAP_ADDR, 0x5A, 0x02, 1, 1);
    }

    {
        HdmiInts->CsValidRaw = (BOOL) (LvlRaw2 & VRX_BIT_CS_DATA_VALID_RAW);
        if (!HdmiInts->CsValidRaw)
        {
            HdmiInts->AudModeChg   = FALSE;
            HdmiInts->AudSampChg   = FALSE;
/*          HdmiInts->AudChanMode  = FALSE;     Valid Aud Ch Mode change event is missed because of this */
        }
    }

    /*============================================
     * Packet detection
     *===========================================*/
    PktValid = (LvlStatus1 | EdgStatus1) & LvlRaw1;
    PktNotRec = LvlStatus1 & (~LvlRaw1);

    HdmiInts->AvIfValid  = PktValid & VRX_BIT_AVI_INFO_ST;
    HdmiInts->AudIfValid = PktValid & VRX_BIT_AUDIO_INFO_ST;
    HdmiInts->SpdValid   = PktValid & VRX_BIT_SPD_INFO_ST;
    HdmiInts->MsValid    = PktValid & VRX_BIT_MS_INFO_ST;
    HdmiInts->VsValid    = PktValid & VRX_BIT_VS_INFO_ST;
    HdmiInts->AcpValid   = PktValid & VRX_BIT_ACP_PCKT_ST;
    HdmiInts->Isrc1Valid = PktValid & VRX_BIT_ISRC1_PCKT_ST;
    HdmiInts->Isrc2Valid = PktValid & VRX_BIT_ISRC2_PCKT_ST;
    HdmiInts->GamutValid = GMD_VALID & VRX_BIT_GAMUT_MDATA_ST;

    HdmiInts->AvIfNotRec = PktNotRec & VRX_BIT_AVI_INFO_ST;
    HdmiInts->AudIfNotRec= PktNotRec & VRX_BIT_AUDIO_INFO_ST;
    HdmiInts->SpdNotRec  = PktNotRec & VRX_BIT_SPD_INFO_ST;
    HdmiInts->MsNotRec   = PktNotRec & VRX_BIT_MS_INFO_ST;
    HdmiInts->VsNotRec   = PktNotRec & VRX_BIT_VS_INFO_ST;
    HdmiInts->AcpNotRec  = PktNotRec & VRX_BIT_ACP_PCKT_ST;
    HdmiInts->Isrc1NotRec= PktNotRec & VRX_BIT_ISRC1_PCKT_ST;
    HdmiInts->Isrc2NotRec= PktNotRec & VRX_BIT_ISRC2_PCKT_ST;
    HdmiInts->GamutNotRec= GMD_NOT_REC & VRX_BIT_GAMUT_MDATA_ST;

    /*=============================================
     * Workaround for deep color INT occasionally
     * not generated after plug-in
     *============================================*/
    if ((HdmiInts->TmdsClock[Port] && HdmiInts->VidPllLock[Port]) &&
        (HdmiInts->VidPllChg[Port] || HdmiInts->AvIfValid))
    {
        HdmiInts->DeepClrChg = TRUE;
    }

}

#if( RX_DEVICE !=7850)
/*==========================================================================
 * Finds out all the active nad unmasked CEC interrupts. It clears all the 
 * active interupts on return.
 *
 * Entry:  CecInts = BOOL array that contains status of all CEC interrupts
 * 
 * Notes:  None
 *
 *=========================================================================*/
void HAL_RxCecGetInterrupts (RX_CEC_INTS *CecInts)
{
    UCHAR CecStatus1;
#if (RX_DEVICE==7844)
    UCHAR CecBufTimeStamp1;
    UCHAR CecBufTimeStamp2;
    UCHAR CecBufTimeStamp3;
    UCHAR i;
#endif    	
    HAL_I2CReadByte(VRX_IO_MAP_ADDR, VRX_REG_CEC_STATUS1_INT_STATUS,&CecStatus1);
    HAL_I2CWriteByte(VRX_IO_MAP_ADDR, VRX_REG_CEC_STATUS1_INT_CLEAR, CecStatus1);

    CecInts->TxReady  = (BOOL) (CecStatus1 & VRX_BIT_CEC_TX_READY_ST);
    CecInts->RxReady  = (BOOL) (CecStatus1 & VRX_BIT_CEC_RX_RDY0_ST);
    CecInts->ArbLost  = (BOOL) (CecStatus1 & VRX_BIT_CEC_TX_ARBITRATION_LOST_ST);
    CecInts->Timeout  = (BOOL) (CecStatus1 & VRX_BIT_CEC_TX_RETRY_TIMEOUT_ST);
#if (RX_DEVICE==7844)
    /*======================================================
     * Force HPD/MSEN interrupts first time s/w starts
     *=====================================================*/
   
    for ( i = 0; i < CEC_TRIPLE_NUMBER; i++)
    {
        CecInts->RxFrameOrder[i] = 0;     
    }
    
    VRX_get_CEC_BUF0_TIMESTAMP(&CecBufTimeStamp1);
    VRX_get_CEC_BUF1_TIMESTAMP(&CecBufTimeStamp2);
    VRX_get_CEC_BUF2_TIMESTAMP(&CecBufTimeStamp3);
    
    CecInts->RxFrameOrder[0] = CecBufTimeStamp1;
    CecInts->RxFrameOrder[1] = CecBufTimeStamp2;
    CecInts->RxFrameOrder[2] = CecBufTimeStamp3;	
    
#endif                         
}
#endif
/*==========================================================================
 *
 * Return:  TRUE if Video PLL locked on currently selected port
 *
 *=========================================================================*/
BOOL HAL_RxVPllLocked (RX_HDMI_PORT Port)
{
    BOOL VpllLck = FALSE;
    
    if (Port == PORT_NONE)
    {
        Port = (RX_HDMI_PORT)VRX_ret_HDMI_PORT_SELECT();
    }
    switch (Port)
    {
        case PORT_A:
            VpllLck = VRX_ret_TMDSPLL_LCK_A_RAW();
            break;
        case PORT_B:
            VpllLck = VRX_ret_TMDSPLL_LCK_B_RAW();
            break;
        case PORT_C:
            VpllLck = VRX_ret_TMDSPLL_LCK_C_RAW();
            break;
        case PORT_D:
            VpllLck = VRX_ret_TMDSPLL_LCK_D_RAW();
            break;
        default:
            break;
    }
    return (VpllLck);
}

/*==========================================================================
 *
 * Return:  TRUE if Video PLL locked on currently selected port
 *
 *=========================================================================*/
BOOL HAL_RxEncrypted (RX_HDMI_PORT Port)
{
    BOOL Enc = FALSE;
    
    if (Port == PORT_NONE)
    {
        Port = (RX_HDMI_PORT)VRX_ret_HDMI_PORT_SELECT();
    }
    switch (Port)
    {
        case PORT_A:
            Enc = VRX_ret_HDMI_ENCRPT_A_RAW();
            break;
        case PORT_B:
            Enc = VRX_ret_HDMI_ENCRPT_B_RAW();
            break;
        case PORT_C:
            Enc = VRX_ret_HDMI_ENCRPT_C_RAW();
            break;
        case PORT_D:
            Enc = VRX_ret_HDMI_ENCRPT_D_RAW();
            break;
        default:
            break;
    }
    return (Enc);
}

/*==========================================================================
 *
 *
 *
 *=========================================================================*/
BOOL HAL_RxGetAksvUpdate (RX_HDMI_PORT Port)
{
    BOOL RetVal = FALSE;

    switch (Port)
    {
        case PORT_A:
            RetVal = VRX_ret_AKSV_UPDATE_A_RAW();
            break;
        case PORT_B:
            RetVal = VRX_ret_AKSV_UPDATE_B_RAW();
            break;
        case PORT_C:
            RetVal = VRX_ret_AKSV_UPDATE_C_RAW();
            break;
        case PORT_D:
            RetVal = VRX_ret_AKSV_UPDATE_D_RAW();
            break;
        default:
            break;
    }
    return (RetVal);
}

/*============================================================================
 * Set value for the HDCP BCAPS register
 *
 * Entry:   Port    = Port to set Bcaps for
 *          Bcaps   = BCAPS register value
 *
 * Return:  ATVERR_OK = Indicates the function completed successfully
 *
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR HAL_RxSetHdcpBcaps (RX_HDMI_PORT Port, UCHAR Bcaps)
{
    UCHAR i, j;

    if (RX_VALID_PORT(Port) || (Port == PORT_ALL))
    {
        i = j = RX_PORT_ID(Port);
        if (Port == PORT_ALL)
        {
            i = 0;
            j = RX_NOF_PORTS - 1;
        }

        for (; i<=j; i++)
        {
            VRX_set_HDCP_MAP_SELECT(i);
            VRX_set_BCAPS (Bcaps);
        }
        return (ATVERR_OK);
    }
    return (ATVERR_INV_PARM);
}

/*============================================================================
 * Set value for the HDCP BSTATUS register
 *
 * Entry:   Port    = Port to set Bstatus for
 *          Bstatus = BSTATUS register value
 *
 * Return:  ATVERR_OK = Indicates the function completed successfully
 *
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR HAL_RxSetHdcpBstatus (RX_HDMI_PORT Port, UINT16 Bstatus)
{
    UCHAR i, j;

    if (RX_VALID_PORT(Port) || (Port == PORT_ALL))
    {
        i = j = RX_PORT_ID(Port);
        if (Port == PORT_ALL)
        {
            i = 0;
            j = RX_NOF_PORTS - 1;
        }

        for (; i<=j; i++)
        {
            VRX_set_HDCP_MAP_SELECT(i);
            VRX_set_BSTATUS(Bstatus);
        }
        return (ATVERR_OK);
    }
    return (ATVERR_INV_PARM);
}


/*============================================================================
 * Enable/Disable HPD on specified port
 *
 * Entry:   Port   = Port to enable/disable its HPD
 *          Enable = TRUE/FALSE to enable/disable HPD
 *
 * Return:  ATVERR_OK = Indicates the function completed successfully
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR HAL_RxAssertHpd (RX_HDMI_PORT Port, BOOL Enable)
{
    UCHAR En;
    ATV_ERR RetVal = ATVERR_OK;

    En = Enable? 1: 0;
    VRX_set_HPD_MANUAL(1);

    switch (Port)
    {
        case PORT_A:
            VRX_set_HPA_MAN_VALUE_A(En);
            break;
        case PORT_B:
            VRX_set_HPA_MAN_VALUE_B(En);
            break;
        case PORT_C:
            VRX_set_HPA_MAN_VALUE_C(En);
            break;
        case PORT_D:
            VRX_set_HPA_MAN_VALUE_D(En);
            break;
        case PORT_ALL:
            VRX_set_HPA_MAN_VALUE_A(En);
            VRX_set_HPA_MAN_VALUE_B(En);
            VRX_set_HPA_MAN_VALUE_C(En);
            VRX_set_HPA_MAN_VALUE_D(En);
            break;
        default:
            RetVal = ATVERR_INV_PARM;
            break;
    }
    return (RetVal);
}

/*============================================================================
 * Enable/Disable HPD on specified port
 *
 * Entry:   Port   = Port to enable/disable its HPD
 *          Enable = TRUE/FALSE to enable/disable HPD
 *
 * Return:  ATVERR_OK = Indicates the function completed successfully
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR HAL_RxIsHpdOn (RX_HDMI_PORT Port, BOOL *HpdOn)
{
    BOOL IsOn;
    ATV_ERR RetVal = ATVERR_OK;

    switch (Port)
    {
        case PORT_A:
            IsOn = VRX_ret_HPA_STATUS_PORT_A();
            break;
        case PORT_B:
            IsOn = VRX_ret_HPA_STATUS_PORT_B();
            break;
        case PORT_C:
            IsOn = VRX_ret_HPA_STATUS_PORT_C();
            break;
        case PORT_D:
            IsOn = VRX_ret_HPA_STATUS_PORT_D();
            break;
        default:
            IsOn = FALSE;
            RetVal = ATVERR_INV_PARM;
            break;
    }
    if (HpdOn)
    {
        *HpdOn = IsOn;
    }
    if (RetVal == ATVERR_OK)
    {
        RetVal = IsOn? ATVERR_TRUE: ATVERR_FALSE;
    }
    return (RetVal);
}

/*===========================================================================
 *
 *
 *==========================================================================*/
void HAL_RxSetBksvListReadyBit (BOOL On)
{
    UCHAR i=0, Bcaps=0;

    VRX_set_KSV_LIST_READY(On? 1: 0);
    if (!On)
    {
        ATV_DUMMY_SET(i);
        ATV_DUMMY_SET(Bcaps);
        VRX_set_CLR_BCAPS_RDY_BITS(0xf);
    }
}

/*===========================================================================
 * Check if RX interrupt is pending
 *
 * Entry:   IntId = 1 or 2 for RX Interrupt1 or Interrupt2 lines
 *
 * Return:  TRUE  if interrupt is pending
 *          FALSE if no interrupt is pending
 *
 *==========================================================================*/
BOOL HAL_RxIntPending (UCHAR IntId)
{
    if (IntId == 1)
    {
        return (VRX_ret_INTRQ_RAW());
    }
    else
    {
        return (VRX_ret_INTRQ2_RAW());
    }
}

/*============================================================================
 *
 *
 * Entry:
 *
 * Return:
 *
 *===========================================================================*/
ATV_ERR HAL_RxHdmiReqBgMeas (RX_HDMI_PORT Port)
{
    if(RX_VALID_PORT(Port))
    {
        VRX_set_BG_MEAS_PORT_SEL(RX_PORT_ID(Port));
        VRX_set_BG_MEAS_REQ(1);
        return (ATVERR_OK);
    }
    return (ATVERR_INV_PARM);
}

/*============================================================================
 *
 *
 * Entry:
 *
 * Return:
 *
 *===========================================================================*/
ATV_ERR HAL_RxHdmiGetBgTmdsFreq (RX_HDMI_PORT Port, UINT16 * TmdsFreqMHz, UCHAR * TmdsFreqFrac)
{
    BOOL TmdsDetected;
    
    
    ADIAPI_RxHdmiTmdsDetected (Port, &TmdsDetected);
    if (TmdsDetected)
    {
        if((HAL_RxHdmiReqBgMeas(Port) == (ATVERR_OK)))
        {
            *TmdsFreqMHz = (UINT16)(VRX_ret_BG_TMDSFREQ());
            if(TmdsFreqFrac != NULL)
            {
                *TmdsFreqFrac = VRX_ret_BG_TMDSFREQ_FRAC() << TMDSFRAQ_SHIFT;
            }
            return (ATVERR_OK);
        }
    }
    return (ATVERR_FAILED);
}

/*============================================================================
 *
 *
 * Entry:
 *
 * Return:
 *
 *===========================================================================*/
ATV_ERR HAL_RxHdmiGetBgHsyncInfo (RX_HDMI_PORT Port, RX_HDMI_HSYNC * HsyncInfo)
{
    UINT16 HTotal, LineWid, PRValue;
    
    
    if((HAL_RxHdmiReqBgMeas(Port) == (ATVERR_OK)))
    {    
        if (VRX_ret_BG_MEAS_DONE_RAW())
        {
            VRX_get_BG_TOTAL_LINE_WIDTH (&HTotal);
            VRX_get_BG_LINE_WIDTH(&LineWid);
            HsyncInfo->FrontPorch = 0;
            HsyncInfo->SyncPulse = 0;
            HsyncInfo->BackPorch = 0;
    
            PRValue = (UINT16)VRX_ret_BG_PIX_REP() + 1;
            
            HsyncInfo->LinesTotal = (HTotal * PRValue);
            HsyncInfo->LinesActive = (LineWid * PRValue);
            return (ATVERR_OK);
        }
    }
    return (ATVERR_FAILED);
}

/*============================================================================
 *
 *
 * Entry:
 *
 * Return:
 *
 *===========================================================================*/
ATV_ERR HAL_RxHdmiGetBgVsyncInfo (RX_HDMI_PORT Port, RX_HDMI_VSYNC * VsyncInfo)
{
    UINT16 VTotal0, VTotal1;

    if((HAL_RxHdmiReqBgMeas(Port) == (ATVERR_OK)))
    {    
        if (VRX_ret_BG_MEAS_DONE_RAW())
        {
            VsyncInfo->FrontPorch = 0;
            VsyncInfo->SyncPulse = 0;
            VsyncInfo->BackPorch = 0;
            VRX_get_BG_TOTAL_FIELD_HEIGHT(&VTotal0);
            VRX_get_BG_FIELD_HEIGHT(&(VsyncInfo->LinesActive));
            VsyncInfo->Interlaced = ((VRX_is_BG_HDMI_INTERLACED_true())? TRUE : FALSE);
            if (VsyncInfo->Interlaced)
            {
                VsyncInfo->F1FrontPorch = 0;
                VsyncInfo->F1SyncPulse = 0;
                VsyncInfo->F1BackPorch = 0;
                VRX_get_BG_TOTAL_FIELD_HEIGHT(&(VsyncInfo->F1LinesActive));
                VRX_get_BG_TOTAL_FIELD_HEIGHT(&VTotal1);
                VsyncInfo->F1LinesTotal = (VTotal1 >> 1);
            }
            VsyncInfo->LinesTotal = (VTotal0 >> 1);
            return (ATVERR_OK);
        }
    }
    return (ATVERR_FAILED);
}

/*============================================================================
 *
 *
 * Entry:
 *
 * Return:
 *
 *===========================================================================*/
ATV_ERR HAL_RxHdmiGetBgDeepColorMode (RX_HDMI_PORT Port, RX_COLOR_DEPTH * DeepColorMode)
{ 
    UCHAR ColDepth;
    RX_COLOR_DEPTH CdTable[] = {RX_CD_24, RX_CD_30, RX_CD_36, RX_CD_48};


    if((HAL_RxHdmiReqBgMeas(Port) == (ATVERR_OK)))
    {
        if(VRX_ret_BG_MEAS_DONE_RAW())
        {
            VRX_get_BG_DEEP_COLOR_MODE(&ColDepth);
            if (ColDepth < 4)
            {
                *DeepColorMode = CdTable[ColDepth];
            }
            else
            {
                *DeepColorMode = RX_CD_24;
            }
            return (ATVERR_OK);
        }
    }
    return (ATVERR_FAILED);
}

/*============================================================================
 *
 *
 * Entry:
 *
 * Return:
 *
 *===========================================================================*/
ATV_ERR HAL_RxHdmiGetBgPixelRepeat (RX_HDMI_PORT Port, UCHAR * RepeatFactor)
{
    UCHAR RetVal;

    if((HAL_RxHdmiReqBgMeas(Port) == (ATVERR_OK)))
    {
        VRX_get_BG_PIX_REP(&RetVal);
        *RepeatFactor = RetVal + 1;
        return (ATVERR_OK);
    }
    return (ATVERR_FAILED);
}

#endif

#if (RX_DEVICE == 7623) || (RX_DEVICE == 7622) || (RX_DEVICE == 76221) || (RX_DEVICE == 7850)

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
            break;
        case PORT_B:
            VRX_set_EN_BG_PORT_B(En);
            break;
        case PORT_C:
            VRX_set_EN_BG_PORT_C(En);
            break;
        case PORT_D:
            VRX_set_EN_BG_PORT_D(En);
            break;
        case PORT_ALL:
            VRX_set_EN_BG_PORT_A(En);
            VRX_set_EN_BG_PORT_B(En);
            VRX_set_EN_BG_PORT_C(En);
            VRX_set_EN_BG_PORT_D(En);
            break;
        default:
            RetVal = ATVERR_INV_PARM;
            break;
    }
    return (RetVal);
}
#endif
