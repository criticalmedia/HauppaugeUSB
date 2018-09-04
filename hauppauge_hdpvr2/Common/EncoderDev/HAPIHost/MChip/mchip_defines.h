//================================================================
//  File Name: Usb_defines.h
//
//  Copyright 2010 Magnum Semiconductor Inc.  All rights reserved.
//
//  Description:
//
//  Define all interface between Host and EZ-USB FX2 under Linux.
//
//  Modification History:
//
//================================================================

#ifndef __MCHIP_DEFINES_H_
#define __MCHIP_DEFINES_H_

#include "winwrap.h"
#include "HapiBaseType.h"

#define ASSERT(V)

#define USB_RW_MAXBYTES_PERTIME 32768//1024
//#define USB_RW_MAXBYTES_PERTIME 1024
//#define USB_RW_MAXBYTES_PERTIME 512
#define USB_IN_MAXBYTES_PERTIME (32768+512)
//#define USB_IN_MAXBYTES_PERTIME 512

#define EP0BUFF_SIZE    64
#define VR_UPLOAD       0xc0
#define VR_DOWNLOAD     0x40

typedef enum _VR_OPCODE
{
    VR_RAM = 0xA3,             // loads (uploads) external ram
    VR_PORT_SETTING,       // set port dir and state
    VR_WF_SETTING,           // set waveform mode and select waveform
    VR_INPACKETLEN,
    VR_OUTPACKETLEN,
    VR_DATA_TRANSFER,     // data transfer command
    VR_CPUCLK,
    VR_I2C,
    VR_DEBUG
}VR_OPCODE;

typedef enum _WF_OP
{
    WF_MODE = 0,
    WF_SETRW
}WF_OP;

typedef enum _WAVEFORM_MODE
{
    WF_HOST = 0,
    WF_SBP_48,
    WF_SBP_30
}WAVEFORM_MODE;



typedef enum _PORT_OP
{
    OP_SET_STATE = 0,
    OP_GET_STATE,
    OP_DIR,
	OP_GET_DIR
}PORT_OP;

typedef enum _USB_PORT
{
    USB_PORT_A = 0,
    USB_PORT_B,
    USB_PORT_C,
    USB_PORT_D,
    USB_PORT_E,
	REC_BUTTON,
	USB_CTL_PORTS
}USB_PORT;

typedef enum _CPU_CLK
{
    CLK_12_MHZ = 0,
    CLK_24_MHZ,
    CLK_48_MHZ
}CPU_CLK;

typedef enum _I2C_OP
{
    I2C_WRITE = 0,
    I2C_READ,
    I2C_SETADR
}I2C_OP;

typedef struct _Usb_Port_SetupDat
{
    BYTE reserved0;
    BYTE vrOpcode;
    BYTE portNum;
    BYTE portOp;
    BYTE portSetting;
    BYTE reserved5;
    BYTE reserved6;
    BYTE reserved7;
}Usb_Port_SetupDat;

typedef struct _Usb_WF_SetupDat
{
    BYTE reserved0;
    BYTE vrOpcode;
    BYTE wfOp;
    BYTE wfMode;
    BYTE wfRead;
    BYTE wfWrite;
    BYTE reserved6;
    BYTE reserved7;
}Usb_WF_SetupDat;

typedef struct _Usb_I2C_SetupDat
{
    BYTE reserved0;
    BYTE vrOpcode;
    BYTE vrOpType;
    BYTE i2cAdr;
    BYTE slaveAdrHi;
    BYTE slaveAdrLo;
    BYTE dataLen;
    BYTE reserved7;
}Usb_I2C_SetupDat;

#endif
