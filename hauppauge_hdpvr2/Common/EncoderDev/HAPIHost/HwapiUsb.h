//================================================================
//  File Name: HwapiUsb.h
//
//  Copyright 2010 Magnum Semiconductor Inc.  All rights reserved.
//
//  Description:
//
//  Define all usb port hwapi functions under Windows.
//
//  Modification History:
//
//================================================================

#ifndef _HWAPI_USB_H_
#define _HWAPI_USB_H_

#include "Hwapi.h"

typedef void * USBDevHandle;



USBDevHandle USB_CommBusInit (Uint32 ChipID,hw_port_config *pHwPortConfig);
HWAPIErrCode USB_GetBoardInfo (USBDevHandle hDevice,BOARD_INFO *pBoardInfo);
HWAPIErrCode USB_BoardInit (USBDevHandle hDevice, DRAM_BKV_CONFIG *bkvConfig);
HWAPIErrCode USB_BinaryDownload (USBDevHandle hDevice, FIRMWARE_FILE *Binary);
HWAPIErrCode USB_SystemBootup (USBDevHandle hDevice);
HWAPIErrCode USB_Exit (USBDevHandle hDevice);
HWAPIErrCode USB_Receive(USBDevHandle hDevice, Uint8 *buf, Uint32 size);
HWAPIErrCode USB_Send (USBDevHandle hDevice, Uint8 *buf, Uint32 size);



#endif
