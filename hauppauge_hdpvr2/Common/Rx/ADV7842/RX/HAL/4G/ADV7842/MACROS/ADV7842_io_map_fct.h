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
* DATE: 18 Nov 2009 15:43:0                                                    *
*                                                                              *
*******************************************************************************/


#ifndef ADV7842_IO_MAP_FCT_H
#define ADV7842_IO_MAP_FCT_H

#include "ADV7842_cfg.h"

#define VRX_get_VID_STD(pval)                               ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x00, 0x3F, 0, pval)
#define VRX_ret_VID_STD()                                   ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x00, 0x3F, 0)
#define VRX_set_VID_STD(val)                                ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x00, 0x3F, 0, val)

#define VRX_is_ADC_HDMI_SIMULT_MODE_true()                  ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x01, 0x80, 0x7)
#define VRX_get_ADC_HDMI_SIMULT_MODE(pval)                  ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x01, 0x80, 0x7, pval)
#define VRX_ret_ADC_HDMI_SIMULT_MODE()                      ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x01, 0x80, 0x7)
#define VRX_set_ADC_HDMI_SIMULT_MODE(val)                   ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x01, 0x80, 0x7, val)

#define VRX_get_V_FREQ(pval)                                ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x01, 0x70, 4, pval)
#define VRX_ret_V_FREQ()                                    ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x01, 0x70, 4)
#define VRX_set_V_FREQ(val)                                 ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x01, 0x70, 4, val)

#define VRX_get_PRIM_MODE(pval)                             ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x01, 0xF, 0, pval)
#define VRX_ret_PRIM_MODE()                                 ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x01, 0xF, 0)
#define VRX_set_PRIM_MODE(val)                              ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x01, 0xF, 0, val)

#define VRX_get_INP_COLOR_SPACE(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x02, 0xF0, 4, pval)
#define VRX_ret_INP_COLOR_SPACE()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x02, 0xF0, 4)
#define VRX_set_INP_COLOR_SPACE(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x02, 0xF0, 4, val)

#define VRX_is_ALT_GAMMA_true()                             ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x02, 0x8, 0x3)
#define VRX_get_ALT_GAMMA(pval)                             ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x02, 0x8, 0x3, pval)
#define VRX_ret_ALT_GAMMA()                                 ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x02, 0x8, 0x3)
#define VRX_set_ALT_GAMMA(val)                              ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x02, 0x8, 0x3, val)

#define VRX_is_OP_656_RANGE_true()                          ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x02, 0x4, 0x2)
#define VRX_get_OP_656_RANGE(pval)                          ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x02, 0x4, 0x2, pval)
#define VRX_ret_OP_656_RANGE()                              ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x02, 0x4, 0x2)
#define VRX_set_OP_656_RANGE(val)                           ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x02, 0x4, 0x2, val)

#define VRX_is_RGB_OUT_true()                               ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x02, 0x2, 0x1)
#define VRX_get_RGB_OUT(pval)                               ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x02, 0x2, 0x1, pval)
#define VRX_ret_RGB_OUT()                                   ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x02, 0x2, 0x1)
#define VRX_set_RGB_OUT(val)                                ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x02, 0x2, 0x1, val)

#define VRX_is_ALT_DATA_SAT_true()                          ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x02, 0x1, 0x0)
#define VRX_get_ALT_DATA_SAT(pval)                          ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x02, 0x1, 0x0, pval)
#define VRX_ret_ALT_DATA_SAT()                              ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x02, 0x1, 0x0)
#define VRX_set_ALT_DATA_SAT(val)                           ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x02, 0x1, 0x0, val)

#define VRX_get_OP_FORMAT_SEL(pval)                         ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x03, 0xFF, 0, pval)
#define VRX_ret_OP_FORMAT_SEL()                             ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x03, 0xFF, 0)
#define VRX_set_OP_FORMAT_SEL(val)                          ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x03, 0xFF, 0, val)

#define VRX_get_OP_CH_SEL(pval)                             ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x04, 0xE0, 5, pval)
#define VRX_ret_OP_CH_SEL()                                 ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x04, 0xE0, 5)
#define VRX_set_OP_CH_SEL(val)                              ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x04, 0xE0, 5, val)

#define VRX_is_F_OUT_SEL_true()                             ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x05, 0x10, 0x4)
#define VRX_get_F_OUT_SEL(pval)                             ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x05, 0x10, 0x4, pval)
#define VRX_ret_F_OUT_SEL()                                 ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x05, 0x10, 0x4)
#define VRX_set_F_OUT_SEL(val)                              ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x05, 0x10, 0x4, val)

#define VRX_is_DATA_BLANK_EN_true()                         ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x05, 0x8, 0x3)
#define VRX_get_DATA_BLANK_EN(pval)                         ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x05, 0x8, 0x3, pval)
#define VRX_ret_DATA_BLANK_EN()                             ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x05, 0x8, 0x3)
#define VRX_set_DATA_BLANK_EN(val)                          ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x05, 0x8, 0x3, val)

#define VRX_is_AVCODE_INSERT_EN_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x05, 0x4, 0x2)
#define VRX_get_AVCODE_INSERT_EN(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x05, 0x4, 0x2, pval)
#define VRX_ret_AVCODE_INSERT_EN()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x05, 0x4, 0x2)
#define VRX_set_AVCODE_INSERT_EN(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x05, 0x4, 0x2, val)

#define VRX_is_REPL_AV_CODE_true()                          ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x05, 0x2, 0x1)
#define VRX_get_REPL_AV_CODE(pval)                          ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x05, 0x2, 0x1, pval)
#define VRX_ret_REPL_AV_CODE()                              ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x05, 0x2, 0x1)
#define VRX_set_REPL_AV_CODE(val)                           ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x05, 0x2, 0x1, val)

#define VRX_is_OP_SWAP_CB_CR_true()                         ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x05, 0x1, 0x0)
#define VRX_get_OP_SWAP_CB_CR(pval)                         ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x05, 0x1, 0x0, pval)
#define VRX_ret_OP_SWAP_CB_CR()                             ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x05, 0x1, 0x0)
#define VRX_set_OP_SWAP_CB_CR(val)                          ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x05, 0x1, 0x0, val)

#define VRX_is_VS_OUT_SEL_true()                            ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x06, 0x80, 0x7)
#define VRX_get_VS_OUT_SEL(pval)                            ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x06, 0x80, 0x7, pval)
#define VRX_ret_VS_OUT_SEL()                                ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x06, 0x80, 0x7)
#define VRX_set_VS_OUT_SEL(val)                             ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x06, 0x80, 0x7, val)

#define VRX_get_HS_OUT_SEL(pval)                            ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x06, 0x60, 5, pval)
#define VRX_ret_HS_OUT_SEL()                                ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x06, 0x60, 5)
#define VRX_set_HS_OUT_SEL(val)                             ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x06, 0x60, 5, val)

#define VRX_is_INV_SYNC_OUT_POL_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x06, 0x10, 0x4)
#define VRX_get_INV_SYNC_OUT_POL(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x06, 0x10, 0x4, pval)
#define VRX_ret_INV_SYNC_OUT_POL()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x06, 0x10, 0x4)
#define VRX_set_INV_SYNC_OUT_POL(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x06, 0x10, 0x4, val)

#define VRX_is_INV_F_POL_true()                             ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x06, 0x8, 0x3)
#define VRX_get_INV_F_POL(pval)                             ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x06, 0x8, 0x3, pval)
#define VRX_ret_INV_F_POL()                                 ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x06, 0x8, 0x3)
#define VRX_set_INV_F_POL(val)                              ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x06, 0x8, 0x3, val)

#define VRX_is_INV_VS_POL_true()                            ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x06, 0x4, 0x2)
#define VRX_get_INV_VS_POL(pval)                            ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x06, 0x4, 0x2, pval)
#define VRX_ret_INV_VS_POL()                                ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x06, 0x4, 0x2)
#define VRX_set_INV_VS_POL(val)                             ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x06, 0x4, 0x2, val)

#define VRX_is_INV_HS_POL_true()                            ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x06, 0x2, 0x1)
#define VRX_get_INV_HS_POL(pval)                            ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x06, 0x2, 0x1, pval)
#define VRX_ret_INV_HS_POL()                                ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x06, 0x2, 0x1)
#define VRX_set_INV_HS_POL(val)                             ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x06, 0x2, 0x1, val)

#define VRX_is_INV_LLC_POL_true()                           ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x06, 0x1, 0x0)
#define VRX_get_INV_LLC_POL(pval)                           ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x06, 0x1, 0x0, pval)
#define VRX_ret_INV_LLC_POL()                               ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x06, 0x1, 0x0)
#define VRX_set_INV_LLC_POL(val)                            ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x06, 0x1, 0x0, val)

#define VRX_is_SYNC_CH_AUTO_MODE_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x07, 0x80, 0x7)
#define VRX_get_SYNC_CH_AUTO_MODE(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x07, 0x80, 0x7, pval)
#define VRX_ret_SYNC_CH_AUTO_MODE()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x07, 0x80, 0x7)
#define VRX_set_SYNC_CH_AUTO_MODE(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x07, 0x80, 0x7, val)

#define VRX_is_SYNC_CH1_PRIORITY_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x07, 0x40, 0x6)
#define VRX_get_SYNC_CH1_PRIORITY(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x07, 0x40, 0x6, pval)
#define VRX_ret_SYNC_CH1_PRIORITY()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x07, 0x40, 0x6)
#define VRX_set_SYNC_CH1_PRIORITY(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x07, 0x40, 0x6, val)

#define VRX_get_SYNC_CH1_HS_SEL(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x07, 0x30, 4, pval)
#define VRX_ret_SYNC_CH1_HS_SEL()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x07, 0x30, 4)
#define VRX_set_SYNC_CH1_HS_SEL(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x07, 0x30, 4, val)

#define VRX_get_SYNC_CH1_VS_SEL(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x07, 0xC, 2, pval)
#define VRX_ret_SYNC_CH1_VS_SEL()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x07, 0xC, 2)
#define VRX_set_SYNC_CH1_VS_SEL(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x07, 0xC, 2, val)

#define VRX_get_SYNC_CH1_EMB_SYNC_SEL(pval)                 ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x07, 0x3, 0, pval)
#define VRX_ret_SYNC_CH1_EMB_SYNC_SEL()                     ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x07, 0x3, 0)
#define VRX_set_SYNC_CH1_EMB_SYNC_SEL(val)                  ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x07, 0x3, 0, val)

#define VRX_get_SYNC_CH2_HS_SEL(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x08, 0x30, 4, pval)
#define VRX_ret_SYNC_CH2_HS_SEL()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x08, 0x30, 4)
#define VRX_set_SYNC_CH2_HS_SEL(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x08, 0x30, 4, val)

#define VRX_get_SYNC_CH2_VS_SEL(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x08, 0xC, 2, pval)
#define VRX_ret_SYNC_CH2_VS_SEL()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x08, 0xC, 2)
#define VRX_set_SYNC_CH2_VS_SEL(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x08, 0xC, 2, val)

#define VRX_get_SYNC_CH2_EMB_SYNC_SEL(pval)                 ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x08, 0x3, 0, pval)
#define VRX_ret_SYNC_CH2_EMB_SYNC_SEL()                     ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x08, 0x3, 0)
#define VRX_set_SYNC_CH2_EMB_SYNC_SEL(val)                  ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x08, 0x3, 0, val)

#define VRX_is_SEL_RAW_CS_true()                            ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x0B, 0x40, 0x6)
#define VRX_get_SEL_RAW_CS(pval)                            ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x0B, 0x40, 0x6, pval)
#define VRX_ret_SEL_RAW_CS()                                ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x0B, 0x40, 0x6)
#define VRX_set_SEL_RAW_CS(val)                             ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x0B, 0x40, 0x6, val)

#define VRX_is_OSD_CLK_PDN_true()                           ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x0B, 0x8, 0x3)
#define VRX_get_OSD_CLK_PDN(pval)                           ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x0B, 0x8, 0x3, pval)
#define VRX_ret_OSD_CLK_PDN()                               ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x0B, 0x8, 0x3)
#define VRX_set_OSD_CLK_PDN(val)                            ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x0B, 0x8, 0x3, val)

#define VRX_is_CORE_PDN_true()                              ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x0B, 0x2, 0x1)
#define VRX_get_CORE_PDN(pval)                              ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x0B, 0x2, 0x1, pval)
#define VRX_ret_CORE_PDN()                                  ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x0B, 0x2, 0x1)
#define VRX_set_CORE_PDN(val)                               ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x0B, 0x2, 0x1, val)

#define VRX_is_XTAL_PDN_true()                              ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x0B, 0x1, 0x0)
#define VRX_get_XTAL_PDN(pval)                              ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x0B, 0x1, 0x0, pval)
#define VRX_ret_XTAL_PDN()                                  ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x0B, 0x1, 0x0)
#define VRX_set_XTAL_PDN(val)                               ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x0B, 0x1, 0x0, val)

#define VRX_get_PWR_SAVE_SOG_SEL(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x0C, 0xC0, 6, pval)
#define VRX_ret_PWR_SAVE_SOG_SEL()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x0C, 0xC0, 6)
#define VRX_set_PWR_SAVE_SOG_SEL(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x0C, 0xC0, 6, val)

#define VRX_is_POWER_DOWN_true()                            ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x0C, 0x20, 0x5)
#define VRX_get_POWER_DOWN(pval)                            ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x0C, 0x20, 0x5, pval)
#define VRX_ret_POWER_DOWN()                                ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x0C, 0x20, 0x5)
#define VRX_set_POWER_DOWN(val)                             ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x0C, 0x20, 0x5, val)

#define VRX_is_PWR_SAVE_MODE_true()                         ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x0C, 0x8, 0x3)
#define VRX_get_PWR_SAVE_MODE(pval)                         ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x0C, 0x8, 0x3, pval)
#define VRX_ret_PWR_SAVE_MODE()                             ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x0C, 0x8, 0x3)
#define VRX_set_PWR_SAVE_MODE(val)                          ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x0C, 0x8, 0x3, val)

#define VRX_is_CP_PWRDN_true()                              ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x0C, 0x4, 0x2)
#define VRX_get_CP_PWRDN(pval)                              ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x0C, 0x4, 0x2, pval)
#define VRX_ret_CP_PWRDN()                                  ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x0C, 0x4, 0x2)
#define VRX_set_CP_PWRDN(val)                               ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x0C, 0x4, 0x2, val)

#define VRX_is_VDP_PDN_true()                               ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x0C, 0x2, 0x1)
#define VRX_get_VDP_PDN(pval)                               ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x0C, 0x2, 0x1, pval)
#define VRX_ret_VDP_PDN()                                   ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x0C, 0x2, 0x1)
#define VRX_set_VDP_PDN(val)                                ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x0C, 0x2, 0x1, val)

#define VRX_is_PADS_PDN_true()                              ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x0C, 0x1, 0x0)
#define VRX_get_PADS_PDN(pval)                              ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x0C, 0x1, 0x0, pval)
#define VRX_ret_PADS_PDN()                                  ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x0C, 0x1, 0x0)
#define VRX_set_PADS_PDN(val)                               ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x0C, 0x1, 0x0, val)

#define VRX_is_SEL_SYNC_CHANNEL_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x12, 0x80, 0x7)
#define VRX_get_SEL_SYNC_CHANNEL(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x12, 0x80, 0x7, pval)
#define VRX_ret_SEL_SYNC_CHANNEL()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x12, 0x80, 0x7)

#define VRX_is_CP_STDI_INTERLACED_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x12, 0x10, 0x4)
#define VRX_get_CP_STDI_INTERLACED(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x12, 0x10, 0x4, pval)
#define VRX_ret_CP_STDI_INTERLACED()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x12, 0x10, 0x4)

#define VRX_is_CP_INTERLACED_true()                         ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x12, 0x8, 0x3)
#define VRX_get_CP_INTERLACED(pval)                         ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x12, 0x8, 0x3, pval)
#define VRX_ret_CP_INTERLACED()                             ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x12, 0x8, 0x3)

#define VRX_is_CP_PROG_PARM_FOR_INT_true()                  ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x12, 0x4, 0x2)
#define VRX_get_CP_PROG_PARM_FOR_INT(pval)                  ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x12, 0x4, 0x2, pval)
#define VRX_ret_CP_PROG_PARM_FOR_INT()                      ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x12, 0x4, 0x2)

#define VRX_is_CP_FORCE_INTERLACED_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x12, 0x2, 0x1)
#define VRX_get_CP_FORCE_INTERLACED(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x12, 0x2, 0x1, pval)
#define VRX_ret_CP_FORCE_INTERLACED()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x12, 0x2, 0x1)

#define VRX_is_CP_NON_STD_VIDEO_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x12, 0x1, 0x0)
#define VRX_get_CP_NON_STD_VIDEO(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x12, 0x1, 0x0, pval)
#define VRX_ret_CP_NON_STD_VIDEO()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x12, 0x1, 0x0)

#define VRX_get_CP_CURRENT_SYNC_SRC(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x13, 0x3, 0, pval)
#define VRX_ret_CP_CURRENT_SYNC_SRC()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x13, 0x3, 0)

#define VRX_get_DR_STR(pval)                                ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x14, 0x30, 4, pval)
#define VRX_ret_DR_STR()                                    ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x14, 0x30, 4)
#define VRX_set_DR_STR(val)                                 ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x14, 0x30, 4, val)

#define VRX_get_DR_STR_CLK(pval)                            ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x14, 0xC, 2, pval)
#define VRX_ret_DR_STR_CLK()                                ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x14, 0xC, 2)
#define VRX_set_DR_STR_CLK(val)                             ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x14, 0xC, 2, val)

#define VRX_get_DR_STR_SYNC(pval)                           ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x14, 0x3, 0, pval)
#define VRX_ret_DR_STR_SYNC()                               ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x14, 0x3, 0)
#define VRX_set_DR_STR_SYNC(val)                            ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x14, 0x3, 0, val)

#define VRX_is_TRI_AUDIO_true()                             ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x15, 0x10, 0x4)
#define VRX_get_TRI_AUDIO(pval)                             ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x15, 0x10, 0x4, pval)
#define VRX_ret_TRI_AUDIO()                                 ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x15, 0x10, 0x4)
#define VRX_set_TRI_AUDIO(val)                              ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x15, 0x10, 0x4, val)

#define VRX_is_TRI_SYNCS_true()                             ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x15, 0x8, 0x3)
#define VRX_get_TRI_SYNCS(pval)                             ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x15, 0x8, 0x3, pval)
#define VRX_ret_TRI_SYNCS()                                 ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x15, 0x8, 0x3)
#define VRX_set_TRI_SYNCS(val)                              ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x15, 0x8, 0x3, val)

#define VRX_is_TRI_LLC_true()                               ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x15, 0x4, 0x2)
#define VRX_get_TRI_LLC(pval)                               ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x15, 0x4, 0x2, pval)
#define VRX_ret_TRI_LLC()                                   ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x15, 0x4, 0x2)
#define VRX_set_TRI_LLC(val)                                ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x15, 0x4, 0x2, val)

#define VRX_is_TRI_PIX_true()                               ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x15, 0x2, 0x1)
#define VRX_get_TRI_PIX(pval)                               ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x15, 0x2, 0x1, pval)
#define VRX_ret_TRI_PIX()                                   ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x15, 0x2, 0x1)
#define VRX_set_TRI_PIX(val)                                ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x15, 0x2, 0x1, val)

#define VRX_is_PLL_DIV_MAN_EN_true()                        ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x16, 0x80, 0x7)
#define VRX_get_PLL_DIV_MAN_EN(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x16, 0x80, 0x7, pval)
#define VRX_ret_PLL_DIV_MAN_EN()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x16, 0x80, 0x7)
#define VRX_set_PLL_DIV_MAN_EN(val)                         ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x16, 0x80, 0x7, val)

#define VRX_get_PLL_DIV_RATIO(pval)                         ATV_I2CGetField32(VRX_IO_MAP_ADDR, 0x16, 0x1F, 0xFF, 0, 2, pval)
#define VRX_ret_PLL_DIV_RATIO()                             ATV_I2CReadField32(VRX_IO_MAP_ADDR, 0x16, 0x1F, 0xFF, 0, 2)
#define VRX_set_PLL_DIV_RATIO(val)                          ATV_I2CWriteField32(VRX_IO_MAP_ADDR, 0x16, 0x1F, 0xFF, 0, 2, val)

#define VRX_is_LLC_DLL_EN_true()                            ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x19, 0x80, 0x7)
#define VRX_get_LLC_DLL_EN(pval)                            ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x19, 0x80, 0x7, pval)
#define VRX_ret_LLC_DLL_EN()                                ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x19, 0x80, 0x7)
#define VRX_set_LLC_DLL_EN(val)                             ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x19, 0x80, 0x7, val)

#define VRX_get_LLC_DLL_PHASE(pval)                         ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x19, 0x1F, 0, pval)
#define VRX_ret_LLC_DLL_PHASE()                             ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x19, 0x1F, 0)
#define VRX_set_LLC_DLL_PHASE(val)                          ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x19, 0x1F, 0, val)

#define VRX_is_SUBI2C_EN_true()                             ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x1A, 0x2, 0x1)
#define VRX_get_SUBI2C_EN(pval)                             ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x1A, 0x2, 0x1, pval)
#define VRX_ret_SUBI2C_EN()                                 ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x1A, 0x2, 0x1)
#define VRX_set_SUBI2C_EN(val)                              ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x1A, 0x2, 0x1, val)

#define VRX_is_VDP_ON_SUB_I2C_true()                        ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x1A, 0x1, 0x0)
#define VRX_get_VDP_ON_SUB_I2C(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x1A, 0x1, 0x0, pval)
#define VRX_ret_VDP_ON_SUB_I2C()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x1A, 0x1, 0x0)
#define VRX_set_VDP_ON_SUB_I2C(val)                         ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x1A, 0x1, 0x0, val)

#define VRX_is_HPA_MAN_VALUE_A_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x20, 0x20, 0x5)
#define VRX_get_HPA_MAN_VALUE_A(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x20, 0x20, 0x5, pval)
#define VRX_ret_HPA_MAN_VALUE_A()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x20, 0x20, 0x5)
#define VRX_set_HPA_MAN_VALUE_A(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x20, 0x20, 0x5, val)

#define VRX_is_HPA_MAN_VALUE_B_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x20, 0x10, 0x4)
#define VRX_get_HPA_MAN_VALUE_B(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x20, 0x10, 0x4, pval)
#define VRX_ret_HPA_MAN_VALUE_B()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x20, 0x10, 0x4)
#define VRX_set_HPA_MAN_VALUE_B(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x20, 0x10, 0x4, val)

#define VRX_is_HPA_TRISTATE_A_true()                        ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x20, 0x2, 0x1)
#define VRX_get_HPA_TRISTATE_A(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x20, 0x2, 0x1, pval)
#define VRX_ret_HPA_TRISTATE_A()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x20, 0x2, 0x1)
#define VRX_set_HPA_TRISTATE_A(val)                         ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x20, 0x2, 0x1, val)

#define VRX_is_HPA_TRISTATE_B_true()                        ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x20, 0x1, 0x0)
#define VRX_get_HPA_TRISTATE_B(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x20, 0x1, 0x0, pval)
#define VRX_ret_HPA_TRISTATE_B()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x20, 0x1, 0x0)
#define VRX_set_HPA_TRISTATE_B(val)                         ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x20, 0x1, 0x0, val)

#define VRX_is_HPA_STATUS_PORT_A_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x21, 0x2, 0x1)
#define VRX_get_HPA_STATUS_PORT_A(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x21, 0x2, 0x1, pval)
#define VRX_ret_HPA_STATUS_PORT_A()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x21, 0x2, 0x1)

#define VRX_is_HPA_STATUS_PORT_B_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x21, 0x1, 0x0)
#define VRX_get_HPA_STATUS_PORT_B(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x21, 0x1, 0x0, pval)
#define VRX_ret_HPA_STATUS_PORT_B()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x21, 0x1, 0x0)

#define VRX_is_PIXBUS_MSB_TO_LSB_REORDER_true()             ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x30, 0x10, 0x4)
#define VRX_get_PIXBUS_MSB_TO_LSB_REORDER(pval)             ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x30, 0x10, 0x4, pval)
#define VRX_ret_PIXBUS_MSB_TO_LSB_REORDER()                 ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x30, 0x10, 0x4)
#define VRX_set_PIXBUS_MSB_TO_LSB_REORDER(val)              ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x30, 0x10, 0x4, val)

#define VRX_is_LLC_DLL_MUX_true()                           ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x33, 0x40, 0x6)
#define VRX_get_LLC_DLL_MUX(pval)                           ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x33, 0x40, 0x6, pval)
#define VRX_ret_LLC_DLL_MUX()                               ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x33, 0x40, 0x6)
#define VRX_set_LLC_DLL_MUX(val)                            ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x33, 0x40, 0x6, val)

#define VRX_is_INTRQ_RAW_true()                             ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x3F, 0x2, 0x1)
#define VRX_get_INTRQ_RAW(pval)                             ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x3F, 0x2, 0x1, pval)
#define VRX_ret_INTRQ_RAW()                                 ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x3F, 0x2, 0x1)

#define VRX_is_INTRQ2_RAW_true()                            ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x3F, 0x1, 0x0)
#define VRX_get_INTRQ2_RAW(pval)                            ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x3F, 0x1, 0x0, pval)
#define VRX_ret_INTRQ2_RAW()                                ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x3F, 0x1, 0x0)

#define VRX_get_INTRQ_DUR_SEL(pval)                         ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x40, 0xC0, 6, pval)
#define VRX_ret_INTRQ_DUR_SEL()                             ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x40, 0xC0, 6)
#define VRX_set_INTRQ_DUR_SEL(val)                          ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x40, 0xC0, 6, val)

#define VRX_is_STORE_UNMASKED_IRQS_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x40, 0x10, 0x4)
#define VRX_get_STORE_UNMASKED_IRQS(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x40, 0x10, 0x4, pval)
#define VRX_ret_STORE_UNMASKED_IRQS()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x40, 0x10, 0x4)
#define VRX_set_STORE_UNMASKED_IRQS(val)                    ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x40, 0x10, 0x4, val)

#define VRX_is_EN_MUTE_OUT_INTRQ_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x40, 0x8, 0x3)
#define VRX_get_EN_MUTE_OUT_INTRQ(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x40, 0x8, 0x3, pval)
#define VRX_ret_EN_MUTE_OUT_INTRQ()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x40, 0x8, 0x3)
#define VRX_set_EN_MUTE_OUT_INTRQ(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x40, 0x8, 0x3, val)

#define VRX_is_MPU_STIM_INTRQ_true()                        ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x40, 0x4, 0x2)
#define VRX_get_MPU_STIM_INTRQ(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x40, 0x4, 0x2, pval)
#define VRX_ret_MPU_STIM_INTRQ()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x40, 0x4, 0x2)
#define VRX_set_MPU_STIM_INTRQ(val)                         ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x40, 0x4, 0x2, val)

#define VRX_get_INTRQ_OP_SEL(pval)                          ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x40, 0x3, 0, pval)
#define VRX_ret_INTRQ_OP_SEL()                              ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x40, 0x3, 0)
#define VRX_set_INTRQ_OP_SEL(val)                           ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x40, 0x3, 0, val)

#define VRX_get_INTRQ2_DUR_SEL(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x41, 0xC0, 6, pval)
#define VRX_ret_INTRQ2_DUR_SEL()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x41, 0xC0, 6)
#define VRX_set_INTRQ2_DUR_SEL(val)                         ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x41, 0xC0, 6, val)

#define VRX_is_CP_LOCK_UNLOCK_EDGE_SEL_true()               ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x41, 0x20, 0x5)
#define VRX_get_CP_LOCK_UNLOCK_EDGE_SEL(pval)               ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x41, 0x20, 0x5, pval)
#define VRX_ret_CP_LOCK_UNLOCK_EDGE_SEL()                   ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x41, 0x20, 0x5)
#define VRX_set_CP_LOCK_UNLOCK_EDGE_SEL(val)                ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x41, 0x20, 0x5, val)

#define VRX_is_STDI_DATA_VALID_EDGE_SEL_true()              ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x41, 0x10, 0x4)
#define VRX_get_STDI_DATA_VALID_EDGE_SEL(pval)              ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x41, 0x10, 0x4, pval)
#define VRX_ret_STDI_DATA_VALID_EDGE_SEL()                  ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x41, 0x10, 0x4)
#define VRX_set_STDI_DATA_VALID_EDGE_SEL(val)               ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x41, 0x10, 0x4, val)

#define VRX_is_EN_MUTE_OUT_INTRQ2_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x41, 0x8, 0x3)
#define VRX_get_EN_MUTE_OUT_INTRQ2(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x41, 0x8, 0x3, pval)
#define VRX_ret_EN_MUTE_OUT_INTRQ2()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x41, 0x8, 0x3)
#define VRX_set_EN_MUTE_OUT_INTRQ2(val)                     ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x41, 0x8, 0x3, val)

#define VRX_is_INT2_EN_true()                               ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x41, 0x4, 0x2)
#define VRX_get_INT2_EN(pval)                               ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x41, 0x4, 0x2, pval)
#define VRX_ret_INT2_EN()                                   ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x41, 0x4, 0x2)
#define VRX_set_INT2_EN(val)                                ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x41, 0x4, 0x2, val)

#define VRX_get_INTRQ2_OP_SEL(pval)                         ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x41, 0x3, 0, pval)
#define VRX_ret_INTRQ2_OP_SEL()                             ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x41, 0x3, 0)
#define VRX_set_INTRQ2_OP_SEL(val)                          ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x41, 0x3, 0, val)

#define VRX_is_SSPD_RSLT_CHNGD_RAW_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x42, 0x80, 0x7)
#define VRX_get_SSPD_RSLT_CHNGD_RAW(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x42, 0x80, 0x7, pval)
#define VRX_ret_SSPD_RSLT_CHNGD_RAW()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x42, 0x80, 0x7)

#define VRX_is_MV_PS_DET_RAW_true()                         ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x42, 0x40, 0x6)
#define VRX_get_MV_PS_DET_RAW(pval)                         ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x42, 0x40, 0x6, pval)
#define VRX_ret_MV_PS_DET_RAW()                             ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x42, 0x40, 0x6)

#define VRX_is_STDI_DATA_VALID_RAW_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x42, 0x10, 0x4)
#define VRX_get_STDI_DATA_VALID_RAW(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x42, 0x10, 0x4, pval)
#define VRX_ret_STDI_DATA_VALID_RAW()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x42, 0x10, 0x4)

#define VRX_is_CP_UNLOCK_RAW_true()                         ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x42, 0x8, 0x3)
#define VRX_get_CP_UNLOCK_RAW(pval)                         ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x42, 0x8, 0x3, pval)
#define VRX_ret_CP_UNLOCK_RAW()                             ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x42, 0x8, 0x3)

#define VRX_is_CP_LOCK_RAW_true()                           ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x42, 0x4, 0x2)
#define VRX_get_CP_LOCK_RAW(pval)                           ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x42, 0x4, 0x2, pval)
#define VRX_ret_CP_LOCK_RAW()                               ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x42, 0x4, 0x2)

#define VRX_is_AFE_INTERRUPT_RAW_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x42, 0x1, 0x0)
#define VRX_get_AFE_INTERRUPT_RAW(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x42, 0x1, 0x0, pval)
#define VRX_ret_AFE_INTERRUPT_RAW()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x42, 0x1, 0x0)

#define VRX_is_SSPD_RSLT_CHNGD_ST_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x43, 0x80, 0x7)
#define VRX_get_SSPD_RSLT_CHNGD_ST(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x43, 0x80, 0x7, pval)
#define VRX_ret_SSPD_RSLT_CHNGD_ST()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x43, 0x80, 0x7)

#define VRX_is_MV_PS_DET_ST_true()                          ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x43, 0x40, 0x6)
#define VRX_get_MV_PS_DET_ST(pval)                          ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x43, 0x40, 0x6, pval)
#define VRX_ret_MV_PS_DET_ST()                              ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x43, 0x40, 0x6)

#define VRX_is_STDI_DATA_VALID_ST_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x43, 0x10, 0x4)
#define VRX_get_STDI_DATA_VALID_ST(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x43, 0x10, 0x4, pval)
#define VRX_ret_STDI_DATA_VALID_ST()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x43, 0x10, 0x4)

#define VRX_is_CP_UNLOCK_ST_true()                          ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x43, 0x8, 0x3)
#define VRX_get_CP_UNLOCK_ST(pval)                          ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x43, 0x8, 0x3, pval)
#define VRX_ret_CP_UNLOCK_ST()                              ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x43, 0x8, 0x3)

#define VRX_is_CP_LOCK_ST_true()                            ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x43, 0x4, 0x2)
#define VRX_get_CP_LOCK_ST(pval)                            ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x43, 0x4, 0x2, pval)
#define VRX_ret_CP_LOCK_ST()                                ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x43, 0x4, 0x2)

#define VRX_is_AFE_INTERRUPT_ST_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x43, 0x1, 0x0)
#define VRX_get_AFE_INTERRUPT_ST(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x43, 0x1, 0x0, pval)
#define VRX_ret_AFE_INTERRUPT_ST()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x43, 0x1, 0x0)

#define VRX_set_SSPD_RSLT_CHNGD_CLR(val)                    ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x44, 0x80, 0x7, val)

#define VRX_set_MV_PS_DET_CLR(val)                          ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x44, 0x40, 0x6, val)

#define VRX_set_STDI_DATA_VALID_CLR(val)                    ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x44, 0x10, 0x4, val)

#define VRX_set_CP_UNLOCK_CLR(val)                          ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x44, 0x8, 0x3, val)

#define VRX_set_CP_LOCK_CLR(val)                            ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x44, 0x4, 0x2, val)

#define VRX_set_AFE_INTERRUPT_CLR(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x44, 0x1, 0x0, val)

#define VRX_is_SSPD_RSLT_CHNGD_MB2_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x45, 0x80, 0x7)
#define VRX_get_SSPD_RSLT_CHNGD_MB2(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x45, 0x80, 0x7, pval)
#define VRX_ret_SSPD_RSLT_CHNGD_MB2()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x45, 0x80, 0x7)
#define VRX_set_SSPD_RSLT_CHNGD_MB2(val)                    ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x45, 0x80, 0x7, val)

#define VRX_is_MV_PS_DET_MB2_true()                         ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x45, 0x40, 0x6)
#define VRX_get_MV_PS_DET_MB2(pval)                         ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x45, 0x40, 0x6, pval)
#define VRX_ret_MV_PS_DET_MB2()                             ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x45, 0x40, 0x6)
#define VRX_set_MV_PS_DET_MB2(val)                          ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x45, 0x40, 0x6, val)

#define VRX_is_STDI_DATA_VALID_MB2_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x45, 0x10, 0x4)
#define VRX_get_STDI_DATA_VALID_MB2(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x45, 0x10, 0x4, pval)
#define VRX_ret_STDI_DATA_VALID_MB2()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x45, 0x10, 0x4)
#define VRX_set_STDI_DATA_VALID_MB2(val)                    ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x45, 0x10, 0x4, val)

#define VRX_is_CP_UNLOCK_MB2_true()                         ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x45, 0x8, 0x3)
#define VRX_get_CP_UNLOCK_MB2(pval)                         ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x45, 0x8, 0x3, pval)
#define VRX_ret_CP_UNLOCK_MB2()                             ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x45, 0x8, 0x3)
#define VRX_set_CP_UNLOCK_MB2(val)                          ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x45, 0x8, 0x3, val)

#define VRX_is_CP_LOCK_MB2_true()                           ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x45, 0x4, 0x2)
#define VRX_get_CP_LOCK_MB2(pval)                           ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x45, 0x4, 0x2, pval)
#define VRX_ret_CP_LOCK_MB2()                               ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x45, 0x4, 0x2)
#define VRX_set_CP_LOCK_MB2(val)                            ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x45, 0x4, 0x2, val)

#define VRX_is_AFE_INTERRUPT_MB2_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x45, 0x1, 0x0)
#define VRX_get_AFE_INTERRUPT_MB2(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x45, 0x1, 0x0, pval)
#define VRX_ret_AFE_INTERRUPT_MB2()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x45, 0x1, 0x0)
#define VRX_set_AFE_INTERRUPT_MB2(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x45, 0x1, 0x0, val)

#define VRX_is_SSPD_RSLT_CHNGD_MB1_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x46, 0x80, 0x7)
#define VRX_get_SSPD_RSLT_CHNGD_MB1(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x46, 0x80, 0x7, pval)
#define VRX_ret_SSPD_RSLT_CHNGD_MB1()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x46, 0x80, 0x7)
#define VRX_set_SSPD_RSLT_CHNGD_MB1(val)                    ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x46, 0x80, 0x7, val)

#define VRX_is_MV_PS_DET_MB1_true()                         ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x46, 0x40, 0x6)
#define VRX_get_MV_PS_DET_MB1(pval)                         ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x46, 0x40, 0x6, pval)
#define VRX_ret_MV_PS_DET_MB1()                             ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x46, 0x40, 0x6)
#define VRX_set_MV_PS_DET_MB1(val)                          ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x46, 0x40, 0x6, val)

#define VRX_is_STDI_DATA_VALID_MB1_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x46, 0x10, 0x4)
#define VRX_get_STDI_DATA_VALID_MB1(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x46, 0x10, 0x4, pval)
#define VRX_ret_STDI_DATA_VALID_MB1()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x46, 0x10, 0x4)
#define VRX_set_STDI_DATA_VALID_MB1(val)                    ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x46, 0x10, 0x4, val)

#define VRX_is_CP_UNLOCK_MB1_true()                         ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x46, 0x8, 0x3)
#define VRX_get_CP_UNLOCK_MB1(pval)                         ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x46, 0x8, 0x3, pval)
#define VRX_ret_CP_UNLOCK_MB1()                             ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x46, 0x8, 0x3)
#define VRX_set_CP_UNLOCK_MB1(val)                          ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x46, 0x8, 0x3, val)

#define VRX_is_CP_LOCK_MB1_true()                           ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x46, 0x4, 0x2)
#define VRX_get_CP_LOCK_MB1(pval)                           ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x46, 0x4, 0x2, pval)
#define VRX_ret_CP_LOCK_MB1()                               ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x46, 0x4, 0x2)
#define VRX_set_CP_LOCK_MB1(val)                            ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x46, 0x4, 0x2, val)

#define VRX_is_AFE_INTERRUPT_MB1_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x46, 0x1, 0x0)
#define VRX_get_AFE_INTERRUPT_MB1(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x46, 0x1, 0x0, pval)
#define VRX_ret_AFE_INTERRUPT_MB1()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x46, 0x1, 0x0)
#define VRX_set_AFE_INTERRUPT_MB1(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x46, 0x1, 0x0, val)

#define VRX_is_MPU_STIM_INTRQ_RAW_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x47, 0x80, 0x7)
#define VRX_get_MPU_STIM_INTRQ_RAW(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x47, 0x80, 0x7, pval)
#define VRX_ret_MPU_STIM_INTRQ_RAW()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x47, 0x80, 0x7)

#define VRX_is_MV_AGC_DET_RAW_true()                        ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x47, 0x40, 0x6)
#define VRX_get_MV_AGC_DET_RAW(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x47, 0x40, 0x6, pval)
#define VRX_ret_MV_AGC_DET_RAW()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x47, 0x40, 0x6)

#define VRX_is_MV_CS_DET_RAW_true()                         ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x47, 0x20, 0x5)
#define VRX_get_MV_CS_DET_RAW(pval)                         ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x47, 0x20, 0x5, pval)
#define VRX_ret_MV_CS_DET_RAW()                             ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x47, 0x20, 0x5)

#define VRX_is_CP_CGMS_CHNGD_RAW_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x47, 0x4, 0x2)
#define VRX_get_CP_CGMS_CHNGD_RAW(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x47, 0x4, 0x2, pval)
#define VRX_ret_CP_CGMS_CHNGD_RAW()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x47, 0x4, 0x2)

#define VRX_is_MPU_STIM_INTRQ_ST_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x48, 0x80, 0x7)
#define VRX_get_MPU_STIM_INTRQ_ST(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x48, 0x80, 0x7, pval)
#define VRX_ret_MPU_STIM_INTRQ_ST()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x48, 0x80, 0x7)

#define VRX_is_MV_AGC_DET_ST_true()                         ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x48, 0x40, 0x6)
#define VRX_get_MV_AGC_DET_ST(pval)                         ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x48, 0x40, 0x6, pval)
#define VRX_ret_MV_AGC_DET_ST()                             ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x48, 0x40, 0x6)

#define VRX_is_MV_CS_DET_ST_true()                          ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x48, 0x20, 0x5)
#define VRX_get_MV_CS_DET_ST(pval)                          ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x48, 0x20, 0x5, pval)
#define VRX_ret_MV_CS_DET_ST()                              ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x48, 0x20, 0x5)

#define VRX_is_CP_CGMS_CHNGD_ST_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x48, 0x4, 0x2)
#define VRX_get_CP_CGMS_CHNGD_ST(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x48, 0x4, 0x2, pval)
#define VRX_ret_CP_CGMS_CHNGD_ST()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x48, 0x4, 0x2)

#define VRX_set_MPU_STIM_INTRQ_CLR(val)                     ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x49, 0x80, 0x7, val)

#define VRX_set_MV_AGC_DET_CLR(val)                         ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x49, 0x40, 0x6, val)

#define VRX_set_MV_CS_DET_CLR(val)                          ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x49, 0x20, 0x5, val)

#define VRX_set_CP_CGMS_CHNGD_CLR(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x49, 0x4, 0x2, val)

#define VRX_is_MPU_STIM_INTRQ_MB2_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x4A, 0x80, 0x7)
#define VRX_get_MPU_STIM_INTRQ_MB2(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x4A, 0x80, 0x7, pval)
#define VRX_ret_MPU_STIM_INTRQ_MB2()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x4A, 0x80, 0x7)
#define VRX_set_MPU_STIM_INTRQ_MB2(val)                     ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x4A, 0x80, 0x7, val)

#define VRX_is_MV_AGC_DET_MB2_true()                        ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x4A, 0x40, 0x6)
#define VRX_get_MV_AGC_DET_MB2(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x4A, 0x40, 0x6, pval)
#define VRX_ret_MV_AGC_DET_MB2()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x4A, 0x40, 0x6)
#define VRX_set_MV_AGC_DET_MB2(val)                         ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x4A, 0x40, 0x6, val)

#define VRX_is_MV_CS_DET_MB2_true()                         ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x4A, 0x20, 0x5)
#define VRX_get_MV_CS_DET_MB2(pval)                         ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x4A, 0x20, 0x5, pval)
#define VRX_ret_MV_CS_DET_MB2()                             ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x4A, 0x20, 0x5)
#define VRX_set_MV_CS_DET_MB2(val)                          ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x4A, 0x20, 0x5, val)

#define VRX_is_CP_CGMS_CHNGD_MB2_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x4A, 0x4, 0x2)
#define VRX_get_CP_CGMS_CHNGD_MB2(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x4A, 0x4, 0x2, pval)
#define VRX_ret_CP_CGMS_CHNGD_MB2()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x4A, 0x4, 0x2)
#define VRX_set_CP_CGMS_CHNGD_MB2(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x4A, 0x4, 0x2, val)

#define VRX_is_MPU_STIM_INTRQ_MB1_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x4B, 0x80, 0x7)
#define VRX_get_MPU_STIM_INTRQ_MB1(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x4B, 0x80, 0x7, pval)
#define VRX_ret_MPU_STIM_INTRQ_MB1()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x4B, 0x80, 0x7)
#define VRX_set_MPU_STIM_INTRQ_MB1(val)                     ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x4B, 0x80, 0x7, val)

#define VRX_is_MV_AGC_DET_MB1_true()                        ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x4B, 0x40, 0x6)
#define VRX_get_MV_AGC_DET_MB1(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x4B, 0x40, 0x6, pval)
#define VRX_ret_MV_AGC_DET_MB1()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x4B, 0x40, 0x6)
#define VRX_set_MV_AGC_DET_MB1(val)                         ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x4B, 0x40, 0x6, val)

#define VRX_is_MV_CS_DET_MB1_true()                         ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x4B, 0x20, 0x5)
#define VRX_get_MV_CS_DET_MB1(pval)                         ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x4B, 0x20, 0x5, pval)
#define VRX_ret_MV_CS_DET_MB1()                             ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x4B, 0x20, 0x5)
#define VRX_set_MV_CS_DET_MB1(val)                          ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x4B, 0x20, 0x5, val)

#define VRX_is_CP_CGMS_CHNGD_MB1_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x4B, 0x4, 0x2)
#define VRX_get_CP_CGMS_CHNGD_MB1(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x4B, 0x4, 0x2, pval)
#define VRX_ret_CP_CGMS_CHNGD_MB1()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x4B, 0x4, 0x2)
#define VRX_set_CP_CGMS_CHNGD_MB1(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x4B, 0x4, 0x2, val)

#define VRX_is_AVLINK_RX_READY_RAW_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x4C, 0x8, 0x3)
#define VRX_get_AVLINK_RX_READY_RAW(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x4C, 0x8, 0x3, pval)
#define VRX_ret_AVLINK_RX_READY_RAW()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x4C, 0x8, 0x3)

#define VRX_is_AVLINK_TX_RETRY_TIMEOUT_RAW_true()           ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x4C, 0x4, 0x2)
#define VRX_get_AVLINK_TX_RETRY_TIMEOUT_RAW(pval)           ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x4C, 0x4, 0x2, pval)
#define VRX_ret_AVLINK_TX_RETRY_TIMEOUT_RAW()               ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x4C, 0x4, 0x2)

#define VRX_is_AVLINK_TX_ARBITRATION_LOST_RAW_true()        ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x4C, 0x2, 0x1)
#define VRX_get_AVLINK_TX_ARBITRATION_LOST_RAW(pval)        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x4C, 0x2, 0x1, pval)
#define VRX_ret_AVLINK_TX_ARBITRATION_LOST_RAW()            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x4C, 0x2, 0x1)

#define VRX_is_AVLINK_TX_READY_RAW_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x4C, 0x1, 0x0)
#define VRX_get_AVLINK_TX_READY_RAW(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x4C, 0x1, 0x0, pval)
#define VRX_ret_AVLINK_TX_READY_RAW()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x4C, 0x1, 0x0)

#define VRX_is_AVLINK_RX_READY_ST_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x4D, 0x8, 0x3)
#define VRX_get_AVLINK_RX_READY_ST(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x4D, 0x8, 0x3, pval)
#define VRX_ret_AVLINK_RX_READY_ST()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x4D, 0x8, 0x3)

#define VRX_is_AVLINK_TX_RETRY_TIMEOUT_ST_true()            ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x4D, 0x4, 0x2)
#define VRX_get_AVLINK_TX_RETRY_TIMEOUT_ST(pval)            ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x4D, 0x4, 0x2, pval)
#define VRX_ret_AVLINK_TX_RETRY_TIMEOUT_ST()                ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x4D, 0x4, 0x2)

#define VRX_is_AVLINK_TX_ARBITRATION_LOST_ST_true()         ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x4D, 0x2, 0x1)
#define VRX_get_AVLINK_TX_ARBITRATION_LOST_ST(pval)         ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x4D, 0x2, 0x1, pval)
#define VRX_ret_AVLINK_TX_ARBITRATION_LOST_ST()             ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x4D, 0x2, 0x1)

#define VRX_is_AVLINK_TX_READY_ST_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x4D, 0x1, 0x0)
#define VRX_get_AVLINK_TX_READY_ST(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x4D, 0x1, 0x0, pval)
#define VRX_ret_AVLINK_TX_READY_ST()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x4D, 0x1, 0x0)

#define VRX_set_AVLINK_RX_READY_CLR(val)                    ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x4E, 0x8, 0x3, val)

#define VRX_set_AVLINK_TX_RETRY_TIMEOUT_CLR(val)            ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x4E, 0x4, 0x2, val)

#define VRX_set_AVLINK_TX_ARBITRATION_LOST_CLR(val)         ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x4E, 0x2, 0x1, val)

#define VRX_set_AVLINK_TX_READY_CLR(val)                    ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x4E, 0x1, 0x0, val)

#define VRX_is_AVLINK_RX_READY_MB2_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x4F, 0x8, 0x3)
#define VRX_get_AVLINK_RX_READY_MB2(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x4F, 0x8, 0x3, pval)
#define VRX_ret_AVLINK_RX_READY_MB2()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x4F, 0x8, 0x3)
#define VRX_set_AVLINK_RX_READY_MB2(val)                    ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x4F, 0x8, 0x3, val)

#define VRX_is_AVLINK_TX_RETRY_TIMEOUT_MB2_true()           ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x4F, 0x4, 0x2)
#define VRX_get_AVLINK_TX_RETRY_TIMEOUT_MB2(pval)           ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x4F, 0x4, 0x2, pval)
#define VRX_ret_AVLINK_TX_RETRY_TIMEOUT_MB2()               ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x4F, 0x4, 0x2)
#define VRX_set_AVLINK_TX_RETRY_TIMEOUT_MB2(val)            ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x4F, 0x4, 0x2, val)

#define VRX_is_AVLINK_TX_ARBITRATION_LOST_MB2_true()        ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x4F, 0x2, 0x1)
#define VRX_get_AVLINK_TX_ARBITRATION_LOST_MB2(pval)        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x4F, 0x2, 0x1, pval)
#define VRX_ret_AVLINK_TX_ARBITRATION_LOST_MB2()            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x4F, 0x2, 0x1)
#define VRX_set_AVLINK_TX_ARBITRATION_LOST_MB2(val)         ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x4F, 0x2, 0x1, val)

#define VRX_is_AVLINK_TX_READY_MB2_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x4F, 0x1, 0x0)
#define VRX_get_AVLINK_TX_READY_MB2(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x4F, 0x1, 0x0, pval)
#define VRX_ret_AVLINK_TX_READY_MB2()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x4F, 0x1, 0x0)
#define VRX_set_AVLINK_TX_READY_MB2(val)                    ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x4F, 0x1, 0x0, val)

#define VRX_is_AVLINK_RX_READY_MB1_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x50, 0x8, 0x3)
#define VRX_get_AVLINK_RX_READY_MB1(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x50, 0x8, 0x3, pval)
#define VRX_ret_AVLINK_RX_READY_MB1()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x50, 0x8, 0x3)
#define VRX_set_AVLINK_RX_READY_MB1(val)                    ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x50, 0x8, 0x3, val)

#define VRX_is_AVLINK_TX_RETRY_TIMEOUT_MB1_true()           ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x50, 0x4, 0x2)
#define VRX_get_AVLINK_TX_RETRY_TIMEOUT_MB1(pval)           ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x50, 0x4, 0x2, pval)
#define VRX_ret_AVLINK_TX_RETRY_TIMEOUT_MB1()               ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x50, 0x4, 0x2)
#define VRX_set_AVLINK_TX_RETRY_TIMEOUT_MB1(val)            ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x50, 0x4, 0x2, val)

#define VRX_is_AVLINK_TX_ARBITRATION_LOST_MB1_true()        ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x50, 0x2, 0x1)
#define VRX_get_AVLINK_TX_ARBITRATION_LOST_MB1(pval)        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x50, 0x2, 0x1, pval)
#define VRX_ret_AVLINK_TX_ARBITRATION_LOST_MB1()            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x50, 0x2, 0x1)
#define VRX_set_AVLINK_TX_ARBITRATION_LOST_MB1(val)         ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x50, 0x2, 0x1, val)

#define VRX_is_AVLINK_TX_READY_MB1_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x50, 0x1, 0x0)
#define VRX_get_AVLINK_TX_READY_MB1(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x50, 0x1, 0x0, pval)
#define VRX_ret_AVLINK_TX_READY_MB1()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x50, 0x1, 0x0)
#define VRX_set_AVLINK_TX_READY_MB1(val)                    ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x50, 0x1, 0x0, val)

#define VRX_is_TTXT_AVL_RAW_true()                          ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x51, 0x80, 0x7)
#define VRX_get_TTXT_AVL_RAW(pval)                          ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x51, 0x80, 0x7, pval)
#define VRX_ret_TTXT_AVL_RAW()                              ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x51, 0x80, 0x7)

#define VRX_is_VITC_AVL_RAW_true()                          ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x51, 0x40, 0x6)
#define VRX_get_VITC_AVL_RAW(pval)                          ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x51, 0x40, 0x6, pval)
#define VRX_ret_VITC_AVL_RAW()                              ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x51, 0x40, 0x6)

#define VRX_is_GS_DATA_TYPE_RAW_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x51, 0x20, 0x5)
#define VRX_get_GS_DATA_TYPE_RAW(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x51, 0x20, 0x5, pval)
#define VRX_ret_GS_DATA_TYPE_RAW()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x51, 0x20, 0x5)

#define VRX_is_GS_PDC_VPS_UTC_AVL_RAW_true()                ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x51, 0x10, 0x4)
#define VRX_get_GS_PDC_VPS_UTC_AVL_RAW(pval)                ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x51, 0x10, 0x4, pval)
#define VRX_ret_GS_PDC_VPS_UTC_AVL_RAW()                    ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x51, 0x10, 0x4)

#define VRX_is_FASTI2C_DATA_RDY_RAW_true()                  ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x51, 0x8, 0x3)
#define VRX_get_FASTI2C_DATA_RDY_RAW(pval)                  ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x51, 0x8, 0x3, pval)
#define VRX_ret_FASTI2C_DATA_RDY_RAW()                      ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x51, 0x8, 0x3)

#define VRX_is_CGMS_WSS_AVL_RAW_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x51, 0x4, 0x2)
#define VRX_get_CGMS_WSS_AVL_RAW(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x51, 0x4, 0x2, pval)
#define VRX_ret_CGMS_WSS_AVL_RAW()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x51, 0x4, 0x2)

#define VRX_is_CCAP_EVEN_FIELD_RAW_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x51, 0x2, 0x1)
#define VRX_get_CCAP_EVEN_FIELD_RAW(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x51, 0x2, 0x1, pval)
#define VRX_ret_CCAP_EVEN_FIELD_RAW()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x51, 0x2, 0x1)

#define VRX_is_CCAP_AVL_RAW_true()                          ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x51, 0x1, 0x0)
#define VRX_get_CCAP_AVL_RAW(pval)                          ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x51, 0x1, 0x0, pval)
#define VRX_ret_CCAP_AVL_RAW()                              ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x51, 0x1, 0x0)

#define VRX_is_TTXT_AVL_ST_true()                           ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x52, 0x80, 0x7)
#define VRX_get_TTXT_AVL_ST(pval)                           ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x52, 0x80, 0x7, pval)
#define VRX_ret_TTXT_AVL_ST()                               ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x52, 0x80, 0x7)

#define VRX_is_VITC_AVL_ST_true()                           ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x52, 0x40, 0x6)
#define VRX_get_VITC_AVL_ST(pval)                           ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x52, 0x40, 0x6, pval)
#define VRX_ret_VITC_AVL_ST()                               ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x52, 0x40, 0x6)

#define VRX_is_GS_DATA_TYPE_ST_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x52, 0x20, 0x5)
#define VRX_get_GS_DATA_TYPE_ST(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x52, 0x20, 0x5, pval)
#define VRX_ret_GS_DATA_TYPE_ST()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x52, 0x20, 0x5)

#define VRX_is_GS_PDC_VPS_UTC_AVL_ST_true()                 ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x52, 0x10, 0x4)
#define VRX_get_GS_PDC_VPS_UTC_AVL_ST(pval)                 ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x52, 0x10, 0x4, pval)
#define VRX_ret_GS_PDC_VPS_UTC_AVL_ST()                     ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x52, 0x10, 0x4)

#define VRX_is_FASTI2C_DATA_RDY_ST_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x52, 0x8, 0x3)
#define VRX_get_FASTI2C_DATA_RDY_ST(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x52, 0x8, 0x3, pval)
#define VRX_ret_FASTI2C_DATA_RDY_ST()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x52, 0x8, 0x3)

#define VRX_is_CGMS_WSS_AVL_ST_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x52, 0x4, 0x2)
#define VRX_get_CGMS_WSS_AVL_ST(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x52, 0x4, 0x2, pval)
#define VRX_ret_CGMS_WSS_AVL_ST()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x52, 0x4, 0x2)

#define VRX_is_CCAP_EVEN_FIELD_ST_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x52, 0x2, 0x1)
#define VRX_get_CCAP_EVEN_FIELD_ST(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x52, 0x2, 0x1, pval)
#define VRX_ret_CCAP_EVEN_FIELD_ST()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x52, 0x2, 0x1)

#define VRX_is_CCAP_AVL_ST_true()                           ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x52, 0x1, 0x0)
#define VRX_get_CCAP_AVL_ST(pval)                           ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x52, 0x1, 0x0, pval)
#define VRX_ret_CCAP_AVL_ST()                               ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x52, 0x1, 0x0)

#define VRX_set_TTXT_AVL_CLR(val)                           ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x53, 0x80, 0x7, val)

#define VRX_set_VITC_AVL_CLR(val)                           ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x53, 0x40, 0x6, val)

#define VRX_set_GS_DATA_TYPE_CLR(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x53, 0x20, 0x5, val)

#define VRX_set_GS_PDC_VPS_UTC_AVL_CLR(val)                 ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x53, 0x10, 0x4, val)

#define VRX_set_FASTI2C_DATA_RDY_CLR(val)                   ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x53, 0x8, 0x3, val)

#define VRX_set_CGMS_WSS_AVL_CLR(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x53, 0x4, 0x2, val)

#define VRX_set_CCAP_EVEN_FIELD_CLR(val)                    ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x53, 0x2, 0x1, val)

#define VRX_set_CCAP_AVL_CLR(val)                           ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x53, 0x1, 0x0, val)

#define VRX_is_TTXT_AVL_MB2_true()                          ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x54, 0x80, 0x7)
#define VRX_get_TTXT_AVL_MB2(pval)                          ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x54, 0x80, 0x7, pval)
#define VRX_ret_TTXT_AVL_MB2()                              ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x54, 0x80, 0x7)
#define VRX_set_TTXT_AVL_MB2(val)                           ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x54, 0x80, 0x7, val)

#define VRX_is_VITC_AVL_MB2_true()                          ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x54, 0x40, 0x6)
#define VRX_get_VITC_AVL_MB2(pval)                          ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x54, 0x40, 0x6, pval)
#define VRX_ret_VITC_AVL_MB2()                              ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x54, 0x40, 0x6)
#define VRX_set_VITC_AVL_MB2(val)                           ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x54, 0x40, 0x6, val)

#define VRX_is_GS_DATA_TYPE_MB2_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x54, 0x20, 0x5)
#define VRX_get_GS_DATA_TYPE_MB2(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x54, 0x20, 0x5, pval)
#define VRX_ret_GS_DATA_TYPE_MB2()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x54, 0x20, 0x5)
#define VRX_set_GS_DATA_TYPE_MB2(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x54, 0x20, 0x5, val)

#define VRX_is_GS_PDC_VPS_UTC_AVL_MB2_true()                ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x54, 0x10, 0x4)
#define VRX_get_GS_PDC_VPS_UTC_AVL_MB2(pval)                ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x54, 0x10, 0x4, pval)
#define VRX_ret_GS_PDC_VPS_UTC_AVL_MB2()                    ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x54, 0x10, 0x4)
#define VRX_set_GS_PDC_VPS_UTC_AVL_MB2(val)                 ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x54, 0x10, 0x4, val)

#define VRX_is_FASTI2C_DATA_RDY_MB2_true()                  ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x54, 0x8, 0x3)
#define VRX_get_FASTI2C_DATA_RDY_MB2(pval)                  ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x54, 0x8, 0x3, pval)
#define VRX_ret_FASTI2C_DATA_RDY_MB2()                      ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x54, 0x8, 0x3)
#define VRX_set_FASTI2C_DATA_RDY_MB2(val)                   ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x54, 0x8, 0x3, val)

#define VRX_is_CGMS_WSS_AVL_MB2_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x54, 0x4, 0x2)
#define VRX_get_CGMS_WSS_AVL_MB2(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x54, 0x4, 0x2, pval)
#define VRX_ret_CGMS_WSS_AVL_MB2()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x54, 0x4, 0x2)
#define VRX_set_CGMS_WSS_AVL_MB2(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x54, 0x4, 0x2, val)

#define VRX_is_CCAP_EVEN_FIELD_MB2_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x54, 0x2, 0x1)
#define VRX_get_CCAP_EVEN_FIELD_MB2(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x54, 0x2, 0x1, pval)
#define VRX_ret_CCAP_EVEN_FIELD_MB2()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x54, 0x2, 0x1)
#define VRX_set_CCAP_EVEN_FIELD_MB2(val)                    ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x54, 0x2, 0x1, val)

#define VRX_is_CCAP_AVL_MB2_true()                          ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x54, 0x1, 0x0)
#define VRX_get_CCAP_AVL_MB2(pval)                          ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x54, 0x1, 0x0, pval)
#define VRX_ret_CCAP_AVL_MB2()                              ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x54, 0x1, 0x0)
#define VRX_set_CCAP_AVL_MB2(val)                           ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x54, 0x1, 0x0, val)

#define VRX_is_TTXT_AVL_MB1_true()                          ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x55, 0x80, 0x7)
#define VRX_get_TTXT_AVL_MB1(pval)                          ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x55, 0x80, 0x7, pval)
#define VRX_ret_TTXT_AVL_MB1()                              ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x55, 0x80, 0x7)
#define VRX_set_TTXT_AVL_MB1(val)                           ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x55, 0x80, 0x7, val)

#define VRX_is_VITC_AVL_MB1_true()                          ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x55, 0x40, 0x6)
#define VRX_get_VITC_AVL_MB1(pval)                          ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x55, 0x40, 0x6, pval)
#define VRX_ret_VITC_AVL_MB1()                              ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x55, 0x40, 0x6)
#define VRX_set_VITC_AVL_MB1(val)                           ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x55, 0x40, 0x6, val)

#define VRX_is_GS_DATA_TYPE_MB1_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x55, 0x20, 0x5)
#define VRX_get_GS_DATA_TYPE_MB1(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x55, 0x20, 0x5, pval)
#define VRX_ret_GS_DATA_TYPE_MB1()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x55, 0x20, 0x5)
#define VRX_set_GS_DATA_TYPE_MB1(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x55, 0x20, 0x5, val)

#define VRX_is_GS_PDC_VPS_UTC_AVL_MB1_true()                ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x55, 0x10, 0x4)
#define VRX_get_GS_PDC_VPS_UTC_AVL_MB1(pval)                ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x55, 0x10, 0x4, pval)
#define VRX_ret_GS_PDC_VPS_UTC_AVL_MB1()                    ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x55, 0x10, 0x4)
#define VRX_set_GS_PDC_VPS_UTC_AVL_MB1(val)                 ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x55, 0x10, 0x4, val)

#define VRX_is_FASTI2C_DATA_RDY_MB1_true()                  ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x55, 0x8, 0x3)
#define VRX_get_FASTI2C_DATA_RDY_MB1(pval)                  ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x55, 0x8, 0x3, pval)
#define VRX_ret_FASTI2C_DATA_RDY_MB1()                      ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x55, 0x8, 0x3)
#define VRX_set_FASTI2C_DATA_RDY_MB1(val)                   ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x55, 0x8, 0x3, val)

#define VRX_is_CGMS_WSS_AVL_MB1_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x55, 0x4, 0x2)
#define VRX_get_CGMS_WSS_AVL_MB1(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x55, 0x4, 0x2, pval)
#define VRX_ret_CGMS_WSS_AVL_MB1()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x55, 0x4, 0x2)
#define VRX_set_CGMS_WSS_AVL_MB1(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x55, 0x4, 0x2, val)

#define VRX_is_CCAP_EVEN_FIELD_MB1_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x55, 0x2, 0x1)
#define VRX_get_CCAP_EVEN_FIELD_MB1(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x55, 0x2, 0x1, pval)
#define VRX_ret_CCAP_EVEN_FIELD_MB1()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x55, 0x2, 0x1)
#define VRX_set_CCAP_EVEN_FIELD_MB1(val)                    ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x55, 0x2, 0x1, val)

#define VRX_is_CCAP_AVL_MB1_true()                          ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x55, 0x1, 0x0)
#define VRX_get_CCAP_AVL_MB1(pval)                          ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x55, 0x1, 0x0, pval)
#define VRX_ret_CCAP_AVL_MB1()                              ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x55, 0x1, 0x0)
#define VRX_set_CCAP_AVL_MB1(val)                           ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x55, 0x1, 0x0, val)

#define VRX_is_SDP_PROGRESSIVE_RAW_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x56, 0x80, 0x7)
#define VRX_get_SDP_PROGRESSIVE_RAW(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x56, 0x80, 0x7, pval)
#define VRX_ret_SDP_PROGRESSIVE_RAW()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x56, 0x80, 0x7)

#define VRX_is_SDP_PR_DET_RAW_true()                        ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x56, 0x40, 0x6)
#define VRX_get_SDP_PR_DET_RAW(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x56, 0x40, 0x6, pval)
#define VRX_ret_SDP_PR_DET_RAW()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x56, 0x40, 0x6)

#define VRX_is_SDP_SD_DET_RAW_true()                        ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x56, 0x20, 0x5)
#define VRX_get_SDP_SD_DET_RAW(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x56, 0x20, 0x5, pval)
#define VRX_ret_SDP_SD_DET_RAW()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x56, 0x20, 0x5)

#define VRX_is_SDP_50HZ_DET_RAW_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x56, 0x10, 0x4)
#define VRX_get_SDP_50HZ_DET_RAW(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x56, 0x10, 0x4, pval)
#define VRX_ret_SDP_50HZ_DET_RAW()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x56, 0x10, 0x4)

#define VRX_is_SDP_PROGRESSIVE_ST_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x57, 0x80, 0x7)
#define VRX_get_SDP_PROGRESSIVE_ST(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x57, 0x80, 0x7, pval)
#define VRX_ret_SDP_PROGRESSIVE_ST()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x57, 0x80, 0x7)

#define VRX_is_SDP_PR_DET_ST_true()                         ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x57, 0x40, 0x6)
#define VRX_get_SDP_PR_DET_ST(pval)                         ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x57, 0x40, 0x6, pval)
#define VRX_ret_SDP_PR_DET_ST()                             ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x57, 0x40, 0x6)

#define VRX_is_SDP_SD_DET_ST_true()                         ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x57, 0x20, 0x5)
#define VRX_get_SDP_SD_DET_ST(pval)                         ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x57, 0x20, 0x5, pval)
#define VRX_ret_SDP_SD_DET_ST()                             ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x57, 0x20, 0x5)

#define VRX_is_SDP_50HZ_DET_ST_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x57, 0x10, 0x4)
#define VRX_get_SDP_50HZ_DET_ST(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x57, 0x10, 0x4, pval)
#define VRX_ret_SDP_50HZ_DET_ST()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x57, 0x10, 0x4)

#define VRX_set_SDP_PROGRESSIVE_CLR(val)                    ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x58, 0x80, 0x7, val)

#define VRX_set_SDP_PR_DET_CLR(val)                         ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x58, 0x40, 0x6, val)

#define VRX_set_SDP_SD_DET_CLR(val)                         ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x58, 0x20, 0x5, val)

#define VRX_set_SDP_50HZ_DET_CLR(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x58, 0x10, 0x4, val)

#define VRX_is_SDP_PROGRESSIVE_MB2_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x59, 0x80, 0x7)
#define VRX_get_SDP_PROGRESSIVE_MB2(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x59, 0x80, 0x7, pval)
#define VRX_ret_SDP_PROGRESSIVE_MB2()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x59, 0x80, 0x7)
#define VRX_set_SDP_PROGRESSIVE_MB2(val)                    ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x59, 0x80, 0x7, val)

#define VRX_is_SDP_PR_DET_MB2_true()                        ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x59, 0x40, 0x6)
#define VRX_get_SDP_PR_DET_MB2(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x59, 0x40, 0x6, pval)
#define VRX_ret_SDP_PR_DET_MB2()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x59, 0x40, 0x6)
#define VRX_set_SDP_PR_DET_MB2(val)                         ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x59, 0x40, 0x6, val)

#define VRX_is_SDP_SD_DET_MB2_true()                        ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x59, 0x20, 0x5)
#define VRX_get_SDP_SD_DET_MB2(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x59, 0x20, 0x5, pval)
#define VRX_ret_SDP_SD_DET_MB2()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x59, 0x20, 0x5)
#define VRX_set_SDP_SD_DET_MB2(val)                         ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x59, 0x20, 0x5, val)

#define VRX_is_SDP_50HZ_DET_MB2_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x59, 0x10, 0x4)
#define VRX_get_SDP_50HZ_DET_MB2(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x59, 0x10, 0x4, pval)
#define VRX_ret_SDP_50HZ_DET_MB2()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x59, 0x10, 0x4)
#define VRX_set_SDP_50HZ_DET_MB2(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x59, 0x10, 0x4, val)

#define VRX_is_SDP_PROGRESSIVE_MB1_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x5A, 0x80, 0x7)
#define VRX_get_SDP_PROGRESSIVE_MB1(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x5A, 0x80, 0x7, pval)
#define VRX_ret_SDP_PROGRESSIVE_MB1()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x5A, 0x80, 0x7)
#define VRX_set_SDP_PROGRESSIVE_MB1(val)                    ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x5A, 0x80, 0x7, val)

#define VRX_is_SDP_PR_DET_MB1_true()                        ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x5A, 0x40, 0x6)
#define VRX_get_SDP_PR_DET_MB1(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x5A, 0x40, 0x6, pval)
#define VRX_ret_SDP_PR_DET_MB1()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x5A, 0x40, 0x6)
#define VRX_set_SDP_PR_DET_MB1(val)                         ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x5A, 0x40, 0x6, val)

#define VRX_is_SDP_SD_DET_MB1_true()                        ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x5A, 0x20, 0x5)
#define VRX_get_SDP_SD_DET_MB1(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x5A, 0x20, 0x5, pval)
#define VRX_ret_SDP_SD_DET_MB1()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x5A, 0x20, 0x5)
#define VRX_set_SDP_SD_DET_MB1(val)                         ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x5A, 0x20, 0x5, val)

#define VRX_is_SDP_50HZ_DET_MB1_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x5A, 0x10, 0x4)
#define VRX_get_SDP_50HZ_DET_MB1(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x5A, 0x10, 0x4, pval)
#define VRX_ret_SDP_50HZ_DET_MB1()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x5A, 0x10, 0x4)
#define VRX_set_SDP_50HZ_DET_MB1(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x5A, 0x10, 0x4, val)

#define VRX_is_CP_LOCK_CH2_RAW_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x5B, 0x80, 0x7)
#define VRX_get_CP_LOCK_CH2_RAW(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x5B, 0x80, 0x7, pval)
#define VRX_ret_CP_LOCK_CH2_RAW()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x5B, 0x80, 0x7)

#define VRX_is_CP_UNLOCK_CH2_RAW_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x5B, 0x40, 0x6)
#define VRX_get_CP_UNLOCK_CH2_RAW(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x5B, 0x40, 0x6, pval)
#define VRX_ret_CP_UNLOCK_CH2_RAW()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x5B, 0x40, 0x6)

#define VRX_is_STDI_DVALID_CH2_RAW_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x5B, 0x20, 0x5)
#define VRX_get_STDI_DVALID_CH2_RAW(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x5B, 0x20, 0x5, pval)
#define VRX_ret_STDI_DVALID_CH2_RAW()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x5B, 0x20, 0x5)

#define VRX_is_SSPD_RSLT_CHNGD_CH2_RAW_true()               ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x5B, 0x10, 0x4)
#define VRX_get_SSPD_RSLT_CHNGD_CH2_RAW(pval)               ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x5B, 0x10, 0x4, pval)
#define VRX_ret_SSPD_RSLT_CHNGD_CH2_RAW()                   ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x5B, 0x10, 0x4)

#define VRX_is_CP_LOCK_CH1_RAW_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x5B, 0x8, 0x3)
#define VRX_get_CP_LOCK_CH1_RAW(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x5B, 0x8, 0x3, pval)
#define VRX_ret_CP_LOCK_CH1_RAW()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x5B, 0x8, 0x3)

#define VRX_is_CP_UNLOCK_CH1_RAW_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x5B, 0x4, 0x2)
#define VRX_get_CP_UNLOCK_CH1_RAW(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x5B, 0x4, 0x2, pval)
#define VRX_ret_CP_UNLOCK_CH1_RAW()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x5B, 0x4, 0x2)

#define VRX_is_STDI_DVALID_CH1_RAW_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x5B, 0x2, 0x1)
#define VRX_get_STDI_DVALID_CH1_RAW(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x5B, 0x2, 0x1, pval)
#define VRX_ret_STDI_DVALID_CH1_RAW()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x5B, 0x2, 0x1)

#define VRX_is_SSPD_RSLT_CHNGD_CH1_RAW_true()               ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x5B, 0x1, 0x0)
#define VRX_get_SSPD_RSLT_CHNGD_CH1_RAW(pval)               ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x5B, 0x1, 0x0, pval)
#define VRX_ret_SSPD_RSLT_CHNGD_CH1_RAW()                   ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x5B, 0x1, 0x0)

#define VRX_is_CP_LOCK_CH2_ST_true()                        ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x5C, 0x80, 0x7)
#define VRX_get_CP_LOCK_CH2_ST(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x5C, 0x80, 0x7, pval)
#define VRX_ret_CP_LOCK_CH2_ST()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x5C, 0x80, 0x7)

#define VRX_is_CP_UNLOCK_CH2_ST_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x5C, 0x40, 0x6)
#define VRX_get_CP_UNLOCK_CH2_ST(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x5C, 0x40, 0x6, pval)
#define VRX_ret_CP_UNLOCK_CH2_ST()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x5C, 0x40, 0x6)

#define VRX_is_STDI_DVALID_CH2_ST_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x5C, 0x20, 0x5)
#define VRX_get_STDI_DVALID_CH2_ST(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x5C, 0x20, 0x5, pval)
#define VRX_ret_STDI_DVALID_CH2_ST()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x5C, 0x20, 0x5)

#define VRX_is_SSPD_RSLT_CHNGD_CH2_ST_true()                ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x5C, 0x10, 0x4)
#define VRX_get_SSPD_RSLT_CHNGD_CH2_ST(pval)                ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x5C, 0x10, 0x4, pval)
#define VRX_ret_SSPD_RSLT_CHNGD_CH2_ST()                    ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x5C, 0x10, 0x4)

#define VRX_is_CP_LOCK_CH1_ST_true()                        ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x5C, 0x8, 0x3)
#define VRX_get_CP_LOCK_CH1_ST(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x5C, 0x8, 0x3, pval)
#define VRX_ret_CP_LOCK_CH1_ST()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x5C, 0x8, 0x3)

#define VRX_is_CP_UNLOCK_CH1_ST_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x5C, 0x4, 0x2)
#define VRX_get_CP_UNLOCK_CH1_ST(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x5C, 0x4, 0x2, pval)
#define VRX_ret_CP_UNLOCK_CH1_ST()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x5C, 0x4, 0x2)

#define VRX_is_STDI_DVALID_CH1_ST_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x5C, 0x2, 0x1)
#define VRX_get_STDI_DVALID_CH1_ST(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x5C, 0x2, 0x1, pval)
#define VRX_ret_STDI_DVALID_CH1_ST()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x5C, 0x2, 0x1)

#define VRX_is_SSPD_RSLT_CHNGD_CH1_ST_true()                ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x5C, 0x1, 0x0)
#define VRX_get_SSPD_RSLT_CHNGD_CH1_ST(pval)                ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x5C, 0x1, 0x0, pval)
#define VRX_ret_SSPD_RSLT_CHNGD_CH1_ST()                    ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x5C, 0x1, 0x0)

#define VRX_set_CP_LOCK_CH2_CLR(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x5D, 0x80, 0x7, val)

#define VRX_set_CP_UNLOCK_CH2_CLR(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x5D, 0x40, 0x6, val)

#define VRX_set_STDI_DVALID_CH2_CLR(val)                    ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x5D, 0x20, 0x5, val)

#define VRX_set_SSPD_RSLT_CHNGD_CH2_CLR(val)                ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x5D, 0x10, 0x4, val)

#define VRX_set_CP_LOCK_CH1_CLR(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x5D, 0x8, 0x3, val)

#define VRX_set_CP_UNLOCK_CH1_CLR(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x5D, 0x4, 0x2, val)

#define VRX_set_STDI_DVALID_CH1_CLR(val)                    ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x5D, 0x2, 0x1, val)

#define VRX_set_SSPD_RSLT_CHNGD_CH1_CLR(val)                ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x5D, 0x1, 0x0, val)

#define VRX_is_CP_LOCK_CH2_MB2_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x5E, 0x80, 0x7)
#define VRX_get_CP_LOCK_CH2_MB2(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x5E, 0x80, 0x7, pval)
#define VRX_ret_CP_LOCK_CH2_MB2()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x5E, 0x80, 0x7)
#define VRX_set_CP_LOCK_CH2_MB2(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x5E, 0x80, 0x7, val)

#define VRX_is_CP_UNLOCK_CH2_MB2_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x5E, 0x40, 0x6)
#define VRX_get_CP_UNLOCK_CH2_MB2(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x5E, 0x40, 0x6, pval)
#define VRX_ret_CP_UNLOCK_CH2_MB2()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x5E, 0x40, 0x6)
#define VRX_set_CP_UNLOCK_CH2_MB2(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x5E, 0x40, 0x6, val)

#define VRX_is_STDI_DVALID_CH2_MB2_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x5E, 0x20, 0x5)
#define VRX_get_STDI_DVALID_CH2_MB2(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x5E, 0x20, 0x5, pval)
#define VRX_ret_STDI_DVALID_CH2_MB2()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x5E, 0x20, 0x5)
#define VRX_set_STDI_DVALID_CH2_MB2(val)                    ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x5E, 0x20, 0x5, val)

#define VRX_is_SSPD_RSLT_CHNGD_CH2_MB2_true()               ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x5E, 0x10, 0x4)
#define VRX_get_SSPD_RSLT_CHNGD_CH2_MB2(pval)               ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x5E, 0x10, 0x4, pval)
#define VRX_ret_SSPD_RSLT_CHNGD_CH2_MB2()                   ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x5E, 0x10, 0x4)
#define VRX_set_SSPD_RSLT_CHNGD_CH2_MB2(val)                ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x5E, 0x10, 0x4, val)

#define VRX_is_CP_LOCK_CH1_MB2_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x5E, 0x8, 0x3)
#define VRX_get_CP_LOCK_CH1_MB2(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x5E, 0x8, 0x3, pval)
#define VRX_ret_CP_LOCK_CH1_MB2()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x5E, 0x8, 0x3)
#define VRX_set_CP_LOCK_CH1_MB2(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x5E, 0x8, 0x3, val)

#define VRX_is_CP_UNLOCK_CH1_MB2_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x5E, 0x4, 0x2)
#define VRX_get_CP_UNLOCK_CH1_MB2(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x5E, 0x4, 0x2, pval)
#define VRX_ret_CP_UNLOCK_CH1_MB2()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x5E, 0x4, 0x2)
#define VRX_set_CP_UNLOCK_CH1_MB2(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x5E, 0x4, 0x2, val)

#define VRX_is_STDI_DVALID_CH1_MB2_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x5E, 0x2, 0x1)
#define VRX_get_STDI_DVALID_CH1_MB2(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x5E, 0x2, 0x1, pval)
#define VRX_ret_STDI_DVALID_CH1_MB2()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x5E, 0x2, 0x1)
#define VRX_set_STDI_DVALID_CH1_MB2(val)                    ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x5E, 0x2, 0x1, val)

#define VRX_is_SSPD_RSLT_CHNGD_CH1_MB2_true()               ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x5E, 0x1, 0x0)
#define VRX_get_SSPD_RSLT_CHNGD_CH1_MB2(pval)               ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x5E, 0x1, 0x0, pval)
#define VRX_ret_SSPD_RSLT_CHNGD_CH1_MB2()                   ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x5E, 0x1, 0x0)
#define VRX_set_SSPD_RSLT_CHNGD_CH1_MB2(val)                ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x5E, 0x1, 0x0, val)

#define VRX_is_CP_LOCK_CH2_MB1_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x5F, 0x80, 0x7)
#define VRX_get_CP_LOCK_CH2_MB1(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x5F, 0x80, 0x7, pval)
#define VRX_ret_CP_LOCK_CH2_MB1()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x5F, 0x80, 0x7)
#define VRX_set_CP_LOCK_CH2_MB1(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x5F, 0x80, 0x7, val)

#define VRX_is_CP_UNLOCK_CH2_MB1_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x5F, 0x40, 0x6)
#define VRX_get_CP_UNLOCK_CH2_MB1(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x5F, 0x40, 0x6, pval)
#define VRX_ret_CP_UNLOCK_CH2_MB1()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x5F, 0x40, 0x6)
#define VRX_set_CP_UNLOCK_CH2_MB1(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x5F, 0x40, 0x6, val)

#define VRX_is_STDI_DVALID_CH2_MB1_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x5F, 0x20, 0x5)
#define VRX_get_STDI_DVALID_CH2_MB1(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x5F, 0x20, 0x5, pval)
#define VRX_ret_STDI_DVALID_CH2_MB1()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x5F, 0x20, 0x5)
#define VRX_set_STDI_DVALID_CH2_MB1(val)                    ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x5F, 0x20, 0x5, val)

#define VRX_is_SSPD_RSLT_CHNGD_CH2_MB1_true()               ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x5F, 0x10, 0x4)
#define VRX_get_SSPD_RSLT_CHNGD_CH2_MB1(pval)               ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x5F, 0x10, 0x4, pval)
#define VRX_ret_SSPD_RSLT_CHNGD_CH2_MB1()                   ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x5F, 0x10, 0x4)
#define VRX_set_SSPD_RSLT_CHNGD_CH2_MB1(val)                ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x5F, 0x10, 0x4, val)

#define VRX_is_CP_LOCK_CH1_MB1_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x5F, 0x8, 0x3)
#define VRX_get_CP_LOCK_CH1_MB1(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x5F, 0x8, 0x3, pval)
#define VRX_ret_CP_LOCK_CH1_MB1()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x5F, 0x8, 0x3)
#define VRX_set_CP_LOCK_CH1_MB1(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x5F, 0x8, 0x3, val)

#define VRX_is_CP_UNLOCK_CH1_MB1_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x5F, 0x4, 0x2)
#define VRX_get_CP_UNLOCK_CH1_MB1(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x5F, 0x4, 0x2, pval)
#define VRX_ret_CP_UNLOCK_CH1_MB1()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x5F, 0x4, 0x2)
#define VRX_set_CP_UNLOCK_CH1_MB1(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x5F, 0x4, 0x2, val)

#define VRX_is_STDI_DVALID_CH1_MB1_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x5F, 0x2, 0x1)
#define VRX_get_STDI_DVALID_CH1_MB1(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x5F, 0x2, 0x1, pval)
#define VRX_ret_STDI_DVALID_CH1_MB1()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x5F, 0x2, 0x1)
#define VRX_set_STDI_DVALID_CH1_MB1(val)                    ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x5F, 0x2, 0x1, val)

#define VRX_is_SSPD_RSLT_CHNGD_CH1_MB1_true()               ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x5F, 0x1, 0x0)
#define VRX_get_SSPD_RSLT_CHNGD_CH1_MB1(pval)               ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x5F, 0x1, 0x0, pval)
#define VRX_ret_SSPD_RSLT_CHNGD_CH1_MB1()                   ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x5F, 0x1, 0x0)
#define VRX_set_SSPD_RSLT_CHNGD_CH1_MB1(val)                ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x5F, 0x1, 0x0, val)

#define VRX_is_ISRC2_PCKT_RAW_true()                        ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x60, 0x80, 0x7)
#define VRX_get_ISRC2_PCKT_RAW(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x60, 0x80, 0x7, pval)
#define VRX_ret_ISRC2_PCKT_RAW()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x60, 0x80, 0x7)

#define VRX_is_ISRC1_PCKT_RAW_true()                        ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x60, 0x40, 0x6)
#define VRX_get_ISRC1_PCKT_RAW(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x60, 0x40, 0x6, pval)
#define VRX_ret_ISRC1_PCKT_RAW()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x60, 0x40, 0x6)

#define VRX_is_ACP_PCKT_RAW_true()                          ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x60, 0x20, 0x5)
#define VRX_get_ACP_PCKT_RAW(pval)                          ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x60, 0x20, 0x5, pval)
#define VRX_ret_ACP_PCKT_RAW()                              ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x60, 0x20, 0x5)

#define VRX_is_VS_INFO_RAW_true()                           ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x60, 0x10, 0x4)
#define VRX_get_VS_INFO_RAW(pval)                           ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x60, 0x10, 0x4, pval)
#define VRX_ret_VS_INFO_RAW()                               ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x60, 0x10, 0x4)

#define VRX_is_MS_INFO_RAW_true()                           ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x60, 0x8, 0x3)
#define VRX_get_MS_INFO_RAW(pval)                           ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x60, 0x8, 0x3, pval)
#define VRX_ret_MS_INFO_RAW()                               ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x60, 0x8, 0x3)

#define VRX_is_SPD_INFO_RAW_true()                          ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x60, 0x4, 0x2)
#define VRX_get_SPD_INFO_RAW(pval)                          ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x60, 0x4, 0x2, pval)
#define VRX_ret_SPD_INFO_RAW()                              ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x60, 0x4, 0x2)

#define VRX_is_AUDIO_INFO_RAW_true()                        ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x60, 0x2, 0x1)
#define VRX_get_AUDIO_INFO_RAW(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x60, 0x2, 0x1, pval)
#define VRX_ret_AUDIO_INFO_RAW()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x60, 0x2, 0x1)

#define VRX_is_AVI_INFO_RAW_true()                          ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x60, 0x1, 0x0)
#define VRX_get_AVI_INFO_RAW(pval)                          ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x60, 0x1, 0x0, pval)
#define VRX_ret_AVI_INFO_RAW()                              ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x60, 0x1, 0x0)

#define VRX_is_ISRC2_PCKT_ST_true()                         ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x61, 0x80, 0x7)
#define VRX_get_ISRC2_PCKT_ST(pval)                         ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x61, 0x80, 0x7, pval)
#define VRX_ret_ISRC2_PCKT_ST()                             ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x61, 0x80, 0x7)

#define VRX_is_ISRC1_PCKT_ST_true()                         ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x61, 0x40, 0x6)
#define VRX_get_ISRC1_PCKT_ST(pval)                         ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x61, 0x40, 0x6, pval)
#define VRX_ret_ISRC1_PCKT_ST()                             ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x61, 0x40, 0x6)

#define VRX_is_ACP_PCKT_ST_true()                           ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x61, 0x20, 0x5)
#define VRX_get_ACP_PCKT_ST(pval)                           ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x61, 0x20, 0x5, pval)
#define VRX_ret_ACP_PCKT_ST()                               ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x61, 0x20, 0x5)

#define VRX_is_VS_INFO_ST_true()                            ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x61, 0x10, 0x4)
#define VRX_get_VS_INFO_ST(pval)                            ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x61, 0x10, 0x4, pval)
#define VRX_ret_VS_INFO_ST()                                ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x61, 0x10, 0x4)

#define VRX_is_MS_INFO_ST_true()                            ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x61, 0x8, 0x3)
#define VRX_get_MS_INFO_ST(pval)                            ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x61, 0x8, 0x3, pval)
#define VRX_ret_MS_INFO_ST()                                ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x61, 0x8, 0x3)

#define VRX_is_SPD_INFO_ST_true()                           ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x61, 0x4, 0x2)
#define VRX_get_SPD_INFO_ST(pval)                           ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x61, 0x4, 0x2, pval)
#define VRX_ret_SPD_INFO_ST()                               ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x61, 0x4, 0x2)

#define VRX_is_AUDIO_INFO_ST_true()                         ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x61, 0x2, 0x1)
#define VRX_get_AUDIO_INFO_ST(pval)                         ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x61, 0x2, 0x1, pval)
#define VRX_ret_AUDIO_INFO_ST()                             ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x61, 0x2, 0x1)

#define VRX_is_AVI_INFO_ST_true()                           ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x61, 0x1, 0x0)
#define VRX_get_AVI_INFO_ST(pval)                           ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x61, 0x1, 0x0, pval)
#define VRX_ret_AVI_INFO_ST()                               ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x61, 0x1, 0x0)

#define VRX_set_ISRC2_PCKT_CLR(val)                         ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x62, 0x80, 0x7, val)

#define VRX_set_ISRC1_PCKT_CLR(val)                         ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x62, 0x40, 0x6, val)

#define VRX_set_ACP_PCKT_CLR(val)                           ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x62, 0x20, 0x5, val)

#define VRX_set_VS_INFO_CLR(val)                            ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x62, 0x10, 0x4, val)

#define VRX_set_MS_INFO_CLR(val)                            ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x62, 0x8, 0x3, val)

#define VRX_set_SPD_INFO_CLR(val)                           ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x62, 0x4, 0x2, val)

#define VRX_set_AUDIO_INFO_CLR(val)                         ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x62, 0x2, 0x1, val)

#define VRX_set_AVI_INFO_CLR(val)                           ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x62, 0x1, 0x0, val)

#define VRX_is_ISRC2_PCKT_MB2_true()                        ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x63, 0x80, 0x7)
#define VRX_get_ISRC2_PCKT_MB2(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x63, 0x80, 0x7, pval)
#define VRX_ret_ISRC2_PCKT_MB2()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x63, 0x80, 0x7)
#define VRX_set_ISRC2_PCKT_MB2(val)                         ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x63, 0x80, 0x7, val)

#define VRX_is_ISRC1_PCKT_MB2_true()                        ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x63, 0x40, 0x6)
#define VRX_get_ISRC1_PCKT_MB2(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x63, 0x40, 0x6, pval)
#define VRX_ret_ISRC1_PCKT_MB2()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x63, 0x40, 0x6)
#define VRX_set_ISRC1_PCKT_MB2(val)                         ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x63, 0x40, 0x6, val)

#define VRX_is_ACP_PCKT_MB2_true()                          ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x63, 0x20, 0x5)
#define VRX_get_ACP_PCKT_MB2(pval)                          ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x63, 0x20, 0x5, pval)
#define VRX_ret_ACP_PCKT_MB2()                              ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x63, 0x20, 0x5)
#define VRX_set_ACP_PCKT_MB2(val)                           ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x63, 0x20, 0x5, val)

#define VRX_is_VS_INFO_MB2_true()                           ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x63, 0x10, 0x4)
#define VRX_get_VS_INFO_MB2(pval)                           ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x63, 0x10, 0x4, pval)
#define VRX_ret_VS_INFO_MB2()                               ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x63, 0x10, 0x4)
#define VRX_set_VS_INFO_MB2(val)                            ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x63, 0x10, 0x4, val)

#define VRX_is_MS_INFO_MB2_true()                           ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x63, 0x8, 0x3)
#define VRX_get_MS_INFO_MB2(pval)                           ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x63, 0x8, 0x3, pval)
#define VRX_ret_MS_INFO_MB2()                               ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x63, 0x8, 0x3)
#define VRX_set_MS_INFO_MB2(val)                            ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x63, 0x8, 0x3, val)

#define VRX_is_SPD_INFO_MB2_true()                          ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x63, 0x4, 0x2)
#define VRX_get_SPD_INFO_MB2(pval)                          ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x63, 0x4, 0x2, pval)
#define VRX_ret_SPD_INFO_MB2()                              ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x63, 0x4, 0x2)
#define VRX_set_SPD_INFO_MB2(val)                           ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x63, 0x4, 0x2, val)

#define VRX_is_AUDIO_INFO_MB2_true()                        ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x63, 0x2, 0x1)
#define VRX_get_AUDIO_INFO_MB2(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x63, 0x2, 0x1, pval)
#define VRX_ret_AUDIO_INFO_MB2()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x63, 0x2, 0x1)
#define VRX_set_AUDIO_INFO_MB2(val)                         ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x63, 0x2, 0x1, val)

#define VRX_is_AVI_INFO_MB2_true()                          ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x63, 0x1, 0x0)
#define VRX_get_AVI_INFO_MB2(pval)                          ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x63, 0x1, 0x0, pval)
#define VRX_ret_AVI_INFO_MB2()                              ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x63, 0x1, 0x0)
#define VRX_set_AVI_INFO_MB2(val)                           ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x63, 0x1, 0x0, val)

#define VRX_is_ISRC2_PCKT_MB1_true()                        ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x64, 0x80, 0x7)
#define VRX_get_ISRC2_PCKT_MB1(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x64, 0x80, 0x7, pval)
#define VRX_ret_ISRC2_PCKT_MB1()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x64, 0x80, 0x7)
#define VRX_set_ISRC2_PCKT_MB1(val)                         ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x64, 0x80, 0x7, val)

#define VRX_is_ISRC1_PCKT_MB1_true()                        ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x64, 0x40, 0x6)
#define VRX_get_ISRC1_PCKT_MB1(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x64, 0x40, 0x6, pval)
#define VRX_ret_ISRC1_PCKT_MB1()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x64, 0x40, 0x6)
#define VRX_set_ISRC1_PCKT_MB1(val)                         ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x64, 0x40, 0x6, val)

#define VRX_is_ACP_PCKT_MB1_true()                          ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x64, 0x20, 0x5)
#define VRX_get_ACP_PCKT_MB1(pval)                          ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x64, 0x20, 0x5, pval)
#define VRX_ret_ACP_PCKT_MB1()                              ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x64, 0x20, 0x5)
#define VRX_set_ACP_PCKT_MB1(val)                           ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x64, 0x20, 0x5, val)

#define VRX_is_VS_INFO_MB1_true()                           ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x64, 0x10, 0x4)
#define VRX_get_VS_INFO_MB1(pval)                           ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x64, 0x10, 0x4, pval)
#define VRX_ret_VS_INFO_MB1()                               ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x64, 0x10, 0x4)
#define VRX_set_VS_INFO_MB1(val)                            ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x64, 0x10, 0x4, val)

#define VRX_is_MS_INFO_MB1_true()                           ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x64, 0x8, 0x3)
#define VRX_get_MS_INFO_MB1(pval)                           ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x64, 0x8, 0x3, pval)
#define VRX_ret_MS_INFO_MB1()                               ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x64, 0x8, 0x3)
#define VRX_set_MS_INFO_MB1(val)                            ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x64, 0x8, 0x3, val)

#define VRX_is_SPD_INFO_MB1_true()                          ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x64, 0x4, 0x2)
#define VRX_get_SPD_INFO_MB1(pval)                          ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x64, 0x4, 0x2, pval)
#define VRX_ret_SPD_INFO_MB1()                              ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x64, 0x4, 0x2)
#define VRX_set_SPD_INFO_MB1(val)                           ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x64, 0x4, 0x2, val)

#define VRX_is_AUDIO_INFO_MB1_true()                        ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x64, 0x2, 0x1)
#define VRX_get_AUDIO_INFO_MB1(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x64, 0x2, 0x1, pval)
#define VRX_ret_AUDIO_INFO_MB1()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x64, 0x2, 0x1)
#define VRX_set_AUDIO_INFO_MB1(val)                         ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x64, 0x2, 0x1, val)

#define VRX_is_AVI_INFO_MB1_true()                          ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x64, 0x1, 0x0)
#define VRX_get_AVI_INFO_MB1(pval)                          ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x64, 0x1, 0x0, pval)
#define VRX_ret_AVI_INFO_MB1()                              ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x64, 0x1, 0x0)
#define VRX_set_AVI_INFO_MB1(val)                           ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x64, 0x1, 0x0, val)

#define VRX_is_CS_DATA_VALID_RAW_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x65, 0x80, 0x7)
#define VRX_get_CS_DATA_VALID_RAW(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x65, 0x80, 0x7, pval)
#define VRX_ret_CS_DATA_VALID_RAW()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x65, 0x80, 0x7)

#define VRX_is_INTERNAL_MUTE_RAW_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x65, 0x40, 0x6)
#define VRX_get_INTERNAL_MUTE_RAW(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x65, 0x40, 0x6, pval)
#define VRX_ret_INTERNAL_MUTE_RAW()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x65, 0x40, 0x6)

#define VRX_is_AV_MUTE_RAW_true()                           ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x65, 0x20, 0x5)
#define VRX_get_AV_MUTE_RAW(pval)                           ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x65, 0x20, 0x5, pval)
#define VRX_ret_AV_MUTE_RAW()                               ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x65, 0x20, 0x5)

#define VRX_is_AUDIO_CH_MD_RAW_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x65, 0x10, 0x4)
#define VRX_get_AUDIO_CH_MD_RAW(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x65, 0x10, 0x4, pval)
#define VRX_ret_AUDIO_CH_MD_RAW()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x65, 0x10, 0x4)

#define VRX_is_HDMI_MODE_RAW_true()                         ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x65, 0x8, 0x3)
#define VRX_get_HDMI_MODE_RAW(pval)                         ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x65, 0x8, 0x3, pval)
#define VRX_ret_HDMI_MODE_RAW()                             ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x65, 0x8, 0x3)

#define VRX_is_GEN_CTL_PCKT_RAW_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x65, 0x4, 0x2)
#define VRX_get_GEN_CTL_PCKT_RAW(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x65, 0x4, 0x2, pval)
#define VRX_ret_GEN_CTL_PCKT_RAW()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x65, 0x4, 0x2)

#define VRX_is_AUDIO_C_PCKT_RAW_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x65, 0x2, 0x1)
#define VRX_get_AUDIO_C_PCKT_RAW(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x65, 0x2, 0x1, pval)
#define VRX_ret_AUDIO_C_PCKT_RAW()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x65, 0x2, 0x1)

#define VRX_is_GAMUT_MDATA_RAW_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x65, 0x1, 0x0)
#define VRX_get_GAMUT_MDATA_RAW(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x65, 0x1, 0x0, pval)
#define VRX_ret_GAMUT_MDATA_RAW()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x65, 0x1, 0x0)

#define VRX_is_CS_DATA_VALID_ST_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x66, 0x80, 0x7)
#define VRX_get_CS_DATA_VALID_ST(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x66, 0x80, 0x7, pval)
#define VRX_ret_CS_DATA_VALID_ST()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x66, 0x80, 0x7)

#define VRX_is_INTERNAL_MUTE_ST_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x66, 0x40, 0x6)
#define VRX_get_INTERNAL_MUTE_ST(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x66, 0x40, 0x6, pval)
#define VRX_ret_INTERNAL_MUTE_ST()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x66, 0x40, 0x6)

#define VRX_is_AV_MUTE_ST_true()                            ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x66, 0x20, 0x5)
#define VRX_get_AV_MUTE_ST(pval)                            ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x66, 0x20, 0x5, pval)
#define VRX_ret_AV_MUTE_ST()                                ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x66, 0x20, 0x5)

#define VRX_is_AUDIO_CH_MD_ST_true()                        ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x66, 0x10, 0x4)
#define VRX_get_AUDIO_CH_MD_ST(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x66, 0x10, 0x4, pval)
#define VRX_ret_AUDIO_CH_MD_ST()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x66, 0x10, 0x4)

#define VRX_is_HDMI_MODE_ST_true()                          ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x66, 0x8, 0x3)
#define VRX_get_HDMI_MODE_ST(pval)                          ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x66, 0x8, 0x3, pval)
#define VRX_ret_HDMI_MODE_ST()                              ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x66, 0x8, 0x3)

#define VRX_is_GEN_CTL_PCKT_ST_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x66, 0x4, 0x2)
#define VRX_get_GEN_CTL_PCKT_ST(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x66, 0x4, 0x2, pval)
#define VRX_ret_GEN_CTL_PCKT_ST()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x66, 0x4, 0x2)

#define VRX_is_AUDIO_C_PCKT_ST_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x66, 0x2, 0x1)
#define VRX_get_AUDIO_C_PCKT_ST(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x66, 0x2, 0x1, pval)
#define VRX_ret_AUDIO_C_PCKT_ST()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x66, 0x2, 0x1)

#define VRX_is_GAMUT_MDATA_ST_true()                        ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x66, 0x1, 0x0)
#define VRX_get_GAMUT_MDATA_ST(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x66, 0x1, 0x0, pval)
#define VRX_ret_GAMUT_MDATA_ST()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x66, 0x1, 0x0)

#define VRX_set_CS_DATA_VALID_CLR(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x67, 0x80, 0x7, val)

#define VRX_set_INTERNAL_MUTE_CLR(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x67, 0x40, 0x6, val)

#define VRX_set_AV_MUTE_CLR(val)                            ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x67, 0x20, 0x5, val)

#define VRX_set_AUDIO_CH_MD_CLR(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x67, 0x10, 0x4, val)

#define VRX_set_HDMI_MODE_CLR(val)                          ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x67, 0x8, 0x3, val)

#define VRX_set_GEN_CTL_PCKT_CLR(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x67, 0x4, 0x2, val)

#define VRX_set_AUDIO_C_PCKT_CLR(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x67, 0x2, 0x1, val)

#define VRX_set_GAMUT_MDATA_CLR(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x67, 0x1, 0x0, val)

#define VRX_is_CS_DATA_VALID_MB2_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x68, 0x80, 0x7)
#define VRX_get_CS_DATA_VALID_MB2(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x68, 0x80, 0x7, pval)
#define VRX_ret_CS_DATA_VALID_MB2()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x68, 0x80, 0x7)
#define VRX_set_CS_DATA_VALID_MB2(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x68, 0x80, 0x7, val)

#define VRX_is_INTERNAL_MUTE_MB2_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x68, 0x40, 0x6)
#define VRX_get_INTERNAL_MUTE_MB2(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x68, 0x40, 0x6, pval)
#define VRX_ret_INTERNAL_MUTE_MB2()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x68, 0x40, 0x6)
#define VRX_set_INTERNAL_MUTE_MB2(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x68, 0x40, 0x6, val)

#define VRX_is_AV_MUTE_MB2_true()                           ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x68, 0x20, 0x5)
#define VRX_get_AV_MUTE_MB2(pval)                           ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x68, 0x20, 0x5, pval)
#define VRX_ret_AV_MUTE_MB2()                               ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x68, 0x20, 0x5)
#define VRX_set_AV_MUTE_MB2(val)                            ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x68, 0x20, 0x5, val)

#define VRX_is_AUDIO_CH_MD_MB2_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x68, 0x10, 0x4)
#define VRX_get_AUDIO_CH_MD_MB2(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x68, 0x10, 0x4, pval)
#define VRX_ret_AUDIO_CH_MD_MB2()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x68, 0x10, 0x4)
#define VRX_set_AUDIO_CH_MD_MB2(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x68, 0x10, 0x4, val)

#define VRX_is_HDMI_MODE_MB2_true()                         ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x68, 0x8, 0x3)
#define VRX_get_HDMI_MODE_MB2(pval)                         ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x68, 0x8, 0x3, pval)
#define VRX_ret_HDMI_MODE_MB2()                             ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x68, 0x8, 0x3)
#define VRX_set_HDMI_MODE_MB2(val)                          ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x68, 0x8, 0x3, val)

#define VRX_is_GEN_CTL_PCKT_MB2_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x68, 0x4, 0x2)
#define VRX_get_GEN_CTL_PCKT_MB2(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x68, 0x4, 0x2, pval)
#define VRX_ret_GEN_CTL_PCKT_MB2()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x68, 0x4, 0x2)
#define VRX_set_GEN_CTL_PCKT_MB2(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x68, 0x4, 0x2, val)

#define VRX_is_AUDIO_C_PCKT_MB2_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x68, 0x2, 0x1)
#define VRX_get_AUDIO_C_PCKT_MB2(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x68, 0x2, 0x1, pval)
#define VRX_ret_AUDIO_C_PCKT_MB2()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x68, 0x2, 0x1)
#define VRX_set_AUDIO_C_PCKT_MB2(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x68, 0x2, 0x1, val)

#define VRX_is_GAMUT_MDATA_MB2_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x68, 0x1, 0x0)
#define VRX_get_GAMUT_MDATA_MB2(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x68, 0x1, 0x0, pval)
#define VRX_ret_GAMUT_MDATA_MB2()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x68, 0x1, 0x0)
#define VRX_set_GAMUT_MDATA_MB2(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x68, 0x1, 0x0, val)

#define VRX_is_CS_DATA_VALID_MB1_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x69, 0x80, 0x7)
#define VRX_get_CS_DATA_VALID_MB1(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x69, 0x80, 0x7, pval)
#define VRX_ret_CS_DATA_VALID_MB1()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x69, 0x80, 0x7)
#define VRX_set_CS_DATA_VALID_MB1(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x69, 0x80, 0x7, val)

#define VRX_is_INTERNAL_MUTE_MB1_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x69, 0x40, 0x6)
#define VRX_get_INTERNAL_MUTE_MB1(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x69, 0x40, 0x6, pval)
#define VRX_ret_INTERNAL_MUTE_MB1()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x69, 0x40, 0x6)
#define VRX_set_INTERNAL_MUTE_MB1(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x69, 0x40, 0x6, val)

#define VRX_is_AV_MUTE_MB1_true()                           ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x69, 0x20, 0x5)
#define VRX_get_AV_MUTE_MB1(pval)                           ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x69, 0x20, 0x5, pval)
#define VRX_ret_AV_MUTE_MB1()                               ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x69, 0x20, 0x5)
#define VRX_set_AV_MUTE_MB1(val)                            ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x69, 0x20, 0x5, val)

#define VRX_is_AUDIO_CH_MD_MB1_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x69, 0x10, 0x4)
#define VRX_get_AUDIO_CH_MD_MB1(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x69, 0x10, 0x4, pval)
#define VRX_ret_AUDIO_CH_MD_MB1()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x69, 0x10, 0x4)
#define VRX_set_AUDIO_CH_MD_MB1(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x69, 0x10, 0x4, val)

#define VRX_is_HDMI_MODE_MB1_true()                         ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x69, 0x8, 0x3)
#define VRX_get_HDMI_MODE_MB1(pval)                         ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x69, 0x8, 0x3, pval)
#define VRX_ret_HDMI_MODE_MB1()                             ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x69, 0x8, 0x3)
#define VRX_set_HDMI_MODE_MB1(val)                          ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x69, 0x8, 0x3, val)

#define VRX_is_GEN_CTL_PCKT_MB1_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x69, 0x4, 0x2)
#define VRX_get_GEN_CTL_PCKT_MB1(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x69, 0x4, 0x2, pval)
#define VRX_ret_GEN_CTL_PCKT_MB1()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x69, 0x4, 0x2)
#define VRX_set_GEN_CTL_PCKT_MB1(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x69, 0x4, 0x2, val)

#define VRX_is_AUDIO_C_PCKT_MB1_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x69, 0x2, 0x1)
#define VRX_get_AUDIO_C_PCKT_MB1(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x69, 0x2, 0x1, pval)
#define VRX_ret_AUDIO_C_PCKT_MB1()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x69, 0x2, 0x1)
#define VRX_set_AUDIO_C_PCKT_MB1(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x69, 0x2, 0x1, val)

#define VRX_is_GAMUT_MDATA_MB1_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x69, 0x1, 0x0)
#define VRX_get_GAMUT_MDATA_MB1(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x69, 0x1, 0x0, pval)
#define VRX_ret_GAMUT_MDATA_MB1()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x69, 0x1, 0x0)
#define VRX_set_GAMUT_MDATA_MB1(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x69, 0x1, 0x0, val)

#define VRX_is_TMDSPLL_LCK_A_RAW_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x6A, 0x20, 0x5)
#define VRX_get_TMDSPLL_LCK_A_RAW(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x6A, 0x20, 0x5, pval)
#define VRX_ret_TMDSPLL_LCK_A_RAW()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x6A, 0x20, 0x5)

#define VRX_is_TMDSPLL_LCK_B_RAW_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x6A, 0x10, 0x4)
#define VRX_get_TMDSPLL_LCK_B_RAW(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x6A, 0x10, 0x4, pval)
#define VRX_ret_TMDSPLL_LCK_B_RAW()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x6A, 0x10, 0x4)

#define VRX_is_TMDS_CLK_A_RAW_true()                        ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x6A, 0x2, 0x1)
#define VRX_get_TMDS_CLK_A_RAW(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x6A, 0x2, 0x1, pval)
#define VRX_ret_TMDS_CLK_A_RAW()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x6A, 0x2, 0x1)

#define VRX_is_TMDS_CLK_B_RAW_true()                        ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x6A, 0x1, 0x0)
#define VRX_get_TMDS_CLK_B_RAW(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x6A, 0x1, 0x0, pval)
#define VRX_ret_TMDS_CLK_B_RAW()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x6A, 0x1, 0x0)

#define VRX_is_TMDSPLL_LCK_A_ST_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x6B, 0x20, 0x5)
#define VRX_get_TMDSPLL_LCK_A_ST(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x6B, 0x20, 0x5, pval)
#define VRX_ret_TMDSPLL_LCK_A_ST()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x6B, 0x20, 0x5)

#define VRX_is_TMDSPLL_LCK_B_ST_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x6B, 0x10, 0x4)
#define VRX_get_TMDSPLL_LCK_B_ST(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x6B, 0x10, 0x4, pval)
#define VRX_ret_TMDSPLL_LCK_B_ST()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x6B, 0x10, 0x4)

#define VRX_is_TMDS_CLK_A_ST_true()                         ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x6B, 0x2, 0x1)
#define VRX_get_TMDS_CLK_A_ST(pval)                         ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x6B, 0x2, 0x1, pval)
#define VRX_ret_TMDS_CLK_A_ST()                             ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x6B, 0x2, 0x1)

#define VRX_is_TMDS_CLK_B_ST_true()                         ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x6B, 0x1, 0x0)
#define VRX_get_TMDS_CLK_B_ST(pval)                         ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x6B, 0x1, 0x0, pval)
#define VRX_ret_TMDS_CLK_B_ST()                             ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x6B, 0x1, 0x0)

#define VRX_set_TMDSPLL_LCK_A_CLR(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x6C, 0x20, 0x5, val)

#define VRX_set_TMDSPLL_LCK_B_CLR(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x6C, 0x10, 0x4, val)

#define VRX_set_TMDS_CLK_A_CLR(val)                         ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x6C, 0x2, 0x1, val)

#define VRX_set_TMDS_CLK_B_CLR(val)                         ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x6C, 0x1, 0x0, val)

#define VRX_is_TMDSPLL_LCK_A_MB2_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x6D, 0x20, 0x5)
#define VRX_get_TMDSPLL_LCK_A_MB2(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x6D, 0x20, 0x5, pval)
#define VRX_ret_TMDSPLL_LCK_A_MB2()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x6D, 0x20, 0x5)
#define VRX_set_TMDSPLL_LCK_A_MB2(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x6D, 0x20, 0x5, val)

#define VRX_is_TMDSPLL_LCK_B_MB2_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x6D, 0x10, 0x4)
#define VRX_get_TMDSPLL_LCK_B_MB2(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x6D, 0x10, 0x4, pval)
#define VRX_ret_TMDSPLL_LCK_B_MB2()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x6D, 0x10, 0x4)
#define VRX_set_TMDSPLL_LCK_B_MB2(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x6D, 0x10, 0x4, val)

#define VRX_is_TMDS_CLK_A_MB2_true()                        ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x6D, 0x2, 0x1)
#define VRX_get_TMDS_CLK_A_MB2(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x6D, 0x2, 0x1, pval)
#define VRX_ret_TMDS_CLK_A_MB2()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x6D, 0x2, 0x1)
#define VRX_set_TMDS_CLK_A_MB2(val)                         ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x6D, 0x2, 0x1, val)

#define VRX_is_TMDS_CLK_B_MB2_true()                        ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x6D, 0x1, 0x0)
#define VRX_get_TMDS_CLK_B_MB2(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x6D, 0x1, 0x0, pval)
#define VRX_ret_TMDS_CLK_B_MB2()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x6D, 0x1, 0x0)
#define VRX_set_TMDS_CLK_B_MB2(val)                         ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x6D, 0x1, 0x0, val)

#define VRX_is_TMDSPLL_LCK_A_MB1_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x6E, 0x20, 0x5)
#define VRX_get_TMDSPLL_LCK_A_MB1(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x6E, 0x20, 0x5, pval)
#define VRX_ret_TMDSPLL_LCK_A_MB1()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x6E, 0x20, 0x5)
#define VRX_set_TMDSPLL_LCK_A_MB1(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x6E, 0x20, 0x5, val)

#define VRX_is_TMDSPLL_LCK_B_MB1_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x6E, 0x10, 0x4)
#define VRX_get_TMDSPLL_LCK_B_MB1(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x6E, 0x10, 0x4, pval)
#define VRX_ret_TMDSPLL_LCK_B_MB1()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x6E, 0x10, 0x4)
#define VRX_set_TMDSPLL_LCK_B_MB1(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x6E, 0x10, 0x4, val)

#define VRX_is_TMDS_CLK_A_MB1_true()                        ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x6E, 0x2, 0x1)
#define VRX_get_TMDS_CLK_A_MB1(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x6E, 0x2, 0x1, pval)
#define VRX_ret_TMDS_CLK_A_MB1()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x6E, 0x2, 0x1)
#define VRX_set_TMDS_CLK_A_MB1(val)                         ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x6E, 0x2, 0x1, val)

#define VRX_is_TMDS_CLK_B_MB1_true()                        ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x6E, 0x1, 0x0)
#define VRX_get_TMDS_CLK_B_MB1(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x6E, 0x1, 0x0, pval)
#define VRX_ret_TMDS_CLK_B_MB1()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x6E, 0x1, 0x0)
#define VRX_set_TMDS_CLK_B_MB1(val)                         ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x6E, 0x1, 0x0, val)

#define VRX_is_HDMI_ENCRPT_A_RAW_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x6F, 0x20, 0x5)
#define VRX_get_HDMI_ENCRPT_A_RAW(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x6F, 0x20, 0x5, pval)
#define VRX_ret_HDMI_ENCRPT_A_RAW()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x6F, 0x20, 0x5)

#define VRX_is_HDMI_ENCRPT_B_RAW_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x6F, 0x10, 0x4)
#define VRX_get_HDMI_ENCRPT_B_RAW(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x6F, 0x10, 0x4, pval)
#define VRX_ret_HDMI_ENCRPT_B_RAW()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x6F, 0x10, 0x4)

#define VRX_is_CABLE_DET_A_RAW_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x6F, 0x2, 0x1)
#define VRX_get_CABLE_DET_A_RAW(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x6F, 0x2, 0x1, pval)
#define VRX_ret_CABLE_DET_A_RAW()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x6F, 0x2, 0x1)

#define VRX_is_CABLE_DET_B_RAW_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x6F, 0x1, 0x0)
#define VRX_get_CABLE_DET_B_RAW(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x6F, 0x1, 0x0, pval)
#define VRX_ret_CABLE_DET_B_RAW()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x6F, 0x1, 0x0)

#define VRX_is_HDMI_ENCRPT_A_ST_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x70, 0x20, 0x5)
#define VRX_get_HDMI_ENCRPT_A_ST(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x70, 0x20, 0x5, pval)
#define VRX_ret_HDMI_ENCRPT_A_ST()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x70, 0x20, 0x5)

#define VRX_is_HDMI_ENCRPT_B_ST_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x70, 0x10, 0x4)
#define VRX_get_HDMI_ENCRPT_B_ST(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x70, 0x10, 0x4, pval)
#define VRX_ret_HDMI_ENCRPT_B_ST()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x70, 0x10, 0x4)

#define VRX_is_CABLE_DET_A_ST_true()                        ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x70, 0x2, 0x1)
#define VRX_get_CABLE_DET_A_ST(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x70, 0x2, 0x1, pval)
#define VRX_ret_CABLE_DET_A_ST()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x70, 0x2, 0x1)

#define VRX_is_CABLE_DET_B_ST_true()                        ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x70, 0x1, 0x0)
#define VRX_get_CABLE_DET_B_ST(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x70, 0x1, 0x0, pval)
#define VRX_ret_CABLE_DET_B_ST()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x70, 0x1, 0x0)

#define VRX_set_HDMI_ENCRPT_A_CLR(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x71, 0x20, 0x5, val)

#define VRX_set_HDMI_ENCRPT_B_CLR(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x71, 0x10, 0x4, val)

#define VRX_set_CABLE_DET_A_CLR(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x71, 0x2, 0x1, val)

#define VRX_set_CABLE_DET_B_CLR(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x71, 0x1, 0x0, val)

#define VRX_is_HDMI_ENCRPT_A_MB2_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x72, 0x20, 0x5)
#define VRX_get_HDMI_ENCRPT_A_MB2(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x72, 0x20, 0x5, pval)
#define VRX_ret_HDMI_ENCRPT_A_MB2()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x72, 0x20, 0x5)
#define VRX_set_HDMI_ENCRPT_A_MB2(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x72, 0x20, 0x5, val)

#define VRX_is_HDMI_ENCRPT_B_MB2_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x72, 0x10, 0x4)
#define VRX_get_HDMI_ENCRPT_B_MB2(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x72, 0x10, 0x4, pval)
#define VRX_ret_HDMI_ENCRPT_B_MB2()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x72, 0x10, 0x4)
#define VRX_set_HDMI_ENCRPT_B_MB2(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x72, 0x10, 0x4, val)

#define VRX_is_CABLE_DET_A_MB2_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x72, 0x2, 0x1)
#define VRX_get_CABLE_DET_A_MB2(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x72, 0x2, 0x1, pval)
#define VRX_ret_CABLE_DET_A_MB2()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x72, 0x2, 0x1)
#define VRX_set_CABLE_DET_A_MB2(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x72, 0x2, 0x1, val)

#define VRX_is_CABLE_DET_B_MB2_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x72, 0x1, 0x0)
#define VRX_get_CABLE_DET_B_MB2(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x72, 0x1, 0x0, pval)
#define VRX_ret_CABLE_DET_B_MB2()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x72, 0x1, 0x0)
#define VRX_set_CABLE_DET_B_MB2(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x72, 0x1, 0x0, val)

#define VRX_is_HDMI_ENCRPT_A_MB1_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x73, 0x20, 0x5)
#define VRX_get_HDMI_ENCRPT_A_MB1(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x73, 0x20, 0x5, pval)
#define VRX_ret_HDMI_ENCRPT_A_MB1()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x73, 0x20, 0x5)
#define VRX_set_HDMI_ENCRPT_A_MB1(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x73, 0x20, 0x5, val)

#define VRX_is_HDMI_ENCRPT_B_MB1_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x73, 0x10, 0x4)
#define VRX_get_HDMI_ENCRPT_B_MB1(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x73, 0x10, 0x4, pval)
#define VRX_ret_HDMI_ENCRPT_B_MB1()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x73, 0x10, 0x4)
#define VRX_set_HDMI_ENCRPT_B_MB1(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x73, 0x10, 0x4, val)

#define VRX_is_CABLE_DET_A_MB1_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x73, 0x2, 0x1)
#define VRX_get_CABLE_DET_A_MB1(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x73, 0x2, 0x1, pval)
#define VRX_ret_CABLE_DET_A_MB1()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x73, 0x2, 0x1)
#define VRX_set_CABLE_DET_A_MB1(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x73, 0x2, 0x1, val)

#define VRX_is_CABLE_DET_B_MB1_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x73, 0x1, 0x0)
#define VRX_get_CABLE_DET_B_MB1(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x73, 0x1, 0x0, pval)
#define VRX_ret_CABLE_DET_B_MB1()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x73, 0x1, 0x0)
#define VRX_set_CABLE_DET_B_MB1(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x73, 0x1, 0x0, val)

#define VRX_is_VIDEO_3D_RAW_true()                          ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x74, 0x4, 0x2)
#define VRX_get_VIDEO_3D_RAW(pval)                          ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x74, 0x4, 0x2, pval)
#define VRX_ret_VIDEO_3D_RAW()                              ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x74, 0x4, 0x2)

#define VRX_is_V_LOCKED_RAW_true()                          ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x74, 0x2, 0x1)
#define VRX_get_V_LOCKED_RAW(pval)                          ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x74, 0x2, 0x1, pval)
#define VRX_ret_V_LOCKED_RAW()                              ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x74, 0x2, 0x1)

#define VRX_is_DE_REGEN_LCK_RAW_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x74, 0x1, 0x0)
#define VRX_get_DE_REGEN_LCK_RAW(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x74, 0x1, 0x0, pval)
#define VRX_ret_DE_REGEN_LCK_RAW()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x74, 0x1, 0x0)

#define VRX_is_VIDEO_3D_ST_true()                           ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x75, 0x4, 0x2)
#define VRX_get_VIDEO_3D_ST(pval)                           ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x75, 0x4, 0x2, pval)
#define VRX_ret_VIDEO_3D_ST()                               ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x75, 0x4, 0x2)

#define VRX_is_V_LOCKED_ST_true()                           ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x75, 0x2, 0x1)
#define VRX_get_V_LOCKED_ST(pval)                           ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x75, 0x2, 0x1, pval)
#define VRX_ret_V_LOCKED_ST()                               ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x75, 0x2, 0x1)

#define VRX_is_DE_REGEN_LCK_ST_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x75, 0x1, 0x0)
#define VRX_get_DE_REGEN_LCK_ST(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x75, 0x1, 0x0, pval)
#define VRX_ret_DE_REGEN_LCK_ST()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x75, 0x1, 0x0)

#define VRX_set_VIDEO_3D_CLR(val)                           ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x76, 0x4, 0x2, val)

#define VRX_set_V_LOCKED_CLR(val)                           ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x76, 0x2, 0x1, val)

#define VRX_set_DE_REGEN_LCK_CLR(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x76, 0x1, 0x0, val)

#define VRX_is_VIDEO_3D_MB2_true()                          ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x77, 0x4, 0x2)
#define VRX_get_VIDEO_3D_MB2(pval)                          ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x77, 0x4, 0x2, pval)
#define VRX_ret_VIDEO_3D_MB2()                              ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x77, 0x4, 0x2)
#define VRX_set_VIDEO_3D_MB2(val)                           ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x77, 0x4, 0x2, val)

#define VRX_is_V_LOCKED_MB2_true()                          ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x77, 0x2, 0x1)
#define VRX_get_V_LOCKED_MB2(pval)                          ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x77, 0x2, 0x1, pval)
#define VRX_ret_V_LOCKED_MB2()                              ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x77, 0x2, 0x1)
#define VRX_set_V_LOCKED_MB2(val)                           ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x77, 0x2, 0x1, val)

#define VRX_is_DE_REGEN_LCK_MB2_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x77, 0x1, 0x0)
#define VRX_get_DE_REGEN_LCK_MB2(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x77, 0x1, 0x0, pval)
#define VRX_ret_DE_REGEN_LCK_MB2()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x77, 0x1, 0x0)
#define VRX_set_DE_REGEN_LCK_MB2(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x77, 0x1, 0x0, val)

#define VRX_is_VIDEO_3D_MB1_true()                          ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x78, 0x4, 0x2)
#define VRX_get_VIDEO_3D_MB1(pval)                          ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x78, 0x4, 0x2, pval)
#define VRX_ret_VIDEO_3D_MB1()                              ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x78, 0x4, 0x2)
#define VRX_set_VIDEO_3D_MB1(val)                           ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x78, 0x4, 0x2, val)

#define VRX_is_V_LOCKED_MB1_true()                          ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x78, 0x2, 0x1)
#define VRX_get_V_LOCKED_MB1(pval)                          ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x78, 0x2, 0x1, pval)
#define VRX_ret_V_LOCKED_MB1()                              ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x78, 0x2, 0x1)
#define VRX_set_V_LOCKED_MB1(val)                           ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x78, 0x2, 0x1, val)

#define VRX_is_DE_REGEN_LCK_MB1_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x78, 0x1, 0x0)
#define VRX_get_DE_REGEN_LCK_MB1(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x78, 0x1, 0x0, pval)
#define VRX_ret_DE_REGEN_LCK_MB1()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x78, 0x1, 0x0)
#define VRX_set_DE_REGEN_LCK_MB1(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x78, 0x1, 0x0, val)

#define VRX_is_NEW_ISRC2_PCKT_RAW_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x79, 0x80, 0x7)
#define VRX_get_NEW_ISRC2_PCKT_RAW(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x79, 0x80, 0x7, pval)
#define VRX_ret_NEW_ISRC2_PCKT_RAW()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x79, 0x80, 0x7)

#define VRX_is_NEW_ISRC1_PCKT_RAW_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x79, 0x40, 0x6)
#define VRX_get_NEW_ISRC1_PCKT_RAW(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x79, 0x40, 0x6, pval)
#define VRX_ret_NEW_ISRC1_PCKT_RAW()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x79, 0x40, 0x6)

#define VRX_is_NEW_ACP_PCKT_RAW_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x79, 0x20, 0x5)
#define VRX_get_NEW_ACP_PCKT_RAW(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x79, 0x20, 0x5, pval)
#define VRX_ret_NEW_ACP_PCKT_RAW()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x79, 0x20, 0x5)

#define VRX_is_NEW_VS_INFO_RAW_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x79, 0x10, 0x4)
#define VRX_get_NEW_VS_INFO_RAW(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x79, 0x10, 0x4, pval)
#define VRX_ret_NEW_VS_INFO_RAW()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x79, 0x10, 0x4)

#define VRX_is_NEW_MS_INFO_RAW_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x79, 0x8, 0x3)
#define VRX_get_NEW_MS_INFO_RAW(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x79, 0x8, 0x3, pval)
#define VRX_ret_NEW_MS_INFO_RAW()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x79, 0x8, 0x3)

#define VRX_is_NEW_SPD_INFO_RAW_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x79, 0x4, 0x2)
#define VRX_get_NEW_SPD_INFO_RAW(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x79, 0x4, 0x2, pval)
#define VRX_ret_NEW_SPD_INFO_RAW()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x79, 0x4, 0x2)

#define VRX_is_NEW_AUDIO_INFO_RAW_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x79, 0x2, 0x1)
#define VRX_get_NEW_AUDIO_INFO_RAW(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x79, 0x2, 0x1, pval)
#define VRX_ret_NEW_AUDIO_INFO_RAW()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x79, 0x2, 0x1)

#define VRX_is_NEW_AVI_INFO_RAW_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x79, 0x1, 0x0)
#define VRX_get_NEW_AVI_INFO_RAW(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x79, 0x1, 0x0, pval)
#define VRX_ret_NEW_AVI_INFO_RAW()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x79, 0x1, 0x0)

#define VRX_is_NEW_ISRC2_PCKT_ST_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x7A, 0x80, 0x7)
#define VRX_get_NEW_ISRC2_PCKT_ST(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x7A, 0x80, 0x7, pval)
#define VRX_ret_NEW_ISRC2_PCKT_ST()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x7A, 0x80, 0x7)

#define VRX_is_NEW_ISRC1_PCKT_ST_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x7A, 0x40, 0x6)
#define VRX_get_NEW_ISRC1_PCKT_ST(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x7A, 0x40, 0x6, pval)
#define VRX_ret_NEW_ISRC1_PCKT_ST()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x7A, 0x40, 0x6)

#define VRX_is_NEW_ACP_PCKT_ST_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x7A, 0x20, 0x5)
#define VRX_get_NEW_ACP_PCKT_ST(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x7A, 0x20, 0x5, pval)
#define VRX_ret_NEW_ACP_PCKT_ST()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x7A, 0x20, 0x5)

#define VRX_is_NEW_VS_INFO_ST_true()                        ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x7A, 0x10, 0x4)
#define VRX_get_NEW_VS_INFO_ST(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x7A, 0x10, 0x4, pval)
#define VRX_ret_NEW_VS_INFO_ST()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x7A, 0x10, 0x4)

#define VRX_is_NEW_MS_INFO_ST_true()                        ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x7A, 0x8, 0x3)
#define VRX_get_NEW_MS_INFO_ST(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x7A, 0x8, 0x3, pval)
#define VRX_ret_NEW_MS_INFO_ST()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x7A, 0x8, 0x3)

#define VRX_is_NEW_SPD_INFO_ST_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x7A, 0x4, 0x2)
#define VRX_get_NEW_SPD_INFO_ST(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x7A, 0x4, 0x2, pval)
#define VRX_ret_NEW_SPD_INFO_ST()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x7A, 0x4, 0x2)

#define VRX_is_NEW_AUDIO_INFO_ST_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x7A, 0x2, 0x1)
#define VRX_get_NEW_AUDIO_INFO_ST(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x7A, 0x2, 0x1, pval)
#define VRX_ret_NEW_AUDIO_INFO_ST()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x7A, 0x2, 0x1)

#define VRX_is_NEW_AVI_INFO_ST_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x7A, 0x1, 0x0)
#define VRX_get_NEW_AVI_INFO_ST(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x7A, 0x1, 0x0, pval)
#define VRX_ret_NEW_AVI_INFO_ST()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x7A, 0x1, 0x0)

#define VRX_set_NEW_ISRC2_PCKT_CLR(val)                     ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x7B, 0x80, 0x7, val)

#define VRX_set_NEW_ISRC1_PCKT_CLR(val)                     ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x7B, 0x40, 0x6, val)

#define VRX_set_NEW_ACP_PCKT_CLR(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x7B, 0x20, 0x5, val)

#define VRX_set_NEW_VS_INFO_CLR(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x7B, 0x10, 0x4, val)

#define VRX_set_NEW_MS_INFO_CLR(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x7B, 0x8, 0x3, val)

#define VRX_set_NEW_SPD_INFO_CLR(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x7B, 0x4, 0x2, val)

#define VRX_set_NEW_AUDIO_INFO_CLR(val)                     ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x7B, 0x2, 0x1, val)

#define VRX_set_NEW_AVI_INFO_CLR(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x7B, 0x1, 0x0, val)

#define VRX_is_NEW_ISRC2_PCKT_MB2_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x7C, 0x80, 0x7)
#define VRX_get_NEW_ISRC2_PCKT_MB2(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x7C, 0x80, 0x7, pval)
#define VRX_ret_NEW_ISRC2_PCKT_MB2()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x7C, 0x80, 0x7)
#define VRX_set_NEW_ISRC2_PCKT_MB2(val)                     ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x7C, 0x80, 0x7, val)

#define VRX_is_NEW_ISRC1_PCKT_MB2_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x7C, 0x40, 0x6)
#define VRX_get_NEW_ISRC1_PCKT_MB2(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x7C, 0x40, 0x6, pval)
#define VRX_ret_NEW_ISRC1_PCKT_MB2()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x7C, 0x40, 0x6)
#define VRX_set_NEW_ISRC1_PCKT_MB2(val)                     ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x7C, 0x40, 0x6, val)

#define VRX_is_NEW_ACP_PCKT_MB2_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x7C, 0x20, 0x5)
#define VRX_get_NEW_ACP_PCKT_MB2(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x7C, 0x20, 0x5, pval)
#define VRX_ret_NEW_ACP_PCKT_MB2()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x7C, 0x20, 0x5)
#define VRX_set_NEW_ACP_PCKT_MB2(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x7C, 0x20, 0x5, val)

#define VRX_is_NEW_VS_INFO_MB2_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x7C, 0x10, 0x4)
#define VRX_get_NEW_VS_INFO_MB2(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x7C, 0x10, 0x4, pval)
#define VRX_ret_NEW_VS_INFO_MB2()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x7C, 0x10, 0x4)
#define VRX_set_NEW_VS_INFO_MB2(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x7C, 0x10, 0x4, val)

#define VRX_is_NEW_MS_INFO_MB2_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x7C, 0x8, 0x3)
#define VRX_get_NEW_MS_INFO_MB2(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x7C, 0x8, 0x3, pval)
#define VRX_ret_NEW_MS_INFO_MB2()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x7C, 0x8, 0x3)
#define VRX_set_NEW_MS_INFO_MB2(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x7C, 0x8, 0x3, val)

#define VRX_is_NEW_SPD_INFO_MB2_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x7C, 0x4, 0x2)
#define VRX_get_NEW_SPD_INFO_MB2(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x7C, 0x4, 0x2, pval)
#define VRX_ret_NEW_SPD_INFO_MB2()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x7C, 0x4, 0x2)
#define VRX_set_NEW_SPD_INFO_MB2(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x7C, 0x4, 0x2, val)

#define VRX_is_NEW_AUDIO_INFO_MB2_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x7C, 0x2, 0x1)
#define VRX_get_NEW_AUDIO_INFO_MB2(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x7C, 0x2, 0x1, pval)
#define VRX_ret_NEW_AUDIO_INFO_MB2()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x7C, 0x2, 0x1)
#define VRX_set_NEW_AUDIO_INFO_MB2(val)                     ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x7C, 0x2, 0x1, val)

#define VRX_is_NEW_AVI_INFO_MB2_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x7C, 0x1, 0x0)
#define VRX_get_NEW_AVI_INFO_MB2(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x7C, 0x1, 0x0, pval)
#define VRX_ret_NEW_AVI_INFO_MB2()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x7C, 0x1, 0x0)
#define VRX_set_NEW_AVI_INFO_MB2(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x7C, 0x1, 0x0, val)

#define VRX_is_NEW_ISRC2_PCKT_MB1_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x7D, 0x80, 0x7)
#define VRX_get_NEW_ISRC2_PCKT_MB1(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x7D, 0x80, 0x7, pval)
#define VRX_ret_NEW_ISRC2_PCKT_MB1()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x7D, 0x80, 0x7)
#define VRX_set_NEW_ISRC2_PCKT_MB1(val)                     ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x7D, 0x80, 0x7, val)

#define VRX_is_NEW_ISRC1_PCKT_MB1_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x7D, 0x40, 0x6)
#define VRX_get_NEW_ISRC1_PCKT_MB1(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x7D, 0x40, 0x6, pval)
#define VRX_ret_NEW_ISRC1_PCKT_MB1()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x7D, 0x40, 0x6)
#define VRX_set_NEW_ISRC1_PCKT_MB1(val)                     ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x7D, 0x40, 0x6, val)

#define VRX_is_NEW_ACP_PCKT_MB1_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x7D, 0x20, 0x5)
#define VRX_get_NEW_ACP_PCKT_MB1(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x7D, 0x20, 0x5, pval)
#define VRX_ret_NEW_ACP_PCKT_MB1()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x7D, 0x20, 0x5)
#define VRX_set_NEW_ACP_PCKT_MB1(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x7D, 0x20, 0x5, val)

#define VRX_is_NEW_VS_INFO_MB1_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x7D, 0x10, 0x4)
#define VRX_get_NEW_VS_INFO_MB1(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x7D, 0x10, 0x4, pval)
#define VRX_ret_NEW_VS_INFO_MB1()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x7D, 0x10, 0x4)
#define VRX_set_NEW_VS_INFO_MB1(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x7D, 0x10, 0x4, val)

#define VRX_is_NEW_MS_INFO_MB1_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x7D, 0x8, 0x3)
#define VRX_get_NEW_MS_INFO_MB1(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x7D, 0x8, 0x3, pval)
#define VRX_ret_NEW_MS_INFO_MB1()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x7D, 0x8, 0x3)
#define VRX_set_NEW_MS_INFO_MB1(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x7D, 0x8, 0x3, val)

#define VRX_is_NEW_SPD_INFO_MB1_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x7D, 0x4, 0x2)
#define VRX_get_NEW_SPD_INFO_MB1(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x7D, 0x4, 0x2, pval)
#define VRX_ret_NEW_SPD_INFO_MB1()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x7D, 0x4, 0x2)
#define VRX_set_NEW_SPD_INFO_MB1(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x7D, 0x4, 0x2, val)

#define VRX_is_NEW_AUDIO_INFO_MB1_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x7D, 0x2, 0x1)
#define VRX_get_NEW_AUDIO_INFO_MB1(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x7D, 0x2, 0x1, pval)
#define VRX_ret_NEW_AUDIO_INFO_MB1()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x7D, 0x2, 0x1)
#define VRX_set_NEW_AUDIO_INFO_MB1(val)                     ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x7D, 0x2, 0x1, val)

#define VRX_is_NEW_AVI_INFO_MB1_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x7D, 0x1, 0x0)
#define VRX_get_NEW_AVI_INFO_MB1(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x7D, 0x1, 0x0, pval)
#define VRX_ret_NEW_AVI_INFO_MB1()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x7D, 0x1, 0x0)
#define VRX_set_NEW_AVI_INFO_MB1(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x7D, 0x1, 0x0, val)

#define VRX_is_FIFO_NEAR_OVFL_RAW_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x7E, 0x80, 0x7)
#define VRX_get_FIFO_NEAR_OVFL_RAW(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x7E, 0x80, 0x7, pval)
#define VRX_ret_FIFO_NEAR_OVFL_RAW()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x7E, 0x80, 0x7)

#define VRX_is_FIFO_UNDERFLO_RAW_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x7E, 0x40, 0x6)
#define VRX_get_FIFO_UNDERFLO_RAW(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x7E, 0x40, 0x6, pval)
#define VRX_ret_FIFO_UNDERFLO_RAW()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x7E, 0x40, 0x6)

#define VRX_is_FIFO_OVERFLO_RAW_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x7E, 0x20, 0x5)
#define VRX_get_FIFO_OVERFLO_RAW(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x7E, 0x20, 0x5, pval)
#define VRX_ret_FIFO_OVERFLO_RAW()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x7E, 0x20, 0x5)

#define VRX_is_CTS_PASS_THRSH_RAW_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x7E, 0x10, 0x4)
#define VRX_get_CTS_PASS_THRSH_RAW(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x7E, 0x10, 0x4, pval)
#define VRX_ret_CTS_PASS_THRSH_RAW()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x7E, 0x10, 0x4)

#define VRX_is_CHANGE_N_RAW_true()                          ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x7E, 0x8, 0x3)
#define VRX_get_CHANGE_N_RAW(pval)                          ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x7E, 0x8, 0x3, pval)
#define VRX_ret_CHANGE_N_RAW()                              ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x7E, 0x8, 0x3)

#define VRX_is_PACKET_ERROR_RAW_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x7E, 0x4, 0x2)
#define VRX_get_PACKET_ERROR_RAW(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x7E, 0x4, 0x2, pval)
#define VRX_ret_PACKET_ERROR_RAW()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x7E, 0x4, 0x2)

#define VRX_is_AUDIO_PCKT_ERR_RAW_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x7E, 0x2, 0x1)
#define VRX_get_AUDIO_PCKT_ERR_RAW(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x7E, 0x2, 0x1, pval)
#define VRX_ret_AUDIO_PCKT_ERR_RAW()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x7E, 0x2, 0x1)

#define VRX_is_NEW_GAMUT_MDATA_RAW_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x7E, 0x1, 0x0)
#define VRX_get_NEW_GAMUT_MDATA_RAW(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x7E, 0x1, 0x0, pval)
#define VRX_ret_NEW_GAMUT_MDATA_RAW()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x7E, 0x1, 0x0)

#define VRX_is_FIFO_NEAR_OVFL_ST_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x7F, 0x80, 0x7)
#define VRX_get_FIFO_NEAR_OVFL_ST(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x7F, 0x80, 0x7, pval)
#define VRX_ret_FIFO_NEAR_OVFL_ST()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x7F, 0x80, 0x7)

#define VRX_is_FIFO_UNDERFLO_ST_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x7F, 0x40, 0x6)
#define VRX_get_FIFO_UNDERFLO_ST(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x7F, 0x40, 0x6, pval)
#define VRX_ret_FIFO_UNDERFLO_ST()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x7F, 0x40, 0x6)

#define VRX_is_FIFO_OVERFLO_ST_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x7F, 0x20, 0x5)
#define VRX_get_FIFO_OVERFLO_ST(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x7F, 0x20, 0x5, pval)
#define VRX_ret_FIFO_OVERFLO_ST()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x7F, 0x20, 0x5)

#define VRX_is_CTS_PASS_THRSH_ST_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x7F, 0x10, 0x4)
#define VRX_get_CTS_PASS_THRSH_ST(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x7F, 0x10, 0x4, pval)
#define VRX_ret_CTS_PASS_THRSH_ST()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x7F, 0x10, 0x4)

#define VRX_is_CHANGE_N_ST_true()                           ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x7F, 0x8, 0x3)
#define VRX_get_CHANGE_N_ST(pval)                           ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x7F, 0x8, 0x3, pval)
#define VRX_ret_CHANGE_N_ST()                               ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x7F, 0x8, 0x3)

#define VRX_is_PACKET_ERROR_ST_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x7F, 0x4, 0x2)
#define VRX_get_PACKET_ERROR_ST(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x7F, 0x4, 0x2, pval)
#define VRX_ret_PACKET_ERROR_ST()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x7F, 0x4, 0x2)

#define VRX_is_AUDIO_PCKT_ERR_ST_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x7F, 0x2, 0x1)
#define VRX_get_AUDIO_PCKT_ERR_ST(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x7F, 0x2, 0x1, pval)
#define VRX_ret_AUDIO_PCKT_ERR_ST()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x7F, 0x2, 0x1)

#define VRX_is_NEW_GAMUT_MDATA_ST_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x7F, 0x1, 0x0)
#define VRX_get_NEW_GAMUT_MDATA_ST(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x7F, 0x1, 0x0, pval)
#define VRX_ret_NEW_GAMUT_MDATA_ST()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x7F, 0x1, 0x0)

#define VRX_set_FIFO_NEAR_OVFL_CLR(val)                     ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x80, 0x80, 0x7, val)

#define VRX_set_FIFO_UNDERFLO_CLR(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x80, 0x40, 0x6, val)

#define VRX_set_FIFO_OVERFLO_CLR(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x80, 0x20, 0x5, val)

#define VRX_set_CTS_PASS_THRSH_CLR(val)                     ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x80, 0x10, 0x4, val)

#define VRX_set_CHANGE_N_CLR(val)                           ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x80, 0x8, 0x3, val)

#define VRX_set_PACKET_ERROR_CLR(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x80, 0x4, 0x2, val)

#define VRX_set_AUDIO_PCKT_ERR_CLR(val)                     ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x80, 0x2, 0x1, val)

#define VRX_set_NEW_GAMUT_MDATA_CLR(val)                    ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x80, 0x1, 0x0, val)

#define VRX_is_FIFO_NEAR_OVFL_MB2_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x81, 0x80, 0x7)
#define VRX_get_FIFO_NEAR_OVFL_MB2(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x81, 0x80, 0x7, pval)
#define VRX_ret_FIFO_NEAR_OVFL_MB2()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x81, 0x80, 0x7)
#define VRX_set_FIFO_NEAR_OVFL_MB2(val)                     ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x81, 0x80, 0x7, val)

#define VRX_is_FIFO_UNDERFLO_MB2_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x81, 0x40, 0x6)
#define VRX_get_FIFO_UNDERFLO_MB2(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x81, 0x40, 0x6, pval)
#define VRX_ret_FIFO_UNDERFLO_MB2()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x81, 0x40, 0x6)
#define VRX_set_FIFO_UNDERFLO_MB2(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x81, 0x40, 0x6, val)

#define VRX_is_FIFO_OVERFLO_MB2_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x81, 0x20, 0x5)
#define VRX_get_FIFO_OVERFLO_MB2(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x81, 0x20, 0x5, pval)
#define VRX_ret_FIFO_OVERFLO_MB2()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x81, 0x20, 0x5)
#define VRX_set_FIFO_OVERFLO_MB2(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x81, 0x20, 0x5, val)

#define VRX_is_CTS_PASS_THRSH_MB2_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x81, 0x10, 0x4)
#define VRX_get_CTS_PASS_THRSH_MB2(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x81, 0x10, 0x4, pval)
#define VRX_ret_CTS_PASS_THRSH_MB2()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x81, 0x10, 0x4)
#define VRX_set_CTS_PASS_THRSH_MB2(val)                     ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x81, 0x10, 0x4, val)

#define VRX_is_CHANGE_N_MB2_true()                          ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x81, 0x8, 0x3)
#define VRX_get_CHANGE_N_MB2(pval)                          ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x81, 0x8, 0x3, pval)
#define VRX_ret_CHANGE_N_MB2()                              ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x81, 0x8, 0x3)
#define VRX_set_CHANGE_N_MB2(val)                           ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x81, 0x8, 0x3, val)

#define VRX_is_PACKET_ERROR_MB2_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x81, 0x4, 0x2)
#define VRX_get_PACKET_ERROR_MB2(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x81, 0x4, 0x2, pval)
#define VRX_ret_PACKET_ERROR_MB2()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x81, 0x4, 0x2)
#define VRX_set_PACKET_ERROR_MB2(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x81, 0x4, 0x2, val)

#define VRX_is_AUDIO_PCKT_ERR_MB2_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x81, 0x2, 0x1)
#define VRX_get_AUDIO_PCKT_ERR_MB2(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x81, 0x2, 0x1, pval)
#define VRX_ret_AUDIO_PCKT_ERR_MB2()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x81, 0x2, 0x1)
#define VRX_set_AUDIO_PCKT_ERR_MB2(val)                     ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x81, 0x2, 0x1, val)

#define VRX_is_NEW_GAMUT_MDATA_MB2_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x81, 0x1, 0x0)
#define VRX_get_NEW_GAMUT_MDATA_MB2(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x81, 0x1, 0x0, pval)
#define VRX_ret_NEW_GAMUT_MDATA_MB2()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x81, 0x1, 0x0)
#define VRX_set_NEW_GAMUT_MDATA_MB2(val)                    ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x81, 0x1, 0x0, val)

#define VRX_is_FIFO_NEAR_OVFL_MB1_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x82, 0x80, 0x7)
#define VRX_get_FIFO_NEAR_OVFL_MB1(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x82, 0x80, 0x7, pval)
#define VRX_ret_FIFO_NEAR_OVFL_MB1()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x82, 0x80, 0x7)
#define VRX_set_FIFO_NEAR_OVFL_MB1(val)                     ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x82, 0x80, 0x7, val)

#define VRX_is_FIFO_UNDERFLO_MB1_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x82, 0x40, 0x6)
#define VRX_get_FIFO_UNDERFLO_MB1(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x82, 0x40, 0x6, pval)
#define VRX_ret_FIFO_UNDERFLO_MB1()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x82, 0x40, 0x6)
#define VRX_set_FIFO_UNDERFLO_MB1(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x82, 0x40, 0x6, val)

#define VRX_is_FIFO_OVERFLO_MB1_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x82, 0x20, 0x5)
#define VRX_get_FIFO_OVERFLO_MB1(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x82, 0x20, 0x5, pval)
#define VRX_ret_FIFO_OVERFLO_MB1()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x82, 0x20, 0x5)
#define VRX_set_FIFO_OVERFLO_MB1(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x82, 0x20, 0x5, val)

#define VRX_is_CTS_PASS_THRSH_MB1_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x82, 0x10, 0x4)
#define VRX_get_CTS_PASS_THRSH_MB1(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x82, 0x10, 0x4, pval)
#define VRX_ret_CTS_PASS_THRSH_MB1()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x82, 0x10, 0x4)
#define VRX_set_CTS_PASS_THRSH_MB1(val)                     ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x82, 0x10, 0x4, val)

#define VRX_is_CHANGE_N_MB1_true()                          ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x82, 0x8, 0x3)
#define VRX_get_CHANGE_N_MB1(pval)                          ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x82, 0x8, 0x3, pval)
#define VRX_ret_CHANGE_N_MB1()                              ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x82, 0x8, 0x3)
#define VRX_set_CHANGE_N_MB1(val)                           ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x82, 0x8, 0x3, val)

#define VRX_is_PACKET_ERROR_MB1_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x82, 0x4, 0x2)
#define VRX_get_PACKET_ERROR_MB1(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x82, 0x4, 0x2, pval)
#define VRX_ret_PACKET_ERROR_MB1()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x82, 0x4, 0x2)
#define VRX_set_PACKET_ERROR_MB1(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x82, 0x4, 0x2, val)

#define VRX_is_AUDIO_PCKT_ERR_MB1_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x82, 0x2, 0x1)
#define VRX_get_AUDIO_PCKT_ERR_MB1(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x82, 0x2, 0x1, pval)
#define VRX_ret_AUDIO_PCKT_ERR_MB1()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x82, 0x2, 0x1)
#define VRX_set_AUDIO_PCKT_ERR_MB1(val)                     ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x82, 0x2, 0x1, val)

#define VRX_is_NEW_GAMUT_MDATA_MB1_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x82, 0x1, 0x0)
#define VRX_get_NEW_GAMUT_MDATA_MB1(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x82, 0x1, 0x0, pval)
#define VRX_ret_NEW_GAMUT_MDATA_MB1()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x82, 0x1, 0x0)
#define VRX_set_NEW_GAMUT_MDATA_MB1(val)                    ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x82, 0x1, 0x0, val)

#define VRX_is_DEEP_COLOR_CHNG_RAW_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x83, 0x80, 0x7)
#define VRX_get_DEEP_COLOR_CHNG_RAW(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x83, 0x80, 0x7, pval)
#define VRX_ret_DEEP_COLOR_CHNG_RAW()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x83, 0x80, 0x7)

#define VRX_is_VCLK_CHNG_RAW_true()                         ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x83, 0x40, 0x6)
#define VRX_get_VCLK_CHNG_RAW(pval)                         ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x83, 0x40, 0x6, pval)
#define VRX_ret_VCLK_CHNG_RAW()                             ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x83, 0x40, 0x6)

#define VRX_is_AUDIO_MODE_CHANGE_RAW_true()                 ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x83, 0x20, 0x5)
#define VRX_get_AUDIO_MODE_CHANGE_RAW(pval)                 ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x83, 0x20, 0x5, pval)
#define VRX_ret_AUDIO_MODE_CHANGE_RAW()                     ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x83, 0x20, 0x5)

#define VRX_is_PARITY_ERROR_RAW_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x83, 0x10, 0x4)
#define VRX_get_PARITY_ERROR_RAW(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x83, 0x10, 0x4, pval)
#define VRX_ret_PARITY_ERROR_RAW()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x83, 0x10, 0x4)

#define VRX_is_NEW_SAMP_RT_RAW_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x83, 0x8, 0x3)
#define VRX_get_NEW_SAMP_RT_RAW(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x83, 0x8, 0x3, pval)
#define VRX_ret_NEW_SAMP_RT_RAW()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x83, 0x8, 0x3)

#define VRX_is_AUDIO_FLT_LINE_RAW_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x83, 0x4, 0x2)
#define VRX_get_AUDIO_FLT_LINE_RAW(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x83, 0x4, 0x2, pval)
#define VRX_ret_AUDIO_FLT_LINE_RAW()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x83, 0x4, 0x2)

#define VRX_is_NEW_TMDS_FRQ_RAW_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x83, 0x2, 0x1)
#define VRX_get_NEW_TMDS_FRQ_RAW(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x83, 0x2, 0x1, pval)
#define VRX_ret_NEW_TMDS_FRQ_RAW()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x83, 0x2, 0x1)

#define VRX_is_FIFO_NEAR_UFLO_RAW_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x83, 0x1, 0x0)
#define VRX_get_FIFO_NEAR_UFLO_RAW(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x83, 0x1, 0x0, pval)
#define VRX_ret_FIFO_NEAR_UFLO_RAW()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x83, 0x1, 0x0)

#define VRX_is_DEEP_COLOR_CHNG_ST_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x84, 0x80, 0x7)
#define VRX_get_DEEP_COLOR_CHNG_ST(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x84, 0x80, 0x7, pval)
#define VRX_ret_DEEP_COLOR_CHNG_ST()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x84, 0x80, 0x7)

#define VRX_is_VCLK_CHNG_ST_true()                          ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x84, 0x40, 0x6)
#define VRX_get_VCLK_CHNG_ST(pval)                          ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x84, 0x40, 0x6, pval)
#define VRX_ret_VCLK_CHNG_ST()                              ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x84, 0x40, 0x6)

#define VRX_is_AUDIO_MODE_CHANGE_ST_true()                  ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x84, 0x20, 0x5)
#define VRX_get_AUDIO_MODE_CHANGE_ST(pval)                  ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x84, 0x20, 0x5, pval)
#define VRX_ret_AUDIO_MODE_CHANGE_ST()                      ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x84, 0x20, 0x5)

#define VRX_is_PARITY_ERROR_ST_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x84, 0x10, 0x4)
#define VRX_get_PARITY_ERROR_ST(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x84, 0x10, 0x4, pval)
#define VRX_ret_PARITY_ERROR_ST()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x84, 0x10, 0x4)

#define VRX_is_NEW_SAMP_RT_ST_true()                        ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x84, 0x8, 0x3)
#define VRX_get_NEW_SAMP_RT_ST(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x84, 0x8, 0x3, pval)
#define VRX_ret_NEW_SAMP_RT_ST()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x84, 0x8, 0x3)

#define VRX_is_AUDIO_FLT_LINE_ST_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x84, 0x4, 0x2)
#define VRX_get_AUDIO_FLT_LINE_ST(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x84, 0x4, 0x2, pval)
#define VRX_ret_AUDIO_FLT_LINE_ST()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x84, 0x4, 0x2)

#define VRX_is_NEW_TMDS_FRQ_ST_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x84, 0x2, 0x1)
#define VRX_get_NEW_TMDS_FRQ_ST(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x84, 0x2, 0x1, pval)
#define VRX_ret_NEW_TMDS_FRQ_ST()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x84, 0x2, 0x1)

#define VRX_is_FIFO_NEAR_UFLO_ST_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x84, 0x1, 0x0)
#define VRX_get_FIFO_NEAR_UFLO_ST(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x84, 0x1, 0x0, pval)
#define VRX_ret_FIFO_NEAR_UFLO_ST()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x84, 0x1, 0x0)

#define VRX_set_DEEP_COLOR_CHNG_CLR(val)                    ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x85, 0x80, 0x7, val)

#define VRX_set_VCLK_CHNG_CLR(val)                          ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x85, 0x40, 0x6, val)

#define VRX_set_AUDIO_MODE_CHANGE_CLR(val)                  ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x85, 0x20, 0x5, val)

#define VRX_set_PARITY_ERROR_CLR(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x85, 0x10, 0x4, val)

#define VRX_set_NEW_SAMP_RT_CLR(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x85, 0x8, 0x3, val)

#define VRX_set_AUDIO_FLT_LINE_CLR(val)                     ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x85, 0x4, 0x2, val)

#define VRX_set_NEW_TMDS_FRQ_CLR(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x85, 0x2, 0x1, val)

#define VRX_set_FIFO_NEAR_UFLO_CLR(val)                     ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x85, 0x1, 0x0, val)

#define VRX_is_DEEP_COLOR_CHNG_MB2_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x86, 0x80, 0x7)
#define VRX_get_DEEP_COLOR_CHNG_MB2(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x86, 0x80, 0x7, pval)
#define VRX_ret_DEEP_COLOR_CHNG_MB2()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x86, 0x80, 0x7)
#define VRX_set_DEEP_COLOR_CHNG_MB2(val)                    ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x86, 0x80, 0x7, val)

#define VRX_is_VCLK_CHNG_MB2_true()                         ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x86, 0x40, 0x6)
#define VRX_get_VCLK_CHNG_MB2(pval)                         ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x86, 0x40, 0x6, pval)
#define VRX_ret_VCLK_CHNG_MB2()                             ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x86, 0x40, 0x6)
#define VRX_set_VCLK_CHNG_MB2(val)                          ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x86, 0x40, 0x6, val)

#define VRX_is_AUDIO_MODE_CHANGE_MB2_true()                 ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x86, 0x20, 0x5)
#define VRX_get_AUDIO_MODE_CHANGE_MB2(pval)                 ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x86, 0x20, 0x5, pval)
#define VRX_ret_AUDIO_MODE_CHANGE_MB2()                     ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x86, 0x20, 0x5)
#define VRX_set_AUDIO_MODE_CHANGE_MB2(val)                  ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x86, 0x20, 0x5, val)

#define VRX_is_PARITY_ERROR_MB2_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x86, 0x10, 0x4)
#define VRX_get_PARITY_ERROR_MB2(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x86, 0x10, 0x4, pval)
#define VRX_ret_PARITY_ERROR_MB2()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x86, 0x10, 0x4)
#define VRX_set_PARITY_ERROR_MB2(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x86, 0x10, 0x4, val)

#define VRX_is_NEW_SAMP_RT_MB2_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x86, 0x8, 0x3)
#define VRX_get_NEW_SAMP_RT_MB2(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x86, 0x8, 0x3, pval)
#define VRX_ret_NEW_SAMP_RT_MB2()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x86, 0x8, 0x3)
#define VRX_set_NEW_SAMP_RT_MB2(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x86, 0x8, 0x3, val)

#define VRX_is_AUDIO_FLT_LINE_MB2_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x86, 0x4, 0x2)
#define VRX_get_AUDIO_FLT_LINE_MB2(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x86, 0x4, 0x2, pval)
#define VRX_ret_AUDIO_FLT_LINE_MB2()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x86, 0x4, 0x2)
#define VRX_set_AUDIO_FLT_LINE_MB2(val)                     ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x86, 0x4, 0x2, val)

#define VRX_is_NEW_TMDS_FRQ_MB2_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x86, 0x2, 0x1)
#define VRX_get_NEW_TMDS_FRQ_MB2(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x86, 0x2, 0x1, pval)
#define VRX_ret_NEW_TMDS_FRQ_MB2()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x86, 0x2, 0x1)
#define VRX_set_NEW_TMDS_FRQ_MB2(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x86, 0x2, 0x1, val)

#define VRX_is_FIFO_NEAR_UFLO_MB2_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x86, 0x1, 0x0)
#define VRX_get_FIFO_NEAR_UFLO_MB2(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x86, 0x1, 0x0, pval)
#define VRX_ret_FIFO_NEAR_UFLO_MB2()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x86, 0x1, 0x0)
#define VRX_set_FIFO_NEAR_UFLO_MB2(val)                     ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x86, 0x1, 0x0, val)

#define VRX_is_DEEP_COLOR_CHNG_MB1_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x87, 0x80, 0x7)
#define VRX_get_DEEP_COLOR_CHNG_MB1(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x87, 0x80, 0x7, pval)
#define VRX_ret_DEEP_COLOR_CHNG_MB1()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x87, 0x80, 0x7)
#define VRX_set_DEEP_COLOR_CHNG_MB1(val)                    ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x87, 0x80, 0x7, val)

#define VRX_is_VCLK_CHNG_MB1_true()                         ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x87, 0x40, 0x6)
#define VRX_get_VCLK_CHNG_MB1(pval)                         ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x87, 0x40, 0x6, pval)
#define VRX_ret_VCLK_CHNG_MB1()                             ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x87, 0x40, 0x6)
#define VRX_set_VCLK_CHNG_MB1(val)                          ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x87, 0x40, 0x6, val)

#define VRX_is_AUDIO_MODE_CHANGE_MB1_true()                 ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x87, 0x20, 0x5)
#define VRX_get_AUDIO_MODE_CHANGE_MB1(pval)                 ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x87, 0x20, 0x5, pval)
#define VRX_ret_AUDIO_MODE_CHANGE_MB1()                     ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x87, 0x20, 0x5)
#define VRX_set_AUDIO_MODE_CHANGE_MB1(val)                  ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x87, 0x20, 0x5, val)

#define VRX_is_PARITY_ERROR_MB1_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x87, 0x10, 0x4)
#define VRX_get_PARITY_ERROR_MB1(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x87, 0x10, 0x4, pval)
#define VRX_ret_PARITY_ERROR_MB1()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x87, 0x10, 0x4)
#define VRX_set_PARITY_ERROR_MB1(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x87, 0x10, 0x4, val)

#define VRX_is_NEW_SAMP_RT_MB1_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x87, 0x8, 0x3)
#define VRX_get_NEW_SAMP_RT_MB1(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x87, 0x8, 0x3, pval)
#define VRX_ret_NEW_SAMP_RT_MB1()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x87, 0x8, 0x3)
#define VRX_set_NEW_SAMP_RT_MB1(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x87, 0x8, 0x3, val)

#define VRX_is_AUDIO_FLT_LINE_MB1_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x87, 0x4, 0x2)
#define VRX_get_AUDIO_FLT_LINE_MB1(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x87, 0x4, 0x2, pval)
#define VRX_ret_AUDIO_FLT_LINE_MB1()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x87, 0x4, 0x2)
#define VRX_set_AUDIO_FLT_LINE_MB1(val)                     ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x87, 0x4, 0x2, val)

#define VRX_is_NEW_TMDS_FRQ_MB1_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x87, 0x2, 0x1)
#define VRX_get_NEW_TMDS_FRQ_MB1(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x87, 0x2, 0x1, pval)
#define VRX_ret_NEW_TMDS_FRQ_MB1()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x87, 0x2, 0x1)
#define VRX_set_NEW_TMDS_FRQ_MB1(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x87, 0x2, 0x1, val)

#define VRX_is_FIFO_NEAR_UFLO_MB1_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x87, 0x1, 0x0)
#define VRX_get_FIFO_NEAR_UFLO_MB1(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x87, 0x1, 0x0, pval)
#define VRX_ret_FIFO_NEAR_UFLO_MB1()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x87, 0x1, 0x0)
#define VRX_set_FIFO_NEAR_UFLO_MB1(val)                     ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x87, 0x1, 0x0, val)

#define VRX_is_MS_INF_CKS_ERR_RAW_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x88, 0x80, 0x7)
#define VRX_get_MS_INF_CKS_ERR_RAW(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x88, 0x80, 0x7, pval)
#define VRX_ret_MS_INF_CKS_ERR_RAW()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x88, 0x80, 0x7)

#define VRX_is_SPD_INF_CKS_ERR_RAW_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x88, 0x40, 0x6)
#define VRX_get_SPD_INF_CKS_ERR_RAW(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x88, 0x40, 0x6, pval)
#define VRX_ret_SPD_INF_CKS_ERR_RAW()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x88, 0x40, 0x6)

#define VRX_is_AUD_INF_CKS_ERR_RAW_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x88, 0x20, 0x5)
#define VRX_get_AUD_INF_CKS_ERR_RAW(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x88, 0x20, 0x5, pval)
#define VRX_ret_AUD_INF_CKS_ERR_RAW()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x88, 0x20, 0x5)

#define VRX_is_AVI_INF_CKS_ERR_RAW_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x88, 0x10, 0x4)
#define VRX_get_AVI_INF_CKS_ERR_RAW(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x88, 0x10, 0x4, pval)
#define VRX_ret_AVI_INF_CKS_ERR_RAW()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x88, 0x10, 0x4)

#define VRX_is_AKSV_UPDATE_A_RAW_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x88, 0x2, 0x1)
#define VRX_get_AKSV_UPDATE_A_RAW(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x88, 0x2, 0x1, pval)
#define VRX_ret_AKSV_UPDATE_A_RAW()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x88, 0x2, 0x1)

#define VRX_is_AKSV_UPDATE_B_RAW_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x88, 0x1, 0x0)
#define VRX_get_AKSV_UPDATE_B_RAW(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x88, 0x1, 0x0, pval)
#define VRX_ret_AKSV_UPDATE_B_RAW()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x88, 0x1, 0x0)

#define VRX_is_MS_INF_CKS_ERR_ST_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x89, 0x80, 0x7)
#define VRX_get_MS_INF_CKS_ERR_ST(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x89, 0x80, 0x7, pval)
#define VRX_ret_MS_INF_CKS_ERR_ST()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x89, 0x80, 0x7)

#define VRX_is_SPD_INF_CKS_ERR_ST_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x89, 0x40, 0x6)
#define VRX_get_SPD_INF_CKS_ERR_ST(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x89, 0x40, 0x6, pval)
#define VRX_ret_SPD_INF_CKS_ERR_ST()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x89, 0x40, 0x6)

#define VRX_is_AUD_INF_CKS_ERR_ST_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x89, 0x20, 0x5)
#define VRX_get_AUD_INF_CKS_ERR_ST(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x89, 0x20, 0x5, pval)
#define VRX_ret_AUD_INF_CKS_ERR_ST()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x89, 0x20, 0x5)

#define VRX_is_AVI_INF_CKS_ERR_ST_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x89, 0x10, 0x4)
#define VRX_get_AVI_INF_CKS_ERR_ST(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x89, 0x10, 0x4, pval)
#define VRX_ret_AVI_INF_CKS_ERR_ST()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x89, 0x10, 0x4)

#define VRX_is_AKSV_UPDATE_A_ST_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x89, 0x2, 0x1)
#define VRX_get_AKSV_UPDATE_A_ST(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x89, 0x2, 0x1, pval)
#define VRX_ret_AKSV_UPDATE_A_ST()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x89, 0x2, 0x1)

#define VRX_is_AKSV_UPDATE_B_ST_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x89, 0x1, 0x0)
#define VRX_get_AKSV_UPDATE_B_ST(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x89, 0x1, 0x0, pval)
#define VRX_ret_AKSV_UPDATE_B_ST()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x89, 0x1, 0x0)

#define VRX_set_MS_INF_CKS_ERR_CLR(val)                     ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x8A, 0x80, 0x7, val)

#define VRX_set_SPD_INF_CKS_ERR_CLR(val)                    ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x8A, 0x40, 0x6, val)

#define VRX_set_AUD_INF_CKS_ERR_CLR(val)                    ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x8A, 0x20, 0x5, val)

#define VRX_set_AVI_INF_CKS_ERR_CLR(val)                    ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x8A, 0x10, 0x4, val)

#define VRX_set_AKSV_UPDATE_A_CLR(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x8A, 0x2, 0x1, val)

#define VRX_set_AKSV_UPDATE_B_CLR(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x8A, 0x1, 0x0, val)

#define VRX_is_MS_INF_CKS_ERR_MB2_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x8B, 0x80, 0x7)
#define VRX_get_MS_INF_CKS_ERR_MB2(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x8B, 0x80, 0x7, pval)
#define VRX_ret_MS_INF_CKS_ERR_MB2()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x8B, 0x80, 0x7)
#define VRX_set_MS_INF_CKS_ERR_MB2(val)                     ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x8B, 0x80, 0x7, val)

#define VRX_is_SPD_INF_CKS_ERR_MB2_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x8B, 0x40, 0x6)
#define VRX_get_SPD_INF_CKS_ERR_MB2(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x8B, 0x40, 0x6, pval)
#define VRX_ret_SPD_INF_CKS_ERR_MB2()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x8B, 0x40, 0x6)
#define VRX_set_SPD_INF_CKS_ERR_MB2(val)                    ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x8B, 0x40, 0x6, val)

#define VRX_is_AUD_INF_CKS_ERR_MB2_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x8B, 0x20, 0x5)
#define VRX_get_AUD_INF_CKS_ERR_MB2(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x8B, 0x20, 0x5, pval)
#define VRX_ret_AUD_INF_CKS_ERR_MB2()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x8B, 0x20, 0x5)
#define VRX_set_AUD_INF_CKS_ERR_MB2(val)                    ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x8B, 0x20, 0x5, val)

#define VRX_is_AVI_INF_CKS_ERR_MB2_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x8B, 0x10, 0x4)
#define VRX_get_AVI_INF_CKS_ERR_MB2(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x8B, 0x10, 0x4, pval)
#define VRX_ret_AVI_INF_CKS_ERR_MB2()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x8B, 0x10, 0x4)
#define VRX_set_AVI_INF_CKS_ERR_MB2(val)                    ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x8B, 0x10, 0x4, val)

#define VRX_is_AKSV_UPDATE_A_MB2_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x8B, 0x2, 0x1)
#define VRX_get_AKSV_UPDATE_A_MB2(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x8B, 0x2, 0x1, pval)
#define VRX_ret_AKSV_UPDATE_A_MB2()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x8B, 0x2, 0x1)
#define VRX_set_AKSV_UPDATE_A_MB2(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x8B, 0x2, 0x1, val)

#define VRX_is_AKSV_UPDATE_B_MB2_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x8B, 0x1, 0x0)
#define VRX_get_AKSV_UPDATE_B_MB2(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x8B, 0x1, 0x0, pval)
#define VRX_ret_AKSV_UPDATE_B_MB2()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x8B, 0x1, 0x0)
#define VRX_set_AKSV_UPDATE_B_MB2(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x8B, 0x1, 0x0, val)

#define VRX_is_MS_INF_CKS_ERR_MB1_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x8C, 0x80, 0x7)
#define VRX_get_MS_INF_CKS_ERR_MB1(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x8C, 0x80, 0x7, pval)
#define VRX_ret_MS_INF_CKS_ERR_MB1()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x8C, 0x80, 0x7)
#define VRX_set_MS_INF_CKS_ERR_MB1(val)                     ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x8C, 0x80, 0x7, val)

#define VRX_is_SPD_INF_CKS_ERR_MB1_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x8C, 0x40, 0x6)
#define VRX_get_SPD_INF_CKS_ERR_MB1(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x8C, 0x40, 0x6, pval)
#define VRX_ret_SPD_INF_CKS_ERR_MB1()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x8C, 0x40, 0x6)
#define VRX_set_SPD_INF_CKS_ERR_MB1(val)                    ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x8C, 0x40, 0x6, val)

#define VRX_is_AUD_INF_CKS_ERR_MB1_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x8C, 0x20, 0x5)
#define VRX_get_AUD_INF_CKS_ERR_MB1(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x8C, 0x20, 0x5, pval)
#define VRX_ret_AUD_INF_CKS_ERR_MB1()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x8C, 0x20, 0x5)
#define VRX_set_AUD_INF_CKS_ERR_MB1(val)                    ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x8C, 0x20, 0x5, val)

#define VRX_is_AVI_INF_CKS_ERR_MB1_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x8C, 0x10, 0x4)
#define VRX_get_AVI_INF_CKS_ERR_MB1(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x8C, 0x10, 0x4, pval)
#define VRX_ret_AVI_INF_CKS_ERR_MB1()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x8C, 0x10, 0x4)
#define VRX_set_AVI_INF_CKS_ERR_MB1(val)                    ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x8C, 0x10, 0x4, val)

#define VRX_is_AKSV_UPDATE_A_MB1_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x8C, 0x2, 0x1)
#define VRX_get_AKSV_UPDATE_A_MB1(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x8C, 0x2, 0x1, pval)
#define VRX_ret_AKSV_UPDATE_A_MB1()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x8C, 0x2, 0x1)
#define VRX_set_AKSV_UPDATE_A_MB1(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x8C, 0x2, 0x1, val)

#define VRX_is_AKSV_UPDATE_B_MB1_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x8C, 0x1, 0x0)
#define VRX_get_AKSV_UPDATE_B_MB1(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x8C, 0x1, 0x0, pval)
#define VRX_ret_AKSV_UPDATE_B_MB1()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x8C, 0x1, 0x0)
#define VRX_set_AKSV_UPDATE_B_MB1(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x8C, 0x1, 0x0, val)

#define VRX_is_BG_MEAS_DONE_RAW_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x8D, 0x2, 0x1)
#define VRX_get_BG_MEAS_DONE_RAW(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x8D, 0x2, 0x1, pval)
#define VRX_ret_BG_MEAS_DONE_RAW()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x8D, 0x2, 0x1)

#define VRX_is_VS_INF_CKS_ERR_RAW_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x8D, 0x1, 0x0)
#define VRX_get_VS_INF_CKS_ERR_RAW(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x8D, 0x1, 0x0, pval)
#define VRX_ret_VS_INF_CKS_ERR_RAW()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x8D, 0x1, 0x0)

#define VRX_is_BG_MEAS_DONE_ST_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x8E, 0x2, 0x1)
#define VRX_get_BG_MEAS_DONE_ST(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x8E, 0x2, 0x1, pval)
#define VRX_ret_BG_MEAS_DONE_ST()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x8E, 0x2, 0x1)

#define VRX_is_VS_INF_CKS_ERR_ST_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x8E, 0x1, 0x0)
#define VRX_get_VS_INF_CKS_ERR_ST(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x8E, 0x1, 0x0, pval)
#define VRX_ret_VS_INF_CKS_ERR_ST()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x8E, 0x1, 0x0)

#define VRX_set_BG_MEAS_DONE_CLR(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x8F, 0x2, 0x1, val)

#define VRX_set_VS_INF_CKS_ERR_CLR(val)                     ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x8F, 0x1, 0x0, val)

#define VRX_is_BG_MEAS_DONE_MB2_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x90, 0x2, 0x1)
#define VRX_get_BG_MEAS_DONE_MB2(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x90, 0x2, 0x1, pval)
#define VRX_ret_BG_MEAS_DONE_MB2()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x90, 0x2, 0x1)
#define VRX_set_BG_MEAS_DONE_MB2(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x90, 0x2, 0x1, val)

#define VRX_is_VS_INF_CKS_ERR_MB2_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x90, 0x1, 0x0)
#define VRX_get_VS_INF_CKS_ERR_MB2(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x90, 0x1, 0x0, pval)
#define VRX_ret_VS_INF_CKS_ERR_MB2()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x90, 0x1, 0x0)
#define VRX_set_VS_INF_CKS_ERR_MB2(val)                     ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x90, 0x1, 0x0, val)

#define VRX_is_BG_MEAS_DONE_MB1_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x91, 0x2, 0x1)
#define VRX_get_BG_MEAS_DONE_MB1(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x91, 0x2, 0x1, pval)
#define VRX_ret_BG_MEAS_DONE_MB1()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x91, 0x2, 0x1)
#define VRX_set_BG_MEAS_DONE_MB1(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x91, 0x2, 0x1, val)

#define VRX_is_VS_INF_CKS_ERR_MB1_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x91, 0x1, 0x0)
#define VRX_get_VS_INF_CKS_ERR_MB1(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x91, 0x1, 0x0, pval)
#define VRX_ret_VS_INF_CKS_ERR_MB1()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x91, 0x1, 0x0)
#define VRX_set_VS_INF_CKS_ERR_MB1(val)                     ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x91, 0x1, 0x0, val)

#define VRX_is_CEC_RX_RDY2_RAW_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x92, 0x20, 0x5)
#define VRX_get_CEC_RX_RDY2_RAW(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x92, 0x20, 0x5, pval)
#define VRX_ret_CEC_RX_RDY2_RAW()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x92, 0x20, 0x5)

#define VRX_is_CEC_RX_RDY1_RAW_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x92, 0x10, 0x4)
#define VRX_get_CEC_RX_RDY1_RAW(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x92, 0x10, 0x4, pval)
#define VRX_ret_CEC_RX_RDY1_RAW()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x92, 0x10, 0x4)

#define VRX_is_CEC_RX_RDY0_RAW_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x92, 0x8, 0x3)
#define VRX_get_CEC_RX_RDY0_RAW(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x92, 0x8, 0x3, pval)
#define VRX_ret_CEC_RX_RDY0_RAW()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x92, 0x8, 0x3)

#define VRX_is_CEC_TX_RETRY_TIMEOUT_RAW_true()              ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x92, 0x4, 0x2)
#define VRX_get_CEC_TX_RETRY_TIMEOUT_RAW(pval)              ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x92, 0x4, 0x2, pval)
#define VRX_ret_CEC_TX_RETRY_TIMEOUT_RAW()                  ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x92, 0x4, 0x2)

#define VRX_is_CEC_TX_ARBITRATION_LOST_RAW_true()           ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x92, 0x2, 0x1)
#define VRX_get_CEC_TX_ARBITRATION_LOST_RAW(pval)           ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x92, 0x2, 0x1, pval)
#define VRX_ret_CEC_TX_ARBITRATION_LOST_RAW()               ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x92, 0x2, 0x1)

#define VRX_is_CEC_TX_READY_RAW_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x92, 0x1, 0x0)
#define VRX_get_CEC_TX_READY_RAW(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x92, 0x1, 0x0, pval)
#define VRX_ret_CEC_TX_READY_RAW()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x92, 0x1, 0x0)

#define VRX_is_CEC_RX_RDY2_ST_true()                        ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x93, 0x20, 0x5)
#define VRX_get_CEC_RX_RDY2_ST(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x93, 0x20, 0x5, pval)
#define VRX_ret_CEC_RX_RDY2_ST()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x93, 0x20, 0x5)

#define VRX_is_CEC_RX_RDY1_ST_true()                        ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x93, 0x10, 0x4)
#define VRX_get_CEC_RX_RDY1_ST(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x93, 0x10, 0x4, pval)
#define VRX_ret_CEC_RX_RDY1_ST()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x93, 0x10, 0x4)

#define VRX_is_CEC_RX_RDY0_ST_true()                        ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x93, 0x8, 0x3)
#define VRX_get_CEC_RX_RDY0_ST(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x93, 0x8, 0x3, pval)
#define VRX_ret_CEC_RX_RDY0_ST()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x93, 0x8, 0x3)

#define VRX_is_CEC_TX_RETRY_TIMEOUT_ST_true()               ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x93, 0x4, 0x2)
#define VRX_get_CEC_TX_RETRY_TIMEOUT_ST(pval)               ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x93, 0x4, 0x2, pval)
#define VRX_ret_CEC_TX_RETRY_TIMEOUT_ST()                   ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x93, 0x4, 0x2)

#define VRX_is_CEC_TX_ARBITRATION_LOST_ST_true()            ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x93, 0x2, 0x1)
#define VRX_get_CEC_TX_ARBITRATION_LOST_ST(pval)            ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x93, 0x2, 0x1, pval)
#define VRX_ret_CEC_TX_ARBITRATION_LOST_ST()                ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x93, 0x2, 0x1)

#define VRX_is_CEC_TX_READY_ST_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x93, 0x1, 0x0)
#define VRX_get_CEC_TX_READY_ST(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x93, 0x1, 0x0, pval)
#define VRX_ret_CEC_TX_READY_ST()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x93, 0x1, 0x0)

#define VRX_set_CEC_RX_RDY2_CLR(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x94, 0x20, 0x5, val)

#define VRX_set_CEC_RX_RDY1_CLR(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x94, 0x10, 0x4, val)

#define VRX_set_CEC_RX_RDY0_CLR(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x94, 0x8, 0x3, val)

#define VRX_set_CEC_TX_RETRY_TIMEOUT_CLR(val)               ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x94, 0x4, 0x2, val)

#define VRX_set_CEC_TX_ARBITRATION_LOST_CLR(val)            ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x94, 0x2, 0x1, val)

#define VRX_set_CEC_TX_READY_CLR(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x94, 0x1, 0x0, val)

#define VRX_is_CEC_RX_RDY2_MB2_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x95, 0x20, 0x5)
#define VRX_get_CEC_RX_RDY2_MB2(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x95, 0x20, 0x5, pval)
#define VRX_ret_CEC_RX_RDY2_MB2()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x95, 0x20, 0x5)
#define VRX_set_CEC_RX_RDY2_MB2(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x95, 0x20, 0x5, val)

#define VRX_is_CEC_RX_RDY1_MB2_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x95, 0x10, 0x4)
#define VRX_get_CEC_RX_RDY1_MB2(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x95, 0x10, 0x4, pval)
#define VRX_ret_CEC_RX_RDY1_MB2()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x95, 0x10, 0x4)
#define VRX_set_CEC_RX_RDY1_MB2(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x95, 0x10, 0x4, val)

#define VRX_is_CEC_RX_RDY0_MB2_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x95, 0x8, 0x3)
#define VRX_get_CEC_RX_RDY0_MB2(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x95, 0x8, 0x3, pval)
#define VRX_ret_CEC_RX_RDY0_MB2()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x95, 0x8, 0x3)
#define VRX_set_CEC_RX_RDY0_MB2(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x95, 0x8, 0x3, val)

#define VRX_is_CEC_TX_RETRY_TIMEOUT_MB2_true()              ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x95, 0x4, 0x2)
#define VRX_get_CEC_TX_RETRY_TIMEOUT_MB2(pval)              ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x95, 0x4, 0x2, pval)
#define VRX_ret_CEC_TX_RETRY_TIMEOUT_MB2()                  ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x95, 0x4, 0x2)
#define VRX_set_CEC_TX_RETRY_TIMEOUT_MB2(val)               ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x95, 0x4, 0x2, val)

#define VRX_is_CEC_TX_ARBITRATION_LOST_MB2_true()           ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x95, 0x2, 0x1)
#define VRX_get_CEC_TX_ARBITRATION_LOST_MB2(pval)           ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x95, 0x2, 0x1, pval)
#define VRX_ret_CEC_TX_ARBITRATION_LOST_MB2()               ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x95, 0x2, 0x1)
#define VRX_set_CEC_TX_ARBITRATION_LOST_MB2(val)            ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x95, 0x2, 0x1, val)

#define VRX_is_CEC_TX_READY_MB2_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x95, 0x1, 0x0)
#define VRX_get_CEC_TX_READY_MB2(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x95, 0x1, 0x0, pval)
#define VRX_ret_CEC_TX_READY_MB2()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x95, 0x1, 0x0)
#define VRX_set_CEC_TX_READY_MB2(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x95, 0x1, 0x0, val)

#define VRX_is_CEC_RX_RDY2_MB1_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x96, 0x20, 0x5)
#define VRX_get_CEC_RX_RDY2_MB1(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x96, 0x20, 0x5, pval)
#define VRX_ret_CEC_RX_RDY2_MB1()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x96, 0x20, 0x5)
#define VRX_set_CEC_RX_RDY2_MB1(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x96, 0x20, 0x5, val)

#define VRX_is_CEC_RX_RDY1_MB1_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x96, 0x10, 0x4)
#define VRX_get_CEC_RX_RDY1_MB1(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x96, 0x10, 0x4, pval)
#define VRX_ret_CEC_RX_RDY1_MB1()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x96, 0x10, 0x4)
#define VRX_set_CEC_RX_RDY1_MB1(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x96, 0x10, 0x4, val)

#define VRX_is_CEC_RX_RDY0_MB1_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x96, 0x8, 0x3)
#define VRX_get_CEC_RX_RDY0_MB1(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x96, 0x8, 0x3, pval)
#define VRX_ret_CEC_RX_RDY0_MB1()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x96, 0x8, 0x3)
#define VRX_set_CEC_RX_RDY0_MB1(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x96, 0x8, 0x3, val)

#define VRX_is_CEC_TX_RETRY_TIMEOUT_MB1_true()              ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x96, 0x4, 0x2)
#define VRX_get_CEC_TX_RETRY_TIMEOUT_MB1(pval)              ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x96, 0x4, 0x2, pval)
#define VRX_ret_CEC_TX_RETRY_TIMEOUT_MB1()                  ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x96, 0x4, 0x2)
#define VRX_set_CEC_TX_RETRY_TIMEOUT_MB1(val)               ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x96, 0x4, 0x2, val)

#define VRX_is_CEC_TX_ARBITRATION_LOST_MB1_true()           ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x96, 0x2, 0x1)
#define VRX_get_CEC_TX_ARBITRATION_LOST_MB1(pval)           ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x96, 0x2, 0x1, pval)
#define VRX_ret_CEC_TX_ARBITRATION_LOST_MB1()               ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x96, 0x2, 0x1)
#define VRX_set_CEC_TX_ARBITRATION_LOST_MB1(val)            ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x96, 0x2, 0x1, val)

#define VRX_is_CEC_TX_READY_MB1_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x96, 0x1, 0x0)
#define VRX_get_CEC_TX_READY_MB1(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x96, 0x1, 0x0, pval)
#define VRX_ret_CEC_TX_READY_MB1()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x96, 0x1, 0x0)
#define VRX_set_CEC_TX_READY_MB1(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x96, 0x1, 0x0, val)

#define VRX_get_CEC_INTERRUPT_BYTE(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x97, 0xFF, 0, pval)
#define VRX_ret_CEC_INTERRUPT_BYTE()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x97, 0xFF, 0)

#define VRX_get_CEC_INTERRUPT_BYTE_ST(pval)                 ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x98, 0xFF, 0, pval)
#define VRX_ret_CEC_INTERRUPT_BYTE_ST()                     ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x98, 0xFF, 0)

#define VRX_set_CEC_INTERRUPT_BYTE_CLR(val)                 ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x99, 0xFF, 0, val)

#define VRX_get_CEC_INTERRUPT_BYTE_MB2(pval)                ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x9A, 0xFF, 0, pval)
#define VRX_ret_CEC_INTERRUPT_BYTE_MB2()                    ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x9A, 0xFF, 0)
#define VRX_set_CEC_INTERRUPT_BYTE_MB2(val)                 ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x9A, 0xFF, 0, val)

#define VRX_get_CEC_INTERRUPT_BYTE_MB1(pval)                ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x9B, 0xFF, 0, pval)
#define VRX_ret_CEC_INTERRUPT_BYTE_MB1()                    ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x9B, 0xFF, 0)
#define VRX_set_CEC_INTERRUPT_BYTE_MB1(val)                 ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x9B, 0xFF, 0, val)

#define VRX_is_SDP_STD_CHANGED_RAW_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x9C, 0x8, 0x3)
#define VRX_get_SDP_STD_CHANGED_RAW(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x9C, 0x8, 0x3, pval)
#define VRX_ret_SDP_STD_CHANGED_RAW()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x9C, 0x8, 0x3)

#define VRX_is_SDP_BURST_LOCKED_RAW_true()                  ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x9C, 0x2, 0x1)
#define VRX_get_SDP_BURST_LOCKED_RAW(pval)                  ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x9C, 0x2, 0x1, pval)
#define VRX_ret_SDP_BURST_LOCKED_RAW()                      ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x9C, 0x2, 0x1)

#define VRX_is_SDP_VIDEO_DETECTED_RAW_true()                ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x9C, 0x1, 0x0)
#define VRX_get_SDP_VIDEO_DETECTED_RAW(pval)                ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x9C, 0x1, 0x0, pval)
#define VRX_ret_SDP_VIDEO_DETECTED_RAW()                    ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x9C, 0x1, 0x0)

#define VRX_is_SDP_STD_CHANGED_ST_true()                    ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x9D, 0x8, 0x3)
#define VRX_get_SDP_STD_CHANGED_ST(pval)                    ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x9D, 0x8, 0x3, pval)
#define VRX_ret_SDP_STD_CHANGED_ST()                        ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x9D, 0x8, 0x3)

#define VRX_is_SDP_BURST_LOCKED_ST_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x9D, 0x2, 0x1)
#define VRX_get_SDP_BURST_LOCKED_ST(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x9D, 0x2, 0x1, pval)
#define VRX_ret_SDP_BURST_LOCKED_ST()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x9D, 0x2, 0x1)

#define VRX_is_SDP_VIDEO_DETECTED_ST_true()                 ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x9D, 0x1, 0x0)
#define VRX_get_SDP_VIDEO_DETECTED_ST(pval)                 ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x9D, 0x1, 0x0, pval)
#define VRX_ret_SDP_VIDEO_DETECTED_ST()                     ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x9D, 0x1, 0x0)

#define VRX_set_SDP_STD_CHANGED_CLR(val)                    ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x9E, 0x8, 0x3, val)

#define VRX_set_SDP_BURST_LOCKED_CLR(val)                   ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x9E, 0x2, 0x1, val)

#define VRX_set_SDP_VIDEO_DETECTED_CLR(val)                 ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x9E, 0x1, 0x0, val)

#define VRX_is_SDP_STD_CHANGED_MB2_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x9F, 0x8, 0x3)
#define VRX_get_SDP_STD_CHANGED_MB2(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x9F, 0x8, 0x3, pval)
#define VRX_ret_SDP_STD_CHANGED_MB2()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x9F, 0x8, 0x3)
#define VRX_set_SDP_STD_CHANGED_MB2(val)                    ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x9F, 0x8, 0x3, val)

#define VRX_is_SDP_BURST_LOCKED_MB2_true()                  ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x9F, 0x2, 0x1)
#define VRX_get_SDP_BURST_LOCKED_MB2(pval)                  ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x9F, 0x2, 0x1, pval)
#define VRX_ret_SDP_BURST_LOCKED_MB2()                      ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x9F, 0x2, 0x1)
#define VRX_set_SDP_BURST_LOCKED_MB2(val)                   ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x9F, 0x2, 0x1, val)

#define VRX_is_SDP_VIDEO_DETECTED_MB2_true()                ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x9F, 0x1, 0x0)
#define VRX_get_SDP_VIDEO_DETECTED_MB2(pval)                ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x9F, 0x1, 0x0, pval)
#define VRX_ret_SDP_VIDEO_DETECTED_MB2()                    ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x9F, 0x1, 0x0)
#define VRX_set_SDP_VIDEO_DETECTED_MB2(val)                 ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x9F, 0x1, 0x0, val)

#define VRX_is_SDP_STD_CHANGED_MB1_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0xA0, 0x8, 0x3)
#define VRX_get_SDP_STD_CHANGED_MB1(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0xA0, 0x8, 0x3, pval)
#define VRX_ret_SDP_STD_CHANGED_MB1()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0xA0, 0x8, 0x3)
#define VRX_set_SDP_STD_CHANGED_MB1(val)                    ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0xA0, 0x8, 0x3, val)

#define VRX_is_SDP_FIFO_CRISIS_MB1_true()                   ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0xA0, 0x4, 0x2)
#define VRX_get_SDP_FIFO_CRISIS_MB1(pval)                   ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0xA0, 0x4, 0x2, pval)
#define VRX_ret_SDP_FIFO_CRISIS_MB1()                       ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0xA0, 0x4, 0x2)
#define VRX_set_SDP_FIFO_CRISIS_MB1(val)                    ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0xA0, 0x4, 0x2, val)

#define VRX_is_SDP_BURST_LOCKED_MB1_true()                  ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0xA0, 0x2, 0x1)
#define VRX_get_SDP_BURST_LOCKED_MB1(pval)                  ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0xA0, 0x2, 0x1, pval)
#define VRX_ret_SDP_BURST_LOCKED_MB1()                      ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0xA0, 0x2, 0x1)
#define VRX_set_SDP_BURST_LOCKED_MB1(val)                   ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0xA0, 0x2, 0x1, val)

#define VRX_is_SDP_VIDEO_DETECTED_MB1_true()                ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0xA0, 0x1, 0x0)
#define VRX_get_SDP_VIDEO_DETECTED_MB1(pval)                ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0xA0, 0x1, 0x0, pval)
#define VRX_ret_SDP_VIDEO_DETECTED_MB1()                    ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0xA0, 0x1, 0x0)
#define VRX_set_SDP_VIDEO_DETECTED_MB1(val)                 ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0xA0, 0x1, 0x0, val)

#define VRX_is_PIN_CHECKER_EN_true()                        ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0xD6, 0x1, 0x0)
#define VRX_get_PIN_CHECKER_EN(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0xD6, 0x1, 0x0, pval)
#define VRX_ret_PIN_CHECKER_EN()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0xD6, 0x1, 0x0)
#define VRX_set_PIN_CHECKER_EN(val)                         ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0xD6, 0x1, 0x0, val)

#define VRX_get_PIN_CHECKER_VAL(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0xD7, 0xFF, 0, pval)
#define VRX_ret_PIN_CHECKER_VAL()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0xD7, 0xFF, 0)
#define VRX_set_PIN_CHECKER_VAL(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0xD7, 0xFF, 0, val)

#define VRX_get_DDS_FREQ_MAN(pval)                          ATV_I2CGetMultiField(VRX_IO_MAP_ADDR, 0xD8, 5, pval)
#define VRX_set_DDS_FREQ_MAN(pval)                          ATV_I2CSetMultiField(VRX_IO_MAP_ADDR, 0xD8, 5, pval)

#define VRX_is_DDS_FREQ_MAN_EN_true()                       ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0xDC, 0x20, 0x5)
#define VRX_get_DDS_FREQ_MAN_EN(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0xDC, 0x20, 0x5, pval)
#define VRX_ret_DDS_FREQ_MAN_EN()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0xDC, 0x20, 0x5)
#define VRX_set_DDS_FREQ_MAN_EN(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0xDC, 0x20, 0x5, val)

#define VRX_is_MAN_OP_CLK_SEL_EN_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0xDD, 0x80, 0x7)
#define VRX_get_MAN_OP_CLK_SEL_EN(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0xDD, 0x80, 0x7, pval)
#define VRX_ret_MAN_OP_CLK_SEL_EN()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0xDD, 0x80, 0x7)
#define VRX_set_MAN_OP_CLK_SEL_EN(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0xDD, 0x80, 0x7, val)

#define VRX_get_MAN_OP_CLK_SEL(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0xDD, 0x70, 4, pval)
#define VRX_ret_MAN_OP_CLK_SEL()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0xDD, 0x70, 4)
#define VRX_set_MAN_OP_CLK_SEL(val)                         ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0xDD, 0x70, 4, val)

#define VRX_is_DS_WITHOUT_FILTER_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0xE0, 0x80, 0x7)
#define VRX_get_DS_WITHOUT_FILTER(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0xE0, 0x80, 0x7, pval)
#define VRX_ret_DS_WITHOUT_FILTER()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0xE0, 0x80, 0x7)
#define VRX_set_DS_WITHOUT_FILTER(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0xE0, 0x80, 0x7, val)

#define VRX_is_DPP_LUMA_HBW_SEL_true()                      ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0xE7, 0x20, 0x5)
#define VRX_get_DPP_LUMA_HBW_SEL(pval)                      ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0xE7, 0x20, 0x5, pval)
#define VRX_ret_DPP_LUMA_HBW_SEL()                          ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0xE7, 0x20, 0x5)
#define VRX_set_DPP_LUMA_HBW_SEL(val)                       ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0xE7, 0x20, 0x5, val)

#define VRX_is_DPP_CHROMA_LOW_EN_true()                     ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0xE7, 0x10, 0x4)
#define VRX_get_DPP_CHROMA_LOW_EN(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0xE7, 0x10, 0x4, pval)
#define VRX_ret_DPP_CHROMA_LOW_EN()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0xE7, 0x10, 0x4)
#define VRX_set_DPP_CHROMA_LOW_EN(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0xE7, 0x10, 0x4, val)

#define VRX_get_RD_INFO(pval)                               ATV_I2CGetField32(VRX_IO_MAP_ADDR, 0xEA, 0xFF, 0xFF, 0, 2, pval)
#define VRX_ret_RD_INFO()                                   ATV_I2CReadField32(VRX_IO_MAP_ADDR, 0xEA, 0xFF, 0xFF, 0, 2)

#define VRX_get_SDP_SLAVE_ADDR(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0xF1, 0xFE, 1, pval)
#define VRX_ret_SDP_SLAVE_ADDR()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0xF1, 0xFE, 1)
#define VRX_set_SDP_SLAVE_ADDR(val)                         ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0xF1, 0xFE, 1, val)

#define VRX_get_SDP_IO_SLAVE_ADDR(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0xF2, 0xFE, 1, pval)
#define VRX_ret_SDP_IO_SLAVE_ADDR()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0xF2, 0xFE, 1)
#define VRX_set_SDP_IO_SLAVE_ADDR(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0xF2, 0xFE, 1, val)

#define VRX_get_AVLINK_SLAVE_ADDR(pval)                     ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0xF3, 0xFE, 1, pval)
#define VRX_ret_AVLINK_SLAVE_ADDR()                         ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0xF3, 0xFE, 1)
#define VRX_set_AVLINK_SLAVE_ADDR(val)                      ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0xF3, 0xFE, 1, val)

#define VRX_get_CEC_SLAVE_ADDR(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0xF4, 0xFE, 1, pval)
#define VRX_ret_CEC_SLAVE_ADDR()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0xF4, 0xFE, 1)
#define VRX_set_CEC_SLAVE_ADDR(val)                         ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0xF4, 0xFE, 1, val)

#define VRX_get_INFOFRAME_SLAVE_ADDR(pval)                  ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0xF5, 0xFE, 1, pval)
#define VRX_ret_INFOFRAME_SLAVE_ADDR()                      ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0xF5, 0xFE, 1)
#define VRX_set_INFOFRAME_SLAVE_ADDR(val)                   ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0xF5, 0xFE, 1, val)

#define VRX_get_AFE_SLAVE_ADDR(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0xF8, 0xFE, 1, pval)
#define VRX_ret_AFE_SLAVE_ADDR()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0xF8, 0xFE, 1)
#define VRX_set_AFE_SLAVE_ADDR(val)                         ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0xF8, 0xFE, 1, val)

#define VRX_get_KSV_SLAVE_ADDR(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0xF9, 0xFE, 1, pval)
#define VRX_ret_KSV_SLAVE_ADDR()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0xF9, 0xFE, 1)
#define VRX_set_KSV_SLAVE_ADDR(val)                         ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0xF9, 0xFE, 1, val)

#define VRX_get_EDID_SLAVE_ADDR(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0xFA, 0xFE, 1, pval)
#define VRX_ret_EDID_SLAVE_ADDR()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0xFA, 0xFE, 1)
#define VRX_set_EDID_SLAVE_ADDR(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0xFA, 0xFE, 1, val)

#define VRX_get_HDMI_SLAVE_ADDR(pval)                       ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0xFB, 0xFE, 1, pval)
#define VRX_ret_HDMI_SLAVE_ADDR()                           ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0xFB, 0xFE, 1)
#define VRX_set_HDMI_SLAVE_ADDR(val)                        ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0xFB, 0xFE, 1, val)

#define VRX_get_CP_SLAVE_ADDR(pval)                         ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0xFD, 0xFE, 1, pval)
#define VRX_ret_CP_SLAVE_ADDR()                             ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0xFD, 0xFE, 1)
#define VRX_set_CP_SLAVE_ADDR(val)                          ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0xFD, 0xFE, 1, val)

#define VRX_get_VDP_SLAVE_ADDR(pval)                        ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0xFE, 0xFE, 1, pval)
#define VRX_ret_VDP_SLAVE_ADDR()                            ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0xFE, 0xFE, 1)
#define VRX_set_VDP_SLAVE_ADDR(val)                         ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0xFE, 0xFE, 1, val)

#define VRX_set_MAIN_RESET(val)                             ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0xFF, 0x80, 0x7, val)

#define VRX_set_VDP_RESET(val)                              ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0xFF, 0x20, 0x5, val)

#define VRX_set_SDP_RESET(val)                              ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0xFF, 0x8, 0x3, val)

#define VRX_set_SDP_MEM_RESET(val)                          ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0xFF, 0x4, 0x2, val)

#endif
