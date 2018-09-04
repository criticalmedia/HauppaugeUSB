#ifndef __DEVICE_H_
#define __DEVICE_H_

#include <CoreFoundation/CoreFoundation.h>
#include <IOKit/IOKitLib.h>
#include <IOKit/IOMessage.h>
#include <IOKit/IOCFPlugIn.h>
#include <IOKit/usb/IOUSBLib.h>

#include <stdint.h>
#include <string.h>

#include "log.h"
#include "common.h"
#include "baseif.h"
#include "USBif.h"

//Wrapper to make initial Windows driver classes happy

class Device {
public:

};



//Device

class Device_t {
protected:
public:
};

#endif
