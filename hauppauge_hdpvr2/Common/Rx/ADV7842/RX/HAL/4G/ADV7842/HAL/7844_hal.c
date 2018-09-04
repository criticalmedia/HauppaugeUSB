/**********************************************************************************************
*																						      *
* Copyright (c) 2012 Analog Devices, Inc.  All Rights Reserved.                               *
* This software is proprietary and confidential to Analog Devices, Inc. and its licensors.    *
*                                                                                             *
***********************************************************************************************/

/*============================================================================
 * This file contains all functions that are chip-specific
 *
 *===========================================================================*/
#include "rx_lib.h"

#if (RX_DEVICE == 7844 || RX_DEVICE == 7842) /*NNIC details to be updated with 8x1*/

#include "rx_cfg.h"
#include "rx_isr.h"

/*======================================================================
 * ADV7844 Primary Mode & Video Standard Details 
 *======================================================================*/
#define RX_VFRQ_24_VAL            0x4
#define RX_VFRQ_25_VAL            0x3     
#define RX_VFRQ_30_VAL            0x2
#define RX_VFRQ_50_VAL            0x1
#define RX_VFRQ_60_VAL            0x0
#define RX_SDP_PRIM_MODE          0x0
#define RX_CMP_PRIM_MODE          0x1
#define RX_SDP_TBL_SIZE           4
#define RX_CMP_TBL_SIZE           12
#define RX_GR_TBL_SIZE            14
#define RX_HDMI_TBL_SIZE          25
#define RX_GR_PRIM_MODE           0x2
#define RX_GR_PM                  0x2
#define RX_SD_PM                  0x0
#define RX_HDMI_CMP_PM            0x5
#define RX_HDMI_GR_PM             0x6
#define RX_NOT_SUP                0xFF
#define RX_OS_NOT_SUP             0xFF
#define RX_FREQ_NOT_SUP           0xFF
#define RX_NO_CMP_FREQ            {FALSE,FALSE,FALSE,FALSE,FALSE}
#define RX_NO_CMP_VIDSTD          {RX_NOT_SUP,RX_NOT_SUP,RX_NOT_SUP,RX_NOT_SUP,RX_NOT_SUP} 
#define RX_NO_GR_VIDSTD           {RX_NOT_SUP,RX_NOT_SUP,RX_NOT_SUP,RX_NOT_SUP,RX_NOT_SUP, RX_NOT_SUP}
#define RX_AUTO_GRAPHICS_MODE     0x7

/*=======================================================================
 * Local constants
 *======================================================================*/
STATIC CONSTANT RX_SDP_VIDSTD_INFO SDPVidStdTable[RX_SDP_TBL_SIZE] =
{
    {RX_525I, {0x0,0x1}, {0x4,0x5},{0x8,0x9},{0xC,0xD},{0x10,0x11}},
    {RX_625I, {0x0,0x1}, {0x4,0x5},{0x8,0x9},{0xC,0xD},{0x10,0x11}},
    {RX_525P, {0x0,0x1}, {0x4,0x5},{0x8,0x9},{0xC,0xD},{0x10,0x11}},
    {RX_625I, {0x0,0x1}, {0x4,0x5},{0x8,0x9},{0xC,0xD},{0x10,0x11}}
};

STATIC CONSTANT RX_CMP_VIDSTD_INFO CmpVidStdTable[RX_CMP_TBL_SIZE] =
{    {RX_525I,          {RX_OS_NOT_SUP ,0x2,0x4,0x6,0x8},{FALSE,FALSE,FALSE,FALSE,TRUE}}, 
     {RX_625I,          {RX_OS_NOT_SUP,0x3,0x5,0x7,0x9},{FALSE,FALSE,FALSE,TRUE,FALSE}},
     {RX_525P,          {RX_OS_NOT_SUP,0xC,0XE,0x10,RX_OS_NOT_SUP},{FALSE,FALSE,FALSE,FALSE,TRUE}},
     {RX_625P,          {RX_OS_NOT_SUP,0xD,0XF,0x11,RX_OS_NOT_SUP},{FALSE,FALSE,FALSE,TRUE,TRUE}},
     {RX_720P,          {0x13,0x19,RX_OS_NOT_SUP,RX_OS_NOT_SUP,RX_OS_NOT_SUP},{TRUE,TRUE,TRUE,TRUE,TRUE}},
     {RX_1125I_274M,    {0x14,0x1A,RX_OS_NOT_SUP,RX_OS_NOT_SUP,RX_OS_NOT_SUP},{FALSE,FALSE,FALSE,TRUE,TRUE}},
     {RX_1125I_240M,    {0x15,0x1B,RX_OS_NOT_SUP,RX_OS_NOT_SUP,RX_OS_NOT_SUP},{FALSE,FALSE,FALSE,FALSE,TRUE}},
     {RX_1250I_295M,    {0x16,0x1C,RX_OS_NOT_SUP,RX_OS_NOT_SUP,RX_OS_NOT_SUP},{FALSE,FALSE,FALSE,FALSE,TRUE}},
     {RX_1920I_1152,    {0x17,0x1D,RX_OS_NOT_SUP,RX_OS_NOT_SUP,RX_OS_NOT_SUP},{FALSE,FALSE,FALSE,FALSE,TRUE}},
     {RX_1125P_274M,    {0x1E,RX_OS_NOT_SUP,RX_OS_NOT_SUP,RX_OS_NOT_SUP,RX_OS_NOT_SUP},{TRUE,TRUE,TRUE,TRUE,TRUE}},
     {RX_1250P_295M,    {0x1F,RX_OS_NOT_SUP,RX_OS_NOT_SUP,RX_OS_NOT_SUP,RX_OS_NOT_SUP},{FALSE,FALSE,FALSE,FALSE,TRUE}},
     {RX_1125P_RB,      {0x34,RX_OS_NOT_SUP,RX_OS_NOT_SUP,RX_OS_NOT_SUP,RX_OS_NOT_SUP},{FALSE,FALSE,FALSE,FALSE,TRUE}}   
};

STATIC CONSTANT RX_GR_VIDSTD_INFO GrVidStdTable[RX_GR_TBL_SIZE] =
{    {RX_SVGA,      {0x0,0x1,RX_FREQ_NOT_SUP,0x2,0x3,0x4}},
     {RX_SXGA,      {RX_FREQ_NOT_SUP,0x5,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP,0x6,RX_FREQ_NOT_SUP}},
     {RX_VGA,       {RX_FREQ_NOT_SUP,0x8,RX_FREQ_NOT_SUP,0x9,0xA,0xB}},
     {RX_XGA,       {RX_FREQ_NOT_SUP,0xC,0xD,RX_OS_NOT_SUP,0xE,0xF}},
     {RX_WXGA,      {RX_FREQ_NOT_SUP,0x10,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP}},
     {RX_WXGAR,     {RX_FREQ_NOT_SUP,0x11,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP}},
     {RX_WXGA_1360, {RX_FREQ_NOT_SUP,0x12,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP}},
     {RX_WXGA_1366, {RX_FREQ_NOT_SUP,0x13,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP}},
     {RX_SXGAR,     {RX_FREQ_NOT_SUP,0x14,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP,0x15,RX_FREQ_NOT_SUP}},
     {RX_UXGA,      {RX_FREQ_NOT_SUP,0x16,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP,0x15,RX_FREQ_NOT_SUP}},
     {RX_UXGAR,     {RX_FREQ_NOT_SUP,0x17,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP,0x15,RX_FREQ_NOT_SUP}},
     {RX_WSXGA,     {RX_FREQ_NOT_SUP,0x18,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP,0x15,RX_FREQ_NOT_SUP}},
     {RX_SXGA_PLUS, {RX_FREQ_NOT_SUP,0x14,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP,0x15,RX_FREQ_NOT_SUP}},
     {RX_WUXGA,     {RX_FREQ_NOT_SUP,0x19,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP,0x15,RX_FREQ_NOT_SUP}}
};

STATIC CONSTANT RX_HDMI_VIDSTD_INFO HdmiVidStdTable[RX_HDMI_TBL_SIZE ] =
{    {RX_HDMI_GR_PM,  RX_SVGA,          {0x0,0x1,RX_OS_NOT_SUP,0x2,0x3,0x4},RX_NO_CMP_VIDSTD ,RX_NO_CMP_FREQ },
     {RX_HDMI_GR_PM,  RX_SXGA,          {RX_FREQ_NOT_SUP,0x5,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP,0x6,RX_FREQ_NOT_SUP},RX_NO_CMP_VIDSTD, RX_NO_CMP_FREQ },
     {RX_HDMI_GR_PM,  RX_VGA,           {RX_FREQ_NOT_SUP,0x8,RX_FREQ_NOT_SUP,0x9,0xA,0xB},RX_NO_CMP_VIDSTD,RX_NO_CMP_FREQ},
     {RX_HDMI_GR_PM,  RX_XGA,           {RX_FREQ_NOT_SUP,0xC,0xD,RX_OS_NOT_SUP,0xE,0xF},RX_NO_CMP_VIDSTD,RX_NO_CMP_FREQ },
     {RX_HDMI_GR_PM,  RX_WXGA,          {RX_FREQ_NOT_SUP,0x10,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP},RX_NO_CMP_VIDSTD, RX_NO_CMP_FREQ },
     {RX_HDMI_GR_PM,  RX_WXGAR,         {RX_FREQ_NOT_SUP,0x11,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP}, RX_NO_CMP_VIDSTD,RX_NO_CMP_FREQ },
     {RX_HDMI_GR_PM,  RX_WXGA_1360,     {RX_FREQ_NOT_SUP,0x12,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP},RX_NO_CMP_VIDSTD, RX_NO_CMP_FREQ },
     {RX_HDMI_GR_PM,  RX_WXGA_1366,     {RX_FREQ_NOT_SUP,0x13,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP},RX_NO_CMP_VIDSTD, RX_NO_CMP_FREQ },
     {RX_HDMI_GR_PM,  RX_SXGA_PLUS,     {RX_FREQ_NOT_SUP,0x14,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP,0x15,RX_FREQ_NOT_SUP},   RX_NO_CMP_VIDSTD,RX_NO_CMP_FREQ },
     {RX_HDMI_GR_PM,  RX_UXGA,          {RX_FREQ_NOT_SUP,0x16,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP,0x15,RX_FREQ_NOT_SUP}, RX_NO_CMP_VIDSTD,RX_NO_CMP_FREQ },
     {RX_HDMI_GR_PM,  RX_UXGAR,         {RX_FREQ_NOT_SUP,0x17,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP,0x15,RX_FREQ_NOT_SUP}, RX_NO_CMP_VIDSTD,RX_NO_CMP_FREQ },
     {RX_HDMI_GR_PM,  RX_WSXGA,         {RX_FREQ_NOT_SUP,0x18,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP,0x15,RX_FREQ_NOT_SUP}, RX_NO_CMP_VIDSTD,RX_NO_CMP_FREQ },
     {RX_HDMI_GR_PM,  RX_WUXGA,         {RX_FREQ_NOT_SUP,0x19,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP,0x15,RX_FREQ_NOT_SUP}, RX_NO_CMP_VIDSTD,RX_NO_CMP_FREQ },
     {RX_HDMI_CMP_PM, RX_525I,          RX_NO_GR_VIDSTD,{0x0 ,0x2,RX_OS_NOT_SUP,RX_OS_NOT_SUP,RX_OS_NOT_SUP},{FALSE,FALSE,FALSE,FALSE,TRUE}}, 
     {RX_HDMI_CMP_PM, RX_625I,          RX_NO_GR_VIDSTD,{0x1,0x3,RX_OS_NOT_SUP,RX_OS_NOT_SUP,RX_OS_NOT_SUP},{FALSE,FALSE,FALSE,TRUE,FALSE}},
     {RX_HDMI_CMP_PM, RX_525P,          RX_NO_GR_VIDSTD,{0x0A,0xC,RX_OS_NOT_SUP,RX_OS_NOT_SUP,RX_OS_NOT_SUP},{FALSE,FALSE,FALSE,FALSE,TRUE}},
     {RX_HDMI_CMP_PM, RX_625P,          RX_NO_GR_VIDSTD,{0x0B,0xD,RX_OS_NOT_SUP,RX_OS_NOT_SUP,RX_OS_NOT_SUP},{FALSE,FALSE,FALSE,TRUE,FALSE}},
     {RX_HDMI_CMP_PM, RX_720P,          RX_NO_GR_VIDSTD,{0x13,0x19,RX_OS_NOT_SUP,RX_OS_NOT_SUP,RX_OS_NOT_SUP},{FALSE,FALSE,TRUE,TRUE,TRUE}},
     {RX_HDMI_CMP_PM, RX_1125I_274M,    RX_NO_GR_VIDSTD,{0x14,0x1A,RX_OS_NOT_SUP,RX_OS_NOT_SUP,RX_OS_NOT_SUP},{FALSE,FALSE,FALSE,TRUE,TRUE}},
     {RX_HDMI_CMP_PM, RX_1125I_240M,    RX_NO_GR_VIDSTD,{0x15,0x1B,RX_OS_NOT_SUP,RX_OS_NOT_SUP,RX_OS_NOT_SUP},{FALSE,FALSE,FALSE,FALSE,TRUE}},
     {RX_HDMI_CMP_PM, RX_1250I_295M,    RX_NO_GR_VIDSTD,{0x16,0x1C,RX_OS_NOT_SUP,RX_OS_NOT_SUP,RX_OS_NOT_SUP},{FALSE,FALSE,FALSE,FALSE,TRUE}},
     {RX_HDMI_CMP_PM, RX_1920I_1152,    RX_NO_GR_VIDSTD,{0x17,0x1D,RX_OS_NOT_SUP,RX_OS_NOT_SUP,RX_OS_NOT_SUP},{FALSE,FALSE,FALSE,FALSE,TRUE}},
     {RX_HDMI_CMP_PM, RX_1125P_274M,    RX_NO_GR_VIDSTD,{0x1E,RX_OS_NOT_SUP,RX_OS_NOT_SUP,RX_OS_NOT_SUP,RX_OS_NOT_SUP},{TRUE,TRUE,TRUE,TRUE,TRUE}},
     {RX_HDMI_CMP_PM, RX_1250P_295M,    RX_NO_GR_VIDSTD,{0x1F,RX_OS_NOT_SUP,RX_OS_NOT_SUP,RX_OS_NOT_SUP,RX_OS_NOT_SUP},{FALSE,FALSE,FALSE,FALSE,TRUE}},
     {RX_HDMI_CMP_PM, RX_1125P_RB,      RX_NO_GR_VIDSTD,{0x34,RX_OS_NOT_SUP,RX_OS_NOT_SUP,RX_OS_NOT_SUP,RX_OS_NOT_SUP},{FALSE,FALSE,FALSE,FALSE,TRUE}},
};

CONSTANT UCHAR SdpSyncDefault[] =
{
    RX_I2C_SDP_IO_MAP_ADDR, 0xAA, 0x04,
    RX_I2C_SDP_IO_MAP_ADDR, 0xB0, 0xC0,
    0
};

CONSTANT UCHAR PalTo576i[] =
{
    RX_I2C_SDP_IO_MAP_ADDR, 0xAA, 0x05,
    RX_I2C_SDP_IO_MAP_ADDR, 0xB0, 0xCC,
    0
};

CONSTANT SDP_861_INFO Sdp861SettingsTable[] =
{
    {RX_PAL, 21, (UINT8*)PalTo576i, (UINT8*)PalTo576i},
    {RX_PALNC, 21, (UINT8*)PalTo576i, (UINT8*)PalTo576i},
    {RX_288P, 21, (UINT8*)PalTo576i, (UINT8*)PalTo576i},
    {RX_SECAM, 21, (UINT8*)PalTo576i, (UINT8*)PalTo576i},
    {RX_UNDEF_SDP_FORMAT, 0, (UINT8*)SdpSyncDefault, (UINT8*)SdpSyncDefault},
    {RX_UNDEF_SDP_FORMAT, 0, NULL, NULL}
};

STATIC CONSTANT UCHAR RxCeaId00RecSettingTable[] = 
{
    /*===============================
     * recommended sync 
     * adjustment settings
     * for 861 Vid = 0
     *==============================*/
    RX_I2C_CP_MAP_ADDR, 0x7C, 0xC0,     /*Default value*/
    RX_I2C_CP_MAP_ADDR, 0x7D, 0x00,     /*Default value*/
    RX_I2C_CP_MAP_ADDR, 0x7F, 0x00,     /*Default value*/
    RX_I2C_CP_MAP_ADDR, 0x88, 0x00,     /*Default value*/
    RX_I2C_CP_MAP_ADDR, 0x8B, 0x40,     /*Default value*/
    RX_I2C_CP_MAP_ADDR, 0x8C, 0x00,     /*Default value*/
    RX_I2C_CP_MAP_ADDR, 0x8B, 0x40,     /*Default value*/
    RX_I2C_CP_MAP_ADDR, 0x8D, 0x00,     /*Default value*/
    RX_I2C_CP_MAP_ADDR, 0x8E, 0x00,     /*Default value*/
    0
};

#if 0
STATIC CONSTANT UCHAR RxCeaId02RecSettingTable[] = 
{
    /*===============================
     * 480p recommended sync 
     * adjustment settings
     *==============================*/
    RX_I2C_CP_MAP_ADDR, 0x7C, 0xC3,    /*HS Adjustment*/
    RX_I2C_CP_MAP_ADDR, 0x7D, 0xFE,    /*HS Adjustment*/
    RX_I2C_CP_MAP_ADDR, 0x7F, 0x33,     /*VS Adjustment*/
    RX_I2C_CP_MAP_ADDR, 0x8B, 0x40,    /*Default value*/
    RX_I2C_CP_MAP_ADDR, 0x8C, 0x00,    /*Default value*/ 
    RX_I2C_CP_MAP_ADDR, 0x8B, 0x40,    /*Default value*/ /*Repeat write due to I2C sequencer*/
    RX_I2C_CP_MAP_ADDR, 0x8D, 0x00,    /*Default value*/
    RX_I2C_CP_MAP_ADDR, 0x8E, 0x03,    /*DE VS Adjustment*/
    0
};

STATIC CONSTANT UCHAR RxCeaId06RecSettingTable[] = 
{

    /*===============================
     * 480i recommended sync 
     * adjustment settings
     *==============================*/
    RX_I2C_CP_MAP_ADDR, 0x7C, 0xC3,     /*HS Adjustment*/
    RX_I2C_CP_MAP_ADDR, 0x7D, 0xFE,     /*HS ADJ*/
    RX_I2C_CP_MAP_ADDR, 0x7F, 0x00,     /*Default value*/
    RX_I2C_CP_MAP_ADDR, 0x8B, 0x4F,     /*DE HS ADJ*/
    RX_I2C_CP_MAP_ADDR, 0x8C, 0xFD,     /*DE HS ADJ*/
    RX_I2C_CP_MAP_ADDR, 0x8B, 0x4F,     /*DE HS ADJ*/
    RX_I2C_CP_MAP_ADDR, 0x8D, 0xFD,     /*DE HS ADJ*/
    RX_I2C_CP_MAP_ADDR, 0x8E, 0x00,     /*Default value*/
    0
};

STATIC CONSTANT UCHAR RxCeaId21RecSettingTable[] = 
{
    /*===============================
     * 576i recommended sync 
     * adjustment settings
     *==============================*/
    RX_I2C_CP_MAP_ADDR, 0x7C, 0xC3,     /*HS Adjustment*/
    RX_I2C_CP_MAP_ADDR, 0x7D, 0xFF,     /*HS Adjustment*/
    RX_I2C_CP_MAP_ADDR, 0x7F, 0x00,     /*Default value*/
    RX_I2C_CP_MAP_ADDR, 0x8B, 0x40,     /*Default value*/
    RX_I2C_CP_MAP_ADDR, 0x8C, 0x00,     /*Default value*/
    RX_I2C_CP_MAP_ADDR, 0x8B, 0x40,     /*Default value*/ /*Repeat write due to I2C sequencer*/
    RX_I2C_CP_MAP_ADDR, 0x8D, 0x00,     /*Default value*/
    RX_I2C_CP_MAP_ADDR, 0x8E, 0x00,     /*Default value*/
   0
};
#endif

CONSTANT UCHAR RxCpMaskRegs[] = 
{
    VRX_REG_INTERRUPT_MASKB_1, VRX_REG_INTERRUPT2_MASKB_1, INT_MASK_B1,
    VRX_REG_INTERRUPT_MASKB_2, VRX_REG_INTERRUPT2_MASKB_2, INT_MASK_B2,
    VRX_REG_INTERRUPT_MASKB_6, VRX_REG_INTERRUPT2_MASKB_6, INT_MASK_B6,
    0, 0
};

CONSTANT UCHAR RxSdpMaskRegs[] = 
{
    VRX_REG_SDP_INTERRUPT_MASKB, VRX_REG_SDP_INTERRUPT2_MASKB, SDP_MASK_B1,
    0, 0
};

CONSTANT UCHAR RxMvMaskRegs[] = 
{
    VRX_REG_INTERRUPT_MASKB_2, VRX_REG_INTERRUPT2_MASKB_2, MV_MASK_B1,
    VRX_REG_INTERRUPT_MASKB_1, VRX_REG_INTERRUPT2_MASKB_1, MV_MASK_B2, 
    0, 0
};

CONSTANT UCHAR SdpSdrMemCfg[] =
{
    RX_I2C_SDP_IO_MAP_ADDR,    0x74,   0x00,
    RX_I2C_SDP_IO_MAP_ADDR,    0x75,   0xE6,
    RX_I2C_SDP_IO_MAP_ADDR,    0x79,   0x33,
    RX_I2C_SDP_IO_MAP_ADDR,    0x7A,   0xA5,
    RX_I2C_SDP_IO_MAP_ADDR,    0x7B,   0x8F,
    RX_I2C_SDP_IO_MAP_ADDR,    0x6F,   0x01, 
    0
};

CONSTANT UCHAR SdpDdrMemCfg[] =
{
    RX_I2C_SDP_IO_MAP_ADDR,    0x74,   0x10,       /*return to default*/
    RX_I2C_SDP_IO_MAP_ADDR,    0x79,   0x63,       /*return to default*/
    RX_I2C_SDP_IO_MAP_ADDR,    0x6F,   0x00,       /*return to default*/
    RX_I2C_SDP_IO_MAP_ADDR,    0x7A,   0xA5,
    RX_I2C_SDP_IO_MAP_ADDR,    0x7B,   0x8F,
    0
};

/*===============================================
 * Local Function Prototypes
 *==============================================*/
void RxSetSpecificResCnfg(UINT8 PrimMode, RX_VID_RES Res );
void RxRstSpecificResCnfg(void);
BOOL RxGetCmpVidStdCfg(UINT8 Index,RX_VRT_FRQ Freq,RX_OS_RATE OvrSmplng, UINT8* VidStd,UINT8 *VFreq);
BOOL RxGetGrVidStdCfg(UINT8 Index,RX_VRT_FRQ Freq, UINT8* VidStd);
BOOL RxGetHdmiVidStdCfg(UINT8 Index, RX_VRT_FRQ Freq, RX_OS_RATE OvrSmplng, UINT8* VidStd, UINT8* VFreq);
BOOL RxGetSDPVidStdCfg(RX_OP_MODE SDPMode, UINT8 Index, RX_OS_RATE OvrSmplng, UINT8* VidStd);

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
ATV_ERR HAL_SetManagePowerDown(RX_CHIP_SECTION Section, RX_PWRDN_MODE PowerDownMode)
{
    return (ATVERR_FAILED);
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
ATV_ERR HAL_SetChipReset(RX_CHIP_SECTION Section)
{
    ATV_ERR ErrVal = ATVERR_OK;

    switch (Section)
    {
        case RX_ALL_SECTIONS:
            VRX_set_MAIN_RESET(0x1);
            break;
        case RX_SDP_CORE:
            VRX_set_SDP_RESET(0x1);
            break;
        case RX_VDP:
            VRX_set_VDP_RESET(0x1);
            break;
        case RX_MEM:
            VRX_set_SDP_MEM_RESET(0x1); 
            break;
        case RX_EDID_REP_MPU:
            VRX_set_HDCP_REPT_EDID_RESET(0x1);
            break;
        case RX_CEC_CTRL:
            VRX_set_CEC_SOFT_RESET(0x1);
            break;
        case RX_AVLINK_CTRL:
            VRX_set_AVL_SOFT_RESET(0x1);
            break;
        default:
            ErrVal = ATVERR_INV_PARM;
            break;
    }
    return (ErrVal);
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
ATV_ERR HAL_SetPinFunction(RX_PIN PinId, RX_PIN_FUNCTION PinFunction)
{
    ATV_ERR ErrVal = ATVERR_OK;

    switch(PinId)
    {
        case RX_VS_OUT_PIN:
            switch(PinFunction)
            {
               case RX_VS_SIG:
                    VRX_set_VS_OUT_SEL(0x1);
                    break;
               case RX_FIELD_SIG:
                    VRX_set_VS_OUT_SEL(0x0);
                    break;
               default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
        case RX_HS_OUT_PIN:
            switch(PinFunction)
            {
                case RX_HS_SIG:
                    VRX_set_HS_OUT_SEL(0x1);
                    break;
                case RX_CS_SIG:
                    VRX_set_HS_OUT_SEL(0x0);
                    break;
                default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
       case RX_SYNC_OUT_PIN:
            switch(PinFunction)
            {
                case RX_INT_SIG:
                    VRX_set_INT2_EN(0x1);
                    break;
                case RX_SYNC_OUT_SIG:
                    VRX_set_INT2_EN(0x0);
                    break;
                default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
       case RX_DE_OUT_PIN:
            switch(PinFunction)
            {
                case RX_DE_SIG:
                    VRX_set_F_OUT_SEL(0x0);
                    break;
                case RX_FIELD_SIG:
                    VRX_set_F_OUT_SEL(0x1);
                    break;
                    default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
       case RX_HS_IN1_PIN:
            switch(PinFunction)
            {
                case RX_HS_SIG:
                    VRX_set_TRI8_SLICER_PWRDN(0x1);
                    break;
                case RX_TRILEVEL_SIG:
                    VRX_set_TRI8_SLICER_PWRDN(0x0);
                    break;
                case RX_FB_SIG:
                    VRX_set_FB_SELECT(0x6);
                    break;
                default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
       case RX_VS_IN1_PIN:
            switch(PinFunction)
            {
                case RX_VS_SIG:
                    VRX_set_TRI7_SLICER_PWRDN(0x1);
                    break;
                case RX_TRILEVEL_SIG:
                    VRX_set_TRI7_SLICER_PWRDN(0x0);
                    break;
                case RX_FB_SIG:
                    VRX_set_FB_SELECT(0x7);
                    break;
                default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
   
        case RX_HS_IN2_PIN:
            switch(PinFunction)
            {
                case RX_HS_SIG:
                    VRX_set_TRI5_SLICER_PWRDN(0x1);
                    break;
                case RX_TRILEVEL_SIG:
                    VRX_set_TRI5_SLICER_PWRDN(0x0);
                    break;
                case RX_FB_SIG:
                    VRX_set_FB_SELECT(0x4);
                    break;
                default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
       case RX_VS_IN2_PIN:
            switch(PinFunction)
            {
                case RX_VS_SIG:
                    VRX_set_TRI6_SLICER_PWRDN(0x1);
                    break;
                case RX_TRILEVEL_SIG:
                    VRX_set_TRI6_SLICER_PWRDN(0x0);
                    break;
                case RX_FB_SIG:
                    VRX_set_FB_SELECT(0x5);
                    break;
                default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
       case RX_FIELD_OUT_PIN:
            switch(PinFunction)
            {
                case RX_DE_SIG:
                    VRX_set_F_OUT_SEL(0x0);
                    break;
                case RX_FIELD_SIG:
                    VRX_set_F_OUT_SEL(0x1);
                    break;
                default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
        case RX_INT2_OUT_PIN:
            switch(PinFunction)
            {
                case RX_ENABLE_PIN:
                case RX_INT_SIG:
                    VRX_set_INT2_EN(0x1);
                    VRX_set_EN_MUTE_OUT_INTRQ2(0x0);
                    break;
                case RX_AUDIO_MUTE_SIG:
                    VRX_set_INT2_EN(0x1);
                    VRX_set_EN_MUTE_OUT_INTRQ2(0x1);
                    break;
                case RX_DISABLE_PIN:
                    VRX_set_INT2_EN(0x0);
                    break;
                default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
        case RX_INT1_OUT_PIN:
            switch(PinFunction)
            {
                case RX_ENABLE_PIN:
                case RX_INT_SIG:
                    VRX_set_EN_MUTE_OUT_INTRQ(0x0);
                    break;
                case RX_AUDIO_MUTE_SIG:
                    VRX_set_EN_MUTE_OUT_INTRQ(0x1);
                    break;
                default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
        case RX_CABLE_DET_PINS:
            switch(PinFunction)
            {
                case RX_DISABLE_PIN:
                    VRX_set_FILT_5V_DET_DIS(0x1);
                    break;
                case RX_ENABLE_PIN:
                    VRX_set_FILT_5V_DET_DIS(0x0);
                    break;
                default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
        case RX_POWERDNB_PIN:
            switch(PinFunction)
            {
                case RX_DISABLE_PIN:
                    VRX_set_DIS_PWRDNB(0x1);
                    break;
                case RX_ENABLE_PIN:
                    VRX_set_DIS_PWRDNB(0x0);
                    break;
                default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
         case RX_TRI1_PIN:
            switch(PinFunction)
            {
                 case RX_FB_SIG:
                    VRX_set_FB_SELECT(0x0);
                    break;
                 case RX_TRILEVEL_SIG:
                    VRX_set_FB_SELECT(0x0);
                    break;
                default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
          case RX_TRI2_PIN:
            switch(PinFunction)
            {
                 case RX_FB_SIG:
                    VRX_set_FB_SELECT(0x1);
                    break;
                 case RX_TRILEVEL_SIG:
                    VRX_set_FB_SELECT(0x0);
                    break;
                default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
           case RX_TRI3_PIN:
            switch(PinFunction)
            {
                 case RX_FB_SIG:
                    VRX_set_FB_SELECT(0x2);
                    break;
                 case RX_TRILEVEL_SIG:
                    VRX_set_FB_SELECT(0x0);
                    break;
                default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
            case RX_TRI4_PIN:
            switch(PinFunction)
            {
                 case RX_FB_SIG:
                    VRX_set_FB_SELECT(0x3);
                    break;
                 case RX_TRILEVEL_SIG:
                    VRX_set_FB_SELECT(0x0);
                    break;
                default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
            case RX_TRI5_PIN:
            switch(PinFunction)
            {
                 case RX_FB_SIG:
                    VRX_set_FB_SELECT(0x4);
                    break;
                 case RX_TRILEVEL_SIG:
                    VRX_set_FB_SELECT(0x0);
                    break;
                default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
            case RX_TRI6_PIN:
            switch(PinFunction)
            {
                 case RX_FB_SIG:
                    VRX_set_FB_SELECT(0x5);
                    break;
                 case RX_TRILEVEL_SIG:
                    VRX_set_FB_SELECT(0x0);
                    break;
                default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
            case RX_TRI7_PIN:
            switch(PinFunction)
            {
                 case RX_FB_SIG:
                    VRX_set_FB_SELECT(0x6);
                    break;
                 case RX_TRILEVEL_SIG:
                    VRX_set_FB_SELECT(0x0);
                    break;
                default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
            case RX_TRI8_PIN:
            switch(PinFunction)
            {
                 case RX_FB_SIG:
                    VRX_set_FB_SELECT(0x7);
                    break;
                 case RX_TRILEVEL_SIG:
                    VRX_set_FB_SELECT(0x0);
                    break;
                default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
        default:
            ErrVal = ATVERR_INV_PARM;
            break;
    }
    return (ErrVal);        
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
ATV_ERR HAL_SetTristatePin(RX_PIN Pin, BOOL Tristate)
{
    ATV_ERR ErrVal = ATVERR_OK;
    switch (Pin)
    {
        case RX_LLC_OUT_PIN:
            switch(Tristate)
            {
                case TRUE:
                    VRX_set_TRI_LLC(0x1);
                    break;
                case FALSE:
                    VRX_set_TRI_LLC(0x0);
                    break;
                default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
        case RX_PIX_OUT_PINS:
            switch(Tristate)
            {
                case TRUE:
                    VRX_set_TRI_PIX(0x1);
                    break;
                case FALSE:
                    VRX_set_TRI_PIX(0x0);
                    break;
                default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
        case RX_SYNC_OUT_PINS:
            switch(Tristate)
            {
                case TRUE:
                    VRX_set_TRI_SYNCS(0x1);
                    break;
                case FALSE:
                    VRX_set_TRI_SYNCS(0x0);
                    break;
                default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
        case RX_AUD_OUT_PINS:
            switch(Tristate)
            {
                case TRUE:
                    VRX_set_TRI_AUDIO(0x1); 
                    break;
                case FALSE:
                    VRX_set_TRI_AUDIO(0x0);
                    break;
                default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
        case RX_MEM_IF_PINS:
            switch(Tristate)
            {
                case TRUE:
                    VRX_set_SDP_TRI_MEMORY_IF_B(0x1);
                    break;
                case FALSE:
                    VRX_set_SDP_TRI_MEMORY_IF_B(0x0);
                    break;
                default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
        case RX_OUT_PINS:
            switch(Tristate)
            {
                case TRUE:
                    VRX_set_TRI_AUDIO(0x1); 
                    VRX_set_TRI_SYNCS(0x1);
                    VRX_set_TRI_PIX(0x1);
                    VRX_set_TRI_LLC(0x1);
                    VRX_set_SDP_TRI_MEMORY_IF_B(0x1);
                    
                    break;
                case FALSE:
                    VRX_set_TRI_AUDIO(0x0);
                    VRX_set_TRI_SYNCS(0x0);
                    VRX_set_TRI_PIX(0x0);
                    VRX_set_TRI_LLC(0x0);
                    VRX_set_SDP_TRI_MEMORY_IF_B(0x0);
                    break;
                default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
        default:
            ErrVal = ATVERR_INV_PARM;
            break;
    }
    return (ErrVal);
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
ATV_ERR HAL_SetPinPolarity(RX_PIN Pin, BOOL PosPolarity)
{
    ATV_ERR ErrVal;
    ErrVal = ATVERR_OK;
    switch(Pin)
    {
        case RX_VS_OUT_PIN:
            switch(PosPolarity)
            {
                case TRUE:
                    VRX_set_INV_VS_POL(0x1);
                    break;
                case FALSE:
                    VRX_set_INV_VS_POL(0x0);
                    break;
                default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
        case RX_HS_OUT_PIN:
            switch(PosPolarity)
            {
                case TRUE:
                    VRX_set_INV_HS_POL(0x1);
                    break;
                case FALSE:
                    VRX_set_INV_HS_POL(0x0);
                    break;
                default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
       case RX_DE_OUT_PIN:
            switch(PosPolarity)
            {
                case TRUE:
                    VRX_set_INV_F_POL(0x1);
                    break;
                case FALSE:
                    VRX_set_INV_F_POL(0x0);
                    break;
                default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
       case RX_FIELD_OUT_PIN:
            switch(PosPolarity)
            {
                case TRUE:
                    VRX_set_INV_F_POL(0x1);
                    break;
                case FALSE:
                    VRX_set_INV_F_POL(0x0);
                    break;
                default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
       case RX_SYNC_OUT_PINS:
            switch(PosPolarity)
            {
                case TRUE:
                    VRX_set_INV_SYNC_OUT_POL(0x1);
                    break;
                case FALSE:
                    VRX_set_INV_SYNC_OUT_POL(0x0);
                    break;
                default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
       case RX_LLC_OUT_PIN:
            switch(PosPolarity)
            {
                case TRUE:
                    VRX_set_INV_LLC_POL(0x1);
                    break;
                case FALSE:
                    VRX_set_INV_LLC_POL(0x0);
                    break;
                default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;               
        default:
            ErrVal = ATVERR_INV_PARM;
            break;
    }
    return (ErrVal);
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
ATV_ERR HAL_ConfigInt(RX_PIN IntPin, RX_INT_DURATION Duration, RX_PIN_LEVEL PinLevel)
{
    ATV_ERR ErrVal;
    UINT8 TmpDur;
    UINT8 TmpLevel;
    ErrVal = ATVERR_OK;
    switch(Duration)
    {
       case RX_3_XTAL_CLK:
            TmpDur = 0x0;
            break;
       case RX_15_XTAL_CLK:
            TmpDur = 0x1;
            break;
       case RX_63_XTAL_CLK:
            TmpDur = 0x2;
            break;
       case RX_ACT_UNTIL_CLR:
            TmpDur = 0x3;
            break;
       default:
            ErrVal = ATVERR_INV_PARM;
            return (ErrVal);
    }
    switch(PinLevel)
    {
       case RX_OPEN_DRAIN:
            TmpLevel = 0x0;
            break;
       case RX_LOW_LEVEL:
            TmpLevel = 0x1;
            break;
       case RX_HIGH_LEVEL:
            TmpLevel = 0x2;
            break;
       default:
            ErrVal = ATVERR_INV_PARM;
            return (ErrVal);
     }
     switch(IntPin)
     {
        case RX_INT1_OUT_PIN:
             VRX_set_INTRQ_DUR_SEL(TmpDur);    
             VRX_set_INTRQ_OP_SEL(TmpLevel);
             break;
        case RX_INT2_OUT_PIN:
             VRX_set_INTRQ2_DUR_SEL(TmpDur);
             VRX_set_INTRQ2_OP_SEL(TmpLevel);
             break;
        default:
             ErrVal = ATVERR_INV_PARM;
             break;
     }
     return (ErrVal);
    
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
ATV_ERR HAL_ForceIntLevel(RX_PIN IntPin, BOOL ForceLevel)
{
    ATV_ERR ErrVal = ATVERR_OK;

    if(ForceLevel)
    {
        switch(IntPin)
        {
            case RX_INT1_OUT_PIN:
                VRX_set_MPU_STIM_INTRQ_MB1(0x1);
                break;
            case RX_INT2_OUT_PIN:
                VRX_set_MPU_STIM_INTRQ_MB2(0x1);
                break;
            default:
                ErrVal = ATVERR_INV_PARM;
                return (ErrVal);
        }
        VRX_set_MPU_STIM_INTRQ(0x1);
    }
    else
    {
        switch(IntPin)
        {
            case RX_INT1_OUT_PIN:
                VRX_set_MPU_STIM_INTRQ_MB1(0x0);
                break;
            case RX_INT2_OUT_PIN:
                VRX_set_MPU_STIM_INTRQ_MB2(0x0);
                break;
            default:
                ErrVal = ATVERR_INV_PARM;
                return (ErrVal);
        }
        VRX_set_MPU_STIM_INTRQ(0x0);
    }
    return (ErrVal);
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
ATV_ERR HAL_SetDriveStrength(RX_PIN PinId,  RX_OP_DR_STR DriveLevel)
{
    ATV_ERR ErrVal = ATVERR_OK;
    UINT8 TmpDrStrngth;
    
    switch(DriveLevel)
    {
        case RX_DR_STR_1X: 
             TmpDrStrngth =0x0;
             break;
        case RX_DR_STR_2X :
             TmpDrStrngth =0x1;
             break;           
        case RX_DR_STR_3X:
            TmpDrStrngth =0x2;
             break;      
        case RX_DR_STR_4X:
            TmpDrStrngth =0x3;
             break;
        default: 
             ErrVal = ATVERR_INV_PARM;
             return (ErrVal);
    }
    switch(PinId)
    {
        case RX_LLC_OUT_PIN:
            VRX_set_DR_STR_CLK(TmpDrStrngth);
            break;
        case RX_PIX_OUT_PINS:
            VRX_set_DR_STR(TmpDrStrngth);
            break;
        case RX_SYNC_OUT_PINS:
            VRX_set_DR_STR_SYNC(TmpDrStrngth);
            break;
        case RX_OUT_PINS:
            VRX_set_DR_STR_CLK(TmpDrStrngth);
            VRX_set_DR_STR(TmpDrStrngth);
            VRX_set_DR_STR_SYNC(TmpDrStrngth);
            VRX_set_DR_STR_SYNC(TmpDrStrngth);
            break; 
        default:
            ErrVal = ATVERR_INV_PARM;
            break;
    }
    return (ErrVal);
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
ATV_ERR HAL_SetManSigPhase(RX_CLOCK_SIG Signal, UINT8 Phase)
{
    ATV_ERR ErrVal;
    ErrVal = ATVERR_OK;
    
    if(Phase > 31)
    {
        return (ATVERR_INV_PARM);
    }
    switch(Signal)
    {
        case RX_SAMP_CLK_SIG:
             VRX_set_DLL_PHASE(Phase);  
             break;
        case RX_LLC_SIG:
             VRX_set_LLC_DLL_PHASE(Phase);  
             break;
     
        default:
             ErrVal = ATVERR_INV_PARM; 
    }
    return (ErrVal);
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
ATV_ERR HAL_SetManSigPhaseEn(RX_CLOCK_SIG Signal, BOOL Enable)
{
    ATV_ERR ErrVal;
    ErrVal = ATVERR_OK;
    
    switch(Signal)
    {
       case RX_SAMP_CLK_SIG:
            ErrVal = ATVERR_INV_PARM;  
            break;
       
       case RX_LLC_SIG:
            if(Enable)
            {
                VRX_set_LLC_DLL_EN(0x1);
                VRX_set_LLC_DLL_MUX(0x1);
            }
            else
            {
                VRX_set_LLC_DLL_EN(0x0);
                VRX_set_LLC_DLL_MUX(0x0);
            }
            break;
       default:
            ErrVal = ATVERR_INV_PARM;  
            break;
    }
    return (ErrVal);
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
ATV_ERR HAL_SetAinAutoMuxModeSel(UINT8 AinMode)
{
    ATV_ERR ErrVal;
    ErrVal = ATVERR_OK;
    if(AinMode > 0x4)
    {
        return (ATVERR_INV_PARM);
    }
    VRX_set_AIN_SEL(AinMode);
    return (ErrVal);
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
ATV_ERR HAL_SetManAinMux(RX_ADC ADC, RX_AIN_CH AinChannel)
{
    ATV_ERR ErrVal = ATVERR_OK;
    UINT8 ADCVal=0x0;
    
    switch(ADC)
    {
        case RX_ADC0:
             switch(AinChannel)
             {
                case RX_AIN1:     
                     ADCVal =0x1;
                     break;
                case RX_AIN4:
                     ADCVal =0x4;
                     break;
                     
                case RX_AIN7:
                     ADCVal =0x7;
                     break;
                
                case RX_AIN9:
                     ADCVal =0x9;
                     break;
                
                case RX_AIN10:
                     ADCVal =0xA;
                     break;
                
                case RX_AIN11:
                     ADCVal =0xB;
                     break;
                     
                default:
                     ErrVal=ATVERR_INV_PARM;
                     break;
            }
            VRX_set_ADC0_SW_MAN(ADCVal);
            break;
       case RX_ADC1:
            switch(AinChannel)
            {
                case RX_AIN2:
                     ADCVal =0x2;
                     break;
                case RX_AIN4:
                     ADCVal =0x4;
                     break;
                case RX_AIN5:
                     ADCVal =0x5;
                     break;
                case RX_AIN8:
                     ADCVal =0x8;
                     break;
                case RX_AIN11:
                     ADCVal =0x11;
                     break;
                default:
                     ErrVal=ATVERR_INV_PARM;
                     break;
            }
            VRX_set_ADC1_SW_MAN(ADCVal);
            break;
       case RX_ADC2:
            switch(AinChannel)
            {
                case RX_AIN3:
                     ADCVal =0x3;
                     break;
                case RX_AIN4:
                     ADCVal =0x4;
                     break;
                case RX_AIN5:
                     ADCVal =0x5;
                     break;
                case RX_AIN6:
                     ADCVal =0x6;
                     break;
                case RX_AIN9:
                     ADCVal =0x9;
                     break;
                case RX_AIN12:
                     ADCVal =0xC;
                     break;
                
                default:
                     ErrVal=ATVERR_INV_PARM;
                     break;
            }
            VRX_set_ADC2_SW_MAN(ADCVal);
            break;
       
       case RX_ADC3:
            switch(AinChannel)
            {
               case RX_AIN4:
                    ADCVal =0x4;
                    break;
               case RX_AIN6:
                    ADCVal =0x6;
                    break;
               case RX_AIN7:
                    ADCVal =0x7;
                    break;
               default:
                    ErrVal=ATVERR_INV_PARM;
                    break;
            }
            VRX_set_ADC3_SW_MAN(ADCVal);
            break;
      default:
            ErrVal=ATVERR_INV_PARM;
            break;
   }
   return (ErrVal);
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
ATV_ERR HAL_SetAntiAliasFiltEn(RX_ADC ADC, BOOL Enable)
{ 

    ATV_ERR ErrVal = ATVERR_OK;

    switch(ADC)
    {
        case RX_ADC0:
            VRX_set_AA_FILTER_EN0(Enable);
            break;
        case RX_ADC1:
            VRX_set_AA_FILTER_EN1(Enable);
            break;
        case RX_ADC2:
            VRX_set_AA_FILTER_EN2(Enable);
            break;
        case RX_ADC3:
            VRX_set_AA_FILTER_EN3(Enable);
            break;
       
        case RX_ALL_ADCS:
            VRX_set_AA_FILTER_EN0(Enable);
            VRX_set_AA_FILTER_EN1(Enable);
            VRX_set_AA_FILTER_EN2(Enable);
            VRX_set_AA_FILTER_EN3(Enable);
            break;
        default:
            ErrVal=ATVERR_INV_PARM;
            break;
    }
    return (ErrVal);
}

/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  TRUE
 *          FALSE
 *
 * Notes:
 *
 *=========================================================================*/
BOOL RxGetCmpVidStdCfg(UINT8 Index, RX_VRT_FRQ Freq, RX_OS_RATE OvrSmplng, UINT8* VidStd, UINT8* VFreq)
{ 
    switch (Freq)
    {
       case RX_VFRQ_24HZ:
       if (CmpVidStdTable[Index].CmpVFreq[0]==FALSE)
             {
                return FALSE;
             }
             *VFreq =  RX_VFRQ_24_VAL;
             break;
        case RX_VFRQ_25HZ:
            if (CmpVidStdTable[Index].CmpVFreq[1]==FALSE)
             {
                return FALSE;
             }
             *VFreq =  RX_VFRQ_25_VAL;
             break;
        case RX_VFRQ_30HZ:
             if (CmpVidStdTable[Index].CmpVFreq[2]==FALSE)
             {
                return FALSE;
             }
             *VFreq =  RX_VFRQ_30_VAL;
             break;
        case RX_VFRQ_50HZ:
             if (CmpVidStdTable[Index].CmpVFreq[3]==FALSE)
             {
             
                return FALSE;
             }
             *VFreq =  RX_VFRQ_50_VAL;
             break;
        case RX_VFRQ_60HZ:
            if (CmpVidStdTable[Index].CmpVFreq[4]==FALSE)
             {
                return FALSE;
             }
            *VFreq =  RX_VFRQ_60_VAL;
             break;
        default:
             RX_DEBUG("Vertical Frequency not supported \r\n"); 
             return FALSE; 
    }        
  
      switch(OvrSmplng)
      {
        case RX_OS_1X1:
            if (CmpVidStdTable[Index].VidStdSet[0] == RX_OS_NOT_SUP)
            {
                return FALSE; 
            }
            *VidStd = CmpVidStdTable[Index].VidStdSet[0];
            break;
        case RX_OS_2X1:
            if (CmpVidStdTable[Index].VidStdSet[1] == RX_OS_NOT_SUP)
            {
                return FALSE; 
            }
            *VidStd = CmpVidStdTable[Index].VidStdSet[1];
            break;
        case RX_OS_4X1:
            if (CmpVidStdTable[Index].VidStdSet[2] == RX_OS_NOT_SUP)
            {
                return FALSE; 
            }
            *VidStd = CmpVidStdTable[Index].VidStdSet[2];
            break;
        case RX_OS_2X2:
            if (CmpVidStdTable[Index].VidStdSet[3] == RX_OS_NOT_SUP)
            {
                return FALSE; 
            }
            *VidStd = CmpVidStdTable[Index].VidStdSet[3];
            break;
        case RX_OS_4X2:
          if (CmpVidStdTable[Index].VidStdSet[4] == RX_OS_NOT_SUP)
            {
                return FALSE; 
            }
            *VidStd = CmpVidStdTable[Index].VidStdSet[4];
            break;
        
        default:
            RX_DEBUG("Over Sampling Mode Not Supported \r\n");
            return FALSE; 
          }
      return TRUE;
 
     
}

/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  TRUE
 *          FALSE
 *
 * Notes:
 *
 *=========================================================================*/
BOOL RxGetGrVidStdCfg(UINT8 Index, RX_VRT_FRQ Freq, UINT8* VidStd)
{ 
   switch(Freq)
   {
        case RX_VFRQ_56HZ:
            if (GrVidStdTable[Index].VidStdSet[0] == RX_FREQ_NOT_SUP)
            {
                return FALSE;
            }
            *VidStd = GrVidStdTable[Index].VidStdSet[0];
            break;
        case RX_VFRQ_60HZ:
            if (GrVidStdTable[Index].VidStdSet[1] == RX_FREQ_NOT_SUP)
            {
                return FALSE;
            }
            *VidStd = GrVidStdTable[Index].VidStdSet[1];
            break;
        case RX_VFRQ_70HZ:
            if (GrVidStdTable[Index].VidStdSet[2] == RX_FREQ_NOT_SUP)
            {
                return FALSE;
            }
            *VidStd = GrVidStdTable[Index].VidStdSet[2];
            break;
        case RX_VFRQ_72HZ:
             if (GrVidStdTable[Index].VidStdSet[3] == RX_FREQ_NOT_SUP)
             {
                return FALSE;
             }
             *VidStd = GrVidStdTable[Index].VidStdSet[3];
            break;
        case RX_VFRQ_75HZ:
            if (GrVidStdTable[Index].VidStdSet[4] == RX_FREQ_NOT_SUP)
            {
               return FALSE;
            }
            *VidStd = GrVidStdTable[Index].VidStdSet[4];
            break;
        case RX_VFRQ_85HZ:
            if (GrVidStdTable[Index].VidStdSet[5] == RX_FREQ_NOT_SUP)
            {
                return FALSE;
            }
            *VidStd = GrVidStdTable[Index].VidStdSet[5];
            break;
         
        default:
            RX_DEBUG("Vertical Frequency not supported \r\n");
            return FALSE;
      }
    return TRUE;
      
}

/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  TRUE
 *          FALSE
 *
 * Notes:
 *
 *=========================================================================*/
BOOL RxGetHdmiVidStdCfg(UINT8 Index, RX_VRT_FRQ Freq, RX_OS_RATE OvrSmplng, UINT8* VidStd, UINT8* VFreq)
{
    switch(HdmiVidStdTable[Index].PrimMode)
    {
        case RX_HDMI_GR_PM:
            switch(Freq)
            {
                case RX_VFRQ_56HZ:
                    if (HdmiVidStdTable[Index].GrVidStdSet[0] == RX_FREQ_NOT_SUP)
                    {
                        return FALSE;
                    }
                    *VidStd = HdmiVidStdTable[Index].GrVidStdSet[0];
                    break;
                case RX_VFRQ_60HZ:
                    if (HdmiVidStdTable[Index].GrVidStdSet[1] == RX_FREQ_NOT_SUP)
                    {
                        return FALSE;
                    }
                    *VidStd = HdmiVidStdTable[Index].GrVidStdSet[1];
                    break;
                case RX_VFRQ_70HZ:
                    if (HdmiVidStdTable[Index].GrVidStdSet[2] == RX_FREQ_NOT_SUP)
                    {
                        return FALSE;
                    }
                    *VidStd = HdmiVidStdTable[Index].GrVidStdSet[2];
                    break;
                case RX_VFRQ_72HZ:
                    if (HdmiVidStdTable[Index].GrVidStdSet[3] == RX_FREQ_NOT_SUP)
                    {
                    return FALSE;
                    }
                    *VidStd = HdmiVidStdTable[Index].GrVidStdSet[3];
                    break;
                case RX_VFRQ_75HZ:
                    if (HdmiVidStdTable[Index].GrVidStdSet[4] == RX_FREQ_NOT_SUP)
                    {
                        return FALSE;
                    }
                    *VidStd = GrVidStdTable[Index].VidStdSet[4];
                    break;
                case RX_VFRQ_85HZ:
                    if (HdmiVidStdTable[Index].GrVidStdSet[5] == RX_FREQ_NOT_SUP)
                    {
                        return FALSE;
                    }
                    *VidStd = HdmiVidStdTable[Index].GrVidStdSet[5];
                    break;
                 
                default:
                    RX_DEBUG("Vertical Frequency not supported \r\n");
                    return FALSE; 
             }
             break;
            
        case RX_HDMI_CMP_PM:
            
            switch (Freq)
            {
                case RX_VFRQ_24HZ:
                    if (HdmiVidStdTable[Index].CmpVFreq[0]==FALSE)
                    {
                        return FALSE;
                    }
                    *VFreq =  RX_VFRQ_24_VAL;
                    break;
                case RX_VFRQ_25HZ:
                    if (HdmiVidStdTable[Index].CmpVFreq[1]==FALSE)
                    {
                        return FALSE;
                    }
                    *VFreq =  RX_VFRQ_25_VAL;
                    break;
                case RX_VFRQ_30HZ:
                    if (HdmiVidStdTable[Index].CmpVFreq[2]==FALSE)
                    {
                       return FALSE;
                    }
                    *VFreq =  RX_VFRQ_30_VAL;
                    break;
                case RX_VFRQ_50HZ:
                    if (HdmiVidStdTable[Index].CmpVFreq[3]==FALSE)
                    {
                        return FALSE;
                    }
                    *VFreq =  RX_VFRQ_50_VAL;
                    break;
                case RX_VFRQ_60HZ:
                    if (HdmiVidStdTable[Index].CmpVFreq[4]==FALSE)
                    {
                        return FALSE;
                    }
                    *VFreq =  RX_VFRQ_60_VAL;
                    break;
                default:
                    RX_DEBUG("Vertical Frequency not supported \r\n"); 
                    return FALSE; 
            }

            switch(OvrSmplng)
            {
                case RX_OS_1X1:
                    if (HdmiVidStdTable[Index].CmpVidStdSet[0] == RX_OS_NOT_SUP)
                    {
                        return FALSE;
                    }
                    *VidStd = HdmiVidStdTable[Index].CmpVidStdSet[0];
                    break;
                case RX_OS_2X1:
                    if (HdmiVidStdTable[Index].CmpVidStdSet[1] == RX_OS_NOT_SUP)
                    {
                        return FALSE;
                    }
                    *VidStd = HdmiVidStdTable[Index].CmpVidStdSet[1];
                    break;
                case RX_OS_4X1:
                    if (HdmiVidStdTable[Index].CmpVidStdSet[2] == RX_OS_NOT_SUP)
                    {
                        return FALSE;
                    }
                    *VidStd = HdmiVidStdTable[Index].CmpVidStdSet[2];
                    break;
                case RX_OS_2X2:
                    if (HdmiVidStdTable[Index].CmpVidStdSet[3] == RX_OS_NOT_SUP)
                    {
                        return FALSE;
                    }
                    *VidStd = HdmiVidStdTable[Index].CmpVidStdSet[3];
                    break;
                case RX_OS_4X2:
                    if (HdmiVidStdTable[Index].CmpVidStdSet[4] == RX_OS_NOT_SUP)
                    {
                        return FALSE;
                    }
                    *VidStd = HdmiVidStdTable[Index].CmpVidStdSet[4];
                    break;        
                default:
                    RX_DEBUG("Over Sampling Mode Not Supported \r\n");
                    return FALSE; 
            }
            break;

        default:
            break;
    }
    return (TRUE);
}

/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  TRUE
 *          FALSE
 *
 * Notes:
 *
 *=========================================================================*/
BOOL RxGetSDPVidStdCfg(RX_OP_MODE SDPMode, UINT8 Index, RX_OS_RATE OvrSmplng, UINT8* VidStd)
{
    UINT8 OsIndex;
    
    switch(OvrSmplng)
    {
        case RX_OS_2X1:
             OsIndex =0;
             break;
        case RX_OS_4X1:
             OsIndex =1;
             break;
        default:
            RX_DEBUG("Over Sampling Mode Not Supported \r\n");
            return FALSE;
    }
    
    switch(SDPMode)
    {
        case RX_OPMODE_SDP_CVBS:
             *VidStd = SDPVidStdTable[Index].CVBSVidStdSet[OsIndex];
             return TRUE;
        case RX_OPMODE_SDP_CVBS_YC_AUTO:
             *VidStd = SDPVidStdTable[Index].CVBS_YCVidStdSet[OsIndex];
             return TRUE;
        case RX_OPMODE_SDP_YC:
            *VidStd = SDPVidStdTable[Index].YCVidStdSet[OsIndex];
             return TRUE;
        case RX_OPMODE_SDP_SCART:
            *VidStd = SDPVidStdTable[Index].SCARTVidStdSet[OsIndex];
             return TRUE;
        default:
            RX_DEBUG("SDP Mode Not Supported \r\n");
            return FALSE;    
    }
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
ATV_ERR HAL_RxSetInpVidCfg(RX_OP_MODE OpMode, RX_VID_RES Res, RX_VRT_FRQ Freq, RX_OS_RATE OvrSmplng)
{
    ATV_ERR ErrVal = ATVERR_OK;
    UINT8 i,index;
    UINT8 TmpPrimMode;
    UINT8 TmpVidStd;
    UINT8 TmpVFreq;
    
    switch(OpMode)
    {
        case RX_OPMODE_COMP:
            TmpPrimMode = RX_CMP_PRIM_MODE;
            for(i=0; i<RX_CMP_TBL_SIZE; i++)
            {
                if((CmpVidStdTable[i].Res == Res))
                {
                    index = i;
                    RX_DEBUG("Resolution index: %d\r\n", i);              
                    if(RxGetCmpVidStdCfg(index, Freq, OvrSmplng, &TmpVidStd, &TmpVFreq)== TRUE)
                    { 
                        VRX_set_VID_STD( TmpVidStd); 
                        VRX_set_PRIM_MODE(TmpPrimMode);
                        VRX_set_V_FREQ(TmpVFreq); 
                        RxSetSpecificResCnfg(TmpPrimMode, Res);
                        RX_DEBUG("Primary Mode: %x, Video Std: %x\r\n", TmpPrimMode,TmpVidStd);
                        return(ATVERR_OK);
                    }
                }
            }
            RX_DEBUG("Resolution not directly supported\r\n");    
            return(ATVERR_FAILED);

        case RX_OPMODE_GR:
            for (i=0; i<RX_GR_TBL_SIZE; i++)
            {
                if((GrVidStdTable[i].Res == Res))
                { 
                    index =i;
                    RX_DEBUG("Resolution index: %d\r\n", i);
                    
                    if(RxGetGrVidStdCfg(index, Freq, &TmpVidStd)==TRUE)
                    {
                        VRX_set_VID_STD( TmpVidStd); 
                        VRX_set_PRIM_MODE(RX_GR_PRIM_MODE);  
                        RxSetSpecificResCnfg(RX_GR_PRIM_MODE, Res); 
                        RX_DEBUG("Primary Mode: %x, Video Std: %x\r\n", RX_GR_PRIM_MODE,TmpVidStd); 
                        return(ATVERR_OK);         
                    }
                }
            }       
            for(i=0; i<RX_CMP_TBL_SIZE; i++)
            {
                if((CmpVidStdTable[i].Res == Res))
                {
                    index =i;
                    RX_DEBUG("Resolution index: %d\r\n", i);              
                    if(RxGetCmpVidStdCfg(index, Freq, OvrSmplng, &TmpVidStd, &TmpVFreq)== TRUE)
                    { 
                        VRX_set_VID_STD( TmpVidStd); 
                        VRX_set_PRIM_MODE(RX_CMP_PRIM_MODE);
                        VRX_set_V_FREQ(TmpVFreq); 
                        RxSetSpecificResCnfg(RX_CMP_PRIM_MODE, Res);
                        RX_DEBUG("Primary Mode: %x, Video Std: %x\r\n", RX_CMP_PRIM_MODE,TmpVidStd);
                        return(ATVERR_OK);
                    }
                }
            }
            RX_DEBUG("Resolution not directly supported\r\n");
            return(ATVERR_FAILED);

         case RX_OPMODE_HDMI:
            for (i=0; i<RX_HDMI_TBL_SIZE; i++)
            {
                if ((HdmiVidStdTable[i].Res == Res))
                {
                    index =i;
                    RX_DEBUG("Resolution index: %d\r\n", i); 
                    TmpPrimMode = HdmiVidStdTable[index].PrimMode;
                    if(RxGetHdmiVidStdCfg(index, Freq, OvrSmplng, &TmpVidStd, &TmpVFreq)== TRUE)
                    { 
                        VRX_set_VID_STD( TmpVidStd); 
                        VRX_set_PRIM_MODE(TmpPrimMode);  
                        if(TmpPrimMode == RX_HDMI_CMP_PM)
                        {
                            VRX_set_V_FREQ(TmpVFreq); 
                        }
                        RxSetSpecificResCnfg(TmpPrimMode, Res); 
                        ATV_I2CWriteField8(RX_I2C_IO_MAP_ADDR, 0xC1, 0x01, 0x0,  0x0); /* Ensure CP Core is enabled*/
                        ATV_I2CWriteField8(RX_I2C_IO_MAP_ADDR, 0xC1, 0x20, 0x5,  0x0); /* Ensure CP Core is enabled*/
                        RX_DEBUG("Primary Mode: %x, Video Std: %x\r\n", TmpPrimMode,TmpVidStd); 
                        return(ATVERR_OK);         
                    }
                }
            }
            RX_DEBUG("Resolution not directly supported\r\n");
            return(ATVERR_FAILED);

        case RX_OPMODE_SDP_CVBS:
            for(i=0; i<RX_SDP_TBL_SIZE; i++)
            {
                if((SDPVidStdTable[i].Res == Res))
                {
                    index =i;
                    RX_DEBUG("Resolution index: %d\r\n", i); 
                    if(RxGetSDPVidStdCfg(RX_OPMODE_SDP_CVBS,index,OvrSmplng, &TmpVidStd) ==TRUE)
                    {
                        VRX_set_PRIM_MODE(RX_SDP_PRIM_MODE);
                        VRX_set_VID_STD( TmpVidStd); 
                        /* RxSetSpecificResCnfg(TmpPrimMode, Res);*/  /*nnic to revisit*/
                        RX_DEBUG("Primary Mode: SDP_CVBS, Video Std: %x\r\n", TmpVidStd); 
                        return(ATVERR_OK);         
                    }
                }
            }
            RX_DEBUG("Resolution not directly supported\r\n");
            return(ATVERR_FAILED);

        case RX_OPMODE_SDP_YC:
            for(i=0; i<RX_SDP_TBL_SIZE; i++)
            {
                if((SDPVidStdTable[i].Res == Res))
                {
                    index =i;
                    RX_DEBUG("Resolution index: %d\r\n", i); 
                    if(RxGetSDPVidStdCfg(RX_OPMODE_SDP_YC,index,OvrSmplng, &TmpVidStd) ==TRUE)
                    {
                        VRX_set_PRIM_MODE(RX_SDP_PRIM_MODE);
                        VRX_set_VID_STD( TmpVidStd); 
                        /* RxSetSpecificResCnfg(TmpPrimMode, Res);*/ /*nnic to revisit*/
                        RX_DEBUG("Primary Mode: SDP YC, Video Std: %x\r\n",TmpVidStd); 
                        return(ATVERR_OK);         
                    }
                }
            }
            RX_DEBUG("Resolution not directly supported\r\n");
            return(ATVERR_FAILED);

        case RX_OPMODE_SDP_CVBS_YC_AUTO:
            for(i=0; i<RX_SDP_TBL_SIZE; i++)
            {
                if((SDPVidStdTable[i].Res == Res))
                {
                    index =i;
                    RX_DEBUG("Resolution index: %d\r\n", i); 
                    if(RxGetSDPVidStdCfg(RX_OPMODE_SDP_CVBS_YC_AUTO,index,OvrSmplng, &TmpVidStd) ==TRUE)
                    {
                        VRX_set_PRIM_MODE(RX_SDP_PRIM_MODE);
                        VRX_set_VID_STD( TmpVidStd); 
                        /*RxSetSpecificResCnfg(TmpPrimMode, Res);*/ /*nnic to revisit*/
                        RX_DEBUG("Primary Mode: SDP CVBS YC -Auto, Video Std: %x\r\n",TmpVidStd); 
                        return(ATVERR_OK);         
                    }
                }
            }

        case RX_OPMODE_SDP_SCART:
            for(i=0; i<RX_SDP_TBL_SIZE; i++)
            {
                if ((SDPVidStdTable[i].Res == Res))
                {
                    index =i;
                    RX_DEBUG("Resolution index: %d\r\n", i); 
                    if(RxGetSDPVidStdCfg(RX_OPMODE_SDP_SCART,index,OvrSmplng, &TmpVidStd) ==TRUE)
                    {
                        VRX_set_PRIM_MODE(RX_SDP_PRIM_MODE);
                        VRX_set_VID_STD( TmpVidStd); 
                        /*RxSetSpecificResCnfg(TmpPrimMode, Res);*/ /*nnic to revisit*/
                        RX_DEBUG("Primary Mode: SDP YC, Video Std: %x\r\n",TmpVidStd); 
                        return(ATVERR_OK);         
                    }
                }
            }
        default:
            ErrVal = ATVERR_INV_PARM;
            break;
    }
    return (ErrVal);    
}

/*============================================================================
 * This Local function is used Reset any setting that are base Resolution.
 *
 * Entry:   None
 * Return:  None
 *
 * Notes:   None
 *
 *===========================================================================*/
void RxRstSpecificResCnfg(void)
{
    /*========================================
     * Reset Primary Mode, Video Standard and 
     * Vertical Frequency Setting
     *=======================================*/
     VRX_set_VID_STD( 0x2);  
     VRX_set_V_FREQ(0x2);  

    /*========================================
     * Reset Specific Format Settings
     *=======================================*/
     VRX_set_SYNC1_FILTER_SEL(0x2); /*Set Sync Filter settings to default*/
     VRX_set_SYNC2_FILTER_SEL(0x2);
}

/*============================================================================
 * This Local function is used to Set Specific ADI Recommended Configuration based 
 * on Primary mode and Resolution
 *
 * Entry:   Primary Mode: Primary Mode of Operation
 *          Res: Expected Resolution of the video
 * Return:  
 *
 * Notes:   None
 *
 *===========================================================================*/
void RxSetSpecificResCnfg(UINT8 PrimMode, RX_VID_RES Res )
{
    
}

/*============================================================================
 *
 * Entry:   None
 *  
 * Return:  void
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR HAL_SetOpPixFormat (RX_PIX_BUS_INFO* PixBusInfo,  RX_OP_MODE* OpMode)
{
   

    ATV_ERR ErrVal = ATVERR_OK;
    UINT8 TmpBusWidth=0;
    UINT8 TmpFormat=0;
    UINT8 TmpMode=0;
    UINT8 OpFormatSel; 
    ErrVal = ATVERR_OK;
    
    switch(PixBusInfo->BitWidth)
    {
        case RX_BUS_BITS_8:
            TmpBusWidth = 0x0;
            break;
        case RX_BUS_BITS_10:
            TmpBusWidth = 0x1;
            break;
        case RX_BUS_BITS_12:
            TmpBusWidth = 0x2;
            break;
        default:
            ErrVal=  ATVERR_INV_PARM;   
            break;
    }

    switch(PixBusInfo->Mode)
    {
        case RX_BUS_MODE0:
            TmpMode = 0x0;
            break;
        case RX_BUS_MODE1:
            TmpMode = 0x1;
            break;
        case RX_BUS_MODE2:
            TmpMode = 0x2;
            break;
        default:
            ErrVal=  ATVERR_INV_PARM;   
            break;
    }
    
    switch(PixBusInfo->Format)
    {
        case RX_BUS_OP_MODE_422PSDR:
            TmpFormat= 0x00;
            break;
        case RX_BUS_OP_MODE_422DDR:
            TmpFormat= 0x01;
            break;
        case RX_BUS_OP_MODE_444SDR:
            TmpFormat= 0x02;
            break;
        case RX_BUS_OP_MODE_444DDR:
            TmpFormat= 0x03;
            break;
        case RX_BUS_OP_MODE_422SDR:
            TmpFormat= 0x04;
            break;
        default:
            ErrVal=  ATVERR_INV_PARM;   
            break;
    }

    OpFormatSel= ( TmpFormat << 5) | (TmpMode <<2)| (TmpBusWidth);
    VRX_set_OP_FORMAT_SEL(OpFormatSel);
    
    switch(PixBusInfo->ChOrder)
    {
        case RX_BUS_OP_CH_GBR:

             VRX_set_OP_CH_SEL(0x0);
             break;     
        case RX_BUS_OP_CH_GRB:
             VRX_set_OP_CH_SEL(0x1);
             break;
        case RX_BUS_OP_CH_BGR:
             VRX_set_OP_CH_SEL(0x2);
             break;
        case RX_BUS_OP_CH_RGB:
             VRX_set_OP_CH_SEL(0x3);
             break;
        case RX_BUS_OP_CH_BRG:
             VRX_set_OP_CH_SEL(0x4);
             break;
        case RX_BUS_OP_CH_RBG:
             VRX_set_OP_CH_SEL(0x5);
             break;
        default:
              ErrVal=  ATVERR_INV_PARM; 
              break;
    }
    VRX_set_PIXBUS_MSB_TO_LSB_REORDER(PixBusInfo->BitReorder);
    VRX_set_OP_SWAP_CB_CR(PixBusInfo->CrCbSwap);
    return (ErrVal);
}

/*============================================================================
 * This function is used to enable or disable CP events
 *
 * Entry:   EventList: A pointer to a list of CP event that must be enabled
 *                     Non CP event are discared by this function
 *          ListSize: The number of event in the listed pointed by EvntList
 *          Enable: TRUE = List of events pointed by EventList must be enabled
 *                  FALSE = List of events pointed by EventList must be disabled
 *  
 * Return:  
 *
 * Notes:   None
 *
 *===========================================================================*/
UCHAR HAL_RxSdpSetEnabledEvents (RX_EVENT *EventList, UCHAR ListSize, BOOL Enable)
{
    UINT8 i, j, IntIdx, IntCount=0, MaskVal[NOF_RX_MASK_REGS];
    IntIdx = HAL_RxGetIntIndex();

    /*=======================================
     * Get interrupt mask values
     *======================================*/
    for (i=0; RxSdpMaskRegs[i]; i+=3)
    {
        HAL_I2CReadByte(VRX_IO_MAP_ADDR, RxSdpMaskRegs[IntIdx+i], &(MaskVal[RxSdpMaskRegs[i+2]]));
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
    for (i=0; RxSdpMaskRegs[i]; i+=3)
    {
        HAL_I2CWriteByte(VRX_IO_MAP_ADDR, RxSdpMaskRegs[IntIdx+i], MaskVal[RxSdpMaskRegs[i+2]]);
    }

    /*=======================================
     * Clear masks for unused interrupt
     *======================================*/
    IntIdx = (~IntIdx) & 1;
    for (i=0; RxSdpMaskRegs[i]; i+=3)
    {
        HAL_I2CWriteByte(VRX_IO_MAP_ADDR, RxSdpMaskRegs[IntIdx+i], 0);
    }
    
    return(IntCount);
}
/*============================================================================
 * This function is used to enable or disable MV events
 *
 * Entry:   EventList: A pointer to a list of MV event that must be enabled
 *                     Non MV event are discared by this function
 *          ListSize: The number of event in the listed pointed by EvntList
 *          Enable: TRUE = List of events pointed by EventList must be enabled
 *                  FALSE = List of events pointed by EventList must be disabled
 *  
 * Return:  
 *
 * Notes:   None
 *
 *===========================================================================*/
UCHAR HAL_RxMvSetEnabledEvents (RX_EVENT *EventList, UCHAR ListSize, BOOL Enable)
{
    UINT8 i, j, IntIdx, IntCount=0, MaskVal[NOF_RX_MASK_REGS];
    IntIdx = HAL_RxGetIntIndex();

    /*=======================================
     * Get interrupt mask values
     *======================================*/
    for (i=0; RxMvMaskRegs[i]; i+=3)
    {
        HAL_I2CReadByte(VRX_IO_MAP_ADDR, RxMvMaskRegs[IntIdx+i], &(MaskVal[RxMvMaskRegs[i+2]]));
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
    for (i=0; RxMvMaskRegs[i]; i+=3)
    {
        HAL_I2CWriteByte(VRX_IO_MAP_ADDR, RxMvMaskRegs[IntIdx+i], MaskVal[RxMvMaskRegs[i+2]]);
    }

    /*=======================================
     * Clear masks for unused interrupt
     *======================================*/
    IntIdx = (~IntIdx) & 1;
    for (i=0; RxMvMaskRegs[i]; i+=3)
    {
        HAL_I2CWriteByte(VRX_IO_MAP_ADDR, RxMvMaskRegs[IntIdx+i], 0);
    }
    
    return(IntCount);
}

/*============================================================================
 * This function is used to if SDP events that can't be notified by the 
 * ISR have occurred
 *
 * Entry:   None
 *  
 * Return:  void
 *
 * Notes:   None
 *
 *===========================================================================*/
void HAL_RxSdpHouseKeeping (void)
{
    RX_SDP_FORMAT    TempSdpStdDetected;
    BOOL BurstLock; 
    UINT8 ByteX;    
    
    if (RX_EVENT_IS_ENABLED(RX_EVENT_SDP_BURST_LCK))
    {
        BurstLock = VRX_is_SDP_BURST_LOCKED_RB_true();
        if(BurstLock) 
        {
            ADIAPI_RxSdpGetAutoFormatDetectResult(&TempSdpStdDetected);
            if (CurrSdpStdDetected != TempSdpStdDetected)
            {
                CurrSdpStdDetected = TempSdpStdDetected;
                ByteX = (UINT8)(BurstLock); 
                RX_NOTIFY_USER(RX_EVENT_SDP_BURST_LCK, 0, &ByteX);
            }
        }
    }
}
/*==========================================================================
 * SDP ISR
 *
 * Entry:  None
 * 
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 * 
 * Notes:  None
 *=========================================================================*/
ATV_ERR HAL_RXLIB_SdpIsr (void)
{
    RX_SDP_INTERRUPTS SdpInts;
    UINT8 ByteX;
    ATV_ERR RetVal = ATVERR_FAILED;
    
    /*=======================================
     * Get asserted interrupts
     *======================================*/
    HAL_RxSdpGetInterrupts (&SdpInts);
    
    /*==================================================
     * Burst-Lock  detection
     *=================================================*/
    
    if (SdpInts.BrstLckDet)
    {
        ByteX = VRX_ret_SDP_BURST_LOCKED_RB();
        RX_NOTIFY_USER(RX_EVENT_SDP_BURST_LCK, 0, &ByteX);
        RetVal = ATVERR_OK;
    }
    /*==================================================
     * Vid-Lock  detection
     *=================================================*/
     if (SdpInts.VidSigDet)
     {
        ByteX= VRX_ret_SDP_VIDEO_DETECTED();
        RX_NOTIFY_USER(RX_EVENT_SDP_VIDEO_DET, 0, &ByteX);
        RetVal = ATVERR_OK;
     }
     
     /*==================================================
     * Std-Change  detection
     *=================================================*/
     if(SdpInts.StdChng)
     {
        ByteX = VRX_ret_SDP_BURST_LOCKED_RB();
        RX_NOTIFY_USER(RX_EVENT_SDP_BURST_LCK, 0, &ByteX);
        RetVal = ATVERR_OK;
     }
    return (RetVal);
}

/*==========================================================================
 * Finds out all the active and unmasked SDP interrupts. It clears all the 
 * active interupts on return.
 *
 * Entry:   RxSdpInts = is a BOOL array that contains status of all the HDMI
 *                      interrupts
 * 
 * Notes:  None
 *=========================================================================*/
void HAL_RxSdpGetInterrupts(RX_SDP_INTERRUPTS *RxSdpInts)
{
    UINT8 SdpIntStat;
        
    HAL_I2CReadByte(VRX_IO_MAP_ADDR, VRX_REG_SDP_INTERRUPT_STATUS, &SdpIntStat);

    RxSdpInts->VidSigDet = (BOOL) (SdpIntStat & VRX_BIT_SDP_VIDEO_DETECTED_ST);
    RxSdpInts->BrstLckDet= (BOOL)(SdpIntStat & VRX_BIT_SDP_BURST_LOCKED_ST);
    RxSdpInts->StdChng= (BOOL)(SdpIntStat & VRX_BIT_SDP_STD_CHANGED_ST);
        
   /* =========================================================================================
    * The below is done so that we only clear the interrupts that we're currently interested in
    * This way we don't inadvertently clear something that another function might need to look at
    * ===========================================================================================*/
      SdpIntStat = RxSdpInts->VidSigDet | RxSdpInts->BrstLckDet | RxSdpInts->StdChng;
    /*==================================================================
    * Acknowledge all interrupts immediately so we don't lose any
    *=================================================================*/
    HAL_I2CWriteByte(VRX_IO_MAP_ADDR, VRX_REG_SDP_INTERRUPT_CLEAR, SdpIntStat);
   
}

/*==========================================================================
 * MV ISR
 *
 * Entry:  None
 * 
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 * 
 * Notes:  None
 *=========================================================================*/
ATV_ERR HAL_RXLIB_MvIsr (void)
{
    RX_MV_INTERRUPTS MvInts;
    /*RX_MCVS_STATUS MvPckt;*/
    UINT8 ByteX = 0;
    ATV_ERR RetVal = ATVERR_FAILED;
    
    /*=======================================
     * Get asserted interrupts
     *======================================*/
    HAL_RxMvGetInterrupts (&MvInts);
    

    
    if (MvInts.AGCDet)
    {
        ByteX = VRX_ret_MV_AGC_DET_RAW();
       /* MvPckt.AgcDetected = (BOOL)VRX_is_SDP_MV_AGC_DETECTED_true();
        if (VRX_is_SDP_MVCS_TYPE3_true())
        {
           MvPckt.CsType3 = TRUE;
           MvPckt.CsType2 = FALSE;
        }
        else if (VRX_is_SDP_MVCS_DETECT_true())
        {
           MvPckt.CsType2 = TRUE;
           MvPckt.CsType3 = FALSE;
        }
        else
        {
           MvPckt.CsType2 = FALSE;
           MvPckt.CsType3 = FALSE;
        }*/
       
        RX_NOTIFY_USER(RX_EVENT_MV_AGC_DET, 0, &ByteX);
        RetVal = ATVERR_OK;
    }
    if (MvInts.CSDet)
    {
        ByteX = VRX_is_MV_CS_DET_RAW_true();
       
        RX_NOTIFY_USER(RX_EVENT_MV_CS_DET, 0, &ByteX);
        RetVal = ATVERR_OK;
    }
       if (MvInts.PSDet)
    {
        ByteX = VRX_is_MV_PS_DET_RAW_true();
       
        RX_NOTIFY_USER(RX_EVENT_MV_PS_DET, 0, &ByteX);
        RetVal = ATVERR_OK;
    }
    return (RetVal);
}

/*==========================================================================
 * Finds out all the active and unmasked MV interrupts. It clears all the 
 * active interupts on return.
 *
 * Entry:   MvSdpInts = is a BOOL array that contains status of all the MV
 *                      interrupts
 * 
 * Notes:  None
 *=========================================================================*/
void HAL_RxMvGetInterrupts(RX_MV_INTERRUPTS *RxMvInts)
{
    UINT8 MvIntStat1, MvIntStat2;
    
    HAL_I2CReadByte(VRX_IO_MAP_ADDR, VRX_REG_INTERRUPT_STATUS_1, &MvIntStat2);    
    HAL_I2CReadByte(VRX_IO_MAP_ADDR, VRX_REG_INTERRUPT_STATUS_2, &MvIntStat1);    
  
    RxMvInts->AGCDet = (BOOL) (MvIntStat1 & VRX_BIT_MV_AGC_DET_ST);
    RxMvInts->CSDet = (BOOL)(MvIntStat1 & VRX_BIT_MV_CS_DET_ST);
    RxMvInts->PSDet = (BOOL)(MvIntStat2 & VRX_BIT_MV_PS_DET_ST);
   /* =========================================================================================
    * The below is done so that we only clear the interrupts that we're currently interested in
    * This way we don't inadvertently clear something that another function might need to look at
    * ===========================================================================================*/
     MvIntStat1 = RxMvInts->AGCDet | RxMvInts->CSDet;
     MvIntStat2 = RxMvInts->PSDet;
   /*==================================================================
    * Acknowledge all interrupts immediately so we don't lose any
    *=================================================================*/
    HAL_I2CWriteByte(VRX_IO_MAP_ADDR, VRX_REG_INTERRUPT_CLEAR_2, MvIntStat1);
    HAL_I2CWriteByte(VRX_IO_MAP_ADDR, VRX_REG_INTERRUPT_CLEAR_1, MvIntStat2);
   
}





/*============================================================================
 *
 * Entry:   None
 *  
 * Return:  void
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR HAL_SetSdp861RecSettings(RX_SDP_FORMAT SdpFormatIn, UINT8 Vid861Out, RX_OP_MODE OpMode)
{
    UINT8 i=0;
    
    switch (OpMode)
    {
        case RX_OPMODE_SDP_COMP:
        case RX_OPMODE_SDP_CVBS:
        case RX_OPMODE_SDP_CVBS_HDMI_MON:
        case RX_OPMODE_SDP_YC:
        case RX_OPMODE_SDP_SCART:
            ATV_I2CWriteTable ((UINT8*)SdpSyncDefault, 0);
            VRX_set_SDP_HS_WIDTH(0x000);
            while (Sdp861SettingsTable[i].I2cTable != NULL)
            {
                if (Sdp861SettingsTable[i].SdpFormatIn == SdpFormatIn)
                {
                    if (Sdp861SettingsTable[i]._861IdOut == Vid861Out)
                    {
                        HAL_RxI2CWriteTable (Sdp861SettingsTable[i].I2cTable, 0);
                        return (ATVERR_OK);
                    }
                }
                i++;
            }
            VRX_set_INV_HS_POL(0);
            VRX_set_INV_VS_POL(0);
            break;            
        default:
            return (ATVERR_INV_PARM);
    }
    return (ATVERR_OK);
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
ATV_ERR HAL_EnSdpFrameTbc(BOOL Enable)
{
    VRX_set_SDP_FR_TBC_EN(Enable);
    return (ATVERR_OK);
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
ATV_ERR HAL_InitSdpMemInterface(RX_SDP_MEM MemType)
{
    ATV_ERR RetVal = ATVERR_OK;


    VRX_set_SDP_TRI_MEMORY_IF_B(0x0);
    switch (MemType)
    {
        case RX_SDR_MEM:
            HAL_RxI2CWriteTable ((UINT8*)SdpSdrMemCfg, 0);
            VRX_set_SDP_SDRAM_MEM(1);
            VRX_set_SDP_MEM_SM_RESET(1);
            break;
        case RX_DDR_MEM:
            HAL_RxI2CWriteTable ((UINT8*)SdpDdrMemCfg, 0);
            VRX_set_SDP_SDRAM_MEM(0);
            VRX_set_SDP_MEM_SM_RESET(1);
            break;
       default:
            RetVal = ATVERR_INV_PARM;
            break;
    }
    return (RetVal);
}

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
ATV_ERR HAL_RxSetCscMode(RX_CSC_MODE Mode, RX_CSC Csc)
{
   switch(Csc)
    {
       
        case RX_CP_CSC:
            switch(Mode)
            {
                case RX_CS_AUTO_EN:
                   VRX_set_MAN_CP_CSC_EN(0);
                    break;
                case RX_CS_MAN_EN:
                   VRX_set_MAN_CP_CSC_EN(1);
                    break;
                case RX_CS_MAN_DIS:
                   return (ATVERR_INV_PARM);
                default:
                    return (ATVERR_INV_PARM);
            }
            break;
        case RX_SDP_CSC:
            return (ATVERR_INV_PARM);
        default:
            return (ATVERR_INV_PARM);
    }
    return (ATVERR_OK);
}
/*============================================================================
 * Return the enable mode a CSC is set into
 *
 * Entry:   EnMode: The enable mode the CSC is set into
 *          Csc: Specifies the CSC
 *
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_INV_PARM = Invalid parameter
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR HAL_RxGetCscMode(RX_CSC_MODE *Mode, RX_CSC Csc)
{
    switch(Csc)
    {
        
        case RX_CP_CSC:
           
                if(VRX_is_MAN_CP_CSC_EN_true())
                {
                    *Mode = RX_CS_MAN_EN;
                }
                else
                {
                    *Mode = RX_CS_AUTO_EN;
                }
            break;
        case RX_SDP_CSC:
            *Mode = RX_CS_AUTO_EN;
            break;
        default:
            return (ATVERR_INV_PARM);
    }
    return (ATVERR_OK);
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
ATV_ERR HAL_RxSetCscConfig(RX_CSC_CONFIG Config, RX_CSC Csc)
{ 
    RX_CSC_MODE CpMode;
    ATV_ERR CpRet;

    CpRet = HAL_RxGetCscMode(&CpMode, RX_CP_CSC);
    if(CpRet != ATVERR_OK)
    {
        return (ATVERR_INV_PARM);
    }
    switch(Csc)
    {
        case RX_CP_CSC:
            switch(Config)
            {
                case RX_CS_AUTO:
                    if((CpMode == RX_CS_MAN_EN) || (CpMode == RX_CS_AUTO_EN))
                    {
                        VRX_set_CSC_COEFF_SEL(0xf);
                    }
                    else
                    {
                        return (ATVERR_FAILED);
                    }
                    break;
                case RX_CS_MAN:
                    if((CpMode == RX_CS_MAN_EN) || (CpMode == RX_CS_AUTO_EN))
                    {
                            VRX_set_CSC_COEFF_SEL(0);
                    }
                    else
                    {
                        return (ATVERR_FAILED);
                    }
                    break;
                default:
                    return (ATVERR_INV_PARM);
            }
            break;
        case RX_SDP_CSC:
            return (ATVERR_INV_PARM);
        default:
            return (ATVERR_INV_PARM);
    }
    return (ATVERR_OK);
}

/*============================================================================
 * Return the Mode a CSC is set into
 *
 * Entry:   Mode: The mode the CSC is set into
 *          Csc: Specifies the CSC
 *
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_INV_PARM = Invalid parameter
 *          ATVERR_FAILED = The configuration requested is not valid or
 *                          not possible
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR HAL_RxGetCscConfig(RX_CSC_CONFIG *Config, RX_CSC Csc)
{
    RX_CSC_MODE CpMode;
    UINT8 CscCoeffSel;

    HAL_RxGetCscMode(&CpMode, RX_CP_CSC);
    switch(Csc)
    {
        case RX_CP_CSC:
            /* Check if the CP CSC is enabled
             * This check condition my need to be reviewed as the CP CSC
             * is disabled when the out put is decimated and CP CSC in
             * auto mode
             * */
            if((CpMode == RX_CS_AUTO_EN)  || (CpMode == RX_CS_MAN_EN)) 
            {
                CscCoeffSel = VRX_ret_CSC_COEFF_SEL();
                if(CscCoeffSel == 0xf)
                {
                    *Config = RX_CS_AUTO;
                }
                else if(CscCoeffSel == 0)
                {
                     *Config = RX_CS_MAN;
                }
            }
            else
            {
                return (ATVERR_FAILED);
            }
            break;
        case RX_SDP_CSC:
                *Config = RX_CS_AUTO;
            break;
        default:
            return (ATVERR_INV_PARM);
    }
    return (ATVERR_OK);
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
ATV_ERR HAL_RxSetIpColorSpace(RX_CS_COLOR ColorSpace, RX_RANGE Range, RX_CSC Csc)
{
    RX_CSC_CONFIG CscConfig;
    ATV_ERR Ret = ATVERR_FAILED;

    Ret = HAL_RxGetCscConfig(&CscConfig, Csc);
    if(Ret != ATVERR_OK)
    {
        return (ATVERR_FAILED);
    }
    
    switch(Csc)
    {
        case RX_CP_CSC:
            
            if(CscConfig == RX_CS_AUTO)
            {
                return (HAL_RxSetAutoIpColorSpace(ColorSpace, Range, RX_CP_CSC));
            }
            break;
        case RX_SDP_CSC:
            if(CscConfig == RX_CS_AUTO)
            {
                return (HAL_RxSetAutoIpColorSpace(ColorSpace, Range, RX_SDP_CSC));
            }
            break;
        default:
            return (ATVERR_INV_PARM);
    }
    return (ATVERR_FAILED);
}
/*============================================================================
 * Set the input color space for a CSC configured in automatic mode
 *
 * Entry:   Mode: The mode the CSC is set into
 *          Csc: Specifies the CSC
 *
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_INV_PARM = Invalid parameter
 *
 * Notes:   This function does not check if the CSC is configured in automatic
 *          mode. This function simply configure the input color space of a CSC
 *          assuming that it has already been configured in automatic mode
 *
 *===========================================================================*/
ATV_ERR HAL_RxSetAutoIpColorSpace(RX_CS_COLOR ColorSpace, RX_RANGE Range, RX_CSC Csc)
{
 
    if((Csc == RX_CP_CSC) )
    {
        switch(ColorSpace)
        {
            case RX_CS_FOLLOW_INPUT:
                VRX_set_INP_COLOR_SPACE(0xf);
                break;
            case RX_CS_RGB:
                if(Range == RX_RG_16_235)
                {
                    VRX_set_INP_COLOR_SPACE(0);
                }
                else if(Range == RX_RG_0_255)
                {
                    VRX_set_INP_COLOR_SPACE(0x1);
                }
                break;
            case RX_CS_YCrCb601:
                if(Range == RX_RG_16_235)
                {
                    VRX_set_INP_COLOR_SPACE(0x2);
                }
                else if(Range == RX_RG_0_255)
                {
                    VRX_set_INP_COLOR_SPACE(0x6);
                }
                break;
            case RX_CS_YCrCb709:
                if(Range == RX_RG_16_235)
                {
                    VRX_set_INP_COLOR_SPACE(0x3);
                }
                else if(Range == RX_RG_0_255)
                {
                    VRX_set_INP_COLOR_SPACE(0x7);
                }
                break;
            case RX_CS_XVYCC601:
                VRX_set_INP_COLOR_SPACE(0x4);
                break;
            case RX_CS_XVYCC709:
                VRX_set_INP_COLOR_SPACE(0x5);
                break;
            default:
                return (ATVERR_INV_PARM);
        }
    }
    else if (Csc == RX_SDP_CSC)
    {
        return (ATVERR_INV_PARM);
    }
    else
    {
        return (ATVERR_INV_PARM);
    }
    return (ATVERR_OK);
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
ATV_ERR HAL_RxGetIpColorSpace(RX_CS_COLOR *ColorSpace, RX_RANGE *Range, RX_CSC Csc)
{
    RX_CSC_CONFIG CscConfig;
    ATV_ERR Ret= ATVERR_FAILED;

    Ret = HAL_RxGetCscConfig(&CscConfig, Csc);
    if(Ret != ATVERR_OK)
    {
        return (ATVERR_FAILED);
    }
    if(Csc == RX_CP_CSC)
    {
        if(CscConfig != RX_CS_AUTO)
        {
            return (ATVERR_FAILED);
        }
        Ret = HAL_RxGetAutoIpColorSpace(ColorSpace, Range, Csc);
        if(Ret != ATVERR_OK)
        {
            return (ATVERR_FAILED);
        }
    }
    else
    {
        return (ATVERR_INV_PARM);
    }
    return (ATVERR_OK);
    
}
/*============================================================================
 * Get the output color space for a CSC configured in automatic mode
 *
 * Entry:   Mode: Output colorspace
 *          Csc: Specifies the CSC
 *
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_INV_PARM = Invalid parameter
 *          ATVERR_ERR = the input color space is not available
 *
 * Notes:   This function does not check if the CSC is configured in automatic
 *          mode. This function simply returns the input color space of a CSC
 *          assuming that it has already been configured in automatic mode
 *
 *===========================================================================*/
ATV_ERR HAL_RxGetAutoIpColorSpace(RX_CS_COLOR *ColorSpace, RX_RANGE *Range, RX_CSC Csc)
{
    UINT8 CscConv;
    UINT8 PrimMode;
    UINT8 VidStd;


    if(Csc == RX_CP_CSC )
    {
        CscConv = VRX_ret_INP_COLOR_SPACE();
        switch(CscConv)
        {
            case 0:
                *ColorSpace = RX_CS_RGB;
                *Range = RX_RG_16_235;
                break;
            case 0x1:
                *ColorSpace = RX_CS_RGB;
                *Range = RX_RG_0_255;
                break;
            case 0x2:
                *ColorSpace = RX_CS_YCrCb601;
                *Range = RX_RG_16_235;
                break;
            case 0x3:
                *ColorSpace = RX_CS_YCrCb709;
                *Range = RX_RG_16_235;
                break;
            case 0x4:
                *ColorSpace = RX_CS_XVYCC601;
                *Range = RX_RG_0_255;
                break;
            case 0x5:
                *ColorSpace = RX_CS_XVYCC709;
                *Range = RX_RG_0_255;
                break;
            case 0x6:
                *ColorSpace = RX_CS_YCrCb601;
                *Range = RX_RG_0_255;
                break;
            case 0x7:
                *ColorSpace = RX_CS_YCrCb601;
                *Range = RX_RG_0_255;
                break;
            case 0xf:
                PrimMode = VRX_ret_PRIM_MODE();
                VidStd = VRX_ret_VID_STD();
                if((PrimMode == 0x1) && (VidStd <= 0x11))
                {
                    *ColorSpace = RX_CS_YCrCb601;
                    *Range = RX_RG_0_255;
                }
                else if((PrimMode == 0x1) && (VidStd > 0x11))
                {
                    *ColorSpace = RX_CS_YCrCb709;
                    *Range = RX_RG_0_255;
                }
                else if((PrimMode == 0x5) || (PrimMode == 0x6))
                {
                    HAL_RxGetHdmiOpColorSpace(ColorSpace);
                    HAL_RxGetHdmiOpRange(Range);
                }
                else
                {
                    return (ATVERR_FAILED);
                }
                break;
            default:
                return (ATVERR_FAILED);
        }
    }
    else
    {
        return (ATVERR_INV_PARM);
    }
    return (ATVERR_OK);
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
ATV_ERR HAL_RxSetOpColorSpace(RX_CS_COLOR ColorSpace, RX_CSC Csc)
{
   
    RX_CSC_CONFIG CscConfig;
    ATV_ERR Ret;

    Ret = HAL_RxGetCscConfig(&CscConfig, Csc);
    if(Ret != ATVERR_OK)
    {
        return (ATVERR_FAILED);
    }
    if(Csc == RX_CP_CSC)
    {
        if(CscConfig != RX_CS_AUTO)
        {
            return (ATVERR_FAILED);
        }
        Ret = HAL_RxSetAutoOpColorSpace(ColorSpace, Csc);
        if(Ret != ATVERR_OK)
        {
            return (ATVERR_FAILED);
        }
    }
    else
    {
        return (ATVERR_INV_PARM);
    }
    return (ATVERR_OK);
    
}
/*============================================================================
 * Set the output color space for a CSC configured in automatic mode
 *
 * Entry:   ColorSpace: Output colorspace
 *          Csc: Specifies the CSC
 *
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_INV_PARM = Invalid parameter
 *
 * Notes:   This function does not check if the CSC is configured in automatic
 *          mode. This function simply returns the input color space of a CSC
 *          assuming that it has already been configured in automatic mode
 *
 *===========================================================================*/
ATV_ERR HAL_RxSetAutoOpColorSpace(RX_CS_COLOR ColorSpace, RX_CSC Csc)
{
    UINT8 RgbOut = 0;
    UINT8 AltGamma = 0;
    RX_CS_COLOR IpColorSpace = RX_CS_RGB;
    RX_RANGE IpRange;

    if(Csc == RX_CP_CSC )
    {
        HAL_RxGetAutoIpColorSpace(&IpColorSpace, &IpRange, Csc);
        switch(ColorSpace)
        {
            case RX_CS_RGB:
                RgbOut = 1;
                break;
            case RX_CS_YCrCb601:
                switch(IpColorSpace)
                {
                    case RX_CS_RGB:
                        AltGamma = 0;
                        break;
                    case RX_CS_YCrCb601:
                        AltGamma = 0;
                        break;
                    case RX_CS_YCrCb709:
                        AltGamma = 1;
                        break;
                    default:
                        return (ATVERR_FAILED);
                }
                break;
            case RX_CS_YCrCb709:
                switch(IpColorSpace)
                {
                    case RX_CS_RGB:
                        AltGamma = 0;
                        break;
                    case RX_CS_YCrCb601:
                        AltGamma = 1;
                        break;
                    case RX_CS_YCrCb709:
                        AltGamma = 0;
                        break;
                    default:
                        return (ATVERR_FAILED);
                }
                break;
            default:
                return (ATVERR_INV_PARM);
        }
    }
    else
    {
        return (ATVERR_INV_PARM);
    }
    VRX_set_RGB_OUT(RgbOut);
    VRX_set_ALT_GAMMA(AltGamma);
    return (ATVERR_OK);
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
ATV_ERR HAL_RxGetOpColorSpace(RX_CS_COLOR *ColorSpace, RX_CSC Csc)
{
    RX_CSC_CONFIG CscConfig;
    ATV_ERR Ret;

    Ret = HAL_RxGetCscConfig(&CscConfig, Csc);
    if(Ret != ATVERR_OK)
    {
        return (ATVERR_FAILED);
    }
    if(Csc == RX_CP_CSC )
    {
        if(CscConfig != RX_CS_AUTO)
        {
            return (ATVERR_FAILED);
        }
        Ret = HAL_RxGetAutoOpColorSpace(ColorSpace, Csc);
        if(Ret != ATVERR_OK)
        {
            return (ATVERR_FAILED);
        }
    }
    else
    {
        return (ATVERR_INV_PARM);
    }
    return (ATVERR_OK);
}
/*============================================================================
 * Get the output color space for a CSC configured in automatic mode
 *
 * Entry:   ColorSpace: Output colorspace
 *          Csc: Specifies the CSC
 *
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_INV_PARM = Invalid parameter
 *          ATVERR_ERR = the input color space is not available
 *                       (the CSC may be set in manual mode)
 *
 * Notes:   This function does not check if the CSC is configured in automatic
 *          mode. This function simply returns the input color space of a CSC
 *          assuming that it has already been configured in automatic mode
 *
 *===========================================================================*/
ATV_ERR HAL_RxGetAutoOpColorSpace(RX_CS_COLOR *ColorSpace, RX_CSC Csc)
{
    RX_CS_COLOR IpColorSpace;
    RX_RANGE IpRange;
    UINT8 RgbOut;
    UINT8 AltGamma;

    if((Csc == RX_CP_CSC))
    {
        HAL_RxGetAutoIpColorSpace(&IpColorSpace, &IpRange, Csc);
        RgbOut = VRX_ret_RGB_OUT();
        AltGamma = VRX_ret_ALT_GAMMA();
        switch(IpColorSpace)
        {
            case RX_CS_RGB:
                if(RgbOut)
                {
                    *ColorSpace = RX_CS_RGB;
                }
                else
                {
                    if(AltGamma)
                    {
                        *ColorSpace = RX_CS_YCrCb709;
                    }
                    else
                    {
                        *ColorSpace = RX_CS_YCrCb601;
                    }
                }
                break;
            case RX_CS_YCrCb601:
                if(RgbOut)
                {
                    *ColorSpace = RX_CS_RGB;
                }
                else
                {
                    if(AltGamma)
                    {
                        *ColorSpace = RX_CS_YCrCb709;
                    }
                    else
                    {
                        *ColorSpace = RX_CS_YCrCb601;
                    }
                }
                break;
            case RX_CS_YCrCb709:
                if(RgbOut)
                {
                    *ColorSpace = RX_CS_RGB;
                }
                else
                {
                    if(AltGamma)
                    {
                        *ColorSpace = RX_CS_YCrCb601;
                    }
                    else
                    {
                        *ColorSpace = RX_CS_YCrCb709;
                    }
                }
                break;
            case RX_CS_XVYCC601:
                *ColorSpace = RX_CS_XVYCC601;
                break;
            case RX_CS_XVYCC709:
                *ColorSpace = RX_CS_XVYCC709;
                break;
            default:
                return (ATVERR_FAILED);
        }
    }
    else
    {
        return (ATVERR_INV_PARM);
    }
    return (ATVERR_OK);
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
  *         CoeffC: A pointer to 4 coefficients for channel C
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
ATV_ERR HAL_RxSetManCscCoeffs(UINT8 CscScale, UINT8* CoeffA, UINT8* CoeffB, UINT8* CoeffC, RX_CSC CSC)
{
    return (ATVERR_OK);
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
  *         CoeffC: A pointer to 4 coefficients for channel C
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
ATV_ERR HAL_RxGetManCscCoeffs(UINT8 *CscScale, UINT8* CoeffA, UINT8* CoeffB, UINT8* CoeffC, RX_CSC CSC)
{
    return (ATVERR_OK);
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
ATV_ERR HAL_EnSdpSFL(BOOL Enable)
{
    VRX_set_SDP_SFL_EN(Enable); 
    return (ATVERR_OK);
}

/*============================================================================
 * This function sets 861 related settings i.e. sync adjustment and sync 
 * polarity for inputs processed via the CP section
 * 
 * Entry:   Vid861 = CEA-861 Vic. Set to 0 for VESA or any other formats
 *          OperatingMode = Graphics, Comp or HDMI.
 *  
 * Return:  ATVERR_OK
 *          ATVERR_INV_PARM: Combination of Vid861 and operating mode not
 *                           supported
 *
 * Notes:   This function should be called periodically by the application
 *
 *===========================================================================*/
ATV_ERR HAL_CpSet861RecSettings(UINT8 Vid861, RX_OP_MODE OperatingMode)
{
    switch(OperatingMode)
    {
        case RX_OPMODE_COMP:
        case RX_OPMODE_GR:
            switch(Vid861)
            {
                /* CP Core mode doesn't require Addition Adjustment in 7844 */
                /* 
                case 2: 
                case 3:   
                    ATV_I2CWriteTable((UCHAR *)RxCeaId02RecSettingTable, 0);
                    break;
                case 6: 
                case 7:
                    ATV_I2CWriteTable((UCHAR *)RxCeaId06RecSettingTable, 0);
                    break;
                case 21:
                case 22:
                    ATV_I2CWriteTable((UCHAR *)RxCeaId21RecSettingTable, 0);
                    break;
                */
                case 0:
                default:
                    ATV_I2CWriteTable((UCHAR *)RxCeaId00RecSettingTable, 0);
                    break;
            }
            break;
        case RX_OPMODE_HDMI:
            ATV_I2CWriteTable((UCHAR *)RxCeaId00RecSettingTable, 0);
            break;            
        default:
            return (ATVERR_INV_PARM);
    }
    if (Vid861)
    {
        VRX_set_INV_HS_POL((Vid861==39)?1:CeaVsyncPol[Vid861]);
        VRX_set_INV_VS_POL(CeaVsyncPol[Vid861]);
    }
    else
    {
        VRX_set_INV_HS_POL(0);
        VRX_set_INV_VS_POL(0);
    }
    return (ATVERR_OK);
}

/*============================================================================
 * This function is used to enable or disable CP events
 *
 * Entry:   EventList: A pointer to a list of CP event that must be enabled
 *                     Non CP event are discared by this function
 *          ListSize: The number of event in the listed pointed by EvntList
 *          Enable: TRUE = List of events pointed by EventList must be enabled
 *                  FALSE = List of events pointed by EventList must be disabled
 *  
 * Return:  
 *
 * Notes:   None
 *
 *===========================================================================*/
UCHAR HAL_RxCpSetEnabledEvents (RX_EVENT *EventList, UCHAR ListSize, BOOL Enable)
{
    UINT8 i, j, IntIdx, IntCount=0, MaskVal[NOF_RX_MASK_REGS];
    IntIdx = HAL_RxGetIntIndex();

    /*=======================================
     * Get interrupt mask values
     *======================================*/
    for (i=0; RxCpMaskRegs[i]; i+=3)
    {
        HAL_I2CReadByte(VRX_IO_MAP_ADDR, RxCpMaskRegs[IntIdx+i], &(MaskVal[RxCpMaskRegs[i+2]]));
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
        switch(EventList[i])
        {
            case RX_EVENT_CP_STDI_LCK:
                VRX_set_STDI_DATA_VALID_EDGE_SEL((Enable)? 1: 0);
                break;
            default:
                break;
        }
    }

    /*=======================================
     * Update interrupt masks
     *======================================*/
    for (i=0; RxCpMaskRegs[i]; i+=3)
    {
        HAL_I2CWriteByte(VRX_IO_MAP_ADDR, RxCpMaskRegs[IntIdx+i], MaskVal[RxCpMaskRegs[i+2]]);
    }

    /*=======================================
     * Clear masks for unused interrupt
     *======================================*/
    IntIdx = (~IntIdx) & 1;
    for (i=0; RxCpMaskRegs[i]; i+=3)
    {
        HAL_I2CWriteByte(VRX_IO_MAP_ADDR, RxCpMaskRegs[IntIdx+i], 0);
    }
  
    return(IntCount);
}

/*============================================================================
 * This function is used to if CP events that can't be notified by the 
 * ISR have occurred
 *
 * Entry:   None
 *  
 * Return:  void
 *
 * Notes:   None
 *
 *===========================================================================*/
void HAL_RxCpHouseKeeping (void)
{
    BOOL StdiLock, SspdLock;
    UINT8 ByteX;
    RX_SYNC_CH SyncCh;
    
    if (RX_EVENT_IS_ENABLED(RX_EVENT_CP_STDI_LCK))
    {
        ADIAPI_RxCpGetMainSyncCh (&SyncCh);
        ADIAPI_RxCpGetSspdStatus (&SspdLock, SyncCh);
        ADIAPI_RxCpGetStdiStatus (&StdiLock, SyncCh);
        if (SspdLock != CurrSspdLock)
        {
            CurrSspdLock = SspdLock;
            ByteX = ((SspdLock && StdiLock) ? 1 :0); 
            RX_NOTIFY_USER(RX_EVENT_CP_STDI_LCK, 0, &ByteX);
        }
    }

    if (RX_EVENT_IS_ENABLED(RX_EVENT_CP_STDI_LCK_SYNC_CH1)) 
    {
        ADIAPI_RxCpGetSspdStatus (&SspdLock, RX_SYNC_CH1);
        ADIAPI_RxCpGetStdiStatus (&StdiLock, RX_SYNC_CH1);
        if (SspdLock != CurrSspdLockCh1)
        {
            CurrSspdLockCh1 = SspdLock;
            ByteX = ((SspdLock && StdiLock) ? 1:0); 
            RX_NOTIFY_USER(RX_EVENT_CP_STDI_LCK_SYNC_CH1, 0, &ByteX);
        }
    }

    if (RX_EVENT_IS_ENABLED(RX_EVENT_CP_STDI_LCK_SYNC_CH2))
    {
        ADIAPI_RxCpGetSspdStatus (&SspdLock, RX_SYNC_CH2);
        ADIAPI_RxCpGetStdiStatus (&StdiLock, RX_SYNC_CH2);
        if (SspdLock != CurrSspdLockCh2)
        {
            CurrSspdLockCh2 = SspdLock;
            ByteX = ((SspdLock && StdiLock) ? 1:0); 
            RX_NOTIFY_USER(RX_EVENT_CP_STDI_LCK_SYNC_CH2, 0, &ByteX);
        }
    }
}

/*==========================================================================
 * 
 * 
 *
 *=========================================================================*/
ATV_ERR HAL_RxVdpEnable(BOOL Enable)
{
    ADIAPI_RxManagePower (RX_VDP, Enable);
    return (ATVERR_OK);
}
/*==========================================================================
 * 
 * 
 *
 *=========================================================================*/
ATV_ERR HAL_RxSetPixelClkFreq (RX_PIX_CLK_FREQ PixClkFreq, BOOL Enable)
{
    ATV_ERR ErrVal = ATVERR_OK;
   

    switch (PixClkFreq)
    {
        
        case RX_2X_CLK:
          if (Enable)
          {
             VRX_set_LLC_DLL_MUX(1);
             VRX_set_LLC_DLL_EN(1);
             VRX_set_LLC_DLL_DOUBLE_EN(1);
           }
           else
           { 
              VRX_set_LLC_DLL_DOUBLE_EN(0);
            }
            break;
       
        default:
            
            ErrVal = ATVERR_INV_PARM;
            break;
    }        
    return (ErrVal);
}
#if (RX_DEVICE == 7844)
/*==========================================================================
 * Enable/Disable RX ARC
 *
 * Entry:   Mode = RX_ARC_SINGLE    --Not Supported on ADV7844
 *                 RX_ARC_COMMON    --Supported on ADV7844 turn on ARC
 *                 RX_ARC_OFF       -- Turn off ARC.
 *
 * Return:  ATVERR_OK
 *          ATVERR_INV_PARM 
 * Notes:
 *
 *=========================================================================*/
ATV_ERR HAL_RxHdmiSetArcMode (RX_ARC_MODE Mode, RX_ARC_TX ArcTx)
{
    if(ArcTx >1 )
    {
        return (ATVERR_INV_PARM);
    }
    switch(Mode)
    {
        case RX_ARC_SINGLE:
               return (ATVERR_INV_PARM);
        case RX_ARC_COMMON:
               switch(ArcTx)
               {
                    case RX_ARC_TX1:
                        VRX_set_ARC_1_PWRDN(0);
                        break;
                    
                    case RX_ARC_TX2:
                         VRX_set_ARC_2_PWRDN(0);
                         break;
                    default:
                        return (ATVERR_INV_PARM);   
               }
                break;
        case RX_ARC_OFF:
               switch(ArcTx)
               {
                    case RX_ARC_TX1:
                        VRX_set_ARC_1_PWRDN(1);
                        break;
                    
                    case RX_ARC_TX2:
                         VRX_set_ARC_2_PWRDN(1);
                         break;
                    default:
                        return (ATVERR_INV_PARM);   
               }
               break;
        default:
                 return (ATVERR_INV_PARM);
             
    }
    return (ATVERR_OK);
   
}

/*============================================================================
 * Enable/Disable fast switching on specified port
 *
 * Entry:   Port   = Port to set Bstatus for
 *          Enable = TRUE/FALSE to enable/disable fast switching
 *
 * Return:  ATVERR_OK = Indicates the function completed successfully
 *
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR HAL_RxSetFastSwitchPort (RX_HDMI_PORT Port, BOOL Enable)
{
    UCHAR En;
    ATV_ERR RetVal = ATVERR_OK;

    En = Enable? 1: 0;

	
    switch (Port)
    {
        case PORT_A:
            VRX_set_EN_BG_PORT_A(En);
            VRX_set_FULL_PWR_BG_PORT_A(En);
            break;
        case PORT_B:
            VRX_set_EN_BG_PORT_B(En);
            VRX_set_FULL_PWR_BG_PORT_B(En);
            break;
        case PORT_C:
            VRX_set_EN_BG_PORT_C(En);
            VRX_set_FULL_PWR_BG_PORT_C(En);
            break;
        case PORT_D:
            VRX_set_EN_BG_PORT_D(En);
            VRX_set_FULL_PWR_BG_PORT_D(En);
            break;
        case PORT_ALL:
            VRX_set_EN_BG_PORT_A(En);
            VRX_set_EN_BG_PORT_B(En);
            VRX_set_EN_BG_PORT_C(En);
            VRX_set_EN_BG_PORT_D(En);
            VRX_set_FULL_PWR_BG_PORT_A(En);
            VRX_set_FULL_PWR_BG_PORT_B(En);
            VRX_set_FULL_PWR_BG_PORT_C(En);
            VRX_set_FULL_PWR_BG_PORT_D(En);
            break;
        default:
            RetVal = ATVERR_INV_PARM;
            break;
    }
    VRX_set_FR_BG_PORTS(En);        /* If enabling fast switching-enable Freerun BG ports*/
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
ATV_ERR HAL_SetManagePower(RX_CHIP_SECTION Section, BOOL PowerUp)
{
    ATV_ERR ErrVal;
    ErrVal = ATVERR_OK;
    switch(Section)
    {
        case RX_ALL_SECTIONS:
            VRX_set_POWER_DOWN(!PowerUp);
            break;
        case RX_CP:
            VRX_set_CP_PWRDN(!PowerUp);
            break;
        case RX_XTAL:
            VRX_set_XTAL_PDN(!PowerUp);
            break;
        case RX_ALL_CORES:
            VRX_set_CORE_PDN(!PowerUp);
            break;
        case RX_VDP:
            VRX_set_VDP_PDN(!PowerUp);
            break;
        case RX_ALL_ADC_CCT:
            VRX_set_PDN_ADC0(!PowerUp);
            VRX_set_PDN_ADC1(!PowerUp);
            VRX_set_PDN_ADC2(!PowerUp);
            VRX_set_PDN_ADC3(!PowerUp);
            break;
        case RX_ADC0_CCT:
            VRX_set_PDN_ADC0(!PowerUp);
            break;
        case RX_ADC1_CCT:
            VRX_set_PDN_ADC1(!PowerUp);
            break;
        case RX_ADC2_CCT:
            VRX_set_PDN_ADC2(!PowerUp);
            break;
        case RX_ADC3_CCT:
            VRX_set_PDN_ADC3(!PowerUp);
            break;
        case RX_CEC_CTRL:
            VRX_set_CEC_POWER_UP(PowerUp);
            break;
        case RX_AVLINK_CTRL:
            VRX_set_AVL_AVLINK_POWER_UP(PowerUp);
            break;
        case RX_ETH1:
            VRX_set_ETH_1_PWRDN((PowerUp?0:1));
            break;
        case RX_ETH2:
            VRX_set_ETH_2_PWRDN((PowerUp?0:1));
            break;
        case RX_HEC1:
            VRX_set_HEC_1_PWRDN((PowerUp?0:1));
            break;
        case RX_HEC2:
            VRX_set_HEC_2_PWRDN((PowerUp?0:1));
            break;
        default:
            ErrVal= ATVERR_INV_PARM;
            break;
    }
    return (ErrVal);
}


/*===========================================================================
 * Set and enable Rx internal EDID for all ports
 *
 * Entry:   EdidBuf   = Pointer to 256 byte buffer containing EDID data
 *          SpaOffset = Offset of SPA in the buffer. 0 to ignore spa seetings
 *                      in SpaValues
 *          SpaValues = Array of SPA values for port B, C and D (2 bytes/port)
 *                      First byte contains A.B, second contains C.D
 *                      if SpaOffset ise set to 0, this parameter is ignored
 *          Segment   = 0 or 1
 *
 * Return:  ATVERR_OK
 *
 * Notes:   This function DOES NOT change HPD state for any of the ports
 *
 *==========================================================================*/
 ATV_ERR HAL_RxHdmiSetInternalEdid (UCHAR *EdidBuffer, UINT16 SpaOffset, 
                        UCHAR *SpaValues, UCHAR SegNum, BOOL DisableAutoEdid)
{
    HAL_RxPopulateEdidMap (EdidBuffer, 256, SegNum);
    if (SpaOffset && SpaValues)
    {
        HAL_RxSetSpas(SpaOffset, SpaValues);
    }
    HAL_RxToggleInternalEdid();
    return (ATVERR_OK);
}

#endif
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
 * Notes:   There is only one internal EDID RAM.Therefore a HDMI EDID second segmen
 *           cannot be available at the same time the VGA EDID feature is being used.
 *
 *===========================================================================*/
ATV_ERR HAL_RxEnInternalVgaEdid (UCHAR * EdidBuffer, BOOL Enable)
{
    /* UCHAR EdidCtrl;
       UCHAR ByteX = 0;*/
                 
    if(Enable)
    {
       /* HAL_I2CReadByte(VRX_REPEATER_MAP_ADDR, VRX_REG_HDCP_EDID_CONTROLS, &EdidCtrl);
        ByteX |= VRX_BIT_EDID_A_ENABLE | VRX_BIT_EDID_B_ENABLE |
                 VRX_BIT_EDID_C_ENABLE | VRX_BIT_EDID_D_ENABLE;
        EdidCtrl &= ~ByteX;
   
        HAL_I2CWriteByte(VRX_REPEATER_MAP_ADDR, VRX_REG_HDCP_EDID_CONTROLS, EdidCtrl);*/
        HAL_RxPopulateEdidMap (EdidBuffer, 128, 0x1);
           
    }
    VRX_set_VGA_PWRDN(!Enable);
    VRX_set_VGA_EDID_ENABLE(Enable);
    return (ATVERR_OK);
}
 /*============================================================================
 *
 *===========================================================================*/
ATV_ERR HAL_SpiEdidEnable(BOOL Enable)
{
    return (ATVERR_NOT_AVAILABLE);
}

/*==========================================================================
 * Function to configure the dedicated I2C interface for VDP extraction
 * Can be enabled or Disabled
 *
 * Entry:  Enable, 
 *          TRUE  - Enable the Fast I2C interface 
 *          FALSE - Disable the Fast I2C Interface

 * 
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 * 
 * Notes:  None
 *=========================================================================*/
ATV_ERR HAL_RxVdpEnFastI2cInterface(BOOL Enable)
{
	VRX_set_SUBI2C_EN(Enable);
	VRX_set_VDP_ON_SUB_I2C(Enable);
	return ATVERR_OK;
	
}
ATV_ERR HAL_RxVdpEnFastRbDataType(RX_VBI_TYPE DataType, BOOL Enable)
{
    switch(DataType)
    {
        case RX_NO_VBI:
            VRX_set_VDP_FAST_REG_CONF_TTXT(0);
            VRX_set_VDP_FAST_REG_CONF_VPS_CGMSTB(0);
            VRX_set_VDP_FAST_REG_CONF_VITC(0);
            VRX_set_VDP_FAST_REG_CONF_CGMS_WSS(0);
            VRX_set_VDP_FAST_REG_CONF_GEM1X_2X(0);
            VRX_set_VDP_FAST_REG_CONF_CCAP(0);
            break;
        case RX_GEMS:
            VRX_set_VDP_FAST_REG_CONF_GEM1X_2X(Enable);
            break;
       case RX_TTXT:
            VRX_set_VDP_FAST_REG_CONF_TTXT(Enable);
            break;
        case RX_VPS:
            VRX_set_VDP_FAST_REG_CONF_VPS_CGMSTB(Enable);
            break;
        case RX_VITC:
            VRX_set_VDP_FAST_REG_CONF_VITC(Enable);
            break;
        case RX_CCAP:
            VRX_set_VDP_FAST_REG_CONF_CCAP(Enable);
            break;
        case RX_CGMS:
        case RX_WSS:
            VRX_set_VDP_FAST_REG_CONF_CGMS_WSS(Enable);
            break;
        default:
            return ATVERR_INV_PARM;
    }
    return ATVERR_OK;
    
    
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
ATV_ERR HAL_RxDppFiltMode(RX_FILT_MODE FiltMode)
{
    UINT8 Val;
    
    switch(FiltMode)
    {
        case RX_FILTER_DOWNSAMPLE:
            Val = 0;
            break;
        case RX_DOWNSAMPLE_ONLY:
            Val = 1;
            break;
        default:
            return (ATVERR_INV_PARM);
    }
    VRX_set_DS_WITHOUT_FILTER(Val);
    if(VRX_is_DPP_BYPASS_EN_true())
    {
        return (ATVERR_FAILED);
    }
    return (ATVERR_OK); 
}
#endif
