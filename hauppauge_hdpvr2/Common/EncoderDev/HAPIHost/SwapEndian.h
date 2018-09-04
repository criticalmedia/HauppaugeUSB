//=============================================================================
//  File Name: SwapEndian.h
//
//  Copyright 2009 Magnum Semiconductor Inc. All rights reserved.
//
//  Description:
//      SwapEndian function definitions.
//
//  Modification History:
//      $Id: $
//      $Log: $
//
//=============================================================================
#ifndef _SWAP_ENDIAN_H
#define _SWAP_ENDIAN_H

#include "HapiMsg.h"

#ifndef DRIVER_BUILD//HAUPPAUGE
#define SWAP16(us_value)  \
	    us_value = (((us_value) << 8) | (((us_value) >> 8) & 0xFF))

#define SWAP32(ui_value)  \
	    ui_value = (((ui_value) << 24) | (((ui_value) >> 24) & 0xFF) |  \
	    (((ui_value) >> 8) & 0xFF00) | (((ui_value) << 8) & 0xFF0000))


#else
#define SWAP16(us_value)  do_SWAP16((BYTE *)&(us_value))
#define SWAP32(us_value)  do_SWAP32((BYTE *)&(us_value))

#endif

Uint64 SWAP64(Uint64 ull);

int swapMessage(HWAPI_MSG_HEADER * pHeader, int direction);
void swapHeader(HWAPI_MSG_HEADER *pHeader);



#endif
