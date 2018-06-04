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

#include "AVoutput.h"
#include <unistd.h>

extern "C" {
#include <libavformat/avformat.h>
}

using namespace std;

const string VERSION = "0.1";

AVoutput::AVoutput(const Parameters & params)
    : m_params(params),
      m_dev(nullptr),
      m_cb(std::bind(&AVoutput::Fill, this, std::placeholders::_1, std::placeholders::_2)),
      m_run(true),
      m_fatal(false),
      m_streaming(false),
      m_ready(false)
{
    this->OpenDev();
    Logger::setThreadName("Buffer");
}

AVoutput::~AVoutput(void)
{
    Terminate();

    delete m_dev;
    m_dev = nullptr;
}

void AVoutput::Terminate(void)
{
    LOG(Logger::CRIT) <<"Terminating." << flush;
    StopEncoding(true);
    m_run = false;
}

void AVoutput::OpenDev(void)
{
    LOG(Logger::DEBUG) <<"Opening Hauppauge Dev." << flush;
    if (m_dev != nullptr)
        return;

    m_dev = new HauppaugeDev(m_params);
    if (!m_dev)
    {
        Fatal("Unable to create Hauppauge dev.");
        return;
    }
    if (!(*m_dev))
    {
        delete m_dev;
        m_dev = nullptr;
        Fatal(m_dev->ErrorString());
        return;
    }

    if (!m_usbio.Open(m_params.serial))
    {
        delete m_dev;
        m_dev = nullptr;
        Fatal(m_usbio.ErrorString());
        return;
    }

    if (!m_dev->Open(m_usbio, &getWriteCallBack()))
    {
        Fatal(m_dev->ErrorString());
        delete m_dev;
        m_dev = nullptr;

        m_usbio.Close();

        return;
    }

    m_ready = true;
}

void AVoutput::Fatal(const string & msg)
{
    LOG(Logger::CRIT) << msg << flush;

    m_fatal_msg = msg;
    m_fatal = true;
    m_run   = false;

    Terminate();
}

bool AVoutput::StartEncoding(void)
{
    if (m_streaming)
    {
        LOG(Logger::WARNING) << "Already streaming!" << flush;
        return true;
    }
    if (!m_ready)
    {
        LOG(Logger::CRIT) << "Hauppauge device not ready." << flush;
        return false;
    }

    if (m_dev->StartEncoding() && this->OpenAVOutput())
    {
        m_streaming = true;
        return true;
    }

    return false;
}

bool AVoutput::OpenAVOutput(void)
{
    int ret;
    av_register_all();
    avformat_network_init();
    LOG(Logger::CRIT) << "Output to : " << m_params.avoutput << flush;
    if ((ret = avio_open2(&this->avio_ctx, m_params.avoutput.c_str(), AVIO_FLAG_WRITE, NULL, NULL)) < 0) {
        LOG(Logger::CRIT) << "Can't Open output: " << m_params.avoutput << flush;
        return false;
    }
    return true;
}

bool AVoutput::CloseAVOutput(void)
{
    LOG(Logger::NOTICE) << "Close AVIO Output" << flush;
    avio_w8(this->avio_ctx, 0);
    avio_close(this->avio_ctx);
    return true;
}

bool AVoutput::StopEncoding(bool soft)
{
    if (!m_streaming)
    {
        if (!soft)
            LOG(Logger::WARNING) << "Already not streaming!" << flush;
        return true;
    }
    if (!m_ready)
    {
        LOG(Logger::CRIT) << "Hauppauge device not ready." << flush;
        return false;
    }

    if (!m_dev)
    {
        LOG(Logger::CRIT) << "Invalid Hauppauge device." << flush;
        return false;
    }

    if (m_dev->StopEncoding())
    {
        this->CloseAVOutput();
        m_streaming = false;
        return true;
    }

    return false;
}

void AVoutput::Fill(void * data, size_t len)
{
    if (len < 1) {
        return;
    }
    LOG(Logger::DEBUG) << "Got data with size: " << len << flush;
    avio_write(this->avio_ctx, (const unsigned char*)data, len);
    avio_flush(this->avio_ctx);
}
