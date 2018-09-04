/**********************************************************************************************
*																						      *
* Copyright (c) 2012 Analog Devices, Inc.  All Rights Reserved.                               *
* This software is proprietary and confidential to Analog Devices, Inc. and its licensors.    *
*                                                                                             *
***********************************************************************************************/

#ifndef _RX_ISR_H_
#define _RX_ISR_H_

/*===================================================
 * All RX variables are locates in this structure
 *==================================================*/
#define RX_ENABLE_EVENTS_SIZE           16
#define CH_STAT_SIZE                    5
#define MAX_NOF_WO_REGS                 8       /* For any device */

typedef struct
{
    /*===========================
     * Local vars
     *==========================*/
    UCHAR   StickyGroup3IntsN;
    UCHAR   EncStateN;

    RX_AUDIO_TYPE CurrAudModeN;         /* Current Audio Mode       */
    UINT8   CurrCsN[CH_STAT_SIZE];      /* Current Channel Status   */

    UCHAR   LastRawBitsN;
    UINT32  LastIsrc1TimeN;
    UINT32  LastIsrc2TimeN;
    UINT32  LastAcpTimeN;
    UINT32  LastSpdTimeN;
    UINT32  LastAudIfTimeN;
    UINT32  LastAviIfTimeN;
    UINT32  LastMpegTimeN;
    UINT32  LastVsTimeN;
    UINT32  LastGmdTimeN;
    UINT32  CurrNValN;
    BOOL    VsInfoFrame3DN;

    BOOL    CurrSspdLockN;
    BOOL    CurrSspdLockCh1N;
    BOOL    CurrSspdLockCh2N;

    BOOL    CurrVideoDetectedN;
    BOOL    CurrBurstLockN;
    BOOL    CurrMvAgcDetectedN;
    BOOL    CurrMvCsDetectedN;
    BOOL    CurrMvPsDetectedN;
    RX_SDP_FORMAT    CurrSdpStdDetectedN;

    UCHAR   WoRegValN[MAX_NOF_WO_REGS];

    /*===========================
     * Shared vars
     *==========================*/
    UCHAR       RxEnabledEventsN[RX_ENABLE_EVENTS_SIZE];
    RX_OP_MODE  RxPrevOperatingModeN;
    RX_OP_MODE  RxOperatingModeN;
    RX_CONFIG   RxUsrConfigN;
} RX_LIB_VARS;

EXTERNAL RX_LIB_VARS RxLibVars[];
EXTERNAL UCHAR RxCurrDevIdx;

#define RxEnabledEvents         (RxLibVars[RxCurrDevIdx].RxEnabledEventsN)
#define StickyGroup3Ints        (RxLibVars[RxCurrDevIdx].StickyGroup3IntsN)
#define EncState                (RxLibVars[RxCurrDevIdx].EncStateN)
#define CurrAudMode             (RxLibVars[RxCurrDevIdx].CurrAudModeN)
#define CurrCs                  (RxLibVars[RxCurrDevIdx].CurrCsN)
#define LastRawBits             (RxLibVars[RxCurrDevIdx].LastRawBitsN)
#define LastAudIfTime           (RxLibVars[RxCurrDevIdx].LastAudIfTimeN)
#define LastAviIfTime           (RxLibVars[RxCurrDevIdx].LastAviIfTimeN)
#define LastIsrc1Time           (RxLibVars[RxCurrDevIdx].LastIsrc1TimeN)
#define LastIsrc2Time           (RxLibVars[RxCurrDevIdx].LastIsrc2TimeN)
#define LastSpdTime             (RxLibVars[RxCurrDevIdx].LastSpdTimeN)
#define LastMpegTime            (RxLibVars[RxCurrDevIdx].LastMpegTimeN)
#define LastVsTime              (RxLibVars[RxCurrDevIdx].LastVsTimeN)
#define LastGmdTime             (RxLibVars[RxCurrDevIdx].LastGmdTimeN)
#define LastAcpTime             (RxLibVars[RxCurrDevIdx].LastAcpTimeN)
#define CurrNVal                (RxLibVars[RxCurrDevIdx].CurrNValN)
#define VsInfoFrame3D           (RxLibVars[RxCurrDevIdx].VsInfoFrame3DN)
#define RxPrevOperatingMode     (RxLibVars[RxCurrDevIdx].RxPrevOperatingModeN)
#define RxOperatingMode         (RxLibVars[RxCurrDevIdx].RxOperatingModeN)
#define RxUsrConfig             (RxLibVars[RxCurrDevIdx].RxUsrConfigN)
#define CurrSspdLock            (RxLibVars[RxCurrDevIdx].CurrSspdLockN)
#define CurrSspdLockCh1         (RxLibVars[RxCurrDevIdx].CurrSspdLockCh1N)
#define CurrSspdLockCh2         (RxLibVars[RxCurrDevIdx].CurrSspdLockCh2N)
#define CurrVideoDetected       (RxLibVars[RxCurrDevIdx].CurrVideoDetectedN)
#define CurrBurstLock           (RxLibVars[RxCurrDevIdx].CurrBurstLockN)
#define CurrMvAgcDetected       (RxLibVars[RxCurrDevIdx].CurrMvAgcDetectedN)
#define CurrMvCsDetected        (RxLibVars[RxCurrDevIdx].CurrMvCsDetectedN)
#define CurrMvPsDetected        (RxLibVars[RxCurrDevIdx].CurrMvPsDetectedN)
#define CurrSdpStdDetected      (RxLibVars[RxCurrDevIdx].CurrSdpStdDetectedN)
#define WoRegVal                (RxLibVars[RxCurrDevIdx].WoRegValN)

/*===================================================
 * Events related defines
 *==================================================*/
#ifdef RX_CALLBACK_FUNCTION
EXTERNAL UINT16 RX_CALLBACK_FUNCTION (RX_EVENT Ev, UINT16 Cnt, void *Buf);
#else
#define RX_CALLBACK_FUNCTION(a,b,c)     0
#endif

#define RX_EVENT_BYTE(a)            (RxEnabledEvents[(a)>>3])
#define RX_EVENT_BIT(a)             (1<<((a)&7))
#define RX_EVENT_IS_ENABLED(a)      (RX_EVENT_BYTE(a)&  RX_EVENT_BIT(a))
#define RX_EVENT_ENABLE(a)          (RX_EVENT_BYTE(a)|= RX_EVENT_BIT(a))
#define RX_EVENT_DISABLE(a)         (RX_EVENT_BYTE(a)&= ~(RX_EVENT_BIT(a)))

#define RX_NOTIFY_USER(a,b,c)       if(RX_EVENT_IS_ENABLED(a))RX_CALLBACK_FUNCTION(a,b,c)

#endif
