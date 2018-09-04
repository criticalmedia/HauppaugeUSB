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


#ifndef ADV7842_SDP_MAP_DEF_H
#define ADV7842_SDP_MAP_DEF_H

#define VRX_FIELD_SDP_AD_SECAM_EN_DEF                       0x0
#define VRX_FIELD_SDP_AD_SECAM_EN_BIT_SIZE                  1

#define VRX_FIELD_SDP_AD_N443_EN_DEF                        0x0
#define VRX_FIELD_SDP_AD_N443_EN_BIT_SIZE                   1

#define VRX_FIELD_SDP_AD_PAL60_EN_DEF                       0x0
#define VRX_FIELD_SDP_AD_PAL60_EN_BIT_SIZE                  1

#define VRX_FIELD_SDP_AD_PALCN_EN_DEF                       0x0
#define VRX_FIELD_SDP_AD_PALCN_EN_BIT_SIZE                  1

#define VRX_FIELD_SDP_AD_PALM_EN_DEF                        0x0
#define VRX_FIELD_SDP_AD_PALM_EN_BIT_SIZE                   1

#define VRX_FIELD_SDP_AD_NTSC_EN_DEF                        0x1
#define VRX_FIELD_SDP_AD_NTSC_EN_BIT_SIZE                   1

#define VRX_FIELD_SDP_AD_PAL_EN_DEF                         0x0
#define VRX_FIELD_SDP_AD_PAL_EN_BIT_SIZE                    1

#define VRX_FIELD_SDP_SECAM_PED_EN_DEF                      0x0
#define VRX_FIELD_SDP_SECAM_PED_EN_BIT_SIZE                 1

#define VRX_FIELD_SDP_N443_PED_EN_DEF                       0x1
#define VRX_FIELD_SDP_N443_PED_EN_BIT_SIZE                  1

#define VRX_FIELD_SDP_PAL60_PED_EN_DEF                      0x1
#define VRX_FIELD_SDP_PAL60_PED_EN_BIT_SIZE                 1

#define VRX_FIELD_SDP_PALCN_PED_EN_DEF                      0x0
#define VRX_FIELD_SDP_PALCN_PED_EN_BIT_SIZE                 1

#define VRX_FIELD_SDP_PALM_PED_EN_DEF                       0x1
#define VRX_FIELD_SDP_PALM_PED_EN_BIT_SIZE                  1

#define VRX_FIELD_SDP_NTSC_PED_EN_DEF                       0x1
#define VRX_FIELD_SDP_NTSC_PED_EN_BIT_SIZE                  1

#define VRX_FIELD_SDP_PAL_PED_EN_DEF                        0x0
#define VRX_FIELD_SDP_PAL_PED_EN_BIT_SIZE                   1

#define VRX_REG_SDP_02H_DEF                                 0x27
#define VRX_FIELD_SDP_CR_MODE_EN_DEF                        0x0
#define VRX_FIELD_SDP_CR_MODE_EN_BIT_SIZE                   1

#define VRX_REG_SDP_03H_DEF                                 0xC4
#define VRX_FIELD_SDP_Y_AGC_EN_DEF                          0x1
#define VRX_FIELD_SDP_Y_AGC_EN_BIT_SIZE                     1

#define VRX_FIELD_SDP_PW_EN_DEF                             0x1
#define VRX_FIELD_SDP_PW_EN_BIT_SIZE                        1

#define VRX_FIELD_SDP_MAN_GAIN_VCR_DEF                      0x0
#define VRX_FIELD_SDP_MAN_GAIN_VCR_BIT_SIZE                 1

#define VRX_REG_SDP_04H_DEF                                 0x0B
#define VRX_FIELD_SDP_Y_GAIN_MAN_DEF                        0x40b
#define VRX_FIELD_SDP_Y_GAIN_MAN_BIT_SIZE                   13

#define VRX_REG_SDP_05H_DEF                                 0xC3
#define VRX_FIELD_SDP_C_AGC_EN_DEF                          0x1
#define VRX_FIELD_SDP_C_AGC_EN_BIT_SIZE                     1

#define VRX_FIELD_SDP_PC_EN_DEF                             0x1
#define VRX_FIELD_SDP_PC_EN_BIT_SIZE                        1

#define VRX_REG_SDP_06H_DEF                                 0xC0
#define VRX_FIELD_SDP_C_GAIN_ACT_MAN_DEF                    0x3c0
#define VRX_FIELD_SDP_C_GAIN_ACT_MAN_BIT_SIZE               13

#define VRX_REG_SDP_07H_DEF                                 0x8B
#define VRX_FIELD_SDP_CKILL_EN_DEF                          0x1
#define VRX_FIELD_SDP_CKILL_EN_BIT_SIZE                     1

#define VRX_FIELD_SDP_CK_LOW_THR_DEF                        0xb
#define VRX_FIELD_SDP_CK_LOW_THR_BIT_SIZE                   7

#define VRX_REG_SDP_08H_DEF                                 0x1A
#define VRX_FIELD_SDP_CK_HIGH_THR_DEF                       0x1a
#define VRX_FIELD_SDP_CK_HIGH_THR_BIT_SIZE                  8

#define VRX_REG_SDP_0AH_DEF                                 0xE5
#define VRX_FIELD_SDP_DGAIN_SPEED_DEF                       0x5
#define VRX_FIELD_SDP_DGAIN_SPEED_BIT_SIZE                  5

#define VRX_REG_SDP_0BH_DEF                                 0xE5
#define VRX_FIELD_SDP_C_DGAIN_SPEED_DEF                     0x5
#define VRX_FIELD_SDP_C_DGAIN_SPEED_BIT_SIZE                5

#define VRX_REG_SDP_0CH_DEF                                 0xE5
#define VRX_FIELD_SDP_DCLP_SPEED_DEF                        0x5
#define VRX_FIELD_SDP_DCLP_SPEED_BIT_SIZE                   5

#define VRX_REG_SDP_0DH_DEF                                 0xE4
#define VRX_FIELD_SDP_ACLP_SPEED_DEF                        0x4
#define VRX_FIELD_SDP_ACLP_SPEED_BIT_SIZE                   5

#define VRX_REG_SDP_0EH_DEF                                 0x31
#define VRX_FIELD_SDP_SCM_CTI_EN_DEF                        0x1
#define VRX_FIELD_SDP_SCM_CTI_EN_BIT_SIZE                   1

#define VRX_FIELD_SDP_Y_2D_PK_EN_DEF                        0x1
#define VRX_FIELD_SDP_Y_2D_PK_EN_BIT_SIZE                   1

#define VRX_FIELD_SDP_V_PK_EN_DEF                           0x0
#define VRX_FIELD_SDP_V_PK_EN_BIT_SIZE                      1

#define VRX_FIELD_SDP_H_PK_EN_DEF                           0x0
#define VRX_FIELD_SDP_H_PK_EN_BIT_SIZE                      1

#define VRX_FIELD_SDP_LTI_EN_DEF                            0x0
#define VRX_FIELD_SDP_LTI_EN_BIT_SIZE                       1

#define VRX_FIELD_SDP_CTI_EN_DEF                            0x1
#define VRX_FIELD_SDP_CTI_EN_BIT_SIZE                       1

#define VRX_REG_SDP_0FH_DEF                                 0x00
#define VRX_REG_SDP_11H_DEF                                 0x10
#define VRX_FIELD_SDP_PC_REC_RATE_DEF                       0x10
#define VRX_FIELD_SDP_PC_REC_RATE_BIT_SIZE                  12

#define VRX_REG_SDP_10H_DEF                                 0x01
#define VRX_FIELD_SDP_PW_REC_RATE_DEF                       0x1
#define VRX_FIELD_SDP_PW_REC_RATE_BIT_SIZE                  12

#define VRX_REG_SDP_12H_DEF                                 0x01
#define VRX_FIELD_SDP_SHIP_EN_DEF                           0x0
#define VRX_FIELD_SDP_SHIP_EN_BIT_SIZE                      1

#define VRX_FIELD_SDP_FR_TBC_EN_DEF                         0x0
#define VRX_FIELD_SDP_FR_TBC_EN_BIT_SIZE                    1

#define VRX_FIELD_SDP_3D_COMB_EN_DEF                        0x1
#define VRX_FIELD_SDP_3D_COMB_EN_BIT_SIZE                   1

#define VRX_REG_SDP_13H_DEF                                 0x80
#define VRX_REG_SDP_17H_DEF                                 0x00
#define VRX_FIELD_SDP_CONTRAST_DEF                          0x200
#define VRX_FIELD_SDP_CONTRAST_BIT_SIZE                     10

#define VRX_REG_SDP_14H_DEF                                 0x00
#define VRX_FIELD_SDP_BRIGHTNESS_DEF                        0x0
#define VRX_FIELD_SDP_BRIGHTNESS_BIT_SIZE                   10

#define VRX_REG_SDP_15H_DEF                                 0x80
#define VRX_FIELD_SDP_SATURATION_DEF                        0x200
#define VRX_FIELD_SDP_SATURATION_BIT_SIZE                   10

#define VRX_REG_SDP_16H_DEF                                 0x00
#define VRX_FIELD_SDP_HUE_DEF                               0x0
#define VRX_FIELD_SDP_HUE_BIT_SIZE                          10

#define VRX_REG_SDP_18H_DEF                                 0xFF
#define VRX_FIELD_SDP_BLANK_C_VBI_DEF                       0x1
#define VRX_FIELD_SDP_BLANK_C_VBI_BIT_SIZE                  1

#define VRX_FIELD_SDP_FORCE_CKILL_HQI_DEF                   0x1
#define VRX_FIELD_SDP_FORCE_CKILL_HQI_BIT_SIZE              1

#define VRX_FIELD_SDP_Y_SHAPE_SEL_VBI_DEF                   0x3f
#define VRX_FIELD_SDP_Y_SHAPE_SEL_VBI_BIT_SIZE              6

#define VRX_REG_SDP_19H_DEF                                 0xCD
#define VRX_FIELD_SDP_Y_SHAPE_AUTO_EN_DEF                   0x1
#define VRX_FIELD_SDP_Y_SHAPE_AUTO_EN_BIT_SIZE              1

#define VRX_FIELD_SDP_FORCE_COMP_HQI_DEF                    0x1
#define VRX_FIELD_SDP_FORCE_COMP_HQI_BIT_SIZE               1

#define VRX_FIELD_SDP_Y_SHAPE_SEL_HQI_DEF                   0xd
#define VRX_FIELD_SDP_Y_SHAPE_SEL_HQI_BIT_SIZE              6

#define VRX_REG_SDP_1AH_DEF                                 0x95
#define VRX_FIELD_SDP_HQI_REQ_STD_DEF                       0x1
#define VRX_FIELD_SDP_HQI_REQ_STD_BIT_SIZE                  1

#define VRX_FIELD_SDP_Y_SHAPE_SEL_LQI_DEF                   0x15
#define VRX_FIELD_SDP_Y_SHAPE_SEL_LQI_BIT_SIZE              6

#define VRX_REG_SDP_1BH_DEF                                 0x1E
#define VRX_FIELD_SDP_Y_SHAPE_SEL_SCM_DEF                   0x1e
#define VRX_FIELD_SDP_Y_SHAPE_SEL_SCM_BIT_SIZE              6

#define VRX_REG_SDP_1CH_DEF                                 0xC4
#define VRX_FIELD_SDP_C_SHAPE_AUTO_EN_DEF                   0x1
#define VRX_FIELD_SDP_C_SHAPE_AUTO_EN_BIT_SIZE              1

#define VRX_FIELD_SDP_CSH_WBW_AUTO_DEF                      0x1
#define VRX_FIELD_SDP_CSH_WBW_AUTO_BIT_SIZE                 1

#define VRX_FIELD_SDP_C_SHAPE_SEL_HQI_DEF                   0x4
#define VRX_FIELD_SDP_C_SHAPE_SEL_HQI_BIT_SIZE              5

#define VRX_REG_SDP_1DH_DEF                                 0x02
#define VRX_FIELD_SDP_C_SHAPE_SEL_LQI_DEF                   0x2
#define VRX_FIELD_SDP_C_SHAPE_SEL_LQI_BIT_SIZE              5

#define VRX_REG_SDP_1EH_DEF                                 0x04
#define VRX_FIELD_SDP_C_SHAPE_SEL_SCM_DEF                   0x4
#define VRX_FIELD_SDP_C_SHAPE_SEL_SCM_BIT_SIZE              5

#define VRX_REG_SDP_1FH_DEF                                 0x12
#define VRX_FIELD_SDP_SPLIT_FILTER_SEL_DEF                  0x12
#define VRX_FIELD_SDP_SPLIT_FILTER_SEL_BIT_SIZE             5

#define VRX_REG_SDP_20H_DEF                                 0x00
#define VRX_FIELD_SDP_IF_FILT_SEL_DEF                       0x0
#define VRX_FIELD_SDP_IF_FILT_SEL_BIT_SIZE                  5

#define VRX_REG_SDP_21H_DEF                                 0xFF
#define VRX_FIELD_SDP_U_DEL_LINE_EN_DEF                     0x1
#define VRX_FIELD_SDP_U_DEL_LINE_EN_BIT_SIZE                1

#define VRX_FIELD_SDP_V_DEL_LINE_EN_DEF                     0x1
#define VRX_FIELD_SDP_V_DEL_LINE_EN_BIT_SIZE                1

#define VRX_REG_SDP_22H_DEF                                 0x20
#define VRX_FIELD_SDP_H_PK_INV_DEF                          0x0
#define VRX_FIELD_SDP_H_PK_INV_BIT_SIZE                     1

#define VRX_FIELD_SDP_H_PK_GAIN_DEF                         0x4
#define VRX_FIELD_SDP_H_PK_GAIN_BIT_SIZE                    4

#define VRX_FIELD_SDP_H_PK_CORE_DEF                         0x0
#define VRX_FIELD_SDP_H_PK_CORE_BIT_SIZE                    3

#define VRX_REG_SDP_23H_DEF                                 0x10
#define VRX_FIELD_SDP_V_PK_INV_DEF                          0x0
#define VRX_FIELD_SDP_V_PK_INV_BIT_SIZE                     1

#define VRX_FIELD_SDP_V_PK_GAIN_DEF                         0x2
#define VRX_FIELD_SDP_V_PK_GAIN_BIT_SIZE                    4

#define VRX_FIELD_SDP_V_PK_CORE_DEF                         0x0
#define VRX_FIELD_SDP_V_PK_CORE_BIT_SIZE                    3

#define VRX_REG_SDP_24H_DEF                                 0x4C
#define VRX_FIELD_SDP_V_PK_FLIP_DEF                         0x4
#define VRX_FIELD_SDP_V_PK_FLIP_BIT_SIZE                    3

#define VRX_FIELD_SDP_V_PK_CLIP_DEF                         0x3
#define VRX_FIELD_SDP_V_PK_CLIP_BIT_SIZE                    2

#define VRX_FIELD_SDP_H_PK_BAND_DEF                         0x0
#define VRX_FIELD_SDP_H_PK_BAND_BIT_SIZE                    2

#define VRX_REG_SDP_25H_DEF                                 0x00
#define VRX_FIELD_SDP_LTI_FILT_SEL_DEF                      0x0
#define VRX_FIELD_SDP_LTI_FILT_SEL_BIT_SIZE                 1

#define VRX_FIELD_SDP_LTI_LEVEL_DEF                         0x0
#define VRX_FIELD_SDP_LTI_LEVEL_BIT_SIZE                    7

#define VRX_REG_SDP_26H_DEF                                 0x8F
#define VRX_FIELD_SDP_CTI_FILT_SEL_DEF                      0x1
#define VRX_FIELD_SDP_CTI_FILT_SEL_BIT_SIZE                 1

#define VRX_FIELD_SDP_CTI_LEVEL_DEF                         0xf
#define VRX_FIELD_SDP_CTI_LEVEL_BIT_SIZE                    6

#define VRX_REG_SDP_27H_DEF                                 0xAA
#define VRX_FIELD_SDP_CTI_FLIP_DEF                          0x2
#define VRX_FIELD_SDP_CTI_FLIP_BIT_SIZE                     2

#define VRX_FIELD_SDP_LTI_FLIP_DEF                          0x2
#define VRX_FIELD_SDP_LTI_FLIP_BIT_SIZE                     2

#define VRX_REG_SDP_28H_DEF                                 0x02
#define VRX_FIELD_SDP_SCM_CTI_GAIN_DEF                      0x1
#define VRX_FIELD_SDP_SCM_CTI_GAIN_BIT_SIZE                 2

#define VRX_REG_SDP_2AH_DEF                                 0x00
#define VRX_FIELD_SDP_MAN_FB_DEF                            0x0
#define VRX_FIELD_SDP_MAN_FB_BIT_SIZE                       1

#define VRX_FIELD_SDP_RGB_DELAY_ADJ_DEF                     0x0
#define VRX_FIELD_SDP_RGB_DELAY_ADJ_BIT_SIZE                3

#define VRX_FIELD_SDP_MAN_FB_EN_DEF                         0x0
#define VRX_FIELD_SDP_MAN_FB_EN_BIT_SIZE                    1

#define VRX_FIELD_SDP_FB_DELAY_ADJ_DEF                      0x0
#define VRX_FIELD_SDP_FB_DELAY_ADJ_BIT_SIZE                 3

#define VRX_REG_SDP_34H_DEF                                 0xA0
#define VRX_FIELD_SDP_TBC_EN_DEF                            0x1
#define VRX_FIELD_SDP_TBC_EN_BIT_SIZE                       1

#define VRX_REG_SDP_4CH_DEF                                 0x00
#define VRX_FIELD_SDP_LBOX_BLK_TOP_DEF                      0x0
#define VRX_FIELD_SDP_LBOX_BLK_TOP_BIT_SIZE                 8

#define VRX_REG_SDP_4DH_DEF                                 0x00
#define VRX_FIELD_SDP_LBOX_BLK_BOT_DEF                      0x0
#define VRX_FIELD_SDP_LBOX_BLK_BOT_BIT_SIZE                 8

#define VRX_REG_SDP_4EH_DEF                                 0x00
#define VRX_FIELD_SDP_LBOX_BLK_SUB_BOT_DEF                  0x0
#define VRX_FIELD_SDP_LBOX_BLK_SUB_BOT_BIT_SIZE             8

#define VRX_REG_SDP_4FH_DEF                                 0x00
#define VRX_REG_SDP_53H_DEF                                 0x00
#define VRX_FIELD_SDP_SYNCTIP_NOISE_DEF                     0x0
#define VRX_FIELD_SDP_SYNCTIP_NOISE_BIT_SIZE                16

#define VRX_REG_SDP_50H_DEF                                 0x00
#define VRX_FIELD_SDP_MV_AGC_DETECTED_DEF                   0x0
#define VRX_FIELD_SDP_MV_AGC_DETECTED_BIT_SIZE              1

#define VRX_FIELD_SDP_MV_PS_DETECTED_DEF                    0x0
#define VRX_FIELD_SDP_MV_PS_DETECTED_BIT_SIZE               1

#define VRX_FIELD_SDP_MVCS_TYPE3_DEF                        0x0
#define VRX_FIELD_SDP_MVCS_TYPE3_BIT_SIZE                   1

#define VRX_FIELD_SDP_MVCS_DETECT_DEF                       0x0
#define VRX_FIELD_SDP_MVCS_DETECT_BIT_SIZE                  1

#define VRX_REG_SDP_51H_DEF                                 0x00
#define VRX_FIELD_SDP_BP_TOTAL_PULSE_BEG_DEF                0x0
#define VRX_FIELD_SDP_BP_TOTAL_PULSE_BEG_BIT_SIZE           4

#define VRX_FIELD_SDP_BP_TOTAL_PULSES_END_DEF               0x0
#define VRX_FIELD_SDP_BP_TOTAL_PULSES_END_BIT_SIZE          4

#define VRX_REG_SDP_52H_DEF                                 0x00
#define VRX_FIELD_SDP_STD_DEF                               0x0
#define VRX_FIELD_SDP_STD_BIT_SIZE                          4

#define VRX_REG_SDP_54H_DEF                                 0x00
#define VRX_FIELD_SDP_NOISY_IP_DEF                          0x0
#define VRX_FIELD_SDP_NOISY_IP_BIT_SIZE                     1

#define VRX_FIELD_SDP_VERY_NOISY_IP_DEF                     0x0
#define VRX_FIELD_SDP_VERY_NOISY_IP_BIT_SIZE                1

#define VRX_FIELD_SDP_C_CHAN_ACTIVE_DEF                     0x0
#define VRX_FIELD_SDP_C_CHAN_ACTIVE_BIT_SIZE                1

#define VRX_REG_SDP_55H_DEF                                 0x00
#define VRX_FIELD_SDP_Y_GAIN_MAN_RB_DEF                     0x0
#define VRX_FIELD_SDP_Y_GAIN_MAN_RB_BIT_SIZE                13

#define VRX_REG_SDP_56H_DEF                                 0x00
#define VRX_FIELD_SDP_HSWITCH_PRESENT_DEF                   0x0
#define VRX_FIELD_SDP_HSWITCH_PRESENT_BIT_SIZE              1

#define VRX_FIELD_SDP_BLK_NSTD_DEF                          0x0
#define VRX_FIELD_SDP_BLK_NSTD_BIT_SIZE                     1

#define VRX_FIELD_SDP_FLD_NSTD_DEF                          0x0
#define VRX_FIELD_SDP_FLD_NSTD_BIT_SIZE                     1

#define VRX_FIELD_SDP_FRM_NSTD_DEF                          0x0
#define VRX_FIELD_SDP_FRM_NSTD_BIT_SIZE                     1

#define VRX_FIELD_SDP_LC_NSTD_DEF                           0x0
#define VRX_FIELD_SDP_LC_NSTD_BIT_SIZE                      1

#define VRX_FIELD_SDP_ALLOW_MED_PLL_DEF                     0x0
#define VRX_FIELD_SDP_ALLOW_MED_PLL_BIT_SIZE                1

#define VRX_FIELD_SDP_ALLOW_SLOW_PLL_DEF                    0x0
#define VRX_FIELD_SDP_ALLOW_SLOW_PLL_BIT_SIZE               1

#define VRX_FIELD_SDP_FREE_RUN_DEF                          0x0
#define VRX_FIELD_SDP_FREE_RUN_BIT_SIZE                     1

#define VRX_REG_SDP_57H_DEF                                 0x00
#define VRX_FIELD_SDP_CKILL_ACT_DEF                         0x0
#define VRX_FIELD_SDP_CKILL_ACT_BIT_SIZE                    1

#define VRX_FIELD_SDP_VS_STD_MODE_DEF                       0x0
#define VRX_FIELD_SDP_VS_STD_MODE_BIT_SIZE                  1

#define VRX_FIELD_SDP_ALLOW_3D_COMB_DEF                     0x0
#define VRX_FIELD_SDP_ALLOW_3D_COMB_BIT_SIZE                1

#define VRX_FIELD_SDP_INTERLACED_DEF                        0x0
#define VRX_FIELD_SDP_INTERLACED_BIT_SIZE                   1

#define VRX_FIELD_SDP_TRICK_MODE_DEF                        0x0
#define VRX_FIELD_SDP_TRICK_MODE_BIT_SIZE                   1

#define VRX_REG_SDP_58H_DEF                                 0x00
#define VRX_FIELD_SDP_SD_DETECTED_IN_PR_DEF                 0x0
#define VRX_FIELD_SDP_SD_DETECTED_IN_PR_BIT_SIZE            1

#define VRX_FIELD_SDP_PR_DETECTED_IN_SD_DEF                 0x0
#define VRX_FIELD_SDP_PR_DETECTED_IN_SD_BIT_SIZE            1

#define VRX_REG_SDP_59H_DEF                                 0x00
#define VRX_FIELD_SDP_BURST_LOCKED_RB_DEF                   0x0
#define VRX_FIELD_SDP_BURST_LOCKED_RB_BIT_SIZE              1

#define VRX_FIELD_SDP_AD_50_60_HZ_DEF                       0x0
#define VRX_FIELD_SDP_AD_50_60_HZ_BIT_SIZE                  1

#define VRX_FIELD_SDP_PAL_SW_LOCKED_DEF                     0x0
#define VRX_FIELD_SDP_PAL_SW_LOCKED_BIT_SIZE                1

#define VRX_FIELD_SDP_FSC_FREQ_OK_DEF                       0x0
#define VRX_FIELD_SDP_FSC_FREQ_OK_BIT_SIZE                  1

#define VRX_FIELD_SDP_SCM_LOCKED_DEF                        0x0
#define VRX_FIELD_SDP_SCM_LOCKED_BIT_SIZE                   1

#define VRX_REG_SDP_5AH_DEF                                 0x00
#define VRX_FIELD_SDP_VIDEO_DETECTED_DEF                    0x0
#define VRX_FIELD_SDP_VIDEO_DETECTED_BIT_SIZE               1

#define VRX_REG_SDP_7BH_DEF                                 0x69
#define VRX_FIELD_SDP_EXTEND_VS_MAX_FREQ_DEF                0x0
#define VRX_FIELD_SDP_EXTEND_VS_MAX_FREQ_BIT_SIZE           1

#define VRX_FIELD_SDP_EXTEND_VS_MIN_FREQ_DEF                0x0
#define VRX_FIELD_SDP_EXTEND_VS_MIN_FREQ_BIT_SIZE           1

#define VRX_REG_SDP_89H_DEF                                 0x03
#define VRX_FIELD_SDP_LIMIT_Y_GAIN_DEF                      0x0
#define VRX_FIELD_SDP_LIMIT_Y_GAIN_BIT_SIZE                 1

#define VRX_FIELD_SDP_LIMIT_C_GAIN_DEF                      0x0
#define VRX_FIELD_SDP_LIMIT_C_GAIN_BIT_SIZE                 1

#define VRX_FIELD_SDP_LIMIT_UV_GAIN_DEF                     0x0
#define VRX_FIELD_SDP_LIMIT_UV_GAIN_BIT_SIZE                1

#define VRX_FIELD_SDP_LIMIT_G_GAIN_DEF                      0x0
#define VRX_FIELD_SDP_LIMIT_G_GAIN_BIT_SIZE                 1

#define VRX_REG_SDP_98H_DEF                                 0xBF
#define VRX_FIELD_SDP_NSY_DIS_SFS_STD_DEF                   0x1
#define VRX_FIELD_SDP_NSY_DIS_SFS_STD_BIT_SIZE              1

#define VRX_FIELD_SDP_HSW2_DIS_SFS_STD_DEF                  0x0
#define VRX_FIELD_SDP_HSW2_DIS_SFS_STD_BIT_SIZE             1

#define VRX_FIELD_SDP_HSW1_DIS_SFS_STD_DEF                  0x1
#define VRX_FIELD_SDP_HSW1_DIS_SFS_STD_BIT_SIZE             1

#define VRX_FIELD_SDP_LC_DIS_SFS_STD_DEF                    0x1
#define VRX_FIELD_SDP_LC_DIS_SFS_STD_BIT_SIZE               1

#define VRX_FIELD_SDP_BLK_DIS_SFS_STD_DEF                   0x1
#define VRX_FIELD_SDP_BLK_DIS_SFS_STD_BIT_SIZE              1

#define VRX_FIELD_SDP_FLD_SFS_STD_DEF                       0x1
#define VRX_FIELD_SDP_FLD_SFS_STD_BIT_SIZE                  1

#define VRX_FIELD_SDP_FRM_DIS_SFS_STD_DEF                   0x1
#define VRX_FIELD_SDP_FRM_DIS_SFS_STD_BIT_SIZE              1

#define VRX_FIELD_SDP_VNSY_DIS_SFS_STD_DEF                  0x1
#define VRX_FIELD_SDP_VNSY_DIS_SFS_STD_BIT_SIZE             1

#define VRX_REG_SDP_99H_DEF                                 0x10
#define VRX_FIELD_SDP_SHAPE_STD_FILT_SEL_DEF                0x1
#define VRX_FIELD_SDP_SHAPE_STD_FILT_SEL_BIT_SIZE           3

#define VRX_REG_SDP_9AH_DEF                                 0x01
#define VRX_FIELD_SDP_ALLOW_3D_FILT_SEL_DEF                 0x1
#define VRX_FIELD_SDP_ALLOW_3D_FILT_SEL_BIT_SIZE            3

#define VRX_REG_SDP_A1H_DEF                                 0x50
#define VRX_FIELD_SDP_NOISY_THR_DEF                         0x50
#define VRX_FIELD_SDP_NOISY_THR_BIT_SIZE                    8

#define VRX_REG_SDP_A2H_DEF                                 0xA0
#define VRX_FIELD_SDP_VERY_NOISY_THR_DEF                    0xa0
#define VRX_FIELD_SDP_VERY_NOISY_THR_BIT_SIZE               8

#define VRX_REG_SDP_A3H_DEF                                 0xBE
#define VRX_FIELD_SDP_CKILL_DIS_3D_DEF                      0x1
#define VRX_FIELD_SDP_CKILL_DIS_3D_BIT_SIZE                 1

#define VRX_REG_SDP_A4H_DEF                                 0xBF
#define VRX_FIELD_SDP_CKILL_DIS_2D_DEF                      0x1
#define VRX_FIELD_SDP_CKILL_DIS_2D_BIT_SIZE                 1

#define VRX_FIELD_SDP_NOISY_HSW2_DIS_3D_DEF                 0x0
#define VRX_FIELD_SDP_NOISY_HSW2_DIS_3D_BIT_SIZE            1

#define VRX_FIELD_SDP_NOISY_HSW1_DIS_3D_DEF                 0x1
#define VRX_FIELD_SDP_NOISY_HSW1_DIS_3D_BIT_SIZE            1

#define VRX_FIELD_SDP_NOISY_LC_DIS_3D_DEF                   0x1
#define VRX_FIELD_SDP_NOISY_LC_DIS_3D_BIT_SIZE              1

#define VRX_FIELD_SDP_NOISY_BLK_DIS_3D_DEF                  0x1
#define VRX_FIELD_SDP_NOISY_BLK_DIS_3D_BIT_SIZE             1

#define VRX_FIELD_SDP_NOISY_FLD_DIS_3D_DEF                  0x1
#define VRX_FIELD_SDP_NOISY_FLD_DIS_3D_BIT_SIZE             1

#define VRX_FIELD_SDP_NOISY_FRM_DIS_3D_DEF                  0x1
#define VRX_FIELD_SDP_NOISY_FRM_DIS_3D_BIT_SIZE             1

#define VRX_FIELD_SDP_NOISY_DIS_3D_DEF                      0x1
#define VRX_FIELD_SDP_NOISY_DIS_3D_BIT_SIZE                 1

#define VRX_REG_SDP_A5H_DEF                                 0xBF
#define VRX_FIELD_SDP_P60_N443_DIS_3D_DEF                   0x1
#define VRX_FIELD_SDP_P60_N443_DIS_3D_BIT_SIZE              1

#define VRX_FIELD_SDP_VNOISY_HSW2_DIS_3D_DEF                0x0
#define VRX_FIELD_SDP_VNOISY_HSW2_DIS_3D_BIT_SIZE           1

#define VRX_FIELD_SDP_VNOISY_HSW1_DIS_3D_DEF                0x1
#define VRX_FIELD_SDP_VNOISY_HSW1_DIS_3D_BIT_SIZE           1

#define VRX_FIELD_SDP_VNOISY_LC_DIS_3D_DEF                  0x1
#define VRX_FIELD_SDP_VNOISY_LC_DIS_3D_BIT_SIZE             1

#define VRX_FIELD_SDP_VNOISY_BLK_DIS_3D_DEF                 0x1
#define VRX_FIELD_SDP_VNOISY_BLK_DIS_3D_BIT_SIZE            1

#define VRX_FIELD_SDP_VNOISY_FLD_DIS_3D_DEF                 0x1
#define VRX_FIELD_SDP_VNOISY_FLD_DIS_3D_BIT_SIZE            1

#define VRX_FIELD_SDP_VNOISY_FRM_DIS_3D_DEF                 0x1
#define VRX_FIELD_SDP_VNOISY_FRM_DIS_3D_BIT_SIZE            1

#define VRX_FIELD_SDP_VNOISY_DIS_3D_DEF                     0x1
#define VRX_FIELD_SDP_VNOISY_DIS_3D_BIT_SIZE                1

#define VRX_REG_SDP_A8H_DEF                                 0x40
#define VRX_FIELD_SDP_3D_COMB_NOISE_SNS_DEF                 0x40
#define VRX_FIELD_SDP_3D_COMB_NOISE_SNS_BIT_SIZE            7

#define VRX_REG_SDP_A9H_DEF                                 0x88
#define VRX_FIELD_SDP_3D_COMB_CHROMA_CORE_DEF               0x8
#define VRX_FIELD_SDP_3D_COMB_CHROMA_CORE_BIT_SIZE          4

#define VRX_FIELD_SDP_3D_COMB_CHROMA_SNS_DEF                0x8
#define VRX_FIELD_SDP_3D_COMB_CHROMA_SNS_BIT_SIZE           4

#define VRX_REG_SDP_AAH_DEF                                 0x88
#define VRX_FIELD_SDP_3D_COMB_LUMA_CORE_DEF                 0x8
#define VRX_FIELD_SDP_3D_COMB_LUMA_CORE_BIT_SIZE            4

#define VRX_FIELD_SDP_3D_COMB_LUMA_SNS_DEF                  0x8
#define VRX_FIELD_SDP_3D_COMB_LUMA_SNS_BIT_SIZE             4

#define VRX_REG_SDP_D9H_DEF                                 0x44
#define VRX_FIELD_SDP_SHIP_INT_EN_DEF                       0x1
#define VRX_FIELD_SDP_SHIP_INT_EN_BIT_SIZE                  1

#define VRX_REG_SDP_DBH_DEF                                 0x88
#define VRX_FIELD_SDP_LBOX_END_DEL_DEF                      0x8
#define VRX_FIELD_SDP_LBOX_END_DEL_BIT_SIZE                 4

#define VRX_FIELD_SDP_LBOX_BEG_DEL_DEF                      0x8
#define VRX_FIELD_SDP_LBOX_BEG_DEL_BIT_SIZE                 4

#define VRX_REG_SDP_DCH_DEF                                 0x02
#define VRX_FIELD_SDP_LBOX_BLK_LVL_DEF                      0x0
#define VRX_FIELD_SDP_LBOX_BLK_LVL_BIT_SIZE                 3

#define VRX_FIELD_SDP_LBOX_THR_DEF                          0x2
#define VRX_FIELD_SDP_LBOX_THR_BIT_SIZE                     5

#define VRX_REG_SDP_DDH_DEF                                 0xBC
#define VRX_FIELD_SDP_FREE_RUN_AUTO_DEF                     0x1
#define VRX_FIELD_SDP_FREE_RUN_AUTO_BIT_SIZE                1

#define VRX_FIELD_SDP_FREE_RUN_MAN_COL_EN_DEF               0x1
#define VRX_FIELD_SDP_FREE_RUN_MAN_COL_EN_BIT_SIZE          1

#define VRX_FIELD_SDP_FREE_RUN_CBAR_EN_DEF                  0x0
#define VRX_FIELD_SDP_FREE_RUN_CBAR_EN_BIT_SIZE             1

#define VRX_FIELD_SDP_FORCE_FREE_RUN_DEF                    0x0
#define VRX_FIELD_SDP_FORCE_FREE_RUN_BIT_SIZE               1

#define VRX_REG_SDP_DEH_DEF                                 0x23
#define VRX_FIELD_SDP_FREE_RUN_Y_DEF                        0x23
#define VRX_FIELD_SDP_FREE_RUN_Y_BIT_SIZE                   8

#define VRX_REG_SDP_DFH_DEF                                 0x7D
#define VRX_FIELD_SDP_FREE_RUN_V_DEF                        0x7
#define VRX_FIELD_SDP_FREE_RUN_V_BIT_SIZE                   4

#define VRX_FIELD_SDP_FREE_RUN_U_DEF                        0xd
#define VRX_FIELD_SDP_FREE_RUN_U_BIT_SIZE                   4

#endif
