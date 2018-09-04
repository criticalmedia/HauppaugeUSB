#include "FX2Device.h"

#include <string.h>

#define MC_WRITE_I2C_GENERIC 0x08
#define MC_READ_I2C_GENERIC 0x09
#define MC_GET_USB_SPEED 0x0B

typedef enum {
	VR_RAM = 0xA3,		// loads (uploads) external ram
	VR_PORT_SETTING,	// set port dir and state
	VR_WF_SETTING,		// set waveform mode and select waveform
	VR_INPACKETLEN,
	VR_OUTPACKETLEN,
	VR_DATA_TRANSFER,	// data transfer command
	VR_CPUCLK,
	VR_I2C,
	VR_DEBUG
} VR_OPCODE_t;

//PORTS

typedef enum {
	VR_OP_SET_STATE = 0,
	VR_OP_GET_STATE,
	VR_OP_SET_DIR,
	VR_OP_GET_DIR
} VR_OP_PORT_t;

//=====

#define EZUSB_BASE_ADDRESS 0xE600

#define DEFAULT_TIMEOUT 1000

int FX2Device_t::sendCommand(const uint8_t *outbuf, size_t outlen, uint8_t *inbuf, size_t inlen, size_t timeout) {
	WRAP_ATOMIC_SCOPE;
	int ret;
	if(timeout == 0) timeout = DEFAULT_TIMEOUT;
	if(outlen) {
		ret = usb.bulkWrite(FX2_EP_CMD_WR, outbuf, outlen, timeout);
		if(ret < 0) {
			return -1;
		}
	}
	ret = 0;
	if(inlen) {
		ret = usb.bulkRead(FX2_EP_CMD_RD, inbuf, inlen, timeout);
		if(ret < 0) {
			return -1;
		}
	}
	return ret;
}

int FX2Device_t::getUSBSpeed() {
	uint8_t cmd = MC_GET_USB_SPEED;
	uint8_t speed;
	if(sendCommand(&cmd, 1, &speed, 1, DEFAULT_TIMEOUT) < 0) {
		return -1;
	}
	return speed;
}

bool FX2Device_t::stopCPU(bool v) {
	USBWrapperControlMessage_t cm;
	int ret;
	uint8_t cmd = v;
	cm.bmRequestType = USBWRAP_CM_DEVICE_VENDOR_WR;
	cm.bRequest = 0xA0;
	cm.wValue = EZUSB_BASE_ADDRESS;
	cm.wIndex = 0x00;
	cm.wLength = 1;
	ret = usb.controlMessage(cm, &cmd, DEFAULT_TIMEOUT);
	wrapSleep_ms(10);
	return ret >= 0;
}

bool FX2Device_t::loadFirmware() {
	WRAP_ATOMIC_SCOPE;
	const size_t CHUNKLEN = 512;
	USBWrapperControlMessage_t cm;
	size_t addr;
	WRAPLOG(WRAPLOGL_DEBUG, "Loading FX2 firmware...");
	cm.bmRequestType = USBWRAP_CM_DEVICE_VENDOR_WR;
	cm.bRequest = 0xA0;
	cm.wIndex = 0x00;
	cm.wLength = CHUNKLEN;
	for(addr = 0; addr < m_firmwareBytesLen; addr += CHUNKLEN) {
		cm.wValue = addr;
		if(usb.controlMessage(cm, (uint8_t*)m_firmwareBytes + addr, DEFAULT_TIMEOUT) != CHUNKLEN) return false;
	}
	WRAPLOG(WRAPLOGL_DEBUG, "Done");
	return true;
}

bool FX2Device_t::I2CWriteRead(uint8_t addr, const uint8_t *outbuf, size_t outlen, uint8_t *inbuf, size_t inlen) {
	int ret;
//	WRAPLOG(WRAPLOGL_DEBUG, "FX2Device_t::I2CWriteRead(): addr: 0x%02X", addr);
	outlen &= 0xFF;
	inlen &= 0xFF;
	uint8_t wrbuf[4 + UINT8_MAX];
	uint8_t rdbuf[1 + UINT8_MAX];
	wrbuf[0] = MC_READ_I2C_GENERIC;
	wrbuf[1] = outlen;
	wrbuf[2] = inlen;
	wrbuf[3] = addr >> 1;
	memcpy(wrbuf + 4, outbuf, outlen);
	if(sendCommand(wrbuf, 4 + outlen, rdbuf, 1 + inlen, DEFAULT_TIMEOUT) != (1 + inlen)) {
		WRAPLOG(WRAPLOGL_ERROR, "I2C: Improper answer length");
		return false;
	}
	memcpy(inbuf, rdbuf + 1, inlen);
	if(rdbuf[0] != 8) {
		WRAPLOG(WRAPLOGL_ERROR, "I2C: Improper answer: status %02X", rdbuf[0]);
		return false;
	}
	return true;
}

bool FX2Device_t::I2CRead(uint8_t addr, uint8_t *inbuf, size_t inlen) {
	int ret;
//	WRAPLOG(WRAPLOGL_DEBUG, "FX2Device_t::I2CRead(): addr: 0x%02X", addr);
	inlen &= 0xFF;
	uint8_t wrbuf[4];
	uint8_t rdbuf[1 + UINT8_MAX];
	wrbuf[0] = MC_READ_I2C_GENERIC;
	wrbuf[1] = 0;
	wrbuf[2] = inlen;
	wrbuf[3] = addr >> 1;
	if(sendCommand(wrbuf, 4, rdbuf, 1 + inlen, DEFAULT_TIMEOUT) != (1 + inlen)) {
		WRAPLOG(WRAPLOGL_ERROR, "I2C: Improper answer length");
		return false;
	}
	memcpy(inbuf, rdbuf + 1, inlen);
	if(rdbuf[0] != 8) {
		WRAPLOG(WRAPLOGL_ERROR, "I2C: Improper answer: status %02X", rdbuf[0]);
		return false;
	}
	return true;
}

bool FX2Device_t::I2CWrite(uint8_t addr, const uint8_t *outbuf, size_t outlen) {
	int ret;
//	WRAPLOG(WRAPLOGL_DEBUG, "FX2Device_t::I2CWrite(): addr: 0x%02X", addr);
	outlen &= 0xFF;
	uint8_t wrbuf[3 + UINT8_MAX];
	uint8_t rdbuf[1];
	wrbuf[0] = MC_WRITE_I2C_GENERIC;
	wrbuf[1] = addr >> 1;
	wrbuf[2] = outlen;
	memcpy(wrbuf + 3, outbuf, outlen);
	if(sendCommand(wrbuf, 3 + outlen, rdbuf, 1, DEFAULT_TIMEOUT) != 1) {
		WRAPLOG(WRAPLOGL_ERROR, "I2C: Improper answer length");
		return false;
	}
	if(rdbuf[0] != 8) {
		WRAPLOG(WRAPLOGL_ERROR, "I2C: Improper answer: status %02X", rdbuf[0]);
		return false;
	}
	return true;
}

int FX2Device_t::getPortDir(uint8_t p) {
	USBWrapperControlMessage_t cm;
	int ret;
	uint8_t res;
	cm.bmRequestType = USBWRAP_CM_DEVICE_VENDOR_RD;
	cm.bRequest = VR_PORT_SETTING;
	cm.wValue = p | (VR_OP_GET_DIR << 8);
	cm.wIndex = 0;
	cm.wLength = 1;
	if(usb.controlMessage(cm, &res, DEFAULT_TIMEOUT) != 1) {
		WRAPLOG(WRAPLOGL_ERROR, "Error getting port direction");
		return -1;
	}
	return res;
}

bool FX2Device_t::setPortDir(uint8_t p, uint8_t v) {
	USBWrapperControlMessage_t cm;
	int ret;
	uint8_t res;
	cm.bmRequestType = USBWRAP_CM_DEVICE_VENDOR_RD;
	cm.bRequest = VR_PORT_SETTING;
	cm.wValue = p | (VR_OP_SET_DIR << 8);
	cm.wIndex = v;
	cm.wLength = 1;
	if((usb.controlMessage(cm, &res, DEFAULT_TIMEOUT) != 1) || (res != 1)) {
		WRAPLOG(WRAPLOGL_ERROR, "Error setting port direction");
		return false;
	}
	return true;
}

int FX2Device_t::getPortState(uint8_t p) {
	USBWrapperControlMessage_t cm;
	int ret;
	uint8_t res;
	cm.bmRequestType = USBWRAP_CM_DEVICE_VENDOR_RD;
	cm.bRequest = VR_PORT_SETTING;
	cm.wValue = p | (VR_OP_GET_STATE << 8);
	cm.wIndex = 0;
	cm.wLength = 1;
	if(usb.controlMessage(cm, &res, DEFAULT_TIMEOUT) != 1) {
		WRAPLOG(WRAPLOGL_ERROR, "Error getting port state");
		return -1;
	}
	return res;
}

bool FX2Device_t::setPortState(uint8_t p, uint8_t v) {
	USBWrapperControlMessage_t cm;
	int ret;
	uint8_t res;
	cm.bmRequestType = USBWRAP_CM_DEVICE_VENDOR_RD;
	cm.bRequest = VR_PORT_SETTING;
	cm.wValue = p | (VR_OP_SET_STATE << 8);
	cm.wIndex = v;
	cm.wLength = 1;
	if((usb.controlMessage(cm, &res, DEFAULT_TIMEOUT) != 1) || (res != 1)) {
		WRAPLOG(WRAPLOGL_ERROR, "Error setting port state");
		return false;
	}
	return true;
}
