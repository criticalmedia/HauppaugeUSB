/**********************************************************************************************
*																						      *
* Copyright (c) 2012 Analog Devices, Inc.  All Rights Reserved.                               *
* This software is proprietary and confidential to Analog Devices, Inc. and its licensors.    *
*                                                                                             *
***********************************************************************************************/

#ifndef _RX_4G_HAL_H_
#define _RX_4G_HAL_H_
#if ((RX_DEVICE == 7623) ||(RX_DEVICE == 7622) || (RX_DEVICE == 76221) || (RX_DEVICE == 7844) || (RX_DEVICE == 7842)|| (RX_DEVICE == 7850))
#define TMDSFRAQ_SHIFT                          0
#define CEC_CFG02_REV_2                         1

#define VRX_set_SPA_PORT_1                      VRX_set_SPA_PORT_B
#define VRX_set_SPA_PORT_2                      VRX_set_SPA_PORT_C
#define VRX_set_SPA_PORT_3                      VRX_set_SPA_PORT_D
#define VRX_ret_SPA_PORT_1                      VRX_ret_SPA_PORT_B
#define VRX_ret_SPA_PORT_2                      VRX_ret_SPA_PORT_C
#define VRX_ret_SPA_PORT_3                      VRX_ret_SPA_PORT_D

#define VRX_set_DIRECT_PORT_SW(val)             ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x3D, 0x40, 0x6, val)
#define VRX_set_CLR_BCAPS_RDY_BITS(val)         ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x7E, 0xF0, 0x4, val)

#if (!RX_INCLUDE_VBI)

#define HAL_RXLIB_VdpIsr()                      (ATVERR_OK)
#define HAL_RXLIB_SdpVdpIsr()                   (ATVERR_OK)
#define HAL_RxVdpSetEnabledEvents(a,b,c)
#define HAL_RxSdpVdpSetEnabledEvents(a,b,c)
#endif

#if (RX_DEVICE ==7850)
#define VRX_set_audio_core_pdn(val)  
#else
#define VRX_set_audio_core_pdn(val)             ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0xC3, 0x20, 0x5, val)
#endif

#endif

#endif
