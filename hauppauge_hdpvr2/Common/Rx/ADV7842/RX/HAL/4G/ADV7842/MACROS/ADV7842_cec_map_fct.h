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
* DATE: 18 Nov 2009 15:43:9                                                    *
*                                                                              *
*******************************************************************************/


#ifndef ADV7842_CEC_MAP_FCT_H
#define ADV7842_CEC_MAP_FCT_H

#include "ADV7842_cfg.h"

#define VRX_get_CEC_TX_FRAME_HEADER(pval)                   ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x00, 0xFF, 0, pval)
#define VRX_ret_CEC_TX_FRAME_HEADER()                       ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x00, 0xFF, 0)
#define VRX_set_CEC_TX_FRAME_HEADER(val)                    ATV_I2CWriteField8(VRX_CEC_MAP_ADDR, 0x00, 0xFF, 0, val)

#define VRX_get_CEC_TX_FRAME_DATA0(pval)                    ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x01, 0xFF, 0, pval)
#define VRX_ret_CEC_TX_FRAME_DATA0()                        ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x01, 0xFF, 0)
#define VRX_set_CEC_TX_FRAME_DATA0(val)                     ATV_I2CWriteField8(VRX_CEC_MAP_ADDR, 0x01, 0xFF, 0, val)

#define VRX_get_CEC_TX_FRAME_DATA1(pval)                    ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x02, 0xFF, 0, pval)
#define VRX_ret_CEC_TX_FRAME_DATA1()                        ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x02, 0xFF, 0)
#define VRX_set_CEC_TX_FRAME_DATA1(val)                     ATV_I2CWriteField8(VRX_CEC_MAP_ADDR, 0x02, 0xFF, 0, val)

#define VRX_get_CEC_TX_FRAME_DATA2(pval)                    ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x03, 0xFF, 0, pval)
#define VRX_ret_CEC_TX_FRAME_DATA2()                        ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x03, 0xFF, 0)
#define VRX_set_CEC_TX_FRAME_DATA2(val)                     ATV_I2CWriteField8(VRX_CEC_MAP_ADDR, 0x03, 0xFF, 0, val)

#define VRX_get_CEC_TX_FRAME_DATA3(pval)                    ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x04, 0xFF, 0, pval)
#define VRX_ret_CEC_TX_FRAME_DATA3()                        ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x04, 0xFF, 0)
#define VRX_set_CEC_TX_FRAME_DATA3(val)                     ATV_I2CWriteField8(VRX_CEC_MAP_ADDR, 0x04, 0xFF, 0, val)

#define VRX_get_CEC_TX_FRAME_DATA4(pval)                    ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x05, 0xFF, 0, pval)
#define VRX_ret_CEC_TX_FRAME_DATA4()                        ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x05, 0xFF, 0)
#define VRX_set_CEC_TX_FRAME_DATA4(val)                     ATV_I2CWriteField8(VRX_CEC_MAP_ADDR, 0x05, 0xFF, 0, val)

#define VRX_get_CEC_TX_FRAME_DATA5(pval)                    ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x06, 0xFF, 0, pval)
#define VRX_ret_CEC_TX_FRAME_DATA5()                        ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x06, 0xFF, 0)
#define VRX_set_CEC_TX_FRAME_DATA5(val)                     ATV_I2CWriteField8(VRX_CEC_MAP_ADDR, 0x06, 0xFF, 0, val)

#define VRX_get_CEC_TX_FRAME_DATA6(pval)                    ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x07, 0xFF, 0, pval)
#define VRX_ret_CEC_TX_FRAME_DATA6()                        ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x07, 0xFF, 0)
#define VRX_set_CEC_TX_FRAME_DATA6(val)                     ATV_I2CWriteField8(VRX_CEC_MAP_ADDR, 0x07, 0xFF, 0, val)

#define VRX_get_CEC_TX_FRAME_DATA7(pval)                    ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x08, 0xFF, 0, pval)
#define VRX_ret_CEC_TX_FRAME_DATA7()                        ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x08, 0xFF, 0)
#define VRX_set_CEC_TX_FRAME_DATA7(val)                     ATV_I2CWriteField8(VRX_CEC_MAP_ADDR, 0x08, 0xFF, 0, val)

#define VRX_get_CEC_TX_FRAME_DATA8(pval)                    ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x09, 0xFF, 0, pval)
#define VRX_ret_CEC_TX_FRAME_DATA8()                        ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x09, 0xFF, 0)
#define VRX_set_CEC_TX_FRAME_DATA8(val)                     ATV_I2CWriteField8(VRX_CEC_MAP_ADDR, 0x09, 0xFF, 0, val)

#define VRX_get_CEC_TX_FRAME_DATA9(pval)                    ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x0A, 0xFF, 0, pval)
#define VRX_ret_CEC_TX_FRAME_DATA9()                        ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x0A, 0xFF, 0)
#define VRX_set_CEC_TX_FRAME_DATA9(val)                     ATV_I2CWriteField8(VRX_CEC_MAP_ADDR, 0x0A, 0xFF, 0, val)

#define VRX_get_CEC_TX_FRAME_DATA10(pval)                   ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x0B, 0xFF, 0, pval)
#define VRX_ret_CEC_TX_FRAME_DATA10()                       ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x0B, 0xFF, 0)
#define VRX_set_CEC_TX_FRAME_DATA10(val)                    ATV_I2CWriteField8(VRX_CEC_MAP_ADDR, 0x0B, 0xFF, 0, val)

#define VRX_get_CEC_TX_FRAME_DATA11(pval)                   ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x0C, 0xFF, 0, pval)
#define VRX_ret_CEC_TX_FRAME_DATA11()                       ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x0C, 0xFF, 0)
#define VRX_set_CEC_TX_FRAME_DATA11(val)                    ATV_I2CWriteField8(VRX_CEC_MAP_ADDR, 0x0C, 0xFF, 0, val)

#define VRX_get_CEC_TX_FRAME_DATA12(pval)                   ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x0D, 0xFF, 0, pval)
#define VRX_ret_CEC_TX_FRAME_DATA12()                       ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x0D, 0xFF, 0)
#define VRX_set_CEC_TX_FRAME_DATA12(val)                    ATV_I2CWriteField8(VRX_CEC_MAP_ADDR, 0x0D, 0xFF, 0, val)

#define VRX_get_CEC_TX_FRAME_DATA13(pval)                   ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x0E, 0xFF, 0, pval)
#define VRX_ret_CEC_TX_FRAME_DATA13()                       ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x0E, 0xFF, 0)
#define VRX_set_CEC_TX_FRAME_DATA13(val)                    ATV_I2CWriteField8(VRX_CEC_MAP_ADDR, 0x0E, 0xFF, 0, val)

#define VRX_get_CEC_TX_FRAME_DATA14(pval)                   ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x0F, 0xFF, 0, pval)
#define VRX_ret_CEC_TX_FRAME_DATA14()                       ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x0F, 0xFF, 0)
#define VRX_set_CEC_TX_FRAME_DATA14(val)                    ATV_I2CWriteField8(VRX_CEC_MAP_ADDR, 0x0F, 0xFF, 0, val)

#define VRX_get_CEC_TX_FRAME_LENGTH(pval)                   ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x10, 0x1F, 0, pval)
#define VRX_ret_CEC_TX_FRAME_LENGTH()                       ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x10, 0x1F, 0)
#define VRX_set_CEC_TX_FRAME_LENGTH(val)                    ATV_I2CWriteField8(VRX_CEC_MAP_ADDR, 0x10, 0x1F, 0, val)

#define VRX_is_CEC_TX_ENABLE_true()                         ATV_I2CIsField8(VRX_CEC_MAP_ADDR, 0x11, 0x1, 0x0)
#define VRX_get_CEC_TX_ENABLE(pval)                         ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x11, 0x1, 0x0, pval)
#define VRX_ret_CEC_TX_ENABLE()                             ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x11, 0x1, 0x0)
#define VRX_set_CEC_TX_ENABLE(val)                          ATV_I2CWriteField8(VRX_CEC_MAP_ADDR, 0x11, 0x1, 0x0, val)

#define VRX_get_CEC_TX_RETRY(pval)                          ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x12, 0x70, 4, pval)
#define VRX_ret_CEC_TX_RETRY()                              ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x12, 0x70, 4)
#define VRX_set_CEC_TX_RETRY(val)                           ATV_I2CWriteField8(VRX_CEC_MAP_ADDR, 0x12, 0x70, 4, val)

#define VRX_get_CEC_RETRY_SFT(pval)                         ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x12, 0xF, 0, pval)
#define VRX_ret_CEC_RETRY_SFT()                             ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x12, 0xF, 0)
#define VRX_set_CEC_RETRY_SFT(val)                          ATV_I2CWriteField8(VRX_CEC_MAP_ADDR, 0x12, 0xF, 0, val)

#define VRX_get_CEC_TX_SFT(pval)                            ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x13, 0xF, 0, pval)
#define VRX_ret_CEC_TX_SFT()                                ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x13, 0xF, 0)
#define VRX_set_CEC_TX_SFT(val)                             ATV_I2CWriteField8(VRX_CEC_MAP_ADDR, 0x13, 0xF, 0, val)

#define VRX_get_CEC_TX_LOWDRIVE_COUNTER(pval)               ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x14, 0xF0, 4, pval)
#define VRX_ret_CEC_TX_LOWDRIVE_COUNTER()                   ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x14, 0xF0, 4)

#define VRX_get_CEC_TX_NACK_COUNTER(pval)                   ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x14, 0xF, 0, pval)
#define VRX_ret_CEC_TX_NACK_COUNTER()                       ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x14, 0xF, 0)

#define VRX_get_CEC_BUF0_RX_FRAME_HEADER(pval)              ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x15, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF0_RX_FRAME_HEADER()                  ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x15, 0xFF, 0)

#define VRX_get_CEC_BUF0_RX_FRAME_DATA0(pval)               ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x16, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF0_RX_FRAME_DATA0()                   ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x16, 0xFF, 0)

#define VRX_get_CEC_BUF0_RX_FRAME_DATA1(pval)               ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x17, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF0_RX_FRAME_DATA1()                   ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x17, 0xFF, 0)

#define VRX_get_CEC_BUF0_RX_FRAME_DATA2(pval)               ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x18, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF0_RX_FRAME_DATA2()                   ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x18, 0xFF, 0)

#define VRX_get_CEC_BUF0_RX_FRAME_DATA3(pval)               ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x19, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF0_RX_FRAME_DATA3()                   ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x19, 0xFF, 0)

#define VRX_get_CEC_BUF0_RX_FRAME_DATA4(pval)               ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x1A, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF0_RX_FRAME_DATA4()                   ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x1A, 0xFF, 0)

#define VRX_get_CEC_BUF0_RX_FRAME_DATA5(pval)               ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x1B, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF0_RX_FRAME_DATA5()                   ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x1B, 0xFF, 0)

#define VRX_get_CEC_BUF0_RX_FRAME_DATA6(pval)               ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x1C, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF0_RX_FRAME_DATA6()                   ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x1C, 0xFF, 0)

#define VRX_get_CEC_BUF0_RX_FRAME_DATA7(pval)               ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x1D, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF0_RX_FRAME_DATA7()                   ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x1D, 0xFF, 0)

#define VRX_get_CEC_BUF0_RX_FRAME_DATA8(pval)               ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x1E, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF0_RX_FRAME_DATA8()                   ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x1E, 0xFF, 0)

#define VRX_get_CEC_BUF0_RX_FRAME_DATA9(pval)               ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x1F, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF0_RX_FRAME_DATA9()                   ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x1F, 0xFF, 0)

#define VRX_get_CEC_BUF0_RX_FRAME_DATA10(pval)              ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x20, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF0_RX_FRAME_DATA10()                  ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x20, 0xFF, 0)

#define VRX_get_CEC_BUF0_RX_FRAME_DATA11(pval)              ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x21, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF0_RX_FRAME_DATA11()                  ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x21, 0xFF, 0)

#define VRX_get_CEC_BUF0_RX_FRAME_DATA12(pval)              ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x22, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF0_RX_FRAME_DATA12()                  ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x22, 0xFF, 0)

#define VRX_get_CEC_BUF0_RX_FRAME_DATA13(pval)              ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x23, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF0_RX_FRAME_DATA13()                  ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x23, 0xFF, 0)

#define VRX_get_CEC_BUF0_RX_FRAME_DATA14(pval)              ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x24, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF0_RX_FRAME_DATA14()                  ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x24, 0xFF, 0)

#define VRX_get_CEC_BUF0_RX_FRAME_LENGTH(pval)              ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x25, 0x1F, 0, pval)
#define VRX_ret_CEC_BUF0_RX_FRAME_LENGTH()                  ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x25, 0x1F, 0)

#define VRX_get_CEC_LOGICAL_ADDRESS_MASK(pval)              ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x27, 0x70, 4, pval)
#define VRX_ret_CEC_LOGICAL_ADDRESS_MASK()                  ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x27, 0x70, 4)
#define VRX_set_CEC_LOGICAL_ADDRESS_MASK(val)               ATV_I2CWriteField8(VRX_CEC_MAP_ADDR, 0x27, 0x70, 4, val)

#define VRX_is_CEC_ERROR_REPORT_MODE_true()                 ATV_I2CIsField8(VRX_CEC_MAP_ADDR, 0x27, 0x8, 0x3)
#define VRX_get_CEC_ERROR_REPORT_MODE(pval)                 ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x27, 0x8, 0x3, pval)
#define VRX_ret_CEC_ERROR_REPORT_MODE()                     ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x27, 0x8, 0x3)
#define VRX_set_CEC_ERROR_REPORT_MODE(val)                  ATV_I2CWriteField8(VRX_CEC_MAP_ADDR, 0x27, 0x8, 0x3, val)

#define VRX_is_CEC_ERROR_DET_MODE_true()                    ATV_I2CIsField8(VRX_CEC_MAP_ADDR, 0x27, 0x4, 0x2)
#define VRX_get_CEC_ERROR_DET_MODE(pval)                    ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x27, 0x4, 0x2, pval)
#define VRX_ret_CEC_ERROR_DET_MODE()                        ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x27, 0x4, 0x2)
#define VRX_set_CEC_ERROR_DET_MODE(val)                     ATV_I2CWriteField8(VRX_CEC_MAP_ADDR, 0x27, 0x4, 0x2, val)

#define VRX_is_CEC_FORCE_NACK_true()                        ATV_I2CIsField8(VRX_CEC_MAP_ADDR, 0x27, 0x2, 0x1)
#define VRX_get_CEC_FORCE_NACK(pval)                        ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x27, 0x2, 0x1, pval)
#define VRX_ret_CEC_FORCE_NACK()                            ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x27, 0x2, 0x1)
#define VRX_set_CEC_FORCE_NACK(val)                         ATV_I2CWriteField8(VRX_CEC_MAP_ADDR, 0x27, 0x2, 0x1, val)

#define VRX_is_CEC_FORCE_IGNORE_true()                      ATV_I2CIsField8(VRX_CEC_MAP_ADDR, 0x27, 0x1, 0x0)
#define VRX_get_CEC_FORCE_IGNORE(pval)                      ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x27, 0x1, 0x0, pval)
#define VRX_ret_CEC_FORCE_IGNORE()                          ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x27, 0x1, 0x0)
#define VRX_set_CEC_FORCE_IGNORE(val)                       ATV_I2CWriteField8(VRX_CEC_MAP_ADDR, 0x27, 0x1, 0x0, val)

#define VRX_get_CEC_LOGICAL_ADDRESS1(pval)                  ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x28, 0xF0, 4, pval)
#define VRX_ret_CEC_LOGICAL_ADDRESS1()                      ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x28, 0xF0, 4)
#define VRX_set_CEC_LOGICAL_ADDRESS1(val)                   ATV_I2CWriteField8(VRX_CEC_MAP_ADDR, 0x28, 0xF0, 4, val)

#define VRX_get_CEC_LOGICAL_ADDRESS0(pval)                  ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x28, 0xF, 0, pval)
#define VRX_ret_CEC_LOGICAL_ADDRESS0()                      ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x28, 0xF, 0)
#define VRX_set_CEC_LOGICAL_ADDRESS0(val)                   ATV_I2CWriteField8(VRX_CEC_MAP_ADDR, 0x28, 0xF, 0, val)

#define VRX_get_CEC_LOGICAL_ADDRESS2(pval)                  ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x29, 0xF, 0, pval)
#define VRX_ret_CEC_LOGICAL_ADDRESS2()                      ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x29, 0xF, 0)
#define VRX_set_CEC_LOGICAL_ADDRESS2(val)                   ATV_I2CWriteField8(VRX_CEC_MAP_ADDR, 0x29, 0xF, 0, val)

#define VRX_is_CEC_POWER_UP_true()                          ATV_I2CIsField8(VRX_CEC_MAP_ADDR, 0x2A, 0x1, 0x0)
#define VRX_get_CEC_POWER_UP(pval)                          ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x2A, 0x1, 0x0, pval)
#define VRX_ret_CEC_POWER_UP()                              ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x2A, 0x1, 0x0)
#define VRX_set_CEC_POWER_UP(val)                           ATV_I2CWriteField8(VRX_CEC_MAP_ADDR, 0x2A, 0x1, 0x0, val)

#define VRX_get_CEC_GLITCH_FILTER_CTRL(pval)                ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x2B, 0x3F, 0, pval)
#define VRX_ret_CEC_GLITCH_FILTER_CTRL()                    ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x2B, 0x3F, 0)
#define VRX_set_CEC_GLITCH_FILTER_CTRL(val)                 ATV_I2CWriteField8(VRX_CEC_MAP_ADDR, 0x2B, 0x3F, 0, val)

#define VRX_set_CEC_CLR_RX_RDY2(val)                        ATV_I2CWriteField8(VRX_CEC_MAP_ADDR, 0x2C, 0x8, 0x3, val)

#define VRX_set_CEC_CLR_RX_RDY1(val)                        ATV_I2CWriteField8(VRX_CEC_MAP_ADDR, 0x2C, 0x4, 0x2, val)

#define VRX_set_CEC_CLR_RX_RDY0(val)                        ATV_I2CWriteField8(VRX_CEC_MAP_ADDR, 0x2C, 0x2, 0x1, val)

#define VRX_set_CEC_SOFT_RESET(val)                         ATV_I2CWriteField8(VRX_CEC_MAP_ADDR, 0x2C, 0x1, 0x0, val)

#define VRX_is_CEC_DIS_AUTO_MODE_true()                     ATV_I2CIsField8(VRX_CEC_MAP_ADDR, 0x4C, 0x4, 0x2)
#define VRX_get_CEC_DIS_AUTO_MODE(pval)                     ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x4C, 0x4, 0x2, pval)
#define VRX_ret_CEC_DIS_AUTO_MODE()                         ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x4C, 0x4, 0x2)
#define VRX_set_CEC_DIS_AUTO_MODE(val)                      ATV_I2CWriteField8(VRX_CEC_MAP_ADDR, 0x4C, 0x4, 0x2, val)

#define VRX_get_CEC_BUF2_TIMESTAMP(pval)                    ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x53, 0x30, 4, pval)
#define VRX_ret_CEC_BUF2_TIMESTAMP()                        ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x53, 0x30, 4)

#define VRX_get_CEC_BUF1_TIMESTAMP(pval)                    ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x53, 0xC, 2, pval)
#define VRX_ret_CEC_BUF1_TIMESTAMP()                        ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x53, 0xC, 2)

#define VRX_get_CEC_BUF0_TIMESTAMP(pval)                    ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x53, 0x3, 0, pval)
#define VRX_ret_CEC_BUF0_TIMESTAMP()                        ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x53, 0x3, 0)

#define VRX_get_CEC_BUF1_RX_FRAME_HEADER(pval)              ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x54, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF1_RX_FRAME_HEADER()                  ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x54, 0xFF, 0)

#define VRX_get_CEC_BUF1_RX_FRAME_DATA0(pval)               ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x55, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF1_RX_FRAME_DATA0()                   ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x55, 0xFF, 0)

#define VRX_get_CEC_BUF1_RX_FRAME_DATA1(pval)               ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x56, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF1_RX_FRAME_DATA1()                   ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x56, 0xFF, 0)

#define VRX_get_CEC_BUF1_RX_FRAME_DATA2(pval)               ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x57, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF1_RX_FRAME_DATA2()                   ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x57, 0xFF, 0)

#define VRX_get_CEC_BUF1_RX_FRAME_DATA3(pval)               ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x58, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF1_RX_FRAME_DATA3()                   ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x58, 0xFF, 0)

#define VRX_get_CEC_BUF1_RX_FRAME_DATA4(pval)               ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x59, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF1_RX_FRAME_DATA4()                   ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x59, 0xFF, 0)

#define VRX_get_CEC_BUF1_RX_FRAME_DATA5(pval)               ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x5A, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF1_RX_FRAME_DATA5()                   ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x5A, 0xFF, 0)

#define VRX_get_CEC_BUF1_RX_FRAME_DATA6(pval)               ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x5B, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF1_RX_FRAME_DATA6()                   ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x5B, 0xFF, 0)

#define VRX_get_CEC_BUF1_RX_FRAME_DATA7(pval)               ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x5C, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF1_RX_FRAME_DATA7()                   ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x5C, 0xFF, 0)

#define VRX_get_CEC_BUF1_RX_FRAME_DATA8(pval)               ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x5D, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF1_RX_FRAME_DATA8()                   ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x5D, 0xFF, 0)

#define VRX_get_CEC_BUF1_RX_FRAME_DATA9(pval)               ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x5E, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF1_RX_FRAME_DATA9()                   ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x5E, 0xFF, 0)

#define VRX_get_CEC_BUF1_RX_FRAME_DATA10(pval)              ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x5F, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF1_RX_FRAME_DATA10()                  ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x5F, 0xFF, 0)

#define VRX_get_CEC_BUF1_RX_FRAME_DATA11(pval)              ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x60, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF1_RX_FRAME_DATA11()                  ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x60, 0xFF, 0)

#define VRX_get_CEC_BUF1_RX_FRAME_DATA12(pval)              ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x61, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF1_RX_FRAME_DATA12()                  ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x61, 0xFF, 0)

#define VRX_get_CEC_BUF1_RX_FRAME_DATA13(pval)              ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x62, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF1_RX_FRAME_DATA13()                  ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x62, 0xFF, 0)

#define VRX_get_CEC_BUF1_RX_FRAME_DATA14(pval)              ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x63, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF1_RX_FRAME_DATA14()                  ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x63, 0xFF, 0)

#define VRX_get_CEC_BUF1_RX_FRAME_LENGTH(pval)              ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x64, 0x1F, 0, pval)
#define VRX_ret_CEC_BUF1_RX_FRAME_LENGTH()                  ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x64, 0x1F, 0)

#define VRX_get_CEC_BUF2_RX_FRAME_HEADER(pval)              ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x65, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF2_RX_FRAME_HEADER()                  ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x65, 0xFF, 0)

#define VRX_get_CEC_BUF2_RX_FRAME_DATA0(pval)               ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x66, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF2_RX_FRAME_DATA0()                   ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x66, 0xFF, 0)

#define VRX_get_CEC_BUF2_RX_FRAME_DATA1(pval)               ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x67, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF2_RX_FRAME_DATA1()                   ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x67, 0xFF, 0)

#define VRX_get_CEC_BUF2_RX_FRAME_DATA2(pval)               ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x68, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF2_RX_FRAME_DATA2()                   ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x68, 0xFF, 0)

#define VRX_get_CEC_BUF2_RX_FRAME_DATA3(pval)               ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x69, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF2_RX_FRAME_DATA3()                   ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x69, 0xFF, 0)

#define VRX_get_CEC_BUF2_RX_FRAME_DATA4(pval)               ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x6A, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF2_RX_FRAME_DATA4()                   ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x6A, 0xFF, 0)

#define VRX_get_CEC_BUF2_RX_FRAME_DATA5(pval)               ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x6B, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF2_RX_FRAME_DATA5()                   ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x6B, 0xFF, 0)

#define VRX_get_CEC_BUF2_RX_FRAME_DATA6(pval)               ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x6C, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF2_RX_FRAME_DATA6()                   ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x6C, 0xFF, 0)

#define VRX_get_CEC_BUF2_RX_FRAME_DATA7(pval)               ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x6D, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF2_RX_FRAME_DATA7()                   ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x6D, 0xFF, 0)

#define VRX_get_CEC_BUF2_RX_FRAME_DATA8(pval)               ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x6E, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF2_RX_FRAME_DATA8()                   ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x6E, 0xFF, 0)

#define VRX_get_CEC_BUF2_RX_FRAME_DATA9(pval)               ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x6F, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF2_RX_FRAME_DATA9()                   ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x6F, 0xFF, 0)

#define VRX_get_CEC_BUF2_RX_FRAME_DATA10(pval)              ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x70, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF2_RX_FRAME_DATA10()                  ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x70, 0xFF, 0)

#define VRX_get_CEC_BUF2_RX_FRAME_DATA11(pval)              ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x71, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF2_RX_FRAME_DATA11()                  ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x71, 0xFF, 0)

#define VRX_get_CEC_BUF2_RX_FRAME_DATA12(pval)              ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x72, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF2_RX_FRAME_DATA12()                  ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x72, 0xFF, 0)

#define VRX_get_CEC_BUF2_RX_FRAME_DATA13(pval)              ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x73, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF2_RX_FRAME_DATA13()                  ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x73, 0xFF, 0)

#define VRX_get_CEC_BUF2_RX_FRAME_DATA14(pval)              ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x74, 0xFF, 0, pval)
#define VRX_ret_CEC_BUF2_RX_FRAME_DATA14()                  ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x74, 0xFF, 0)

#define VRX_get_CEC_BUF2_RX_FRAME_LENGTH(pval)              ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x75, 0x1F, 0, pval)
#define VRX_ret_CEC_BUF2_RX_FRAME_LENGTH()                  ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x75, 0x1F, 0)

#define VRX_is_CEC_RX_RDY2_true()                           ATV_I2CIsField8(VRX_CEC_MAP_ADDR, 0x76, 0x4, 0x2)
#define VRX_get_CEC_RX_RDY2(pval)                           ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x76, 0x4, 0x2, pval)
#define VRX_ret_CEC_RX_RDY2()                               ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x76, 0x4, 0x2)

#define VRX_is_CEC_RX_RDY1_true()                           ATV_I2CIsField8(VRX_CEC_MAP_ADDR, 0x76, 0x2, 0x1)
#define VRX_get_CEC_RX_RDY1(pval)                           ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x76, 0x2, 0x1, pval)
#define VRX_ret_CEC_RX_RDY1()                               ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x76, 0x2, 0x1)

#define VRX_is_CEC_RX_RDY0_true()                           ATV_I2CIsField8(VRX_CEC_MAP_ADDR, 0x76, 0x1, 0x0)
#define VRX_get_CEC_RX_RDY0(pval)                           ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x76, 0x1, 0x0, pval)
#define VRX_ret_CEC_RX_RDY0()                               ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x76, 0x1, 0x0)

#define VRX_is_CEC_USE_ALL_BUFS_true()                      ATV_I2CIsField8(VRX_CEC_MAP_ADDR, 0x77, 0x1, 0x0)
#define VRX_get_CEC_USE_ALL_BUFS(pval)                      ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x77, 0x1, 0x0, pval)
#define VRX_ret_CEC_USE_ALL_BUFS()                          ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x77, 0x1, 0x0)
#define VRX_set_CEC_USE_ALL_BUFS(val)                       ATV_I2CWriteField8(VRX_CEC_MAP_ADDR, 0x77, 0x1, 0x0, val)

#define VRX_get_CEC_WAKE_OPCODE0(pval)                      ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x78, 0xFF, 0, pval)
#define VRX_ret_CEC_WAKE_OPCODE0()                          ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x78, 0xFF, 0)
#define VRX_set_CEC_WAKE_OPCODE0(val)                       ATV_I2CWriteField8(VRX_CEC_MAP_ADDR, 0x78, 0xFF, 0, val)

#define VRX_get_CEC_WAKE_OPCODE1(pval)                      ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x79, 0xFF, 0, pval)
#define VRX_ret_CEC_WAKE_OPCODE1()                          ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x79, 0xFF, 0)
#define VRX_set_CEC_WAKE_OPCODE1(val)                       ATV_I2CWriteField8(VRX_CEC_MAP_ADDR, 0x79, 0xFF, 0, val)

#define VRX_get_CEC_WAKE_OPCODE2(pval)                      ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x7A, 0xFF, 0, pval)
#define VRX_ret_CEC_WAKE_OPCODE2()                          ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x7A, 0xFF, 0)
#define VRX_set_CEC_WAKE_OPCODE2(val)                       ATV_I2CWriteField8(VRX_CEC_MAP_ADDR, 0x7A, 0xFF, 0, val)

#define VRX_get_CEC_WAKE_OPCODE3(pval)                      ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x7B, 0xFF, 0, pval)
#define VRX_ret_CEC_WAKE_OPCODE3()                          ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x7B, 0xFF, 0)
#define VRX_set_CEC_WAKE_OPCODE3(val)                       ATV_I2CWriteField8(VRX_CEC_MAP_ADDR, 0x7B, 0xFF, 0, val)

#define VRX_get_CEC_WAKE_OPCODE4(pval)                      ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x7C, 0xFF, 0, pval)
#define VRX_ret_CEC_WAKE_OPCODE4()                          ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x7C, 0xFF, 0)
#define VRX_set_CEC_WAKE_OPCODE4(val)                       ATV_I2CWriteField8(VRX_CEC_MAP_ADDR, 0x7C, 0xFF, 0, val)

#define VRX_get_CEC_WAKE_OPCODE5(pval)                      ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x7D, 0xFF, 0, pval)
#define VRX_ret_CEC_WAKE_OPCODE5()                          ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x7D, 0xFF, 0)
#define VRX_set_CEC_WAKE_OPCODE5(val)                       ATV_I2CWriteField8(VRX_CEC_MAP_ADDR, 0x7D, 0xFF, 0, val)

#define VRX_get_CEC_WAKE_OPCODE6(pval)                      ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x7E, 0xFF, 0, pval)
#define VRX_ret_CEC_WAKE_OPCODE6()                          ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x7E, 0xFF, 0)
#define VRX_set_CEC_WAKE_OPCODE6(val)                       ATV_I2CWriteField8(VRX_CEC_MAP_ADDR, 0x7E, 0xFF, 0, val)

#define VRX_get_CEC_WAKE_OPCODE7(pval)                      ATV_I2CGetField8(VRX_CEC_MAP_ADDR, 0x7F, 0xFF, 0, pval)
#define VRX_ret_CEC_WAKE_OPCODE7()                          ATV_I2CReadField8(VRX_CEC_MAP_ADDR, 0x7F, 0xFF, 0)
#define VRX_set_CEC_WAKE_OPCODE7(val)                       ATV_I2CWriteField8(VRX_CEC_MAP_ADDR, 0x7F, 0xFF, 0, val)

#endif
