/**********************************************************************************************
*																						      *
* Copyright (c) 2012 Analog Devices, Inc.  All Rights Reserved.                               *
* This software is proprietary and confidential to Analog Devices, Inc. and its licensors.    *
*                                                                                             *
***********************************************************************************************/

#include "rx_lib.h"
#include "rx_isr.h"

#if RX_INCLUDE_CEC
#include "wrapper.h"
#endif

/*===================================
 * Local funtions prototypes
 *==================================*/
STATIC ATV_ERR RXLIB_HdmiIsr (void);
STATIC ATV_ERR RXLIB_CpIsr (void);

STATIC ATV_ERR RXLIB_SdpIsr (void);
STATIC ATV_ERR RXLIB_CecIsr (void);
STATIC ATV_ERR RXLIB_VdpIsr (void);
STATIC ATV_ERR RXLIB_MvIsr (void);
#if (RX_DEVICE == 7840)
STATIC ATV_ERR RXLIB_SdpVdpIsr (void);
#endif

/*=====================================
 * Local variables
 *====================================*/

/*=====================================
 * Shared variables
 *====================================*/

/*===========================================================================
 * Check if RX interrupt is pending
 *
 * Entry:   IntId = 1 or 2 for RX Interrupt1 or Interrupt2 lines
 *
 * Return:  ATVERR_TRUE  if interrupt is pending
 *          ATVERR_FALSE if no interrupt is pending
 *
 *==========================================================================*/
ATV_ERR ADIAPI_RxIntPending (UCHAR IntId)
{
#if IGNORE_INT_LINES
    return (HAL_RxIntPending(IntId)? ATVERR_TRUE: ATVERR_FALSE);
#else
    if (IntId == 1)
    {
        return (HAL_RxInt1Pending()? ATVERR_TRUE: ATVERR_FALSE);
    }
    else
    {
        return (HAL_RxInt2Pending()? ATVERR_TRUE: ATVERR_FALSE);
    }
#endif
}

/*==========================================================================
 * Process any pending RX interrupts
 *
 * Entry:   None
 *
 * Return:  ATVERR_OK       if interrupt detected, processing complete
 *          ATVERR_FAILED   if no interrupt detected
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxIsr (void)
{
    ATV_ERR HdmiRetVal;
    ATV_ERR CpRetVal;
    ATV_ERR VdpRetVal;
    ATV_ERR SdpRetVal;
    ATV_ERR CecRetVal;
    ATV_ERR MvRetVal;

#if (RX_DEVICE == 7840)
    switch(RxOperatingMode)
    {
        case RX_OPMODE_HDMI:
        case RX_OPMODE_COMP:
        case RX_OPMODE_GR:
        case RX_OPMODE_PWRDWN:
            HdmiRetVal = RXLIB_HdmiIsr();
            CpRetVal = RXLIB_CpIsr();
            VdpRetVal = RXLIB_VdpIsr();
            SdpRetVal = RXLIB_SdpIsr();
            MvRetVal  = RXLIB_MvIsr();
            CecRetVal = RXLIB_CecIsr();
            if((HdmiRetVal == (ATVERR_OK)) || (CpRetVal == (ATVERR_OK)) ||
               (VdpRetVal == (ATVERR_OK)) || (SdpRetVal==(ATVERR_OK)) ||
                (CecRetVal == (ATVERR_OK)))
            {
                return (ATVERR_OK);
            }
            else
            {
                return (ATVERR_FALSE);
            }            
            break;
        case RX_OPMODE_SDP_COMP:
        case RX_OPMODE_SDP_CVBS:
        case RX_OPMODE_SDP_CVBS_HDMI_MON:
        case RX_OPMODE_SDP_CVBS_YC_AUTO:
        case RX_OPMODE_SDP_YC:
        case RX_OPMODE_SDP_SCART:
            VdpRetVal = RXLIB_SdpVdpIsr();  
            if(VdpRetVal == (ATVERR_OK))
            {
                return (ATVERR_OK);
            }
            else
            {
                return (ATVERR_FALSE);
            }
            break;
        default:
           return (ATVERR_FALSE);         
    }
#else  
    HdmiRetVal = RXLIB_HdmiIsr();
    CpRetVal = RXLIB_CpIsr();
    VdpRetVal = RXLIB_VdpIsr();
    SdpRetVal = RXLIB_SdpIsr();
    MvRetVal  = RXLIB_MvIsr();
    CecRetVal = RXLIB_CecIsr();
    if((HdmiRetVal == (ATVERR_OK)) || (CpRetVal == (ATVERR_OK)) ||
       (VdpRetVal == (ATVERR_OK)) || (SdpRetVal==(ATVERR_OK)) ||
       (CecRetVal == (ATVERR_OK))||(MvRetVal == (ATVERR_OK)))
    {
        return (ATVERR_OK);
    }
    else
    {
        return (ATVERR_FALSE);
    }
#endif
}

/*==========================================================================
 * Process any pending HDMI interrupts
 *
 * Entry:   None
 *
 * Return:  ATVERR_OK       if interrupt detected, processing complete
 *          ATVERR_FAILED   if no interrupt detected
 *
 * Notes:
 *
 *=========================================================================*/
STATIC ATV_ERR RXLIB_HdmiIsr (void)
{
    RX_HDMI_INTERRUPTS HdmiInts;
    UCHAR i, ByteX, ActvPort, PktBuf[MAX_HDMI_PACKET_SIZE];
    RX_AUDIO_TYPE AudType;
    RX_DST_MODE DstType;
    UINT32 NValue, CtsValue;
    BOOL CsumErr, MultiChan;
    ATV_ERR RetVal = ATVERR_FAILED;

    /*=======================================
     * Get asserted interrupts
     *======================================*/
    memset (&HdmiInts, 0, sizeof(RX_HDMI_INTERRUPTS));
    HAL_RxHdmiGetInterrupts (&HdmiInts);
    ActvPort = VRX_ret_HDMI_PORT_SELECT();

    /*==================================================
     * TMDS clock detection state change
     *=================================================*/
    for (i=0; i<RX_NOF_PORTS; i++)
    {
        if (HdmiInts.TmdsClkChg[i])
        {
            ByteX = HdmiInts.TmdsClock[i];
            RX_NOTIFY_USER(RX_EVENT_HDMI_TMDS_CLK_CHNG, (UINT16)i, &ByteX);
            RetVal = ATVERR_OK;
        } 
    }

    /*==================================================
     * Cable detection state change
     *=================================================*/
    for (i=0; i<RX_NOF_PORTS; i++)
    {
        if (HdmiInts.CableDetChg[i])
        {
            ByteX = HdmiInts.CableDetect[i];
            RX_NOTIFY_USER(RX_EVENT_HDMI_CABLE_DETECT, (UINT16)i, &ByteX);
            RetVal = ATVERR_OK;
        } 
    }

    /*=========================================================
     * AKSV ready interrupt is always valid. For fast 
     * switching, the second parameter carries port number
     *========================================================*/
    for (i=0; i<RX_NOF_PORTS; i++)
    {
        if (HdmiInts.AksvUpdate[i])
        {
            RX_NOTIFY_USER(RX_EVENT_HDMI_AKSV_UPDATE, (UINT16)i, NULL);
            RetVal = ATVERR_OK;
        }
    }

    /*==================================================
     * Internal mute is always valid
     *=================================================*/
    if (HdmiInts.InternMute)
    {
        ByteX = VRX_is_INTERNAL_MUTE_RAW_true();
        RX_NOTIFY_USER(RX_EVENT_HDMI_INTERNAL_MUTE, 0, &ByteX);
        RetVal = ATVERR_OK;
    }

    /*==================================================
     * Video PLL Lock changed status
     *=================================================*/
    for (i=0; i<RX_NOF_PORTS; i++)
    {
        if (HdmiInts.VidPllChg[i])
        {
            /*==================================================
             * VPLL unlock is always valid
             * VPLL locked is valid ONLY if TMDS is on
             *=================================================*/
            if ((HdmiInts.VidPllLock[i] == 0) || HdmiInts.TmdsClock[i])
            {
                ByteX = HdmiInts.VidPllLock[i];
                RX_NOTIFY_USER(RX_EVENT_HDMI_VIDEO_PLL_LCK, (UINT16)i, &ByteX);
                RetVal = ATVERR_OK;
            }
            /*==================================================
             * Send AV MUTE state when PLL is locked
             *=================================================*/
            if ((i == ActvPort) && HdmiInts.TmdsClock[i] && HdmiInts.VidPllLock[i])
            { 
                ByteX = VRX_is_AV_MUTE_RAW_true();
                RX_NOTIFY_USER(RX_EVENT_HDMI_AV_MUTE, 0, &ByteX);
                RetVal = ATVERR_OK;
            }
        }
    }

    /*========================================
     * Clear last received pkt times
     *=======================================*/
    if ((HdmiInts.VidPllChg[ActvPort] && (HdmiInts.VidPllLock[ActvPort] == 0)) 
        ||
        (HdmiInts.TmdsClkChg[ActvPort] && (HdmiInts.TmdsClock[ActvPort] == 0)))
    {
        HAL_RxPktDetectWorkaround((RX_PACKET_TYPE)0xff);
    }

    /*===============================================
     * DE regen lock
     *==============================================*/
    if (HdmiInts.DeRegenLck)
    {
        ByteX = VRX_is_DE_REGEN_LCK_RAW_true();
        RX_NOTIFY_USER (RX_EVENT_HDMI_DE_REGEN_LCK, 0, &ByteX);
        RetVal = ATVERR_OK;
    }

    /*===============================================
     * Vsync lock
     *==============================================*/
    if (HdmiInts.VsyncLck)
    {
        ByteX = VRX_is_V_LOCKED_RAW_true();
        RX_NOTIFY_USER (RX_EVENT_HDMI_V_LOCKED, 0, &ByteX);
        RetVal = ATVERR_OK;
    }

    /*==================================================
     * Encryption change
     *=================================================*/
    for (i=0; i<RX_NOF_PORTS; i++)
    {
        if (HdmiInts.TmdsClock[i] && HdmiInts.VidPllLock[i])
        {
            if (HdmiInts.EncChange[i])
            {
                ByteX = HdmiInts.Encrypted[i];
                if (ByteX)
                {
                    EncState |= (1 << i);
                }
                RX_NOTIFY_USER(RX_EVENT_HDMI_ENC_CHNG, (UINT16)i, &ByteX);
                RetVal = ATVERR_OK;
            }
        } 
        else
        {
            if (EncState & (1 << i))
            {
                EncState &= ~(1 << i);
                ByteX = 0;
                RX_NOTIFY_USER(RX_EVENT_HDMI_ENC_CHNG, (UINT16)i, &ByteX);
            }
        }
    }

    /*========================================================
     * All interrupts following this point are invalid if
     * TMDS clock is not detected OR Video PLL is not locked
     *=======================================================*/
    if ((!HdmiInts.TmdsClock[ActvPort]) || (!HdmiInts.VidPllLock[ActvPort]))
    {
        /*=====================================================
         * Record interrupts that occurs during VPLL unlock
         *====================================================*/
        StickyGroup3Ints |= HdmiInts.HdmiModeChg?   1: 0;
        StickyGroup3Ints |= HdmiInts.DeepClrChg?    2: 0;
        StickyGroup3Ints |= HdmiInts.AudChanMode?   4: 0;
        return (ATVERR_OK);
    }
    else if (StickyGroup3Ints)
    {
        /*==============================================================
         * Restore interrupts that occured during TMDS off/VPLL unlock
         *=============================================================*/
        HdmiInts.HdmiModeChg |= (BOOL)(StickyGroup3Ints & 1);
        HdmiInts.DeepClrChg  |= (BOOL)(StickyGroup3Ints & 2);
        HdmiInts.AudChanMode |= (BOOL)(StickyGroup3Ints & 4);
        StickyGroup3Ints = 0;
        RetVal = ATVERR_OK;
    }
    
    /*==================================================
     * AV info frame
     *=================================================*/
    if (HdmiInts.AvIfValid)
    {
        ADIAPI_RxHdmiGetPacket (AVI_INFO_PACKET, PktBuf, &CsumErr);
        RX_NOTIFY_USER(RX_EVENT_HDMI_AVI_INFO, CsumErr? 1: 0, PktBuf);
        RetVal = ATVERR_OK;
        HAL_RxPktDetectWorkaround(AVI_INFO_PACKET);
    }

    if (HdmiInts.AvIfNotRec)
    {
        ByteX = (UCHAR)AVI_INFO_PACKET;
        RX_NOTIFY_USER(RX_EVENT_HDMI_NO_PACKET, 0, &ByteX);
        RetVal = ATVERR_OK;
    }

    /*==================================================
     * Audio info frame
     *=================================================*/
    if (HdmiInts.AudIfValid)
    {
        ADIAPI_RxHdmiGetPacket (AUDIO_INFO_PACKET, PktBuf, &CsumErr);
        RX_NOTIFY_USER(RX_EVENT_HDMI_AUDIO_INFO, CsumErr? 1: 0, PktBuf);
        RetVal = ATVERR_OK;
        HAL_RxPktDetectWorkaround(AUDIO_INFO_PACKET);
    }

    if (HdmiInts.AudIfNotRec)
    {
        ByteX = (UCHAR)AUDIO_INFO_PACKET;
        RX_NOTIFY_USER(RX_EVENT_HDMI_NO_PACKET, 0, &ByteX);
        RetVal = ATVERR_OK;
    }

    /*==================================================
     * ACP packet
     *=================================================*/
    if (HdmiInts.AcpValid)
    {
        ADIAPI_RxHdmiGetPacket (ACP_PACKET, PktBuf, &CsumErr);
        RX_NOTIFY_USER(RX_EVENT_HDMI_ACP_PCKT, CsumErr? 1: 0, PktBuf);
        RetVal = ATVERR_OK;
        HAL_RxPktDetectWorkaround(ACP_PACKET);
    }
    
    if (HdmiInts.AcpNotRec)
    {
        ByteX = (UCHAR)ACP_PACKET;
        RX_NOTIFY_USER(RX_EVENT_HDMI_NO_PACKET, 0, &ByteX);
        RetVal = ATVERR_OK;
    }

    /*==================================================
     * SPD packet
     *=================================================*/
    if (HdmiInts.SpdValid)
    {
        ADIAPI_RxHdmiGetPacket (SPD_INFO_PACKET, PktBuf, &CsumErr);
        RX_NOTIFY_USER(RX_EVENT_HDMI_SPD_INFO, CsumErr? 1: 0, PktBuf);
        RetVal = ATVERR_OK;
        HAL_RxPktDetectWorkaround(SPD_INFO_PACKET);
    }

    if (HdmiInts.SpdNotRec)
    {
        ByteX = (UCHAR)SPD_INFO_PACKET;
        RX_NOTIFY_USER(RX_EVENT_HDMI_NO_PACKET, 0, &ByteX);
        RetVal = ATVERR_OK;
    }

    /*==================================================
     * ISRC1 and ISRC2 packets
     *=================================================*/
    if (HdmiInts.Isrc1Valid)
    {
        ADIAPI_RxHdmiGetPacket (ISRC1_PACKET, PktBuf, &CsumErr);
        RX_NOTIFY_USER(RX_EVENT_HDMI_ISRC1_PCKT, CsumErr? 1: 0, PktBuf);
        RetVal = ATVERR_OK;
        HAL_RxPktDetectWorkaround(ISRC1_PACKET);
    }

    if (HdmiInts.Isrc1NotRec)
    {
        ByteX = (UCHAR)ISRC1_PACKET;
        RX_NOTIFY_USER(RX_EVENT_HDMI_NO_PACKET, 0, &ByteX);
        RetVal = ATVERR_OK;
    }

    if (HdmiInts.Isrc2Valid)
    {
        ADIAPI_RxHdmiGetPacket (ISRC2_PACKET, PktBuf, &CsumErr);
        RX_NOTIFY_USER(RX_EVENT_HDMI_ISRC2_PCKT, CsumErr? 1: 0, PktBuf);
        RetVal = ATVERR_OK;
        HAL_RxPktDetectWorkaround(ISRC2_PACKET);
    }

    if (HdmiInts.Isrc2NotRec)
    {
        ByteX = (UCHAR)ISRC2_PACKET;
        RX_NOTIFY_USER(RX_EVENT_HDMI_NO_PACKET, 0, &ByteX);
        RetVal = ATVERR_OK;
    }

    /*==================================================
     * GMD packet
     *=================================================*/
    if (HdmiInts.GamutValid)
    {
        ADIAPI_RxHdmiGetPacket (GAMUT_PACKET, PktBuf, &CsumErr);
        RX_NOTIFY_USER(RX_EVENT_HDMI_GAMUT_PCKT, CsumErr? 1: 0, PktBuf);
        RetVal = ATVERR_OK;
        HAL_RxPktDetectWorkaround(GAMUT_PACKET);
    }
    
    if (HdmiInts.GamutNotRec)
    {
        ByteX = (UCHAR)GAMUT_PACKET;
        RX_NOTIFY_USER(RX_EVENT_HDMI_NO_PACKET, 0, &ByteX);
        RetVal = ATVERR_OK;
    }

    /*==================================================
     * MPEG info frame
     *=================================================*/
    if (HdmiInts.MsValid)
    {
        ADIAPI_RxHdmiGetPacket (MPEG_INFO_PACKET, PktBuf, &CsumErr);
        RX_NOTIFY_USER(RX_EVENT_HDMI_MS_INFO, CsumErr? 1: 0, PktBuf);
        RetVal = ATVERR_OK;
        HAL_RxPktDetectWorkaround(MPEG_INFO_PACKET);
    }

    if (HdmiInts.MsNotRec)
    {
        ByteX = (UCHAR)MPEG_INFO_PACKET;
        RX_NOTIFY_USER(RX_EVENT_HDMI_NO_PACKET, 0, &ByteX);
        RetVal = ATVERR_OK;
    }

    /*==================================================
     * VS info frame
     *=================================================*/
    if (HdmiInts.VsValid)
    {
        ADIAPI_RxHdmiGetPacket (VS_INFO_PACKET, PktBuf, &CsumErr);
        RX_NOTIFY_USER(RX_EVENT_HDMI_VS_INFO, CsumErr? 1: 0, PktBuf);
        RetVal = ATVERR_OK;
        HAL_RxPktDetectWorkaround(VS_INFO_PACKET);
    }

    if (HdmiInts.VsNotRec)
    {
        ByteX = (UCHAR)VS_INFO_PACKET;
        RX_NOTIFY_USER(RX_EVENT_HDMI_NO_PACKET, 0, &ByteX);
        RetVal = ATVERR_OK;
    }

    /*==================================================
     * HDMI/DVI mode change
     *=================================================*/
    if (HdmiInts.HdmiModeChg)
    {
        ByteX = VRX_is_HDMI_MODE_true();
        RX_NOTIFY_USER(RX_EVENT_HDMI_MODE_CHNG, 0, &ByteX);
        RetVal = ATVERR_OK;
    } 

    /*===============================================
     * Deep Color change int
     *==============================================*/
    if (HdmiInts.DeepClrChg)
    {
        VRX_get_DEEP_COLOR_MODE(&ByteX);
        if (ByteX < 3)
        {
            ByteX = (ByteX<<1) + 8;
        }
        else if (ByteX == 3)
        {
            ByteX = 16;
        }
        RX_NOTIFY_USER(RX_EVENT_HDMI_DEEP_COLOR_CHNG, 0, &ByteX);
        RetVal = ATVERR_OK;
    }

    /*==================================================
     * CTS interrupt
     *=================================================*/
/*mbw if (HdmiInts.CtsPassint)
 *    {
 *        VRX_set_AUDIO_PLL_RESET(1);
 *        RxEvents.Ready = TRUE;
 *    }
 */
    /*==================================================
     * N changed
     *=================================================*/
    if (HdmiInts.NChange)
    {
        for (ByteX=0; ByteX<3; ByteX++)
        {
            if (ADIAPI_RxHdmiGetAcrInfo (&NValue, &CtsValue) == ATVERR_OK)
            {
                break;
            }
            else
            {
                NValue = CtsValue = 0;
            }
        }
        CurrNVal = NValue;
        RX_NOTIFY_USER(RX_EVENT_HDMI_N_CHNG, 0, &NValue);
        RetVal = ATVERR_OK;
    }

    /*==================================================
     * Av Mute
     *=================================================*/
    if (HdmiInts.AvMute)
    {
        ByteX = VRX_is_AV_MUTE_RAW_true();
        RX_NOTIFY_USER(RX_EVENT_HDMI_AV_MUTE, 0, &ByteX);
        RetVal = ATVERR_OK;
    } 

    /*==================================================
     * Channel status data valid changed
     * This interrupt is not triggered for HBR audio
     * and the CS bits are always invalid for HBR
     *=================================================*/
    if (HdmiInts.CsDataValid)
    {
        if (ADIAPI_RxHdmiGetAudioChanStatus(PktBuf) == ATVERR_OK)
		{
            for (i=0; i<CH_STAT_SIZE; i++)
			{
                CurrCs[i] = PktBuf[i];
			}
            RX_NOTIFY_USER (RX_EVENT_HDMI_CS_DATA_VALID, 
                              HdmiInts.CsValidRaw? 1: 0, PktBuf);
            RetVal = ATVERR_OK;
		}
    }

    /*==================================================
     * Audio mode change.
     * This interrupt does not always trigger and the 
     * audio mode must be polled by the application
     *=================================================*/
    if (HdmiInts.AudModeChg)
    {
        ADIAPI_RxHdmiGetAudioType (&AudType);
        ADIAPI_RxHdmiGetDstMode (&DstType);
        CurrAudMode = AudType;
        RX_NOTIFY_USER (RX_EVENT_HDMI_AUDIO_MODE_CHNG, 
                            DstType == RX_DST_SDR ? 1: 0, &AudType);
        RetVal = ATVERR_OK;
    } 

    /*==================================================
     * Audio channel mode
     *=================================================*/
    if (HdmiInts.AudChanMode)
    {
        ADIAPI_RxHdmiGetAudioChanCount (&MultiChan);
        RX_NOTIFY_USER (RX_EVENT_HDMI_AUDIO_CH_MODE_CHNG, 0, &MultiChan);
        RetVal = ATVERR_OK;
    } 

    /*===============================================
     * Audio sampling rate change int
     *==============================================*/
    if (HdmiInts.AudSampChg)
    {
        RX_NOTIFY_USER (RX_EVENT_HDMI_NEW_SAMP_RT, 0, NULL);
        RetVal = ATVERR_OK;
    }

    /*===============================================
     * Audio FIFO change int
     *==============================================*/
    if (HdmiInts.AudFifoOv)
    {
        RX_NOTIFY_USER (RX_EVENT_HDMI_FIFO_OVERFLO, HdmiInts.AudFifoOv? 1: 0, NULL);
        RetVal = ATVERR_OK;
    }
    if (HdmiInts.AudFifoUn)
    {
        RX_NOTIFY_USER (RX_EVENT_HDMI_FIFO_UNDERFLO, HdmiInts.AudFifoUn? 1: 0, NULL);
        RetVal = ATVERR_OK;
    }
    if (HdmiInts.AudFifoNrOv)
    {
        RX_NOTIFY_USER (RX_EVENT_HDMI_FIFO_NEAROVFL, HdmiInts.AudFifoNrOv? 1: 0, NULL);
        RetVal = ATVERR_OK;
    }
    if (HdmiInts.AudFifoNrUn)
    {
        RX_NOTIFY_USER (RX_EVENT_HDMI_FIFO_NEARUFLO, HdmiInts.AudFifoNrUn? 1: 0, NULL);
        RetVal = ATVERR_OK;
    }
    return (RetVal);
}

/*==========================================================================
 * Process any pending CEC interrupts
 *
 * Entry:   None
 *
 * Return:  ATVERR_OK       if interrupt detected, processing complete
 *          ATVERR_FAILED   if no interrupt detected
 *
 * Notes:
 *
 *=========================================================================*/
STATIC ATV_ERR RXLIB_CecIsr (void)
{
#if RX_INCLUDE_CEC
    CEC_INTERRUPTS CecInts;
    RX_CEC_INTS CecInterrupts;
    UCHAR i;
    /*=======================================
     * Get asserted interrupts
     *======================================*/
    HAL_RxCecGetInterrupts (&CecInterrupts);

    CecInts.TxReady = CecInterrupts.TxReady;
    CecInts.RxReady = CecInterrupts.RxReady;
    CecInts.ArbLost = CecInterrupts.ArbLost;
    CecInts.Timeout = CecInterrupts.Timeout;
#if (RX_DEVICE==7844)    
    CecInts.RxReady1 = CecInterrupts.RxReady1;
    CecInts.RxReady2 = CecInterrupts.RxReady2;
    CecInts.RxReady3 = CecInterrupts.RxReady3;
#endif
    
    for ( i = 0; i < CEC_TRIPLE_NUMBER ;i++)
    {
        CecInts.RxFrameOrder[i] = CecInterrupts.RxFrameOrder[i];
    }        
    CEC_Isr(&CecInts);
    return (ATVERR_OK);
#else
    return (ATVERR_FAILED);
#endif
}

/*==========================================================================
 * Process any pending CP interrupts
 *
 * Entry:   None
 *
 * Return:  ATVERR_OK       if interrupt detected, processing complete
 *          ATVERR_FAILED   if no interrupt detected
 *
 * Notes:
 *
 *=========================================================================*/
STATIC ATV_ERR RXLIB_CpIsr (void)
{
    RX_CP_INTERRUPTS CpInts;
    UINT8 ByteX;
    ATV_ERR RetVal = ATVERR_FAILED;
    BOOL StdiLock;
    BOOL SspdLock;
    RX_SYNC_CH SyncCh;
    
        
        
    /*=======================================
     * Get asserted interrupts
     *======================================*/
    HAL_RxCpGetInterrupts (&CpInts);
    
    /*==================================================
     * CP lock change
     *=================================================*/
    if (CpInts.CpLckChng)
    {
        ByteX = (UINT8)(VRX_is_CP_LOCK_RAW_true());
        RX_NOTIFY_USER(RX_EVENT_CP_LCK, 0, &ByteX);
        RetVal = ATVERR_OK;
    }
    /*==================================================
     * STDI change
     *=================================================*/
    if (CpInts.StdiLckChng)
    {
        ADIAPI_RxCpGetMainSyncCh (&SyncCh);
        ADIAPI_RxCpGetSspdStatus (&SspdLock, SyncCh);
        ADIAPI_RxCpGetStdiStatus (&StdiLock, SyncCh);
        ByteX = ((SspdLock && StdiLock) ? 1:0);
        RX_NOTIFY_USER(RX_EVENT_CP_STDI_LCK, 0, &ByteX);
        RetVal = ATVERR_OK;
    }
    /*==================================================
     * CP lock change for sync channel 1
     *=================================================*/
    if (CpInts.CpCh1LckChng)
    {
        ByteX = VRX_is_CP_UNLOCK_CH1_RAW_true()? 0: 1;
        RX_NOTIFY_USER(RX_EVENT_CP_LCK_SYNC_CH1, 0, &ByteX);
        RetVal = ATVERR_OK;
    }
    /*==================================================
     * STDI change for sync channel 1
     *=================================================*/
    if (CpInts.StdiCh1LckChng)
    {
        ADIAPI_RxCpGetSspdStatus (&SspdLock, RX_SYNC_CH1);
        ADIAPI_RxCpGetStdiStatus (&StdiLock, RX_SYNC_CH1);
        ByteX = (UINT8) (SspdLock & StdiLock);
        RX_NOTIFY_USER(RX_EVENT_CP_STDI_LCK_SYNC_CH1, 0, &ByteX);
        RetVal = ATVERR_OK;
    }
    /*==================================================
     * CP lock change for sync channel 2
     *=================================================*/
    if (CpInts.CpCh2LckChng)
    {
        ByteX = VRX_is_CP_UNLOCK_CH2_RAW_true()? 0: 1;
        RX_NOTIFY_USER(RX_EVENT_CP_LCK_SYNC_CH2, 0, &ByteX);
        RetVal = ATVERR_OK;
    }
    /*==================================================
     * STDI change for sync channel 2
     *=================================================*/
    if (CpInts.StdiCh2LckChng)
    {
        ADIAPI_RxCpGetSspdStatus (&SspdLock, RX_SYNC_CH2);
        ADIAPI_RxCpGetStdiStatus (&StdiLock, RX_SYNC_CH2);
        ByteX = ((SspdLock && StdiLock) ? 1:0);
        RX_NOTIFY_USER(RX_EVENT_CP_STDI_LCK_SYNC_CH2, 0, &ByteX);
        RetVal = ATVERR_OK;
    }

    return (RetVal);
}

/*==========================================================================
 * Process any pending VDP interrupts
 *
 * Entry:   None
 *
 * Return:  ATVERR_OK       if interrupt detected, processing complete
 *          ATVERR_FAILED   if no interrupt detected
 *
 * Notes:
 *
 *=========================================================================*/
STATIC ATV_ERR RXLIB_VdpIsr (void)
{
    return (HAL_RXLIB_VdpIsr());
}

/*==========================================================================
 * Process any pending SDP interrupts
 *
 * Entry:   None
 *
 * Return:  ATVERR_OK       if interrupt detected, processing complete
 *          ATVERR_FAILED   if no interrupt detected
 *
 * Notes:
 *
 *=========================================================================*/
STATIC ATV_ERR RXLIB_SdpIsr (void)
{
    return (HAL_RXLIB_SdpIsr());
}

STATIC ATV_ERR RXLIB_MvIsr (void)
{
	return (HAL_RXLIB_MvIsr());
}

#if (RX_DEVICE == 7840)
/*==========================================================================
 * Process any pending SDP VDP interrupts
 *
 * Entry:   None
 *
 * Return:  ATVERR_OK       if interrupt detected, processing complete
 *          ATVERR_FAILED   if no interrupt detected
 *
 * Notes:
 *
 *=========================================================================*/
STATIC ATV_ERR RXLIB_SdpVdpIsr (void)
{
    return (HAL_RXLIB_SdpVdpIsr());
}
#endif

