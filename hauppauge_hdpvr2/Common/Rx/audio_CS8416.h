#pragma once

/*+++ *******************************************************************\
*
*  Copyright and Disclaimer:
*
*     ---------------------------------------------------------------
*     This software is provided "AS IS" without warranty of any kind,
*     either expressed or implied, including but not limited to the
*     implied warranties of noninfringement, merchantability and/or
*     fitness for a particular purpose.
*     ---------------------------------------------------------------
*
*     Copyright (c) 2011 Hauppauge Computer Works, Inc.
*     All rights reserved.
*
\******************************************************************* ---*/

#ifndef _AUDIO_CS8416_H_
#define _AUDIO_CS8416_H_

#include <mutex>

#include "FX2Device.h"

/* Control0 [R/W] bits definition */
#define CTRL0_TRUNC          0x04
#define CTRL0_PDUR           0x08
#define CTRL0_FSWCLK         0x40

/* Control1 [R/W] bits definition */
#define CTRL1_CHS            0x01
#define CTRL1_RMCKF          0x02
#define CTRL1_HOLD0          0x04
#define CTRL1_HOLD1          0x08
#define CTRL1_INT0           0x10
#define CTRL1_INT1           0x20
#define CTRL1_MUTSAO         0x40
#define CTRL1_SWCLK          0x80

/* Control2 [R/W] bits definition */
#define CTRL2_GPO0SEL0       0x01
#define CTRL2_GPO0SEL1       0x02
#define CTRL2_GPO0SEL2       0x04
#define CTRL2_GPO0SEL3       0x08
#define CTRL2_EMPH_CNTL0     0x10
#define CTRL2_EMPH_CNTL1     0x20
#define CTRL2_EMPH_CNTL2     0x40
#define CTRL2_DETCI          0x80

/* Control3 [R/W] bits definition */
#define CTRL3_GPO2SEL0       0x01
#define CTRL3_GPO2SEL1       0x02
#define CTRL3_GPO2SEL2       0x04
#define CTRL3_GPO2SEL3       0x08
#define CTRL3_GPO1SEL0       0x10
#define CTRL3_GPO1SEL1       0x20
#define CTRL3_GPO1SEL2       0x40
#define CTRL3_GPO1SEL3       0x80

/* Control4 [R/W] bits definition */
#define CTRL4_TXSEL0         0x01
#define CTRL4_TXSEL1         0x02
#define CTRL4_TXSEL2         0x04
#define CTRL4_RXSEL0         0x08
#define CTRL4_RXSEL1         0x10
#define CTRL4_RXSEL2         0x20
#define CTRL4_RXD            0x40
#define CTRL4_RUN            0x80

/* Serial Audio Data Format [R/W] bits definition */
#define ASERFMT_SOLRPOL      0x01
#define ASERFMT_SOSPOL       0x02
#define ASERFMT_SODEL        0x04
#define ASERFMT_SOJUST       0x08
#define ASERFMT_SORES0       0x10
#define ASERFMT_SORES1       0x20
#define ASERFMT_SOSF         0x40
#define ASERFMT_SOMS         0x80

/* Receiver Error Mask [R/W] bits definition */
#define RXEMSK_PARM          0x01
#define RXEMSK_BIPM          0x02
#define RXEMSK_CONFM         0x04
#define RXEMSK_VM            0x08
#define RXEMSK_UNLOCKM       0x10
#define RXEMSK_CCRCM         0x20
#define RXEMSK_QCRCM         0x40

/* Interrupt Mask [R/W] bits definition */
#define INTMSK_FCHM          0x01
#define INTMSK_QCHM          0x02
#define INTMSK_RERRM         0x04
#define INTMSK_CCHM          0x08
#define INTMSK_DETCM         0x10
#define INTMSK_OSLIPM        0x20
#define INTMSK_PCCHM         0x40

/* Interrupt Mode MSB [R/W] bits definition */
#define INTMODH_FCH1         0x01
#define INTMODH_QCH1         0x02
#define INTMODH_RERR1        0x04
#define INTMODH_CCH1         0x08
#define INTMODH_DETC1        0x10
#define INTMODH_OSLIP1       0x20
#define INTMODH_PCCH1        0x40

/* Interrupt Mode LSB [R/W] bits definition */
#define INTMODL_FCH0         0x01
#define INTMODL_QCH0         0x02
#define INTMODL_RERR0        0x04
#define INTMODL_CCH0         0x08
#define INTMODL_DETC0        0x10
#define INTMODL_OSLIP0       0x20
#define INTMODL_PCCH0        0x40

/* Receiver Channel Status [R] bits definition */
#define RXCSTAT_EMPH         0x01
#define RXCSTAT_ORIG         0x02
#define RXCSTAT_COPY         0x04
#define RXCSTAT_PRO          0x08
#define RXCSTAT_AUX0         0x10
#define RXCSTAT_AUX1         0x20
#define RXCSTAT_AUX2         0x40
#define RXCSTAT_AUX3         0x80

/* Audio Format Detect [R] bits definition */
#define AFMTD_96KHZ          0x01
#define AFMTD_DGTL_SIL       0x02
#define AFMTD_DTS_CD         0x08
#define AFMTD_DTS_LD         0x10
#define AFMTD_IEC61937       0x20
#define AFMTD_PCM            0x40

/* Receiver Error [R] bits definition */
#define RXERR_PAR            0x01
#define RXERR_BIP            0x02
#define RXERR_CONF           0x04
#define RXERR_V              0x08
#define RXERR_UNLOCK         0x10
#define RXERR_CCRC           0x20
#define RXERR_QCRC           0x40

/* Interrupt Status [R] bits definition */
#define INTSTAT_FCH          0x01
#define INTSTAT_QCH          0x02
#define INTSTAT_RERR         0x04
#define INTSTAT_CCH          0x08
#define INTSTAT_DETC         0x10
#define INTSTAT_OSLIP        0x20
#define INTSTAT_PCCH         0x40

/* Q-Channel Subcode [0:7] [R] bits definition */
#define CHANSUB0_ADDRESS0    0x01
#define CHANSUB0_ADDRESS1    0x02
#define CHANSUB0_ADDRESS2    0x04
#define CHANSUB0_ADDRESS3    0x08
#define CHANSUB0_CONTROL0    0x10
#define CHANSUB0_CONTROL1    0x20
#define CHANSUB0_CONTROL2    0x40
#define CHANSUB0_CONTROL3    0x80

/* Q-Channel Subcode [8:15] [R] bits definition */
#define CHANSUB1_TRACK0      0x01
#define CHANSUB1_TRACK1      0x02
#define CHANSUB1_TRACK2      0x04
#define CHANSUB1_TRACK3      0x08
#define CHANSUB1_TRACK4      0x10
#define CHANSUB1_TRACK5      0x20
#define CHANSUB1_TRACK6      0x40
#define CHANSUB1_TRACK7      0x80

/* Q-Channel Subcode [16:23] [R] bits definition */
#define CHANSUB2_INDEX0      0x01
#define CHANSUB2_INDEX1      0x02
#define CHANSUB2_INDEX2      0x04
#define CHANSUB2_INDEX3      0x08
#define CHANSUB2_INDEX4      0x10
#define CHANSUB2_INDEX5      0x20
#define CHANSUB2_INDEX6      0x40
#define CHANSUB2_INDEX7      0x80

/* Q-Channel Subcode [24:31] [R] bits definition */
#define CHANSUB3_MINUTE0     0x01
#define CHANSUB3_MINUTE1     0x02
#define CHANSUB3_MINUTE2     0x04
#define CHANSUB3_MINUTE3     0x08
#define CHANSUB3_MINUTE4     0x10
#define CHANSUB3_MINUTE5     0x20
#define CHANSUB3_MINUTE6     0x40
#define CHANSUB3_MINUTE7     0x80

/* Q-Channel Subcode [32:39] [R] bits definition */
#define CHANSUB4_SECOND0     0x01
#define CHANSUB4_SECOND1     0x02
#define CHANSUB4_SECOND2     0x04
#define CHANSUB4_SECOND3     0x08
#define CHANSUB4_SECOND4     0x10
#define CHANSUB4_SECOND5     0x20
#define CHANSUB4_SECOND6     0x40
#define CHANSUB4_SECOND7     0x80

/* Q-Channel Subcode [40:47] [R] bits definition */
#define CHANSUB5_FRAME0      0x01
#define CHANSUB5_FRAME1      0x02
#define CHANSUB5_FRAME2      0x04
#define CHANSUB5_FRAME3      0x08
#define CHANSUB5_FRAME4      0x10
#define CHANSUB5_FRAME5      0x20
#define CHANSUB5_FRAME6      0x40
#define CHANSUB5_FRAME7      0x80

/* Q-Channel Subcode [48:55] [R] bits definition */
#define CHANSUB6_ZERO0       0x01
#define CHANSUB6_ZERO1       0x02
#define CHANSUB6_ZERO2       0x04
#define CHANSUB6_ZERO3       0x08
#define CHANSUB6_ZERO4       0x10
#define CHANSUB6_ZERO5       0x20
#define CHANSUB6_ZERO6       0x40
#define CHANSUB6_ZERO7       0x80

/* Q-Channel Subcode [56:63] [R] bits definition */
#define CHANSUB7_ABS_MINUTE0 0x01
#define CHANSUB7_ABS_MINUTE1 0x02
#define CHANSUB7_ABS_MINUTE2 0x04
#define CHANSUB7_ABS_MINUTE3 0x08
#define CHANSUB7_ABS_MINUTE4 0x10
#define CHANSUB7_ABS_MINUTE5 0x20
#define CHANSUB7_ABS_MINUTE6 0x40
#define CHANSUB7_ABS_MINUTE7 0x80

/* _Q-Channel Subcode [64:71] [R] bits definition */
#define CHANSUB8_ABS_SECOND0 0x01
#define CHANSUB8_ABS_SECOND1 0x02
#define CHANSUB8_ABS_SECOND2 0x04
#define CHANSUB8_ABS_SECOND3 0x08
#define CHANSUB8_ABS_SECOND4 0x10
#define CHANSUB8_ABS_SECOND5 0x20
#define CHANSUB8_ABS_SECOND6 0x40
#define CHANSUB8_ABS_SECOND7 0x80

/* Q-Channel Subcode [72:79] [R] bits definition */
#define CHANSUB9_ABS_FRAME0  0x01
#define CHANSUB9_ABS_FRAME1  0x02
#define CHANSUB9_ABS_FRAME2  0x04
#define CHANSUB9_ABS_FRAME3  0x08
#define CHANSUB9_ABS_FRAME4  0x10
#define CHANSUB9_ABS_FRAME5  0x20
#define CHANSUB9_ABS_FRAME6  0x40
#define CHANSUB9_ABS_FRAME7  0x80

/* OMCK_RMCK Ratio [R] bits definition */
#define OMRMRAT_ORR0         0x01
#define OMRMRAT_ORR1         0x02
#define OMRMRAT_ORR2         0x04
#define OMRMRAT_ORR3         0x08
#define OMRMRAT_ORR4         0x10
#define OMRMRAT_ORR5         0x20
#define OMRMRAT_ORR6         0x40
#define OMRMRAT_ORR7         0x80

/* Channel A Status [R] bits definition */
#define CHANAST0_AC0_0       0x01
#define CHANAST0_AC0_1       0x02
#define CHANAST0_AC0_2       0x04
#define CHANAST0_AC0_3       0x08
#define CHANAST0_AC0_4       0x10
#define CHANAST0_AC0_5       0x20
#define CHANAST0_AC0_6       0x40
#define CHANAST0_AC0_7       0x80

/* Channel A Status [R] bits definition */
#define CHANAST1_AC1_0       0x01
#define CHANAST1_AC1_1       0x02
#define CHANAST1_AC1_2       0x04
#define CHANAST1_AC1_3       0x08
#define CHANAST1_AC1_4       0x10
#define CHANAST1_AC1_5       0x20
#define CHANAST1_AC1_6       0x40
#define CHANAST1_AC1_7       0x80

/* Channel A Status [R] bits definition */
#define CHANAST2_AC2_0       0x01
#define CHANAST2_AC2_1       0x02
#define CHANAST2_AC2_2       0x04
#define CHANAST2_AC2_3       0x08
#define CHANAST2_AC2_4       0x10
#define CHANAST2_AC2_5       0x20
#define CHANAST2_AC2_6       0x40
#define CHANAST2_AC2_7       0x80

/* Channel A Status [R] bits definition */
#define CHANAST3_AC3_0       0x01
#define CHANAST3_AC3_1       0x02
#define CHANAST3_AC3_2       0x04
#define CHANAST3_AC3_3       0x08
#define CHANAST3_AC3_4       0x10
#define CHANAST3_AC3_5       0x20
#define CHANAST3_AC3_6       0x40
#define CHANAST3_AC3_7       0x80

/* Channel A Status [R] bits definition */
#define CHANAST4_AC4_0       0x01
#define CHANAST4_AC4_1       0x02
#define CHANAST4_AC4_2       0x04
#define CHANAST4_AC4_3       0x08
#define CHANAST4_AC4_4       0x10
#define CHANAST4_AC4_5       0x20
#define CHANAST4_AC4_6       0x40
#define CHANAST4_AC4_7       0x80

/* Channel B Status [R] bits definition */
#define CHANBST0_BC0_0       0x01
#define CHANBST0_BC0_1       0x02
#define CHANBST0_BC0_2       0x04
#define CHANBST0_BC0_3       0x08
#define CHANBST0_BC0_4       0x10
#define CHANBST0_BC0_5       0x20
#define CHANBST0_BC0_6       0x40
#define CHANBST0_BC0_7       0x80

/* Channel B Status [R] bits definition */
#define CHANBST1_BC1_0       0x01
#define CHANBST1_BC1_1       0x02
#define CHANBST1_BC1_2       0x04
#define CHANBST1_BC1_3       0x08
#define CHANBST1_BC1_4       0x10
#define CHANBST1_BC1_5       0x20
#define CHANBST1_BC1_6       0x40
#define CHANBST1_BC1_7       0x80

/* Channel B Status [R] bits definition */
#define CHANBST2_BC2_0       0x01
#define CHANBST2_BC2_1       0x02
#define CHANBST2_BC2_2       0x04
#define CHANBST2_BC2_3       0x08
#define CHANBST2_BC2_4       0x10
#define CHANBST2_BC2_5       0x20
#define CHANBST2_BC2_6       0x40
#define CHANBST2_BC2_7       0x80

/* Channel B Status [R] bits definition */
#define CHANBST3_BC3_0       0x01
#define CHANBST3_BC3_1       0x02
#define CHANBST3_BC3_2       0x04
#define CHANBST3_BC3_3       0x08
#define CHANBST3_BC3_4       0x10
#define CHANBST3_BC3_5       0x20
#define CHANBST3_BC3_6       0x40
#define CHANBST3_BC3_7       0x80

/* Channel B Status [R] bits definition */
#define CHANBST4_BC4_0       0x01
#define CHANBST4_BC4_1       0x02
#define CHANBST4_BC4_2       0x04
#define CHANBST4_BC4_3       0x08
#define CHANBST4_BC4_4       0x10
#define CHANBST4_BC4_5       0x20
#define CHANBST4_BC4_6       0x40
#define CHANBST4_BC4_7       0x80

/* Burst Preamble PC Byte 0 [R] bits definition */
#define BRSTPREAPC0_PC0_0    0x01
#define BRSTPREAPC0_PC0_1    0x02
#define BRSTPREAPC0_PC0_2    0x04
#define BRSTPREAPC0_PC0_3    0x08
#define BRSTPREAPC0_PC0_4    0x10
#define BRSTPREAPC0_PC0_5    0x20
#define BRSTPREAPC0_PC0_6    0x40
#define BRSTPREAPC0_PC0_7    0x80

/* Burst Preamble PC Byte 1 [R] bits definition */
#define BRSTPREAPC1_PC1_0    0x01
#define BRSTPREAPC1_PC1_1    0x02
#define BRSTPREAPC1_PC1_2    0x04
#define BRSTPREAPC1_PC1_3    0x08
#define BRSTPREAPC1_PC1_4    0x10
#define BRSTPREAPC1_PC1_5    0x20
#define BRSTPREAPC1_PC1_6    0x40
#define BRSTPREAPC1_PC1_7    0x80

/* Burst Preamble PD Byte 0 [R] bits definition */
#define BRSTPREAPD0_PD0_0    0x01
#define BRSTPREAPD0_PD0_1    0x02
#define BRSTPREAPD0_PD0_2    0x04
#define BRSTPREAPD0_PD0_3    0x08
#define BRSTPREAPD0_PD0_4    0x10
#define BRSTPREAPD0_PD0_5    0x20
#define BRSTPREAPD0_PD0_6    0x40
#define BRSTPREAPD0_PD0_7    0x80

/* Burst Preamble PD Byte 1 [R] bits definition */
#define BRSTPREAPD1_PD1_0    0x01
#define BRSTPREAPD1_PD1_1    0x02
#define BRSTPREAPD1_PD1_2    0x04
#define BRSTPREAPD1_PD1_3    0x08
#define BRSTPREAPD1_PD1_4    0x10
#define BRSTPREAPD1_PD1_5    0x20
#define BRSTPREAPD1_PD1_6    0x40
#define BRSTPREAPD1_PD1_7    0x80

/* ID & Version [R] bits definition */
#define CHIPIDN_VER0         0x01
#define CHIPIDN_VER1         0x02
#define CHIPIDN_VER2         0x04
#define CHIPIDN_VER3         0x08
#define CHIPIDN_ID0          0x10
#define CHIPIDN_ID1          0x20
#define CHIPIDN_ID2          0x40
#define CHIPIDN_ID3          0x80

class audio_CS8416
{
public:

    class DeviceIO
    {
    public:

        enum class Reg : uint8_t
        {
            CTRL0       = 0x00, /* [R/W] Control0 */
            CTRL1       = 0x01, /* [R/W] Control1 */
            CTRL2       = 0x02, /* [R/W] Control2 */
            CTRL3       = 0x03, /* [R/W] Control3 */
            CTRL4       = 0x04, /* [R/W] Control4 */
            ASERFMT     = 0x05, /* [R/W] Serial Audio Data Format */
            RXEMSK      = 0x06, /* [R/W] Receiver Error Mask */
            INTMSK      = 0x07, /* [R/W] Interrupt Mask */
            INTMODH     = 0x08, /* [R/W] Interrupt Mode MSB */
            INTMODL     = 0x09, /* [R/W] Interrupt Mode LSB */
            RXCSTAT     = 0x0A, /* [R]   Receiver Channel Status */
            AFMTD       = 0x0B, /* [R]   Audio Format Detect */
            RXERR       = 0x0C, /* [R]   Receiver Error */
            INTSTAT     = 0x0D, /* [R]   Interrupt Status */
            CHANSUB0    = 0x0E, /* [R]   Q-Channel CSubcode [0:7] */
            CHANSUB1    = 0x0F, /* [R]   Q-Channel Subcode [8:15] */
            CHANSUB2    = 0x10, /* [R]   Q-Channel Subcode [16:23] */
            CHANSUB3    = 0x11, /* [R]   Q-Channel Subcode [24:31] */
            CHANSUB4    = 0x12, /* [R]   Q-Channel Subcode [32:39] */
            CHANSUB5    = 0x13, /* [R]   Q-Channel Subcode [40:47] */
            CHANSUB6    = 0x14, /* [R]   Q-Channel Subcode [48:55] */
            CHANSUB7    = 0x15, /* [R]   Q-Channel Subcode [56:63] */
            CHANSUB8    = 0x16, /* [R]   Q-Channel Subcode [64:71] */
            CHANSUB9    = 0x17, /* [R]   Q-Channel Subcode [72:79] */
            OMRMRAT     = 0x18, /* [R]   OMCK_RMCK Ratio */
            CHANAST0    = 0x19, /* [R]   Channel A Status]  */
            CHANAST1    = 0x1A, /* [R]   Channel A Status */
            CHANAST2    = 0x1B, /* [R]   Channel A Status */
            CHANAST3    = 0x1C, /* [R]   Channel A Status */
            CHANAST4    = 0x1D, /* [R]   Channel A Status */
            CHANBST0    = 0x1E, /* [R]   Channel B Status */
            CHANBST1    = 0x1F, /* [R]   Channel B Status */
            CHANBST2    = 0x20, /* [R]   Channel B Status */
            CHANBST3    = 0x21, /* [R]   Channel B Status */
            CHANBST4    = 0x22, /* [R]   Channel B Status */
            BRSTPREAPC0 = 0x23, /* [R]   Burst Preamble PC Byte 0 */
            BRSTPREAPC1 = 0x24, /* [R]   Burst Preamble PC Byte 1 */
            BRSTPREAPD0 = 0x25, /* [R]   Burst Preamble PD Byte 0 */
            BRSTPREAPD1 = 0x26, /* [R]   Burst Preamble PD Byte 1 */
            CHIPIDN     = 0x7F  /* [R]   ID & Version */
        };

        DeviceIO(FX2Device_t &fx2);
        ~DeviceIO();

        bool write(Reg reg, const uint8_t * data, size_t len);
        bool read(Reg reg, uint8_t * data, size_t len);

    private:

        std::mutex m_guard;

        FX2Device_t &m_fx2;
    };

    enum class AudioInput : uint8_t
    {
        MUTE,
        HDMI,
        OPTICAL
    };

private:

    DeviceIO * m_io_device;

public:

    bool reset(AudioInput in = AudioInput::OPTICAL);

    void run();
    void stop();

    DeviceIO * direct_io() { return m_io_device; }

    audio_CS8416(FX2Device_t &fx2);
    ~audio_CS8416();

private:

    char numToStepChar(uint8_t ver);
};

#endif // _AUDIO_CS8416_H_
