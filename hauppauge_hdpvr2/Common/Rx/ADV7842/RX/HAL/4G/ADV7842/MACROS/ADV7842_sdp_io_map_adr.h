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


#ifndef ADV7842_SDP_IO_MAP_ADR_H
#define ADV7842_SDP_IO_MAP_ADR_H

#define VRX_REG_MEMORY_PAD_COTNROL                          0x29
#define VRX_BIT_SDP_TRI_MEMORY_IF_B                         0x10

#define VRX_REG_RINGING_REDUCTION_CONTROL_1                 0x51
#define VRX_BIT_SDP_RING_RED_EN                             0x80

#define VRX_REG_RESETS                                      0x60

#define VRX_REG_SFL_CONFIGURATION_1                         0x66
#define VRX_BIT_SDP_MAN_SFL_STD_EN                          0x02
#define VRX_BIT_SDP_AUTO_SFL_STD_EN                         0x01

#define VRX_REG_SFL_CONFIGURATION_2                         0x67
#define VRX_BIT_SDP_SFL_EN                                  0x04
#define VRX_BIT_SDP_SFL_INV_PSW                             0x01

#define VRX_REG_MEMORY_ARBITER_CONTROL                      0x6F
#define VRX_BIT_SDP_FREEZE_FRAME                            0x02
#define VRX_BIT_SDP_SDRAM_MEM                               0x01

#define VRX_REG_AUX_EAV_POSITION_1                          0x8C

#define VRX_REG_AUX_EAV_POSITION_2                          0x8D

#define VRX_REG_AUX_SAV_POSITION_1                          0x8E

#define VRX_REG_AUX_SAV_POSITION_2                          0x8F

#define VRX_REG_EAV_POSITION_1                              0x90

#define VRX_REG_EAV_POSITION_2                              0x91

#define VRX_REG_SAV_POSITION_1                              0x92

#define VRX_REG_SAV_POSITION_2                              0x93

#define VRX_REG_HSYNC_BEGIN_1                               0x94

#define VRX_REG_HSYNC_BEGIN_2                               0x95

#define VRX_REG_HSYNC_WIDTH_1                               0x96

#define VRX_REG_HSYNC_WIDTH_2                               0x97

#define VRX_REG_DE_HORIZONTAL_BEGIN_1                       0x98

#define VRX_REG_DE_HORIZONTAL_BEGIN_2                       0x99

#define VRX_REG_DE_HORIZONTAL_END_1                         0x9A

#define VRX_REG_DE_HORIZONTAL_END_2                         0x9B

#define VRX_REG_VSYNC_FIELD_HORIZONTAL_BEGIN_1              0x9C

#define VRX_REG_VSYNC_FIELD_HORIZONTAL_BEGIN_2              0x9D

#define VRX_REG_VSYNC_FIELD_HORIZONTAL_BEGIN_3              0x9E

#define VRX_REG_VSYNC_FIELD_HORIZONTAL_BEGIN_4              0x9F

#define VRX_REG_V_BIT_BEGIN_ODD                             0xA0

#define VRX_REG_V_BIT_BEGIN_EVEN                            0xA1

#define VRX_REG_V_BIT_END_ODD                               0xA2

#define VRX_REG_V_BIT_END_EVEN                              0xA3

#define VRX_REG_F_BIT_TOGGLE_ODD                            0xA4

#define VRX_REG_F_BIT_TOGGLE_EVEN                           0xA5

#define VRX_REG_FIELD_TOGGLE_ODD                            0xA6

#define VRX_REG_FIELD_TOGGLE_EVEN                           0xA7

#define VRX_REG_VSYNC_VERTICAL_BEGIN_ODD                    0xA8

#define VRX_REG_VSYNC_VERTICAL_BEGIN_EVEN                   0xA9

#define VRX_REG_VSYNC_VERTICAL_END_ODD                      0xAA

#define VRX_REG_VSYNC_VERTICAL_END_EVEN                     0xAB

#define VRX_REG_DE_VERTICAL_BEGIN_ODD                       0xAC

#define VRX_REG_DE_VERTICAL_BEGIN_EVEN                      0xAD

#define VRX_REG_DE_VERTICAL_END_ODD                         0xAE

#define VRX_REG_DE_VERTICAL_END_EVEN                        0xAF

#define VRX_REG_BLANKING_CONTROL                            0xB0
#define VRX_BIT_SDP_VBLANK_EN                               0x80
#define VRX_BIT_SDP_HBLANK_EN                               0x40
#define VRX_BIT_SDP_FHE_TOG_INV                             0x20
#define VRX_BIT_SDP_FHO_TOG_INV                             0x10
#define VRX_BIT_SDP_VHE_END_INV                             0x08
#define VRX_BIT_SDP_VHO_END_INV                             0x04
#define VRX_BIT_SDP_VHE_BEG_INV                             0x02
#define VRX_BIT_SDP_VHO_BEG_INV                             0x01

#define VRX_REG_POLARITY                                    0xB1
#define VRX_BIT_SDP_V_BIT_POL                               0x40
#define VRX_BIT_SDP_F_BIT_POL                               0x20
#define VRX_BIT_SDP_DE_POL                                  0x10
#define VRX_BIT_SDP_CS_POL                                  0x08
#define VRX_BIT_SDP_FLD_POL                                 0x04
#define VRX_BIT_SDP_VS_POL                                  0x02
#define VRX_BIT_SDP_HS_POL                                  0x01

#define VRX_REG_SAV_EAV_CONTROLS                            0xB2
#define VRX_BIT_SDP_EAV_EN                                  0x08
#define VRX_BIT_SDP_SAV_EN                                  0x04
#define VRX_BIT_SDP_FRZ_F_BIT                               0x02

#define VRX_REG_ANCILLARY_DATA_BEGIN                        0xB3
#define VRX_BIT_SDP_REPL_ANC_DATA                           0x80
#define VRX_BIT_SDP_SPLIT_ANC_DATA                          0x40
#define VRX_BIT_SDP_SPLIT_AV_CODE                           0x20

#define VRX_REG_V_BIT_BEGIN_ODD_TM                          0xB4

#define VRX_REG_V_BIT_BEGIN_EVEN_TM                         0xB5

#define VRX_REG_V_BIT_END_ODD_TM                            0xB6

#define VRX_REG_V_BIT_END_EVEN_TM                           0xB7

#define VRX_REG_F_BIT_TOGGLE_ODD_TM                         0xB8

#define VRX_REG_F_BIT_TOGGLE_EVEN_TM                        0xB9

#define VRX_REG_AUX_V_BIT_BEGIN_ODD                         0xC2

#define VRX_REG_AUX_V_BIT_BEGIN_EVEN                        0xC3

#define VRX_REG_AUX_V_BIT_END_ODD                           0xC4

#define VRX_REG_AUX_V_BIT_END_EVEN                          0xC5

#define VRX_REG_AUX_F_BIT_TOGGLE_ODD                        0xC6

#define VRX_REG_AUX_F_BIT_TOGGLE_EVEN                       0xC7

#define VRX_REG_AUX_SAV_EAV_CONTROLS_1                      0xC8
#define VRX_BIT_SDP_AUX_V_BIT_POL                           0x40
#define VRX_BIT_SDP_AUX_F_BIT_POL                           0x20
#define VRX_BIT_SDP_ANC_MAIN_EN                             0x08
#define VRX_BIT_SDP_ANC_AUX_EN                              0x04
#define VRX_BIT_SDP_AUX_VBLANK_EN                           0x02
#define VRX_BIT_SDP_AUX_HBLANK_EN                           0x01

#define VRX_REG_AUX_SAV_EAV_CONTROLS_2                      0xC9
#define VRX_BIT_SDP_AUX_REPL_AV_CODE                        0x10
#define VRX_BIT_SDP_AUX_EAV_EN                              0x08
#define VRX_BIT_SDP_AUX_SAV_EN                              0x04

#define VRX_REG_SDP_CSC_A1_1                                0xE0
#define VRX_BIT_SDP_CSC_SCALE                               0x80
#define VRX_BIT_SDP_CSC_AUTO                                0x40
#define VRX_BIT_SDP_RET_VID_ADJ                             0x20

#define VRX_REG_SDP_CSC_A1_2                                0xE1

#define VRX_REG_SDP_CSC_A2_1                                0xE2

#define VRX_REG_SDP_CSC_A2_2                                0xE3

#define VRX_REG_SDP_CSC_A3_1                                0xE4

#define VRX_REG_SDP_CSC_A3_2                                0xE5

#define VRX_REG_SDP_CSC_A4_1                                0xE6

#define VRX_REG_SDP_CSC_A4_2                                0xE7

#define VRX_REG_SDP_CSC_B1_1                                0xE8

#define VRX_REG_SDP_CSC_B1_2                                0xE9

#define VRX_REG_SDP_CSC_B2_1                                0xEA

#define VRX_REG_SDP_CSC_B2_2                                0xEB

#define VRX_REG_SDP_CSC_B3_1                                0xEC

#define VRX_REG_SDP_CSC_B3_2                                0xED

#define VRX_REG_SDP_CSC_B4_1                                0xEE

#define VRX_REG_SDP_CSC_B4_2                                0xEF

#define VRX_REG_SDP_CSC_C1_1                                0xF0

#define VRX_REG_SDP_CSC_C1_2                                0xF1

#define VRX_REG_SDP_CSC_C2_1                                0xF2

#define VRX_REG_SDP_CSC_C2_2                                0xF3

#define VRX_REG_SDP_CSC_C3_1                                0xF4

#define VRX_REG_SDP_CSC_C3_2                                0xF5

#define VRX_REG_SDP_CSC_C4_1                                0xF6

#define VRX_REG_SDP_CSC_C4_2                                0xF7


#endif
