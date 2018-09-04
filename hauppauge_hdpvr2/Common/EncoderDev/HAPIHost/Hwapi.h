//=============================================================================
//  File Name: hwapi.h
//
//  Copyright 2009 Magnum Semiconductor Inc. All rights reserved.
//
//  Description:
//      HAPI function definitions.
//
//  Modification History:
//      $Id: $
//      $Log: $
//
//=============================================================================
#ifndef HWAPI_H
#define HWAPI_H

#include "HapiBaseType.h"
#include "registryif.h"

typedef enum _HWAPIErrCode
{
	HWAPI_Success,
	HWAPI_Fail,
}HWAPIErrCode;

typedef struct _DRAM_BKV_CONFIG
{
    Uint32 mem_pll;
    Uint32 left_ls_read_gate_guess;
    Uint32 left_ms_read_gate_guess;
    Uint32 right_ls_read_gate_guess;
    Uint32 right_ms_read_gate_guess;
    Uint32 dram_mr;
    Uint32 dram_emr;
    Uint32 mem_intf_timing_ctrl;
    Uint32 mem_intf_add_config;
    Uint32 mem_intf_rfsh_ctrl;
    Uint32 mem_intf_left_cmd_ctrl1;
    Uint32 sys_pll;
    Uint32 mem_intf_left_cmd_ctrl2;
    Uint32 mem_intf_right_cmd_ctrl1;
    Uint32 mem_intf_right_cmd_ctrl2;
    Uint32 mem_intf_left_data_ctrl;
    Uint32 mem_intf_right_data_ctrl;
    Uint32 left_ls_read_eye_guess;
    Uint32 left_ms_read_eye_guess;
    Uint32 right_ls_read_eye_guess;
    Uint32 sys_pll_2;                   
    Uint32 right_ms_read_eye_guess;
    Uint32 mem_intf_dll1;
    Uint32 mem_intf_dll2;
    Uint32 mem_intf_left_ls_dll2;
    Uint32 mem_intf_left_ms_dll2;
    Uint32 mem_intf_right_ls_dll2;
    Uint32 mem_intf_right_ms_dll2;
    Uint32 mem_intf_left_ls_ditrm;
    Uint32 mem_intf_left_ms_ditrm;
    Uint32 mem_intf_right_ls_ditrm;
    Uint32 mem_intf_right_ms_ditrm;
    Uint32 mempll_workaround_attempt;
    Uint32 mempll_workaround_wait;
    Uint32 left_itm_read_delay;
    Uint32 right_itm_read_delay;
    Uint32 vp_boot_mode;
    Uint32 MCHIP_a2_gate_sweep;
    Uint32 MCHIP_a2_itm_sweep;
    Uint32 MCHIP_a2_dq_sweep;
    Uint32 MCHIP_a2_dqs_sweep;
    Uint32 memtest_mask;
    Uint32 reserved1;
    Uint32 reserved2;
    Uint32 reserved3;
    Uint32 reserved4;
    Uint32 otp_config_flash;
}DRAM_BKV_CONFIG;

typedef struct _FIRMWARE_FILE
{
	const char *mipsFileName;
	Uint32 mipsBaseAddr;
	Uint32 mipsEntryAddr;
	const char *sparcFileName;
	Uint32 sparcBaseAddr;
	Uint32 sparcEntryAddr;
}FIRMWARE_FILE;

typedef enum _CommBusType
{
	CommBusType_USB = 0,
	CommBusType_UART,
	CommBusType_PCI,
	CommBusType_HostBus,
    CommBusType_MAX
}CommBusType;

#define DATA_PACKET_LEN 32

typedef enum _NAMEPLATE_IDENTIFIER
{
    NI_COMPANY = 1,
    NI_BOARD_ID,
    NI_HDR_EV,
    NI_PCB_SKU,
    NI_PCB_SN,
    NI_MAIN_CPU,
    NI_ADDI_CPUS,
    NI_ADDI_CPUS_TYPE,
    NI_CHIP_REV,
    NI_DRAM,
    NI_CORE_VOLTAGE,
    NI_MAX_MIPS_FREQ,
    NI_MAX_SPARC_FREQ,
    NI_DRAM_FREQ,
    NI_DRAM_SIZE,
    NI_ECO,
    NI_MAX
}NAMEPLATE_IDENTIFIER;

typedef enum {
    UART_BAUD_RATE_2400   = 2400,
    UART_BAUD_RATE_4800   = 4800,
    UART_BAUD_RATE_9600   = 9600,
    UART_BAUD_RATE_19200  = 19200,
    UART_BAUD_RATE_38400  = 38400,
    UART_BAUD_RATE_115200 = 115200,
}UART_BAUD_RATE;

typedef enum {
    UART_DATA_BITS_5 = 5,
    UART_DATA_BITS_6 = 6,
    UART_DATA_BITS_7 =7,
    UART_DATA_BITS_8 =8,
}UART_DATA_BITS;

typedef enum {
    UART_PARITY_NONE = 0,
    UART_PARITY_ODD  = 1,
    UART_PARITY_EVEN = 2,
}UART_PARITY_CHECK;

typedef enum {
    UART_STOP_BITS_1   = 0,
    UART_STOP_BITS_1_5 = 1,
    UART_STOP_BITS_2   = 2,
}UART_STOP_BITS;

typedef enum {
    UART_FLOW_NONE,
    UART_FLOW_RTSCTS,
    UART_FLOW_XONXOFF,
    UART_FLOW_RTSCTS_XONXOFF,
}UART_FLOW_CONTROL;


#define SBP_FREQ_48 0
#define SBP_FREQ_30 1

#define DXT_CLK_48 0
#define DXT_CLK_24 1

typedef struct _BOARD_INFO
{
    char company[12+1];
	char boardID[12+1];
	char hardwareRev[12+1];
	Uint16 pcbSKU;//char PCBSKU[2];
    Uint16 pcbSN;//char PCBSN[2];
    char mainCPU[12+1];
    Uint16 additionalCPUs;//char additionalCPUs[2];
    char additionalCPUsType[12+1];
    char magnumChipRev [12+1];
    char dram[16+1];
    Uint16 coreVoltage;
    Uint16 maxMipsFreq;
    Uint16 maxSparcFreq;
    Uint16 dramFreq;
    Uint16 dramSize;    
    Uint8 eco[16+1];
    Uint8 dxt_clk;
}BOARD_INFO;

class USBBootMChip_t;

typedef struct {
	USBBootMChip_t *p_mchip;
    Uint8 sbp_freq;
    Uint8 dxt_clk;
    int reserve;
}usb_config_st;

typedef union _hw_port_config{
    usb_config_st        usb_port_config;
}hw_port_config;
typedef void * DeviceHandle;

typedef DeviceHandle (*HWAPI_CommBusInit) (Uint32 ChipID, hw_port_config *pHwPortConfig);
typedef HWAPIErrCode (*HWAPI_GetBoardInfo) (DeviceHandle hDevice,BOARD_INFO *pBoardInfo);
typedef HWAPIErrCode (*HWAPI_BoardInit) (DeviceHandle hDevice, DRAM_BKV_CONFIG *bkvConfig);
typedef HWAPIErrCode (*HWAPI_BinaryDownload) (DeviceHandle hDevice, FIRMWARE_FILE *Binary);
typedef HWAPIErrCode (*HWAPI_SystemBootup) (DeviceHandle hDevice);
typedef HWAPIErrCode (*HWAPI_Exit) (DeviceHandle hDevice);
typedef HWAPIErrCode (*HWAPI_Receive)(DeviceHandle hDevice, Uint8 *buf, Uint32 size);
typedef HWAPIErrCode (*HWAPI_Send) (DeviceHandle hDevice, Uint8 *buf, Uint32 size);

typedef struct _HWAPI_FUNCTIONS
{
	HWAPI_CommBusInit		commBusInit;
	HWAPI_GetBoardInfo		getBoardInfo;
	HWAPI_BoardInit			boardInit;
	HWAPI_BinaryDownload	binaryDownload;
	HWAPI_SystemBootup		systemBootup;
	HWAPI_Exit				exit;
	HWAPI_Receive			receive;
	HWAPI_Send				send;
}HWAPI_FUNCTIONS;

typedef struct _HWAPI_STRUCT
{
	DeviceHandle device;
	CommBusType busType;
	HWAPI_FUNCTIONS	IF;
}HWAPI_STRUCT;

typedef HWAPI_STRUCT* HWAPIHandle;

#endif
