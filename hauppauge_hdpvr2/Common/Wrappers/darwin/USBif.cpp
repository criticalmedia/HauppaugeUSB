#include "USBif.h"

static const char *strRetMsg (kern_return_t result) {
  switch (result) {
  case kIOReturnSuccess:
    return "no error";
  case kIOReturnNotOpen:
    return "device not opened for exclusive access";
  case kIOReturnNoDevice:
    return "no connection to an IOService";
  case kIOUSBNoAsyncPortErr:
    return "no async port has been opened for interface";
  case kIOReturnExclusiveAccess:
    return "another process has device opened for exclusive access";
  case kIOUSBPipeStalled:
    return "pipe is stalled";
  case kIOReturnError:
    return "could not establish a connection to the Darwin kernel";
  case kIOUSBTransactionTimeout:
    return "transaction timed out";
  case kIOReturnBadArgument:
    return "invalid argument";
  case kIOReturnAborted:
    return "transaction aborted";
  case kIOReturnNotResponding:
    return "device not responding";
  case kIOReturnOverrun:
    return "data overrun";
  case kIOReturnCannotWire:
    return "physical memory can not be wired down";
  case kIOReturnNoResources:
    return "out of resources";
  case kIOUSBHighSpeedSplitError:
    return "high speed split error";
  default:
    return "unknown error";
  }
}

static int retMsg (kern_return_t result) {
  switch (result) {
  case kIOReturnUnderrun:
  case kIOReturnSuccess:
    return USBWRAP_SUCCESS;
  case kIOReturnNotOpen:
  case kIOReturnNoDevice:
    return USBWRAP_ERROR_NO_DEVICE;
  case kIOReturnExclusiveAccess:
    return USBWRAP_ERROR_ACCESS;
  case kIOUSBPipeStalled:
    return USBWRAP_ERROR_PIPE;
  case kIOReturnBadArgument:
    return USBWRAP_ERROR_INVALID_PARAM;
  case kIOUSBTransactionTimeout:
    return USBWRAP_ERROR_TIMEOUT;
  case kIOReturnNotResponding:
  case kIOReturnAborted:
  case kIOReturnError:
  case kIOUSBNoAsyncPortErr:
  default:
    return USBWRAP_ERROR_OTHER;
  }
}

static IOUSBDeviceInterfaceXXX** deviceInterfaceFromKernel(io_service_t device) {
	kern_return_t kr;
	IOCFPlugInInterface **plugInInterface = NULL;
	SInt32 score;
	IOUSBDeviceInterfaceXXX **deviceInterface = NULL;

	kr = IOCreatePlugInInterfaceForService(device, kIOUSBDeviceUserClientTypeID, kIOCFPlugInInterfaceID,
		&plugInInterface, &score);

	if ((kIOReturnSuccess != kr) || !plugInInterface) {
		wrapLogError("IOCreatePlugInInterfaceForService returned 0x%08X %s", kr, strRetMsg(kr));
		return NULL;
	}

	kr = (*plugInInterface)->QueryInterface(plugInInterface, CFUUIDGetUUIDBytes(kIOUSBDeviceInterfaceID),
		(LPVOID*) &deviceInterface);

	(*plugInInterface)->Release(plugInInterface);

	if (kr || deviceInterface == NULL) {
		wrapLogError("QueryInterface returned 0x%08X %s", kr, strRetMsg(kr));
		return NULL;
	}

	return deviceInterface;
}

static IOUSBInterfaceInterfaceXXX** interfaceInterfaceFromKernel(io_service_t interface) {
	kern_return_t kr;
	IOCFPlugInInterface **plugInInterface = NULL;
	SInt32 score;
	IOUSBInterfaceInterfaceXXX **interfaceInterface = NULL;

	kr = IOCreatePlugInInterfaceForService(interface, kIOUSBInterfaceUserClientTypeID, kIOCFPlugInInterfaceID,
		&plugInInterface, &score);

	if ((kIOReturnSuccess != kr) || !plugInInterface) {
		WRAPLOG(WRAPLOGL_ERROR, "IOCreatePlugInInterfaceForService returned 0x%08X %s", kr, strRetMsg(kr));
		return NULL;
	}

	kr = (*plugInInterface)->QueryInterface(plugInInterface, CFUUIDGetUUIDBytes(kIOUSBInterfaceInterfaceIDXXX),
		(LPVOID*) &interfaceInterface);

	(*plugInInterface)->Release(plugInInterface);

	if (kr || interfaceInterface == NULL) {
		WRAPLOG(WRAPLOGL_ERROR, "QueryInterface returned 0x%08X %s", kr, strRetMsg(kr));
		return NULL;
	}

	return interfaceInterface;
}

int USBWrapper_t::open(IOUSBDeviceInterfaceXXX **devi) {
	IOUSBFindInterfaceRequest request;
	kern_return_t kr;
	io_iterator_t interface_iterator;
	io_service_t usbInterfacep;

	WRAPLOG(WRAPLOGL_DEBUG, "opening...");

	memset(m_pipeRefs, 0, sizeof(m_pipeRefs));

	m_deviceI = devi;
	m_isDevAlloc = false;

	request.bInterfaceClass = kIOUSBFindInterfaceDontCare;
	request.bInterfaceSubClass = kIOUSBFindInterfaceDontCare;
	request.bInterfaceProtocol = kIOUSBFindInterfaceDontCare;
	request.bAlternateSetting = kIOUSBFindInterfaceDontCare;

	kr = (*m_deviceI)->CreateInterfaceIterator(m_deviceI, &request, &interface_iterator);
	if (kr) {
		WRAPLOG(WRAPLOGL_ERROR, "CreateInterfaceIterator(): 0x%08X %s", kr, strRetMsg(kr));
		return retMsg(kr);
	}

	usbInterfacep = IOIteratorNext(interface_iterator);
	if(usbInterfacep) {
		m_interfaceI = interfaceInterfaceFromKernel(usbInterfacep);
		IOObjectRelease(usbInterfacep);
	}
	IOObjectRelease(interface_iterator);

	uint8_t numep, direction, number;
	uint8_t dont_care1, dont_care3;
	uint16_t dont_care2;
	int i;

	kr = (*m_deviceI)->USBDeviceOpen(m_deviceI);
	if(kr) {
		WRAPLOG(WRAPLOGL_ERROR, "can't open device: 0x%08X %s", kr, strRetMsg(kr));
		return retMsg(kr);
	}

	kr = (*m_interfaceI)->USBInterfaceOpen(m_interfaceI);
	if(kr) {
		WRAPLOG(WRAPLOGL_ERROR, "can't open interface: 0x%08X %s", kr, strRetMsg(kr));
		return retMsg(kr);
	}

	WRAPLOG(WRAPLOGL_DEBUG, "building table of endpoints...");

	kr = (*m_interfaceI)->GetNumEndpoints(m_interfaceI, &numep);
	if (kr) {
		WRAPLOG(WRAPLOGL_ERROR, "can't get number of endpoints for interface: 0x%08X %s", kr, strRetMsg(kr));
		return retMsg(kr);
	}

	WRAPLOG(WRAPLOGL_DEBUG, "%d endpoints", numep);

	for (i = 1 ; i <= numep ; i++) {
		kr = (*m_interfaceI)->GetPipeProperties(m_interfaceI, i, &direction, &number, &dont_care1,
			&dont_care2, &dont_care3);
		if (kr != kIOReturnSuccess) {
			WRAPLOG(WRAPLOGL_ERROR, "error getting pipe information for pipe %d: 0x%08X %s", i, kr, strRetMsg(kr));
			return retMsg(kr);
		}

		WRAPLOG(WRAPLOGL_DEBUG, "interface: %i pipe %i: dir: %i number: %i", 0, i, direction, number);
		m_pipeRefs[((direction << 4 & 0x10) | (number & 0x0F))] = i;
	}

	startEventLoop();
	WRAPLOG(WRAPLOGL_DEBUG, "opened");
	return USBWRAP_SUCCESS;
}

int USBWrapper_t::close() {
	stopEventLoop();
	if(m_deviceI) {
		(*m_deviceI)->USBDeviceClose(m_deviceI);
		if(m_isDevAlloc) (*m_deviceI)->Release(m_deviceI);
		m_deviceI = NULL;
	}
	if(m_interfaceI) {
		(*m_interfaceI)->USBInterfaceClose(m_interfaceI);
		(*m_interfaceI)->Release(m_interfaceI);
		m_interfaceI = NULL;
	}
	return USBWRAP_SUCCESS;
}

int USBWrapper_t::open(uint16_t _vid, uint16_t _pid) {
	int32_t vid = _vid;
	int32_t pid = _pid;
	CFMutableDictionaryRef matchingDict;
	CFNumberRef numberRef;
	io_iterator_t iter;
	kern_return_t kr;
	io_service_t device;

	matchingDict = IOServiceMatching(kIOUSBDeviceClassName);
	if (matchingDict == NULL) {
		return USBWRAP_ERROR_OTHER;
	}

	numberRef = CFNumberCreate(kCFAllocatorDefault, kCFNumberSInt32Type, &vid);
	CFDictionarySetValue(matchingDict,
		CFSTR(kUSBVendorID),
		numberRef);
	CFRelease(numberRef);

	numberRef = CFNumberCreate(kCFAllocatorDefault, kCFNumberSInt32Type, &pid);
	CFDictionarySetValue(matchingDict,
		CFSTR(kUSBProductID),
		numberRef);
	CFRelease(numberRef);

	kr = IOServiceGetMatchingServices(kIOMasterPortDefault, matchingDict, &iter);
	if (kr != kIOReturnSuccess) {
		if (kr == kIOReturnNoDevice) {
			return USBWRAP_ERROR_NOT_FOUND;
		}
		return retMsg(kr);
	}

	while ((device = IOIteratorNext(iter))) {
		IOUSBDeviceInterfaceXXX **devi = deviceInterfaceFromKernel(device);
		IOObjectRelease(device);
		IOObjectRelease(iter);
		if(!devi) {
			return USBWRAP_ERROR_OTHER;
		}
		wrapLogDebug("Got it");
		int r = open(devi);
		m_isDevAlloc = true;
		return r;
	}

	IOObjectRelease(iter);
	return USBWRAP_ERROR_NOT_FOUND;
}

#define ASSERT_OBJ_CMD(C, V, M)\
do {\
	if(!(V)) {\
		WRAPLOG(WRAPLOGL_ERROR, (M));\
		int ret = USBWRAP_ERROR_NO_DEVICE;\
		C;\
		return ret;\
	}\
} while(0)

#define ASSERT_OBJ(V, M) ASSERT_OBJ_CMD(, V, M)

#define ASSERT_PIPE_CMD(C, R, V, M)\
do {\
	if(((V) & 0x70) || ((V) == 0)) {\
		WRAPLOG(WRAPLOGL_ERROR, M": bad endpoint number 0x%02X", (V));\
		int ret = USBWRAP_ERROR_INVALID_PARAM;\
		C;\
		return ret;\
	}\
	R = m_pipeRefs[((V) & 0x0F) | (((V) & 0x80) >> 3)];\
	if(R == 0) {\
		WRAPLOG(WRAPLOGL_ERROR, M": no endpoint 0x%02X", (V));\
		int ret = USBWRAP_ERROR_INVALID_PARAM;\
		C;\
		return ret;\
	}\
} while(0)

#define ASSERT_PIPE(R, V, M) ASSERT_PIPE_CMD(, R, V, M)

static void async_callback (void *refcon, IOReturn result, void *arg0) {
	USBWrapperAsyncCtx_t *ctx = (USBWrapperAsyncCtx_t*)refcon;
	if(!ctx) return;
	if(result) WRAPLOG(WRAPLOGL_ERROR, "cannot finish async bulk read from endpoint --: 0x%08X %s", result, strRetMsg(result));
//	else WRAPLOG(WRAPLOGL_DEBUG, "async Ok, length: %d", (UInt32)(uintptr_t)arg0);
	ctx->set(retMsg(result), (UInt32)(uintptr_t)arg0);
}

int USBWrapper_t::controlMessage(USBWrapperControlMessage_t &msg, uint8_t *buf, uint32_t timeout) {
	kern_return_t kr;
	IOUSBDevRequestTO req;
	ASSERT_OBJ(m_deviceI, "cannot send control message: device is not opened");
	memset(&req, 0, sizeof(req));
	req.bmRequestType = msg.bmRequestType;
	req.bRequest      = msg.bRequest;
	req.wValue        = msg.wValue;
	req.wIndex        = msg.wIndex;
	req.wLength       = msg.wLength;
	req.pData         = buf;
	req.noDataTimeout = timeout;
	req.completionTimeout = timeout;
	kr = (*m_deviceI)->DeviceRequestTO(m_deviceI, &req);
	if(kr) {
		WRAPLOG(WRAPLOGL_ERROR, "cannot send control message: 0x%08X %s", kr, strRetMsg(kr));
		return retMsg(kr);
	}
	return req.wLenDone;
}

int USBWrapper_t::bulkRead(uint8_t num, uint8_t *buf, uint32_t len, uint32_t timeout) {
	kern_return_t kr;
	uint8_t pipe;
	ASSERT_OBJ(m_interfaceI, "cannot bulk read: interface is not opened");
	ASSERT_PIPE(pipe, num | 0x80, "cannot bulk read");
	UInt32 l = len;
	kr = (*m_interfaceI)->ReadPipeTO(m_interfaceI, pipe, buf, &l, timeout, timeout);
	if(kr) {
		WRAPLOG(WRAPLOGL_ERROR, "cannot bulk read from endpoint 0x%02X: 0x%08X %s", num, kr, strRetMsg(kr));
		return retMsg(kr);
	}
	return l;
}

int USBWrapper_t::bulkReadAsync(USBWrapperAsyncCtx_t &ctx, uint8_t num, uint8_t *buf, uint32_t len, uint32_t timeout) {
	kern_return_t kr;
	uint8_t pipe;
	ctx.init();
	ASSERT_OBJ_CMD(ctx.set(ret, 0), m_interfaceI, "cannot async bulk read: interface is not opened");
	ASSERT_PIPE_CMD(ctx.set(ret, 0), pipe, num | 0x80, "cannot async bulk read");
	kr = (*m_interfaceI)->ReadPipeAsyncTO(m_interfaceI, pipe, buf, len, timeout, timeout, async_callback, (void*)&ctx);
	if(kr) {
		WRAPLOG(WRAPLOGL_ERROR, "cannot async bulk read from endpoint 0x%02X: 0x%08X %s", num, kr, strRetMsg(kr));
		int r = retMsg(kr);
		ctx.set(r, 0);
		return r;
	}
	return USBWRAP_SUCCESS;
}

int USBWrapper_t::bulkWrite(uint8_t num, const uint8_t *buf, uint32_t len, uint32_t timeout) {
	kern_return_t kr;
	uint8_t pipe;
	ASSERT_OBJ(m_interfaceI, "cannot bulk write: interface is not opened");
	ASSERT_PIPE(pipe, num & 0x7F, "cannot bulk write");
	kr = (*m_interfaceI)->WritePipeTO(m_interfaceI, pipe, (void*)buf, len, timeout, timeout);
	if(kr) {
		WRAPLOG(WRAPLOGL_ERROR, "cannot bulk write to endpoint 0x%02X: 0x%08X %s", num, kr, strRetMsg(kr));
		return retMsg(kr);
	}
	return len;
}

int USBWrapper_t::clearStall(uint8_t num) {
	kern_return_t kr;
	uint8_t pipe;
	ASSERT_OBJ(m_interfaceI, "cannot clear stall: interface is not opened");
	ASSERT_PIPE(pipe, num, "cannot clear stall");
	kr = (*m_interfaceI)->ClearPipeStallBothEnds(m_interfaceI, pipe);
	if(kr) {
		WRAPLOG(WRAPLOGL_ERROR, "cannot clear stall of endpoint 0x%02X: 0x%08X %s", num, kr, strRetMsg(kr));
	}
	return retMsg(kr);
}

int USBWrapper_t::abort(uint8_t num) {
	kern_return_t kr;
	uint8_t pipe;
	ASSERT_OBJ(m_interfaceI, "cannot abort transfer: interface is not opened");
	ASSERT_PIPE(pipe, num, "cannot abort transfer");
	kr = (*m_interfaceI)->AbortPipe(m_interfaceI, pipe);
	if(kr) {
		WRAPLOG(WRAPLOGL_ERROR, "cannot abort transfer on endpoint 0x%02X: 0x%08X %s", num, kr, strRetMsg(kr));
	}
	return retMsg(kr);
}

int USBWrapper_t::abortControl() {
	kern_return_t kr;
	ASSERT_OBJ(m_deviceI, "cannot abort control transfer: device is not opened");
	kr = (*m_deviceI)->USBDeviceAbortPipeZero(m_deviceI);
	if(kr) {
		WRAPLOG(WRAPLOGL_ERROR, "cannot abort control transfer: 0x%08X %s", kr, strRetMsg(kr));
	}
	return retMsg(kr);
}
