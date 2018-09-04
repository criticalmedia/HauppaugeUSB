//=============================================================================
//  File Name: Hapi_priv.h
//
//  Copyright 2009 Magnum Semiconductor Inc. All rights reserved.
//
//  Description:
//      HAPI private definitions.
//
//  Modification History:
//      $Id: $
//      $Log: $
//
//=============================================================================
#ifndef _HAPI_PRIV_H_
#define _HAPI_PRIV_H_

#include "mchip_utils.h"
#include "Queue.h"
#include "HapiMsg.h"

#ifdef  __cplusplus
extern  "C"
{
#endif

/* HAPI state enumeration. The state is set by HAPI API function calls such as HAPI_Start() and HAPI_Stop(). */
typedef enum {
	HAPI_STATE_IDLE,	// Initial state. Go to INIT state if HAPI_Init() is called.
	HAPI_STATE_INIT,	// HAPI is initialized. Go to START state if HAPI_Start() is called. Go to IDLE state if HAPI_Exit() is called.
	HAPI_STATE_START,	// HAPI is stated and running. Go to INIT state if HAPI_Stop() is called.
} HAPI_STATE;

typedef struct _HAPIStruct
{
	Uint32 chipID;
	HWAPIHandle cmdBus;
	HWAPIHandle dataBus;
	Uint32 endianSwap;
	DX_THREAD_HANDLE cmdThread;
	DX_THREAD_HANDLE dataThread;
	DX_THREAD_HANDLE mainThread;
	DX_THREAD_HANDLE writeThread;
	DX_THREAD_HANDLE callbackThread;
	QueueHandle sendQueue;
	QueueHandle sendAndWaitQueue;
	QueueHandle receiveQueue;
#ifndef HAUPPAUGE//not used
	QueueHandle waitResponseQueue;
#endif
	QueueHandle callbackQueue;          // Queue for messages that are handled by callbackThread. Messages going to the queue should be asynchronous messages from DXT that require callback.
	DX_SEM_HANDLE userCmdSem;
	DX_SEM_HANDLE sendQueueSem;
	DX_SEM_HANDLE sendAndWaitQueueSem;
	DX_SEM_HANDLE receiveQueueSem;
#ifndef HAUPPAUGE//not used
	DX_SEM_HANDLE waitResponseQueueSem;
#endif
	DX_SEM_HANDLE cmdBusSem;
	DX_SEM_HANDLE dataBusSem;	
	DX_SEM_HANDLE cbQueueSem;       //callback queue semaphore
	Uint32 cookie, responseCookie;
	Uint32 userCmdResponseCode;
	HAPI_SET_PARAM SetParam; // parameters that have been send to board
	HAPI_GET_PARAM GetParam; // parameters that are get from board

	HAPI_AVDataSend dataSend;
	HAPI_AVDataReceive dataReceive;
    HAPI_I2CMonitorCallback I2CMonitorCallback;
    HAPI_ErrorMsgCallback    ErrorMsgCallback;
#ifndef HAUPPAUGE
    void* errCbContext;
#else
	void *context;
#endif
    HAPI_QUERY_STRUCT queryStatus;
    HAPI_I2C_MONITOR_PARAM I2CMonitorparams[HAPI_I2C_MONITOR_MAX];

    HAPI_I2C_READ_PARAM        I2CReadParam;
    Uint32                     GpioReturnVal;
    Uint16                     I2CClockFreq;

	HWAPI_MSG_HEADER * pMsgWaitingRsp;
	Uint32 timeStartWaiting;

	Uint8 exitCmdThread;
	Uint8 exitDataThread;
	Uint8 exitMainThread;
	Uint8 exitWriteThread;
	Uint8 exitCBThread;         // to exit callback thread?
       
	HAPI_STATE state;
	
}HAPIStruct;

typedef HAPIStruct * HAPIHandler;

#ifdef   __cplusplus
}
#endif

#endif
