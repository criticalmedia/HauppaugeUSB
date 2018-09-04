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


#ifndef ADV7842_VDP_MAP_FCT_H
#define ADV7842_VDP_MAP_FCT_H

#include "ADV7842_cfg.h"

#define VRX_get_VDP_CGMS_TYPEB_DATA(pval)                   ATV_I2CGetField32LE(VRX_VDP_MAP_ADDR, 0x3C, 0xFF, 0xFF, 0, 2, pval)
#define VRX_ret_VDP_CGMS_TYPEB_DATA()                       ATV_I2CReadField32LE(VRX_VDP_MAP_ADDR, 0x3C, 0xFF, 0xFF, 0, 2)

#define VRX_get_VDP_CGMS_TYPEB_DATA_3(pval)                 ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x3E, 0xFF, 16, pval)
#define VRX_ret_VDP_CGMS_TYPEB_DATA_3()                     ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x3E, 0xFF, 16)

#define VRX_get_VDP_CGMS_TYPEB_DATA_4(pval)                 ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x3F, 0xFF, 24, pval)
#define VRX_ret_VDP_CGMS_TYPEB_DATA_4()                     ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x3F, 0xFF, 24)

#define VRX_is_VDP_STATUS_TTXT_true()                       ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0x40, 0x80, 0x7)
#define VRX_get_VDP_STATUS_TTXT(pval)                       ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x40, 0x80, 0x7, pval)
#define VRX_ret_VDP_STATUS_TTXT()                           ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x40, 0x80, 0x7)

#define VRX_is_VDP_STATUS_VITC_true()                       ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0x40, 0x40, 0x6)
#define VRX_get_VDP_STATUS_VITC(pval)                       ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x40, 0x40, 0x6, pval)
#define VRX_ret_VDP_STATUS_VITC()                           ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x40, 0x40, 0x6)

#define VRX_is_VDP_STATUS_GEMS_TYPE_true()                  ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0x40, 0x20, 0x5)
#define VRX_get_VDP_STATUS_GEMS_TYPE(pval)                  ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x40, 0x20, 0x5, pval)
#define VRX_ret_VDP_STATUS_GEMS_TYPE()                      ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x40, 0x20, 0x5)

#define VRX_is_VDP_STATUS_GS_VPS_PDC_UTC_CGMSTB_true()      ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0x40, 0x10, 0x4)
#define VRX_get_VDP_STATUS_GS_VPS_PDC_UTC_CGMSTB(pval)      ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x40, 0x10, 0x4, pval)
#define VRX_ret_VDP_STATUS_GS_VPS_PDC_UTC_CGMSTB()          ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x40, 0x10, 0x4)

#define VRX_is_VDP_STATUS_FAST_I2C_true()                   ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0x40, 0x8, 0x3)
#define VRX_get_VDP_STATUS_FAST_I2C(pval)                   ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x40, 0x8, 0x3, pval)
#define VRX_ret_VDP_STATUS_FAST_I2C()                       ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x40, 0x8, 0x3)

#define VRX_is_VDP_STATUS_WSS_CGMS_true()                   ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0x40, 0x4, 0x2)
#define VRX_get_VDP_STATUS_WSS_CGMS(pval)                   ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x40, 0x4, 0x2, pval)
#define VRX_ret_VDP_STATUS_WSS_CGMS()                       ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x40, 0x4, 0x2)

#define VRX_is_VDP_STATUS_CCAP_EVEN_FIELD_true()            ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0x40, 0x2, 0x1)
#define VRX_get_VDP_STATUS_CCAP_EVEN_FIELD(pval)            ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x40, 0x2, 0x1, pval)
#define VRX_ret_VDP_STATUS_CCAP_EVEN_FIELD()                ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x40, 0x2, 0x1)

#define VRX_is_VDP_STATUS_CCAP_true()                       ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0x40, 0x1, 0x0)
#define VRX_get_VDP_STATUS_CCAP(pval)                       ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x40, 0x1, 0x0, pval)
#define VRX_ret_VDP_STATUS_CCAP()                           ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x40, 0x1, 0x0)

#define VRX_get_VDP_CCAP_DATA(pval)                         ATV_I2CGetField32LE(VRX_VDP_MAP_ADDR, 0x41, 0xFF, 0xFF, 0, 2, pval)
#define VRX_ret_VDP_CCAP_DATA()                             ATV_I2CReadField32LE(VRX_VDP_MAP_ADDR, 0x41, 0xFF, 0xFF, 0, 2)

#define VRX_get_VDP_CGMS_WSS_DATA(pval)                     ATV_I2CGetField32(VRX_VDP_MAP_ADDR, 0x43, 0xFF, 0xFF, 0, 3, pval)
#define VRX_ret_VDP_CGMS_WSS_DATA()                         ATV_I2CReadField32(VRX_VDP_MAP_ADDR, 0x43, 0xFF, 0xFF, 0, 3)

#define VRX_get_VDP_GS_VPS_PDC_UTC_CGMSTB_DATA(pval)        ATV_I2CGetMultiField(VRX_VDP_MAP_ADDR, 0x47, 13, pval)

#define VRX_get_VDP_VITC_DATA(pval)                         ATV_I2CGetMultiField(VRX_VDP_MAP_ADDR, 0x55, 9, pval)

#define VRX_get_VDP_VITC_CALC_CRC(pval)                     ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x5E, 0xFF, 0, pval)
#define VRX_ret_VDP_VITC_CALC_CRC()                         ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x5E, 0xFF, 0)

#define VRX_is_HAM_ERR_OP_EN_true()                         ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0x60, 0x80, 0x7)
#define VRX_get_HAM_ERR_OP_EN(pval)                         ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x60, 0x80, 0x7, pval)
#define VRX_ret_HAM_ERR_OP_EN()                             ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x60, 0x80, 0x7)
#define VRX_set_HAM_ERR_OP_EN(val)                          ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x60, 0x80, 0x7, val)

#define VRX_get_SOFT_ERROR_CORRECTION_MODE(pval)            ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x60, 0x60, 5, pval)
#define VRX_ret_SOFT_ERROR_CORRECTION_MODE()                ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x60, 0x60, 5)
#define VRX_set_SOFT_ERROR_CORRECTION_MODE(val)             ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x60, 0x60, 5, val)

#define VRX_is_SOFT_ERROR_CORRECTION_EN_true()              ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0x60, 0x10, 0x4)
#define VRX_get_SOFT_ERROR_CORRECTION_EN(pval)              ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x60, 0x10, 0x4, pval)
#define VRX_ret_SOFT_ERROR_CORRECTION_EN()                  ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x60, 0x10, 0x4)
#define VRX_set_SOFT_ERROR_CORRECTION_EN(val)               ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x60, 0x10, 0x4, val)

#define VRX_is_EN_FC_WINDOW_AFTER_CRI_DET_true()            ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0x60, 0x8, 0x3)
#define VRX_get_EN_FC_WINDOW_AFTER_CRI_DET(pval)            ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x60, 0x8, 0x3, pval)
#define VRX_ret_EN_FC_WINDOW_AFTER_CRI_DET()                ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x60, 0x8, 0x3)
#define VRX_set_EN_FC_WINDOW_AFTER_CRI_DET(val)             ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x60, 0x8, 0x3, val)

#define VRX_is_VDP_TTXT_TYPE_MAN_EN_true()                  ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0x60, 0x4, 0x2)
#define VRX_get_VDP_TTXT_TYPE_MAN_EN(pval)                  ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x60, 0x4, 0x2, pval)
#define VRX_ret_VDP_TTXT_TYPE_MAN_EN()                      ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x60, 0x4, 0x2)
#define VRX_set_VDP_TTXT_TYPE_MAN_EN(val)                   ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x60, 0x4, 0x2, val)

#define VRX_get_VDP_TTXT_TYPE(pval)                         ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x60, 0x3, 0, pval)
#define VRX_ret_VDP_TTXT_TYPE()                             ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x60, 0x3, 0)
#define VRX_set_VDP_TTXT_TYPE(val)                          ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x60, 0x3, 0, val)

#define VRX_is_VDP_CP_CLMP_AVG_true()                       ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0x61, 0x80, 0x7)
#define VRX_get_VDP_CP_CLMP_AVG(pval)                       ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x61, 0x80, 0x7, pval)
#define VRX_ret_VDP_CP_CLMP_AVG()                           ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x61, 0x80, 0x7)
#define VRX_set_VDP_CP_CLMP_AVG(val)                        ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x61, 0x80, 0x7, val)

#define VRX_is_NOISE_CLK_DISABLE_true()                     ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0x61, 0x20, 0x5)
#define VRX_get_NOISE_CLK_DISABLE(pval)                     ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x61, 0x20, 0x5, pval)
#define VRX_ret_NOISE_CLK_DISABLE()                         ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x61, 0x20, 0x5)
#define VRX_set_NOISE_CLK_DISABLE(val)                      ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x61, 0x20, 0x5, val)

#define VRX_is_AUTO_DETECT_GEM_true()                       ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0x61, 0x10, 0x4)
#define VRX_get_AUTO_DETECT_GEM(pval)                       ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x61, 0x10, 0x4, pval)
#define VRX_ret_AUTO_DETECT_GEM()                           ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x61, 0x10, 0x4)
#define VRX_set_AUTO_DETECT_GEM(val)                        ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x61, 0x10, 0x4, val)

#define VRX_is_VITC_STRIP_SYNC_DISABLE_true()               ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0x61, 0x2, 0x1)
#define VRX_get_VITC_STRIP_SYNC_DISABLE(pval)               ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x61, 0x2, 0x1, pval)
#define VRX_ret_VITC_STRIP_SYNC_DISABLE()                   ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x61, 0x2, 0x1)
#define VRX_set_VITC_STRIP_SYNC_DISABLE(val)                ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x61, 0x2, 0x1, val)

#define VRX_is_BIPHASE_DECODE_DISABLE_true()                ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0x61, 0x1, 0x0)
#define VRX_get_BIPHASE_DECODE_DISABLE(pval)                ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x61, 0x1, 0x0, pval)
#define VRX_ret_BIPHASE_DECODE_DISABLE()                    ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x61, 0x1, 0x0)
#define VRX_set_BIPHASE_DECODE_DISABLE(val)                 ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x61, 0x1, 0x0, val)

#define VRX_is_ADF_EN_true()                                ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0x62, 0x80, 0x7)
#define VRX_get_ADF_EN(pval)                                ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x62, 0x80, 0x7, pval)
#define VRX_ret_ADF_EN()                                    ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x62, 0x80, 0x7)
#define VRX_set_ADF_EN(val)                                 ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x62, 0x80, 0x7, val)

#define VRX_get_ADF_MODE(pval)                              ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x62, 0x60, 5, pval)
#define VRX_ret_ADF_MODE()                                  ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x62, 0x60, 5)
#define VRX_set_ADF_MODE(val)                               ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x62, 0x60, 5, val)

#define VRX_get_ADF_DID(pval)                               ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x62, 0x1F, 0, pval)
#define VRX_ret_ADF_DID()                                   ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x62, 0x1F, 0)
#define VRX_set_ADF_DID(val)                                ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x62, 0x1F, 0, val)

#define VRX_is_TOGGLE_ADF_true()                            ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0x63, 0x80, 0x7)
#define VRX_get_TOGGLE_ADF(pval)                            ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x63, 0x80, 0x7, pval)
#define VRX_ret_TOGGLE_ADF()                                ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x63, 0x80, 0x7)
#define VRX_set_TOGGLE_ADF(val)                             ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x63, 0x80, 0x7, val)

#define VRX_get_ADF_SDID(pval)                              ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x63, 0x3F, 0, pval)
#define VRX_ret_ADF_SDID()                                  ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x63, 0x3F, 0)
#define VRX_set_ADF_SDID(val)                               ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x63, 0x3F, 0, val)

#define VRX_get_VDP_MAN_LINE_1_21(pval)                     ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x64, 0xFF, 0, pval)
#define VRX_ret_VDP_MAN_LINE_1_21()                         ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x64, 0xFF, 0)
#define VRX_set_VDP_MAN_LINE_1_21(val)                      ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x64, 0xFF, 0, val)

#define VRX_get_VDP_MAN_LINE_2_22(pval)                     ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x65, 0xFF, 0, pval)
#define VRX_ret_VDP_MAN_LINE_2_22()                         ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x65, 0xFF, 0)
#define VRX_set_VDP_MAN_LINE_2_22(val)                      ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x65, 0xFF, 0, val)

#define VRX_get_VDP_MAN_LINE_3_23(pval)                     ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x66, 0xFF, 0, pval)
#define VRX_ret_VDP_MAN_LINE_3_23()                         ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x66, 0xFF, 0)
#define VRX_set_VDP_MAN_LINE_3_23(val)                      ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x66, 0xFF, 0, val)

#define VRX_get_VDP_MAN_LINE_4_24(pval)                     ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x67, 0xFF, 0, pval)
#define VRX_ret_VDP_MAN_LINE_4_24()                         ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x67, 0xFF, 0)
#define VRX_set_VDP_MAN_LINE_4_24(val)                      ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x67, 0xFF, 0, val)

#define VRX_get_VDP_MAN_LINE_5_25(pval)                     ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x68, 0xFF, 0, pval)
#define VRX_ret_VDP_MAN_LINE_5_25()                         ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x68, 0xFF, 0)
#define VRX_set_VDP_MAN_LINE_5_25(val)                      ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x68, 0xFF, 0, val)

#define VRX_get_VDP_MAN_LINE_6_26(pval)                     ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x69, 0xFF, 0, pval)
#define VRX_ret_VDP_MAN_LINE_6_26()                         ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x69, 0xFF, 0)
#define VRX_set_VDP_MAN_LINE_6_26(val)                      ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x69, 0xFF, 0, val)

#define VRX_get_VDP_MAN_LINE_7_27(pval)                     ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x6A, 0xFF, 0, pval)
#define VRX_ret_VDP_MAN_LINE_7_27()                         ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x6A, 0xFF, 0)
#define VRX_set_VDP_MAN_LINE_7_27(val)                      ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x6A, 0xFF, 0, val)

#define VRX_get_VDP_MAN_LINE_8_28(pval)                     ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x6B, 0xFF, 0, pval)
#define VRX_ret_VDP_MAN_LINE_8_28()                         ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x6B, 0xFF, 0)
#define VRX_set_VDP_MAN_LINE_8_28(val)                      ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x6B, 0xFF, 0, val)

#define VRX_get_VDP_MAN_LINE_9_29(pval)                     ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x6C, 0xFF, 0, pval)
#define VRX_ret_VDP_MAN_LINE_9_29()                         ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x6C, 0xFF, 0)
#define VRX_set_VDP_MAN_LINE_9_29(val)                      ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x6C, 0xFF, 0, val)

#define VRX_get_VDP_MAN_LINE_10_30(pval)                    ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x6D, 0xFF, 0, pval)
#define VRX_ret_VDP_MAN_LINE_10_30()                        ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x6D, 0xFF, 0)
#define VRX_set_VDP_MAN_LINE_10_30(val)                     ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x6D, 0xFF, 0, val)

#define VRX_get_VDP_MAN_LINE_11_31(pval)                    ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x6E, 0xFF, 0, pval)
#define VRX_ret_VDP_MAN_LINE_11_31()                        ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x6E, 0xFF, 0)
#define VRX_set_VDP_MAN_LINE_11_31(val)                     ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x6E, 0xFF, 0, val)

#define VRX_get_VDP_MAN_LINE_12_32(pval)                    ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x6F, 0xFF, 0, pval)
#define VRX_ret_VDP_MAN_LINE_12_32()                        ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x6F, 0xFF, 0)
#define VRX_set_VDP_MAN_LINE_12_32(val)                     ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x6F, 0xFF, 0, val)

#define VRX_get_VDP_MAN_LINE_13_33(pval)                    ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x70, 0xFF, 0, pval)
#define VRX_ret_VDP_MAN_LINE_13_33()                        ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x70, 0xFF, 0)
#define VRX_set_VDP_MAN_LINE_13_33(val)                     ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x70, 0xFF, 0, val)

#define VRX_get_VDP_MAN_LINE_14_34(pval)                    ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x71, 0xFF, 0, pval)
#define VRX_ret_VDP_MAN_LINE_14_34()                        ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x71, 0xFF, 0)
#define VRX_set_VDP_MAN_LINE_14_34(val)                     ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x71, 0xFF, 0, val)

#define VRX_get_VDP_MAN_LINE_15_35(pval)                    ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x72, 0xFF, 0, pval)
#define VRX_ret_VDP_MAN_LINE_15_35()                        ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x72, 0xFF, 0)
#define VRX_set_VDP_MAN_LINE_15_35(val)                     ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x72, 0xFF, 0, val)

#define VRX_get_VDP_MAN_LINE_16_36(pval)                    ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x73, 0xFF, 0, pval)
#define VRX_ret_VDP_MAN_LINE_16_36()                        ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x73, 0xFF, 0)
#define VRX_set_VDP_MAN_LINE_16_36(val)                     ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x73, 0xFF, 0, val)

#define VRX_get_VDP_MAN_LINE_17_37(pval)                    ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x74, 0xFF, 0, pval)
#define VRX_ret_VDP_MAN_LINE_17_37()                        ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x74, 0xFF, 0)
#define VRX_set_VDP_MAN_LINE_17_37(val)                     ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x74, 0xFF, 0, val)

#define VRX_get_VDP_MAN_LINE_18_38(pval)                    ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x75, 0xFF, 0, pval)
#define VRX_ret_VDP_MAN_LINE_18_38()                        ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x75, 0xFF, 0)
#define VRX_set_VDP_MAN_LINE_18_38(val)                     ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x75, 0xFF, 0, val)

#define VRX_get_VDP_MAN_LINE_19_39(pval)                    ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x76, 0xFF, 0, pval)
#define VRX_ret_VDP_MAN_LINE_19_39()                        ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x76, 0xFF, 0)
#define VRX_set_VDP_MAN_LINE_19_39(val)                     ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x76, 0xFF, 0, val)

#define VRX_get_VDP_MAN_LINE_20_40(pval)                    ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x77, 0xFF, 0, pval)
#define VRX_ret_VDP_MAN_LINE_20_40()                        ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x77, 0xFF, 0)
#define VRX_set_VDP_MAN_LINE_20_40(val)                     ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x77, 0xFF, 0, val)

#define VRX_set_STATUS_CLEAR_TTXT(val)                      ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x78, 0x80, 0x7, val)

#define VRX_set_STATUS_CLEAR_VITC(val)                      ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x78, 0x40, 0x6, val)

#define VRX_set_STATUS_CLEAR_GEMS_VPS(val)                  ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x78, 0x10, 0x4, val)

#define VRX_set_VDP_STATUS_CLEAR_FAST_I2C(val)              ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x78, 0x8, 0x3, val)

#define VRX_set_STATUS_CLEAR_WSS_CGMS(val)                  ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x78, 0x4, 0x2, val)

#define VRX_set_STATUS_CLEAR_CCAP(val)                      ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x78, 0x1, 0x0, val)

#define VRX_is_LOW_DATA_STD_FILTER_EN_true()                ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0x98, 0x80, 0x7)
#define VRX_get_LOW_DATA_STD_FILTER_EN(pval)                ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x98, 0x80, 0x7, pval)
#define VRX_ret_LOW_DATA_STD_FILTER_EN()                    ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x98, 0x80, 0x7)
#define VRX_set_LOW_DATA_STD_FILTER_EN(val)                 ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x98, 0x80, 0x7, val)

#define VRX_is_ADAP1_SL_CONFIG_EN_true()                    ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0x98, 0x20, 0x5)
#define VRX_get_ADAP1_SL_CONFIG_EN(pval)                    ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x98, 0x20, 0x5, pval)
#define VRX_ret_ADAP1_SL_CONFIG_EN()                        ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x98, 0x20, 0x5)
#define VRX_set_ADAP1_SL_CONFIG_EN(val)                     ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x98, 0x20, 0x5, val)

#define VRX_is_TTX_SEL_true()                               ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0x98, 0x10, 0x4)
#define VRX_get_TTX_SEL(pval)                               ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x98, 0x10, 0x4, pval)
#define VRX_ret_TTX_SEL()                                   ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x98, 0x10, 0x4)
#define VRX_set_TTX_SEL(val)                                ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x98, 0x10, 0x4, val)

#define VRX_is_ADAP2_SL_CONFIG_EN_true()                    ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0x98, 0x8, 0x3)
#define VRX_get_ADAP2_SL_CONFIG_EN(pval)                    ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x98, 0x8, 0x3, pval)
#define VRX_ret_ADAP2_SL_CONFIG_EN()                        ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x98, 0x8, 0x3)
#define VRX_set_ADAP2_SL_CONFIG_EN(val)                     ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x98, 0x8, 0x3, val)

#define VRX_is_ADAP2_TTXT_STD_EN_true()                     ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0x99, 0x80, 0x7)
#define VRX_get_ADAP2_TTXT_STD_EN(pval)                     ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x99, 0x80, 0x7, pval)
#define VRX_ret_ADAP2_TTXT_STD_EN()                         ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x99, 0x80, 0x7)
#define VRX_set_ADAP2_TTXT_STD_EN(val)                      ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x99, 0x80, 0x7, val)

#define VRX_is_ADAP2_VITC_STD_EN_true()                     ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0x99, 0x40, 0x6)
#define VRX_get_ADAP2_VITC_STD_EN(pval)                     ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x99, 0x40, 0x6, pval)
#define VRX_ret_ADAP2_VITC_STD_EN()                         ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x99, 0x40, 0x6)
#define VRX_set_ADAP2_VITC_STD_EN(val)                      ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x99, 0x40, 0x6, val)

#define VRX_is_ADAP2_GEMS_STD_EN_true()                     ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0x99, 0x10, 0x4)
#define VRX_get_ADAP2_GEMS_STD_EN(pval)                     ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x99, 0x10, 0x4, pval)
#define VRX_ret_ADAP2_GEMS_STD_EN()                         ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x99, 0x10, 0x4)
#define VRX_set_ADAP2_GEMS_STD_EN(val)                      ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x99, 0x10, 0x4, val)

#define VRX_is_ADAP2_VPS_STD_EN_true()                      ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0x99, 0x8, 0x3)
#define VRX_get_ADAP2_VPS_STD_EN(pval)                      ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x99, 0x8, 0x3, pval)
#define VRX_ret_ADAP2_VPS_STD_EN()                          ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x99, 0x8, 0x3)
#define VRX_set_ADAP2_VPS_STD_EN(val)                       ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x99, 0x8, 0x3, val)

#define VRX_is_ADAP2_WSS_CGMS_STD_EN_true()                 ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0x99, 0x4, 0x2)
#define VRX_get_ADAP2_WSS_CGMS_STD_EN(pval)                 ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x99, 0x4, 0x2, pval)
#define VRX_ret_ADAP2_WSS_CGMS_STD_EN()                     ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x99, 0x4, 0x2)
#define VRX_set_ADAP2_WSS_CGMS_STD_EN(val)                  ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x99, 0x4, 0x2, val)

#define VRX_is_ADAP2_CCAP_STD_EN_true()                     ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0x99, 0x1, 0x0)
#define VRX_get_ADAP2_CCAP_STD_EN(pval)                     ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x99, 0x1, 0x0, pval)
#define VRX_ret_ADAP2_CCAP_STD_EN()                         ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x99, 0x1, 0x0)
#define VRX_set_ADAP2_CCAP_STD_EN(val)                      ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x99, 0x1, 0x0, val)

#define VRX_is_GS_VPS_PDC_UTC_CB_CHANGE_true()              ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0x9C, 0x20, 0x5)
#define VRX_get_GS_VPS_PDC_UTC_CB_CHANGE(pval)              ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x9C, 0x20, 0x5, pval)
#define VRX_ret_GS_VPS_PDC_UTC_CB_CHANGE()                  ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x9C, 0x20, 0x5)
#define VRX_set_GS_VPS_PDC_UTC_CB_CHANGE(val)               ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x9C, 0x20, 0x5, val)

#define VRX_is_WSS_CGMS_CB_CHANGE_true()                    ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0x9C, 0x10, 0x4)
#define VRX_get_WSS_CGMS_CB_CHANGE(pval)                    ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x9C, 0x10, 0x4, pval)
#define VRX_ret_WSS_CGMS_CB_CHANGE()                        ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x9C, 0x10, 0x4)
#define VRX_set_WSS_CGMS_CB_CHANGE(val)                     ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x9C, 0x10, 0x4, val)

#define VRX_is_RAW_STATUS_ENABLE_true()                     ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0x9C, 0x8, 0x3)
#define VRX_get_RAW_STATUS_ENABLE(pval)                     ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x9C, 0x8, 0x3, pval)
#define VRX_ret_RAW_STATUS_ENABLE()                         ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x9C, 0x8, 0x3)
#define VRX_set_RAW_STATUS_ENABLE(val)                      ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x9C, 0x8, 0x3, val)

#define VRX_get_GS_VPS_PDC_UTC_CGMSTB(pval)                 ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x9C, 0x7, 0, pval)
#define VRX_ret_GS_VPS_PDC_UTC_CGMSTB()                     ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x9C, 0x7, 0)
#define VRX_set_GS_VPS_PDC_UTC_CGMSTB(val)                  ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x9C, 0x7, 0, val)

#define VRX_is_SLICE_CORRECTOR_EN_true()                    ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0x9D, 0x2, 0x1)
#define VRX_get_SLICE_CORRECTOR_EN(pval)                    ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x9D, 0x2, 0x1, pval)
#define VRX_ret_SLICE_CORRECTOR_EN()                        ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x9D, 0x2, 0x1)
#define VRX_set_SLICE_CORRECTOR_EN(val)                     ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x9D, 0x2, 0x1, val)

#define VRX_is_ADAP2_VPS_CTB_FAST_LEARN_EN_true()           ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0x9E, 0x8, 0x3)
#define VRX_get_ADAP2_VPS_CTB_FAST_LEARN_EN(pval)           ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0x9E, 0x8, 0x3, pval)
#define VRX_ret_ADAP2_VPS_CTB_FAST_LEARN_EN()               ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0x9E, 0x8, 0x3)
#define VRX_set_ADAP2_VPS_CTB_FAST_LEARN_EN(val)            ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0x9E, 0x8, 0x3, val)

#define VRX_is_VDP_USE_PREDEF_FREQ_true()                   ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0xA5, 0x40, 0x6)
#define VRX_get_VDP_USE_PREDEF_FREQ(pval)                   ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xA5, 0x40, 0x6, pval)
#define VRX_ret_VDP_USE_PREDEF_FREQ()                       ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xA5, 0x40, 0x6)
#define VRX_set_VDP_USE_PREDEF_FREQ(val)                    ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0xA5, 0x40, 0x6, val)

#define VRX_is_VDP_CRI_TOLERANCE_true()                     ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0xA5, 0x20, 0x5)
#define VRX_get_VDP_CRI_TOLERANCE(pval)                     ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xA5, 0x20, 0x5, pval)
#define VRX_ret_VDP_CRI_TOLERANCE()                         ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xA5, 0x20, 0x5)
#define VRX_set_VDP_CRI_TOLERANCE(val)                      ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0xA5, 0x20, 0x5, val)

#define VRX_is_VDP_FRM_CODE_TOLERANCE_true()                ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0xA5, 0x10, 0x4)
#define VRX_get_VDP_FRM_CODE_TOLERANCE(pval)                ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xA5, 0x10, 0x4, pval)
#define VRX_ret_VDP_FRM_CODE_TOLERANCE()                    ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xA5, 0x10, 0x4)
#define VRX_set_VDP_FRM_CODE_TOLERANCE(val)                 ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0xA5, 0x10, 0x4, val)

#define VRX_is_VDP_CRI_8BIT_true()                          ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0xA5, 0x8, 0x3)
#define VRX_get_VDP_CRI_8BIT(pval)                          ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xA5, 0x8, 0x3, pval)
#define VRX_ret_VDP_CRI_8BIT()                              ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xA5, 0x8, 0x3)
#define VRX_set_VDP_CRI_8BIT(val)                           ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0xA5, 0x8, 0x3, val)

#define VRX_is_VDP_INVERT_EVEN_FIELD_true()                 ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0xA6, 0x10, 0x4)
#define VRX_get_VDP_INVERT_EVEN_FIELD(pval)                 ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xA6, 0x10, 0x4, pval)
#define VRX_ret_VDP_INVERT_EVEN_FIELD()                     ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xA6, 0x10, 0x4)
#define VRX_set_VDP_INVERT_EVEN_FIELD(val)                  ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0xA6, 0x10, 0x4, val)

#define VRX_is_VDP_MANUAL_TTXC_true()                       ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0xA8, 0x40, 0x6)
#define VRX_get_VDP_MANUAL_TTXC(pval)                       ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xA8, 0x40, 0x6, pval)
#define VRX_ret_VDP_MANUAL_TTXC()                           ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xA8, 0x40, 0x6)
#define VRX_set_VDP_MANUAL_TTXC(val)                        ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0xA8, 0x40, 0x6, val)

#define VRX_get_VDP_CRI_MAG_TRESH(pval)                     ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xAC, 0xFF, 0, pval)
#define VRX_ret_VDP_CRI_MAG_TRESH()                         ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xAC, 0xFF, 0)
#define VRX_set_VDP_CRI_MAG_TRESH(val)                      ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0xAC, 0xFF, 0, val)

#define VRX_is_VDP_FAST_REG_CONF_CUS2_true()                ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0xC0, 0x80, 0x7)
#define VRX_get_VDP_FAST_REG_CONF_CUS2(pval)                ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xC0, 0x80, 0x7, pval)
#define VRX_ret_VDP_FAST_REG_CONF_CUS2()                    ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xC0, 0x80, 0x7)
#define VRX_set_VDP_FAST_REG_CONF_CUS2(val)                 ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0xC0, 0x80, 0x7, val)

#define VRX_is_VDP_FAST_REG_CONF_CUST_true()                ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0xC0, 0x40, 0x6)
#define VRX_get_VDP_FAST_REG_CONF_CUST(pval)                ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xC0, 0x40, 0x6, pval)
#define VRX_ret_VDP_FAST_REG_CONF_CUST()                    ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xC0, 0x40, 0x6)
#define VRX_set_VDP_FAST_REG_CONF_CUST(val)                 ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0xC0, 0x40, 0x6, val)

#define VRX_is_VDP_FAST_REG_CONF_CCAP_true()                ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0xC0, 0x20, 0x5)
#define VRX_get_VDP_FAST_REG_CONF_CCAP(pval)                ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xC0, 0x20, 0x5, pval)
#define VRX_ret_VDP_FAST_REG_CONF_CCAP()                    ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xC0, 0x20, 0x5)
#define VRX_set_VDP_FAST_REG_CONF_CCAP(val)                 ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0xC0, 0x20, 0x5, val)

#define VRX_is_VDP_FAST_REG_CONF_GEM1X_2X_true()            ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0xC0, 0x10, 0x4)
#define VRX_get_VDP_FAST_REG_CONF_GEM1X_2X(pval)            ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xC0, 0x10, 0x4, pval)
#define VRX_ret_VDP_FAST_REG_CONF_GEM1X_2X()                ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xC0, 0x10, 0x4)
#define VRX_set_VDP_FAST_REG_CONF_GEM1X_2X(val)             ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0xC0, 0x10, 0x4, val)

#define VRX_is_VDP_FAST_REG_CONF_CGMS_WSS_true()            ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0xC0, 0x8, 0x3)
#define VRX_get_VDP_FAST_REG_CONF_CGMS_WSS(pval)            ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xC0, 0x8, 0x3, pval)
#define VRX_ret_VDP_FAST_REG_CONF_CGMS_WSS()                ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xC0, 0x8, 0x3)
#define VRX_set_VDP_FAST_REG_CONF_CGMS_WSS(val)             ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0xC0, 0x8, 0x3, val)

#define VRX_is_VDP_FAST_REG_CONF_VITC_true()                ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0xC0, 0x4, 0x2)
#define VRX_get_VDP_FAST_REG_CONF_VITC(pval)                ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xC0, 0x4, 0x2, pval)
#define VRX_ret_VDP_FAST_REG_CONF_VITC()                    ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xC0, 0x4, 0x2)
#define VRX_set_VDP_FAST_REG_CONF_VITC(val)                 ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0xC0, 0x4, 0x2, val)

#define VRX_is_VDP_FAST_REG_CONF_VPS_CGMSTB_true()          ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0xC0, 0x2, 0x1)
#define VRX_get_VDP_FAST_REG_CONF_VPS_CGMSTB(pval)          ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xC0, 0x2, 0x1, pval)
#define VRX_ret_VDP_FAST_REG_CONF_VPS_CGMSTB()              ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xC0, 0x2, 0x1)
#define VRX_set_VDP_FAST_REG_CONF_VPS_CGMSTB(val)           ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0xC0, 0x2, 0x1, val)

#define VRX_is_VDP_FAST_REG_CONF_TTXT_true()                ATV_I2CIsField8(VRX_VDP_MAP_ADDR, 0xC0, 0x1, 0x0)
#define VRX_get_VDP_FAST_REG_CONF_TTXT(pval)                ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xC0, 0x1, 0x0, pval)
#define VRX_ret_VDP_FAST_REG_CONF_TTXT()                    ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xC0, 0x1, 0x0)
#define VRX_set_VDP_FAST_REG_CONF_TTXT(val)                 ATV_I2CWriteField8(VRX_VDP_MAP_ADDR, 0xC0, 0x1, 0x0, val)

#define VRX_get_VDP_FAST_VBI_STD(pval)                      ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xC2, 0xF, 0, pval)
#define VRX_ret_VDP_FAST_VBI_STD()                          ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xC2, 0xF, 0)

#define VRX_get_VDP_FAST_PACKET_SIZE(pval)                  ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xC3, 0xFF, 0, pval)
#define VRX_ret_VDP_FAST_PACKET_SIZE()                      ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xC3, 0xFF, 0)

#define VRX_get_VDP_FAST_REG00(pval)                        ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xC4, 0xFF, 0, pval)
#define VRX_ret_VDP_FAST_REG00()                            ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xC4, 0xFF, 0)

#define VRX_get_VDP_FAST_REG01(pval)                        ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xC5, 0xFF, 0, pval)
#define VRX_ret_VDP_FAST_REG01()                            ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xC5, 0xFF, 0)

#define VRX_get_VDP_FAST_REG02(pval)                        ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xC6, 0xFF, 0, pval)
#define VRX_ret_VDP_FAST_REG02()                            ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xC6, 0xFF, 0)

#define VRX_get_VDP_FAST_REG03(pval)                        ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xC7, 0xFF, 0, pval)
#define VRX_ret_VDP_FAST_REG03()                            ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xC7, 0xFF, 0)

#define VRX_get_VDP_FAST_REG04(pval)                        ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xC8, 0xFF, 0, pval)
#define VRX_ret_VDP_FAST_REG04()                            ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xC8, 0xFF, 0)

#define VRX_get_VDP_FAST_REG05(pval)                        ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xC9, 0xFF, 0, pval)
#define VRX_ret_VDP_FAST_REG05()                            ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xC9, 0xFF, 0)

#define VRX_get_VDP_FAST_REG06(pval)                        ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xCA, 0xFF, 0, pval)
#define VRX_ret_VDP_FAST_REG06()                            ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xCA, 0xFF, 0)

#define VRX_get_VDP_FAST_REG07(pval)                        ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xCB, 0xFF, 0, pval)
#define VRX_ret_VDP_FAST_REG07()                            ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xCB, 0xFF, 0)

#define VRX_get_VDP_FAST_REG08(pval)                        ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xCC, 0xFF, 0, pval)
#define VRX_ret_VDP_FAST_REG08()                            ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xCC, 0xFF, 0)

#define VRX_get_VDP_FAST_REG09(pval)                        ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xCD, 0xFF, 0, pval)
#define VRX_ret_VDP_FAST_REG09()                            ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xCD, 0xFF, 0)

#define VRX_get_VDP_FAST_REG10(pval)                        ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xCE, 0xFF, 0, pval)
#define VRX_ret_VDP_FAST_REG10()                            ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xCE, 0xFF, 0)

#define VRX_get_VDP_FAST_REG11(pval)                        ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xCF, 0xFF, 0, pval)
#define VRX_ret_VDP_FAST_REG11()                            ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xCF, 0xFF, 0)

#define VRX_get_VDP_FAST_REG12(pval)                        ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xD0, 0xFF, 0, pval)
#define VRX_ret_VDP_FAST_REG12()                            ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xD0, 0xFF, 0)

#define VRX_get_VDP_FAST_REG13(pval)                        ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xD1, 0xFF, 0, pval)
#define VRX_ret_VDP_FAST_REG13()                            ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xD1, 0xFF, 0)

#define VRX_get_VDP_FAST_REG14(pval)                        ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xD2, 0xFF, 0, pval)
#define VRX_ret_VDP_FAST_REG14()                            ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xD2, 0xFF, 0)

#define VRX_get_VDP_FAST_REG15(pval)                        ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xD3, 0xFF, 0, pval)
#define VRX_ret_VDP_FAST_REG15()                            ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xD3, 0xFF, 0)

#define VRX_get_VDP_FAST_REG16(pval)                        ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xD4, 0xFF, 0, pval)
#define VRX_ret_VDP_FAST_REG16()                            ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xD4, 0xFF, 0)

#define VRX_get_VDP_FAST_REG17(pval)                        ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xD5, 0xFF, 0, pval)
#define VRX_ret_VDP_FAST_REG17()                            ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xD5, 0xFF, 0)

#define VRX_get_VDP_FAST_REG18(pval)                        ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xD6, 0xFF, 0, pval)
#define VRX_ret_VDP_FAST_REG18()                            ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xD6, 0xFF, 0)

#define VRX_get_VDP_FAST_REG19(pval)                        ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xD7, 0xFF, 0, pval)
#define VRX_ret_VDP_FAST_REG19()                            ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xD7, 0xFF, 0)

#define VRX_get_VDP_FAST_REG20(pval)                        ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xD8, 0xFF, 0, pval)
#define VRX_ret_VDP_FAST_REG20()                            ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xD8, 0xFF, 0)

#define VRX_get_VDP_FAST_REG21(pval)                        ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xD9, 0xFF, 0, pval)
#define VRX_ret_VDP_FAST_REG21()                            ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xD9, 0xFF, 0)

#define VRX_get_VDP_FAST_REG22(pval)                        ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xDA, 0xFF, 0, pval)
#define VRX_ret_VDP_FAST_REG22()                            ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xDA, 0xFF, 0)

#define VRX_get_VDP_FAST_REG23(pval)                        ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xDB, 0xFF, 0, pval)
#define VRX_ret_VDP_FAST_REG23()                            ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xDB, 0xFF, 0)

#define VRX_get_VDP_FAST_REG24(pval)                        ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xDC, 0xFF, 0, pval)
#define VRX_ret_VDP_FAST_REG24()                            ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xDC, 0xFF, 0)

#define VRX_get_VDP_FAST_REG25(pval)                        ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xDD, 0xFF, 0, pval)
#define VRX_ret_VDP_FAST_REG25()                            ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xDD, 0xFF, 0)

#define VRX_get_VDP_FAST_REG26(pval)                        ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xDE, 0xFF, 0, pval)
#define VRX_ret_VDP_FAST_REG26()                            ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xDE, 0xFF, 0)

#define VRX_get_VDP_FAST_REG27(pval)                        ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xDF, 0xFF, 0, pval)
#define VRX_ret_VDP_FAST_REG27()                            ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xDF, 0xFF, 0)

#define VRX_get_VDP_FAST_REG28(pval)                        ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xE0, 0xFF, 0, pval)
#define VRX_ret_VDP_FAST_REG28()                            ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xE0, 0xFF, 0)

#define VRX_get_VDP_FAST_REG29(pval)                        ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xE1, 0xFF, 0, pval)
#define VRX_ret_VDP_FAST_REG29()                            ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xE1, 0xFF, 0)

#define VRX_get_VDP_FAST_REG30(pval)                        ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xE2, 0xFF, 0, pval)
#define VRX_ret_VDP_FAST_REG30()                            ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xE2, 0xFF, 0)

#define VRX_get_VDP_FAST_REG31(pval)                        ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xE3, 0xFF, 0, pval)
#define VRX_ret_VDP_FAST_REG31()                            ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xE3, 0xFF, 0)

#define VRX_get_VDP_FAST_REG32(pval)                        ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xE4, 0xFF, 0, pval)
#define VRX_ret_VDP_FAST_REG32()                            ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xE4, 0xFF, 0)

#define VRX_get_VDP_FAST_REG33(pval)                        ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xE5, 0xFF, 0, pval)
#define VRX_ret_VDP_FAST_REG33()                            ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xE5, 0xFF, 0)

#define VRX_get_VDP_FAST_REG34(pval)                        ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xE6, 0xFF, 0, pval)
#define VRX_ret_VDP_FAST_REG34()                            ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xE6, 0xFF, 0)

#define VRX_get_VDP_FAST_REG35(pval)                        ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xE7, 0xFF, 0, pval)
#define VRX_ret_VDP_FAST_REG35()                            ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xE7, 0xFF, 0)

#define VRX_get_VDP_FAST_REG36(pval)                        ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xE8, 0xFF, 0, pval)
#define VRX_ret_VDP_FAST_REG36()                            ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xE8, 0xFF, 0)

#define VRX_get_VDP_FAST_REG37(pval)                        ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xE9, 0xFF, 0, pval)
#define VRX_ret_VDP_FAST_REG37()                            ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xE9, 0xFF, 0)

#define VRX_get_VDP_FAST_REG38(pval)                        ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xEA, 0xFF, 0, pval)
#define VRX_ret_VDP_FAST_REG38()                            ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xEA, 0xFF, 0)

#define VRX_get_VDP_FAST_REG39(pval)                        ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xEB, 0xFF, 0, pval)
#define VRX_ret_VDP_FAST_REG39()                            ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xEB, 0xFF, 0)

#define VRX_get_VDP_FAST_REG40(pval)                        ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xEC, 0xFF, 0, pval)
#define VRX_ret_VDP_FAST_REG40()                            ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xEC, 0xFF, 0)

#define VRX_get_VDP_FAST_REG41(pval)                        ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xED, 0xFF, 0, pval)
#define VRX_ret_VDP_FAST_REG41()                            ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xED, 0xFF, 0)

#define VRX_get_VDP_FAST_REG42(pval)                        ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xEE, 0xFF, 0, pval)
#define VRX_ret_VDP_FAST_REG42()                            ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xEE, 0xFF, 0)

#define VRX_get_VDP_FAST_REG43(pval)                        ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xEF, 0xFF, 0, pval)
#define VRX_ret_VDP_FAST_REG43()                            ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xEF, 0xFF, 0)

#define VRX_get_VDP_FAST_REG44(pval)                        ATV_I2CGetField8(VRX_VDP_MAP_ADDR, 0xF0, 0xFF, 0, pval)
#define VRX_ret_VDP_FAST_REG44()                            ATV_I2CReadField8(VRX_VDP_MAP_ADDR, 0xF0, 0xFF, 0)

#endif
