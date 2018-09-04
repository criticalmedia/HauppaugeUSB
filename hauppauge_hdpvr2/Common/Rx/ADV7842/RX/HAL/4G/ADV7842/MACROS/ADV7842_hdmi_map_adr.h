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
* DATE: 18 Nov 2009 16:10:7                                                    *
*                                                                              *
*******************************************************************************/


#ifndef ADV7842_HDMI_MAP_ADR_H
#define ADV7842_HDMI_MAP_ADR_H

#define VRX_REG_HDMI_REGISTER_00H                           0x00
#define VRX_BIT_EN_BG_PORT_A                                0x20
#define VRX_BIT_EN_BG_PORT_B                                0x10

#define VRX_REG_HDMI_REGISTER_01H                           0x01
#define VRX_BIT_TERM_AUTO                                   0x80
#define VRX_BIT_CLOCK_TERMB_DISABLE                         0x40
#define VRX_BIT_CLOCK_TERMA_DISABLE                         0x20
#define VRX_BIT_HDCP_ONLY_MODE                              0x04
#define VRX_BIT_OVR_MUX_HBR                                 0x02
#define VRX_BIT_MUX_HBR_OUT                                 0x01

#define VRX_REG_HDMI_REGISTER_02H                           0x02
#define VRX_BIT_HDCP_A0                                     0x08
#define VRX_BIT_OVR_AUTO_MUX_DSD_OUT                        0x02
#define VRX_BIT_MUX_DSD_OUT                                 0x01

#define VRX_REG_HDMI_REGISTER_03H                           0x03

#define VRX_REG_HDMI_REGISTER_04H                           0x04
#define VRX_BIT_AV_MUTE                                     0x40
#define VRX_BIT_HDCP_KEYS_READ                              0x20
#define VRX_BIT_HDCP_KEY_ERROR                              0x10
#define VRX_BIT_TMDS_PLL_LOCKED                             0x02
#define VRX_BIT_AUDIO_PLL_LOCKED                            0x01

#define VRX_REG_HDMI_REGISTER_05H                           0x05
#define VRX_BIT_HDMI_MODE                                   0x80
#define VRX_BIT_HDMI_CONTENT_ENCRYPTED                      0x40
#define VRX_BIT_DVI_HSYNC_POLARITY                          0x20
#define VRX_BIT_DVI_VSYNC_POLARITY                          0x10

#define VRX_REG_LINE_WIDTH_1                                0x07
#define VRX_BIT_VERT_FILTER_LOCKED                          0x80
#define VRX_BIT_AUDIO_CHANNEL_MODE                          0x40
#define VRX_BIT_DE_REGEN_FILTER_LOCKED                      0x20

#define VRX_REG_LINE_WIDTH_2                                0x08

#define VRX_REG_FIELD0_HEIGHT_1                             0x09

#define VRX_REG_FIELD0_HEIGHT_2                             0x0A

#define VRX_REG_FIELD1_HEIGHT_1                             0x0B
#define VRX_BIT_HDMI_INTERLACED                             0x20

#define VRX_REG_FIELD1_HEIGHT_2                             0x0C

#define VRX_REG_HDMI_REGISTER_0DH                           0x0D

#define VRX_REG_AUDIO_MUTE_SPEED                            0x0F
#define VRX_BIT_MAN_AUDIO_DL_BYPASS                         0x80
#define VRX_BIT_AUDIO_DELAY_LINE_BYPASS                     0x40

#define VRX_REG_HDMI_REGISTER_10H                           0x10

#define VRX_REG_AUDIO_FIFO_ALMOST_FULL_THRESHOLD            0x11

#define VRX_REG_AUDIO_FIFO_ALMOST_EMPTY_THRESHOLD           0x12

#define VRX_REG_AUDIO_COAST_MASK                            0x13
#define VRX_BIT_AC_MSK_VCLK_CHNG                            0x40
#define VRX_BIT_AC_MSK_VPLL_UNLOCK                          0x20
#define VRX_BIT_AC_MSK_NEW_CTS                              0x08
#define VRX_BIT_AC_MSK_NEW_N                                0x04
#define VRX_BIT_AC_MSK_CHNG_PORT                            0x02
#define VRX_BIT_AC_MSK_VCLK_DET                             0x01

#define VRX_REG_MUTE_MASK_21_16                             0x14
#define VRX_BIT_MT_MSK_COMPRS_AUD                           0x20
#define VRX_BIT_MT_MSK_AUD_MODE_CHNG                        0x10
#define VRX_BIT_MT_MSK_PARITY_ERR                           0x02
#define VRX_BIT_MT_MSK_VCLK_CHNG                            0x01

#define VRX_REG_MUTE_MASK_15_8                              0x15
#define VRX_BIT_MT_MSK_APLL_UNLOCK                          0x80
#define VRX_BIT_MT_MSK_VPLL_UNLOCK                          0x40
#define VRX_BIT_MT_MSK_ACR_NOT_DET                          0x20
#define VRX_BIT_MT_MSK_FLATLINE_DET                         0x08
#define VRX_BIT_MT_MSK_FIFO_UNDERLFOW                       0x02
#define VRX_BIT_MT_MSK_FIFO_OVERFLOW                        0x01

#define VRX_REG_MUTE_MASK_7_0                               0x16
#define VRX_BIT_MT_MSK_AVMUTE                               0x80
#define VRX_BIT_MT_MSK_NOT_HDMIMODE                         0x40
#define VRX_BIT_MT_MSK_NEW_CTS                              0x20
#define VRX_BIT_MT_MSK_NEW_N                                0x10
#define VRX_BIT_MT_MSK_CHMODE_CHNG                          0x08
#define VRX_BIT_MT_MSK_APCKT_ECC_ERR                        0x04
#define VRX_BIT_MT_MSK_CHNG_PORT                            0x02
#define VRX_BIT_MT_MSK_VCLK_DET                             0x01

#define VRX_REG_PACKETS_DETECTED_2                          0x18
#define VRX_BIT_HBR_AUDIO_PCKT_DET                          0x08
#define VRX_BIT_DST_AUDIO_PCKT_DET                          0x04
#define VRX_BIT_DSD_PACKET_DET                              0x02
#define VRX_BIT_AUDIO_SAMPLE_PCKT_DET                       0x01

#define VRX_REG_PACKETS_DETECTED_3                          0x19
#define VRX_BIT_DST_DOUBLE                                  0x04

#define VRX_REG_MUTE_CTRL                                   0x1A
#define VRX_BIT_IGNORE_PARITY_ERR                           0x40
#define VRX_BIT_MUTE_AUDIO                                  0x10
#define VRX_BIT_NOT_AUTO_UNMUTE                             0x01

#define VRX_REG_DEEPCOLOR_FIFO_DEBUG_1                      0x1B
#define VRX_BIT_DCFIFO_RESET_ON_LOCK                        0x10
#define VRX_BIT_DCFIFO_KILL_NOT_LOCKED                      0x08
#define VRX_BIT_DCFIFO_KILL_DIS                             0x04

#define VRX_REG_DEEPCOLOR_FIFO_DEBUG_2                      0x1C
#define VRX_BIT_DCFIFO_LOCKED                               0x08

#define VRX_REG_REGISTER_1DH                                0x1D
#define VRX_BIT_UP_CONVERSION_MODE                          0x20

#define VRX_REG_TOTAL_LINE_WIDTH_1                          0x1E

#define VRX_REG_TOTAL_LINE_WIDTH_2                          0x1F

#define VRX_REG_HSYNC_FRONT_PORCH_1                         0x20

#define VRX_REG_HSYNC_FRONT_PORCH_2                         0x21

#define VRX_REG_HSYNC_PULSE_WIDTH_1                         0x22

#define VRX_REG_HSYNC_PULSE_WIDTH_2                         0x23

#define VRX_REG_HSYNC_BACK_PORCH_1                          0x24

#define VRX_REG_HSYNC_BACK_PORCH_2                          0x25

#define VRX_REG_FIELD0_TOTAL_HEIGHT_1                       0x26

#define VRX_REG_FIELD0_TOTAL_HEIGHT_2                       0x27

#define VRX_REG_FIELD1_TOTAL_HEIGHT_1                       0x28

#define VRX_REG_FIELD1_TOTAL_HEIGHT_2                       0x29

#define VRX_REG_FIELD0_VS_FRONT_PORCH_1                     0x2A

#define VRX_REG_FIELD0_VS_FRONT_PORCH_2                     0x2B

#define VRX_REG_FIELD1_VS_FRONT_PORCH_1                     0x2C

#define VRX_REG_FIELD1_VS_FRONT_PORCH_2                     0x2D

#define VRX_REG_FIELD0_VS_PULSE_WIDTH_1                     0x2E

#define VRX_REG_FIELD0_VS_PULSE_WIDTH_2                     0x2F

#define VRX_REG_FIELD1_VS_PULSE_WIDTH_1                     0x30

#define VRX_REG_FIELD1_VS_PULSE_WIDTH_2                     0x31

#define VRX_REG_FIELD0_VS_BACK_PORCH_1                      0x32

#define VRX_REG_FIELD0_VS_BACK_PORCH_2                      0x33

#define VRX_REG_FIELD1_VS_BACK_PORCH_1                      0x34

#define VRX_REG_FIELD1_VS_BACK_PORCH_2                      0x35

#define VRX_REG_CHANNEL_STATUS_DATA_1                       0x36

#define VRX_REG_CHANNEL_STATUS_DATA_2                       0x37

#define VRX_REG_CHANNEL_STATUS_DATA_3                       0x38

#define VRX_REG_CHANNEL_STATUS_DATA_4                       0x39

#define VRX_REG_CHANNEL_STATUS_DATA_5                       0x3A

#define VRX_REG_REGISTER_40H                                0x40
#define VRX_BIT_OVERRIDE_DEEP_COLOR_MODE                    0x40

#define VRX_REG_REGISTER_41H                                0x41
#define VRX_BIT_DEREP_N_OVERRIDE                            0x10

#define VRX_REG_REGISTER_47H                                0x47
#define VRX_BIT_QZERO_ITC_DIS                               0x04
#define VRX_BIT_QZERO_RGB_FULL                              0x02
#define VRX_BIT_ALWAYS_STORE_INF                            0x01

#define VRX_REG_REGISTER_48H                                0x48
#define VRX_BIT_DIS_PWRDNB                                  0x80
#define VRX_BIT_DIS_CABLE_DET_RST                           0x40

#define VRX_REG_HDMI_REGISTER_50                            0x50
#define VRX_BIT_GAMUT_IRQ_NEXT_FIELD                        0x10
#define VRX_BIT_CS_COPYRIGHT_MANUAL                         0x02
#define VRX_BIT_CS_COPYRIGHT_VALUE                          0x01

#define VRX_REG_HDMI_COLORSPACE                             0x53

#define VRX_REG_FILT_5V_DET_REG                             0x56
#define VRX_BIT_FILT_5V_DET_DIS                             0x80

#define VRX_REG_REGISTER_5A                                 0x5A

#define VRX_REG_CTS_N_1                                     0x5B

#define VRX_REG_CTS_N_2                                     0x5C

#define VRX_REG_CTS_N_3                                     0x5D

#define VRX_REG_CTS_N_4                                     0x5E

#define VRX_REG_CTS_N_5                                     0x5F

#define VRX_BIT_HPA_OVR_TERM                                0x08
#define VRX_BIT_HPA_MANUAL                                  0x01

#define VRX_BIT_I2S_SPDIF_MAP_INV                           0x40
#define VRX_BIT_DSD_MAP_INV                                 0x08

#define VRX_BIT_VGA_PWRDN                                   0x10

#define VRX_REG_DDC_PAD                                     0x73

#define VRX_REG_EQ_DYNAMIC_FREQ                             0x8C

#define VRX_REG_EQ_DYN1_LF                                  0x8D

#define VRX_REG_EQ_DYN1_HF                                  0x8E

#define VRX_REG_EQ_DYN2_LF                                  0x90

#define VRX_REG_EQ_DYN2_HF                                  0x91

#define VRX_REG_EQ_DYN3_LF                                  0x93

#define VRX_REG_EQ_DYN3_HF                                  0x94

#define VRX_REG_EQ_DYNAMIC_ENABLE                           0x96
#define VRX_BIT_EQ_DYN_EN                                   0x01

#define VRX_REG_HEC_MUX_SEL                                 0xBC
#define VRX_BIT_HEC_TO_ETH_2_SEL_EN                         0x40
#define VRX_BIT_HEC_TO_ETH_1_SEL_EN                         0x04

#define VRX_REG_HEC_POWERDOWN                               0xBD
#define VRX_BIT_ETH_2_PWRDN                                 0x20
#define VRX_BIT_ETH_1_PWRDN                                 0x10

#define VRX_BIT_BG_PARAM_LOCK                               0x02
#define VRX_BIT_BG_HDMI_INTERLACED                          0x01

#define VRX_BIT_BG_HDMI_MODE                                0x01


#endif
