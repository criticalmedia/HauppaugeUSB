/**********************************************************************************************
*																						      *
* Copyright (c) 2012 Analog Devices, Inc.  All Rights Reserved.                               *
* This software is proprietary and confidential to Analog Devices, Inc. and its licensors.    *
*                                                                                             *
***********************************************************************************************/

#ifndef _7842_DEF_H_
#define _7842_DEF_H_

/*============================================
 * General defines
 *===========================================*/
#define RX_NOF_PORTS                2
#define RX_MAX_NOF_KSVS             24
#define RX_FAST_SWITCHING_DEVICE    1
#define RX_DEV_NAME                 "ADV7842"

/*============================================
 * Engineering Samples
 *===========================================*/
#define RX_DEV_REV_ES1              0
#define RX_DEV_REV_ES2              1
#define RX_DEV_REV_ES3              2
#define RX_DEV_REV_ES4              3

#if (RX_DEVICE == 7842)
#if (RX_ES_ID == 1)
#define ES1_7842                    1
#endif
#if (RX_ES_ID == 2)
#define ES2_7842                    1
#endif
#if ((RX_ES_ID == 3)|| (RX_ES_ID == 0))
#define ES3_7842                    1
#endif
#endif

/*===========================================
 * HDMI Port Macros
 *===========================================*/
#define RX_VALID_PORT(a)            ((UCHAR)a<RX_NOF_PORTS)
#define RX_PORT_INDEX(a)            ((UCHAR)(a) & 0x01)
#define RX_PORT_ID(a)               ((UCHAR)(a) | 0x02)
#define RX_PORT_NAME(a)             ((RX_HDMI_PORT)(a & 0x01))

#endif
