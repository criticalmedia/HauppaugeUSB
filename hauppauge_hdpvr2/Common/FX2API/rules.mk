FX2FIRMWARE_VAR = FX2Device_t::m_firmwareBytes

FX2Firmware.o: FX2Firmware.cpp

FX2Firmware.cpp: FX2Firmware.bin
	echo '#include "FX2Device.h"' > $@
	xxd -u -i $^ | sed -E 's/unsigned char [_a-zA-Z0-9]{1,}/const unsigned char $(FX2FIRMWARE_VAR)/' | sed -E 's/unsigned int [_a-zA-Z0-9]{1,}/const unsigned int $(FX2FIRMWARE_VAR)Len/' >> $@
