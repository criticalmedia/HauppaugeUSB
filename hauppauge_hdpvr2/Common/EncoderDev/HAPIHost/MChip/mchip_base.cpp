#include "mchip.h"

#include <string.h>

#define TRANSFER_TIMEOUT 3000

#define HIGH_BYTE(addr) ((BYTE)(addr>>8))
#define LOW_BYTE(addr) ((BYTE)(addr&0xFF))

#define MSB(p)    (BYTE)(((p) & 0xFF00)>>8)
#define LSB(p)     (BYTE)((p) & 0xFF)

DWORD
USBBootMChip_t::
UsbReadWrite(DWORD fRead, const BYTE * setupdat, void* pBuffer,
             WORD wBufferSize, DWORD * pdwBytesTransferred, DWORD dwTimeout)
{
	WRAP_ATOMIC_SCOPE;
	USBWrapperControlMessage_t cm;
	int ret;
	DWORD rst;

	memcpy((void*)&cm, setupdat, 8);
	cm.bmRequestType = fRead ? USBWRAP_CM_DEVICE_VENDOR_RD : USBWRAP_CM_DEVICE_VENDOR_WR; // Device / Vendor
	cm.wLength = wBufferSize;
	ret = fx2.usb.controlMessage(cm, (uint8_t*)pBuffer, dwTimeout);
	if(ret >= 0) {
		rst = 0;
		*pdwBytesTransferred = ret;
		statusErr = 0;
		statusCnt = 0;
	} else {
		rst = 1;
		DbgLogError(("UsbReadWrite(%d, ) failed 0x%08X\n", fRead, ret));
		statusErr = ret;
		statusCnt++;
	}

	return rst;
}

DWORD
USBBootMChip_t::
UsbReadWriteBulk(DWORD fRead, void* pBuffer,
             WORD wBufferSize, DWORD * pdwBytesTransferred, DWORD dwTimeout)
{
	WRAP_ATOMIC_SCOPE;
	if(hadUsbError("UsbReadWriteBulk")) {
		return 1;
	}
	DWORD rst;
	int ret;

#if 0 // seems not required

	USBWrapperAsyncCtx_t actx;

	if(fRead) {
//		wrapLogDebug("Trying read hack: begin");
		ret = fx2.usb.bulkReadAsync(actx, FX2_EP_SBP_RD, (uint8_t*)pBuffer, wBufferSize, dwTimeout);
		if(actx.getState() == USBWRAP_PENDING) {
			uint8_t cr;
			uint16_t stublen = wBufferSize % 1024;
			uint16_t loops = wBufferSize / 1024;
			USBWrapperControlMessage_t cm;
			cm.bmRequestType = USBWRAP_CM_DEVICE_VENDOR_RD;
			cm.wValue = stublen;
			cm.wIndex = loops;
			cm.wLength = 1;
			cm.bRequest = VR_INPACKETLEN;
			fx2.usb.controlMessage(cm, &cr, dwTimeout); // TODO: AVS_Capture/CUSBINTF.CPP must be used by idea
		}
//		wrapLogDebug("Trying read hack: waiting...");
		actx.wait();
//		wrapLogDebug("Trying read hack: done");
		ret = (actx.result == USBWRAP_SUCCESS) ? actx.size : actx.result;
	} else {
		ret = fx2.usb.bulkWrite(FX2_EP_SBP_WR, (uint8_t*)pBuffer, wBufferSize, dwTimeout);
	}

#else

	if(fRead) {
		uint8_t cr;
		uint16_t stublen = wBufferSize % 1024;
		uint16_t loops = wBufferSize / 1024;
		USBWrapperControlMessage_t cm;
		cm.bmRequestType = USBWRAP_CM_DEVICE_VENDOR_RD;
		cm.wValue = stublen;
		cm.wIndex = loops;
		cm.wLength = 1;
		cm.bRequest = VR_INPACKETLEN;
		fx2.usb.controlMessage(cm, &cr, dwTimeout);
		ret = fx2.usb.bulkRead(FX2_EP_SBP_RD, (uint8_t*)pBuffer, wBufferSize, dwTimeout);
	} else {
		ret = fx2.usb.bulkWrite(FX2_EP_SBP_WR, (uint8_t*)pBuffer, wBufferSize, dwTimeout);
	}

#endif

	if(ret >= 0) {
		rst = 0;
		*pdwBytesTransferred = ret;
		statusErr = 0;
		statusCnt = 0;
	} else if(ret == USBWRAP_ERROR_TIMEOUT) {
		rst = 2;
		if(dwTimeout < 1500) {
			DbgLogInfo(("UsbReadWriteBulk() TIMEOUT(%d) (recovery)!\n", dwTimeout));
			statusErr = 0;
			statusCnt = 0;
		} else {
			DbgLogError(("UsbReadWriteBulk() TIMEOUT(%d)!\n", dwTimeout));
		}
	} else {
		DbgLogError(("UsbReadWriteBulk() failed 0x%x\n", ret));
		rst = 1;
		statusErr = ret;
		statusCnt++;
	}

	if(ret < 0){
		if(fRead) {
			uint8_t cr;
			USBWrapperControlMessage_t cm;
			cm.bmRequestType = USBWRAP_CM_DEVICE_VENDOR_RD;
			cm.wValue = 0;
			cm.wIndex = 0;
			cm.wLength = 1;
			cm.bRequest = VR_INPACKETLEN;
			fx2.usb.controlMessage(cm, &cr, dwTimeout); // TODO: AVS_Capture/CUSBINTF.CPP must be used by idea
		}
	}

	return rst;
}

BOOL
USBBootMChip_t::
UsbSetClk(BYTE clk)
{
    BOOL rst = FALSE;
    DWORD dwBytesTransferred;
    BYTE setup[8];
    BYTE buf;

	memset(setup, 0, sizeof(setup));

	if(hadUsbError("UsbSetClk")){
		return FALSE;
	}
    setup[1] = VR_CPUCLK;
    setup[2] = clk;

    if( 0 != UsbReadWrite(TRUE, (BYTE *)(&setup[0]), (void *)&buf, 8, &dwBytesTransferred, TRANSFER_TIMEOUT) )
    {
        DbgLogError(("set clk error\n"));
        rst = FALSE;
    }

    if( buf == 1 )
        rst = TRUE;
    else
        rst = FALSE;

    return rst;
}

BOOL
USBBootMChip_t::
UsbEEpSetAddr(BYTE addr)
{
    BOOL rst = FALSE;
    DWORD dwBytesTransferred;
    Usb_I2C_SetupDat setupdat;
    BYTE buf;
	memset(&setupdat, 0, sizeof(setupdat));

	if(hadUsbError("UsbEEpSetAddr")){
		return FALSE;
	}

    setupdat.vrOpcode = VR_I2C;
    setupdat.vrOpType = I2C_SETADR;
    setupdat.i2cAdr = addr;

    if( 0 != UsbReadWrite(TRUE, (BYTE *)(&setupdat), (void *)&buf, 1, &dwBytesTransferred, TRANSFER_TIMEOUT) )
    {
        DbgLogError(("set i2c addr err\n"));
        rst = FALSE;
    }
    if( buf == 1 )
        rst = TRUE;
    else
        rst = FALSE;
    
    return rst;
}


BOOL
USBBootMChip_t::
UsbEEpReadBytes(WORD addr, BYTE len, BYTE *data)
{
    BOOL rst = FALSE;
    DWORD dwBytesTransferred;
    Usb_I2C_SetupDat setupdat;
    BYTE *buf;
    int i=0;
	memset(&setupdat, 0, sizeof(setupdat));

	if(hadUsbError("UsbEEpReadBytes")){
		return FALSE;
	}

    buf = data;
    setupdat.vrOpcode = VR_I2C;
    setupdat.vrOpType = I2C_READ;
    setupdat.slaveAdrLo= addr&0xff;
    setupdat.slaveAdrHi= (addr>>8)&0xff;
    setupdat.dataLen = len;
    if( 0 != UsbReadWrite(TRUE, (BYTE *)(&setupdat), (void *)buf, len, &dwBytesTransferred, TRANSFER_TIMEOUT) )
    {
        DbgLogError(("get i2c data err\n"));
        rst = FALSE;
    }
    else
    {
        
        //for(i=0;i<len;i++)
        //DbgLogTrace(("data[%d] = %x, addr = %d\n", i, buf[i], addr+i));
        rst = TRUE;
    }

    return rst;
}


BOOL
USBBootMChip_t::
UsbSetPortDir(BYTE portNum, BYTE dir)
{
	WRAP_ATOMIC_SCOPE;
    BOOL rst = FALSE;
    Usb_Port_SetupDat setupdat;
    BYTE buf;
    DWORD dwBytesTransferred;
	memset(&setupdat, 0, sizeof(setupdat));

	if(0/*hadUsbError("UsbSetPortState")*/){
		return FALSE;
	}
	DbgLogTrace(("UsbSetPortDir(%d, 0x%02x)\n", portNum, dir));
    
    setupdat.vrOpcode = VR_PORT_SETTING;
    setupdat.portNum = portNum;
    setupdat.portOp = OP_DIR;
    setupdat.portSetting = dir;

    if( 0 != UsbReadWrite(TRUE, (BYTE *)(&setupdat), (void *)&buf, 1, &dwBytesTransferred, TRANSFER_TIMEOUT) )
    {
        DbgLogError(("set port dir err\n"));
        rst = FALSE;
    }
    if( buf == 1 )
        rst = TRUE;
    else
        rst = FALSE;
    
    return rst;
}

BOOL
USBBootMChip_t::
UsbSetPortState(BYTE portNum, BYTE state)
{
	WRAP_ATOMIC_SCOPE;
    BOOL rst = FALSE;
    Usb_Port_SetupDat setupdat;
    BYTE buf;
    DWORD dwBytesTransferred;
    DWORD tmp;
	memset(&setupdat, 0, sizeof(setupdat));

	if(0/*hadUsbError("UsbSetPortState")*/){
		return FALSE;
	}
 #if DBG
	if(portNum >= sizeof(sav_port_state)){
		DbgLogError(("UsbSetPortState(%d) Illegal portNum\n", portNum));
		return FALSE;
	}
	if(portNum && (sav_port_state[portNum] != state)){
		sav_port_state[portNum] = state;
		DbgLogTrace(("UsbSetPortState(%d, 0x%02x)\n", portNum, state));
	}
 #endif

    setupdat.vrOpcode = VR_PORT_SETTING;
    setupdat.portNum = portNum;
    setupdat.portOp = OP_SET_STATE;
    setupdat.portSetting = state;

    tmp = UsbReadWrite(TRUE, (BYTE *)(&setupdat), (void *)&buf, 1, &dwBytesTransferred, TRANSFER_TIMEOUT);
    if( 0 != tmp )
    {
        DbgLogError(("UsbSetPortState(%d, 0x%02x) FAILED\n", portNum, state));
        rst = FALSE;
    }
    if( buf == 1 )
        rst = TRUE;
    else
        rst = FALSE;
    
    return rst;
}

BOOL
USBBootMChip_t::
UsbGetPortState(BYTE portNum, BYTE * state)
{
	WRAP_ATOMIC_SCOPE;
    BOOL rst = FALSE;
    Usb_Port_SetupDat setupdat;
    BYTE buf;
    DWORD dwBytesTransferred;
	memset(&setupdat, 0, sizeof(setupdat));

	if(0/*hadUsbError("UsbSetPortState")*/){
		return FALSE;
	}
 #if DBG
	if(portNum >= sizeof(sav_port_state)){
		DbgLogError(("UsbGetPortState(%d) Illegal portNum\n", portNum));
		return FALSE;
	}
 #endif

    setupdat.vrOpcode = VR_PORT_SETTING;
    setupdat.portNum = portNum;
    setupdat.portOp = OP_GET_STATE;

    if( 0 != UsbReadWrite(TRUE, (BYTE *)(&setupdat), (void *)&buf, 1, &dwBytesTransferred, TRANSFER_TIMEOUT) )
    {
        DbgLogError(("UsbGetPortState(%d) FAILED\n", portNum));
        rst = FALSE;
    }
    else
    {
#if DBG//HAUPPAUGE
		if(sav_port_state[portNum] != buf){
			sav_port_state[portNum] = buf;
			DbgLogTrace(("UsbGetPortState(%d) =0x%02x\n", portNum, buf));
		}
		if((portNum == 0) && ((prv_port_a&~0x3) != (buf&~0x3))){//ignore IR bits (or unconnected pins)
			DbgLogWarn(("UsbGetPortState(%d)=0x%02x prv_port_a=0x%x!!\n", portNum, buf, prv_port_a));
			prv_port_a = (prv_port_a&0x3) | (buf&~0x3);
		}
#endif
        *state = buf;
        rst = TRUE;
    }
    
    return rst;
}

BOOL
USBBootMChip_t::
UsbGetPortDir(BYTE portNum, BYTE * dir)
{
	WRAP_ATOMIC_SCOPE;
    BOOL rst = FALSE;
    Usb_Port_SetupDat setupdat;
    BYTE buf;
    DWORD dwBytesTransferred;
	memset(&setupdat, 0, sizeof(setupdat));

	if(0/*hadUsbError("UsbSetPortState")*/){
		return FALSE;
	}

    setupdat.vrOpcode = VR_PORT_SETTING;
    setupdat.portNum = portNum;
    setupdat.portOp = OP_GET_DIR;

    if( 0 != UsbReadWrite(TRUE, (BYTE *)(&setupdat), (void *)&buf, 1, &dwBytesTransferred, TRANSFER_TIMEOUT) )
    {
        DbgLogError(("UsbGetPortDir(%d) FAILED\n", portNum));
        rst = FALSE;
    }
    else
    {
		DbgLogTrace(("UsbGetPortDir(%d) returns=0x%02x\n", portNum, buf));
        *dir = buf;
        rst = TRUE;
    }
    return rst;
}

BOOL
USBBootMChip_t::
UsbForceWFMode(BYTE mode){
	WRAP_ATOMIC_SCOPE;
	DbgLogTrace(("UsbForceWFMode(0x%x)\n", mode));
	_lastWFMode = 0xFD;
	return UsbSetWFMode(mode);
}

BOOL
USBBootMChip_t::
UsbSetWFMode(BYTE mode)
{
	WRAP_ATOMIC_SCOPE;
    BOOL rst = FALSE;
    Usb_WF_SetupDat setupdat;
    BYTE buf;
    DWORD dwBytesTransferred;
    DWORD tmp;

	memset(&setupdat, 0, sizeof(setupdat));

	if(0/*hadUsbError("UsbSetPortState")*/){
		return FALSE;
	}
	//FGR - see if we can avoid doing this (overly used) call to the Cypress FW
	if(_lastWFMode == mode){
//	    DbgLogInfo(("UsbSetWFMode(%d) skipped\n", mode));
		return TRUE;
	}
	_lastWFMode = 0xFE; //indicate we are changing modes

    setupdat.vrOpcode = VR_WF_SETTING;
    setupdat.wfOp = WF_MODE;
    setupdat.wfMode = mode;

    tmp = UsbReadWrite(TRUE, (BYTE *)(&setupdat), (void *)&buf, 1, &dwBytesTransferred, TRANSFER_TIMEOUT);
    if( 0 != tmp )
    {
        DbgLogError(("UsbSetWFMode(%d) returns=0x%x\n", mode, tmp));
        rst = FALSE;
    }
    if( buf == 1 ){
        rst = TRUE;
		_lastWFMode = mode; //mode changed ok
    } else {
        rst = FALSE;
    }
//	DbgLogTrace(("UsbSetWFMode(%d) returns %d\n", mode, rst));
    return rst;
}


BOOL
USBBootMChip_t::
UsbSetWFRW(BYTE read, BYTE write)
{
#if 0//ndef DRIVER_BUILD
	WRAP_ATOMIC_SCOPE;
    BOOL rst = FALSE;
    Usb_WF_SetupDat setupdat;
    BYTE buf;
    DWORD dwBytesTransferred;

	memset(&setupdat, 0, sizeof(setupdat));

    setupdat.vrOpcode = VR_WF_SETTING;
    setupdat.wfOp = WF_SETRW;
    setupdat.wfRead = read;
    setupdat.wfWrite = write;

    if( 0 != UsbReadWrite(TRUE, (BYTE *)(&setupdat), (void *)&buf, 1, &dwBytesTransferred, TRANSFER_TIMEOUT) )
    {
        DbgLogError(("set waveform read write err\n"));
        rst = 0;
    }
    if( buf == 1 )
        rst = TRUE;
    else
        rst = FALSE;
    
    DbgLogTrace(("UsbSetWFRW(%d,%d) returns %d\n", read, write, rst));
    return rst;
#else
	return TRUE; //FGR - our FW always assumes this configuration
#endif
}

void
USBBootMChip_t::
UsbDebug()
{
    BOOL rst = FALSE;
    DWORD dwBytesTransferred;
    BYTE setup[8];
    BYTE buf[8];

	memset(setup, 0, sizeof(setup));
	memset(buf, 0, sizeof(buf));

    setup[1] = VR_DEBUG;

    if( 0 != UsbReadWrite(TRUE, (BYTE *)(&setup[0]), (void *)buf, 8, &dwBytesTransferred, TRANSFER_TIMEOUT) )
    {
        DbgLogError(("send debug length err\n"));
        rst = 0;
    }

    //DbgLogTrace(("debug: %02x %02x\n", buf[1], buf[0]));
    DbgLogTrace(("debug: %02x %02x %02x %02x %02x %02x %02x %02x\n", buf[0], buf[1], buf[2], buf[3], buf[4], buf[5], buf[6], buf[7]));

    return;
}


BOOL
USBBootMChip_t::
UsbParOut(char * data, DWORD len)
{
	WRAP_ATOMIC_SCOPE;
    BOOL rst = FALSE;
    DWORD tmp;
    DWORD dwBytesTransferred;
    BYTE setup[8];
    BYTE buf;

	if(hadUsbError("UsbParOut")){
		return FALSE;
	}
 #if 0//DBG
	static DWORD lastLen=0;
	if(len > lastLen){
		lastLen = len;
		DbgLogTrace(("UsbParOut(%p, %u) largest tranfer request\n", data, len));
	}
 #endif

	if(len > USB_RW_MAXBYTES_PERTIME){
 #if 1
//		DbgLogTrace(("UsbParOut(%p, %u) too big, breaking up transfer\n", data, len));
		while(len > USB_RW_MAXBYTES_PERTIME){
			if(!UsbParOut(data, USB_RW_MAXBYTES_PERTIME)){
				return 0;
			}
			data += USB_RW_MAXBYTES_PERTIME;
			len -= USB_RW_MAXBYTES_PERTIME;
		}
 #endif			
	}
    //DbgLogTrace(("%d != %d\n", prevOutLen, len));
    prevOutLen = len;
    
    setup[1] = VR_OUTPACKETLEN;
 
#if 0//FGR - this seems wrong, esp for large value of len
    setup[2] = (BYTE)(len & 0xff);
    setup[3] = (BYTE)((len >> 8) & 0xff);
    //setup[4] = (BYTE)((len >> 16) & 0xff);
    //setup[5] = (BYTE)((len >> 24) & 0xff);
    setup[4] = 0;   //transfer loop equal to 0 in order to compatible UsbSetOutputLen
    setup[5] = 0;
#else
	DWORD stublen = len%512;
	DWORD loops = len/512;
	
	setup[2] = (BYTE)(stublen & 0xff);
	setup[3] = (BYTE)(stublen >> 8);
	setup[4] = (BYTE)(loops & 0xff);
	setup[5] = (BYTE)(loops >> 8);
#endif
    
    if( 0 != UsbReadWrite(TRUE, (BYTE *)(&setup[0]), (void *)&buf, 1, &dwBytesTransferred, TRANSFER_TIMEOUT) )
    {
        DbgLogError(("UsbParOut() send out-packet length err\n"));
        rst = 0;
		resetWFMode();
    }

    tmp = UsbReadWriteBulk(FALSE, (void *)data, (WORD)len, &dwBytesTransferred, TRANSFER_TIMEOUT);
    if( 0 != tmp )
    {
        DbgLogError(("UsbParOut() send data error 0x%x\n", tmp));
        rst = 0;
		resetWFMode();
        return rst;
    }
    else
    {
//		DbgLogTrace(("UsbParOut() %d bytes OK\n", dwBytesTransferred));
        rst = TRUE;
    }
    return rst;
}

void
USBBootMChip_t::
UsbSetOutputLen(DWORD len, DWORD loop)
{
    DWORD dwBytesTransferred;
    BYTE setup[8];
    BYTE buf;
	memset(setup, 0, sizeof(setup));

	if(hadUsbError("UsbSetOutputLen")){
		return;
	}

    setup[1] = VR_OUTPACKETLEN;
     
    setup[2] = (BYTE)(len & 0xff);
    setup[3] = (BYTE)((len >> 8) & 0xff);

    setup[4] = (BYTE)(loop & 0xff);
    setup[5] = (BYTE)((loop >> 8) & 0xff);

    if( 0 != UsbReadWrite(TRUE, (BYTE *)(&setup[0]), (void *)&buf, 1, &dwBytesTransferred, TRANSFER_TIMEOUT) )
    {
        DbgLogError(("UsbSetOutputLen() send out-packet length err\n"));
		resetWFMode();
    }

//	DbgLogTrace(("UsbSetOutputLen(%d,%d)\n", len, loop));
    return;
}

BOOL
USBBootMChip_t::
UsbParOutHighSpeed(char * data, DWORD len)
{
    BOOL rst = FALSE;
    DWORD tmp;
    DWORD dwBytesTransferred;
	if(hadUsbError("UsbParOutHighSpeed")){
		return FALSE;
	}

    tmp = UsbReadWriteBulk(FALSE, (void *)data, (WORD)len, &dwBytesTransferred, TRANSFER_TIMEOUT);
    if( 0 !=  tmp)
    {
        DbgLogError(("UsbParOutHighSpeed() send data error 0x%x  read %d\n",tmp, dwBytesTransferred));
        rst = 0;
		resetWFMode();
        return rst;
    }
    else
    {
//		DbgLogTrace(("UsbParOutHighSpeed() %d bytes OK\n", dwBytesTransferred));
        rst = TRUE;
    }

    return rst;
}

BOOL
USBBootMChip_t::
UsbParIn(char * data, DWORD len)
{
	WRAP_ATOMIC_SCOPE;
    BOOL rst = FALSE;
    DWORD tmp;
    DWORD dwBytesTransferred;
    BYTE setup[8];
    BYTE buf;
	memset(setup, 0, sizeof(setup));

	if(hadUsbError("UsbParIn")){
		return FALSE;
	}
 #if 0//DBG
	static DWORD lastLen=0;
	if(len > lastLen){
		lastLen = len;
		DbgLogTrace(("UsbParIn(%p, %u) largest tranfer request\n", data, len));
	}
 #endif

 #if 1//testing
	if(len > USB_IN_MAXBYTES_PERTIME){
		//DbgLogTrace(("UsbParIn(%p, %u) too big, breaking up transfer\n", data, len));
		while(len > USB_IN_MAXBYTES_PERTIME){
			if(!UsbParIn(data, USB_IN_MAXBYTES_PERTIME)){
				return 0;
			}
			data += USB_IN_MAXBYTES_PERTIME;
			len -= USB_IN_MAXBYTES_PERTIME;
		}
	}
 #endif

#if 0//FGR - moved to CUsbInterface::SendSBPCmdAndWait to avoid races with returned read data
    setup[1] = VR_INPACKETLEN;

    DWORD stublen = len%1024;
	DWORD loops = len/1024;

	setup[2] = (BYTE)(stublen);
    setup[3] = (BYTE)(stublen >> 8);
    setup[4] = (BYTE)(loops);
    setup[5] = (BYTE)(loops >> 8);

    if( 0 != UsbReadWrite(TRUE, (BYTE *)(&setup[0]), (void *)&buf, 1, &dwBytesTransferred, TRANSFER_TIMEOUT) )
    {
        DbgLogError(("UsbParIn() send in-packet length err\n"));
        rst = 0;
    }
#endif

    tmp = UsbReadWriteBulk(TRUE, (void *)data, (WORD)len, &dwBytesTransferred, _SBPtimeout);//1100 is good for 256Kbs and above
    if( 0 !=  tmp)
    {
        if(tmp != 2){
			DbgLogError(("UsbParIn() receive data error 0x%x read %d\n",tmp, dwBytesTransferred));
		} else {
//			DbgLogWarn(("UsbParIn() receive data timeout, _SBPtimeout=%u\n", _SBPtimeout));
		}
        rst = 0;
        return rst;
    }
    else
    {
//		DbgLogTrace(("UsbParIn() got %d of %d bytes\n", dwBytesTransferred, len));
        rst = TRUE;
    }

    return rst;
}

#if 1//FGR - removed
void
USBBootMChip_t::
UsbSetInputLen(DWORD len, DWORD loop)
{
    DWORD dwBytesTransferred;
    BYTE setup[8];
    BYTE buf;
	memset(setup, 0, sizeof(setup));

	if(hadUsbError("UsbSetInputLen")){
		return;
	}

    setup[1] = VR_INPACKETLEN;

    setup[2] = (BYTE)(len & 0xff);
    setup[3] = (BYTE)((len >> 8) & 0xff);

    setup[4] = (BYTE)(loop & 0xff);
    setup[5] = (BYTE)((loop >> 8) & 0xff);

    if( 0 != UsbReadWrite(TRUE, (BYTE *)(&setup[0]), (void *)&buf, 1, &dwBytesTransferred, TRANSFER_TIMEOUT) )
    {
        DbgLogError(("UsbSetInputLen() send in-packet length err\n"));
		return;
    }

//	DbgLogTrace(("UsbSetInputLen(%d,%d)\n", len, loop));
    return;
}

BOOL
USBBootMChip_t::
UsbParInHighSpeed(char * data, DWORD len)
{
    BOOL rst = FALSE;
    DWORD tmp;
    DWORD dwBytesTransferred;
	if(hadUsbError("UsbParInHighSpeed")){
		return FALSE;
	}
 #if 0//DBG
	static DWORD lastLen=0;
	if(len > lastLen){
		lastLen = len;
		DbgLogTrace(("UsbParInHighSpeed(%p, %u) largest tranfer request\n", data, len));
	}
 #endif

    tmp = UsbReadWriteBulk(TRUE, (void *)data, (WORD)len, &dwBytesTransferred, _SBPtimeout);//1100 is good for 256Kbs and above
    if( 0 !=  tmp)
    {
        if(tmp != 2){
			DbgLogError(("UsbParInHighSpeed() receive data error %d\n",tmp));
		} else {
//			DbgLogError(("UsbParInHighSpeed() receive data timeout\n"));
		}
        rst = 0;
        return rst;
    }
    else
    {
//		DbgLogTrace(("UsbParInHighSpeed() got %d of %d bytes\n", dwBytesTransferred, len));
        rst = TRUE;
    }

    return rst;
}
#endif//FGR - removed
