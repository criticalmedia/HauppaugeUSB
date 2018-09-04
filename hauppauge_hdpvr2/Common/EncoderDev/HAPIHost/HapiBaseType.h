//============================================================================
//  File Name: HapiBaseType.h
//
// Copyright 2005 Magnum Semiconductor Inc.  All rights reserved.
//
//  Description:
//      Basic data types and definitions
//
//  Modification History:
//      $Id: $
//============================================================================

#ifndef _HAPI_BASE_TYPE_H
#define _HAPI_BASE_TYPE_H

#include <stdint.h>

#ifdef  __cplusplus
extern  "C"
{
#endif

#undef   TRUE
#define  TRUE    1

#undef   FALSE
#define  FALSE   0

#ifndef __APPLE__ // Not MAC
typedef uint32_t   Boolean;
typedef uint8_t    Byte;
typedef int8_t     Int8;
typedef int16_t    Int16;
#else
#include <MacTypes.h>
// Historically "Boolean" is "unsigned char" for MAC
#define Boolean uint32_t
#endif

typedef int32_t    Int32;

typedef uint64_t   Uint64;
typedef uint8_t    Uint8;
typedef uint16_t   Uint16;
typedef uint32_t   Uint32;

#ifndef MIN
#ifdef min
#define MIN min
#else
#define MIN(x, y) (((x) < (y)) ? (x):(y))
#endif
#endif

#ifndef NULL
#define NULL 0
#endif

#ifdef   __cplusplus
}
#endif


#define NOP_FUNCTION

//FGR - BUGBUG - Fixme
#if 1//DBG
 #define LOG_API_ENTRANCE	DbgLogTrace
 #define LOG_ERR		DbgLogError
 #define LOG_INFO		DbgLogInfo
 #define LOG_MSG		DbgLogTrace
 #define LOG_DBG		DbgLogTrace
#else
 #define LOG_API_ENTRANCE(...)	NOP_FUNCTION
 #define LOG_ERR			DbgLogError
 #define LOG_INFO(...)		NOP_FUNCTION
 #define LOG_MSG(...)		NOP_FUNCTION
 #define LOG_DBG(...)		NOP_FUNCTION
#endif

#endif //_basetype_H
