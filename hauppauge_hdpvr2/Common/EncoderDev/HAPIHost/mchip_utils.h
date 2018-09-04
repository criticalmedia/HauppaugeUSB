//================================================================
//  File Name: mchip_utils.h
//
//  Copyright 2008 Magnum Semiconductor Inc.  All rights reserved.
//
//  Description:
//
//  Utility functions for use with the DX driver to improve
//  portability across different operating systems.
//
//  Modification History:
//
//================================================================

#ifndef _DX_UTILS_H_
#define _DX_UTILS_H_

#include "mchip_defines_public.h"
#include "baseif.h"
#include "registryif.h"

#if defined(WIN32)
#define DLLCALL __stdcall
#else
#define DLLCALL
#endif

typedef void (DLLCALL *DX_UTIL_THREAD_FUNC)(void *pData);
typedef void *DX_SEM_HANDLE;
typedef wrapThread_t DX_THREAD_HANDLE;

static void *MemAllocFromHeap(const char *file, int line, int size)
{
	if(size % 8)
	{
		size = ((size/8) + 1 ) * 8;
	}
	void *p = wrapHeapAlloc( size );
//	DbgLogTrace(("MemAllocFromHeap(%u) file %s line %d returned %p\n", size, file, line, p ));
	return p;
}

static void MemFree2Heap(const char *file, int line, void *buf)
{
//	DbgLogTrace(("MemFree2Heap(%p) %s line %d\n", buf, file, line));
	if( buf )
	{
		wrapHeapFree( buf );
//		buf = NULL;
	}
}

/*****************************************************************
 * Function:    UtilSemCreate
 *
 * Description: returns a binary semaphore than can be attached
 *              to an interrupt from either linux or windows
 *
 * output:        newSem - sem to be returned
 *****************************************************************/
void UtilSemCreate(DX_SEM_HANDLE *newSem);

/*****************************************************************
 * Function:    UtilSemGive
 *
 * Description: releases a sem, linux or windows
 * 
 * input:       sem - sem to be released
 *****************************************************************/
void UtilSemGive(DX_SEM_HANDLE sem);

/*****************************************************************
 * Function:    UtilSemTakeDbg
 *
 * Description: waits on a sem for specified # milliseconds
 * 
 * input:       sem - sem to be released
 *
 * returns:     DX_SUCCESS for given, DX_ERR_TIMEOUT for timeout, DX_ERR_UNKNOWN other
 *****************************************************************/
dxErrCode UtilSemTake(DX_SEM_HANDLE sem, int milliSeconds);
#define UtilSemTakeDbg(S,T,L) UtilSemTake(S,T)

/*****************************************************************
 * Function:    UtilSemDestroy
 *
 * Description: destroys a previously created sem
 * 
 * input:       sem - sem to be destroyed
 *****************************************************************/
void UtilSemDestroy(DX_SEM_HANDLE *sem);

/*****************************************************************
 * Function:    UtildxErrCodeToString
 *
 * Description: returns a string with text of the error code
 * 
 * input:       err - error code to find
 *              max - max number of chars to write to string
 *
 * output:      pString - dxErrCode string
 *****************************************************************/
void UtildxErrCodeToString(dxErrCode err, int max, char *pString);

/*****************************************************************
 * Function:    UtilThreadStart
 *
 * Description: returns a string with text of the error code
 * 
 * input:       pFunc - func to start
 *              pData - data to pass to the function
 *              pName - name of thread
 *
 * output:      phThread - handle to the thread
 *****************************************************************/
dxErrCode UtilThreadStart(DX_THREAD_HANDLE *phThread, DX_UTIL_THREAD_FUNC pFunc, void *pData, const char *pName);

/*****************************************************************
 * Function:    UtilThreadWait
 *
 * Description: waits until a thread exits
 * 
 * input:       phThread - pointer to thread handle returned from UtilThreadStart
 *****************************************************************/
#ifndef DRIVER_BUILD//HAUPPAUGE
void UtilThreadWait(DX_THREAD_HANDLE *phThread);
#endif

/*****************************************************************
 * Function:    UtilThreadStop
 *
 * Description: stops a thread
 * 
 * input:       phThread - pointer to thread handle returned from UtilThreadStart
 *****************************************************************/
void UtilThreadStop(DX_THREAD_HANDLE *phThread);
/*****************************************************************
 * Function:    UtilThreadExit
 *
 * Description: exit self thread
 * 
 * input:       phThread - pointer to thread handle returned from UtilThreadStart
 *****************************************************************/
#ifndef DRIVER_BUILD//HAUPPAUGE
void UtilThreadExit(int retval);
#endif

/*****************************************************************
 * Function:    UtilThreadSetPriority
 *
 * Description: sets the thread priority
 *
 * input:       phThread - pointer to thread handle returned from UtilThreadStart
 *              priority - the priority to set
 *****************************************************************/
dxErrCode UtilThreadSetPriority(DX_THREAD_HANDLE hThread, int priority);

/*****************************************************************
 * Function:    UtilSleep
 *
 * Description: stops a thread
 * 
 * input:       milliSecs
 *****************************************************************/
void UtilSleep(unsigned int milliSecs);

/*****************************************************************
 * Function:    UtilGetTime
 *
 * Description: Get the current system time 
 * 
 * input:       the point to time variable
 *****************************************************************/
unsigned int UtilGetTime();

#endif
