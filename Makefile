
## Override path set by Hauppauge's make files, to use our 'wrappers'

override TOP := ./hauppauge_hdpvr2

BOOSTLIBDIR := /usr/lib64/boost148
BOOSTINCDIR := /usr/include/boost148

override VPATH = ${TOP} $(TOP)/Common/Rx $(TOP)/Common/Rx/ADV7842	\
$(TOP)/Common/Rx/ADV7842/RX/LIB $(TOP)/Common/Rx/ADV7842/RX/HAL	\
$(TOP)/Common/Rx/ADV7842/RX/HAL/4G				\
$(TOP)/Common/Rx/ADV7842/RX/HAL/4G/ADV7842/HAL $(TOP)/Common	\
./Wrappers/$(OS) $(TOP)/Common/FX2API $(TOP)/Common/EncoderDev	\
$(TOP)/Common/EncoderDev/HAPIHost				\
$(TOP)/Common/EncoderDev/HAPIHost/MChip

override INC = $(OS_INC) -I.. -I$(TOP)/Common -I./Wrappers/$(OS)	\
-I$(TOP)/Common/FX2API -I$(TOP)/Common/Rx/ADV7842			\
-I$(TOP)/Common/Rx/ADV7842/RX -I$(TOP)/Common/Rx/ADV7842/RX/LIB		\
-I$(TOP)/Common/Rx/ADV7842/RX/HAL					\
-I$(TOP)/Common/Rx/ADV7842/RX/HAL/4G					\
-I$(TOP)/Common/Rx/ADV7842/RX/HAL/4G/ADV7842/HAL			\
-I$(TOP)/Common/Rx/ADV7842/RX/HAL/4G/ADV7842/MACROS			\
-I$(TOP)/Common/Rx -I$(TOP)/Common/EncoderDev				\
-I$(TOP)/Common/EncoderDev/HAPIHost					\
-I$(TOP)/Common/EncoderDev/HAPIHost/MChip                               \
-I$(BOOSTINCDIR) \
`pkg-config --cflags libusb-1.0,libavformat`

override OBJS_WRAPPERS = log.o baseif.o registryif.o USBif.o I2Cif.o
override OS_INC := `pkg-config --cflags libusb-1.0,libavformat`

# override CXXFLAGS := -g -c -Wall -std=c++11 ${CFLAGS}

include ./hauppauge_hdpvr2/TestApp/build-ADV7842/Makefile

REC_CXX := c++
REC_CXXFLAGS := -g -c -Wall -std=c++11   -D_GLIBCXX_USE_NANOSLEEP -DBOOST_LOG_DYN_LINK ${CFLAGS}
REC_LDFLAGS =

#	        `pkg-config --libs libsystemd` \

REC_LDFLAGS  += `pkg-config --libs libusb-1.0,libavformat` \
	        -lpthread

REC_SOURCES = Logger.cpp Common.cpp AVoutput.cpp HauppaugeDev.cpp hauppauge2.cpp
REC_HEADERS = Logger.h Common.h AVoutput.h HauppaugeDev.h
REC_OBJECTS = $(REC_SOURCES:.cpp=.o)

CONF = etc/sample.conf
FIRMWARE = hauppauge_hdpvr2/Common/EncoderDev/HAPIHost/bin/llama_usb_vx_host_slave_t22_24.bin hauppauge_hdpvr2/Common/EncoderDev/HAPIHost/bin/mips_vx_host_slave.bin
TRANSIENT = FX2Firmware.cpp mchip_binary.cpp
REC_EXE  = hauppauge2
REC_LIBS = libADV7842.a
REC_LIBS += -L$(BOOSTLIBDIR) -lboost_program_options -lboost_system -lboost_filesystem

all: ${REC_EXE}

${REC_EXE}: ${REC_OBJECTS}
	${REC_CXX} ${REC_OBJECTS} -o $@ ${REC_LIBS} ${REC_LDFLAGS} 

${REC_OBJECTS}: ${REC_SOURCES}

.cpp.o:
	${REC_CXX} ${REC_CXXFLAGS} $< -o $@

#.c.o:
#	${REC_CXX} ${REC_CXXFLAGS} $< -o $@

clean:
	$(RM) *.o *.a ${REC_EXE} ${TRANSIENT}

install:
	mkdir -p $(DESTDIR)/usr/sbin
	mkdir -p $(DESTDIR)/lib/firmware/Hauppauge
	mkdir -p $(DESTDIR)/etc/Hauppauge
	install -m0755 $(REC_EXE) $(DESTDIR)/usr/sbin
	install -m0644 $(FIRMWARE) $(DESTDIR)/lib/firmware/Hauppauge
	install -m0644 $(CONF) $(DESTDIR)/etc/Hauppauge
