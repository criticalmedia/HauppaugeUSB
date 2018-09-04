//================================================================
//  File Name: mchip_utils.c
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

#include "mchip_utils.h"

#include <string.h>

/*****************************************************************
 * Function:    UtilSemCreate
 *****************************************************************/
void UtilSemCreate(DX_SEM_HANDLE *newSem){
	wrapSemCreate(newSem, 0);
}

/*****************************************************************
 * Function:    UtilSemGive
 *****************************************************************/
void UtilSemGive(DX_SEM_HANDLE sem){
	wrapSemGive(&sem);
}

/*****************************************************************
 * Function:    UtilSemTakeDbg
 *****************************************************************/
dxErrCode UtilSemTake(DX_SEM_HANDLE sem, int milliSeconds){
	int ret = wrapSemTake(&sem, milliSeconds);
	switch(ret) {
		case WRAPOS_OK:
			return DX_SUCCESS;
		case WRAPOS_TIMEOUT:
			return DX_ERR_TIMEOUT;
	}
	return DX_ERR_UNKNOWN;
}

/*****************************************************************
 * Function:    UtilSemDestroy
 *****************************************************************/
void UtilSemDestroy(DX_SEM_HANDLE *sem){
	wrapSemDestroy(sem);
}

/*****************************************************************
 * Function:    UtildxErrCodeToString
 *****************************************************************/
void UtildxErrCodeToString(dxErrCode err, int max, char *pString){

    switch(err){
        case DX_SUCCESS:
            strncpy(pString, "success", max);
            break;
        case DX_ERR_RECOVERABLE:
            strncpy(pString, "recoverable error", max);
            break;
        case DX_ERR_UNSUPPORTED_ACCESS_MODE:
            strncpy(pString, 
              "unsupported access mode - only 32-bit access supported", max);
            break;
        case DX_ERR_TIMEOUT:
            strncpy(pString, "timeout", max);
            break;
        case DX_ERR_BAD_PARAMETER:
            strncpy(pString, "bad parameter passed to function", max);
            break;
        case DX_ERR_RESOURCE_ALLOCATION_FAILED:
            strncpy(pString, "system resource allocation failed", max);
            break;
        case DX_ERR_READ_FAILED:
            strncpy(pString, "PCI read failed", max);
            break;
        case DX_ERR_WRITE_FAILED:
            strncpy(pString, "PCI write failed", max);
            break;
        case DX_ERR_PCI_SCAN_FAILED:
            strncpy(pString, "failed to scan PCI bus or no devices found", max);
            break;
        case DX_ERR_DEVICE_OPEN_FAILED:
            strncpy(pString, "failed to open device", max);
            break;
        case DX_ERR_DEVICE_CLOSE_FAILED:
            strncpy(pString, "failed to close device", max);
            break;
        case DX_ERR_DEVICE_MISSING_RESOURCES:
            strncpy(pString, 
              "device is missing resources - memory or interrupt", max);
            break;
        case DX_ERR_INSUFFICIENT_BUFFERS:
            strncpy(pString, "insufficient dma buffers", max);
            break;
        case DX_ERR_SYNC_FAILED:
            strncpy(pString, "DMA sync failed", max);
            break;
        case DX_ERR_ARRAY_TOO_SMALL:
            strncpy(pString, "semaphore array is too small", max);
            break;
        case DX_ERR_DRIVER_NAME_SET_FAILED:
            strncpy(pString, "failed to set driver name", max);
            break;
        case DX_ERR_DEBUG_SET_FAILED:
            strncpy(pString, "failed to set debug mode", max);
            break;
        case DX_ERR_LIB_INIT_FAILED:
            strncpy(pString, "failed to initialize the library", max);
            break;
        case DX_ERR_LIB_UNINIT_FAILED:
            strncpy(pString, "failed to uninitialize the library", max);
            break;
        case DX_ERR_OPERATION_ALREADY_DONE:
            strncpy(pString, "operation requested is already done", max);
            break;
        case DX_ERR_INTERRUPT_SET_FAILED:
            strncpy(pString, "failed to set interrupt", max);
            break;
        case DX_ERR_NOT_IMPLEMENTED:
            strncpy(pString, "function is not yet implemented", max);
            break;
        case DX_ERR_UNKNOWN:
            strncpy(pString, "unknown error has occurred", max);
            break;
        case DX_ERR_DONE:
            strncpy(pString, "input file is done", max);
            break;
        case DX_ERR_NOT_FOUND:
            strncpy(pString, "not found", max);
            break;
        case DX_ERR_WRONG_CHIP_TYPE:
            strncpy(pString, 
              "wrong chip - use E6 functions for DX1, MCHIP functions for MCHIP",
              max);
            break;
        case DX_ERR_MEMORY_ALLOCATION_FAILED:
            strncpy(pString, "failed to allocate some memory", max);
            break;
        case DX_ERR_INVALID_ADDRESS:
            strncpy(pString, "the address was invalid", max);
            break;
        case DX_ERR_INVALID_ID:
            strncpy(pString, "the ID was invalid", max);
            break;
        case DX_ERR_SDRAM_NOT_INITIALIZED:
            strncpy(pString, "SDRAM not initialized", max);
            break;
        default:
            strncpy(pString, "error code not recognized", max);
            break;
    }

    /* Make sure that the string is terminated. */
    pString[ max - 1 ] = 0;
}

/*****************************************************************
 * Function:    UtilThreadStart
 *****************************************************************/
dxErrCode UtilThreadStart(DX_THREAD_HANDLE *phThread, DX_UTIL_THREAD_FUNC pFunc, void *pData, const char *pName){
        int err = wrapThreadStart(phThread, pFunc, pData, pName);
	if(err != WRAPOS_OK) {
		return DX_ERR_UNKNOWN;
	}
	return DX_SUCCESS;
}

#ifndef DRIVER_BUILD//HAUPPAUGE
/*****************************************************************
 * Function:    UtilThreadWait
 *****************************************************************/
void UtilThreadWait(DX_THREAD_HANDLE *phThread){
	wrapThreadWait(phThread);
}
#endif//DRIVER_BUILD

/*****************************************************************
 * Function:    UtilThreadStop
 *****************************************************************/
void UtilThreadStop(DX_THREAD_HANDLE *phThread){
	wrapThreadStop(phThread);
}

#ifndef DRIVER_BUILD//HAUPPAUGE
/*****************************************************************
 * Function:    UtilThreadExit
 *****************************************************************/
void UtilThreadExit(int retval){
	wrapThreadExit(retval);
}
#endif

/*****************************************************************
 * Function:    UtilThreadSetPriority
 *****************************************************************/
dxErrCode UtilThreadSetPriority(DX_THREAD_HANDLE hThread, int priority){
    return DX_ERR_NOT_IMPLEMENTED;
}

/*****************************************************************
 * Function:    UtilSleep
 *****************************************************************/
void UtilSleep(unsigned int milliSecs){
	wrapSleep_ms(milliSecs);
}

/*****************************************************************
 * Function:    UtilGetTime
 *****************************************************************/
unsigned int UtilGetTime()
{
	return wrapGetTime_ms();
}
