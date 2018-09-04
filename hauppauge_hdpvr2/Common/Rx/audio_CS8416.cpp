/*+++ *******************************************************************\
*
*  Copyright and Disclaimer:
*
*     ---------------------------------------------------------------
*     This software is provided "AS IS" without warranty of any kind,
*     either expressed or implied, including but not limited to the
*     implied warranties of noninfringement, merchantability and/or
*     fitness for a particular purpose.
*     ---------------------------------------------------------------
*
*     Copyright (c) 2011 Hauppauge Computer Works, Inc.
*     All rights reserved.
*
\******************************************************************* ---*/

#include <cstdint>
#include <map>
#include <stdexcept>

#include "audio_CS8416.h"

#define CS8416_DEVICE_ADDR       0x22
#define CS8416_DEVICE_ID         0x02

using REG = audio_CS8416::DeviceIO::Reg;

audio_CS8416::audio_CS8416(FX2Device_t &fx2)
{
    uint8_t reg_chipidn = static_cast<uint8_t>(DeviceIO::Reg::CHIPIDN);
    uint8_t chip_ver = 0x00;

    char id   = 0x00;
    char step = 0x00;

    fx2.I2CWriteRead(CS8416_DEVICE_ADDR, &reg_chipidn, 1, &chip_ver, 1);

    id   = 0x0F & (chip_ver >> 4);
    step = numToStepChar(0x0F & chip_ver);

    if (id != CS8416_DEVICE_ID || !step)
    {
        throw std::runtime_error("CS8416: device is not ready");
    }

    m_io_device = new DeviceIO(fx2);

    DbgLogInfo(("CS8416: initialized part ID: 0x%02X, stepping: %c\n", id, step));
}

audio_CS8416::~audio_CS8416()
{
    delete m_io_device;
}

bool audio_CS8416::reset(AudioInput in)
{
    std::map<AudioInput, std::pair<const char *, uint8_t>> inputs = {
        { AudioInput::MUTE,    { "MUTE" ,   0x00 } },
        { AudioInput::HDMI,    { "HDMI" ,   0x09 } },
        { AudioInput::OPTICAL, { "OPTICAL", 0x1B } }
    };

    uint8_t value;

    // init register Control 0
    value = CTRL0_PDUR;
    direct_io()->write(REG::CTRL0, &value, sizeof(value));

    // init register Control 1
    value = CTRL1_SWCLK | CTRL1_HOLD1;
    direct_io()->write(REG::CTRL1, &value, sizeof(value));

    // init register Control 2
    value = CTRL2_GPO0SEL1;
    direct_io()->write(REG::CTRL2, &value, sizeof(value));

    // init register Control 3
    value = CTRL3_GPO1SEL3 | CTRL3_GPO1SEL2 | CTRL3_GPO1SEL0 | CTRL3_GPO2SEL3 | CTRL3_GPO2SEL0;
    direct_io()->write(REG::CTRL3, &value, sizeof(value));

    // init register Control 4, set input source
    value = 0x00 | (0x3F & inputs[in].second);
    direct_io()->write(REG::CTRL4, &value, sizeof(value));

    // init Audio Serial Format register
    value = ASERFMT_SOMS | ASERFMT_SODEL | ASERFMT_SOLRPOL;
    direct_io()->write(REG::ASERFMT, &value, sizeof(value));

    // initReceiver Error Mask register
    value = RXEMSK_PARM | RXEMSK_BIPM | RXEMSK_CONFM | RXEMSK_UNLOCKM | RXEMSK_QCRCM | RXEMSK_CCRCM;
    direct_io()->write(REG::RXEMSK, &value, sizeof(value));

    // init Interrupt Mask register
    value = INTMSK_FCHM | INTMSK_RERRM | INTMSK_CCHM | INTMSK_PCCHM;
    direct_io()->write(REG::INTMSK, &value, sizeof(value));

    DbgLogInfo(("CS8416: reset: input is %s\n", inputs[in].first));

    run();

    return true;
}

void audio_CS8416::run()
{
    uint8_t value  = 0x00;

    direct_io()->read(REG::CTRL4, &value, sizeof(value));

    // set RUN bit to activate device
    value |= CTRL4_RUN;

    direct_io()->write(REG::CTRL4, &value, sizeof(value));
}

void audio_CS8416::stop()
{
    uint8_t value  = 0x00;

    direct_io()->read(REG::CTRL4, &value, sizeof(value));

    // clear RUN bit to stop device
    value &= ~CTRL4_RUN;

    direct_io()->write(REG::CTRL4, &value, sizeof(value));
}

char audio_CS8416::numToStepChar(uint8_t ver)
{
    switch(ver)
    {
        case 0x01: return 'A';
        case 0x02: return 'B';
        case 0x03: return 'C';
        case 0x07: return 'D';
        case 0x0F: return 'F';

        default:
            return 0x00;
    }
}

audio_CS8416::DeviceIO::DeviceIO(FX2Device_t &fx2) : m_fx2(fx2)
{
}

audio_CS8416::DeviceIO::~DeviceIO()
{
}

bool audio_CS8416::DeviceIO::write(DeviceIO::Reg reg, const uint8_t *data, size_t len)
{
    uint8_t singlebyte[2] = {0};
    uint8_t *sendbuff = NULL;

    bool result = false;

    std::lock_guard<std::mutex> lock(m_guard);

    if (!data || !len)
        return false;

    if (len == 1) {
        singlebyte[0] = static_cast<uint8_t>(reg);
        singlebyte[1] = *data;

        sendbuff = singlebyte;
    }
    else {
        sendbuff = static_cast<uint8_t*>(malloc(len + 1));
        *sendbuff = static_cast<uint8_t>(reg);
        memcpy(sendbuff + 1, data, len);
    }

    result = m_fx2.I2CWrite(CS8416_DEVICE_ADDR, sendbuff, len + 1);

    if (len > 1) {
        free(sendbuff);
    }

    return result;
}

bool audio_CS8416::DeviceIO::read(DeviceIO::Reg reg, uint8_t *data, size_t len)
{
    std::lock_guard<std::mutex> lock(m_guard);

    uint8_t reg_addr = static_cast<uint8_t>(reg);

    if (!data || !len)
        return false;

    if(!m_fx2.I2CWriteRead(CS8416_DEVICE_ADDR, &reg_addr, 1, data, len)) {
        DbgLogError(("CS8416: unable to read from register 0x%02X\n", reg_addr));
        return false;
    }

    return true;
}

