/**********************************************************************************************
*																						      *
* Copyright (c) 2008 - 2012 Analog Devices, Inc.  All Rights Reserved.                        *
* This software is proprietary and confidential to Analog Devices, Inc. and its licensors.    *
*                                                                                             *
***********************************************************************************************/
/*******************************************************************************
*                                                                              *

* This software is intended for use with the ADV7842 part only.                *
*                                                                              *
*******************************************************************************/

/*******************************************************************************
*                                                                              *
* FILE AUTOMATICALLY GENERATED.                                                *
* DATE: 18 Nov 2009 15:43:12                                                   *
*                                                                              *
*******************************************************************************/


#ifndef ADV7842_INFOFRAME_MAP_FCT_H
#define ADV7842_INFOFRAME_MAP_FCT_H

#include "ADV7842_cfg.h"

#define VRX_get_AVI_INF_PB(pval)                            ATV_I2CGetMultiField(VRX_INFOFRAME_MAP_ADDR, 0x00, 28, pval)

#define VRX_get_AUD_INF_PB(pval)                            ATV_I2CGetMultiField(VRX_INFOFRAME_MAP_ADDR, 0x1C, 14, pval)

#define VRX_get_SPD_INF_PB(pval)                            ATV_I2CGetMultiField(VRX_INFOFRAME_MAP_ADDR, 0x2A, 28, pval)

#define VRX_get_MS_INF_PB(pval)                             ATV_I2CGetMultiField(VRX_INFOFRAME_MAP_ADDR, 0x46, 14, pval)

#define VRX_get_VS_INF_PB(pval)                             ATV_I2CGetMultiField(VRX_INFOFRAME_MAP_ADDR, 0x54, 28, pval)

#define VRX_get_ACP_PB(pval)                                ATV_I2CGetMultiField(VRX_INFOFRAME_MAP_ADDR, 0x70, 28, pval)

#define VRX_get_ISRC1_PB(pval)                              ATV_I2CGetMultiField(VRX_INFOFRAME_MAP_ADDR, 0x8C, 28, pval)

#define VRX_get_ISRC2_PB(pval)                              ATV_I2CGetMultiField(VRX_INFOFRAME_MAP_ADDR, 0xA8, 28, pval)

#define VRX_get_GBD(pval)                                   ATV_I2CGetMultiField(VRX_INFOFRAME_MAP_ADDR, 0xC4, 28, pval)

#define VRX_get_AVI_PACKET_ID(pval)                         ATV_I2CGetField8(VRX_INFOFRAME_MAP_ADDR, 0xE0, 0xFF, 0, pval)
#define VRX_ret_AVI_PACKET_ID()                             ATV_I2CReadField8(VRX_INFOFRAME_MAP_ADDR, 0xE0, 0xFF, 0)
#define VRX_set_AVI_PACKET_ID(val)                          ATV_I2CWriteField8(VRX_INFOFRAME_MAP_ADDR, 0xE0, 0xFF, 0, val)

#define VRX_get_AVI_INF_VERS(pval)                          ATV_I2CGetField8(VRX_INFOFRAME_MAP_ADDR, 0xE1, 0xFF, 0, pval)
#define VRX_ret_AVI_INF_VERS()                              ATV_I2CReadField8(VRX_INFOFRAME_MAP_ADDR, 0xE1, 0xFF, 0)

#define VRX_get_AVI_INF_LEN(pval)                           ATV_I2CGetField8(VRX_INFOFRAME_MAP_ADDR, 0xE2, 0xFF, 0, pval)
#define VRX_ret_AVI_INF_LEN()                               ATV_I2CReadField8(VRX_INFOFRAME_MAP_ADDR, 0xE2, 0xFF, 0)

#define VRX_get_AUD_PACKET_ID(pval)                         ATV_I2CGetField8(VRX_INFOFRAME_MAP_ADDR, 0xE3, 0xFF, 0, pval)
#define VRX_ret_AUD_PACKET_ID()                             ATV_I2CReadField8(VRX_INFOFRAME_MAP_ADDR, 0xE3, 0xFF, 0)
#define VRX_set_AUD_PACKET_ID(val)                          ATV_I2CWriteField8(VRX_INFOFRAME_MAP_ADDR, 0xE3, 0xFF, 0, val)

#define VRX_get_AUD_INF_VERS(pval)                          ATV_I2CGetField8(VRX_INFOFRAME_MAP_ADDR, 0xE4, 0xFF, 0, pval)
#define VRX_ret_AUD_INF_VERS()                              ATV_I2CReadField8(VRX_INFOFRAME_MAP_ADDR, 0xE4, 0xFF, 0)

#define VRX_get_AUD_INF_LEN(pval)                           ATV_I2CGetField8(VRX_INFOFRAME_MAP_ADDR, 0xE5, 0xFF, 0, pval)
#define VRX_ret_AUD_INF_LEN()                               ATV_I2CReadField8(VRX_INFOFRAME_MAP_ADDR, 0xE5, 0xFF, 0)

#define VRX_get_SPD_PACKET_ID(pval)                         ATV_I2CGetField8(VRX_INFOFRAME_MAP_ADDR, 0xE6, 0xFF, 0, pval)
#define VRX_ret_SPD_PACKET_ID()                             ATV_I2CReadField8(VRX_INFOFRAME_MAP_ADDR, 0xE6, 0xFF, 0)
#define VRX_set_SPD_PACKET_ID(val)                          ATV_I2CWriteField8(VRX_INFOFRAME_MAP_ADDR, 0xE6, 0xFF, 0, val)

#define VRX_get_SPD_INF_VERS(pval)                          ATV_I2CGetField8(VRX_INFOFRAME_MAP_ADDR, 0xE7, 0xFF, 0, pval)
#define VRX_ret_SPD_INF_VERS()                              ATV_I2CReadField8(VRX_INFOFRAME_MAP_ADDR, 0xE7, 0xFF, 0)

#define VRX_get_SPD_INF_LEN(pval)                           ATV_I2CGetField8(VRX_INFOFRAME_MAP_ADDR, 0xE8, 0xFF, 0, pval)
#define VRX_ret_SPD_INF_LEN()                               ATV_I2CReadField8(VRX_INFOFRAME_MAP_ADDR, 0xE8, 0xFF, 0)

#define VRX_get_MS_PACKET_ID(pval)                          ATV_I2CGetField8(VRX_INFOFRAME_MAP_ADDR, 0xE9, 0xFF, 0, pval)
#define VRX_ret_MS_PACKET_ID()                              ATV_I2CReadField8(VRX_INFOFRAME_MAP_ADDR, 0xE9, 0xFF, 0)
#define VRX_set_MS_PACKET_ID(val)                           ATV_I2CWriteField8(VRX_INFOFRAME_MAP_ADDR, 0xE9, 0xFF, 0, val)

#define VRX_get_MS_INF_VERS(pval)                           ATV_I2CGetField8(VRX_INFOFRAME_MAP_ADDR, 0xEA, 0xFF, 0, pval)
#define VRX_ret_MS_INF_VERS()                               ATV_I2CReadField8(VRX_INFOFRAME_MAP_ADDR, 0xEA, 0xFF, 0)

#define VRX_get_MS_INF_LEN(pval)                            ATV_I2CGetField8(VRX_INFOFRAME_MAP_ADDR, 0xEB, 0xFF, 0, pval)
#define VRX_ret_MS_INF_LEN()                                ATV_I2CReadField8(VRX_INFOFRAME_MAP_ADDR, 0xEB, 0xFF, 0)

#define VRX_get_VS_PACKET_ID(pval)                          ATV_I2CGetField8(VRX_INFOFRAME_MAP_ADDR, 0xEC, 0xFF, 0, pval)
#define VRX_ret_VS_PACKET_ID()                              ATV_I2CReadField8(VRX_INFOFRAME_MAP_ADDR, 0xEC, 0xFF, 0)
#define VRX_set_VS_PACKET_ID(val)                           ATV_I2CWriteField8(VRX_INFOFRAME_MAP_ADDR, 0xEC, 0xFF, 0, val)

#define VRX_get_VS_INF_VERS(pval)                           ATV_I2CGetField8(VRX_INFOFRAME_MAP_ADDR, 0xED, 0xFF, 0, pval)
#define VRX_ret_VS_INF_VERS()                               ATV_I2CReadField8(VRX_INFOFRAME_MAP_ADDR, 0xED, 0xFF, 0)

#define VRX_get_VS_INF_LEN(pval)                            ATV_I2CGetField8(VRX_INFOFRAME_MAP_ADDR, 0xEE, 0xFF, 0, pval)
#define VRX_ret_VS_INF_LEN()                                ATV_I2CReadField8(VRX_INFOFRAME_MAP_ADDR, 0xEE, 0xFF, 0)

#define VRX_get_ACP_PACKET_ID(pval)                         ATV_I2CGetField8(VRX_INFOFRAME_MAP_ADDR, 0xEF, 0xFF, 0, pval)
#define VRX_ret_ACP_PACKET_ID()                             ATV_I2CReadField8(VRX_INFOFRAME_MAP_ADDR, 0xEF, 0xFF, 0)
#define VRX_set_ACP_PACKET_ID(val)                          ATV_I2CWriteField8(VRX_INFOFRAME_MAP_ADDR, 0xEF, 0xFF, 0, val)

#define VRX_get_ACP_TYPE(pval)                              ATV_I2CGetField8(VRX_INFOFRAME_MAP_ADDR, 0xF0, 0xFF, 0, pval)
#define VRX_ret_ACP_TYPE()                                  ATV_I2CReadField8(VRX_INFOFRAME_MAP_ADDR, 0xF0, 0xFF, 0)

#define VRX_get_ACP_HEADER2(pval)                           ATV_I2CGetField8(VRX_INFOFRAME_MAP_ADDR, 0xF1, 0xFF, 0, pval)
#define VRX_ret_ACP_HEADER2()                               ATV_I2CReadField8(VRX_INFOFRAME_MAP_ADDR, 0xF1, 0xFF, 0)

#define VRX_get_ISRC1_PACKET_ID(pval)                       ATV_I2CGetField8(VRX_INFOFRAME_MAP_ADDR, 0xF2, 0xFF, 0, pval)
#define VRX_ret_ISRC1_PACKET_ID()                           ATV_I2CReadField8(VRX_INFOFRAME_MAP_ADDR, 0xF2, 0xFF, 0)
#define VRX_set_ISRC1_PACKET_ID(val)                        ATV_I2CWriteField8(VRX_INFOFRAME_MAP_ADDR, 0xF2, 0xFF, 0, val)

#define VRX_get_ISRC1_HEADER1(pval)                         ATV_I2CGetField8(VRX_INFOFRAME_MAP_ADDR, 0xF3, 0xFF, 0, pval)
#define VRX_ret_ISRC1_HEADER1()                             ATV_I2CReadField8(VRX_INFOFRAME_MAP_ADDR, 0xF3, 0xFF, 0)

#define VRX_get_ISRC1_HEADER2(pval)                         ATV_I2CGetField8(VRX_INFOFRAME_MAP_ADDR, 0xF4, 0xFF, 0, pval)
#define VRX_ret_ISRC1_HEADER2()                             ATV_I2CReadField8(VRX_INFOFRAME_MAP_ADDR, 0xF4, 0xFF, 0)

#define VRX_get_ISRC2_PACKET_ID(pval)                       ATV_I2CGetField8(VRX_INFOFRAME_MAP_ADDR, 0xF5, 0xFF, 0, pval)
#define VRX_ret_ISRC2_PACKET_ID()                           ATV_I2CReadField8(VRX_INFOFRAME_MAP_ADDR, 0xF5, 0xFF, 0)
#define VRX_set_ISRC2_PACKET_ID(val)                        ATV_I2CWriteField8(VRX_INFOFRAME_MAP_ADDR, 0xF5, 0xFF, 0, val)

#define VRX_get_ISRC2_HEADER1(pval)                         ATV_I2CGetField8(VRX_INFOFRAME_MAP_ADDR, 0xF6, 0xFF, 0, pval)
#define VRX_ret_ISRC2_HEADER1()                             ATV_I2CReadField8(VRX_INFOFRAME_MAP_ADDR, 0xF6, 0xFF, 0)

#define VRX_get_ISRC2_HEADER2(pval)                         ATV_I2CGetField8(VRX_INFOFRAME_MAP_ADDR, 0xF7, 0xFF, 0, pval)
#define VRX_ret_ISRC2_HEADER2()                             ATV_I2CReadField8(VRX_INFOFRAME_MAP_ADDR, 0xF7, 0xFF, 0)

#define VRX_get_GAMUT_PACKET_ID(pval)                       ATV_I2CGetField8(VRX_INFOFRAME_MAP_ADDR, 0xF8, 0xFF, 0, pval)
#define VRX_ret_GAMUT_PACKET_ID()                           ATV_I2CReadField8(VRX_INFOFRAME_MAP_ADDR, 0xF8, 0xFF, 0)
#define VRX_set_GAMUT_PACKET_ID(val)                        ATV_I2CWriteField8(VRX_INFOFRAME_MAP_ADDR, 0xF8, 0xFF, 0, val)

#define VRX_get_GAMUT_HEADER1(pval)                         ATV_I2CGetField8(VRX_INFOFRAME_MAP_ADDR, 0xF9, 0xFF, 0, pval)
#define VRX_ret_GAMUT_HEADER1()                             ATV_I2CReadField8(VRX_INFOFRAME_MAP_ADDR, 0xF9, 0xFF, 0)

#define VRX_get_GAMUT_HEADER2(pval)                         ATV_I2CGetField8(VRX_INFOFRAME_MAP_ADDR, 0xFA, 0xFF, 0, pval)
#define VRX_ret_GAMUT_HEADER2()                             ATV_I2CReadField8(VRX_INFOFRAME_MAP_ADDR, 0xFA, 0xFF, 0)

#endif
