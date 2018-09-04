/**********************************************************************************************
*                                                                                             *
* Copyright (c) 2012 Analog Devices, Inc.  All Rights Reserved.                               *
* This software is proprietary and confidential to Analog Devices, Inc. and its licensors.    *
*                                                                                             *
***********************************************************************************************/
#ifndef _WRAPPER_H_
#define _WRAPPER_H_

#include <stdint.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

/* The values of these definitions are currently set as per ADI evaluation platforms and the ADI example application*/
/* If the ADI example application is ported and customised it is important to review and set these options accordingly*/
/* Please refer to release build options file and DVP documentation for futher information*/

#define RX_DEVICE           7842  /*Set the Target Rx  device. Tv Driver supports the following devices: 7844, 7842, 7604, 7840, 7612, 7611, 7614, 7622/3, 7619 */
#define RX_USER_CONFIG         1  /*Always set to 1 when using ADI REP Middleware and ADI REP Application. */
#define RX_USER_INIT           0  /*Always set to 0. Set to 1 for customer initialisation custimization only. */
#define RX_ES_ID               0  /*For unreleased products set to 1,2 for ES1 and ES2 legacy Engineering samples only. Set to 0 for released products*/
 
#define UART_DEBUG             1  /*Set to 1 to enable Debug message Printouts. Set to 0 to disable.  */

#define IGNORE_INT_LINES       1  /*Set to 1 to ignore hw interrupt pin status to determine if interrupt is pending. Software method used only*/
#define RX_INCLUDE_VBI         0
#define MULTI_RX_NUM           0


/*=======================================
 * Data types
 *======================================*/
 
#define STATIC      static
#define INLINE      inline
#define CONSTANT    const
#define EXTERNAL    extern
#define PACKED      __attribute__((packed))
#define PACKED_STR  struct PACKED

typedef uint8_t     UCHAR;          /* unsigned 8-bit */
typedef uint16_t    UINT16;         /* unsigned 16-bit */
typedef uint32_t    UINT32;         /* unsigned 32-bit */
typedef uint64_t    UINT64;         /* unsigned 64-bit */
typedef int16_t     INT16;
typedef int32_t     INT32;
typedef int8_t      CHAR;

#define UINT8           UCHAR

#ifndef BOOL
#define BOOL            UCHAR
#endif

#ifndef TRUE
#define TRUE            1
#endif

#ifndef FALSE
#define FALSE           0
#endif

#ifndef NULL
#define NULL            ((void *)0)
#endif

typedef uint16_t u16;
typedef uint32_t u32;
typedef uint8_t u8;
//typedef char*  va_list;


/*===========================================================
 * Global defines
 *==========================================================*/
EXTERNAL UINT32 AtvDummy;


/*===========================================================
 * Defines and Macros
 *==========================================================*/
#define MAX_VIC_VALUE                   64
#define NUM_OF_VICS                     (MAX_VIC_VALUE+1)


#define AV_IF_PKT_SIZE                  16
#define AUD_IF_PKT_SIZE                 13
#define ACP_PKT_SIZE                    31
#define SPD_PKT_SIZE                    31
#define ISRC1_PKT_SIZE                  31
#define ISRC2_PKT_SIZE                  31
#define GMD_PKT_SIZE                    31
#define VS_PKT_SIZE                     31
#define MS_PKT_SIZE                     17
#define MAX_HDMI_PACKET_SIZE            32
  

#define CEC_TRIPLE_NUMBER               3

#if UART_DEBUG
    #define DBG_MSG                 DBG_Printf
#else
    #define DBG_MSG(...)
#endif

#define ATV_DUMMY_SET(a)                AtvDummy=(UINT32)a

#if (RX_DEVICE == 7623) || (RX_DEVICE == 7622) || (RX_DEVICE == 76221)
#define RX_I2C_IO_MAP_ADDR              0xB2
#define RX2_I2C_IO_MAP_ADDR             0xB0
#elif (RX_DEVICE == 7612) || (RX_DEVICE == 7611) || (RX_DEVICE == 7619)
#define RX_I2C_IO_MAP_ADDR              0x98
#define RX2_I2C_IO_MAP_ADDR             0x98
#elif (RX_DEVICE == 7630) 
#define RX_I2C_IO_MAP_ADDR              0xB0
#else
#define RX_I2C_IO_MAP_ADDR              0x40
#define RX2_I2C_IO_MAP_ADDR             0xB4
#endif

#define RX_I2C_SDP_VDP_MAP_ADDR         0x22 
#define RX_I2C_AFE_DPLL_MAP_ADDR        0x4C	//*
#define RX_I2C_ESDP_MAP_ADDR            0x34    /* Def 0x70 */
#define RX_I2C_SDP_IO_MAP_ADDR          0x94	//*
#define RX_I2C_CP_MAP_ADDR              0x44
#define RX_I2C_VDP_MAP_ADDR             0x48
#define RX_I2C_TEST_MAP3_ADDR           0x52
#define RX_I2C_TEST_MAP1_ADDR           0x60
#define RX_I2C_TEST_MAP2_ADDR           0x62
#define RX_I2C_REPEATER_MAP_ADDR        0x64
#define RX_I2C_HDMI_MAP_ADDR            0x6A	//*
#define RX_I2C_EDID_MAP_ADDR            0x6C
#define RX_I2C_DPP_MAP_ADDR             0x74    /* Def 0x78 */
#define RX_I2C_INFOFRAME_MAP_ADDR       0x76    /* 0x7C on ATV_MB seems to cause readback of all 0x00, occasionally. Happens more often when no Sink is connected */
#define RX_I2C_CEC_MAP_ADDR             0x80 
#define RX_I2C_SDP_MAP_ADDR             0x90	//*
#define RX_I2C_AVLINK_MAP_ADDR          0x84 
#define RX_I2C_OSD_MAP_ADDR             0x88
#define RX_I2C_AUDIO_CODEC_MAP_ADDR     0x5C 
#define RX_I2C_XMEM_MAP_ADDR            0xA8
#define RX_I2C_VFE_MAP_ADDR             0xA0

#define RX2_I2C_SDP_VDP_MAP_ADDR        0xC0 
#define RX2_I2C_AFE_DPLL_MAP_ADDR       0xC2
#define RX2_I2C_ESDP_MAP_ADDR           0xC4    /* Def 0x70 */
#define RX2_I2C_SDP_IO_MAP_ADDR         0xC6 
#define RX2_I2C_CP_MAP_ADDR             0xC8
#define RX2_I2C_VDP_MAP_ADDR            0xCA
#define RX2_I2C_TEST_MAP3_ADDR          0xCC
#define RX2_I2C_TEST_MAP1_ADDR          0xCE
#define RX2_I2C_TEST_MAP2_ADDR          0xD0
#define RX2_I2C_REPEATER_MAP_ADDR       0xD2
#define RX2_I2C_HDMI_MAP_ADDR           0xD4
#define RX2_I2C_EDID_MAP_ADDR           0xD6
#define RX2_I2C_DPP_MAP_ADDR            0xD8    /* Def 0x78 */
#define RX2_I2C_INFOFRAME_MAP_ADDR      0xDA
#define RX2_I2C_CEC_MAP_ADDR            0xDC 
#define RX2_I2C_SDP_MAP_ADDR            0xDE 
#define RX2_I2C_AVLINK_MAP_ADDR         0xE0 
#define RX2_I2C_OSD_MAP_ADDR            0xE2
#define RX2_I2C_VFE_MAP_ADDR            RX_I2C_VFE_MAP_ADDR
#define RX2_I2C_AUDIO_CODEC_MAP_ADDR    RX_I2C_AUDIO_CODEC_MAP_ADDR
#define RX2_I2C_XMEM_GAMMA_MAP_ADDR     RX_I2C_XMEM_MAP_ADDR
#if (TX_DEVICE == 8002)
#define TX_I2C_PKT_MEM_MAP_ADDR         0xF2 
#define TX_I2C_CEC_MAP_ADDR             0xF0 
#define TX_I2C_EDID_MAP_ADDR            0xEE 
#define TX2_I2C_PKT_MEM_MAP_ADDR        0xFA 
#define TX2_I2C_CEC_MAP_ADDR            0xF8 
#define TX2_I2C_EDID_MAP_ADDR           0xF6 
#else
#define TX_I2C_PKT_MEM_MAP_ADDR         0x70
#define TX_I2C_CEC_MAP_ADDR             0x78
#if ( (TX_DEVICE == 7511) && (TX_NUM_OF_DEVICES > 1))
#define TX_I2C_EDID_MAP_ADDR            0xFE
#else
#define TX_I2C_EDID_MAP_ADDR            0x7E
#endif
#define TX_I2C_TEST1_MAP_ADDR           0x92
#if ( RX_NUM_OF_DEVICES > 1 )
#define TX2_I2C_PKT_MEM_MAP_ADDR        0x7C
#else
#define TX2_I2C_PKT_MEM_MAP_ADDR        0x76
#endif
#define TX2_I2C_CEC_MAP_ADDR            0x82
#define TX2_I2C_EDID_MAP_ADDR           0x86
#endif

#if (MULTI_RX_NUM) 
#define RX_NUM_OF_DEVICES               2 
#else
#define RX_NUM_OF_DEVICES               1
#endif

#if ( RX_NUM_OF_DEVICES > 1 )
#define RX_SPLITTER                     1
#else
#define RX_SPLITTER                     0
#endif

#if (RX_DEVICE != 7850)
#define RX_INCLUDE_CEC                  1
#else
#define RX_INCLUDE_CEC                  0
#endif

/*========================================
 * Enums and structures
 *=======================================*/
typedef enum
{
    ATVERR_OK=0,
    ATVERR_FALSE=0,
    ATVERR_TRUE=1,
    ATVERR_INV_PARM,
    ATVERR_NOT_AVAILABLE,
    ATVERR_FAILED
} ATV_ERR;

typedef struct
{
    UCHAR   RegAddr;        /* Register address */
    UCHAR   Mask;           /* Mask for the bits in RegAddr */
    UCHAR   LShift;         /* Absolute left shift (in 2's complement) of */
                            /* field bits in RegAddr */
    UCHAR   Reserved;
} I2C_FIELD_INFO;


typedef struct
{
    BOOL TxReady;
    BOOL RxReady;
    BOOL ArbLost;
    BOOL Timeout;
    BOOL RxReady1;
    BOOL RxReady2;
    BOOL RxReady3;
    UCHAR RxFrameOrder[CEC_TRIPLE_NUMBER];    
}CEC_INTERRUPTS;

enum
{
    CEC_EVENT_RX_MSG, 
    CEC_EVENT_TX_DONE,
    CEC_EVENT_TX_TIMEOUT,
    CEC_EVENT_TX_ARB_LOST,
    CEC_EVENT_LOG_ADDR_ALLOC,
    CEC_EVENT_LOG_ADDR_LIST,
    CEC_EVENT_RX_MSG_RESPOND
};
/*========================================
 * Auxiliary 8-bit I2C field access macros
 *=======================================*/
#define ATV_I2CIsField8                             (BOOL)ATV_I2CReadField8
#define ATV_I2CGetField8(d,r,m,b,p)                 *p=ATV_I2CReadField8(d,r,m,b)
#define ATV_I2CGetField32(d,r,Mm,Lm,b,s,p)          *p=ATV_I2CReadField32(d,r,Mm,Lm,b,s)
#define ATV_I2CGetField32LE(d,r,Mm,Lm,b,s,p)        *p=ATV_I2CReadField32LE(d,r,Mm,Lm,b,s)
#define ATV_I2CGetMultiField(d,r,s,p)               HAL_I2CReadBlock(d,r,p,(UINT16)s)


void    HAL_DelayMs (UINT16 Counter);
UCHAR   HAL_I2CReadByte (UCHAR Dev, UCHAR Reg, UCHAR *Data);
UCHAR   HAL_I2CWriteByte (UCHAR Dev, UCHAR Reg, UCHAR Data);
UINT16  HAL_I2CReadBlock (UCHAR Dev, UCHAR Reg, UCHAR *Data, UINT16 NumberBytes);
UINT16  HAL_I2CWriteBlock (UCHAR Dev, UCHAR Reg, const UCHAR *Data, UINT16 NumberBytes);
UCHAR HAL_SetRxChipSelect(UCHAR DevIdx);
void WaitMilliSec(unsigned int msec);
void DBG_Printf(const char *data, ...);


UCHAR   ATV_I2CReadField8   (UCHAR DevAddr, UCHAR RegAddr, UCHAR Mask,
                             UCHAR BitPos);
void    ATV_I2CWriteField8  (UCHAR DevAddr, UCHAR RegAddr, UCHAR Mask,
                             UCHAR BitPos,  UCHAR FieldVal);
UINT32  ATV_I2CReadField32  (UCHAR DevAddr, UCHAR RegAddr, UCHAR MsbMask,
                             UCHAR LsbMask, UCHAR LsbPos, UCHAR FldSpan);
UINT32  ATV_I2CReadField32LE   (UCHAR DevAddr, UCHAR RegAddr, UCHAR MsbMask,
                                UCHAR LsbMask, UCHAR LsbPos,  UCHAR FldSpan);
void    ATV_I2CWriteField32      (UCHAR DevAddr, UCHAR RegAddr, UCHAR MsbMask,
                                  UCHAR LsbMask, UCHAR LsbPos,  UCHAR FldSpan,
                                  UINT32 Val);
void    ATV_I2CWriteField32LE    (UCHAR DevAddr, UCHAR RegAddr, UCHAR MsbMask,
                                  UCHAR LsbMask, UCHAR LsbPos,  UCHAR FldSpan,
                                  UINT32 Val);
void ATV_I2CWriteRandField32 (UCHAR DevAddr, I2C_FIELD_INFO *FldInfo,
								  UCHAR FldSpan, UINT32 Val);
void    ATV_I2CWriteFields (const UCHAR *Table, UCHAR EndVal);
void    ATV_I2CWriteTable (const UCHAR *Table, UCHAR EndVal);
UINT16  ATV_LookupValue8 (const UCHAR *Table, UCHAR Value, UCHAR EndVal, UINT16 Step);
void    ATV_PrintTime (char *Prefix, UCHAR Gran, char *Postfix);

UINT32  ATV_GetElapsedMs (UINT32 StartCount, UINT32 *CurrMsCount);
UINT32  ATV_GetMsCountNZ (void);


ATV_ERR CEC_Reset (void);
ATV_ERR CEC_Enable (BOOL Enable);
ATV_ERR CEC_SetLogicalAddr (UCHAR LogAddr, UCHAR DevId, BOOL Enable);
ATV_ERR CEC_SendMessage (UCHAR *MsgPtr, UCHAR MsgLen);
ATV_ERR CEC_SendMessageOut (void);
ATV_ERR CEC_ResendLastMessage (void);
ATV_ERR CEC_AllocateLogAddr (UCHAR *LogAddrList);
ATV_ERR CEC_GetLogAddrList (UCHAR SrcLogAddr);
void CEC_Isr (CEC_INTERRUPTS *CecInts);

#ifdef __cplusplus
}
#endif

#endif
