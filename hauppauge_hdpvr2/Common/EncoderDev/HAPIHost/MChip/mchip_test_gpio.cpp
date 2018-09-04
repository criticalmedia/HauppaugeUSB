//=============================================================================
//  File Name: mchip_test_gpio.c
//
//  Copyright 2009 Magnum Semiconductor Inc. All rights reserved.
//
//  Description:
//      Tests GPIOx connection from MCHIP-->Cypress.
//
//  Modification History:
//      $Id: $
//      $Log: $
//
//=============================================================================

#include "mchip.h"

Boolean
USBBootMChip_t::
MCHIP_Test_GPIOx(void)
{
    Boolean val;

    // configure GPIOx on MCHIP to output 0
    if (!MCHIP_GPIOx_Configure(0)) return FALSE;

    // read input
    if (!MCHIP_GPIOx_Read(&val)) return FALSE;
    if (val)
    {
        DbgLogError(("MCHIP: %d: set GPIOExt 0, read 1\n", __LINE__));
        return FALSE;
    }

    // set GPIOx on MCHIP to output 1
    if (!MCHIP_GPIOx_Set(1)) return FALSE;

    // read input
    if (!MCHIP_GPIOx_Read(&val)) return FALSE;
    if (!val)
    {
        DbgLogError(("MCHIP: %d: set GPIOExt 1, read 0\n", __LINE__));
        return FALSE;
    }

    // set GPIOx on MCHIP to output 0
    if (!MCHIP_GPIOx_Set(0)) return FALSE;

    // read input
    if (!MCHIP_GPIOx_Read(&val)) return FALSE;
    if (val)
    {
        DbgLogError(("MCHIP: %d: set GPIOExt 0, read 1\n", __LINE__));
        return FALSE;
    }

    DbgLogInfo(("MCHIP: GPIO input test OK\n"));
    return TRUE;
}
