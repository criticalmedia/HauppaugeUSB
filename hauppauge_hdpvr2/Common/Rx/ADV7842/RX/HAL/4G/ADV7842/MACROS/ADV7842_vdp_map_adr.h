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
* DATE: 18 Nov 2009 15:43:4                                                    *
*                                                                              *
*******************************************************************************/


#ifndef ADV7842_VDP_MAP_ADR_H
#define ADV7842_VDP_MAP_ADR_H

#define VRX_REG_VDP_CGMS_TYPEB_DATA_1                       0x3C

#define VRX_REG_VDP_CGMS_TYPEB_DATA_2                       0x3D

#define VRX_REG_VDP_CGMS_TYPEB_DATA_3                       0x3E

#define VRX_REG_VDP_CGMS_TYPEB_DATA_4                       0x3F

#define VRX_REG_VDP_STATUS                                  0x40
#define VRX_BIT_VDP_STATUS_TTXT                             0x80
#define VRX_BIT_VDP_STATUS_VITC                             0x40
#define VRX_BIT_VDP_STATUS_GEMS_TYPE                        0x20
#define VRX_BIT_VDP_STATUS_GS_VPS_PDC_UTC_CGMSTB            0x10
#define VRX_BIT_VDP_STATUS_FAST_I2C                         0x08
#define VRX_BIT_VDP_STATUS_WSS_CGMS                         0x04
#define VRX_BIT_VDP_STATUS_CCAP_EVEN_FIELD                  0x02
#define VRX_BIT_VDP_STATUS_CCAP                             0x01

#define VRX_REG_VDP_CCAP_DATA_1                             0x41

#define VRX_REG_VDP_CCAP_DATA_2                             0x42

#define VRX_REG_VDP_CGMS_WSS_DATA_1                         0x43

#define VRX_REG_VDP_CGMS_WSS_DATA_2                         0x44

#define VRX_REG_VDP_CGMS_WSS_DATA_3                         0x45

#define VRX_REG_VDP_GS_VPS_PDC_UTC_CGMSTB_DATA_1            0x47

#define VRX_REG_VDP_GS_VPS_PDC_UTC_CGMSTB_DATA_2            0x48

#define VRX_REG_VDP_GS_VPS_PDC_UTC_CGMSTB_DATA_3            0x49

#define VRX_REG_VDP_GS_VPS_PDC_UTC_CGMSTB_DATA_4            0x4A

#define VRX_REG_VDP_GS_VPS_PDC_UTC_CGMSTB_DATA_5            0x4B

#define VRX_REG_VDP_GS_VPS_PDC_UTC_CGMSTB_DATA_6            0x4C

#define VRX_REG_VDP_GS_VPS_PDC_UTC_CGMSTB_DATA_7            0x4D

#define VRX_REG_VDP_GS_VPS_PDC_UTC_CGMSTB_DATA_8            0x4E

#define VRX_REG_VDP_GS_VPS_PDC_UTC_CGMSTB_DATA_9            0x4F

#define VRX_REG_VDP_GS_VPS_PDC_UTC_CGMSTB_DATA_10           0x50

#define VRX_REG_VDP_GS_VPS_PDC_UTC_CGMSTB_DATA_11           0x51

#define VRX_REG_VDP_GS_VPS_PDC_UTC_CGMSTB_DATA_12           0x52

#define VRX_REG_VDP_GS_VPS_PDC_UTC_CGMSTB_DATA_13           0x53

#define VRX_REG_VDP_VITC_DATA_1                             0x55

#define VRX_REG_VDP_VITC_DATA_2                             0x56

#define VRX_REG_VDP_VITC_DATA_3                             0x57

#define VRX_REG_VDP_VITC_DATA_4                             0x58

#define VRX_REG_VDP_VITC_DATA_5                             0x59

#define VRX_REG_VDP_VITC_DATA_6                             0x5A

#define VRX_REG_VDP_VITC_DATA_7                             0x5B

#define VRX_REG_VDP_VITC_DATA_8                             0x5C

#define VRX_REG_VDP_VITC_DATA_9                             0x5D

#define VRX_REG_VDP_VITC_CALC_CRC                           0x5E

#define VRX_REG_VDP_CONFIG_1                                0x60
#define VRX_BIT_HAM_ERR_OP_EN                               0x80
#define VRX_BIT_SOFT_ERROR_CORRECTION_EN                    0x10
#define VRX_BIT_EN_FC_WINDOW_AFTER_CRI_DET                  0x08
#define VRX_BIT_VDP_TTXT_TYPE_MAN_EN                        0x04

#define VRX_REG_VDP_CONFIG_2                                0x61
#define VRX_BIT_VDP_CP_CLMP_AVG                             0x80
#define VRX_BIT_NOISE_CLK_DISABLE                           0x20
#define VRX_BIT_AUTO_DETECT_GEM                             0x10
#define VRX_BIT_VITC_STRIP_SYNC_DISABLE                     0x02
#define VRX_BIT_BIPHASE_DECODE_DISABLE                      0x01

#define VRX_REG_VDP_ADF_CONFIG_1                            0x62
#define VRX_BIT_ADF_EN                                      0x80

#define VRX_REG_VDP_ADF_CONFIG_2                            0x63
#define VRX_BIT_TOGGLE_ADF                                  0x80

#define VRX_REG_VDP_MAN_LINE_1_21                           0x64

#define VRX_REG_VDP_MAN_LINE_2_22                           0x65

#define VRX_REG_VDP_MAN_LINE_3_23                           0x66

#define VRX_REG_VDP_MAN_LINE_4_24                           0x67

#define VRX_REG_VDP_MAN_LINE_5_25                           0x68

#define VRX_REG_VDP_MAN_LINE_6_26                           0x69

#define VRX_REG_VDP_MAN_LINE_7_27                           0x6A

#define VRX_REG_VDP_MAN_LINE_8_28                           0x6B

#define VRX_REG_VDP_MAN_LINE_9_29                           0x6C

#define VRX_REG_VDP_MAN_LINE_10_30                          0x6D

#define VRX_REG_VDP_MAN_LINE_11_31                          0x6E

#define VRX_REG_VDP_MAN_LINE_12_32                          0x6F

#define VRX_REG_VDP_MAN_LINE_13_33                          0x70

#define VRX_REG_VDP_MAN_LINE_14_34                          0x71

#define VRX_REG_VDP_MAN_LINE_15_35                          0x72

#define VRX_REG_VDP_MAN_LINE_16_36                          0x73

#define VRX_REG_VDP_MAN_LINE_17_37                          0x74

#define VRX_REG_VDP_MAN_LINE_18_38                          0x75

#define VRX_REG_VDP_MAN_LINE_19_39                          0x76

#define VRX_REG_VDP_MAN_LINE_20_40                          0x77

#define VRX_REG_VDP_STATUS_CLEAR                            0x78

#define VRX_REG_VDP_FILTER_ADAPTIVE_SLICER_CONFIG           0x98
#define VRX_BIT_LOW_DATA_STD_FILTER_EN                      0x80
#define VRX_BIT_ADAP1_SL_CONFIG_EN                          0x20
#define VRX_BIT_TTX_SEL                                     0x10
#define VRX_BIT_ADAP2_SL_CONFIG_EN                          0x08

#define VRX_REG_VDP_ADAP2_STD_EN                            0x99
#define VRX_BIT_ADAP2_TTXT_STD_EN                           0x80
#define VRX_BIT_ADAP2_VITC_STD_EN                           0x40
#define VRX_BIT_ADAP2_GEMS_STD_EN                           0x10
#define VRX_BIT_ADAP2_VPS_STD_EN                            0x08
#define VRX_BIT_ADAP2_WSS_CGMS_STD_EN                       0x04
#define VRX_BIT_ADAP2_CCAP_STD_EN                           0x01

#define VRX_REG_VDP_STATUS_CONFIG                           0x9C
#define VRX_BIT_GS_VPS_PDC_UTC_CB_CHANGE                    0x20
#define VRX_BIT_WSS_CGMS_CB_CHANGE                          0x10
#define VRX_BIT_RAW_STATUS_ENABLE                           0x08

#define VRX_REG_VDP_MISC_CONFIG                             0x9D
#define VRX_BIT_SLICE_CORRECTOR_EN                          0x02

#define VRX_REG_VDP_ADAP2_FAST_LEARN_EN                     0x9E
#define VRX_BIT_ADAP2_VPS_CTB_FAST_LEARN_EN                 0x08

#define VRX_REG_VDP_NEW_TTX_CONFIG1                         0xA5
#define VRX_BIT_VDP_USE_PREDEF_FREQ                         0x40
#define VRX_BIT_VDP_CRI_TOLERANCE                           0x20
#define VRX_BIT_VDP_FRM_CODE_TOLERANCE                      0x10
#define VRX_BIT_VDP_CRI_8BIT                                0x08

#define VRX_REG_VDP_NEW_TTX_CONFIG2                         0xA6
#define VRX_BIT_VDP_INVERT_EVEN_FIELD                       0x10

#define VRX_REG_VDP_PARITY_MAX                              0xA8
#define VRX_BIT_VDP_MANUAL_TTXC                             0x40

#define VRX_REG_VDP_CRI_MAG_THRESH                          0xAC

#define VRX_REG_FAST_I2C_REG_CONF1                          0xC0
#define VRX_BIT_VDP_FAST_REG_CONF_CUS2                      0x80
#define VRX_BIT_VDP_FAST_REG_CONF_CUST                      0x40
#define VRX_BIT_VDP_FAST_REG_CONF_CCAP                      0x20
#define VRX_BIT_VDP_FAST_REG_CONF_GEM1X_2X                  0x10
#define VRX_BIT_VDP_FAST_REG_CONF_CGMS_WSS                  0x08
#define VRX_BIT_VDP_FAST_REG_CONF_VITC                      0x04
#define VRX_BIT_VDP_FAST_REG_CONF_VPS_CGMSTB                0x02
#define VRX_BIT_VDP_FAST_REG_CONF_TTXT                      0x01

#define VRX_REG_FAST_I2C_VBI_STD                            0xC2

#define VRX_REG_FAST_I2C_PACKET_SIZE                        0xC3

#define VRX_REG_FAST_I2C_REG_00                             0xC4

#define VRX_REG_FAST_I2C_REG_01                             0xC5

#define VRX_REG_FAST_I2C_REG_02                             0xC6

#define VRX_REG_FAST_I2C_REG_03                             0xC7

#define VRX_REG_FAST_I2C_REG_04                             0xC8

#define VRX_REG_FAST_I2C_REG_05                             0xC9

#define VRX_REG_FAST_I2C_REG_06                             0xCA

#define VRX_REG_FAST_I2C_REG_07                             0xCB

#define VRX_REG_FAST_I2C_REG_08                             0xCC

#define VRX_REG_FAST_I2C_REG_09                             0xCD

#define VRX_REG_FAST_I2C_REG_10                             0xCE

#define VRX_REG_FAST_I2C_REG_11                             0xCF

#define VRX_REG_FAST_I2C_REG_12                             0xD0

#define VRX_REG_FAST_I2C_REG_13                             0xD1

#define VRX_REG_FAST_I2C_REG_14                             0xD2

#define VRX_REG_FAST_I2C_REG_15                             0xD3

#define VRX_REG_FAST_I2C_REG_16                             0xD4

#define VRX_REG_FAST_I2C_REG_17                             0xD5

#define VRX_REG_FAST_I2C_REG_18                             0xD6

#define VRX_REG_FAST_I2C_REG_19                             0xD7

#define VRX_REG_FAST_I2C_REG_20                             0xD8

#define VRX_REG_FAST_I2C_REG_21                             0xD9

#define VRX_REG_FAST_I2C_REG_22                             0xDA

#define VRX_REG_FAST_I2C_REG_23                             0xDB

#define VRX_REG_FAST_I2C_REG_24                             0xDC

#define VRX_REG_FAST_I2C_REG_25                             0xDD

#define VRX_REG_FAST_I2C_REG_26                             0xDE

#define VRX_REG_FAST_I2C_REG_27                             0xDF

#define VRX_REG_FAST_I2C_REG_28                             0xE0

#define VRX_REG_FAST_I2C_REG_29                             0xE1

#define VRX_REG_FAST_I2C_REG_30                             0xE2

#define VRX_REG_FAST_I2C_REG_31                             0xE3

#define VRX_REG_FAST_I2C_REG_32                             0xE4

#define VRX_REG_FAST_I2C_REG_33                             0xE5

#define VRX_REG_FAST_I2C_REG_34                             0xE6

#define VRX_REG_FAST_I2C_REG_35                             0xE7

#define VRX_REG_FAST_I2C_REG_36                             0xE8

#define VRX_REG_FAST_I2C_REG_37                             0xE9

#define VRX_REG_FAST_I2C_REG_38                             0xEA

#define VRX_REG_FAST_I2C_REG_39                             0xEB

#define VRX_REG_FAST_I2C_REG_40                             0xEC

#define VRX_REG_FAST_I2C_REG_41                             0xED

#define VRX_REG_FAST_I2C_REG_42                             0xEE

#define VRX_REG_FAST_I2C_REG_43                             0xEF

#define VRX_REG_FAST_I2C_REG_44                             0xF0


#endif
