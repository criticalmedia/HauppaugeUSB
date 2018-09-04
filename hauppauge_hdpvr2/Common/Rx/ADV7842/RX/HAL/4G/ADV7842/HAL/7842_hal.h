/**********************************************************************************************
*																						      *
* Copyright (c) 2012 Analog Devices, Inc.  All Rights Reserved.                               *
* This software is proprietary and confidential to Analog Devices, Inc. and its licensors.    *
*                                                                                             *
***********************************************************************************************/

#ifndef _7842_HAL_H_ 
#define _7842_HAL_H_

#if (RX_DEVICE==7842)

#include "ADV7842_cfg.h"
#include "ADV7842_lib.h"
#include "rx_4g_hal.h"

enum                                            /* Audio unmute delays */
{
    RX_AUD_UNMUTE_AFTER_0MS,
    RX_AUD_UNMUTE_AFTER_250MS,
    RX_AUD_UNMUTE_AFTER_500MS,
    RX_AUD_UNMUTE_AFTER_750MS,
    RX_AUD_UNMUTE_AFTER_1000MS
};

/*==========================================
 * ADV7840/ADV7604- ADV7842 Direct Mapping
 *=========================================*/
#define VRX_is_INTERLACED_HDMI_true             VRX_is_HDMI_INTERLACED_true
#define VRX_set_SDP_MAIN_RESET                  VRX_set_SDP_RESET

#define VRX_get_FIELD_0_HEIGHT                  VRX_get_FIELD0_HEIGHT
#define VRX_get_FIELD_1_HEIGHT                  VRX_get_FIELD1_HEIGHT

#define VRX_set_BYPASS_AUDIO_PASSTHRU(a)        /* Not supported */

/*==========================================
 * Standardization of VDP Fast I2C/SPI naming
 *=========================================*/
#define VRX_BIT_FASTVDP_DATA_AVL_MB1            VRX_BIT_FASTI2C_DATA_RDY_MB1                        
#define VRX_BIT_FASTVDP_DATA_AVL_MB2            VRX_BIT_FASTI2C_DATA_RDY_MB2
#define VRX_BIT_FASTVDP_DATA_AVL_ST             VRX_BIT_FASTI2C_DATA_RDY_ST
#define VRX_BIT_FASTVDP_DATA_AVL_RAW            VRX_BIT_FASTI2C_DATA_RDY_RAW
/*==========================================
 * Non- Supported APIs on ADV7842
 *=========================================*/
#define HAL_RXLIB_SdpVdpIsr()                   (ATVERR_OK)
#define HAL_RxSdpVdpGetInterrupts(a)            (ATVERR_NOT_AVAILABLE)
#define HAL_RxSdpVdpSetEnabledEvents(a,b,c)

#define HAL_RxCpSetSignalPolarity(a, b)         (ATVERR_NOT_AVAILABLE) 

#define HAL_SetSdpPixelClkFreq(a,b)             (ATVERR_NOT_AVAILABLE)
#define HAL_SetSdpOutputPixelFormat(a,b)        (ATVERR_NOT_AVAILABLE)
#define HAL_SetSdpVidStd(a)                     (ATVERR_NOT_AVAILABLE)
#define HAL_SetSdpEnManAinMux(a)                (ATVERR_NOT_AVAILABLE)
#define HAL_EnExtBiasing(a)                     (ATVERR_NOT_AVAILABLE)
#define HAL_EnSdp3dDnr(a)                       (ATVERR_NOT_AVAILABLE)

#define HAL_RxDppEnDcmStageManMode(a)           (ATVERR_NOT_AVAILABLE) 
#define HAL_RxDppEnDppStageManMode(a)           (ATVERR_NOT_AVAILABLE)
#define HAL_RxDppEnChromaFiltManMode(a)         (ATVERR_NOT_AVAILABLE)
#define HAL_RxDppSetDcmResponse(a)              (ATVERR_NOT_AVAILABLE) 
#define HAL_RxDppSetDppResponse(a)              (ATVERR_NOT_AVAILABLE)
#define HAL_RxDppSetDppCoeffs(a,b)              (ATVERR_NOT_AVAILABLE)
#define HAL_RxDppSetChromaResponse(a)           (ATVERR_NOT_AVAILABLE)
#define HAL_RxDppSetChromaBandwidth(a)          (ATVERR_NOT_AVAILABLE)
#define VRX_set_NEW_TMDS_PARAM(a)
#define HAL_RxHdmiSetEthernetPath(a,b,c)        (ATVERR_NOT_AVAILABLE)

#define HAL_RxSetAudioPassThrough(a)           (ATVERR_NOT_AVAILABLE)
#define HAL_RxHdmiSetArcMode(a, b)             (ATVERR_NOT_AVAILABLE)
/*====================================================================
 * All Audio Codec APIs are not supported on ADV7844/2 Devices
 *===================================================================*/
#define HAL_RxCdecHouseKeeping ()
#define HAL_RxCdecConfig(a)                         (ATVERR_NOT_AVAILABLE)
#define HAL_RxCdecRouteAudInToTx(a,b)                 (ATVERR_NOT_AVAILABLE)
#define HAL_RxCdecRouteAudInToAudLoopback(a,b,c)    (ATVERR_NOT_AVAILABLE)
#define HAL_RxCdecConfigAudioOut(a,b)             (ATVERR_NOT_AVAILABLE)
#define HAL_RxCdecSetVolume(a,b)                    (ATVERR_NOT_AVAILABLE)
#define HAL_RxCdecSetMute(a,b)                      (ATVERR_NOT_AVAILABLE)
/*====================================================================
 * The Following SPI Edid APIs are not supported on ADV7844/2 Devices
 *===================================================================*/
#define HAL_RxEdidCfgSpiInterface(a,b)  (ATVERR_NOT_AVAILABLE)
#define HAL_RxEdidCfgSpiHeader(a)  (ATVERR_NOT_AVAILABLE)
/*====================================================================
 * All Video Output Mux APIs are not supported on 5G Devices
 *===================================================================*/
#define HAL_RxAfeSetVideoOutMux(a,b)              (ATVERR_NOT_AVAILABLE)
/*====================================================================
 * VDP SPI Interface is not supported on ADV7844/2 Devices
 *===================================================================*/
#define HAL_RxVdpCfgSpiInterface(a,b)              (ATVERR_NOT_AVAILABLE) 
/*===========================================
 * Port C& D Non- Supported APIs on ADV7842
 *==========================================*/
#define VRX_REG_PORT_B_CHECKSUM         (VRX_REG_PORT_C_CHECKSUM - 1)
#define VRX_BIT_EDID_D_ENABLE           0x0
#define VRX_BIT_EDID_C_ENABLE           0x0
#define VRX_BIT_TMDS_CLK_C_MB1          0x0
#define VRX_BIT_TMDS_CLK_D_MB1          0x0
#define VRX_BIT_CABLE_DET_C_MB1         0x0
#define VRX_BIT_CABLE_DET_D_MB1         0x0
#define VRX_BIT_TMDSPLL_LCK_C_MB1       0x0
#define VRX_BIT_TMDSPLL_LCK_D_MB1       0x0
#define VRX_BIT_TMDS_CLK_C_MB2          0x0
#define VRX_BIT_TMDS_CLK_D_MB2          0x0
#define VRX_BIT_CABLE_DET_C_MB2         0x0
#define VRX_BIT_CABLE_DET_D_MB2         0x0
#define VRX_BIT_TMDSPLL_LCK_C_MB2       0x0
#define VRX_BIT_TMDSPLL_LCK_D_MB2       0x0
#define VRX_BIT_HDMI_ENCRPT_C_MB1       0x0 
#define VRX_BIT_HDMI_ENCRPT_D_MB1       0x0
#define VRX_BIT_HDMI_ENCRPT_C_MB2       0x0
#define VRX_BIT_HDMI_ENCRPT_D_MB2       0x0
#define VRX_BIT_AKSV_UPDATE_C_MB1       0x0
#define VRX_BIT_AKSV_UPDATE_D_MB1       0x0
#define VRX_BIT_AKSV_UPDATE_C_MB2       0x0
#define VRX_BIT_AKSV_UPDATE_D_MB2       0x0
#define VRX_BIT_TMDS_CLK_C_ST           0x0
#define VRX_BIT_TMDS_CLK_D_ST           0x0
#define VRX_BIT_CABLE_DET_C_ST          0x0
#define VRX_BIT_CABLE_DET_D_ST          0x0
#define VRX_BIT_TMDSPLL_LCK_C_ST        0x0
#define VRX_BIT_TMDSPLL_LCK_D_ST        0x0
#define VRX_BIT_HDMI_ENCRPT_C_ST        0x0
#define VRX_BIT_HDMI_ENCRPT_D_ST        0x0
#define VRX_BIT_AKSV_UPDATE_C_ST        0x0
#define VRX_BIT_AKSV_UPDATE_D_ST        0x0

#undef  VRX_get_HDCP_MAP_SELECT
#undef  VRX_ret_HDCP_MAP_SELECT
#undef  VRX_set_HDCP_MAP_SELECT
#define VRX_get_HDCP_MAP_SELECT(pval)  *pval=VRX_ret_HDCP_MAP_SELECT()
#define VRX_ret_HDCP_MAP_SELECT()      (ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x7F, 0x3, 0) & 1)
#define VRX_set_HDCP_MAP_SELECT(val)   ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x7F, 0x3, 0, val | 2)

#undef  VRX_get_HDMI_PORT_SELECT
#undef  VRX_ret_HDMI_PORT_SELECT
#undef  VRX_set_HDMI_PORT_SELECT
#define VRX_get_HDMI_PORT_SELECT(pval)  *pval=VRX_ret_HDMI_PORT_SELECT()
#define VRX_ret_HDMI_PORT_SELECT()      (ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x00, 0x3, 0) & 1)
#define VRX_set_HDMI_PORT_SELECT(val)   ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x00, 0x3, 0, val | 2)

#undef  VRX_set_SPA_PORT_1
#undef  VRX_set_SPA_PORT_2
#undef  VRX_set_SPA_PORT_3
#define VRX_set_SPA_PORT_1              VRX_set_SPA_PORT_A
#define VRX_set_SPA_PORT_2              VRX_set_SPA_PORT_B
#define VRX_set_SPA_PORT_3(a)

#undef  VRX_ret_SPA_PORT_1
#undef  VRX_ret_SPA_PORT_2
#undef  VRX_ret_SPA_PORT_3
#define VRX_ret_SPA_PORT_1              VRX_ret_SPA_PORT_A
#define VRX_ret_SPA_PORT_2              VRX_ret_SPA_PORT_B
#define VRX_ret_SPA_PORT_3()            0

#define VRX_ret_TMDSPLL_LCK_C_RAW()     0
#define VRX_ret_TMDSPLL_LCK_D_RAW()     0
#define VRX_ret_HDMI_ENCRPT_C_RAW()     0
#define VRX_ret_HDMI_ENCRPT_D_RAW()     0
#define VRX_ret_AKSV_UPDATE_C_RAW()     0
#define VRX_ret_AKSV_UPDATE_D_RAW()     0
#define VRX_set_EN_BG_PORT_C(a)         
#define VRX_set_EN_BG_PORT_D(a)         
#define VRX_set_HPA_MAN_VALUE_C(a)      
#define VRX_set_HPA_MAN_VALUE_D(a)      
#define VRX_ret_HPA_STATUS_PORT_C()     FALSE
#define VRX_ret_HPA_STATUS_PORT_D()     FALSE
#define VRX_is_TMDS_CLK_C_RAW_true()    FALSE   
#define VRX_is_TMDS_CLK_D_RAW_true()    FALSE
#define VRX_is_CABLE_DET_C_RAW_true()   FALSE
#define VRX_is_CABLE_DET_D_RAW_true()   FALSE
#define VRX_set_CLOCK_TERMC_DISABLE(a)  
#define VRX_set_CLOCK_TERMD_DISABLE(a)  
#define VRX_ret_CLOCK_TERMC_DISABLE()   FALSE
#define VRX_ret_CLOCK_TERMD_DISABLE()   FALSE       



/*==========================================
 * To be added to library
 *=========================================*/
#define VRX_set_VOLTAGE_CLAMP_EN(a)
#define VRX_set_CURRENT_CLAMP_EN(a)
#define VRX_set_FORCE_GEAR_A(val)               ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x61, 0x10, 0x4, val)
#define VRX_set_FORCE_GEAR_B(val)               ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x61, 0x01, 0x0, val)
#define VRX_set_FORCE_GEAR_C(val)               
#define VRX_set_FORCE_GEAR_D(val)               
#define VRX_ret_GEAR_A_RB()                     ATV_I2CReadField8(VRX_HDMI_MAP_ADDR,  0x63, 0xE0, 3)
#define VRX_ret_GEAR_B_RB()                     ATV_I2CReadField8(VRX_HDMI_MAP_ADDR,  0x63, 0x1C, 3)
#define VRX_ret_GEAR_C_RB()                     0
#define VRX_ret_GEAR_D_RB()                     0
#define VRX_set_FULL_PWR_BG_PORT_A(val)         ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x0D, 0x20, 0x5, val)
#define VRX_set_FULL_PWR_BG_PORT_B(val)         ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x0D, 0x10, 0x4, val)
#define VRX_set_FULL_PWR_BG_PORT_C(val)         
#define VRX_set_FULL_PWR_BG_PORT_D(val)         
#define VRX_set_FR_BG_PORTS(val)                ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x44, 0x80, 0x7, val)
#define VRX_set_NEW_VS_PARAM(val)               ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x4C, 0x04, 0x2, val)
#define VRX_set_TMDSPLL_GEAR_MON(val)           ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x3D, 0x10, 0x4, val)

#define VRX_is_LLC_DLL_DOUBLE_true()            ATV_I2CIsField8(VRX_IO_MAP_ADDR, 0x19, 0x40, 0x6)
#define VRX_get_LLC_DLL_DOUBLE_EN(pval)         ATV_I2CGetField8(VRX_IO_MAP_ADDR, 0x19, 0x40, 0x6, pval)
#define VRX_ret_LLC_DLL_DOUBLE_EN()             ATV_I2CReadField8(VRX_IO_MAP_ADDR, 0x19, 0x40, 0x6)
#define VRX_set_LLC_DLL_DOUBLE_EN(val)          ATV_I2CWriteField8(VRX_IO_MAP_ADDR, 0x19, 0x40, 0x6, val)
/*==========================================
 * ADV7623- ADV7844 Direct Mapping
 *=========================================*/
#define VRX_set_HPD_MANUAL(a)           VRX_set_HPA_MANUAL(a)

/*==========================================
 * Prototypes
 *=========================================*/

#endif

#endif
