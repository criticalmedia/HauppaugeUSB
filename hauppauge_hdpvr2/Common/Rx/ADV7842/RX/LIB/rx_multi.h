/**********************************************************************************************
*																						      *
* Copyright (c) 2012 Analog Devices, Inc.  All Rights Reserved.                               *
* This software is proprietary and confidential to Analog Devices, Inc. and its licensors.    *
*                                                                                             *
***********************************************************************************************/

#ifndef _RX_MULTI_H_
#define _RX_MULTI_H_

/*========================================
 * Multi-device APIs
 *=======================================*/
#if RX_NUM_OF_DEVICES > 1

ATV_ERR ADIAPI_RxInitN (UCHAR DevIdx);
ATV_ERR ADIAPI_RxHdmiSetManualTmdsTermN (UCHAR DevIdx, RX_HDMI_PORT Port, 
                                         BOOL Enable);
ATV_ERR ADIAPI_RxHdmiGetTmdsTermN (UCHAR DevIdx, RX_HDMI_PORT Port, 
                                   BOOL *Enable);   
ATV_ERR ADIAPI_RxHdmiSetAutoTmdsTermN(UCHAR DevIdx);      
ATV_ERR ADIAPI_RxIsrN (UCHAR DevIdx);     
ATV_ERR ADIAPI_RxHdmiInputIsDviN (UCHAR DevIdx, BOOL *Mode);                           
ATV_ERR ADIAPI_RxHdmiAssertHpdN (UCHAR DevIdx, RX_HDMI_PORT Port, BOOL Enable);     
ATV_ERR ADIAPI_RxHdmiIsHpdOnN (UCHAR DevIdx, RX_HDMI_PORT Port, BOOL *HpdOn);
ATV_ERR ADIAPI_RxHdmiConfig5VDetectN (UCHAR DevIdx, BOOL Detect5VFilterDisable, 
                    UCHAR Detected5VFilterTimer, BOOL Detected5VResetDisable);   
ATV_ERR ADIAPI_RxHdmi5VDetectedN (UCHAR DevIdx, RX_HDMI_PORT Port, 
                                  BOOL *Detected5V);     
ATV_ERR ADIAPI_RxHdmiGet5VDetectedN (UCHAR DevIdx, RX_HDMI_PORT *ActivePort,
                                   RX_HDMI_PORT * RxPortDetectPriority);    
ATV_ERR ADIAPI_RxHdmiSetInternalEdidN (UCHAR DevIdx, UCHAR *EdidBuffer, 
                        UINT16 SpaOffset, UCHAR *SpaValues, 
                        UCHAR SegNum, BOOL DisableAutoEdid);     
ATV_ERR ADIAPI_RxHdmiEnableInternalEdidN (UCHAR DevIdx, RX_HDMI_PORT Port,
                                          BOOL Enable); 
ATV_ERR ADIAPI_RxHdmiGetInternalEdidStateN (UCHAR DevIdx, RX_HDMI_PORT Port, 
                        BOOL *EdidEnabled, UCHAR * EdidBuf, UCHAR Segment); 
ATV_ERR ADIAPI_RxHdmiWriteEdidToPromN(UCHAR DevIdx);    
ATV_ERR ADIAPI_RxHdmiSetSelectedPortN (UCHAR DevIdx, RX_HDMI_PORT Port,
                                     BOOL TermEn);      
ATV_ERR ADIAPI_RxHdmiGetSelectedPortN (UCHAR DevIdx, RX_HDMI_PORT *Port);   
ATV_ERR ADIAPI_RxHdmiSetFastSwitchingPortN (UCHAR DevIdx, RX_HDMI_PORT Port, 
                                           BOOL Enable);  
ATV_ERR ADIAPI_RxHdmiTmdsDetectedN (UCHAR DevIdx, RX_HDMI_PORT Port, 
                                    BOOL *Detected);    
ATV_ERR ADIAPI_RxHdmiGetTmdsFreqN (UCHAR DevIdx, UINT16 *TmdsFreqMHz, 
                                UCHAR *TmdsFreqFrac);
ATV_ERR ADIAPI_RxHdmiGetDeepColorModeN (UCHAR DevIdx, 
                               RX_COLOR_DEPTH *DeepColorMode);    
ATV_ERR ADIAPI_RxHdmiSetDeepColorModeN (UCHAR DevIdx, BOOL ManualMode, 
                                       RX_COLOR_DEPTH DeepColorMode);       
ATV_ERR ADIAPI_RxHdmiSetPixelRepeatModeN (UCHAR DevIdx, BOOL AutoRepeat, 
                                       UCHAR RepeatFactor);   
ATV_ERR ADIAPI_RxHdmiGetPixelRepeatN (UCHAR DevIdx, UCHAR * RepeatFactor);   
ATV_ERR ADIAPI_RxHdmiSetHdcpI2CBaseN (UCHAR DevIdx, UCHAR Base);
ATV_ERR ADIAPI_RxHdmiSetVisibleRepMapN (UCHAR DevIdx, RX_HDMI_PORT Port);                                                                                                                                                                                                                                                                                                                                                                                                                            
ATV_ERR ADIAPI_RxHdmiIsContentEncryptedN (UCHAR DevIdx, RX_HDMI_PORT Port,
                                        BOOL *Encrypted);
ATV_ERR ADIAPI_RxHdmiGetHsyncInfoN (UCHAR DevIdx, RX_HDMI_HSYNC * HsyncInfo); 
ATV_ERR ADIAPI_RxHdmiSetVHSyncFilterN (UCHAR DevIdx, UCHAR  Filter); 
ATV_ERR ADIAPI_RxHdmiGetAudioChanStatusN (UCHAR DevIdx, UCHAR * AudioCsData);
ATV_ERR ADIAPI_RxHdmiSetCsCopyrightN (UCHAR DevIdx, BOOL Copyright);   
ATV_ERR ADIAPI_RxHdmiGetAudioChanCountN (UCHAR DevIdx, BOOL * MultiCHAudio);   
ATV_ERR ADIAPI_RxHdmiGetAudioTypeN (UCHAR DevIdx, RX_AUDIO_TYPE * AudioType); 
ATV_ERR ADIAPI_RxHdmiGetDstModeN (UCHAR DevIdx, RX_DST_MODE *DstMode);  
ATV_ERR ADIAPI_RxHdmiConfigI2SOutputN (UCHAR DevIdx, RX_I2S_OUT_MODE I2SMode,
                                      UCHAR *I2SBitWidth); 
ATV_ERR ADIAPI_RxHdmiSetAudioMclkN ( UCHAR DevIdx, RX_MCLK MCLK); 
ATV_ERR ADIAPI_RxHdmiSetCtsRangeN (UCHAR DevIdx, UCHAR  CtsRange);
ATV_ERR ADIAPI_RxHdmiGetAcrInfoN (UCHAR DevIdx, UINT32 * NValue, 
                                  UINT32 * CtsValue);   
ATV_ERR ADIAPI_RxHdmiIgnorePacketChksumErrN (UCHAR DevIdx, BOOL IFAlwaysStore);  
ATV_ERR ADIAPI_RxHdmiGetPacketN (UCHAR DevIdx, RX_PACKET_TYPE PacketType, 
                                UCHAR * Buffer, BOOL * ChecksumErr); 
ATV_ERR ADIAPI_RxHdmiSetHdcpBcapsN (UCHAR DevIdx, RX_HDMI_PORT Port, 
                                   UCHAR Bcaps);   
ATV_ERR ADIAPI_RxHdmiSetHdcpBstatusN (UCHAR DevIdx, RX_HDMI_PORT Port, 
                                      UINT16 Bstatus);  
ATV_ERR ADIAPI_RxHdmiGetHdcpBstatusN (UCHAR DevIdx, RX_HDMI_PORT Port, 
                                     UINT16 * Bstatus);   
ATV_ERR ADIAPI_RxHdmiGetHdcpBcapsN (UCHAR DevIdx, RX_HDMI_PORT Port, 
                                   UCHAR * Bcaps);    
ATV_ERR ADIAPI_RxHdmiClearKsvFifoN (UCHAR DevIdx);  
ATV_ERR ADIAPI_RxHdmiGetAudioChanStatusN (UCHAR DevIdx, UCHAR * AudioCsData);
ATV_ERR ADIAPI_RxHdmiSetCsCopyrightN (UCHAR DevIdx, BOOL Copyright); 
ATV_ERR ADIAPI_RxHdmiSetKsvFifoN (UCHAR DevIdx, UCHAR * BksvList, 
                             UCHAR BksvCount);   
ATV_ERR ADIAPI_RxHdmiSetKsvListReadyBitN (UCHAR DevIdx, BOOL KsvListReady);     
ATV_ERR ADIAPI_RxHdmiAksvReceivedN (UCHAR DevIdx, RX_HDMI_PORT Port, 
                                   BOOL *AksvReady);    
ATV_ERR ADIAPI_RxHdmiGetVideoPllStatusN (UCHAR DevIdx, RX_HDMI_PORT Port, 
                                        BOOL *Locked);  
ATV_ERR ADIAPI_RxHdmiGetAudioPllStatusN (UCHAR DevIdx, BOOL * Locked); 
ATV_ERR ADIAPI_RxHdmiGetStatusN (UCHAR DevIdx, RX_DEV_STATE *DevState);  
ATV_ERR ADIAPI_RxHdmiEnAudioClockN (UCHAR DevIdx, BOOL Enable);   
ATV_ERR ADIAPI_RxHdmiReqBgMeasN (UCHAR DevIdx, RX_HDMI_PORT Port);   
ATV_ERR ADIAPI_RxHdmiGetBgTmdsFreqN (UCHAR DevIdx, RX_HDMI_PORT Port, 
                      UINT16 * TmdsFreqMHz, UCHAR * TmdsFreqFrac);  
ATV_ERR ADIAPI_RxHdmiGetBgHsyncInfoN (UCHAR DevIdx, RX_HDMI_PORT Port, 
                                RX_HDMI_HSYNC * HsyncInfo);
ATV_ERR ADIAPI_RxHdmiGetBgVsyncInfoN (UCHAR DevIdx, RX_HDMI_PORT Port, 
                                      RX_HDMI_VSYNC * VsyncInfo);  
ATV_ERR ADIAPI_RxHdmiGetBgDeepColorModeN (UCHAR DevIdx, RX_HDMI_PORT Port, 
                                         RX_COLOR_DEPTH * DeepColorMode); 
ATV_ERR ADIAPI_RxHdmiGetBgPixelRepeatN (UCHAR DevIdx, RX_HDMI_PORT Port, 
                                       UCHAR * RepeatFactor);     
ATV_ERR ADIAPI_RxSetAudioPassThroughN (UCHAR DevIdx, BOOL Set);    
ATV_ERR ADIAPI_RxHdmiSetEthernetPathN (UCHAR DevIdx, RX_CHIP_SECTION EThPort, 
                 RX_CHIP_SECTION HecPort, BOOL Enable);                                                                                                                                                                                                                                                                                                                                                                                                                     
                                                                                                
#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif

#else

#define ADIAPI_RxInitN(i)                                  ADIAPI_RxInit()
#define ADIAPI_RxHdmiSetManualTmdsTermN(i,a,b)             ADIAPI_RxHdmiSetManualTmdsTerm(a,b)
#define ADIAPI_RxHdmiGetTmdsTermN(i,a,b)                   ADIAPI_RxHdmiGetTmdsTermN(a,b)
#define ADIAPI_RxHdmiSetAutoTmdsTermN(i)                   ADIAPI_RxHdmiSetAutoTmdsTerm()
#define ADIAPI_RxIsrN(i)                                   ADIAPI_RxIsr()
#define ADIAPI_RxHdmiInputIsDviN(i,a)                      ADIAPI_RxHdmiInputIsDviN(a)
#define ADIAPI_RxHdmiAssertHpdN(i,a,b)                     ADIAPI_RxHdmiAssertHpd(a,b)
#define ADIAPI_RxHdmiIsHpdOnN(i,a,b)                       ADIAPI_RxHdmiIsHpdOn(a,b)
#define ADIAPI_RxHdmiConfig5VDetectN(i,a,b,c)              ADIAPI_RxHdmiConfig5VDetect(a,b,c)
#define ADIAPI_RxHdmi5VDetectedN(i,a,b)                    ADIAPI_RxHdmi5VDetected(a,b)
#define ADIAPI_RxHdmiGet5VDetectedN(i,a,b)                 ADIAPI_RxHdmiGet5VDetected(a,b)
#define ADIAPI_RxHdmiSetInternalEdidN(i,a,b,c,d,e)         ADIAPI_RxHdmiSetInternalEdid(a,b,c,d,e)
#define ADIAPI_RxHdmiEnableInternalEdidN(i,a,b)            ADIAPI_RxHdmiEnableInternalEdid(a,b)
#define ADIAPI_RxHdmiGetInternalEdidStateN(i,a,b,c,d)      ADIAPI_RxHdmiGetInternalEdidStateN(a,b,c,d)
#define ADIAPI_RxHdmiSetSelectedPortN(i,a,b)               ADIAPI_RxHdmiSetSelectedPort(a,b)
#define ADIAPI_RxHdmiGetSelectedPortN(i,a)                 ADIAPI_RxHdmiGetSelectedPort(a)
#define ADIAPI_RxHdmiSetFastSwitchingPortN(i,a,b)          ADIAPI_RxHdmiSetFastSwitchingPort(a,b)
#define ADIAPI_RxHdmiTmdsDetectedN(i,a,b)                  ADIAPI_RxHdmiTmdsDetected(a,b)
#define ADIAPI_RxHdmiGetTmdsFreqN(i,a,b)                   ADIAPI_RxHdmiGetTmdsFreq(a,b)
#define ADIAPI_RxHdmiGetDeepColorModeN(i,a)                ADIAPI_RxHdmiGetDeepColorMode(a)
#define ADIAPI_RxHdmiSetDeepColorModeN(i,a,b)              ADIAPI_RxHdmiSetDeepColorMode(a,b)
#define ADIAPI_RxHdmiSetPixelRepeatModeN(i,a,b)            ADIAPI_RxHdmiSetPixelRepeatMode(a,b)
#define ADIAPI_RxHdmiGetPixelRepeatN(i,a)                  ADIAPI_RxHdmiGetPixelRepeat(a)
#define ADIAPI_RxHdmiSetHdcpI2CBaseN(i,a)                  ADIAPI_RxHdmiSetHdcpI2CBase(a)
#define ADIAPI_RxHdmiSetVisibleRepMapN(i,a)                ADIAPI_RxHdmiSetVisibleRepMap(a)
#define ADIAPI_RxHdmiIsContentEncryptedN(i,a,b)            ADIAPI_RxHdmiIsContentEncrypted(a,b)
#define ADIAPI_RxHdmiGetHsyncInfoN(i,a)                    ADIAPI_RxHdmiGetHsyncInfo(a)
#define ADIAPI_RxHdmiSetVHSyncFilterN(i,a)                 ADIAPI_RxHdmiSetVHSyncFilter(a)
#define ADIAPI_RxHdmiGetAudioChanStatusN(i,a)              ADIAPI_RxHdmiGetAudioChanStatus(a)
#define ADIAPI_RxHdmiSetCsCopyrightN(i,a)                  ADIAPI_RxHdmiSetCsCopyright(a)
#define ADIAPI_RxHdmiGetAudioChanCountN(i,a)               ADIAPI_RxHdmiGetAudioChanCount(a)
#define ADIAPI_RxHdmiGetAudioTypeN(i,a)                    ADIAPI_RxHdmiGetAudioType(a)
#define ADIAPI_RxHdmiGetDstModeN(i,a)                      ADIAPI_RxHdmiGetDstMode(a)
#define ADIAPI_RxHdmiConfigI2SOutputN (i,a,b)              ADIAPI_RxHdmiConfigI2SOutput(a,b)
#define ADIAPI_RxHdmiSetAudioMclkN(i,a)                    ADIAPI_RxHdmiSetAudioMclk(a)
#define ADIAPI_RxHdmiSetCtsRangeN(i,a)                     ADIAPI_RxHdmiSetCtsRange(a)
#define ADIAPI_RxHdmiGetAcrInfoN(i,a,b)                    ADIAPI_RxHdmiGetAcrInfo(a,b)
#define ADIAPI_RxHdmiIgnorePacketChksumErrN(i,a)           ADIAPI_RxHdmiIgnorePacketChksumErr(a)
#define ADIAPI_RxHdmiGetPacketN(i,a,b,c)                   ADIAPI_RxHdmiGetPacket(a,b,c)
#define ADIAPI_RxHdmiSetHdcpBcapsN(i,a,b)                  ADIAPI_RxHdmiSetHdcpBcaps(a,b)
#define ADIAPI_RxHdmiSetHdcpBstatusN(i,a,b)                ADIAPI_RxHdmiSetHdcpBstatus(a,b)
#define ADIAPI_RxHdmiGetHdcpBstatusN(i,a,b)                ADIAPI_RxHdmiGetHdcpBstatus(a,b)
#define ADIAPI_RxHdmiGetHdcpBcapsN(i,a,b)                  ADIAPI_RxHdmiGetHdcpBcaps(a,b)
#define ADIAPI_RxHdmiClearKsvFifoN(i)                      ADIAPI_RxHdmiClearKsvFifo()
#define ADIAPI_RxHdmiGetAudioChanStatusN(i,a)              ADIAPI_RxHdmiGetAudioChanStatus(a)
#define ADIAPI_RxHdmiSetCsCopyrightN(i,a)                  ADIAPI_RxHdmiSetCsCopyright(a)
#define ADIAPI_RxHdmiSetKsvFifoN(i,a,b)                    ADIAPI_RxHdmiSetKsvFifo(a,b)
#define ADIAPI_RxHdmiSetKsvListReadyBitN(i,a)              ADIAPI_RxHdmiSetKsvListReadyBit(a)
#define ADIAPI_RxHdmiAksvReceivedN(i,a,b)                  ADIAPI_RxHdmiAksvReceived(a,b)
#define ADIAPI_RxHdmiGetVideoPllStatusN(i,a,b)             ADIAPI_RxHdmiGetVideoPllStatus(a,b)
#define ADIAPI_RxHdmiGetAudioPllStatusN(i,a)               ADIAPI_RxHdmiGetAudioPllStatus(a)
#define ADIAPI_RxHdmiGetStatusN(i,a)                       ADIAPI_RxHdmiGetStatus(a)
#define ADIAPI_RxHdmiEnAudioClockN(i,a)                    ADIAPI_RxHdmiEnAudioClock(a)
#define ADIAPI_RxHdmiReqBgMeasN(i,a)                       ADIAPI_RxHdmiReqBgMeas(a)
#define ADIAPI_RxHdmiGetBgTmdsFreqN(i,a,b,c)               ADIAPI_RxHdmiGetBgTmdsFreq(a,b,c)
#define ADIAPI_RxHdmiGetBgHsyncInfoN(i,a,b)                ADIAPI_RxHdmiGetBgHsyncInfo(a,b)
#define ADIAPI_RxHdmiGetBgVsyncInfoN(i,a,b)                ADIAPI_RxHdmiGetBgVsyncInfo(a,b)
#define ADIAPI_RxHdmiGetBgDeepColorModeN(i,a,b)            ADIAPI_RxHdmiGetBgDeepColorMode(a,b)
#define ADIAPI_RxHdmiGetBgPixelRepeatN(i,a,b)              ADIAPI_RxHdmiGetBgPixelRepeat(a,b)
#define ADIAPI_RxSetAudioPassThroughN(i,a)                 ADIAPI_RxSetAudioPassThrough(a)
#define ADIAPI_RxHdmiSetEthernetPathN(i,a,b,c)             ADIAPI_RxHdmiSetEthernetPath(a,b,c)
#endif

#endif
