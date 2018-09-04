/**********************************************************************************************
*																						      *
* Copyright (c) 2012 Analog Devices, Inc.  All Rights Reserved.                               *
* This software is proprietary and confidential to Analog Devices, Inc. and its licensors.    *
*                                                                                             *
***********************************************************************************************/

#include "rx_lib.h"

#if ((RX_DEVICE == 7604) || (RX_DEVICE == 7840) || (RX_DEVICE == 7844) || (RX_DEVICE == 7842) || (RX_DEVICE == 7850))

#if RX_INCLUDE_VBI
#include "rx_cfg.h"

/*==========================================================================
 * This function enables the VDP section
 *
 * Entry:   Enable: TRUE to enabled the VDP section
 * 
 * Return:  ATVERR_OK = function completed successfully
 *          ATVERR_INV_PARM = Invalid parameters
 *
 * Notes: This function does not initialise the VDP section
 *        use ADIAPI_RxVdpInit for this purpose
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxVdpEnable(BOOL Enable)
{
    return (HAL_RxVdpEnable(Enable));
}

/*==========================================================================
 * This function initializes the VDP section
 *
 * Entry:   DataType: VBI data type
 *                      RX_TTXT
 *                      RX_CCAP
 *                      RX_CGMS
 * 
 * Return:  ATVERR_OK = function completed successfully
 *          ATVERR_INV_PARM = Invalid parameters
 *
 * Notes: This function does not poer up the VDP section
 *        Use ADIAPI_RxVdpEnable or ADIAPI_SetManagePower 
 *        for this purpose
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxVdpInit(RX_VBI_TYPE DataType)
{
    return (HAL_RxVdpInit(DataType));
}

/*==========================================================================
 * This function set the the lines over which VBI extraction is performed
 *
 * Entry:   DataType: VBI data type    
 *                      RX_TTXT
 *                      RX_VPS
 *                      RX_VITC
 *                      RX_WSS
 *                      RX_CGMS
 *                      RX_GEMS_1X
 *                      RX_GEMS_2X
 *                      RX_CCAP
 *                      RX_CGMS_B
 *                      RX_NO_VBI
 *                  Set DataType to NULL and VidRes to only use VbiLine in order to 
 *                  set the lines over which VBI data is extracted
 *          VidRes: Video Resolutions
 *                      RX_525I
 *                      RX_625I
 *                      RX_720P
 *                      RX_1125I_274M
 *                   This parameter is ignored if DataType is set to RX_NO_VBI
 *          VbiLine: A pointer to an array UINT8 values. Each lines has two numbers
 *                      - Line number between 1 and 40 as per chip documentation
 *                      - The Line configuration value as per documentation - This value is used only if
 *                        DataType and VidRes are set to NULL.   
 *                      VbiLine[] = { 
 *                                  Line1, Config1,     /configuration set for Line1 to Lin2-1/
 *                                  Line2, Config2,     /configuration set for Line2 to Lin3-1/
 *                                  Line3, Config3,     /configuration set for Line3 to Lin4-1/
 *                                  ...
 *                                  LineN, ConfigN,     /configuration set for LineN to 40/
 *                                  0
 *                                  }
 *                    NULL is not a valid value for VbiLine
 *    
 * Return:  ATVERR_OK = function completed successfully
 *          ATVERR_INV_PARM = Invalid parameters
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxVdpSetLines(RX_VBI_TYPE *DataType, RX_VID_RES *VidRes, UCHAR *VbiLine)
{
    return (HAL_RxVdpSetLines(DataType, VidRes, VbiLine));
}

/*==========================================================================
 * Set the type of vbi data to decode
 *
 * Entry:   DataType: VBI data type. Used if Enable is set to TRUE
 *                      RX_TTXT_A
 *                      RX_TTXT_B
 *                      RX_TTXT_C
 *                      RX_TTXT_D
 *                      RX_GEMS
 *                      RX_CGMS_B
 *                      RX_VPS
 *                      RX_PDC
 *                      RX_UTC
 *          Enable:
 *              TRUE: Enable manual selection of the VBI data type
 *              FALSE: Disable manual selection of the  VBI data type
 *              This parameter is effective if DataType is set to one of the following type
 *                  RX_TTXT_A
 *                  RX_TTXT_B
 *                  RX_TTXT_C
 *                  RX_TTXT_D
 *   
 * Return:  ATVERR_OK = function completed successfully
 *          ATVERR_INV_PARM = Invalid parameters
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxVdpForceDataType(RX_VBI_TYPE TeleTextType, BOOL Enable)
{
    return (HAL_RxVdpForceDataType(TeleTextType, Enable));
}

/*==========================================================================
 * Determine if a type of VBI data has been detected
 * 
 * Entry:   DataType: VBI data type
 *              RX_TTXT: to detect teletext type A, B, C or D depending
 *                       on the teletext type set via the API
 *                       ADIAPI_RxVdpForceDataType
 *              RX_TTXT_A :to detect teletext type A
 *              RX_TTXT_B :to detect teletext type C
 *              RX_TTXT_C :to detect teletext type B
 *              RX_TTXT_D :to detect teletext type D                
 *              RX_CGMS :to detect WSS or CGMS depending on video resolution
 *              RX_WSS: to detect WSS or CGMS depending on video resolution
 *              RX_CGMS_B: to detect Gemstar 1x, Gemstar 2x, CGMS Type B, UTC, 
 *                         PDC or VPS depending on video resolution
 *              RX_UTC: to detect Gemstar 1x, Gemstar 2x, CGMS Type B, UTC, 
 *                      PDC or VPS depending on video resolution
 *              RX_PDC: to detect Gemstar 1x, Gemstar 2x, CGMS Type B, UTC, 
 *                      PDC or VPS depending on video resolution
 *              RX_VPS: to detect Gemstar 1x, Gemstar 2x, CGMS Type B, UTC, 
 *                      PDC or VPS depending on video resolution
 *              RX_GEMS_1X: to detect Gemstar 1x
 *              RX_GEMS_1X: to detect Gemstar 2x
 *              RX_GEMS: Can be Gemstar 1x or 2x
 *              RX_CCAP: Closed caption
 * 
 * Return:  ATVERR_TRUE: VBI data detected
 *          ATVERR_FALSE: VBI data not detected
 *          ATVERR_INV_PARM: Invalid parameters
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxVdpIsTypeDetected(RX_VBI_TYPE DataType)
{
    return (HAL_RxVdpIsTypeDetected(DataType));
}

/*==========================================================================
 * Refresh VBI data readback status returned by API 
 * ADIAPI_RxVdpDataTypeDetected
 * 
 * Entry:   DataType: VBI data type
 *              RX_TTXT: Teletext type A, B, C or D depending
 *                       on the teletext type set via the API
 *                       ADIAPI_RxVdpForceDataType
 *              RX_TTXT_A: teletext type A
 *              RX_TTXT_B: teletext type C
 *              RX_TTXT_C: teletext type B
 *              RX_TTXT_D: teletext type D                
 *              RX_CGMS: WSS or CGMS depending on video resolution
 *              RX_WSS: WSS or CGMS depending on video resolution
 *              RX_CGMS_B: Gemstar 1x, Gemstar 2x, CGMS Type B, UTC, 
 *                         PDC or VPS depending on video resolution
 *              RX_UTC: Gemstar 1x, Gemstar 2x, CGMS Type B, UTC, 
 *                      PDC or VPS depending on video resolution
 *              RX_PDC: Gemstar 1x, Gemstar 2x, CGMS Type B, UTC, 
 *                      PDC or VPS depending on video resolution
 *              RX_VPS: Gemstar 1x, Gemstar 2x, CGMS Type B, UTC, 
 *                      PDC or VPS depending on video resolution
 *              RX_GEMS_1X: Gemstar 1x
 *              RX_GEMS_1X: Gemstar 2x
 *              RX_CCAP: Closed caption 
 * 
 * Return:  ATVERR_OK = function completed successfully
 *          ATVERR_INV_PARM = Invalid parameters
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxVdpClearTypeDetected(RX_VBI_TYPE DataType)
{
    return (HAL_RxVdpClearTypeDetected(DataType));
}

/*========================================================================== 
 * Determine if VBI data has been detected on even vs. odd fields
 * 
 * Entry:   DataType: VBI data type
 *              RX_CCAP: Closed caption 
 *  
 * Return:  ATVERR_TRUE : VBI data hs been detected on even fields 
 *          ATVERR_FALSE : VBI data hs been detected on odd fields
 *          ATVERR_INV_PARM: Invalid parameters
 *
 * Notes:
 *
 *=========================================================================*/    
ATV_ERR ADIAPI_RxVdpIsDataOnEvenField(RX_VBI_TYPE DataType)
{
    return (HAL_RxVdpIsDataOnEvenField(DataType));
}

/*==========================================================================
 * Return VBI data payload
 * 
 * Entry:   DataType: VBI data type             
 *              RX_CGMS: WSS or CGMS depending on video resolution
 *              RX_WSS: WSS or CGMS depending on video resolution
 *              RX_CGMS_B: Gemstar 1x, Gemstar 2x, CGMS Type B, UTC, 
 *                         PDC or VPS depending on video resolution
 *              RX_UTC: Gemstar 1x, Gemstar 2x, CGMS Type B, UTC, 
 *                      PDC or VPS depending on video resolution
 *              RX_PDC: Gemstar 1x, Gemstar 2x, CGMS Type B, UTC, 
 *                      PDC or VPS depending on video resolution
 *              RX_VPS: Gemstar 1x, Gemstar 2x, CGMS Type B, UTC, 
 *                      PDC or VPS depending on video resolution
 *              RX_GEMS_1X: Gemstar 1x
 *              RX_GEMS_1X: Gemstar 2x
 *              RX_CCAP: Closed caption
 *              RX_VITC: VITC
 *          Data: a pointer to an array of appriate size to store VBI data:
 *                the sixe of the array pointed by Data is as follows
 *                  RX_CCAP_SIZE for RX_CCAP
 *                  RX_CGMS_SIZE for RX_CGMS
 *                  RX_WSS_SIZE for RX_WSS
 *                  RX_GEMS_1X_SIZE for RX_GEMS_1X
 *                  RX_GEMS_1X_SIZE for RX_GEMS_2X
 *                  RX_VPS_SIZE for RX_VPS
 *                  RX_PDC_SIZE for RX_PDC
 *                  RX_UTC_SIZE for RX_UTC
 *                  RX_CGMS_B_SIZE for RX_CGMS
 *                  RX_VITC_SIZE for RX_UTC               
 * 
 * Return:  ATVERR_OK = function completed successfully
 *          ATVERR_INV_PARM = Invalid parameters
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxVdpGetData(RX_VBI_TYPE DataType, UCHAR* Data)
{
    return (HAL_RxVdpGetData(DataType, Data));
}

/*==========================================================================
 * Return VBI CRC
 * 
 * Entry:   DataType: VBI data type             
 *              RX_VITC: VITC
 *          Crc: A pointer to a byte which is used to store the CRC
 * 
 * Return:  ATVERR_OK = function completed successfully
 *          ATVERR_INV_PARM = Invalid parameters
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxVdpGetCrc(RX_VBI_TYPE DataType, UCHAR* Crc)
{
    return (HAL_RxVdpGetCrc(DataType, Crc));
}

/*==========================================================================
 * Enable automatic detection of VBI data type
 * 
 * Entry:   DataType: VBI data type             
 *              RX_GEMS_1X: For autmatic detection of Gemstar 1x vs. 2x
 *              RX_GEMS_2X: For autmatic detection of Gemstar 1x vs. 2x
 *          Enable: 
                TRUE: Enable automatic detection
                FALSE: Disable automatic detection
 *  
 * Return:  ATVERR_OK
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxVdpEnAutoDetect(RX_VBI_TYPE DataType, BOOL Enable)
{
    return (HAL_RxVdpEnAutoDetect(DataType, Enable));
}

/*==========================================================================
 * 
 * Enable content based update
 * 
 * Entry:   DataType: VBI data type             
 *              RX_WSS: WSS
 *              RX_CGMS: CGMS
 *              RX_UTC: UTC
 *              RX_PDC: PDC
 *              RX_VPS: VPS
 *          Crc: A pointer to a byte which is used to store the CRC
 * 
 * Return:  ATVERR_OK = function completed successfully
 *          ATVERR_INV_PARM = Invalid parameters
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxVdpEnAutoUpdate(RX_VBI_TYPE DataType, BOOL Enable)
{
    return (HAL_RxVdpEnAutoUpdate(DataType, Enable));
}

/*==========================================================================
 * Enable insertion of VBI decoded data into ancialliary 656 stream
 * 
 * Entry:   Enable: 
 *              TRUE: Enable the insertion of VBI decoded data
 *              FALSE: Disable the insertion of VBI decoded data
 * 
 * Return:  ATVERR_OK = function completed successfully
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxVdpInsertDataIn656Stream(BOOL Enable)
{
    return (HAL_RxVdpInsertDataIn656Stream(Enable));
}

/*==========================================================================
 * 
 * User specified second Data Identification Word (SDID) sent in the ancillary stream 
 * with VDP decoded data
 * 
 * Entry:   AuxIdentifier: 
 *              SDID value
 * 
 * Return:  ATVERR_OK = function completed successfully
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxVdpSet656Ident(UCHAR Identifier)
{
    return (HAL_RxVdpSet656Ident(Identifier));
}

/*==========================================================================
 * 
 * User specified Data Identification Word (DID)sent in the ancillary stream 
 * with VDP decoded data
 * 
 * Entry:   Identifier: 
 *              DID value
 * 
 * Return:  ATVERR_OK = function completed successfully
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxVdpSetAux656Ident(UCHAR AuxIdentifier)
{
    return (HAL_RxVdpSetAux656Ident(AuxIdentifier));      
}

/*==========================================================================
 * 
 * Spread ancillary data packets across the Y and C data streams
 * 
 * Entry:   SpreadData: 
 *              TRUE: Spread ancillary data packet across the Y and C data 
 *                    streams
 *              FALSE: Do not spread ancillary data packet across the Y and 
 *                     C data streams
 * 
 * Return:  ATVERR_OK = function completed successfully
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxVdpSpreadDataOnYAndC(BOOL SpreadData)
{
    return (HAL_RxVdpSpreadDataOnYAndC(SpreadData));
}

/*==========================================================================
 * Set the format of the Ancilliary data packet
 * 
 * Entry:   Mode: 
 *              RX_NIBBLE_MODE: Nibble mode
 *              RX_BYTE_MODE_NO_RESTRICT: Byte mode, no code restrictions
 *              RX_BYTE_MODE_WITH_RESTRICT: Byte mode, 0x00 and 0xFF prevented
 *                                          (0x00 -> 0x01, 0xFF -> 0xFE)
 * 
 * Return:  ATVERR_OK = function completed successfully
 *          ATVERR_INV_PARM = Invalid parameter
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxVdpCfg656Data(RX_ADF_MODE Mode)
{
    return (HAL_RxVdpCfg656Data(Mode));
}

/*==========================================================================
 * Enable the serial output for teletext
 * 
 * Entry:   DataType: VBI data type             
 *              RX_TTXT: Teletext
 *          Enable:
 *              TRUE: Enable serial output
 *              FALSE: Disable serial output
 * 
 * Return:  ATVERR_OK = function completed successfully
 *          ATVERR_INV_PARM = Invalid parameter
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxVdpEnSerialOutput(RX_VBI_TYPE DataType, BOOL Enable)
{
    return (HAL_RxVdpEnSerialOutput(DataType, Enable));
}

#endif
#endif
