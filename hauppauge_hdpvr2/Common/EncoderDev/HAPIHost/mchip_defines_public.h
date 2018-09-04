//================================================================
//  File Name: mchip_defines_public.h
//
//  Copyright 2008 Magnum Semiconductor Inc.  All rights reserved.
//
//  Description:
//
//  Public defines, etc for the DX libraries.
//
//  Modification History:
//
//================================================================

#ifndef _DX_DEFINES_PUBLIC_H_
#define _DX_DEFINES_PUBLIC_H_

#define DX_CHIP_MAX 4                    //max number of chips 

/***********************
 * Typedefs
 **********************/
//error codes
typedef enum{
    DX_SUCCESS = 0,
    DX_ERR_RECOVERABLE,
    DX_ERR_UNSUPPORTED_ACCESS_MODE,
    DX_ERR_TIMEOUT,
    DX_ERR_BAD_PARAMETER,
    DX_ERR_RESOURCE_ALLOCATION_FAILED,
    DX_ERR_READ_FAILED,
    DX_ERR_WRITE_FAILED,
    DX_ERR_PCI_SCAN_FAILED,
    DX_ERR_DEVICE_OPEN_FAILED,
    DX_ERR_DEVICE_CLOSE_FAILED,
    DX_ERR_DEVICE_MISSING_RESOURCES,
    DX_ERR_INSUFFICIENT_BUFFERS,
    DX_ERR_SYNC_FAILED,
    DX_ERR_ARRAY_TOO_SMALL,
    DX_ERR_DRIVER_NAME_SET_FAILED,
    DX_ERR_DEBUG_SET_FAILED,
    DX_ERR_LIB_INIT_FAILED,
    DX_ERR_LIB_UNINIT_FAILED,
    DX_ERR_OPERATION_ALREADY_DONE,
    DX_ERR_INTERRUPT_SET_FAILED,
    DX_ERR_NOT_IMPLEMENTED,
    DX_ERR_UNKNOWN,
    DX_ERR_DONE,
    DX_ERR_NOT_FOUND,
    DX_ERR_WRONG_CHIP_TYPE,
    DX_ERR_NOT_SUPPORTED,
    DX_ERR_MEMORY_ALLOCATION_FAILED,
    DX_ERR_INVALID_ADDRESS,
    DX_ERR_INVALID_ID,
    DX_ERR_SDRAM_NOT_INITIALIZED,
    DX_ERR_MAX  // Maximum error value.
}dxErrCode;

//Chip initialization values for MCHIP and E6
//these are set to defaults at open, and can be changed by calling functions
//in mchip_e6_initialization.h.  All values are written directly to the registers.
//refer to chip documentation for how these values are calculated.
typedef struct{
    unsigned int memoryPLL;               //0xFFC2004C
    unsigned int systemPLL;               //0xFFC20048
    unsigned int memoryConfig;            //0xFF030000
    unsigned int memoryLeftDataCtrl;      //0xFF030290
    unsigned int memoryRightDataCtrl;     //0xFF0302B0
    unsigned int memoryLeftCmdCtrl2;      //0xFF030284
    unsigned int memoryRightCmdCtrl2;     //0xFF03028C
    unsigned int memoryLeftLsDLL2;        //0xFF0302A4
    unsigned int memoryLeftMsDLL2;        //0xFF0302AC
    unsigned int memoryRightLsDLL2;       //0xFF0302C4
    unsigned int memoryRightMsDLL2;       //0xFF0302CC
    unsigned int memoryLeftLsDLL1;        //0xFF0302A0
    unsigned int memoryLeftMsDLL1;        //0xFF0302A8
    unsigned int memoryRightLsDLL1;       //0xFF0302C0
    unsigned int memoryRightMsDLL1;       //0xFF0302C8
    unsigned int memoryTimingCtrl;        //0xFF030010
    unsigned int memoryAddConfig;         //0xFF030014
    unsigned int memoryRefreshCtrl;       //0xFF030018
    unsigned int memoryDramMR;            //0xFF030020
    unsigned int memoryDramEMR;           //0xFF030024
    unsigned int memoryDramEMR2;          //0xFF030028
    unsigned int memoryDramEMR3;          //0xFF03002C
    /* These are the work-around for the mem-PLL issue.  The init sequence will
       set the mem PLL to the value in memoryPLL and then will set the value
       memoryPLLResetTimes to memoryPLLResetValue and then back to memoryPLL.
       This is to ensure the memory PLL gets set properly.  Use 0 in Count for
       no resets.  The value in ResetValue should be only 1 off from memoryPLL*/
    unsigned int memoryPLLResetCount;
    unsigned int memoryPLLResetValue;  
    unsigned int verbose;
    unsigned int checkHostIF;            //wait for hostIF start between chips
    unsigned int imageAddr;              //address to load vxWorks
}dx_MCHIP_init_values_struct;

typedef struct{
    unsigned int systemPLL;               //0xFFC20048
    unsigned int memoryPLL;               //0xFFC2004C
    unsigned int memoryConfig;            //0xFF030000
    unsigned int memoryTimingCtrl;        //0xFF030010
    unsigned int memoryAddConfig;         //0xFF030014
    unsigned int memoryRefreshCtrl;       //0xFF030018
    unsigned int memoryDramMR;            //0xFF030020
    unsigned int memoryDramEMR;           //0xFF030024
    unsigned int memoryDramEMR2;          //0xFF030028
    unsigned int memoryDramEMR3;          //0xFF03002C
    unsigned int memoryPadCtrl;           //0xFF030290
    unsigned int memoryLeftReadGate;      //0xFF030294
    unsigned int memoryRightReadGate;     //0xFF030298
    unsigned int memoryCalibrationCtrl;   //0xFF03028C
    unsigned int verbose;
    unsigned int checkHostIF;
    unsigned int imageAddr;
}mchip_E6_init_values_struct;



//some standard types
typedef struct mchip_device_info *DX_HANDLE;
#ifndef FALSE
#define FALSE 0
#endif
#ifndef TRUE
#define TRUE 1
#endif

#endif

