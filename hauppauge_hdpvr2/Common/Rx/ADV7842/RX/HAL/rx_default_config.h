/**********************************************************************************************
*																						      *
* Copyright (c) 2012 Analog Devices, Inc.  All Rights Reserved.                               *
* This software is proprietary and confidential to Analog Devices, Inc. and its licensors.    *
*                                                                                             *
***********************************************************************************************/

#ifndef _RX_DEFAULT_CONFIG_H_
#define _RX_DEFAULT_CONFIG_H_

#if (RX_DEVICE == 7623) || (RX_DEVICE == 7622) || (RX_DEVICE == 76221) 
#define RX_I2C_IO_MAP_ADDR              0xB2
#elif (RX_DEVICE == 7612) || (RX_DEVICE == 7611) || (RX_DEVICE == 7619)
#define RX_I2C_IO_MAP_ADDR              0x98
#else
#define RX_I2C_IO_MAP_ADDR              0x40
#endif
#define RX_I2C_CP_MAP_ADDR              0x44
#define RX_I2C_VDP_MAP_ADDR             0x48
#define RX_I2C_AFE_DPLL_MAP_ADDR        0x4C
#define RX_I2C_REPEATER_MAP_ADDR        0x64
#define RX_I2C_HDMI_MAP_ADDR            0x68
#define RX_I2C_EDID_MAP_ADDR            0x6C
#define RX_I2C_ESDP_MAP_ADDR            0x70
#define RX_I2C_DPP_MAP_ADDR             0x78
#define RX_I2C_AVLINK_MAP_ADDR          0x84
#define RX_I2C_CEC_MAP_ADDR             0x80 
#define RX_I2C_INFOFRAME_MAP_ADDR       0x7C
#define RX_I2C_TEST_MAP1_ADDR           0x60
#define RX_I2C_TEST_MAP2_ADDR           0x62        /* Only for ADV7840 */
#define RX_I2C_TEST_MAP3_ADDR           0x52        /* Only for ADV7840 */
#define RX_I2C_OSD_MAP_ADDR             0x54        /* Only for ADV7623 */
#define TX_I2C_PKT_MEM_MAP_ADDR         0x56        /* Only for ADV7623 */
#define TX_I2C_EDID_MAP_ADDR            0x58        /* Only for ADV7623 */
#define RX_I2C_SDP_VDP_MAP_ADDR         0x22        /* Only for ADV7840 */ 
#define RX_I2C_VFE_MAP_ADDR             0xA0        /* ADV7850 Only*/
#define RX_I2C_AUDIO_CODEC_MAP_ADDR     0x5C        /* ADV7850 Only*/
#define RX_I2C_XMEM_MAP_ADDR            0xA8        /* ADV7850 Only*/
#if (RX_DEVICE == 7840)
#define RX_I2C_SDP_IO_MAP_ADDR          0x42        /* Only for ADV7840 */     
#define RX_I2C_SDP_MAP_ADDR             0x82        /* Only for ADV7840 */ 
#else
#define RX_I2C_SDP_MAP_ADDR             0x90
#define RX_I2C_SDP_IO_MAP_ADDR          0x94
#endif

#define RX_NUM_OF_DEVICES               1
#define RX_INCLUDE_CEC                  1
#define RX_INCLUDE_VBI                  1

#endif
