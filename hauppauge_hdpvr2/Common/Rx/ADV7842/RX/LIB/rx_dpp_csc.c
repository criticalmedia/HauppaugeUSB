/**********************************************************************************************
*																						      *
* Copyright (c) 2012 Analog Devices, Inc.  All Rights Reserved.                               *
* This software is proprietary and confidential to Analog Devices, Inc. and its licensors.    *
*                                                                                             *
***********************************************************************************************/


#include "rx_lib.h"
#include "rx_isr.h"
#if ((RX_DEVICE == 7604) || (RX_DEVICE == 7614) || (RX_DEVICE == 7840)\
    || (RX_DEVICE == 7844) || (RX_DEVICE == 7842) || (RX_DEVICE == 7612)\
    || (RX_DEVICE == 7611) || (RX_DEVICE == 7619) || (RX_DEVICE == 7850))


/*============================================================================
 * Set the CSC Mode. This API is used to decide if a specific CSC is used.  
 *
 * Entry:   Mode: Set the enable mode the CSC is set into
 *              RX_CS_AUTO_EN = 1,
 *              RX_CS_MAN_EN,
 *              RX_CS_MAN_DIS,
 *          Csc: Color space converster 
 *              DPP_CSC
 *              CP_CSC
 *
 * Return:  ATVERR_OK = Function completed successfully
 *          ADIERR_INV_PARM = Invalid parameter
 *
 * Notes:   The entire DPP is enabled when the DPP_CSC is enabled
 *          See also ADIAPI_RxDppEn
 *          This function should be the very first CSC function to be called
 *          before calling any other CSC function (e.g. ADIAPI_RxSetCscConfig)
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxSetCscMode(RX_CSC_MODE Mode, RX_CSC Csc)
{
    return (HAL_RxSetCscMode(Mode, Csc));
}

/*============================================================================
 * Return the mode a CSC is set into. This function will tell if a specific 
 * CSC if used. 
 *
 * Entry:   Mode: Set the enable mode the CSC is set into
 *          Csc: Specify the CSC
 *
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_INV_PARM = Invalid parameter
 *
 * Notes:   See also ADIAPI_RxSetCscMode
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxGetCscMode(RX_CSC_MODE *Mode, RX_CSC Csc)
{
    return (HAL_RxGetCscMode(Mode, Csc));
}

/*============================================================================
 * Set the configuration of a CSC. This function can be used to decide wether 
 * internal (i.e. hardcoded) or manual CSC coefficients are used for a 
 * specific CSC 
 *
 * Entry:   Config: Configuration of the CSC
 *          Csc: DPP_CSC
 *               CP_CSC
 *               SDP_CSC
 *
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_INV_PARM = Invalid parameter
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxSetCscConfig(RX_CSC_CONFIG Config, RX_CSC Csc)
{
    return (HAL_RxSetCscConfig(Config, Csc));
}

/*============================================================================
 * Get the configuration of a CSC
 *
 * Entry:   Config: Set the configuration the CSC is set into
 *          Csc: DPP_CSC
 *               CP_CSC
 *               SDP_CSC
 *
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_INV_PARM = Invalid parameter
 *
 * Notes:   See also ADIAPI_RxSetCscConfig
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxGetCscConfig(RX_CSC_CONFIG *Config, RX_CSC Csc)
{
    return (HAL_RxGetCscConfig(Config, Csc));
}

/*============================================================================
 * Get the input color space of a CSC
 *
 * Entry:   ColorSpace: Set the input color space of the CSC.
 *          Range: Set the input range of the video input to the
 *                 CSC or/and the CP section
 *          Csc: DPP_CSC
 *               CP_CSC
 *               SDP_CSC
 *
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_INV_PARM = Invalid parameter
 *          ATVERR_FAILED = The function failed to
 *
 * Notes:   See also ADIAPI_RxGetIpColorSpace, ADIAPI_RxSetOpColorSpace
 *          ADIAPI_RxGetOpColorSpace
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxSetIpColorSpace(RX_CS_COLOR ColorSpace, RX_RANGE Range, RX_CSC Csc)
{
    return HAL_RxSetIpColorSpace(ColorSpace, Range, Csc);
}

/*============================================================================
 * Get the input color space of a CSC
 *
 * Entry:   ColorSpace: The input color space of the CSC.
 *          Range: Get the input range of the video input to the
 *                 CSC or/and the CP section
 *          Csc: DPP_CSC
 *               CP_CSC
 *               SDP_CSC
 *
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_INV_PARM = Invalid parameter
 *          ATVERR_FAILED = The function failed to return valid information
 *                          (the CSC may be set in manual mode)
 *
 * Notes:   See also ADIAPI_RxSetIpColorSpace, ADIAPI_RxSetOpColorSpace
 *          ADIAPI_RxGetOpColorSpace
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxGetIpColorSpace(RX_CS_COLOR *ColorSpace, RX_RANGE *Range, RX_CSC Csc)
{
    return (HAL_RxGetIpColorSpace(ColorSpace, Range, Csc));
}

/*============================================================================
 * Set the output color space of a CSC
 *
 * Entry:   ColorSpace: Set the input color space of the CSC.
 *                  The input range is also set by this function
 *          Csc: DPP_CSC
 *               CP_CSC
 *               SDP_CSC
 *
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_IN_PARM = Invalid parameter
 *          ATVERR_FAILED = The function is set in manual mode)
 *
 * Notes:   See also ADIAPI_RxSetIpColorSpace, ADIAPI_RxGetIpColorSpace
 *          ADIAPI_RxGetOpColorSpace
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxSetOpColorSpace(RX_CS_COLOR ColorSpace, RX_CSC Csc)
{
    return (HAL_RxSetOpColorSpace(ColorSpace, Csc));
}

/*============================================================================
 * Returns the output color space of a CSC
 *
 * Entry:   ColorSpace: The input color space of the CSC.
 *                  The input range is also set by this function
 *          Csc: DPP_CSC
 *               CP_CSC
 *               SDP_CSC
 *
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_INV_PARM = Invalid parameter
 *          ATVERR_FAILED = The function failed to return valid information
 *                          (the CSC may be set in manual mode)
 *
 * Notes:   See also ADIAPI_RxSetIpColorSpace, ADIAPI_RxGetIpColorSpace
 *          ADIAPI_RxSetOpColorSpace
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxGetOpColorSpace(RX_CS_COLOR *ColorSpace, RX_CSC Csc)
{
    return (HAL_RxGetOpColorSpace(ColorSpace, Csc));
}

/*============================================================================
 * Configure manually a CSC
 *
 * Entry:   CscScale: CSC scale coefficient.
 *          CoeffA: A pointer to 4 coefficients for channel A
 *                  CoeffA[0] = A1
 *                  CoeffA[0] = A2
 *                  CoeffA[0] = A3
 *                  CoeffA[0] = A4
 *          CoeffB: A pointer to 4 coefficients for channel B
 *                  CoeffA[0] = B1
 *                  CoeffA[0] = B2
 *                  CoeffA[0] = B3
 *                  CoeffA[0] = B4
 *          CoeffC: A pointer to 4 coefficients for channel C
 *                  CoeffA[0] = C1
 *                  CoeffA[0] = C2
 *                  CoeffA[0] = C3
 *                  CoeffA[0] = C4
 *          Csc: DPP_CSC
 *               CP_CSC
 *               SDP_CSC
 *
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_INV_PARM = Invalid parameter
 *          ATVERR_FAILED = The function failed to configure the CSC coefficients
 *
 * Notes:   See also ADIAPI_RxSetCscConfig, ADIAPI_RxGetManCscCoeffs
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxSetManCscCoeffs(UINT8 CscScale, UINT8* CoeffA, UINT8* CoeffB, UINT8* CoeffC, RX_CSC CSC)
{
    return (HAL_RxSetManCscCoeffs(CscScale, CoeffA, CoeffB, CoeffC, CSC));
}

/*============================================================================
 * Returns the manual configuration of a CSC
 *
 * Entry:   CscScale: CSC scale coefficient.
 *          CoeffA: A pointer to 4 coefficients for channel A
 *                  CoeffA[0] = A1
 *                  CoeffA[0] = A2
 *                  CoeffA[0] = A3
 *                  CoeffA[0] = A4
 *          CoeffB: A pointer to 4 coefficients for channel B
 *                  CoeffA[0] = B1
 *                  CoeffA[0] = B2
 *                  CoeffA[0] = B3
 *                  CoeffA[0] = B4
 *          CoeffC: A pointer to 4 coefficients for channel C
 *                  CoeffA[0] = C1
 *                  CoeffA[0] = C2
 *                  CoeffA[0] = C3
 *                  CoeffA[0] = C4
 *          Csc: DPP_CSC
 *               CP_CSC
 *               SDP_CSC
 *
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_INV_PARM = Invalid parameter
 *          ATVERR_FAILED = The function failed to configure the CSC coefficients
 *
 * Notes:   See also ADIAPI_RxSetCscConfig, ADIAPI_RxSetManCscCoeffs
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxGetManCscCoeffs(UINT8 *CscScale, UINT8* CoeffA, UINT8* CoeffB, UINT8* CoeffC, RX_CSC Csc)
{
    return (HAL_RxGetManCscCoeffs( CscScale, CoeffA, CoeffB, CoeffC, Csc));
}

/*============================================================================
 * Enables/Disables the DPP section
 *
 * Entry:   Enable : ATV_TRUE = Enable the DPP section
 *                   ATV_FALSE = Disable the DPP section
 *
 * Return:  ATVERR_OK = Function completed successfully
 *
 * Notes:   The DPP section can also be eanabled/disblabed with the function
 *          ADIAPI_RxSetCscMode
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxDppEn(BOOL Enable)
{
    Enable &= 1;
    VRX_set_DPP_BYPASS_EN((UINT8)Enable);
    return (ATVERR_OK);
}

/*============================================================================
 * Enables the DCM stage of the DPP section
 *
 * Entry:   Enable : ATV_TRUE = Enable the DCM stage
 *                   ATV_FALSE = Disable the DCM stage
 *
 * Return:  ATVERR_OK = Function completed successfully
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxDppEnDcmStageManMode(BOOL Enable)
{
    return (HAL_RxDppEnDcmStageManMode(Enable));
}

/*============================================================================
 * Enables the DPP stage of the DPP section
 *
 * Entry:   Enable : ATV_TRUE = Enable the DPP stage
 *                   ATV_FALSE = Disable the DPP stage
 *
 * Return:  ATVERR_OK = Function completed successfully
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxDppEnDppStageManMode(BOOL Enable)
{
    return (HAL_RxDppEnDppStageManMode(Enable));
}

/*============================================================================
 * Enables the Chroma stage of the DPP section
 *
 * Entry:   Enable : ATV_TRUE = Enable the Chroma stage
 *                   ATV_FALSE = Disable the Chroma stage
 *
 * Return:  ATVERR_OK = Function completed successfully
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxDppEnChromaFiltManMode(BOOL Enable)
{
    return (HAL_RxDppEnChromaFiltManMode(Enable));
}

/*============================================================================
 * Sets the filter response of the DCM stage in the DPP section 
 *
 * Entry:   FilterResponse : Filter response
 *
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_INV_PARM = Invalid input parameter
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxDppSetDcmResponse(RX_FILT_RESPONSE FiltResponse)
{
    return (HAL_RxDppSetDcmResponse(FiltResponse)); 
}

/*============================================================================
 * Sets the filter response of the DPP stage in the DPP section 
 *
 * Entry:   FilterResponse : Filter response
 *
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_INV_PARM = Invalid input parameter
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxDppSetDppResponse(RX_FILT_RESPONSE FiltResponse)
{
   return (HAL_RxDppSetDppResponse(FiltResponse));
}

/*============================================================================
 * Sets the manual filter response coefficients for the DPP stage 
 * in the DPP section 
 *
 * Entry:   CoeffA : Coefficients for channel A
 *                   CoeffA[0] = PROG_COEFF1_CHA
 *                   CoeffA[1] = PROG_COEFF2_CHA
 *                   CoeffA[2] = PROG_COEFF3_CHA
 *                   ...
 *                   CoeffA[9] = PROG_COEFF10_CHA
 *          CoeffBC : Coefficients for channels B and C
 *                   CoeffBC[0] = PROG_COEFF1_CHBC
 *                   CoeffBC[1] = PROG_COEFF2_CHBC
 *                   CoeffBC[2] = PROG_COEFF3_CHBC
 *                   ...
 *                   CoeffBC[9] = PROG_COEFF10_CHBC
 *
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_INV_PARM = Invalid input parameter
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxDppSetDppCoeffs(UINT16 *CoeffA, UINT16 *CoeffBC)
{
   return (HAL_RxDppSetDppCoeffs(CoeffA, CoeffBC));
}

/*============================================================================
 * Sets the chroma filter response  
 *
 * Entry:   FilterResponse : Filter response
 *
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_INV_PARM = Invalid input parameter
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxDppSetChromaResponse(RX_FILT_RESPONSE FiltResponse)
{
    return (HAL_RxDppSetChromaResponse(FiltResponse));
}

/*============================================================================
 * Sets the chroma filter bandwidth  
 *
 * Entry:   FilterResponse : Filter response
 *
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_INV_PARM = Invalid input parameter
 *
 * Notes:   See also ADIAPI_RxDppEnChromaFiltManMode, 
 *          ADIAPI_RxDppSetChromaResponse
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxDppSetDppChromaBandwidth(RX_FILT_BANDWIDTH Bandwidth)
{
    return (HAL_RxDppSetChromaBandwidth(Bandwidth));
}

/*============================================================================
 * Enables/Disable downsampling 
 *
 * Entry:   FiltMode : FILTER_DOWNSAMPLE = Filter and downsample in all 
 *                     modes but HDMI 4:2:2.
 *                     Downsample only (no filtering) in HDMI 4:2:2
 *                     DOWNSAMPLE_ONLY = Downsample only (no filtering) in all
 *                     modes but HDMI 4:2:2.
 *                     Filter and downsample in HDMI 4:2:2
 *
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_INV_PARM = Invalid input parameter
 *          ATVERR_FAILED = Function failed to perform the required action
 *                          because the DPP section is not enabled
 *
 * Notes:   None
 *
 *===========================================================================*/ 
ATV_ERR ADIAPI_RxDppFiltMode(RX_FILT_MODE FiltMode)
{
    return (HAL_RxDppFiltMode(FiltMode));
}

#endif
