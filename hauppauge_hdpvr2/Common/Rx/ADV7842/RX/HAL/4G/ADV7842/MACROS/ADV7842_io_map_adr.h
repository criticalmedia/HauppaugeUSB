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


#ifndef ADV7842_IO_MAP_ADR_H
#define ADV7842_IO_MAP_ADR_H

#define VRX_REG_VIDEO_STANDARD                              0x00

#define VRX_REG_PRIMARY_MODE                                0x01
#define VRX_BIT_ADC_HDMI_SIMULT_MODE                        0x80

#define VRX_REG_IO_REG_02                                   0x02
#define VRX_BIT_ALT_GAMMA                                   0x08
#define VRX_BIT_OP_656_RANGE                                0x04
#define VRX_BIT_RGB_OUT                                     0x02
#define VRX_BIT_ALT_DATA_SAT                                0x01

#define VRX_REG_IO_REG_03                                   0x03

#define VRX_REG_IO_REG_04                                   0x04

#define VRX_REG_IO_REG_05                                   0x05
#define VRX_BIT_F_OUT_SEL                                   0x10
#define VRX_BIT_DATA_BLANK_EN                               0x08
#define VRX_BIT_AVCODE_INSERT_EN                            0x04
#define VRX_BIT_REPL_AV_CODE                                0x02
#define VRX_BIT_OP_SWAP_CB_CR                               0x01

#define VRX_REG_IO_REG_06                                   0x06
#define VRX_BIT_VS_OUT_SEL                                  0x80
#define VRX_BIT_INV_SYNC_OUT_POL                            0x10
#define VRX_BIT_INV_F_POL                                   0x08
#define VRX_BIT_INV_VS_POL                                  0x04
#define VRX_BIT_INV_HS_POL                                  0x02
#define VRX_BIT_INV_LLC_POL                                 0x01

#define VRX_REG_IO_REG_07                                   0x07
#define VRX_BIT_SYNC_CH_AUTO_MODE                           0x80
#define VRX_BIT_SYNC_CH1_PRIORITY                           0x40

#define VRX_REG_IO_REG_08                                   0x08

#define VRX_REG_IO_REG_0B                                   0x0B
#define VRX_BIT_SEL_RAW_CS                                  0x40
#define VRX_BIT_OSD_CLK_PDN                                 0x08
#define VRX_BIT_CORE_PDN                                    0x02
#define VRX_BIT_XTAL_PDN                                    0x01

#define VRX_REG_IO_REG_0C                                   0x0C
#define VRX_BIT_POWER_DOWN                                  0x20
#define VRX_BIT_PWR_SAVE_MODE                               0x08
#define VRX_BIT_CP_PWRDN                                    0x04
#define VRX_BIT_VDP_PDN                                     0x02
#define VRX_BIT_PADS_PDN                                    0x01

#define VRX_REG_IO_REG_12                                   0x12
#define VRX_BIT_SEL_SYNC_CHANNEL                            0x80
#define VRX_BIT_CP_STDI_INTERLACED                          0x10
#define VRX_BIT_CP_INTERLACED                               0x08
#define VRX_BIT_CP_PROG_PARM_FOR_INT                        0x04
#define VRX_BIT_CP_FORCE_INTERLACED                         0x02
#define VRX_BIT_CP_NON_STD_VIDEO                            0x01

#define VRX_REG_IO_REG_13                                   0x13

#define VRX_REG_IO_REG_14                                   0x14

#define VRX_REG_IO_REG_15                                   0x15
#define VRX_BIT_TRI_AUDIO                                   0x10
#define VRX_BIT_TRI_SYNCS                                   0x08
#define VRX_BIT_TRI_LLC                                     0x04
#define VRX_BIT_TRI_PIX                                     0x02

#define VRX_REG_IO_REG_16                                   0x16
#define VRX_BIT_PLL_DIV_MAN_EN                              0x80

#define VRX_REG_LLC_DLL                                     0x19
#define VRX_BIT_LLC_DLL_EN                                  0x80

#define VRX_REG_SUB_I2C_CONTROL                             0x1A
#define VRX_BIT_SUBI2C_EN                                   0x02
#define VRX_BIT_VDP_ON_SUB_I2C                              0x01

#define VRX_REG_HPA_REG1                                    0x20
#define VRX_BIT_HPA_MAN_VALUE_A                             0x20
#define VRX_BIT_HPA_MAN_VALUE_B                             0x10
#define VRX_BIT_HPA_TRISTATE_A                              0x02
#define VRX_BIT_HPA_TRISTATE_B                              0x01

#define VRX_REG_HPA_REG2                                    0x21
#define VRX_BIT_HPA_STATUS_PORT_A                           0x02
#define VRX_BIT_HPA_STATUS_PORT_B                           0x01

#define VRX_REG_IO_REG_30                                   0x30
#define VRX_BIT_PIXBUS_MSB_TO_LSB_REORDER                   0x10

#define VRX_REG_IO_REG_33                                   0x33
#define VRX_BIT_LLC_DLL_MUX                                 0x40

#define VRX_REG_INT_STATUS                                  0x3F
#define VRX_BIT_INTRQ_RAW                                   0x02
#define VRX_BIT_INTRQ2_RAW                                  0x01

#define VRX_REG_INT1_CONFIGURATION                          0x40
#define VRX_BIT_STORE_UNMASKED_IRQS                         0x10
#define VRX_BIT_EN_MUTE_OUT_INTRQ                           0x08
#define VRX_BIT_MPU_STIM_INTRQ                              0x04

#define VRX_REG_INT2_CONFIGURATION                          0x41
#define VRX_BIT_CP_LOCK_UNLOCK_EDGE_SEL                     0x20
#define VRX_BIT_STDI_DATA_VALID_EDGE_SEL                    0x10
#define VRX_BIT_EN_MUTE_OUT_INTRQ2                          0x08
#define VRX_BIT_INT2_EN                                     0x04

#define VRX_REG_RAW_STATUS_1                                0x42
#define VRX_BIT_SSPD_RSLT_CHNGD_RAW                         0x80
#define VRX_BIT_MV_PS_DET_RAW                               0x40
#define VRX_BIT_STDI_DATA_VALID_RAW                         0x10
#define VRX_BIT_CP_UNLOCK_RAW                               0x08
#define VRX_BIT_CP_LOCK_RAW                                 0x04
#define VRX_BIT_AFE_INTERRUPT_RAW                           0x01

#define VRX_REG_INTERRUPT_STATUS_1                          0x43
#define VRX_BIT_SSPD_RSLT_CHNGD_ST                          0x80
#define VRX_BIT_MV_PS_DET_ST                                0x40
#define VRX_BIT_STDI_DATA_VALID_ST                          0x10
#define VRX_BIT_CP_UNLOCK_ST                                0x08
#define VRX_BIT_CP_LOCK_ST                                  0x04
#define VRX_BIT_AFE_INTERRUPT_ST                            0x01

#define VRX_REG_INTERRUPT_CLEAR_1                           0x44

#define VRX_REG_INTERRUPT2_MASKB_1                          0x45
#define VRX_BIT_SSPD_RSLT_CHNGD_MB2                         0x80
#define VRX_BIT_MV_PS_DET_MB2                               0x40
#define VRX_BIT_STDI_DATA_VALID_MB2                         0x10
#define VRX_BIT_CP_UNLOCK_MB2                               0x08
#define VRX_BIT_CP_LOCK_MB2                                 0x04
#define VRX_BIT_AFE_INTERRUPT_MB2                           0x01

#define VRX_REG_INTERRUPT_MASKB_1                           0x46
#define VRX_BIT_SSPD_RSLT_CHNGD_MB1                         0x80
#define VRX_BIT_MV_PS_DET_MB1                               0x40
#define VRX_BIT_STDI_DATA_VALID_MB1                         0x10
#define VRX_BIT_CP_UNLOCK_MB1                               0x08
#define VRX_BIT_CP_LOCK_MB1                                 0x04
#define VRX_BIT_AFE_INTERRUPT_MB1                           0x01

#define VRX_REG_RAW_STATUS_2                                0x47
#define VRX_BIT_MPU_STIM_INTRQ_RAW                          0x80
#define VRX_BIT_MV_AGC_DET_RAW                              0x40
#define VRX_BIT_MV_CS_DET_RAW                               0x20
#define VRX_BIT_CP_CGMS_CHNGD_RAW                           0x04

#define VRX_REG_INTERRUPT_STATUS_2                          0x48
#define VRX_BIT_MPU_STIM_INTRQ_ST                           0x80
#define VRX_BIT_MV_AGC_DET_ST                               0x40
#define VRX_BIT_MV_CS_DET_ST                                0x20
#define VRX_BIT_CP_CGMS_CHNGD_ST                            0x04

#define VRX_REG_INTERRUPT_CLEAR_2                           0x49

#define VRX_REG_INTERRUPT2_MASKB_2                          0x4A
#define VRX_BIT_MPU_STIM_INTRQ_MB2                          0x80
#define VRX_BIT_MV_AGC_DET_MB2                              0x40
#define VRX_BIT_MV_CS_DET_MB2                               0x20
#define VRX_BIT_CP_CGMS_CHNGD_MB2                           0x04

#define VRX_REG_INTERRUPT_MASKB_2                           0x4B
#define VRX_BIT_MPU_STIM_INTRQ_MB1                          0x80
#define VRX_BIT_MV_AGC_DET_MB1                              0x40
#define VRX_BIT_MV_CS_DET_MB1                               0x20
#define VRX_BIT_CP_CGMS_CHNGD_MB1                           0x04

#define VRX_REG_AVLINK_RAW_STATUS                           0x4C
#define VRX_BIT_AVLINK_RX_READY_RAW                         0x08
#define VRX_BIT_AVLINK_TX_RETRY_TIMEOUT_RAW                 0x04
#define VRX_BIT_AVLINK_TX_ARBITRATION_LOST_RAW              0x02
#define VRX_BIT_AVLINK_TX_READY_RAW                         0x01

#define VRX_REG_INTERRUPT_STATUS_3                          0x4D
#define VRX_BIT_AVLINK_RX_READY_ST                          0x08
#define VRX_BIT_AVLINK_TX_RETRY_TIMEOUT_ST                  0x04
#define VRX_BIT_AVLINK_TX_ARBITRATION_LOST_ST               0x02
#define VRX_BIT_AVLINK_TX_READY_ST                          0x01

#define VRX_REG_INTERRUPT_CLEAR_3                           0x4E

#define VRX_REG_INTERRUPT2_MASKB_3                          0x4F
#define VRX_BIT_AVLINK_RX_READY_MB2                         0x08
#define VRX_BIT_AVLINK_TX_RETRY_TIMEOUT_MB2                 0x04
#define VRX_BIT_AVLINK_TX_ARBITRATION_LOST_MB2              0x02
#define VRX_BIT_AVLINK_TX_READY_MB2                         0x01

#define VRX_REG_INTERRUPT_MASKB_3                           0x50
#define VRX_BIT_AVLINK_RX_READY_MB1                         0x08
#define VRX_BIT_AVLINK_TX_RETRY_TIMEOUT_MB1                 0x04
#define VRX_BIT_AVLINK_TX_ARBITRATION_LOST_MB1              0x02
#define VRX_BIT_AVLINK_TX_READY_MB1                         0x01

#define VRX_REG_RAW_STATUS_4                                0x51
#define VRX_BIT_TTXT_AVL_RAW                                0x80
#define VRX_BIT_VITC_AVL_RAW                                0x40
#define VRX_BIT_GS_DATA_TYPE_RAW                            0x20
#define VRX_BIT_GS_PDC_VPS_UTC_AVL_RAW                      0x10
#define VRX_BIT_FASTI2C_DATA_RDY_RAW                        0x08
#define VRX_BIT_CGMS_WSS_AVL_RAW                            0x04
#define VRX_BIT_CCAP_EVEN_FIELD_RAW                         0x02
#define VRX_BIT_CCAP_AVL_RAW                                0x01

#define VRX_REG_INTERRUPT_STATUS_4                          0x52
#define VRX_BIT_TTXT_AVL_ST                                 0x80
#define VRX_BIT_VITC_AVL_ST                                 0x40
#define VRX_BIT_GS_DATA_TYPE_ST                             0x20
#define VRX_BIT_GS_PDC_VPS_UTC_AVL_ST                       0x10
#define VRX_BIT_FASTI2C_DATA_RDY_ST                         0x08
#define VRX_BIT_CGMS_WSS_AVL_ST                             0x04
#define VRX_BIT_CCAP_EVEN_FIELD_ST                          0x02
#define VRX_BIT_CCAP_AVL_ST                                 0x01

#define VRX_REG_INTERRUPT_CLEAR_4                           0x53

#define VRX_REG_INTERRUPT2_MASKB_4                          0x54
#define VRX_BIT_TTXT_AVL_MB2                                0x80
#define VRX_BIT_VITC_AVL_MB2                                0x40
#define VRX_BIT_GS_DATA_TYPE_MB2                            0x20
#define VRX_BIT_GS_PDC_VPS_UTC_AVL_MB2                      0x10
#define VRX_BIT_FASTI2C_DATA_RDY_MB2                        0x08
#define VRX_BIT_CGMS_WSS_AVL_MB2                            0x04
#define VRX_BIT_CCAP_EVEN_FIELD_MB2                         0x02
#define VRX_BIT_CCAP_AVL_MB2                                0x01

#define VRX_REG_INTERRUPT_MASKB_4                           0x55
#define VRX_BIT_TTXT_AVL_MB1                                0x80
#define VRX_BIT_VITC_AVL_MB1                                0x40
#define VRX_BIT_GS_DATA_TYPE_MB1                            0x20
#define VRX_BIT_GS_PDC_VPS_UTC_AVL_MB1                      0x10
#define VRX_BIT_FASTI2C_DATA_RDY_MB1                        0x08
#define VRX_BIT_CGMS_WSS_AVL_MB1                            0x04
#define VRX_BIT_CCAP_EVEN_FIELD_MB1                         0x02
#define VRX_BIT_CCAP_AVL_MB1                                0x01

#define VRX_REG_RAW_STATUS_5                                0x56
#define VRX_BIT_SDP_PROGRESSIVE_RAW                         0x80
#define VRX_BIT_SDP_PR_DET_RAW                              0x40
#define VRX_BIT_SDP_SD_DET_RAW                              0x20
#define VRX_BIT_SDP_50HZ_DET_RAW                            0x10

#define VRX_REG_INTERRUPT_STATUS_5                          0x57
#define VRX_BIT_SDP_PROGRESSIVE_ST                          0x80
#define VRX_BIT_SDP_PR_DET_ST                               0x40
#define VRX_BIT_SDP_SD_DET_ST                               0x20
#define VRX_BIT_SDP_50HZ_DET_ST                             0x10

#define VRX_REG_INTERRUPT_CLEAR_5                           0x58

#define VRX_REG_INTERRUPT2_MASKB_5                          0x59
#define VRX_BIT_SDP_PROGRESSIVE_MB2                         0x80
#define VRX_BIT_SDP_PR_DET_MB2                              0x40
#define VRX_BIT_SDP_SD_DET_MB2                              0x20
#define VRX_BIT_SDP_50HZ_DET_MB2                            0x10

#define VRX_REG_INTERRUPT_MASKB_5                           0x5A
#define VRX_BIT_SDP_PROGRESSIVE_MB1                         0x80
#define VRX_BIT_SDP_PR_DET_MB1                              0x40
#define VRX_BIT_SDP_SD_DET_MB1                              0x20
#define VRX_BIT_SDP_50HZ_DET_MB1                            0x10

#define VRX_REG_RAW_STATUS_6                                0x5B
#define VRX_BIT_CP_LOCK_CH2_RAW                             0x80
#define VRX_BIT_CP_UNLOCK_CH2_RAW                           0x40
#define VRX_BIT_STDI_DVALID_CH2_RAW                         0x20
#define VRX_BIT_SSPD_RSLT_CHNGD_CH2_RAW                     0x10
#define VRX_BIT_CP_LOCK_CH1_RAW                             0x08
#define VRX_BIT_CP_UNLOCK_CH1_RAW                           0x04
#define VRX_BIT_STDI_DVALID_CH1_RAW                         0x02
#define VRX_BIT_SSPD_RSLT_CHNGD_CH1_RAW                     0x01

#define VRX_REG_INTERRUPT_STATUS_6                          0x5C
#define VRX_BIT_CP_LOCK_CH2_ST                              0x80
#define VRX_BIT_CP_UNLOCK_CH2_ST                            0x40
#define VRX_BIT_STDI_DVALID_CH2_ST                          0x20
#define VRX_BIT_SSPD_RSLT_CHNGD_CH2_ST                      0x10
#define VRX_BIT_CP_LOCK_CH1_ST                              0x08
#define VRX_BIT_CP_UNLOCK_CH1_ST                            0x04
#define VRX_BIT_STDI_DVALID_CH1_ST                          0x02
#define VRX_BIT_SSPD_RSLT_CHNGD_CH1_ST                      0x01

#define VRX_REG_INTERRUPT_CLEAR_6                           0x5D

#define VRX_REG_INTERRUPT2_MASKB_6                          0x5E
#define VRX_BIT_CP_LOCK_CH2_MB2                             0x80
#define VRX_BIT_CP_UNLOCK_CH2_MB2                           0x40
#define VRX_BIT_STDI_DVALID_CH2_MB2                         0x20
#define VRX_BIT_SSPD_RSLT_CHNGD_CH2_MB2                     0x10
#define VRX_BIT_CP_LOCK_CH1_MB2                             0x08
#define VRX_BIT_CP_UNLOCK_CH1_MB2                           0x04
#define VRX_BIT_STDI_DVALID_CH1_MB2                         0x02
#define VRX_BIT_SSPD_RSLT_CHNGD_CH1_MB2                     0x01

#define VRX_REG_INTERRUPT_MASKB_6                           0x5F
#define VRX_BIT_CP_LOCK_CH2_MB1                             0x80
#define VRX_BIT_CP_UNLOCK_CH2_MB1                           0x40
#define VRX_BIT_STDI_DVALID_CH2_MB1                         0x20
#define VRX_BIT_SSPD_RSLT_CHNGD_CH2_MB1                     0x10
#define VRX_BIT_CP_LOCK_CH1_MB1                             0x08
#define VRX_BIT_CP_UNLOCK_CH1_MB1                           0x04
#define VRX_BIT_STDI_DVALID_CH1_MB1                         0x02
#define VRX_BIT_SSPD_RSLT_CHNGD_CH1_MB1                     0x01

#define VRX_REG_HDMI_LVL_RAW_STATUS_1                       0x60
#define VRX_BIT_ISRC2_PCKT_RAW                              0x80
#define VRX_BIT_ISRC1_PCKT_RAW                              0x40
#define VRX_BIT_ACP_PCKT_RAW                                0x20
#define VRX_BIT_VS_INFO_RAW                                 0x10
#define VRX_BIT_MS_INFO_RAW                                 0x08
#define VRX_BIT_SPD_INFO_RAW                                0x04
#define VRX_BIT_AUDIO_INFO_RAW                              0x02
#define VRX_BIT_AVI_INFO_RAW                                0x01

#define VRX_REG_HDMI_LVL_INT_STATUS_1                       0x61
#define VRX_BIT_ISRC2_PCKT_ST                               0x80
#define VRX_BIT_ISRC1_PCKT_ST                               0x40
#define VRX_BIT_ACP_PCKT_ST                                 0x20
#define VRX_BIT_VS_INFO_ST                                  0x10
#define VRX_BIT_MS_INFO_ST                                  0x08
#define VRX_BIT_SPD_INFO_ST                                 0x04
#define VRX_BIT_AUDIO_INFO_ST                               0x02
#define VRX_BIT_AVI_INFO_ST                                 0x01

#define VRX_REG_HDMI_LVL_INT_CLR_1                          0x62

#define VRX_REG_HDMI_LVL_INT2_MASKB_1                       0x63
#define VRX_BIT_ISRC2_PCKT_MB2                              0x80
#define VRX_BIT_ISRC1_PCKT_MB2                              0x40
#define VRX_BIT_ACP_PCKT_MB2                                0x20
#define VRX_BIT_VS_INFO_MB2                                 0x10
#define VRX_BIT_MS_INFO_MB2                                 0x08
#define VRX_BIT_SPD_INFO_MB2                                0x04
#define VRX_BIT_AUDIO_INFO_MB2                              0x02
#define VRX_BIT_AVI_INFO_MB2                                0x01

#define VRX_REG_HDMI_LVL_INT_MASKB_1                        0x64
#define VRX_BIT_ISRC2_PCKT_MB1                              0x80
#define VRX_BIT_ISRC1_PCKT_MB1                              0x40
#define VRX_BIT_ACP_PCKT_MB1                                0x20
#define VRX_BIT_VS_INFO_MB1                                 0x10
#define VRX_BIT_MS_INFO_MB1                                 0x08
#define VRX_BIT_SPD_INFO_MB1                                0x04
#define VRX_BIT_AUDIO_INFO_MB1                              0x02
#define VRX_BIT_AVI_INFO_MB1                                0x01

#define VRX_REG_HDMI_LVL_RAW_STATUS_2                       0x65
#define VRX_BIT_CS_DATA_VALID_RAW                           0x80
#define VRX_BIT_INTERNAL_MUTE_RAW                           0x40
#define VRX_BIT_AV_MUTE_RAW                                 0x20
#define VRX_BIT_AUDIO_CH_MD_RAW                             0x10
#define VRX_BIT_HDMI_MODE_RAW                               0x08
#define VRX_BIT_GEN_CTL_PCKT_RAW                            0x04
#define VRX_BIT_AUDIO_C_PCKT_RAW                            0x02
#define VRX_BIT_GAMUT_MDATA_RAW                             0x01

#define VRX_REG_HDMI_LVL_INT_STATUS_2                       0x66
#define VRX_BIT_CS_DATA_VALID_ST                            0x80
#define VRX_BIT_INTERNAL_MUTE_ST                            0x40
#define VRX_BIT_AV_MUTE_ST                                  0x20
#define VRX_BIT_AUDIO_CH_MD_ST                              0x10
#define VRX_BIT_HDMI_MODE_ST                                0x08
#define VRX_BIT_GEN_CTL_PCKT_ST                             0x04
#define VRX_BIT_AUDIO_C_PCKT_ST                             0x02
#define VRX_BIT_GAMUT_MDATA_ST                              0x01

#define VRX_REG_HDMI_LVL_INT_CLR_2                          0x67

#define VRX_REG_HDMI_LVL_INT2_MASKB_2                       0x68
#define VRX_BIT_CS_DATA_VALID_MB2                           0x80
#define VRX_BIT_INTERNAL_MUTE_MB2                           0x40
#define VRX_BIT_AV_MUTE_MB2                                 0x20
#define VRX_BIT_AUDIO_CH_MD_MB2                             0x10
#define VRX_BIT_HDMI_MODE_MB2                               0x08
#define VRX_BIT_GEN_CTL_PCKT_MB2                            0x04
#define VRX_BIT_AUDIO_C_PCKT_MB2                            0x02
#define VRX_BIT_GAMUT_MDATA_MB2                             0x01

#define VRX_REG_HDMI_LVL_INT_MASKB_2                        0x69
#define VRX_BIT_CS_DATA_VALID_MB1                           0x80
#define VRX_BIT_INTERNAL_MUTE_MB1                           0x40
#define VRX_BIT_AV_MUTE_MB1                                 0x20
#define VRX_BIT_AUDIO_CH_MD_MB1                             0x10
#define VRX_BIT_HDMI_MODE_MB1                               0x08
#define VRX_BIT_GEN_CTL_PCKT_MB1                            0x04
#define VRX_BIT_AUDIO_C_PCKT_MB1                            0x02
#define VRX_BIT_GAMUT_MDATA_MB1                             0x01

#define VRX_REG_HDMI_LVL_RAW_STATUS_3                       0x6A
#define VRX_BIT_TMDSPLL_LCK_A_RAW                           0x20
#define VRX_BIT_TMDSPLL_LCK_B_RAW                           0x10
#define VRX_BIT_TMDS_CLK_A_RAW                              0x02
#define VRX_BIT_TMDS_CLK_B_RAW                              0x01

#define VRX_REG_HDMI_LVL_INT_STATUS_3                       0x6B
#define VRX_BIT_TMDSPLL_LCK_A_ST                            0x20
#define VRX_BIT_TMDSPLL_LCK_B_ST                            0x10
#define VRX_BIT_TMDS_CLK_A_ST                               0x02
#define VRX_BIT_TMDS_CLK_B_ST                               0x01

#define VRX_REG_HDMI_LVL_INT_CLR_3                          0x6C

#define VRX_REG_HDMI_LVL_INT2_MASKB_3                       0x6D
#define VRX_BIT_TMDSPLL_LCK_A_MB2                           0x20
#define VRX_BIT_TMDSPLL_LCK_B_MB2                           0x10
#define VRX_BIT_TMDS_CLK_A_MB2                              0x02
#define VRX_BIT_TMDS_CLK_B_MB2                              0x01

#define VRX_REG_HDMI_LVL_INT_MASKB_3                        0x6E
#define VRX_BIT_TMDSPLL_LCK_A_MB1                           0x20
#define VRX_BIT_TMDSPLL_LCK_B_MB1                           0x10
#define VRX_BIT_TMDS_CLK_A_MB1                              0x02
#define VRX_BIT_TMDS_CLK_B_MB1                              0x01

#define VRX_REG_HDMI_LVL_RAW_STATUS_4                       0x6F
#define VRX_BIT_HDMI_ENCRPT_A_RAW                           0x20
#define VRX_BIT_HDMI_ENCRPT_B_RAW                           0x10
#define VRX_BIT_CABLE_DET_A_RAW                             0x02
#define VRX_BIT_CABLE_DET_B_RAW                             0x01

#define VRX_REG_HDMI_LVL_INT_STATUS_4                       0x70
#define VRX_BIT_HDMI_ENCRPT_A_ST                            0x20
#define VRX_BIT_HDMI_ENCRPT_B_ST                            0x10
#define VRX_BIT_CABLE_DET_A_ST                              0x02
#define VRX_BIT_CABLE_DET_B_ST                              0x01

#define VRX_REG_HDMI_LVL_INT_CLR_4                          0x71

#define VRX_REG_HDMI_LVL_INT2_MASKB_4                       0x72
#define VRX_BIT_HDMI_ENCRPT_A_MB2                           0x20
#define VRX_BIT_HDMI_ENCRPT_B_MB2                           0x10
#define VRX_BIT_CABLE_DET_A_MB2                             0x02
#define VRX_BIT_CABLE_DET_B_MB2                             0x01

#define VRX_REG_HDMI_LVL_INT_MASKB_4                        0x73
#define VRX_BIT_HDMI_ENCRPT_A_MB1                           0x20
#define VRX_BIT_HDMI_ENCRPT_B_MB1                           0x10
#define VRX_BIT_CABLE_DET_A_MB1                             0x02
#define VRX_BIT_CABLE_DET_B_MB1                             0x01

#define VRX_REG_HDMI_LVL_RAW_STATUS_5                       0x74
#define VRX_BIT_VIDEO_3D_RAW                                0x04
#define VRX_BIT_V_LOCKED_RAW                                0x02
#define VRX_BIT_DE_REGEN_LCK_RAW                            0x01

#define VRX_REG_HDMI_LVL_INT_STATUS_5                       0x75
#define VRX_BIT_VIDEO_3D_ST                                 0x04
#define VRX_BIT_V_LOCKED_ST                                 0x02
#define VRX_BIT_DE_REGEN_LCK_ST                             0x01

#define VRX_REG_HDMI_LVL_INT_CLR_5                          0x76

#define VRX_REG_HDMI_LVL_INT2_MASKB_5                       0x77
#define VRX_BIT_VIDEO_3D_MB2                                0x04
#define VRX_BIT_V_LOCKED_MB2                                0x02
#define VRX_BIT_DE_REGEN_LCK_MB2                            0x01

#define VRX_REG_HDMI_LVL_INT_MASKB_5                        0x78
#define VRX_BIT_VIDEO_3D_MB1                                0x04
#define VRX_BIT_V_LOCKED_MB1                                0x02
#define VRX_BIT_DE_REGEN_LCK_MB1                            0x01

#define VRX_REG_HDMI_EDG_RAW_STATUS_1                       0x79
#define VRX_BIT_NEW_ISRC2_PCKT_RAW                          0x80
#define VRX_BIT_NEW_ISRC1_PCKT_RAW                          0x40
#define VRX_BIT_NEW_ACP_PCKT_RAW                            0x20
#define VRX_BIT_NEW_VS_INFO_RAW                             0x10
#define VRX_BIT_NEW_MS_INFO_RAW                             0x08
#define VRX_BIT_NEW_SPD_INFO_RAW                            0x04
#define VRX_BIT_NEW_AUDIO_INFO_RAW                          0x02
#define VRX_BIT_NEW_AVI_INFO_RAW                            0x01

#define VRX_REG_HDMI_EDG_INT_STATUS_1                       0x7A
#define VRX_BIT_NEW_ISRC2_PCKT_ST                           0x80
#define VRX_BIT_NEW_ISRC1_PCKT_ST                           0x40
#define VRX_BIT_NEW_ACP_PCKT_ST                             0x20
#define VRX_BIT_NEW_VS_INFO_ST                              0x10
#define VRX_BIT_NEW_MS_INFO_ST                              0x08
#define VRX_BIT_NEW_SPD_INFO_ST                             0x04
#define VRX_BIT_NEW_AUDIO_INFO_ST                           0x02
#define VRX_BIT_NEW_AVI_INFO_ST                             0x01

#define VRX_REG_HDMI_EDG_INT_CLR_1                          0x7B

#define VRX_REG_HDMI_EDG_INT2_MASKB_1                       0x7C
#define VRX_BIT_NEW_ISRC2_PCKT_MB2                          0x80
#define VRX_BIT_NEW_ISRC1_PCKT_MB2                          0x40
#define VRX_BIT_NEW_ACP_PCKT_MB2                            0x20
#define VRX_BIT_NEW_VS_INFO_MB2                             0x10
#define VRX_BIT_NEW_MS_INFO_MB2                             0x08
#define VRX_BIT_NEW_SPD_INFO_MB2                            0x04
#define VRX_BIT_NEW_AUDIO_INFO_MB2                          0x02
#define VRX_BIT_NEW_AVI_INFO_MB2                            0x01

#define VRX_REG_HDMI_EDG_INT_MASKB_1                        0x7D
#define VRX_BIT_NEW_ISRC2_PCKT_MB1                          0x80
#define VRX_BIT_NEW_ISRC1_PCKT_MB1                          0x40
#define VRX_BIT_NEW_ACP_PCKT_MB1                            0x20
#define VRX_BIT_NEW_VS_INFO_MB1                             0x10
#define VRX_BIT_NEW_MS_INFO_MB1                             0x08
#define VRX_BIT_NEW_SPD_INFO_MB1                            0x04
#define VRX_BIT_NEW_AUDIO_INFO_MB1                          0x02
#define VRX_BIT_NEW_AVI_INFO_MB1                            0x01

#define VRX_REG_HDMI_EDG_RAW_STATUS_2                       0x7E
#define VRX_BIT_FIFO_NEAR_OVFL_RAW                          0x80
#define VRX_BIT_FIFO_UNDERFLO_RAW                           0x40
#define VRX_BIT_FIFO_OVERFLO_RAW                            0x20
#define VRX_BIT_CTS_PASS_THRSH_RAW                          0x10
#define VRX_BIT_CHANGE_N_RAW                                0x08
#define VRX_BIT_PACKET_ERROR_RAW                            0x04
#define VRX_BIT_AUDIO_PCKT_ERR_RAW                          0x02
#define VRX_BIT_NEW_GAMUT_MDATA_RAW                         0x01

#define VRX_REG_HDMI_EDG_INT_STATUS_2                       0x7F
#define VRX_BIT_FIFO_NEAR_OVFL_ST                           0x80
#define VRX_BIT_FIFO_UNDERFLO_ST                            0x40
#define VRX_BIT_FIFO_OVERFLO_ST                             0x20
#define VRX_BIT_CTS_PASS_THRSH_ST                           0x10
#define VRX_BIT_CHANGE_N_ST                                 0x08
#define VRX_BIT_PACKET_ERROR_ST                             0x04
#define VRX_BIT_AUDIO_PCKT_ERR_ST                           0x02
#define VRX_BIT_NEW_GAMUT_MDATA_ST                          0x01

#define VRX_REG_HDMI_EDG_INT_CLR_2                          0x80

#define VRX_REG_HDMI_EDG_INT2_MASKB_2                       0x81
#define VRX_BIT_FIFO_NEAR_OVFL_MB2                          0x80
#define VRX_BIT_FIFO_UNDERFLO_MB2                           0x40
#define VRX_BIT_FIFO_OVERFLO_MB2                            0x20
#define VRX_BIT_CTS_PASS_THRSH_MB2                          0x10
#define VRX_BIT_CHANGE_N_MB2                                0x08
#define VRX_BIT_PACKET_ERROR_MB2                            0x04
#define VRX_BIT_AUDIO_PCKT_ERR_MB2                          0x02
#define VRX_BIT_NEW_GAMUT_MDATA_MB2                         0x01

#define VRX_REG_HDMI_EDG_INT_MASKB_2                        0x82
#define VRX_BIT_FIFO_NEAR_OVFL_MB1                          0x80
#define VRX_BIT_FIFO_UNDERFLO_MB1                           0x40
#define VRX_BIT_FIFO_OVERFLO_MB1                            0x20
#define VRX_BIT_CTS_PASS_THRSH_MB1                          0x10
#define VRX_BIT_CHANGE_N_MB1                                0x08
#define VRX_BIT_PACKET_ERROR_MB1                            0x04
#define VRX_BIT_AUDIO_PCKT_ERR_MB1                          0x02
#define VRX_BIT_NEW_GAMUT_MDATA_MB1                         0x01

#define VRX_REG_HDMI_EDG_RAW_STATUS_3                       0x83
#define VRX_BIT_DEEP_COLOR_CHNG_RAW                         0x80
#define VRX_BIT_VCLK_CHNG_RAW                               0x40
#define VRX_BIT_AUDIO_MODE_CHANGE_RAW                       0x20
#define VRX_BIT_PARITY_ERROR_RAW                            0x10
#define VRX_BIT_NEW_SAMP_RT_RAW                             0x08
#define VRX_BIT_AUDIO_FLT_LINE_RAW                          0x04
#define VRX_BIT_NEW_TMDS_FRQ_RAW                            0x02
#define VRX_BIT_FIFO_NEAR_UFLO_RAW                          0x01

#define VRX_REG_HDMI_EDG_STATUS_3                           0x84
#define VRX_BIT_DEEP_COLOR_CHNG_ST                          0x80
#define VRX_BIT_VCLK_CHNG_ST                                0x40
#define VRX_BIT_AUDIO_MODE_CHANGE_ST                        0x20
#define VRX_BIT_PARITY_ERROR_ST                             0x10
#define VRX_BIT_NEW_SAMP_RT_ST                              0x08
#define VRX_BIT_AUDIO_FLT_LINE_ST                           0x04
#define VRX_BIT_NEW_TMDS_FRQ_ST                             0x02
#define VRX_BIT_FIFO_NEAR_UFLO_ST                           0x01

#define VRX_REG_HDMI_EDG_INT_CLR_3                          0x85

#define VRX_REG_HDMI_EDG_INT2_MASKB_3                       0x86
#define VRX_BIT_DEEP_COLOR_CHNG_MB2                         0x80
#define VRX_BIT_VCLK_CHNG_MB2                               0x40
#define VRX_BIT_AUDIO_MODE_CHANGE_MB2                       0x20
#define VRX_BIT_PARITY_ERROR_MB2                            0x10
#define VRX_BIT_NEW_SAMP_RT_MB2                             0x08
#define VRX_BIT_AUDIO_FLT_LINE_MB2                          0x04
#define VRX_BIT_NEW_TMDS_FRQ_MB2                            0x02
#define VRX_BIT_FIFO_NEAR_UFLO_MB2                          0x01

#define VRX_REG_HDMI_EDG_INT_MASKB_3                        0x87
#define VRX_BIT_DEEP_COLOR_CHNG_MB1                         0x80
#define VRX_BIT_VCLK_CHNG_MB1                               0x40
#define VRX_BIT_AUDIO_MODE_CHANGE_MB1                       0x20
#define VRX_BIT_PARITY_ERROR_MB1                            0x10
#define VRX_BIT_NEW_SAMP_RT_MB1                             0x08
#define VRX_BIT_AUDIO_FLT_LINE_MB1                          0x04
#define VRX_BIT_NEW_TMDS_FRQ_MB1                            0x02
#define VRX_BIT_FIFO_NEAR_UFLO_MB1                          0x01

#define VRX_REG_HDMI_EDG_RAW_STATUS_4                       0x88
#define VRX_BIT_MS_INF_CKS_ERR_RAW                          0x80
#define VRX_BIT_SPD_INF_CKS_ERR_RAW                         0x40
#define VRX_BIT_AUD_INF_CKS_ERR_RAW                         0x20
#define VRX_BIT_AVI_INF_CKS_ERR_RAW                         0x10
#define VRX_BIT_AKSV_UPDATE_A_RAW                           0x02
#define VRX_BIT_AKSV_UPDATE_B_RAW                           0x01

#define VRX_REG_HDMI_EDG_STATUS_4                           0x89
#define VRX_BIT_MS_INF_CKS_ERR_ST                           0x80
#define VRX_BIT_SPD_INF_CKS_ERR_ST                          0x40
#define VRX_BIT_AUD_INF_CKS_ERR_ST                          0x20
#define VRX_BIT_AVI_INF_CKS_ERR_ST                          0x10
#define VRX_BIT_AKSV_UPDATE_A_ST                            0x02
#define VRX_BIT_AKSV_UPDATE_B_ST                            0x01

#define VRX_REG_HDMI_EDG_INT_CLR_4                          0x8A

#define VRX_REG_HDMI_EDG_INT2_MASKB_4                       0x8B
#define VRX_BIT_MS_INF_CKS_ERR_MB2                          0x80
#define VRX_BIT_SPD_INF_CKS_ERR_MB2                         0x40
#define VRX_BIT_AUD_INF_CKS_ERR_MB2                         0x20
#define VRX_BIT_AVI_INF_CKS_ERR_MB2                         0x10
#define VRX_BIT_AKSV_UPDATE_A_MB2                           0x02
#define VRX_BIT_AKSV_UPDATE_B_MB2                           0x01

#define VRX_REG_HDMI_EDG_INT_MASKB_4                        0x8C
#define VRX_BIT_MS_INF_CKS_ERR_MB1                          0x80
#define VRX_BIT_SPD_INF_CKS_ERR_MB1                         0x40
#define VRX_BIT_AUD_INF_CKS_ERR_MB1                         0x20
#define VRX_BIT_AVI_INF_CKS_ERR_MB1                         0x10
#define VRX_BIT_AKSV_UPDATE_A_MB1                           0x02
#define VRX_BIT_AKSV_UPDATE_B_MB1                           0x01

#define VRX_REG_HDMI_EDG_RAW_STATUS_5                       0x8D
#define VRX_BIT_BG_MEAS_DONE_RAW                            0x02
#define VRX_BIT_VS_INF_CKS_ERR_RAW                          0x01

#define VRX_REG_HDMI_EDG_STATUS_5                           0x8E
#define VRX_BIT_BG_MEAS_DONE_ST                             0x02
#define VRX_BIT_VS_INF_CKS_ERR_ST                           0x01

#define VRX_REG_HDMI_EDG_INT_CLR_5                          0x8F

#define VRX_REG_HDMI_EDG_INT2_MASKB_5                       0x90
#define VRX_BIT_BG_MEAS_DONE_MB2                            0x02
#define VRX_BIT_VS_INF_CKS_ERR_MB2                          0x01

#define VRX_REG_HDMI_EDG_INT_MASKB_5                        0x91
#define VRX_BIT_BG_MEAS_DONE_MB1                            0x02
#define VRX_BIT_VS_INF_CKS_ERR_MB1                          0x01

#define VRX_REG_CEC_STATUS1_RAW                             0x92
#define VRX_BIT_CEC_RX_RDY2_RAW                             0x20
#define VRX_BIT_CEC_RX_RDY1_RAW                             0x10
#define VRX_BIT_CEC_RX_RDY0_RAW                             0x08
#define VRX_BIT_CEC_TX_RETRY_TIMEOUT_RAW                    0x04
#define VRX_BIT_CEC_TX_ARBITRATION_LOST_RAW                 0x02
#define VRX_BIT_CEC_TX_READY_RAW                            0x01

#define VRX_REG_CEC_STATUS1_INT_STATUS                      0x93
#define VRX_BIT_CEC_RX_RDY2_ST                              0x20
#define VRX_BIT_CEC_RX_RDY1_ST                              0x10
#define VRX_BIT_CEC_RX_RDY0_ST                              0x08
#define VRX_BIT_CEC_TX_RETRY_TIMEOUT_ST                     0x04
#define VRX_BIT_CEC_TX_ARBITRATION_LOST_ST                  0x02
#define VRX_BIT_CEC_TX_READY_ST                             0x01

#define VRX_REG_CEC_STATUS1_INT_CLEAR                       0x94

#define VRX_REG_CEC_STATUS1_INT2_MASKB                      0x95
#define VRX_BIT_CEC_RX_RDY2_MB2                             0x20
#define VRX_BIT_CEC_RX_RDY1_MB2                             0x10
#define VRX_BIT_CEC_RX_RDY0_MB2                             0x08
#define VRX_BIT_CEC_TX_RETRY_TIMEOUT_MB2                    0x04
#define VRX_BIT_CEC_TX_ARBITRATION_LOST_MB2                 0x02
#define VRX_BIT_CEC_TX_READY_MB2                            0x01

#define VRX_REG_CEC_STATUS1_INT1_MASKB                      0x96
#define VRX_BIT_CEC_RX_RDY2_MB1                             0x20
#define VRX_BIT_CEC_RX_RDY1_MB1                             0x10
#define VRX_BIT_CEC_RX_RDY0_MB1                             0x08
#define VRX_BIT_CEC_TX_RETRY_TIMEOUT_MB1                    0x04
#define VRX_BIT_CEC_TX_ARBITRATION_LOST_MB1                 0x02
#define VRX_BIT_CEC_TX_READY_MB1                            0x01

#define VRX_REG_CEC_RAW_STATUS2                             0x97

#define VRX_REG_CEC_INTERRUPT_STATUS2                       0x98

#define VRX_REG_CEC_INTERRUPT_CLEAR2                        0x99

#define VRX_REG_CEC_INTERRUPT2_MASKB                        0x9A

#define VRX_REG_CEC_INTERRUPT_MASKB                         0x9B

#define VRX_REG_SDP_RAW_STATUS                              0x9C
#define VRX_BIT_SDP_STD_CHANGED_RAW                         0x08
#define VRX_BIT_SDP_BURST_LOCKED_RAW                        0x02
#define VRX_BIT_SDP_VIDEO_DETECTED_RAW                      0x01

#define VRX_REG_SDP_INTERRUPT_STATUS                        0x9D
#define VRX_BIT_SDP_STD_CHANGED_ST                          0x08
#define VRX_BIT_SDP_BURST_LOCKED_ST                         0x02
#define VRX_BIT_SDP_VIDEO_DETECTED_ST                       0x01

#define VRX_REG_SDP_INTERRUPT_CLEAR                         0x9E

#define VRX_REG_SDP_INTERRUPT2_MASKB                        0x9F
#define VRX_BIT_SDP_STD_CHANGED_MB2                         0x08
#define VRX_BIT_SDP_BURST_LOCKED_MB2                        0x02
#define VRX_BIT_SDP_VIDEO_DETECTED_MB2                      0x01

#define VRX_REG_SDP_INTERRUPT_MASKB                         0xA0
#define VRX_BIT_SDP_STD_CHANGED_MB1                         0x08
#define VRX_BIT_SDP_FIFO_CRISIS_MB1                         0x04
#define VRX_BIT_SDP_BURST_LOCKED_MB1                        0x02
#define VRX_BIT_SDP_VIDEO_DETECTED_MB1                      0x01

#define VRX_REG_IO_REG_D6                                   0xD6
#define VRX_BIT_PIN_CHECKER_EN                              0x01

#define VRX_REG_IO_REG_D7                                   0xD7

#define VRX_BIT_DDS_FREQ_MAN_EN                             0x20

#define VRX_BIT_MAN_OP_CLK_SEL_EN                           0x80

#define VRX_REG_IO_REG_E0                                   0xE0
#define VRX_BIT_DS_WITHOUT_FILTER                           0x80

#define VRX_REG_IO_REG_E7                                   0xE7
#define VRX_BIT_DPP_LUMA_HBW_SEL                            0x20
#define VRX_BIT_DPP_CHROMA_LOW_EN                           0x10

#define VRX_REG_SDP_SLAVE_ADDRESS                           0xF1

#define VRX_REG_SDP_IO_SLAVE_ADDRESS                        0xF2

#define VRX_REG_AVLINK_SLAVE_ADDRESS                        0xF3

#define VRX_REG_CEC_SLAVE_ADDRESS                           0xF4

#define VRX_REG_INFOFRAME_SLAVE_ADDRESS                     0xF5

#define VRX_REG_AFE_SLAVE_ADDRESS                           0xF8

#define VRX_REG_KSV_SLAVE_ADDRESS                           0xF9

#define VRX_REG_EDID_SLAVE_ADDRESS                          0xFA

#define VRX_REG_HDMI_SLAVE_ADDRESS                          0xFB

#define VRX_REG_CP_SLAVE_ADDRESS                            0xFD

#define VRX_REG_VDP_SLAVE_ADDRESS                           0xFE

#define VRX_REG_IO_REG_FF                                   0xFF


#endif
