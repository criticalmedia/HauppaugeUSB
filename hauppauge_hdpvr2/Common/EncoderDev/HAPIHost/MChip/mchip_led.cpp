//=============================================================================
//  File Name: mchip_led.c
//
//  Copyright 2009 Magnum Semiconductor Inc. All rights reserved.
//
//  Description:
//      Configure/set LED on MCHIP GPIOExt pin.
//
//  Modification History:
//      $Id: $
//      $Log: $
//
//=============================================================================

#include "mchip.h"

Boolean
USBBootMChip_t::
MCHIP_LED_Configure(Uint8 gpio, Boolean value)
{
    Uint32 addr;
    Uint8 bit;
    Uint32 val32;

    // get address, bit for relevant GPIOExt Configuration Register
    MCHIP_GPIO_Get_GPIOExtConfig(gpio, &addr, &bit);

    // configure as general purpose output

    // read
    if (!MCHIP_Read32(addr, &val32)) return FALSE;
    DbgLogTrace(("MCHIP: GPIOExtConfig=0x%08x\n", val32));
    // set appropriate nybble to 0x9 (Write Enable | General Purpose Output)
    if (!MCHIP_Write32(addr, 0x9 << bit)) return FALSE;
    // reread
    if (!MCHIP_Read32(addr, &val32)) return FALSE;
    DbgLogTrace(("MCHIP: GPIOExtConfig=0x%08x\n", val32));

    MCHIP_LED_Set(gpio, value);

    return TRUE;
}

Boolean
USBBootMChip_t::
MCHIP_LED_Set(Uint8 gpio, Boolean value)
{
    Uint32 addr;
    Uint8 bit;
    Uint32 val32;

    // get address, bit for relevant GPIOExt Value Register
    MCHIP_GPIO_Get_GPIOExtValue(gpio, &addr, &bit);

    // set to value
    // note LED drive is active-high, so write 1 to light LED
    if (!MCHIP_Read32(addr, &val32)) return FALSE;
    DbgLogTrace(("MCHIP: GPIOExtValue=0x%08x\n", val32));
    if (!MCHIP_Write32(addr, (1 << bit) | (value ? 1:0))) return FALSE;
    if (!MCHIP_Read32(addr, &val32)) return FALSE;
    DbgLogTrace(("   new GPIOExtValue=0x%08x\n", val32));

    return TRUE;
}

Boolean
USBBootMChip_t::
MCHIP_LED_Get(Uint8 gpio)
{
    Uint32 addr;
    Uint8 bit;
    Uint32 val32;

    // get address, bit for relevant GPIOExt Value Register
    MCHIP_GPIO_Get_GPIOExtValue(gpio, &addr, &bit);

    // get the value
    if (!MCHIP_Read32(addr, &val32)) return FALSE;
    DbgLogTrace(("MCHIP: GPIOExtValue=0x%08x\n", val32));

    return (Boolean)((val32 & (1 << bit))?1:0);
}
