#ifndef __FX2DEVICE_H_
#define __FX2DEVICE_H_

#include "baseif.h"
#include "log.h"
#include "USBif.h"

#define FX2_EP_CMD_WR 0x01
#define FX2_EP_CMD_RD 0x81
#define FX2_EP_SBP_WR 0x02
#define FX2_EP_SBP_RD 0x86

typedef enum {
	FX2_PORT_A = 0,
	FX2_PORT_B,
	FX2_PORT_C,
	FX2_PORT_D,
	FX2_PORT_E,
	FX2_REC_BUTTON,
	FX2_CTL_PORTS
} FX2_PORT_t;

class FX2Device_t {
protected:
	static const unsigned char m_firmwareBytes[];
	static const unsigned int m_firmwareBytesLen;
public:
	USBWrapper_t &usb;

	FX2Device_t(USBWrapper_t &_usb): usb(_usb) {}

	int sendCommand(const uint8_t *outbuf, size_t outlen, uint8_t *inbuf, size_t inlen, size_t timeout = 0);

	int getUSBSpeed();
	bool isUSBHighSpeed() {return getUSBSpeed() > 0;}
	bool stopCPU(bool v);
	bool stopCPU() {return stopCPU(true);}
	bool startCPU() {return stopCPU(false);}
	bool loadFirmware();

	bool I2CWriteRead(uint8_t addr, const uint8_t *outbuf, size_t outlen, uint8_t *inbuf, size_t inlen);
	bool I2CRead(uint8_t addr, uint8_t *inbuf, size_t inlen);
	bool I2CWrite(uint8_t addr, const uint8_t *outbuf, size_t outlen);

	int getPortDir(uint8_t p);
	bool setPortDir(uint8_t p, uint8_t v);
	int getPortState(uint8_t p);
	bool setPortState(uint8_t p, uint8_t v);
	bool setPortStateBits(uint8_t p, uint8_t set, uint8_t reset) {
		int r = getPortState(p);
		if(r < 0) return false;
		return setPortState(p, (r | set) & ~reset);
	}
};

#endif
