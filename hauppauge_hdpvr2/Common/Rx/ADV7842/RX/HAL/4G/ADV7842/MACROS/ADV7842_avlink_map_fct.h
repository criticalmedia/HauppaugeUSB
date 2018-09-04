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
* DATE: 18 Nov 2009 15:43:10                                                   *
*                                                                              *
*******************************************************************************/


#ifndef ADV7842_AVLINK_MAP_FCT_H
#define ADV7842_AVLINK_MAP_FCT_H

#include "ADV7842_cfg.h"

#define VRX_get_AVL_TX_FRAME_MODE(pval)                     ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x00, 0x3, 0, pval)
#define VRX_ret_AVL_TX_FRAME_MODE()                         ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x00, 0x3, 0)
#define VRX_set_AVL_TX_FRAME_MODE(val)                      ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x00, 0x3, 0, val)

#define VRX_get_AVL_TX_FRAME_HEADER(pval)                   ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x01, 0xFF, 0, pval)
#define VRX_ret_AVL_TX_FRAME_HEADER()                       ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x01, 0xFF, 0)
#define VRX_set_AVL_TX_FRAME_HEADER(val)                    ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x01, 0xFF, 0, val)

#define VRX_get_AVL_TX_FRAME_DATA0(pval)                    ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x02, 0xFF, 0, pval)
#define VRX_ret_AVL_TX_FRAME_DATA0()                        ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x02, 0xFF, 0)
#define VRX_set_AVL_TX_FRAME_DATA0(val)                     ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x02, 0xFF, 0, val)

#define VRX_get_AVL_TX_FRAME_DATA1(pval)                    ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x03, 0xFF, 0, pval)
#define VRX_ret_AVL_TX_FRAME_DATA1()                        ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x03, 0xFF, 0)
#define VRX_set_AVL_TX_FRAME_DATA1(val)                     ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x03, 0xFF, 0, val)

#define VRX_get_AVL_TX_FRAME_DATA2(pval)                    ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x04, 0xFF, 0, pval)
#define VRX_ret_AVL_TX_FRAME_DATA2()                        ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x04, 0xFF, 0)
#define VRX_set_AVL_TX_FRAME_DATA2(val)                     ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x04, 0xFF, 0, val)

#define VRX_get_AVL_TX_FRAME_DATA3(pval)                    ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x05, 0xFF, 0, pval)
#define VRX_ret_AVL_TX_FRAME_DATA3()                        ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x05, 0xFF, 0)
#define VRX_set_AVL_TX_FRAME_DATA3(val)                     ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x05, 0xFF, 0, val)

#define VRX_get_AVL_TX_FRAME_DATA4(pval)                    ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x06, 0xFF, 0, pval)
#define VRX_ret_AVL_TX_FRAME_DATA4()                        ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x06, 0xFF, 0)
#define VRX_set_AVL_TX_FRAME_DATA4(val)                     ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x06, 0xFF, 0, val)

#define VRX_get_AVL_TX_FRAME_DATA5(pval)                    ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x07, 0xFF, 0, pval)
#define VRX_ret_AVL_TX_FRAME_DATA5()                        ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x07, 0xFF, 0)
#define VRX_set_AVL_TX_FRAME_DATA5(val)                     ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x07, 0xFF, 0, val)

#define VRX_get_AVL_TX_FRAME_DATA6(pval)                    ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x08, 0xFF, 0, pval)
#define VRX_ret_AVL_TX_FRAME_DATA6()                        ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x08, 0xFF, 0)
#define VRX_set_AVL_TX_FRAME_DATA6(val)                     ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x08, 0xFF, 0, val)

#define VRX_get_AVL_TX_FRAME_DATA7(pval)                    ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x09, 0xFF, 0, pval)
#define VRX_ret_AVL_TX_FRAME_DATA7()                        ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x09, 0xFF, 0)
#define VRX_set_AVL_TX_FRAME_DATA7(val)                     ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x09, 0xFF, 0, val)

#define VRX_get_AVL_TX_FRAME_DATA8(pval)                    ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x0A, 0xFF, 0, pval)
#define VRX_ret_AVL_TX_FRAME_DATA8()                        ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x0A, 0xFF, 0)
#define VRX_set_AVL_TX_FRAME_DATA8(val)                     ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x0A, 0xFF, 0, val)

#define VRX_get_AVL_TX_FRAME_DATA9(pval)                    ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x0B, 0xFF, 0, pval)
#define VRX_ret_AVL_TX_FRAME_DATA9()                        ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x0B, 0xFF, 0)
#define VRX_set_AVL_TX_FRAME_DATA9(val)                     ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x0B, 0xFF, 0, val)

#define VRX_get_AVL_TX_FRAME_DATA10(pval)                   ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x0C, 0xFF, 0, pval)
#define VRX_ret_AVL_TX_FRAME_DATA10()                       ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x0C, 0xFF, 0)
#define VRX_set_AVL_TX_FRAME_DATA10(val)                    ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x0C, 0xFF, 0, val)

#define VRX_get_AVL_TX_FRAME_DATA11(pval)                   ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x0D, 0xFF, 0, pval)
#define VRX_ret_AVL_TX_FRAME_DATA11()                       ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x0D, 0xFF, 0)
#define VRX_set_AVL_TX_FRAME_DATA11(val)                    ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x0D, 0xFF, 0, val)

#define VRX_is_AVL_TX_FRAME_ECT_true()                      ATV_I2CIsField8(VRX_AVLINK_MAP_ADDR, 0x0E, 0x1, 0x0)
#define VRX_get_AVL_TX_FRAME_ECT(pval)                      ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x0E, 0x1, 0x0, pval)
#define VRX_ret_AVL_TX_FRAME_ECT()                          ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x0E, 0x1, 0x0)
#define VRX_set_AVL_TX_FRAME_ECT(val)                       ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x0E, 0x1, 0x0, val)

#define VRX_get_AVL_TX_FRAME_LENGTH(pval)                   ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x0F, 0xFF, 0, pval)
#define VRX_ret_AVL_TX_FRAME_LENGTH()                       ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x0F, 0xFF, 0)
#define VRX_set_AVL_TX_FRAME_LENGTH(val)                    ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x0F, 0xFF, 0, val)

#define VRX_is_AVL_TX_ENABLE_true()                         ATV_I2CIsField8(VRX_AVLINK_MAP_ADDR, 0x10, 0x1, 0x0)
#define VRX_get_AVL_TX_ENABLE(pval)                         ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x10, 0x1, 0x0, pval)
#define VRX_ret_AVL_TX_ENABLE()                             ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x10, 0x1, 0x0)
#define VRX_set_AVL_TX_ENABLE(val)                          ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x10, 0x1, 0x0, val)

#define VRX_get_AVL_TX_SFT3(pval)                           ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x11, 0x78, 3, pval)
#define VRX_ret_AVL_TX_SFT3()                               ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x11, 0x78, 3)
#define VRX_set_AVL_TX_SFT3(val)                            ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x11, 0x78, 3, val)

#define VRX_get_AVL_TX_RETRY(pval)                          ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x11, 0x7, 0, pval)
#define VRX_ret_AVL_TX_RETRY()                              ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x11, 0x7, 0)
#define VRX_set_AVL_TX_RETRY(val)                           ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x11, 0x7, 0, val)

#define VRX_get_AVL_TX_SFT7(pval)                           ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x12, 0xF0, 4, pval)
#define VRX_ret_AVL_TX_SFT7()                               ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x12, 0xF0, 4)
#define VRX_set_AVL_TX_SFT7(val)                            ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x12, 0xF0, 4, val)

#define VRX_get_AVL_TX_SFT5(pval)                           ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x12, 0xF, 0, pval)
#define VRX_ret_AVL_TX_SFT5()                               ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x12, 0xF, 0)
#define VRX_set_AVL_TX_SFT5(val)                            ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x12, 0xF, 0, val)

#define VRX_get_AVL_TX_SFT9(pval)                           ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x13, 0xF, 0, pval)
#define VRX_ret_AVL_TX_SFT9()                               ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x13, 0xF, 0)
#define VRX_set_AVL_TX_SFT9(val)                            ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x13, 0xF, 0, val)

#define VRX_get_AVL_TX_NACK_COUNTER(pval)                   ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x14, 0xF, 0, pval)
#define VRX_ret_AVL_TX_NACK_COUNTER()                       ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x14, 0xF, 0)

#define VRX_get_AVL_RX_FRAME_MODE(pval)                     ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x15, 0x3, 0, pval)
#define VRX_ret_AVL_RX_FRAME_MODE()                         ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x15, 0x3, 0)

#define VRX_get_AVL_RX_FRAME_HEADER(pval)                   ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x16, 0xFF, 0, pval)
#define VRX_ret_AVL_RX_FRAME_HEADER()                       ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x16, 0xFF, 0)

#define VRX_get_AVL_RX_FRAME_DATA0(pval)                    ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x17, 0xFF, 0, pval)
#define VRX_ret_AVL_RX_FRAME_DATA0()                        ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x17, 0xFF, 0)

#define VRX_get_AVL_RX_FRAME_DATA1(pval)                    ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x18, 0xFF, 0, pval)
#define VRX_ret_AVL_RX_FRAME_DATA1()                        ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x18, 0xFF, 0)

#define VRX_get_AVL_RX_FRAME_DATA2(pval)                    ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x19, 0xFF, 0, pval)
#define VRX_ret_AVL_RX_FRAME_DATA2()                        ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x19, 0xFF, 0)

#define VRX_get_AVL_RX_FRAME_DATA3(pval)                    ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x1A, 0xFF, 0, pval)
#define VRX_ret_AVL_RX_FRAME_DATA3()                        ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x1A, 0xFF, 0)

#define VRX_get_AVL_RX_FRAME_DATA4(pval)                    ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x1B, 0xFF, 0, pval)
#define VRX_ret_AVL_RX_FRAME_DATA4()                        ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x1B, 0xFF, 0)

#define VRX_get_AVL_RX_FRAME_DATA5(pval)                    ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x1C, 0xFF, 0, pval)
#define VRX_ret_AVL_RX_FRAME_DATA5()                        ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x1C, 0xFF, 0)

#define VRX_get_AVL_RX_FRAME_DATA6(pval)                    ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x1D, 0xFF, 0, pval)
#define VRX_ret_AVL_RX_FRAME_DATA6()                        ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x1D, 0xFF, 0)

#define VRX_get_AVL_RX_FRAME_DATA7(pval)                    ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x1E, 0xFF, 0, pval)
#define VRX_ret_AVL_RX_FRAME_DATA7()                        ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x1E, 0xFF, 0)

#define VRX_get_AVL_RX_FRAME_DATA8(pval)                    ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x1F, 0xFF, 0, pval)
#define VRX_ret_AVL_RX_FRAME_DATA8()                        ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x1F, 0xFF, 0)

#define VRX_get_AVL_RX_FRAME_DATA9(pval)                    ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x20, 0xFF, 0, pval)
#define VRX_ret_AVL_RX_FRAME_DATA9()                        ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x20, 0xFF, 0)

#define VRX_get_AVL_RX_FRAME_DATA10(pval)                   ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x21, 0xFF, 0, pval)
#define VRX_ret_AVL_RX_FRAME_DATA10()                       ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x21, 0xFF, 0)

#define VRX_get_AVL_RX_FRAME_DATA11(pval)                   ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x22, 0xFF, 0, pval)
#define VRX_ret_AVL_RX_FRAME_DATA11()                       ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x22, 0xFF, 0)

#define VRX_is_AVL_RX_FRAME_ECT_true()                      ATV_I2CIsField8(VRX_AVLINK_MAP_ADDR, 0x23, 0x1, 0x0)
#define VRX_get_AVL_RX_FRAME_ECT(pval)                      ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x23, 0x1, 0x0, pval)
#define VRX_ret_AVL_RX_FRAME_ECT()                          ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x23, 0x1, 0x0)

#define VRX_get_AVL_RX_FRAME_LENGTH(pval)                   ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x24, 0xFF, 0, pval)
#define VRX_ret_AVL_RX_FRAME_LENGTH()                       ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x24, 0xFF, 0)

#define VRX_is_AVL_RX_ENABLE_true()                         ATV_I2CIsField8(VRX_AVLINK_MAP_ADDR, 0x25, 0x1, 0x0)
#define VRX_get_AVL_RX_ENABLE(pval)                         ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x25, 0x1, 0x0, pval)
#define VRX_ret_AVL_RX_ENABLE()                             ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x25, 0x1, 0x0)
#define VRX_set_AVL_RX_ENABLE(val)                          ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x25, 0x1, 0x0, val)

#define VRX_get_AVL_LOGICAL_ADDRESS_MASK(pval)              ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x26, 0x70, 4, pval)
#define VRX_ret_AVL_LOGICAL_ADDRESS_MASK()                  ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x26, 0x70, 4)
#define VRX_set_AVL_LOGICAL_ADDRESS_MASK(val)               ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x26, 0x70, 4, val)

#define VRX_is_AVL_ERROR_REPORT_MODE_true()                 ATV_I2CIsField8(VRX_AVLINK_MAP_ADDR, 0x26, 0x8, 0x3)
#define VRX_get_AVL_ERROR_REPORT_MODE(pval)                 ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x26, 0x8, 0x3, pval)
#define VRX_ret_AVL_ERROR_REPORT_MODE()                     ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x26, 0x8, 0x3)
#define VRX_set_AVL_ERROR_REPORT_MODE(val)                  ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x26, 0x8, 0x3, val)

#define VRX_is_AVL_ERROR_DET_MODE_true()                    ATV_I2CIsField8(VRX_AVLINK_MAP_ADDR, 0x26, 0x4, 0x2)
#define VRX_get_AVL_ERROR_DET_MODE(pval)                    ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x26, 0x4, 0x2, pval)
#define VRX_ret_AVL_ERROR_DET_MODE()                        ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x26, 0x4, 0x2)
#define VRX_set_AVL_ERROR_DET_MODE(val)                     ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x26, 0x4, 0x2, val)

#define VRX_is_AVL_FORCE_NACK_true()                        ATV_I2CIsField8(VRX_AVLINK_MAP_ADDR, 0x26, 0x2, 0x1)
#define VRX_get_AVL_FORCE_NACK(pval)                        ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x26, 0x2, 0x1, pval)
#define VRX_ret_AVL_FORCE_NACK()                            ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x26, 0x2, 0x1)
#define VRX_set_AVL_FORCE_NACK(val)                         ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x26, 0x2, 0x1, val)

#define VRX_is_AVL_FORCE_IGNORE_true()                      ATV_I2CIsField8(VRX_AVLINK_MAP_ADDR, 0x26, 0x1, 0x0)
#define VRX_get_AVL_FORCE_IGNORE(pval)                      ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x26, 0x1, 0x0, pval)
#define VRX_ret_AVL_FORCE_IGNORE()                          ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x26, 0x1, 0x0)
#define VRX_set_AVL_FORCE_IGNORE(val)                       ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x26, 0x1, 0x0, val)

#define VRX_is_AVL_AVLINK_POWER_UP_true()                   ATV_I2CIsField8(VRX_AVLINK_MAP_ADDR, 0x27, 0x1, 0x0)
#define VRX_get_AVL_AVLINK_POWER_UP(pval)                   ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x27, 0x1, 0x0, pval)
#define VRX_ret_AVL_AVLINK_POWER_UP()                       ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x27, 0x1, 0x0)
#define VRX_set_AVL_AVLINK_POWER_UP(val)                    ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x27, 0x1, 0x0, val)

#define VRX_get_AVL_GLITCH_FILTER_CTRL(pval)                ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x28, 0x3F, 0, pval)
#define VRX_ret_AVL_GLITCH_FILTER_CTRL()                    ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x28, 0x3F, 0)
#define VRX_set_AVL_GLITCH_FILTER_CTRL(val)                 ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x28, 0x3F, 0, val)

#define VRX_set_AVL_FORCE_ERROR(val)                        ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x29, 0x2, 0x1, val)

#define VRX_set_AVL_SOFT_RESET(val)                         ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x29, 0x1, 0x0, val)

#define VRX_get_AVL_LOGICAL_ADDRESS1(pval)                  ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x2A, 0xF0, 4, pval)
#define VRX_ret_AVL_LOGICAL_ADDRESS1()                      ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x2A, 0xF0, 4)
#define VRX_set_AVL_LOGICAL_ADDRESS1(val)                   ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x2A, 0xF0, 4, val)

#define VRX_get_AVL_LOGICAL_ADDRESS0(pval)                  ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x2A, 0xF, 0, pval)
#define VRX_ret_AVL_LOGICAL_ADDRESS0()                      ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x2A, 0xF, 0)
#define VRX_set_AVL_LOGICAL_ADDRESS0(val)                   ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x2A, 0xF, 0, val)

#define VRX_get_AVL_LOGICAL_ADDRESS2(pval)                  ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x2B, 0xF, 0, pval)
#define VRX_ret_AVL_LOGICAL_ADDRESS2()                      ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x2B, 0xF, 0)
#define VRX_set_AVL_LOGICAL_ADDRESS2(val)                   ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x2B, 0xF, 0, val)

#define VRX_get_AVL_ST_TOTAL_H(pval)                        ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x2C, 0xFF, 0, pval)
#define VRX_ret_AVL_ST_TOTAL_H()                            ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x2C, 0xFF, 0)
#define VRX_set_AVL_ST_TOTAL_H(val)                         ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x2C, 0xFF, 0, val)

#define VRX_get_AVL_ST_TOTAL_L(pval)                        ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x2D, 0xFF, 0, pval)
#define VRX_ret_AVL_ST_TOTAL_L()                            ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x2D, 0xFF, 0)
#define VRX_set_AVL_ST_TOTAL_L(val)                         ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x2D, 0xFF, 0, val)

#define VRX_get_AVL_ST_TOTAL_MIN_H(pval)                    ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x2E, 0xFF, 0, pval)
#define VRX_ret_AVL_ST_TOTAL_MIN_H()                        ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x2E, 0xFF, 0)
#define VRX_set_AVL_ST_TOTAL_MIN_H(val)                     ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x2E, 0xFF, 0, val)

#define VRX_get_AVL_ST_TOTAL_MIN_L(pval)                    ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x2F, 0xFF, 0, pval)
#define VRX_ret_AVL_ST_TOTAL_MIN_L()                        ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x2F, 0xFF, 0)
#define VRX_set_AVL_ST_TOTAL_MIN_L(val)                     ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x2F, 0xFF, 0, val)

#define VRX_get_AVL_ST_TOTAL_MAX_H(pval)                    ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x30, 0xFF, 0, pval)
#define VRX_ret_AVL_ST_TOTAL_MAX_H()                        ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x30, 0xFF, 0)
#define VRX_set_AVL_ST_TOTAL_MAX_H(val)                     ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x30, 0xFF, 0, val)

#define VRX_get_AVL_ST_TOTAL_MAX_L(pval)                    ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x31, 0xFF, 0, pval)
#define VRX_ret_AVL_ST_TOTAL_MAX_L()                        ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x31, 0xFF, 0)
#define VRX_set_AVL_ST_TOTAL_MAX_L(val)                     ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x31, 0xFF, 0, val)

#define VRX_get_AVL_ST_LOW_H(pval)                          ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x32, 0xFF, 0, pval)
#define VRX_ret_AVL_ST_LOW_H()                              ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x32, 0xFF, 0)
#define VRX_set_AVL_ST_LOW_H(val)                           ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x32, 0xFF, 0, val)

#define VRX_get_AVL_ST_LOW_L(pval)                          ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x33, 0xFF, 0, pval)
#define VRX_ret_AVL_ST_LOW_L()                              ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x33, 0xFF, 0)
#define VRX_set_AVL_ST_LOW_L(val)                           ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x33, 0xFF, 0, val)

#define VRX_get_AVL_ST_LOW_MINIMUM_H(pval)                  ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x34, 0xFF, 0, pval)
#define VRX_ret_AVL_ST_LOW_MINIMUM_H()                      ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x34, 0xFF, 0)
#define VRX_set_AVL_ST_LOW_MINIMUM_H(val)                   ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x34, 0xFF, 0, val)

#define VRX_get_AVL_ST_LOW_MINIMUM_L(pval)                  ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x35, 0xFF, 0, pval)
#define VRX_ret_AVL_ST_LOW_MINIMUM_L()                      ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x35, 0xFF, 0)
#define VRX_set_AVL_ST_LOW_MINIMUM_L(val)                   ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x35, 0xFF, 0, val)

#define VRX_get_AVL_ST_LOW_MAXIMUM_H(pval)                  ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x36, 0xFF, 0, pval)
#define VRX_ret_AVL_ST_LOW_MAXIMUM_H()                      ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x36, 0xFF, 0)
#define VRX_set_AVL_ST_LOW_MAXIMUM_H(val)                   ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x36, 0xFF, 0, val)

#define VRX_get_AVL_ST_LOW_MAXIMUM_L(pval)                  ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x37, 0xFF, 0, pval)
#define VRX_ret_AVL_ST_LOW_MAXIMUM_L()                      ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x37, 0xFF, 0)
#define VRX_set_AVL_ST_LOW_MAXIMUM_L(val)                   ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x37, 0xFF, 0, val)

#define VRX_get_AVL_BIT_TOTAL_H(pval)                       ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x38, 0xFF, 0, pval)
#define VRX_ret_AVL_BIT_TOTAL_H()                           ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x38, 0xFF, 0)
#define VRX_set_AVL_BIT_TOTAL_H(val)                        ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x38, 0xFF, 0, val)

#define VRX_get_AVL_BIT_TOTAL_L(pval)                       ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x39, 0xFF, 0, pval)
#define VRX_ret_AVL_BIT_TOTAL_L()                           ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x39, 0xFF, 0)
#define VRX_set_AVL_BIT_TOTAL_L(val)                        ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x39, 0xFF, 0, val)

#define VRX_get_AVL_BIT_TOTAL_MIN_H(pval)                   ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x3A, 0xFF, 0, pval)
#define VRX_ret_AVL_BIT_TOTAL_MIN_H()                       ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x3A, 0xFF, 0)
#define VRX_set_AVL_BIT_TOTAL_MIN_H(val)                    ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x3A, 0xFF, 0, val)

#define VRX_get_AVL_BIT_TOTAL_MIN_L(pval)                   ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x3B, 0xFF, 0, pval)
#define VRX_ret_AVL_BIT_TOTAL_MIN_L()                       ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x3B, 0xFF, 0)
#define VRX_set_AVL_BIT_TOTAL_MIN_L(val)                    ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x3B, 0xFF, 0, val)

#define VRX_get_AVL_BIT_TOTAL_MAX_H(pval)                   ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x3C, 0xFF, 0, pval)
#define VRX_ret_AVL_BIT_TOTAL_MAX_H()                       ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x3C, 0xFF, 0)
#define VRX_set_AVL_BIT_TOTAL_MAX_H(val)                    ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x3C, 0xFF, 0, val)

#define VRX_get_AVL_BIT_TOTAL_MAX_L(pval)                   ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x3D, 0xFF, 0, pval)
#define VRX_ret_AVL_BIT_TOTAL_MAX_L()                       ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x3D, 0xFF, 0)
#define VRX_set_AVL_BIT_TOTAL_MAX_L(val)                    ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x3D, 0xFF, 0, val)

#define VRX_get_AVL_BIT_LOW_ONE_H(pval)                     ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x3E, 0xFF, 0, pval)
#define VRX_ret_AVL_BIT_LOW_ONE_H()                         ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x3E, 0xFF, 0)
#define VRX_set_AVL_BIT_LOW_ONE_H(val)                      ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x3E, 0xFF, 0, val)

#define VRX_get_AVL_BIT_LOW_ONE_L(pval)                     ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x3F, 0xFF, 0, pval)
#define VRX_ret_AVL_BIT_LOW_ONE_L()                         ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x3F, 0xFF, 0)
#define VRX_set_AVL_BIT_LOW_ONE_L(val)                      ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x3F, 0xFF, 0, val)

#define VRX_get_AVL_BIT_LOW_ONE_MIN_H(pval)                 ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x40, 0xFF, 0, pval)
#define VRX_ret_AVL_BIT_LOW_ONE_MIN_H()                     ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x40, 0xFF, 0)
#define VRX_set_AVL_BIT_LOW_ONE_MIN_H(val)                  ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x40, 0xFF, 0, val)

#define VRX_get_AVL_BIT_LOW_ONE_MIN_L(pval)                 ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x41, 0xFF, 0, pval)
#define VRX_ret_AVL_BIT_LOW_ONE_MIN_L()                     ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x41, 0xFF, 0)
#define VRX_set_AVL_BIT_LOW_ONE_MIN_L(val)                  ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x41, 0xFF, 0, val)

#define VRX_get_AVL_BIT_LOW_ONE_MAX_H(pval)                 ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x42, 0xFF, 0, pval)
#define VRX_ret_AVL_BIT_LOW_ONE_MAX_H()                     ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x42, 0xFF, 0)
#define VRX_set_AVL_BIT_LOW_ONE_MAX_H(val)                  ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x42, 0xFF, 0, val)

#define VRX_get_AVL_BIT_LOW_ONE_MAX_L(pval)                 ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x43, 0xFF, 0, pval)
#define VRX_ret_AVL_BIT_LOW_ONE_MAX_L()                     ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x43, 0xFF, 0)
#define VRX_set_AVL_BIT_LOW_ONE_MAX_L(val)                  ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x43, 0xFF, 0, val)

#define VRX_get_AVL_BIT_LOW_ZERO_H(pval)                    ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x44, 0xFF, 0, pval)
#define VRX_ret_AVL_BIT_LOW_ZERO_H()                        ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x44, 0xFF, 0)
#define VRX_set_AVL_BIT_LOW_ZERO_H(val)                     ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x44, 0xFF, 0, val)

#define VRX_get_AVL_BIT_LOW_ZERO_L(pval)                    ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x45, 0xFF, 0, pval)
#define VRX_ret_AVL_BIT_LOW_ZERO_L()                        ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x45, 0xFF, 0)
#define VRX_set_AVL_BIT_LOW_ZERO_L(val)                     ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x45, 0xFF, 0, val)

#define VRX_get_AVL_BIT_LOW_MAX_H(pval)                     ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x46, 0xFF, 0, pval)
#define VRX_ret_AVL_BIT_LOW_MAX_H()                         ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x46, 0xFF, 0)
#define VRX_set_AVL_BIT_LOW_MAX_H(val)                      ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x46, 0xFF, 0, val)

#define VRX_get_AVL_BIT_LOW_MAX_L(pval)                     ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x47, 0xFF, 0, pval)
#define VRX_ret_AVL_BIT_LOW_MAX_L()                         ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x47, 0xFF, 0)
#define VRX_set_AVL_BIT_LOW_MAX_L(val)                      ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x47, 0xFF, 0, val)

#define VRX_get_AVL_BIT_LOW_ZERO_MIN_H(pval)                ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x48, 0xFF, 0, pval)
#define VRX_ret_AVL_BIT_LOW_ZERO_MIN_H()                    ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x48, 0xFF, 0)
#define VRX_set_AVL_BIT_LOW_ZERO_MIN_H(val)                 ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x48, 0xFF, 0, val)

#define VRX_get_AVL_BIT_LOW_ZERO_MIN_L(pval)                ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x49, 0xFF, 0, pval)
#define VRX_ret_AVL_BIT_LOW_ZERO_MIN_L()                    ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x49, 0xFF, 0)
#define VRX_set_AVL_BIT_LOW_ZERO_MIN_L(val)                 ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x49, 0xFF, 0, val)

#define VRX_get_AVL_SAMPLE_TIME_H(pval)                     ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x4A, 0xFF, 0, pval)
#define VRX_ret_AVL_SAMPLE_TIME_H()                         ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x4A, 0xFF, 0)
#define VRX_set_AVL_SAMPLE_TIME_H(val)                      ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x4A, 0xFF, 0, val)

#define VRX_get_AVL_SAMPLE_TIME_L(pval)                     ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x4B, 0xFF, 0, pval)
#define VRX_ret_AVL_SAMPLE_TIME_L()                         ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x4B, 0xFF, 0)
#define VRX_set_AVL_SAMPLE_TIME_L(val)                      ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x4B, 0xFF, 0, val)

#define VRX_get_AVL_LINE_ERROR_TIME_H(pval)                 ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x4C, 0xFF, 0, pval)
#define VRX_ret_AVL_LINE_ERROR_TIME_H()                     ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x4C, 0xFF, 0)
#define VRX_set_AVL_LINE_ERROR_TIME_H(val)                  ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x4C, 0xFF, 0, val)

#define VRX_get_AVL_LINE_ERROR_TIME_L(pval)                 ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x4D, 0xFF, 0, pval)
#define VRX_ret_AVL_LINE_ERROR_TIME_L()                     ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x4D, 0xFF, 0)
#define VRX_set_AVL_LINE_ERROR_TIME_L(val)                  ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x4D, 0xFF, 0, val)

#define VRX_get_AVL_RISE_TIME_H(pval)                       ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x4E, 0xFF, 0, pval)
#define VRX_ret_AVL_RISE_TIME_H()                           ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x4E, 0xFF, 0)
#define VRX_set_AVL_RISE_TIME_H(val)                        ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x4E, 0xFF, 0, val)

#define VRX_get_AVL_RISE_TIME_L(pval)                       ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x4F, 0xFF, 0, pval)
#define VRX_ret_AVL_RISE_TIME_L()                           ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x4F, 0xFF, 0)
#define VRX_set_AVL_RISE_TIME_L(val)                        ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x4F, 0xFF, 0, val)

#define VRX_is_AVL_BIT_LOW_DETMODE_true()                   ATV_I2CIsField8(VRX_AVLINK_MAP_ADDR, 0x50, 0x1, 0x0)
#define VRX_get_AVL_BIT_LOW_DETMODE(pval)                   ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x50, 0x1, 0x0, pval)
#define VRX_ret_AVL_BIT_LOW_DETMODE()                       ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x50, 0x1, 0x0)
#define VRX_set_AVL_BIT_LOW_DETMODE(val)                    ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x50, 0x1, 0x0, val)

#define VRX_is_AVL_TIMING_MAN_true()                        ATV_I2CIsField8(VRX_AVLINK_MAP_ADDR, 0x51, 0x1, 0x0)
#define VRX_get_AVL_TIMING_MAN(pval)                        ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x51, 0x1, 0x0, pval)
#define VRX_ret_AVL_TIMING_MAN()                            ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x51, 0x1, 0x0)
#define VRX_set_AVL_TIMING_MAN(val)                         ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x51, 0x1, 0x0, val)

#define VRX_is_AVL_MODE00_HEADER_VALIDATE_true()            ATV_I2CIsField8(VRX_AVLINK_MAP_ADDR, 0x52, 0x1, 0x0)
#define VRX_get_AVL_MODE00_HEADER_VALIDATE(pval)            ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x52, 0x1, 0x0, pval)
#define VRX_ret_AVL_MODE00_HEADER_VALIDATE()                ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x52, 0x1, 0x0)
#define VRX_set_AVL_MODE00_HEADER_VALIDATE(val)             ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x52, 0x1, 0x0, val)

#define VRX_get_AVL_PROP_DELAY_H(pval)                      ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x53, 0xFF, 0, pval)
#define VRX_ret_AVL_PROP_DELAY_H()                          ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x53, 0xFF, 0)
#define VRX_set_AVL_PROP_DELAY_H(val)                       ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x53, 0xFF, 0, val)

#define VRX_get_AVL_PROP_DELAY_L(pval)                      ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x54, 0xFF, 0, pval)
#define VRX_ret_AVL_PROP_DELAY_L()                          ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x54, 0xFF, 0)
#define VRX_set_AVL_PROP_DELAY_L(val)                       ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x54, 0xFF, 0, val)

#define VRX_get_AVL_RX_DEVICE_CAPABILITY_ARB(pval)          ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x55, 0x3F, 0, pval)
#define VRX_ret_AVL_RX_DEVICE_CAPABILITY_ARB()              ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x55, 0x3F, 0)
#define VRX_set_AVL_RX_DEVICE_CAPABILITY_ARB(val)           ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x55, 0x3F, 0, val)

#define VRX_get_AVL_TX_RECEIVED_ARB(pval)                   ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x56, 0x3F, 0, pval)
#define VRX_ret_AVL_TX_RECEIVED_ARB()                       ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x56, 0x3F, 0)

#define VRX_get_AVL_RX_EXPECT_FRAME_LENGTH(pval)            ATV_I2CGetField8(VRX_AVLINK_MAP_ADDR, 0x58, 0xFF, 0, pval)
#define VRX_ret_AVL_RX_EXPECT_FRAME_LENGTH()                ATV_I2CReadField8(VRX_AVLINK_MAP_ADDR, 0x58, 0xFF, 0)
#define VRX_set_AVL_RX_EXPECT_FRAME_LENGTH(val)             ATV_I2CWriteField8(VRX_AVLINK_MAP_ADDR, 0x58, 0xFF, 0, val)

#endif
