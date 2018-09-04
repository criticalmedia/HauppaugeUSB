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


#ifndef ADV7842_HDMI_MAP_FCT_H
#define ADV7842_HDMI_MAP_FCT_H

#include "ADV7842_cfg.h"

#define VRX_is_EN_BG_PORT_A_true()                          ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x00, 0x20, 0x5)
#define VRX_get_EN_BG_PORT_A(pval)                          ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x00, 0x20, 0x5, pval)
#define VRX_ret_EN_BG_PORT_A()                              ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x00, 0x20, 0x5)
#define VRX_set_EN_BG_PORT_A(val)                           ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x00, 0x20, 0x5, val)

#define VRX_is_EN_BG_PORT_B_true()                          ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x00, 0x10, 0x4)
#define VRX_get_EN_BG_PORT_B(pval)                          ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x00, 0x10, 0x4, pval)
#define VRX_ret_EN_BG_PORT_B()                              ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x00, 0x10, 0x4)
#define VRX_set_EN_BG_PORT_B(val)                           ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x00, 0x10, 0x4, val)

#define VRX_get_BG_MEAS_PORT_SEL(pval)                      ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x00, 0xC, 2, pval)
#define VRX_ret_BG_MEAS_PORT_SEL()                          ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x00, 0xC, 2)
#define VRX_set_BG_MEAS_PORT_SEL(val)                       ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x00, 0xC, 2, val)

#define VRX_get_HDMI_PORT_SELECT(pval)                      ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x00, 0x3, 0, pval)
#define VRX_ret_HDMI_PORT_SELECT()                          ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x00, 0x3, 0)
#define VRX_set_HDMI_PORT_SELECT(val)                       ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x00, 0x3, 0, val)

#define VRX_is_TERM_AUTO_true()                             ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x01, 0x80, 0x7)
#define VRX_get_TERM_AUTO(pval)                             ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x01, 0x80, 0x7, pval)
#define VRX_ret_TERM_AUTO()                                 ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x01, 0x80, 0x7)
#define VRX_set_TERM_AUTO(val)                              ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x01, 0x80, 0x7, val)

#define VRX_is_CLOCK_TERMB_DISABLE_true()                   ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x01, 0x40, 0x6)
#define VRX_get_CLOCK_TERMB_DISABLE(pval)                   ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x01, 0x40, 0x6, pval)
#define VRX_ret_CLOCK_TERMB_DISABLE()                       ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x01, 0x40, 0x6)
#define VRX_set_CLOCK_TERMB_DISABLE(val)                    ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x01, 0x40, 0x6, val)

#define VRX_is_CLOCK_TERMA_DISABLE_true()                   ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x01, 0x20, 0x5)
#define VRX_get_CLOCK_TERMA_DISABLE(pval)                   ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x01, 0x20, 0x5, pval)
#define VRX_ret_CLOCK_TERMA_DISABLE()                       ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x01, 0x20, 0x5)
#define VRX_set_CLOCK_TERMA_DISABLE(val)                    ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x01, 0x20, 0x5, val)

#define VRX_is_HDCP_ONLY_MODE_true()                        ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x01, 0x4, 0x2)
#define VRX_get_HDCP_ONLY_MODE(pval)                        ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x01, 0x4, 0x2, pval)
#define VRX_ret_HDCP_ONLY_MODE()                            ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x01, 0x4, 0x2)
#define VRX_set_HDCP_ONLY_MODE(val)                         ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x01, 0x4, 0x2, val)

#define VRX_is_OVR_MUX_HBR_true()                           ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x01, 0x2, 0x1)
#define VRX_get_OVR_MUX_HBR(pval)                           ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x01, 0x2, 0x1, pval)
#define VRX_ret_OVR_MUX_HBR()                               ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x01, 0x2, 0x1)
#define VRX_set_OVR_MUX_HBR(val)                            ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x01, 0x2, 0x1, val)

#define VRX_is_MUX_HBR_OUT_true()                           ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x01, 0x1, 0x0)
#define VRX_get_MUX_HBR_OUT(pval)                           ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x01, 0x1, 0x0, pval)
#define VRX_ret_MUX_HBR_OUT()                               ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x01, 0x1, 0x0)
#define VRX_set_MUX_HBR_OUT(val)                            ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x01, 0x1, 0x0, val)

#define VRX_is_HDCP_A0_true()                               ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x02, 0x8, 0x3)
#define VRX_get_HDCP_A0(pval)                               ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x02, 0x8, 0x3, pval)
#define VRX_ret_HDCP_A0()                                   ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x02, 0x8, 0x3)
#define VRX_set_HDCP_A0(val)                                ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x02, 0x8, 0x3, val)

#define VRX_is_OVR_AUTO_MUX_DSD_OUT_true()                  ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x02, 0x2, 0x1)
#define VRX_get_OVR_AUTO_MUX_DSD_OUT(pval)                  ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x02, 0x2, 0x1, pval)
#define VRX_ret_OVR_AUTO_MUX_DSD_OUT()                      ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x02, 0x2, 0x1)
#define VRX_set_OVR_AUTO_MUX_DSD_OUT(val)                   ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x02, 0x2, 0x1, val)

#define VRX_is_MUX_DSD_OUT_true()                           ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x02, 0x1, 0x0)
#define VRX_get_MUX_DSD_OUT(pval)                           ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x02, 0x1, 0x0, pval)
#define VRX_ret_MUX_DSD_OUT()                               ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x02, 0x1, 0x0)
#define VRX_set_MUX_DSD_OUT(val)                            ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x02, 0x1, 0x0, val)

#define VRX_get_I2SOUTMODE(pval)                            ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x03, 0x60, 5, pval)
#define VRX_ret_I2SOUTMODE()                                ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x03, 0x60, 5)
#define VRX_set_I2SOUTMODE(val)                             ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x03, 0x60, 5, val)

#define VRX_get_I2SBITWIDTH(pval)                           ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x03, 0x1F, 0, pval)
#define VRX_ret_I2SBITWIDTH()                               ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x03, 0x1F, 0)
#define VRX_set_I2SBITWIDTH(val)                            ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x03, 0x1F, 0, val)

#define VRX_is_AV_MUTE_true()                               ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x04, 0x40, 0x6)
#define VRX_get_AV_MUTE(pval)                               ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x04, 0x40, 0x6, pval)
#define VRX_ret_AV_MUTE()                                   ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x04, 0x40, 0x6)

#define VRX_is_HDCP_KEYS_READ_true()                        ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x04, 0x20, 0x5)
#define VRX_get_HDCP_KEYS_READ(pval)                        ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x04, 0x20, 0x5, pval)
#define VRX_ret_HDCP_KEYS_READ()                            ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x04, 0x20, 0x5)

#define VRX_is_HDCP_KEY_ERROR_true()                        ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x04, 0x10, 0x4)
#define VRX_get_HDCP_KEY_ERROR(pval)                        ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x04, 0x10, 0x4, pval)
#define VRX_ret_HDCP_KEY_ERROR()                            ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x04, 0x10, 0x4)

#define VRX_is_TMDS_PLL_LOCKED_true()                       ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x04, 0x2, 0x1)
#define VRX_get_TMDS_PLL_LOCKED(pval)                       ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x04, 0x2, 0x1, pval)
#define VRX_ret_TMDS_PLL_LOCKED()                           ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x04, 0x2, 0x1)

#define VRX_is_AUDIO_PLL_LOCKED_true()                      ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x04, 0x1, 0x0)
#define VRX_get_AUDIO_PLL_LOCKED(pval)                      ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x04, 0x1, 0x0, pval)
#define VRX_ret_AUDIO_PLL_LOCKED()                          ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x04, 0x1, 0x0)

#define VRX_is_HDMI_MODE_true()                             ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x05, 0x80, 0x7)
#define VRX_get_HDMI_MODE(pval)                             ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x05, 0x80, 0x7, pval)
#define VRX_ret_HDMI_MODE()                                 ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x05, 0x80, 0x7)

#define VRX_is_HDMI_CONTENT_ENCRYPTED_true()                ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x05, 0x40, 0x6)
#define VRX_get_HDMI_CONTENT_ENCRYPTED(pval)                ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x05, 0x40, 0x6, pval)
#define VRX_ret_HDMI_CONTENT_ENCRYPTED()                    ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x05, 0x40, 0x6)

#define VRX_is_DVI_HSYNC_POLARITY_true()                    ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x05, 0x20, 0x5)
#define VRX_get_DVI_HSYNC_POLARITY(pval)                    ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x05, 0x20, 0x5, pval)
#define VRX_ret_DVI_HSYNC_POLARITY()                        ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x05, 0x20, 0x5)

#define VRX_is_DVI_VSYNC_POLARITY_true()                    ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x05, 0x10, 0x4)
#define VRX_get_DVI_VSYNC_POLARITY(pval)                    ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x05, 0x10, 0x4, pval)
#define VRX_ret_DVI_VSYNC_POLARITY()                        ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x05, 0x10, 0x4)

#define VRX_get_HDMI_PIXEL_REPETITION(pval)                 ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x05, 0xF, 0, pval)
#define VRX_ret_HDMI_PIXEL_REPETITION()                     ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x05, 0xF, 0)

#define VRX_is_VERT_FILTER_LOCKED_true()                    ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x07, 0x80, 0x7)
#define VRX_get_VERT_FILTER_LOCKED(pval)                    ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x07, 0x80, 0x7, pval)
#define VRX_ret_VERT_FILTER_LOCKED()                        ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x07, 0x80, 0x7)

#define VRX_is_AUDIO_CHANNEL_MODE_true()                    ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x07, 0x40, 0x6)
#define VRX_get_AUDIO_CHANNEL_MODE(pval)                    ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x07, 0x40, 0x6, pval)
#define VRX_ret_AUDIO_CHANNEL_MODE()                        ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x07, 0x40, 0x6)

#define VRX_is_DE_REGEN_FILTER_LOCKED_true()                ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x07, 0x20, 0x5)
#define VRX_get_DE_REGEN_FILTER_LOCKED(pval)                ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x07, 0x20, 0x5, pval)
#define VRX_ret_DE_REGEN_FILTER_LOCKED()                    ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x07, 0x20, 0x5)

#define VRX_get_LINE_WIDTH(pval)                            ATV_I2CGetField32(VRX_HDMI_MAP_ADDR, 0x07, 0x1F, 0xFF, 0, 2, pval)
#define VRX_ret_LINE_WIDTH()                                ATV_I2CReadField32(VRX_HDMI_MAP_ADDR, 0x07, 0x1F, 0xFF, 0, 2)

#define VRX_get_FIELD0_HEIGHT(pval)                         ATV_I2CGetField32(VRX_HDMI_MAP_ADDR, 0x09, 0x1F, 0xFF, 0, 2, pval)
#define VRX_ret_FIELD0_HEIGHT()                             ATV_I2CReadField32(VRX_HDMI_MAP_ADDR, 0x09, 0x1F, 0xFF, 0, 2)

#define VRX_get_DEEP_COLOR_MODE(pval)                       ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x0B, 0xC0, 6, pval)
#define VRX_ret_DEEP_COLOR_MODE()                           ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x0B, 0xC0, 6)

#define VRX_is_HDMI_INTERLACED_true()                       ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x0B, 0x20, 0x5)
#define VRX_get_HDMI_INTERLACED(pval)                       ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x0B, 0x20, 0x5, pval)
#define VRX_ret_HDMI_INTERLACED()                           ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x0B, 0x20, 0x5)

#define VRX_get_FIELD1_HEIGHT(pval)                         ATV_I2CGetField32(VRX_HDMI_MAP_ADDR, 0x0B, 0x1F, 0xFF, 0, 2, pval)
#define VRX_ret_FIELD1_HEIGHT()                             ATV_I2CReadField32(VRX_HDMI_MAP_ADDR, 0x0B, 0x1F, 0xFF, 0, 2)

#define VRX_get_FREQTOLERANCE(pval)                         ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x0D, 0xF, 0, pval)
#define VRX_ret_FREQTOLERANCE()                             ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x0D, 0xF, 0)
#define VRX_set_FREQTOLERANCE(val)                          ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x0D, 0xF, 0, val)

#define VRX_is_MAN_AUDIO_DL_BYPASS_true()                   ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x0F, 0x80, 0x7)
#define VRX_get_MAN_AUDIO_DL_BYPASS(pval)                   ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x0F, 0x80, 0x7, pval)
#define VRX_ret_MAN_AUDIO_DL_BYPASS()                       ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x0F, 0x80, 0x7)
#define VRX_set_MAN_AUDIO_DL_BYPASS(val)                    ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x0F, 0x80, 0x7, val)

#define VRX_is_AUDIO_DELAY_LINE_BYPASS_true()               ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x0F, 0x40, 0x6)
#define VRX_get_AUDIO_DELAY_LINE_BYPASS(pval)               ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x0F, 0x40, 0x6, pval)
#define VRX_ret_AUDIO_DELAY_LINE_BYPASS()                   ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x0F, 0x40, 0x6)
#define VRX_set_AUDIO_DELAY_LINE_BYPASS(val)                ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x0F, 0x40, 0x6, val)

#define VRX_get_AUDIO_MUTE_SPEED(pval)                      ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x0F, 0x1F, 0, pval)
#define VRX_ret_AUDIO_MUTE_SPEED()                          ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x0F, 0x1F, 0)
#define VRX_set_AUDIO_MUTE_SPEED(val)                       ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x0F, 0x1F, 0, val)

#define VRX_get_CTS_CHANGE_THRESHOLD(pval)                  ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x10, 0x3F, 0, pval)
#define VRX_ret_CTS_CHANGE_THRESHOLD()                      ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x10, 0x3F, 0)
#define VRX_set_CTS_CHANGE_THRESHOLD(val)                   ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x10, 0x3F, 0, val)

#define VRX_get_AUDIO_FIFO_ALMOST_FULL_THRESHOLD(pval)      ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x11, 0x7F, 0, pval)
#define VRX_ret_AUDIO_FIFO_ALMOST_FULL_THRESHOLD()          ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x11, 0x7F, 0)
#define VRX_set_AUDIO_FIFO_ALMOST_FULL_THRESHOLD(val)       ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x11, 0x7F, 0, val)

#define VRX_get_AUDIO_FIFO_ALMOST_EMPTY_THRESHOLD(pval)     ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x12, 0x7F, 0, pval)
#define VRX_ret_AUDIO_FIFO_ALMOST_EMPTY_THRESHOLD()         ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x12, 0x7F, 0)
#define VRX_set_AUDIO_FIFO_ALMOST_EMPTY_THRESHOLD(val)      ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x12, 0x7F, 0, val)

#define VRX_is_AC_MSK_VCLK_CHNG_true()                      ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x13, 0x40, 0x6)
#define VRX_get_AC_MSK_VCLK_CHNG(pval)                      ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x13, 0x40, 0x6, pval)
#define VRX_ret_AC_MSK_VCLK_CHNG()                          ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x13, 0x40, 0x6)
#define VRX_set_AC_MSK_VCLK_CHNG(val)                       ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x13, 0x40, 0x6, val)

#define VRX_is_AC_MSK_VPLL_UNLOCK_true()                    ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x13, 0x20, 0x5)
#define VRX_get_AC_MSK_VPLL_UNLOCK(pval)                    ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x13, 0x20, 0x5, pval)
#define VRX_ret_AC_MSK_VPLL_UNLOCK()                        ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x13, 0x20, 0x5)
#define VRX_set_AC_MSK_VPLL_UNLOCK(val)                     ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x13, 0x20, 0x5, val)

#define VRX_is_AC_MSK_NEW_CTS_true()                        ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x13, 0x8, 0x3)
#define VRX_get_AC_MSK_NEW_CTS(pval)                        ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x13, 0x8, 0x3, pval)
#define VRX_ret_AC_MSK_NEW_CTS()                            ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x13, 0x8, 0x3)
#define VRX_set_AC_MSK_NEW_CTS(val)                         ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x13, 0x8, 0x3, val)

#define VRX_is_AC_MSK_NEW_N_true()                          ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x13, 0x4, 0x2)
#define VRX_get_AC_MSK_NEW_N(pval)                          ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x13, 0x4, 0x2, pval)
#define VRX_ret_AC_MSK_NEW_N()                              ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x13, 0x4, 0x2)
#define VRX_set_AC_MSK_NEW_N(val)                           ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x13, 0x4, 0x2, val)

#define VRX_is_AC_MSK_CHNG_PORT_true()                      ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x13, 0x2, 0x1)
#define VRX_get_AC_MSK_CHNG_PORT(pval)                      ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x13, 0x2, 0x1, pval)
#define VRX_ret_AC_MSK_CHNG_PORT()                          ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x13, 0x2, 0x1)
#define VRX_set_AC_MSK_CHNG_PORT(val)                       ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x13, 0x2, 0x1, val)

#define VRX_is_AC_MSK_VCLK_DET_true()                       ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x13, 0x1, 0x0)
#define VRX_get_AC_MSK_VCLK_DET(pval)                       ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x13, 0x1, 0x0, pval)
#define VRX_ret_AC_MSK_VCLK_DET()                           ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x13, 0x1, 0x0)
#define VRX_set_AC_MSK_VCLK_DET(val)                        ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x13, 0x1, 0x0, val)

#define VRX_is_MT_MSK_COMPRS_AUD_true()                     ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x14, 0x20, 0x5)
#define VRX_get_MT_MSK_COMPRS_AUD(pval)                     ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x14, 0x20, 0x5, pval)
#define VRX_ret_MT_MSK_COMPRS_AUD()                         ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x14, 0x20, 0x5)
#define VRX_set_MT_MSK_COMPRS_AUD(val)                      ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x14, 0x20, 0x5, val)

#define VRX_is_MT_MSK_AUD_MODE_CHNG_true()                  ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x14, 0x10, 0x4)
#define VRX_get_MT_MSK_AUD_MODE_CHNG(pval)                  ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x14, 0x10, 0x4, pval)
#define VRX_ret_MT_MSK_AUD_MODE_CHNG()                      ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x14, 0x10, 0x4)
#define VRX_set_MT_MSK_AUD_MODE_CHNG(val)                   ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x14, 0x10, 0x4, val)

#define VRX_is_MT_MSK_PARITY_ERR_true()                     ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x14, 0x2, 0x1)
#define VRX_get_MT_MSK_PARITY_ERR(pval)                     ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x14, 0x2, 0x1, pval)
#define VRX_ret_MT_MSK_PARITY_ERR()                         ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x14, 0x2, 0x1)
#define VRX_set_MT_MSK_PARITY_ERR(val)                      ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x14, 0x2, 0x1, val)

#define VRX_is_MT_MSK_VCLK_CHNG_true()                      ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x14, 0x1, 0x0)
#define VRX_get_MT_MSK_VCLK_CHNG(pval)                      ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x14, 0x1, 0x0, pval)
#define VRX_ret_MT_MSK_VCLK_CHNG()                          ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x14, 0x1, 0x0)
#define VRX_set_MT_MSK_VCLK_CHNG(val)                       ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x14, 0x1, 0x0, val)

#define VRX_is_MT_MSK_APLL_UNLOCK_true()                    ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x15, 0x80, 0x7)
#define VRX_get_MT_MSK_APLL_UNLOCK(pval)                    ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x15, 0x80, 0x7, pval)
#define VRX_ret_MT_MSK_APLL_UNLOCK()                        ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x15, 0x80, 0x7)
#define VRX_set_MT_MSK_APLL_UNLOCK(val)                     ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x15, 0x80, 0x7, val)

#define VRX_is_MT_MSK_VPLL_UNLOCK_true()                    ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x15, 0x40, 0x6)
#define VRX_get_MT_MSK_VPLL_UNLOCK(pval)                    ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x15, 0x40, 0x6, pval)
#define VRX_ret_MT_MSK_VPLL_UNLOCK()                        ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x15, 0x40, 0x6)
#define VRX_set_MT_MSK_VPLL_UNLOCK(val)                     ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x15, 0x40, 0x6, val)

#define VRX_is_MT_MSK_ACR_NOT_DET_true()                    ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x15, 0x20, 0x5)
#define VRX_get_MT_MSK_ACR_NOT_DET(pval)                    ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x15, 0x20, 0x5, pval)
#define VRX_ret_MT_MSK_ACR_NOT_DET()                        ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x15, 0x20, 0x5)
#define VRX_set_MT_MSK_ACR_NOT_DET(val)                     ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x15, 0x20, 0x5, val)

#define VRX_is_MT_MSK_FLATLINE_DET_true()                   ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x15, 0x8, 0x3)
#define VRX_get_MT_MSK_FLATLINE_DET(pval)                   ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x15, 0x8, 0x3, pval)
#define VRX_ret_MT_MSK_FLATLINE_DET()                       ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x15, 0x8, 0x3)
#define VRX_set_MT_MSK_FLATLINE_DET(val)                    ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x15, 0x8, 0x3, val)

#define VRX_is_MT_MSK_FIFO_UNDERLFOW_true()                 ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x15, 0x2, 0x1)
#define VRX_get_MT_MSK_FIFO_UNDERLFOW(pval)                 ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x15, 0x2, 0x1, pval)
#define VRX_ret_MT_MSK_FIFO_UNDERLFOW()                     ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x15, 0x2, 0x1)
#define VRX_set_MT_MSK_FIFO_UNDERLFOW(val)                  ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x15, 0x2, 0x1, val)

#define VRX_is_MT_MSK_FIFO_OVERFLOW_true()                  ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x15, 0x1, 0x0)
#define VRX_get_MT_MSK_FIFO_OVERFLOW(pval)                  ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x15, 0x1, 0x0, pval)
#define VRX_ret_MT_MSK_FIFO_OVERFLOW()                      ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x15, 0x1, 0x0)
#define VRX_set_MT_MSK_FIFO_OVERFLOW(val)                   ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x15, 0x1, 0x0, val)

#define VRX_is_MT_MSK_AVMUTE_true()                         ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x16, 0x80, 0x7)
#define VRX_get_MT_MSK_AVMUTE(pval)                         ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x16, 0x80, 0x7, pval)
#define VRX_ret_MT_MSK_AVMUTE()                             ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x16, 0x80, 0x7)
#define VRX_set_MT_MSK_AVMUTE(val)                          ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x16, 0x80, 0x7, val)

#define VRX_is_MT_MSK_NOT_HDMIMODE_true()                   ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x16, 0x40, 0x6)
#define VRX_get_MT_MSK_NOT_HDMIMODE(pval)                   ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x16, 0x40, 0x6, pval)
#define VRX_ret_MT_MSK_NOT_HDMIMODE()                       ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x16, 0x40, 0x6)
#define VRX_set_MT_MSK_NOT_HDMIMODE(val)                    ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x16, 0x40, 0x6, val)

#define VRX_is_MT_MSK_NEW_CTS_true()                        ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x16, 0x20, 0x5)
#define VRX_get_MT_MSK_NEW_CTS(pval)                        ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x16, 0x20, 0x5, pval)
#define VRX_ret_MT_MSK_NEW_CTS()                            ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x16, 0x20, 0x5)
#define VRX_set_MT_MSK_NEW_CTS(val)                         ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x16, 0x20, 0x5, val)

#define VRX_is_MT_MSK_NEW_N_true()                          ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x16, 0x10, 0x4)
#define VRX_get_MT_MSK_NEW_N(pval)                          ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x16, 0x10, 0x4, pval)
#define VRX_ret_MT_MSK_NEW_N()                              ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x16, 0x10, 0x4)
#define VRX_set_MT_MSK_NEW_N(val)                           ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x16, 0x10, 0x4, val)

#define VRX_is_MT_MSK_CHMODE_CHNG_true()                    ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x16, 0x8, 0x3)
#define VRX_get_MT_MSK_CHMODE_CHNG(pval)                    ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x16, 0x8, 0x3, pval)
#define VRX_ret_MT_MSK_CHMODE_CHNG()                        ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x16, 0x8, 0x3)
#define VRX_set_MT_MSK_CHMODE_CHNG(val)                     ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x16, 0x8, 0x3, val)

#define VRX_is_MT_MSK_APCKT_ECC_ERR_true()                  ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x16, 0x4, 0x2)
#define VRX_get_MT_MSK_APCKT_ECC_ERR(pval)                  ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x16, 0x4, 0x2, pval)
#define VRX_ret_MT_MSK_APCKT_ECC_ERR()                      ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x16, 0x4, 0x2)
#define VRX_set_MT_MSK_APCKT_ECC_ERR(val)                   ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x16, 0x4, 0x2, val)

#define VRX_is_MT_MSK_CHNG_PORT_true()                      ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x16, 0x2, 0x1)
#define VRX_get_MT_MSK_CHNG_PORT(pval)                      ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x16, 0x2, 0x1, pval)
#define VRX_ret_MT_MSK_CHNG_PORT()                          ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x16, 0x2, 0x1)
#define VRX_set_MT_MSK_CHNG_PORT(val)                       ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x16, 0x2, 0x1, val)

#define VRX_is_MT_MSK_VCLK_DET_true()                       ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x16, 0x1, 0x0)
#define VRX_get_MT_MSK_VCLK_DET(pval)                       ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x16, 0x1, 0x0, pval)
#define VRX_ret_MT_MSK_VCLK_DET()                           ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x16, 0x1, 0x0)
#define VRX_set_MT_MSK_VCLK_DET(val)                        ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x16, 0x1, 0x0, val)

#define VRX_is_HBR_AUDIO_PCKT_DET_true()                    ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x18, 0x8, 0x3)
#define VRX_get_HBR_AUDIO_PCKT_DET(pval)                    ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x18, 0x8, 0x3, pval)
#define VRX_ret_HBR_AUDIO_PCKT_DET()                        ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x18, 0x8, 0x3)

#define VRX_is_DST_AUDIO_PCKT_DET_true()                    ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x18, 0x4, 0x2)
#define VRX_get_DST_AUDIO_PCKT_DET(pval)                    ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x18, 0x4, 0x2, pval)
#define VRX_ret_DST_AUDIO_PCKT_DET()                        ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x18, 0x4, 0x2)

#define VRX_is_DSD_PACKET_DET_true()                        ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x18, 0x2, 0x1)
#define VRX_get_DSD_PACKET_DET(pval)                        ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x18, 0x2, 0x1, pval)
#define VRX_ret_DSD_PACKET_DET()                            ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x18, 0x2, 0x1)

#define VRX_is_AUDIO_SAMPLE_PCKT_DET_true()                 ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x18, 0x1, 0x0)
#define VRX_get_AUDIO_SAMPLE_PCKT_DET(pval)                 ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x18, 0x1, 0x0, pval)
#define VRX_ret_AUDIO_SAMPLE_PCKT_DET()                     ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x18, 0x1, 0x0)

#define VRX_is_DST_DOUBLE_true()                            ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x19, 0x4, 0x2)
#define VRX_get_DST_DOUBLE(pval)                            ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x19, 0x4, 0x2, pval)
#define VRX_ret_DST_DOUBLE()                                ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x19, 0x4, 0x2)

#define VRX_is_IGNORE_PARITY_ERR_true()                     ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x1A, 0x40, 0x6)
#define VRX_get_IGNORE_PARITY_ERR(pval)                     ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x1A, 0x40, 0x6, pval)
#define VRX_ret_IGNORE_PARITY_ERR()                         ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x1A, 0x40, 0x6)
#define VRX_set_IGNORE_PARITY_ERR(val)                      ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x1A, 0x40, 0x6, val)

#define VRX_is_MUTE_AUDIO_true()                            ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x1A, 0x10, 0x4)
#define VRX_get_MUTE_AUDIO(pval)                            ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x1A, 0x10, 0x4, pval)
#define VRX_ret_MUTE_AUDIO()                                ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x1A, 0x10, 0x4)
#define VRX_set_MUTE_AUDIO(val)                             ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x1A, 0x10, 0x4, val)

#define VRX_get_WAIT_UNMUTE(pval)                           ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x1A, 0xE, 1, pval)
#define VRX_ret_WAIT_UNMUTE()                               ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x1A, 0xE, 1)
#define VRX_set_WAIT_UNMUTE(val)                            ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x1A, 0xE, 1, val)

#define VRX_is_NOT_AUTO_UNMUTE_true()                       ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x1A, 0x1, 0x0)
#define VRX_get_NOT_AUTO_UNMUTE(pval)                       ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x1A, 0x1, 0x0, pval)
#define VRX_ret_NOT_AUTO_UNMUTE()                           ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x1A, 0x1, 0x0)
#define VRX_set_NOT_AUTO_UNMUTE(val)                        ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x1A, 0x1, 0x0, val)

#define VRX_is_DCFIFO_RESET_ON_LOCK_true()                  ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x1B, 0x10, 0x4)
#define VRX_get_DCFIFO_RESET_ON_LOCK(pval)                  ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x1B, 0x10, 0x4, pval)
#define VRX_ret_DCFIFO_RESET_ON_LOCK()                      ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x1B, 0x10, 0x4)
#define VRX_set_DCFIFO_RESET_ON_LOCK(val)                   ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x1B, 0x10, 0x4, val)

#define VRX_is_DCFIFO_KILL_NOT_LOCKED_true()                ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x1B, 0x8, 0x3)
#define VRX_get_DCFIFO_KILL_NOT_LOCKED(pval)                ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x1B, 0x8, 0x3, pval)
#define VRX_ret_DCFIFO_KILL_NOT_LOCKED()                    ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x1B, 0x8, 0x3)
#define VRX_set_DCFIFO_KILL_NOT_LOCKED(val)                 ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x1B, 0x8, 0x3, val)

#define VRX_is_DCFIFO_KILL_DIS_true()                       ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x1B, 0x4, 0x2)
#define VRX_get_DCFIFO_KILL_DIS(pval)                       ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x1B, 0x4, 0x2, pval)
#define VRX_ret_DCFIFO_KILL_DIS()                           ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x1B, 0x4, 0x2)
#define VRX_set_DCFIFO_KILL_DIS(val)                        ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x1B, 0x4, 0x2, val)

#define VRX_is_DCFIFO_LOCKED_true()                         ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x1C, 0x8, 0x3)
#define VRX_get_DCFIFO_LOCKED(pval)                         ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x1C, 0x8, 0x3, pval)
#define VRX_ret_DCFIFO_LOCKED()                             ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x1C, 0x8, 0x3)

#define VRX_get_DCFIFO_LEVEL(pval)                          ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x1C, 0x7, 0, pval)
#define VRX_ret_DCFIFO_LEVEL()                              ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x1C, 0x7, 0)

#define VRX_is_UP_CONVERSION_MODE_true()                    ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x1D, 0x20, 0x5)
#define VRX_get_UP_CONVERSION_MODE(pval)                    ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x1D, 0x20, 0x5, pval)
#define VRX_ret_UP_CONVERSION_MODE()                        ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x1D, 0x20, 0x5)
#define VRX_set_UP_CONVERSION_MODE(val)                     ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x1D, 0x20, 0x5, val)

#define VRX_get_TOTAL_LINE_WIDTH(pval)                      ATV_I2CGetField32(VRX_HDMI_MAP_ADDR, 0x1E, 0x3F, 0xFF, 0, 2, pval)
#define VRX_ret_TOTAL_LINE_WIDTH()                          ATV_I2CReadField32(VRX_HDMI_MAP_ADDR, 0x1E, 0x3F, 0xFF, 0, 2)

#define VRX_get_HSYNC_FRONT_PORCH(pval)                     ATV_I2CGetField32(VRX_HDMI_MAP_ADDR, 0x20, 0x1F, 0xFF, 0, 2, pval)
#define VRX_ret_HSYNC_FRONT_PORCH()                         ATV_I2CReadField32(VRX_HDMI_MAP_ADDR, 0x20, 0x1F, 0xFF, 0, 2)

#define VRX_get_HSYNC_PULSE_WIDTH(pval)                     ATV_I2CGetField32(VRX_HDMI_MAP_ADDR, 0x22, 0x1F, 0xFF, 0, 2, pval)
#define VRX_ret_HSYNC_PULSE_WIDTH()                         ATV_I2CReadField32(VRX_HDMI_MAP_ADDR, 0x22, 0x1F, 0xFF, 0, 2)

#define VRX_get_HSYNC_BACK_PORCH(pval)                      ATV_I2CGetField32(VRX_HDMI_MAP_ADDR, 0x24, 0x1F, 0xFF, 0, 2, pval)
#define VRX_ret_HSYNC_BACK_PORCH()                          ATV_I2CReadField32(VRX_HDMI_MAP_ADDR, 0x24, 0x1F, 0xFF, 0, 2)

#define VRX_get_FIELD0_TOTAL_HEIGHT(pval)                   ATV_I2CGetField32(VRX_HDMI_MAP_ADDR, 0x26, 0x3F, 0xFF, 0, 2, pval)
#define VRX_ret_FIELD0_TOTAL_HEIGHT()                       ATV_I2CReadField32(VRX_HDMI_MAP_ADDR, 0x26, 0x3F, 0xFF, 0, 2)

#define VRX_get_FIELD1_TOTAL_HEIGHT(pval)                   ATV_I2CGetField32(VRX_HDMI_MAP_ADDR, 0x28, 0x3F, 0xFF, 0, 2, pval)
#define VRX_ret_FIELD1_TOTAL_HEIGHT()                       ATV_I2CReadField32(VRX_HDMI_MAP_ADDR, 0x28, 0x3F, 0xFF, 0, 2)

#define VRX_get_FIELD0_VS_FRONT_PORCH(pval)                 ATV_I2CGetField32(VRX_HDMI_MAP_ADDR, 0x2A, 0x3F, 0xFF, 0, 2, pval)
#define VRX_ret_FIELD0_VS_FRONT_PORCH()                     ATV_I2CReadField32(VRX_HDMI_MAP_ADDR, 0x2A, 0x3F, 0xFF, 0, 2)

#define VRX_get_FIELD1_VS_FRONT_PORCH(pval)                 ATV_I2CGetField32(VRX_HDMI_MAP_ADDR, 0x2C, 0x3F, 0xFF, 0, 2, pval)
#define VRX_ret_FIELD1_VS_FRONT_PORCH()                     ATV_I2CReadField32(VRX_HDMI_MAP_ADDR, 0x2C, 0x3F, 0xFF, 0, 2)

#define VRX_get_FIELD0_VS_PULSE_WIDTH(pval)                 ATV_I2CGetField32(VRX_HDMI_MAP_ADDR, 0x2E, 0x3F, 0xFF, 0, 2, pval)
#define VRX_ret_FIELD0_VS_PULSE_WIDTH()                     ATV_I2CReadField32(VRX_HDMI_MAP_ADDR, 0x2E, 0x3F, 0xFF, 0, 2)

#define VRX_get_FIELD1_VS_PULSE_WIDTH(pval)                 ATV_I2CGetField32(VRX_HDMI_MAP_ADDR, 0x30, 0x3F, 0xFF, 0, 2, pval)
#define VRX_ret_FIELD1_VS_PULSE_WIDTH()                     ATV_I2CReadField32(VRX_HDMI_MAP_ADDR, 0x30, 0x3F, 0xFF, 0, 2)

#define VRX_get_FIELD0_VS_BACK_PORCH(pval)                  ATV_I2CGetField32(VRX_HDMI_MAP_ADDR, 0x32, 0x3F, 0xFF, 0, 2, pval)
#define VRX_ret_FIELD0_VS_BACK_PORCH()                      ATV_I2CReadField32(VRX_HDMI_MAP_ADDR, 0x32, 0x3F, 0xFF, 0, 2)

#define VRX_get_FIELD1_VS_BACK_PORCH(pval)                  ATV_I2CGetField32(VRX_HDMI_MAP_ADDR, 0x34, 0x3F, 0xFF, 0, 2, pval)
#define VRX_ret_FIELD1_VS_BACK_PORCH()                      ATV_I2CReadField32(VRX_HDMI_MAP_ADDR, 0x34, 0x3F, 0xFF, 0, 2)

#define VRX_get_CS_DATA(pval)                               ATV_I2CGetMultiField(VRX_HDMI_MAP_ADDR, 0x36, 5, pval)

#define VRX_is_OVERRIDE_DEEP_COLOR_MODE_true()              ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x40, 0x40, 0x6)
#define VRX_get_OVERRIDE_DEEP_COLOR_MODE(pval)              ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x40, 0x40, 0x6, pval)
#define VRX_ret_OVERRIDE_DEEP_COLOR_MODE()                  ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x40, 0x40, 0x6)
#define VRX_set_OVERRIDE_DEEP_COLOR_MODE(val)               ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x40, 0x40, 0x6, val)

#define VRX_get_DEEP_COLOR_MODE_USER(pval)                  ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x40, 0x30, 4, pval)
#define VRX_ret_DEEP_COLOR_MODE_USER()                      ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x40, 0x30, 4)
#define VRX_set_DEEP_COLOR_MODE_USER(val)                   ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x40, 0x30, 4, val)

#define VRX_is_DEREP_N_OVERRIDE_true()                      ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x41, 0x10, 0x4)
#define VRX_get_DEREP_N_OVERRIDE(pval)                      ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x41, 0x10, 0x4, pval)
#define VRX_ret_DEREP_N_OVERRIDE()                          ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x41, 0x10, 0x4)
#define VRX_set_DEREP_N_OVERRIDE(val)                       ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x41, 0x10, 0x4, val)

#define VRX_get_DEREP_N(pval)                               ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x41, 0xF, 0, pval)
#define VRX_ret_DEREP_N()                                   ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x41, 0xF, 0)
#define VRX_set_DEREP_N(val)                                ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x41, 0xF, 0, val)

#define VRX_is_QZERO_ITC_DIS_true()                         ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x47, 0x4, 0x2)
#define VRX_get_QZERO_ITC_DIS(pval)                         ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x47, 0x4, 0x2, pval)
#define VRX_ret_QZERO_ITC_DIS()                             ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x47, 0x4, 0x2)
#define VRX_set_QZERO_ITC_DIS(val)                          ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x47, 0x4, 0x2, val)

#define VRX_is_QZERO_RGB_FULL_true()                        ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x47, 0x2, 0x1)
#define VRX_get_QZERO_RGB_FULL(pval)                        ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x47, 0x2, 0x1, pval)
#define VRX_ret_QZERO_RGB_FULL()                            ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x47, 0x2, 0x1)
#define VRX_set_QZERO_RGB_FULL(val)                         ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x47, 0x2, 0x1, val)

#define VRX_is_ALWAYS_STORE_INF_true()                      ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x47, 0x1, 0x0)
#define VRX_get_ALWAYS_STORE_INF(pval)                      ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x47, 0x1, 0x0, pval)
#define VRX_ret_ALWAYS_STORE_INF()                          ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x47, 0x1, 0x0)
#define VRX_set_ALWAYS_STORE_INF(val)                       ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x47, 0x1, 0x0, val)

#define VRX_is_DIS_PWRDNB_true()                            ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x48, 0x80, 0x7)
#define VRX_get_DIS_PWRDNB(pval)                            ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x48, 0x80, 0x7, pval)
#define VRX_ret_DIS_PWRDNB()                                ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x48, 0x80, 0x7)
#define VRX_set_DIS_PWRDNB(val)                             ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x48, 0x80, 0x7, val)

#define VRX_is_DIS_CABLE_DET_RST_true()                     ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x48, 0x40, 0x6)
#define VRX_get_DIS_CABLE_DET_RST(pval)                     ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x48, 0x40, 0x6, pval)
#define VRX_ret_DIS_CABLE_DET_RST()                         ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x48, 0x40, 0x6)
#define VRX_set_DIS_CABLE_DET_RST(val)                      ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x48, 0x40, 0x6, val)

#define VRX_is_GAMUT_IRQ_NEXT_FIELD_true()                  ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x50, 0x10, 0x4)
#define VRX_get_GAMUT_IRQ_NEXT_FIELD(pval)                  ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x50, 0x10, 0x4, pval)
#define VRX_ret_GAMUT_IRQ_NEXT_FIELD()                      ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x50, 0x10, 0x4)
#define VRX_set_GAMUT_IRQ_NEXT_FIELD(val)                   ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x50, 0x10, 0x4, val)

#define VRX_is_CS_COPYRIGHT_MANUAL_true()                   ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x50, 0x2, 0x1)
#define VRX_get_CS_COPYRIGHT_MANUAL(pval)                   ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x50, 0x2, 0x1, pval)
#define VRX_ret_CS_COPYRIGHT_MANUAL()                       ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x50, 0x2, 0x1)
#define VRX_set_CS_COPYRIGHT_MANUAL(val)                    ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x50, 0x2, 0x1, val)

#define VRX_is_CS_COPYRIGHT_VALUE_true()                    ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x50, 0x1, 0x0)
#define VRX_get_CS_COPYRIGHT_VALUE(pval)                    ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x50, 0x1, 0x0, pval)
#define VRX_ret_CS_COPYRIGHT_VALUE()                        ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x50, 0x1, 0x0)
#define VRX_set_CS_COPYRIGHT_VALUE(val)                     ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x50, 0x1, 0x0, val)

#define VRX_get_TMDSFREQ(pval)                              ATV_I2CGetField32(VRX_HDMI_MAP_ADDR, 0x51, 0xFF, 0x80, 7, 2, pval)
#define VRX_ret_TMDSFREQ()                                  ATV_I2CReadField32(VRX_HDMI_MAP_ADDR, 0x51, 0xFF, 0x80, 7, 2)

#define VRX_get_TMDSFREQ_FRAC(pval)                         ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x52, 0x7F, 0, pval)
#define VRX_ret_TMDSFREQ_FRAC()                             ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x52, 0x7F, 0)

#define VRX_get_HDMI_COLORSPACE(pval)                       ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x53, 0xF, 0, pval)
#define VRX_ret_HDMI_COLORSPACE()                           ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x53, 0xF, 0)

#define VRX_is_FILT_5V_DET_DIS_true()                       ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x56, 0x80, 0x7)
#define VRX_get_FILT_5V_DET_DIS(pval)                       ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x56, 0x80, 0x7, pval)
#define VRX_ret_FILT_5V_DET_DIS()                           ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x56, 0x80, 0x7)
#define VRX_set_FILT_5V_DET_DIS(val)                        ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x56, 0x80, 0x7, val)

#define VRX_get_FILT_5V_DET_TIMER(pval)                     ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x56, 0x7F, 0, pval)
#define VRX_ret_FILT_5V_DET_TIMER()                         ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x56, 0x7F, 0)
#define VRX_set_FILT_5V_DET_TIMER(val)                      ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x56, 0x7F, 0, val)

#define VRX_set_BG_MEAS_REQ(val)                            ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x5A, 0x20, 0x5, val)

#define VRX_set_HDCP_REPT_EDID_RESET(val)                   ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x5A, 0x8, 0x3, val)

#define VRX_set_DCFIFO_RECENTER(val)                        ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x5A, 0x4, 0x2, val)

#define VRX_set_FORCE_N_UPDATE(val)                         ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x5A, 0x1, 0x0, val)

#define VRX_get_CTS(pval)                                   ATV_I2CGetField32(VRX_HDMI_MAP_ADDR, 0x5B, 0xFF, 0xF0, 4, 3, pval)
#define VRX_ret_CTS()                                       ATV_I2CReadField32(VRX_HDMI_MAP_ADDR, 0x5B, 0xFF, 0xF0, 4, 3)

#define VRX_get_N(pval)                                     ATV_I2CGetField32(VRX_HDMI_MAP_ADDR, 0x5D, 0xF, 0xFF, 0, 3, pval)
#define VRX_ret_N()                                         ATV_I2CReadField32(VRX_HDMI_MAP_ADDR, 0x5D, 0xF, 0xFF, 0, 3)

#define VRX_get_HPA_DELAY_SEL(pval)                         ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x69, 0xF0, 4, pval)
#define VRX_ret_HPA_DELAY_SEL()                             ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x69, 0xF0, 4)
#define VRX_set_HPA_DELAY_SEL(val)                          ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x69, 0xF0, 4, val)

#define VRX_is_HPA_OVR_TERM_true()                          ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x69, 0x8, 0x3)
#define VRX_get_HPA_OVR_TERM(pval)                          ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x69, 0x8, 0x3, pval)
#define VRX_ret_HPA_OVR_TERM()                              ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x69, 0x8, 0x3)
#define VRX_set_HPA_OVR_TERM(val)                           ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x69, 0x8, 0x3, val)

#define VRX_get_HPA_AUTO_INT_EDID(pval)                     ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x69, 0x6, 1, pval)
#define VRX_ret_HPA_AUTO_INT_EDID()                         ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x69, 0x6, 1)
#define VRX_set_HPA_AUTO_INT_EDID(val)                      ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x69, 0x6, 1, val)

#define VRX_is_HPA_MANUAL_true()                            ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x69, 0x1, 0x0)
#define VRX_get_HPA_MANUAL(pval)                            ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x69, 0x1, 0x0, pval)
#define VRX_ret_HPA_MANUAL()                                ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x69, 0x1, 0x0)
#define VRX_set_HPA_MANUAL(val)                             ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x69, 0x1, 0x0, val)

#define VRX_is_I2S_SPDIF_MAP_INV_true()                     ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x6A, 0x40, 0x6)
#define VRX_get_I2S_SPDIF_MAP_INV(pval)                     ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x6A, 0x40, 0x6, pval)
#define VRX_ret_I2S_SPDIF_MAP_INV()                         ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x6A, 0x40, 0x6)
#define VRX_set_I2S_SPDIF_MAP_INV(val)                      ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x6A, 0x40, 0x6, val)

#define VRX_get_I2S_SPDIF_MAP_ROT(pval)                     ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x6A, 0x30, 4, pval)
#define VRX_ret_I2S_SPDIF_MAP_ROT()                         ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x6A, 0x30, 4)
#define VRX_set_I2S_SPDIF_MAP_ROT(val)                      ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x6A, 0x30, 4, val)

#define VRX_is_DSD_MAP_INV_true()                           ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x6A, 0x8, 0x3)
#define VRX_get_DSD_MAP_INV(pval)                           ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x6A, 0x8, 0x3, pval)
#define VRX_ret_DSD_MAP_INV()                               ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x6A, 0x8, 0x3)
#define VRX_set_DSD_MAP_INV(val)                            ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x6A, 0x8, 0x3, val)

#define VRX_get_DSD_MAP_ROT(pval)                           ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x6A, 0x7, 0, pval)
#define VRX_ret_DSD_MAP_ROT()                               ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x6A, 0x7, 0)
#define VRX_set_DSD_MAP_ROT(val)                            ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x6A, 0x7, 0, val)

#define VRX_get_DST_MAP_ROT(pval)                           ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x6B, 0x7, 0, pval)
#define VRX_ret_DST_MAP_ROT()                               ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x6B, 0x7, 0)
#define VRX_set_DST_MAP_ROT(val)                            ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x6B, 0x7, 0, val)

#define VRX_is_VGA_PWRDN_true()                             ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x72, 0x10, 0x4)
#define VRX_get_VGA_PWRDN(pval)                             ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x72, 0x10, 0x4, pval)
#define VRX_ret_VGA_PWRDN()                                 ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x72, 0x10, 0x4)
#define VRX_set_VGA_PWRDN(val)                              ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x72, 0x10, 0x4, val)

#define VRX_get_DDC_PWRDN(pval)                             ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x73, 0xF, 0, pval)
#define VRX_ret_DDC_PWRDN()                                 ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x73, 0xF, 0)
#define VRX_set_DDC_PWRDN(val)                              ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x73, 0xF, 0, val)

#define VRX_get_EQ_DYN_FREQ2(pval)                          ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x8C, 0xF0, 4, pval)
#define VRX_ret_EQ_DYN_FREQ2()                              ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x8C, 0xF0, 4)
#define VRX_set_EQ_DYN_FREQ2(val)                           ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x8C, 0xF0, 4, val)

#define VRX_get_EQ_DYN_FREQ1(pval)                          ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x8C, 0xF, 0, pval)
#define VRX_ret_EQ_DYN_FREQ1()                              ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x8C, 0xF, 0)
#define VRX_set_EQ_DYN_FREQ1(val)                           ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x8C, 0xF, 0, val)

#define VRX_get_EQ_DYN1_LF(pval)                            ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x8D, 0xFF, 0, pval)
#define VRX_ret_EQ_DYN1_LF()                                ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x8D, 0xFF, 0)
#define VRX_set_EQ_DYN1_LF(val)                             ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x8D, 0xFF, 0, val)

#define VRX_get_EQ_DYN1_HF(pval)                            ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x8E, 0xFF, 0, pval)
#define VRX_ret_EQ_DYN1_HF()                                ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x8E, 0xFF, 0)
#define VRX_set_EQ_DYN1_HF(val)                             ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x8E, 0xFF, 0, val)

#define VRX_get_EQ_DYN2_LF(pval)                            ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x90, 0xFF, 0, pval)
#define VRX_ret_EQ_DYN2_LF()                                ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x90, 0xFF, 0)
#define VRX_set_EQ_DYN2_LF(val)                             ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x90, 0xFF, 0, val)

#define VRX_get_EQ_DYN2_HF(pval)                            ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x91, 0xFF, 0, pval)
#define VRX_ret_EQ_DYN2_HF()                                ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x91, 0xFF, 0)
#define VRX_set_EQ_DYN2_HF(val)                             ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x91, 0xFF, 0, val)

#define VRX_get_EQ_DYN3_LF(pval)                            ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x93, 0xFF, 0, pval)
#define VRX_ret_EQ_DYN3_LF()                                ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x93, 0xFF, 0)
#define VRX_set_EQ_DYN3_LF(val)                             ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x93, 0xFF, 0, val)

#define VRX_get_EQ_DYN3_HF(pval)                            ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x94, 0xFF, 0, pval)
#define VRX_ret_EQ_DYN3_HF()                                ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x94, 0xFF, 0)
#define VRX_set_EQ_DYN3_HF(val)                             ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x94, 0xFF, 0, val)

#define VRX_is_EQ_DYN_EN_true()                             ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x96, 0x1, 0x0)
#define VRX_get_EQ_DYN_EN(pval)                             ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x96, 0x1, 0x0, pval)
#define VRX_ret_EQ_DYN_EN()                                 ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x96, 0x1, 0x0)
#define VRX_set_EQ_DYN_EN(val)                              ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x96, 0x1, 0x0, val)

#define VRX_is_HEC_TO_ETH_2_SEL_EN_true()                   ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0xBC, 0x40, 0x6)
#define VRX_get_HEC_TO_ETH_2_SEL_EN(pval)                   ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0xBC, 0x40, 0x6, pval)
#define VRX_ret_HEC_TO_ETH_2_SEL_EN()                       ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0xBC, 0x40, 0x6)
#define VRX_set_HEC_TO_ETH_2_SEL_EN(val)                    ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0xBC, 0x40, 0x6, val)

#define VRX_get_HEC_TO_ETH_2_SEL(pval)                      ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0xBC, 0x30, 4, pval)
#define VRX_ret_HEC_TO_ETH_2_SEL()                          ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0xBC, 0x30, 4)
#define VRX_set_HEC_TO_ETH_2_SEL(val)                       ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0xBC, 0x30, 4, val)

#define VRX_is_HEC_TO_ETH_1_SEL_EN_true()                   ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0xBC, 0x4, 0x2)
#define VRX_get_HEC_TO_ETH_1_SEL_EN(pval)                   ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0xBC, 0x4, 0x2, pval)
#define VRX_ret_HEC_TO_ETH_1_SEL_EN()                       ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0xBC, 0x4, 0x2)
#define VRX_set_HEC_TO_ETH_1_SEL_EN(val)                    ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0xBC, 0x4, 0x2, val)

#define VRX_get_HEC_TO_ETH_1_SEL(pval)                      ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0xBC, 0x3, 0, pval)
#define VRX_ret_HEC_TO_ETH_1_SEL()                          ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0xBC, 0x3, 0)
#define VRX_set_HEC_TO_ETH_1_SEL(val)                       ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0xBC, 0x3, 0, val)

#define VRX_is_ETH_2_PWRDN_true()                           ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0xBD, 0x20, 0x5)
#define VRX_get_ETH_2_PWRDN(pval)                           ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0xBD, 0x20, 0x5, pval)
#define VRX_ret_ETH_2_PWRDN()                               ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0xBD, 0x20, 0x5)
#define VRX_set_ETH_2_PWRDN(val)                            ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0xBD, 0x20, 0x5, val)

#define VRX_is_ETH_1_PWRDN_true()                           ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0xBD, 0x10, 0x4)
#define VRX_get_ETH_1_PWRDN(pval)                           ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0xBD, 0x10, 0x4, pval)
#define VRX_ret_ETH_1_PWRDN()                               ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0xBD, 0x10, 0x4)
#define VRX_set_ETH_1_PWRDN(val)                            ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0xBD, 0x10, 0x4, val)

#define VRX_get_BG_TMDSFREQ(pval)                           ATV_I2CGetField32(VRX_HDMI_MAP_ADDR, 0xE0, 0xFF, 0x80, 7, 2, pval)
#define VRX_ret_BG_TMDSFREQ()                               ATV_I2CReadField32(VRX_HDMI_MAP_ADDR, 0xE0, 0xFF, 0x80, 7, 2)

#define VRX_get_BG_TMDSFREQ_FRAC(pval)                      ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0xE1, 0x7F, 0, pval)
#define VRX_ret_BG_TMDSFREQ_FRAC()                          ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0xE1, 0x7F, 0)

#define VRX_get_BG_LINE_WIDTH(pval)                         ATV_I2CGetField32(VRX_HDMI_MAP_ADDR, 0xE2, 0x1F, 0xFF, 0, 2, pval)
#define VRX_ret_BG_LINE_WIDTH()                             ATV_I2CReadField32(VRX_HDMI_MAP_ADDR, 0xE2, 0x1F, 0xFF, 0, 2)

#define VRX_get_BG_TOTAL_LINE_WIDTH(pval)                   ATV_I2CGetField32(VRX_HDMI_MAP_ADDR, 0xE4, 0x3F, 0xFF, 0, 2, pval)
#define VRX_ret_BG_TOTAL_LINE_WIDTH()                       ATV_I2CReadField32(VRX_HDMI_MAP_ADDR, 0xE4, 0x3F, 0xFF, 0, 2)

#define VRX_get_BG_FIELD_HEIGHT(pval)                       ATV_I2CGetField32(VRX_HDMI_MAP_ADDR, 0xE6, 0x1F, 0xFF, 0, 2, pval)
#define VRX_ret_BG_FIELD_HEIGHT()                           ATV_I2CReadField32(VRX_HDMI_MAP_ADDR, 0xE6, 0x1F, 0xFF, 0, 2)

#define VRX_get_BG_TOTAL_FIELD_HEIGHT(pval)                 ATV_I2CGetField32(VRX_HDMI_MAP_ADDR, 0xE8, 0x1F, 0xFF, 0, 2, pval)
#define VRX_ret_BG_TOTAL_FIELD_HEIGHT()                     ATV_I2CReadField32(VRX_HDMI_MAP_ADDR, 0xE8, 0x1F, 0xFF, 0, 2)

#define VRX_get_BG_PIX_REP(pval)                            ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0xEA, 0xF0, 4, pval)
#define VRX_ret_BG_PIX_REP()                                ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0xEA, 0xF0, 4)

#define VRX_get_BG_DEEP_COLOR_MODE(pval)                    ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0xEA, 0xC, 2, pval)
#define VRX_ret_BG_DEEP_COLOR_MODE()                        ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0xEA, 0xC, 2)

#define VRX_is_BG_PARAM_LOCK_true()                         ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0xEA, 0x2, 0x1)
#define VRX_get_BG_PARAM_LOCK(pval)                         ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0xEA, 0x2, 0x1, pval)
#define VRX_ret_BG_PARAM_LOCK()                             ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0xEA, 0x2, 0x1)

#define VRX_is_BG_HDMI_INTERLACED_true()                    ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0xEA, 0x1, 0x0)
#define VRX_get_BG_HDMI_INTERLACED(pval)                    ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0xEA, 0x1, 0x0, pval)
#define VRX_ret_BG_HDMI_INTERLACED()                        ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0xEA, 0x1, 0x0)

#define VRX_is_BG_HDMI_MODE_true()                          ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0xEB, 0x1, 0x0)
#define VRX_get_BG_HDMI_MODE(pval)                          ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0xEB, 0x1, 0x0, pval)
#define VRX_ret_BG_HDMI_MODE()                              ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0xEB, 0x1, 0x0)

#endif
