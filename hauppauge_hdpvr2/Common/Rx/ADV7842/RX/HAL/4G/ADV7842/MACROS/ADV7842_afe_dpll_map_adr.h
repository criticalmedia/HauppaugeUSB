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


#ifndef ADV7842_AFE_DPLL_MAP_ADR_H
#define ADV7842_AFE_DPLL_MAP_ADR_H

#define VRX_REG_ADC_POWERDOWN_CONTROL                       0x00
#define VRX_BIT_PDN_ADC3                                    0x08
#define VRX_BIT_PDN_ADC2                                    0x04
#define VRX_BIT_PDN_ADC1                                    0x02
#define VRX_BIT_PDN_ADC0                                    0x01

#define VRX_REG_INPUT_MUX_CONTROL_1                         0x02
#define VRX_BIT_ADC_SWITCH_MAN                              0x80
#define VRX_BIT_EMB_SYNC_SEL_MAN_EN                         0x40

#define VRX_REG_INPUT_MUX_CONTROL_2                         0x03

#define VRX_REG_INPUT_MUX_CONTROL_3                         0x04

#define VRX_REG_ANTI_ALIAS_FILTER_ENABLE                    0x05
#define VRX_BIT_AA_FILTER_EN3                               0x08
#define VRX_BIT_AA_FILTER_EN2                               0x04
#define VRX_BIT_AA_FILTER_EN1                               0x02
#define VRX_BIT_AA_FILTER_EN0                               0x01

#define VRX_REG_ANTI_ALIAS_FILTER_CALIBRATION               0x06

#define VRX_REG_ANTI_ALIAS_FILTER_BANDWIDTH                 0x07

#define VRX_REG_FAST_BLANK                                  0x14

#define VRX_REG_SYNC_STRIPPER                               0x15

#define VRX_REG_SYNC_SLICER_LEVEL                           0x16

#define VRX_REG_TRILEVEL_INTERRUPT_ENABLE_1                 0x17

#define VRX_REG_TRILEVEL_INTERRUPT_ENABLE_2                 0x18

#define VRX_REG_TRILEVEL_INTERRUPT_CLEAR_1                  0x19

#define VRX_REG_TRILEVEL_INTERRUPT_CLEAR_2                  0x1A

#define VRX_REG_TRILEVEL_INTERRUPT_STATUS_1                 0x1B

#define VRX_REG_TRILEVEL_INTERRUPT_STATUS_2                 0x1C

#define VRX_REG_TRI1_SLICE_CONTROL                          0x1D
#define VRX_BIT_TRI1_SLICER_PWRDN                           0x40
#define VRX_BIT_TRI1_BILEVEL_SLICE_EN                       0x20

#define VRX_REG_TRI2_SLICE_CONTROL                          0x1E
#define VRX_BIT_TRI2_SLICER_PWRDN                           0x40
#define VRX_BIT_TRI2_BILEVEL_SLICE_EN                       0x20

#define VRX_REG_TRI3_SLICE_CONTROL                          0x1F
#define VRX_BIT_TRI3_SLICER_PWRDN                           0x40
#define VRX_BIT_TRI3_BILEVEL_SLICE_EN                       0x20

#define VRX_REG_TRI4_SLICE_CONTROL                          0x20
#define VRX_BIT_TRI4_SLICER_PWRDN                           0x40
#define VRX_BIT_TRI4_BILEVEL_SLICE_EN                       0x20

#define VRX_REG_TRI5_SLICE_CONTROL                          0x21
#define VRX_BIT_TRI5_SLICER_PWRDN                           0x40
#define VRX_BIT_TRI5_BILEVEL_SLICE_EN                       0x20

#define VRX_REG_TRI6_SLICE_CONTROL                          0x22
#define VRX_BIT_TRI6_SLICER_PWRDN                           0x40
#define VRX_BIT_TRI6_BILEVEL_SLICE_EN                       0x20

#define VRX_REG_TRI7_SLICE_CONTROL                          0x23
#define VRX_BIT_TRI7_SLICER_PWRDN                           0x40
#define VRX_BIT_TRI7_BILEVEL_SLICE_EN                       0x20

#define VRX_REG_TRI8_SLICE_CONTROL                          0x24
#define VRX_BIT_TRI8_SLICER_PWRDN                           0x40
#define VRX_BIT_TRI8_BILEVEL_SLICE_EN                       0x20

#define VRX_REG_TRI_INPUTS_LEVEL_READBACK_1                 0x27

#define VRX_REG_TRI_INPUTS_LEVEL_READBACK_2                 0x28

#define VRX_REG_MCLK_FS                                     0xB5

#define VRX_REG_DLL_CONTROL_2                               0xC8

#define VRX_REG_FB_CONTROL                                  0xC9


#endif
