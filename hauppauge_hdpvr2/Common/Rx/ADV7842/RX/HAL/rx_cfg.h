/**********************************************************************************************
*																						      *
* Copyright (c) 2012 Analog Devices, Inc.  All Rights Reserved.                               *
* This software is proprietary and confidential to Analog Devices, Inc. and its licensors.    *
*                                                                                             *
***********************************************************************************************/

#ifndef _RX_CFG_H_
#define _RX_CFG_H_

#if RX_USER_CONFIG
/*#include "rx_config.h"*/
#include "wrapper.h"
#else
#include "rx_default_config.h"
#endif

#ifndef RX_NUM_OF_INSTANCES
#define RX_NUM_OF_INSTANCES         RX_NUM_OF_DEVICES
#endif

/*===============================================
 * User RX config uses "RX_" instead of "VRX_"
 *==============================================*/
#define VRX_IO_MAP_ADDR             RxDevAddr->Io
#define VRX_CP_MAP_ADDR             RxDevAddr->Cp
#define VRX_VDP_MAP_ADDR            RxDevAddr->Vdp
#define VRX_AFE_DPLL_MAP_ADDR       RxDevAddr->AfeDpll
#define VRX_REPEATER_MAP_ADDR       RxDevAddr->Rep
#define VRX_HDMI_MAP_ADDR           RxDevAddr->Hdmi
#define VRX_EDID_MAP_ADDR           RxDevAddr->Edid
#define VRX_ESDP_MAP_ADDR           RxDevAddr->Esdp
#define VRX_DPP_MAP_ADDR            RxDevAddr->Dpp
#define VRX_AVLINK_MAP_ADDR         RxDevAddr->Avlink
#define VRX_CEC_MAP_ADDR            RxDevAddr->Cec
#define VRX_INFOFRAME_MAP_ADDR      RxDevAddr->Infoframe
#define VRX_SDP_IO_MAP_ADDR         RxDevAddr->SdpIo
#define VRX_SDP_VDP_MAP_ADDR        RxDevAddr->SdpVdp
#define VRX_SDP_MAP_ADDR            RxDevAddr->Sdp
#define VRX_TEST_MAP1_ADDR          RxDevAddr->Test1
#define VRX_TEST_MAP2_ADDR          RxDevAddr->Test2
#define VRX_TEST_MAP3_ADDR          RxDevAddr->Test3
#define VRX_OSD_MAP_ADDR            RxDevAddr->Osd
#define VRX_VFE_MAP_ADDR            RxDevAddr->Vfe
#define VRX_AUDIO_CODEC_MAP_ADDR    RxDevAddr->AudCodec
#define VRX_XMEM_GAMMA_MAP_ADDR     RxDevAddr->DdrMem
#define VRX_TX_UDP_MAP_ADDR         RxDevAddr->TxUdp
#define VRX_TX_EDID_MAP_ADDR        RxDevAddr->TxEdid
#define VRX_ACTIVE_CEC_MAP          RxDeviceAddress[RxActiveCecIdx].Cec

#if RX_USER_INIT
EXTERNAL CONSTANT UCHAR UserRxRegInitTable[];
EXTERNAL CONSTANT UCHAR UserRxFieldInitTable[];
#endif

#endif
