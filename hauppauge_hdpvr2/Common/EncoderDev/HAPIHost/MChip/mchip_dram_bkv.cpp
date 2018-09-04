//=============================================================================
//  File Name: mchip_dram_bkv.c
//
//  Copyright 2009 Magnum Semiconductor Inc. All rights reserved.
//
//  Description:
//      MCHIP DRAM BKV (best-known-value) config parser.
//
//  Modification History:
//      $Id: $
//      $Log: $
//
//=============================================================================
#include "mchip.h"

#ifndef DRIVER_BUILD//HAUPPAUGE
const char* MCHIP_DRAM_BKV_FieldName[] = 
{
    "MEM_PLL",
    "LEFT_LS_READ_GATE_GUESS",
    "LEFT_MS_READ_GATE_GUESS",
    "RIGHT_LS_READ_GATE_GUESS",
    "RIGHT_MS_READ_GATE_GUESS",
    "DRAM_MR",
    "DRAM_EMR",
    "MEM_INTF_TIMING_CTRL",
    "MEM_INTF_ADD_CONFIG",
    "MEM_INTF_RFSH_CTRL",
    "MEM_INTF_LEFT_CMD_CTRL1",
    "SYS_PLL",
    "MEM_INTF_LEFT_CMD_CTRL2",
    "MEM_INTF_RIGHT_CMD_CTRL1",
    "MEM_INTF_RIGHT_CMD_CTRL2",
    "MEM_INTF_LEFT_DATA_CTRL",
    "MEM_INTF_RIGHT_DATA_CTRL",
    "LEFT_LS_READ_EYE_GUESS",
    "LEFT_MS_READ_EYE_GUESS",
    "RIGHT_LS_READ_EYE_GUESS",
    "SYS_PLL (copy, not used)",
    "RIGHT_MS_READ_EYE_GUESS",
    "MEM_INTF_DLL1",
    "MEM_INTF_DLL2",
    "MEM_INTF_LEFT_LS_DLL2",
    "MEM_INTF_LEFT_MS_DLL2",
    "MEM_INTF_RIGHT_LS_DLL2",
    "MEM_INTF_RIGHT_MS_DLL2",
    "MEM_INTF_LEFT_LS_DITRM",
    "MEM_INTF_LEFT_MS_DITRM",
    "MEM_INTF_RIGHT_LS_DITRM",
    "MEM_INTF_RIGHT_MS_DITRM",
    "MEMPLL_WORKAROUND_ATTEMPT",
    "MEMPLL_WORKAROUND_WAIT",
    "LEFT_ITM_READ_DELAY",
    "RIGHT_ITM_READ_DELAY",
    "VP_BOOT_MODE",
    "MCHIP_A2_GATE_SWEEP",
    "MCHIP_A2_ITM_SWEEP",
    "MCHIP_A2_DQ_SWEEP",
    "MCHIP_A2_DQS_SWEEP",
    "MEMTEST_MASK",
    "RESERVED1",
    "RESERVED2",
    "RESERVED3",
    "RESERVED4",
    "OTP_CONFIG_FLASH",
};

// FLASH base address for BKV config save
// for our purposes this is not significant
#define BKV_FLASH_BASE 0xFE0000

   

Boolean MCHIP_DRAM_BKV_Save(const char* filename, MCHIP_DRAM_BKV* bkv)
{
    FILE* f;
    Uint32 i;

    printf("MCHIP: saving BKV to file %s:\n", filename);

    f = fopen(filename, "wb");
    if (!f)
    {
        fprintf(stderr, "MCHIP: ERROR %d: cannot open file %s\n", __LINE__, filename);
        return FALSE;
    }

    if (fprintf(f, "1\n15\n11000000\n8\n0x%x\n1\n", BKV_FLASH_BASE) < 0)
    {
        fprintf(stderr, "MCHIP: ERROR %d: cannot write file %s\n", __LINE__, filename);
        fclose(f);
        return FALSE;
    }

    for (i = 0; i < MCHIP_DRAM_BKV_FieldCount; i++)
    {
        if (!fprintf(f, "# %s\n5\n0x%x\n0x%04x\n5\n0x%x\n0x%04x\n", 
                     MCHIP_DRAM_BKV_FieldName[i],
                     BKV_FLASH_BASE + 4*i, ((Uint32*)bkv)[i] >> 16,
                     BKV_FLASH_BASE + 4*i + 2, ((Uint32*)bkv)[i] & 0xFFFF))
        {
            fprintf(stderr, "MCHIP: ERROR %d: cannot write file %s\n", __LINE__, filename);
            fclose(f);
            return FALSE;
        }
    }

    if (fclose(f) == EOF)
    {
        fprintf(stderr, "MCHIP: ERROR %d: cannot close file %s\n", __LINE__, filename);
        return FALSE;
    }

    return TRUE;
}

void MCHIP_DRAM_BKV_Dump(const MCHIP_DRAM_BKV* bkv, const char* name)
{
    Uint32 i;

    assert(bkv);

    printf("static const MCHIP_DRAM_BKV %s = \n{\n", (name) ? name:"bkv");
    for (i = 0; i < MCHIP_DRAM_BKV_FieldCount; i++)
    {
        printf("    0x%08x, // %s\n", ((Uint32*)bkv)[i], MCHIP_DRAM_BKV_FieldName[i]);
    }
    printf("};\n");
}
#endif//DRIVER_BUILD//HAUPPAUGE


#ifndef DRIVER_BUILD
#define MCHIP_IDLE_TIMEOUT    100000
#else
#define MCHIP_IDLE_TIMEOUT    1000 // msec
#endif

// default values
#define MEM_INTF_CONFIG     0xCBA10000
#define DRAM_EMR2           0x00000000
#define DRAM_EMR3           0x00000000


static Uint32 mypow(Uint32 n, Uint32 count)
{
    Uint32   i;   
    Uint32 num=1;   

    for(i=0; i<count; i++)   
       num=num*n;   

    return num;  
}

static Uint32 pllCount(Uint32 val)
{
    uint64_t a, b;
    a = mypow(2,(32-((val>>28)&0xf)));
    b = ((val&0xfffffff)+1);

    return (Uint32)((24*a)/b);
}

Boolean
USBBootMChip_t::
MCHIP_DRAM_BKV_Init(const MCHIP_DRAM_BKV* bkv)
{
    Uint32 val32;
    //int i;
    //Uint32 tmp;

    // 1P is single-oscillator system
    // set MemPllSrc = 1 to source from CLKI

    if (!MCHIP_Write32(0xFFc20008, 0x00000001)) return FALSE;

    // ported version of bsp.system.init
#if 0
    // temp debug
    if (MCHIP_Read32(0xFFC20020, &val32)) DbgLogInfo(("MCHIP: before PLL set ByPassPLLMCfgReg=0x%08x\n", val32));
    if (MCHIP_Read32(0xFF030004, &val32)) DbgLogInfo(("MCHIP: before PLL set MemIntfCtrl=0x%08x\n", val32));
    if (MCHIP_Read32(0xFF030018, &val32)) DbgLogInfo(("MCHIP: before PLL set MemIntfRfshCtrl=0x%08x\n", val32));
#endif

    DbgLogInfo(("sys_pll: %d\n", pllCount(bkv->sys_pll)));

    // 9-Set system pll 
    if (!MCHIP_Write32(0xFFc20048, bkv->sys_pll)) return FALSE;
   
 
    // xx-Wait for 1.25ms
    // UsbWaituSec(1250);
    // temp lengthen delay 
#ifndef DRIVER_BUILD
    usleep(12500);
#else
	wrapSleep_ms(15);//ms
#endif

    DbgLogInfo(("mem_pll: %dMHz\n", pllCount(bkv->mem_pll)));

    // 12-Set Memory PLL
    if (!MCHIP_Write32(0xFFc2004c, bkv->mem_pll)) return FALSE;
 
    // 13-Wait for 1.25ms
    // UsbWaituSec(1250);
    // temp lengthen delay
#ifndef DRIVER_BUILD
    usleep(12500);
#else
	wrapSleep_ms(15);//ms
#endif

    // 17-Switch to DDR2 mode 256 MByte
    // MEM_INTF_CONFIG
    if (!MCHIP_Write32(0xFF030000, MEM_INTF_CONFIG)) return FALSE;

#if 0
    // temp debug
    if (MCHIP_Read32(0xFFC20020, &val32)) DbgLogInfo(("MCHIP: before idle ByPassPLLMCfgReg=0x%08x\n", val32));
    if (MCHIP_Read32(0xFF030004, &val32)) DbgLogInfo(("MCHIP: before idle MemIntfCtrl=0x%08x\n", val32));
    if (MCHIP_Read32(0xFF030018, &val32)) DbgLogInfo(("MCHIP: before idle MemIntfRfshCtrl=0x%08x\n", val32));
#endif

    // 18-Stop SDRAM controller
    // MEM_INTF_CTRL
    if (!MCHIP_Write32(0xFF030004, 0x00000001)) return FALSE;

    // wait for idle
	int timeout = MCHIP_IDLE_TIMEOUT/10;
    while(timeout--)
    {
        if (!MCHIP_Read32(0xFF030004, &val32)) return FALSE;
        
        // IdleStatus = 1?
        if (val32 & 0x01000000) break;

        // timed out?
		wrapSleep_ms(10);
	}
	if(timeout <= 0){
        DbgLogError(("MCHIP: %d: DRAM controller not idle after timeout, MemIntfCtrl=0x%08x\n", __LINE__, val32));
        if (MCHIP_Read32(0xFFC20020, &val32)) DbgLogInfo(("MCHIP: after timeout ByPassPLLMCfgReg=0x%08x\n", val32));
        if (MCHIP_Read32(0xFF030018, &val32)) DbgLogInfo(("MCHIP: after timeout MemIntfRfshCtrl=0x%08x\n", val32));
        return FALSE;
	}

#if 0
    // temp debug
    if (MCHIP_Read32(0xFF030004, &val32)) DbgLogInfo(("MCHIP: at idle MemIntfCtrl=0x%08x\n", val32));
#endif

    // # 19-Reset the PHY after a SDRAM freq change
    // # MEM_INTF_LEFT_CMD_CTRL2 MEM_INTF_RIGHT_CMD_CTRL2
    if (!MCHIP_Write32(0xff030284, 0x40000000)) return FALSE;
    if (!MCHIP_Write32(0xff03028C, 0x40000000)) return FALSE;
    // MEM_INTF_LEFT_LS_DLL2 MEM_INTF_LEFT_MS_DLL2
    if (!MCHIP_Write32(0xff0302A4, 0x40000000)) return FALSE;
    if (!MCHIP_Write32(0xff0302AC, 0x40000000)) return FALSE;
    // MEM_INTF_RIGHT_LS_DLL2 MEM_INTF_RIGHT_MS_DLL2
    if (!MCHIP_Write32(0xff0302C4, 0x40000000)) return FALSE;
    if (!MCHIP_Write32(0xff0302CC, 0x40000000)) return FALSE;

    // pcird -e7 -c$1 0xff0302cc
 
    // # MEM_INTF_CONFIG
    if (!MCHIP_Write32(0xFF030000, MEM_INTF_CONFIG)) return FALSE;
 
    // # 21-Set the SDRAM parameters 
    // # MEM_INTF_LEFT_DATA_CTRL MEM_INTF_RIGHT_DATA_CTRL
    if (!MCHIP_Write32(0xFF030290, bkv->mem_intf_left_data_ctrl)) return FALSE;
    if (!MCHIP_Write32(0xFF0302B0, bkv->mem_intf_right_data_ctrl)) return FALSE;
    // # MEM_INTF_LEFT_CMD_CTRL2 MEM_INTF_RIGHT_CMD_CTRL2
    if (!MCHIP_Write32(0xff030284, bkv->mem_intf_left_cmd_ctrl2)) return FALSE;
    if (!MCHIP_Write32(0xff03028C, bkv->mem_intf_right_cmd_ctrl2)) return FALSE;
    // # MEM_INTF_LEFT_LS_DLL2 MEM_INTF_LEFT_MS_DLL2
    if (!MCHIP_Write32(0xff0302A4, bkv->mem_intf_left_ls_dll2)) return FALSE;
    if (!MCHIP_Write32(0xff0302AC, bkv->mem_intf_left_ms_dll2)) return FALSE;
    // # MEM_INTF_RIGHT_LS_DLL2 MEM_INTF_RIGHT_MS_DLL2
    if (!MCHIP_Write32(0xff0302C4, bkv->mem_intf_right_ls_dll2)) return FALSE;
    if (!MCHIP_Write32(0xff0302CC, bkv->mem_intf_right_ms_dll2)) return FALSE;
    // # MEM_INTF_LEFT_CMD_CTRL1 MEM_INTF_RIGHT_CMD_CTRL1
    if (!MCHIP_Write32(0xff030280, bkv->mem_intf_left_cmd_ctrl1)) return FALSE;
    if (!MCHIP_Write32(0xff030288, bkv->mem_intf_right_cmd_ctrl1)) return FALSE;
    // # MEM_INTF_LEFT_LS_DLL1 MEM_INTF_LEFT_MS_DLL1
    if (!MCHIP_Write32(0xff0302A0, bkv->mem_intf_dll1)) return FALSE;
    if (!MCHIP_Write32(0xff0302A8, bkv->mem_intf_dll1)) return FALSE;
    // # MEM_INTF_RIGHT_LS_DLL1 MEM_INTF_RIGHT_MS_DLL1
    if (!MCHIP_Write32(0xff0302C0, bkv->mem_intf_dll1)) return FALSE;
    if (!MCHIP_Write32(0xff0302C8, bkv->mem_intf_dll1)) return FALSE;
    // # MEM_INTF_LEFT_LS_DITRM, MEM_INTF_LEFT_MS_DITRM
    if (!MCHIP_Write32(0xff030298, bkv->mem_intf_left_ls_ditrm)) return FALSE;
    if (!MCHIP_Write32(0xff03029C, bkv->mem_intf_left_ms_ditrm)) return FALSE;
    // # MEM_INTF_RIGHT_LS_DITRM, MEM_INTF_RIGHT_MS_DITRM
    if (!MCHIP_Write32(0xff0302B8, bkv->mem_intf_right_ls_ditrm)) return FALSE;
    if (!MCHIP_Write32(0xff0302BC, bkv->mem_intf_right_ms_ditrm)) return FALSE;

    // # MEM_INTF_TIMING_CTRL
    if (!MCHIP_Write32(0xFF030010, bkv->mem_intf_timing_ctrl)) return FALSE;
    // # MEM_INTF_ADD_CONFIG
    if (!MCHIP_Write32(0xFF030014, bkv->mem_intf_add_config)) return FALSE;
    // # MEM_INTF_RFSH_CTRL
    if (!MCHIP_Write32(0xFF030018, bkv->mem_intf_rfsh_ctrl)) return FALSE;
    // # DRAM_MR
    if (!MCHIP_Write32(0xFF030020, bkv->dram_mr)) return FALSE;
    // # DRAM_EMR
    if (!MCHIP_Write32(0xFF030024, bkv->dram_emr)) return FALSE;
    // # DRAM_EMR2
    if (!MCHIP_Write32(0xFF030028, DRAM_EMR2)) return FALSE;
    // # DRAM_EMR3
    if (!MCHIP_Write32(0xFF03002c, DRAM_EMR3)) return FALSE;
 
    // UsbWaituSec(1000);
    // temp lengthen delay
#ifndef DRIVER_BUILD
    usleep(10000);
#else
	wrapSleep_ms(10);//ms
#endif

#if 0
    // temp debug
    if (MCHIP_Read32(0xFFC20020, &val32)) DbgLogInfo(("MCHIP: before autoinit ByPassPLLMCfgReg=0x%08x\n", val32));
    if (MCHIP_Read32(0xFF030004, &val32)) DbgLogInfo(("MCHIP: before autoinit MemIntfCtrl=0x%08x\n", val32));
    if (MCHIP_Read32(0xFF030018, &val32)) DbgLogInfo(("MCHIP: before autoinit MemIntfRfshCtrl=0x%08x\n", val32));
#endif

    // # 23-Sdram start
    // MEM_INTF_CTRL
    if (!MCHIP_Write32(0xFF030004, 00000004)) return FALSE;

    // wait for not idle
	timeout = MCHIP_IDLE_TIMEOUT/10;
    while(timeout--)
    {
        if (!MCHIP_Read32(0xFF030004, &val32)) return FALSE;
        
        // IdleStatus = 0?
        if (!(val32 & 0x01000000)) break;

        // timed out?
		wrapSleep_ms(10);
	}
	if(timeout <= 0){
        DbgLogError(("MCHIP: %d: DRAM controller idle after timeout, MemIntfCtrl=0x%08x\n", __LINE__, val32));
        if (MCHIP_Read32(0xFFC20020, &val32)) DbgLogInfo(("MCHIP: after timeout ByPassPLLMCfgReg=0x%08x\n", val32));
        if (MCHIP_Read32(0xFF030018, &val32)) DbgLogInfo(("MCHIP: after timeout MemIntfRfshCtrl=0x%08x\n", val32));
        return FALSE;
	}

#if 0
    // temp debug
    if (MCHIP_Read32(0xFFC20020, &val32)) DbgLogInfo(("MCHIP: after autoinit ByPassPLLMCfgReg=0x%08x\n", val32));
    if (MCHIP_Read32(0xFF030004, &val32)) DbgLogInfo(("MCHIP: after autoinit MemIntfCtrl=0x%08x\n", val32));
    if (MCHIP_Read32(0xFF030018, &val32)) DbgLogInfo(("MCHIP: after autoinit MemIntfRfshCtrl=0x%08x\n", val32));
#endif

    DbgLogInfo(("MCHIP: DRAM init OK\n"));
    return TRUE;
}
