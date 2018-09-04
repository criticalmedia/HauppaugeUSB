//=============================================================================
//  File Name: mchip_test_led.c
//
//  Copyright 2009 Magnum Semiconductor Inc. All rights reserved.
//
//  Description:
//      Tests LED LED on MCHIP GPIOExt pin.
//
//  Modification History:
//      $Id: $
//      $Log: $
//
//=============================================================================

#include "mchip.h"

Boolean
USBBootMChip_t::
MCHIP_Test_LED(Uint8 gpio)
{
    int i;
    DbgLogInfo(("MCHIP_Test_LED(%u)\n", gpio));

    // configure LED on MCHIP to off
    if (!MCHIP_LED_Configure(gpio, 0)) return FALSE;

    // flash LED on/off 3 times 
    for (i = 0; i < 3; i++)
    {
		wrapSleep_ms(200);//ms
        // set LED on
        if (!MCHIP_LED_Set(gpio, 1)) return FALSE;
		wrapSleep_ms(200);//ms
        // set LED off
        if (!MCHIP_LED_Set(gpio, 0)) return FALSE;
    }

    return TRUE;
}
