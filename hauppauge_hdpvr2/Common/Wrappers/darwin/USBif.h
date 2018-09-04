#ifndef __USBIF_H_
#define __USBIF_H_

#include <CoreFoundation/CoreFoundation.h>
#include <IOKit/IOKitLib.h>
#include <IOKit/IOMessage.h>
#include <IOKit/IOCFPlugIn.h>
#include <IOKit/usb/IOUSBLib.h>

#include <stdint.h>
#include <string.h>

//#include "common.h"
#include "log.h"
#include "baseif.h"

//USB wrapper

#define IOUSBDeviceInterfaceXXX IOUSBDeviceInterface197
#define kIOUSBDeviceInterfaceIDXXX kIOUSBDeviceInterfaceID197
#define IOUSBInterfaceInterfaceXXX IOUSBInterfaceInterface220
#define kIOUSBInterfaceInterfaceIDXXX kIOUSBInterfaceInterfaceID220

typedef IONotificationPortRef io_notification_port_t;

#define USBWRAP_CM_DEVICE_VENDOR_WR 0x40
#define USBWRAP_CM_DEVICE_VENDOR_RD 0xC0

typedef enum {
	USBWRAP_SUCCESS = 0,
	USBWRAP_ERROR_IO = -1,
	USBWRAP_ERROR_INVALID_PARAM = -2,
	USBWRAP_ERROR_ACCESS = -3,
	USBWRAP_ERROR_NO_DEVICE = -4,
	USBWRAP_ERROR_NOT_FOUND = -5,
	USBWRAP_ERROR_BUSY = -6,
	USBWRAP_ERROR_TIMEOUT = -7,
	USBWRAP_ERROR_OVERFLOW = -8,
	USBWRAP_ERROR_PIPE = -9,
	USBWRAP_ERROR_INTERRUPTED = -10,
	USBWRAP_ERROR_NO_MEM = -11,
	USBWRAP_ERROR_NOT_SUPPORTED = -12,
	USBWRAP_ERROR_OTHER = -99,
	USBWRAP_PENDING = -101
} USBWrapperError_t;

typedef enum {
	USBWRAP_TT_CONTROL,
	USBWRAP_TT_BULK
} USBWrapperTT_t;

typedef struct {
	uint8_t bmRequestType;
	uint8_t bRequest;
	uint16_t wValue;
	uint16_t wIndex;
	uint16_t wLength;
} USBWrapperControlMessage_t;

class USBWrapperAsyncCtx_t;

class USBWrapper_t {
protected:
	IOUSBDeviceInterfaceXXX **m_deviceI;
	bool m_isDevAlloc;
	IOUSBInterfaceInterfaceXXX **m_interfaceI; // yes, just only one here
	uint8_t m_pipeRefs[32];

	pthread_mutex_t eventLoopMutex;
	pthread_cond_t eventLoopCond;
	pthread_t eventLoop;
	CFRunLoopRef eventLoopObj;
	static void* eventLoopCallback(void *ctx);
	void startEventLoop();
	void stopEventLoop();
public:
	USBWrapper_t(): m_deviceI(NULL), m_isDevAlloc(false), m_interfaceI(NULL), eventLoopObj(NULL) {memset(m_pipeRefs, 0, sizeof(m_pipeRefs));}
	~USBWrapper_t() {close();}
	int open(IOUSBDeviceInterfaceXXX **devi);
	int close();
	int controlMessage(USBWrapperControlMessage_t &msg, uint8_t *buf, uint32_t timeout);
//	int controlMessageAsync(USBWrapperAsyncCtx_t &ctx, USBWrapperControlMessage_t &msg, uint8_t *buf, uint32_t timeout);
	int bulkRead(uint8_t num, uint8_t *buf, uint32_t len, uint32_t timeout);
	int bulkReadAsync(USBWrapperAsyncCtx_t &ctx, uint8_t num, uint8_t *buf, uint32_t len, uint32_t timeout);
	int bulkWrite(uint8_t num, const uint8_t *buf, uint32_t len, uint32_t timeout);
//	int bulkWriteAsync(USBWrapperAsyncCtx_t &ctx, uint8_t num, const uint8_t *buf, uint32_t len, uint32_t timeout);
	int clearStall(uint8_t num);
	int abort(uint8_t num);
	int abortControl();
// enumeration
	int open(uint16_t vid, uint16_t pid);
};

class USBWrapperAsyncCtx_t {
protected:
//	USBWrapper_t &usb;
//	USBWrapperTT_t transferType;
//	uint8_t pipeNum;
	pthread_mutex_t m_mutex;
	pthread_cond_t m_cond;
	bool finished;
public:
	int result;
	uint32_t size;
	USBWrapperAsyncCtx_t(): finished(true), result(USBWRAP_PENDING) {
		pthread_mutex_init(&m_mutex, NULL);
		pthread_cond_init(&m_cond, NULL);
	}
	~USBWrapperAsyncCtx_t() {
		wait();
		pthread_cond_destroy(&m_cond);
		pthread_mutex_destroy(&m_mutex);
	}
/*
	inline void init(USBWrapper_t &u, USBWrapperTT_t tt, uint8_t pn) {
		finished = false;
		transferType = tt;
		pipeNum = pn;
		usb = &u;
	}
*/
	inline void init() {
		finished = false;
		result = USBWRAP_PENDING;
	}
	inline void set(int r, uint32_t s) {
		pthread_mutex_lock(&m_mutex);
		finished = true;
		result = r;
		size = s;
		pthread_cond_signal(&m_cond);
		pthread_mutex_unlock(&m_mutex);
	}
	inline int getState() {
		pthread_mutex_lock(&m_mutex);
		int r = result;
		pthread_mutex_unlock(&m_mutex);
		return r;
	}
	inline void wait() {
		pthread_mutex_lock(&m_mutex);
		while(!finished) pthread_cond_wait(&m_cond, &m_mutex);
		pthread_mutex_unlock(&m_mutex);
	}
};

#endif
