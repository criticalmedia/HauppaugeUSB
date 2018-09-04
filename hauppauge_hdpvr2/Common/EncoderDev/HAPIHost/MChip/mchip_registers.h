//=============================================================================
//  File Name: mchip_registers.h
//
//  Copyright 2009 Magnum Semiconductor Inc. All rights reserved.
//
//  Description:
//      MCHIP register definitions.
//
//  Modification History:
//      $Id: $
//      $Log: $
//
//=============================================================================

#ifndef MCHIP_REGISTERS_H
#define MCHIP_REGISTERS_H

#define DMN_HB_CONTROL          0x0
#define DMN_HB_VERSION          0x1
#define DMN_HB_DATA_HIGH        0x2     // if LE=0, else swapped
#define DMN_HB_DATA_LOW         0x3     // if LE=0
#define DMN_HB_ADDR_HIGH        0x4     // if LE=0, else swapped
#define DMN_HB_ADDR_LOW         0x5     // if LE=0
/*
#define DMN_HB_DATA_HIGH        0x3     // if LE=1
#define DMN_HB_DATA_LOW         0x2     // if LE=1
#define DMN_HB_ADDR_HIGH        0x5     // if LE=1
#define DMN_HB_ADDR_LOW         0x4     // if LE=1
*/

#define DMN_HB_DATA             0x2
#define DMN_HB_ADDR             0x4

#define DMN_HB_HC_MIPS_RST      (0x1 << 13)
#define DMN_HB_HC_LE            (0x1 << 12)
#define DMN_HB_HC_INT_OEN       (0x1 << 9)
#define DMN_HB_HC_VDSP_RST      (0x1 << 8)
#define DMN_HB_HC_VDBG_INT      (0x1 << 7)
#define DMN_HB_HC_VCPU_ERR      (0x1 << 6)
#define DMN_HB_HC_VCPU_RST      (0x1 << 5)
#define DMN_HB_HC_SDBG_INT      (0x1 << 4)
#define DMN_HB_HC_SCPU_ERR      (0x1 << 3)
#define DMN_HB_HC_SCPU_RST      (0x1 << 2)
#define DMN_HB_HC_CHIP_RST      (0x1 << 1)
#define DMN_HB_HC_WR_DATA       (0x1 << 0)
#define DMN_HB_HC_WR_DATA_0     (0x0 << 0)
#define DMN_HB_HC_WR_DATA_1     (0x1 << 0)


// Host
// ----

// Host Version Register (PCI_HostVer)
#define DMN_HOST_VERSION            0xFF060044

// Secondary Bitstream Port
// ------------------------

// Secondary Bitstream Configuration Register (IPC_SecCfg[0:3])
#define DMN_IPC_SECCFG0             0xFF080820
#define DMN_IPC_SECCFG1             0xFF081820
#define DMN_IPC_SECCFG2             0xFF082820
#define DMN_IPC_SECCFG3             0xFF083820
// This register specifies the secondary bitstream port configuration.

#define DMN_IPC_SECCFG_ARNCNT       (0xFFFF << 16)
#define DMN_IPC_SECCFG_ARNCNT_SHIFT (16)
// ArnCnt Auto Run Repeat Count 31:16
// This field determines the number of times the DMA Engine restarts for
// each GO operation. If set to 0x0000, the DMA engine runs one time when
// GO is set. If set to any other value, Auto Run functionality is enabled
// and the DMA engine runs for ARnRCnt+1 cycles each time GO is set.

#define DMN_IPC_SECCFG_IFSEL        (0x1 << 15)
// IFSel Interface Select 15
// For the Secondary Bitstream Configuration registers associated with SBP
// Ports 1, 2, and 3 (0xFF08 1820, 0xFF08 2820, and 0xFF08 3820), when
// IFSel is set, 1, the E6.0 pins multiplexed with associated SBP 1, 2,
// and 3 ports operate in the SBP mode. When IFSel is clear, 0, the pins
// operate in their alternate functions.
// For the Secondary Bitstream Configuration register associated with SBP
// port 0 (0xFF08 0820), IFSel can be set by software but it has no other
// effect for E6.0 and should be regarded as reserved--that is, the bit
// can be written to but it has no control over multiplexing SBP0 pins.

#define DMN_IPC_SECCFG_IFD          (0x1 << 7)
// IFD Interrupt on Final Data 7
// When IFD is set, 1, and a SBP DMA complete interrupt is due to be
// triggered (IE set and DMA transfer completed), the IRQ is only
// generated if ARnRCnt[15:0] is also equal to 0x0000--that is, If IFD is
// set, the DMA Complete IRQ only occurs on completion of the last DMA
// event of an Auto Run sequence.
// If IFD is clear, 0, and IE is set, an IRQ is generated on completion of
// every DMA cycle--that is, during Auto Run mode, an IRQ is generated
// after each section of data is transferred.

#define DMN_IPC_SECCFG_WRREQ        (0x1 << 6)
// WRREQ Write Request 6
// This read/writable bit has a default value of 0. If WRREQ is set, the
// SBP_REQ pin is redefined as a DMA write request, which is only asserted
// on outgoing transfers when the bitstream FIFO is not empty.
// If WRREQ is set, the SBP_RD pin is redefined as a DMA read request,
// which is asserted on incoming transfers when the bitstream FIFO is not
// full.
// 1 = SBP_REQ is a DMA write request and SBP_RD is a DMA read request
// 0 = SBP_REQ is a DMA request and SBP_RD is the direction of transfer

#define DMN_IPC_SECCFG_FP           (0x1 << 5)
// FP Framed Packet 5
// 1 = Incoming packets on the secondary bitstream port are framed with
//  the SBP_FRAME pin.
// If FP is cleared, SBP_FRAME is de-asserted on outgoing packets and is
// ignored on incoming packets.

#define DMN_IPC_SECCFG_IE           (0x1 << 4)
// IE Interrupt Enable 4
// 1 = An SBP completion interrupt is generated when a secondary bitstream
// DMA transfer is completed; otherwise, no interrupt is generated.
// Incoming transfers are complete when the Secondary Next Address
// register reaches the Secondary Stop Address register, and the bitstream
// data has been written to SDRAM. Outgoing transfers are complete when
// the Secondary Next Address register reaches the Secondary Stop Address
// and the bitstream data has been transferred to the system; that is,
// when the bitstream FIFO is empty.

#define DMN_IPC_SECCFG_GO           (0x1 << 3)
// Go 3
// Go is set by microcode to begin secondary bitstream transfers. The Go
// bit is cleared by hardware after the transfer is completed.
// Clearing the Go bit when BSRD is clear flushes the remaining contents
// of the secondary bitstream transfer FIFO to SDRAM, and terminates the
// transfer.
// Clearing the Go bit when BSRD is set discards the remaining contents of
// the secondary bitstream FIFO, and terminates the transfer.
// Clearing the Go bit in either direction generates an interrupt, if
// enabled (that is, if the IE bit is set to logic value 1). Since this
// flush takes some time to complete, software must keep polling the Go
// bit, after writing zero, until the Go bit reads zero, to ensure that
// the last data has been written to SDRAM.
// Note: The Go bit must be cleared only if necessary. It must read zero
// before software changes the value of BSRD or any other secondary
// bitstream DMA register, except for changing the Stop Address register.
// Clearing the Go bit by hardware or software resets the packet framing
// Software must set the stop address so the number of bytes transferred
// in a DMA operation is a multiple of IPC_SecPkSize.
// Note: During Auto Run mode, when ARnRCnt[15:0] is not zero, GO
// naturally transitions to 0 between each DMA cycle. Therefore, if GO is
// polled for completion of operation, software must check for both GO and
// ARnRCnt[15:0] being equal to 0.
// If GO is cleared, 0, by software during an Auto Run sequence, the
// current DMA cycle is regarded as the last in the sequence--that is,
// ARnRCnt[15:0] transitions to 0, Next Address points to one byte after
// the last transferred byte in SDRAM, and Stop Address points to the last
// transferred byte in SDRAM.

#define DMN_IPC_SECCFG_POL          (0x1 << 2)
// POL Request/Acknowledge Polarity 2
// If POL is set and WRREQ is clear, the SBP_REQ and SBP_ACK pins are
// active low, otherwise they are active high.
// If POL and WRREQ are set, the SBP_WR, SBP_RD and SBP_ACK pins are
// active low; otherwise, they are active high.

#define DMN_IPC_SECCFG_BSRD         (0x1 << 1)
// BSRD Secondary Bitstream Read 1
// 1 = The secondary bitstream transfers will be read by the system; that
// is, the bitstream is being output.
// 0 = The secondary bitstream transfers will be written by the system.
// Note: BSRD must not be changed while the Go bit is set.

#define DMN_IPC_SECCFG_WRDA         (0x1 << 0)
#define DMN_IPC_SECCFG_WRDA_0       (0x0 << 0)
#define DMN_IPC_SECCFG_WRDA_1       (0x1 << 0)
// WrDa Write Data Action 0
// The value of this bit is written to any selected bits during Secondary
// Bitstream Configuration register writes. Bits to be written are
// selected by placing a 1 in each desired location as the register is
// written. Any bit positions that contain a 0 during register writes
// remain unchanged.

// Secondary Next Address Register (IPC_SecNext[0:3])
#define DMN_IPC_SECNEXT0            0xFF080824
#define DMN_IPC_SECNEXT1            0xFF081824
#define DMN_IPC_SECNEXT2            0xFF082824
#define DMN_IPC_SECNEXT3            0xFF083824
// This register specifies the SDRAM address for secondary bitstream data.
// When Go is set, this register specifies the starting SDRAM address
// where secondary bitstream data will be transferred. As bitstream data
// is transferred, this register is updated to point to one byte after the
// last transferred byte in SDRAM. Microcode reads this register to
// determine how many bytes of bitstream information have been
// transferred.
// During Auto Run mode, when ARnRCnt[15:0] is not zero, this register is
// automatically updated with the start address of the next sequence
// between DMA cycle transfers. In this case, the new starting address is
// the previous starting address plus the auto increment value in the
// Secondary Bitstream Auto Increment Value Register (IPC_SecBase[0:3]).
// Note: The two least significant bits and the upper four bits of this
// register must be zero.

// Secondary Stop Address Register (IPC_SecStop[0:3])
#define DMN_IPC_SECSTOP0            0xFF080828
#define DMN_IPC_SECSTOP1            0xFF081828
#define DMN_IPC_SECSTOP2            0xFF082828
#define DMN_IPC_SECSTOP3            0xFF083828
// This register specifies the transfer stop SDRAM address for secondary
// bitstream data. When the Next Address reaches the value in this register
// and the bitstream data has been transferred to SDRAM or the system,
// the DMA transfer is completed and the Go bit is cleared. This register
// can be reloaded while a DMA transfer is active to extend the length of a
// DMA operation. In normal operation, this register must never be greater
// than or equal to the Limit Address register.
// Note: The two least significant bits and the upper four bits of this
// register must be zero.
// While a DMA transfer is active, the Stop Address register must not be
// reloaded with the value of the Next Address register. It is possible that
// the Next Address reaches the old Stop Address when the Stop Address
// register is reloaded with a new value; this condition must be avoided.
// During Auto Run mode, when ARnRCnt[15:0] is not zero, this register is
// automatically updated with the stop address of the next sequence
// between DMA cycle transfers. In this case, the new stop address is the
// previous stop address plus the auto increment value in the Secondary
// Bitstream Auto Increment Value Register (IPC_SecBase[0:3]).
// Note: Reloads of the Stop Address must be synchronized with detecting
// DMA completion, so that the DMA operation is not restarted after the Go
// bit is cleared or a completion interrupt is generated.

// Secondary Base Address Register (IPC_SecBase[0:3])
#define DMN_IPC_SECBASE0            0xFF08082C
#define DMN_IPC_SECBASE1            0xFF08182C
#define DMN_IPC_SECBASE2            0xFF08282C
#define DMN_IPC_SECBASE3            0xFF08382C
// This register specifies the SDRAM address for the beginning of the
// circular SDRAM buffer.

// Secondary Limit Address Register (IPC_SecLimit[0:3])
#define DMN_IPC_SECLIMIT0           0xFF080830
#define DMN_IPC_SECLIMIT1           0xFF081830
#define DMN_IPC_SECLIMIT2           0xFF082830
#define DMN_IPC_SECLIMIT3           0xFF083830
// The Secondary Limit Address register specifies the SDRAM address for
// the first byte after the buffer. When the next address reaches the
// value in the Limit Address register, it is reloaded with the Base
// Address register value before transferring additional data.
// The two least significant bits and the upper four bits of these registers
// must be zero.

// Secondary Bitstream Auto Increment Value Register (IPC_SecBase[0:3])
#define DMN_IPC_SECAUTOINC0         0xFF08083C
#define DMN_IPC_SECAUTOINC1         0xFF08183C
#define DMN_IPC_SECAUTOINC2         0xFF08283C
#define DMN_IPC_SECAUTOINC3         0xFF08383C
// During Auto Run mode (any non-zero ARnRCnt value) this register
// determines the amount by which the preceding initial Next Address and
// Stop Address values are incremented to form the new Next Address and
// Stop Address. For example, during the Auto Run process, each cycle
// starts with a new (automatically generated) set of Next/Stop Address
// settings and these values are equal to the previous start/stop address
// plus the AutoInc value.
// Note: The two least significant and the four most significant bits
// of this register must be zero.

// Storage Interface
// -----------------
// SBP[0] is only available when the storage interface is in SD mode

#define DMN_DVD_CFG                 0xFFFB0050

#define DMN_DVD_CFG_MODE            (0x3 << 17)
#define DMN_DVD_CFG_MODE_ATAPI      (0x0 << 17)
#define DMN_DVD_CFG_MODE_SD         (0x1 << 17)
#define DMN_DVD_CFG_MODE_CD         (0x2 << 17)
#define DMN_DVD_CFG_MODE_SD_PLUS    (0x3 << 17)

#define DMN_DVD_CFG_ATAPIRST        (0x1 << 22)


// Clock / Power
// -------------

#define DMN_CLK_PWR_MANAGER     0xFFC20000
// The Power Management Register can selectively disable E6.0 modules
// as well as power down all internally clocked logic. After reset, all
// PLLs and modules are enabled so that all sub-blocks can be reset.
// After the power up sequence has completed, individual units can be
// disabled by software to save power.

#define DMN_PLL_POWER_DOWN_XTAL_OSC     ((0x1 << 11) | (0x1 << 5))
// CLKPad_PwrDown 11
// When this bit is set, 1, the divider logic associated with the
// dedicated clock pad is powered down. This bit should be set whenever
// the Audio and Video PLLs use the clock from the crystal oscillator as a
// reference and when CLKPad_Div[1] = 0 (no division required).
// XTAL_OSC_OFF 5
// When this bit is set, 1, the internal crystal oscillator is powered
// down. This bit can be set when an external clock source is used. If
// there is no external clock source and this bit is set, the chip hangs.

#define DMN_CLK_CLKCONTROL      0xFFC20008

#define DMN_PLL_SET_XTAL_DIRECT_MODE    (0x1 << 29)
// Sysclk Direct from Crystal Oscillator 29
// When this bit is set, 1, the system clock (Sysclk) is generated
// directly from the XTAL oscillator (using the normal XTAL oscillator
// output, not the dlv2_bypass output), rather than from the System PLL.
// This bit does power down the XTAL oscillator like the BYPASS_PLL bit.
// Setting this bit enables the system clock to run at XTAL frequency or
// less. It also activates the clock de-glitch logic to ensure the system
// clock is glitch free.

// System PLL Control Register (SysPLLCtrlReg)
#define DMN_CLK_SYSPLLCONTROL   0xFFC20048

// Memory PLL Control Register (MemoryPLLCtrlReg)
#define DMN_CLK_MEMPLLCONTROL   0xFFC2004C

// Video Output Clock Control Register (VIOCLKCtrlReg)
#define DMN_CLK_VIDEOCLKCTL     0xFFC2000C

#define DMN_PLL_SET_IREF                (0x1 << 13)
// DAC_BYPASS 13
// When this bit is set, 1, the DAC obtains input data from the DAC_Test_In
// bus. This feature is used only for debug.



// DENC
// ----

// Global Configuration and Control Register (DENC_GCC)
#define DMN_DENC_GCC                0xFF840000

#define DMN_PLL_INIT_DAC            (0x00003e00)
// DPD DAC Power Down Register 13:8
// This field controls power to individual DACs. When a bit is set, the
// corresponding DAC enters a low power state; Bit 8 corresponds to DAC 0,
// bit 9 corresponds to DAC 1, and so forth. This field is duplicated in
// both registers of the primary and secondary DENC. However, only the
// primary register controls power down for all 6 DACs.


// Audio SPARC
// -----------

// Software Interrupt Request Source
#define DMN_ADSP_INTREQSW           0xFFFC0204

// Hardware Interrupt Request Source
#define DMN_ADSP_INTREQ1            0xFFFC0208
#define DMN_ADSP_INTREQ2            0xFFFC0214
#define DMN_ADSP_INTREQ3            0xFFFC0220
#define DMN_ADSP_INTREQ4            0xFFFC022C

// Clear interrupts
#define DMN_ADSP_CLEAR_INTERRUP     0xFFFFFFFE

// Hardware Interrupt Request Level
#define DMN_ADSP_INTREQLVL1A        0xFFFC020C
#define DMN_ADSP_INTREQLVL1B        0xFFFC0210
#define DMN_ADSP_INTREQLVL2A        0xFFFC0218
#define DMN_ADSP_INTREQLVL2B        0xFFFC021C
#define DMN_ADSP_INTREQLVL3A        0xFFFC0224
#define DMN_ADSP_INTREQLVL3B        0xFFFC0228
#define DMN_ADSP_INTREQLVL4A        0xFFFC0230
#define DMN_ADSP_INTREQLVL4B        0xFFFC0234


#endif
