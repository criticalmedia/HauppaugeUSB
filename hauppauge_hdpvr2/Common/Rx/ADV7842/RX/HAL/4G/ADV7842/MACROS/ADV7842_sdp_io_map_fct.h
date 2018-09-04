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
* DATE: 18 Nov 2009 17:2:59                                                    *
*                                                                              *
*******************************************************************************/


#ifndef ADV7842_SDP_IO_MAP_FCT_H
#define ADV7842_SDP_IO_MAP_FCT_H

#include "ADV7842_cfg.h"

#define VRX_is_SDP_TRI_MEMORY_IF_B_true()                   ATV_I2CIsField8(VRX_SDP_IO_MAP_ADDR, 0x29, 0x10, 0x4)
#define VRX_get_SDP_TRI_MEMORY_IF_B(pval)                   ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0x29, 0x10, 0x4, pval)
#define VRX_ret_SDP_TRI_MEMORY_IF_B()                       ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0x29, 0x10, 0x4)
#define VRX_set_SDP_TRI_MEMORY_IF_B(val)                    ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0x29, 0x10, 0x4, val)

#define VRX_is_SDP_RING_RED_EN_true()                       ATV_I2CIsField8(VRX_SDP_IO_MAP_ADDR, 0x51, 0x80, 0x7)
#define VRX_get_SDP_RING_RED_EN(pval)                       ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0x51, 0x80, 0x7, pval)
#define VRX_ret_SDP_RING_RED_EN()                           ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0x51, 0x80, 0x7)
#define VRX_set_SDP_RING_RED_EN(val)                        ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0x51, 0x80, 0x7, val)

#define VRX_get_SDP_RING_RED_LEVEL(pval)                    ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0x51, 0x7F, 0, pval)
#define VRX_ret_SDP_RING_RED_LEVEL()                        ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0x51, 0x7F, 0)
#define VRX_set_SDP_RING_RED_LEVEL(val)                     ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0x51, 0x7F, 0, val)

#define VRX_set_SDP_MEM_SM_RESET(val)                       ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0x60, 0x1, 0x0, val)

#define VRX_get_SDP_MAN_SFL_STANDARD(pval)                  ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0x66, 0xF0, 4, pval)
#define VRX_ret_SDP_MAN_SFL_STANDARD()                      ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0x66, 0xF0, 4)
#define VRX_set_SDP_MAN_SFL_STANDARD(val)                   ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0x66, 0xF0, 4, val)

#define VRX_is_SDP_MAN_SFL_STD_EN_true()                    ATV_I2CIsField8(VRX_SDP_IO_MAP_ADDR, 0x66, 0x2, 0x1)
#define VRX_get_SDP_MAN_SFL_STD_EN(pval)                    ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0x66, 0x2, 0x1, pval)
#define VRX_ret_SDP_MAN_SFL_STD_EN()                        ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0x66, 0x2, 0x1)
#define VRX_set_SDP_MAN_SFL_STD_EN(val)                     ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0x66, 0x2, 0x1, val)

#define VRX_is_SDP_AUTO_SFL_STD_EN_true()                   ATV_I2CIsField8(VRX_SDP_IO_MAP_ADDR, 0x66, 0x1, 0x0)
#define VRX_get_SDP_AUTO_SFL_STD_EN(pval)                   ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0x66, 0x1, 0x0, pval)
#define VRX_ret_SDP_AUTO_SFL_STD_EN()                       ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0x66, 0x1, 0x0)
#define VRX_set_SDP_AUTO_SFL_STD_EN(val)                    ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0x66, 0x1, 0x0, val)

#define VRX_is_SDP_SFL_EN_true()                            ATV_I2CIsField8(VRX_SDP_IO_MAP_ADDR, 0x67, 0x4, 0x2)
#define VRX_get_SDP_SFL_EN(pval)                            ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0x67, 0x4, 0x2, pval)
#define VRX_ret_SDP_SFL_EN()                                ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0x67, 0x4, 0x2)
#define VRX_set_SDP_SFL_EN(val)                             ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0x67, 0x4, 0x2, val)

#define VRX_is_SDP_SFL_INV_PSW_true()                       ATV_I2CIsField8(VRX_SDP_IO_MAP_ADDR, 0x67, 0x1, 0x0)
#define VRX_get_SDP_SFL_INV_PSW(pval)                       ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0x67, 0x1, 0x0, pval)
#define VRX_ret_SDP_SFL_INV_PSW()                           ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0x67, 0x1, 0x0)
#define VRX_set_SDP_SFL_INV_PSW(val)                        ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0x67, 0x1, 0x0, val)

#define VRX_is_SDP_FREEZE_FRAME_true()                      ATV_I2CIsField8(VRX_SDP_IO_MAP_ADDR, 0x6F, 0x2, 0x1)
#define VRX_get_SDP_FREEZE_FRAME(pval)                      ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0x6F, 0x2, 0x1, pval)
#define VRX_ret_SDP_FREEZE_FRAME()                          ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0x6F, 0x2, 0x1)
#define VRX_set_SDP_FREEZE_FRAME(val)                       ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0x6F, 0x2, 0x1, val)

#define VRX_is_SDP_SDRAM_MEM_true()                         ATV_I2CIsField8(VRX_SDP_IO_MAP_ADDR, 0x6F, 0x1, 0x0)
#define VRX_get_SDP_SDRAM_MEM(pval)                         ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0x6F, 0x1, 0x0, pval)
#define VRX_ret_SDP_SDRAM_MEM()                             ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0x6F, 0x1, 0x0)
#define VRX_set_SDP_SDRAM_MEM(val)                          ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0x6F, 0x1, 0x0, val)

#define VRX_get_SDP_AUX_EAV_POS_ADJ(pval)                   ATV_I2CGetField32(VRX_SDP_IO_MAP_ADDR, 0x8C, 0xF, 0xFF, 0, 2, pval)
#define VRX_ret_SDP_AUX_EAV_POS_ADJ()                       ATV_I2CReadField32(VRX_SDP_IO_MAP_ADDR, 0x8C, 0xF, 0xFF, 0, 2)
#define VRX_set_SDP_AUX_EAV_POS_ADJ(val)                    ATV_I2CWriteField32(VRX_SDP_IO_MAP_ADDR, 0x8C, 0xF, 0xFF, 0, 2, val)

#define VRX_get_SDP_AUX_SAV_POS_ADJ(pval)                   ATV_I2CGetField32(VRX_SDP_IO_MAP_ADDR, 0x8E, 0xF, 0xFF, 0, 2, pval)
#define VRX_ret_SDP_AUX_SAV_POS_ADJ()                       ATV_I2CReadField32(VRX_SDP_IO_MAP_ADDR, 0x8E, 0xF, 0xFF, 0, 2)
#define VRX_set_SDP_AUX_SAV_POS_ADJ(val)                    ATV_I2CWriteField32(VRX_SDP_IO_MAP_ADDR, 0x8E, 0xF, 0xFF, 0, 2, val)

#define VRX_get_SDP_EAV_POS_ADJ(pval)                       ATV_I2CGetField32(VRX_SDP_IO_MAP_ADDR, 0x90, 0xF, 0xFF, 0, 2, pval)
#define VRX_ret_SDP_EAV_POS_ADJ()                           ATV_I2CReadField32(VRX_SDP_IO_MAP_ADDR, 0x90, 0xF, 0xFF, 0, 2)
#define VRX_set_SDP_EAV_POS_ADJ(val)                        ATV_I2CWriteField32(VRX_SDP_IO_MAP_ADDR, 0x90, 0xF, 0xFF, 0, 2, val)

#define VRX_get_SDP_SAV_POS_ADJ(pval)                       ATV_I2CGetField32(VRX_SDP_IO_MAP_ADDR, 0x92, 0xF, 0xFF, 0, 2, pval)
#define VRX_ret_SDP_SAV_POS_ADJ()                           ATV_I2CReadField32(VRX_SDP_IO_MAP_ADDR, 0x92, 0xF, 0xFF, 0, 2)
#define VRX_set_SDP_SAV_POS_ADJ(val)                        ATV_I2CWriteField32(VRX_SDP_IO_MAP_ADDR, 0x92, 0xF, 0xFF, 0, 2, val)

#define VRX_get_SDP_HS_BEG_ADJ(pval)                        ATV_I2CGetField32(VRX_SDP_IO_MAP_ADDR, 0x94, 0xF, 0xFF, 0, 2, pval)
#define VRX_ret_SDP_HS_BEG_ADJ()                            ATV_I2CReadField32(VRX_SDP_IO_MAP_ADDR, 0x94, 0xF, 0xFF, 0, 2)
#define VRX_set_SDP_HS_BEG_ADJ(val)                         ATV_I2CWriteField32(VRX_SDP_IO_MAP_ADDR, 0x94, 0xF, 0xFF, 0, 2, val)

#define VRX_get_SDP_HS_WIDTH(pval)                          ATV_I2CGetField32(VRX_SDP_IO_MAP_ADDR, 0x96, 0xF, 0xFF, 0, 2, pval)
#define VRX_ret_SDP_HS_WIDTH()                              ATV_I2CReadField32(VRX_SDP_IO_MAP_ADDR, 0x96, 0xF, 0xFF, 0, 2)
#define VRX_set_SDP_HS_WIDTH(val)                           ATV_I2CWriteField32(VRX_SDP_IO_MAP_ADDR, 0x96, 0xF, 0xFF, 0, 2, val)

#define VRX_get_SDP_DE_H_BEG_ADJ(pval)                      ATV_I2CGetField32(VRX_SDP_IO_MAP_ADDR, 0x98, 0xF, 0xFF, 0, 2, pval)
#define VRX_ret_SDP_DE_H_BEG_ADJ()                          ATV_I2CReadField32(VRX_SDP_IO_MAP_ADDR, 0x98, 0xF, 0xFF, 0, 2)
#define VRX_set_SDP_DE_H_BEG_ADJ(val)                       ATV_I2CWriteField32(VRX_SDP_IO_MAP_ADDR, 0x98, 0xF, 0xFF, 0, 2, val)

#define VRX_get_SDP_DE_H_END_ADJ(pval)                      ATV_I2CGetField32(VRX_SDP_IO_MAP_ADDR, 0x9A, 0xF, 0xFF, 0, 2, pval)
#define VRX_ret_SDP_DE_H_END_ADJ()                          ATV_I2CReadField32(VRX_SDP_IO_MAP_ADDR, 0x9A, 0xF, 0xFF, 0, 2)
#define VRX_set_SDP_DE_H_END_ADJ(val)                       ATV_I2CWriteField32(VRX_SDP_IO_MAP_ADDR, 0x9A, 0xF, 0xFF, 0, 2, val)

#define VRX_get_SDP_VSF_H_BEG_ADJ(pval)                     ATV_I2CGetField32(VRX_SDP_IO_MAP_ADDR, 0x9C, 0xF, 0xFF, 0, 2, pval)
#define VRX_ret_SDP_VSF_H_BEG_ADJ()                         ATV_I2CReadField32(VRX_SDP_IO_MAP_ADDR, 0x9C, 0xF, 0xFF, 0, 2)
#define VRX_set_SDP_VSF_H_BEG_ADJ(val)                      ATV_I2CWriteField32(VRX_SDP_IO_MAP_ADDR, 0x9C, 0xF, 0xFF, 0, 2, val)

#define VRX_get_SDP_VSF_H_MID_ADJ(pval)                     ATV_I2CGetField32(VRX_SDP_IO_MAP_ADDR, 0x9E, 0xF, 0xFF, 0, 2, pval)
#define VRX_ret_SDP_VSF_H_MID_ADJ()                         ATV_I2CReadField32(VRX_SDP_IO_MAP_ADDR, 0x9E, 0xF, 0xFF, 0, 2)
#define VRX_set_SDP_VSF_H_MID_ADJ(val)                      ATV_I2CWriteField32(VRX_SDP_IO_MAP_ADDR, 0x9E, 0xF, 0xFF, 0, 2, val)

#define VRX_get_SDP_V_BEG_O_ADJ(pval)                       ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xA0, 0x3F, 0, pval)
#define VRX_ret_SDP_V_BEG_O_ADJ()                           ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xA0, 0x3F, 0)
#define VRX_set_SDP_V_BEG_O_ADJ(val)                        ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xA0, 0x3F, 0, val)

#define VRX_get_SDP_V_BEG_E_ADJ(pval)                       ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xA1, 0x3F, 0, pval)
#define VRX_ret_SDP_V_BEG_E_ADJ()                           ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xA1, 0x3F, 0)
#define VRX_set_SDP_V_BEG_E_ADJ(val)                        ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xA1, 0x3F, 0, val)

#define VRX_get_SDP_V_END_O_ADJ(pval)                       ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xA2, 0x3F, 0, pval)
#define VRX_ret_SDP_V_END_O_ADJ()                           ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xA2, 0x3F, 0)
#define VRX_set_SDP_V_END_O_ADJ(val)                        ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xA2, 0x3F, 0, val)

#define VRX_get_SDP_V_END_E_ADJ(pval)                       ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xA3, 0x3F, 0, pval)
#define VRX_ret_SDP_V_END_E_ADJ()                           ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xA3, 0x3F, 0)
#define VRX_set_SDP_V_END_E_ADJ(val)                        ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xA3, 0x3F, 0, val)

#define VRX_get_SDP_F_TOG_O_ADJ(pval)                       ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xA4, 0x3F, 0, pval)
#define VRX_ret_SDP_F_TOG_O_ADJ()                           ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xA4, 0x3F, 0)
#define VRX_set_SDP_F_TOG_O_ADJ(val)                        ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xA4, 0x3F, 0, val)

#define VRX_get_SDP_F_TOG_E_ADJ(pval)                       ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xA5, 0x3F, 0, pval)
#define VRX_ret_SDP_F_TOG_E_ADJ()                           ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xA5, 0x3F, 0)
#define VRX_set_SDP_F_TOG_E_ADJ(val)                        ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xA5, 0x3F, 0, val)

#define VRX_get_SDP_FLD_TOG_O_ADJ(pval)                     ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xA6, 0x3F, 0, pval)
#define VRX_ret_SDP_FLD_TOG_O_ADJ()                         ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xA6, 0x3F, 0)
#define VRX_set_SDP_FLD_TOG_O_ADJ(val)                      ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xA6, 0x3F, 0, val)

#define VRX_get_SDP_FLD_TOG_E_ADJ(pval)                     ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xA7, 0x3F, 0, pval)
#define VRX_ret_SDP_FLD_TOG_E_ADJ()                         ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xA7, 0x3F, 0)
#define VRX_set_SDP_FLD_TOG_E_ADJ(val)                      ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xA7, 0x3F, 0, val)

#define VRX_get_SDP_VS_V_BEG_O_ADJ(pval)                    ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xA8, 0x3F, 0, pval)
#define VRX_ret_SDP_VS_V_BEG_O_ADJ()                        ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xA8, 0x3F, 0)
#define VRX_set_SDP_VS_V_BEG_O_ADJ(val)                     ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xA8, 0x3F, 0, val)

#define VRX_get_SDP_VS_V_BEG_E_ADJ(pval)                    ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xA9, 0x3F, 0, pval)
#define VRX_ret_SDP_VS_V_BEG_E_ADJ()                        ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xA9, 0x3F, 0)
#define VRX_set_SDP_VS_V_BEG_E_ADJ(val)                     ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xA9, 0x3F, 0, val)

#define VRX_get_SDP_VS_V_END_O_ADJ(pval)                    ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xAA, 0x3F, 0, pval)
#define VRX_ret_SDP_VS_V_END_O_ADJ()                        ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xAA, 0x3F, 0)
#define VRX_set_SDP_VS_V_END_O_ADJ(val)                     ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xAA, 0x3F, 0, val)

#define VRX_get_SDP_VS_V_END_E_ADJ(pval)                    ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xAB, 0x3F, 0, pval)
#define VRX_ret_SDP_VS_V_END_E_ADJ()                        ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xAB, 0x3F, 0)
#define VRX_set_SDP_VS_V_END_E_ADJ(val)                     ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xAB, 0x3F, 0, val)

#define VRX_get_SDP_DE_V_BEG_O_ADJ(pval)                    ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xAC, 0x3F, 0, pval)
#define VRX_ret_SDP_DE_V_BEG_O_ADJ()                        ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xAC, 0x3F, 0)
#define VRX_set_SDP_DE_V_BEG_O_ADJ(val)                     ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xAC, 0x3F, 0, val)

#define VRX_get_SDP_DE_V_BEG_E_ADJ(pval)                    ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xAD, 0x3F, 0, pval)
#define VRX_ret_SDP_DE_V_BEG_E_ADJ()                        ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xAD, 0x3F, 0)
#define VRX_set_SDP_DE_V_BEG_E_ADJ(val)                     ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xAD, 0x3F, 0, val)

#define VRX_get_SDP_DE_V_END_O_ADJ(pval)                    ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xAE, 0x3F, 0, pval)
#define VRX_ret_SDP_DE_V_END_O_ADJ()                        ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xAE, 0x3F, 0)
#define VRX_set_SDP_DE_V_END_O_ADJ(val)                     ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xAE, 0x3F, 0, val)

#define VRX_get_SDP_DE_V_END_E_ADJ(pval)                    ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xAF, 0x3F, 0, pval)
#define VRX_ret_SDP_DE_V_END_E_ADJ()                        ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xAF, 0x3F, 0)
#define VRX_set_SDP_DE_V_END_E_ADJ(val)                     ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xAF, 0x3F, 0, val)

#define VRX_is_SDP_VBLANK_EN_true()                         ATV_I2CIsField8(VRX_SDP_IO_MAP_ADDR, 0xB0, 0x80, 0x7)
#define VRX_get_SDP_VBLANK_EN(pval)                         ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xB0, 0x80, 0x7, pval)
#define VRX_ret_SDP_VBLANK_EN()                             ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xB0, 0x80, 0x7)
#define VRX_set_SDP_VBLANK_EN(val)                          ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xB0, 0x80, 0x7, val)

#define VRX_is_SDP_HBLANK_EN_true()                         ATV_I2CIsField8(VRX_SDP_IO_MAP_ADDR, 0xB0, 0x40, 0x6)
#define VRX_get_SDP_HBLANK_EN(pval)                         ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xB0, 0x40, 0x6, pval)
#define VRX_ret_SDP_HBLANK_EN()                             ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xB0, 0x40, 0x6)
#define VRX_set_SDP_HBLANK_EN(val)                          ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xB0, 0x40, 0x6, val)

#define VRX_is_SDP_FHE_TOG_INV_true()                       ATV_I2CIsField8(VRX_SDP_IO_MAP_ADDR, 0xB0, 0x20, 0x5)
#define VRX_get_SDP_FHE_TOG_INV(pval)                       ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xB0, 0x20, 0x5, pval)
#define VRX_ret_SDP_FHE_TOG_INV()                           ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xB0, 0x20, 0x5)
#define VRX_set_SDP_FHE_TOG_INV(val)                        ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xB0, 0x20, 0x5, val)

#define VRX_is_SDP_FHO_TOG_INV_true()                       ATV_I2CIsField8(VRX_SDP_IO_MAP_ADDR, 0xB0, 0x10, 0x4)
#define VRX_get_SDP_FHO_TOG_INV(pval)                       ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xB0, 0x10, 0x4, pval)
#define VRX_ret_SDP_FHO_TOG_INV()                           ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xB0, 0x10, 0x4)
#define VRX_set_SDP_FHO_TOG_INV(val)                        ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xB0, 0x10, 0x4, val)

#define VRX_is_SDP_VHE_END_INV_true()                       ATV_I2CIsField8(VRX_SDP_IO_MAP_ADDR, 0xB0, 0x8, 0x3)
#define VRX_get_SDP_VHE_END_INV(pval)                       ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xB0, 0x8, 0x3, pval)
#define VRX_ret_SDP_VHE_END_INV()                           ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xB0, 0x8, 0x3)
#define VRX_set_SDP_VHE_END_INV(val)                        ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xB0, 0x8, 0x3, val)

#define VRX_is_SDP_VHO_END_INV_true()                       ATV_I2CIsField8(VRX_SDP_IO_MAP_ADDR, 0xB0, 0x4, 0x2)
#define VRX_get_SDP_VHO_END_INV(pval)                       ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xB0, 0x4, 0x2, pval)
#define VRX_ret_SDP_VHO_END_INV()                           ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xB0, 0x4, 0x2)
#define VRX_set_SDP_VHO_END_INV(val)                        ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xB0, 0x4, 0x2, val)

#define VRX_is_SDP_VHE_BEG_INV_true()                       ATV_I2CIsField8(VRX_SDP_IO_MAP_ADDR, 0xB0, 0x2, 0x1)
#define VRX_get_SDP_VHE_BEG_INV(pval)                       ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xB0, 0x2, 0x1, pval)
#define VRX_ret_SDP_VHE_BEG_INV()                           ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xB0, 0x2, 0x1)
#define VRX_set_SDP_VHE_BEG_INV(val)                        ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xB0, 0x2, 0x1, val)

#define VRX_is_SDP_VHO_BEG_INV_true()                       ATV_I2CIsField8(VRX_SDP_IO_MAP_ADDR, 0xB0, 0x1, 0x0)
#define VRX_get_SDP_VHO_BEG_INV(pval)                       ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xB0, 0x1, 0x0, pval)
#define VRX_ret_SDP_VHO_BEG_INV()                           ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xB0, 0x1, 0x0)
#define VRX_set_SDP_VHO_BEG_INV(val)                        ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xB0, 0x1, 0x0, val)

#define VRX_is_SDP_V_BIT_POL_true()                         ATV_I2CIsField8(VRX_SDP_IO_MAP_ADDR, 0xB1, 0x40, 0x6)
#define VRX_get_SDP_V_BIT_POL(pval)                         ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xB1, 0x40, 0x6, pval)
#define VRX_ret_SDP_V_BIT_POL()                             ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xB1, 0x40, 0x6)
#define VRX_set_SDP_V_BIT_POL(val)                          ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xB1, 0x40, 0x6, val)

#define VRX_is_SDP_F_BIT_POL_true()                         ATV_I2CIsField8(VRX_SDP_IO_MAP_ADDR, 0xB1, 0x20, 0x5)
#define VRX_get_SDP_F_BIT_POL(pval)                         ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xB1, 0x20, 0x5, pval)
#define VRX_ret_SDP_F_BIT_POL()                             ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xB1, 0x20, 0x5)
#define VRX_set_SDP_F_BIT_POL(val)                          ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xB1, 0x20, 0x5, val)

#define VRX_is_SDP_DE_POL_true()                            ATV_I2CIsField8(VRX_SDP_IO_MAP_ADDR, 0xB1, 0x10, 0x4)
#define VRX_get_SDP_DE_POL(pval)                            ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xB1, 0x10, 0x4, pval)
#define VRX_ret_SDP_DE_POL()                                ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xB1, 0x10, 0x4)
#define VRX_set_SDP_DE_POL(val)                             ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xB1, 0x10, 0x4, val)

#define VRX_is_SDP_CS_POL_true()                            ATV_I2CIsField8(VRX_SDP_IO_MAP_ADDR, 0xB1, 0x8, 0x3)
#define VRX_get_SDP_CS_POL(pval)                            ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xB1, 0x8, 0x3, pval)
#define VRX_ret_SDP_CS_POL()                                ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xB1, 0x8, 0x3)
#define VRX_set_SDP_CS_POL(val)                             ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xB1, 0x8, 0x3, val)

#define VRX_is_SDP_FLD_POL_true()                           ATV_I2CIsField8(VRX_SDP_IO_MAP_ADDR, 0xB1, 0x4, 0x2)
#define VRX_get_SDP_FLD_POL(pval)                           ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xB1, 0x4, 0x2, pval)
#define VRX_ret_SDP_FLD_POL()                               ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xB1, 0x4, 0x2)
#define VRX_set_SDP_FLD_POL(val)                            ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xB1, 0x4, 0x2, val)

#define VRX_is_SDP_VS_POL_true()                            ATV_I2CIsField8(VRX_SDP_IO_MAP_ADDR, 0xB1, 0x2, 0x1)
#define VRX_get_SDP_VS_POL(pval)                            ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xB1, 0x2, 0x1, pval)
#define VRX_ret_SDP_VS_POL()                                ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xB1, 0x2, 0x1)
#define VRX_set_SDP_VS_POL(val)                             ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xB1, 0x2, 0x1, val)

#define VRX_is_SDP_HS_POL_true()                            ATV_I2CIsField8(VRX_SDP_IO_MAP_ADDR, 0xB1, 0x1, 0x0)
#define VRX_get_SDP_HS_POL(pval)                            ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xB1, 0x1, 0x0, pval)
#define VRX_ret_SDP_HS_POL()                                ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xB1, 0x1, 0x0)
#define VRX_set_SDP_HS_POL(val)                             ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xB1, 0x1, 0x0, val)

#define VRX_is_SDP_EAV_EN_true()                            ATV_I2CIsField8(VRX_SDP_IO_MAP_ADDR, 0xB2, 0x8, 0x3)
#define VRX_get_SDP_EAV_EN(pval)                            ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xB2, 0x8, 0x3, pval)
#define VRX_ret_SDP_EAV_EN()                                ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xB2, 0x8, 0x3)
#define VRX_set_SDP_EAV_EN(val)                             ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xB2, 0x8, 0x3, val)

#define VRX_is_SDP_SAV_EN_true()                            ATV_I2CIsField8(VRX_SDP_IO_MAP_ADDR, 0xB2, 0x4, 0x2)
#define VRX_get_SDP_SAV_EN(pval)                            ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xB2, 0x4, 0x2, pval)
#define VRX_ret_SDP_SAV_EN()                                ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xB2, 0x4, 0x2)
#define VRX_set_SDP_SAV_EN(val)                             ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xB2, 0x4, 0x2, val)

#define VRX_is_SDP_FRZ_F_BIT_true()                         ATV_I2CIsField8(VRX_SDP_IO_MAP_ADDR, 0xB2, 0x2, 0x1)
#define VRX_get_SDP_FRZ_F_BIT(pval)                         ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xB2, 0x2, 0x1, pval)
#define VRX_ret_SDP_FRZ_F_BIT()                             ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xB2, 0x2, 0x1)
#define VRX_set_SDP_FRZ_F_BIT(val)                          ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xB2, 0x2, 0x1, val)

#define VRX_is_SDP_REPL_ANC_DATA_true()                     ATV_I2CIsField8(VRX_SDP_IO_MAP_ADDR, 0xB3, 0x80, 0x7)
#define VRX_get_SDP_REPL_ANC_DATA(pval)                     ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xB3, 0x80, 0x7, pval)
#define VRX_ret_SDP_REPL_ANC_DATA()                         ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xB3, 0x80, 0x7)
#define VRX_set_SDP_REPL_ANC_DATA(val)                      ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xB3, 0x80, 0x7, val)

#define VRX_is_SDP_SPLIT_ANC_DATA_true()                    ATV_I2CIsField8(VRX_SDP_IO_MAP_ADDR, 0xB3, 0x40, 0x6)
#define VRX_get_SDP_SPLIT_ANC_DATA(pval)                    ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xB3, 0x40, 0x6, pval)
#define VRX_ret_SDP_SPLIT_ANC_DATA()                        ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xB3, 0x40, 0x6)
#define VRX_set_SDP_SPLIT_ANC_DATA(val)                     ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xB3, 0x40, 0x6, val)

#define VRX_is_SDP_SPLIT_AV_CODE_true()                     ATV_I2CIsField8(VRX_SDP_IO_MAP_ADDR, 0xB3, 0x20, 0x5)
#define VRX_get_SDP_SPLIT_AV_CODE(pval)                     ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xB3, 0x20, 0x5, pval)
#define VRX_ret_SDP_SPLIT_AV_CODE()                         ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xB3, 0x20, 0x5)
#define VRX_set_SDP_SPLIT_AV_CODE(val)                      ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xB3, 0x20, 0x5, val)

#define VRX_get_SDP_V_BEG_TRICK_O_ADJ(pval)                 ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xB4, 0x3F, 0, pval)
#define VRX_ret_SDP_V_BEG_TRICK_O_ADJ()                     ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xB4, 0x3F, 0)
#define VRX_set_SDP_V_BEG_TRICK_O_ADJ(val)                  ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xB4, 0x3F, 0, val)

#define VRX_get_SDP_V_BEG_TRICK_E_ADJ(pval)                 ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xB5, 0x3F, 0, pval)
#define VRX_ret_SDP_V_BEG_TRICK_E_ADJ()                     ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xB5, 0x3F, 0)
#define VRX_set_SDP_V_BEG_TRICK_E_ADJ(val)                  ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xB5, 0x3F, 0, val)

#define VRX_get_SDP_V_END_TRICK_O_ADJ(pval)                 ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xB6, 0x3F, 0, pval)
#define VRX_ret_SDP_V_END_TRICK_O_ADJ()                     ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xB6, 0x3F, 0)
#define VRX_set_SDP_V_END_TRICK_O_ADJ(val)                  ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xB6, 0x3F, 0, val)

#define VRX_get_SDP_V_END_TRICK_E_ADJ(pval)                 ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xB7, 0x3F, 0, pval)
#define VRX_ret_SDP_V_END_TRICK_E_ADJ()                     ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xB7, 0x3F, 0)
#define VRX_set_SDP_V_END_TRICK_E_ADJ(val)                  ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xB7, 0x3F, 0, val)

#define VRX_get_SDP_F_TOG_TRICK_O_ADJ(pval)                 ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xB8, 0x3F, 0, pval)
#define VRX_ret_SDP_F_TOG_TRICK_O_ADJ()                     ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xB8, 0x3F, 0)
#define VRX_set_SDP_F_TOG_TRICK_O_ADJ(val)                  ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xB8, 0x3F, 0, val)

#define VRX_get_SDP_F_TOG_TRICK_E_ADJ(pval)                 ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xB9, 0x3F, 0, pval)
#define VRX_ret_SDP_F_TOG_TRICK_E_ADJ()                     ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xB9, 0x3F, 0)
#define VRX_set_SDP_F_TOG_TRICK_E_ADJ(val)                  ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xB9, 0x3F, 0, val)

#define VRX_get_SDP_AUX_V_BEG_O_ADJ(pval)                   ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xC2, 0x3F, 0, pval)
#define VRX_ret_SDP_AUX_V_BEG_O_ADJ()                       ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xC2, 0x3F, 0)
#define VRX_set_SDP_AUX_V_BEG_O_ADJ(val)                    ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xC2, 0x3F, 0, val)

#define VRX_get_SDP_AUX_V_BEG_E_ADJ(pval)                   ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xC3, 0x3F, 0, pval)
#define VRX_ret_SDP_AUX_V_BEG_E_ADJ()                       ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xC3, 0x3F, 0)
#define VRX_set_SDP_AUX_V_BEG_E_ADJ(val)                    ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xC3, 0x3F, 0, val)

#define VRX_get_SDP_AUX_V_END_O_ADJ(pval)                   ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xC4, 0x3F, 0, pval)
#define VRX_ret_SDP_AUX_V_END_O_ADJ()                       ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xC4, 0x3F, 0)
#define VRX_set_SDP_AUX_V_END_O_ADJ(val)                    ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xC4, 0x3F, 0, val)

#define VRX_get_SDP_AUX_V_END_E_ADJ(pval)                   ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xC5, 0x3F, 0, pval)
#define VRX_ret_SDP_AUX_V_END_E_ADJ()                       ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xC5, 0x3F, 0)
#define VRX_set_SDP_AUX_V_END_E_ADJ(val)                    ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xC5, 0x3F, 0, val)

#define VRX_get_SDP_AUX_F_TOG_O_ADJ(pval)                   ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xC6, 0x3F, 0, pval)
#define VRX_ret_SDP_AUX_F_TOG_O_ADJ()                       ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xC6, 0x3F, 0)
#define VRX_set_SDP_AUX_F_TOG_O_ADJ(val)                    ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xC6, 0x3F, 0, val)

#define VRX_get_SDP_AUX_F_TOG_E_ADJ(pval)                   ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xC7, 0x3F, 0, pval)
#define VRX_ret_SDP_AUX_F_TOG_E_ADJ()                       ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xC7, 0x3F, 0)
#define VRX_set_SDP_AUX_F_TOG_E_ADJ(val)                    ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xC7, 0x3F, 0, val)

#define VRX_is_SDP_AUX_V_BIT_POL_true()                     ATV_I2CIsField8(VRX_SDP_IO_MAP_ADDR, 0xC8, 0x40, 0x6)
#define VRX_get_SDP_AUX_V_BIT_POL(pval)                     ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xC8, 0x40, 0x6, pval)
#define VRX_ret_SDP_AUX_V_BIT_POL()                         ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xC8, 0x40, 0x6)
#define VRX_set_SDP_AUX_V_BIT_POL(val)                      ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xC8, 0x40, 0x6, val)

#define VRX_is_SDP_AUX_F_BIT_POL_true()                     ATV_I2CIsField8(VRX_SDP_IO_MAP_ADDR, 0xC8, 0x20, 0x5)
#define VRX_get_SDP_AUX_F_BIT_POL(pval)                     ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xC8, 0x20, 0x5, pval)
#define VRX_ret_SDP_AUX_F_BIT_POL()                         ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xC8, 0x20, 0x5)
#define VRX_set_SDP_AUX_F_BIT_POL(val)                      ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xC8, 0x20, 0x5, val)

#define VRX_is_SDP_ANC_MAIN_EN_true()                       ATV_I2CIsField8(VRX_SDP_IO_MAP_ADDR, 0xC8, 0x8, 0x3)
#define VRX_get_SDP_ANC_MAIN_EN(pval)                       ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xC8, 0x8, 0x3, pval)
#define VRX_ret_SDP_ANC_MAIN_EN()                           ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xC8, 0x8, 0x3)
#define VRX_set_SDP_ANC_MAIN_EN(val)                        ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xC8, 0x8, 0x3, val)

#define VRX_is_SDP_ANC_AUX_EN_true()                        ATV_I2CIsField8(VRX_SDP_IO_MAP_ADDR, 0xC8, 0x4, 0x2)
#define VRX_get_SDP_ANC_AUX_EN(pval)                        ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xC8, 0x4, 0x2, pval)
#define VRX_ret_SDP_ANC_AUX_EN()                            ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xC8, 0x4, 0x2)
#define VRX_set_SDP_ANC_AUX_EN(val)                         ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xC8, 0x4, 0x2, val)

#define VRX_is_SDP_AUX_VBLANK_EN_true()                     ATV_I2CIsField8(VRX_SDP_IO_MAP_ADDR, 0xC8, 0x2, 0x1)
#define VRX_get_SDP_AUX_VBLANK_EN(pval)                     ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xC8, 0x2, 0x1, pval)
#define VRX_ret_SDP_AUX_VBLANK_EN()                         ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xC8, 0x2, 0x1)
#define VRX_set_SDP_AUX_VBLANK_EN(val)                      ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xC8, 0x2, 0x1, val)

#define VRX_is_SDP_AUX_HBLANK_EN_true()                     ATV_I2CIsField8(VRX_SDP_IO_MAP_ADDR, 0xC8, 0x1, 0x0)
#define VRX_get_SDP_AUX_HBLANK_EN(pval)                     ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xC8, 0x1, 0x0, pval)
#define VRX_ret_SDP_AUX_HBLANK_EN()                         ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xC8, 0x1, 0x0)
#define VRX_set_SDP_AUX_HBLANK_EN(val)                      ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xC8, 0x1, 0x0, val)

#define VRX_is_SDP_AUX_REPL_AV_CODE_true()                  ATV_I2CIsField8(VRX_SDP_IO_MAP_ADDR, 0xC9, 0x10, 0x4)
#define VRX_get_SDP_AUX_REPL_AV_CODE(pval)                  ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xC9, 0x10, 0x4, pval)
#define VRX_ret_SDP_AUX_REPL_AV_CODE()                      ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xC9, 0x10, 0x4)
#define VRX_set_SDP_AUX_REPL_AV_CODE(val)                   ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xC9, 0x10, 0x4, val)

#define VRX_is_SDP_AUX_EAV_EN_true()                        ATV_I2CIsField8(VRX_SDP_IO_MAP_ADDR, 0xC9, 0x8, 0x3)
#define VRX_get_SDP_AUX_EAV_EN(pval)                        ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xC9, 0x8, 0x3, pval)
#define VRX_ret_SDP_AUX_EAV_EN()                            ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xC9, 0x8, 0x3)
#define VRX_set_SDP_AUX_EAV_EN(val)                         ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xC9, 0x8, 0x3, val)

#define VRX_is_SDP_AUX_SAV_EN_true()                        ATV_I2CIsField8(VRX_SDP_IO_MAP_ADDR, 0xC9, 0x4, 0x2)
#define VRX_get_SDP_AUX_SAV_EN(pval)                        ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xC9, 0x4, 0x2, pval)
#define VRX_ret_SDP_AUX_SAV_EN()                            ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xC9, 0x4, 0x2)
#define VRX_set_SDP_AUX_SAV_EN(val)                         ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xC9, 0x4, 0x2, val)

#define VRX_is_SDP_CSC_SCALE_true()                         ATV_I2CIsField8(VRX_SDP_IO_MAP_ADDR, 0xE0, 0x80, 0x7)
#define VRX_get_SDP_CSC_SCALE(pval)                         ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xE0, 0x80, 0x7, pval)
#define VRX_ret_SDP_CSC_SCALE()                             ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xE0, 0x80, 0x7)
#define VRX_set_SDP_CSC_SCALE(val)                          ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xE0, 0x80, 0x7, val)

#define VRX_is_SDP_CSC_AUTO_true()                          ATV_I2CIsField8(VRX_SDP_IO_MAP_ADDR, 0xE0, 0x40, 0x6)
#define VRX_get_SDP_CSC_AUTO(pval)                          ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xE0, 0x40, 0x6, pval)
#define VRX_ret_SDP_CSC_AUTO()                              ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xE0, 0x40, 0x6)
#define VRX_set_SDP_CSC_AUTO(val)                           ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xE0, 0x40, 0x6, val)

#define VRX_is_SDP_RET_VID_ADJ_true()                       ATV_I2CIsField8(VRX_SDP_IO_MAP_ADDR, 0xE0, 0x20, 0x5)
#define VRX_get_SDP_RET_VID_ADJ(pval)                       ATV_I2CGetField8(VRX_SDP_IO_MAP_ADDR, 0xE0, 0x20, 0x5, pval)
#define VRX_ret_SDP_RET_VID_ADJ()                           ATV_I2CReadField8(VRX_SDP_IO_MAP_ADDR, 0xE0, 0x20, 0x5)
#define VRX_set_SDP_RET_VID_ADJ(val)                        ATV_I2CWriteField8(VRX_SDP_IO_MAP_ADDR, 0xE0, 0x20, 0x5, val)

#define VRX_get_SDP_A1(pval)                                ATV_I2CGetField32(VRX_SDP_IO_MAP_ADDR, 0xE0, 0x1F, 0xFF, 0, 2, pval)
#define VRX_ret_SDP_A1()                                    ATV_I2CReadField32(VRX_SDP_IO_MAP_ADDR, 0xE0, 0x1F, 0xFF, 0, 2)
#define VRX_set_SDP_A1(val)                                 ATV_I2CWriteField32(VRX_SDP_IO_MAP_ADDR, 0xE0, 0x1F, 0xFF, 0, 2, val)

#define VRX_get_SDP_A2(pval)                                ATV_I2CGetField32(VRX_SDP_IO_MAP_ADDR, 0xE2, 0x1F, 0xFF, 0, 2, pval)
#define VRX_ret_SDP_A2()                                    ATV_I2CReadField32(VRX_SDP_IO_MAP_ADDR, 0xE2, 0x1F, 0xFF, 0, 2)
#define VRX_set_SDP_A2(val)                                 ATV_I2CWriteField32(VRX_SDP_IO_MAP_ADDR, 0xE2, 0x1F, 0xFF, 0, 2, val)

#define VRX_get_SDP_A3(pval)                                ATV_I2CGetField32(VRX_SDP_IO_MAP_ADDR, 0xE4, 0x1F, 0xFF, 0, 2, pval)
#define VRX_ret_SDP_A3()                                    ATV_I2CReadField32(VRX_SDP_IO_MAP_ADDR, 0xE4, 0x1F, 0xFF, 0, 2)
#define VRX_set_SDP_A3(val)                                 ATV_I2CWriteField32(VRX_SDP_IO_MAP_ADDR, 0xE4, 0x1F, 0xFF, 0, 2, val)

#define VRX_get_SDP_A4(pval)                                ATV_I2CGetField32(VRX_SDP_IO_MAP_ADDR, 0xE6, 0x7F, 0xFF, 0, 2, pval)
#define VRX_ret_SDP_A4()                                    ATV_I2CReadField32(VRX_SDP_IO_MAP_ADDR, 0xE6, 0x7F, 0xFF, 0, 2)
#define VRX_set_SDP_A4(val)                                 ATV_I2CWriteField32(VRX_SDP_IO_MAP_ADDR, 0xE6, 0x7F, 0xFF, 0, 2, val)

#define VRX_get_SDP_B1(pval)                                ATV_I2CGetField32(VRX_SDP_IO_MAP_ADDR, 0xE8, 0x1F, 0xFF, 0, 2, pval)
#define VRX_ret_SDP_B1()                                    ATV_I2CReadField32(VRX_SDP_IO_MAP_ADDR, 0xE8, 0x1F, 0xFF, 0, 2)
#define VRX_set_SDP_B1(val)                                 ATV_I2CWriteField32(VRX_SDP_IO_MAP_ADDR, 0xE8, 0x1F, 0xFF, 0, 2, val)

#define VRX_get_SDP_B2(pval)                                ATV_I2CGetField32(VRX_SDP_IO_MAP_ADDR, 0xEA, 0x1F, 0xFF, 0, 2, pval)
#define VRX_ret_SDP_B2()                                    ATV_I2CReadField32(VRX_SDP_IO_MAP_ADDR, 0xEA, 0x1F, 0xFF, 0, 2)
#define VRX_set_SDP_B2(val)                                 ATV_I2CWriteField32(VRX_SDP_IO_MAP_ADDR, 0xEA, 0x1F, 0xFF, 0, 2, val)

#define VRX_get_SDP_B3(pval)                                ATV_I2CGetField32(VRX_SDP_IO_MAP_ADDR, 0xEC, 0x1F, 0xFF, 0, 2, pval)
#define VRX_ret_SDP_B3()                                    ATV_I2CReadField32(VRX_SDP_IO_MAP_ADDR, 0xEC, 0x1F, 0xFF, 0, 2)
#define VRX_set_SDP_B3(val)                                 ATV_I2CWriteField32(VRX_SDP_IO_MAP_ADDR, 0xEC, 0x1F, 0xFF, 0, 2, val)

#define VRX_get_SDP_B4(pval)                                ATV_I2CGetField32(VRX_SDP_IO_MAP_ADDR, 0xEE, 0x7F, 0xFF, 0, 2, pval)
#define VRX_ret_SDP_B4()                                    ATV_I2CReadField32(VRX_SDP_IO_MAP_ADDR, 0xEE, 0x7F, 0xFF, 0, 2)
#define VRX_set_SDP_B4(val)                                 ATV_I2CWriteField32(VRX_SDP_IO_MAP_ADDR, 0xEE, 0x7F, 0xFF, 0, 2, val)

#define VRX_get_SDP_C1(pval)                                ATV_I2CGetField32(VRX_SDP_IO_MAP_ADDR, 0xF0, 0x1F, 0xFF, 0, 2, pval)
#define VRX_ret_SDP_C1()                                    ATV_I2CReadField32(VRX_SDP_IO_MAP_ADDR, 0xF0, 0x1F, 0xFF, 0, 2)
#define VRX_set_SDP_C1(val)                                 ATV_I2CWriteField32(VRX_SDP_IO_MAP_ADDR, 0xF0, 0x1F, 0xFF, 0, 2, val)

#define VRX_get_SDP_C2(pval)                                ATV_I2CGetField32(VRX_SDP_IO_MAP_ADDR, 0xF2, 0x1F, 0xFF, 0, 2, pval)
#define VRX_ret_SDP_C2()                                    ATV_I2CReadField32(VRX_SDP_IO_MAP_ADDR, 0xF2, 0x1F, 0xFF, 0, 2)
#define VRX_set_SDP_C2(val)                                 ATV_I2CWriteField32(VRX_SDP_IO_MAP_ADDR, 0xF2, 0x1F, 0xFF, 0, 2, val)

#define VRX_get_SDP_C3(pval)                                ATV_I2CGetField32(VRX_SDP_IO_MAP_ADDR, 0xF4, 0x1F, 0xFF, 0, 2, pval)
#define VRX_ret_SDP_C3()                                    ATV_I2CReadField32(VRX_SDP_IO_MAP_ADDR, 0xF4, 0x1F, 0xFF, 0, 2)
#define VRX_set_SDP_C3(val)                                 ATV_I2CWriteField32(VRX_SDP_IO_MAP_ADDR, 0xF4, 0x1F, 0xFF, 0, 2, val)

#define VRX_get_SDP_C4(pval)                                ATV_I2CGetField32(VRX_SDP_IO_MAP_ADDR, 0xF6, 0x7F, 0xFF, 0, 2, pval)
#define VRX_ret_SDP_C4()                                    ATV_I2CReadField32(VRX_SDP_IO_MAP_ADDR, 0xF6, 0x7F, 0xFF, 0, 2)
#define VRX_set_SDP_C4(val)                                 ATV_I2CWriteField32(VRX_SDP_IO_MAP_ADDR, 0xF6, 0x7F, 0xFF, 0, 2, val)

#endif
