#include "mchip.h"

// Cypress Port A pin definitions
#define PA_MCHIP_GPIOX_SHIFT      0                   // PA0 <-- MCHIP_GPIOx input     
#define PA_MCHIP_GPIOX_MSK        0x01
#define PA_HST_SELECT_SHIFT     1                   // PA1 --> HST_SELECT* output
#define PA_HST_SELECT_MSK       0x02
#define PA_MCHIP_RESET_SHIFT      2                   // PA2 --> MCHIP_RESET* output
#define PA_MCHIP_RESET_MSK        0x04
#define PA_POWER_ENABLE_SHIFT   3                   // PA3 --> POWER_ENABLE output
#define PA_POWER_ENABLE_MSK     0x08
#define PA_HST_ADR_SHIFT        4                   // PA4,5,6 --> HST_ADR1,2,3 output
#define PA_HST_ADR_MSK          0x70
#define PA_HST_RDWR_SHIFT       7                   // PA7 --> HST_RD/WR* output
#define PA_HST_RDWR_MSK         0x80


Boolean
USBBootMChip_t::
MCHIP_PortA_Init(void)
{
    // Port A directions
    static const BYTE init_dir_port_a =
                      /* MCHIP_GPIOX_MSK | */         // PA0 <-- MCHIP_GPIOx input       
#ifndef HCW_E5BDA
                      PA_HST_SELECT_MSK |           // PA1 --> HST_SELECT* output
#endif
                      PA_MCHIP_RESET_MSK |            // PA2 --> MCHIP_RESET* output
                      PA_POWER_ENABLE_MSK |         // PA3 --> POWER_ENABLE output
                      PA_HST_ADR_MSK |              // PA4,5,6 --> HST_ADR1,2,3 output
                      PA_HST_RDWR_MSK;              // PA7 --> HST_RD/WR* output
    BYTE dir_port_a = init_dir_port_a;

    // Port A initial values
    // power off, MCHIP reset held
    static const BYTE init_val_port_a =
                      /* MCHIP_GPIOX_MSK | */         // PA0 <-- MCHIP_GPIOx = don't-care         
                      /* PA_HST_SELECT_MSK | */     // PA1 --> HST_SELECT* = 0
                      /* PA_MCHIP_RESET_MSK | */      // PA2 --> MCHIP_RESET* = 0
                      /* PA_POWER_ENABLE_MSK | */   // PA3 --> POWER_ENABLE = 0
                      /* PA_HST_RDWR_MSK | */       // PA4,5,6 --> HST_ADR1,2,3 = 0
                      /* PA_HST_RDWR_MSK */ 0;      // PA7 --> HST_RD/WR* = 0
    BYTE val_port_a = init_val_port_a;

    // set initial state

	lock();
#ifdef HCW_E5BDA
    if (!UsbGetPortState(0, &val_port_a))
    {
        DbgLogError(("MCHIP_PortA_Init: UsbGetPortState failed\n"));
		unlock();
        return FALSE;
    }
	val_port_a &= 0x03; //Leave PA.0 and PA.1 alone; Siena2 uses them
	val_port_a |= (init_val_port_a & ~0x03);
#endif
    if (!UsbSetPortState(0, val_port_a))
    {
        DbgLogError(("MCHIP_PortA_Init: UsbSetPortState failed\n"));
		unlock();
        return FALSE;
    }

#ifdef HCW_E5BDA
    if (!UsbGetPortDir(0, &dir_port_a))
    {
        DbgLogError(("MCHIP_PortA_Init: UsbGetPortDir failed\n"));
		unlock();
        return FALSE;
    }
	dir_port_a &= 0x03; //Leave PA.0 and PA.1 alone; Siena2 uses them
	dir_port_a |= (init_dir_port_a & ~0x03);
#endif
    if (!UsbSetPortDir(0, dir_port_a))
    {
        //fprintf(stderr, "UsbSetPortDir failed: error %d\n", UsbGetError());
		DbgLogError(("MCHIP_PortA_Init: UsbSetPortDir failed\n"));
		unlock();
        return FALSE;
    }

#ifdef HCW_E5BDA
	//PC.1 --> HST_SELECT* output is assumed to be set in the Cypress FW!!
    BYTE val_port_c = 0;
	UsbGetPortState(2, &val_port_c);

	val_port_c &= ~PA_HST_SELECT_MSK; //PC.1 --> HST_SELECT* = 0

	if (!UsbSetPortState(2, val_port_c))
    {
        DbgLogError(("MCHIP_PortA_Init: UsbSetPortState(2, 0x%x) failed\n", val_port_c));
		unlock();
        return FALSE;
    }
#endif

    // record current state
    prv_port_a = val_port_a;

	unlock();
    return TRUE;
}

Boolean
USBBootMChip_t::
MCHIP_PortA_Get_MCHIP_GPIOx(Boolean* value)
{
    BYTE val_port_a;

    ASSERT(value);

    // get current state of input
	lock();

#ifndef HCW_E5BDA
    if (!UsbGetPortState(0, &val_port_a))
#else
	if (!UsbGetPortState(2, &val_port_a))
#endif
    {
        DbgLogError(("MCHIP_PortA_Get_MCHIP_GPIOx: UsbGetPortState failed\n"));
		unlock();
        return FALSE;
    }

    *value = (val_port_a & PA_MCHIP_GPIOX_MSK) ? TRUE:FALSE;
	unlock();
    return TRUE;
}

Boolean
USBBootMChip_t::
MCHIP_PortA_Set_HST_SELECT_L(Boolean value)
{
    // update output if state has changed
	lock();
//  BYTE new_port_a = (prv_port_a & ~PA_HST_SELECT_MSK) | ((value) ? PA_HST_SELECT_MSK:0x00);
//	DbgLogTrace(("MCHIP_PortA_Set_HST_SELECT_L: new_port_a=0x%x prv_port_a=0x%x\n", new_port_a, prv_port_a));

//  if (new_port_a != prv_port_a)
    {
#ifndef HCW_E5BDA
        if (!UsbSetPortState(0, new_port_a))
#else
		BYTE val_port_c = 0;
		UsbGetPortState(2, &val_port_c);
		
#if DBG
		BYTE dir_port_c = 0;
		UsbGetPortDir(2, &dir_port_c);
		
		DbgLogTrace(("MCHIP_PortA_Set_HST_SELECT_L: Port C dir=0x%x state=0x%x\n", dir_port_c, val_port_c));
#endif
		val_port_c &= ~PA_HST_SELECT_MSK;
		val_port_c |= ((value) ? PA_HST_SELECT_MSK:0x00);
		if (!UsbSetPortState(2, val_port_c))
#endif
        {
            DbgLogError(("MCHIP_PortA_Set_HST_SELECT_L() UsbSetPortState failed\n"));
			unlock();
            return FALSE;
        }
    }
//  prv_port_a = new_port_a;
	unlock();
    return TRUE;
}

Boolean
USBBootMChip_t::
MCHIP_PortA_Set_MCHIP_RESET_L(Boolean value)
{
    // update output if state has changed
	lock();
    BYTE new_port_a = (prv_port_a & ~PA_MCHIP_RESET_MSK) | ((value) ? PA_MCHIP_RESET_MSK:0x00);

    if (new_port_a != prv_port_a)
    {
        if (!UsbSetPortState(0, new_port_a))
        {
            DbgLogError(("MCHIP_PortA_Set_MCHIP_RESET_L: UsbSetPortState failed\n"));
			unlock();
            return FALSE;
        }
    }
    
    prv_port_a = new_port_a;
	unlock();
    return TRUE;
}

#define PC_POWER_ENABLE2_MSK 0x80 //starting with -03 siena

Boolean
USBBootMChip_t::
MCHIP_PortA_Set_POWER_ENABLE_H(Boolean value)
{
    // update output if state has changed
	lock();
    BYTE new_port_a = (prv_port_a & ~PA_POWER_ENABLE_MSK) | ((value) ? PA_POWER_ENABLE_MSK:0x00);

    if (new_port_a != prv_port_a)
    {
#if 0//def HCW_E5BDA//FGR - now handled in Cypress FW
		//FGR - for Siena -03 make sure that PWR_EN2 starts disabled
		BYTE val_port_c = 0;
		UsbGetPortState(2, &val_port_c);
		
		BYTE dir_port_c = 0;
		UsbGetPortDir(2, &dir_port_c);
		
		DbgLogTrace(("MCHIP_PortA_Set_POWER_ENABLE_H: Port C dir=0x%x state=0x%x\n", dir_port_c, val_port_c));

		if(value){
			val_port_c &= ~PC_POWER_ENABLE2_MSK;
			if (!UsbSetPortState(2, val_port_c)){
				DbgLogError(("MCHIP_PortA_Set_POWER_ENABLE_H: UsbSetPortState(2,) failed!!\n"));
				unlock();
				return FALSE;
			}
		}
		dir_port_c |= PC_POWER_ENABLE2_MSK;
		UsbSetPortDir(2, dir_port_c);
#endif
        if (!UsbSetPortState(0, new_port_a))
        {
            DbgLogError(("MCHIP_PortA_Set_POWER_ENABLE_H: UsbSetPortState failed!!\n"));
			unlock();
            return FALSE;
        }
#if 0//def HCW_E5BDA//FGR - now handled in Cypress FW
		if(value){
			wrapSleep_ms(10); //wait for core to come up to nominal voltage
			val_port_c |= PC_POWER_ENABLE2_MSK; //Enable 1.8v DDR and 3.3v IO ring
		} else {
			val_port_c &= ~PC_POWER_ENABLE2_MSK;
		}
		UsbSetPortState(2, val_port_c);
		wrapSleep_ms(70);
#endif
    }

    prv_port_a = new_port_a;
	unlock();
    return TRUE;
}

Boolean
USBBootMChip_t::
MCHIP_PortA_Set_HST_ADR_RDWR_L(Uint8 addr, Boolean rdwr)
{
    BYTE new_port_a;

    // host address must be in range 0:7
    ASSERT((addr & ~0x7) == 0x00);

    // update output if state has changed
	lock();
    new_port_a = (prv_port_a & ~(PA_HST_ADR_MSK | PA_HST_RDWR_MSK)) | (addr << PA_HST_ADR_SHIFT) | ((rdwr) ? PA_HST_RDWR_MSK:0x00);
    if (new_port_a != prv_port_a)
    {
        if (!UsbSetPortState(0, new_port_a))
        {
            DbgLogError(("MCHIP_PortA_Set_HST_ADR_RDWR_L: UsbSetPortState failed: error\n"));
			unlock();
            return FALSE;
        }
    }

    prv_port_a = new_port_a;
	unlock();
    return TRUE;
}

Boolean
USBBootMChip_t::
MCHIP_Reset_Cypress()
{
	lock();
	BYTE val_port_a = 0;
	UsbGetPortState(0, &val_port_a);
	val_port_a &= ~0x01; //clear PA.0
	
	BYTE dir_port_a = 0;
	UsbGetPortDir(0, &dir_port_a);
	dir_port_a |= 0x01; //Enable PA.0 as output

    if (!UsbSetPortDir(0, dir_port_a))
    {
        DbgLogError(("MCHIP_Reset_Cypress() UsbSetPortDir failed: error\n"));
		unlock();
        return FALSE;
    }
    if (!UsbSetPortState(0, val_port_a))
    {
        DbgLogError(("MCHIP_Reset_Cypress() UsbSetPortState failed: error\n"));
		unlock();
        return FALSE;
    }
    DbgLogWarn(("MCHIP_Reset_Cypress() CYPRESS should be reset now!!!\n"));
	unlock();
	return TRUE;
}
