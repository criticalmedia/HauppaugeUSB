/**********************************************************************************************
*																						      *
* Copyright (c) 2012 Analog Devices, Inc.  All Rights Reserved.                               *
* This software is proprietary and confidential to Analog Devices, Inc. and its licensors.    *
*                                                                                             *
***********************************************************************************************/

#include "rx_lib.h"
#include "rx_isr.h"

/*============================================================================
 * Set the device index to be used for API calls
 *
 * Entry:   DevIdx  = Index of the RX device to be used for all subsequent 
 *                    API calls
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *
 * Notes: 
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxSetDeviceIndex (UCHAR DevIdx)
{
    return (HAL_RxSetChipIndex(DevIdx));
}

/*============================================================================
 * Get the index of the RX device currently being processed
 *
 * Entry:   DevIdx  = Pointer to receive the index of the RX device currently
 *                    being processed by the library
 *
 * Return:  ATVERR_OK
 *
 * Notes: 
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxGetDeviceIndex (UCHAR *DevIdx)
{
    *DevIdx = RxCurrDevIdx;
    return (ATVERR_OK);
}

/*============================================================================
 * Configure how RX ISR responds to various events and set other operational
 * parameters
 *
 * Entry:   UserConfig  = RX_ENABLE_DBG
 *          Set         = TRUE/FALSE
 *
 * Return:  ATVERR_OK
 *
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxSetConfig (RX_CONFIG UserConfig, BOOL Set)
{
    if (Set)
    {
        RxUsrConfig |= UserConfig;
    }
    else
    {
        RxUsrConfig &= (~UserConfig);
    }
    return (ATVERR_OK);
}

/*===========================================================================
 * Initialise the part into a specific mode.
 *
 * Entry:   OperatingMode = Mode the part mus be set into
 *
 * Return:  ATVERR_OK
 *
 * Notes:   For the ADV7840 or the ADV7604, a hardware reset should be done 
 *          before this function is called         
 *
 *==========================================================================*/
ATV_ERR ADIAPI_RxInit (RX_OP_MODE OperatingMode)
{
    memset(&(RxLibVars[RxCurrDevIdx]), 0, sizeof (RX_LIB_VARS));
    HAL_RxHdmiInit();
    return (HAL_RxInit(OperatingMode));
}

/*===========================================================================
 * Get HDMI RX chip revision
 *
 * Entry:   RxRev = Pointer to receive chip revision
 *
 * Return:  ATVERR_OK
 *
 * Notes: 
 *
 *==========================================================================*/
ATV_ERR ADIAPI_RxGetChipRevision (UINT16 *RxRev)
{
    UINT32 ChipRev;

    VRX_get_RD_INFO (&ChipRev);
    *RxRev = (UINT16)ChipRev;
    return (ATVERR_OK);
}

/*==========================================================================
 * Set the I2C Map Address of a particular I2C Map
 *
 * Entry:   Map:    I2C Map whose address will be modified. 
 *          Address: Desired address value.
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxSetI2cMapAddress (RX_I2C_MAP  Map, UINT8 Address)
{
    return (HAL_SetI2cMapAddress(Map, Address));
}

/*==========================================================================
 * To set the Mode of Operation for the chip. This function will set the 
 * Primary mode of operation, the power up the required blocks and set 
 * any I2C setting based on the selected mode of operation. 
 *  
 * Entry:   OpMode: Desire Mode of Operation
 *          DisPowerMgt: Select whether or not to also control power settings 
 *                       for the selected mode of operation.
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxSetOperatingMode (RX_OP_MODE OperatingMode, RX_OP_MODE_CFG *OpModeCfg)
{
    return (HAL_SetOperatingMode(OperatingMode, OpModeCfg));
}

/*==========================================================================
 * Get the Mode of Operation for the chip. 
 *  
 * Entry:   OperatingMode: Current operating mode the chip is into
 *
 * Return:  ATVERR_OK
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxGetOperatingMode (RX_OP_MODE *OperatingMode)
{
    *OperatingMode = RxOperatingMode;
    return (ATVERR_OK);
}

/*==========================================================================
 * To Power up individual functional sections of the chip
 *
 * Entry:   Section: The selected functional section to apply the power control.
 *          PowerUp: The Power-up status to be applied to the function section.
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxManagePower (RX_CHIP_SECTION Section, BOOL PowerUp)
{
    return (HAL_SetManagePower(Section, PowerUp));
}

/*==========================================================================
 * To Power down individual functional sections of the chip
 *
 * Entry:  Section: The selected functional section to apply the power control.
 *         PowerDown: The Power-down status to be applied to the function section. 
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxManagePowerDown (RX_CHIP_SECTION Section, RX_PWRDN_MODE PowerDownMode)
{
    return (HAL_SetManagePowerDown(Section, PowerDownMode));
}

/*==========================================================================
 *  To Reset individual functional sections of the chip
 *
 * Entry:   Section: The selected functional section to apply the reset.
 *          
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxChipReset (RX_CHIP_SECTION Section)
{
    return (HAL_SetChipReset(Section));
}

/*==========================================================================
 * To set the functionality of dual function pins.
 *
 * Entry:   PinId: The dual function pin for which the functionality must be set
 *          PinFunction: The desired functionality for the dual function pin.
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxSetPinFunction (RX_PIN PinId, RX_PIN_FUNCTION PinFunction)
{
    return (HAL_SetPinFunction(PinId, PinFunction));
}

/*==========================================================================
 * To set the tristate status on a selected output pin.
 *
 * Entry:   Pin: The selecte pin for which the tristate status is to be set.
 *          Tristate: The desired tristate status for the selected pin.
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxTristatePin (RX_PIN Pin, BOOL Tristate)
{
    return (HAL_SetTristatePin(Pin, Tristate));
}

/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxSetPinPolarity (RX_PIN Pin, BOOL PosPolarity)
{
    return (HAL_SetPinPolarity(Pin, PosPolarity));
}

/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxConfigInt (RX_PIN IntPin, RX_INT_DURATION Duration, RX_PIN_LEVEL PinLevel)
{
    return (HAL_ConfigInt(IntPin, Duration, PinLevel));
}

/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxForceIntLevel (RX_PIN IntPin, BOOL ForceLevel)
{
    return (HAL_ForceIntLevel(IntPin, ForceLevel));
}

/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxSetDriveStrength (RX_PIN PinId,  RX_OP_DR_STR DriveLevel)
{
    return (HAL_SetDriveStrength(PinId, DriveLevel));
}



/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxSetManSigPhase (RX_CLOCK_SIG Signal, UINT8 Phase)
{
    return (HAL_SetManSigPhase(Signal, Phase));
}

/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxManSigPhaseEn (RX_CLOCK_SIG Signal, UINT8 Enable)
{
    return (HAL_SetManSigPhaseEn(Signal, Enable));
}

/*============================================================================
 * Apply user(manual) adjustment of the Pixel Clock applied to the LLC Pin.
 *
 * Entry:   Enable - TRUE to enable manual adjustment
 *                 - FALSE to disable manual adjustment
 *          PixClkFreq -RX_1X_CLK to output Pixel Clock equal to ADC Clk
 *                     -RX_2X_CLK to output Pixel Clock equal to 2x ADC Clk
 *                     -RX_0Dot5_CLK to output Pixel clock equal to 0.5x ADC Clk
 *                     -RX_90Deg_1X_CLK to output Pixel Clock equal to ADC Clk 
 *                                      with 90 degrees shift 
 *                 
 *  
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_INV_PARM = PixClkFreq is set to an invalid value.
 * 
 * Notes:   
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxSetPixelClkFreq (RX_PIX_CLK_FREQ PixClkFreq, BOOL Enable)
{
    return HAL_RxSetPixelClkFreq(PixClkFreq, Enable);
}



/*===========================================================================
 * Sets the RX output audio interface
 *
 * Entry:   AudInterface = Define the output audio interface:
 *                          RX_AUD_IF_I2S
 *                          RX_AUD_IF_SPDIF
 *                          RX_AUD_IF_DSD
 *                          RX_AUD_IF_AUTO
 *
 * Return:  ATVERR_OK
 *          ATVERR_INV_PARM
 *
 * Notes: 
 *
 *==========================================================================*/
ATV_ERR ADIAPI_RxSetAudioInterface (RX_AUD_INTERFACE AudInterface)
{
      UCHAR DsdMan=1, DsdSel=0, HbrMan=1, HbrSel=0;
    ATV_ERR RetVal = ATVERR_OK;

    switch (AudInterface)
    {
        case RX_AUD_IF_I2S:
            break;

        case RX_AUD_IF_SPDIF:
            HbrSel = 1;
            break;

        case RX_AUD_IF_DSD:
            DsdSel = 1;
            break;

        case RX_AUD_IF_AUTO:
            DsdMan = HbrMan = 0;
            break;

        default:
            RetVal = ATVERR_INV_PARM;
            break;
            
    }
    if (RetVal == ATVERR_OK)
    {
        VRX_set_OVR_AUTO_MUX_DSD_OUT(DsdMan);
        VRX_set_MUX_DSD_OUT(DsdSel);
        VRX_set_OVR_MUX_HBR(HbrMan);
        VRX_set_MUX_HBR_OUT(HbrSel);
    }
    return (RetVal);
}



/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxSetOpPixFormat (RX_PIX_BUS_INFO* PixBusInfo, RX_OP_MODE* OpMode)
{
    return (HAL_SetOpPixFormat(PixBusInfo, OpMode));
}

/*=====================================================================================================
 * Configure the Primary Mode and Video Standard
 *
 * Entry:   PrimaryMode - Sets the primary mode of operation of the Video Reciever
 *          VideoStandard -Set the Video Standard that is expected to be applied to the Video Reciever     
 *  
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_INV_PARM = PixClkFreq is set to an invalid value.
 * 
 * Notes:   Refer to the Hardware Manual of Video Chip for Appropriate Values
 *
 *=====================================================================================================*/
ATV_ERR ADIAPI_RxSetPrimModVidStd (UINT8 PrimaryMode, UINT8 VideoStandard)
{
    ATV_ERR ErrVal = ATVERR_OK;

    if((PrimaryMode > 15) || (VideoStandard > MAX_VIC_VALUE))
    {
       return (ATVERR_INV_PARM);
    }

    VRX_set_PRIM_MODE( PrimaryMode);
    VRX_set_VID_STD(VideoStandard);

    return (ErrVal);
}



/*==========================================================================
 * To set the expected vertical frequency for component modes
 *
 * Entry:   VertFreq: The expected vertical frequency of the input video for 
 *                    component formats.
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxSetVertFreq (RX_VRT_FRQ VertFreq)
{
    ATV_ERR ErrVal = ATVERR_OK;
    
    switch(VertFreq)
    {
        case RX_VFRQ_24HZ:
            VRX_set_V_FREQ(0x4);
            break;
        case RX_VFRQ_25HZ:
            VRX_set_V_FREQ(0x3);
            break;
        case RX_VFRQ_30HZ:
            VRX_set_V_FREQ(0x2);
            break;
        case RX_VFRQ_50HZ:
            VRX_set_V_FREQ(0x1);
            break;
        case RX_VFRQ_60HZ:
            VRX_set_V_FREQ(0x0);
            break;
        default:
            ErrVal = ATVERR_INV_PARM;
            break;
    }
    return (ErrVal);
}



/*==========================================================================
 * To select the insertion of AV timing codes into the digital video stream.
 *
 * Entry:   Enable: To enable or disable the insertion of AV timing codes into 
 *                  the digital video data stream.
 *
 * 
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxEnAvCode(BOOL Enable)
{
    VRX_set_AVCODE_INSERT_EN(Enable);
    return (ATVERR_OK);    
}

/*============================================================================
 * This function is used to enable or disable events
 *
 * Entry:   EventList: A pointer to a list of CP event that must be enabled
 *          ListSize: The number of event in the listed pointed by EvntList
 *          Enable: TRUE = List of events pointed by EventList must be enabled
 *                  FALSE = List of events pointed by EventList must be disabled
 *  
 * Return:  ATVERR_OK = Function completed successfully
 *
 * Notes:   The interrupt corresponding to the list of event input to this
 *          are enabled on one single interrupt pin in the order described below
 *          + HDMI and CP and AFE events:
 *              - Interrupts enabled on INT2 if INT2 pin has been configured 
 *                as an interrupt pin before calling this function
 *              - Interrupts enabled on INT1 if INT2 pin has not been configured 
 *                as an interrupt pin before calling this function
 *          + SDP events the part does not feature an INT3 pin
 *              - Interrupts enabled on INT2 if INT2 pin has been configured 
 *                as an interrupt pin before calling this function
 *              - Interrupts enabled on INT1 if INT2 pin has not been configured 
 *                as an interrupt pin before calling this function
 *          + SDP events the part features an INT3 pin
 *              - Interrupts enabled on INT3 pin
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxSetEnabledEvents (RX_EVENT *EventList, UCHAR ListSize, BOOL Enable)
{
    HAL_RxHdmiSetEnabledEvents (EventList, ListSize, Enable);
    HAL_RxCpSetEnabledEvents (EventList, ListSize, Enable);
    HAL_RxSdpSetEnabledEvents (EventList, ListSize, Enable);
    

#if (RX_DEVICE == 7840)    
    switch(RxOperatingMode)
    {
        case RX_OPMODE_HDMI:
        case RX_OPMODE_COMP:
        case RX_OPMODE_GR:        
            HAL_RxVdpSetEnabledEvents (EventList, ListSize, Enable);
            break;
        case RX_OPMODE_SDP_COMP:
        case RX_OPMODE_SDP_CVBS:
        case RX_OPMODE_SDP_CVBS_HDMI_MON:
        case RX_OPMODE_SDP_CVBS_YC_AUTO:
        case RX_OPMODE_SDP_YC:
        case RX_OPMODE_SDP_SCART:
            HAL_RxSdpVdpSetEnabledEvents (EventList, ListSize, Enable);
            break;
        default:
            break;
    }
#else
    HAL_RxMvSetEnabledEvents(EventList, ListSize, Enable);
    HAL_RxVdpSetEnabledEvents (EventList, ListSize, Enable);
#endif
    return (ATVERR_OK);
}

/*============================================================================
 * This function is used to if events that can't be notified by the ISR have 
 * occurred
 * 
 * Entry:   None
 *  
 * Return:  ATVERR_OK = Function completed successfully
 *
 * Notes:   This function should be called periodically by the application
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxHouseKeeping (void)
{
    HAL_RxHdmiHouseKeeping();
    HAL_RxCpHouseKeeping();
    HAL_RxSdpHouseKeeping();
    return (ATVERR_OK);
}

/*============================================================================
 * 
 * 
 * Entry:   None
 *  
 * Return:  
 *
 * Notes:
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxSetInpVidCfg(RX_OP_MODE VidFormat, RX_VID_RES Res, RX_VRT_FRQ Freq, RX_OS_RATE OvrSmplng)
{
    return (HAL_RxSetInpVidCfg(VidFormat, Res, Freq, OvrSmplng));
}

/*============================================================================
 * This function sets 861 related settings i.e. sync adjustment and sync 
 * polarity for inputs processed via the CP section
 * 
 * Entry:   SdpFormatIn
 *              Set to appropriate value for SDP related mode
 *              Set to NULL or any other value for non SDP modes
 *          Vid861Out
 *              CEA 861 Vic that the sync out of the pat must comply with
 *          OperatingMode
 *              Optional parameter
 *              When set to NULL, the function used operating mode stored
 *              by the library
 * 
 *  
 * Return:  ATVERR_OK
 *          ATVERR_INV_PARM: Combination of Vid861 and operating mode not
 *                           supported
 *                           SdpFormatIn set to NULL while the part is in SDP
 *                           mode
 *
 * Notes:   SdpFormatIn is not used by the function when the operating mode
 *          not an SDP related mode
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxSet861RecSettings(RX_SDP_FORMAT *SdpFormatIn, UINT8 Vid861Out, RX_OP_MODE *OperatingMode)
{
    RX_OP_MODE UsedOperatingMode;
    
    if(OperatingMode)
    {
        UsedOperatingMode =  *OperatingMode;
    }
    else
    {
        UsedOperatingMode =  RxOperatingMode;
    }
    switch(UsedOperatingMode)
    {
        case RX_OPMODE_COMP:
        case RX_OPMODE_GR:
        case RX_OPMODE_HDMI:
            return(HAL_CpSet861RecSettings(Vid861Out, UsedOperatingMode));
        case RX_OPMODE_SDP_COMP:
        case RX_OPMODE_SDP_CVBS:
        case RX_OPMODE_SDP_CVBS_HDMI_MON:
        case RX_OPMODE_SDP_YC:
        case RX_OPMODE_SDP_SCART:
            if(SdpFormatIn != NULL)
            {
                return(HAL_SetSdp861RecSettings(*SdpFormatIn, Vid861Out, UsedOperatingMode));
            }
            else
            {
                return (ATVERR_INV_PARM);
            }           
        default:
            return (ATVERR_INV_PARM);
    }
}
/*============================================================================
 * This function loads the Internal Edid Ram with VGA 128Byte data and 
 * enables or disables the VGA EDID feature and VGA EDID DDC linse
 * 
 * Entry:   EdidBuffer
 *              Array of 128 Byte data representing a VGA EDID to be written
 *              to the internal EDID Ram
 *         Enable
 *              A Boolean Value that enables or disables the VGA edid Feature
 *              and the VGA EDID DDC lines.
 *          
 * Notes:   There is only one internal EDID RAM.Therefore a HDMI EDID cannot be 
 *          available at the same time the VGA EDID feature is being used.
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxEnInternalVgaEdid (UCHAR * EdidBuffer, BOOL Enable)
{
    return (HAL_RxEnInternalVgaEdid (EdidBuffer, Enable));
}
/*============================================================================
 * This function enables the SPI interface for EDID Eprom.
 *
 * 
 * Entry:Enable
 *              A Boolean Value that enables or disables the EDID Spi interface.
 *             
 *	EdidSpiConfig
 *              A pointer to a structure with the configuration details of the 
 *				SPI interface.
 *         
 * Notes:   This is only require for devices that support many EDID SPI proms
 *			Sizes such as the ADV7850
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxEdidCfgSpiInterface( RX_EDID_SPI_CFG* EdidSpiConfig, BOOL Enable)
{
	return (HAL_RxEdidCfgSpiInterface (EdidSpiConfig, Enable));
}
/*============================================================================
 * This function sets the Header information for the EDIDs stored in SPI PROM
 * 
 * Entry:SpiEdidHeader
 *              Header information required for EDID stored in SPI Prom.
 *             
 *         
 * Notes:   This is only require for devices that multiple EDIDs in the SPI prom
 * 			such as the ADV7850.
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxEdidCfgSpiHeader( RX_EDID_SPI_HEADER SpiEdidHeader)
{
		return (HAL_RxEdidCfgSpiHeader (SpiEdidHeader));
}
