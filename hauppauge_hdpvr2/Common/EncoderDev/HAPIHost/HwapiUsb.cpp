//=============================================================================
//  File Name: HwapiUsb.c
//
//  Copyright 2010 Magnum Semiconductor Inc. All rights reserved.
//
//  Description:
//      Hwapi of usb port.
//
//
//=============================================================================

#include <string.h>
#include "HwapiUsb.h"

#include "mchip.h"
#include "mchip_registers.h"
#include "mchip_utils.h"

#define MCHIP_MEMTEST_SWEEP       1
// timeout for image to boot
#define MCHIP_BOOT_TIMEOUT    1000 // ms

USBDevHandle USB_CommBusInit (Uint32 ChipID,hw_port_config *pHwPortConfig)
{
	// chipID???
    usb_config_st *pUsbConfig;

    pUsbConfig = (usb_config_st*)MemAllocFromHeap(__FILE__, __LINE__, sizeof(usb_config_st));
    if(pUsbConfig==NULL)
    {
        DbgLogInfo(("USB_CommBusInit malloc failed\n"));
        return NULL;
    }
	pUsbConfig->p_mchip = pHwPortConfig->usb_port_config.p_mchip;
    pUsbConfig->sbp_freq = pHwPortConfig->usb_port_config.sbp_freq;
    pUsbConfig->dxt_clk = pHwPortConfig->usb_port_config.dxt_clk;

	return (USBDevHandle)pUsbConfig;
}

HWAPIErrCode USB_GetBoardInfo (USBDevHandle hDevice, BOARD_INFO *pBoardInfo)
{
    usb_config_st *pUsbConfig = (usb_config_st*)hDevice;
	USBBootMChip_t *p_mchip = pUsbConfig->p_mchip;
	Uint8 dataLength = 0, nameplateIndex=0, i=0;
    BYTE nameplate;
    char tmpData[20];

    pBoardInfo->dxt_clk = DXT_CLK_48;

	p_mchip->UsbEEpSetAddr(0x51);
	nameplateIndex=232; //FGR assumes a 8192 byte EEprom; and 512 bytes ofnameplate data starting at 7424

    while(++nameplateIndex < NI_MAX)
    {
        if(!p_mchip->UsbEEpReadBytes((nameplateIndex-1)*DATA_PACKET_LEN, 1, &dataLength))
        {
        	DbgLogError(("read data length fail!\n"));
        	return HWAPI_Fail;
        }
        if(dataLength==0xff)
        {
        	DbgLogWarn(("EEprom appears to be blank!\n"));
        	return HWAPI_Fail;
        }
        if(dataLength >= sizeof(tmpData))
        {
        	DbgLogWarn(("Nameplate(%d) length(%d)>%d!\n", (nameplateIndex-1), dataLength, sizeof(tmpData)));
        	return HWAPI_Fail;
        }
        if(!p_mchip->UsbEEpReadBytes((nameplateIndex-1)*DATA_PACKET_LEN+1, 1, &nameplate))
        {
        	DbgLogError(("read nameplate fail!\n"));
        	return HWAPI_Fail;
        }
        if(!p_mchip->UsbEEpReadBytes((nameplateIndex-1)*DATA_PACKET_LEN+2, dataLength, (BYTE *)tmpData))
        {
        	DbgLogError(("read data fail! nameplate=%d.\n",nameplate));
        	return HWAPI_Fail;
        }
        else
        {
            tmpData[dataLength]=0;
			//DbgLogInfo(("dataLength is %d\n",dataLength));
        }
        switch(nameplate)
        {
            case NI_COMPANY       :
                strcpy(pBoardInfo->company,tmpData);
                DbgLogInfo(("Company Name: %s.\n",tmpData));
                break;
            case NI_BOARD_ID      :
                strcpy(pBoardInfo->boardID,tmpData);
                DbgLogInfo(("Board ID: %s.\n",tmpData));
                break;
            case NI_HDR_EV        :
                strcpy(pBoardInfo->hardwareRev,tmpData);
                DbgLogInfo(("Hardware Revision: %s.\n",tmpData));
                break;
            case NI_PCB_SKU       :
                pBoardInfo->pcbSKU = tmpData[1]&0xff;
                pBoardInfo->pcbSKU |= tmpData[0]<<8;
                DbgLogInfo(("PCB SKU : %d.\n",pBoardInfo->pcbSKU));
                break;
            case NI_PCB_SN        :
                pBoardInfo->pcbSN= tmpData[1]&0xff;
                pBoardInfo->pcbSN |= tmpData[0]<<8;
                DbgLogInfo(("PCB SN : %d.\n",pBoardInfo->pcbSN));
                break;
            case NI_MAIN_CPU      :
                strcpy(pBoardInfo->mainCPU,tmpData);
                DbgLogInfo(("Main CPU on the PCB: %s.\n",tmpData));
                break;
            case NI_ADDI_CPUS     :
                pBoardInfo->additionalCPUs= tmpData[1]&0xff;
                pBoardInfo->additionalCPUs |= tmpData[0]<<8;
                DbgLogInfo(("Number of addtitional CPUs on the PCB: %d.\n",pBoardInfo->additionalCPUs));
                break;
            case NI_ADDI_CPUS_TYPE:
                strcpy(pBoardInfo->additionalCPUsType,tmpData);
                DbgLogInfo(("Type of additional CPUs: %s.\n",tmpData));
                break;
            case NI_CHIP_REV      :
                strcpy(pBoardInfo->magnumChipRev,tmpData);
                DbgLogInfo(("Magnum Chip revision : %s.\n",tmpData));
                break;
            case NI_DRAM          :
                strcpy(pBoardInfo->dram,tmpData);
                DbgLogInfo(("DRAM used with Magnum Chip: %s.\n",tmpData));
                break;
            case NI_CORE_VOLTAGE  :
                pBoardInfo->coreVoltage= tmpData[1]&0xff;
                pBoardInfo->coreVoltage |= tmpData[0]<<8;
                DbgLogInfo(("Core Voltage for Magnum Chip in mV: %d.\n",pBoardInfo->coreVoltage));
                break;
            case NI_MAX_MIPS_FREQ :
                pBoardInfo->maxMipsFreq= tmpData[1]&0xff;
                pBoardInfo->maxMipsFreq|= tmpData[0]<<8;
                DbgLogInfo(("max. MIPS System Frequency in MHz : %d.\n",pBoardInfo->maxMipsFreq));
                break;
            case NI_MAX_SPARC_FREQ:
                pBoardInfo->maxSparcFreq= tmpData[1]&0xff;
                pBoardInfo->maxSparcFreq |= tmpData[0]<<8;
                DbgLogInfo(("max. SPARC System Frequency in MHz : %d.\n",pBoardInfo->maxSparcFreq));
                break;
            case NI_DRAM_FREQ     :
                pBoardInfo->dramFreq= tmpData[1]&0xff;
                pBoardInfo->dramFreq |= tmpData[0]<<8;
                DbgLogInfo(("max. DDR DRAM Clock Frequency in MHz: %d.\n",pBoardInfo->dramFreq));
                break;
            case NI_DRAM_SIZE     :
                pBoardInfo->dramSize= tmpData[1]&0xff;
                pBoardInfo->dramSize|= tmpData[0]<<8;
                DbgLogInfo(("DRAM Size in MByte : %d.\n",pBoardInfo->dramSize));
                break;
            case NI_ECO           :
                strcpy((char *)(pBoardInfo->eco), tmpData);
                DbgLogInfo(("List of applied ECOs for this hardware revision : \n"));
				i = 0;
                while(tmpData[i]!=0)
                {
                    DbgLogInfo(("%d \n",tmpData[i]));
                    if(tmpData[i]==8)   //sbp frequence is 30MHz
                    {
                        pUsbConfig->sbp_freq = p_mchip->gSbpFreq = SBP_FREQ_30;
						DbgLogInfo((" gSbpFreq == SBP_FREQ_30\n"));
                    }
                    else if(tmpData[i]==9) 
                    {
                        pBoardInfo->dxt_clk = DXT_CLK_24;
						DbgLogInfo((" dxt_clk == DXT_CLK_24\n"));
                    }
                    i++;
                }
                //DbgLogInfo(("\n"));
				
                break;
            case NI_MAX           :
            default:
                DbgLogInfo(("USB_GetBoardInfo() Unknown nameplate value=%d\n", nameplate));
                break;
        }
    }
	return HWAPI_Success;

}

HWAPIErrCode USB_BoardInit (USBDevHandle hDevice, DRAM_BKV_CONFIG* bkv)
{
	DbgLogInfo(("USB_BoardInit(%p)\n", hDevice));

    usb_config_st *pUsbConfig = (usb_config_st*)hDevice;
	USBBootMChip_t *p_mchip = pUsbConfig->p_mchip;
    int ret = HWAPI_Fail;// was EXIT_FAILURE;
    Uint16 ver16;
    Uint32 ver32;
    Uint16 val16;
    Uint32 val32;
//    DWORD start;

#if MCHIP_MEMTEST_SWEEP
    //Boolean bkv_updated;
#endif

	//FGR - do retrys if HW init fails, also use longer delays for each subsequent retry
	Uint32 pass;
	for(pass=1; pass<5; pass++){
    
		DbgLogInfo(("Power on_1: MCHIP power-on reset, Pass=%d\n", pass));

		// initialize Cypress PA7:0 GPIO lines
		// note this initializes MCHIP_RESET_L low and POWER_ENABLE_H low
		// so MCHIP is held in reset with power disabled
		if (!p_mchip->MCHIP_PortA_Init()) {DbgLogError(("!!!%d\n",__LINE__));continue;}

		// hold with power down for a while
		wrapSleep_ms(100*pass);

		// enable power
		if (!p_mchip->MCHIP_PortA_Set_POWER_ENABLE_H(1)) {DbgLogError(("!!!%d\n",__LINE__));continue;}
		// wait before bringing MCHIP out of reset
		wrapSleep_ms(80*pass);

		// bring MCHIP out of reset
		if (!p_mchip->MCHIP_PortA_Set_MCHIP_RESET_L(1)) {DbgLogError(("!!!%d\n",__LINE__));continue;}
		// wait 25ms for reset complete
		// internal reset for 65536 clocks, plus however long it takes to come out of reset
		wrapSleep_ms(25*pass);
		// wait a few ms


		// hold reset low 1ms
		if (!p_mchip->MCHIP_PortA_Set_MCHIP_RESET_L(0)) {DbgLogError(("!!!%d\n",__LINE__));continue;}
		wrapSleep_ms(10);
		// bring high and wait for reset complete
		// internal reset for 65536 clocks, plus however long it takes to come out of reset
		if (!p_mchip->MCHIP_PortA_Set_MCHIP_RESET_L(1)) {DbgLogError(("!!!%d\n",__LINE__));continue;}
		wrapSleep_ms(25*pass);

		p_mchip->UsbForceWFMode(0xFF);
		// select MCHIP host
		if (!p_mchip->MCHIP_Host_Select()) {DbgLogError(("!!!%d\n",__LINE__));continue;}

		// select M-mode on MCHIP host slave interface
		// issue a dummy write cycle to MCHIP Host Address Register
		if (!p_mchip->MCHIP_Host_Write16(DMN_HB_ADDR, 0)) {DbgLogError(("!!!%d\n",__LINE__));continue;}

		// verify MCHIP presence by reading MCHIP Host Version Register
		if (!p_mchip->MCHIP_Host_Read16(DMN_HB_VERSION, &ver16)) {DbgLogError(("!!!%d\n",__LINE__));continue;}
		DbgLogInfo(("MCHIP: Host Version (via Host) = 0x%04x\n", ver16));
		// bits 15:8 = Version, bits 7:0 == Stepping
		// expected value for MCHIP: 6100h
		if (ver16 != 0x6100)
		{
			DbgLogError(("MCHIP: ERROR %d: expected Host Version=0x6100, got 0x%x\n", __LINE__, ver16));
			continue;
		}

		// read MCHIP Host Control Register
		if (!p_mchip->MCHIP_Host_Read16(DMN_HB_CONTROL, &val16)) {DbgLogError(("!!!%d\n",__LINE__));continue;}
		DbgLogInfo(("MCHIP: Host Control (via Host) = 0x%04x\n", val16));
		// expected value for MCHIP: 2024h: MIPS, Video SPARC, System SPARC held in reset
		if (val16 != 0x2024)
		{
			DbgLogError(("MCHIP: ERROR %d: expected Host Control = 0x2024\n", __LINE__));
			continue;
		}

		// verify 16-bit host bus accesses
		if (!p_mchip->MCHIP_Test_Host_16()) {DbgLogError(("!!!%d\n",__LINE__));continue;}

		// verify 32-bit host bus accesses
		if (!p_mchip->MCHIP_Test_Host_32()) {DbgLogError(("!!!%d\n",__LINE__));continue;}

		break; //everything is good
	}
	if(pass >= 5)
		goto EXIT;


    // verify MCHIP CBus access by reading MCHIP Host Version Register on CBus
#if 0
    if (!p_mchip->MCHIP_Read32(DMN_HOST_VERSION, &ver32)) {DbgLogError(("!!!%d\n",__LINE__));/*goto EXIT;*/}
#else
    if (!p_mchip->MCHIP_Read32(DMN_HOST_VERSION, &ver32)) {
		if (!p_mchip->MCHIP_Read32(DMN_HOST_VERSION, &ver32)){//FGR - just for kicks, lets give it one more chance
			DbgLogError(("!!!%d\n",__LINE__));/*goto EXIT;*/
		}
	}
#endif
    DbgLogInfo(("MCHIP: Host Version (via CBus) = 0x%08x\n", ver32));
    // should have the same value as when read from host
    if (ver16 != (ver32 & 0x0000ffff)) //RMV
    {
        DbgLogError(("MCHIP: %d: Host Version different via Host (0x%04x) and CBus (0x%08x)\n", __LINE__, ver16, ver32));
        goto EXIT;
    }
    if (ver16 != ver32)
    {
        DbgLogWarn(("MCHIP: %d: Host Version different via Host (0x%04x) and CBus (0x%08x)\n", __LINE__, ver16, ver32));
    }

    // check MConfig, Bond_Option bits
    if (!p_mchip->MCHIP_Read32(0xFFC20020, &val32)) {DbgLogError(("!!!%d\n",__LINE__));goto EXIT;}
    DbgLogInfo(("MCHIP: ByPassPLLMCfgReg (via CBus) = 0x%08x\n", val32));
    DbgLogInfo(("MCHIP: MConfig[3:0] = 0x%x\n", (val32 >> 7) & 0xF));
    DbgLogInfo(("MCHIP: Bond_Option[2:0] = 0x%x\n", (val32 >> 3) & 0x7));
    // TODO: could check these for suitability
    // require Bond_Option[0] = 1 to enable ASBP0, ASBP1 pins
    if (!((val32 >> 3) & 0x1))
    {
        DbgLogError(("MCHIP: ERROR %d: Bond_Option[0] = 0, ASBP0/ASBP1 not enabled\n"));
        goto EXIT;
    }


    // GPIO to FX2 configure/set/read test
    if (!p_mchip->MCHIP_Test_GPIOx()) {DbgLogError(("!!!%d\n",__LINE__));goto EXIT;}

    // GPIO to LED configure/set test
#ifndef HAUPPAUGE
	if (!p_mchip->MCHIP_Test_LED()) {DbgLogError(("!!!%d\n",__LINE__));goto EXIT;}
#else
	//Encoder power led on -01; Bling ring on -03
//	if (!p_mchip->MCHIP_Test_LED(55)) {DbgLogError(("!!!%d\n",__LINE__));goto EXIT;}
	//LED1 -03
//	if (!p_mchip->MCHIP_Test_LED(47)) {DbgLogError(("!!!%d\n",__LINE__));goto EXIT;}
	//LED2 -03
//	if (!p_mchip->MCHIP_Test_LED(48)) {DbgLogError(("!!!%d\n",__LINE__));goto EXIT;}
	//FRED_LED -03, LED3 -05
//	if (!p_mchip->MCHIP_Test_LED(49)) {DbgLogError(("!!!%d\n",__LINE__));goto EXIT;}
#endif

#ifndef HAUPPAUGE
    // set LED off for now
    DbgLogInfo(("clearing LED:\n"));
    if (!p_mchip->MCHIP_LED_Configure(0)) {DbgLogError(("!!!%d\n",__LINE__));goto EXIT;}
#else
    // set LED2 on for now
	if (!p_mchip->MCHIP_LED_Configure(48, 1)) {DbgLogError(("!!!%d\n",__LINE__));goto EXIT;}
#endif

    // initialize sys/mem PLL and DRC from loaded BKV
    if (!p_mchip->MCHIP_DRAM_BKV_Init(bkv)) {DbgLogError(("!!!%d\n",__LINE__));goto EXIT;}

    if (!p_mchip->MCHIP_Read32(0xFFC20048, &val32)) {DbgLogError(("!!!%d\n",__LINE__));goto EXIT;}
    DbgLogInfo(("MCHIP: SysPLLCtrlReg=0x%08x\n", val32));
    if (!p_mchip->MCHIP_Read32(0xFFC2004C, &val32)) {DbgLogError(("!!!%d\n",__LINE__));goto EXIT;}
    DbgLogInfo(("MCHIP: MemPLLCtrlReg=0x%08x\n", val32));
    if (!p_mchip->MCHIP_Read32(0xFFC20000, &val32)) {DbgLogError(("!!!%d\n",__LINE__));goto EXIT;}
    DbgLogInfo(("MCHIP: PwrMgtReg=0x%08x\n", val32));
    if (!p_mchip->MCHIP_Read32(0xFFC20018, &val32)) {DbgLogError(("!!!%d\n",__LINE__));goto EXIT;}
    DbgLogInfo(("MCHIP: ClkDisableReg=0x%08x\n", val32));
    if (!p_mchip->MCHIP_Read32(0xFFC20020, &val32)) {DbgLogError(("!!!%d\n",__LINE__));goto EXIT;}
    DbgLogInfo(("MCHIP: ByPassPLLMCfgReg=0x%08x\n", val32));


   
goto MCHIP_BOOT;

	// Extra Code removed from here.
MCHIP_BOOT:

    // hold reset low 1ms
    if (!p_mchip->MCHIP_PortA_Set_MCHIP_RESET_L(0)) {DbgLogError(("!!!%d\n",__LINE__));goto EXIT;}
    wrapSleep_ms(1);
    // bring high and wait for reset complete
    // internal reset for 65536 clocks, plus however long it takes to come out of reset
    if (!p_mchip->MCHIP_PortA_Set_MCHIP_RESET_L(1)) {DbgLogError(("!!!%d\n",__LINE__));goto EXIT;}
    wrapSleep_ms(25);

    // must reselect M-mode on MCHIP host slave after reset
    // issue a dummy write cycle to MCHIP Host Address Register
    if (!p_mchip->MCHIP_Host_Write16(DMN_HB_ADDR, 0)) {DbgLogError(("!!!%d\n",__LINE__));goto EXIT;}

    // set LED off for now
    DbgLogInfo(("clearing LED:\n"));
#ifndef HAUPPAUGE
    if (!p_mchip->MCHIP_LED_Configure(0)) {DbgLogError(("!!!%d\n",__LINE__));goto EXIT;}
#else
    //Bling On
	if (!p_mchip->MCHIP_LED_Configure(55, 1)) {DbgLogError(("!!!%d\n",__LINE__));goto EXIT;}
	if (!p_mchip->MCHIP_LED_Configure(53, 1)) {DbgLogError(("!!!%d\n",__LINE__));goto EXIT;}
    //Already configured during LED test above
	//if (!p_mchip->MCHIP_LED_Configure(48, 0)) {DbgLogError(("!!!%d\n",__LINE__));goto EXIT;}
#endif
    DbgLogInfo(("\n"));

    // initialize sys/mem PLL and DRC from loaded BKV
    if (!p_mchip->MCHIP_DRAM_BKV_Init(bkv)) {DbgLogError(("!!!%d\n",__LINE__));goto EXIT;}

    // set LED on to indicate DRAM initialized
    DbgLogInfo(("setting LED:\n"));
#ifndef HAUPPAUGE
    if (!p_mchip->MCHIP_LED_Configure(1)) {DbgLogError(("!!!%d\n",__LINE__));goto EXIT;}
#else
	//Bling Off; LED1 off; LED2 on; LED3 on; configure the LED ports
	if (!p_mchip->MCHIP_LED_Configure(55, 0)) {DbgLogError(("!!!%d\n",__LINE__));goto EXIT;}
	if (!p_mchip->MCHIP_LED_Configure(53, 0)) {DbgLogError(("!!!%d\n",__LINE__));goto EXIT;}
	if (!p_mchip->MCHIP_LED_Configure(47, 0)) {DbgLogError(("!!!%d\n",__LINE__));goto EXIT;}
	if (!p_mchip->MCHIP_LED_Configure(48, 1)) {DbgLogError(("!!!%d\n",__LINE__));goto EXIT;}
	
 #if 0//old way, we would drive LED3 via Magnum, when it was powered up
	//FGR - if LED3 will be used for Video Present turn it on now, so it won't blink off while starting encoder
	if(p_mchip->getBling_Options() & 0x08){
		if (!p_mchip->MCHIP_LED_Configure(49, 1)) {DbgLogError(("!!!%d\n",__LINE__));goto EXIT;}
	} else {
		if (!p_mchip->MCHIP_LED_Configure(49, 0)) {DbgLogError(("!!!%d\n",__LINE__));goto EXIT;}
	}
 #else//new way, always drive via Cypress, so make sure LED3 off on Magnum
	if (!p_mchip->MCHIP_LED_Configure(49, 0)) {DbgLogError(("!!!%d\n",__LINE__));goto EXIT;}
 #endif
#endif
	DbgLogRelease(("Using %d block(s) for SPB transfers\n", p_mchip->getSBP0Blocks()));

    // configure MCHIP GPIOx output to 1
    // we expect the test image to set it to 0 when it is booted and ready for SBP
    if (!p_mchip->MCHIP_GPIOx_Configure(1)) {DbgLogError(("!!!%d\n",__LINE__));goto EXIT;}

	// zero DRAM
    // this seems to be necessary for the binaries to run successfully?
    // HINT: maybe required for MIPS bootup, which runs in the first 12MB
    //MCHIP_Binary_ZeroDRAM(256*1024*1024);
    if(!p_mchip->MCHIP_Binary_ZeroDRAM(13*1024*1024)){
		return HWAPI_Fail;
	}

    ret = HWAPI_Success;// was EXIT_SUCCESS;

EXIT:

	if(ret == HWAPI_Success)// was EXIT_SUCCESS)
		return HWAPI_Success;
	else
		return HWAPI_Fail;
}

#ifdef HAUPPAUGE
DWORD dwUSB_VerifyFWload = 0x00; //FGR - BUGBUG - enabling this can break HW bootup

static HWAPIErrCode HCW_BinaryVerify(USBBootMChip_t *p_mchip, const char *fileName, Uint32 fwBaseAddr)
{
	DbgLogRelease(("HCW_BinaryVerify(%p, '%s', 0x%x)\n", p_mchip, fileName, fwBaseAddr));

	Uint32 size = 0;
    Uint8* bin = NULL;
	int memfail = 0;
	static char dumpfile[256];

	fwBaseAddr &= 0x1fffffff;

	if(!p_mchip->prv_load_bin(fileName, &bin, &size)){
		DbgLogError(("HCW_BinaryVerify - prv_load_bin() failed\n"));
		return HWAPI_Fail;
	}

	Uint8* buf = (Uint8*)MemAllocFromHeap(__FILE__, __LINE__, size);
	if( buf == NULL ){ 
		DbgLogError(("HCW_BinaryVerify - cannot allocate buffer\n"));
		MemFree2Heap(__FILE__, __LINE__, bin);
		return HWAPI_Fail;
	}
	memset(buf, 0, size);

	if(dwUSB_VerifyFWload & 0x10){
		//FGR - this method is VERY slow, but reliable
		DbgLog(("HCW_BinaryVerify - calling MCHIP_ReadBlock\n"));
		if( !p_mchip->MCHIP_ReadBlock( fwBaseAddr, buf, size) )
		{
			DbgLogError(("HCW_BinaryVerify - MCHIP_ReadBlock failed\n"));
			MemFree2Heap(__FILE__, __LINE__, buf);
			MemFree2Heap(__FILE__, __LINE__, bin);
			return HWAPI_Fail;
		}
	} else {
		//FGR - this method is fast, but will break any further attempt to use the FW
		// however, it's generally good for debugging
		DbgLog(("HCW_BinaryVerify - calling prv_sbp1_read\n"));
		if( !p_mchip->prv_sbp1_read( fwBaseAddr, buf, size) )
		{
			DbgLogError(("HCW_BinaryVerify - prv_sbp1_read failed\n"));
			MemFree2Heap(__FILE__, __LINE__, buf);
			MemFree2Heap(__FILE__, __LINE__, bin);
			return HWAPI_Fail;
		}
	}
	DbgLogRelease(("HCW_BinaryVerify - Comparing %u bytes...\n", size));

	for( Uint32 i = 0; i < size; i++ )
	{
		if( bin[i] != buf[i] ){
			DbgLogError((" offset 0x%08x, file: 0x%02x, mem: 0x%02x\n", i, bin[i], buf[i]));
			memfail = 1;

#if 0
			strcpy(dumpfile, fileName);
			strcat(dumpfile, ".ok");
			p_mchip->prv_save_bin(dumpfile, bin, size);//write the good reference file

			strcpy(dumpfile, fileName);
			strcat(dumpfile, ".bad");
			p_mchip->prv_save_bin(dumpfile, buf, size);//write the bad, readback data
#endif
			break;
		}
	}
	DbgLog(("HCW_BinaryVerify - Compare complete\n"));

	MemFree2Heap(__FILE__, __LINE__, buf);
	MemFree2Heap(__FILE__, __LINE__, bin);
	
	if(memfail)
		return HWAPI_Fail;
	return HWAPI_Success;
}
#endif

HWAPIErrCode USB_BinaryDownload (USBDevHandle hDevice, FIRMWARE_FILE *binary)
{
	DbgLogInfo(("USB_BinaryDownload(%p, %p)\n", hDevice, binary));
    // load MIPS binary and write its jump instruction
    usb_config_st *pUsbConfig = (usb_config_st*)hDevice;
	USBBootMChip_t *p_mchip = pUsbConfig->p_mchip;
	Uint32 size = 0;
    Uint8* bin = NULL;
	
	if (!p_mchip->prv_load_bin(binary->mipsFileName, &bin, &size))
		return HWAPI_Fail;

    // load binary to MIPS
    if (!p_mchip->MCHIP_Binary_LoadMIPS(binary->mipsBaseAddr, binary->mipsEntryAddr, bin, size, TRUE))
	{
	    MemFree2Heap(__FILE__, __LINE__, bin); //FGR - don't leak memory!!
		HCW_BinaryVerify(p_mchip, binary->mipsFileName, binary->mipsBaseAddr);
		p_mchip->setSBP0Blocks(1);//FGR - force subsequent FW downloads to slowest transfer rate
		return HWAPI_Fail;
	}
    MemFree2Heap(__FILE__, __LINE__, bin);

	if (!p_mchip->prv_load_bin(binary->sparcFileName, &bin, &size))
		return HWAPI_Fail;

    // load binary to Sparc
    if (!p_mchip->MCHIP_Binary_LoadSPARC(binary->sparcBaseAddr, binary->sparcEntryAddr, bin, size, TRUE))
	{
	    MemFree2Heap(__FILE__, __LINE__, bin); //FGR - don't leak memory!!
		HCW_BinaryVerify(p_mchip, binary->sparcFileName, binary->sparcBaseAddr);
		p_mchip->setSBP0Blocks(1);//FGR - force subsequent FW downloads to slowest transfer rate
		return HWAPI_Fail;
	}
    MemFree2Heap(__FILE__, __LINE__, bin);

#ifdef HAUPPAUGE
	//FGR - enabling these tests can break further use of FW; use only for debug
	if(dwUSB_VerifyFWload & 0x01){
		if(HCW_BinaryVerify(p_mchip, binary->mipsFileName, binary->mipsBaseAddr) != HWAPI_Success){
			return HWAPI_Fail;
		}
	}
	if(dwUSB_VerifyFWload & 0x02){
		if(HCW_BinaryVerify(p_mchip, binary->sparcFileName, binary->sparcBaseAddr) != HWAPI_Success){
			return HWAPI_Fail;
		}
	}
#endif

    return HWAPI_Success;
}


HWAPIErrCode USB_SystemBootup (USBDevHandle hDevice)
{
	DbgLogInfo(("USB_SystemBootup(%p)\n", hDevice));
    usb_config_st *pUsbConfig = (usb_config_st*)hDevice;
	USBBootMChip_t *p_mchip = pUsbConfig->p_mchip;
    HWAPIErrCode ret = HWAPI_Fail;
    DWORD start = 0;
    Uint16 val16;
    Uint32 val32;
	DWORD dwUSB_SystemBootupDelay = 750; //FGR - BUGBUG - what's a resonable value here (was 2000)??

    if (!p_mchip->MCHIP_Binary_BootMIPS()) 
    {
        DbgLogError(("MIPS Binary boot failure.\n"));
        goto EXIT;
    }

    wrapSleep_ms(125);

    if (!p_mchip->MCHIP_Host_Read16(DMN_HB_CONTROL, &val16)) {DbgLogError(("!!!%d\n",__LINE__));goto EXIT;}
	DbgLogInfo(("MCHIP: Host Control = 0x%04x\n", val16));

    if (!p_mchip->MCHIP_Binary_BootSystemSPARC()) return HWAPI_Fail;

    // check that MCHIP Host Control Register shows System SPARC running and not errored
    if (!p_mchip->MCHIP_Host_Read16(DMN_HB_CONTROL, &val16)) {DbgLogError(("!!!%d\n",__LINE__));goto EXIT;}
    DbgLogInfo(("MCHIP: Host Control = 0x%04x\n", val16));
    if (val16 & DMN_HB_HC_SCPU_RST)
    {
        DbgLogError(("MCHIP: ERROR %d: SCPU_Rst set after image boot\n", __LINE__));
        goto EXIT;
    }
    if (val16 & DMN_HB_HC_SCPU_ERR)
    {
        DbgLogError(("MCHIP: ERROR %d: SCPU_Err set after image boot\n", __LINE__));
        goto EXIT;
    }

    // check that image is running
    // expect the image to enable some of the INTREQ1 hardware interrupt
    // sources on system SPARC, for example, watchdog and timer interrupts

	start = wrapGetTicks_ms();
    for (;;)
    {
        // app set INTREQLVL1A?
        if (!p_mchip->MCHIP_Read32(DMN_ADSP_INTREQLVL1A, &val32)) {DbgLogError(("!!!%d\n",__LINE__));goto EXIT;};
        if (val32 != 0x00000000) break;
        // app set INTREQLVL1B?
        if (!p_mchip->MCHIP_Read32(DMN_ADSP_INTREQLVL1B, &val32)) {DbgLogError(("!!!%d\n",__LINE__));goto EXIT;};
        if (val32 != 0x00000000) break;

        // timed out?
        if (wrapGetTicks_ms() - start > MCHIP_BOOT_TIMEOUT)
        {
            DbgLogError(("MCHIP: ERROR %d: image not running\n", __LINE__));
            goto EXIT;
        }
		wrapSleep_ms(10);
    }

	hcwGetRegistryDWORD("USB_SystemBootupDelay", &dwUSB_SystemBootupDelay);
	if(dwUSB_SystemBootupDelay > 3000){
		dwUSB_SystemBootupDelay = 3000;
	}
	if(dwUSB_SystemBootupDelay){
		wrapSleep_ms(dwUSB_SystemBootupDelay);
	}
    DbgLogInfo(("USB_SystemBootup() after image startup delay (%ums)\n", dwUSB_SystemBootupDelay));

    // all tests OK
    ret = HWAPI_Success;
    // fall thru to exit


EXIT:
	
#if 0//FGR - BUGBUG - these always fail, WHY? Anyway, don't waste time trying
    // temp: read host control, host version
    if (p_mchip->MCHIP_Host_Read16(DMN_HB_CONTROL, &val16)) {DbgLogInfo(("on exit: Host Control=0x%04x\n", val16));}
    if (p_mchip->MCHIP_Host_Read16(DMN_HB_VERSION, &val16)) {DbgLogInfo(("on exit: Host Version=0x%04x\n", val16));}
#endif

	if (!p_mchip->MCHIP_SBP_Select()) 
	{
		return HWAPI_Fail;
	}

	return ret;
}


HWAPIErrCode USB_Exit (USBDevHandle hDevice)
{
	DbgLogInfo(("USB_Exit(%p)\n", hDevice));

    if(hDevice!=NULL)
    {
		usb_config_st *pUsbConfig = (usb_config_st*)hDevice;
		USBBootMChip_t *p_mchip = pUsbConfig->p_mchip;
		
		if(p_mchip){
#if 0//FGR - this will get done, after DXT is isolated from video bus, in CHapi::powerDownHW()
			if (!p_mchip->MCHIP_PortA_Set_POWER_ENABLE_H(0))
			{
				DbgLogError(("USB_Exit() MCHIP_PortA_Set_POWER_ENABLE_H() FAILED!!\n"));
			}
			p_mchip->MCHIP_PortA_Set_MCHIP_RESET_L(0);
			wrapSleep_ms(30);
#endif
		} else {
			DbgLogError(("USB_Exit() p_mchip==NULL!!\n"));
		}
		pUsbConfig->p_mchip = NULL; //assume caller will delete the actual USBBootMChip_t class

		MemFree2Heap(__FILE__, __LINE__, hDevice);
        hDevice = NULL;
    }
    else
    {
		DbgLogError(("USB_Exit() hDevice==NULL!!\n"));
        return HWAPI_Fail;
    }
    return HWAPI_Success;
}

HWAPIErrCode USB_Receive(USBDevHandle hDevice, Uint8 *buf, Uint32 size)
{
    usb_config_st *pUsbConfig = (usb_config_st*)hDevice;
	USBBootMChip_t *p_mchip = pUsbConfig->p_mchip;
	p_mchip->lockBus();

	if(!p_mchip->MCHIP_SBP_Select()){
		p_mchip->unlockBus();
		return HWAPI_Fail;
	}
	int ret = p_mchip->UsbParIn((char*)buf, size);
	p_mchip->unlockBus();

	if(1 == ret)
		return HWAPI_Success;
	else
		return HWAPI_Fail;

}

HWAPIErrCode USB_Send (USBDevHandle hDevice, Uint8 *buf, Uint32 size)
{
    usb_config_st *pUsbConfig = (usb_config_st*)hDevice;
	USBBootMChip_t *p_mchip = pUsbConfig->p_mchip;
	p_mchip->lockBus();
	//DbgLogInfo(("USB_Send: buf:0x%x, size:%d\n", buf, size));
	if(!p_mchip->MCHIP_SBP_Select()){
		p_mchip->unlockBus();
		return HWAPI_Fail;
	}

	int ret = p_mchip->UsbParOut((char*)buf, size);
	p_mchip->unlockBus();

	if(1 == ret)
		return HWAPI_Success;
	else
		return HWAPI_Fail;

}
