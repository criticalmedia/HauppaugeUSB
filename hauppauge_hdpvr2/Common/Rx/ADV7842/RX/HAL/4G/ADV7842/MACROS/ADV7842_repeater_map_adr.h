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
* DATE: 18 Nov 2009 15:43:14                                                   *
*                                                                              *
*******************************************************************************/


#ifndef ADV7842_REPEATER_MAP_ADR_H
#define ADV7842_REPEATER_MAP_ADR_H

#define VRX_REG_BKSV_1                                      0x00

#define VRX_REG_BKSV_2                                      0x01

#define VRX_REG_BKSV_3                                      0x02

#define VRX_REG_BKSV_4                                      0x03

#define VRX_REG_BKSV_5                                      0x04

#define VRX_REG_RI_1                                        0x08

#define VRX_REG_RI_2                                        0x09

#define VRX_REG_PJ                                          0x0A

#define VRX_REG_AKSV_1                                      0x10

#define VRX_REG_AKSV_2                                      0x11

#define VRX_REG_AKSV_3                                      0x12

#define VRX_REG_AKSV_4                                      0x13

#define VRX_REG_AKSV_5                                      0x14

#define VRX_REG_AINFO                                       0x15

#define VRX_REG_AN_1                                        0x18

#define VRX_REG_AN_2                                        0x19

#define VRX_REG_AN_3                                        0x1A

#define VRX_REG_AN_4                                        0x1B

#define VRX_REG_AN_5                                        0x1C

#define VRX_REG_AN_6                                        0x1D

#define VRX_REG_AN_7                                        0x1E

#define VRX_REG_AN_8                                        0x1F

#define VRX_REG_SHA_A_1                                     0x20

#define VRX_REG_SHA_A_2                                     0x21

#define VRX_REG_SHA_A_3                                     0x22

#define VRX_REG_SHA_A_4                                     0x23

#define VRX_REG_SHA_B_1                                     0x24

#define VRX_REG_SHA_B_2                                     0x25

#define VRX_REG_SHA_B_3                                     0x26

#define VRX_REG_SHA_B_4                                     0x27

#define VRX_REG_SHA_C_1                                     0x28

#define VRX_REG_SHA_C_2                                     0x29

#define VRX_REG_SHA_C_3                                     0x2A

#define VRX_REG_SHA_C_4                                     0x2B

#define VRX_REG_SHA_D_1                                     0x2C

#define VRX_REG_SHA_D_2                                     0x2D

#define VRX_REG_SHA_D_3                                     0x2E

#define VRX_REG_SHA_D_4                                     0x2F

#define VRX_REG_SHA_E_1                                     0x30

#define VRX_REG_SHA_E_2                                     0x31

#define VRX_REG_SHA_E_3                                     0x32

#define VRX_REG_SHA_E_4                                     0x33

#define VRX_REG_BCAPS                                       0x40

#define VRX_REG_BSTATUS_1                                   0x41

#define VRX_REG_BSTATUS_2                                   0x42

#define VRX_REG_SPA_PORT_C_1                                0x72

#define VRX_REG_SPA_PORT_C_2                                0x73

#define VRX_REG_SPA_PORT_D_1                                0x74

#define VRX_REG_SPA_PORT_D_2                                0x75

#define VRX_REG_SPA_LOCATION                                0x76

#define VRX_REG_HDCP_EDID_CONTROLS                          0x77
#define VRX_BIT_KSV_LIST_READY                              0x80
#define VRX_BIT_SPA_LOCATION_MSB                            0x40
#define VRX_BIT_DISABLE_AUTO_EDID                           0x20
#define VRX_BIT_EDID_SEGMENT_POINTER                        0x10
#define VRX_BIT_EDID_B_ENABLE                               0x08
#define VRX_BIT_EDID_A_ENABLE                               0x04

#define VRX_REG_IROM_BIST                                   0x78
#define VRX_BIT_EXT_EEPROM_TRI                              0x40

#define VRX_BIT_VGA_EDID_ENABLE_CPU                         0x20

#define VRX_REG_PORT_C_CHECKSUM                             0x7B

#define VRX_REG_PORT_D_CHECKSUM                             0x7C

#define VRX_REG_EDID_DEBUG                                  0x7D
#define VRX_BIT_EDID_B_ENABLE_CPU                           0x08
#define VRX_BIT_EDID_A_ENABLE_CPU                           0x04

#define VRX_BIT_VGA_EDID_ENABLE                             0x80
#define VRX_BIT_AUTO_HDCP_MAP_ENABLE                        0x04

#define VRX_REG_KSV_0_1                                     0x80

#define VRX_REG_KSV_0_2                                     0x81

#define VRX_REG_KSV_0_3                                     0x82

#define VRX_REG_KSV_0_4                                     0x83

#define VRX_REG_KSV_0_5                                     0x84

#define VRX_REG_KSV_1_1                                     0x85

#define VRX_REG_KSV_1_2                                     0x86

#define VRX_REG_KSV_1_3                                     0x87

#define VRX_REG_KSV_1_4                                     0x88

#define VRX_REG_KSV_1_5                                     0x89

#define VRX_REG_KSV_2_1                                     0x8A

#define VRX_REG_KSV_2_2                                     0x8B

#define VRX_REG_KSV_2_3                                     0x8C

#define VRX_REG_KSV_2_4                                     0x8D

#define VRX_REG_KSV_2_5                                     0x8E

#define VRX_REG_KSV_3_1                                     0x8F

#define VRX_REG_KSV_3_2                                     0x90

#define VRX_REG_KSV_3_3                                     0x91

#define VRX_REG_KSV_3_4                                     0x92

#define VRX_REG_KSV_3_5                                     0x93

#define VRX_REG_KSV_4_1                                     0x94

#define VRX_REG_KSV_4_2                                     0x95

#define VRX_REG_KSV_4_3                                     0x96

#define VRX_REG_KSV_4_4                                     0x97

#define VRX_REG_KSV_4_5                                     0x98

#define VRX_REG_KSV_5_1                                     0x99

#define VRX_REG_KSV_5_2                                     0x9A

#define VRX_REG_KSV_5_3                                     0x9B

#define VRX_REG_KSV_5_4                                     0x9C

#define VRX_REG_KSV_5_5                                     0x9D

#define VRX_REG_KSV_6_1                                     0x9E

#define VRX_REG_KSV_6_2                                     0x9F

#define VRX_REG_KSV_6_3                                     0xA0

#define VRX_REG_KSV_6_4                                     0xA1

#define VRX_REG_KSV_6_5                                     0xA2

#define VRX_REG_KSV_7_1                                     0xA3

#define VRX_REG_KSV_7_2                                     0xA4

#define VRX_REG_KSV_7_3                                     0xA5

#define VRX_REG_KSV_7_4                                     0xA6

#define VRX_REG_KSV_7_5                                     0xA7

#define VRX_REG_KSV_8_1                                     0xA8

#define VRX_REG_KSV_8_2                                     0xA9

#define VRX_REG_KSV_8_3                                     0xAA

#define VRX_REG_KSV_8_4                                     0xAB

#define VRX_REG_KSV_8_5                                     0xAC

#define VRX_REG_KSV_9_1                                     0xAD

#define VRX_REG_KSV_9_2                                     0xAE

#define VRX_REG_KSV_9_3                                     0xAF

#define VRX_REG_KSV_9_4                                     0xB0

#define VRX_REG_KSV_9_5                                     0xB1

#define VRX_REG_KSV_10_1                                    0xB2

#define VRX_REG_KSV_10_2                                    0xB3

#define VRX_REG_KSV_10_3                                    0xB4

#define VRX_REG_KSV_10_4                                    0xB5

#define VRX_REG_KSV_10_5                                    0xB6

#define VRX_REG_KSV_11_1                                    0xB7

#define VRX_REG_KSV_11_2                                    0xB8

#define VRX_REG_KSV_11_3                                    0xB9

#define VRX_REG_KSV_11_4                                    0xBA

#define VRX_REG_KSV_11_5                                    0xBB

#define VRX_REG_KSV_12_1                                    0xBC

#define VRX_REG_KSV_12_2                                    0xBD

#define VRX_REG_KSV_12_3                                    0xBE

#define VRX_REG_KSV_12_4                                    0xBF

#define VRX_REG_KSV_12_5                                    0xC0

#define VRX_REG_KSV_13_1                                    0xC1

#define VRX_REG_KSV_13_2                                    0xC2

#define VRX_REG_KSV_13_3                                    0xC3

#define VRX_REG_KSV_13_4                                    0xC4

#define VRX_REG_KSV_13_5                                    0xC5

#define VRX_REG_KSV_14_1                                    0xC6

#define VRX_REG_KSV_14_2                                    0xC7

#define VRX_REG_KSV_14_3                                    0xC8

#define VRX_REG_KSV_14_4                                    0xC9

#define VRX_REG_KSV_14_5                                    0xCA

#define VRX_REG_KSV_15_1                                    0xCB

#define VRX_REG_KSV_15_2                                    0xCC

#define VRX_REG_KSV_15_3                                    0xCD

#define VRX_REG_KSV_15_4                                    0xCE

#define VRX_REG_KSV_15_5                                    0xCF

#define VRX_REG_KSV_16_1                                    0xD0

#define VRX_REG_KSV_16_2                                    0xD1

#define VRX_REG_KSV_16_3                                    0xD2

#define VRX_REG_KSV_16_4                                    0xD3

#define VRX_REG_KSV_16_5                                    0xD4

#define VRX_REG_KSV_17_1                                    0xD5

#define VRX_REG_KSV_17_2                                    0xD6

#define VRX_REG_KSV_17_3                                    0xD7

#define VRX_REG_KSV_17_4                                    0xD8

#define VRX_REG_KSV_17_5                                    0xD9

#define VRX_REG_KSV_18_1                                    0xDA

#define VRX_REG_KSV_18_2                                    0xDB

#define VRX_REG_KSV_18_3                                    0xDC

#define VRX_REG_KSV_18_4                                    0xDD

#define VRX_REG_KSV_18_5                                    0xDE

#define VRX_REG_KSV_19_1                                    0xDF

#define VRX_REG_KSV_19_2                                    0xE0

#define VRX_REG_KSV_19_3                                    0xE1

#define VRX_REG_KSV_19_4                                    0xE2

#define VRX_REG_KSV_19_5                                    0xE3

#define VRX_REG_KSV_20_1                                    0xE4

#define VRX_REG_KSV_20_2                                    0xE5

#define VRX_REG_KSV_20_3                                    0xE6

#define VRX_REG_KSV_20_4                                    0xE7

#define VRX_REG_KSV_20_5                                    0xE8

#define VRX_REG_KSV_21_1                                    0xE9

#define VRX_REG_KSV_21_2                                    0xEA

#define VRX_REG_KSV_21_3                                    0xEB

#define VRX_REG_KSV_21_4                                    0xEC

#define VRX_REG_KSV_21_5                                    0xED

#define VRX_REG_KSV_22_1                                    0xEE

#define VRX_REG_KSV_22_2                                    0xEF

#define VRX_REG_KSV_22_3                                    0xF0

#define VRX_REG_KSV_22_4                                    0xF1

#define VRX_REG_KSV_22_5                                    0xF2

#define VRX_REG_KSV_23_1                                    0xF3

#define VRX_REG_KSV_23_2                                    0xF4

#define VRX_REG_KSV_23_3                                    0xF5

#define VRX_REG_KSV_23_4                                    0xF6

#define VRX_REG_KSV_23_5                                    0xF7


#endif
