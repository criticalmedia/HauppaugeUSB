//=============================================================================
//  File Name: mchip_memtomem.c
//
//  Copyright 2009 Magnum Semiconductor Inc. All rights reserved.
//
//  Description:
//      MCHIP memory to memory copy using VIO horizontal scaler.
//
//  Modification History:
//      $Id: $
//      $Log: $
//
//=============================================================================

#include "mchip.h"

#ifndef DRIVER_BUILD
#define MCHIP_MEMTOMEM_TIMEOUT                100000        // msec
#else
#define MCHIP_MEMTOMEM_TIMEOUT                30 // *10msec/tick=300ms // WTF???
#endif

Boolean
USBBootMChip_t::
MCHIP_MemToMem_Copy(Uint32 source, Uint32 dest, Uint32 size)
{
    DbgLogInfo(("MCHIP_MemToMem_Copy(0x%x,0x%x,%d)\n", source, dest, size));
    DWORD begin = 0;
    Uint32 val32;

    // we are copying rows of 1024 bytes
    ASSERT((size % 0x400) == 0);
    // maximum number of rows is 0x7FF
    ASSERT((size / 0x400) < 0x800);

    // set source address
    // VIO_HorizontalRescaleSourceAddress
    if (!MCHIP_Write32(0xFFC40C30, source)) return FALSE;

    // set source row, column
    // VIO_HorizontalRescaleRowColumn
    if (!MCHIP_Write32(0xFFC40C34, 0x00000000)) return FALSE;

    // set unfiltered horizontal range for source pitch, horizontal size
    // VIO_HorizontalRescaleUnfilteredHorizontalRange
    if (!MCHIP_Write32(0xFFC40C38, (0x400 << 16) | 0x400)) return FALSE;

    // set destination address
    // VIO_HorizontalRescaleDestinationAddress
    if (!MCHIP_Write32(0xFFC40C40, dest)) return FALSE;

    // set destination row, column
    // VIO_HorizontalRescaleDesRowColumn
    if (!MCHIP_Write32(0xFFC40C50, 0x00000000)) return FALSE;

    // set filtered horizontal range for destination pitch
    // VIO_HorizontalRescaleFilteredHorizontalRange
    if (!MCHIP_Write32(0xFFC40C44, (0x400 << 16) | 0x400)) return FALSE;

    // set vertical range for source/destination vertical size
    // VIO_HorizontalRescaleVerticalRange
    if (!MCHIP_Write32(0xFFC40C3C, size / 0x400)) return FALSE;

    // begin memory-to-memory copy
    if (!MCHIP_Write32(0xFFC40000, (1 << 30) | (1 << 6))) return FALSE;     // Luma || GoR

    // wait for copy to end
	begin = wrapGetTicks_ms();
    for (;;)
    {
        if (!MCHIP_Read32(0xFFC40000, &val32)){
			DbgLogError(("MCHIP_MemToMem_Copy(): MCHIP_Read32(0xFFC40000,...) failed\n"));
			return FALSE;
		}

        // GoR = 0?
        if (!(val32 & (1 << 6))) break;

		if (wrapGetTicks_ms()-begin > MCHIP_MEMTOMEM_TIMEOUT){
			DbgLogError(("MCHIP_MemToMem_Copy(size=%d): GoR set after timeout, VIO_VideoControl=0x%08x\n", size, val32));
			return FALSE;
		}
	}
//	DbgLogInfo(("MCHIP_MemToMem_Copy(size=%d) done\n", size));

    return TRUE;
}
