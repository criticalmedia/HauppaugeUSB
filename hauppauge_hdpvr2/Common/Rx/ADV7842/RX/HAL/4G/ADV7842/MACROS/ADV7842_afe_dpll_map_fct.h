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
* DATE: 18 Nov 2009 15:43:7                                                    *
*                                                                              *
*******************************************************************************/


#ifndef ADV7842_AFE_DPLL_MAP_FCT_H
#define ADV7842_AFE_DPLL_MAP_FCT_H

#include "ADV7842_cfg.h"

#define VRX_is_PDN_ADC3_true()                              ATV_I2CIsField8(VRX_AFE_DPLL_MAP_ADDR, 0x00, 0x8, 0x3)
#define VRX_get_PDN_ADC3(pval)                              ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x00, 0x8, 0x3, pval)
#define VRX_ret_PDN_ADC3()                                  ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x00, 0x8, 0x3)
#define VRX_set_PDN_ADC3(val)                               ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x00, 0x8, 0x3, val)

#define VRX_is_PDN_ADC2_true()                              ATV_I2CIsField8(VRX_AFE_DPLL_MAP_ADDR, 0x00, 0x4, 0x2)
#define VRX_get_PDN_ADC2(pval)                              ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x00, 0x4, 0x2, pval)
#define VRX_ret_PDN_ADC2()                                  ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x00, 0x4, 0x2)
#define VRX_set_PDN_ADC2(val)                               ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x00, 0x4, 0x2, val)

#define VRX_is_PDN_ADC1_true()                              ATV_I2CIsField8(VRX_AFE_DPLL_MAP_ADDR, 0x00, 0x2, 0x1)
#define VRX_get_PDN_ADC1(pval)                              ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x00, 0x2, 0x1, pval)
#define VRX_ret_PDN_ADC1()                                  ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x00, 0x2, 0x1)
#define VRX_set_PDN_ADC1(val)                               ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x00, 0x2, 0x1, val)

#define VRX_is_PDN_ADC0_true()                              ATV_I2CIsField8(VRX_AFE_DPLL_MAP_ADDR, 0x00, 0x1, 0x0)
#define VRX_get_PDN_ADC0(pval)                              ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x00, 0x1, 0x0, pval)
#define VRX_ret_PDN_ADC0()                                  ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x00, 0x1, 0x0)
#define VRX_set_PDN_ADC0(val)                               ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x00, 0x1, 0x0, val)

#define VRX_is_ADC_SWITCH_MAN_true()                        ATV_I2CIsField8(VRX_AFE_DPLL_MAP_ADDR, 0x02, 0x80, 0x7)
#define VRX_get_ADC_SWITCH_MAN(pval)                        ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x02, 0x80, 0x7, pval)
#define VRX_ret_ADC_SWITCH_MAN()                            ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x02, 0x80, 0x7)
#define VRX_set_ADC_SWITCH_MAN(val)                         ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x02, 0x80, 0x7, val)

#define VRX_is_EMB_SYNC_SEL_MAN_EN_true()                   ATV_I2CIsField8(VRX_AFE_DPLL_MAP_ADDR, 0x02, 0x40, 0x6)
#define VRX_get_EMB_SYNC_SEL_MAN_EN(pval)                   ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x02, 0x40, 0x6, pval)
#define VRX_ret_EMB_SYNC_SEL_MAN_EN()                       ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x02, 0x40, 0x6)
#define VRX_set_EMB_SYNC_SEL_MAN_EN(val)                    ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x02, 0x40, 0x6, val)

#define VRX_get_AIN_SEL(pval)                               ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x02, 0xF, 0, pval)
#define VRX_ret_AIN_SEL()                                   ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x02, 0xF, 0)
#define VRX_set_AIN_SEL(val)                                ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x02, 0xF, 0, val)

#define VRX_get_ADC0_SW_MAN(pval)                           ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x03, 0xF0, 4, pval)
#define VRX_ret_ADC0_SW_MAN()                               ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x03, 0xF0, 4)
#define VRX_set_ADC0_SW_MAN(val)                            ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x03, 0xF0, 4, val)

#define VRX_get_ADC1_SW_MAN(pval)                           ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x03, 0xF, 0, pval)
#define VRX_ret_ADC1_SW_MAN()                               ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x03, 0xF, 0)
#define VRX_set_ADC1_SW_MAN(val)                            ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x03, 0xF, 0, val)

#define VRX_get_ADC2_SW_MAN(pval)                           ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x04, 0xF0, 4, pval)
#define VRX_ret_ADC2_SW_MAN()                               ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x04, 0xF0, 4)
#define VRX_set_ADC2_SW_MAN(val)                            ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x04, 0xF0, 4, val)

#define VRX_get_ADC3_SW_MAN(pval)                           ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x04, 0xF, 0, pval)
#define VRX_ret_ADC3_SW_MAN()                               ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x04, 0xF, 0)
#define VRX_set_ADC3_SW_MAN(val)                            ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x04, 0xF, 0, val)

#define VRX_is_AA_FILTER_EN3_true()                         ATV_I2CIsField8(VRX_AFE_DPLL_MAP_ADDR, 0x05, 0x8, 0x3)
#define VRX_get_AA_FILTER_EN3(pval)                         ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x05, 0x8, 0x3, pval)
#define VRX_ret_AA_FILTER_EN3()                             ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x05, 0x8, 0x3)
#define VRX_set_AA_FILTER_EN3(val)                          ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x05, 0x8, 0x3, val)

#define VRX_is_AA_FILTER_EN2_true()                         ATV_I2CIsField8(VRX_AFE_DPLL_MAP_ADDR, 0x05, 0x4, 0x2)
#define VRX_get_AA_FILTER_EN2(pval)                         ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x05, 0x4, 0x2, pval)
#define VRX_ret_AA_FILTER_EN2()                             ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x05, 0x4, 0x2)
#define VRX_set_AA_FILTER_EN2(val)                          ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x05, 0x4, 0x2, val)

#define VRX_is_AA_FILTER_EN1_true()                         ATV_I2CIsField8(VRX_AFE_DPLL_MAP_ADDR, 0x05, 0x2, 0x1)
#define VRX_get_AA_FILTER_EN1(pval)                         ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x05, 0x2, 0x1, pval)
#define VRX_ret_AA_FILTER_EN1()                             ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x05, 0x2, 0x1)
#define VRX_set_AA_FILTER_EN1(val)                          ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x05, 0x2, 0x1, val)

#define VRX_is_AA_FILTER_EN0_true()                         ATV_I2CIsField8(VRX_AFE_DPLL_MAP_ADDR, 0x05, 0x1, 0x0)
#define VRX_get_AA_FILTER_EN0(pval)                         ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x05, 0x1, 0x0, pval)
#define VRX_ret_AA_FILTER_EN0()                             ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x05, 0x1, 0x0)
#define VRX_set_AA_FILTER_EN0(val)                          ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x05, 0x1, 0x0, val)

#define VRX_get_AA_FILT_HIGH_BW(pval)                       ATV_I2CGetField32(VRX_AFE_DPLL_MAP_ADDR, 0x06, 0x20, 0x80, 7, 2, pval)
#define VRX_ret_AA_FILT_HIGH_BW()                           ATV_I2CReadField32(VRX_AFE_DPLL_MAP_ADDR, 0x06, 0x20, 0x80, 7, 2)
#define VRX_set_AA_FILT_HIGH_BW(val)                        ATV_I2CWriteField32(VRX_AFE_DPLL_MAP_ADDR, 0x06, 0x20, 0x80, 7, 2, val)

#define VRX_get_AA_FILT_PROG_BW(pval)                       ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x07, 0x60, 5, pval)
#define VRX_ret_AA_FILT_PROG_BW()                           ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x07, 0x60, 5)
#define VRX_set_AA_FILT_PROG_BW(val)                        ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x07, 0x60, 5, val)

#define VRX_get_FB_SELECT(pval)                             ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x14, 0xF, 0, pval)
#define VRX_ret_FB_SELECT()                                 ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x14, 0xF, 0)
#define VRX_set_FB_SELECT(val)                              ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x14, 0xF, 0, val)

#define VRX_get_EMB_SYNC_1_SEL_MAN(pval)                    ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x15, 0xC0, 6, pval)
#define VRX_ret_EMB_SYNC_1_SEL_MAN()                        ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x15, 0xC0, 6)
#define VRX_set_EMB_SYNC_1_SEL_MAN(val)                     ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x15, 0xC0, 6, val)

#define VRX_get_EMB_SYNC_2_SEL_MAN(pval)                    ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x15, 0x30, 4, pval)
#define VRX_ret_EMB_SYNC_2_SEL_MAN()                        ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x15, 0x30, 4)
#define VRX_set_EMB_SYNC_2_SEL_MAN(val)                     ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x15, 0x30, 4, val)

#define VRX_get_SYNC1_FILTER_SEL(pval)                      ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x15, 0xC, 2, pval)
#define VRX_ret_SYNC1_FILTER_SEL()                          ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x15, 0xC, 2)
#define VRX_set_SYNC1_FILTER_SEL(val)                       ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x15, 0xC, 2, val)

#define VRX_get_SYNC2_FILTER_SEL(pval)                      ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x15, 0x3, 0, pval)
#define VRX_ret_SYNC2_FILTER_SEL()                          ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x15, 0x3, 0)
#define VRX_set_SYNC2_FILTER_SEL(val)                       ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x15, 0x3, 0, val)

#define VRX_get_SLICE_LEVEL(pval)                           ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x16, 0x1F, 0, pval)
#define VRX_ret_SLICE_LEVEL()                               ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x16, 0x1F, 0)
#define VRX_set_SLICE_LEVEL(val)                            ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x16, 0x1F, 0, val)

#define VRX_get_TRI1_INT_MASKB(pval)                        ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x17, 0xC0, 6, pval)
#define VRX_ret_TRI1_INT_MASKB()                            ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x17, 0xC0, 6)
#define VRX_set_TRI1_INT_MASKB(val)                         ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x17, 0xC0, 6, val)

#define VRX_get_TRI2_INT_MASKB(pval)                        ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x17, 0x30, 4, pval)
#define VRX_ret_TRI2_INT_MASKB()                            ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x17, 0x30, 4)
#define VRX_set_TRI2_INT_MASKB(val)                         ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x17, 0x30, 4, val)

#define VRX_get_TRI3_INT_MASKB(pval)                        ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x17, 0xC, 2, pval)
#define VRX_ret_TRI3_INT_MASKB()                            ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x17, 0xC, 2)
#define VRX_set_TRI3_INT_MASKB(val)                         ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x17, 0xC, 2, val)

#define VRX_get_TRI4_INT_MASKB(pval)                        ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x17, 0x3, 0, pval)
#define VRX_ret_TRI4_INT_MASKB()                            ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x17, 0x3, 0)
#define VRX_set_TRI4_INT_MASKB(val)                         ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x17, 0x3, 0, val)

#define VRX_get_TRI5_INT_MASKB(pval)                        ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x18, 0xC0, 6, pval)
#define VRX_ret_TRI5_INT_MASKB()                            ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x18, 0xC0, 6)
#define VRX_set_TRI5_INT_MASKB(val)                         ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x18, 0xC0, 6, val)

#define VRX_get_TRI6_INT_MASKB(pval)                        ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x18, 0x30, 4, pval)
#define VRX_ret_TRI6_INT_MASKB()                            ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x18, 0x30, 4)
#define VRX_set_TRI6_INT_MASKB(val)                         ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x18, 0x30, 4, val)

#define VRX_get_TRI7_INT_MASKB(pval)                        ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x18, 0xC, 2, pval)
#define VRX_ret_TRI7_INT_MASKB()                            ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x18, 0xC, 2)
#define VRX_set_TRI7_INT_MASKB(val)                         ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x18, 0xC, 2, val)

#define VRX_get_TRI8_INT_MASKB(pval)                        ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x18, 0x3, 0, pval)
#define VRX_ret_TRI8_INT_MASKB()                            ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x18, 0x3, 0)
#define VRX_set_TRI8_INT_MASKB(val)                         ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x18, 0x3, 0, val)

#define VRX_set_TRI1_INT_CLEAR(val)                         ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x19, 0xC0, 6, val)

#define VRX_set_TRI2_INT_CLEAR(val)                         ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x19, 0x30, 4, val)

#define VRX_set_TRI3_INT_CLEAR(val)                         ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x19, 0xC, 2, val)

#define VRX_set_TRI4_INT_CLEAR(val)                         ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x19, 0x3, 0, val)

#define VRX_set_TRI5_INT_CLEAR(val)                         ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x1A, 0xC0, 6, val)

#define VRX_set_TRI6_INT_CLEAR(val)                         ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x1A, 0x30, 4, val)

#define VRX_set_TRI7_INT_CLEAR(val)                         ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x1A, 0xC, 2, val)

#define VRX_set_TRI8_INT_CLEAR(val)                         ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x1A, 0x3, 0, val)

#define VRX_get_TRI1_INT_STATUS(pval)                       ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x1B, 0xC0, 6, pval)
#define VRX_ret_TRI1_INT_STATUS()                           ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x1B, 0xC0, 6)

#define VRX_get_TRI2_INT_STATUS(pval)                       ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x1B, 0x30, 4, pval)
#define VRX_ret_TRI2_INT_STATUS()                           ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x1B, 0x30, 4)

#define VRX_get_TRI3_INT_STATUS(pval)                       ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x1B, 0xC, 2, pval)
#define VRX_ret_TRI3_INT_STATUS()                           ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x1B, 0xC, 2)

#define VRX_get_TRI4_INT_STATUS(pval)                       ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x1B, 0x3, 0, pval)
#define VRX_ret_TRI4_INT_STATUS()                           ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x1B, 0x3, 0)

#define VRX_get_TRI5_INT_STATUS(pval)                       ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x1C, 0xC0, 6, pval)
#define VRX_ret_TRI5_INT_STATUS()                           ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x1C, 0xC0, 6)

#define VRX_get_TRI6_INT_STATUS(pval)                       ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x1C, 0x30, 4, pval)
#define VRX_ret_TRI6_INT_STATUS()                           ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x1C, 0x30, 4)

#define VRX_get_TRI7_INT_STATUS(pval)                       ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x1C, 0xC, 2, pval)
#define VRX_ret_TRI7_INT_STATUS()                           ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x1C, 0xC, 2)

#define VRX_get_TRI8_INT_STATUS(pval)                       ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x1C, 0x3, 0, pval)
#define VRX_ret_TRI8_INT_STATUS()                           ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x1C, 0x3, 0)

#define VRX_is_TRI1_SLICER_PWRDN_true()                     ATV_I2CIsField8(VRX_AFE_DPLL_MAP_ADDR, 0x1D, 0x40, 0x6)
#define VRX_get_TRI1_SLICER_PWRDN(pval)                     ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x1D, 0x40, 0x6, pval)
#define VRX_ret_TRI1_SLICER_PWRDN()                         ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x1D, 0x40, 0x6)
#define VRX_set_TRI1_SLICER_PWRDN(val)                      ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x1D, 0x40, 0x6, val)

#define VRX_is_TRI1_BILEVEL_SLICE_EN_true()                 ATV_I2CIsField8(VRX_AFE_DPLL_MAP_ADDR, 0x1D, 0x20, 0x5)
#define VRX_get_TRI1_BILEVEL_SLICE_EN(pval)                 ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x1D, 0x20, 0x5, pval)
#define VRX_ret_TRI1_BILEVEL_SLICE_EN()                     ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x1D, 0x20, 0x5)
#define VRX_set_TRI1_BILEVEL_SLICE_EN(val)                  ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x1D, 0x20, 0x5, val)

#define VRX_get_TRI1_UPPER_SLICE_LEVEL(pval)                ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x1D, 0x1C, 2, pval)
#define VRX_ret_TRI1_UPPER_SLICE_LEVEL()                    ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x1D, 0x1C, 2)
#define VRX_set_TRI1_UPPER_SLICE_LEVEL(val)                 ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x1D, 0x1C, 2, val)

#define VRX_get_TRI1_LOWER_SLICE_LEVEL(pval)                ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x1D, 0x3, 0, pval)
#define VRX_ret_TRI1_LOWER_SLICE_LEVEL()                    ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x1D, 0x3, 0)
#define VRX_set_TRI1_LOWER_SLICE_LEVEL(val)                 ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x1D, 0x3, 0, val)

#define VRX_is_TRI2_SLICER_PWRDN_true()                     ATV_I2CIsField8(VRX_AFE_DPLL_MAP_ADDR, 0x1E, 0x40, 0x6)
#define VRX_get_TRI2_SLICER_PWRDN(pval)                     ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x1E, 0x40, 0x6, pval)
#define VRX_ret_TRI2_SLICER_PWRDN()                         ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x1E, 0x40, 0x6)
#define VRX_set_TRI2_SLICER_PWRDN(val)                      ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x1E, 0x40, 0x6, val)

#define VRX_is_TRI2_BILEVEL_SLICE_EN_true()                 ATV_I2CIsField8(VRX_AFE_DPLL_MAP_ADDR, 0x1E, 0x20, 0x5)
#define VRX_get_TRI2_BILEVEL_SLICE_EN(pval)                 ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x1E, 0x20, 0x5, pval)
#define VRX_ret_TRI2_BILEVEL_SLICE_EN()                     ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x1E, 0x20, 0x5)
#define VRX_set_TRI2_BILEVEL_SLICE_EN(val)                  ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x1E, 0x20, 0x5, val)

#define VRX_get_TRI2_UPPER_SLICE_LEVEL(pval)                ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x1E, 0x1C, 2, pval)
#define VRX_ret_TRI2_UPPER_SLICE_LEVEL()                    ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x1E, 0x1C, 2)
#define VRX_set_TRI2_UPPER_SLICE_LEVEL(val)                 ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x1E, 0x1C, 2, val)

#define VRX_get_TRI2_LOWER_SLICE_LEVEL(pval)                ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x1E, 0x3, 0, pval)
#define VRX_ret_TRI2_LOWER_SLICE_LEVEL()                    ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x1E, 0x3, 0)
#define VRX_set_TRI2_LOWER_SLICE_LEVEL(val)                 ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x1E, 0x3, 0, val)

#define VRX_is_TRI3_SLICER_PWRDN_true()                     ATV_I2CIsField8(VRX_AFE_DPLL_MAP_ADDR, 0x1F, 0x40, 0x6)
#define VRX_get_TRI3_SLICER_PWRDN(pval)                     ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x1F, 0x40, 0x6, pval)
#define VRX_ret_TRI3_SLICER_PWRDN()                         ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x1F, 0x40, 0x6)
#define VRX_set_TRI3_SLICER_PWRDN(val)                      ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x1F, 0x40, 0x6, val)

#define VRX_is_TRI3_BILEVEL_SLICE_EN_true()                 ATV_I2CIsField8(VRX_AFE_DPLL_MAP_ADDR, 0x1F, 0x20, 0x5)
#define VRX_get_TRI3_BILEVEL_SLICE_EN(pval)                 ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x1F, 0x20, 0x5, pval)
#define VRX_ret_TRI3_BILEVEL_SLICE_EN()                     ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x1F, 0x20, 0x5)
#define VRX_set_TRI3_BILEVEL_SLICE_EN(val)                  ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x1F, 0x20, 0x5, val)

#define VRX_get_TRI3_UPPER_SLICE_LEVEL(pval)                ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x1F, 0x1C, 2, pval)
#define VRX_ret_TRI3_UPPER_SLICE_LEVEL()                    ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x1F, 0x1C, 2)
#define VRX_set_TRI3_UPPER_SLICE_LEVEL(val)                 ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x1F, 0x1C, 2, val)

#define VRX_get_TRI3_LOWER_SLICE_LEVEL(pval)                ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x1F, 0x3, 0, pval)
#define VRX_ret_TRI3_LOWER_SLICE_LEVEL()                    ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x1F, 0x3, 0)
#define VRX_set_TRI3_LOWER_SLICE_LEVEL(val)                 ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x1F, 0x3, 0, val)

#define VRX_is_TRI4_SLICER_PWRDN_true()                     ATV_I2CIsField8(VRX_AFE_DPLL_MAP_ADDR, 0x20, 0x40, 0x6)
#define VRX_get_TRI4_SLICER_PWRDN(pval)                     ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x20, 0x40, 0x6, pval)
#define VRX_ret_TRI4_SLICER_PWRDN()                         ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x20, 0x40, 0x6)
#define VRX_set_TRI4_SLICER_PWRDN(val)                      ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x20, 0x40, 0x6, val)

#define VRX_is_TRI4_BILEVEL_SLICE_EN_true()                 ATV_I2CIsField8(VRX_AFE_DPLL_MAP_ADDR, 0x20, 0x20, 0x5)
#define VRX_get_TRI4_BILEVEL_SLICE_EN(pval)                 ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x20, 0x20, 0x5, pval)
#define VRX_ret_TRI4_BILEVEL_SLICE_EN()                     ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x20, 0x20, 0x5)
#define VRX_set_TRI4_BILEVEL_SLICE_EN(val)                  ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x20, 0x20, 0x5, val)

#define VRX_get_TRI4_UPPER_SLICE_LEVEL(pval)                ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x20, 0x1C, 2, pval)
#define VRX_ret_TRI4_UPPER_SLICE_LEVEL()                    ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x20, 0x1C, 2)
#define VRX_set_TRI4_UPPER_SLICE_LEVEL(val)                 ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x20, 0x1C, 2, val)

#define VRX_get_TRI4_LOWER_SLICE_LEVEL(pval)                ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x20, 0x3, 0, pval)
#define VRX_ret_TRI4_LOWER_SLICE_LEVEL()                    ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x20, 0x3, 0)
#define VRX_set_TRI4_LOWER_SLICE_LEVEL(val)                 ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x20, 0x3, 0, val)

#define VRX_is_TRI5_SLICER_PWRDN_true()                     ATV_I2CIsField8(VRX_AFE_DPLL_MAP_ADDR, 0x21, 0x40, 0x6)
#define VRX_get_TRI5_SLICER_PWRDN(pval)                     ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x21, 0x40, 0x6, pval)
#define VRX_ret_TRI5_SLICER_PWRDN()                         ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x21, 0x40, 0x6)
#define VRX_set_TRI5_SLICER_PWRDN(val)                      ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x21, 0x40, 0x6, val)

#define VRX_is_TRI5_BILEVEL_SLICE_EN_true()                 ATV_I2CIsField8(VRX_AFE_DPLL_MAP_ADDR, 0x21, 0x20, 0x5)
#define VRX_get_TRI5_BILEVEL_SLICE_EN(pval)                 ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x21, 0x20, 0x5, pval)
#define VRX_ret_TRI5_BILEVEL_SLICE_EN()                     ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x21, 0x20, 0x5)
#define VRX_set_TRI5_BILEVEL_SLICE_EN(val)                  ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x21, 0x20, 0x5, val)

#define VRX_get_TRI5_UPPER_SLICE_LEVEL(pval)                ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x21, 0x1C, 2, pval)
#define VRX_ret_TRI5_UPPER_SLICE_LEVEL()                    ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x21, 0x1C, 2)
#define VRX_set_TRI5_UPPER_SLICE_LEVEL(val)                 ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x21, 0x1C, 2, val)

#define VRX_get_TRI5_LOWER_SLICE_LEVEL(pval)                ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x21, 0x3, 0, pval)
#define VRX_ret_TRI5_LOWER_SLICE_LEVEL()                    ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x21, 0x3, 0)
#define VRX_set_TRI5_LOWER_SLICE_LEVEL(val)                 ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x21, 0x3, 0, val)

#define VRX_is_TRI6_SLICER_PWRDN_true()                     ATV_I2CIsField8(VRX_AFE_DPLL_MAP_ADDR, 0x22, 0x40, 0x6)
#define VRX_get_TRI6_SLICER_PWRDN(pval)                     ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x22, 0x40, 0x6, pval)
#define VRX_ret_TRI6_SLICER_PWRDN()                         ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x22, 0x40, 0x6)
#define VRX_set_TRI6_SLICER_PWRDN(val)                      ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x22, 0x40, 0x6, val)

#define VRX_is_TRI6_BILEVEL_SLICE_EN_true()                 ATV_I2CIsField8(VRX_AFE_DPLL_MAP_ADDR, 0x22, 0x20, 0x5)
#define VRX_get_TRI6_BILEVEL_SLICE_EN(pval)                 ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x22, 0x20, 0x5, pval)
#define VRX_ret_TRI6_BILEVEL_SLICE_EN()                     ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x22, 0x20, 0x5)
#define VRX_set_TRI6_BILEVEL_SLICE_EN(val)                  ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x22, 0x20, 0x5, val)

#define VRX_get_TRI6_UPPER_SLICE_LEVEL(pval)                ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x22, 0x1C, 2, pval)
#define VRX_ret_TRI6_UPPER_SLICE_LEVEL()                    ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x22, 0x1C, 2)
#define VRX_set_TRI6_UPPER_SLICE_LEVEL(val)                 ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x22, 0x1C, 2, val)

#define VRX_get_TRI6_LOWER_SLICE_LEVEL(pval)                ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x22, 0x3, 0, pval)
#define VRX_ret_TRI6_LOWER_SLICE_LEVEL()                    ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x22, 0x3, 0)
#define VRX_set_TRI6_LOWER_SLICE_LEVEL(val)                 ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x22, 0x3, 0, val)

#define VRX_is_TRI7_SLICER_PWRDN_true()                     ATV_I2CIsField8(VRX_AFE_DPLL_MAP_ADDR, 0x23, 0x40, 0x6)
#define VRX_get_TRI7_SLICER_PWRDN(pval)                     ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x23, 0x40, 0x6, pval)
#define VRX_ret_TRI7_SLICER_PWRDN()                         ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x23, 0x40, 0x6)
#define VRX_set_TRI7_SLICER_PWRDN(val)                      ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x23, 0x40, 0x6, val)

#define VRX_is_TRI7_BILEVEL_SLICE_EN_true()                 ATV_I2CIsField8(VRX_AFE_DPLL_MAP_ADDR, 0x23, 0x20, 0x5)
#define VRX_get_TRI7_BILEVEL_SLICE_EN(pval)                 ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x23, 0x20, 0x5, pval)
#define VRX_ret_TRI7_BILEVEL_SLICE_EN()                     ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x23, 0x20, 0x5)
#define VRX_set_TRI7_BILEVEL_SLICE_EN(val)                  ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x23, 0x20, 0x5, val)

#define VRX_get_TRI7_UPPER_SLICE_LEVEL(pval)                ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x23, 0x1C, 2, pval)
#define VRX_ret_TRI7_UPPER_SLICE_LEVEL()                    ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x23, 0x1C, 2)
#define VRX_set_TRI7_UPPER_SLICE_LEVEL(val)                 ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x23, 0x1C, 2, val)

#define VRX_get_TRI7_LOWER_SLICE_LEVEL(pval)                ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x23, 0x3, 0, pval)
#define VRX_ret_TRI7_LOWER_SLICE_LEVEL()                    ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x23, 0x3, 0)
#define VRX_set_TRI7_LOWER_SLICE_LEVEL(val)                 ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x23, 0x3, 0, val)

#define VRX_is_TRI8_SLICER_PWRDN_true()                     ATV_I2CIsField8(VRX_AFE_DPLL_MAP_ADDR, 0x24, 0x40, 0x6)
#define VRX_get_TRI8_SLICER_PWRDN(pval)                     ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x24, 0x40, 0x6, pval)
#define VRX_ret_TRI8_SLICER_PWRDN()                         ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x24, 0x40, 0x6)
#define VRX_set_TRI8_SLICER_PWRDN(val)                      ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x24, 0x40, 0x6, val)

#define VRX_is_TRI8_BILEVEL_SLICE_EN_true()                 ATV_I2CIsField8(VRX_AFE_DPLL_MAP_ADDR, 0x24, 0x20, 0x5)
#define VRX_get_TRI8_BILEVEL_SLICE_EN(pval)                 ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x24, 0x20, 0x5, pval)
#define VRX_ret_TRI8_BILEVEL_SLICE_EN()                     ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x24, 0x20, 0x5)
#define VRX_set_TRI8_BILEVEL_SLICE_EN(val)                  ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x24, 0x20, 0x5, val)

#define VRX_get_TRI8_UPPER_SLICE_LEVEL(pval)                ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x24, 0x1C, 2, pval)
#define VRX_ret_TRI8_UPPER_SLICE_LEVEL()                    ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x24, 0x1C, 2)
#define VRX_set_TRI8_UPPER_SLICE_LEVEL(val)                 ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x24, 0x1C, 2, val)

#define VRX_get_TRI8_LOWER_SLICE_LEVEL(pval)                ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x24, 0x3, 0, pval)
#define VRX_ret_TRI8_LOWER_SLICE_LEVEL()                    ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x24, 0x3, 0)
#define VRX_set_TRI8_LOWER_SLICE_LEVEL(val)                 ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0x24, 0x3, 0, val)

#define VRX_get_TRI1_READBACK(pval)                         ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x27, 0xC0, 6, pval)
#define VRX_ret_TRI1_READBACK()                             ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x27, 0xC0, 6)

#define VRX_get_TRI2_READBACK(pval)                         ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x27, 0x30, 4, pval)
#define VRX_ret_TRI2_READBACK()                             ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x27, 0x30, 4)

#define VRX_get_TRI3_READBACK(pval)                         ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x27, 0xC, 2, pval)
#define VRX_ret_TRI3_READBACK()                             ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x27, 0xC, 2)

#define VRX_get_TRI4_READBACK(pval)                         ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x27, 0x3, 0, pval)
#define VRX_ret_TRI4_READBACK()                             ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x27, 0x3, 0)

#define VRX_get_TRI5_READBACK(pval)                         ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x28, 0xC0, 6, pval)
#define VRX_ret_TRI5_READBACK()                             ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x28, 0xC0, 6)

#define VRX_get_TRI6_READBACK(pval)                         ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x28, 0x30, 4, pval)
#define VRX_ret_TRI6_READBACK()                             ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x28, 0x30, 4)

#define VRX_get_TRI7_READBACK(pval)                         ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x28, 0xC, 2, pval)
#define VRX_ret_TRI7_READBACK()                             ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x28, 0xC, 2)

#define VRX_get_TRI8_READBACK(pval)                         ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0x28, 0x3, 0, pval)
#define VRX_ret_TRI8_READBACK()                             ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0x28, 0x3, 0)

#define VRX_get_MCLK_FS_N(pval)                             ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0xB5, 0x7, 0, pval)
#define VRX_ret_MCLK_FS_N()                                 ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0xB5, 0x7, 0)
#define VRX_set_MCLK_FS_N(val)                              ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0xB5, 0x7, 0, val)

#define VRX_get_DLL_PHASE(pval)                             ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0xC8, 0x3F, 0, pval)
#define VRX_ret_DLL_PHASE()                                 ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0xC8, 0x3F, 0)
#define VRX_set_DLL_PHASE(val)                              ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0xC8, 0x3F, 0, val)

#define VRX_get_FB_PHASE_ADJUST(pval)                       ATV_I2CGetField8(VRX_AFE_DPLL_MAP_ADDR, 0xC9, 0xF, 0, pval)
#define VRX_ret_FB_PHASE_ADJUST()                           ATV_I2CReadField8(VRX_AFE_DPLL_MAP_ADDR, 0xC9, 0xF, 0)
#define VRX_set_FB_PHASE_ADJUST(val)                        ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0xC9, 0xF, 0, val)

#endif
