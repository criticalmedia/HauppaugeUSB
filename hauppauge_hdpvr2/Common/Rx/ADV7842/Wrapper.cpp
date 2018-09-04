/**********************************************************************************************
*                                                                                             *
* Copyright (c) 2012 Analog Devices, Inc.  All Rights Reserved.                               *
* This software is proprietary and confidential to Analog Devices, Inc. and its licensors.    *
*                                                                                             *
***********************************************************************************************/
#include "wrapper.h"

#include <string.h>
#include <stdarg.h>
#include "log.h"
#include "baseif.h"
#include "I2Cif.h"

#if RX_USER_INIT
CONSTANT UCHAR UserRxRegInitTable[] = {0};
CONSTANT UCHAR UserRxFieldInitTable[] = {0};
#endif

UINT32 AtvDummy;

//#define TRACE(M, ...) WRAPLOG(WRAPLOGL_DEBUG, M, ##__VA_ARGS__)
#define TRACE(M, ...)

void DBG_Printf(const char *data, ...)
{
	va_list args;
	va_start(args, data);
	WRAPLOGV(WRAPLOGL_DEBUG, data, args);
	va_end(args);
}

/*===========================================================================
 * Get the elapsed time in milliseconds from a defined starting point
 *
 * Entry:   StartCount  = Time in milliseconds at the sarting point
 *          CurrMsCount = Pointer to receive the current time in milliseconds
 *                        Can be set to NULL if not needed
 *
 * Return:  Time (in milliseconds) that elapsed since StartCount.
 *          This function can not return elapsed time over 65 seconds
 *
 *==========================================================================*/
UINT32 ATV_GetElapsedMs (UINT32 StartCount, UINT32 *CurrMsCount)
{
	UINT32 t = wrapGetTime_ms();
	if(CurrMsCount) *CurrMsCount = t;
	return t - StartCount;
}

/*===========================================================================
 * Return the current time in milliseconds. 
 * If the current time is 0, return 0xFFFFFFFF
 *
 *
 *==========================================================================*/
UINT32 ATV_GetMsCountNZ (void)
{
	UINT32 t = wrapGetTime_ms();
	if(t == 0) t = 0xFFFFFFFF;
	return t;
}

/*============================================================================
 * Read up to 8-bit field from a single 8-bit register
 *              ________   
 * Example     |___***__|  Mask = 0x1C     BitPos = 2
 *
 *
 * Entry:   DevAddr = Device Address
 *          RegAddr = 8-bit register address
 *          Mask    = Field mask
 *          BitPos  = Field LSBit position in the register (0-7)
 *
 * Return:  Field value in the LSBits of the return value
 *
 *===========================================================================*/
UCHAR ATV_I2CReadField8 (UCHAR DevAddr, UCHAR RegAddr, UCHAR Mask, 
                         UCHAR BitPos)
{
	TRACE("ATV_I2CReadField8()");
	UCHAR v;
	I2CWrapper_writeRead(DevAddr, &RegAddr, 1, &v, 1);
	return (v & Mask) >> BitPos;
}

/*============================================================================
 * Write up to 8-bit field to a single 8-bit register
 *              ________   
 * Example     |___****_|  Mask = 0x1E     BitPos = 1
 *
 * Entry:   DevAddr = Device Address
 *          RegAddr = 8-bit register address
 *          Mask    = Field mask
 *          BitPos  = Field LSBit position in the register (0-7)
 *                    Set to 0 if FieldVal is in correct position of the reg
 *          FieldVal= Value (in the LSBits) of the field to be written
 *                    If FieldVal is already in the correct position (i.e., 
 *                    does not need to be shifted,) set BitPos to 0
 *
 * Return:  None
 *
 *===========================================================================*/
void ATV_I2CWriteField8 (UCHAR DevAddr, UCHAR RegAddr, UCHAR Mask, 
                         UCHAR BitPos, UCHAR FieldVal)
{
	TRACE("ATV_I2CWriteField8()");
	UCHAR b[2];
	b[0] = RegAddr;
	I2CWrapper_writeRead(DevAddr, &RegAddr, 1, &b[1], 1);
	b[1] &= ~Mask;
	b[1] |= (FieldVal << BitPos) & Mask;
	I2CWrapper_write(DevAddr, b, 2);
}

/*============================================================================
 * Read up to 32-bit field from two or more consecutive 8-bit registers in
 * Big Endian format
 *
 *                   ________
 * Start Reg Addr-> |     ***|  MSbits          MsbMask = 0x07
 *                  |********|  Middle bits
 *                  |********|  Middle bits
 *                  |********|  Middle bits
 * End Reg Addr---> |**______|  LSbits          LsbMask = 0xC0, LsbPos = 6
 *                                              FldSpan = 5
 *
 * Entry:   DevAddr = Device Address
 *          RegAddr = Starting 8-bit register address
 *          MsbMask = Mask for MSbits
 *          LsbMask = Mask for LSbits
 *          LsbPos  = LSbit position (0-7)
 *          FldSpan = Number of consecutive registers containing field bits
 *                    (Maximum 5 registers)
 *
 * Return:  Field value in the LSBits of the return value
 *
 *===========================================================================*/
UINT32 ATV_I2CReadField32 (UCHAR DevAddr, UCHAR RegAddr, UCHAR MsbMask, 
                           UCHAR LsbMask, UCHAR LsbPos, UCHAR FldSpan)
{
	TRACE("ATV_I2CReadField32()");
	UINT64 v = 0;
	I2CWrapper_writeRead(DevAddr, &RegAddr, 1, ((UCHAR*)&v) + 5 - FldSpan, FldSpan);
	v = swapBytes40(v);
	((UCHAR*)&v)[0] &= LsbMask;
	((UCHAR*)&v)[FldSpan - 1] &= MsbMask;
	v >>= LsbPos;
	return v;
}

/*============================================================================
 * Read up to 32-bit field from two or more consecutive 8-bit registers in
 * Little Endian format
 *
 *                   ________  
 * Start Reg Addr-> |***     |  LSbits          LsbMask = 0xE0, LsbPos = 5
 *                  |********|  Middle bits
 *                  |********|  Middle bits
 *                  |********|  Middle bits
 * End Reg Addr---> |______**|  MSbits          MsbMask = 0x03
 *                                              FldSpan = 5
 *
 * Entry:   DevAddr = Device Address
 *          RegAddr = Starting 8-bit register address
 *          MsbMask = Mask for MSbits
 *          LsbMask = Mask for LSbits
 *          LsbPos  = LSbit position (0-7)
 *          FldSpan = Number of consecutive registers containing field bits
 *                    (Maximum 5 registers)
 *
 * Return:  Field value in the LSBits of the return value
 *
 *===========================================================================*/
UINT32 ATV_I2CReadField32LE (UCHAR DevAddr, UCHAR RegAddr, UCHAR MsbMask, 
                             UCHAR LsbMask, UCHAR LsbPos, UCHAR FldSpan)
{
	TRACE("ATV_I2CReadField32LE()");
	UINT64 v = 0;
	I2CWrapper_writeRead(DevAddr, &RegAddr, 1, (UCHAR*)&v, FldSpan);
	((UCHAR*)&v)[0] &= LsbMask;
	((UCHAR*)&v)[FldSpan - 1] &= MsbMask;
	v >>= LsbPos;
	return v;
}

/*============================================================================
 * Write up to 32-bit field to two or more consecutive 8-bit registers in
 * Big Endian format
 *                   ________
 * Start Reg Addr-> |   *****|  MSbits          MsbMask = 0x1F
 *                  |********|  Middle bits
 * End Reg Addr---> |******__|  LSbits          LsbMask = 0xFC, LsbPos = 2
 *                                              FldSpan = 3
 * Entry:   DevAddr = Device Address
 *          RegAddr = Starting 8-bit register address
 *          MsbMask = Mask for MSbits
 *          LsbMask = Mask for LSbits
 *          LsbPos  = LSbit position (0-7)
 *          FldSpan = Number of consecutive registers containing field bits
 *          Val     = Field value (in the LSBits) to be written
 *
 * Return:  None
 *
 *
 *===========================================================================*/
void ATV_I2CWriteField32 (UCHAR DevAddr, UCHAR RegAddr, UCHAR MsbMask, 
                     UCHAR LsbMask, UCHAR LsbPos, UCHAR FldSpan, UINT32 Val)
{
	TRACE("ATV_I2CWriteField32()");
	UINT64 v = 0;
	UINT64 vn;
	UCHAR b[6];
	I2CWrapper_writeRead(DevAddr, &RegAddr, 1, (UCHAR*)&v, FldSpan);
	vn = Val;
	vn <<= LsbPos + (5 - FldSpan) * 8;
	vn = swapBytes40(vn);
	((UCHAR*)&vn)[0] &= MsbMask;
	((UCHAR*)&vn)[0] |= ((UCHAR*)&v)[0] & ~MsbMask;
	((UCHAR*)&vn)[FldSpan - 1] &= LsbMask;
	((UCHAR*)&vn)[FldSpan - 1] |= ((UCHAR*)&v)[FldSpan - 1] & ~LsbMask;
	b[0] = RegAddr;
	memcpy(b + 1, &vn, FldSpan);
	I2CWrapper_write(DevAddr, b, FldSpan + 1);
}

/*===========================================================================
 * Modify multiple registers fields from a user-supllied table
 *
 * Entry:   Table : A pointer to the table of writes that must be performed
 *                  Table[] = { 
 *                              DevAddr0, RegOffset0, Mask0, Value0,
 *                              DevAddr1, RegOffset1, Mask1, Value1,
 *                              DevAddr2, RegOffset2, Mask2, Value2,
 *                              ...
 *                              DevAddrN, RegOffsetN, MaskN, ValueN,
 *                              EndVal
 *                             }
 *          EndVal : The last value in the table
 *
 * Return:  None
 *
 *==========================================================================*/
void ATV_I2CWriteFields (const UCHAR *Table, UCHAR EndVal)
{
	TRACE("ATV_I2CWriteFields()");
	unsigned int i;
	for(i = 0; Table[i] != EndVal; i += 4) {
		ATV_I2CWriteField8(Table[i], Table[i+1], Table[i+2], 0, Table[i+3]);
	}
}

/*============================================================================
 * Write up to 32-bit field to two or more consecutive 8-bit registers in
 * Little Endian format
 *                   ________
 * Start Reg Addr-> |*       |  LSbits          LsbMask = 0x80, LsbPos = 7
 *                  |********|  Middle bits
 *                  |********|  Middle bits
 * End Reg Addr---> |********|  MSbits          MsbMask = 0xFF
 *                                              FldSpan = 4
 * Entry:   DevAddr = Device Address
 *          RegAddr = Starting 8-bit register address
 *          MsbMask = Mask for MSbits
 *          LsbMask = Mask for LSbits
 *          LsbPos  = LSbit position (0-7)
 *          FldSpan = Number of consecutive registers containing field bits
 *          Val     = Field value (in the LSBits) to be written
 *
 * Return:  None
 *
 *
 *===========================================================================*/
void ATV_I2CWriteField32LE (UCHAR DevAddr, UCHAR RegAddr, UCHAR MsbMask, 
                     UCHAR LsbMask, UCHAR LsbPos, UCHAR FldSpan, UINT32 Val)
{
	TRACE("ATV_I2CWriteField32LE()");
	UINT64 v = 0;
	UINT64 vn;
	UCHAR b[6];
	I2CWrapper_writeRead(DevAddr, &RegAddr, 1, (UCHAR*)&v, FldSpan);
	vn = Val;
	vn <<= LsbPos;
	((UCHAR*)&vn)[0] &= LsbMask;
	((UCHAR*)&vn)[0] |= ((UCHAR*)&v)[0] & ~LsbMask;
	((UCHAR*)&vn)[FldSpan - 1] &= MsbMask;
	((UCHAR*)&vn)[FldSpan - 1] |= ((UCHAR*)&v)[FldSpan - 1] & ~MsbMask;
	b[0] = RegAddr;
	memcpy(b + 1, &vn, FldSpan);
	I2CWrapper_write(DevAddr, b, FldSpan + 1);
}

/*============================================================================
 * Write up to 32-bit field to one or more non-consecutive 8-bit registers 
 * in Big or Little Endian format
 *                                              
 *           ________       Mask    LShift(LE)  LShift(BE)
 * Reg 0    | ****** |      0x7E   -1           3
 *          .        .
 * Reg 1    |   ***  |      0x1C    4          -1
 *          .        .
 * Reg 2    |____*___|      0x08    6          -3
 *
 *
 * Entry:   DevAddr = Device Address
 *          FldInfo = Pointer to array of field-inofrmation structures
 *                    The LShift member of the structure is the absolute left 
 *                    shift of each register field bits (in 2's complement) as
 *                    illustrated in the above example for both Little and Big 
 *                    Endian cases. An absolute right-shift is indicated by 
 *                    a negative value for LShift.
 *          FldSpan = Number of entries in FldInfo
 *          Val     = Field value (in the LSBits) to be written
 *
 * Return:  None
 *
 *===========================================================================*/
void ATV_I2CWriteRandField32 (UCHAR DevAddr, I2C_FIELD_INFO *FldInfo, 
                              UCHAR FldSpan, UINT32 Val)
{
	WRAPLOG(WRAPLOGL_ERROR, "ATV_I2CWriteRandField32(): ???");
}

/*===========================================================================
 * Perform multiple I2C register writes from a user-supplied Table
 *
 * Entry:   Table : A pointer to the table of writes that must be performed
 *                  Table[] = { 
 *                              DevAddr0, RegOffset0, Value0,
 *                              DevAddr1, RegOffset1, Value1,
 *                              DevAddr2, RegOffset2, Value2,
 *                              ...
 *                              DevAddrN, RegOffsetN, ValueN,
 *                              EndVal
 *                             }
 *          EndVal : The last value in the table
 *
 * Return:  None
 *
 *==========================================================================*/
void ATV_I2CWriteTable (const UCHAR *Table, UCHAR EndVal)
{
	TRACE("ATV_I2CWriteTable()");
	unsigned int i;
	for(i = 0; Table[i] != EndVal; i += 3) {
		ATV_I2CWriteField8(Table[i], Table[i+1], 0xFF, 0, Table[i+2]);
	}
}

/*===========================================================================
 * Look for UCHAR Value in Table with Step increments
 *
 * Return:  Offset of matching value or end value
 *
 *==========================================================================*/
UINT16 ATV_LookupValue8 (const UCHAR *Table, UCHAR Value, UCHAR EndVal, UINT16 Step)
{
	UINT16 i;
	for(i = 0; (Table[i] != EndVal) && (Table[i] != Value); i += Step);
	return i;
}

/*===========================================================================
 * Print current system time
 *
 * Entry:   Gran    = 0  for ms
 *                    1  for sec:ms
 *                    2  for min:sec:ms
 *          PostFix = Postfix string
 *
 *==========================================================================*/
void ATV_PrintTime (char *Prefix, UCHAR Gran, char *Postfix)
{
}

/*===========================================================================
 *
 *==========================================================================*/
void HAL_DelayMs (UINT16 Counter)
{
	WaitMilliSec(Counter);
}

/*===========================================================================
 *
 *==========================================================================*/
UINT16 HAL_I2CReadBlock (UCHAR Dev, UCHAR Reg, UCHAR *Data, UINT16 NofBytes)
{
	TRACE("HAL_I2CReadBlock()");
	const unsigned blen = 32;
	unsigned i = 0;
	for(; i < NofBytes; i += blen) {
		unsigned rlen = NofBytes - i;
		unsigned len = (rlen > blen) ? blen : rlen;
		UCHAR r = Reg + i;
		I2CWrapper_writeRead(Dev, &r, 1, Data + i, len);
	}
	return 1;
}

/*===========================================================================
 *
 *==========================================================================*/
UINT16  HAL_I2CWriteBlock (UCHAR Dev, UCHAR Reg, const UCHAR *Data, UINT16 NumberBytes)
{
	TRACE("HAL_I2CWriteBlock()");
	const unsigned blen = 32;
	unsigned i = 0;
	for(; i < NumberBytes; i += blen) {
		unsigned rlen = NumberBytes - i;
		unsigned len = (rlen > blen) ? blen : rlen;
		UCHAR b[len + 1];
		b[0] = Reg + i;
		memcpy(b + 1, Data + i, len);
		I2CWrapper_write(Dev, b, len + 1);
	}
	return 1;
}

/*===========================================================================
 *
 *==========================================================================*/
UCHAR HAL_I2CReadByte (UCHAR Dev, UCHAR Reg, UCHAR *Data)
{
	TRACE("HAL_I2CReadByte()");
	I2CWrapper_writeRead(Dev, &Reg, 1, Data, 1);
	return 1;
}

/*===========================================================================
 *
 *==========================================================================*/
UCHAR HAL_I2CWriteByte (UCHAR Dev, UCHAR Reg, UCHAR Data)
{
	TRACE("HAL_I2CWriteByte()");
	UCHAR b[2];
	b[0] = Reg;
	b[1] = Data;
	I2CWrapper_write(Dev, b, 2);
	return 1;
}

UCHAR HAL_SetRxChipSelect(UCHAR DevIdx)
{
    return 1;
}

/**
 * Wait for passed number of milli-seconds
 */
void WaitMilliSec(unsigned int msec)
{
	wrapSleep_ms(msec);
}

/*============================================================================
 * Reset CEC controller
 * 
 * Entry:   None
 * 
 * Return:  ATVERR_OK
 * 
 *===========================================================================*/
ATV_ERR CEC_Reset (void)
{
	return ATVERR_OK;
}

/*============================================================================
 * Enable/Disable CEC controller
 * 
 * Entry:   Enable = TRUE to enable CEC controller
 *                   FALSE to disable
 * 
 * Return:  ATVERR_OK
 * 
 *===========================================================================*/
ATV_ERR CEC_Enable (BOOL Enable)
{
	return ATVERR_OK;
}

/*============================================================================
 * Set the logical address for one of 3 logical devices
 * 
 * Entry:   LogAddr = Logical address for the device
 *          DevId   = The device to set the logical address to. (0, 1 or 2)
 *          Enable  = TRUE to enable the logical device
 *                    FALSE to disable the logical device
 * 
 * Return:  ATVERR_OK
 *          ATVERR_INV_PARM if DevId is larger than 2
 * 
 *===========================================================================*/
ATV_ERR CEC_SetLogicalAddr (UCHAR LogAddr, UCHAR DevId, BOOL Enable)
{
	return ATVERR_OK;
}

/*============================================================================
 * Send message to CEC
 * 
 * Entry:   MsgPtr = Pointer to the message to be sent
 *          MsgLen
 * 
 * Return:  ATVERR_OK
 *          ATVERR_FAILED if CEC controller is busy
 *          ATVERR_INV_PARM if MsgLen is larger than max message size
 * 
 *===========================================================================*/
ATV_ERR CEC_SendMessage (UCHAR *MsgPtr, UCHAR MsgLen)
{
	return ATVERR_OK;
}

/*============================================================================
 * Send message to CEC
 * 
 * Entry:   MsgPtr = Pointer to the message to be sent
 *          MsgLen
 * 
 * Return:  ATVERR_OK
 *          ATVERR_FAILED if CEC controller is busy
 *          ATVERR_INV_PARM if MsgLen is larger than max message size
 * 
 *===========================================================================*/
ATV_ERR CEC_SendMessageOut (void)
{
	return ATVERR_OK;
}

/*============================================================================
 * Resend last sent message to CEC
 * 
 * Entry:   None
 * 
 * Return:  ATVERR_OK
 *          ATVERR_FAILED if CEC controller is busy
 * 
 *===========================================================================*/
ATV_ERR CEC_ResendLastMessage (void)
{
	return ATVERR_OK;
}

/*============================================================================
 * Perform logical address allocation
 *
 * Entry:   LogAddrList = Pointer to a prioritized list of logical addresses 
 *                        that the device will try to obtain, terminated by
 *                        0xff.
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED if CEC is busy
 *          ATVERR_INV_PARM if LogAddrList is too long or contains no data
 * 
 * This function returns immediately. If a logical address slot is found,
 * the caller will be notified by the event ADI_EVENT_CEC_LOG_ADDR_ALLOC
 * 
 *===========================================================================*/
ATV_ERR CEC_AllocateLogAddr (UCHAR *LogAddrList)
{
	return ATVERR_OK;
}

/*============================================================================
 * List all active logical addresses in the system
 *
 * Entry:   UsrSrcLogAddr = The logical address of the initiator to be used in
 *                          the polling messages sent to get the list of 
 *                          logical addresses. Set to 0xff to use the 
 *                          destination logical address as the source
 * 
 * Return:  ATVERR_OK
 *          ATVERR_FAILED if CEC is busy
 * 
 * This function returns immediately. The list of active logical addresses 
 * will be provided by the event ADI_EVENT_CEC_LOG_ADDR_LIST
 * 
 *===========================================================================*/
ATV_ERR CEC_GetLogAddrList (UCHAR SrcLogAddr)
{
	return ATVERR_OK;
}

/*============================================================================
 *
 * Entry:   CecInts = CEC interrupts
 * 
 * Return:  None
 * 
 * 
 *===========================================================================*/
void CEC_Isr (CEC_INTERRUPTS *CecInts)
{
	
}
