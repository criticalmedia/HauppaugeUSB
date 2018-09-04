#include "mchip.h"

USBBootMChip_t::USBBootMChip_t(FX2Device_t &_fx2) :
fx2(_fx2),
prevOutLen(0),
gSbpFreq(SBP_FREQ_30),
maxSBP0Blocks(32), //allows 16384 bytes SBP0 send for FW download
_SBPtimeout(1100) //good for 256Kbps and above streaming rate
{
	resetWFMode();
	resetUsbError();
	wrapMutexInit(&_mutex);
	wrapMutexInit(&_mutexBus);

	DbgLogInfo(("USBBootMChip_t::USBBootMChip_t(%p)\n", &fx2));

#if DBG
	memset(sav_port_state, 0xcc, sizeof(sav_port_state));

	//Verify initial HW conditions
	BYTE value;
	BYTE i;
	for(i=0; i<5; i++){
		if(!UsbGetPortDir(i, &value))
			break;
		DbgLogInfo((" Cypress Port dir %d=0x%02x\n", i, value));
	}
	for(i=0; i<5; i++){
		if(!UsbGetPortState(i, &value))
			break;
		DbgLogInfo((" Cypress Port value %d=0x%02x\n", i, value));
	}
#endif
	//FGR - support tuning how much data is sent over USB per SBP0 "write"
	// default=32 (*512)=16384 bytes
	hcwGetRegistryDWORD("maxSBP0Blocks", &maxSBP0Blocks);
	if((maxSBP0Blocks == 0) || (maxSBP0Blocks > 64)){
		maxSBP0Blocks = 32;
	}
}

USBBootMChip_t::~USBBootMChip_t()
{
	DbgLogInfo(("USBBootMChip_t::~USBBootMChip_t(%p)\n", &fx2));
	wrapMutexDestroy(&_mutexBus);
	wrapMutexDestroy(&_mutex);
}

VOID USBBootMChip_t::lock()
{
	wrapMutexLock(&_mutex);
}

VOID USBBootMChip_t::unlock()
{
	wrapMutexUnlock(&_mutex);
}

VOID USBBootMChip_t::lockBus()
{
	wrapMutexLock(&_mutexBus);
}

VOID USBBootMChip_t::unlockBus()
{
	wrapMutexUnlock(&_mutexBus);
}

Boolean USBBootMChip_t::hadUsbError(const char *function)
{
	if(statusCnt > USB_ERR_LIMIT){
		return true;
	}
#if 0
	if(_p_device->IsBoardRemoved()){
		DbgLogError(("hadUsbError() called from %s: IsBoardRemoved()==TRUE\n", function));
		statusCnt = USB_ERR_LIMIT+1;
		statusErr = STATUS_DEVICE_REMOVED;
		return true;
	}
#endif
	if(statusCnt == 0){
		return false;
	}
	if(statusCnt == USB_ERR_LIMIT){
		DbgLogWarn(("hadUsbError() called from %s: too many errors\n", function));
		statusCnt++;
	}
	return false;
}

VOID USBBootMChip_t::setUsbError(const char *function, int line)
{
	if(statusCnt > USB_ERR_LIMIT){
		return;
	}
	statusErr = STATUS_UNSUCCESSFUL;
	statusCnt = USB_ERR_LIMIT+1;
	DbgLogError(("setUsbError() called from %s, %d:\n", function, line));
	return;
}

VOID USBBootMChip_t::resetUsbError()
{
	statusErr = STATUS_SUCCESS;
	statusCnt = 0;
	prevOutLen= 0; 
	//DbgLogInfo(("USBBootMChip_t::resetUsbError()\n"));
	return;
}

#if 1//FGR: untested, and currently unused, but might be useful when interface gets hosed during startup

VOID USBBootMChip_t::resetUsbPipes()
{
	int status;
//	DbgLogInfo(("USBBootMChip_t::resetUsbPipes()\n"));
	// reset SBP in/out pipes
	status = fx2.usb.abort(FX2_EP_SBP_WR);
	status = fx2.usb.clearStall(FX2_EP_SBP_WR);
	if (status != USBWRAP_SUCCESS)
	{
		DbgLogError(("USBBootMChip_t::resetUsbPipes(), Failed to reset FX2_EP_SBP_WR %x\n", status));
	}
	status = fx2.usb.abort(FX2_EP_SBP_RD);
	status = fx2.usb.clearStall(FX2_EP_SBP_RD);
	if (!NT_SUCCESS(status))
	{
		DbgLogError(("USBBootMChip_t::resetUsbPipes(), Failed to reset FX2_EP_SBP_RD %x\n", status));
	}
	resetUsbError();
	return;
}
#endif
