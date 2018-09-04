/**********************************************************************************************
*																						      *
* Copyright (c) 2012 Analog Devices, Inc.  All Rights Reserved.                               *
* This software is proprietary and confidential to Analog Devices, Inc. and its licensors.    *
*                                                                                             *
***********************************************************************************************/

#include "rx_lib.h"
#include "rx_isr.h"

#if ( (RX_NUM_OF_DEVICES > 1) && (RX_DEVICE != 7612))

/*======================================
 * Defines, Macros and Externals
 *=====================================*/
#define SINGLE_PREFIX       ATV_ERR RetVal = ATVERR_INV_PARM;               \
                            UCHAR OrgIdx;                                   \
                            if (DevIdx < RX_NUM_OF_DEVICES)                 \
                            {                                               \
                                OrgIdx = RxCurrDevIdx;                      \
                                RxCurrDevIdx = DevIdx;                      \
                                RxDevAddr = &(RxDeviceAddress[RxCurrDevIdx]);

#define SINGLE_SUFFIX           RxCurrDevIdx = OrgIdx;                      \
                                RxDevAddr = &(RxDeviceAddress[RxCurrDevIdx]); \
                            }                                               \
                            return (RetVal);                                


#define MULTI_PREFIX        ATV_ERR RetVal = ATVERR_INV_PARM;               \
                            UCHAR OrgIdx, StartIdx, EndIdx;                 \
                            OrgIdx = RxCurrDevIdx;                          \
                            if (DevIdx == RX_ALL_DEV)                       \
                            {                                               \
                                StartIdx = 0;                               \
                                EndIdx = RX_NUM_OF_DEVICES;                 \
                            }                                               \
                            else if (DevIdx < RX_NUM_OF_DEVICES)            \
                            {                                               \
                                StartIdx = DevIdx;                          \
                                EndIdx = StartIdx + 1;                      \
                            }                                               \
                            else                                            \
                            {                                               \
                                return (RetVal);                            \
                            }                                               \
                            for (; StartIdx<EndIdx; StartIdx++)             \
                            {                                               \
                                RxCurrDevIdx = StartIdx;                    \
                                RxDevAddr = &(RxDeviceAddress[RxCurrDevIdx]);

#define MULTI_SUFFIX        }                                               \
                            RxCurrDevIdx = OrgIdx;                          \
                            RxDevAddr = &(RxDeviceAddress[RxCurrDevIdx]);   \
                            return (RetVal);

/*==================================================
 * Mapping between dev 0 addresses and the pointer
 * to current device addresses
 *=================================================*/
typedef struct 
{
    UCHAR   Dev0Addr;
    UCHAR   *CurrAddrPtr;
} RX_CURR_I2C_ADDR;

#if 0
STATIC CONSTANT RX_CURR_I2C_ADDR RxDevMapTable[] {
    {RX_I2C_IO_MAP_ADDR,        &(VRX_IO_MAP_ADDR)           },
    {RX_I2C_SDP_VDP_MAP_ADDR,   &(VRX_SDP_VDP_MAP_ADDR)      },
    {RX_I2C_AFE_DPLL_MAP_ADDR,  &(VRX_AFE_DPLL_MAP_ADDR)     },
    {RX_I2C_ESDP_MAP_ADDR,      &(VRX_ESDP_MAP_ADDR)         },
    {RX_I2C_SDP_IO_MAP_ADDR,    &(VRX_SDP_IO_MAP_ADDR)       },
    {RX_I2C_CP_MAP_ADDR,        &(VRX_CP_MAP_ADDR)           },
    {RX_I2C_VDP_MAP_ADDR,       &(VRX_VDP_MAP_ADDR)          },
    {RX_I2C_TEST_MAP3_ADDR,     &(VRX_TEST_MAP3_ADDR)        },
    {RX_I2C_TEST_MAP1_ADDR,     &(VRX_TEST_MAP1_ADDR)        },
    {RX_I2C_TEST_MAP2_ADDR,     &(VRX_TEST_MAP2_ADDR)        },
    {RX_I2C_REPEATER_MAP_ADDR,  &(VRX_REPEATER_MAP_ADDR)     },
    {RX_I2C_HDMI_MAP_ADDR,      &(VRX_HDMI_MAP_ADDR)         },
    {RX_I2C_EDID_MAP_ADDR,      &(VRX_EDID_MAP_ADDR)         },
    {RX_I2C_DPP_MAP_ADDR,       &(VRX_DPP_MAP_ADDR)          },
    {RX_I2C_INFOFRAME_MAP_ADDR, &(VRX_INFOFRAME_MAP_ADDR)    },  
    {RX_I2C_CEC_MAP_ADDR,       &(VRX_CEC_MAP_ADDR)          },
    {RX_I2C_SDP_MAP_ADDR,       &(VRX_SDP_MAP_ADDR)          },
    {RX_I2C_AVLINK_MAP_ADDR,    &(VRX_AVLINK_MAP_ADDR)       },
    {RX_I2C_OSD_MAP_ADDR,         &(VRX_OSD_MAP_ADDR)         },
    {RX_I2C_VFE_MAP_ADDR,         &(VRX_VFE_MAP_ADDR)         },
    {RX_I2C_AUDIO_CODEC_MAP_ADDR, &(VRX_AUDIO_CODEC_MAP_ADDR) },
    {RX_I2C_XMEM_GAMMA_MAP_ADDR, &(VRX_AUDIO_CODEC_MAP_ADDR)  },
    {TX_I2C_PKT_MEM_MAP_ADDR,   &(VRX_TX_UDP_MAP_ADDR)        },
    {TX_I2C_EDID_MAP_ADDR,      &(VRX_TX_EDID_MAP_ADDR)       },
    {0,                         NULL}
};
#endif

/*============================================================================
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxInitN (UCHAR DevIdx, RX_OP_MODE OperatingMode)
{
    MULTI_PREFIX
    RetVal = ADIAPI_RxInit(OperatingMode);
    MULTI_SUFFIX
}

ATV_ERR ADIAPI_RxHdmiSetManualTmdsTermN (UCHAR DevIdx, RX_HDMI_PORT Port, 
                                         BOOL Enable)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiSetManualTmdsTerm(Port,Enable);
        MULTI_SUFFIX
}

ATV_ERR ADIAPI_RxHdmiGetTmdsTermN (UCHAR DevIdx, RX_HDMI_PORT Port, 
                                   BOOL *Enable)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiGetTmdsTerm(Port, Enable);
        MULTI_SUFFIX    
}

ATV_ERR ADIAPI_RxHdmiSetAutoTmdsTermN(UCHAR DevIdx)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiSetAutoTmdsTerm();
        MULTI_SUFFIX            
        
} 

ATV_ERR ADIAPI_RxIsrN (UCHAR DevIdx)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxIsr();
        MULTI_SUFFIX                    
}

ATV_ERR ADIAPI_RxHdmiInputIsDviN (UCHAR DevIdx, BOOL *Mode)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiInputIsDvi(Mode);
        MULTI_SUFFIX                            
}

ATV_ERR ADIAPI_RxHdmiAssertHpdN (UCHAR DevIdx, RX_HDMI_PORT Port, BOOL Enable)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiAssertHpd(Port,Enable);
        MULTI_SUFFIX                                    
}
ATV_ERR ADIAPI_RxHdmiIsHpdOnN (UCHAR DevIdx, RX_HDMI_PORT Port, BOOL *HpdOn)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiIsHpdOn(Port,HpdOn);
        MULTI_SUFFIX                    
}
ATV_ERR ADIAPI_RxHdmiConfig5VDetectN (UCHAR DevIdx, BOOL Detect5VFilterDisable, 
                    UCHAR Detected5VFilterTimer, BOOL Detected5VResetDisable)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiConfig5VDetect (Detect5VFilterDisable, 
                    Detected5VFilterTimer, Detected5VResetDisable);
    MULTI_SUFFIX                        
}    

ATV_ERR ADIAPI_RxHdmi5VDetectedN (UCHAR DevIdx, RX_HDMI_PORT Port, 
                                  BOOL *Detected5V)                
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmi5VDetected (Port,Detected5V); 
    MULTI_SUFFIX                                
}                                  

ATV_ERR ADIAPI_RxHdmiGet5VDetectedN (UCHAR DevIdx, RX_HDMI_PORT *ActivePort,
                                   RX_HDMI_PORT * RxPortDetectPriority)                                  
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiGet5VDetected (ActivePort,RxPortDetectPriority); 
    MULTI_SUFFIX                                
}         

ATV_ERR ADIAPI_RxHdmiSetInternalEdidN (UCHAR DevIdx, UCHAR *EdidBuffer, 
                        UINT16 SpaOffset, UCHAR *SpaValues, 
                        UCHAR SegNum, BOOL DisableAutoEdid)                                
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiSetInternalEdid (EdidBuffer,SpaOffset,
                           SpaValues, SegNum, DisableAutoEdid); 
    MULTI_SUFFIX                                        
} 

ATV_ERR ADIAPI_RxHdmiEnableInternalEdidN (UCHAR DevIdx, RX_HDMI_PORT Port,
                                          BOOL Enable)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiEnableInternalEdid (Port,Enable);
    MULTI_SUFFIX                                        
}                                           

ATV_ERR ADIAPI_RxHdmiGetInternalEdidStateN (UCHAR DevIdx, RX_HDMI_PORT Port, 
                        BOOL *EdidEnabled, UCHAR * EdidBuf, UCHAR Segment)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiGetInternalEdidState (Port,EdidEnabled,
                                   EdidBuf, Segment);
    MULTI_SUFFIX                        
} 

ATV_ERR ADIAPI_RxHdmiSetSelectedPortN (UCHAR DevIdx,RX_HDMI_PORT Port,
                                     BOOL TermEn)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiSetSelectedPort (Port,TermEn);
    MULTI_SUFFIX                                
}                                     
ATV_ERR ADIAPI_RxHdmiGetSelectedPortN (UCHAR DevIdx, RX_HDMI_PORT *Port)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiGetSelectedPort (Port);
    MULTI_SUFFIX                                        
        
}

ATV_ERR ADIAPI_RxHdmiSetFastSwitchingPortN (UCHAR DevIdx, RX_HDMI_PORT Port, 
                                           BOOL Enable)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiSetFastSwitchingPort (Port, Enable);
    MULTI_SUFFIX                                        
        
}

ATV_ERR ADIAPI_RxHdmiTmdsDetectedN (UCHAR DevIdx, RX_HDMI_PORT Port, 
                                    BOOL *Detected)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiTmdsDetected (Port, Detected);
    MULTI_SUFFIX                                        
}

ATV_ERR ADIAPI_RxHdmiGetTmdsFreqN (UCHAR DevIdx, UINT16 *TmdsFreqMHz, 
                                UCHAR *TmdsFreqFrac)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiGetTmdsFreq (TmdsFreqMHz, TmdsFreqFrac);
    MULTI_SUFFIX                                                
}       

ATV_ERR ADIAPI_RxHdmiGetDeepColorModeN (UCHAR DevIdx, 
                               RX_COLOR_DEPTH *DeepColorMode)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiGetDeepColorMode (DeepColorMode);
    MULTI_SUFFIX                                                        
}
        
ATV_ERR ADIAPI_RxHdmiSetDeepColorModeN (UCHAR DevIdx, BOOL ManualMode, 
                                       RX_COLOR_DEPTH DeepColorMode) 
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiSetDeepColorMode (ManualMode, DeepColorMode);
    MULTI_SUFFIX                                                        
}                                       
 
ATV_ERR ADIAPI_RxHdmiSetPixelRepeatModeN (UCHAR DevIdx, BOOL AutoRepeat, 
                                       UCHAR RepeatFactor)                                       
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiSetPixelRepeatMode (AutoRepeat, RepeatFactor);
    MULTI_SUFFIX        
}
         
ATV_ERR ADIAPI_RxHdmiGetPixelRepeatN (UCHAR DevIdx, UCHAR * RepeatFactor)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiGetPixelRepeat (RepeatFactor);
    MULTI_SUFFIX                
}     

ATV_ERR ADIAPI_RxHdmiSetHdcpI2CBaseN (UCHAR DevIdx, UCHAR Base)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiSetHdcpI2CBase (Base);
    MULTI_SUFFIX                        
}   

ATV_ERR ADIAPI_RxHdmiSetVisibleRepMapN (UCHAR DevIdx, RX_HDMI_PORT Port)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiSetVisibleRepMap (Port);
    MULTI_SUFFIX                
}    

ATV_ERR ADIAPI_RxHdmiIsContentEncryptedN (UCHAR DevIdx, RX_HDMI_PORT Port,
                                        BOOL *Encrypted)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiIsContentEncrypted (Port, Encrypted);
    MULTI_SUFFIX        
}  

ATV_ERR ADIAPI_RxHdmiGetHdcpKeyStatusN (UCHAR DevIdx, BOOL * KeyRead, BOOL * KeyErr)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiGetHdcpKeyStatus (KeyRead, KeyErr);
    MULTI_SUFFIX                
}

ATV_ERR ADIAPI_RxHdmiGetHsyncInfoN (UCHAR DevIdx, RX_HDMI_HSYNC * HsyncInfo) 
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiGetHsyncInfo (HsyncInfo);
    MULTI_SUFFIX                
} 

ATV_ERR ADIAPI_RxHdmiSetVHSyncFilterN (UCHAR DevIdx, UCHAR  Filter)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiSetVHSyncFilter (Filter);
    MULTI_SUFFIX                        
}   
ATV_ERR ADIAPI_RxHdmiGetAudioChanStatusN (UCHAR DevIdx, UCHAR * AudioCsData)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiGetAudioChanStatus (AudioCsData);
    MULTI_SUFFIX                        
}   
        
ATV_ERR ADIAPI_RxHdmiSetCsCopyrightN (UCHAR DevIdx, BOOL Copyright)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiSetCsCopyright (Copyright);
    MULTI_SUFFIX                        
}       

ATV_ERR ADIAPI_RxHdmiGetAudioChanCountN (UCHAR DevIdx, BOOL * MultiCHAudio)  
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiGetAudioChanCount (MultiCHAudio);
    MULTI_SUFFIX                        
}       

ATV_ERR ADIAPI_RxHdmiGetAudioTypeN (UCHAR DevIdx, RX_AUDIO_TYPE * AudioType)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiGetAudioType (AudioType);
    MULTI_SUFFIX                        
}       

ATV_ERR ADIAPI_RxHdmiGetDstModeN (UCHAR DevIdx, RX_DST_MODE *DstMode) 
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiGetDstMode (DstMode);
    MULTI_SUFFIX                        
}       

ATV_ERR ADIAPI_RxHdmiConfigI2SOutputN (UCHAR DevIdx, RX_I2S_OUT_MODE I2SMode,
                                      UCHAR *I2SBitWidth)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiConfigI2SOutput (I2SMode, I2SBitWidth );
    MULTI_SUFFIX                        
}                                             

ATV_ERR ADIAPI_RxHdmiSetAudioMclkN ( UCHAR DevIdx, RX_MCLK MCLK)                        
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiSetAudioMclk (MCLK );
    MULTI_SUFFIX                        
}  

ATV_ERR ADIAPI_RxHdmiSetCtsRangeN (UCHAR DevIdx, UCHAR  CtsRange)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiSetCtsRange (CtsRange );
    MULTI_SUFFIX                        
}  

ATV_ERR ADIAPI_RxHdmiGetAcrInfoN (UCHAR DevIdx, UINT32 * NValue, 
                                  UINT32 * CtsValue)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiGetAcrInfo (NValue, CtsValue );
    MULTI_SUFFIX                        
}       

ATV_ERR ADIAPI_RxHdmiIgnorePacketChksumErrN (UCHAR DevIdx, BOOL IFAlwaysStore)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiIgnorePacketChksumErr (IFAlwaysStore );
    MULTI_SUFFIX        
}

ATV_ERR ADIAPI_RxHdmiChangePacketIDN (UCHAR DevIdx, RX_PACKET_TYPE PacketType, 
                                     UCHAR NewPacketID)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiChangePacketID (PacketType, NewPacketID );
    MULTI_SUFFIX                
                                             
}

ATV_ERR ADIAPI_RxHdmiGetPacketN (UCHAR DevIdx, RX_PACKET_TYPE PacketType, 
                                UCHAR * Buffer, BOOL * ChecksumErr)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiGetPacket (PacketType, Buffer, ChecksumErr );
    MULTI_SUFFIX        
}   

ATV_ERR ADIAPI_RxHdmiSetHdcpBcapsN (UCHAR DevIdx, RX_HDMI_PORT Port, 
                                   UCHAR Bcaps)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiSetHdcpBcaps (Port, Bcaps );
    MULTI_SUFFIX        
}                                   

ATV_ERR ADIAPI_RxHdmiSetHdcpBstatusN (UCHAR DevIdx, RX_HDMI_PORT Port, 
                                      UINT16 Bstatus)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiSetHdcpBstatus (Port, Bstatus );
    MULTI_SUFFIX        
}                                              

ATV_ERR ADIAPI_RxHdmiGetHdcpBstatusN (UCHAR DevIdx, RX_HDMI_PORT Port, 
                                     UINT16 * Bstatus)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiGetHdcpBstatus (Port, Bstatus );
    MULTI_SUFFIX                
        
}  

ATV_ERR ADIAPI_RxHdmiGetHdcpBcapsN (UCHAR DevIdx, RX_HDMI_PORT Port, 
                                   UCHAR * Bcaps)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiGetHdcpBcaps (Port, Bcaps );
    MULTI_SUFFIX                
        
}  

ATV_ERR ADIAPI_RxHdmiClearKsvFifoN (UCHAR DevIdx)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiClearKsvFifo ( );
    MULTI_SUFFIX                        
}

ATV_ERR ADIAPI_RxHdmiSetKsvFifoN (UCHAR DevIdx, UCHAR * BksvList, 
                             UCHAR BksvCount)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiSetKsvFifo (BksvList, BksvCount);
    MULTI_SUFFIX                        
}

ATV_ERR ADIAPI_RxHdmiSetKsvListReadyBitN (UCHAR DevIdx, BOOL KsvListReady)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiSetKsvListReadyBit (KsvListReady);
    MULTI_SUFFIX        
}

ATV_ERR ADIAPI_RxHdmiAksvReceivedN (UCHAR DevIdx, RX_HDMI_PORT Port, 
                                   BOOL *AksvReady)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiAksvReceived (Port, AksvReady);
    MULTI_SUFFIX        
}

ATV_ERR ADIAPI_RxHdmiGetVideoPllStatusN (UCHAR DevIdx, RX_HDMI_PORT Port, 
                                        BOOL *Locked)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiGetVideoPllStatus (Port, Locked);
    MULTI_SUFFIX        
}                                        

ATV_ERR ADIAPI_RxHdmiGetAudioPllStatusN (UCHAR DevIdx, BOOL * Locked)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiGetAudioPllStatus (Locked);
    MULTI_SUFFIX        
}       

ATV_ERR ADIAPI_RxHdmiGetStatusN (UCHAR DevIdx, RX_DEV_STATE *DevState)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiGetStatus (DevState);
    MULTI_SUFFIX        
}       

ATV_ERR ADIAPI_RxHdmiEnAudioClockN (UCHAR DevIdx, BOOL Enable)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiEnAudioClock (Enable);
    MULTI_SUFFIX        
}  

ATV_ERR ADIAPI_RxHdmiReqBgMeasN (UCHAR DevIdx, RX_HDMI_PORT Port)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiReqBgMeas (Port);
    MULTI_SUFFIX        
}  

ATV_ERR ADIAPI_RxHdmiGetBgTmdsFreqN (UCHAR DevIdx, RX_HDMI_PORT Port, 
                      UINT16 * TmdsFreqMHz, UCHAR * TmdsFreqFrac)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiGetBgTmdsFreq (Port, TmdsFreqMHz, TmdsFreqFrac);
    MULTI_SUFFIX        
}                        

ATV_ERR ADIAPI_RxHdmiGetBgHsyncInfoN (UCHAR DevIdx, RX_HDMI_PORT Port, 
                                RX_HDMI_HSYNC * HsyncInfo) 
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiGetBgHsyncInfo (Port, HsyncInfo);
    MULTI_SUFFIX        
}            

ATV_ERR ADIAPI_RxHdmiGetBgVsyncInfoN (UCHAR DevIdx, RX_HDMI_PORT Port, 
                                      RX_HDMI_VSYNC * VsyncInfo)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiGetBgVsyncInfo (Port, VsyncInfo);
    MULTI_SUFFIX                
}
ATV_ERR ADIAPI_RxHdmiGetBgDeepColorModeN (UCHAR DevIdx, RX_HDMI_PORT Port, 
                                         RX_COLOR_DEPTH * DeepColorMode)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiGetBgDeepColorMode (Port, DeepColorMode);
    MULTI_SUFFIX                
}    

ATV_ERR ADIAPI_RxHdmiGetBgPixelRepeatN (UCHAR DevIdx, RX_HDMI_PORT Port, 
                                       UCHAR * RepeatFactor)                                     
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiGetBgPixelRepeat (Port, RepeatFactor);
    MULTI_SUFFIX                
}                                           

ATV_ERR ADIAPI_RxSetAudioPassThroughN (UCHAR DevIdx, BOOL Set)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxSetAudioPassThrough (Set);
    MULTI_SUFFIX                        
}
ATV_ERR ADIAPI_RxHdmiSetArcModeN (UCHAR DevIdx, RX_ARC_MODE Mode)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiSetArcMode (Mode);
    MULTI_SUFFIX                
}
ATV_ERR ADIAPI_RxHdmiSetEthernetPathN (UCHAR DevIdx, RX_CHIP_SECTION EThPort, 
                 RX_CHIP_SECTION HecPort, BOOL Enable)
{
    MULTI_PREFIX
        RetVal = ADIAPI_RxHdmiSetEthernetPath (EThPort,HecPort,Enable);
    MULTI_SUFFIX                        
}
#endif
