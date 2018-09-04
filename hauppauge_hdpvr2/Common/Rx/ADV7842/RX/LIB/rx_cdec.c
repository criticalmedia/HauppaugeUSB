/**********************************************************************************************
*																						      *
* Copyright (c) 2012 Analog Devices, Inc.  All Rights Reserved.                               *
* This software is proprietary and confidential to Analog Devices, Inc. and its licensors.    *
*                                                                                             *
***********************************************************************************************/

#include "rx_lib.h"


#include "rx_cfg.h"




/*==========================================================================
 * Sets the PLL Reference Frequency
 *
 * Entry:  RX_MCLK      RX_MCLK_128Fs 
 *                  RX_MCLK_256Fs,
 *                  RX_MCLK_512Fs,
 *                  RX_MCLK_64Fs
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxCdecConfig(RX_MCLK MclkRef)
{
    return (HAL_RxCdecConfig(MclkRef));
}

/*==========================================================================
 * Select Audio source and routes to HDMI Tx
 *
 * Entry:   BOOL Enable         Enables the feature to route Audio Data from AudLrIn to HDMI Tx
 *                          RX_CDEC_LR_IN1      RCA STERO Input 1 Routed to TX
 *                          RX_CDEC_LR_IN2      RCA STERO Input 2 Routed to TX
 *                          RX_CDEC_LR_IN3  RCA STERO Input 3 Routed to TX
 *                          RX_CDEC_LR_IN4  RCA STERO Input 4 Routed to TX
 *                          RX_CDEC_LR_IN5  RCA STERO Input 5 Routed to TX   
 *                          RX_CDEC_NONE_IN  HDMI Audio Will be routed to TX
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxCdecRouteAudInToTx(RX_CDEC_IN AudLrIn, BOOL Enable)
{
    return (HAL_RxCdecRouteAudInToTx(AudLrIn, Enable));
}

/*==========================================================================
 * Select the Left and Right Channel Sources to be Looped Back to the Audio LR output.
 *
 * Entry:   RX_CDEC_IN OutL Left Channel Source
 *                      RX_CDEC_IN OutR Right Channel Source
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxCdecRouteAudInToAudLoopback(RX_CDEC_IN OutL, RX_CDEC_IN OutR, BOOL Enable)
{
    return (HAL_RxCdecRouteAudInToAudLoopback(OutL, OutR, Enable));
}

/*==========================================================================
 * Enables or disables the Audio Outputs, Stereo LR and Headphone and selects 
 * the digital data source.
 *
 * Entry:  RX_CDEC_OUT AudOut 
 *                     RX_CDEC_LR_OUT1,
 *                     RX_CDEC_HP_OUT1,
 *                     RX_CDEC_OUT_ALL,
 *                     RX_CDEC_OUT_NONE 
 *         RX_CDEC_IN DigAudIn
 *                    RX_CDEC_I2S_IN1
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxCdecConfigAudioOut(RX_CDEC_OUT AudOut, RX_CDEC_IN DigAudIn)
{
    return (HAL_RxCdecConfigAudioOut( AudOut, DigAudIn));
}

/*==========================================================================
 * Sets the Audio Ouput component (L,R HeadPhone L, HeadPhone R) volume 
 *
 * Entry:   RX_CDEC AudOutComp  
 *                  RX_CDEC_ADC_L0 
 *                  RX_CDEC_ADC_R0
 *                  RX_CDEC_DAC_L0
 *                  RX_CDEC_DAC_R0 
 *          UCHAR   FACTOR
 *                                      Volume will be Adjusted by the UCHAR factor* -0.37dB
 *                  Value of Factor must be an integer between 0 and 16
 * 
 *Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxCdecSetVolume(RX_CDEC AudOutComp, UCHAR Factor)
{
    return (HAL_RxCdecSetVolume( AudOutComp, Factor));
}

/*==========================================================================
 * Set Mute status an Audio  Component
 *
 * Entry:   RX_CDEC AudOutComp
 *             RX_CDEC_ADC_L0
 *             RX_CDEC_ADC_R0
 *             RX_CDEC_DAC_L0
 *             RX_CDEC_DAC_R0
 *             RX_CDEC_DAC_HP
 *          BOOL Mute
 *                               TRUE  Mute
 *               FALSE Unmute
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxCdecSetMute(RX_CDEC AudComp, BOOL Mute)
{
    return (HAL_RxCdecSetMute(AudComp, Mute));
}



