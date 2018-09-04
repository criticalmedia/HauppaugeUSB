/**********************************************************************************************
*																						      *
* Copyright (c) 2012 Analog Devices, Inc.  All Rights Reserved.                               *
* This software is proprietary and confidential to Analog Devices, Inc. and its licensors.    *
*                                                                                             *
***********************************************************************************************/

/*============================================================================
 * This file contains all functions that are 4G family specific
 *
 *===========================================================================*/
#include "rx_lib.h"

#if ((RX_DEVICE == 7844) || (RX_DEVICE == 7842) \
    || (RX_DEVICE == 7623) || (RX_DEVICE == 7622) || (RX_DEVICE == 7850) || (RX_DEVICE == 76221))
   

#include "rx_isr.h"

CONSTANT MASK_INFO RxMaskInfo[] =
{
    { RX_EVENT_HDMI_AVI_INFO,     
        LVL_MASK_B1, {VRX_BIT_AVI_INFO_MB1,       VRX_BIT_AVI_INFO_MB2}, 
        EDG_MASK_B1, {VRX_BIT_NEW_AVI_INFO_MB1,   VRX_BIT_NEW_AVI_INFO_MB2}
    },
    { RX_EVENT_HDMI_AUDIO_INFO,
        LVL_MASK_B1, {VRX_BIT_AUDIO_INFO_MB1,     VRX_BIT_AUDIO_INFO_MB2},
        EDG_MASK_B1, {VRX_BIT_NEW_AUDIO_INFO_MB1, VRX_BIT_NEW_AUDIO_INFO_MB2}
    },
    { RX_EVENT_HDMI_SPD_INFO,
        LVL_MASK_B1, {VRX_BIT_SPD_INFO_MB1,       VRX_BIT_SPD_INFO_MB2},
        EDG_MASK_B1, {VRX_BIT_NEW_SPD_INFO_MB1,   VRX_BIT_NEW_SPD_INFO_MB2},
    },
    { RX_EVENT_HDMI_MS_INFO,
        LVL_MASK_B1, {VRX_BIT_MS_INFO_MB1,        VRX_BIT_MS_INFO_MB2},
        EDG_MASK_B1, {VRX_BIT_NEW_MS_INFO_MB1,    VRX_BIT_NEW_MS_INFO_MB2},
    },
    { RX_EVENT_HDMI_VS_INFO,
        LVL_MASK_B1, {VRX_BIT_VS_INFO_MB1,        VRX_BIT_VS_INFO_MB2},
        EDG_MASK_B1, {VRX_BIT_NEW_VS_INFO_MB1,    VRX_BIT_NEW_VS_INFO_MB2},
    },
    { RX_EVENT_HDMI_ACP_PCKT,
        LVL_MASK_B1, {VRX_BIT_ACP_PCKT_MB1,       VRX_BIT_ACP_PCKT_MB2},
        EDG_MASK_B1, {VRX_BIT_NEW_ACP_PCKT_MB1,   VRX_BIT_NEW_ACP_PCKT_MB2},
    },
    { RX_EVENT_HDMI_ISRC1_PCKT,
        LVL_MASK_B1, {VRX_BIT_ISRC1_PCKT_MB1,     VRX_BIT_ISRC1_PCKT_MB2},
        EDG_MASK_B1, {VRX_BIT_NEW_ISRC1_PCKT_MB1, VRX_BIT_NEW_ISRC1_PCKT_MB2},
    },
    { RX_EVENT_HDMI_ISRC2_PCKT,
        LVL_MASK_B1, {VRX_BIT_ISRC2_PCKT_MB1,     VRX_BIT_ISRC2_PCKT_MB2},
        EDG_MASK_B1, {VRX_BIT_NEW_ISRC2_PCKT_MB1, VRX_BIT_NEW_ISRC2_PCKT_MB2},
    },
    { RX_EVENT_HDMI_GAMUT_PCKT,
        LVL_MASK_B2, {VRX_BIT_GAMUT_MDATA_MB1,    VRX_BIT_GAMUT_MDATA_MB2},
        EDG_MASK_B2, {VRX_BIT_NEW_GAMUT_MDATA_MB1,VRX_BIT_NEW_GAMUT_MDATA_MB2},
    },
    { RX_EVENT_HDMI_NO_PACKET, 
        LVL_MASK_B1, {0,                          0},
        0xff, {0, 0}
    },
    { RX_EVENT_HDMI_AV_MUTE,
        LVL_MASK_B2, {VRX_BIT_AV_MUTE_MB1,        VRX_BIT_AV_MUTE_MB2},
        0xff, {0, 0}
    },

    { RX_EVENT_HDMI_N_CHNG, 
        EDG_MASK_B2, {VRX_BIT_CHANGE_N_MB1,       VRX_BIT_CHANGE_N_MB2},
        0xff, {0, 0}
    },
    { RX_EVENT_HDMI_CTS_PASS_THRSH, 
        EDG_MASK_B2, {VRX_BIT_CTS_PASS_THRSH_MB1, VRX_BIT_CTS_PASS_THRSH_MB2},
        0xff, {0, 0}
    },
    { RX_EVENT_HDMI_FIFO_OVERFLO,
        EDG_MASK_B2, {VRX_BIT_FIFO_OVERFLO_MB1,   VRX_BIT_FIFO_OVERFLO_MB2},
        0xff, {0, 0}
    },
    { RX_EVENT_HDMI_FIFO_UNDERFLO,
        EDG_MASK_B2, {VRX_BIT_FIFO_UNDERFLO_MB1,  VRX_BIT_FIFO_UNDERFLO_MB2},
        0xff, {0, 0}
    },
    { RX_EVENT_HDMI_FIFO_NEAROVFL,
        EDG_MASK_B2, {VRX_BIT_FIFO_NEAR_OVFL_MB1, VRX_BIT_FIFO_NEAR_OVFL_MB2},
        0xff, {0, 0}
    },
    { RX_EVENT_HDMI_FIFO_NEARUFLO,
        EDG_MASK_B3, {VRX_BIT_FIFO_NEAR_UFLO_MB1, VRX_BIT_FIFO_NEAR_UFLO_MB2},
        0xff, {0, 0}
    },
    { RX_EVENT_HDMI_AUDIO_MODE_CHNG,
        EDG_MASK_B3, {VRX_BIT_AUDIO_MODE_CHANGE_MB1, VRX_BIT_AUDIO_MODE_CHANGE_MB2},
        0xff, {0, 0}
    },
    { RX_EVENT_HDMI_AUDIO_CH_MODE_CHNG,
        LVL_MASK_B2, {VRX_BIT_AUDIO_CH_MD_MB1,    VRX_BIT_AUDIO_CH_MD_MB2},
        0xff, {0, 0}
    },
    { RX_EVENT_HDMI_INTERNAL_MUTE,
        LVL_MASK_B2, {VRX_BIT_INTERNAL_MUTE_MB1,  VRX_BIT_INTERNAL_MUTE_MB2},
        0xff, {0, 0}
    },
    { RX_EVENT_HDMI_CS_DATA_VALID,
        LVL_MASK_B2, {VRX_BIT_CS_DATA_VALID_MB1,  VRX_BIT_CS_DATA_VALID_MB2},
        0xff, {0, 0}
    },
    { RX_EVENT_HDMI_AUDIO_FLT_LINE,
        EDG_MASK_B3, {VRX_BIT_AUDIO_FLT_LINE_MB1, VRX_BIT_AUDIO_FLT_LINE_MB2},
        0xff, {0, 0}
    },
    { RX_EVENT_HDMI_NEW_SAMP_RT,
        EDG_MASK_B3, {VRX_BIT_NEW_SAMP_RT_MB1,    VRX_BIT_NEW_SAMP_RT_MB2},
        0xff, {0, 0}
    },
    { RX_EVENT_HDMI_PARITY_ERR,
        EDG_MASK_B3, {VRX_BIT_PARITY_ERROR_MB1,   VRX_BIT_PARITY_ERROR_MB2},
        0xff, {0, 0}
    },

    { RX_EVENT_HDMI_TMDS_CLK_CHNG,
        LVL_MASK_B3, {VRX_BIT_TMDS_CLK_A_MB1 | VRX_BIT_TMDS_CLK_B_MB1 |
                     VRX_BIT_TMDS_CLK_C_MB1 | VRX_BIT_TMDS_CLK_D_MB1,
                     VRX_BIT_TMDS_CLK_A_MB2 | VRX_BIT_TMDS_CLK_B_MB2 |
                     VRX_BIT_TMDS_CLK_C_MB2 | VRX_BIT_TMDS_CLK_D_MB2},
        0xff, {0, 0}
    },
    { RX_EVENT_HDMI_CABLE_DETECT,
        LVL_MASK_B4, {VRX_BIT_CABLE_DET_A_MB1 | VRX_BIT_CABLE_DET_B_MB1 |
                     VRX_BIT_CABLE_DET_C_MB1 | VRX_BIT_CABLE_DET_D_MB1,
                     VRX_BIT_CABLE_DET_A_MB2 | VRX_BIT_CABLE_DET_B_MB2 |
                     VRX_BIT_CABLE_DET_C_MB2 | VRX_BIT_CABLE_DET_D_MB2},
        0xff, {0, 0}
    },
    { RX_EVENT_HDMI_VIDEO_PLL_LCK,
       LVL_MASK_B3, {VRX_BIT_TMDSPLL_LCK_A_MB1 | VRX_BIT_TMDSPLL_LCK_B_MB1 |
                    VRX_BIT_TMDSPLL_LCK_C_MB1 | VRX_BIT_TMDSPLL_LCK_D_MB1,
                    VRX_BIT_TMDSPLL_LCK_A_MB2 | VRX_BIT_TMDSPLL_LCK_B_MB2 |
                    VRX_BIT_TMDSPLL_LCK_C_MB2 | VRX_BIT_TMDSPLL_LCK_D_MB2},
        0xff, {0, 0}
    },
    { RX_EVENT_HDMI_DE_REGEN_LCK,
        LVL_MASK_B5, {VRX_BIT_DE_REGEN_LCK_MB1,   VRX_BIT_DE_REGEN_LCK_MB2},
        0xff, {0, 0}
    },
    { RX_EVENT_HDMI_V_LOCKED,
        LVL_MASK_B5, {VRX_BIT_V_LOCKED_MB1,       VRX_BIT_V_LOCKED_MB2},
        0xff, {0, 0}
    },
    { RX_EVENT_HDMI_ENC_CHNG,
        LVL_MASK_B4, {VRX_BIT_HDMI_ENCRPT_A_MB1 | VRX_BIT_HDMI_ENCRPT_B_MB1 |
                     VRX_BIT_HDMI_ENCRPT_C_MB1 | VRX_BIT_HDMI_ENCRPT_D_MB1,
                     VRX_BIT_HDMI_ENCRPT_A_MB2 | VRX_BIT_HDMI_ENCRPT_B_MB2 |
                     VRX_BIT_HDMI_ENCRPT_C_MB2 | VRX_BIT_HDMI_ENCRPT_D_MB2},
        0xff, {0, 0}
    },
    { RX_EVENT_HDMI_MODE_CHNG,
        LVL_MASK_B2, {VRX_BIT_HDMI_MODE_MB1,      VRX_BIT_HDMI_MODE_MB2},
        0xff, {0, 0}
    },
    { RX_EVENT_HDMI_NEW_TMDS_FRQ,
        EDG_MASK_B3, {VRX_BIT_NEW_TMDS_FRQ_MB1,   VRX_BIT_NEW_TMDS_FRQ_MB2},
        0xff, {0, 0}
    },
    { RX_EVENT_HDMI_AKSV_UPDATE,
        EDG_MASK_B4, {VRX_BIT_AKSV_UPDATE_A_MB1 | VRX_BIT_AKSV_UPDATE_B_MB1 |
                     VRX_BIT_AKSV_UPDATE_C_MB1 | VRX_BIT_AKSV_UPDATE_D_MB1,
                     VRX_BIT_AKSV_UPDATE_A_MB2 | VRX_BIT_AKSV_UPDATE_B_MB2 |
                     VRX_BIT_AKSV_UPDATE_C_MB2 | VRX_BIT_AKSV_UPDATE_D_MB2},
        0xff, {0, 0}
    },
    { RX_EVENT_HDMI_VCLK_CHNG,
        EDG_MASK_B3, {VRX_BIT_VCLK_CHNG_MB1,      VRX_BIT_VCLK_CHNG_MB2},
        0xff, {0, 0}
    },
    { RX_EVENT_HDMI_DEEP_COLOR_CHNG,
        EDG_MASK_B3, {VRX_BIT_DEEP_COLOR_CHNG_MB1,VRX_BIT_DEEP_COLOR_CHNG_MB2},
        0xff, {0, 0}
    },
    { RX_EVENT_HDMI_3D_PACKET, 
        LVL_MASK_B1, {0,                          0},
        0xff, {0, 0}
    },
    { RX_EVENT_HDMI_NO_3D_PACKET, 
        LVL_MASK_B1, {0,                          0},
        0xff, {0, 0}
    },
#if RX_INCLUDE_CEC
    { RX_EVENT_CEC_RX_MSG,
        INT_MASK_B3, {VRX_BIT_CEC_RX_RDY0_MB1, VRX_BIT_CEC_RX_RDY0_MB2},
        0xff, {0, 0}
    },
    { RX_EVENT_CEC_TX_DONE,
        INT_MASK_B3, {VRX_BIT_CEC_TX_READY_MB1, VRX_BIT_CEC_TX_READY_MB2},
        0xff, {0, 0}
    },
    { RX_EVENT_CEC_TX_ARB_LOST,
        INT_MASK_B3, {VRX_BIT_CEC_TX_ARBITRATION_LOST_MB1, VRX_BIT_CEC_TX_ARBITRATION_LOST_MB2},
        0xff, {0, 0}
    },
    { RX_EVENT_CEC_TX_TIMEOUT,
        INT_MASK_B3, {VRX_BIT_CEC_TX_RETRY_TIMEOUT_MB1, VRX_BIT_CEC_TX_RETRY_TIMEOUT_MB2},
        0xff, {0, 0}
    },
    { RX_EVENT_CEC_LOG_ADDR_ALLOC,
        INT_MASK_B3, {VRX_BIT_CEC_RX_RDY0_MB1             | VRX_BIT_CEC_TX_READY_MB1 | 
                      VRX_BIT_CEC_TX_ARBITRATION_LOST_MB1 | VRX_BIT_CEC_TX_RETRY_TIMEOUT_MB1,
                      VRX_BIT_CEC_RX_RDY0_MB2             | VRX_BIT_CEC_TX_READY_MB2 | 
                      VRX_BIT_CEC_TX_ARBITRATION_LOST_MB2 | VRX_BIT_CEC_TX_RETRY_TIMEOUT_MB2},
        0xff, {0, 0}
    },
    { RX_EVENT_CEC_LOG_ADDR_LIST,
        INT_MASK_B3, {VRX_BIT_CEC_RX_RDY0_MB1             | VRX_BIT_CEC_TX_READY_MB1 | 
                      VRX_BIT_CEC_TX_ARBITRATION_LOST_MB1 | VRX_BIT_CEC_TX_RETRY_TIMEOUT_MB1,
                      VRX_BIT_CEC_RX_RDY0_MB2             | VRX_BIT_CEC_TX_READY_MB2 | 
                      VRX_BIT_CEC_TX_ARBITRATION_LOST_MB2 | VRX_BIT_CEC_TX_RETRY_TIMEOUT_MB2},
        0xff, {0, 0}
    },
    { RX_EVENT_CEC_RX_MSG_RESPOND,
        INT_MASK_B3, {VRX_BIT_CEC_RX_RDY0_MB1             | VRX_BIT_CEC_TX_READY_MB1 | 
                      VRX_BIT_CEC_TX_ARBITRATION_LOST_MB1 | VRX_BIT_CEC_TX_RETRY_TIMEOUT_MB1,
                      VRX_BIT_CEC_RX_RDY0_MB2             | VRX_BIT_CEC_TX_READY_MB2 | 
                      VRX_BIT_CEC_TX_ARBITRATION_LOST_MB2 | VRX_BIT_CEC_TX_RETRY_TIMEOUT_MB2},
        0xff, {0, 0}
    },    
#endif
    { RX_EVENT_CP_LCK,     
        INT_MASK_B1, {VRX_BIT_CP_LOCK_MB1,       VRX_BIT_CP_LOCK_MB2}, 
        INT_MASK_B1, {VRX_BIT_CP_UNLOCK_MB1,     VRX_BIT_CP_UNLOCK_MB2}, 
    },
    { RX_EVENT_CP_STDI_LCK,
        INT_MASK_B1, {VRX_BIT_STDI_DATA_VALID_MB1, VRX_BIT_STDI_DATA_VALID_MB2},
        0xff, {0, 0}
    },
    { RX_EVENT_CP_LCK_SYNC_CH1,
        INT_MASK_B6, {VRX_BIT_CP_LOCK_CH1_MB1,   VRX_BIT_CP_LOCK_CH1_MB2}, 
        INT_MASK_B6, {VRX_BIT_CP_UNLOCK_CH1_MB1, VRX_BIT_CP_UNLOCK_CH1_MB2}, 
    },
    { RX_EVENT_CP_STDI_LCK_SYNC_CH1,
        INT_MASK_B6, {VRX_BIT_STDI_DVALID_CH1_MB1, VRX_BIT_STDI_DVALID_CH1_MB2},
        0xff, {0, 0}
    },
    { RX_EVENT_CP_LCK_SYNC_CH2,
        INT_MASK_B6, {VRX_BIT_CP_LOCK_CH2_MB1,   VRX_BIT_CP_LOCK_CH2_MB2}, 
        INT_MASK_B6, {VRX_BIT_CP_UNLOCK_CH2_MB1, VRX_BIT_CP_UNLOCK_CH2_MB2}, 
    },
    { RX_EVENT_CP_STDI_LCK_SYNC_CH2,
        INT_MASK_B6, {VRX_BIT_STDI_DVALID_CH2_MB1, VRX_BIT_STDI_DVALID_CH2_MB2},
        0xff, {0, 0}
    },
#if (RX_DEVICE==7844 || RX_DEVICE ==7842 || RX_DEVICE ==7850)
    { RX_EVENT_VDP_TTXT,
        INT_MASK_B4, {VRX_BIT_TTXT_AVL_MB1, VRX_BIT_TTXT_AVL_MB2},
        0xff, {0, 0}
    },    
    { RX_EVENT_VDP_VITC,
        INT_MASK_B4, {VRX_BIT_VITC_AVL_MB1, VRX_BIT_VITC_AVL_MB2},
        0xff, {0, 0}
    },
    { RX_EVENT_VDP_GPVUC,
        INT_MASK_B4, {VRX_BIT_GS_PDC_VPS_UTC_AVL_MB1, VRX_BIT_GS_PDC_VPS_UTC_AVL_MB2},
        INT_MASK_B4, {VRX_BIT_GS_DATA_TYPE_MB1, VRX_BIT_GS_DATA_TYPE_MB2}
    },
    { RX_EVENT_VDP_CGMS_WSS,
        INT_MASK_B4, {VRX_BIT_CGMS_WSS_AVL_MB1, VRX_BIT_CGMS_WSS_AVL_MB2},
        0xff, {0, 0}
    },
    { RX_EVENT_VDP_CCAP,
        INT_MASK_B4, {VRX_BIT_CCAP_AVL_MB1, VRX_BIT_CCAP_AVL_MB2},
        INT_MASK_B4, {VRX_BIT_CCAP_EVEN_FIELD_MB1, VRX_BIT_CCAP_EVEN_FIELD_MB2}
    },
    { RX_EVENT_VDP_FAST_DATARB_RDY,
        INT_MASK_B4, {VRX_BIT_FASTVDP_DATA_AVL_MB1, VRX_BIT_FASTVDP_DATA_AVL_MB2},
        0xff, {0, 0}
    },
    { RX_EVENT_SDP_VIDEO_DET,
        SDP_MASK_B1, {VRX_BIT_SDP_VIDEO_DETECTED_MB1, VRX_BIT_SDP_VIDEO_DETECTED_MB2},
        0xff, {0, 0}
    },
    { RX_EVENT_SDP_BURST_LCK,
        SDP_MASK_B1, {VRX_BIT_SDP_BURST_LOCKED_MB1, VRX_BIT_SDP_BURST_LOCKED_MB2},
        0xff, {0, 0}
    },
    { RX_EVENT_MV_PS_DET,
        MV_MASK_B2, {VRX_BIT_MV_PS_DET_MB1, VRX_BIT_MV_PS_DET_MB2},
        0xff, {0, 0}
    },
    { RX_EVENT_MV_AGC_DET,
        MV_MASK_B1, {VRX_BIT_MV_AGC_DET_MB1, VRX_BIT_MV_AGC_DET_MB2},
        0xff, {0, 0}
    },
    { RX_EVENT_MV_CS_DET,
        MV_MASK_B1, {VRX_BIT_MV_CS_DET_MB1, VRX_BIT_MV_CS_DET_MB2},
        0xff, {0, 0}
    },

#endif
    {
        (RX_EVENT)0xff, 
        0xff, {0, 0}, 
        0xff, {0, 0}
    }
};
ATV_ERR HAL_RxHdmiEnAudioClock (BOOL Enable)
{
    VRX_set_audio_core_pdn(!Enable);
    return ATVERR_OK;
}

#endif
