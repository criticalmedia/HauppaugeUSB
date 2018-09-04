/**********************************************************************************************
*																						      *
* Copyright (c) 2012 Analog Devices, Inc.  All Rights Reserved.                               *
* This software is proprietary and confidential to Analog Devices, Inc. and its licensors.    *
*                                                                                             *
***********************************************************************************************/

#include "rx_lib.h"
#include "rx_isr.h"

#define RXLIB_ABS(a,b)     ((a)>=(b) ? (a-b) : (b-a))
#define RXLIB_MIN(a,b)     ((a)<=(b) ? (a) : (b))
#define RXLIB_MAX(a,b)     ((a)>=(b) ? (a) : (b))

/*============================================================================
 * Select manual TMDS clock termination for all ports and enable/disable clock
 * termination on specified port
 *
 * Entry:   Port    = PORT_A
 *                  = PORT_B
 *                  = PORT_C
 *                  = PORT_D
 *                  = PORT_ALL
 *          Enable  = TRUE to enable clock terminator
 *
 * Return:  ATVERR_OK
 *          ATVERR_INV_PARM
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxHdmiSetManualTmdsTerm (RX_HDMI_PORT Port, BOOL Enable)
{
    ATV_ERR RetVal = ATVERR_OK;

    Enable ^= 1;

    switch (Port)
    {
        case PORT_A:
            VRX_set_CLOCK_TERMA_DISABLE(Enable);
            break;
        case PORT_B:
            VRX_set_CLOCK_TERMB_DISABLE(Enable);
            break;
        case PORT_C:
            VRX_set_CLOCK_TERMC_DISABLE(Enable);
            break;
        case PORT_D:
            VRX_set_CLOCK_TERMD_DISABLE(Enable);
            break;
        case PORT_ALL:
            VRX_set_CLOCK_TERMA_DISABLE(Enable);
            VRX_set_CLOCK_TERMB_DISABLE(Enable);
            VRX_set_CLOCK_TERMC_DISABLE(Enable);
            VRX_set_CLOCK_TERMD_DISABLE(Enable);
            break;
        case PORT_NONE:
        default:
            RetVal = ATVERR_INV_PARM;
            break;
    }

    if (RetVal == ATVERR_OK)
    {
        VRX_set_TERM_AUTO(0);
    }
    return (RetVal);
}

/*============================================================================
 * Return the TMDS clock termination configuration for a specific port
 *
 * Entry:   Port    = PORT_A
 *                  = PORT_B
 *                  = PORT_C
 *                  = PORT_D
 *          Enable  = TRUE if clock/data termination is enabled
 *
 * Return:  ATVERR_OK
 *          ATVERR_INV_PARM
 *          ATVERR_FAILED
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxHdmiGetTmdsTerm (RX_HDMI_PORT Port, BOOL *Enable)
{
    if(VRX_ret_TERM_AUTO())
    {
        return (ATVERR_FAILED);
    }
    switch(Port)
    {
        case PORT_A:
            *Enable = (BOOL)(!(VRX_ret_CLOCK_TERMA_DISABLE()));
            break;
        case PORT_B:
            *Enable = (BOOL)(!(VRX_ret_CLOCK_TERMB_DISABLE()));
            break;
        case PORT_C:
            *Enable = (BOOL)(!(VRX_ret_CLOCK_TERMC_DISABLE()));
            break;
        case PORT_D:
            *Enable = (BOOL)(!(VRX_ret_CLOCK_TERMD_DISABLE()));
            break;
        default:
            return (ATVERR_INV_PARM);           
    }
    return (ATVERR_OK);
}

/*==========================================================================
 * 
 *
 * Entry:   None
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxHdmiSetAutoTmdsTerm (void)
{
    VRX_set_TERM_AUTO(1);
    return(ATVERR_OK);
}

/*============================================================================
 * Check if the input is DVI
 *
 * Entry:   Mode = Pointer to receive input mode
 *                 returns TRUE input mode is DVI
 *                 returns FALSE input mode is HDMI
 *                 Can be set to NULL to be ignored
 *
 * Return:  ATVERR_TRUE = Indicates the input is DVI
 *          ATVERR_FALSE = Indicates the input is HDMI
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxHdmiInputIsDvi (BOOL *Mode)
{
    BOOL IsDvi;

    IsDvi = ! (VRX_is_HDMI_MODE_true());
    if (Mode)
    {
        *Mode = IsDvi;
    }
    return (IsDvi? ATVERR_TRUE: ATVERR_FALSE);
}

/*============================================================================
 * Assert HPD on selected port
 *
 * Entry:   Port    =
 *          Enable  =
 *
 * Return:  ATVERR_OK
 *          ATVERR_INV_PARM
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxHdmiAssertHpd (RX_HDMI_PORT Port, BOOL Enable)
{
    return (HAL_RxAssertHpd (Port, Enable));
}

/*============================================================================
 * Check if HPD is on for selected port
 *
 * Entry:   Port    =
 *          HpdOn   =
 *
 * Return:  ATVERR_TRUE = Indicates the input is DVI
 *          ATVERR_FALSE = Indicates the input is HDMI
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxHdmiIsHpdOn (RX_HDMI_PORT Port, BOOL *HpdOn)
{
    return (HAL_RxIsHpdOn (Port, HpdOn));
}

/*==========================================================================
 * Configure HDMI 5V detection glitch filter
 *
 * Entry:   Detect5VFilterDisable = 
 *                         TRUE    enable filter
 *                         FALSE   disable filter
 *          Detected5VFilterTimer
 *                         TImer duration of 5V filter
 *          Detected5VResetDisable
 *                         TRUE    reset HDMI block when 5V is not present
 *                         FALSE   do not reset HDMI block when 5V is not present
 *
 * Return:  ATVERR_OK
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxHdmiConfig5VDetect (BOOL Detect5VFilterDisable, 
                    UCHAR Detected5VFilterTimer, BOOL Detected5VResetDisable)
{
    VRX_set_FILT_5V_DET_DIS(Detect5VFilterDisable);
    if (Detected5VFilterTimer)
    {
        VRX_set_FILT_5V_DET_TIMER(Detected5VFilterTimer);
    }
    VRX_set_DIS_CABLE_DET_RST(Detected5VResetDisable);
    return (ATVERR_OK);
}

/*============================================================================
 * Check if +5V from HDMI cable is present on the selected input port
 *
 * Entry:   Port    = PORT_A
 *                  = PORT_B
 *                  = PORT_C
 *                  = PORT_D
 *                  = PORT_ALL
 *
 * Entry:   5VDetected = TRUE, 5V is present on selected port
 *                     = FALSE, 5V is not detected
 *
 * Return:  ATVERR_TRUE     = Indicates 5V is detected on specified port
 *          ATVERR_FALSE    = Indicates 5V is not detected on specified port
 *          ATVERR_INV_PARM = Invalid parameters
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxHdmi5VDetected (RX_HDMI_PORT Port, BOOL *Detected5V)
{
    ATV_ERR RetVal = ATVERR_OK;
    BOOL V5;

    switch (Port)
    {
        case PORT_A:
            V5 = (BOOL)VRX_is_CABLE_DET_A_RAW_true();
            break;
        case PORT_B:
            V5 = (BOOL)VRX_is_CABLE_DET_B_RAW_true();
            break;
        case PORT_C:
            V5 = (BOOL)VRX_is_CABLE_DET_C_RAW_true();
            break;
        case PORT_D:
            V5 = (BOOL)VRX_is_CABLE_DET_D_RAW_true();
            break;
        case PORT_ALL:
            V5 = (BOOL)VRX_is_CABLE_DET_A_RAW_true() ||
                 (BOOL)VRX_is_CABLE_DET_B_RAW_true() ||
                 (BOOL)VRX_is_CABLE_DET_C_RAW_true() ||
                 (BOOL)VRX_is_CABLE_DET_D_RAW_true();
            break;
        default:
            V5 = FALSE;
            RetVal = ATVERR_INV_PARM;
            break;
    }

    if (Detected5V)
    {
        *Detected5V = V5;
    }
    if (RetVal == ATVERR_OK)
    {
        RetVal = V5? ATVERR_TRUE: ATVERR_FALSE;
    }
    return (RetVal);
}

/*============================================================================
 * Check which is the port with 5V detected
 *
 * Entry:   ActivePort = Pointer to received HDMI port with 5V signal detected
 *                       The highest priority port is PORT_A
 *                       The lowest priority port is PORT_D
 *                       This value will be set to PORT_NONE if none of the
 *                       ports have 5V signal detected.
 *
 * Entry:   RxPortDetectPriority = An array of input ports that defines the 
 *                       priority of checking the 5V of the input ports.
 *                       This priority is defined based on the position of
 *                       ports names in the array. A NULL array defines the 
 *                       default priority which is PORT_A, PORT_B, PORT_C, ...
 *
 * Return:  ATVERR_OK
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxHdmiGet5VDetected (RX_HDMI_PORT *ActivePort, RX_HDMI_PORT * RxPortDetectPriority)
{
    UCHAR i, j;
    BOOL Detect;

    *ActivePort = PORT_NONE;
    for (i=0; i<RX_NOF_PORTS; i++)
    {
        if (RxPortDetectPriority)
        {
            j = RxPortDetectPriority[i];
        }
        else
        {
            j = i;
        }
        ADIAPI_RxHdmi5VDetected ((RX_HDMI_PORT)j, &Detect);
        if (Detect)
        {
            *ActivePort = (RX_HDMI_PORT)j;
            break;
        }
    }
    return (ATVERR_OK);
}

/*===========================================================================
 * Set and enable Rx internal EDID for all ports
 *
 * Entry:   EdidBuf   = Pointer to 256 byte buffer containing EDID data
 *          SpaOffset = Offset of SPA in the buffer. 0 to ignore spa seetings
 *                      in SpaValues
 *          SpaValues = Array of SPA values for port B, C and D (2 bytes/port)
 *                      First byte contains nibbles A.B, second contains 
 *                      nibbles C.D
 *                      SpaValues[0] MSB (i.e. SPA nibbles A.B) of spa port B
 *                      SpaValues[1] LSB (i.e. SPA nibbles C.D) of spa port B
 *                      SpaValues[2] MSB (i.e. SPA nibbles A.B) of spa port C
 *                      SpaValues[3] LSB (i.e. SPA nibbles C.D) of spa port C
 *                      SpaValues[4] MSB (i.e. SPA nibbles A.B) of spa port D
 *                      SpaValues[5] LSB (i.e. SPA nibbles C.D) of spa port D                     
 *                      if SpaOffset ise set to 0, this parameter is ignored
 *          Segment   = 0 or 1
 *
 * Return:  ATVERR_OK
 *
 * Notes:   This function DOES NOT change HPD state for any of the ports
 *
 *==========================================================================*/
 ATV_ERR ADIAPI_RxHdmiSetInternalEdid (UCHAR *EdidBuffer, UINT16 SpaOffset, 
                        UCHAR *SpaValues, UCHAR SegNum, BOOL DisableAutoEdid)
{
    return (HAL_RxHdmiSetInternalEdid (EdidBuffer, SpaOffset, 
                        SpaValues, SegNum, DisableAutoEdid));
}

/*============================================================================
 * Enables or disables the internal EDID for selected HDMI port
 *
 * Entry:   Port    = PORT_A
 *                  = PORT_B
 *                  = PORT_C
 *                  = PORT_D
 *                  = PORT_ALL
 *          Enable  = TRUE, enables internal EDID
 *                  = FALSE, disable internal EDID
 *
 * Return:  ATVERR_OK = function completed successfully
 *          ATVERR_INV_PARM = Invalid parameters
 *
 * Notes:   This function DOES NOT enable HPD for selected port
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxHdmiEnableInternalEdid (RX_HDMI_PORT Port, BOOL Enable)
{
    return (HAL_RxEnableInternalEdid (Port, Enable));
}

/*==========================================================================
 * 
 *
 * Entry:   None
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxHdmiGetInternalEdidState (RX_HDMI_PORT Port, 
                        BOOL *EdidEnabled, UCHAR * EdidBuf, UCHAR Segment)
{
    HAL_RxGetEnabledInternalEdid (Port, EdidEnabled);
    if (EdidBuf)
    {
        HAL_RxReadEdidMap(EdidBuf, 256, Segment);
    }
    return (ATVERR_OK);
}
#if ((RX_DEVICE != 7612 ) && (RX_DEVICE != 7611 ) && (RX_DEVICE != 7619 ))


/*============================================================================
 * Stores the EDID data from the internal EDID area to an external SPI PROM
 *
 *
 * Return:  ATVERR_OK = function completed successfully
 *
 * Notes:   This API is usually used before entering the power-down mode(s),
 *          and not at any other occasions
 *          It is important to consider a delay before exiting from this API
 *          This delay is required to make sure the internal EDID is 
 *          written to the SPI eeprom. The amount of delay may have to be 
 *          adjustted based on the type of SPI eeprom used
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxHdmiWriteEdidToProm (void)
{
    HAL_SpiEdidEnable(TRUE);
    VRX_set_STORE_EDID(1);  
    HAL_DelayMs(500);
    HAL_SpiEdidEnable(FALSE);
    return (ATVERR_OK);
}

/*============================================================================
 * Loads EDID data from external SPI PROM to the internal EDID area
 *
 *
 * Return:  ATVERR_OK = function completed successfully
 *
 * Notes:   This API is usually used right after waking up from a power-down
 *          state, and not at any other occasions.
 *          It is important to consider a delay before exiting from this API
 *          This delay is required to make sure the internal EDID is 
 *          read from the SPI eeprom. The amount of delay may have to be 
 *          adjustted based on the type of SPI eeprom used
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxHdmiReadEdidFromProm (void)
{
    HAL_SpiEdidEnable(TRUE);
    VRX_set_LOAD_EDID(1);
    HAL_DelayMs(50);
    HAL_SpiEdidEnable(FALSE);
    return (ATVERR_OK);
}
#endif
/*============================================================================
 * Select Rx input port. This function DOES NOT enable HPD for selected port
 *
 * Entry:   Port    = PORT_A
 *                  = PORT_B
 *                  = PORT_C
 *                  = PORT_D
 *                  = PORT_NONE
 *          TermEn  = Set to TRUE to enable TMDS clock termination for 
 *                    specified port and disable termination for all other
 *                    ports.
 *                    This parameter will be ignored if set to FALSE or if
 *                    TMDS clock termination is in auto mode.
 *
 * Return:  ATVERR_OK
 *          ATVERR_INV_PARM
 *
 * Notes:   This function DOES NOT enable HPD or enabled TMDS termination for
 *          selected port
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxHdmiSetSelectedPort (RX_HDMI_PORT Port, BOOL TermEn)
{
    if (RX_VALID_PORT(Port))
    {
        VRX_set_HDMI_PORT_SELECT(RX_PORT_ID(Port));
    }

    if ((RX_VALID_PORT(Port)) || (Port == PORT_NONE))
    {
        if (TermEn)
        {
            if (!VRX_is_TERM_AUTO_true())
            {
                ADIAPI_RxHdmiSetManualTmdsTerm (PORT_A, (Port==PORT_A));
                ADIAPI_RxHdmiSetManualTmdsTerm (PORT_B, (Port==PORT_B));
                ADIAPI_RxHdmiSetManualTmdsTerm (PORT_C, (Port==PORT_C));
                ADIAPI_RxHdmiSetManualTmdsTerm (PORT_D, (Port==PORT_D));
            }
        }
        return (ATVERR_OK);
    }
    return (ATVERR_INV_PARM);
}   

/*============================================================================
 * Check witch Rx input port is currently set as the selected pot for HDMI
 *
 * Entry:   Port    = PORT_A
 *                  = PORT_B
 *                  = PORT_C
 *                  = PORT_D
 *                  = PORT_NONE
 *
 * Return:  ATVERR_OK = function completed successfully
 *
 * Notes:   This function DOES NOT enable HPD for selected port
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxHdmiGetSelectedPort (RX_HDMI_PORT *Port)
{
    UCHAR SelPort;

    VRX_get_HDMI_PORT_SELECT(&SelPort);
    *Port = RX_PORT_NAME(SelPort);

    return (ATVERR_OK);
}

/*============================================================================
 * Enable/Disable fast-switching on specified port(s)
 *
 * Entry:   Port    = PORT_A
 *                  = PORT_B
 *                  = PORT_C
 *                  = PORT_D
 *                  = PORT_ALL
 *          Enable  = TRUE/FALSE to enable/disable fast switching
 *
 * Return:  ATVERR_OK = function completed successfully
 *
 * Notes:
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxHdmiSetFastSwitchingPort (RX_HDMI_PORT Port, BOOL Enable)
{
    return (HAL_RxSetFastSwitchPort (Port, Enable));
}

/*============================================================================
 * Checks whether TMDS clock is present on the specified input port
 *
 * Entry:   Port     = Port to check if TMDS clock is available
 *                     Can also be set to PORT_ALL
 *          Detected = Pointer to receive TMDS state on specified port(s)
 *                     TRUE, TMDS clock detected on specified port(s)
 *                     FALSE, TMDS clock not detected on specified port(s)
 *
 * Return:  ATVERR_OK       Function completed successfully
 *          ATVERR_INV_PARM Invalid port
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxHdmiTmdsDetected (RX_HDMI_PORT Port, BOOL *Detected)
{
    if (Port == PORT_A)
    {
        *Detected = VRX_is_TMDS_CLK_A_RAW_true();
    }
    else if (Port == PORT_B)
    {
        *Detected = VRX_is_TMDS_CLK_B_RAW_true();
    }
    else if (Port == PORT_C)
    {
        *Detected = VRX_is_TMDS_CLK_C_RAW_true();
    }
    else if (Port == PORT_D)
    {
        *Detected = VRX_is_TMDS_CLK_D_RAW_true();
    }
    else if (Port == PORT_ALL)
    {
        *Detected = VRX_is_TMDS_CLK_A_RAW_true() ||
                    VRX_is_TMDS_CLK_B_RAW_true() ||
                    VRX_is_TMDS_CLK_C_RAW_true() ||
                    VRX_is_TMDS_CLK_D_RAW_true();
    }
    else
    {
        *Detected = FALSE;
        return (ATVERR_INV_PARM);
    }
    return (ATVERR_OK);
}


/*============================================================================
 * Measures the TMDS frequency
 *
 * Entry:   TmdsFreqMHz  = Integer part of TMDS frequency in unit of 1MHz
 *                     
 *          TmdsFreqFrac = Fractional part of the measured TMDS frequency
 *                         in unit of 1/128 MHz
 *                         This value is not returned if TmdsFreqFrac is a NULL
 *                         pointer                         
 *
 * Return:  ATVERR_OK       Function completed successfully
 *          ATVERR_FAILED = Indicates the function is not completed successfully
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxHdmiGetTmdsFreq (UINT16 *TmdsFreqMHz, UCHAR *TmdsFreqFrac)
{
    UINT16 TmdsFreq;

    if (HAL_RxSelPortTmdsDetected())
    {
        if (HAL_RxVPllLocked(PORT_NONE))
        {
            *TmdsFreqMHz = (UINT16)(VRX_ret_TMDSFREQ());
            TmdsFreq = (UINT16)(VRX_ret_TMDSFREQ());
            if(RXLIB_ABS((*TmdsFreqMHz), TmdsFreq) > 1)
            {
                return (ATVERR_FAILED);
            }
            if(TmdsFreqFrac != NULL)
            {
                *TmdsFreqFrac = VRX_ret_TMDSFREQ_FRAC() << TMDSFRAQ_SHIFT;
            }
            return (ATVERR_OK);
        }
    }
    return (ATVERR_FAILED);
}

/*============================================================================
 * Identifies the video color depth
 *
 * Entry:   DeepColorMode  = Video color depth
 *
 * Return:  ATVERR_OK       Function completed successfully
 *          ATVERR_FAILED = Indicates the function is not completed successfully
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxHdmiGetDeepColorMode (RX_COLOR_DEPTH *DeepColorMode)
{
    UCHAR ColDepth;
    RX_COLOR_DEPTH CdTable[] = {RX_CD_24, RX_CD_30, RX_CD_36, RX_CD_48};

    /* May need to add check for reception of GC packets */
    if (VRX_ret_TMDS_PLL_LOCKED())
    {
        if (VRX_is_OVERRIDE_DEEP_COLOR_MODE_true()) 
        {
            ColDepth = VRX_ret_DEEP_COLOR_MODE_USER();
        }
        else
        {
            VRX_get_DEEP_COLOR_MODE(&ColDepth);
        }

        if (ColDepth < 4)
        {
            *DeepColorMode = CdTable[ColDepth];
        }
        else
        {
            *DeepColorMode = RX_CD_24;
        }
        return (ATVERR_OK);
    }   
    return (ATVERR_FAILED);
}

/*============================================================================
 * Sets the deep color mode to automatic or manual
 *
 * Entry:   AutoMode = Deep color Automatic or Manual mode
 *          DeepColorMode  = Video color depth
 *
 * Return:  ATVERR_OK       Function completed successfully
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxHdmiSetDeepColorMode (BOOL ManualMode, 
                                       RX_COLOR_DEPTH DeepColorMode) 
{
    UINT16 WordX;
    UCHAR CdTable[] = {(UCHAR)RX_CD_24, 0, (UCHAR)RX_CD_30, 1,
                       (UCHAR)RX_CD_36, 2, (UCHAR)RX_CD_48, 3, 0xff};

    WordX = ATV_LookupValue8(CdTable, (UCHAR)DeepColorMode, 0xff, 2);
    if (CdTable[WordX] != 0xff)
    {
        VRX_set_OVERRIDE_DEEP_COLOR_MODE(ManualMode);
        if (ManualMode)
        {
            VRX_set_DEEP_COLOR_MODE_USER(CdTable[WordX+1]);
        }   
        return (ATVERR_OK);
    }
    return (ATVERR_INV_PARM);
}

/*============================================================================
 * Enalble or disable automatic discard repeated pixel data from the incoming HDMI data
 *
 * Entry:   AutoRepeat = TRUE, automatic discard of repeated pixels
 *                     = FALSE, manual discard of repeated pixels
 *          RepeatFactor = Pixel and clock discard factor
 *
 * Return:  ATVERR_OK = function completed successfully
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxHdmiSetPixelRepeatMode (BOOL AutoRepeat, UCHAR RepeatFactor)
{   
    if (AutoRepeat)
    {
        VRX_set_DEREP_N_OVERRIDE(0);
    }
    else
    {
        VRX_set_DEREP_N_OVERRIDE(1);
        VRX_set_DEREP_N(RepeatFactor);
    }
    return (ATVERR_OK);
}

/*============================================================================
 * Find out the video and clock repeat discard factor
 *
 * Entry:   RepeatFactor = Pixel and clock discard factor
 *
 * Return:  ATVERR_OK = function completed successfully
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxHdmiGetPixelRepeat (UCHAR * RepeatFactor)
{   
    UCHAR RetVal;

    if (VRX_is_DEREP_N_OVERRIDE_true())
    {
        VRX_get_DEREP_N(&RetVal);
    }
    else
    {
        VRX_get_HDMI_PIXEL_REPETITION(&RetVal);
    }
    *RepeatFactor = RetVal + 1;

    return (ATVERR_OK);
}

/*============================================================================
 * Sets the I2C base address accessible by DDC bus for HDCP registers
 *
 * Entry:   Base = 0x74
 *               = 0x76
 *
 * Return:  ATVERR_OK = function completed successfully
 *          ATVERR_INV_PARM = Invalid parameters
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxHdmiSetHdcpI2CBase (UCHAR Base)
{
    UCHAR value;

    if (Base == 0x74)
    {
        value = 0;
    }
    else if (Base == 0x76)
    {
        value = 1;
    }
    else
    {
        return (ATVERR_INV_PARM);
    }

    VRX_set_HDCP_A0(value);
    return (ATVERR_OK);
}

/*============================================================================
 * Sets visible repeater map for fast-switching devices
 *
 * Entry:   Port  = Port number to make it's map visible
 *                  Set to PORT_NONE to automatically switch the visible map 
 *                  based on the currently selected port
 *
 * Return:  ATVERR_OK = function completed successfully
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxHdmiSetVisibleRepMap (RX_HDMI_PORT Port)
{
    if (RX_VALID_PORT(Port))
    {
        VRX_set_AUTO_HDCP_MAP_ENABLE(0);
        VRX_set_HDCP_MAP_SELECT(Port);
    }
    else
    {
        VRX_set_AUTO_HDCP_MAP_ENABLE(1);
    }
    return (ATVERR_OK);
}

/*============================================================================
 * Indicates if the incoming HDMI content is encrypted
 *
 * Entry:   Encryption  = TRUE, Content is encrypted
 *                      = FALSE Content is not encrypted
 *
 * Return:  ATVERR_OK = Indicates the function completed successfully
 *          ATVERR_TRUE = Indicates the content is encrypted
 *          ATVERR_FALSE = Indicates the content is not encrypted
 *          ATVERR_FAILED = Indicates the function is not completed successfully
 *
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxHdmiIsContentEncrypted (RX_HDMI_PORT Port, BOOL *Encrypted)
{
    BOOL Locked;
    if (!RX_VALID_PORT(Port))
    {
        return (ATVERR_INV_PARM);
    }
    *Encrypted = FALSE;
    ADIAPI_RxHdmiGetVideoPllStatus (Port, &Locked);
    if (Locked)
    {
        *Encrypted = HAL_RxEncrypted(Port);
    }
    return (ATVERR_OK);
}

/*============================================================================
 * Indicates if KSV and HDCP keys are successfully read from the internal ROM
 *
 * Entry:   KeyRead = TRUE, Keys are read from the internal ROM
 *                  = FALSE, Keys are not read yet
 *          KeyErr  = TRUE, Error happened during HDCP Key access
 *                  = FALSE, No error happened during HDCP Key access
 *
 * Return:  ATVERR_OK = function completed successfully
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxHdmiGetHdcpKeyStatus (BOOL * KeyRead, BOOL * KeyErr)
{
    *KeyRead = VRX_is_HDCP_KEYS_READ_true();
    *KeyErr = VRX_is_HDCP_KEY_ERROR_true();
    return (ATVERR_OK);  
}

/*==========================================================================
 * Set Hsync, Vsync and LLC polarity
 * 
 * Entry:   Hsync = Required Hsyns polarity (0/1 = Neg/Pos)
 *          Vsync = Required Vsyns polarity (0/1 = Neg/Pos)
 *          Llc   = Required LLC   polarity (0/1 = Neg/Pos)
 * 
 * Return:  ATVERR_OK
 * 
 * Notes:   You can set any of the input parameters to invalid value to 
 *          skip setting it
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxHdmiSetSyncPolarity(UCHAR Hsync, UCHAR Vsync, UCHAR Llc)
{
    if (Hsync <= 1)
    {
        VRX_set_INV_HS_POL (Hsync);
    }
    if (Vsync <= 1)
    {
        VRX_set_INV_VS_POL (Vsync);
    }
#if (RX_DEVICE !=7850)
    if (Llc <= 1)
    {
        VRX_set_INV_LLC_POL (Llc);
    }
#endif
    return (ATVERR_OK);
}

/*==========================================================================
 * Provides all the Hsync measurements on the incoming HDMI video signal
 * 
 * Entry:   HsyncInfo = a structure that contains all the Hsync measurements
 * 
 * Return:  ATVERR_OK = function completed successfully
 *          ATVERR_FAILED =  measurement requested not available                    
 * 
 * Notes:  None
 *=========================================================================*/
ATV_ERR ADIAPI_RxHdmiGetHsyncInfo (RX_HDMI_HSYNC * HsyncInfo)
{
    UINT16 HTotal, LineWid, PRValue;
    
    if (VRX_is_DE_REGEN_LCK_RAW_true())
    {
        VRX_get_TOTAL_LINE_WIDTH (&HTotal);
        VRX_get_LINE_WIDTH(&LineWid);
        VRX_get_HSYNC_FRONT_PORCH(&(HsyncInfo->FrontPorch));
        VRX_get_HSYNC_PULSE_WIDTH(&(HsyncInfo->SyncPulse));
        VRX_get_HSYNC_BACK_PORCH (&(HsyncInfo->BackPorch));

        PRValue = (UINT16)HAL_RxGetPixRepValue() + 1;
        
        HsyncInfo->LinesTotal = (HTotal * PRValue);
        HsyncInfo->LinesActive = (LineWid * PRValue);
        HsyncInfo->Polarity= VRX_is_DVI_HSYNC_POLARITY_true()? TRUE: FALSE;
        return (ATVERR_OK);
    }
    return (ATVERR_FAILED);
}

/*==========================================================================
 * Provides all the Vsync measurements on the incoming HDMI video signal
 *   
 * Entry:   VsyncInfo = a structure that contains all the Vsync measurements
 *                      
 * Return:  ATVERR_OK = function completed successfully
 *          ATVERR_FAILED =  measurement requested not available
 * 
 * Notes:  None
 *=========================================================================*/
ATV_ERR ADIAPI_RxHdmiGetVsyncInfo (RX_HDMI_VSYNC * VsyncInfo)
{
    UINT16 VTotal0, VTotal1;

    if (VRX_is_V_LOCKED_RAW_true())
    {
        VRX_get_FIELD0_VS_FRONT_PORCH(&(VsyncInfo->FrontPorch));
        VRX_get_FIELD0_VS_PULSE_WIDTH(&(VsyncInfo->SyncPulse));
        VRX_get_FIELD0_VS_BACK_PORCH(&(VsyncInfo->BackPorch));
        VRX_get_FIELD0_TOTAL_HEIGHT(&VTotal0);
        VRX_get_FIELD_0_HEIGHT(&(VsyncInfo->LinesActive));
        VsyncInfo->Interlaced = ((VRX_is_INTERLACED_HDMI_true())? TRUE : FALSE);
        if (VsyncInfo->Interlaced)
        {
            VRX_get_FIELD1_VS_FRONT_PORCH(&(VsyncInfo->F1FrontPorch));
            VRX_get_FIELD1_VS_PULSE_WIDTH(&(VsyncInfo->F1SyncPulse));
            VRX_get_FIELD1_VS_BACK_PORCH(&(VsyncInfo->F1BackPorch));
            VRX_get_FIELD_1_HEIGHT(&(VsyncInfo->F1LinesActive));
            VRX_get_FIELD1_TOTAL_HEIGHT(&VTotal1);
            VsyncInfo->F1LinesTotal = (VTotal1 >> 1);
        }
        VsyncInfo->LinesTotal = (VTotal0 >> 1);
        VsyncInfo->Polarity= VRX_is_DVI_VSYNC_POLARITY_true()? TRUE: FALSE;
        return (ATVERR_OK);
    }
    return (ATVERR_FAILED);
}

/*==========================================================================
 * 
 *
 * Entry:   Filter = 
 *                    0   Filter type I
 *                    1   Filter type II
 *
 * Return:  ATVERR_OK
 *
 * Notes:
 *       ADV7840/ ADV7604/14 2 Filter options Filter 1 and Filter 2 
 *       ADV7844/2 & ADV7623 Also 2 filter options, Orginal filter 2 or New filters
 *      
 *=========================================================================*/
ATV_ERR ADIAPI_RxHdmiSetVHSyncFilter (UCHAR  Filter)
{
    if (Filter == 0 || Filter == 1)
    {
        VRX_set_NEW_TMDS_PARAM(Filter);
    }
    else
    {
        VRX_set_NEW_TMDS_PARAM(0);
    }

    return (ATVERR_OK);
}

/*==========================================================================
 * 
 *
 * Entry:   AudioCsData = detected audio channel status 
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxHdmiGetAudioChanStatus (UCHAR * AudioCsData)
{
    UCHAR i;
    BOOL lock;
    UCHAR CsData[5] = {0,0,0,0,0};

    ADIAPI_RxHdmiGetAudioPllStatus(&lock);
    if (lock)
    {
        if (VRX_is_CS_DATA_VALID_RAW_true())
        {
            VRX_get_CS_DATA(CsData);
            for (i=0; i<5; i++)
            {
                *(AudioCsData+i) = CsData[i];
            }
            return (ATVERR_OK);
        }
    }
    return (ATVERR_FAILED);
}

/*============================================================================
 * Allows to set the copyright value of the channel status bits
 *
 * Entry:   Copyright = TRUE, Assert channel status copyright bit
 *                    = FALSE, Does not change the channel status copyright bit value
 *
 * Return:  ATVERR_OK = Indicates the function completed successfully
 *
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxHdmiSetCsCopyright (BOOL Copyright)
{
    VRX_set_CS_COPYRIGHT_MANUAL(Copyright);
    return (ATVERR_OK);
}

/*==========================================================================
 * 
 *
 * Entry:   MultiCHAudio = number of detected audio channel, 2 or more
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxHdmiGetAudioChanCount (BOOL * MultiCHAudio)
{
    BOOL Lock;

    ADIAPI_RxHdmiGetAudioPllStatus(&Lock);
    if (Lock)
    {
        *MultiCHAudio = (BOOL) VRX_is_AUDIO_CHANNEL_MODE_true();
        return (ATVERR_OK);
    }

    return (ATVERR_FAILED);
}

/*==========================================================================
 * Get detected audio type
 *
 * Entry:   AudioType = Type of detected audio
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxHdmiGetAudioType (RX_AUDIO_TYPE * AudioType)
{
    BOOL Lock;

    ADIAPI_RxHdmiGetAudioPllStatus(&Lock);
    if (Lock)
    {
        HAL_GetDetectedAudioType (AudioType);
        return (ATVERR_OK);
    }
    return (ATVERR_FAILED);
}

/*==========================================================================
 * Get detected audio type
 *
 * Entry:   DstMode = SDR vs DDr mode of the DST packet
 *
 * Return:  ATVERR_OK
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxHdmiGetDstMode (RX_DST_MODE *DstMode)
{
    *DstMode = (VRX_is_DST_DOUBLE_true() ? RX_DST_DDR : RX_DST_SDR);
    return (ATVERR_OK);
}

/*==========================================================================
 * Configure I2S output format
 *
 * Entry:   I2SBitWidth = number audio bits
 *          I2SMode     =  I2S mode 
 *
 * Return:  ATVERR_OK
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxHdmiConfigI2SOutput (RX_I2S_OUT_MODE I2SMode,
                                      UCHAR *I2SBitWidth)
{

    VRX_set_I2SOUTMODE(I2SMode);
    if(I2SBitWidth)
    {
        VRX_set_I2SBITWIDTH(*I2SBitWidth);
    }
    return (ATVERR_OK);
}

/*============================================================================
 * Sets the frequency of audio master clock MCLK output signal
 *
 * Entry:   MCLK    = RX_MCLK_128Fs
 *                  = RX_MCLK_256Fs
 *                  = RX_MCLK_384Fs
 *                  = RX_MCLK_512Fs
 *                  = RX_MCLK_640Fs
 *                  = RX_MCLK_768Fs
 *
 * Return:  ATVERR_OK = Function completed successfully
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxHdmiSetAudioMclk (RX_MCLK MCLK)
{
    VRX_set_MCLK_FS_N(MCLK);
    return (ATVERR_OK);
}

/*============================================================================
 * Sets a CTS tolerance value
 *
 * Entry:   CtsRange    = 0 ~ RX_AUDIO_CTS_MAX_THRESHOLD
 *
 * Return:  ATVERR_OK = Indicates the function completed successfully
 *          ATVERR_INV_PARM = Invalid parameters
 *
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxHdmiSetCtsRange (UCHAR  CtsRange)
{
    if (CtsRange <= RX_AUDIO_CTS_MAX_THRESHOLD)
    {
        VRX_set_CTS_CHANGE_THRESHOLD(CtsRange); 
        return (ATVERR_OK);
    }
    
    return (ATVERR_INV_PARM);
}

/*============================================================================
 * This function retrives the Audio Clock Regeneration values N and CTS
 *
 * Entry:   NValue    = Value of audio clock regeneration N
 *          CtsValue  = Cycle Time Stamp
 *
 * Return:  ATVERR_OK = function completed successfully
 *          ATVERR_FAILED = N or CTS not available
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxHdmiGetAcrInfo (UINT32 * NValue, UINT32 * CtsValue)
{
    UINT32  CtsRead2;
    UINT32  CtsRead3;
    UINT32  CtsMin;
    UINT32  CtsMax;
    UINT8   CtsThreshold;

    if(VRX_is_AUDIO_C_PCKT_RAW_true())
    {
        *NValue = VRX_ret_N();
        /*====================================================
        * Read first byte of CTS three times to get a valid
        * CTS value 
        *===================================================*/
        *CtsValue = VRX_ret_CTS();
        CtsRead2 = VRX_ret_CTS();
        CtsRead3 = VRX_ret_CTS();
        CtsThreshold = VRX_ret_CTS_CHANGE_THRESHOLD();
        CtsMin = RXLIB_MIN(*CtsValue, CtsRead2);
        CtsMin = RXLIB_MIN(CtsMin, CtsRead3);
        CtsMax = RXLIB_MAX(*CtsValue, CtsRead2);
        CtsMax = RXLIB_MAX(CtsMax, CtsRead3);
        if(RXLIB_ABS(CtsMin, CtsMax)> CtsThreshold)
        {
            return (ATVERR_FAILED);
        }
        if (*NValue)
        {
            return (ATVERR_OK);
        }
    }
    return (ATVERR_FAILED);
}

/*============================================================================
 * Allows for storing every HDMI InfoFrames regardless if its checksum error
 *
 * Entry:   IFAlwaysStore = TRUE, Stores InfoFrames regardless of teh checksum error
 *                        = FALSE, Stores InfoFrames only if the checksum is correct
 *
 * Return:  ATVERR_OK = function completed successfully
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxHdmiIgnorePacketChksumErr (BOOL IFAlwaysStore)
{
    VRX_set_ALWAYS_STORE_INF(IFAlwaysStore);
    return (ATVERR_OK);
}

/*============================================================================
 * content of any packet with the new packet type ID to be stored in the 
 * registers previously allocated for the default packet type value.  
 *
 * Entry:   PacketType = VS_INFO_PACKET
 *                       AVI_INFO_PACKET
 *                       SPD_INFO_PACKET
 *                       AUDIO_INFO_PACKET
 *                       MPEG_INFO_PACKET
 *                       ACP_PACKET
 *                       ISRC1_PACKET
 *                       ISRC2_PACKET
 *                       GAMUT_PACKET
 *          NewPacketID = The new packet type ID
 *
 * Return:  ATVERR_OK = Function completed successfully
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxHdmiChangePacketID (RX_PACKET_TYPE PacketType, 
                                     UCHAR NewPacketID)
{
    UCHAR packet;

    switch (PacketType)
    {
        case VS_INFO_PACKET:
            packet=VRX_REG_VS_PACKET_ID;
            break;
        case AVI_INFO_PACKET:
            packet=VRX_REG_AVI_PACKET_ID;
            break;
        case SPD_INFO_PACKET:
            packet=VRX_REG_SPD_PACKET_ID;
            break;
        case AUDIO_INFO_PACKET:
            packet=VRX_REG_AUD_PACKET_ID;
            break;
        case MPEG_INFO_PACKET:
            packet=VRX_REG_MS_PACKET_ID;
            break;
        case ACP_PACKET:
            packet=VRX_REG_ACP_PACKET_ID;
            break;
        case ISRC1_PACKET:
            packet=VRX_REG_ISRC1_PACKET_ID;
            break;
        case ISRC2_PACKET:
            packet=VRX_REG_ISRC2_PACKET_ID;
            break;
        case GAMUT_PACKET:
            packet=VRX_REG_GAMUT_PACKET_ID;
            break;
        default:
            return (ATVERR_FAILED);
    }
    HAL_I2CWriteByte (VRX_INFOFRAME_MAP_ADDR, packet,  NewPacketID);
    return (ATVERR_OK);
}

/*============================================================================
 * Load HDMI packet into the Buffer
 *
 * Entry:   PacketType  = Packet type. This can be one of the following:
 *                          VS_INFO_PACKET
 *                          AVI_INFO_PACKET
 *                          SPD_INFO_PACKET
 *                          AUDIO_INFO_PACKET
 *                          MPEG_INFO_PACKET
 *                          ACP_PACKET
 *                          ISRC1_PACKET
 *                          ISRC2_PACKET
 *                          GAMUT_PACKET
 *          Buffer      = Pointer to buffer to receive packet (starting with
 *                        Header byte 0)
 *          ChecksumErr = Pointer to receive packet checksum state
 *                        Will be set to TRUE if checksum error detected
 *                        Will be set to FALSE if no checksum error is detected
 *                        Can be set to NULL to be ignored
 *
 * Return:  ATVERR_OK = function completed successfully
 *          ATVERR_FAILED = function is not completed successfully
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxHdmiGetPacket (RX_PACKET_TYPE PacketType, UCHAR * Buffer, 
                                BOOL * ChecksumErr)
{
    if (ChecksumErr)
    {
        *ChecksumErr = FALSE;
    }

    switch (PacketType)
    {
        case VS_INFO_PACKET:
            HAL_I2CReadBlock (VRX_INFOFRAME_MAP_ADDR, VRX_REG_VS_PACKET_ID, Buffer, 3);
            HAL_I2CReadBlock (VRX_INFOFRAME_MAP_ADDR, VRX_REG_VS_INF_PB_0_1, (Buffer+3), VS_PKT_SIZE-3);
            if (ChecksumErr)
            {
                if (VRX_is_VS_INF_CKS_ERR_ST_true())
                {
                    VRX_set_VS_INF_CKS_ERR_CLR(1);
                    *ChecksumErr = TRUE;
                }
            }
            break;
        case AVI_INFO_PACKET:
            HAL_I2CReadBlock (VRX_INFOFRAME_MAP_ADDR, VRX_REG_AVI_PACKET_ID, Buffer, 3);
            HAL_I2CReadBlock (VRX_INFOFRAME_MAP_ADDR, VRX_REG_AVI_INF_PB_0_2, (Buffer+3), AV_IF_PKT_SIZE-3);
            if (ChecksumErr)
            {
                if (VRX_is_AVI_INF_CKS_ERR_ST_true())
                {
                    VRX_set_AVI_INF_CKS_ERR_CLR(1);
                    *ChecksumErr = TRUE;
                }
            }
            break;
        case SPD_INFO_PACKET:
            HAL_I2CReadBlock (VRX_INFOFRAME_MAP_ADDR, VRX_REG_SPD_PACKET_ID, Buffer, 3);
            HAL_I2CReadBlock (VRX_INFOFRAME_MAP_ADDR, VRX_REG_SPD_INF_PB_0_2, (Buffer+3), SPD_PKT_SIZE-3);;
            if (ChecksumErr)
            {
                if (VRX_is_SPD_INF_CKS_ERR_ST_true())
                {
                    VRX_set_SPD_INF_CKS_ERR_CLR(1);
                    *ChecksumErr = TRUE;
                }
            }
            break;
        case AUDIO_INFO_PACKET:
            HAL_I2CReadBlock (VRX_INFOFRAME_MAP_ADDR, VRX_REG_AUD_PACKET_ID, Buffer, 3);
            HAL_I2CReadBlock (VRX_INFOFRAME_MAP_ADDR, VRX_REG_AUD_INF_PB_0_2, (Buffer+3), AUD_IF_PKT_SIZE-3);
            if (ChecksumErr)
            {
                if (VRX_is_AUD_INF_CKS_ERR_ST_true())
                {
                    VRX_set_AUD_INF_CKS_ERR_CLR(1);
                    *ChecksumErr = TRUE;
                }
            }
            break;
        case MPEG_INFO_PACKET:
            HAL_I2CReadBlock (VRX_INFOFRAME_MAP_ADDR, VRX_REG_MS_PACKET_ID, Buffer, 3);
            HAL_I2CReadBlock (VRX_INFOFRAME_MAP_ADDR, VRX_REG_MS_INF_PB_0_2, (Buffer+3), MS_PKT_SIZE-3);
            if (ChecksumErr)
            {
                if (VRX_is_MS_INF_CKS_ERR_ST_true())
                {
                    VRX_set_MS_INF_CKS_ERR_CLR(1);
                    *ChecksumErr = TRUE;
                }
            }
            break;
        case ACP_PACKET:
            HAL_I2CReadBlock (VRX_INFOFRAME_MAP_ADDR, VRX_REG_ACP_PACKET_ID, Buffer, 3);
            HAL_I2CReadBlock (VRX_INFOFRAME_MAP_ADDR, VRX_REG_ACP_PB_0_1, (Buffer+3), ACP_PKT_SIZE-3);
            break;
        case ISRC1_PACKET:
            HAL_I2CReadBlock (VRX_INFOFRAME_MAP_ADDR, VRX_REG_ISRC1_PACKET_ID, Buffer, 3);
            HAL_I2CReadBlock (VRX_INFOFRAME_MAP_ADDR, VRX_REG_ISRC1_PB_0_1, (Buffer+3), ISRC1_PKT_SIZE-3);
            break;
        case ISRC2_PACKET:
            HAL_I2CReadBlock (VRX_INFOFRAME_MAP_ADDR, VRX_REG_ISRC2_PACKET_ID, Buffer, 3);
            HAL_I2CReadBlock (VRX_INFOFRAME_MAP_ADDR, VRX_REG_ISRC2_PB_0_1, (Buffer+3), ISRC2_PKT_SIZE-3);
            break;
        case GAMUT_PACKET:
            HAL_I2CReadBlock (VRX_INFOFRAME_MAP_ADDR, VRX_REG_GAMUT_PACKET_ID, Buffer, 3);
            HAL_I2CReadBlock (VRX_INFOFRAME_MAP_ADDR, VRX_REG_GAMUT_MDATA_PB_0_1, (Buffer+3), GMD_PKT_SIZE-3);
            break;
        default:
            return (ATVERR_FAILED);
    }
    return (ATVERR_OK);
}

/*============================================================================
 * Set value for the HDCP BCAPS register
 *
 * Entry:   Port    = Port to set Bcaps for
 *                    Set to PORT_ALL to set Bcaps for all ports or for non 
 *                    fast-switching devices
 *          Bcaps   = BCAPS register value
 *
 * Return:  ATVERR_OK = Indicates the function completed successfully
 *
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxHdmiSetHdcpBcaps (RX_HDMI_PORT Port, UCHAR Bcaps)
{
    return (HAL_RxSetHdcpBcaps (Port, Bcaps));
}

/*============================================================================
 * Set value for the HDCP BSTATUS register
 *
 * Entry:   Port    = Port to set Bstatus for.
 *                    Set to PORT_ALL to set Bstatus for all ports or for non 
 *                    fast-switching devices
 *          Bstatus = BSTATUS register value
 *
 * Return:  ATVERR_OK = Indicates the function completed successfully
 *
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxHdmiSetHdcpBstatus (RX_HDMI_PORT Port, UINT16 Bstatus)
{
    return (HAL_RxSetHdcpBstatus (Port, Bstatus));
}

/*============================================================================
 * Get the value of the HDCP BSTATUS register
 *
 * Entry:   Port    = Port to get its Bstatus
 *                    This value is not used for non fast switching devices,
 *                    but still have to be set to a valid port
 *                    PORT_ALL is not a valid setting for this parameter
 *          Bstatus = BSTATUS register value
 *
 * Return:  ATVERR_OK = Indicates the function completed successfully
 *
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxHdmiGetHdcpBstatus (RX_HDMI_PORT Port, UINT16 * Bstatus)
{
    if (RX_VALID_PORT(Port))
    {
        VRX_set_HDCP_MAP_SELECT(Port);
        VRX_get_BSTATUS(Bstatus);
        return (ATVERR_OK);
    }
    return (ATVERR_INV_PARM);
}

/*============================================================================
 * Get the value of the HDCP BCAPS register
 *
 * Entry:   Port    = Port to get its Bcaps
 *                    This value is not used for non fast switching devices,
 *                    but still have to be set to a valid port
 *                    PORT_ALL is not a valid setting for this parameter
 *          Bcaps   = BCAPS register value
 *
 * Return:  ATVERR_OK = Indicates the function completed successfully
 *
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxHdmiGetHdcpBcaps (RX_HDMI_PORT Port, UCHAR * Bcaps)
{
    if (RX_VALID_PORT(Port))
    {
        VRX_set_HDCP_MAP_SELECT(Port);
        VRX_get_BCAPS(Bcaps);
        return (ATVERR_OK);
    }
    return (ATVERR_INV_PARM);
}

/*===========================================================================
 * Clear the KSV FIFO registers
 *
 * Entry:   None
 *
 * Return:  ATVERR_OK
 *
 * Notes:   None
 *
 *==========================================================================*/
ATV_ERR ADIAPI_RxHdmiClearKsvFifo (void)
{

#if (RX_DEVICE == 7612 || RX_DEVICE == 7611 || RX_DEVICE == 7619 || RX_DEVICE == 7850)
    UCHAR i,j;
    UCHAR ZeroBuf[64] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                          0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                          0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                          0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0                          
                         };
    UCHAR RdBuf[10];
    UCHAR StartReg = VRX_REG_KSV_0_1;

    for (i=0,j=0; (j<RX_MAX_NOF_KSVS)&&(i<5); i++,j+=12)
    {
        VRX_set_KSV_MAP_SELECT(i);
        HAL_I2CWriteBlock(VRX_REPEATER_MAP_ADDR, StartReg, ZeroBuf, 64);
        HAL_I2CReadBlock(VRX_REPEATER_MAP_ADDR, StartReg+64, RdBuf, 10);
        if (memcmp(RdBuf, ZeroBuf, 10)==0)
        {
            break;
        }
        HAL_I2CWriteBlock(VRX_REPEATER_MAP_ADDR, StartReg, ZeroBuf, 64);
    }
    VRX_set_KSV_MAP_SELECT(0);
#else
#if RX_MAX_NOF_KSVS >= 128
#error RX_MAX_NOF_KSVS >= 128: this RX_DEVICE should use KSV_MAP_SELECT version of ADIAPI_RxHdmiClearKsvFifo()
#endif
    UCHAR i, ZeroBuf[5] = {0, 0, 0, 0, 0};
    UCHAR StartReg = VRX_REG_KSV_0_1;

    for (i=0; i<RX_MAX_NOF_KSVS; i++)
    {
        HAL_I2CWriteBlock(VRX_REPEATER_MAP_ADDR, StartReg, ZeroBuf, 5);
        StartReg+= 5;
    }
#endif
    return (ATVERR_OK);
}

/*==========================================================================
 * Updates the BKSV FIFO with the KSV values collected by the downstream 
 * devices
 *
 * Entry:   BksvList  = Pointer to a buffer that contains KSVs collected by
 *                      the downstrream device
 *          BksvCount = Number of KSVs in the buffer (= buffer size / 5)
 *
 * Return:  ATVERR_OK = function completed successfully
 *
 * Notes:   None
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxHdmiSetKsvFifo (UCHAR * BksvList, UCHAR BksvCount)
{
    return (HAL_RxSetKsvFifo (BksvList, BksvCount));
}

/*============================================================================
 * Updates the BKSV List Ready bit in Bcaps.
 *
 * Entry:   Port         = Port to set list ready bit for. Not used for non 
 *                         fast-switching devices. Set to PORT_NONE to set 
 *                         KSV list ready bit for current map
 *          KsvListReady = TRUE, sets KSV list ready bit = 1
 *                       = FALSE, sets KSV list ready bit = 0
 *
 * Return:  ATVERR_OK = Indicates the function completed successfully
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxHdmiSetKsvListReadyBit (BOOL KsvListReady)
{
    HAL_RxSetBksvListReadyBit(KsvListReady);
    return (ATVERR_OK);
}

/*============================================================================
 * Indicates if the source device has written its AKSV into the HDCP registers
 *
 * Entry:   AksvReady    = AKSV is written by transmitter
 *                       = AKSV list is not written by transmitter
 *
 * Return:  ATVERR_OK = Indicates the function completed successfully
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxHdmiAksvReceived (RX_HDMI_PORT Port, BOOL *AksvReady)
{
    if (RX_VALID_PORT(Port))
    {
        *AksvReady = HAL_RxGetAksvUpdate(Port);
        return (ATVERR_OK);
    }
     return (ATVERR_INV_PARM);
}

/*===========================================================================
 * Indicates if TMDS clock is detected AND Video PLL is locked on the 
 * currently selected input port
 *
 * Entry:   Locked = Pointer to receive the state of the Video PLL lock on
 *                   the selected port.
 *                   It will be set to TRUE if the TMDS clock is detcted and
 *                   the video PLL is locked on the currently selected port,
 *                   otherwise it will be set to FALSE
 *
 * Return:  ATVERR_OK
 *
 * Notes:   None
 *
 *==========================================================================*/
ATV_ERR ADIAPI_RxHdmiGetVideoPllStatus (RX_HDMI_PORT Port, BOOL *Locked)
{
    BOOL Tmds;

    *Locked = FALSE;
    ADIAPI_RxHdmiTmdsDetected (Port, &Tmds);
    if (Tmds)
    {
        *Locked = HAL_RxVPllLocked(Port);
    }
    return (ATVERR_OK);
}

/*===========================================================================
 * Check if Rx audio PLL is locked
 *
 * Entry:   Locked = Pointer to receive audio PLL status
 *                   return TRUE if audio PLL is Locked.
 *                   It will be set to TRUE if the TMDS clock is detcted and
 *                   the audio PLL is locked on the currently selected port,
 *                   otherwise it will be set to FALSE
 *
 * Return:  ATVERR_OK
 *
 * Notes:   None
 *
 *==========================================================================*/
ATV_ERR ADIAPI_RxHdmiGetAudioPllStatus (BOOL * Locked)
{
    *Locked = FALSE;
    if (HAL_RxSelPortTmdsDetected())
    {
        *Locked = (BOOL) (VRX_is_AUDIO_PLL_LOCKED_true());
    }
    return (ATVERR_OK);
}

/*===========================================================================
 * Get device HDMI status
 *
 * Entry:   DevState = Pointer to receive device status
 *
 * Return:  ATVERR_OK
 *
 * Notes:   None
 *
 *==========================================================================*/
ATV_ERR ADIAPI_RxHdmiGetStatus (RX_DEV_STATE *DevState)
{
    UCHAR i;
    RX_HDMI_PORT Port;

    memset (DevState, 0, sizeof(RX_DEV_STATE));

    for (i=0; i<RX_NOF_PORTS; i++)
    {
        ADIAPI_RxHdmi5VDetected ((RX_HDMI_PORT)i, &(DevState->Detected5V[i]));
        ADIAPI_RxHdmiTmdsDetected ((RX_HDMI_PORT)i, &(DevState->Tmds[i]));
        ADIAPI_RxHdmiGetVideoPllStatus ((RX_HDMI_PORT)i, &(DevState->VidPllLocked[i]));
        ADIAPI_RxHdmiIsContentEncrypted ((RX_HDMI_PORT)i, &(DevState->Encrypted[i]));
    }

    ADIAPI_RxHdmiGetSelectedPort (&Port);
    DevState->HwSelPort = RX_PORT_INDEX(Port);
    
    if (DevState->Tmds[DevState->HwSelPort])
    {
        DevState->DeRegenLock     = VRX_is_DE_REGEN_LCK_RAW_true();
        DevState->VLocked         = VRX_is_V_LOCKED_RAW_true();
        DevState->StdiDvalidCh1   = VRX_is_STDI_DVALID_CH1_RAW_true();
        if (DevState->VidPllLocked)
        {
            DevState->AudMultiChan= VRX_is_AUDIO_CHANNEL_MODE_true();
            DevState->AvMute      = VRX_is_AV_MUTE_RAW_true();
            DevState->InternalMute= VRX_is_INTERNAL_MUTE_RAW_true();
            DevState->HdmiMode    = VRX_is_HDMI_MODE_true();
            ADIAPI_RxHdmiGetDeepColorMode (&DevState->ColorDepth);
            ADIAPI_RxHdmiGetAudioType(&DevState->AudioType);
        }
    }
    return (ATVERR_OK);
}

/*===========================================================================
 * Disable the Audio clock
 *
 * Entry:   Disable = TRUE : Disable the audio clock
 *                    FALSE :  Enable the audio clock
 *
 * Return:  ATVERR_OK
 *
 * Notes:   None
 *
 *==========================================================================*/
ATV_ERR ADIAPI_RxHdmiEnAudioClock (BOOL Enable)
{


    
    
    return HAL_RxHdmiEnAudioClock(Enable);
}

/*============================================================================
 * Requests synchronization measurements for a background HDMI port 
 *
 * Entry:   Port    = PORT_A
 *                  = PORT_B
 *                  = PORT_C
 *                  = PORT_D                        
 *
 * Return:  ATVERR_OK       Function completed successfully
 *          ATVERR_NOT_AVAILABLE =  This API is not available
 * 
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxHdmiReqBgMeas (RX_HDMI_PORT Port)
{
    return (HAL_RxHdmiReqBgMeas (Port));
}

/*============================================================================
 * Measures the TMDS frequency for a background (or auxiliary) HDMI port 
 *
 * Entry:   Port    = PORT_A
 *                  = PORT_B
 *                  = PORT_C
 *                  = PORT_D
 *          
 *          TmdsFreqMHz  = Integer part of TMDS frequency in unit of 1MHz
 *                     
 *          TmdsFreqFrac = Fractional part of the measured TMDS frequency
 *                         in unit of 1/128 MHz
 *                         This value is not returned if TmdsFreqFrac is a NULL
 *                         pointer                         
 *
 * Return:  ATVERR_OK       Function completed successfully
 *          ATVERR_FAILED = Indicates the function is not completed successfully
 *          ATVERR_NOT_AVAILABLE =  This API is not available
 * 
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxHdmiGetBgTmdsFreq (RX_HDMI_PORT Port, UINT16 * TmdsFreqMHz, UCHAR * TmdsFreqFrac)
{
    return (HAL_RxHdmiGetBgTmdsFreq (Port, TmdsFreqMHz, TmdsFreqFrac));
}

/*==========================================================================
 * Provides all the Hsync measurements for a selected background HDMI port
 * 
 * Entry:   Port    = PORT_A
 *                  = PORT_B
 *                  = PORT_C
 *                  = PORT_D
 *          
 *          HsyncInfo = a structure that contains all the Hsync measurements
 * 
 * Return:  ATVERR_OK = function completed successfully
 *          ATVERR_FAILED =  measurement requested not available
 *          ATVERR_NOT_AVAILABLE =  This API is not available                  
 * 
 * Notes:  None
 *=========================================================================*/
ATV_ERR ADIAPI_RxHdmiGetBgHsyncInfo (RX_HDMI_PORT Port, RX_HDMI_HSYNC * HsyncInfo)
{
    return (HAL_RxHdmiGetBgHsyncInfo (Port, HsyncInfo));
}

/*==========================================================================
 * Provides all the Vsync measurements for a selected background HDMI port
 *   
 * Entry:   Port    = PORT_A
 *                  = PORT_B
 *                  = PORT_C
 *                  = PORT_D
 *          
 *          VsyncInfo = a structure that contains all the Vsync measurements
 *                      
 * Return:  ATVERR_OK = function completed successfully
 *          ATVERR_FAILED =  measurement requested not available
 *          ATVERR_NOT_AVAILABLE =  This API is not available
 * 
 * Notes:  None
 *=========================================================================*/
ATV_ERR ADIAPI_RxHdmiGetBgVsyncInfo (RX_HDMI_PORT Port, RX_HDMI_VSYNC * VsyncInfo)
{
    return (HAL_RxHdmiGetBgVsyncInfo (Port, VsyncInfo));
}

/*============================================================================
 * Identifies the video color depth for a selected backgound HDMI port
 *
 * Entry:   Port    = PORT_A
 *                  = PORT_B
 *                  = PORT_C
 *                  = PORT_D
 *          
 *          DeepColorMode  = Video color depth
 *
 * Return:  ATVERR_OK       Function completed successfully
 *          ATVERR_FAILED = Indicates the function is not completed successfully
 *          ATVERR_NOT_AVAILABLE =  This API is not available
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxHdmiGetBgDeepColorMode (RX_HDMI_PORT Port, RX_COLOR_DEPTH * DeepColorMode)
{
    return (HAL_RxHdmiGetBgDeepColorMode (Port, DeepColorMode));
}

/*============================================================================
 * Find out the video and clock repeat discard factor for a selected
 * background HDMI port
 *
 * Entry:   Port    = PORT_A
 *                  = PORT_B
 *                  = PORT_C
 *                  = PORT_D
 *          
 *          RepeatFactor = Pixel and clock discard factor
 *
 * Return:  ATVERR_OK = function completed successfully
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxHdmiGetBgPixelRepeat (RX_HDMI_PORT Port, UCHAR * RepeatFactor)
{   
    return (HAL_RxHdmiGetBgPixelRepeat (Port, RepeatFactor));
}

/*==========================================================================
 * Enable/Disable audio pass-through from RX section of a transceiver 
 * device. This API has no effect for non-transceiver devices
 *
 * Entry:   Set = TRUE to enable audio pass-through
 *                FALSE to disable audio pass-through
 *
 * Return:  ATVERR_OK
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxSetAudioPassThrough (BOOL Set)
{
   return (HAL_RxSetAudioPassThrough(Set));
}
/*============================================================================
 * Enable/Disable ARC function
 *
 * Entry:   RX_ARC_MODE : The Audio Return Channel (ARC) Mode
 *              = RX_ARC_OFF
 *              = RX_ARC_SINGLE
 *              = RX_ARC_COMMON
 *
 * Return:  ATVERR_OK
 *          ATVERR_NOT_AVAILABLE =  This API is not available
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxHdmiSetArcMode (RX_ARC_MODE Mode, RX_ARC_TX ArcTx)
{
    return (HAL_RxHdmiSetArcMode(Mode, ArcTx));
}

/*============================================================================
 * Set the routing configuration for the Ethernal signals
 *
 * Entry:   EthPort : Signal from this Ethernet port are routed to the HEC port 
 *                    set via the parameter HecPort
 *                      = RX_ETH1
 *                      = RX_ETH2
 *          HecPort : Signal from this HEC port are routed to the Ethernet port 
 *                    set via the parameter EthPort
 *                      = RX_HEC1
 *                      = RX_HEC2
 *                    This parameter is ignored if Enable is set to FALSE
 *          Enable  : Enable or disable routing of ethernet signal routed through
 *                    Ethernat port set via the parameter HecPort
 *                      = TRUE
 *                      = FALSE
 * Return:  ATVERR_OK
 *          ATVERR_NOT_AVAILABLE =  This API is not available
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxHdmiSetEthernetPath (RX_CHIP_SECTION EThPort, RX_CHIP_SECTION HecPort, BOOL Enable)
{
    return (HAL_RxHdmiSetEthernetPath (EThPort, HecPort, Enable));
}
