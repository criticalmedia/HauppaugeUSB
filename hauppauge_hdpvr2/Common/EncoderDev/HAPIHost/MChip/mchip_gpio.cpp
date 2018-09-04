//=============================================================================
//  File Name: mchip_gpio.c
//
//  Copyright 2009 Magnum Semiconductor Inc. All rights reserved.
//
//  Description:
//      Configure/set/read MCHIP-->Cypress GPIOx line.
//      The GPIOx line is wired to a MCHIP GPIOExt pin.
//
//  Modification History:
//      $Id: $
//      $Log: $
//
//=============================================================================

#include "mchip.h"

// which GPIOEXT are we using?

//#if MCHIP_BOARD == MCHIP_BOARD_NITRO2
// Cypress dev board to Nitro2: PA0 <-- MCHIP_GPIOEXT53
//#define MCHIP_GPIOEXT_NUM 53
//#elif MCHIP_BOARD == MCHIP_BOARD_1P
// PA0 <-- MCHIP_GPIOEXT44
#define MCHIP_GPIOEXT_NUM 44
//#else
//#error unknown MCHIP_BOARD
//#endif

// We run some code to figure out which bits of which config register,
// and which bit of which value register, is controlling this GPIOExt pin.
// Note that production code might want to simply hard-code the relevant
// address and bit values.

// MCHIP GPIOExtConfig register 0-7 addresses
// careful, they are not contiguous
static const Uint32 MCHIP_GPIOEXTCONFIG[8] = 
{ 
    0xFF06F0B8,     // GPIOExtConfig0
    0xFF06F0BC,     // GPIOExtConfig1
    0xFF06F0C0,     // GPIOExtConfig2
    0xFF06F0C4,     // GPIOExtConfig3
    0xFF06F0C8,     // GPIOExtConfig4
    0xFF06F0D8,     // GPIOExtConfig5
    0xFF06F0DC,     // GPIOExtConfig6
    0xFF06F0E0      // GPIOExtConfig7
};

// MCHIP GPIOExtConfig register 0-7 number of GPIOs configured by each register
static const Uint8 MCHIP_GPIOEXTCONFIG_BITS[8] = 
{
    8,              // GPIOExtConfig0 controls GPIOExt[7:0]
    8,              // GPIOExtConfig1 controls GPIOExt[15:8]
    8,              // GPIOExtConfig2 controls GPIOExt[23:16]
    8,              // GPIOExtConfig3 controls GPIOExt[31:24]
    8,              // GPIOExtConfig4 controls GPIOExt[39:32]
    6,              // GPIOExtConfig5 controls GPIOExt[45:40]
    8,              // GPIOExtConfig6 controls GPIOExt[53:46]
    2,              // GPIOExtConfig7 controls GPIOExt[55:54]
};

// MCHIP GPIOExtValue register 0-2 addresses
// careful, they are not contiguous
static const Uint32 MCHIP_GPIOEXTVALUE[3] = 
{
    0xFF06F0CC,     // GPIOExtValue0
    0xFF06F0D0,     // GPIOExtValue1
    0xFF06F0E4,     // GPIOExtValue2
};

// MCHIP GPIOExtValue register 0-2 number of GPIOs set by each register
static const Uint8 MCHIP_GPIOEXTVALUE_BITS[3] = 
{
    24,             // GPIOExtValue0 sets GPIOExt[23:0]
    22,             // GPIOExtValue1=sets GPIOExt[45:24]
    10,             // GPIOExtValue2 sets GPIOExt[55:46]
};

// get the GPIOExtConfig register address and bit offset for the selected GPIO
void
USBBootMChip_t::
MCHIP_GPIO_Get_GPIOExtConfig(Uint8 gpio, Uint32* addr, Uint8* bit)
{
    Uint8 reg_num;

    ASSERT(gpio < 56);

    // find the relevant GPIOExt Configuration Register
    *bit = gpio;
    for (reg_num = 0; reg_num < 8; reg_num++)
    {
        if (*bit < MCHIP_GPIOEXTCONFIG_BITS[reg_num]) break;
        *bit -= MCHIP_GPIOEXTCONFIG_BITS[reg_num];
    }
    *bit *= 4;
    *addr = MCHIP_GPIOEXTCONFIG[reg_num];
    //printf("MCHIP: GPIOExt%d --> GPIOExtConfig%d[%d:%d] (0x%08x)\n", gpio, reg_num, *bit + 3, *bit, *addr);
}

// get the GPIOExtValue register address and bit offset for the selected GPIO
void
USBBootMChip_t::
MCHIP_GPIO_Get_GPIOExtValue(Uint8 gpio, Uint32* addr, Uint8* bit)
{
    Uint8 reg_num;

    ASSERT(gpio < 56);

    // find the relevant GPIOExt Value Register
    *bit = gpio;
    for (reg_num = 0; reg_num < 3; reg_num++)
    {
        if (*bit < MCHIP_GPIOEXTVALUE_BITS[reg_num]) break;
        *bit -= MCHIP_GPIOEXTVALUE_BITS[reg_num];
    }
    *bit += 1;
    *addr = MCHIP_GPIOEXTVALUE[reg_num];
    //printf("MCHIP: GPIOExt%d --> GPIOExtValue%d[%d] (0x%08x)\n", gpio, reg_num, *bit, *addr);

}

Boolean
USBBootMChip_t::
MCHIP_GPIOx_Configure(Boolean value)
{
    Uint32 addr;
    Uint8 bit;
    Uint32 val32;

    // get address, bit for relevant GPIOExt Configuration Register
    MCHIP_GPIO_Get_GPIOExtConfig(MCHIP_GPIOEXT_NUM, &addr, &bit);

    // configure as general purpose output

    // read
    if (!MCHIP_Read32(addr, &val32)) return FALSE;
    //printf("MCHIP: GPIOExtConfig=0x%08x\n", val32);
    // set appropriate nybble to 0x9 (Write Enable | General Purpose Output)
    if (!MCHIP_Write32(addr, 0x9 << bit)) return FALSE;
    // reread
    if (!MCHIP_Read32(addr, &val32)) return FALSE;
    //printf("MCHIP: GPIOExtConfig=0x%08x\n", val32);

    // get address, bit for relevant GPIOExt Value Register
    MCHIP_GPIO_Get_GPIOExtValue(MCHIP_GPIOEXT_NUM, &addr, &bit);

    // set to value
    if (!MCHIP_Read32(addr, &val32)) return FALSE;
    //printf("MCHIP: GPIOExtValue=0x%08x\n", val32);
    if (!MCHIP_Write32(addr, (1 << bit) | (value ? 1:0))) return FALSE;
    if (!MCHIP_Read32(addr, &val32)) return FALSE;
    //printf("MCHIP: GPIOExtValue=0x%08x\n", val32);

    return TRUE;
}

Boolean
USBBootMChip_t::
MCHIP_GPIOx_Set(Boolean value)
{
    Uint32 addr;
    Uint8 bit;
    Uint32 val32;

    // get address, bit for relevant GPIOExt Value Register
    MCHIP_GPIO_Get_GPIOExtValue(MCHIP_GPIOEXT_NUM, &addr, &bit);

    // set to value
    if (!MCHIP_Read32(addr, &val32)) return FALSE;
    //printf("MCHIP: GPIOExtValue=0x%08x\n", val32);
    if (!MCHIP_Write32(addr, (1 << bit) | (value ? 1:0))) return FALSE;
    if (!MCHIP_Read32(addr, &val32)) return FALSE;
    //printf("MCHIP: GPIOExtValue=0x%08x\n", val32);

    return TRUE;
}

Boolean
USBBootMChip_t::
MCHIP_GPIOx_Read(Boolean* value)
{
    ASSERT(value);

    // read from Cypress PA0
    if (!MCHIP_PortA_Get_MCHIP_GPIOx(value)) return FALSE;
    return TRUE;
}
