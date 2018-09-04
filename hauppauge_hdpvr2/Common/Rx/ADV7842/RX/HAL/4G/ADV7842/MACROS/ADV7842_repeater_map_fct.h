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


#ifndef ADV7842_REPEATER_MAP_FCT_H
#define ADV7842_REPEATER_MAP_FCT_H

#include "ADV7842_cfg.h"

#define VRX_get_BKSV(pval)                                  ATV_I2CGetMultiField(VRX_REPEATER_MAP_ADDR, 0x00, 5, pval)

#define VRX_get_RI(pval)                                    ATV_I2CGetField32LE(VRX_REPEATER_MAP_ADDR, 0x08, 0xFF, 0xFF, 0, 2, pval)
#define VRX_ret_RI()                                        ATV_I2CReadField32LE(VRX_REPEATER_MAP_ADDR, 0x08, 0xFF, 0xFF, 0, 2)

#define VRX_get_PJ(pval)                                    ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x0A, 0xFF, 0, pval)
#define VRX_ret_PJ()                                        ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x0A, 0xFF, 0)

#define VRX_get_AKSV(pval)                                  ATV_I2CGetMultiField(VRX_REPEATER_MAP_ADDR, 0x10, 5, pval)
#define VRX_set_AKSV(pval)                                  ATV_I2CSetMultiField(VRX_REPEATER_MAP_ADDR, 0x10, 5, pval)

#define VRX_get_AINFO(pval)                                 ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x15, 0xFF, 0, pval)
#define VRX_ret_AINFO()                                     ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x15, 0xFF, 0)
#define VRX_set_AINFO(val)                                  ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x15, 0xFF, 0, val)

#define VRX_get_AN(pval)                                    ATV_I2CGetMultiField(VRX_REPEATER_MAP_ADDR, 0x18, 8, pval)
#define VRX_set_AN(pval)                                    ATV_I2CSetMultiField(VRX_REPEATER_MAP_ADDR, 0x18, 8, pval)

#define VRX_get_SHA_A(pval)                                 ATV_I2CGetField32LE(VRX_REPEATER_MAP_ADDR, 0x20, 0xFF, 0xFF, 0, 4, pval)
#define VRX_ret_SHA_A()                                     ATV_I2CReadField32LE(VRX_REPEATER_MAP_ADDR, 0x20, 0xFF, 0xFF, 0, 4)
#define VRX_set_SHA_A(val)                                  ATV_I2CWriteField32LE(VRX_REPEATER_MAP_ADDR, 0x20, 0xFF, 0xFF, 0, 4, val)

#define VRX_get_SHA_B(pval)                                 ATV_I2CGetField32LE(VRX_REPEATER_MAP_ADDR, 0x24, 0xFF, 0xFF, 0, 4, pval)
#define VRX_ret_SHA_B()                                     ATV_I2CReadField32LE(VRX_REPEATER_MAP_ADDR, 0x24, 0xFF, 0xFF, 0, 4)
#define VRX_set_SHA_B(val)                                  ATV_I2CWriteField32LE(VRX_REPEATER_MAP_ADDR, 0x24, 0xFF, 0xFF, 0, 4, val)

#define VRX_get_SHA_C(pval)                                 ATV_I2CGetField32LE(VRX_REPEATER_MAP_ADDR, 0x28, 0xFF, 0xFF, 0, 4, pval)
#define VRX_ret_SHA_C()                                     ATV_I2CReadField32LE(VRX_REPEATER_MAP_ADDR, 0x28, 0xFF, 0xFF, 0, 4)
#define VRX_set_SHA_C(val)                                  ATV_I2CWriteField32LE(VRX_REPEATER_MAP_ADDR, 0x28, 0xFF, 0xFF, 0, 4, val)

#define VRX_get_SHA_D(pval)                                 ATV_I2CGetField32LE(VRX_REPEATER_MAP_ADDR, 0x2C, 0xFF, 0xFF, 0, 4, pval)
#define VRX_ret_SHA_D()                                     ATV_I2CReadField32LE(VRX_REPEATER_MAP_ADDR, 0x2C, 0xFF, 0xFF, 0, 4)
#define VRX_set_SHA_D(val)                                  ATV_I2CWriteField32LE(VRX_REPEATER_MAP_ADDR, 0x2C, 0xFF, 0xFF, 0, 4, val)

#define VRX_get_SHA_E(pval)                                 ATV_I2CGetField32LE(VRX_REPEATER_MAP_ADDR, 0x30, 0xFF, 0xFF, 0, 4, pval)
#define VRX_ret_SHA_E()                                     ATV_I2CReadField32LE(VRX_REPEATER_MAP_ADDR, 0x30, 0xFF, 0xFF, 0, 4)
#define VRX_set_SHA_E(val)                                  ATV_I2CWriteField32LE(VRX_REPEATER_MAP_ADDR, 0x30, 0xFF, 0xFF, 0, 4, val)

#define VRX_get_BCAPS(pval)                                 ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x40, 0xFF, 0, pval)
#define VRX_ret_BCAPS()                                     ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x40, 0xFF, 0)
#define VRX_set_BCAPS(val)                                  ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x40, 0xFF, 0, val)

#define VRX_get_BSTATUS(pval)                               ATV_I2CGetField32LE(VRX_REPEATER_MAP_ADDR, 0x41, 0xFF, 0xFF, 0, 2, pval)
#define VRX_ret_BSTATUS()                                   ATV_I2CReadField32LE(VRX_REPEATER_MAP_ADDR, 0x41, 0xFF, 0xFF, 0, 2)
#define VRX_set_BSTATUS(val)                                ATV_I2CWriteField32LE(VRX_REPEATER_MAP_ADDR, 0x41, 0xFF, 0xFF, 0, 2, val)

#define VRX_get_SPA_PORT_A(pval)                            ATV_I2CGetField32(VRX_REPEATER_MAP_ADDR, 0x72, 0xFF, 0xFF, 0, 2, pval)
#define VRX_ret_SPA_PORT_A()                                ATV_I2CReadField32(VRX_REPEATER_MAP_ADDR, 0x72, 0xFF, 0xFF, 0, 2)
#define VRX_set_SPA_PORT_A(val)                             ATV_I2CWriteField32(VRX_REPEATER_MAP_ADDR, 0x72, 0xFF, 0xFF, 0, 2, val)

#define VRX_get_SPA_PORT_B(pval)                            ATV_I2CGetField32(VRX_REPEATER_MAP_ADDR, 0x74, 0xFF, 0xFF, 0, 2, pval)
#define VRX_ret_SPA_PORT_B()                                ATV_I2CReadField32(VRX_REPEATER_MAP_ADDR, 0x74, 0xFF, 0xFF, 0, 2)
#define VRX_set_SPA_PORT_B(val)                             ATV_I2CWriteField32(VRX_REPEATER_MAP_ADDR, 0x74, 0xFF, 0xFF, 0, 2, val)

#define VRX_get_SPA_LOCATION(pval)                          ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x76, 0xFF, 0, pval)
#define VRX_ret_SPA_LOCATION()                              ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x76, 0xFF, 0)
#define VRX_set_SPA_LOCATION(val)                           ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x76, 0xFF, 0, val)

#define VRX_is_KSV_LIST_READY_true()                        ATV_I2CIsField8(VRX_REPEATER_MAP_ADDR, 0x77, 0x80, 0x7)
#define VRX_get_KSV_LIST_READY(pval)                        ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x77, 0x80, 0x7, pval)
#define VRX_ret_KSV_LIST_READY()                            ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x77, 0x80, 0x7)
#define VRX_set_KSV_LIST_READY(val)                         ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x77, 0x80, 0x7, val)

#define VRX_is_SPA_LOCATION_MSB_true()                      ATV_I2CIsField8(VRX_REPEATER_MAP_ADDR, 0x77, 0x40, 0x6)
#define VRX_get_SPA_LOCATION_MSB(pval)                      ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x77, 0x40, 0x6, pval)
#define VRX_ret_SPA_LOCATION_MSB()                          ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x77, 0x40, 0x6)
#define VRX_set_SPA_LOCATION_MSB(val)                       ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x77, 0x40, 0x6, val)

#define VRX_is_DISABLE_AUTO_EDID_true()                     ATV_I2CIsField8(VRX_REPEATER_MAP_ADDR, 0x77, 0x20, 0x5)
#define VRX_get_DISABLE_AUTO_EDID(pval)                     ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x77, 0x20, 0x5, pval)
#define VRX_ret_DISABLE_AUTO_EDID()                         ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x77, 0x20, 0x5)
#define VRX_set_DISABLE_AUTO_EDID(val)                      ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x77, 0x20, 0x5, val)

#define VRX_is_EDID_SEGMENT_POINTER_true()                  ATV_I2CIsField8(VRX_REPEATER_MAP_ADDR, 0x77, 0x10, 0x4)
#define VRX_get_EDID_SEGMENT_POINTER(pval)                  ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x77, 0x10, 0x4, pval)
#define VRX_ret_EDID_SEGMENT_POINTER()                      ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x77, 0x10, 0x4)
#define VRX_set_EDID_SEGMENT_POINTER(val)                   ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x77, 0x10, 0x4, val)

#define VRX_is_EDID_B_ENABLE_true()                         ATV_I2CIsField8(VRX_REPEATER_MAP_ADDR, 0x77, 0x8, 0x3)
#define VRX_get_EDID_B_ENABLE(pval)                         ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x77, 0x8, 0x3, pval)
#define VRX_ret_EDID_B_ENABLE()                             ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x77, 0x8, 0x3)
#define VRX_set_EDID_B_ENABLE(val)                          ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x77, 0x8, 0x3, val)

#define VRX_is_EDID_A_ENABLE_true()                         ATV_I2CIsField8(VRX_REPEATER_MAP_ADDR, 0x77, 0x4, 0x2)
#define VRX_get_EDID_A_ENABLE(pval)                         ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x77, 0x4, 0x2, pval)
#define VRX_ret_EDID_A_ENABLE()                             ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x77, 0x4, 0x2)
#define VRX_set_EDID_A_ENABLE(val)                          ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x77, 0x4, 0x2, val)

#define VRX_is_EXT_EEPROM_TRI_true()                        ATV_I2CIsField8(VRX_REPEATER_MAP_ADDR, 0x78, 0x40, 0x6)
#define VRX_get_EXT_EEPROM_TRI(pval)                        ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x78, 0x40, 0x6, pval)
#define VRX_ret_EXT_EEPROM_TRI()                            ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x78, 0x40, 0x6)
#define VRX_set_EXT_EEPROM_TRI(val)                         ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x78, 0x40, 0x6, val)

#define VRX_is_VGA_EDID_ENABLE_CPU_true()                   ATV_I2CIsField8(VRX_REPEATER_MAP_ADDR, 0x79, 0x20, 0x5)
#define VRX_get_VGA_EDID_ENABLE_CPU(pval)                   ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x79, 0x20, 0x5, pval)
#define VRX_ret_VGA_EDID_ENABLE_CPU()                       ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x79, 0x20, 0x5)

#define VRX_get_PORT_A_CHECKSUM(pval)                       ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x7B, 0xFF, 0, pval)
#define VRX_ret_PORT_A_CHECKSUM()                           ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x7B, 0xFF, 0)
#define VRX_set_PORT_A_CHECKSUM(val)                        ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x7B, 0xFF, 0, val)

#define VRX_get_PORT_B_CHECKSUM(pval)                       ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x7C, 0xFF, 0, pval)
#define VRX_ret_PORT_B_CHECKSUM()                           ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x7C, 0xFF, 0)
#define VRX_set_PORT_B_CHECKSUM(val)                        ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x7C, 0xFF, 0, val)

#define VRX_is_EDID_B_ENABLE_CPU_true()                     ATV_I2CIsField8(VRX_REPEATER_MAP_ADDR, 0x7D, 0x8, 0x3)
#define VRX_get_EDID_B_ENABLE_CPU(pval)                     ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x7D, 0x8, 0x3, pval)
#define VRX_ret_EDID_B_ENABLE_CPU()                         ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x7D, 0x8, 0x3)

#define VRX_is_EDID_A_ENABLE_CPU_true()                     ATV_I2CIsField8(VRX_REPEATER_MAP_ADDR, 0x7D, 0x4, 0x2)
#define VRX_get_EDID_A_ENABLE_CPU(pval)                     ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x7D, 0x4, 0x2, pval)
#define VRX_ret_EDID_A_ENABLE_CPU()                         ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x7D, 0x4, 0x2)

#define VRX_set_KSV_LIST_READY_CLEAR_A(val)                 ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x7E, 0x20, 0x5, val)

#define VRX_set_KSV_LIST_READY_CLEAR_B(val)                 ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x7E, 0x10, 0x4, val)

#define VRX_set_LOAD_EDID(val)                              ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x7E, 0x2, 0x1, val)

#define VRX_set_STORE_EDID(val)                             ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x7E, 0x1, 0x0, val)

#define VRX_is_VGA_EDID_ENABLE_true()                       ATV_I2CIsField8(VRX_REPEATER_MAP_ADDR, 0x7F, 0x80, 0x7)
#define VRX_get_VGA_EDID_ENABLE(pval)                       ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x7F, 0x80, 0x7, pval)
#define VRX_ret_VGA_EDID_ENABLE()                           ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x7F, 0x80, 0x7)
#define VRX_set_VGA_EDID_ENABLE(val)                        ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x7F, 0x80, 0x7, val)

#define VRX_is_AUTO_HDCP_MAP_ENABLE_true()                  ATV_I2CIsField8(VRX_REPEATER_MAP_ADDR, 0x7F, 0x4, 0x2)
#define VRX_get_AUTO_HDCP_MAP_ENABLE(pval)                  ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x7F, 0x4, 0x2, pval)
#define VRX_ret_AUTO_HDCP_MAP_ENABLE()                      ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x7F, 0x4, 0x2)
#define VRX_set_AUTO_HDCP_MAP_ENABLE(val)                   ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x7F, 0x4, 0x2, val)

#define VRX_get_HDCP_MAP_SELECT(pval)                       ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x7F, 0x3, 0, pval)
#define VRX_ret_HDCP_MAP_SELECT()                           ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x7F, 0x3, 0)
#define VRX_set_HDCP_MAP_SELECT(val)                        ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x7F, 0x3, 0, val)

#define VRX_get_KSV_0(pval)                                 ATV_I2CGetMultiField(VRX_REPEATER_MAP_ADDR, 0x80, 5, pval)
#define VRX_set_KSV_0(pval)                                 ATV_I2CSetMultiField(VRX_REPEATER_MAP_ADDR, 0x80, 5, pval)

#define VRX_get_KSV_1(pval)                                 ATV_I2CGetMultiField(VRX_REPEATER_MAP_ADDR, 0x85, 5, pval)
#define VRX_set_KSV_1(pval)                                 ATV_I2CSetMultiField(VRX_REPEATER_MAP_ADDR, 0x85, 5, pval)

#define VRX_get_KSV_2(pval)                                 ATV_I2CGetMultiField(VRX_REPEATER_MAP_ADDR, 0x8A, 5, pval)
#define VRX_set_KSV_2(pval)                                 ATV_I2CSetMultiField(VRX_REPEATER_MAP_ADDR, 0x8A, 5, pval)

#define VRX_get_KSV_3(pval)                                 ATV_I2CGetMultiField(VRX_REPEATER_MAP_ADDR, 0x8F, 5, pval)
#define VRX_set_KSV_3(pval)                                 ATV_I2CSetMultiField(VRX_REPEATER_MAP_ADDR, 0x8F, 5, pval)

#define VRX_get_KSV_4(pval)                                 ATV_I2CGetMultiField(VRX_REPEATER_MAP_ADDR, 0x94, 5, pval)
#define VRX_set_KSV_4(pval)                                 ATV_I2CSetMultiField(VRX_REPEATER_MAP_ADDR, 0x94, 5, pval)

#define VRX_get_KSV_5(pval)                                 ATV_I2CGetMultiField(VRX_REPEATER_MAP_ADDR, 0x99, 5, pval)
#define VRX_set_KSV_5(pval)                                 ATV_I2CSetMultiField(VRX_REPEATER_MAP_ADDR, 0x99, 5, pval)

#define VRX_get_KSV_6(pval)                                 ATV_I2CGetMultiField(VRX_REPEATER_MAP_ADDR, 0x9E, 5, pval)
#define VRX_set_KSV_6(pval)                                 ATV_I2CSetMultiField(VRX_REPEATER_MAP_ADDR, 0x9E, 5, pval)

#define VRX_get_KSV_7(pval)                                 ATV_I2CGetMultiField(VRX_REPEATER_MAP_ADDR, 0xA3, 5, pval)
#define VRX_set_KSV_7(pval)                                 ATV_I2CSetMultiField(VRX_REPEATER_MAP_ADDR, 0xA3, 5, pval)

#define VRX_get_KSV_8(pval)                                 ATV_I2CGetMultiField(VRX_REPEATER_MAP_ADDR, 0xA8, 5, pval)
#define VRX_set_KSV_8(pval)                                 ATV_I2CSetMultiField(VRX_REPEATER_MAP_ADDR, 0xA8, 5, pval)

#define VRX_get_KSV_9(pval)                                 ATV_I2CGetMultiField(VRX_REPEATER_MAP_ADDR, 0xAD, 5, pval)
#define VRX_set_KSV_9(pval)                                 ATV_I2CSetMultiField(VRX_REPEATER_MAP_ADDR, 0xAD, 5, pval)

#define VRX_get_KSV_10(pval)                                ATV_I2CGetMultiField(VRX_REPEATER_MAP_ADDR, 0xB2, 5, pval)
#define VRX_set_KSV_10(pval)                                ATV_I2CSetMultiField(VRX_REPEATER_MAP_ADDR, 0xB2, 5, pval)

#define VRX_get_KSV_11(pval)                                ATV_I2CGetMultiField(VRX_REPEATER_MAP_ADDR, 0xB7, 5, pval)
#define VRX_set_KSV_11(pval)                                ATV_I2CSetMultiField(VRX_REPEATER_MAP_ADDR, 0xB7, 5, pval)

#define VRX_get_KSV_12(pval)                                ATV_I2CGetMultiField(VRX_REPEATER_MAP_ADDR, 0xBC, 5, pval)
#define VRX_set_KSV_12(pval)                                ATV_I2CSetMultiField(VRX_REPEATER_MAP_ADDR, 0xBC, 5, pval)

#define VRX_get_KSV_13(pval)                                ATV_I2CGetMultiField(VRX_REPEATER_MAP_ADDR, 0xC1, 5, pval)
#define VRX_set_KSV_13(pval)                                ATV_I2CSetMultiField(VRX_REPEATER_MAP_ADDR, 0xC1, 5, pval)

#define VRX_get_KSV_14(pval)                                ATV_I2CGetMultiField(VRX_REPEATER_MAP_ADDR, 0xC6, 5, pval)
#define VRX_set_KSV_14(pval)                                ATV_I2CSetMultiField(VRX_REPEATER_MAP_ADDR, 0xC6, 5, pval)

#define VRX_get_KSV_15(pval)                                ATV_I2CGetMultiField(VRX_REPEATER_MAP_ADDR, 0xCB, 5, pval)
#define VRX_set_KSV_15(pval)                                ATV_I2CSetMultiField(VRX_REPEATER_MAP_ADDR, 0xCB, 5, pval)

#define VRX_get_KSV_16(pval)                                ATV_I2CGetMultiField(VRX_REPEATER_MAP_ADDR, 0xD0, 5, pval)
#define VRX_set_KSV_16(pval)                                ATV_I2CSetMultiField(VRX_REPEATER_MAP_ADDR, 0xD0, 5, pval)

#define VRX_get_KSV_17(pval)                                ATV_I2CGetMultiField(VRX_REPEATER_MAP_ADDR, 0xD5, 5, pval)
#define VRX_set_KSV_17(pval)                                ATV_I2CSetMultiField(VRX_REPEATER_MAP_ADDR, 0xD5, 5, pval)

#define VRX_get_KSV_18(pval)                                ATV_I2CGetMultiField(VRX_REPEATER_MAP_ADDR, 0xDA, 5, pval)
#define VRX_set_KSV_18(pval)                                ATV_I2CSetMultiField(VRX_REPEATER_MAP_ADDR, 0xDA, 5, pval)

#define VRX_get_KSV_19(pval)                                ATV_I2CGetMultiField(VRX_REPEATER_MAP_ADDR, 0xDF, 5, pval)
#define VRX_set_KSV_19(pval)                                ATV_I2CSetMultiField(VRX_REPEATER_MAP_ADDR, 0xDF, 5, pval)

#define VRX_get_KSV_20(pval)                                ATV_I2CGetMultiField(VRX_REPEATER_MAP_ADDR, 0xE4, 5, pval)
#define VRX_set_KSV_20(pval)                                ATV_I2CSetMultiField(VRX_REPEATER_MAP_ADDR, 0xE4, 5, pval)

#define VRX_get_KSV_21(pval)                                ATV_I2CGetMultiField(VRX_REPEATER_MAP_ADDR, 0xE9, 5, pval)
#define VRX_set_KSV_21(pval)                                ATV_I2CSetMultiField(VRX_REPEATER_MAP_ADDR, 0xE9, 5, pval)

#define VRX_get_KSV_22(pval)                                ATV_I2CGetMultiField(VRX_REPEATER_MAP_ADDR, 0xEE, 5, pval)
#define VRX_set_KSV_22(pval)                                ATV_I2CSetMultiField(VRX_REPEATER_MAP_ADDR, 0xEE, 5, pval)

#define VRX_get_KSV_23(pval)                                ATV_I2CGetMultiField(VRX_REPEATER_MAP_ADDR, 0xF3, 5, pval)
#define VRX_set_KSV_23(pval)                                ATV_I2CSetMultiField(VRX_REPEATER_MAP_ADDR, 0xF3, 5, pval)

#endif
