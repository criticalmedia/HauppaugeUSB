#include "audio_CX2081x.h"

//I2C Address of the CX2081x Four Channel ADC
#define CX2081x_DEVICE_ADDR	0x76
#define DEVICE_ID_MSB		0xFC
#define DEVICE_ID_LSB		0xFD
#define DEVICE_STEP_REV		0xFE
#define STATUS_OK true

static struct _reg_init {
    const char *name;
    uint8_t  reg;
    uint8_t  value;
} reg_init[] = {

        {"SOFT_RESET_CTRL", 0x0f, 0x02},//into reg reset
        {"SOFT_RESET_CTRL", 0x0f, 0x00},//out of reg reset
        {"SOFT_RESET_CTRL", 0x0f, 0x00},
        {"SOFT_RESET_CTRL", 0x0f, 0x00},

        {"REF_CTRL_1", 0x78, 0x2d},
        {"REF_CTRL_1", 0x78, 0x2D},
        {"REF_CTRL_1", 0x78, 0x2D},
        {"REF_CTRL_1", 0x78, 0x2D},

        {"REF_CTRL_1", 0x78, 0x6d},
        {"REF_CTRL_1", 0x78, 0x6D},
        {"REF_CTRL_1", 0x78, 0x6D},
        {"REF_CTRL_1", 0x78, 0x6D},

        {"REF_CTRL_3", 0x7A, 0x1},
        {"MCLK_PAD_CTRL", 0x80, 0x03},
        {"MCLK_CTRL", 0x08, 0x20},
        {"PLL_CTRL_1", 0x60, 0x53},//12.288MHz PLL
        {"PLL_CTRL_2", 0x61, 0x2F},//12.288MHz PLL
        {"PLL_CTRL_3", 0x62, 0x01},//12.288MHz PLL
        {"PLL_CTRL_4", 0x63, 0x03},
        {"PLL_CTRL_5", 0x64, 0x90},
        {"PLL_CTRL_6", 0x65, 0x24},
        {"PLL_CTRL_7", 0x66, 0x9},
        {"PLL_CTRL_8", 0x67, 0x9},
        {"PLL_CTRL_9", 0x68, 0x0},
        {"PLL_CTRL_10", 0x69, 0x0},
        {"PLL_CLK_CTRL", 0x09, 0x7},

        {"PWR_CTRL_3", 0x03, 0x0},
        {"PWR_CTRL_4", 0x04, 0x0},
        {"PWR_CTRL_1", 0x01, 0x1},

        {"PLL_DIV_CTRL", 0x0D, 0x08},
        {"PWM_CLK_CTRL", 0x0E, 0x03},

        {"ADC_TEST_CTRL0", 0x16, 0x00},
        {"ADC0_ANALOG_PGA", 0xBC, 0x00 },//0dB, Line-in, Red input
        {"ADC1_ANALOG_PGA", 0xBD, 0x00 },//0dB, Line-in, White input
        {"ADC2_ANALOG_PGA", 0xBE, 0x28}, //+20dB, Mic-in, Red input
        {"ADC3_ANALOG_PGA", 0xBF, 0x28}, //+20dB, Mic-in, White input

        {"I2S_CLK_CTRL", 0x0C, 0x3B},
        {"I2S_RX_PAD_CTRL", 0x82, 0x30},
        {"I2S_TX_PAD_CTRL", 0x83, 0x00},

        {"I2SDSP_CTRL_REG1", 0x30, 0x14},//7 wire mode, 24bits
        {"I2SDSP_CTRL_REG2", 0x31, 0x07},
        {"I2SDSP_CTRL_REG3", 0x32, 0x07},
        {"I2SDSP_MST_CTRL_REG1", 0x33, 0x1F},
        {"I2SDSP_MST_CTRL_REG2", 0x34, 0x1F},

        {"I2S_TX_CTRL_REG1", 0x35, 0xA0},//Left justified=0xA2, I2S=0xA0
        {"I2S_TX_CTRL_REG2", 0x36, 0x00},
        {"I2S_RX_CTRL_REG1", 0x37, 0x00},//disabled
        {"I2S_RX_CTRL_REG2", 0x38, 0x00},

        {"I2S_TX_CLK_CTRL", 0x0A, 0x03},//toggle some bits
        {"I2S_TX_CLK_CTRL", 0x0A, 0x83},
        {"I2S_RX_CLK_CTRL", 0x0B, 0x03},//toggle some bits
        {"I2S_RX_CLK_CTRL", 0x0B, 0x83},

        {"ADC_CLK_CNTRL", 0x10, 0x00},//toggle some bits
        {"ADC_EN_CTRL", 0x11, 0x00},//toggle some bits
        {"ADC_CLK_CNTRL", 0x10, 0x1F},
        {"ADC_EN_CTRL", 0x11, 0x4F},
        {"ADC_CLK_CNTRL", 0x10, 0x5F},

        {"DAC_Sample_rate", 0x29, 0x44},//??? BUGBUG we don't have a DAC

        {"ANA_ADC0_CTRL_1", 0xA0, 0x36},//25KOhm, no bias, Line-in, Red input
        {"ANA_ADC1_CTRL_1", 0xA7, 0x36},//25KOhm, no bias, Line-in, White input
        {"ANA_ADC2_CTRL_1", 0xAE, 0x06},//500KOhm, no bias, Mic-in, Red input
        {"ANA_ADC3_CTRL_1", 0xB5, 0x06},//500KOhm, no bias, Mic-in, White input

        //configure GPIO 1 as input, with no pullup
        {"GPIO1_PAD_CTRL", 0x85, 0x03},
        {"GPIO_OUT", 0x88, 0x09},
// {"GPIO_IN", 0x89, 0x02}, //BUGBUG - this is an input value, not an output

};

void audio_CX2081x::init() {
    RET_STATUS status = STATUS_OK;
    int i;

    int elems = sizeof(reg_init)/sizeof(reg_init[0]);
    for(i=0; i<elems; i++){
        uint8_t in[256] = {0}, out[256] = {0};
        in[0] = reg_init[i].reg;
        in[1] = reg_init[i].value;
        status = m_fx2.I2CWrite(CX2081x_DEVICE_ADDR, in, 2);
        if(!RET_STATUS(status)){
            DbgLogError(("CX2081xRegIo::initialize write reg=0x%x failed(0x%x)\n", reg_init[i].reg, status));
            break;
        }
    }
}

RET_STATUS audio_CX2081x::writeByteNoLock(uint16_t register_address, uint8_t value) {
    RET_STATUS ret = STATUS_OK;

    uint8_t buffer[2];
    uint8_t addr = (register_address & 0xff);

    {
        uint32_t dwValue = value;

        if (dwValue & 0x80000000) {// mode bit to set/clear selected bits
            value &= ~((dwValue >> 8) & 0xFF); //clear some bits
            value |= (dwValue & 0xFF);       //set some bits
        } else {
            value = (uint8_t) dwValue; //just use reg value as-is
        }
    }

    buffer[0] = addr;
    buffer[1] = value;

    return ret;
}