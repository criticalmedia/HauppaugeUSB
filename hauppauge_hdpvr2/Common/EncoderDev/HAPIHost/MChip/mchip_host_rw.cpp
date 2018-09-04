#include "mchip.h"
#include "mchip_registers.h"

Boolean
USBBootMChip_t::
MCHIP_Host_Select(void)
{
//	DbgLogInfo(("MCHIP_Host_Select()\n"));

    if (!UsbSetWFMode(WF_HOST))
    {
        if(statusCnt < USB_ERR_LIMIT){
			DbgLogError(("MCHIP_Host_Select UsbSetWFMode failed\n"));
		}
        return FALSE;
    }

    // select waveform numbers: 2=read 3=write
    if (!UsbSetWFRW(2, 3))
    {
        DbgLogError(("MCHIP_Host_Select UsbSetWFRW failed\n"));
        return FALSE;
    }
    // set HST_SELECT* = 0 to select RDY0/SLRD <-- HST_DTACK*
    if (!MCHIP_PortA_Set_HST_SELECT_L(0))
    {
        DbgLogError(("MCHIP_Host_Select MCHIP_PortA_Set_HST_SELECT_L failed\n"));
        return FALSE;
    }

    return TRUE;
}

Boolean
USBBootMChip_t::
MCHIP_Host_Read16(Uint8 addr, Uint16* data)
{
//	BOOL success;
    // only 8 registers
    ASSERT((addr & ~0x07) == 0x00);
    ASSERT(data);

    // read 16 bits from host slave bus register

    // set PA4/PA5/PA6 = HST_ADR1/HST_ADR2/HST_ADR3
    // set PA7 = HST_RD/WR* = 1
    if (!MCHIP_PortA_Set_HST_ADR_RDWR_L(addr, 1))
    {
        DbgLogError(("MCHIP_Host_Read16: %d: set host addr 0x%x failed\n",  __LINE__, addr));
        return FALSE;
    }

    // read
    // note no endianism concern here
    if (!UsbParIn((char*)data, 2))  // read 1 word = 16 bits
    {
        DbgLogError(("MCHIP_Host_Read16: %d: read host data 0x%x failed\n",  __LINE__, addr));
        return FALSE;
    }

    return TRUE;
}

Boolean
USBBootMChip_t::
MCHIP_Host_Write16(Uint8 addr, Uint16 data)
{
    // only 8 registers
    ASSERT((addr & ~0x07) == 0x00);

    // write 16 bits to host slave bus register

    // set PA4/PA5/PA6 = HST_ADR1/HST_ADR2/HST_ADR3
    // set PA7 = HST_RD/WR* = 0
    if (!MCHIP_PortA_Set_HST_ADR_RDWR_L(addr, 0))
    {
        DbgLogError(("MCHIP_Host_Write16: %d: set host addr 0x%x failed\n",  __LINE__, addr));
        return FALSE;
    }

    // write
    // note no endianism concern here
    if (!UsbParOut((char*)&data, 2))  // write 1 word = 16 bits
    {
        DbgLogError(("MCHIP_Host_Write16: %d: write host data 0x%x failed\n",  __LINE__, addr));
        return FALSE;
    }

    return TRUE;
}

Boolean
USBBootMChip_t::
MCHIP_Host_Read32(Uint8 addr, Uint32* data)
{
    Uint16 hi, lo;
//	BOOL success;

    // only 8 registers
    ASSERT((addr & ~0x07) == 0x00);
    // assume address is even
    ASSERT((addr & 0x01) == 0x00);
    ASSERT(data);

    // read 32 bits from a pair of host slave bus registers

    // set PA4/PA5/PA6 = HST_ADR1=0/HST_ADR2/HST_ADR3
    // set PA7 = HST_RD/WR* = 1
    if (!MCHIP_PortA_Set_HST_ADR_RDWR_L(addr, 1))
    {
        DbgLogError(("MCHIP_Host_Read32: %d: set host addr1 0x%x failed\n",  __LINE__, addr));
        return FALSE;
    }


    // read high 16 bits
    if (!UsbParIn((char*)&hi, 2))  // read 1 word = 16 bits
    {
        DbgLogError(("MCHIP_Host_Read32: %d: read host data1 0x%x failed\n",  __LINE__, addr));
        return FALSE;
    }

    // set PA4 = HST_ADR1=1
    addr++;
    if (!MCHIP_PortA_Set_HST_ADR_RDWR_L(addr, 1))
    {
        DbgLogError(("MCHIP_Host_Read32: %d: set host addr2 0x%x failed\n",  __LINE__, addr));
        return FALSE;
    }

    // read low 16 bits
    if (!UsbParIn((char*)&lo, 2))  // read 1 word = 16 bits
    {
        DbgLogError(("MCHIP_Host_Read32: %d: read host data2 0x%x failed\n",  __LINE__, addr));
        return FALSE;
    }

    *data = (hi << 16) | lo;

    return TRUE;
}

Boolean
USBBootMChip_t::
MCHIP_Host_Write32(Uint8 addr, Uint32 data)
{
    Uint16 hi, lo;

    // only 8 registers
    ASSERT((addr & ~0x07) == 0x00);
    // assume address is even
    ASSERT((addr & 0x01) == 0x00);

    // write 32 bits to a pair of host slave bus registers

    // set PA4/PA5/PA6 = HST_ADR1/HST_ADR2/HST_ADR3
    // set PA7 = HST_RD/WR* = 0
    if (!MCHIP_PortA_Set_HST_ADR_RDWR_L(addr, 0))
    {
        DbgLogError(("MCHIP_Host_Write32: %d: set host addr1 0x%x failed\n",  __LINE__, addr));
        return FALSE;
    }

    hi = (Uint16)(data >> 16);
    lo = (Uint16)(data      );

    // write high 16 bits
    if (!UsbParOut((char*)&hi, 2))  // write 1 word = 16 bits
    {
        DbgLogError(("MCHIP_Host_Write32: %d: write host data1 0x%x failed\n",  __LINE__, addr));
        return FALSE;
    }

    // set PA4 = HST_ADR1=1
    addr++;
    if (!MCHIP_PortA_Set_HST_ADR_RDWR_L(addr, 0))
    {
        DbgLogError(("MCHIP_Host_Write32: %d: set host addr2 0x%x failed\n",  __LINE__, addr));
        return FALSE;
    }

    // write low 16 bits
    if (!UsbParOut((char*)&lo, 2))  // write 1 word = 16 bits
    {
        DbgLogError(("MCHIP_Host_Write32: %d: write host data2 0x%x failed\n",  __LINE__, addr));
        return FALSE;
    }

    return TRUE;
}


Boolean
USBBootMChip_t::
MCHIP_Read32(Uint32 addr, Uint32* data)
{
    Uint32 val;
    // addr must be 4-byte aligned
    ASSERT((addr % 4) == 0);
    ASSERT(data);

    // read 32-bit CBus register/DRAM via host slave bus address/data registers

    // write the MCHIP Host Address registers
    if (!MCHIP_Host_Write32(DMN_HB_ADDR, addr))
    {
        DbgLogError(("MCHIP_Read32: %d: set host addr 0x%08x failed\n",  __LINE__, addr));
        return FALSE;
    }
    // read the MCHIP Host Data registers
    if (!MCHIP_Host_Read32(DMN_HB_DATA, &val)) 
    {
        DbgLogError(("MCHIP_Read32: %d: read host data 0x%08x failed\n",  __LINE__, addr));
        return FALSE;
    }

    *data = val;
    
    //DbgLogInfo(("read: addr = 0x%x, data = 0x%x\n", addr, *data));

    return TRUE;
}

Boolean
USBBootMChip_t::
MCHIP_Write32(Uint32 addr, Uint32 data)
{
    //Uint32 val;
    // addr must be 4-byte aligned
    ASSERT((addr % 4) == 0);

    //DbgLogInfo(("write: addr = 0x%x, data = 0x%x\n", addr, data));

    // write 32-bit CBus register/DRAM via host slave bus address/data registers

    // write the MCHIP Host Address registers
    if (!MCHIP_Host_Write32(DMN_HB_ADDR, addr))
    {
        DbgLogError(("MCHIP_Write32: %d: write host address 0x%08x failed\n",  __LINE__, addr));
        return FALSE;
    }
    // write the MCHIP Host Data registers
    if (!MCHIP_Host_Write32(DMN_HB_DATA, data))
    {
        DbgLogError(("MCHIP_Write32: %d: write host data 0x%08x failed\n",  __LINE__, data));
        return FALSE;
    }

    //MCHIP_Read32(addr, &val);
    //DbgLogInfo(("!read: addr = 0x%x, data = 0x%x\n", addr, val));

    return TRUE;
}

Boolean
USBBootMChip_t::
MCHIP_ReadBlock(Uint32 addr, Uint8* data, Uint32 size)
{
    Uint16 hi, lo;
//	BOOL success;

    ASSERT(data);
    ASSERT(size);
    // addr, size must be 4-byte aligned
    ASSERT((addr % 4) == 0);
    ASSERT((size % 4) == 0);

    // read block of CBus register/DRAM via host slave bus address/data registers

    // write the MCHIP Host Address registers with an auto-incrementing address
    if (!MCHIP_Host_Write32(DMN_HB_ADDR, addr | 0x80000000))
    {
        DbgLogError(("MCHIP: %d: read host block 0x%08x failed\n", __LINE__, addr));
        return FALSE;
    }

    while (size)
    {
        // set PA4/PA5/PA6 = HST_ADR1=0/HST_ADR2/HST_ADR3 = MCHIP Host Data
        // set PA7 = HST_RD/WR* = 1
        if (!MCHIP_PortA_Set_HST_ADR_RDWR_L(DMN_HB_DATA, 1))
        {
             DbgLogError(("MCHIP: %d: read host address1 0x%08x failed\n", __LINE__, addr));
            return FALSE;
        }

        // read high 16 bits
        if (!UsbParIn((char*)&hi, 2))  // read 1 word = 16 bits
        {
             DbgLogError(("MCHIP: %d: read host address1 0x%08x failed\n", __LINE__, addr));
            return FALSE;
        }

        // set PA4/PA5/PA6 = HST_ADR1=0/HST_ADR2/HST_ADR3 = MCHIP Host Data + 1
        // set PA7 = HST_RD/WR* = 1
        if (!MCHIP_PortA_Set_HST_ADR_RDWR_L(DMN_HB_DATA+1, 1))
        {
             DbgLogError(("MCHIP: %d: read host address2 0x%08x failed\n", __LINE__, addr));
            return FALSE;
        }

        // read low 16 bits
        if (!UsbParIn((char*)&lo, 2))  // read 1 word = 16 bits
        {
             DbgLogError(("MCHIP: %d: read host address2 0x%08x failed\n", __LINE__, addr));
            return FALSE;
        }

        // MCHIP is big-endian
        data[0] = (Uint8)(hi >> 8);
        data[1] = (Uint8)(hi     );
        data[2] = (Uint8)(lo >> 8);
        data[3] = (Uint8)(lo     );

        size -= 4;
        addr += 4;
        data += 4;
    }

    return TRUE;
}

Boolean
USBBootMChip_t::
MCHIP_WriteBlock(Uint32 addr, const Uint8* data, Uint32 size)
{
    Uint16 hi, lo;

    ASSERT(data);
    ASSERT(size);
    // addr, size must be 4-byte aligned
    ASSERT((addr % 4) == 0);
    ASSERT((size % 4) == 0);

	DbgLogTrace(("MCHIP_WriteBlock(0x%x, ,%d)\n", addr, size)); //FGR - BUGBUG too VERBOSE

    // write block of CBus register/DRAM via host slave bus address/data registers

    // write the MCHIP Host Address registers with an auto-incrementing address
    if (!MCHIP_Host_Write32(DMN_HB_ADDR, addr | 0x80000000))
    {
        DbgLogError(("MCHIP: %d: write host block 0x%08x failed\n", __LINE__, addr));
        return FALSE;
    }

    while (size)
    {
        // MCHIP is big-endian
        hi = (data[0] << 8) | data[1];
        lo = (data[2] << 8) | data[3];

        // set PA4/PA5/PA6 = HST_ADR1=0/HST_ADR2/HST_ADR3 = MCHIP Host Data
        // set PA7 = HST_RD/WR* = 0
        if (!MCHIP_PortA_Set_HST_ADR_RDWR_L(DMN_HB_DATA, 0))
        {
            DbgLogError(("MCHIP: %d: write host address 0x%08x failed\n", __LINE__, DMN_HB_DATA));
            return FALSE;
        }

        // write high 16 bits
        if (!UsbParOut((char*)&hi, 2))  // read 1 word = 16 bits
        {
            DbgLogError(("MCHIP: %d: write host hi data 0x%08x failed\n", __LINE__, hi));
            return FALSE;
        }

        // set PA4/PA5/PA6 = HST_ADR1=0/HST_ADR2/HST_ADR3 = MCHIP Host Data + 1
        // set PA7 = HST_RD/WR* = 0
        if (!MCHIP_PortA_Set_HST_ADR_RDWR_L(DMN_HB_DATA+1, 0))
        {
            DbgLogError(("MCHIP: %d: write host address+1 0x%08x failed\n", __LINE__, DMN_HB_DATA+1));
            return FALSE;
        }

        // write low 16 bits
        if (!UsbParOut((char*)&lo, 2))  // read 1 word = 16 bits
        {
            DbgLogError(("MCHIP: %d: write host lo data 0x%08x failed\n", __LINE__, lo));
            return FALSE;
        }

        size -= 4;
        addr += 4;
        data += 4;
#if DBG
		if((addr %0x2000) == 0){
			DbgLogInfo(("MCHIP_WriteBlock(0x%x, ,%d)\n", addr, size)); //FGR - BUGBUG too VERBOSE
		}
        //DbgLogInfo(("%x\n",size));
#endif
    }

    return TRUE;
}
