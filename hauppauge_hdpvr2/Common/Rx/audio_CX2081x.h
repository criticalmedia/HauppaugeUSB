#pragma once

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

#ifndef _AUDIO_CX2081X_H_
#define _AUDIO_CX2081X_H_

#include <cstdint>

#include "FX2Device.h"

typedef bool RET_STATUS;

class audio_CX2081x {
protected:
    FX2Device_t &m_fx2;
public:
    audio_CX2081x(FX2Device_t &fx2): m_fx2(fx2){}


    RET_STATUS writeByteNoLock(uint16_t register_address, uint8_t value);
    void init();
};


#endif // _AUDIO_CX2081X_H_
