//=============================================================================
//  File Name: mchip_test_host.c
//
//  Copyright 2009 Magnum Semiconductor Inc. All rights reserved.
//
//  Description:
//      Tests read and write of host slave bus registers.
//
//  Modification History:
//      $Id: $
//      $Log: $
//
//=============================================================================

#include "mchip.h"
#include "mchip_registers.h"

Boolean
USBBootMChip_t::
MCHIP_Test_Host_16(void)
{
    Uint16 read16, write16;

    // verify MCHIP host 16-bit read/write is functional by writing, 
    // reading back MCHIP Host Address Register)
    for (write16 = 0x0001; write16; write16 <<= 1)
    {
        // write
        if (!MCHIP_Host_Write16(DMN_HB_ADDR, write16)) return FALSE;

        // read
        read16 = 0x0000;
        if (!MCHIP_Host_Read16(DMN_HB_ADDR, &read16)) return FALSE;

        // compare
        if (read16 != write16)
        {
            DbgLogError(("MCHIP: %d: host write 0x%04x, read 0x%04x\n", __LINE__, write16, read16));
            return FALSE;
        }
    }

    DbgLogInfo(("MCHIP: host 16-bit test OK\n"));
    return TRUE;
}

Boolean
USBBootMChip_t::
MCHIP_Test_Host_32(void)
{
    Uint16 read16_hi, read16_lo;
    Uint32 read32, write32;

    // verify MCHIP host 32-bit read/write (2x16-bit read/write) is 
    // functional by writing, reading back MCHIP Host Address registers
    for (write32 = 0x00000001; write32; write32 <<= 1)
    {
        // write 2x16-bit writes, read 1x32-bit read
        if (!MCHIP_Host_Write16(DMN_HB_ADDR_HIGH, (Uint16)(write32 >> 16))) return FALSE;
        if (!MCHIP_Host_Write16(DMN_HB_ADDR_LOW, (Uint16)(write32 & 0xFFFF))) return FALSE;
        read32 = 0;
        if (!MCHIP_Host_Read32(DMN_HB_ADDR, &read32)) return FALSE;
        // compare
        if (read32 != write32)
        {
            DbgLogError(("MCHIP: %d: host write 0x%04x 0x%04x, read 0x%08x\n", __LINE__, write32 >> 16, write32 & 0xFFFF, read32));
            return FALSE;
        }

        // write 1x 32-bit write, read 2x16-bit reads
        write32 ^= 0xFFFFFFFF;
        if (!MCHIP_Host_Write32(DMN_HB_ADDR, write32)) return FALSE;
        read16_hi = 0;
        if (!MCHIP_Host_Read16(DMN_HB_ADDR_HIGH, &read16_hi)) return FALSE;
        read16_lo = 0;
        if (!MCHIP_Host_Read16(DMN_HB_ADDR_LOW, &read16_lo)) return FALSE;
        // compare
        if (read16_hi != (write32 >> 16) || read16_lo != (write32 & 0xFFFF))
        {
            DbgLogError(("MCHIP: %d: host write 0x%08x, read 0x%04x 0x%04x\n", __LINE__, write32, read16_hi, read16_lo));
            return FALSE;
        }
        write32 ^= 0xFFFFFFFF;
    }

    DbgLogInfo(("MCHIP: host 32-bit test OK\n"));
    return TRUE;
}
