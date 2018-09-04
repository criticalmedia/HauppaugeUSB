TARGET := HDPVR2-testApp

TOP := ../..
OS := $(shell uname -s | tr '[:upper:]' '[:lower:]')

SPACE :=
SPACE +=

PATH_COMMON = $(TOP)/Common $(TOP)/Common/colossus $(TOP)/Common/Wrappers/$(OS) $(TOP)/Common/FX2API
PATH_RX = $(TOP)/Common/Rx
PATH_ENCODERDEV = $(TOP)/Common/EncoderDev
PATH_HAPI = $(TOP)/Common/EncoderDev/HAPIHost $(TOP)/Common/EncoderDev/HAPIHost/MChip

VPATH = $(subst $(SPACE),:,.. $(PATH_COMMON) $(PATH_RX) $(PATH_ENCODERDEV) $(PATH_HAPI))

ifeq ($(OS), darwin)
ARCH := -arch i386 -arch x86_64
OS_INC := -I/System/Library/Frameworks/IOKit.framework/Headers
OS_LIB :=
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
OS_LIB := -L../../3rd-party/libusb-root-$(CPU)/lib -lrt
endif

INC = $(OS_INC) -I.. $(patsubst %,-I%,$(subst :, ,$(VPATH)))
LIB = -L../build-ADV7842
ifeq ($(OS), darwin)
CFLAGS := $(ARCH) -g -O3 $(INC)
CXXFLAGS := $(CFLAGS)
LDFLAGS := -mmacosx-version-min=10.8 $(ARCH) $(LIB) $(OS_LIB) -Wl,-framework,IOKit -Wl,-framework,CoreFoundation -lc -lc++ -lADV7842
else
CFLAGS := $(ARCH) -g -O3 -D_GNU_SOURCE $(INC)
CXXFLAGS := -std=c++0x $(CFLAGS)
LDFLAGS := $(ARCH) $(LIB) -lADV7842 $(OS_LIB) -lusb-1.0
endif

all: $(TARGET) stuff

stuff: ;
	ln -snf $(TOP)/Common/*.cfg .
	ln -snf $(TOP)/Common/EncoderDev/HAPIHost/bin/*.bin .

$(TARGET): main.o
	$(CXX) -o $@ $^ $(LDFLAGS)

clean:
	$(RM) *.cpp *.o $(TARGET) *.cfg *.bin

.PHONY: all clean stuff
