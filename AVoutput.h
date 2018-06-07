/*  -*- Mode: c++ -*-
 *
 * Copyright (C) John Poet 2018
 *
 * This file is part of HauppaugeUSB.
 *
 * HauppaugeUSB is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * HauppaugeUSB is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with HauppaugeUSB.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _AVoutput_H_
#define _AVoutput_H_

#include "Common.h"
#include "HauppaugeDev.h"
#include "USBif.h"

#include <atomic>
#include <string>
#include <vector>
extern "C" {
#include <libavformat/avformat.h>
}
#include <condition_variable>

class AVoutput
{
  public:
    AVoutput(const Parameters & params);
    ~AVoutput(void);

    void Terminate(void);
    void OpenDev(void);
    void Fatal(const std::string & msg);

    void BlockSize(uint32_t blocksz) { SetBlockSize(blocksz); }

    bool StartEncoding(void);
    bool OpenAVOutput(void);
    bool CloseAVOutput(void);
    bool StopEncoding(bool soft = false);

    void Fill(void * data, size_t len);
    void SetBlockSize(uint32_t sz) { m_block_size = sz; }
    DataTransfer::callback_t & getWriteCallBack(void) { return m_cb; }
    USBWrapper_t::callback_t & getErrorCallBack(void) { return m_error_cb; }
  protected:

    const Parameters   &m_params;
    HauppaugeDev       *m_dev;
    USBWrapper_t        m_usbio;
    
    DataTransfer::callback_t m_cb;
    USBWrapper_t::callback_t m_error_cb;
    uint32_t m_block_size;

    std::atomic<bool> m_run;
    std::string  m_fatal_msg;
    bool         m_fatal;

    std::atomic<bool> m_streaming;
    std::atomic<bool> m_ready;

    AVIOContext *avio_ctx;
};
#endif
