/**********************************************************************************************
*																						      *
* Copyright (c) 2012 Analog Devices, Inc.  All Rights Reserved.                               *
* This software is proprietary and confidential to Analog Devices, Inc. and its licensors.    *
*                                                                                             *
***********************************************************************************************/

#include "rx_lib.h"

#if RX_INCLUDE_CEC
#include "rx_isr.h"
#include "wrapper.h"
/*============================================================================
 * Set the device to be used for CEC processing. Only one CEC engine can be
 * active at any given time
 * 
 * Entry:   DevIndex = Device Index to be used for CEC processing
 * 
 * Return:  ATVERR_OK
 * 
 *===========================================================================*/
ATV_ERR ADIAPI_RxCecSetActiveDevice (UCHAR DevIndex)
{
    ATV_ERR RetVal = ATVERR_INV_PARM;

    if (DevIndex < RX_NUM_OF_DEVICES)
    {
        if  (DevIndex != RxActiveCecIdx)
        {
            /*======================================
             * Disable active CEC controller
             *=====================================*/
            ADIAPI_RxCecEnable(FALSE);

            /*======================================
             * Set new active CEC controller
             *=====================================*/
            RxActiveCecIdx = DevIndex;
            ADIAPI_RxCecEnable(TRUE);
        }
        RetVal = ATVERR_OK;
    }
    return (RetVal);
}

/*============================================================================
 * Reset CEC controller
 * 
 * Entry:   None
 * 
 * Return:  ATVERR_OK
 * 
 *===========================================================================*/
ATV_ERR ADIAPI_RxCecReset (void)
{
/*    RXREG_SET_ACTIVE_CEC_MAP(VRX_ACTIVE_CEC_MAP); */
    CEC_Reset();
/*    RXREG_SET_ACTIVE_CEC_MAP(VRX_ACTIVE_CEC_MAP); */
    return (ATVERR_OK);
}

/*============================================================================
 * Enable/Disable CEC controller
 * 
 * Entry:   Enable = TRUE to enable CEC controller
 *                   FALSE to disable
 * 
 * Return:  ATVERR_OK
 * 
 *===========================================================================*/
ATV_ERR ADIAPI_RxCecEnable (BOOL Enable)
{
/*    RXREG_SET_ACTIVE_CEC_MAP(VRX_ACTIVE_CEC_MAP); */
/*    RXREG_SET_ACTIVE_CEC_PD(Enable? 0 : 1); */
    CEC_Enable(Enable);
    return (ATVERR_OK);
}

/*============================================================================
 * Set the logical address for one of 3 logical devices
 * 
 * Entry:   LogAddr = Logical address for the device
 *          DevId   = The device to set the logical address to. (0, 1 or 2)
 *          Enable  = TRUE to enable the logical device
 *                    FALSE to disable the logical device
 * 
 * Return:  ATVERR_OK
 *          ATVERR_INV_PARM if DevId is larger than 2
 * 
 *===========================================================================*/
ATV_ERR ADIAPI_RxCecSetLogicalAddr (UCHAR LogAddr, UCHAR DevId, BOOL Enable)
{
    return (CEC_SetLogicalAddr(LogAddr, DevId, Enable));
}

/*============================================================================
 * Send message to CEC
 * 
 * Entry:   MsgPtr = Pointer to the message to be sent
 *          MsgLen
 * 
 * Return:  ATVERR_OK
 *          ATVERR_FAILED if CEC controller is busy
 *          ATVERR_INV_PARM if MsgLen is larger than max message size
 * 
 *===========================================================================*/
ATV_ERR ADIAPI_RxCecSendMessage (UCHAR *MsgPtr, UCHAR MsgLen)
{
    return (CEC_SendMessage(MsgPtr, MsgLen));
}

/*============================================================================
 * to check if any CEC message in buffer, if yes, to send one
 * 
 * Entry:   none
 * 
 * Return:  ATVERR_OK
 *          ATVERR_FAILED if CEC controller is busy
  * 
 *===========================================================================*/
ATV_ERR ADIAPI_RxCecSendMessageOut(void)
{
    return (CEC_SendMessageOut()); 
}    

/*============================================================================
 * Resend last sent message to CEC
 * 
 * Entry:   None
 * 
 * Return:  ATVERR_OK
 *          ATVERR_FAILED if CEC controller is busy
 * 
 *===========================================================================*/
ATV_ERR ADIAPI_RxCecResendLastMessage (void)
{
    return (CEC_ResendLastMessage());
}

/*============================================================================
 * Perform logical address allocation
 *
 * Entry:   LogAddrList = Pointer to a prioritized list of logical addresses 
 *                        that the device will try to obtain, terminated by
 *                        0xff.
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED if CEC is busy
 *          ATVERR_INV_PARM if LogAddrList is too long or contains no data
 * 
 * This function returns immediately. If a logical address slot is found,
 * the caller will be notified by the event ADI_EVENT_CEC_LOG_ADDR_ALLOC
 * 
 *===========================================================================*/
ATV_ERR ADIAPI_RxCecAllocateLogAddr (UCHAR *LogAddrList)
{
    return (CEC_AllocateLogAddr(LogAddrList));
}

/*============================================================================
 * Get a list of all active logical addresses in the system
 *
 * Entry:   SrcLogAddr  = The logical address to be used as the initiator in 
 *                        the logical address polling messages. Set to 0xff
 *                        to use the initiator logical address to the same
 *                        value as the destination
 * 
 * Return:  ATVERR_OK
 *          ATVERR_FAILED if CEC is busy
 * 
 * This function returns immediately. The list of active logical addresses 
 * will be provided by the event ADI_EVENT_CEC_LOG_ADDR_LIST
 * 
 *===========================================================================*/
ATV_ERR ADIAPI_RxCecGetLogAddrList (UCHAR SrcLogAddr)
{
    return (CEC_GetLogAddrList(SrcLogAddr));
}

/*============================================================================
 * 
 *
 * Entry:   
 *
 * Return:  ATVERR_OK
 *          ATVERR_INV_PARM
 * 
 * 
 *===========================================================================*/
ATV_ERR ADIAPI_RxCecReadMessage (UCHAR *MsgPtr, UCHAR *MsgLen)
{
    return (ATVERR_OK);
}

/*============================================================================
 * 
 *
 * Entry:   
 *
 * Return:  ATVERR_OK
 *          ATVERR_INV_PARM
 * 
 * 
 *===========================================================================*/
ATV_ERR ADIAPI_RxCecGetStatus (UCHAR *Status)
{
    return (ATVERR_OK);
}

/*============================================================================
 * This function is called from the CEC module ISR
 *
 * Entry:   
 *
 * Return:  
 * 
 *===========================================================================*/
UINT16 Cec_Notification (UCHAR Event, UINT16 Len, void *Buff)
{
    UINT16 RetVal = 0;
    RX_EVENT Ev = (RX_EVENT)0;

    switch (Event)
    {
        case CEC_EVENT_RX_MSG:
            Ev = RX_EVENT_CEC_RX_MSG;
            break;
        case CEC_EVENT_TX_DONE:
            Ev = RX_EVENT_CEC_TX_DONE;
            break;
        case CEC_EVENT_TX_TIMEOUT:
            Ev = RX_EVENT_CEC_TX_TIMEOUT;
            break;
        case CEC_EVENT_TX_ARB_LOST:
            Ev = RX_EVENT_CEC_TX_ARB_LOST;
            break;
        case CEC_EVENT_LOG_ADDR_ALLOC:
            Ev = RX_EVENT_CEC_LOG_ADDR_ALLOC;
            break;
        case CEC_EVENT_LOG_ADDR_LIST:
            Ev = RX_EVENT_CEC_LOG_ADDR_LIST;
            break;
        case CEC_EVENT_RX_MSG_RESPOND:
            Ev = RX_EVENT_CEC_RX_MSG_RESPOND;
            break;
            
        default:
           break;
    }
    if (RX_EVENT_IS_ENABLED(Ev))
    {
        RetVal = RX_CALLBACK_FUNCTION(Ev, Len, Buff);
    }
    return (RetVal);
}

#endif
