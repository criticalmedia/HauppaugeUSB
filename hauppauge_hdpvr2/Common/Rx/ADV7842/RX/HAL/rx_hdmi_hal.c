/**********************************************************************************************
*																						      *
* Copyright (c) 2012 Analog Devices, Inc.  All Rights Reserved.                               *
* This software is proprietary and confidential to Analog Devices, Inc. and its licensors.    *
*                                                                                             *
***********************************************************************************************/

/*============================================================================
 * This file contains all functions that are common across all chip families
 * but can not (or should not) be implemented in the LIB layer
 *
 *===========================================================================*/
#include "rx_lib.h"
#include "rx_isr.h"

#define ACP_PACKET_ID                   0x04
#define ISRC1_PACKET_ID                 0x05
#define ISRC2_PACKET_ID                 0x06
#define GMD_PACKET_ID                   0x0A

#define SPD_PACKET_ID                   0x83
#define AUDIF_PACKET_ID                 0x84
#define AVIIF_PACKET_ID                 0x82
#define MPEG_PACKET_ID                  0x85
#define VS_PACKET_ID                    0x81

#define ENABLE_SPD_INT(Int,En)          Int?VRX_set_SPD_INFO_MB2(En):VRX_set_SPD_INFO_MB1(En)
#define ENABLE_AUDIF_INT(Int,En)        Int?VRX_set_AUDIO_INFO_MB2(En):VRX_set_AUDIO_INFO_MB1(En)
#define ENABLE_AVIIF_INT(Int,En)        Int?VRX_set_AVI_INFO_MB2(En):VRX_set_AVI_INFO_MB1(En)
#define ENABLE_MPEG_INT(Int,En)         Int?VRX_set_MS_INFO_MB2(En):VRX_set_MS_INFO_MB1(En)
#define ENABLE_VS_INT(Int,En)           Int?VRX_set_VS_INFO_MB2(En):VRX_set_VS_INFO_MB1(En)
#define ENABLE_ISRC1_INT(Int,En)        Int?VRX_set_ISRC1_PCKT_MB2(En):VRX_set_ISRC1_PCKT_MB1(En)
#define ENABLE_ISRC2_INT(Int,En)        Int?VRX_set_ISRC2_PCKT_MB2(En):VRX_set_ISRC2_PCKT_MB1(En)
#define ENABLE_GMD_INT(Int,En)          Int?VRX_set_GAMUT_MDATA_MB2(En):VRX_set_GAMUT_MDATA_MB1(En)
#define ENABLE_ACP_INT(Int,En)          Int?VRX_set_ACP_PCKT_MB2(En):VRX_set_ACP_PCKT_MB1(En)

#define SPD_REPEAT_INTERVAL             1000    /* Once per second  */
#define ISRC_REPEAT_INTERVAL            400     /* Arbitrary        */
#define MAX_ACP_REPEAT_INTERVAL         600     /* from spec 300*2  */
#define MAX_AUDIF_REPEAT_INTERVAL       50      /* Once per Vsync   */
#define MAX_AVIIF_REPEAT_INTERVAL       50      /* Once per Vsync   */
#define MAX_GMD_REPEAT_INTERVAL         50      /* Once per Field   */
#define MAX_MPEG_REPEAT_INTERVAL        50      /* Once per Vsync   */
#define MAX_VS_REPEAT_INTERVAL          50      /* Once per Vsync   */

#define SPD_REPEAT_TIMEOUT              1500
#define ISRC_REPEAT_TIMEOUT             400
#define ACP_REPEAT_TIMEOUT              600
#define AUDIF_REPEAT_TIMEOUT            500
#define GMD_REPEAT_TIMEOUT              500
#define MPEG_REPEAT_TIMEOUT             500
#define VS_REPEAT_TIMEOUT               500

/*================================
 * Local constants
 *===============================*/
CONSTANT UCHAR OpColorSpaceCfg[] =
{
    0,      RX_CS_RGB,
    1,      RX_CS_RGB,
    2,      RX_CS_YCrCb601,
    3,      RX_CS_YCrCb709,
    4,      RX_CS_XVYCC601,
    5,      RX_CS_XVYCC709,
    6,      RX_CS_YCrCb601,
    7,      RX_CS_YCrCb709,
    8, 		RX_CS_SYCC601,
    9,		RX_CS_ADOBE_YCC601,
	10,		RX_CS_ADOBE_RGB,
    0xff
};

CONSTANT UCHAR OpRangeCfg[] =
{
    0,      RX_RG_16_235,
    1,      RX_RG_0_255,
    2,      RX_RG_16_235,
    3,      RX_RG_16_235,
    4,      RX_RG_0_255,
    5,      RX_RG_0_255,
    6,      RX_RG_0_255,
    7,      RX_RG_0_255,
    0xff
};

CONSTANT UCHAR DetectedAudioTypeCfg[] =
{
    VRX_BIT_AUDIO_SAMPLE_PCKT_DET,      RX_AUDIO_SAMPLE_PACKET,
    VRX_BIT_DSD_PACKET_DET,             RX_AUDIO_DSD,
    VRX_BIT_DST_AUDIO_PCKT_DET,         RX_AUDIO_DST,
    VRX_BIT_HBR_AUDIO_PCKT_DET,         RX_AUDIO_HBR,
    0xff,                               RX_AUDIO_UNDEFINED
};
            
/*==========================================
 * Local prototypes
 *=========================================*/
STATIC void PacketDetectionHK (void);
STATIC void EnablePktInt (UCHAR IntIdx, UCHAR PktId, UCHAR En);
STATIC void ClearRawBit (UCHAR PktId);
STATIC void CheckStoppedPkt (UINT32 *LastPktTime, UCHAR PktId, UCHAR PktType,
                             RX_EVENT PktEvent, UCHAR IntIdx);
STATIC void NoPacketHandling (RX_EVENT PktEvent, UINT32 *LastPktTime, 
                              BOOL RawBit, UINT32 RepInterv, UCHAR PktId, 
                              UCHAR PktType, UCHAR IntIdx);

/*============================================================================
 * Init HDMI HAL functions
 *
 *===========================================================================*/
void HAL_RxHdmiInit (void)
{
    UCHAR i;

    CurrAudMode = RX_AUDIO_UNDEFINED;
    for (i=0; i<CH_STAT_SIZE; i++)
    {
        CurrCs[i] = 0;
    }
}

/*============================================================================
 * Return port index 0, 1, 2, 3 or 0xff if invalid port
 *
 *===========================================================================*/
UCHAR HAL_RxGetPortIndex (RX_HDMI_PORT Port)
{
    UCHAR Index=0xff;

    if (Port == PORT_A)
    {
        Index = 0;
    }
    else if (Port == PORT_B)
    {
        Index = 1;
    }
    else if (Port == PORT_C)
    {
        Index = 2;
    }
    else if (Port == PORT_D)
    {
        Index = 3;
    }
    return (Index<RX_NOF_PORTS?Index:0xff);
}

/*==========================================================================
 *
 * Return:  TRUE if TMDS is detected on currently selected port
 *
 *=========================================================================*/
BOOL HAL_RxSelPortTmdsDetected (void)
{
    BOOL TmdsOn = FALSE;
    
    switch (VRX_ret_HDMI_PORT_SELECT())
    {
        case 0:
            TmdsOn = VRX_is_TMDS_CLK_A_RAW_true();
            break;
        case 1:
            TmdsOn = VRX_is_TMDS_CLK_B_RAW_true();
            break;
        case 2:
            TmdsOn = VRX_is_TMDS_CLK_C_RAW_true();
            break;
        case 3:
            TmdsOn = VRX_is_TMDS_CLK_D_RAW_true();
            break;
        default:
            break;
    }
    return (TmdsOn);
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
ATV_ERR HAL_RxEnableInternalEdid (RX_HDMI_PORT Port, BOOL Enable)
{
    UCHAR EdidCtrl;
    UCHAR ByteX = 0;

    HAL_I2CReadByte(VRX_REPEATER_MAP_ADDR, VRX_REG_HDCP_EDID_CONTROLS, &EdidCtrl);

    if (Port == PORT_A)
    {
        ByteX = VRX_BIT_EDID_A_ENABLE;
    }
    else if (Port == PORT_B)
    {
        ByteX = VRX_BIT_EDID_B_ENABLE;
    }
    else if (Port == PORT_C)
    {
        ByteX = VRX_BIT_EDID_C_ENABLE;
    }
    else if (Port == PORT_D)
    {
        ByteX = VRX_BIT_EDID_D_ENABLE;
    }
    else if (Port == PORT_ALL)
    {
        ByteX |= VRX_BIT_EDID_A_ENABLE | VRX_BIT_EDID_B_ENABLE |
                 VRX_BIT_EDID_C_ENABLE | VRX_BIT_EDID_D_ENABLE;
    }

    if (Enable)
    {
        EdidCtrl |= ByteX;
    }
    else
    {
        EdidCtrl &= ~ByteX;
    }
    HAL_I2CWriteByte(VRX_REPEATER_MAP_ADDR, VRX_REG_HDCP_EDID_CONTROLS, EdidCtrl);

    return (ATVERR_OK);
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
ATV_ERR HAL_RxGetEnabledInternalEdid (RX_HDMI_PORT Port, BOOL * Enable)
{
    UCHAR EdidCtrl, EdidReady;
    UCHAR ByteX = 0;

    HAL_I2CReadByte(VRX_REPEATER_MAP_ADDR, VRX_REG_HDCP_EDID_CONTROLS, &EdidCtrl);
    HAL_I2CReadByte(VRX_REPEATER_MAP_ADDR, VRX_REG_EDID_DEBUG, &EdidReady);

    if (Port == PORT_A)
    {
        ByteX = VRX_BIT_EDID_A_ENABLE;
    }
    else if (Port == PORT_B)
    {
        ByteX = VRX_BIT_EDID_B_ENABLE;
    }
    else if (Port == PORT_C)
    {
        ByteX = VRX_BIT_EDID_C_ENABLE;
    }
    else if (Port == PORT_D)
    {
        ByteX = VRX_BIT_EDID_D_ENABLE;
    }
    else if (Port == PORT_ALL)
    {
        ByteX |= VRX_BIT_EDID_A_ENABLE | VRX_BIT_EDID_B_ENABLE |
                 VRX_BIT_EDID_C_ENABLE | VRX_BIT_EDID_D_ENABLE;
    }
    EdidCtrl &= ByteX;
    EdidReady &= ByteX;
    
    * Enable = (((EdidCtrl&EdidReady) == 0)? FALSE : TRUE);

    return (ATVERR_OK);
}
/*============================================================================
 * Toggle the state of internal EDID enable only for already-enabled ports
 * This function can be used to force EDID checksum calculation for ports
 * with internal EDID already enabled
 *
 * Entry:   None
 *
 * Return:  ATVERR_OK
 *
 * Notes:
 *
 *===========================================================================*/
void HAL_RxToggleInternalEdid (void)
{
    UCHAR EdidCtrl;
    UCHAR ByteX = VRX_BIT_EDID_A_ENABLE | VRX_BIT_EDID_B_ENABLE |
                  VRX_BIT_EDID_C_ENABLE | VRX_BIT_EDID_D_ENABLE;

    HAL_I2CReadByte(VRX_REPEATER_MAP_ADDR, VRX_REG_HDCP_EDID_CONTROLS, &EdidCtrl);
    HAL_I2CWriteByte(VRX_REPEATER_MAP_ADDR, VRX_REG_HDCP_EDID_CONTROLS, EdidCtrl & (~ByteX));
    HAL_I2CWriteByte(VRX_REPEATER_MAP_ADDR, VRX_REG_HDCP_EDID_CONTROLS, EdidCtrl);
}

/*============================================================================
 * This function set the source physical address (spa) for a specific port
 *
 * Entry:   SpaLoc  = Spa location
 *          SpaPtr  = Pointer to array of SPA for port B, C and D
 *                    SpaPtr[0] MSB of spa port B
 *                    SpaPtr[1] LSB of spa port B
 *
 * Return:  ATVERR_OK
 *
 *===========================================================================*/
UCHAR HAL_RxSetSpas (UINT16 SpaLoc, UCHAR *SpaPtr)
{
    VRX_set_SPA_LOCATION(SpaLoc);
    VRX_set_SPA_LOCATION_MSB(SpaLoc >> 8);
    VRX_set_SPA_PORT_1((UINT16)(SpaPtr[1]) | (((UINT16)(SpaPtr[0]))<<8));
    VRX_set_SPA_PORT_2((UINT16)(SpaPtr[3]) | (((UINT16)(SpaPtr[2]))<<8));
    VRX_set_SPA_PORT_3((UINT16)(SpaPtr[5]) | (((UINT16)(SpaPtr[4]))<<8));
    return (ATVERR_OK);
}

/*============================================================================
 *
 *
 * Entry:
 *
 * Return:
 *
 *===========================================================================*/
UCHAR HAL_RxPopulateEdidMap (UCHAR *data, UINT16 size, UCHAR SegNum)
{
    if (size <= 256) 
    {
        if (SegNum == 1)
        {
            VRX_set_EDID_SEGMENT_POINTER(1);
        }
        HAL_I2CWriteBlock(VRX_EDID_MAP_ADDR, 0x0, data, size);
        VRX_set_EDID_SEGMENT_POINTER(0);
        return (0);
    }
    return (1);
}

/*============================================================================
 *
 *
 * Entry:
 *
 * Return:
 *
 *===========================================================================*/
UCHAR HAL_RxReadEdidMap (UCHAR *data, UINT16 size, UCHAR SegNum)
{
    if (size <= 256) 
    {
        if (SegNum == 1)
        {
            VRX_set_EDID_SEGMENT_POINTER(1);
        }
        HAL_I2CReadBlock(VRX_EDID_MAP_ADDR, 0x0, data, size);
        VRX_set_EDID_SEGMENT_POINTER(0);
        return (0);
    }
    return (1);
}

/*============================================================================
 * Read KSV list from HDMI RX
 *
 * Entry:   KsvBuf  = Pointer to buffer to receive KSV list
 *                    (Max buffer size is 5 * RX_MAX_NOF_KSVS)
 *
 * Return:  Number of KSVs in the list (List ends at the first all-0 KSV)
 *          KsvBuf filled with KSVs starting with AKVS, BKSV then the rest
 *
 *===========================================================================*/
UCHAR HAL_RxReadKsvList (UCHAR *KsvBuf)
{

#if ((RX_DEVICE == 7612) || (RX_DEVICE == 7611) || (RX_DEVICE == 7619) || (RX_DEVICE == 7850))
    UCHAR j,map_sel, *pKsvBuf;
    UINT16 i, ksv_num;

    VRX_get_AKSV(KsvBuf);
    VRX_get_BKSV(KsvBuf+5);

    pKsvBuf = KsvBuf+10;
    ksv_num = RX_MAX_NOF_KSVS*5;
    map_sel = (ksv_num-1)/128;
    for (j=0; j<=map_sel; j++)
    {
        VRX_set_KSV_MAP_SELECT(j);

        i = (ksv_num>125)? 125:ksv_num;
        HAL_I2CReadBlock (VRX_REPEATER_MAP_ADDR, VRX_REG_KSV_0_1, pKsvBuf, i);
        pKsvBuf += i;
        if (ksv_num>i)        /* more Bksv to read */
        {
            HAL_I2CReadBlock (VRX_REPEATER_MAP_ADDR, VRX_REG_KSV_0_126, pKsvBuf, 3);
            pKsvBuf += 3;
        }
        ksv_num -= 128;
    }
    VRX_set_KSV_MAP_SELECT(0);

    pKsvBuf = KsvBuf+10;
    ksv_num = RX_MAX_NOF_KSVS;
    for (i=0; i<ksv_num; i+=5)
    {
        if (pKsvBuf[i]   || pKsvBuf[i+1] || pKsvBuf[i+2] || 
            pKsvBuf[i+3] || pKsvBuf[i+4])
        {
            break;
        }
    }
    j=(i+4)/5;
    return (j);

#else
    UINT16 i=(RX_MAX_NOF_KSVS*5)+5;
    UCHAR j=RX_MAX_NOF_KSVS+2;

    VRX_get_AKSV(KsvBuf);
    VRX_get_BKSV(KsvBuf+5);
    HAL_I2CReadBlock (VRX_REPEATER_MAP_ADDR, VRX_REG_KSV_0_1, KsvBuf+10, i-5);
    for (; i; i-=5)
    {
        if (KsvBuf[i]   || KsvBuf[i+1] || KsvBuf[i+2] || 
            KsvBuf[i+3] || KsvBuf[i+4])
        {
            break;
        }
        j--;
    }
    return (j);
#endif
}

/*============================================================================
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
 *===========================================================================*/
ATV_ERR HAL_RxSetKsvFifo (UCHAR *BksvList, UCHAR BksvCount)
{
#if ((RX_DEVICE == 7612) || (RX_DEVICE == 7611) || (RX_DEVICE == 7619) || (RX_DEVICE == 7850))
    UCHAR i,j,map_sel, *pBksvList;
    UINT16 ksv_num;

    pBksvList = BksvList;
    ksv_num = BksvCount*5;
    map_sel = ksv_num/128;
    for (j=0; j<=map_sel; j++)
    {
        if (j>=5)
        {
            break;
        }
        VRX_set_KSV_MAP_SELECT(j);

        i = (ksv_num>125)? 125:ksv_num;
        HAL_I2CWriteBlock(VRX_REPEATER_MAP_ADDR, VRX_REG_KSV_0_1, pBksvList, i);
        pBksvList += i;
        if (ksv_num>i)        /* more Bksv to read */
        {
            HAL_I2CWriteBlock(VRX_REPEATER_MAP_ADDR, VRX_REG_KSV_0_126, pBksvList, 3);
            pBksvList += 3;
        }
        ksv_num -= 128;
    }
    VRX_set_KSV_MAP_SELECT(0);
#else

    HAL_I2CWriteBlock (VRX_REPEATER_MAP_ADDR, VRX_REG_KSV_0_1, BksvList, (BksvCount*5));

#endif
    return (ATVERR_OK);  
}

/*============================================================================
 *
 * Return: 0 = Repeated 1 time
 *
 *===========================================================================*/
UCHAR HAL_RxGetPixRepValue (void)
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
    return (RetVal);
}
/*============================================================================
 * This function retrives the Audio Clock Regeneration value N
 *
 * Entry:   NValue Pointer to receive N value
 *
 * Return:  N Value
 *
 *===========================================================================*/
UINT32 HAL_GetN (void)
{
    UCHAR ByteX;
    /*====================================================
     * Read first byte of CTS to trigger snapshot of N 
     *===================================================*/
    HAL_I2CReadByte(VRX_HDMI_MAP_ADDR, VRX_REG_CTS_N_1, &ByteX);
    return (VRX_ret_N());
}

/*============================================================================
 *
 * This function retrives the detected audio mode
 *
 *===========================================================================*/
void HAL_GetDetectedAudioType (RX_AUDIO_TYPE *AudioType)
{
    UCHAR AudModes, i;


    HAL_I2CReadByte(VRX_HDMI_MAP_ADDR, VRX_REG_PACKETS_DETECTED_2, &AudModes);
    AudModes &= 0x0F;
    i = (UCHAR)(ATV_LookupValue8 ((UCHAR*)DetectedAudioTypeCfg, 
                                                (UCHAR)AudModes, 0xff, 2));
    /*if(OpColorSpaceCfg[i] == 0xff)
    {
        *AudioType = DetectedAudioTypeCfg[i+1];
    }*/
    *AudioType = (RX_AUDIO_TYPE)(DetectedAudioTypeCfg[i+1]);
}

/*============================================================================
 * This function is used to enable or disable Hdmi events
 *
 * Entry:   EventList: A pointer to a list of RX events that should be enabled
 *                     or disable
 *          ListSize:  The number of event in the listed pointed by EvntList
 *          Enable:    TRUE = To enable the events pointed by EventList
 *                     FALSE = To disable the events pointed by EventList
 *  
 * Return:  Number or enabled/disabled events processed
 *
 * Notes:   None
 *
 *===========================================================================*/
UCHAR HAL_RxHdmiSetEnabledEvents (RX_EVENT *EventList, UCHAR ListSize, BOOL Enable)
{
    UINT8 i, j, IntIdx, IntCount=0, MaskVal[NOF_RX_MASK_REGS];
    IntIdx = HAL_RxGetIntIndex();

    /*=======================================
     * Get interrupt mask values
     *======================================*/
    for (i=0; RxHdmiMaskRegs[i]; i+=3)
    {
        HAL_I2CReadByte(VRX_IO_MAP_ADDR, RxHdmiMaskRegs[IntIdx+i], &(MaskVal[RxHdmiMaskRegs[i+2]]));
    }

    /*====================================
     * Enable/disable required events
     *===================================*/
    for (i=0; i<ListSize; i++)
    {
        for (j=0; RxMaskInfo[j].Event != 0xff; j++)
        {
            if (RxMaskInfo[j].Event == EventList[i])
            {
                MaskVal[RxMaskInfo[j].Reg1] &= ~(RxMaskInfo[j].Mask1[IntIdx]);
                RX_EVENT_DISABLE(EventList[i]);
                if (Enable)
                {
                    MaskVal[RxMaskInfo[j].Reg1] |= RxMaskInfo[j].Mask1[IntIdx];
                    RX_EVENT_ENABLE(EventList[i]);
                }
                if (RxMaskInfo[j].Reg2 != 0xff)
                {
                    MaskVal[RxMaskInfo[j].Reg2] &= ~(RxMaskInfo[j].Mask2[IntIdx]);
                    if (Enable)
                    {
                        MaskVal[RxMaskInfo[j].Reg2] |= RxMaskInfo[j].Mask2[IntIdx];
                    }
                }
                IntCount++;
                break;
            }
        }
    }

    /*=======================================
     * Update interrupt masks
     *======================================*/
    for (i=0; RxHdmiMaskRegs[i]; i+=3)
    {
        HAL_I2CWriteByte(VRX_IO_MAP_ADDR, RxHdmiMaskRegs[IntIdx+i], MaskVal[RxHdmiMaskRegs[i+2]]);
    }

    /*=======================================
     * Clear masks for unused interrupt
     *======================================*/
    IntIdx = (~IntIdx) & 1;
    for (i=0; RxHdmiMaskRegs[i]; i+=3)
    {
        HAL_I2CWriteByte(VRX_IO_MAP_ADDR, RxHdmiMaskRegs[IntIdx+i], 0);
    }

    return(IntCount);
}

/*============================================================================
 * This function is used to if HDMI events that can't be notified by the 
 * ISR have occurred
 *
 * Entry:   None
 *  
 * Return:  void
 *
 * Notes:   None
 *
 *===========================================================================*/
void HAL_RxHdmiHouseKeeping (void)
{
    RX_AUDIO_TYPE NewAudMode;
    UCHAR i, NewCs[CH_STAT_SIZE];
    BOOL CsValid, CsChanged = FALSE;
    UINT32 NValue;
    RX_DST_MODE DstType;

    /*=====================================================
     * Check if N has changed
     * Sometimes N change is not detected by ISR
     *====================================================*/    
    if (RX_EVENT_IS_ENABLED(RX_EVENT_HDMI_N_CHNG))
    {
        NValue = HAL_GetN();
        if (CurrNVal != NValue)
        {
            CurrNVal = NValue;
            RX_NOTIFY_USER(RX_EVENT_HDMI_N_CHNG, 0, &NValue);
        }
    }

    /*=====================================================
     * Check if audio mode has changed
     * Sometimes audio mode change is not detected by ISR
     *====================================================*/    
    if (RX_EVENT_IS_ENABLED(RX_EVENT_HDMI_AUDIO_MODE_CHNG))
    {
        HAL_GetDetectedAudioType (&NewAudMode);
        if (NewAudMode != CurrAudMode)
        {
            CurrAudMode = NewAudMode;
            ADIAPI_RxHdmiGetDstMode (&DstType);
            RX_NOTIFY_USER(RX_EVENT_HDMI_AUDIO_MODE_CHNG, DstType == RX_DST_SDR ? 1: 0, &CurrAudMode);
        }
    }
    else
    {
        CurrAudMode = RX_AUDIO_UNDEFINED;
    }
    
    /*=====================================================
     * Check if Channel Status Valid has changed
     *====================================================*/    
    if (RX_EVENT_IS_ENABLED(RX_EVENT_HDMI_CS_DATA_VALID))
    {
        CsValid = (((ADIAPI_RxHdmiGetAudioChanStatus(&NewCs[0]) == ATVERR_OK)) ? TRUE : FALSE);
        if (CsValid)
        {
            for (i=0; i<CH_STAT_SIZE; i++)
            {
                if (NewCs[i] != CurrCs[i])
                {
                    CurrCs[i] = NewCs[i];
                    CsChanged = TRUE;
                }
            }
            if (CsChanged)
            {
                RX_NOTIFY_USER(RX_EVENT_HDMI_CS_DATA_VALID, CsValid, &CurrCs[0]);
            }
        }
    }

    /*================================
     * Packet detection workaround
     *===============================*/
    PacketDetectionHK();
}

/*============================================================================
 * Get the color space of the video data output by the HDMI section
 *
 * Entry:   Mode: Input colorspace
 *
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_FAILED = the output color space is not available
 *
 * Notes:   This function does not check if the CSC is configured in automatic
 *          mode. This function simply returns the input color space of a CSC
 *          assuming that it has already been configured in automatic mode
 *
 *===========================================================================*/
ATV_ERR HAL_RxGetHdmiOpColorSpace(RX_CS_COLOR *ColorSpace)
{
    UINT8 i;
    UINT8 HdmiColorSpace = VRX_ret_HDMI_COLORSPACE();
    
    
    i = (UCHAR)(ATV_LookupValue8 ((UCHAR*)OpColorSpaceCfg, 
                                                (UCHAR)HdmiColorSpace, 0xff, 2));
    if(OpColorSpaceCfg[i] == 0xff)
    {
        return (ATVERR_FAILED);
    }
    *ColorSpace = (RX_CS_COLOR)(OpColorSpaceCfg[i+1]);
    return (ATVERR_OK);
}

/*============================================================================
 * Get the range of the video data output by the HDMI section
 *
 * Entry:   Mode: Input colorspace
 *
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_FAILED = the output color space is not available
 *
 * Notes:   This function does not check if the CSC is configured in automatic
 *          mode. This function simply returns the input color space of a CSC
 *          assuming that it has already been configured in automatic mode
 *
 *===========================================================================*/
ATV_ERR HAL_RxGetHdmiOpRange(RX_RANGE *Range)
{
    UINT8 i;
    UINT8 ColorSpace = VRX_ret_HDMI_COLORSPACE();

    
    i = (UCHAR)(ATV_LookupValue8 ((UCHAR*)OpRangeCfg, 
                                                (UCHAR)ColorSpace, 0xff, 2));
    if(OpRangeCfg[i] == 0xff)
    {
        return (ATVERR_FAILED);
    }
    *Range = (RX_RANGE)(OpRangeCfg[i+1]);
    return (ATVERR_OK);
}

/*============================================================================
 *
 *===========================================================================*/
void HAL_RxPktDetectWorkaround (RX_PACKET_TYPE PktType)
{
    UINT32 MsCount;
    UCHAR IntIdx;

    MsCount = ATV_GetMsCountNZ();
    IntIdx = HAL_RxGetIntIndex();

    /*==============================
     * VPLL unlock
     *=============================*/
    if (PktType == 0xff)
    {
        CheckStoppedPkt (&LastIsrc1Time, ISRC1_PACKET_ID, ISRC1_PACKET,
                         RX_EVENT_HDMI_ISRC1_PCKT, IntIdx);
        CheckStoppedPkt (&LastIsrc2Time, ISRC2_PACKET_ID, ISRC2_PACKET,
                         RX_EVENT_HDMI_ISRC2_PCKT, IntIdx);
        CheckStoppedPkt (&LastGmdTime, GMD_PACKET_ID, GAMUT_PACKET,
                         RX_EVENT_HDMI_GAMUT_PCKT, IntIdx);
#if (RX_DEVICE == 7622) || (RX_DEVICE == 7623) || (RX_DEVICE == 76221)
        CheckStoppedPkt (&LastSpdTime, SPD_PACKET_ID, SPD_INFO_PACKET,
                         RX_EVENT_HDMI_SPD_INFO, IntIdx);
        CheckStoppedPkt (&LastAudIfTime, AUDIF_PACKET_ID, AUDIO_INFO_PACKET,
                         RX_EVENT_HDMI_AUDIO_INFO, IntIdx);
        CheckStoppedPkt (&LastAviIfTime, AVIIF_PACKET_ID, AVI_INFO_PACKET,
                         RX_EVENT_HDMI_AVI_INFO, IntIdx);
        CheckStoppedPkt (&LastMpegTime, MPEG_PACKET_ID, MPEG_INFO_PACKET,
                         RX_EVENT_HDMI_MS_INFO, IntIdx);
        CheckStoppedPkt (&LastVsTime, VS_PACKET_ID, VS_INFO_PACKET,
                         RX_EVENT_HDMI_VS_INFO, IntIdx);
#endif
        CheckStoppedPkt (&LastAcpTime, ACP_PACKET_ID, ACP_PACKET,
                         RX_EVENT_HDMI_ACP_PCKT, IntIdx);
    }
    else
    {
        switch (PktType)
        {
            case ISRC1_PACKET:
                LastIsrc1Time = MsCount;
                ENABLE_ISRC1_INT(IntIdx, 0);
                break;
            case ISRC2_PACKET:
                LastIsrc2Time = MsCount;
                ENABLE_ISRC2_INT(IntIdx, 0);
                break;
            case GAMUT_PACKET:
                LastGmdTime = MsCount;
                ENABLE_GMD_INT(IntIdx, 0);
                break;
#if ((RX_DEVICE == 7622) || (RX_DEVICE == 7623) || (RX_DEVICE == 7840) || (RX_DEVICE == 7842) || (RX_DEVICE == 7844) || \
     (RX_DEVICE == 7604) || (RX_DEVICE == 7614) || (RX_DEVICE == 7612) || (RX_DEVICE == 7611) || (RX_DEVICE == 7619) || \
     (RX_DEVICE == 76221) || (RX_DEVICE == 7850))
            case AUDIO_INFO_PACKET:
                LastAudIfTime = MsCount;
                ENABLE_AUDIF_INT(IntIdx, 0);
                break;
            case AVI_INFO_PACKET:
                LastAviIfTime = MsCount;
                ENABLE_AVIIF_INT(IntIdx, 0);
                break;
            case VS_INFO_PACKET:
                LastVsTime = MsCount;
                ENABLE_VS_INT(IntIdx, 0);
                break;
            case SPD_INFO_PACKET:
                LastSpdTime = MsCount;
                ENABLE_SPD_INT(IntIdx, 0);
                break;
            case MPEG_INFO_PACKET:
                LastMpegTime = MsCount;
                ENABLE_MPEG_INT(IntIdx, 0);
                break;
#endif
            case ACP_PACKET:
                LastAcpTime = MsCount;
                ENABLE_ACP_INT(IntIdx, 0);
                break;
            default:
                break;
        }
    }
}

/*============================================================================
 * Must be called periodically (e.g., from RX HDMI housekeeping) to perform 
 * packet-detection workarounds for all devices
 *
 *===========================================================================*/
STATIC void PacketDetectionHK (void)
{
    UCHAR IntIdx = HAL_RxGetIntIndex();

    NoPacketHandling (RX_EVENT_HDMI_ISRC1_PCKT, &LastIsrc1Time,
                      VRX_is_ISRC1_PCKT_RAW_true(), ISRC_REPEAT_INTERVAL,
                      ISRC1_PACKET_ID, ISRC1_PACKET, IntIdx);
    NoPacketHandling (RX_EVENT_HDMI_ISRC2_PCKT, &LastIsrc2Time,
                      VRX_is_ISRC2_PCKT_RAW_true(), ISRC_REPEAT_INTERVAL,
                      ISRC2_PACKET_ID, ISRC2_PACKET, IntIdx);
    NoPacketHandling (RX_EVENT_HDMI_GAMUT_PCKT, &LastGmdTime,
                      VRX_is_GAMUT_MDATA_RAW_true(), MAX_GMD_REPEAT_INTERVAL,
                      GMD_PACKET_ID, GAMUT_PACKET, IntIdx);

#if ((RX_DEVICE == 7622) || (RX_DEVICE == 7623) || (RX_DEVICE == 76221) || (RX_DEVICE == 7840) || (RX_DEVICE == 7842) || (RX_DEVICE == 7844))
    NoPacketHandling (RX_EVENT_HDMI_SPD_INFO, &LastSpdTime,
                      VRX_is_SPD_INFO_RAW_true(), SPD_REPEAT_INTERVAL,
                      SPD_PACKET_ID, SPD_INFO_PACKET, IntIdx);
    NoPacketHandling (RX_EVENT_HDMI_AUDIO_INFO, &LastAudIfTime,
                      VRX_is_AUDIO_INFO_RAW_true(), MAX_AUDIF_REPEAT_INTERVAL,
                      AUDIF_PACKET_ID, AUDIO_INFO_PACKET, IntIdx);
    NoPacketHandling (RX_EVENT_HDMI_AVI_INFO, &LastAviIfTime,
                      VRX_is_AVI_INFO_RAW_true(), MAX_AVIIF_REPEAT_INTERVAL,
                      AVIIF_PACKET_ID, AVI_INFO_PACKET, IntIdx);
    NoPacketHandling (RX_EVENT_HDMI_MS_INFO, &LastMpegTime,
                      VRX_is_MS_INFO_RAW_true(), MAX_MPEG_REPEAT_INTERVAL,
                      MPEG_PACKET_ID, MPEG_INFO_PACKET, IntIdx);
    NoPacketHandling (RX_EVENT_HDMI_VS_INFO, &LastVsTime,
                      VRX_is_VS_INFO_RAW_true(), MAX_VS_REPEAT_INTERVAL,
                      VS_PACKET_ID, VS_INFO_PACKET, IntIdx);
#endif
    NoPacketHandling (RX_EVENT_HDMI_ACP_PCKT, &LastAcpTime,
                      VRX_is_ACP_PCKT_RAW_true(), MAX_ACP_REPEAT_INTERVAL,
                      ACP_PACKET_ID, ACP_PACKET, IntIdx);
}

/*============================================================================
 *
 *===========================================================================*/
STATIC void NoPacketHandling (RX_EVENT PktEvent, UINT32 *LastPktTime, 
                              BOOL RawBit, UINT32 RepInterv, UCHAR PktId, 
                              UCHAR PktType, UCHAR IntIdx)
{
    UCHAR PktBuf[MAX_HDMI_PACKET_SIZE];
    UCHAR ByteX;
    BOOL CsumErr;


    /*==================================
     * If packet event is enabled
     *=================================*/
    if (RX_EVENT_IS_ENABLED(PktEvent))
    {
        /*======================================
         * If packet is still being received
         *=====================================*/
        if (RawBit)
        {
            /*======================================
             * If packet int was generated
             *=====================================*/
            if (*LastPktTime)
            {
                *LastPktTime = ATV_GetMsCountNZ();
                EnablePktInt (IntIdx, PktId, 0);        /* Disable Pkt Int */

                /* Check for 3-D VS InfoFrame */
                if (PktType == VS_INFO_PACKET)
                {
                    ADIAPI_RxHdmiGetPacket (VS_INFO_PACKET, PktBuf, &CsumErr);
                    ByteX = PktBuf[7] & 0xE0;
                    if (ByteX == 0x40)
                    {
                        VsInfoFrame3D = TRUE;
                        RX_NOTIFY_USER(RX_EVENT_HDMI_3D_PACKET, 0, NULL);        
                    }
                }
            }
            else
            {
                EnablePktInt (IntIdx, PktId, 1);        /* Enable Pkt Int */
            }
            ClearRawBit(PktId);
        }
        else
        {
            /*======================================
             * If packet stop notify was generated
             *=====================================*/
            if (*LastPktTime && (ATV_GetElapsedMs(*LastPktTime, 0) > RepInterv))
            {
                EnablePktInt (IntIdx, PktId, 1);        /* Enable Pkt Int */
                ClearRawBit(PktId);
                RX_NOTIFY_USER(RX_EVENT_HDMI_NO_PACKET, 0, &PktType);
                *LastPktTime = 0;
                if (VsInfoFrame3D == TRUE)
                {
                    VsInfoFrame3D = FALSE;
                    RX_NOTIFY_USER(RX_EVENT_HDMI_NO_3D_PACKET, 0, NULL);
                }
            }
        }
    }
}

/*============================================================================
 *
 *===========================================================================*/
STATIC void EnablePktInt (UCHAR IntIdx, UCHAR PktId, UCHAR En)
{
    switch (PktId)
    {
        case AUDIF_PACKET_ID:
            ENABLE_AUDIF_INT(IntIdx, En);
            break;
        case AVIIF_PACKET_ID:
            ENABLE_AVIIF_INT(IntIdx, En);
            break;
        case SPD_PACKET_ID:
            ENABLE_SPD_INT(IntIdx, En);
            break;
        case ACP_PACKET_ID:
            ENABLE_ACP_INT(IntIdx, En);
            break;
        case ISRC1_PACKET_ID:
            ENABLE_ISRC1_INT(IntIdx, En);
            break;
        case ISRC2_PACKET_ID:
            ENABLE_ISRC2_INT(IntIdx, En);
            break;
        case GMD_PACKET_ID:
            ENABLE_GMD_INT(IntIdx, En);
            break;
        case MPEG_PACKET_ID:
            ENABLE_MPEG_INT(IntIdx, En);
            break;
        case VS_PACKET_ID:
            ENABLE_VS_INT(IntIdx, En);
            break;
        default:
            break;
    }
}

/*============================================================================
 *
 *===========================================================================*/
STATIC void ClearRawBit (UCHAR PktId)
{
    switch (PktId)
    {
        case AUDIF_PACKET_ID:
            VRX_set_AUD_PACKET_ID(PktId);
            break;
        case AVIIF_PACKET_ID:
            VRX_set_AVI_PACKET_ID(PktId);
            break;
        case SPD_PACKET_ID:
            VRX_set_SPD_PACKET_ID(PktId);
            break;
        case ACP_PACKET_ID:
            VRX_set_ACP_PACKET_ID(PktId);
            break;
        case ISRC1_PACKET_ID:
            VRX_set_ISRC1_PACKET_ID(PktId);
            break;
        case ISRC2_PACKET_ID:
            VRX_set_ISRC2_PACKET_ID(PktId);
            break;
        case GMD_PACKET_ID:
            VRX_set_GAMUT_PACKET_ID(PktId);
            break;
        case MPEG_PACKET_ID:
            VRX_set_MS_PACKET_ID(PktId);
            break;
        case VS_PACKET_ID:
            VRX_set_VS_PACKET_ID(PktId);
            break;
        default:
            break;
    }
}

/*============================================================================
 *
 *
 *===========================================================================*/
STATIC void CheckStoppedPkt (UINT32 *LastPktTime, UCHAR PktId, UCHAR PktType,
                             RX_EVENT PktEvent, UCHAR IntIdx)
{
    if (*LastPktTime)
    {
        RX_NOTIFY_USER(RX_EVENT_HDMI_NO_PACKET, 0, &PktType);
        *LastPktTime = 0;
    }
    if (RX_EVENT_IS_ENABLED(PktEvent))
    {
        EnablePktInt (IntIdx, PktId, 1);            /* Enable Pkt Int */
        ClearRawBit (PktId);
    }                
}

