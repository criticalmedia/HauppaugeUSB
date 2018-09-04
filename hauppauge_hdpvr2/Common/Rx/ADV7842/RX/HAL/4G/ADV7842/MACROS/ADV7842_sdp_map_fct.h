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


#ifndef ADV7842_SDP_MAP_FCT_H
#define ADV7842_SDP_MAP_FCT_H

#include "ADV7842_cfg.h"

#define VRX_is_SDP_AD_SECAM_EN_true()                       ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x00, 0x40, 0x6)
#define VRX_get_SDP_AD_SECAM_EN(pval)                       ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x00, 0x40, 0x6, pval)
#define VRX_ret_SDP_AD_SECAM_EN()                           ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x00, 0x40, 0x6)
#define VRX_set_SDP_AD_SECAM_EN(val)                        ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x00, 0x40, 0x6, val)

#define VRX_is_SDP_AD_N443_EN_true()                        ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x00, 0x20, 0x5)
#define VRX_get_SDP_AD_N443_EN(pval)                        ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x00, 0x20, 0x5, pval)
#define VRX_ret_SDP_AD_N443_EN()                            ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x00, 0x20, 0x5)
#define VRX_set_SDP_AD_N443_EN(val)                         ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x00, 0x20, 0x5, val)

#define VRX_is_SDP_AD_PAL60_EN_true()                       ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x00, 0x10, 0x4)
#define VRX_get_SDP_AD_PAL60_EN(pval)                       ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x00, 0x10, 0x4, pval)
#define VRX_ret_SDP_AD_PAL60_EN()                           ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x00, 0x10, 0x4)
#define VRX_set_SDP_AD_PAL60_EN(val)                        ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x00, 0x10, 0x4, val)

#define VRX_is_SDP_AD_PALCN_EN_true()                       ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x00, 0x8, 0x3)
#define VRX_get_SDP_AD_PALCN_EN(pval)                       ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x00, 0x8, 0x3, pval)
#define VRX_ret_SDP_AD_PALCN_EN()                           ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x00, 0x8, 0x3)
#define VRX_set_SDP_AD_PALCN_EN(val)                        ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x00, 0x8, 0x3, val)

#define VRX_is_SDP_AD_PALM_EN_true()                        ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x00, 0x4, 0x2)
#define VRX_get_SDP_AD_PALM_EN(pval)                        ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x00, 0x4, 0x2, pval)
#define VRX_ret_SDP_AD_PALM_EN()                            ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x00, 0x4, 0x2)
#define VRX_set_SDP_AD_PALM_EN(val)                         ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x00, 0x4, 0x2, val)

#define VRX_is_SDP_AD_NTSC_EN_true()                        ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x00, 0x2, 0x1)
#define VRX_get_SDP_AD_NTSC_EN(pval)                        ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x00, 0x2, 0x1, pval)
#define VRX_ret_SDP_AD_NTSC_EN()                            ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x00, 0x2, 0x1)
#define VRX_set_SDP_AD_NTSC_EN(val)                         ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x00, 0x2, 0x1, val)

#define VRX_is_SDP_AD_PAL_EN_true()                         ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x00, 0x1, 0x0)
#define VRX_get_SDP_AD_PAL_EN(pval)                         ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x00, 0x1, 0x0, pval)
#define VRX_ret_SDP_AD_PAL_EN()                             ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x00, 0x1, 0x0)
#define VRX_set_SDP_AD_PAL_EN(val)                          ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x00, 0x1, 0x0, val)

#define VRX_is_SDP_SECAM_PED_EN_true()                      ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x01, 0x40, 0x6)
#define VRX_get_SDP_SECAM_PED_EN(pval)                      ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x01, 0x40, 0x6, pval)
#define VRX_ret_SDP_SECAM_PED_EN()                          ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x01, 0x40, 0x6)
#define VRX_set_SDP_SECAM_PED_EN(val)                       ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x01, 0x40, 0x6, val)

#define VRX_is_SDP_N443_PED_EN_true()                       ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x01, 0x20, 0x5)
#define VRX_get_SDP_N443_PED_EN(pval)                       ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x01, 0x20, 0x5, pval)
#define VRX_ret_SDP_N443_PED_EN()                           ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x01, 0x20, 0x5)
#define VRX_set_SDP_N443_PED_EN(val)                        ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x01, 0x20, 0x5, val)

#define VRX_is_SDP_PAL60_PED_EN_true()                      ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x01, 0x10, 0x4)
#define VRX_get_SDP_PAL60_PED_EN(pval)                      ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x01, 0x10, 0x4, pval)
#define VRX_ret_SDP_PAL60_PED_EN()                          ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x01, 0x10, 0x4)
#define VRX_set_SDP_PAL60_PED_EN(val)                       ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x01, 0x10, 0x4, val)

#define VRX_is_SDP_PALCN_PED_EN_true()                      ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x01, 0x8, 0x3)
#define VRX_get_SDP_PALCN_PED_EN(pval)                      ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x01, 0x8, 0x3, pval)
#define VRX_ret_SDP_PALCN_PED_EN()                          ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x01, 0x8, 0x3)
#define VRX_set_SDP_PALCN_PED_EN(val)                       ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x01, 0x8, 0x3, val)

#define VRX_is_SDP_PALM_PED_EN_true()                       ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x01, 0x4, 0x2)
#define VRX_get_SDP_PALM_PED_EN(pval)                       ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x01, 0x4, 0x2, pval)
#define VRX_ret_SDP_PALM_PED_EN()                           ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x01, 0x4, 0x2)
#define VRX_set_SDP_PALM_PED_EN(val)                        ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x01, 0x4, 0x2, val)

#define VRX_is_SDP_NTSC_PED_EN_true()                       ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x01, 0x2, 0x1)
#define VRX_get_SDP_NTSC_PED_EN(pval)                       ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x01, 0x2, 0x1, pval)
#define VRX_ret_SDP_NTSC_PED_EN()                           ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x01, 0x2, 0x1)
#define VRX_set_SDP_NTSC_PED_EN(val)                        ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x01, 0x2, 0x1, val)

#define VRX_is_SDP_PAL_PED_EN_true()                        ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x01, 0x1, 0x0)
#define VRX_get_SDP_PAL_PED_EN(pval)                        ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x01, 0x1, 0x0, pval)
#define VRX_ret_SDP_PAL_PED_EN()                            ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x01, 0x1, 0x0)
#define VRX_set_SDP_PAL_PED_EN(val)                         ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x01, 0x1, 0x0, val)

#define VRX_is_SDP_CR_MODE_EN_true()                        ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x02, 0x40, 0x6)
#define VRX_get_SDP_CR_MODE_EN(pval)                        ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x02, 0x40, 0x6, pval)
#define VRX_ret_SDP_CR_MODE_EN()                            ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x02, 0x40, 0x6)
#define VRX_set_SDP_CR_MODE_EN(val)                         ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x02, 0x40, 0x6, val)

#define VRX_is_SDP_Y_AGC_EN_true()                          ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x03, 0x80, 0x7)
#define VRX_get_SDP_Y_AGC_EN(pval)                          ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x03, 0x80, 0x7, pval)
#define VRX_ret_SDP_Y_AGC_EN()                              ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x03, 0x80, 0x7)
#define VRX_set_SDP_Y_AGC_EN(val)                           ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x03, 0x80, 0x7, val)

#define VRX_is_SDP_PW_EN_true()                             ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x03, 0x40, 0x6)
#define VRX_get_SDP_PW_EN(pval)                             ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x03, 0x40, 0x6, pval)
#define VRX_ret_SDP_PW_EN()                                 ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x03, 0x40, 0x6)
#define VRX_set_SDP_PW_EN(val)                              ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x03, 0x40, 0x6, val)

#define VRX_is_SDP_MAN_GAIN_VCR_true()                      ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x03, 0x20, 0x5)
#define VRX_get_SDP_MAN_GAIN_VCR(pval)                      ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x03, 0x20, 0x5, pval)
#define VRX_ret_SDP_MAN_GAIN_VCR()                          ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x03, 0x20, 0x5)
#define VRX_set_SDP_MAN_GAIN_VCR(val)                       ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x03, 0x20, 0x5, val)

#define VRX_get_SDP_Y_GAIN_MAN(pval)                        ATV_I2CGetField32(VRX_SDP_MAP_ADDR, 0x03, 0x1F, 0xFF, 0, 2, pval)
#define VRX_ret_SDP_Y_GAIN_MAN()                            ATV_I2CReadField32(VRX_SDP_MAP_ADDR, 0x03, 0x1F, 0xFF, 0, 2)
#define VRX_set_SDP_Y_GAIN_MAN(val)                         ATV_I2CWriteField32(VRX_SDP_MAP_ADDR, 0x03, 0x1F, 0xFF, 0, 2, val)

#define VRX_is_SDP_C_AGC_EN_true()                          ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x05, 0x80, 0x7)
#define VRX_get_SDP_C_AGC_EN(pval)                          ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x05, 0x80, 0x7, pval)
#define VRX_ret_SDP_C_AGC_EN()                              ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x05, 0x80, 0x7)
#define VRX_set_SDP_C_AGC_EN(val)                           ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x05, 0x80, 0x7, val)

#define VRX_is_SDP_PC_EN_true()                             ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x05, 0x40, 0x6)
#define VRX_get_SDP_PC_EN(pval)                             ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x05, 0x40, 0x6, pval)
#define VRX_ret_SDP_PC_EN()                                 ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x05, 0x40, 0x6)
#define VRX_set_SDP_PC_EN(val)                              ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x05, 0x40, 0x6, val)

#define VRX_get_SDP_C_GAIN_ACT_MAN(pval)                    ATV_I2CGetField32(VRX_SDP_MAP_ADDR, 0x05, 0x1F, 0xFF, 0, 2, pval)
#define VRX_ret_SDP_C_GAIN_ACT_MAN()                        ATV_I2CReadField32(VRX_SDP_MAP_ADDR, 0x05, 0x1F, 0xFF, 0, 2)
#define VRX_set_SDP_C_GAIN_ACT_MAN(val)                     ATV_I2CWriteField32(VRX_SDP_MAP_ADDR, 0x05, 0x1F, 0xFF, 0, 2, val)

#define VRX_is_SDP_CKILL_EN_true()                          ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x07, 0x80, 0x7)
#define VRX_get_SDP_CKILL_EN(pval)                          ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x07, 0x80, 0x7, pval)
#define VRX_ret_SDP_CKILL_EN()                              ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x07, 0x80, 0x7)
#define VRX_set_SDP_CKILL_EN(val)                           ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x07, 0x80, 0x7, val)

#define VRX_get_SDP_CK_LOW_THR(pval)                        ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x07, 0x7F, 0, pval)
#define VRX_ret_SDP_CK_LOW_THR()                            ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x07, 0x7F, 0)
#define VRX_set_SDP_CK_LOW_THR(val)                         ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x07, 0x7F, 0, val)

#define VRX_get_SDP_CK_HIGH_THR(pval)                       ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x08, 0xFF, 0, pval)
#define VRX_ret_SDP_CK_HIGH_THR()                           ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x08, 0xFF, 0)
#define VRX_set_SDP_CK_HIGH_THR(val)                        ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x08, 0xFF, 0, val)

#define VRX_get_SDP_DGAIN_SPEED(pval)                       ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x0A, 0x1F, 0, pval)
#define VRX_ret_SDP_DGAIN_SPEED()                           ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x0A, 0x1F, 0)
#define VRX_set_SDP_DGAIN_SPEED(val)                        ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x0A, 0x1F, 0, val)

#define VRX_get_SDP_C_DGAIN_SPEED(pval)                     ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x0B, 0x1F, 0, pval)
#define VRX_ret_SDP_C_DGAIN_SPEED()                         ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x0B, 0x1F, 0)
#define VRX_set_SDP_C_DGAIN_SPEED(val)                      ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x0B, 0x1F, 0, val)

#define VRX_get_SDP_DCLP_SPEED(pval)                        ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x0C, 0x1F, 0, pval)
#define VRX_ret_SDP_DCLP_SPEED()                            ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x0C, 0x1F, 0)
#define VRX_set_SDP_DCLP_SPEED(val)                         ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x0C, 0x1F, 0, val)

#define VRX_get_SDP_ACLP_SPEED(pval)                        ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x0D, 0x1F, 0, pval)
#define VRX_ret_SDP_ACLP_SPEED()                            ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x0D, 0x1F, 0)
#define VRX_set_SDP_ACLP_SPEED(val)                         ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x0D, 0x1F, 0, val)

#define VRX_is_SDP_SCM_CTI_EN_true()                        ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x0E, 0x20, 0x5)
#define VRX_get_SDP_SCM_CTI_EN(pval)                        ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x0E, 0x20, 0x5, pval)
#define VRX_ret_SDP_SCM_CTI_EN()                            ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x0E, 0x20, 0x5)
#define VRX_set_SDP_SCM_CTI_EN(val)                         ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x0E, 0x20, 0x5, val)

#define VRX_is_SDP_Y_2D_PK_EN_true()                        ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x0E, 0x10, 0x4)
#define VRX_get_SDP_Y_2D_PK_EN(pval)                        ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x0E, 0x10, 0x4, pval)
#define VRX_ret_SDP_Y_2D_PK_EN()                            ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x0E, 0x10, 0x4)
#define VRX_set_SDP_Y_2D_PK_EN(val)                         ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x0E, 0x10, 0x4, val)

#define VRX_is_SDP_V_PK_EN_true()                           ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x0E, 0x8, 0x3)
#define VRX_get_SDP_V_PK_EN(pval)                           ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x0E, 0x8, 0x3, pval)
#define VRX_ret_SDP_V_PK_EN()                               ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x0E, 0x8, 0x3)
#define VRX_set_SDP_V_PK_EN(val)                            ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x0E, 0x8, 0x3, val)

#define VRX_is_SDP_H_PK_EN_true()                           ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x0E, 0x4, 0x2)
#define VRX_get_SDP_H_PK_EN(pval)                           ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x0E, 0x4, 0x2, pval)
#define VRX_ret_SDP_H_PK_EN()                               ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x0E, 0x4, 0x2)
#define VRX_set_SDP_H_PK_EN(val)                            ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x0E, 0x4, 0x2, val)

#define VRX_is_SDP_LTI_EN_true()                            ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x0E, 0x2, 0x1)
#define VRX_get_SDP_LTI_EN(pval)                            ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x0E, 0x2, 0x1, pval)
#define VRX_ret_SDP_LTI_EN()                                ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x0E, 0x2, 0x1)
#define VRX_set_SDP_LTI_EN(val)                             ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x0E, 0x2, 0x1, val)

#define VRX_is_SDP_CTI_EN_true()                            ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x0E, 0x1, 0x0)
#define VRX_get_SDP_CTI_EN(pval)                            ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x0E, 0x1, 0x0, pval)
#define VRX_ret_SDP_CTI_EN()                                ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x0E, 0x1, 0x0)
#define VRX_set_SDP_CTI_EN(val)                             ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x0E, 0x1, 0x0, val)

#define VRX_get_SDP_PC_REC_RATE(pval)                       {I2C_FIELD_INFO FieldInfo[2]; \
                                                            FieldInfo[0].RegAddr = 0x0F;FieldInfo[0].Mask = 0xF0;FieldInfo[0].LShift = 0x4; \
                                                            FieldInfo[1].RegAddr = 0x11;FieldInfo[1].Mask = 0xFF;FieldInfo[1].LShift = 0x0; \
                                                            ATV_I2CGetRandField32(VRX_SDP_MAP_ADDR, &FieldInfo[0], 3, pval);}
#define VRX_get_SDP_PC_REC_RATE(pval)                       {I2C_FIELD_INFO FieldInfo[2]; \
                                                            FieldInfo[0].RegAddr = 0x0F;FieldInfo[0].Mask = 0xF0;FieldInfo[0].LShift = 0x4; \
                                                            FieldInfo[1].RegAddr = 0x11;FieldInfo[1].Mask = 0xFF;FieldInfo[1].LShift = 0x0; \
                                                            ATV_I2CGetRandField32(VRX_SDP_MAP_ADDR, &FieldInfo[0], 3, pval);}

#define VRX_set_SDP_PC_REC_RATE(val)                        {I2C_FIELD_INFO FieldInfo[2]; \
                                                            FieldInfo[0].RegAddr = 0x0F;FieldInfo[0].Mask = 0xF0;FieldInfo[0].LShift = 0x4; \
                                                            FieldInfo[1].RegAddr = 0x11;FieldInfo[1].Mask = 0xFF;FieldInfo[1].LShift = 0x0; \
                                                            ATV_I2CWriteRandField32(VRX_SDP_MAP_ADDR, &FieldInfo[0], 3, val);}

#define VRX_get_SDP_PW_REC_RATE(pval)                       ATV_I2CGetField32(VRX_SDP_MAP_ADDR, 0x0F, 0xF, 0xFF, 0, 2, pval)
#define VRX_ret_SDP_PW_REC_RATE()                           ATV_I2CReadField32(VRX_SDP_MAP_ADDR, 0x0F, 0xF, 0xFF, 0, 2)
#define VRX_set_SDP_PW_REC_RATE(val)                        ATV_I2CWriteField32(VRX_SDP_MAP_ADDR, 0x0F, 0xF, 0xFF, 0, 2, val)

#define VRX_is_SDP_SHIP_EN_true()                           ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x12, 0x8, 0x3)
#define VRX_get_SDP_SHIP_EN(pval)                           ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x12, 0x8, 0x3, pval)
#define VRX_ret_SDP_SHIP_EN()                               ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x12, 0x8, 0x3)
#define VRX_set_SDP_SHIP_EN(val)                            ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x12, 0x8, 0x3, val)

#define VRX_is_SDP_FR_TBC_EN_true()                         ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x12, 0x4, 0x2)
#define VRX_get_SDP_FR_TBC_EN(pval)                         ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x12, 0x4, 0x2, pval)
#define VRX_ret_SDP_FR_TBC_EN()                             ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x12, 0x4, 0x2)
#define VRX_set_SDP_FR_TBC_EN(val)                          ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x12, 0x4, 0x2, val)

#define VRX_is_SDP_3D_COMB_EN_true()                        ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x12, 0x1, 0x0)
#define VRX_get_SDP_3D_COMB_EN(pval)                        ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x12, 0x1, 0x0, pval)
#define VRX_ret_SDP_3D_COMB_EN()                            ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x12, 0x1, 0x0)
#define VRX_set_SDP_3D_COMB_EN(val)                         ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x12, 0x1, 0x0, val)

#define VRX_get_SDP_CONTRAST(pval)                          {I2C_FIELD_INFO FieldInfo[2]; \
                                                            FieldInfo[0].RegAddr = 0x13;FieldInfo[0].Mask = 0xFF;FieldInfo[0].LShift = 0x2; \
                                                            FieldInfo[1].RegAddr = 0x17;FieldInfo[1].Mask = 0x3;FieldInfo[1].LShift = 0x0; \
                                                            ATV_I2CGetRandField32(VRX_SDP_MAP_ADDR, &FieldInfo[0], 5, pval);}
#define VRX_get_SDP_CONTRAST(pval)                          {I2C_FIELD_INFO FieldInfo[2]; \
                                                            FieldInfo[0].RegAddr = 0x13;FieldInfo[0].Mask = 0xFF;FieldInfo[0].LShift = 0x2; \
                                                            FieldInfo[1].RegAddr = 0x17;FieldInfo[1].Mask = 0x3;FieldInfo[1].LShift = 0x0; \
                                                            ATV_I2CGetRandField32(VRX_SDP_MAP_ADDR, &FieldInfo[0], 5, pval);}

#define VRX_set_SDP_CONTRAST(val)                           {I2C_FIELD_INFO FieldInfo[2]; \
                                                            FieldInfo[0].RegAddr = 0x13;FieldInfo[0].Mask = 0xFF;FieldInfo[0].LShift = 0x2; \
                                                            FieldInfo[1].RegAddr = 0x17;FieldInfo[1].Mask = 0x3;FieldInfo[1].LShift = 0x0; \
                                                            ATV_I2CWriteRandField32(VRX_SDP_MAP_ADDR, &FieldInfo[0], 5, val);}

#define VRX_get_SDP_BRIGHTNESS(pval)                        {I2C_FIELD_INFO FieldInfo[2]; \
                                                            FieldInfo[0].RegAddr = 0x14;FieldInfo[0].Mask = 0xFF;FieldInfo[0].LShift = 0x2; \
                                                            FieldInfo[1].RegAddr = 0x17;FieldInfo[1].Mask = 0xC;FieldInfo[1].LShift = 0x82; \
                                                            ATV_I2CGetRandField32(VRX_SDP_MAP_ADDR, &FieldInfo[0], 4, pval);}
#define VRX_get_SDP_BRIGHTNESS(pval)                        {I2C_FIELD_INFO FieldInfo[2]; \
                                                            FieldInfo[0].RegAddr = 0x14;FieldInfo[0].Mask = 0xFF;FieldInfo[0].LShift = 0x2; \
                                                            FieldInfo[1].RegAddr = 0x17;FieldInfo[1].Mask = 0xC;FieldInfo[1].LShift = 0x82; \
                                                            ATV_I2CGetRandField32(VRX_SDP_MAP_ADDR, &FieldInfo[0], 4, pval);}

#define VRX_set_SDP_BRIGHTNESS(val)                         {I2C_FIELD_INFO FieldInfo[2]; \
                                                            FieldInfo[0].RegAddr = 0x14;FieldInfo[0].Mask = 0xFF;FieldInfo[0].LShift = 0x2; \
                                                            FieldInfo[1].RegAddr = 0x17;FieldInfo[1].Mask = 0xC;FieldInfo[1].LShift = 0x82; \
                                                            ATV_I2CWriteRandField32(VRX_SDP_MAP_ADDR, &FieldInfo[0], 4, val);}

#define VRX_get_SDP_SATURATION(pval)                        {I2C_FIELD_INFO FieldInfo[2]; \
                                                            FieldInfo[0].RegAddr = 0x15;FieldInfo[0].Mask = 0xFF;FieldInfo[0].LShift = 0x2; \
                                                            FieldInfo[1].RegAddr = 0x17;FieldInfo[1].Mask = 0x30;FieldInfo[1].LShift = 0x84; \
                                                            ATV_I2CGetRandField32(VRX_SDP_MAP_ADDR, &FieldInfo[0], 3, pval);}
#define VRX_get_SDP_SATURATION(pval)                        {I2C_FIELD_INFO FieldInfo[2]; \
                                                            FieldInfo[0].RegAddr = 0x15;FieldInfo[0].Mask = 0xFF;FieldInfo[0].LShift = 0x2; \
                                                            FieldInfo[1].RegAddr = 0x17;FieldInfo[1].Mask = 0x30;FieldInfo[1].LShift = 0x84; \
                                                            ATV_I2CGetRandField32(VRX_SDP_MAP_ADDR, &FieldInfo[0], 3, pval);}

#define VRX_set_SDP_SATURATION(val)                         {I2C_FIELD_INFO FieldInfo[2]; \
                                                            FieldInfo[0].RegAddr = 0x15;FieldInfo[0].Mask = 0xFF;FieldInfo[0].LShift = 0x2; \
                                                            FieldInfo[1].RegAddr = 0x17;FieldInfo[1].Mask = 0x30;FieldInfo[1].LShift = 0x84; \
                                                            ATV_I2CWriteRandField32(VRX_SDP_MAP_ADDR, &FieldInfo[0], 3, val);}

#define VRX_get_SDP_HUE(pval)                               ATV_I2CGetField32(VRX_SDP_MAP_ADDR, 0x16, 0xFF, 0xC0, 6, 2, pval)
#define VRX_ret_SDP_HUE()                                   ATV_I2CReadField32(VRX_SDP_MAP_ADDR, 0x16, 0xFF, 0xC0, 6, 2)
#define VRX_set_SDP_HUE(val)                                ATV_I2CWriteField32(VRX_SDP_MAP_ADDR, 0x16, 0xFF, 0xC0, 6, 2, val)

#define VRX_is_SDP_BLANK_C_VBI_true()                       ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x18, 0x80, 0x7)
#define VRX_get_SDP_BLANK_C_VBI(pval)                       ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x18, 0x80, 0x7, pval)
#define VRX_ret_SDP_BLANK_C_VBI()                           ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x18, 0x80, 0x7)
#define VRX_set_SDP_BLANK_C_VBI(val)                        ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x18, 0x80, 0x7, val)

#define VRX_is_SDP_FORCE_CKILL_HQI_true()                   ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x18, 0x40, 0x6)
#define VRX_get_SDP_FORCE_CKILL_HQI(pval)                   ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x18, 0x40, 0x6, pval)
#define VRX_ret_SDP_FORCE_CKILL_HQI()                       ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x18, 0x40, 0x6)
#define VRX_set_SDP_FORCE_CKILL_HQI(val)                    ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x18, 0x40, 0x6, val)

#define VRX_get_SDP_Y_SHAPE_SEL_VBI(pval)                   ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x18, 0x3F, 0, pval)
#define VRX_ret_SDP_Y_SHAPE_SEL_VBI()                       ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x18, 0x3F, 0)
#define VRX_set_SDP_Y_SHAPE_SEL_VBI(val)                    ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x18, 0x3F, 0, val)

#define VRX_is_SDP_Y_SHAPE_AUTO_EN_true()                   ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x19, 0x80, 0x7)
#define VRX_get_SDP_Y_SHAPE_AUTO_EN(pval)                   ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x19, 0x80, 0x7, pval)
#define VRX_ret_SDP_Y_SHAPE_AUTO_EN()                       ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x19, 0x80, 0x7)
#define VRX_set_SDP_Y_SHAPE_AUTO_EN(val)                    ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x19, 0x80, 0x7, val)

#define VRX_is_SDP_FORCE_COMP_HQI_true()                    ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x19, 0x40, 0x6)
#define VRX_get_SDP_FORCE_COMP_HQI(pval)                    ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x19, 0x40, 0x6, pval)
#define VRX_ret_SDP_FORCE_COMP_HQI()                        ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x19, 0x40, 0x6)
#define VRX_set_SDP_FORCE_COMP_HQI(val)                     ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x19, 0x40, 0x6, val)

#define VRX_get_SDP_Y_SHAPE_SEL_HQI(pval)                   ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x19, 0x3F, 0, pval)
#define VRX_ret_SDP_Y_SHAPE_SEL_HQI()                       ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x19, 0x3F, 0)
#define VRX_set_SDP_Y_SHAPE_SEL_HQI(val)                    ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x19, 0x3F, 0, val)

#define VRX_is_SDP_HQI_REQ_STD_true()                       ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x1A, 0x80, 0x7)
#define VRX_get_SDP_HQI_REQ_STD(pval)                       ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x1A, 0x80, 0x7, pval)
#define VRX_ret_SDP_HQI_REQ_STD()                           ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x1A, 0x80, 0x7)
#define VRX_set_SDP_HQI_REQ_STD(val)                        ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x1A, 0x80, 0x7, val)

#define VRX_get_SDP_Y_SHAPE_SEL_LQI(pval)                   ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x1A, 0x3F, 0, pval)
#define VRX_ret_SDP_Y_SHAPE_SEL_LQI()                       ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x1A, 0x3F, 0)
#define VRX_set_SDP_Y_SHAPE_SEL_LQI(val)                    ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x1A, 0x3F, 0, val)

#define VRX_get_SDP_Y_SHAPE_SEL_SCM(pval)                   ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x1B, 0x3F, 0, pval)
#define VRX_ret_SDP_Y_SHAPE_SEL_SCM()                       ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x1B, 0x3F, 0)
#define VRX_set_SDP_Y_SHAPE_SEL_SCM(val)                    ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x1B, 0x3F, 0, val)

#define VRX_is_SDP_C_SHAPE_AUTO_EN_true()                   ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x1C, 0x80, 0x7)
#define VRX_get_SDP_C_SHAPE_AUTO_EN(pval)                   ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x1C, 0x80, 0x7, pval)
#define VRX_ret_SDP_C_SHAPE_AUTO_EN()                       ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x1C, 0x80, 0x7)
#define VRX_set_SDP_C_SHAPE_AUTO_EN(val)                    ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x1C, 0x80, 0x7, val)

#define VRX_is_SDP_CSH_WBW_AUTO_true()                      ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x1C, 0x40, 0x6)
#define VRX_get_SDP_CSH_WBW_AUTO(pval)                      ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x1C, 0x40, 0x6, pval)
#define VRX_ret_SDP_CSH_WBW_AUTO()                          ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x1C, 0x40, 0x6)
#define VRX_set_SDP_CSH_WBW_AUTO(val)                       ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x1C, 0x40, 0x6, val)

#define VRX_get_SDP_C_SHAPE_SEL_HQI(pval)                   ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x1C, 0x1F, 0, pval)
#define VRX_ret_SDP_C_SHAPE_SEL_HQI()                       ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x1C, 0x1F, 0)
#define VRX_set_SDP_C_SHAPE_SEL_HQI(val)                    ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x1C, 0x1F, 0, val)

#define VRX_get_SDP_C_SHAPE_SEL_LQI(pval)                   ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x1D, 0x1F, 0, pval)
#define VRX_ret_SDP_C_SHAPE_SEL_LQI()                       ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x1D, 0x1F, 0)
#define VRX_set_SDP_C_SHAPE_SEL_LQI(val)                    ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x1D, 0x1F, 0, val)

#define VRX_get_SDP_C_SHAPE_SEL_SCM(pval)                   ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x1E, 0x1F, 0, pval)
#define VRX_ret_SDP_C_SHAPE_SEL_SCM()                       ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x1E, 0x1F, 0)
#define VRX_set_SDP_C_SHAPE_SEL_SCM(val)                    ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x1E, 0x1F, 0, val)

#define VRX_get_SDP_SPLIT_FILTER_SEL(pval)                  ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x1F, 0x1F, 0, pval)
#define VRX_ret_SDP_SPLIT_FILTER_SEL()                      ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x1F, 0x1F, 0)
#define VRX_set_SDP_SPLIT_FILTER_SEL(val)                   ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x1F, 0x1F, 0, val)

#define VRX_get_SDP_IF_FILT_SEL(pval)                       ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x20, 0x1F, 0, pval)
#define VRX_ret_SDP_IF_FILT_SEL()                           ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x20, 0x1F, 0)
#define VRX_set_SDP_IF_FILT_SEL(val)                        ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x20, 0x1F, 0, val)

#define VRX_is_SDP_U_DEL_LINE_EN_true()                     ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x21, 0x80, 0x7)
#define VRX_get_SDP_U_DEL_LINE_EN(pval)                     ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x21, 0x80, 0x7, pval)
#define VRX_ret_SDP_U_DEL_LINE_EN()                         ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x21, 0x80, 0x7)
#define VRX_set_SDP_U_DEL_LINE_EN(val)                      ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x21, 0x80, 0x7, val)

#define VRX_is_SDP_V_DEL_LINE_EN_true()                     ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x21, 0x40, 0x6)
#define VRX_get_SDP_V_DEL_LINE_EN(pval)                     ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x21, 0x40, 0x6, pval)
#define VRX_ret_SDP_V_DEL_LINE_EN()                         ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x21, 0x40, 0x6)
#define VRX_set_SDP_V_DEL_LINE_EN(val)                      ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x21, 0x40, 0x6, val)

#define VRX_is_SDP_H_PK_INV_true()                          ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x22, 0x80, 0x7)
#define VRX_get_SDP_H_PK_INV(pval)                          ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x22, 0x80, 0x7, pval)
#define VRX_ret_SDP_H_PK_INV()                              ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x22, 0x80, 0x7)
#define VRX_set_SDP_H_PK_INV(val)                           ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x22, 0x80, 0x7, val)

#define VRX_get_SDP_H_PK_GAIN(pval)                         ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x22, 0x78, 3, pval)
#define VRX_ret_SDP_H_PK_GAIN()                             ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x22, 0x78, 3)
#define VRX_set_SDP_H_PK_GAIN(val)                          ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x22, 0x78, 3, val)

#define VRX_get_SDP_H_PK_CORE(pval)                         ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x22, 0x7, 0, pval)
#define VRX_ret_SDP_H_PK_CORE()                             ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x22, 0x7, 0)
#define VRX_set_SDP_H_PK_CORE(val)                          ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x22, 0x7, 0, val)

#define VRX_is_SDP_V_PK_INV_true()                          ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x23, 0x80, 0x7)
#define VRX_get_SDP_V_PK_INV(pval)                          ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x23, 0x80, 0x7, pval)
#define VRX_ret_SDP_V_PK_INV()                              ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x23, 0x80, 0x7)
#define VRX_set_SDP_V_PK_INV(val)                           ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x23, 0x80, 0x7, val)

#define VRX_get_SDP_V_PK_GAIN(pval)                         ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x23, 0x78, 3, pval)
#define VRX_ret_SDP_V_PK_GAIN()                             ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x23, 0x78, 3)
#define VRX_set_SDP_V_PK_GAIN(val)                          ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x23, 0x78, 3, val)

#define VRX_get_SDP_V_PK_CORE(pval)                         ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x23, 0x7, 0, pval)
#define VRX_ret_SDP_V_PK_CORE()                             ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x23, 0x7, 0)
#define VRX_set_SDP_V_PK_CORE(val)                          ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x23, 0x7, 0, val)

#define VRX_get_SDP_V_PK_FLIP(pval)                         ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x24, 0x70, 4, pval)
#define VRX_ret_SDP_V_PK_FLIP()                             ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x24, 0x70, 4)
#define VRX_set_SDP_V_PK_FLIP(val)                          ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x24, 0x70, 4, val)

#define VRX_get_SDP_V_PK_CLIP(pval)                         ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x24, 0xC, 2, pval)
#define VRX_ret_SDP_V_PK_CLIP()                             ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x24, 0xC, 2)
#define VRX_set_SDP_V_PK_CLIP(val)                          ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x24, 0xC, 2, val)

#define VRX_get_SDP_H_PK_BAND(pval)                         ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x24, 0x3, 0, pval)
#define VRX_ret_SDP_H_PK_BAND()                             ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x24, 0x3, 0)
#define VRX_set_SDP_H_PK_BAND(val)                          ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x24, 0x3, 0, val)

#define VRX_is_SDP_LTI_FILT_SEL_true()                      ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x25, 0x80, 0x7)
#define VRX_get_SDP_LTI_FILT_SEL(pval)                      ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x25, 0x80, 0x7, pval)
#define VRX_ret_SDP_LTI_FILT_SEL()                          ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x25, 0x80, 0x7)
#define VRX_set_SDP_LTI_FILT_SEL(val)                       ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x25, 0x80, 0x7, val)

#define VRX_get_SDP_LTI_LEVEL(pval)                         ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x25, 0x7F, 0, pval)
#define VRX_ret_SDP_LTI_LEVEL()                             ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x25, 0x7F, 0)
#define VRX_set_SDP_LTI_LEVEL(val)                          ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x25, 0x7F, 0, val)

#define VRX_is_SDP_CTI_FILT_SEL_true()                      ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x26, 0x80, 0x7)
#define VRX_get_SDP_CTI_FILT_SEL(pval)                      ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x26, 0x80, 0x7, pval)
#define VRX_ret_SDP_CTI_FILT_SEL()                          ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x26, 0x80, 0x7)
#define VRX_set_SDP_CTI_FILT_SEL(val)                       ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x26, 0x80, 0x7, val)

#define VRX_get_SDP_CTI_LEVEL(pval)                         ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x26, 0x3F, 0, pval)
#define VRX_ret_SDP_CTI_LEVEL()                             ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x26, 0x3F, 0)
#define VRX_set_SDP_CTI_LEVEL(val)                          ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x26, 0x3F, 0, val)

#define VRX_get_SDP_CTI_FLIP(pval)                          ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x27, 0xC0, 6, pval)
#define VRX_ret_SDP_CTI_FLIP()                              ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x27, 0xC0, 6)
#define VRX_set_SDP_CTI_FLIP(val)                           ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x27, 0xC0, 6, val)

#define VRX_get_SDP_LTI_FLIP(pval)                          ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x27, 0xC, 2, pval)
#define VRX_ret_SDP_LTI_FLIP()                              ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x27, 0xC, 2)
#define VRX_set_SDP_LTI_FLIP(val)                           ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x27, 0xC, 2, val)

#define VRX_get_SDP_SCM_CTI_GAIN(pval)                      ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x28, 0x6, 1, pval)
#define VRX_ret_SDP_SCM_CTI_GAIN()                          ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x28, 0x6, 1)
#define VRX_set_SDP_SCM_CTI_GAIN(val)                       ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x28, 0x6, 1, val)

#define VRX_is_SDP_MAN_FB_true()                            ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x2A, 0x80, 0x7)
#define VRX_get_SDP_MAN_FB(pval)                            ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x2A, 0x80, 0x7, pval)
#define VRX_ret_SDP_MAN_FB()                                ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x2A, 0x80, 0x7)
#define VRX_set_SDP_MAN_FB(val)                             ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x2A, 0x80, 0x7, val)

#define VRX_get_SDP_RGB_DELAY_ADJ(pval)                     ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x2A, 0x70, 4, pval)
#define VRX_ret_SDP_RGB_DELAY_ADJ()                         ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x2A, 0x70, 4)
#define VRX_set_SDP_RGB_DELAY_ADJ(val)                      ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x2A, 0x70, 4, val)

#define VRX_is_SDP_MAN_FB_EN_true()                         ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x2A, 0x8, 0x3)
#define VRX_get_SDP_MAN_FB_EN(pval)                         ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x2A, 0x8, 0x3, pval)
#define VRX_ret_SDP_MAN_FB_EN()                             ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x2A, 0x8, 0x3)
#define VRX_set_SDP_MAN_FB_EN(val)                          ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x2A, 0x8, 0x3, val)

#define VRX_get_SDP_FB_DELAY_ADJ(pval)                      ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x2A, 0x7, 0, pval)
#define VRX_ret_SDP_FB_DELAY_ADJ()                          ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x2A, 0x7, 0)
#define VRX_set_SDP_FB_DELAY_ADJ(val)                       ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x2A, 0x7, 0, val)

#define VRX_is_SDP_TBC_EN_true()                            ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x34, 0x80, 0x7)
#define VRX_get_SDP_TBC_EN(pval)                            ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x34, 0x80, 0x7, pval)
#define VRX_ret_SDP_TBC_EN()                                ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x34, 0x80, 0x7)
#define VRX_set_SDP_TBC_EN(val)                             ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x34, 0x80, 0x7, val)

#define VRX_get_SDP_LBOX_BLK_TOP(pval)                      ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x4C, 0xFF, 0, pval)
#define VRX_ret_SDP_LBOX_BLK_TOP()                          ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x4C, 0xFF, 0)

#define VRX_get_SDP_LBOX_BLK_BOT(pval)                      ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x4D, 0xFF, 0, pval)
#define VRX_ret_SDP_LBOX_BLK_BOT()                          ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x4D, 0xFF, 0)

#define VRX_get_SDP_LBOX_BLK_SUB_BOT(pval)                  ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x4E, 0xFF, 0, pval)
#define VRX_ret_SDP_LBOX_BLK_SUB_BOT()                      ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x4E, 0xFF, 0)

#define VRX_get_SDP_SYNCTIP_NOISE(pval)                     {I2C_FIELD_INFO FieldInfo[2]; \
                                                            FieldInfo[0].RegAddr = 0x4F;FieldInfo[0].Mask = 0xFF;FieldInfo[0].LShift = 0x0; \
                                                            FieldInfo[1].RegAddr = 0x53;FieldInfo[1].Mask = 0xFF;FieldInfo[1].LShift = 0x4; \
                                                            ATV_I2CGetRandField32(VRX_SDP_MAP_ADDR, &FieldInfo[0], 5, pval);}
#define VRX_get_SDP_SYNCTIP_NOISE(pval)                     {I2C_FIELD_INFO FieldInfo[2]; \
                                                            FieldInfo[0].RegAddr = 0x4F;FieldInfo[0].Mask = 0xFF;FieldInfo[0].LShift = 0x0; \
                                                            FieldInfo[1].RegAddr = 0x53;FieldInfo[1].Mask = 0xFF;FieldInfo[1].LShift = 0x4; \
                                                            ATV_I2CGetRandField32(VRX_SDP_MAP_ADDR, &FieldInfo[0], 5, pval);}


#define VRX_is_SDP_MV_AGC_DETECTED_true()                   ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x50, 0x8, 0x3)
#define VRX_get_SDP_MV_AGC_DETECTED(pval)                   ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x50, 0x8, 0x3, pval)
#define VRX_ret_SDP_MV_AGC_DETECTED()                       ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x50, 0x8, 0x3)

#define VRX_is_SDP_MV_PS_DETECTED_true()                    ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x50, 0x4, 0x2)
#define VRX_get_SDP_MV_PS_DETECTED(pval)                    ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x50, 0x4, 0x2, pval)
#define VRX_ret_SDP_MV_PS_DETECTED()                        ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x50, 0x4, 0x2)

#define VRX_is_SDP_MVCS_TYPE3_true()                        ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x50, 0x2, 0x1)
#define VRX_get_SDP_MVCS_TYPE3(pval)                        ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x50, 0x2, 0x1, pval)
#define VRX_ret_SDP_MVCS_TYPE3()                            ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x50, 0x2, 0x1)

#define VRX_is_SDP_MVCS_DETECT_true()                       ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x50, 0x1, 0x0)
#define VRX_get_SDP_MVCS_DETECT(pval)                       ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x50, 0x1, 0x0, pval)
#define VRX_ret_SDP_MVCS_DETECT()                           ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x50, 0x1, 0x0)

#define VRX_get_SDP_BP_TOTAL_PULSE_BEG(pval)                ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x51, 0xF0, 4, pval)
#define VRX_ret_SDP_BP_TOTAL_PULSE_BEG()                    ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x51, 0xF0, 4)

#define VRX_get_SDP_BP_TOTAL_PULSES_END(pval)               ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x51, 0xF, 0, pval)
#define VRX_ret_SDP_BP_TOTAL_PULSES_END()                   ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x51, 0xF, 0)

#define VRX_get_SDP_STD(pval)                               ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x52, 0xF, 0, pval)
#define VRX_ret_SDP_STD()                                   ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x52, 0xF, 0)

#define VRX_is_SDP_NOISY_IP_true()                          ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x54, 0x80, 0x7)
#define VRX_get_SDP_NOISY_IP(pval)                          ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x54, 0x80, 0x7, pval)
#define VRX_ret_SDP_NOISY_IP()                              ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x54, 0x80, 0x7)

#define VRX_is_SDP_VERY_NOISY_IP_true()                     ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x54, 0x40, 0x6)
#define VRX_get_SDP_VERY_NOISY_IP(pval)                     ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x54, 0x40, 0x6, pval)
#define VRX_ret_SDP_VERY_NOISY_IP()                         ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x54, 0x40, 0x6)

#define VRX_is_SDP_C_CHAN_ACTIVE_true()                     ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x54, 0x20, 0x5)
#define VRX_get_SDP_C_CHAN_ACTIVE(pval)                     ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x54, 0x20, 0x5, pval)
#define VRX_ret_SDP_C_CHAN_ACTIVE()                         ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x54, 0x20, 0x5)

#define VRX_get_SDP_Y_GAIN_MAN_RB(pval)                     ATV_I2CGetField32(VRX_SDP_MAP_ADDR, 0x54, 0x1F, 0xFF, 0, 2, pval)
#define VRX_ret_SDP_Y_GAIN_MAN_RB()                         ATV_I2CReadField32(VRX_SDP_MAP_ADDR, 0x54, 0x1F, 0xFF, 0, 2)

#define VRX_is_SDP_HSWITCH_PRESENT_true()                   ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x56, 0x80, 0x7)
#define VRX_get_SDP_HSWITCH_PRESENT(pval)                   ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x56, 0x80, 0x7, pval)
#define VRX_ret_SDP_HSWITCH_PRESENT()                       ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x56, 0x80, 0x7)

#define VRX_is_SDP_BLK_NSTD_true()                          ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x56, 0x40, 0x6)
#define VRX_get_SDP_BLK_NSTD(pval)                          ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x56, 0x40, 0x6, pval)
#define VRX_ret_SDP_BLK_NSTD()                              ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x56, 0x40, 0x6)

#define VRX_is_SDP_FLD_NSTD_true()                          ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x56, 0x20, 0x5)
#define VRX_get_SDP_FLD_NSTD(pval)                          ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x56, 0x20, 0x5, pval)
#define VRX_ret_SDP_FLD_NSTD()                              ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x56, 0x20, 0x5)

#define VRX_is_SDP_FRM_NSTD_true()                          ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x56, 0x10, 0x4)
#define VRX_get_SDP_FRM_NSTD(pval)                          ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x56, 0x10, 0x4, pval)
#define VRX_ret_SDP_FRM_NSTD()                              ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x56, 0x10, 0x4)

#define VRX_is_SDP_LC_NSTD_true()                           ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x56, 0x8, 0x3)
#define VRX_get_SDP_LC_NSTD(pval)                           ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x56, 0x8, 0x3, pval)
#define VRX_ret_SDP_LC_NSTD()                               ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x56, 0x8, 0x3)

#define VRX_is_SDP_ALLOW_MED_PLL_true()                     ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x56, 0x4, 0x2)
#define VRX_get_SDP_ALLOW_MED_PLL(pval)                     ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x56, 0x4, 0x2, pval)
#define VRX_ret_SDP_ALLOW_MED_PLL()                         ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x56, 0x4, 0x2)

#define VRX_is_SDP_ALLOW_SLOW_PLL_true()                    ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x56, 0x2, 0x1)
#define VRX_get_SDP_ALLOW_SLOW_PLL(pval)                    ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x56, 0x2, 0x1, pval)
#define VRX_ret_SDP_ALLOW_SLOW_PLL()                        ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x56, 0x2, 0x1)

#define VRX_is_SDP_FREE_RUN_true()                          ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x56, 0x1, 0x0)
#define VRX_get_SDP_FREE_RUN(pval)                          ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x56, 0x1, 0x0, pval)
#define VRX_ret_SDP_FREE_RUN()                              ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x56, 0x1, 0x0)

#define VRX_is_SDP_CKILL_ACT_true()                         ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x57, 0x80, 0x7)
#define VRX_get_SDP_CKILL_ACT(pval)                         ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x57, 0x80, 0x7, pval)
#define VRX_ret_SDP_CKILL_ACT()                             ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x57, 0x80, 0x7)

#define VRX_is_SDP_VS_STD_MODE_true()                       ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x57, 0x40, 0x6)
#define VRX_get_SDP_VS_STD_MODE(pval)                       ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x57, 0x40, 0x6, pval)
#define VRX_ret_SDP_VS_STD_MODE()                           ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x57, 0x40, 0x6)

#define VRX_is_SDP_ALLOW_3D_COMB_true()                     ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x57, 0x10, 0x4)
#define VRX_get_SDP_ALLOW_3D_COMB(pval)                     ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x57, 0x10, 0x4, pval)
#define VRX_ret_SDP_ALLOW_3D_COMB()                         ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x57, 0x10, 0x4)

#define VRX_is_SDP_INTERLACED_true()                        ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x57, 0x8, 0x3)
#define VRX_get_SDP_INTERLACED(pval)                        ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x57, 0x8, 0x3, pval)
#define VRX_ret_SDP_INTERLACED()                            ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x57, 0x8, 0x3)

#define VRX_is_SDP_TRICK_MODE_true()                        ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x57, 0x4, 0x2)
#define VRX_get_SDP_TRICK_MODE(pval)                        ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x57, 0x4, 0x2, pval)
#define VRX_ret_SDP_TRICK_MODE()                            ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x57, 0x4, 0x2)

#define VRX_is_SDP_SD_DETECTED_IN_PR_true()                 ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x58, 0x80, 0x7)
#define VRX_get_SDP_SD_DETECTED_IN_PR(pval)                 ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x58, 0x80, 0x7, pval)
#define VRX_ret_SDP_SD_DETECTED_IN_PR()                     ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x58, 0x80, 0x7)

#define VRX_is_SDP_PR_DETECTED_IN_SD_true()                 ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x58, 0x40, 0x6)
#define VRX_get_SDP_PR_DETECTED_IN_SD(pval)                 ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x58, 0x40, 0x6, pval)
#define VRX_ret_SDP_PR_DETECTED_IN_SD()                     ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x58, 0x40, 0x6)

#define VRX_is_SDP_BURST_LOCKED_RB_true()                   ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x59, 0x80, 0x7)
#define VRX_get_SDP_BURST_LOCKED_RB(pval)                   ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x59, 0x80, 0x7, pval)
#define VRX_ret_SDP_BURST_LOCKED_RB()                       ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x59, 0x80, 0x7)

#define VRX_is_SDP_AD_50_60_HZ_true()                       ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x59, 0x8, 0x3)
#define VRX_get_SDP_AD_50_60_HZ(pval)                       ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x59, 0x8, 0x3, pval)
#define VRX_ret_SDP_AD_50_60_HZ()                           ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x59, 0x8, 0x3)

#define VRX_is_SDP_PAL_SW_LOCKED_true()                     ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x59, 0x4, 0x2)
#define VRX_get_SDP_PAL_SW_LOCKED(pval)                     ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x59, 0x4, 0x2, pval)
#define VRX_ret_SDP_PAL_SW_LOCKED()                         ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x59, 0x4, 0x2)

#define VRX_is_SDP_FSC_FREQ_OK_true()                       ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x59, 0x2, 0x1)
#define VRX_get_SDP_FSC_FREQ_OK(pval)                       ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x59, 0x2, 0x1, pval)
#define VRX_ret_SDP_FSC_FREQ_OK()                           ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x59, 0x2, 0x1)

#define VRX_is_SDP_SCM_LOCKED_true()                        ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x59, 0x1, 0x0)
#define VRX_get_SDP_SCM_LOCKED(pval)                        ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x59, 0x1, 0x0, pval)
#define VRX_ret_SDP_SCM_LOCKED()                            ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x59, 0x1, 0x0)

#define VRX_is_SDP_VIDEO_DETECTED_true()                    ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x5A, 0x1, 0x0)
#define VRX_get_SDP_VIDEO_DETECTED(pval)                    ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x5A, 0x1, 0x0, pval)
#define VRX_ret_SDP_VIDEO_DETECTED()                        ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x5A, 0x1, 0x0)

#define VRX_is_SDP_EXTEND_VS_MAX_FREQ_true()                ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x7B, 0x4, 0x2)
#define VRX_get_SDP_EXTEND_VS_MAX_FREQ(pval)                ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x7B, 0x4, 0x2, pval)
#define VRX_ret_SDP_EXTEND_VS_MAX_FREQ()                    ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x7B, 0x4, 0x2)
#define VRX_set_SDP_EXTEND_VS_MAX_FREQ(val)                 ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x7B, 0x4, 0x2, val)

#define VRX_is_SDP_EXTEND_VS_MIN_FREQ_true()                ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x7B, 0x2, 0x1)
#define VRX_get_SDP_EXTEND_VS_MIN_FREQ(pval)                ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x7B, 0x2, 0x1, pval)
#define VRX_ret_SDP_EXTEND_VS_MIN_FREQ()                    ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x7B, 0x2, 0x1)
#define VRX_set_SDP_EXTEND_VS_MIN_FREQ(val)                 ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x7B, 0x2, 0x1, val)

#define VRX_is_SDP_LIMIT_Y_GAIN_true()                      ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x89, 0x80, 0x7)
#define VRX_get_SDP_LIMIT_Y_GAIN(pval)                      ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x89, 0x80, 0x7, pval)
#define VRX_ret_SDP_LIMIT_Y_GAIN()                          ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x89, 0x80, 0x7)
#define VRX_set_SDP_LIMIT_Y_GAIN(val)                       ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x89, 0x80, 0x7, val)

#define VRX_is_SDP_LIMIT_C_GAIN_true()                      ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x89, 0x40, 0x6)
#define VRX_get_SDP_LIMIT_C_GAIN(pval)                      ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x89, 0x40, 0x6, pval)
#define VRX_ret_SDP_LIMIT_C_GAIN()                          ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x89, 0x40, 0x6)
#define VRX_set_SDP_LIMIT_C_GAIN(val)                       ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x89, 0x40, 0x6, val)

#define VRX_is_SDP_LIMIT_UV_GAIN_true()                     ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x89, 0x20, 0x5)
#define VRX_get_SDP_LIMIT_UV_GAIN(pval)                     ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x89, 0x20, 0x5, pval)
#define VRX_ret_SDP_LIMIT_UV_GAIN()                         ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x89, 0x20, 0x5)
#define VRX_set_SDP_LIMIT_UV_GAIN(val)                      ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x89, 0x20, 0x5, val)

#define VRX_is_SDP_LIMIT_G_GAIN_true()                      ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x89, 0x10, 0x4)
#define VRX_get_SDP_LIMIT_G_GAIN(pval)                      ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x89, 0x10, 0x4, pval)
#define VRX_ret_SDP_LIMIT_G_GAIN()                          ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x89, 0x10, 0x4)
#define VRX_set_SDP_LIMIT_G_GAIN(val)                       ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x89, 0x10, 0x4, val)

#define VRX_is_SDP_NSY_DIS_SFS_STD_true()                   ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x98, 0x80, 0x7)
#define VRX_get_SDP_NSY_DIS_SFS_STD(pval)                   ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x98, 0x80, 0x7, pval)
#define VRX_ret_SDP_NSY_DIS_SFS_STD()                       ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x98, 0x80, 0x7)
#define VRX_set_SDP_NSY_DIS_SFS_STD(val)                    ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x98, 0x80, 0x7, val)

#define VRX_is_SDP_HSW2_DIS_SFS_STD_true()                  ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x98, 0x40, 0x6)
#define VRX_get_SDP_HSW2_DIS_SFS_STD(pval)                  ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x98, 0x40, 0x6, pval)
#define VRX_ret_SDP_HSW2_DIS_SFS_STD()                      ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x98, 0x40, 0x6)
#define VRX_set_SDP_HSW2_DIS_SFS_STD(val)                   ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x98, 0x40, 0x6, val)

#define VRX_is_SDP_HSW1_DIS_SFS_STD_true()                  ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x98, 0x20, 0x5)
#define VRX_get_SDP_HSW1_DIS_SFS_STD(pval)                  ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x98, 0x20, 0x5, pval)
#define VRX_ret_SDP_HSW1_DIS_SFS_STD()                      ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x98, 0x20, 0x5)
#define VRX_set_SDP_HSW1_DIS_SFS_STD(val)                   ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x98, 0x20, 0x5, val)

#define VRX_is_SDP_LC_DIS_SFS_STD_true()                    ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x98, 0x10, 0x4)
#define VRX_get_SDP_LC_DIS_SFS_STD(pval)                    ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x98, 0x10, 0x4, pval)
#define VRX_ret_SDP_LC_DIS_SFS_STD()                        ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x98, 0x10, 0x4)
#define VRX_set_SDP_LC_DIS_SFS_STD(val)                     ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x98, 0x10, 0x4, val)

#define VRX_is_SDP_BLK_DIS_SFS_STD_true()                   ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x98, 0x8, 0x3)
#define VRX_get_SDP_BLK_DIS_SFS_STD(pval)                   ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x98, 0x8, 0x3, pval)
#define VRX_ret_SDP_BLK_DIS_SFS_STD()                       ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x98, 0x8, 0x3)
#define VRX_set_SDP_BLK_DIS_SFS_STD(val)                    ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x98, 0x8, 0x3, val)

#define VRX_is_SDP_FLD_SFS_STD_true()                       ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x98, 0x4, 0x2)
#define VRX_get_SDP_FLD_SFS_STD(pval)                       ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x98, 0x4, 0x2, pval)
#define VRX_ret_SDP_FLD_SFS_STD()                           ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x98, 0x4, 0x2)
#define VRX_set_SDP_FLD_SFS_STD(val)                        ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x98, 0x4, 0x2, val)

#define VRX_is_SDP_FRM_DIS_SFS_STD_true()                   ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x98, 0x2, 0x1)
#define VRX_get_SDP_FRM_DIS_SFS_STD(pval)                   ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x98, 0x2, 0x1, pval)
#define VRX_ret_SDP_FRM_DIS_SFS_STD()                       ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x98, 0x2, 0x1)
#define VRX_set_SDP_FRM_DIS_SFS_STD(val)                    ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x98, 0x2, 0x1, val)

#define VRX_is_SDP_VNSY_DIS_SFS_STD_true()                  ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0x98, 0x1, 0x0)
#define VRX_get_SDP_VNSY_DIS_SFS_STD(pval)                  ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x98, 0x1, 0x0, pval)
#define VRX_ret_SDP_VNSY_DIS_SFS_STD()                      ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x98, 0x1, 0x0)
#define VRX_set_SDP_VNSY_DIS_SFS_STD(val)                   ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x98, 0x1, 0x0, val)

#define VRX_get_SDP_SHAPE_STD_FILT_SEL(pval)                ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x99, 0x70, 4, pval)
#define VRX_ret_SDP_SHAPE_STD_FILT_SEL()                    ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x99, 0x70, 4)
#define VRX_set_SDP_SHAPE_STD_FILT_SEL(val)                 ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x99, 0x70, 4, val)

#define VRX_get_SDP_ALLOW_3D_FILT_SEL(pval)                 ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0x9A, 0x7, 0, pval)
#define VRX_ret_SDP_ALLOW_3D_FILT_SEL()                     ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0x9A, 0x7, 0)
#define VRX_set_SDP_ALLOW_3D_FILT_SEL(val)                  ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0x9A, 0x7, 0, val)

#define VRX_get_SDP_NOISY_THR(pval)                         ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0xA1, 0xFF, 0, pval)
#define VRX_ret_SDP_NOISY_THR()                             ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0xA1, 0xFF, 0)
#define VRX_set_SDP_NOISY_THR(val)                          ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0xA1, 0xFF, 0, val)

#define VRX_get_SDP_VERY_NOISY_THR(pval)                    ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0xA2, 0xFF, 0, pval)
#define VRX_ret_SDP_VERY_NOISY_THR()                        ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0xA2, 0xFF, 0)
#define VRX_set_SDP_VERY_NOISY_THR(val)                     ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0xA2, 0xFF, 0, val)

#define VRX_is_SDP_CKILL_DIS_3D_true()                      ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0xA3, 0x80, 0x7)
#define VRX_get_SDP_CKILL_DIS_3D(pval)                      ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0xA3, 0x80, 0x7, pval)
#define VRX_ret_SDP_CKILL_DIS_3D()                          ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0xA3, 0x80, 0x7)
#define VRX_set_SDP_CKILL_DIS_3D(val)                       ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0xA3, 0x80, 0x7, val)

#define VRX_is_SDP_CKILL_DIS_2D_true()                      ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0xA4, 0x80, 0x7)
#define VRX_get_SDP_CKILL_DIS_2D(pval)                      ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0xA4, 0x80, 0x7, pval)
#define VRX_ret_SDP_CKILL_DIS_2D()                          ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0xA4, 0x80, 0x7)
#define VRX_set_SDP_CKILL_DIS_2D(val)                       ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0xA4, 0x80, 0x7, val)

#define VRX_is_SDP_NOISY_HSW2_DIS_3D_true()                 ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0xA4, 0x40, 0x6)
#define VRX_get_SDP_NOISY_HSW2_DIS_3D(pval)                 ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0xA4, 0x40, 0x6, pval)
#define VRX_ret_SDP_NOISY_HSW2_DIS_3D()                     ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0xA4, 0x40, 0x6)
#define VRX_set_SDP_NOISY_HSW2_DIS_3D(val)                  ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0xA4, 0x40, 0x6, val)

#define VRX_is_SDP_NOISY_HSW1_DIS_3D_true()                 ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0xA4, 0x20, 0x5)
#define VRX_get_SDP_NOISY_HSW1_DIS_3D(pval)                 ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0xA4, 0x20, 0x5, pval)
#define VRX_ret_SDP_NOISY_HSW1_DIS_3D()                     ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0xA4, 0x20, 0x5)
#define VRX_set_SDP_NOISY_HSW1_DIS_3D(val)                  ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0xA4, 0x20, 0x5, val)

#define VRX_is_SDP_NOISY_LC_DIS_3D_true()                   ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0xA4, 0x10, 0x4)
#define VRX_get_SDP_NOISY_LC_DIS_3D(pval)                   ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0xA4, 0x10, 0x4, pval)
#define VRX_ret_SDP_NOISY_LC_DIS_3D()                       ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0xA4, 0x10, 0x4)
#define VRX_set_SDP_NOISY_LC_DIS_3D(val)                    ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0xA4, 0x10, 0x4, val)

#define VRX_is_SDP_NOISY_BLK_DIS_3D_true()                  ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0xA4, 0x8, 0x3)
#define VRX_get_SDP_NOISY_BLK_DIS_3D(pval)                  ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0xA4, 0x8, 0x3, pval)
#define VRX_ret_SDP_NOISY_BLK_DIS_3D()                      ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0xA4, 0x8, 0x3)
#define VRX_set_SDP_NOISY_BLK_DIS_3D(val)                   ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0xA4, 0x8, 0x3, val)

#define VRX_is_SDP_NOISY_FLD_DIS_3D_true()                  ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0xA4, 0x4, 0x2)
#define VRX_get_SDP_NOISY_FLD_DIS_3D(pval)                  ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0xA4, 0x4, 0x2, pval)
#define VRX_ret_SDP_NOISY_FLD_DIS_3D()                      ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0xA4, 0x4, 0x2)
#define VRX_set_SDP_NOISY_FLD_DIS_3D(val)                   ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0xA4, 0x4, 0x2, val)

#define VRX_is_SDP_NOISY_FRM_DIS_3D_true()                  ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0xA4, 0x2, 0x1)
#define VRX_get_SDP_NOISY_FRM_DIS_3D(pval)                  ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0xA4, 0x2, 0x1, pval)
#define VRX_ret_SDP_NOISY_FRM_DIS_3D()                      ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0xA4, 0x2, 0x1)
#define VRX_set_SDP_NOISY_FRM_DIS_3D(val)                   ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0xA4, 0x2, 0x1, val)

#define VRX_is_SDP_NOISY_DIS_3D_true()                      ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0xA4, 0x1, 0x0)
#define VRX_get_SDP_NOISY_DIS_3D(pval)                      ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0xA4, 0x1, 0x0, pval)
#define VRX_ret_SDP_NOISY_DIS_3D()                          ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0xA4, 0x1, 0x0)
#define VRX_set_SDP_NOISY_DIS_3D(val)                       ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0xA4, 0x1, 0x0, val)

#define VRX_is_SDP_P60_N443_DIS_3D_true()                   ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0xA5, 0x80, 0x7)
#define VRX_get_SDP_P60_N443_DIS_3D(pval)                   ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0xA5, 0x80, 0x7, pval)
#define VRX_ret_SDP_P60_N443_DIS_3D()                       ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0xA5, 0x80, 0x7)
#define VRX_set_SDP_P60_N443_DIS_3D(val)                    ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0xA5, 0x80, 0x7, val)

#define VRX_is_SDP_VNOISY_HSW2_DIS_3D_true()                ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0xA5, 0x40, 0x6)
#define VRX_get_SDP_VNOISY_HSW2_DIS_3D(pval)                ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0xA5, 0x40, 0x6, pval)
#define VRX_ret_SDP_VNOISY_HSW2_DIS_3D()                    ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0xA5, 0x40, 0x6)
#define VRX_set_SDP_VNOISY_HSW2_DIS_3D(val)                 ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0xA5, 0x40, 0x6, val)

#define VRX_is_SDP_VNOISY_HSW1_DIS_3D_true()                ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0xA5, 0x20, 0x5)
#define VRX_get_SDP_VNOISY_HSW1_DIS_3D(pval)                ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0xA5, 0x20, 0x5, pval)
#define VRX_ret_SDP_VNOISY_HSW1_DIS_3D()                    ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0xA5, 0x20, 0x5)
#define VRX_set_SDP_VNOISY_HSW1_DIS_3D(val)                 ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0xA5, 0x20, 0x5, val)

#define VRX_is_SDP_VNOISY_LC_DIS_3D_true()                  ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0xA5, 0x10, 0x4)
#define VRX_get_SDP_VNOISY_LC_DIS_3D(pval)                  ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0xA5, 0x10, 0x4, pval)
#define VRX_ret_SDP_VNOISY_LC_DIS_3D()                      ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0xA5, 0x10, 0x4)
#define VRX_set_SDP_VNOISY_LC_DIS_3D(val)                   ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0xA5, 0x10, 0x4, val)

#define VRX_is_SDP_VNOISY_BLK_DIS_3D_true()                 ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0xA5, 0x8, 0x3)
#define VRX_get_SDP_VNOISY_BLK_DIS_3D(pval)                 ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0xA5, 0x8, 0x3, pval)
#define VRX_ret_SDP_VNOISY_BLK_DIS_3D()                     ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0xA5, 0x8, 0x3)
#define VRX_set_SDP_VNOISY_BLK_DIS_3D(val)                  ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0xA5, 0x8, 0x3, val)

#define VRX_is_SDP_VNOISY_FLD_DIS_3D_true()                 ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0xA5, 0x4, 0x2)
#define VRX_get_SDP_VNOISY_FLD_DIS_3D(pval)                 ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0xA5, 0x4, 0x2, pval)
#define VRX_ret_SDP_VNOISY_FLD_DIS_3D()                     ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0xA5, 0x4, 0x2)
#define VRX_set_SDP_VNOISY_FLD_DIS_3D(val)                  ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0xA5, 0x4, 0x2, val)

#define VRX_is_SDP_VNOISY_FRM_DIS_3D_true()                 ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0xA5, 0x2, 0x1)
#define VRX_get_SDP_VNOISY_FRM_DIS_3D(pval)                 ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0xA5, 0x2, 0x1, pval)
#define VRX_ret_SDP_VNOISY_FRM_DIS_3D()                     ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0xA5, 0x2, 0x1)
#define VRX_set_SDP_VNOISY_FRM_DIS_3D(val)                  ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0xA5, 0x2, 0x1, val)

#define VRX_is_SDP_VNOISY_DIS_3D_true()                     ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0xA5, 0x1, 0x0)
#define VRX_get_SDP_VNOISY_DIS_3D(pval)                     ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0xA5, 0x1, 0x0, pval)
#define VRX_ret_SDP_VNOISY_DIS_3D()                         ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0xA5, 0x1, 0x0)
#define VRX_set_SDP_VNOISY_DIS_3D(val)                      ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0xA5, 0x1, 0x0, val)

#define VRX_get_SDP_3D_COMB_NOISE_SNS(pval)                 ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0xA8, 0x7F, 0, pval)
#define VRX_ret_SDP_3D_COMB_NOISE_SNS()                     ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0xA8, 0x7F, 0)
#define VRX_set_SDP_3D_COMB_NOISE_SNS(val)                  ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0xA8, 0x7F, 0, val)

#define VRX_get_SDP_3D_COMB_CHROMA_CORE(pval)               ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0xA9, 0xF0, 4, pval)
#define VRX_ret_SDP_3D_COMB_CHROMA_CORE()                   ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0xA9, 0xF0, 4)
#define VRX_set_SDP_3D_COMB_CHROMA_CORE(val)                ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0xA9, 0xF0, 4, val)

#define VRX_get_SDP_3D_COMB_CHROMA_SNS(pval)                ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0xA9, 0xF, 0, pval)
#define VRX_ret_SDP_3D_COMB_CHROMA_SNS()                    ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0xA9, 0xF, 0)
#define VRX_set_SDP_3D_COMB_CHROMA_SNS(val)                 ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0xA9, 0xF, 0, val)

#define VRX_get_SDP_3D_COMB_LUMA_CORE(pval)                 ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0xAA, 0xF0, 4, pval)
#define VRX_ret_SDP_3D_COMB_LUMA_CORE()                     ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0xAA, 0xF0, 4)
#define VRX_set_SDP_3D_COMB_LUMA_CORE(val)                  ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0xAA, 0xF0, 4, val)

#define VRX_get_SDP_3D_COMB_LUMA_SNS(pval)                  ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0xAA, 0xF, 0, pval)
#define VRX_ret_SDP_3D_COMB_LUMA_SNS()                      ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0xAA, 0xF, 0)
#define VRX_set_SDP_3D_COMB_LUMA_SNS(val)                   ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0xAA, 0xF, 0, val)

#define VRX_is_SDP_SHIP_INT_EN_true()                       ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0xD9, 0x40, 0x6)
#define VRX_get_SDP_SHIP_INT_EN(pval)                       ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0xD9, 0x40, 0x6, pval)
#define VRX_ret_SDP_SHIP_INT_EN()                           ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0xD9, 0x40, 0x6)
#define VRX_set_SDP_SHIP_INT_EN(val)                        ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0xD9, 0x40, 0x6, val)

#define VRX_get_SDP_LBOX_END_DEL(pval)                      ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0xDB, 0xF0, 4, pval)
#define VRX_ret_SDP_LBOX_END_DEL()                          ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0xDB, 0xF0, 4)
#define VRX_set_SDP_LBOX_END_DEL(val)                       ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0xDB, 0xF0, 4, val)

#define VRX_get_SDP_LBOX_BEG_DEL(pval)                      ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0xDB, 0xF, 0, pval)
#define VRX_ret_SDP_LBOX_BEG_DEL()                          ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0xDB, 0xF, 0)
#define VRX_set_SDP_LBOX_BEG_DEL(val)                       ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0xDB, 0xF, 0, val)

#define VRX_get_SDP_LBOX_BLK_LVL(pval)                      ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0xDC, 0xE0, 5, pval)
#define VRX_ret_SDP_LBOX_BLK_LVL()                          ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0xDC, 0xE0, 5)
#define VRX_set_SDP_LBOX_BLK_LVL(val)                       ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0xDC, 0xE0, 5, val)

#define VRX_get_SDP_LBOX_THR(pval)                          ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0xDC, 0x1F, 0, pval)
#define VRX_ret_SDP_LBOX_THR()                              ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0xDC, 0x1F, 0)
#define VRX_set_SDP_LBOX_THR(val)                           ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0xDC, 0x1F, 0, val)

#define VRX_is_SDP_FREE_RUN_AUTO_true()                     ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0xDD, 0x8, 0x3)
#define VRX_get_SDP_FREE_RUN_AUTO(pval)                     ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0xDD, 0x8, 0x3, pval)
#define VRX_ret_SDP_FREE_RUN_AUTO()                         ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0xDD, 0x8, 0x3)
#define VRX_set_SDP_FREE_RUN_AUTO(val)                      ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0xDD, 0x8, 0x3, val)

#define VRX_is_SDP_FREE_RUN_MAN_COL_EN_true()               ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0xDD, 0x4, 0x2)
#define VRX_get_SDP_FREE_RUN_MAN_COL_EN(pval)               ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0xDD, 0x4, 0x2, pval)
#define VRX_ret_SDP_FREE_RUN_MAN_COL_EN()                   ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0xDD, 0x4, 0x2)
#define VRX_set_SDP_FREE_RUN_MAN_COL_EN(val)                ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0xDD, 0x4, 0x2, val)

#define VRX_is_SDP_FREE_RUN_CBAR_EN_true()                  ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0xDD, 0x2, 0x1)
#define VRX_get_SDP_FREE_RUN_CBAR_EN(pval)                  ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0xDD, 0x2, 0x1, pval)
#define VRX_ret_SDP_FREE_RUN_CBAR_EN()                      ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0xDD, 0x2, 0x1)
#define VRX_set_SDP_FREE_RUN_CBAR_EN(val)                   ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0xDD, 0x2, 0x1, val)

#define VRX_is_SDP_FORCE_FREE_RUN_true()                    ATV_I2CIsField8(VRX_SDP_MAP_ADDR, 0xDD, 0x1, 0x0)
#define VRX_get_SDP_FORCE_FREE_RUN(pval)                    ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0xDD, 0x1, 0x0, pval)
#define VRX_ret_SDP_FORCE_FREE_RUN()                        ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0xDD, 0x1, 0x0)
#define VRX_set_SDP_FORCE_FREE_RUN(val)                     ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0xDD, 0x1, 0x0, val)

#define VRX_get_SDP_FREE_RUN_Y(pval)                        ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0xDE, 0xFF, 0, pval)
#define VRX_ret_SDP_FREE_RUN_Y()                            ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0xDE, 0xFF, 0)
#define VRX_set_SDP_FREE_RUN_Y(val)                         ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0xDE, 0xFF, 0, val)

#define VRX_get_SDP_FREE_RUN_V(pval)                        ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0xDF, 0xF0, 4, pval)
#define VRX_ret_SDP_FREE_RUN_V()                            ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0xDF, 0xF0, 4)
#define VRX_set_SDP_FREE_RUN_V(val)                         ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0xDF, 0xF0, 4, val)

#define VRX_get_SDP_FREE_RUN_U(pval)                        ATV_I2CGetField8(VRX_SDP_MAP_ADDR, 0xDF, 0xF, 0, pval)
#define VRX_ret_SDP_FREE_RUN_U()                            ATV_I2CReadField8(VRX_SDP_MAP_ADDR, 0xDF, 0xF, 0)
#define VRX_set_SDP_FREE_RUN_U(val)                         ATV_I2CWriteField8(VRX_SDP_MAP_ADDR, 0xDF, 0xF, 0, val)

#endif
