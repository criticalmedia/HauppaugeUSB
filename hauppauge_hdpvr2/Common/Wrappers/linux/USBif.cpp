#include "USBif.h"

#define IFNUM 0

static int retMsg(int result) {
	return result; // the same as in libusb 1.0
}

static const char *strMsg(int result) {
	return libusb_strerror((libusb_error)result);
}

static int retTrSt(int st) {
	switch(st) {
		case LIBUSB_TRANSFER_COMPLETED:
			return USBWRAP_SUCCESS;
		case LIBUSB_TRANSFER_ERROR:
			return USBWRAP_ERROR_IO;
		case LIBUSB_TRANSFER_TIMED_OUT:
			return USBWRAP_ERROR_TIMEOUT;
		case LIBUSB_TRANSFER_CANCELLED:
			return USBWRAP_ERROR_INTERRUPTED;
		case LIBUSB_TRANSFER_STALL:
			return USBWRAP_ERROR_PIPE;
		case LIBUSB_TRANSFER_NO_DEVICE:
			return USBWRAP_ERROR_NO_DEVICE;
		case LIBUSB_TRANSFER_OVERFLOW:
			return USBWRAP_ERROR_OVERFLOW;
		default:
			return USBWRAP_ERROR_OTHER;
	}
}

static const char *strTrSt(int st) {
	return strMsg(retTrSt(st)); // the same as in libusb 1.0
}

int USBWrapper_t::open(libusb_context *ctx, libusb_device *dev) {
	close();
	m_ctx = ctx;
	int r = libusb_open(dev, &m_device);
	if(r != LIBUSB_SUCCESS) {
		wrapLogError("cannot open device: %s", strMsg(r));
		close();
		return retMsg(r);
	}
	r = libusb_claim_interface(m_device, IFNUM);
	if(r != LIBUSB_SUCCESS) {
		wrapLogError("cannot claim interface: %s", strMsg(r));
		close();
	}
	return retMsg(r);
}

int USBWrapper_t::close() {
	if(m_device) {
		libusb_release_interface(m_device, IFNUM);
		libusb_close(m_device);
		m_device = NULL;
	}
	if(m_mustFreeCtx) {
		libusb_exit(m_ctx);
		m_mustFreeCtx = false;
	}
	m_ctx = NULL;
	return USBWRAP_SUCCESS;
}

int USBWrapper_t::open(uint16_t vid, uint16_t pid) {
	close();
	int r = libusb_init(&m_ctx);
	if(r != LIBUSB_SUCCESS) {
		wrapLogError("cannot init libusb: %s", strMsg(r));
		return retMsg(r);
	}
	m_mustFreeCtx = true;
	m_device = libusb_open_device_with_vid_pid(m_ctx, vid, pid);
	if(!m_device) {
		wrapLogError("cannot open device %04X:%04X", vid, pid);
		close();
		return USBWRAP_ERROR_NOT_FOUND;
	}
	r = libusb_claim_interface(m_device, IFNUM);
	if(r != LIBUSB_SUCCESS) {
		wrapLogError("cannot claim interface: %s", strMsg(r));
		close();
	}
	return retMsg(r);
}

#define ASSERT_OBJ_CMD(C, V, M)\
do {\
	if(!(V)) {\
		wrapLogError((M));\
		int ret = USBWRAP_ERROR_NO_DEVICE;\
		C;\
		return ret;\
	}\
} while(0)

#define ASSERT_OBJ(V, M) ASSERT_OBJ_CMD(, V, M)

static void async_callback (libusb_transfer *t) {
	USBWrapperAsyncCtx_t *ctx = (USBWrapperAsyncCtx_t*)t->user_data;
	if(t->status != LIBUSB_TRANSFER_COMPLETED) wrapLogError("cannot finish async bulk read from endpoint --: (%d) %s", t->status, strTrSt(t->status));
//	else wrapLogDebug("async Ok, length: %d", t->actual_length);
	if(ctx) ctx->set(retTrSt(t->status), t->actual_length);
}

int USBWrapper_t::controlMessage(USBWrapperControlMessage_t &msg, uint8_t *buf, uint32_t timeout) {
	ASSERT_OBJ(m_device, "cannot send control message: device is not opened");
        usleep(1);
	int r = libusb_control_transfer(m_device, msg.bmRequestType, msg.bRequest, msg.wValue, msg.wIndex, buf, msg.wLength, timeout);
	if(r < 0) {
		wrapLogError("cannot send control message: %s", strMsg(r));
		return retMsg(r);
	}
	return r;
}

int USBWrapper_t::bulkRead(uint8_t num, uint8_t *buf, uint32_t len, uint32_t timeout) {
	ASSERT_OBJ(m_device, "cannot bulk read: device is not opened");
	int l = len;
	int r = libusb_bulk_transfer(m_device, num | 0x80, buf, len, &l, timeout);
	if(r != LIBUSB_SUCCESS) {
		wrapLogError("cannot bulk read from endpoint 0x%02X: %s", num, strMsg(r));
		return retMsg(r);
	}
	return l;
}

int USBWrapper_t::bulkReadAsync(USBWrapperAsyncCtx_t &ctx, uint8_t num, uint8_t *buf, uint32_t len, uint32_t timeout) {
	ctx.init();
	ASSERT_OBJ_CMD(ctx.set(ret, 0), m_device, "cannot async bulk read: device is not opened");
	libusb_transfer *t = libusb_alloc_transfer(0);
	if(t == NULL) {
		wrapLogError("cannot async bulk read: no memory");
		return USBWRAP_ERROR_NO_MEM;
	}
	libusb_fill_bulk_transfer(t, m_device, num | 0x80, buf, len, async_callback, &ctx, timeout);
	t->flags |= LIBUSB_TRANSFER_FREE_TRANSFER;
	int r = libusb_submit_transfer(t);
	if(r) {
		wrapLogError("cannot async bulk read from endpoint 0x%02X: %s", num, strMsg(r));
		int _r = retMsg(r);
		ctx.set(_r, 0);
		return _r;
	}
	return USBWRAP_SUCCESS;
}

int USBWrapper_t::bulkWrite(uint8_t num, const uint8_t *buf, uint32_t len, uint32_t timeout) {
	ASSERT_OBJ(m_device, "cannot bulk write: device is not opened");
	int l = len;
	int r = libusb_bulk_transfer(m_device, num & ~0x80, (uint8_t*)buf, len, &l, timeout);
	if(r != LIBUSB_SUCCESS) {
		wrapLogError("cannot bulk write to endpoint 0x%02X: %s", num, strMsg(r));
		return retMsg(r);
	}
	return len;
}

int USBWrapper_t::clearStall(uint8_t num) {
	ASSERT_OBJ(m_device, "cannot clear stall: device is not opened");
	int r = libusb_clear_halt(m_device, num);
	if(r != LIBUSB_SUCCESS) {
		wrapLogError("cannot clear stall of endpoint 0x%02X: %s", num, strMsg(r));
	}
	return retMsg(r);
}

int USBWrapper_t::abort(uint8_t num) {
	// stub yet
	return USBWRAP_SUCCESS;
}

int USBWrapper_t::abortControl() {
	// stub yet
	return USBWRAP_SUCCESS;
}
