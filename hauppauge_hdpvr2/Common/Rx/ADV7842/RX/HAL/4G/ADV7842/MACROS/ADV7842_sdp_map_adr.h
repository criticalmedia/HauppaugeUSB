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
* DATE: 18 Nov 2009 15:43:8                                                    *
*                                                                              *
*******************************************************************************/


#ifndef ADV7842_SDP_MAP_ADR_H
#define ADV7842_SDP_MAP_ADR_H

#define VRX_REG_AUTODETECT_ENABLES                          0x00
#define VRX_BIT_SDP_AD_SECAM_EN                             0x40
#define VRX_BIT_SDP_AD_N443_EN                              0x20
#define VRX_BIT_SDP_AD_PAL60_EN                             0x10
#define VRX_BIT_SDP_AD_PALCN_EN                             0x08
#define VRX_BIT_SDP_AD_PALM_EN                              0x04
#define VRX_BIT_SDP_AD_NTSC_EN                              0x02
#define VRX_BIT_SDP_AD_PAL_EN                               0x01

#define VRX_REG_PEDESTAL_SELECTION                          0x01
#define VRX_BIT_SDP_SECAM_PED_EN                            0x40
#define VRX_BIT_SDP_N443_PED_EN                             0x20
#define VRX_BIT_SDP_PAL60_PED_EN                            0x10
#define VRX_BIT_SDP_PALCN_PED_EN                            0x08
#define VRX_BIT_SDP_PALM_PED_EN                             0x04
#define VRX_BIT_SDP_NTSC_PED_EN                             0x02
#define VRX_BIT_SDP_PAL_PED_EN                              0x01

#define VRX_REG_COLOUR_KILL_CONTROL                         0x02
#define VRX_BIT_SDP_CR_MODE_EN                              0x40

#define VRX_REG_LUMA_GAIN_1                                 0x03
#define VRX_BIT_SDP_Y_AGC_EN                                0x80
#define VRX_BIT_SDP_PW_EN                                   0x40
#define VRX_BIT_SDP_MAN_GAIN_VCR                            0x20

#define VRX_REG_LUMA_GAIN_2                                 0x04

#define VRX_REG_CHROMA_GAIN_1                               0x05
#define VRX_BIT_SDP_C_AGC_EN                                0x80
#define VRX_BIT_SDP_PC_EN                                   0x40

#define VRX_REG_CHROMA_GAIN_2                               0x06

#define VRX_REG_COLOUR_KILL_ON_LEVEL                        0x07
#define VRX_BIT_SDP_CKILL_EN                                0x80

#define VRX_REG_COLOUR_KILL_OFF_LEVEL                       0x08

#define VRX_REG_LUMA_GAIN_SPEED                             0x0A

#define VRX_REG_CHROMA_GAIN_SPEED                           0x0B

#define VRX_REG_DIGITAL_CLAMP_SPEED                         0x0C

#define VRX_REG_ANALOGUE_CLAMP_SPEED                        0x0D

#define VRX_REG_VIDEO_ENHANCEMENTS                          0x0E
#define VRX_BIT_SDP_SCM_CTI_EN                              0x20
#define VRX_BIT_SDP_Y_2D_PK_EN                              0x10
#define VRX_BIT_SDP_V_PK_EN                                 0x08
#define VRX_BIT_SDP_H_PK_EN                                 0x04
#define VRX_BIT_SDP_LTI_EN                                  0x02
#define VRX_BIT_SDP_CTI_EN                                  0x01

#define VRX_REG_GAIN_RECOVERY_SPEED_1                       0x0F

#define VRX_REG_GAIN_RECOVERY_SPEED_2                       0x10

#define VRX_REG_GAIN_RECOVERY_SPEED_3                       0x11

#define VRX_REG_3D_ENABLES                                  0x12
#define VRX_BIT_SDP_SHIP_EN                                 0x08
#define VRX_BIT_SDP_FR_TBC_EN                               0x04
#define VRX_BIT_SDP_3D_COMB_EN                              0x01

#define VRX_REG_CONTRAST                                    0x13

#define VRX_REG_BRIGHTNESS                                  0x14

#define VRX_REG_SATURATION                                  0x15

#define VRX_REG_HUE_TINT_1                                  0x16

#define VRX_REG_HUE_TINT_2                                  0x17

#define VRX_REG_Y_SHAPING_FILTER_1                          0x18
#define VRX_BIT_SDP_BLANK_C_VBI                             0x80
#define VRX_BIT_SDP_FORCE_CKILL_HQI                         0x40

#define VRX_REG_Y_SHAPING_FILTER_2                          0x19
#define VRX_BIT_SDP_Y_SHAPE_AUTO_EN                         0x80
#define VRX_BIT_SDP_FORCE_COMP_HQI                          0x40

#define VRX_REG_Y_SHAPING_FILTER_3                          0x1A
#define VRX_BIT_SDP_HQI_REQ_STD                             0x80

#define VRX_REG_Y_SHAPING_FILTER_4                          0x1B

#define VRX_REG_C_SHAPING_FILTER_1                          0x1C
#define VRX_BIT_SDP_C_SHAPE_AUTO_EN                         0x80
#define VRX_BIT_SDP_CSH_WBW_AUTO                            0x40

#define VRX_REG_C_SHAPING_FILTER_2                          0x1D

#define VRX_REG_C_SHAPING_FILTER_3                          0x1E

#define VRX_REG_COMB_SPLIT_FILTER                           0x1F

#define VRX_REG_C_IF_FILTER                                 0x20

#define VRX_REG_DELAY_LINE                                  0x21
#define VRX_BIT_SDP_U_DEL_LINE_EN                           0x80
#define VRX_BIT_SDP_V_DEL_LINE_EN                           0x40

#define VRX_REG_HORIZONTAL_PEAKING                          0x22
#define VRX_BIT_SDP_H_PK_INV                                0x80

#define VRX_REG_VERTICAL_PEAKING                            0x23
#define VRX_BIT_SDP_V_PK_INV                                0x80

#define VRX_REG_H_V_PEAKING                                 0x24

#define VRX_REG_LTI                                         0x25
#define VRX_BIT_SDP_LTI_FILT_SEL                            0x80

#define VRX_REG_CTI                                         0x26
#define VRX_BIT_SDP_CTI_FILT_SEL                            0x80

#define VRX_REG_LTI_CTI                                     0x27

#define VRX_REG_SECAM_CTI                                   0x28

#define VRX_REG_RGB_FB_DELAY_ADJUST                         0x2A
#define VRX_BIT_SDP_MAN_FB                                  0x80
#define VRX_BIT_SDP_MAN_FB_EN                               0x08

#define VRX_REG_LINE_TBC                                    0x34
#define VRX_BIT_SDP_TBC_EN                                  0x80

#define VRX_REG_STATUS_LETTERBOX_TOP                        0x4C

#define VRX_REG_STATUS_LETTERBOX_BOTTOM                     0x4D

#define VRX_REG_STATUS_LETTERBOX_SUBTITLES_BOTTOM           0x4E

#define VRX_REG_STATUS_NOISE_LEVEL_LSBS                     0x4F

#define VRX_REG_STATUS_MACROVISION_DETECTION_1              0x50
#define VRX_BIT_SDP_MV_AGC_DETECTED                         0x08
#define VRX_BIT_SDP_MV_PS_DETECTED                          0x04
#define VRX_BIT_SDP_MVCS_TYPE3                              0x02
#define VRX_BIT_SDP_MVCS_DETECT                             0x01

#define VRX_REG_STATUS_MACROVISION_DETECTION_2              0x51

#define VRX_REG_STATUS_ACTIVE_STANDARD                      0x52

#define VRX_REG_STATUS_NOISE_LEVEL_MSBS                     0x53

#define VRX_REG_STATUS_LUMA_GAIN_1                          0x54
#define VRX_BIT_SDP_NOISY_IP                                0x80
#define VRX_BIT_SDP_VERY_NOISY_IP                           0x40
#define VRX_BIT_SDP_C_CHAN_ACTIVE                           0x20

#define VRX_REG_STATUS_LUMA_GAIN_2                          0x55

#define VRX_REG_SDP_STATUS_INPUT_TYPE_1                     0x56
#define VRX_BIT_SDP_HSWITCH_PRESENT                         0x80
#define VRX_BIT_SDP_BLK_NSTD                                0x40
#define VRX_BIT_SDP_FLD_NSTD                                0x20
#define VRX_BIT_SDP_FRM_NSTD                                0x10
#define VRX_BIT_SDP_LC_NSTD                                 0x08
#define VRX_BIT_SDP_ALLOW_MED_PLL                           0x04
#define VRX_BIT_SDP_ALLOW_SLOW_PLL                          0x02
#define VRX_BIT_SDP_FREE_RUN                                0x01

#define VRX_REG_SDP_STATUS_INPUT_TYPE_2                     0x57
#define VRX_BIT_SDP_CKILL_ACT                               0x80
#define VRX_BIT_SDP_VS_STD_MODE                             0x40
#define VRX_BIT_SDP_ALLOW_3D_COMB                           0x10
#define VRX_BIT_SDP_INTERLACED                              0x08
#define VRX_BIT_SDP_TRICK_MODE                              0x04

#define VRX_REG_STATUS_PR_SD_DETECTION                      0x58
#define VRX_BIT_SDP_SD_DETECTED_IN_PR                       0x80
#define VRX_BIT_SDP_PR_DETECTED_IN_SD                       0x40

#define VRX_REG_STATUS_BURST_LOCKING                        0x59
#define VRX_BIT_SDP_BURST_LOCKED_RB                         0x80
#define VRX_BIT_SDP_AD_50_60_HZ                             0x08
#define VRX_BIT_SDP_PAL_SW_LOCKED                           0x04
#define VRX_BIT_SDP_FSC_FREQ_OK                             0x02
#define VRX_BIT_SDP_SCM_LOCKED                              0x01

#define VRX_REG_STATUS_INPUT_TYPE_3                         0x5A
#define VRX_BIT_SDP_VIDEO_DETECTED                          0x01

#define VRX_REG_SYNC_DETECTION_PARAMETERS_4                 0x7B
#define VRX_BIT_SDP_EXTEND_VS_MAX_FREQ                      0x04
#define VRX_BIT_SDP_EXTEND_VS_MIN_FREQ                      0x02

#define VRX_REG_LUMA_AGC_TARGET_1                           0x89
#define VRX_BIT_SDP_LIMIT_Y_GAIN                            0x80
#define VRX_BIT_SDP_LIMIT_C_GAIN                            0x40
#define VRX_BIT_SDP_LIMIT_UV_GAIN                           0x20
#define VRX_BIT_SDP_LIMIT_G_GAIN                            0x10

#define VRX_REG_HQI_SHAPING_FILTER_DISABLE                  0x98
#define VRX_BIT_SDP_NSY_DIS_SFS_STD                         0x80
#define VRX_BIT_SDP_HSW2_DIS_SFS_STD                        0x40
#define VRX_BIT_SDP_HSW1_DIS_SFS_STD                        0x20
#define VRX_BIT_SDP_LC_DIS_SFS_STD                          0x10
#define VRX_BIT_SDP_BLK_DIS_SFS_STD                         0x08
#define VRX_BIT_SDP_FLD_SFS_STD                             0x04
#define VRX_BIT_SDP_FRM_DIS_SFS_STD                         0x02
#define VRX_BIT_SDP_VNSY_DIS_SFS_STD                        0x01

#define VRX_REG_DETECTION_FILTERING_1                       0x99

#define VRX_REG_DETECTION_FILTERING_2                       0x9A

#define VRX_REG_NOISY_THRESHOLD                             0xA1

#define VRX_REG_VERY_NOISY_THRESHOLD                        0xA2

#define VRX_REG_3D_COMB_DISABLE_CLEAN                       0xA3
#define VRX_BIT_SDP_CKILL_DIS_3D                            0x80

#define VRX_REG_3D_COMB_DISABLE_NOISY                       0xA4
#define VRX_BIT_SDP_CKILL_DIS_2D                            0x80
#define VRX_BIT_SDP_NOISY_HSW2_DIS_3D                       0x40
#define VRX_BIT_SDP_NOISY_HSW1_DIS_3D                       0x20
#define VRX_BIT_SDP_NOISY_LC_DIS_3D                         0x10
#define VRX_BIT_SDP_NOISY_BLK_DIS_3D                        0x08
#define VRX_BIT_SDP_NOISY_FLD_DIS_3D                        0x04
#define VRX_BIT_SDP_NOISY_FRM_DIS_3D                        0x02
#define VRX_BIT_SDP_NOISY_DIS_3D                            0x01

#define VRX_REG_3D_COMB_DISABLE_VERY_NOISY                  0xA5
#define VRX_BIT_SDP_P60_N443_DIS_3D                         0x80
#define VRX_BIT_SDP_VNOISY_HSW2_DIS_3D                      0x40
#define VRX_BIT_SDP_VNOISY_HSW1_DIS_3D                      0x20
#define VRX_BIT_SDP_VNOISY_LC_DIS_3D                        0x10
#define VRX_BIT_SDP_VNOISY_BLK_DIS_3D                       0x08
#define VRX_BIT_SDP_VNOISY_FLD_DIS_3D                       0x04
#define VRX_BIT_SDP_VNOISY_FRM_DIS_3D                       0x02
#define VRX_BIT_SDP_VNOISY_DIS_3D                           0x01

#define VRX_REG_3D_COMB_NOISE_SENSITIVITY                   0xA8

#define VRX_REG_3D_COMB_CHROMA_SENSITIVITY                  0xA9

#define VRX_REG_3D_COMB_LUMA_SENSITIVITY                    0xAA

#define VRX_REG_OP_SPL_1                                    0xD9
#define VRX_BIT_SDP_SHIP_INT_EN                             0x40

#define VRX_REG_LETTERBOX_DETECT_1                          0xDB

#define VRX_REG_LETTERBOX_DETECT_2                          0xDC

#define VRX_REG_SDP_FREE_RUN                                0xDD
#define VRX_BIT_SDP_FREE_RUN_AUTO                           0x08
#define VRX_BIT_SDP_FREE_RUN_MAN_COL_EN                     0x04
#define VRX_BIT_SDP_FREE_RUN_CBAR_EN                        0x02
#define VRX_BIT_SDP_FORCE_FREE_RUN                          0x01

#define VRX_REG_SDP_FREE_RUN_Y                              0xDE

#define VRX_REG_SDP_FREE_RUN_C                              0xDF


#endif
