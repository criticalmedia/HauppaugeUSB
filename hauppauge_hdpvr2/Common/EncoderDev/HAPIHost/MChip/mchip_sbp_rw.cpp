//=============================================================================
//  File Name: mchip_sbp_rw.c
//
//  Copyright 2009 Magnum Semiconductor Inc. All rights reserved.
//
//  Description:
//      MCHIP SBP port bus read/write.
//
//  Modification History:
//      $Id: $
//      $Log: $
//
//=============================================================================


#include "mchip.h"

//#define BLOCKSIZE 512
#define BLOCKSIZE 1024

// note that we can't combine host and SBP waveforms into one waveform definition, even
// though there are 2 unused waveforms in both, as host waveform is 16-bit data bus and
// SBP waveform is 8-bit data bus

Boolean
USBBootMChip_t::
MCHIP_SBP_Select(void)
{
#ifndef HAUPPAUGE
    if (!UsbSetWFMode(getCurSbpFreq()))
#else
//	DbgLogTrace(("MCHIP_SBP_Select()\n"));

	BYTE mode = WF_SBP_30;
	//if(getCurSbpFreq() == SBP_FREQ_48){
	//	mode = WF_SBP_48; //FGR - BUGBUG - do we care about 48 anymore??
	//}
	if (!UsbSetWFMode(mode))
#endif
    {
        if(statusCnt < USB_ERR_LIMIT){
			DbgLogError(("MCHIP_SBP_Select: UsbSetWFMode failed\n"));
		}
        return FALSE;
    }

    // select waveform numbers: 2=read 3=write
    if (!UsbSetWFRW(2, 3))
    {
        DbgLogError(("MCHIP_SBP_Select: UsbSetWFRW failed\n"));
        return FALSE;
    }

    // set HST_SELECT* = 1 to select RDY0/SLRD <-- SBP0_REQ*
    if (!MCHIP_PortA_Set_HST_SELECT_L(1)){
        DbgLogError(("MCHIP_SBP_Select: MCHIP_PortA_Set_HST_SELECT_L failed\n"));
		return FALSE;
	}
    return TRUE;
}

Boolean
USBBootMChip_t::
MCHIP_SBP0_Write(const Uint8* data, Uint32 len)
{
    Boolean rst = TRUE;
    Uint8 * tmpData;
    //Uint32 tmpLen1, tmpLen2;

    Uint32 loop = 0;
    Uint32 residueLen = 0;
	Uint32 loopsize=512;//was 1024

    ASSERT(data);
    ASSERT(len);

    //tmpLen1 = len;
    tmpData = (Uint8 *)data;

#if 1
    //if( len > USB_RW_MAXBYTES_PERTIME )
    {
        loop = len/loopsize;
        residueLen = len%loopsize;
        UsbSetOutputLen(residueLen, loop);
        //DbgLogInfo(("total read %d, %d\n", len, loop));
    }
#endif

    /* sbp can only write 1024 bytes each time, if big than 1024, write will be fail. don't know why */
/*    do
    {
        if( tmpLen1 > USB_RW_MAXBYTES_PERTIME )
            tmpLen2 = USB_RW_MAXBYTES_PERTIME;
        else
        {
            tmpLen2 = tmpLen1;
            UsbSetOutputLen( tmpLen1, 0);
        }

        if (!UsbParOutHighSpeed((char*)tmpData, tmpLen2))
        {
            DbgLogError(("UsbParOut failed\n"));
            rst = FALSE;
            break;
        }
        tmpData += tmpLen2;
        tmpLen1 -= tmpLen2;
    }
    while(tmpLen1 > 0);*/

    while(loop>=maxSBP0Blocks)
    {
        if (!UsbParOutHighSpeed((char*)tmpData, loopsize*maxSBP0Blocks))
        {
            DbgLogError(("MCHIP_SBP0_Write: UsbParOut failed, loop=%d\n",loop));
			maxSBP0Blocks = 1; //force any retrys to use smallest possible SBP write size
            rst = FALSE;
            break;
        }
        tmpData += loopsize*maxSBP0Blocks;
        loop    -= maxSBP0Blocks;
    }

    while(loop>0)
    {
        if (!UsbParOutHighSpeed((char*)tmpData, loopsize))
        {
            DbgLogError(("MCHIP_SBP0_Write: UsbParOut failed, loop=%d\n",loop));
            rst = FALSE;
            break;
        }
        tmpData += loopsize;
        loop--;
    }

    if(residueLen>0)
    {
        if (!UsbParOutHighSpeed((char*)tmpData, residueLen))
        {
            DbgLogError(("MCHIP_SBP0_Write: UsbParOut residue failed\n"));
			maxSBP0Blocks = 1; //force any retrys to use smallest possible SBP write size
            rst = FALSE;
        }
    }

    return rst;
}

#if 1//FGR - Removed
Boolean
USBBootMChip_t::
MCHIP_SBP1_Read(Uint8* data, Uint32 len)
{
    Boolean rst = TRUE;
    Uint8 * tmpData;
    //Uint32 tmpLen1, tmpLen2;

    Uint32 loop = 0;
    Uint32 residueLen = 0;
    
    ASSERT(data);
    ASSERT(len);

    //if( len > USB_RW_MAXBYTES_PERTIME )
    {
        loop = len/1024;
        residueLen = len%1024;
        UsbSetInputLen(residueLen, loop);
        //LOG_DBG("total read: loop=%d, residueLen=%d\n", loop, residueLen);
    }

    //tmpLen1 = len;
    tmpData = data;

    /* sbp can only read 1024 bytes each time, if big than 1024, read will be fail. don't know why */
/*    do
    {
        if( tmpLen1 > USB_RW_MAXBYTES_PERTIME )
            tmpLen2 = USB_RW_MAXBYTES_PERTIME;
        else
        {
            UsbSetInputLen( tmpLen1, 0);
            tmpLen2 = tmpLen1;
        }

        if (!UsbParInHighSpeed((char*)tmpData, tmpLen2))
        {
            //DbgLogInfo(("UsbParIn failed\n"));
            rst = FALSE;
            break;
        }
        tmpData += tmpLen2;
        tmpLen1 -= tmpLen2;
    }
    while(tmpLen1 > 0);*/

    while(loop>0)
    {
        if (!UsbParInHighSpeed((char*)tmpData, BLOCKSIZE))
        {
            DbgLogError(("MCHIP_SBP1_Read: UsbParInHighSpeed failed, loop=%d\n",loop));
            rst = FALSE;
            break;
        }
        tmpData += BLOCKSIZE;
        loop--;
    }

    if(residueLen>0)
    {
        if (!UsbParInHighSpeed((char*)tmpData, residueLen))
        {
            DbgLogError(("MCHIP_SBP1_Read: UsbParInHighSpeed failed, len=%d\n",residueLen));
            rst = FALSE;        
        }
    }

    return rst;
}
#endif//FGR - Removed


Uint8
USBBootMChip_t::
getCurSbpFreq()
{
	DbgLogTrace(("getCurSbpFreq()=%d\n", gSbpFreq));
    return gSbpFreq;
}
