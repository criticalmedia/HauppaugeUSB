TOP := ../..
OS := $(shell uname -s | tr '[:upper:]' '[:lower:]')

VPATH = $(TOP)/Common/Rx $(TOP)/Common/Rx/ADV7842 $(TOP)/Common/Rx/ADV7842/RX/LIB $(TOP)/Common/Rx/ADV7842/RX/HAL \
$(TOP)/Common/Rx/ADV7842/RX/HAL/4G $(TOP)/Common/Rx/ADV7842/RX/HAL/4G/ADV7842/HAL \
$(TOP)/Common $(TOP)/Common/Wrappers/$(OS) $(TOP)/Common/FX2API \
$(TOP)/Common/EncoderDev $(TOP)/Common/EncoderDev/HAPIHost $(TOP)/Common/EncoderDev/HAPIHost/MChip

SPACE :=
SPACE +=

#OPTS := -DDRIVER_BUILD -DHAUPPAUGE -DHCW_E5BDA -DNO_PRV_SBP
OPTS := -DDRIVER_BUILD -DHAUPPAUGE -DHCW_E5BDA

ifeq ($(OS), darwin)
ARCH := -arch i386 -arch x86_64
OS_INC := -I/System/Library/Frameworks/IOKit.framework/Headers
else
CPU := x86_64
ifeq '$(CPU)' 'x86_64'
BITS := 64
else
BITS := 32
endif
ARCH := -pthread -m$(BITS)
#OS_INC := -I/usr/include/libusb-1.0
OS_INC := -I../../3rd-party/libusb-root-$(CPU)/include/libusb-1.0
endif

INC = $(OS_INC) -I.. -I$(TOP)/Common -I$(TOP)/Common/Wrappers/$(OS) -I$(TOP)/Common/FX2API \
-I$(TOP)/Common/Rx/ADV7842 -I$(TOP)/Common/Rx/ADV7842/RX -I$(TOP)/Common/Rx/ADV7842/RX/LIB \
-I$(TOP)/Common/Rx/ADV7842/RX/HAL -I$(TOP)/Common/Rx/ADV7842/RX/HAL/4G -I$(TOP)/Common/Rx/ADV7842/RX/HAL/4G/ADV7842/HAL \
-I$(TOP)/Common/Rx/ADV7842/RX/HAL/4G/ADV7842/MACROS \
-I$(TOP)/Common/Rx \
-I$(TOP)/Common/EncoderDev \
-I$(TOP)/Common/EncoderDev/HAPIHost -I$(TOP)/Common/EncoderDev/HAPIHost/MChip

ifeq ($(OS), darwin)
CFLAGS := $(ARCH) -g -O3 $(OPTS) $(INC)
CXXFLAGS := $(CFLAGS)
MK_A := libtool -static -o
else
CFLAGS := $(ARCH) -g -O3 -D_GNU_SOURCE $(OPTS) $(INC)
CXXFLAGS := -std=c++0x $(CFLAGS)
MK_A := ar rcs
endif

include $(TOP)/Common/Wrappers/$(OS)/files.mk

OBJS_COMMON := $(OBJS_WRAPPERS)

OBJS_FX2API := FX2Device.o FX2Firmware.o

OBJS_ENCODERDEV := encoderDev_DXT.o

OBJS_HAPI := CHapi.o Hapi.o HwapiUsb.o Queue.o SwapEndian.o bkv_init.o mchip_utils.o \
mchip.o mchip_base.o mchip_binary.o \
mchip_dram_bkv.o mchip_gpio.o mchip_host_rw.o mchip_led.o mchip_memtomem.o mchip_port_a.o mchip_sbp_rw.o \
mchip_test_gpio.o mchip_test_host.o mchip_test_led.o

OBJS_CX2081x := audio_CX2081x.o

OBJS_CS8416  := audio_CS8416.o

OBJS := \
7842_hal.o \
7844_hal.o \
7844_ini_hal.o \
rx_4g_hal.o \
rx_4g_hdmi_hal.o \
rx_afe_hal.o \
rx_cp_hal.o \
rx_hal.o \
rx_hdmi_hal.o \
rx_sdp_hal.o \
rx_sdp_vdp_hal.o \
rx_vdp_hal.o \
rx_afe.o \
rx_cdec.o \
rx_cec.o \
rx_cp.o \
rx_dpp_csc.o \
rx_gen.o \
rx_hdmi.o \
rx_isr.o \
rx_multi.o \
rx_sdp.o \
rx_vdp.o \
Wrapper.o \
receiver_ADV7842.o \
$(OBJS_COMMON) $(OBJS_FX2API) $(OBJS_ENCODERDEV) $(OBJS_HAPI) $(OBJS_CX2081x) $(OBJS_CS8416)

all: libADV7842.a

include $(TOP)/Common/FX2API/rules.mk

libADV7842.a: $(OBJS)
	$(MK_A) $@ $^

clean:
	$(RM) *.o *.a *.cpp

.PHONY: all clean
