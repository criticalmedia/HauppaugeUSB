#ifndef __MCHIP_H_
#define __MCHIP_H_

#include "log.h"
#include "USBif.h"
#include "baseif.h"
#include "winwrap.h"

#include "FX2Device.h"

#include "mchip_defines.h"

#include "HapiBaseType.h"
#include "Hwapi.h"

#define ASSERT(V)

// BKV structure
typedef DRAM_BKV_CONFIG  MCHIP_DRAM_BKV;

class USBBootMChip_t {
public:
	FX2Device_t &fx2;
	USBBootMChip_t(FX2Device_t &_fx2);
	~USBBootMChip_t();

public:
    VOID lock();
    VOID unlock();
private:
    wrapMutex_t _mutex;
public:
    VOID lockBus();
    VOID unlockBus();
private:
    wrapMutex_t _mutexBus;

//mchip_base
public:
	BOOL UsbEEpSetAddr(BYTE addr);
	BOOL UsbEEpReadBytes(WORD addr, BYTE len, BYTE *data);
	BOOL UsbSetClk(BYTE clk);
	BOOL UsbSetPortDir(BYTE portNum, BYTE dir);
	BOOL UsbSetPortState(BYTE portNum, BYTE state);
	BOOL UsbGetPortState(BYTE portNum, BYTE * state);
	BOOL UsbGetPortDir(BYTE portNum, BYTE * dir);
	BOOL UsbSetWFMode(BYTE mode);
	BOOL UsbSetWFRW(BYTE read, BYTE write);
	BOOL UsbParOut(char * data, DWORD len);
	void UsbSetOutputLen(DWORD len, DWORD loop);
	BOOL UsbParOutHighSpeed(char * data, DWORD len);
	BOOL UsbParIn(char * data, DWORD len);
	void UsbSetInputLen(DWORD len, DWORD loop);
	BOOL UsbParInHighSpeed(char * data, DWORD len);

	DWORD UsbReadWrite(DWORD fRead, const BYTE * setupdat, void* pBuffer,
             WORD wBufferSize, DWORD * pdwBytesTransferred, DWORD dwTimeout);
	DWORD UsbReadWriteBulk(DWORD fRead, void* pBuffer,
             WORD wBufferSize, DWORD * pdwBytesTransferred, DWORD dwTimeout);
	void UsbDebug();

#define USB_ERR_LIMIT 4
	Boolean hadUsbError(const char *function);
	VOID setUsbError(const char *function, int line);
	VOID resetUsbError();
	VOID resetUsbPipes();

	DWORD getBling_Options() {return 0;}
	void  resetBling_Options() {}
	NTSTATUS resetCs5340() {return STATUS_SUCCESS;}

protected:
	DWORD prevOutLen; //=0
	DWORD maxSBP0Blocks;
	int statusErr;
	int statusCnt;
	BYTE _lastWFMode; //stores last used WAVEFORM_MODE
#if DBG
	BYTE	sav_port_state[10];
#endif

public:
	DWORD    getSBP0Blocks() const { return maxSBP0Blocks; }
	void     setSBP0Blocks(DWORD val) { maxSBP0Blocks = val; }
	BOOL	UsbForceWFMode(BYTE mode);
	void    resetWFMode() { _lastWFMode = 0xFF; prevOutLen=0; } //0xFF is an unknown WAVEFORM_MODE
	BYTE	gSbpFreq;
private:
	DWORD	_SBPtimeout; //usually 150-1100ms; depends on if Encoder running, and streaming rate
public:
    VOID	setSBPtimeout(DWORD timeout) { _SBPtimeout = timeout; }

//#define MCHIP_BINARY_H
public:
	Boolean MCHIP_Binary_LoadSPARC(Uint32 base, Uint32 entry, const Uint8* bin, Uint32 size, Boolean use_sbp);
	Boolean MCHIP_Binary_LoadMIPS(Uint32 base, Uint32 entry, const Uint8* bin, Uint32 size, Boolean use_sbp);
	Boolean MCHIP_Binary_BootSystemSPARC(void);
	Boolean MCHIP_Binary_BootVideoSPARC(void);
	Boolean MCHIP_Binary_BootMIPS(void);
	// zero DRAM from 0x00000000--size
	Boolean MCHIP_Binary_ZeroDRAM(Uint32 size);
	Boolean prv_load_bin(const char *filename, Uint8** bin, Uint32* size);
private:
	Boolean prv_sbp0_init(void);
	Boolean prv_sbp1_init(void);
	Boolean prv_sbp0_write(Uint32 addr, const Uint8* data, Uint32 size);
public:
	Boolean prv_sbp1_read(Uint32 addr, const Uint8* data, Uint32 size);



//#define MCHIP_DRAM_BKV_H
public:
	Boolean MCHIP_DRAM_BKV_Init(const MCHIP_DRAM_BKV* bkv);

//#define MCHIP_GPIO_H
public:
	// get GPIOExtConfig register address and bit offset for configuring GPIOExtN
	void MCHIP_GPIO_Get_GPIOExtConfig(Uint8 gpio, Uint32* addr, Uint8* bit);
	// get GPIOExtValue register address and bit offset for setting GPIOExtN 
	void MCHIP_GPIO_Get_GPIOExtValue(Uint8 gpio, Uint32* addr, Uint8* bit);
	// configure GPIOx on MCHIP to output selected value
	Boolean MCHIP_GPIOx_Configure(Boolean value);
	// set GPIOx on MCHIP to output selected value
	Boolean MCHIP_GPIOx_Set(Boolean value);
	// read GPIOx on Cypress
	Boolean MCHIP_GPIOx_Read(Boolean* value);

//#define MCHIP_HOST_RW_H
public:
	// select host port
	Boolean MCHIP_Host_Select(void);
	// read/write 16-bit host register, or 2x16-bit host registers
	Boolean MCHIP_Host_Read16(Uint8 addr, Uint16* data);
	Boolean MCHIP_Host_Write16(Uint8 addr, Uint16 data);
	Boolean MCHIP_Host_Read32(Uint8 addr, Uint32* data);
	Boolean MCHIP_Host_Write32(Uint8 addr, Uint32 data);
	// read/write 32-bit CBus register / DRAM
	// handles endianism conversion
	Boolean MCHIP_Read32(Uint32 addr, Uint32* data);
	Boolean MCHIP_Write32(Uint32 addr, Uint32 data);
	// read/write DRAM block
	// no endianism conversion
	Boolean MCHIP_ReadBlock(Uint32 addr, Uint8* data, Uint32 size);
	Boolean MCHIP_WriteBlock(Uint32 addr, const Uint8* data, Uint32 size);
	

//#define MCHIP_LED_H
public:
	// configure LED on MCHIP to selected value, TRUE=on FALSE=off
	//Boolean MCHIP_LED_Configure(Boolean value);
	Boolean MCHIP_LED_Configure(Uint8 gpio, Boolean value);
	// set LED on MCHIP to selected value, TRUE=on FALSE=off
	//Boolean MCHIP_LED_Set(Boolean value);
	Boolean MCHIP_LED_Set(Uint8 gpio, Boolean value);
	Boolean MCHIP_LED_Get(Uint8 gpio);

//#define MCHIP_MEMTOMEM_H
public:
	Boolean MCHIP_MemToMem_Copy(Uint32 source, Uint32 dest, Uint32 size);
	

//#define MCHIP_PORT_A_H
public:
	Boolean MCHIP_PortA_Init(void);
	Boolean MCHIP_PortA_Get_MCHIP_GPIOx(Boolean* value);
	Boolean MCHIP_PortA_Set_HST_SELECT_L(Boolean value);
	Boolean MCHIP_PortA_Set_MCHIP_RESET_L(Boolean value);
	Boolean MCHIP_PortA_Set_POWER_ENABLE_H(Boolean value);
	Boolean MCHIP_PortA_Set_HST_ADR_RDWR_L(Uint8 addr, Boolean rdwr);

	Boolean MCHIP_Reset_Cypress();
private:
	Uint8 prv_port_a;

//#define MCHIP_SBP_RW_H
public:
	// select SBP port
	Boolean MCHIP_SBP_Select(void);
	// write block to SBP0
	Boolean MCHIP_SBP0_Write(const Uint8* data, Uint32 size);
	// read block from SBP1
	Boolean MCHIP_SBP1_Read(Uint8* data, Uint32 size);
	Uint8 getCurSbpFreq();

//#define MCHIP_TEST_H
public:
	// host read/write
	Boolean MCHIP_Test_Host_16(void);
	Boolean MCHIP_Test_Host_32(void);
#if 0
	// DRAM read/write
	//	Boolean MCHIP_Test_DRAM_Simple(void);
	Boolean MCHIP_Test_DRAM_32(void);
	Boolean MCHIP_Test_DRAM_Block(void);
	Boolean MCHIP_Test_DRAM_MemToMem(void);
	// SBP0 write
	Boolean MCHIP_Test_SBP0_Write8(void);
	Boolean MCHIP_Test_SBP0_WriteBlock(void);
	Boolean MCHIP_Test_SBP0_WriteBlockMulti(void);
	Boolean MCHIP_Test_SBP0_WritePerf(void);
	// SBP1 read
	Boolean MCHIP_Test_SBP1_Read8(void);
	Boolean MCHIP_Test_SBP1_ReadBlock(void);
	Boolean MCHIP_Test_SBP1_ReadBlockMulti(void);
	Boolean MCHIP_Test_SBP1_ReadPerf(void);
	// SBP0 write + SBP1 read
	Boolean MCHIP_Test_SBP01_WriteReadBlock(void);
	// SBP0 write + SBP1 read + host access
	Boolean MCHIP_Test_SBP01Host_WriteReadBlock(void);
	// SBP0 write + SBP1 read performance
	Boolean MCHIP_Test_SBP01_WriteReadPerf(void);
	// image boot SPARC from .vxWorks
	Boolean MCHIP_Test_Image(Boolean use_sbp);
	// binary boot SPARC and MIPS from .bin
	Boolean MCHIP_Test_Binary(Boolean use_sbp);
#endif
	// GPIOx input
	Boolean MCHIP_Test_GPIOx(void);
	//Boolean MCHIP_Test_LED();
	Boolean MCHIP_Test_LED(Uint8 gpio);
};

#endif
