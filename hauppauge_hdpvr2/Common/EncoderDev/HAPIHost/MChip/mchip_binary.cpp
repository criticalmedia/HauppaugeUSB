//=============================================================================
//  File Name: mchip_binary.c
//
//  Copyright 2009 Magnum Semiconductor Inc. All rights reserved.
//
//  Description:
//      Load and boot binary image(s) to MCHIP.
//
//  Modification History:
//      $Id: $
//      $Log: $
//
//=============================================================================

#include "HapiBaseType.h"
#include "mchip.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/stat.h>
#include <sys/file.h>

//#define NO_PRV_SBP//Warning - super slow!!

#include "mchip_registers.h"

// SBP write timeout
#ifndef DRIVER_BUILD
#define MCHIP_SBP_TIMEOUT         100000            // ms
#else
#define MCHIP_SBP_TIMEOUT         30 //retrys, at 10ms intervals
#endif

// initialize SBP0 registers on MCHIP
Boolean USBBootMChip_t::prv_sbp0_init(void)
{
    // set storage interface to SD mode to make SBP0 available
    if (!MCHIP_Write32(DMN_DVD_CFG, DMN_DVD_CFG_ATAPIRST | DMN_DVD_CFG_MODE_SD)) return FALSE;

    // set GPIO config to make GP_HMST[4], GP_HMST[5] into shared function SBP0_RD, SBP0_OE
    if (!MCHIP_Write32(0xFF06F050, 0x77000000)) return FALSE;

    // clear all bits in SecCfg0 except IFsel and POL
    if (!MCHIP_Write32(DMN_IPC_SECCFG0, 
                     DMN_IPC_SECCFG_IFD | 
                     DMN_IPC_SECCFG_WRREQ | 
                     DMN_IPC_SECCFG_FP | 
                     DMN_IPC_SECCFG_IE |
                     DMN_IPC_SECCFG_GO | 
                     DMN_IPC_SECCFG_BSRD |
                     DMN_IPC_SECCFG_WRDA_0)) return FALSE;
    if (!MCHIP_Write32(DMN_IPC_SECCFG0,
                     DMN_IPC_SECCFG_IFSEL |
                     DMN_IPC_SECCFG_POL |
                     DMN_IPC_SECCFG_WRDA_1)) return FALSE;

    return TRUE;
}

// configure SBP0 registers on MCHIP for write and write a block
// note that this function has the same signature as the host bus MCHIP_WriteBlock
Boolean USBBootMChip_t::prv_sbp0_write(Uint32 addr, const Uint8* data, Uint32 size)
{
    Uint32 val32;

    // SBP start, end must be 4-byte aligned
    ASSERT((addr & 0x03) == 0);
    //ASSERT((size & 0x03) == 0);
    ASSERT(data);

    // set SBP0 destination
    if (!MCHIP_Write32(DMN_IPC_SECBASE0,  0x00000000)) return FALSE;  // circular buffer base
    if (!MCHIP_Write32(DMN_IPC_SECLIMIT0, 0x00000000)) return FALSE;  // circular buffer top
    if (!MCHIP_Write32(DMN_IPC_SECNEXT0,  addr))       return FALSE;  // next write
    if (!MCHIP_Write32(DMN_IPC_SECSTOP0,  addr+size))  return FALSE;  // end of write

    if (MCHIP_Read32(DMN_IPC_SECNEXT0,  &val32)) 
            DbgLogInfo(("prv_sbp0_write: SecNext=0x%08x\n", val32)); 

    if (MCHIP_Read32(DMN_IPC_SECSTOP0,  &val32)) 
            DbgLogInfo(("prv_sbp0_write: SecStop=0x%08x\n", val32)); 

    if (MCHIP_Read32(DMN_IPC_SECCFG0,  &val32)) 
            DbgLogInfo(("prv_sbp0_write: SecCfg=0x%08x\n", val32)); 

    // initiate SBP0 DMA by setting Go bit
	if (!MCHIP_Write32(DMN_IPC_SECCFG0, DMN_IPC_SECCFG_GO | DMN_IPC_SECCFG_WRDA_1)){
		DbgLogError(("prv_sbp0_write: MCHIP_Write32(DMN_IPC_SECCFG0, DMN_IPC_SECCFG_GO | DMN_IPC_SECCFG_WRDA_1) failed\n")); 
		return FALSE;
	}

    // select SBP interface
    if (!MCHIP_SBP_Select()){
		DbgLogError(("prv_sbp0_write: MCHIP_SBP_Select() failed\n")); 
		return FALSE;
	}

    // write block to SBP0
    if (!MCHIP_SBP0_Write(data, size)) 
    {
		DbgLogError(("prv_sbp0_write: MCHIP_SBP0_Write() failed\n")); 
        MCHIP_Host_Select();
        return FALSE;
    }

    // select host interface
    if (!MCHIP_Host_Select()){
		DbgLogError(("prv_sbp0_write: MCHIP_Host_Select() failed\n")); 
		return FALSE;
	}
    // issue a dummy write cycle to MCHIP Host Address Register
    MCHIP_Host_Write16(DMN_HB_ADDR, 0);

    // wait for SBP0 DMA to finish
	int timeout = MCHIP_SBP_TIMEOUT;
    while(timeout--)
    {
		//FGR - this was missing from the loop
		// is it needed?  BUGBUG - is this right??
		if (MCHIP_Read32(DMN_IPC_SECCFG0,  &val32)){
            DbgLogInfo(("prv_sbp0_write: SecCfg=0x%08x\n", val32));
		}
        // Go == 0?
        if ((val32 & DMN_IPC_SECCFG_GO) == 0) 
            break;

		wrapSleep_ms(10);
	}
	if(timeout <= 0){
        Uint32 sec_next0;
		if (!MCHIP_Read32(DMN_IPC_SECNEXT0,  &sec_next0)){
	        DbgLogError(("prv_sbp0_write: %d: SBP0 Go not 0 after timeout, SECNEXT0 read failed\n", __LINE__));
			return FALSE;
		}
        DbgLogInfo(("prv_sbp0_write: SecNext0=0x%08x\n", sec_next0)); 
		
		Uint32 remaining = (addr+size) - sec_next0;
		if(remaining < 256){
	        DbgLogWarn(("prv_sbp0_write: %d: SBP0 stalled, %u remaining\n", __LINE__, remaining));
			
			// terminate SBP0 DMA by clearing Go bit
			if (!MCHIP_Write32(DMN_IPC_SECCFG0, DMN_IPC_SECCFG_WRDA_1)){
				DbgLogError(("prv_sbp0_write: MCHIP_Write32(DMN_IPC_SECCFG0, DMN_IPC_SECCFG_WRDA_1) failed\n")); 
				//return FALSE;
			}
			return TRUE;
		}
        return FALSE;
	}

    return TRUE;
}

Boolean USBBootMChip_t::prv_load_bin(const char *filename, Uint8** bin, Uint32* size)
{
	wrapLogDebug("USBBootMChip_t::prv_load_bin(): %s", filename);
	size_t _size = *size;
	int r = wrapFileLoad(filename, (void**)bin, &_size);
	*size = _size;
	return (r == WRAPOS_OK) ? TRUE : FALSE;
}


Boolean
USBBootMChip_t::
MCHIP_Binary_LoadSPARC(Uint32 base, Uint32 entry, const Uint8* bin, Uint32 size, Boolean use_sbp)
{
    Uint32 inst;

    // block write function: use host write by default
    Boolean (USBBootMChip_t::*write_block)(Uint32 addr, const Uint8* data, Uint32 size) = &USBBootMChip_t::MCHIP_WriteBlock;

    ASSERT(bin);
    // requires that base, entry, size be aligned to 4 bytes
    ASSERT((base & 0x3) == 0x0);
    ASSERT((entry & 0x3) == 0x0);
    ASSERT((size & 0x03) == 0x0);

    // using sethi instruction to set upper 22 bits of entrypoint
    // requires that entry be aligned to 2^10 bits
    ASSERT((entry & 0x3FF) == 0x000);

    // use SBP for block write?
#ifdef NO_PRV_SBP//HAUPPAUGE
	if(use_sbp){
		use_sbp = 0;
		DbgLogInfo(("MCHIP_Binary_LoadSPARC - BUGBUG forcing use_sbp=0 for now\n"));
	}
#endif
    if (use_sbp)
    {
        // init SBP0
        if (!prv_sbp0_init())
        {
            DbgLogInfo(("MCHIP: ERROR %d: SBP0 init failed\n", __LINE__));
            return FALSE;
        }
        // set block write function to SBP0 write
        write_block = &USBBootMChip_t::prv_sbp0_write;
	}
    else
    {
        write_block = &USBBootMChip_t::MCHIP_WriteBlock;
    }

    // mask off upper 3 bits of base to get to physical (DRAM) address
    base &= 0x1fffffff;

    // write image at masked base in DRAM
    DbgLogInfo(("MCHIP: writing SPARC image 0x%08x-0x%08x\n", base, base+size));
    if (!(this->*write_block)(base, bin, size)) return FALSE;

    // mask off upper 3 bits of entry to get to physical (DRAM) address
    entry &= 0x1fffffff;

    DbgLogInfo(("MCHIP: writing SPARC boot jump to entrypoint 0x%08x:\n", entry));
    // 0x00000000: sethi entry >> 10, %8
    inst = 0x11000000 | (entry >> 10);
    DbgLogTrace(("MCHIP: 0x00000000: 0x%08x: sethi 0x%06x, %%8\n", inst, entry >> 10));
    if (!MCHIP_Write32(0x00000000, inst)) return FALSE;
    // 0x00000004: jmpl %8 + %0, %15
    // TODO: could relax 2^10 bit entrypoint alignment by using jmpl %8 + imm?
    inst = 0x9fc20000;
    DbgLogTrace(("MCHIP: 0x00000004: 0x%08x: jmpl %%8\n", inst));
    if (!MCHIP_Write32(0x00000004, inst)) return FALSE;
    // 0x00000008: nop (delay slot)
    inst = 0x01000000;
    DbgLogTrace(("MCHIP: 0x00000008: 0x%08x: nop\n", inst));
    if (!MCHIP_Write32(0x00000008, inst)) return FALSE;

    // ready for boot
    return TRUE;
}

Boolean
USBBootMChip_t::
MCHIP_Binary_LoadMIPS(Uint32 base, Uint32 entry, const Uint8* bin, Uint32 size, Boolean use_sbp)
{
    Uint32 inst;

    // block write function: use host write by default
    Boolean (USBBootMChip_t::*write_block)(Uint32 addr, const Uint8* data, Uint32 size) = &USBBootMChip_t::MCHIP_WriteBlock;

    ASSERT(bin);
    // requires that base, entry, size be aligned to 4 bytes
    ASSERT((base & 0x3) == 0x0);
    ASSERT((entry & 0x3) == 0x0);
    ASSERT((size & 0x03) == 0x0);

    // use SBP for block write?
#ifdef NO_PRV_SBP//HAUPPAUGE
	if(use_sbp){
		use_sbp = 0;
		DbgLogInfo(("MCHIP_Binary_LoadMIPS - BUGBUG forcing use_sbp=0 for now\n"));
	}
#endif
    if (use_sbp)
    {
        // init SBP0
        if (!prv_sbp0_init())
        {
            DbgLogInfo(("MCHIP: ERROR %d: SBP0 init failed\n", __LINE__));
            return FALSE;
        }
        // set block write function to SBP0 write
        write_block = &USBBootMChip_t::prv_sbp0_write;
    }
    else
    {
        write_block = &USBBootMChip_t::MCHIP_WriteBlock;
    }

    // mask off upper 3 bits of base to get to physical (DRAM) address
    base &= 0x1fffffff;

    // write image at masked base in DRAM
    DbgLogInfo(("MCHIP: writing MIPS image 0x%08x-0x%08x\n", base, base+size));
    if (!(this->*write_block)(base, bin, size)) return FALSE;

    // note we keep the entry as virtual MIPS address

    DbgLogInfo(("MCHIP: writing MIPS boot jump to entrypoint 0x%08x:\n", entry));
    // 0x00000020: lui $8, entry >> 16
    inst = 0x3c080000 | (entry >> 16);
    DbgLogTrace(("MCHIP: 0x00000020: 0x%08x: lui $8, 0x%04x\n", inst, entry >> 16));
    if (!MCHIP_Write32(0x00000020, inst)) return FALSE;
    // 0x00000024: ori $8, $8, entry & 0xFFFF
    inst = 0x35080000 | (entry & 0xFFFF);
    DbgLogTrace(("MCHIP: 0x00000024: 0x%08x: ori $8, $8, 0x%04x\n", inst, entry & 0xFFFF));
    if (!MCHIP_Write32(0x00000024, inst)) return FALSE;
    // 0x00000028: jalr $8
    inst = 0x0100f809;
    DbgLogTrace(("MCHIP: 0x00000028: 0x%08x: jalr $8\n", inst));
    if (!MCHIP_Write32(0x00000028, inst)) return FALSE;
    // 0x0000002c: nop (delay slot)
    inst = 0x00000000;
    DbgLogTrace(("MCHIP: 0x0000002c: 0x%08x: nop\n", inst));
    if (!MCHIP_Write32(0x0000002c, inst)) return FALSE;

    // ready for boot
    return TRUE;
}

Boolean
USBBootMChip_t::
MCHIP_Binary_BootSystemSPARC(void)
{
    // boot MCHIP System SPARC (Audio SPARC)
    // write 0 to SCPURst bit to release SPARC from reset
    DbgLogInfo(("MCHIP: booting System SPARC\n"));
    if (!MCHIP_Host_Write16(DMN_HB_CONTROL, DMN_HB_HC_SCPU_RST | DMN_HB_HC_WR_DATA_0)) return FALSE;

    return TRUE;
}

Boolean
USBBootMChip_t::
MCHIP_Binary_BootVideoSPARC(void)
{
    // boot MCHIP Video SPARC
    // write 0 to VCPURst bit to release SPARC from reset
    DbgLogInfo(("MCHIP: booting Video SPARC\n"));
    if (!MCHIP_Host_Write16(DMN_HB_CONTROL, DMN_HB_HC_VCPU_RST | DMN_HB_HC_WR_DATA_0)) return FALSE;

    return TRUE;
}

Boolean
USBBootMChip_t::
MCHIP_Binary_BootMIPS(void)
{
    // boot MCHIP MIPS
    // write 0 to MIPSRst bit to release MIPS from reset
    DbgLogInfo(("MCHIP: booting MIPS\n"));
    if (!MCHIP_Host_Write16(DMN_HB_CONTROL, DMN_HB_HC_MIPS_RST | DMN_HB_HC_WR_DATA_0)) return FALSE;

    return TRUE;
}

Boolean
USBBootMChip_t::
MCHIP_Binary_ZeroDRAM(Uint32 size)
{
    Uint8* buffer;
    Uint32 addr;
    //Uint8 buf;

    ASSERT(size % (1024*1024) == 0);

 #ifndef NO_PRV_SBP//HAUPPAUGE
    if (!prv_sbp0_init())
    {
        DbgLogError(("MCHIP_Binary_ZeroDRAM() prv_sbp0_init() failed\n"));
        return FALSE;
    }
 #endif	
	Uint32 count = 1024;

	DWORD dwDBG_FW_padding = 4; //FGR - adding a few dummy bytes to FW download helps
	hcwGetRegistryDWORD("DBG_FW_padding", &dwDBG_FW_padding);
	dwDBG_FW_padding += 3;
	dwDBG_FW_padding &= ~3; //must align to 4 byte boundry
	if(dwDBG_FW_padding > 256){
		dwDBG_FW_padding = 0;
	}
	addr = 0;

    buffer = (Uint8*)wrapHeapAlloc(count+dwDBG_FW_padding);
    if (!buffer)
    {
        DbgLogError(("MCHIP_Binary_ZeroDRAM() cannot allocate memory\n"));
        return FALSE;
    }
    memset(buffer, 0x00, count+dwDBG_FW_padding);
	
    // write first "count" bytes as zero with SBP0
    DbgLogInfo(("MCHIP_Binary_ZeroDRAM() zero 0x00000000-0x%08x\n", size));
 #ifndef NO_PRV_SBP//HAUPPAUGE
    if (!prv_sbp0_write(addr, buffer, count+dwDBG_FW_padding))
    {
		wrapHeapFree(buffer);
        DbgLogError(("MCHIP_Binary_ZeroDRAM() prv_sbp0_write(%x,,%d) failed\n", addr, count+dwDBG_FW_padding));
        return FALSE;
    }
 #else
	MCHIP_WriteBlock(addr, buffer, count+dwDBG_FW_padding); //FGR - the non-DMA way, but REALLY slow
 #endif
   	wrapHeapFree(buffer);
	
	//now do ever increasing chunks with mem-to-mem copy, but no more than 1MB in length
	while(count <= 512*1024){
        if (!MCHIP_MemToMem_Copy(0x00000000, count, count)){
        	DbgLogError(("MCHIP_Binary_ZeroDRAM() MCHIP_MemToMem_Copy(0x%x,0x%x,%d) failed\n", addr, count, count));
			return FALSE;
		}
        count *= 2;
    }

    // copy 1M chunks with mem-to-mem copy
    addr = 1024*1024;
    size -= 1024*1024;
    while (size)
    {
        //DbgLogInfo(("MCHIP: copy zero 0x%08x-0x%08x\n", addr, addr + 1024*1024));
        if (!MCHIP_MemToMem_Copy(0x00000000, addr, 1024*1024)) return FALSE;

        addr += 1024*1024;
        size -= 1024*1024;
    }

    return TRUE;
}

#ifdef HAUPPAUGE
// initialize SBP1 pins
Boolean USBBootMChip_t::prv_sbp1_init(void)
{
#if 1//DEBUG_REGS
    Uint32 val32;
#endif

    /*
    // check multiplex on POD/CI pins, expect [1:0]=PodCiMd=00, HMST_ADDR[25:15]
    if (!MCHIP_Read32(0xFFFB1100, &version32)) goto EXIT;
    DbgLogInfo(("DXT: POD/CI Data Routing Control=0x%08x\n", version32));
    */

    /*
    // look for clock on SBP1_CLK = GP_HMST[1]
    // set GP_HMST[1] as input
    if (!MCHIP_Read32(0xFF06F050, &val32)) return FALSE;
    DbgLogInfo(("DXT: GpioCfg=0x%08x\n", val32));
    if (!MCHIP_Write32(0xFF06F050, 0x000000F0)) return FALSE;
    if (!MCHIP_Read32(0xFF06F050, &val32)) return FALSE;
    DbgLogInfo(("DXT: GpioCfg=0x%08x\n", val32));
    // poll GP_HMST, if SBP1_CLK is active expect to see activity on bit 2
    if (!MCHIP_Read32(0xFF06F054, &val32)) return FALSE;
    DbgLogInfo(("DXT: GpioVal=0x%08x\n", val32));
    if (!MCHIP_Read32(0xFF06F054, &val32)) return FALSE;
    DbgLogInfo(("DXT: GpioVal=0x%08x\n", val32));
    if (!MCHIP_Read32(0xFF06F054, &val32)) return FALSE;
    DbgLogInfo(("DXT: GpioVal=0x%08x\n", val32));
    if (!MCHIP_Read32(0xFF06F054, &val32)) return FALSE;
    DbgLogInfo(("DXT: GpioVal=0x%08x\n", val32));
    if (!MCHIP_Read32(0xFF06F054, &val32)) return FALSE;
    DbgLogInfo(("DXT: GpioVal=0x%08x\n", val32));
    if (!MCHIP_Read32(0xFF06F054, &val32)) return FALSE;
    DbgLogInfo(("DXT: GpioVal=0x%08x\n", val32));
    if (!MCHIP_Read32(0xFF06F054, &val32)) return FALSE;
    DbgLogInfo(("DXT: GpioVal=0x%08x\n", val32));
    if (!MCHIP_Read32(0xFF06F054, &val32)) return FALSE;
    DbgLogInfo(("DXT: GpioVal=0x%08x\n", val32));
    // set GP_HMST[1] back to shared function SBP1_CLK
    if (!MCHIP_Read32(0xFF06F050, &val32)) return FALSE;
    DbgLogInfo(("DXT: GpioCfg=0x%08x\n", val32));
    if (!MCHIP_Write32(0xFF06F050, 0x00000080)) return FALSE;
    if (!MCHIP_Read32(0xFF06F050, &val32)) return FALSE;
    DbgLogInfo(("DXT: GpioCfg=0x%08x\n", val32));
    */

    // clear all bits in SecCfg1 except IFsel and POL and BSRD
#if 1//DEBUG_REGS
    if (!MCHIP_Read32(DMN_IPC_SECCFG1, &val32)) return FALSE;
    DbgLogInfo(("prv_sbp1_init: SecCfg1=0x%08x 1\n", val32)); 

#endif
    if (!MCHIP_Write32(DMN_IPC_SECCFG1, 
                     DMN_IPC_SECCFG_IFD | 
                     DMN_IPC_SECCFG_WRREQ | 
                     DMN_IPC_SECCFG_FP | 
                     DMN_IPC_SECCFG_IE |
                     DMN_IPC_SECCFG_GO | 
                     DMN_IPC_SECCFG_WRDA_0)) return FALSE;
#if 0//DEBUG_REGS
    if (MCHIP_Read32(DMN_IPC_SECCFG1, &val32)){
		DbgLogInfo(("prv_sbp1_init: SecCfg1=0x%08x 2\n", val32)); 
	}
#endif
    if (!MCHIP_Write32(DMN_IPC_SECCFG1,
                     DMN_IPC_SECCFG_IFSEL |
                     DMN_IPC_SECCFG_POL |
                     DMN_IPC_SECCFG_BSRD |
                     DMN_IPC_SECCFG_WRDA_1)) return FALSE;
#if 0//DEBUG_REGS
    if (MCHIP_Read32(DMN_IPC_SECCFG1, &val32)){
		DbgLogInfo(("prv_sbp1_init: SecCfg1=0x%08x 3\n", val32)); 
	}
#endif

    return TRUE;
}
#endif//HAUPPAUGE

#if 1
Boolean
USBBootMChip_t::
prv_sbp1_read(Uint32 addr, const Uint8* data, Uint32 size)
{
    Uint32 val32;

    // SBP start, end must be 4-byte aligned
    ASSERT((addr & 0x03) == 0);
    ASSERT((size & 0x03) == 0);
    ASSERT(data);

#if 1
	// select host interface
    if (!MCHIP_Host_Select()){
		DbgLogInfo(("prv_sbp1_read: MCHIP_Host_Select() failed\n")); 
		return FALSE;
	}
    // issue a dummy write cycle to MCHIP Host Address Register
    MCHIP_Host_Write16(DMN_HB_ADDR, 0);
#endif
    if (MCHIP_Read32(DMN_IPC_SECNEXT1, &val32)){
		DbgLogInfo(("prv_sbp1_read: SecNext1=0x%08x 1\n", val32)); 
	}

    // initialize SBP1 pins
    if (!prv_sbp1_init()) return FALSE;

    // set SBP1 destination
    if (!MCHIP_Write32(DMN_IPC_SECBASE1,  0x00000000)) return FALSE;  // circular buffer base
    if (!MCHIP_Write32(DMN_IPC_SECLIMIT1, 0x00000000)) return FALSE;  // circular buffer top
    if (!MCHIP_Write32(DMN_IPC_SECNEXT1,  addr))       return FALSE;  // next write
    if (!MCHIP_Write32(DMN_IPC_SECSTOP1,  addr+size))  return FALSE;  // end of write

//    if (MCHIP_Read32(DMN_IPC_SECNEXT1, &val32)){
//		DbgLogInfo(("prv_sbp1_read: SecNext1=0x%08x 2\n", val32)); 
//	}
#if 0
    if (MCHIP_Read32(DMN_IPC_SECNEXT1,  &val32)){
            DbgLogInfo(("prv_sbp1_read: SecNext=0x%08x\n", val32)); 
	}
    if (MCHIP_Read32(DMN_IPC_SECSTOP1,  &val32)){ 
            DbgLogInfo(("prv_sbp1_read: SecStop=0x%08x\n", val32)); 
	}
    if (MCHIP_Read32(DMN_IPC_SECCFG1,  &val32)){ 
            DbgLogInfo(("prv_sbp1_read: SecCfg=0x%08x\n", val32)); 
	}
#endif
    // initiate SBP1 DMA by setting Go bit
    if (!MCHIP_Write32(DMN_IPC_SECCFG1, DMN_IPC_SECCFG_GO | DMN_IPC_SECCFG_WRDA_1)) return FALSE;

    if (MCHIP_Read32(DMN_IPC_SECNEXT1, &val32)){
		DbgLogInfo(("prv_sbp1_read: SecNext1=0x%08x 3\n", val32)); 
	}
    // select SBP interface
    if (!MCHIP_SBP_Select()){
		DbgLogInfo(("prv_sbp1_read: MCHIP_SBP_Select() 2 failed\n")); 
		return FALSE;
	}

    // read from SBP1
//  if (!MCHIP_SBP1_Read((Uint8 *)data, size)) 
    if (!UsbParIn((char *)data, size)) 
    {
        MCHIP_Host_Select();
        return FALSE;
    }

    // select host interface
    if (!MCHIP_Host_Select()){
		DbgLogInfo(("prv_sbp1_read: MCHIP_Host_Select() 2 failed\n")); 
		return FALSE;
	}
    // issue a dummy write cycle to MCHIP Host Address Register
    MCHIP_Host_Write16(DMN_HB_ADDR, 0);

    // end SBP1 DMA by clearing Go bit
    if (!MCHIP_Write32(DMN_IPC_SECCFG1, DMN_IPC_SECCFG_GO | DMN_IPC_SECCFG_WRDA_0)) return FALSE;

#if 0
    if (MCHIP_Read32(DMN_IPC_SECNEXT1, &val32)){
		DbgLogInfo(("prv_sbp1_read: SecNext1=0x%08x 4\n", val32)); 
	}

    // wait for SBP1 DMA to finish
	int timeout = MCHIP_SBP_TIMEOUT;
    while(timeout--)
    {

#ifdef HAUPPAUGE
		//FGR - this was missing from the loop
		// is it needed?  BUGBUG - is this right??
		if (MCHIP_Read32(DMN_IPC_SECCFG1,  &val32)){
            DbgLogInfo(("prv_sbp1_read: SecCfg=0x%08x\n", val32));
		} else {
            DbgLogInfo(("prv_sbp1_read: DMN_IPC_SECCFG1 read failed\n", val32));
			break;
		}
#endif
        // Go == 0?
        if ((val32 & DMN_IPC_SECCFG_GO) == 0) 
            break;

		wrapSleep_ms(10);
	}
	if(timeout <= 0){
        DbgLogError(("prv_sbp1_read: %d: SBP1 Go not 0 after timeout, SecCfg=0x%08x\n", __LINE__, val32));
        if (!MCHIP_Read32(DMN_IPC_SECNEXT1,  &val32)) return TRUE;//FALSE; //BUGBUG - fixme  // next write
        DbgLogInfo(("prv_sbp1_read: SecNext=0x%08x\n", val32));
        return TRUE;//FALSE; //BUGBUG - fixme
	}

#endif//if 0
    return TRUE;
}
#endif//#if 0
