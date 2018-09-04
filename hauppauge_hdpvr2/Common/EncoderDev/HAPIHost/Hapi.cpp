//=============================================================================
//  File Name: Hapi.c
//
//  Copyright 2010 Magnum Semiconductor Inc. All rights reserved.
//
//  Description:
//      Hapi Host APIs and multi thread flow.
//
//
//=============================================================================

#define HCW_POLL_DELAY 30 //FGR - BUGBUG - what's a reasonable polling timeout??
#define HCW_SEMA_DELAY 10 //FGR - BUGBUG - what's a reasonable UtilSemTake() timeout??

#include <string.h>
#include <stdlib.h>

#include "Hapi.h"
#include "Hapi_priv.h"
//#include "Hwapi.h"
//#include "HwapiUsb.h"
#include "HapiMsg.h"
#include "SwapEndian.h"
#include "mchip_utils.h"

//#ifndef INFINITE
#define INFINITE -1
//#endif


//#define USER_CMD_TIME_OUT 12000   // in milli second
DWORD USER_CMD_TIME_OUT = 5000;   //FGR - need to qualify this value better; smaller is better

#include "mchip.h"

//#define USE_WRITE_THREAD

uint32_t dwHAPI_MSG_RSV2_test = 1; //FGR - allow us to skip test if Magnum FW does not support it (as some test releases don't)

#define IS_DATA_MESSAGE(x) \
	(x == HWAPI_MESSAGE_STREAM_OUTPUT_DATA	\
	 || x == HWAPI_MESSAGE_STREAM_INPUT_DATA )

// no wait message will be put to sendQ, sent by cmdThread
// including: input data, rsp of data request, rsp of output data
#define IS_NOWAIT_MESSAGE(x) \
	(x == HWAPI_MESSAGE_STREAM_INPUT_DATA \
		|| x == HWAPI_MESSAGE_STREAM_DATA_REQ \
		|| x == HWAPI_MESSAGE_STREAM_OUTPUT_DATA ) 

// user cmd will be put to sendAndWaitQueue, sent by cmdThread
#define IS_USER_CMD(x) \
	(x == HWAPI_MESSAGE_GET_PARAM_REQ	\
	 || x == HWAPI_MESSAGE_SET_PARAM		\
	 || x == HWAPI_MESSAGE_START			\
	 || x == HWAPI_MESSAGE_STOP			\
	 || x == HWAPI_MESSAGE_INIT				\
	 || x == HWAPI_MESSAGE_EXIT			\
	 || x == HWAPI_MESSAGE_FWUPGRADE   \
	 || x == HWAPI_MESSAGE_SET_AVL    \
	 || x == HWAPI_MESSAGE_I2C_READ    \
	 || x == HWAPI_MESSAGE_I2C_WRITE   \
	 || x == HWAPI_MESSAGE_GPIO_READ\
	 || x == HWAPI_MESSAGE_GPIO_WRITE\
	 || x == HWAPI_MESSAGE_I2C_SET_CLOCK_FREQ \
	 || x == HWAPI_MESSAGE_STATUS_QUERY \
	 || x == HWAPI_MESSAGE_SET_AR \
	 ||x == HWAPI_MESSAGE_SET_PCR \
	 || x == HWAPI_MESSAGE_I2C_MONITOR_INSTALL\
	 || x == HWAPI_MESSAGE_LOGO_CONFIG\
	 || x == HWAPI_MESSAGE_LOGO_ON_OFF)

#define IS_USER_CMD_RSP(x) \
	(x == HWAPI_MESSAGE_GET_PARAM_REQ	\
	 || x == HWAPI_MESSAGE_SET_PARAM		\
	 || x == HWAPI_MESSAGE_START			\
	 || x == HWAPI_MESSAGE_STOP			\
	 || x == HWAPI_MESSAGE_INIT				\
	 || x == HWAPI_MESSAGE_EXIT			\
	 || x == HWAPI_MESSAGE_FWUPGRADE   \
	 || x == HWAPI_MESSAGE_SET_AVL    \
	 || x == HWAPI_MESSAGE_I2C_READ    \
	 || x == HWAPI_MESSAGE_I2C_WRITE   \
	 || x == HWAPI_MESSAGE_GPIO_READ\
	 || x == HWAPI_MESSAGE_GPIO_WRITE\
	 || x == HWAPI_MESSAGE_I2C_SET_CLOCK_FREQ\
        || x == HWAPI_MESSAGE_STATUS_QUERY \
	 || x == HWAPI_MESSAGE_SET_AR \
	 ||x == HWAPI_MESSAGE_SET_PCR \
	 || x == HWAPI_MESSAGE_I2C_MONITOR_INSTALL\
	 || x == HWAPI_MESSAGE_LOGO_CONFIG\
	 || x == HWAPI_MESSAGE_LOGO_ON_OFF)

#define IS_DATA_RSP(x) \
	(x == HWAPI_MESSAGE_STREAM_INPUT_DATA)



unsigned int crc32_table[256] = {
		0x00000000L, 0x77073096L, 0xee0e612cL, 0x990951baL, 0x076dc419L,
		0x706af48fL, 0xe963a535L, 0x9e6495a3L, 0x0edb8832L, 0x79dcb8a4L,
		0xe0d5e91eL, 0x97d2d988L, 0x09b64c2bL, 0x7eb17cbdL, 0xe7b82d07L,
		0x90bf1d91L, 0x1db71064L, 0x6ab020f2L, 0xf3b97148L, 0x84be41deL,
		0x1adad47dL, 0x6ddde4ebL, 0xf4d4b551L, 0x83d385c7L, 0x136c9856L,
		0x646ba8c0L, 0xfd62f97aL, 0x8a65c9ecL, 0x14015c4fL, 0x63066cd9L,
		0xfa0f3d63L, 0x8d080df5L, 0x3b6e20c8L, 0x4c69105eL, 0xd56041e4L,
		0xa2677172L, 0x3c03e4d1L, 0x4b04d447L, 0xd20d85fdL, 0xa50ab56bL,
		0x35b5a8faL, 0x42b2986cL, 0xdbbbc9d6L, 0xacbcf940L, 0x32d86ce3L,
		0x45df5c75L, 0xdcd60dcfL, 0xabd13d59L, 0x26d930acL, 0x51de003aL,
		0xc8d75180L, 0xbfd06116L, 0x21b4f4b5L, 0x56b3c423L, 0xcfba9599L,
		0xb8bda50fL, 0x2802b89eL, 0x5f058808L, 0xc60cd9b2L, 0xb10be924L,
		0x2f6f7c87L, 0x58684c11L, 0xc1611dabL, 0xb6662d3dL, 0x76dc4190L,
		0x01db7106L, 0x98d220bcL, 0xefd5102aL, 0x71b18589L, 0x06b6b51fL,
		0x9fbfe4a5L, 0xe8b8d433L, 0x7807c9a2L, 0x0f00f934L, 0x9609a88eL,
		0xe10e9818L, 0x7f6a0dbbL, 0x086d3d2dL, 0x91646c97L, 0xe6635c01L,
		0x6b6b51f4L, 0x1c6c6162L, 0x856530d8L, 0xf262004eL, 0x6c0695edL,
		0x1b01a57bL, 0x8208f4c1L, 0xf50fc457L, 0x65b0d9c6L, 0x12b7e950L,
		0x8bbeb8eaL, 0xfcb9887cL, 0x62dd1ddfL, 0x15da2d49L, 0x8cd37cf3L,
		0xfbd44c65L, 0x4db26158L, 0x3ab551ceL, 0xa3bc0074L, 0xd4bb30e2L,
		0x4adfa541L, 0x3dd895d7L, 0xa4d1c46dL, 0xd3d6f4fbL, 0x4369e96aL,
		0x346ed9fcL, 0xad678846L, 0xda60b8d0L, 0x44042d73L, 0x33031de5L,
		0xaa0a4c5fL, 0xdd0d7cc9L, 0x5005713cL, 0x270241aaL, 0xbe0b1010L,
		0xc90c2086L, 0x5768b525L, 0x206f85b3L, 0xb966d409L, 0xce61e49fL,
		0x5edef90eL, 0x29d9c998L, 0xb0d09822L, 0xc7d7a8b4L, 0x59b33d17L,
		0x2eb40d81L, 0xb7bd5c3bL, 0xc0ba6cadL, 0xedb88320L, 0x9abfb3b6L,
		0x03b6e20cL, 0x74b1d29aL, 0xead54739L, 0x9dd277afL, 0x04db2615L,
		0x73dc1683L, 0xe3630b12L, 0x94643b84L, 0x0d6d6a3eL, 0x7a6a5aa8L,
		0xe40ecf0bL, 0x9309ff9dL, 0x0a00ae27L, 0x7d079eb1L, 0xf00f9344L,
		0x8708a3d2L, 0x1e01f268L, 0x6906c2feL, 0xf762575dL, 0x806567cbL,
		0x196c3671L, 0x6e6b06e7L, 0xfed41b76L, 0x89d32be0L, 0x10da7a5aL,
		0x67dd4accL, 0xf9b9df6fL, 0x8ebeeff9L, 0x17b7be43L, 0x60b08ed5L,
		0xd6d6a3e8L, 0xa1d1937eL, 0x38d8c2c4L, 0x4fdff252L, 0xd1bb67f1L,
		0xa6bc5767L, 0x3fb506ddL, 0x48b2364bL, 0xd80d2bdaL, 0xaf0a1b4cL,
		0x36034af6L, 0x41047a60L, 0xdf60efc3L, 0xa867df55L, 0x316e8eefL,
		0x4669be79L, 0xcb61b38cL, 0xbc66831aL, 0x256fd2a0L, 0x5268e236L,
		0xcc0c7795L, 0xbb0b4703L, 0x220216b9L, 0x5505262fL, 0xc5ba3bbeL,
		0xb2bd0b28L, 0x2bb45a92L, 0x5cb36a04L, 0xc2d7ffa7L, 0xb5d0cf31L,
		0x2cd99e8bL, 0x5bdeae1dL, 0x9b64c2b0L, 0xec63f226L, 0x756aa39cL,
		0x026d930aL, 0x9c0906a9L, 0xeb0e363fL, 0x72076785L, 0x05005713L,
		0x95bf4a82L, 0xe2b87a14L, 0x7bb12baeL, 0x0cb61b38L, 0x92d28e9bL,
		0xe5d5be0dL, 0x7cdcefb7L, 0x0bdbdf21L, 0x86d3d2d4L, 0xf1d4e242L,
		0x68ddb3f8L, 0x1fda836eL, 0x81be16cdL, 0xf6b9265bL, 0x6fb077e1L,
		0x18b74777L, 0x88085ae6L, 0xff0f6a70L, 0x66063bcaL, 0x11010b5cL,
		0x8f659effL, 0xf862ae69L, 0x616bffd3L, 0x166ccf45L, 0xa00ae278L,
		0xd70dd2eeL, 0x4e048354L, 0x3903b3c2L, 0xa7672661L, 0xd06016f7L,
		0x4969474dL, 0x3e6e77dbL, 0xaed16a4aL, 0xd9d65adcL, 0x40df0b66L,
		0x37d83bf0L, 0xa9bcae53L, 0xdebb9ec5L, 0x47b2cf7fL, 0x30b5ffe9L,
		0xbdbdf21cL, 0xcabac28aL, 0x53b39330L, 0x24b4a3a6L, 0xbad03605L,
		0xcdd70693L, 0x54de5729L, 0x23d967bfL, 0xb3667a2eL, 0xc4614ab8L,
		0x5d681b02L, 0x2a6f2b94L, 0xb40bbe37L, 0xc30c8ea1L, 0x5a05df1bL,
		0x2d02ef8dL
};

#ifndef DRIVER_BUILD
const char * MsgStr[] = 
{
	"\"getParam\"",
	"\"setParam\"",
	"\"start\"",
	"\"stop\"",
	"\"init\"",
	"\"exit\"",
	"\"inputData\"",
	"\"fwupdate\"",
	"\"i2cRead\"",
	"\"i2cWrite\"",
	"\"GpioRead\"",
	"\"GpioWrite\"",
	"\"setClockFreq\"",
	"\"setAVL\"",
	"\"i2cmonitorinstall\"",
	"\"setAR\"",
	"\"setPCR\"",
	"\"statusQuery\"",
	"\"logoConfig\"",
	"\"logoOnOff\"",
	"\"error\"",
	"\"dataReq\"",
	"\"outputData\"",
	"\"avUpdate\"",
	"\"i2coutputmonitorData\"",
};
#endif

unsigned int CRC32(unsigned char * databuf, unsigned int len)
{
    unsigned int temp;
    unsigned int oldcrc=0xffffffff;

    while(len--){
        temp = (oldcrc ^(*databuf++)) & 0x000000FF;
        oldcrc  = (( oldcrc >> 8) & 0x00FFFFFF) ^ crc32_table[temp];
    }

    return ~oldcrc; 
}

static void printHdr(HWAPI_MSG_HEADER *hdr)
{
	LOG_INFO(("  hdr->msgTag=0x%x\n", hdr->msgTag));
	LOG_INFO(("  hdr->msgVersion=0x%x\n", hdr->msgVersion));
	LOG_INFO(("  hdr->type=0x%x\n", hdr->type));
	LOG_INFO(("  hdr->cookie=0x%x\n", hdr->cookie));
	LOG_INFO(("  hdr->payloadSize=0x%x\n", hdr->payloadSize));
	LOG_INFO(("  hdr->responseCode=0x%x\n", hdr->responseCode));
	LOG_INFO(("  hdr->reserved1=0x%x\n", hdr->reserved1));	
	LOG_INFO(("  hdr->reserved2=0x%x\n", hdr->reserved2));				
}

bool checkPayloadSize(HWAPI_MSG_HEADER *pHeader)
{
	Uint32 correctSize = 0;
	Uint32 headerSize = sizeof(HWAPI_MSG_HEADER);
	switch(pHeader->type)
	{
		case HWAPI_MESSAGE_INIT:
			correctSize = sizeof(HWAPI_MSG_INIT_RSP) - headerSize;
			break;
		case HWAPI_MESSAGE_EXIT:
			correctSize = sizeof(HWAPI_MSG_EXIT_RSP) - headerSize;
			break;
		case HWAPI_MESSAGE_GET_PARAM_REQ:
			correctSize = sizeof(HWAPI_MSG_GET_PARAM_RSP) - headerSize;
			break;
		case HWAPI_MESSAGE_SET_PARAM:
			correctSize = sizeof(HWAPI_MSG_SET_PARAM_RSP) - headerSize;
			break;
		case HWAPI_MESSAGE_START:
			correctSize = sizeof(HWAPI_MSG_START_RSP) - headerSize;
			break;
		case HWAPI_MESSAGE_STOP:
			correctSize = sizeof(HWAPI_MSG_STOP_RSP) - headerSize;
			break;
		case HWAPI_MESSAGE_STREAM_DATA_REQ:
			correctSize = sizeof(HWAPI_MSG_STREAM_DATA_REQUEST_RSP) - headerSize;
			break;
		case HWAPI_MESSAGE_STREAM_OUTPUT_DATA:
			correctSize = pHeader->payloadSize;
			break;
		case HWAPI_MESSAGE_AV_UPDATE:
			correctSize = sizeof(HWAPI_MSG_AV_UPDATE) - headerSize;
			break;
		case HWAPI_MESSAGE_FWUPGRADE:
			correctSize = sizeof(HWAPI_MSG_FWUPGRADE_RSP) - headerSize;
            break; 
		case HWAPI_MESSAGE_SET_AVL:
            correctSize = sizeof(HWAPI_MSG_SET_AVL_RSP) - headerSize;
			break;
		case HWAPI_MESSAGE_STATUS_QUERY:
			 correctSize = sizeof(HWAPI_MSG_QUERY_STATUS_RSP) - headerSize;
			break;
		case HWAPI_MESSAGE_SET_AR:
			correctSize = sizeof(HWAPI_MSG_AR_DATA_RSP) - headerSize;
			break;
		case HWAPI_MESSAGE_SET_PCR:
			correctSize = sizeof(HWAPI_MSG_PCR_DATA_RSP) - headerSize;
			break;
        case HWAPI_MESSAGE_I2C_READ:
            correctSize = sizeof(HWAPI_MSG_I2C_READ_RSP) - headerSize;
            break;
		case HWAPI_MESSAGE_I2C_WRITE:
			correctSize = sizeof(HWAPI_MSG_I2C_WRITE_RSP) - headerSize;
            break;
		case HWAPI_MESSAGE_GPIO_READ:
            correctSize = sizeof(HWAPI_MSG_GPIO_READ_RSP) - headerSize;
        	break;
		case HWAPI_MESSAGE_GPIO_WRITE:
            correctSize = sizeof(HWAPI_MSG_GPIO_WRITE_RSP) - headerSize;
        	break;
		case HWAPI_MESSAGE_LOGO_CONFIG:
            correctSize = sizeof(HWAPI_MSG_LOGO_CONFIG_RSP) - headerSize;
        	break;
        case HWAPI_MESSAGE_LOGO_ON_OFF:
            correctSize = sizeof(HWAPI_MSG_LOGO_ON_OFF_RSP) - headerSize;
			break;
		case HWAPI_MESSAGE_I2C_SET_CLOCK_FREQ:
			correctSize = sizeof(HWAPI_MSG_I2C_CLOCK_FREQ_RSP) - headerSize;
			break;
        case HWAPI_MESSAGE_I2C_MONITOR_INSTALL:
             correctSize = sizeof(HWAPI_MSG_I2C_MONITOR_INSTALL_RSP) - headerSize;
             break;
		case HWAPI_MESSAGE_I2C_OUTPUT_MONITOR_DATA:
			 correctSize = sizeof(HWAPI_MSG_I2C_OUTPUT_MONITOR_DATA) - headerSize;
			break;
        case HWAPI_MESSAGE_ERROR:
            correctSize = sizeof(HWAPI_MSG_ERR_UPDATE) - headerSize;
            break;
		default:
			DbgLogError(("checkPayloadSize() type:0x%x Unknown; size=%u\n", pHeader->type, pHeader->payloadSize));
            return false;
			break;
	}
	if(correctSize != pHeader->payloadSize){
		DbgLogError(("checkPayloadSize() type:0x%x, size=%u, expect=%d\n", 
			pHeader->type, pHeader->payloadSize, correctSize));
		return false;
	}
	return true;
}

static void DLLCALL cmdThreadFunc(void * data)
{
	HAPIHandler hapi = (HAPIHandler)data;
	QueueItem item;
	Boolean toSend ;
	Boolean received ;
	int headerSize = sizeof(HWAPI_MSG_HEADER);
	HWAPI_MSG_HEADER header, *pHeader;
	HWAPIErrCode hwapi_err;
	Uint8 * receiveBuffer = NULL;	
	//Uint32 currentTime;
	dxErrCode err;

    Boolean bAnySuccess;  // To indicate if any successful send/receive in a loop.
    Boolean bByteLossResync;
	Uint8   payloadByte; // The byte that have been read into msg header when byte loss occured in message header. 

#ifndef DRIVER_BUILD//HAUPPAUGE
	unsigned int rd_payload_cnt=0;

	//printf("size of header: %d\n", headerSize);
	//printf("size of HWAPI_MSG_GET_PARAM_RSP: %d\n", sizeof(HWAPI_MSG_GET_PARAM_RSP));
	//printf("size of HAPI_Param: %d\n", sizeof(HAPI_Param));
	//printf("size of HAPI_GET_PARAM: %d\n", sizeof(HAPI_GET_PARAM));
	
#else
	DWORD rd_payload_time;

//	DbgLogInfo(("cmdThreadFunc(%p) startup Thread=%p\n", data, KeGetCurrentThread()));
	DbgLogInfo(("size of header: %d\n", headerSize));
	DbgLogInfo(("size of HWAPI_MSG_GET_PARAM_RSP: %d\n", sizeof(HWAPI_MSG_GET_PARAM_RSP)));
	DbgLogInfo(("size of HAPI_GET_PARAM: %d\n", sizeof(HAPI_GET_PARAM)));
#endif
	
	while(!hapi->exitCmdThread)
	{
		item = NULL;
		toSend = FALSE;
        bAnySuccess = FALSE;

		//===========================
		// check sendAndWaitQ
		//===========================
		//LOG_INFO(("take sendQSem\n"));
		err = UtilSemTakeDbg(hapi->sendAndWaitQueueSem, HCW_SEMA_DELAY, __LINE__);

		//LOG_INFO(("ct check sendAndWaitQ...err=%d\n", err));

		if(err == DX_SUCCESS && !HAPIIsQueueEmpty(hapi->sendAndWaitQueue))
		{
			//LOG_INFO(("ct sendAndWaitQ is not empty\n"));
			HAPIPeekQueue(hapi->sendAndWaitQueue, &item);
			if(item != NULL)
			{
				pHeader = (HWAPI_MSG_HEADER *)item;
				//LOG_INFO(("ct type:0x%x\n", pHeader->type));

				if(IS_USER_CMD(pHeader->type))
				{
					if(pHeader == hapi->pMsgWaitingRsp) // this cmd has been sent, check waiting timeout
					{
#ifdef HAUPPAUGE//BUGBUG - check for infinite timeout
						int32_t elapsed = UtilGetTime() - hapi->timeStartWaiting;
						if(elapsed < 0){
							DbgLogError(("??? pMsgWaitingRsp=%p elapsed=%d (%u, %u)\n", pHeader, elapsed, UtilGetTime(), hapi->timeStartWaiting));
							hapi->timeStartWaiting = UtilGetTime();
						}
						if(elapsed > USER_CMD_TIME_OUT - 500){
							DbgLogWarn(("SEVERE: pMsgWaitingRsp=%p appears stuck after %dms\n", pHeader, elapsed));
							
							QueueItem itemToRemove = NULL;
							HAPIDeQueue(hapi->sendAndWaitQueue, &itemToRemove);
							if (itemToRemove != pHeader){
								DbgLogError(("SEVERE: pMsgWaitingRsp=%p != itemToRemove=%p\n", pHeader, itemToRemove));
							}
							if (itemToRemove != NULL){
								MemFree2Heap(__FILE__, __LINE__, itemToRemove);
							}
							DbgLogError(("SEVERE: pMsgWaitingRsp=%p removed from queue\n", pHeader));

						} else if(elapsed > (int32_t)(USER_CMD_TIME_OUT/2)){
							DbgLogWarn((" pMsgWaitingRsp=%p waiting for %dms(limit=%u)\n", pHeader, elapsed, USER_CMD_TIME_OUT));
						} else if(elapsed > 6000){//to allow for testing with really big values of USER_CMD_TIME_OUT
							DbgLogWarn((" pMsgWaitingRsp=%p waiting for %dms(limit=%u)\n", pHeader, elapsed, USER_CMD_TIME_OUT));
						}
#endif
					}
					else // to send this cmd
					{
						if(hapi->pMsgWaitingRsp != NULL)
						{
							DbgLogError(("ct: pMsgWaitingRsp(%p) should be NULL!!!\n", hapi->pMsgWaitingRsp));
						}
						
						toSend = TRUE;
						hapi->pMsgWaitingRsp = pHeader;
						hapi->timeStartWaiting = UtilGetTime();
					}
				}
				else
				{
					DbgLogError(("ct: not a user command in sendAndWaitQ:type=0x%x !!!\n",pHeader->type));
				}
			}
			else
			{
				DbgLogError(("ct: peeked item is NULL when Q is not empty!!!\n"));
			}
		}

		if(err == DX_SUCCESS)
		{
			UtilSemGive(hapi->sendAndWaitQueueSem);
			//LOG_INFO(("ct sendAndWaitQSem given\n"));
		}

		// there is user cmd to send
		if(toSend && item != NULL)
		{

			Uint32 sendSize = pHeader->payloadSize + headerSize;
            Uint8 *msg;
			pHeader->cookie = hapi->cookie++;
			
			LOG_INFO(("ct send wait msg, type=0x%x payld %d <0x%x>\n", pHeader->type,pHeader->payloadSize, pHeader->cookie ));

			if(hapi->endianSwap == 1)
            {
                msg = (Uint8*)MemAllocFromHeap(__FILE__, __LINE__, sendSize);
                memcpy(msg, pHeader, sendSize);
				swapMessage((HWAPI_MSG_HEADER*)msg, 0);
            }
            else
            {
                msg = (Uint8*)pHeader;
            }
#if 0
            if (pHeader->type == HWAPI_MESSAGE_STATUS_QUERY)
            {
                Uint16 i;
                for (i=0; i<sizeof(HWAPI_MSG_QUERY_STATUS); i++)
                {
                     if ((i>0)&& (i%4)==0)
                        printf(" ");
                    if ((i>0)&& (i%32)==0)
                        printf("\n");
                   printf("%02X", msg[i]);
                }
                printf("\n");
            }
#endif			
			UtilSemTakeDbg(hapi->cmdBusSem, INFINITE, __LINE__);
			//LOG_INFO(("ct call IF.send\n"));

			hapi->cmdBus->IF.send(hapi->cmdBus->device,(Uint8 *) msg, sendSize);

			UtilSemGive(hapi->cmdBusSem);
			//LOG_INFO(("give cmd bus sem\n"));

			if(hapi->endianSwap == 1)
            {
                MemFree2Heap(__FILE__,__LINE__,msg);
            }         

            bAnySuccess = TRUE;
		}


		item = NULL;
		toSend = FALSE;

		//===========================
		// check sendQ
		//===========================
		//LOG_INFO(("take sendQSem\n"));
		err = UtilSemTakeDbg(hapi->sendQueueSem, HCW_SEMA_DELAY, __LINE__);

		//LOG_INFO(("ct check sendQ...\n"));

		if(err == DX_SUCCESS && !HAPIIsQueueEmpty(hapi->sendQueue))
		{
			//LOG_INFO(("ct sendQ is not empty\n"));
			HAPIPeekQueue(hapi->sendQueue, &item);
			if(item != NULL)
			{
				pHeader = (HWAPI_MSG_HEADER *)item;
				if(IS_NOWAIT_MESSAGE(pHeader->type))//&&(pHeader->type!=HWAPI_MESSAGE_STREAM_INPUT_DATA)) //jeff modify
				{
					toSend = TRUE;
					HAPIDeQueue(hapi->sendQueue, &item);
				}
			}
		}

		if(err == DX_SUCCESS)
		{
			UtilSemGive(hapi->sendQueueSem);
			//LOG_INFO(("give sendQSem\n"));
		}

		// there is nowait msg to send
		if(toSend && item != NULL)
		{
			Uint32 sendSize = pHeader->payloadSize + headerSize;
			pHeader->cookie = hapi->cookie++;
			
			LOG_INFO(("ct send nowait msg, type=0x%x payld %d <0x%x>\n", pHeader->type, pHeader->payloadSize, pHeader->cookie ));

			if(hapi->endianSwap == 1)
				swapMessage(pHeader, 0);
			
			UtilSemTakeDbg(hapi->cmdBusSem, INFINITE, __LINE__);
			//LOG_INFO(("ct call IF.send\n"));

			hapi->cmdBus->IF.send(hapi->cmdBus->device,(Uint8 *) item, sendSize);

			UtilSemGive(hapi->cmdBusSem);
			//LOG_INFO(("give cmd bus sem\n"));

			MemFree2Heap(__FILE__, __LINE__, item);

            bAnySuccess = TRUE;
		}



		//===========================
		//receive msg from cmd bus
		//===========================
		received = FALSE;
		receiveBuffer = NULL;
		
		err = UtilSemTakeDbg(hapi->cmdBusSem, HCW_SEMA_DELAY, __LINE__);
		//LOG_INFO(("ct cmdBusSem taken\n"));

        bByteLossResync = FALSE;
		if(err == DX_SUCCESS)
		{
			// READ HEADER
			//LOG_INFO(("ct to receive on cmd bus\n"));
			memset(&header, 0xcc, headerSize);
			hwapi_err = hapi->cmdBus->IF.receive(hapi->cmdBus->device, (Uint8*)&header, headerSize);
#if 0
			if(hwapi_err == HWAPI_Success)  // Fake a byte loss for testing.
			{
				static Uint32 msgCounter = 0;
				msgCounter ++;
				if (msgCounter == 31)
				{  // Create a byte loss in header
					HWAPI_MSG_HEADER tempHeader;
					Uint32 shiftLoc = 17;
					tempHeader = header;  // Backup the header for copying later
					memcpy(((Uint8*)&header) + shiftLoc -1, ((Uint8*)&tempHeader) + shiftLoc, sizeof(HWAPI_MSG_HEADER) - shiftLoc);
				}
			}
#endif
			if(hwapi_err == HWAPI_Success && hapi->endianSwap == 1)
				swapHeader(&header);

#if 0//def HAUPPAUGE
			if(hwapi_err == HWAPI_Success)
			{
				//FGR - have seen cases where data starts off missing the data header completely; typically
				// when bad video is present; in that case, lets just dump the payload and see if we resync
				// on the next data transaction
				if((header.msgTag & 0xffbfff00) == 0x47101100){
					DbgLogError(("ct: header.msgTag=0x%x; attempting RESYNC\n"));
					
					Uint32 payloadSize = 0x10020;  // 0x10020 is the typical data payload size
					receiveBuffer = (Uint8 *)MemAllocFromHeap(__FILE__, __LINE__,  payloadSize);

					if(receiveBuffer != NULL)
					{
						rd_payload_time = wrapGetTicks_ms();
						do
						{
							hwapi_err = hapi->cmdBus->IF.receive(hapi->cmdBus->device, receiveBuffer, payloadSize-headerSize);
							if (hwapi_err!=HWAPI_Success)
     								UtilSleep(50);
						}while((hwapi_err!=HWAPI_Success)&&((wrapGetTicks_ms()-rd_payload_time)<3000));
						if(hwapi_err != HWAPI_Success)
						{
							DbgLogError(("ct: HWAPI_Receive RESYNC payload fail!!! err:%d\n", hwapi_err));
						}
						MemFree2Heap(__FILE__, __LINE__, receiveBuffer);
						receiveBuffer = NULL;
					}
					hwapi_err = HWAPI_Fail;
				}
			}
#endif
			if (dwHAPI_MSG_RSV2_test && (hwapi_err == HWAPI_Success) && (header.reserved2 != HAPI_MSG_RSV2))
			{
				//LOG_INFO(("ct received a header on cmd bus: type=0x%x,tag:0x%x,ver:%d,payld:%d,rsp:%x <%d> \n", 
				//		header.type, header.msgTag, header.msgVersion, header.payloadSize, header.responseCode, header.cookie));
				Uint32 temp =0;
				Uint32 shiftLoc = 0xff; // Shift location default value is invalid.
				HWAPI_MSG_HEADER tempHeader;

//				DbgLogError(("ct: Invalid value for reserved2 field in msg header!!!\n"));
//				printHdr(&header);

				// See if there is a byte loss in msg header. If yes, try to resync the lost byte
				// The byte loss might be caused by FX2.
				tempHeader = header;  // Backup the header for copying later
				temp = (header.reserved1 & 0xff)<<24;
				temp |= (header.reserved2 >> 8);
				if (temp == HAPI_MSG_RSV2)  // If not TRUE, unknown error, just let it go as before.
				{ // One byte has been lost in header. See if it can be recovered. If recoverable, restore header and save the last byte in header as the first byte of payload.
					DbgLogError(("ct: Invalid value for reserved2 field in msg header!!!\n"));
					printHdr(&header);
				//	LOG_INFO(("ct INFO: Try to recover the msg header!!!\n"));
					if (header.msgTag == (HAPI_MSG_TAG<<8)) 
					{  // The first word has a byte loss
						shiftLoc = 4;
						header.msgTag = HAPI_MSG_TAG;
					}
					else if (header.msgVersion == (HAPI_MSG_VERSION<<8)) 
					{  // The second word has a byte loss
						shiftLoc = 8;
						header.msgVersion = HAPI_MSG_VERSION;
					}
					else if  (header.type >= HWAPI_MESSAGE_RANGE)
					{
						if (header.type == ((Uint32)HWAPI_MESSAGE_STREAM_OUTPUT_DATA<<8)) 
						{  // The third word has a byte loss
							shiftLoc = 12;
							header.type = HWAPI_MESSAGE_STREAM_OUTPUT_DATA;
						}
						else if (header.type == ((Uint32)HWAPI_MESSAGE_STREAM_DATA_REQ<<8)) 
						{  // The third word has a byte loss
							shiftLoc = 12;
							header.type = HWAPI_MESSAGE_STREAM_DATA_REQ;
						}
					}
					// If the 4th word 'cookie' is incorrect, just let it be. It has no harm to the message.
					// Check the following words below.
					else if ((header.type == HWAPI_MESSAGE_STREAM_OUTPUT_DATA) && (header.payloadSize == (0x10020<<8))) 
					{  // The 5th word has a byte loss
						shiftLoc = 20;
						header.payloadSize = 0x10020;  // 0x10020 is the typical data payload size
					}
					else if ((header.type == HWAPI_MESSAGE_STREAM_DATA_REQ) && 
						(header.payloadSize == (((sizeof(HWAPI_MSG_STREAM_DATA_REQUEST)- sizeof(HWAPI_MSG_HEADER))<<8) + ((Uint32)HAPI_RESPONSE_CODE_DEFAULT>>24)))) 
					{  // The 5th word has a byte loss
						shiftLoc = 20;
						header.payloadSize = sizeof(HWAPI_MSG_STREAM_DATA_REQUEST)- sizeof(HWAPI_MSG_HEADER);
					}

					if (shiftLoc != 0xff)  // Resync the message
					{
						LOG_INFO(("ct INFO: Recovered the msg header!shiftLoc=%d \n", shiftLoc));
						bByteLossResync = TRUE;
						if (hapi->endianSwap == 1)  // Swap header to big endian before copying bytes.
						{
							swapHeader(&header);
							swapHeader(&tempHeader);
						}
						memcpy(((Uint8*)&header) + shiftLoc, ((Uint8*)&tempHeader) + shiftLoc -1, sizeof(HWAPI_MSG_HEADER) - shiftLoc);
						payloadByte = *(((Uint8*)&tempHeader) +  sizeof(HWAPI_MSG_HEADER) -1);
						if (hapi->endianSwap == 1)  // Swap to little endia
						{
							swapHeader(&header);
						}
						LOG_INFO(("Resync hdr:\n"));
						printHdr(&header);
					}
				}
			}

			//check header correctness
			if(hwapi_err == HWAPI_Success 
				&& header.msgTag != HAPI_MSG_TAG)
			{
#ifndef DRIVER_BUILD//HAUPPAUGE
				DbgLogError(("ct: msg tag error!!! got 0x%x, expected 0x%x\n", header.msgTag, HAPI_MSG_TAG));
#else
				DbgLogError(("ct BAD header: tag:%x ver:%x type=%x <%x> payld:%u rsp:%x resv1=%x resv2=%x\n", 
					header.msgTag, header.msgVersion, header.type, header.cookie, header.payloadSize, header.responseCode, header.reserved1, header.reserved2));
				
				usb_config_st *pUsbConfig = (usb_config_st*)hapi->cmdBus->device;
				USBBootMChip_t *p_mchip = pUsbConfig->p_mchip;
	            bAnySuccess = TRUE; //want minimal delay to get next packet
				receiveBuffer = NULL;

				p_mchip->lock();
				p_mchip->resetWFMode();
				//p_mchip->setUsbError("cmdThreadFunc", __LINE__);//FGR - try to make HAPI fail out faster; we will need to reload Magnum
				p_mchip->unlock();
#endif

			}
			// read payload
			else if(hwapi_err == HWAPI_Success 
				&& header.msgTag == HAPI_MSG_TAG)
			{
				int payloadSize = header.payloadSize;

				if(header.cookie > hapi->cookie)
					hapi->cookie = header.cookie + 1;

				bool ok = checkPayloadSize(&header);
				
				receiveBuffer = NULL;
				if(ok){
					receiveBuffer = (Uint8 *)MemAllocFromHeap(__FILE__, __LINE__,  payloadSize + headerSize);
				} else {
					DbgLogError(("ct received a BAD header on cmd bus: ver:0x%x type=0x%x <0x%x> payld:%u rsp:%x resv1=%x resv2=%x\n", 
						header.msgVersion, header.type, header.cookie, header.payloadSize, header.responseCode, header.reserved1, header.reserved2));
				}
				//LOG_INFO(("ct malloc receiveBuf ok:0x%x\n",receiveBuffer));

				if(receiveBuffer != NULL)
				{
					Uint8 *payloadAddr;
					memcpy(receiveBuffer, &header, headerSize);
					payloadAddr = receiveBuffer + headerSize;
					if (bByteLossResync)  // If Byte loss had happened before, put the last byte in head as the first byte in payload.
					{
						*payloadAddr = payloadByte;
						payloadAddr ++;
						payloadSize--;
						LOG_INFO(("Restored payload byte read to msg header.\n"));
					}
#ifndef DRIVER_BUILD
					rd_payload_cnt = 0; 
					do
					{
						rd_payload_cnt++;
						hwapi_err = hapi->cmdBus->IF.receive(hapi->cmdBus->device, payloadAddr, payloadSize);
						if (hwapi_err!=HWAPI_Success)
     						    UtilSleep(5);
					}while((hwapi_err!=HWAPI_Success)&&(rd_payload_cnt<1000));//while((hwapi_err!=HWAPI_Success)&&(UtilGetTime()-rd_payload_time<3000));
#else
					rd_payload_time = wrapGetTicks_ms();
					do
					{
						hwapi_err = hapi->cmdBus->IF.receive(hapi->cmdBus->device, payloadAddr, payloadSize);
						if (hwapi_err!=HWAPI_Success)
     						    UtilSleep(50);
					}while((hwapi_err!=HWAPI_Success)&&((wrapGetTicks_ms()-rd_payload_time)<3000)&&(!hapi->exitCmdThread));
#endif
					if(hwapi_err == HWAPI_Success)
					{
						received = TRUE;
					}
					else
					{
						DbgLogError(("ct: HWAPI_Receive payload fail!!! err:%d, type=0x%x, <%d> payld %u\n", hwapi_err, header.type, header.cookie, payloadSize));
#if 0//def DRIVER_BUILD
						usb_config_st *pUsbConfig = (usb_config_st*)hapi->cmdBus->device;
						USBBootMChip_t *p_mchip = pUsbConfig->p_mchip;

						p_mchip->resetWFMode();
						p_mchip->setUsbError("cmdThreadFunc", __LINE__);//FGR - try to make HAPI fail out faster; we will need to reload Magnum
#endif
						MemFree2Heap(__FILE__, __LINE__, receiveBuffer);
						receiveBuffer = NULL;
					}
				}
				else
				{
					if(ok){
						DbgLogError(("ct: malloc receiveBuffer(%u) fail!!!\n", payloadSize + headerSize));
					}
				}
			}
			else
			{
				//DbgLogError(("ct cmdBus HWAPI_Receive header fail: err:%d\n", hwapi_err));
			}
		}

		if(err == DX_SUCCESS)
		{
			UtilSemGive(hapi->cmdBusSem);
			//LOG_INFO(("ct cmdBusSem given\n"));
		}

		//whole msg received
		if(received == TRUE && receiveBuffer != NULL)
		{
			pHeader = (HWAPI_MSG_HEADER*)receiveBuffer;
		
			LOG_INFO(("ct <<<received msg: type=0x%x payld %d <%d>\n", 
			pHeader->type, pHeader->payloadSize, pHeader->cookie));
#if 0
            if (pHeader->type == HWAPI_MESSAGE_STATUS_QUERY)
            {
                Uint16 i;
                for (i=0; i<sizeof(HWAPI_MSG_QUERY_STATUS_RSP); i++)
                {
                    if ((i>0)&& (i%4)==0)
                        KdPrint((" "));
                    if ((i>0)&& (i%32)==0)
                        KdPrint(("\n"));
                    KdPrint(("%02X", receiveBuffer[i]));
                }
                KdPrint(("\n"));
            }
#endif
			if(hapi->endianSwap == 1)
			{
				swapHeader(pHeader); // swap back header to slave side endian
				swapMessage(pHeader, 1); // swap whole message to local endian
			}

			//LOG_DBG(("received crc:%d \n", 
			//		*(Uint32 *)(receiveBuffer + headerSize + pHeader->payloadSize - 4)));

			//check CRC
			#if 0
			if(*(Uint32 *)(receiveBuffer + headerSize + pHeader->payloadSize - 4) !=
							CRC32(receiveBuffer, headerSize + pHeader->payloadSize - 4))
			{
				DbgLogError(("crc error, ignore msg, type=0x%x, payload:%d\n", pHeader->type, pHeader->payloadSize));
				MemFree2Heap(__FILE__, __LINE__, receiveBuffer);
			}
			else
				#endif
			{
				UtilSemTakeDbg(hapi->receiveQueueSem, INFINITE, __LINE__);
				if (HAPIEnQueue(hapi->receiveQueue, (QueueItem)receiveBuffer) == 1)
                {
                    MemFree2Heap(__FILE__, __LINE__, receiveBuffer); 
                }            
				UtilSemGive(hapi->receiveQueueSem);
			}
            bAnySuccess = TRUE;
		}
        receiveBuffer = NULL;

		if (bAnySuccess)
		  UtilSleep(1);
		else
#ifndef DRIVER_BUILD
		  UtilSleep(5);
#else
		  UtilSleep(HCW_POLL_DELAY);
#endif
	}// end while(1)

	//if(receiveBuffer != NULL)
	//	free(receiveBuffer);

#ifndef DRIVER_BUILD
	LOG_INFO(("cmdThread exiting\n"));
#else
	DbgLogInfo(("cmdThread() exiting\n"));
	hapi->exitCmdThread = 0; //FGR tell those waiting, we are done
	wrapThreadExit(STATUS_SUCCESS);
#endif
	return;
}

#ifndef AV_ASI
static void DLLCALL dataThreadFunc(void * data)
{
	HAPIHandler hapi = (HAPIHandler)data;
	QueueItem item;
	Boolean toSend ;
	Boolean received ;
	int headerSize = sizeof(HWAPI_MSG_HEADER);
	HWAPI_MSG_HEADER header, *pHeader;
	HWAPIErrCode hwapi_err;
	Uint8 * receiveBuffer;	
	dxErrCode err;
    Boolean bAnySuccess;  // To indicate if any successful send/receive in a loop.
    Boolean bByteLossResync;
	Uint8   payloadByte; // The byte that have been read into msg header when byte loss occured in message header. 

#ifndef DRIVER_BUILD//HAUPPAUGE
	unsigned int rd_payload_cnt=0;
#else
	DWORD rd_payload_time;

//	DbgLogInfo(("dataThreadFunc(%p) startup Thread=%p\n", data, KeGetCurrentThread()));
#endif
	
	while(!hapi->exitDataThread)
	{
		item = NULL;
		toSend = FALSE;
        bAnySuccess = FALSE;

		//===========================
		// check sendQ
		//===========================
		err = UtilSemTakeDbg(hapi->sendQueueSem, HCW_SEMA_DELAY, __LINE__);

		//LOG_INFO(("dt check send q \n"));

		if(err == DX_SUCCESS && !HAPIIsQueueEmpty(hapi->sendQueue))
		{
			//LOG_INFO(("dt send q is not empty\n"));
			HAPIPeekQueue(hapi->sendQueue, &item);
			if(item != NULL)
			{
				pHeader = (HWAPI_MSG_HEADER*)item;
				if(pHeader->type == HWAPI_MESSAGE_STREAM_INPUT_DATA)
				{
					toSend = TRUE;
					//LOG_INFO(("dt found input data to send\n"));
					HAPIDeQueue(hapi->sendQueue, &item);
				}
			}
		}

		if(err == DX_SUCCESS)
			UtilSemGive(hapi->sendQueueSem);

		// there are msg to send
		if(toSend && item != NULL)
		{
			Uint32 sendSize = pHeader->payloadSize + headerSize;
			pHeader->cookie = hapi->cookie++;

			LOG_INFO(("dt send msg, type=0x%x, payld:%d <0x%x>\n", pHeader->type,pHeader->payloadSize, pHeader->cookie));

			if(hapi->endianSwap == 1)
				swapMessage(pHeader, 0);
		
			UtilSemTakeDbg(hapi->dataBusSem, INFINITE, __LINE__);
			hapi->dataBus->IF.send(hapi->dataBus->device,(Uint8 *) item, sendSize);
			UtilSemGive(hapi->dataBusSem);

			// swap back to local endian
			//if(hapi->endianSwap == 1)
			//	swapMessage(pHeader, 1);

			//UtilSemTakeDbg(hapi->waitResponseQueueSem, INFINITE, __LINE__);
			//HAPIEnQueue(hapi->waitResponseQueue, item);
			//UtilSemGive(hapi->waitResponseQueueSem);

			MemFree2Heap(__FILE__, __LINE__, item);

            bAnySuccess = TRUE;
		}

		//retrieve message from data bus
		received = FALSE;
		receiveBuffer = NULL;
		
		//===========================
		//receive msg from data bus
		//===========================
		received = FALSE;
		//receiveBuffer = NULL;
		
		err = UtilSemTakeDbg(hapi->dataBusSem, HCW_SEMA_DELAY, __LINE__);
		//LOG_INFO(("dt dataBusSem taken\n"));

        bByteLossResync = FALSE;
		if(err == DX_SUCCESS)
		{
			// read header
			//LOG_INFO(("dt to receive on data bus\n"));

			memset(&header, 0xdd, headerSize);
			hwapi_err = hapi->dataBus->IF.receive(hapi->dataBus->device, (Uint8*)&header, headerSize);
#if 0
			if(hwapi_err == HWAPI_Success)  // Fake a byte loss for testing.
			{
				static Uint32 msgCounter = 0;
				msgCounter ++;
				if (msgCounter == 31)
				{  // Create a byte loss in header
					HWAPI_MSG_HEADER tempHeader;
					Uint32 shiftLoc = 17;
					tempHeader = header;  // Backup the header for copying later
					memcpy(((Uint8*)&header) + shiftLoc -1, ((Uint8*)&tempHeader) + shiftLoc, sizeof(HWAPI_MSG_HEADER) - shiftLoc);
				}
			}
#endif
			if(hwapi_err == HWAPI_Success && hapi->endianSwap == 1)
				swapHeader(&header);

			if ((hwapi_err == HWAPI_Success) && (header.reserved2 != HAPI_MSG_RSV2))
			{
				Uint32 temp =0;
				Uint32 shiftLoc = 0xff; // Shift location default value is invalid.
				HWAPI_MSG_HEADER tempHeader;
				//LOG_INFO(("dt received a header on data bus: type=0x%x,tag:0x%x,ver:%d,payld:%d,rsp:%x <%d> \n", 
				//		header.type, header.msgTag, header.msgVersion, header.payloadSize, header.responseCode, header.cookie));

				DbgLogError(("dt: Invalid value for reserved2 field in msg header!!!\n"));
				printHdr(&header);

				// See if there is a byte loss in msg header. If yes, try to resync the lost byte
				// The byte loss might be caused by FX2.
				tempHeader = header;  // Backup the header for copying later
				temp = (header.reserved1 & 0xff)<<24;
				temp |= (header.reserved2 >> 8);
				if (temp == HAPI_MSG_RSV2)  // If not TRUE, unknown error, just let it go as before.
				{ // One byte has been lost in header. See if it can be recovered. If recoverable, restore header and save the last byte in header as the first byte of payload.
					LOG_INFO(("dt INFO: Try to recover the msg header!!!\n"));
					if (header.msgTag == (HAPI_MSG_TAG<<8)) 
					{  // The first word has a byte loss
						shiftLoc = 4;
						header.msgTag = HAPI_MSG_TAG;
					}
					else if (header.msgVersion == (HAPI_MSG_VERSION<<8)) 
					{  // The second word has a byte loss
						shiftLoc = 8;
						header.msgVersion = HAPI_MSG_VERSION;
					}
					else if  (header.type >= HWAPI_MESSAGE_RANGE)
					{
						if (header.type == ((Uint32)HWAPI_MESSAGE_STREAM_OUTPUT_DATA<<8)) 
						{  // The third word has a byte loss
							shiftLoc = 12;
							header.type = HWAPI_MESSAGE_STREAM_OUTPUT_DATA;
						}
						else if (header.type == ((Uint32)HWAPI_MESSAGE_STREAM_DATA_REQ<<8)) 
						{  // The third word has a byte loss
							shiftLoc = 12;
							header.type = HWAPI_MESSAGE_STREAM_DATA_REQ;
						}
					}
					// If the 4th word 'cookie' is incorrect, just let it be. It has no harm to the message.
					// Check the following words below.
					else if ((header.type == HWAPI_MESSAGE_STREAM_OUTPUT_DATA) && (header.payloadSize == (0x10020<<8))) 
					{  // The 5th word has a byte loss
						shiftLoc = 20;
						header.payloadSize = 0x10020;  // 0x10020 is the typical data payload size
					}
					else if ((header.type == HWAPI_MESSAGE_STREAM_DATA_REQ) && 
						(header.payloadSize == (((sizeof(HWAPI_MSG_STREAM_DATA_REQUEST)- sizeof(HWAPI_MSG_HEADER))<<8) + ((Uint32)HAPI_RESPONSE_CODE_DEFAULT>>24)))) 
					{  // The 5th word has a byte loss
						shiftLoc = 20;
						header.payloadSize = sizeof(HWAPI_MSG_STREAM_DATA_REQUEST)- sizeof(HWAPI_MSG_HEADER);
					}

					if (shiftLoc != 0xff)  // Resync the message
					{
						LOG_INFO(("dt INFO: Recovered the msg header!shiftLoc=%d \n", shiftLoc));
						bByteLossResync = TRUE;
						if (hapi->endianSwap == 1)  // Swap header to big endian before copying bytes.
						{
							swapHeader(&header);
							swapHeader(&tempHeader);
						}
						memcpy(((Uint8*)&header) + shiftLoc, ((Uint8*)&tempHeader) + shiftLoc -1, sizeof(HWAPI_MSG_HEADER) - shiftLoc);
						payloadByte = *(((Uint8*)&tempHeader) +  sizeof(HWAPI_MSG_HEADER) -1);
						if (hapi->endianSwap == 1)  // Swap to little endia
						{
							swapHeader(&header);
						}
//						LOG_INFO(("Resynec hdr:\n"));
//						printHdr(&header);
					}
				}	
			}

			//check header correctness
			if(hwapi_err == HWAPI_Success 
				&& header.msgTag != HAPI_MSG_TAG)
			{
				DbgLogError(("dt: msg tag error!!! 0x%x\n", header.msgTag));
				DbgLogError(("dt received a BAD header: ver:0x%x type=0x%x <0x%x> payld:%u rsp:%x resv1=%x resv2=%x\n", 
					header.msgVersion, header.type, header.cookie, header.payloadSize, header.responseCode, header.reserved1, header.reserved2));
			}
			// read payload
			else if(hwapi_err == HWAPI_Success 
				&& header.msgTag == HAPI_MSG_TAG)
			{
				int payloadSize = header.payloadSize;

				if(header.cookie > hapi->cookie)
					hapi->cookie = header.cookie + 1;

				bool ok = checkPayloadSize(&header);
				
				receiveBuffer = NULL;
				if(ok){
					receiveBuffer = (Uint8 *)MemAllocFromHeap(__FILE__, __LINE__,  payloadSize + headerSize);
				} else {
					DbgLogError(("dt received a BAD header: ver:0x%x type=0x%x <0x%x> payld:%u rsp:%x resv1=%x resv2=%x\n", 
						header.msgVersion, header.type, header.cookie, header.payloadSize, header.responseCode, header.reserved1, header.reserved2));
				}
				
				//LOG_INFO(("dt malloc receiveBuf ok:0x%x\n",receiveBuffer));

				if(receiveBuffer != NULL)
				{
					Uint8 *payloadAddr;
					memcpy(receiveBuffer, &header, headerSize);
					payloadAddr = receiveBuffer + headerSize;
					if (bByteLossResync)  // If Byte loss had happened before, put the last byte in head as the first byte in payload.
					{
						*payloadAddr = payloadByte;
						payloadAddr ++;
						payloadSize--;
						LOG_INFO(("Restored payload byte read to msg header.\n"));
					}
#ifndef DRIVER_BUILD
					rd_payload_cnt = 0;
					do
					{
						rd_payload_cnt++;
						hwapi_err = hapi->dataBus->IF.receive(hapi->dataBus->device, payloadAddr, payloadSize);
						if (hwapi_err !=HWAPI_Success)
						    UtilSleep(5);
					}while((hwapi_err!=HWAPI_Success)&&(rd_payload_cnt<300));//while((hwapi_err!=HWAPI_Success)&&(UtilGetTime()-rd_payload_time<3000));
#else
					rd_payload_time = wrapGetTicks_ms();
					do
					{
						hwapi_err = hapi->cmdBus->IF.receive(hapi->cmdBus->device, payloadAddr, payloadSize);
						if (hwapi_err!=HWAPI_Success)
     						    UtilSleep(50);
					}while((hwapi_err!=HWAPI_Success)&&((wrapGetTicks_ms()-rd_payload_time)<3000));
#endif
					if(hwapi_err == HWAPI_Success)
					{
						received = TRUE;
					}
					else
					{
						DbgLogError(("dt: HWAPI_Receive payload fail!!! err:%d, type=0x%x, <%d>\n", hwapi_err, header.type, header.cookie));
						MemFree2Heap(__FILE__, __LINE__, receiveBuffer);
					}
				}
				else
				{
					if(ok){
						DbgLogError(("dt: malloc receiveBuffer(%u) fail!!!\n", payloadSize + headerSize));
					}
				}
			}
			else
			{
				//DbgLogError(("ct: cmdBus HWAPI_Receive header none: %d\n", hwapi_err));				
			}
		}

		if(err == DX_SUCCESS)
		{
			UtilSemGive(hapi->dataBusSem);
			//LOG_INFO(("dt dataBusSem given\n"));
		}

		//whole msg received
		if(received == TRUE && receiveBuffer != NULL)
		{
			pHeader = (HWAPI_MSG_HEADER*)receiveBuffer;
		
			LOG_INFO(("dt <<<received msg: type=0x%x payld %d <%d>\n", 
					pHeader->type, pHeader->payloadSize, pHeader->cookie));

			if(hapi->endianSwap == 1)
			{
				swapHeader(pHeader); // swap back header to slave side endian
				swapMessage(pHeader, 1); // swap whole message to local endian
			}

			//LOG_DBG(("dt received crc:%d \n", 
			//		*(Uint32 *)(receiveBuffer + headerSize + pHeader->payloadSize - 4)));

			//check CRC
		#if 0
			if(*(Uint32 *)(receiveBuffer + headerSize + pHeader->payloadSize - 4) !=
							CRC32(receiveBuffer, headerSize + pHeader->payloadSize - 4))
			{
				DbgLogError(("dt: crc error, ignore msg, type=0x%x, payload:%d\n", pHeader->type, pHeader->payloadSize));
				MemFree2Heap(__FILE__, __LINE__, receiveBuffer);
			}
			else
		#endif
			{
				UtilSemTakeDbg(hapi->receiveQueueSem, INFINITE, __LINE__);
				if (HAPIEnQueue(hapi->receiveQueue, (QueueItem)receiveBuffer)==1)
                {
                    MemFree2Heap(__FILE__, __LINE__, receiveBuffer); 
                    receiveBuffer = NULL;
                }
                receiveBuffer = NULL;
				UtilSemGive(hapi->receiveQueueSem);
			}

            bAnySuccess = TRUE;
		}

		if (bAnySuccess)
		  UtilSleep(1);
		else
#ifndef DRIVER_BUILD
		  UtilSleep(5);
#else
		  UtilSleep(HCW_POLL_DELAY);
#endif
		
	}// end while(1)

#ifndef DRIVER_BUILD//HAUPPAUGE
	LOG_INFO(("dataThread exiting\n"));
#else
	DbgLogInfo(("dataThread exiting\n"));
#endif

#ifdef DRIVER_BUILD
	hapi->exitDataThread = 0; //FGR tell those waiting, we are done
	wrapThreadExit(STATUS_SUCCESS);
#endif
	return;

}

#endif


static void DLLCALL mainThreadFunc(void * data)
{
	HAPIHandler hapi = (HAPIHandler)data;

	QueueItem item;
	Boolean msgReceived ;
	//int headerSize = sizeof(HWAPI_MSG_HEADER);
	HWAPI_MSG_HEADER *pHeader;
	dxErrCode err;

#ifndef DRIVER_BUILD//HAUPPAUGE
#else
//	DbgLogInfo(("mainThreadFunc(%p) startup Thread=%p\n", data, KeGetCurrentThread()));
#endif

	while(!hapi->exitMainThread)
	{
		item = NULL;
		msgReceived = FALSE;

		//==================
		// check receive queue
		//==================

		err = UtilSemTakeDbg(hapi->receiveQueueSem, HCW_SEMA_DELAY, __LINE__);
		if(err != DX_SUCCESS)
		{
#ifndef DRIVER_BUILD
    		UtilSleep(5);
#else
			UtilSleep(HCW_POLL_DELAY);
#endif
			continue;
		}

		HAPIPeekQueue(hapi->receiveQueue, &item);
		if(item == NULL)
		{
			UtilSemGive(hapi->receiveQueueSem);
#ifndef DRIVER_BUILD
    		UtilSleep(5);
#else
			UtilSleep(HCW_POLL_DELAY);
#endif
			continue;
		}

		pHeader = (HWAPI_MSG_HEADER *)item;

#ifdef USE_WRITE_THREAD
		if(pHeader->type == HWAPI_MESSAGE_STREAM_OUTPUT_DATA)
		{
			UtilSemGive(hapi->receiveQueueSem);
#ifndef DRIVER_BUILD
    		UtilSleep(5);
#else
			UtilSleep(HCW_POLL_DELAY);
#endif
			continue;
		}
#endif

		HAPIDeQueue(hapi->receiveQueue, &item);

		UtilSemGive(hapi->receiveQueueSem);

		// should not call continue/break/return after here because we need to free the "item" at end of while loop

		//LOG_INFO(("mt received msg type=0x%x\n", pHeader->type));

		//===========================
		// user cmd response received
		//===========================
		if(IS_USER_CMD(pHeader->type))
		{
			LOG_INFO(("mt got user cmd rsp, type=0x%x <%d>\n",
				pHeader->type, pHeader->cookie));

			UtilSemTakeDbg(hapi->sendAndWaitQueueSem, INFINITE, __LINE__);
			//LOG_INFO(("mt sendAndWaitQSem taken\n"));

			if(hapi->pMsgWaitingRsp != NULL
				&& pHeader->type == hapi->pMsgWaitingRsp->type
				&& pHeader->cookie == hapi->pMsgWaitingRsp->cookie)
			{
				QueueItem itemToRemove = NULL;
				LOG_INFO(("mt got a correct rsp of type=0x%x <%d>\n", hapi->pMsgWaitingRsp->type, hapi->pMsgWaitingRsp->cookie));
				hapi->userCmdResponseCode = pHeader->responseCode;
				if(pHeader->type == HWAPI_MESSAGE_GET_PARAM_REQ)    //store the parameter from slave
				{
					HWAPI_MSG_GET_PARAM_RSP *pMsg = (HWAPI_MSG_GET_PARAM_RSP *)item;
					if(pHeader->responseCode == HWAPI_MSG_RSP_PASS)
						memcpy(&hapi->GetParam, &pMsg->param, sizeof(HAPI_GET_PARAM));
				}
                else if(pHeader->type == HWAPI_MESSAGE_I2C_READ)
				{
					HWAPI_MSG_I2C_READ_RSP *pMsg = (HWAPI_MSG_I2C_READ_RSP *)item;
					if(pHeader->responseCode == HWAPI_MSG_RSP_PASS)
						memcpy(&hapi->I2CReadParam, &pMsg->param, sizeof(HAPI_I2C_READ_PARAM));
				}
                else if(pHeader->type == HWAPI_MESSAGE_I2C_SET_CLOCK_FREQ)
				{
					HWAPI_MSG_I2C_CLOCK_FREQ_RSP *pMsg = (HWAPI_MSG_I2C_CLOCK_FREQ_RSP *)item;
					if(pHeader->responseCode == HWAPI_MSG_RSP_PASS)
					    hapi->I2CClockFreq=pMsg->f_khz;
				}
                else if(pHeader->type == HWAPI_MESSAGE_STATUS_QUERY)
				{
					HWAPI_MSG_QUERY_STATUS_RSP *pMsg = (HWAPI_MSG_QUERY_STATUS_RSP *)item;
					if(pHeader->responseCode == HWAPI_MSG_RSP_PASS)
					    hapi->queryStatus = pMsg->status;
				}
                else if (pHeader->type == HWAPI_MESSAGE_GPIO_READ)
                {
                    HWAPI_MSG_GPIO_READ_RSP *pMsg = (HWAPI_MSG_GPIO_READ_RSP *)item;
                    if(pHeader->responseCode == HWAPI_MSG_RSP_PASS)
                        hapi->GpioReturnVal = pMsg->Val;
                }
#ifdef HAUPPAUGE
                else if (pHeader->type == HWAPI_MESSAGE_INIT)
                {
                    HWAPI_MSG_INIT_RSP *pMsg = (HWAPI_MSG_INIT_RSP *)item;
                    if(pHeader->responseCode == HWAPI_MSG_RSP_PASS){
						LOG_INFO(("HWAPI_MSG_INIT_RSP  ProductID=0x%x MajorVer=0x%x MinorVer=0x%x BuildVersion=0x%x\n",
							pMsg->ProductID, pMsg->MajorVer, pMsg->MinorVer, pMsg->BuildVersion));
// Is this safe???
						LOG_INFO(("  BuildDate=%16.16s BuildTime=%16.16s Desc='%64.64s'\n",
							pMsg->BuildDate, pMsg->BuildTime, pMsg->Description));
	
					}
                }
#endif
				HAPIDeQueue(hapi->sendAndWaitQueue, &itemToRemove);

                if (itemToRemove != NULL)
    				MemFree2Heap(__FILE__, __LINE__, itemToRemove);
                itemToRemove = NULL;
				hapi->pMsgWaitingRsp = NULL;

				//LOG_DBG(("mt sendAndWaitQSem given\n"));

				UtilSemGive(hapi->userCmdSem);
				
			}
			else
			{
				DbgLogError(("mt: No one waiting this rsp, ignore!!!\n"));
			}

			UtilSemGive(hapi->sendAndWaitQueueSem);
		}
		
		//responese of input data message
		

		//===========================
		// data request received
		//===========================
#ifndef DRIVER_BUILD
		if((pHeader->type == HWAPI_MESSAGE_STREAM_DATA_REQ) && (hapi->state == HAPI_STATE_START))
#else
		if(pHeader->type == HWAPI_MESSAGE_STREAM_DATA_REQ)
#endif
		{
			HWAPI_MSG_STREAM_DATA_REQUEST * pMsg;
			//HWAPI_MSG_STREAM_DATA_REQUEST_RSP *pRsp;
			HWAPI_MSG_STREAM_INPUT_DATA* pInput;
			HAPI_AV_DATA_INFO info;

#ifdef DRIVER_BUILD
			if(hapi->state != HAPI_STATE_START){
				DbgLogWarn(("mt: STREAM_DATA_REQ with state==%d!!\n", hapi->state));
			}
#endif
			pMsg = (HWAPI_MSG_STREAM_DATA_REQUEST*)item;

			//LOG_INFO(("mt got data request: %d <%d>\n", pMsg->dataLength, pMsg->header.cookie));
		
			

			//check data length
			if(pMsg->dataLength > MAX_STREAM_AV_DATA_SIZE)
			{
				DbgLogError(("mt: request length(%d) > max stream size(%d)!!!\n", pMsg->dataLength, MAX_STREAM_AV_DATA_SIZE));
				pMsg->dataLength = MAX_STREAM_AV_DATA_SIZE;
			}

			// get stream data
			//pInput = (HWAPI_MSG_STREAM_INPUT_DATA*)MemAllocFromHeap(__FILE__, __LINE__,  sizeof(HWAPI_MSG_STREAM_INPUT_DATA));
			pInput = (HWAPI_MSG_STREAM_INPUT_DATA*)MemAllocFromHeap(__FILE__, __LINE__,  (sizeof(HWAPI_MSG_STREAM_INPUT_DATA_INF) + pMsg->dataLength));
			info.requestSize = pMsg->dataLength;
			info.channel = 0;//???

			if(pInput == NULL)
			{
				DbgLogError(("mt: allocate INPUT_DATA fail!!!\n"));
			}
			else if(hapi->dataSend == NULL)
			{
				DbgLogError(("mt: callback dataSend not installed!!!\n"));
				MemFree2Heap(__FILE__, __LINE__, pInput);
			}
			else if((info.buf = (Uint8*)&pInput->data) && hapi->dataSend(&info, hapi->context) != HAPI_SUCCESS)
			{
				DbgLogError(("mt callback dataSend no data.\n"));
				MemFree2Heap(__FILE__, __LINE__, pInput);
			}
			else //input data ready
			{
				//LOG_INFO(("mt input data ready, add to sendQ\n"));
				pInput->header.msgTag = HAPI_MSG_TAG;
				pInput->header.msgVersion = HAPI_MSG_VERSION;
				pInput->header.type = HWAPI_MESSAGE_STREAM_INPUT_DATA;
				//pInput->header.payloadSize = sizeof(HWAPI_MSG_STREAM_INPUT_DATA) - headerSize;
				pInput->header.payloadSize = sizeof(HWAPI_MSG_STREAM_INPUT_DATA_INF) - sizeof(HWAPI_MSG_HEADER) + info.requestSize;
				//pInput->checkCode = CRC32((unsigned char *)pInput, headerSize + pInput->header.payloadSize -4);
				pInput->dataLength = info.requestSize;

				UtilSemTakeDbg(hapi->sendQueueSem, INFINITE, __LINE__);
				if (HAPIEnQueue(hapi->sendQueue, (QueueItem)pInput)==1)
                {
                    MemFree2Heap(__FILE__, __LINE__, pInput); 
                    pInput = NULL;
                }
				UtilSemGive(hapi->sendQueueSem);
			}
			
		}

		//===========================
		// output data received
		//===========================
#ifndef USE_WRITE_THREAD

		if(pHeader->type == HWAPI_MESSAGE_STREAM_OUTPUT_DATA)
		{
			HWAPI_MSG_STREAM_OUTPUT_DATA * pOutput = (HWAPI_MSG_STREAM_OUTPUT_DATA*)item;
			HAPI_AV_DATA_INFO info;
			// HWAPI_MSG_STREAM_OUTPUT_DATA_RSP* pRsp;

			//LOG_INFO(("mt got output data %u(%u) <%d> mask=%x\n",
			//	pOutput->dataLength, pOutput->header.payloadSize, pOutput->header.cookie, pOutput->bitMask));

#ifdef HAUPPAUGE//potential "fix" for BSOD with bad dataLength
			if(pOutput->dataLength > pOutput->header.payloadSize)
			{
				DbgLogError(("mt: output data length(%u) > payld data size(%d)!!!\n", pOutput->dataLength, pOutput->header.payloadSize));
				pOutput->dataLength = pOutput->header.payloadSize;
			}
#endif
			if(pOutput->dataLength > MAX_STREAM_AV_DATA_SIZE)
			{
				DbgLogError(("mt: output data length(%d) > max data size(%d) payld(%d)!!!\n", pOutput->dataLength, MAX_STREAM_AV_DATA_SIZE, pOutput->header.payloadSize));
				pOutput->dataLength = MAX_STREAM_AV_DATA_SIZE;
			}

			// transfer output data to user
			info.channel = 0;//???
			info.requestSize = pOutput->dataLength;
			info.buf = (Uint8*)(&pOutput->data);

			if(hapi->dataReceive(&info, hapi->context) != HAPI_SUCCESS)
			{
				DbgLogError(("mt: callback dataReceive fail!!!\n"));
			}
		}
#endif
        if((pHeader->type == HWAPI_MESSAGE_I2C_OUTPUT_MONITOR_DATA) || (pHeader->type == HWAPI_MESSAGE_ERROR))
        {
			UtilSemTakeDbg(hapi->cbQueueSem, INFINITE, __LINE__);
			if (HAPIEnQueue(hapi->callbackQueue, (QueueItem)item)==1)
            {
                MemFree2Heap(__FILE__, __LINE__, item); 
                item = NULL;
            }
			UtilSemGive(hapi->cbQueueSem);
        }
        else // Do not free buffer for messages that are forward to other queues.
        {
			//LOG_INFO(("mt to free item 0x%x\n",item));
		   	MemFree2Heap(__FILE__, __LINE__, (Uint8*)item);
            item = NULL;
        }
	}

#ifndef DRIVER_BUILD//HAUPPAUGE
	LOG_INFO(("mainThread exiting\n"));
#else
	DbgLogInfo(("mainThread() exiting\n"));
#endif

#ifdef DRIVER_BUILD
	hapi->exitMainThread = 0; //FGR tell those waiting, we are done
	wrapThreadExit(STATUS_SUCCESS);
#endif

	return;
}

#ifndef AV_ASI

#ifdef USE_WRITE_THREAD
static void DLLCALL writeThreadFunc(void * data)
{
	HAPIHandler hapi = (HAPIHandler)data;

	QueueItem item;
	Boolean msgReceived ;
	//int headerSize = sizeof(HWAPI_MSG_HEADER);
	HWAPI_MSG_HEADER *pHeader;
	dxErrCode err;

#ifndef DRIVER_BUILD//HAUPPAUGE
#else
	DbgLogInfo(("writeThreadFunc(%p) starting Thread=%p\n", data, KeGetCurrentThread()));
#endif

	while(!hapi->exitWriteThread)
	{

		item = NULL;
		msgReceived = FALSE;

		//==================
		// check receive queue
		//==================

		err = UtilSemTakeDbg(hapi->receiveQueueSem, HCW_SEMA_DELAY, __LINE__);
		if(err != DX_SUCCESS)
		{
#ifndef DRIVER_BUILD
			UtilSleep(5);
#else
			UtilSleep(HCW_POLL_DELAY);
#endif
			continue;
		}

		HAPIPeekQueue(hapi->receiveQueue, &item);
		if(item == NULL)
		{
			UtilSemGive(hapi->receiveQueueSem);
#ifndef DRIVER_BUILD
			UtilSleep(5);
#else
			UtilSleep(HCW_POLL_DELAY);
#endif
			continue;
		}

		pHeader = (HWAPI_MSG_HEADER *)item;
		if(pHeader->type != HWAPI_MESSAGE_STREAM_OUTPUT_DATA)
		{
			UtilSemGive(hapi->receiveQueueSem);
#ifndef DRIVER_BUILD
			UtilSleep(5);
#else
			UtilSleep(HCW_POLL_DELAY);
#endif
			continue;
		}

		HAPIDeQueue(hapi->receiveQueue, &item);

		UtilSemGive(hapi->receiveQueueSem);


		// should not call continue/break/return after here because we need to free the "item" at end of while loop


		//LOG_INFO(("wt received msg type=0x%x\n", pHeader->type));


		//===========================
		// output data received
		//===========================
		if(1){
			HWAPI_MSG_STREAM_OUTPUT_DATA * pOutput = (HWAPI_MSG_STREAM_OUTPUT_DATA*)item;
			HAPI_AV_DATA_INFO info;
			//HWAPI_MSG_STREAM_OUTPUT_DATA_RSP* pRsp;

			LOG_INFO(("wt got output data %u <%d>\n", pOutput->dataLength, pOutput->header.cookie));

			

#ifdef HAUPPAUGE//potential "fix" for BSOD with bad dataLength
			if(pOutput->dataLength > pOutput->header.payloadSize)
			{
				DbgLogError(("wt Error: output data length(%u) > payld data size(%d)!!!\n", pOutput->dataLength, pOutput->header.payloadSize));
				pOutput->dataLength = pOutput->header.payloadSize;
			}
#endif
			if(pOutput->dataLength > MAX_STREAM_AV_DATA_SIZE)
			{
				DbgLogError(("wt Error: output data length(%d) > max data size(%d) payld(%d)!!!\n", pOutput->dataLength, MAX_STREAM_AV_DATA_SIZE, pOutput->header.payloadSize));
				pOutput->dataLength = MAX_STREAM_AV_DATA_SIZE;
			}

			// transfer output data to user
			info.channel = 0;//???
			info.requestSize = pOutput->dataLength;
			info.buf = (Uint8*)(&pOutput->data);

			if(hapi->dataReceive(&info, hapi->context) != HAPI_SUCCESS)
			{
				DbgLogError(("wt Error: callback dataReceive fail!!!\n"));
			}
		}	
		//LOG_INFO(("mt to free item 0x%x\n",item));
		MemFree2Heap(__FILE__, __LINE__, (Uint8*)item);
		
	}

#ifndef DRIVER_BUILD//HAUPPAUGE
	LOG_INFO(("writeThread exiting\n"));
#else
	DbgLogInfo(("writeThreadFunc() exiting\n"));
#endif

#ifdef DRIVER_BUILD
	hapi->exitWriteThread = 0; //FGR tell those waiting, we are done
	PsTerminateSystemThread(STATUS_SUCCESS);
#endif

	return;
}
#endif//USE_WRITE_THREAD

#endif//AV_ASI

/** This thread handles all callback messages. A separate thread for callback msg is 
 *   required to avoid deadlock in mainThread. 
 */
static void DLLCALL callbackThreadFunc(void * data)
{
	HAPIHandler hapi = (HAPIHandler)data;

	QueueItem item;
	Boolean msgReceived ;
	HWAPI_MSG_HEADER *pHeader;
	dxErrCode err;

#ifndef DRIVER_BUILD//HAUPPAUGE
#else
//	DbgLogInfo(("callbackThreadFunc(%p) starting Thread=%p\n", data, KeGetCurrentThread()));
#endif

	while(!hapi->exitCBThread)
	{
		item = NULL;
		msgReceived = FALSE;

		//==================
		// check receive queue
		//==================

		err = UtilSemTakeDbg(hapi->cbQueueSem, HCW_SEMA_DELAY, __LINE__);
		if(err != DX_SUCCESS)
		{
#ifndef DRIVER_BUILD
			UtilSleep(5);
#else
			UtilSleep(HCW_POLL_DELAY);
#endif
			continue;
		}

		HAPIPeekQueue(hapi->callbackQueue, &item);
		if(item == NULL)
		{
			UtilSemGive(hapi->cbQueueSem);
#ifndef DRIVER_BUILD
			UtilSleep(5);
#else
			UtilSleep(HCW_POLL_DELAY);
#endif
			continue;
		}

		HAPIDeQueue(hapi->callbackQueue, &item);  // All messages in the queue are to be processed by this task.

		UtilSemGive(hapi->cbQueueSem);

		pHeader = (HWAPI_MSG_HEADER *)item;

		LOG_INFO(("cbt received msg type=0x%x\n", pHeader->type));


		//===========================
		// I2C monitor msg received
		//===========================
        if(pHeader->type == HWAPI_MESSAGE_I2C_OUTPUT_MONITOR_DATA)
        {
            HWAPI_MSG_I2C_OUTPUT_MONITOR_DATA *pMsg = (HWAPI_MSG_I2C_OUTPUT_MONITOR_DATA *)item;
            (HapiErrCode*)hapi->I2CMonitorparams[pMsg->monitorNum].Callback(&pMsg->Param);
        }
        else if (pHeader->type == HWAPI_MESSAGE_ERROR)
        {
            HWAPI_MSG_ERR_UPDATE *pMsg =(HWAPI_MSG_ERR_UPDATE *)item;
#ifndef DRIVER_BUILD
            if (hapi->ErrorMsgCallback != NULL)
                (HapiErrCode)hapi->ErrorMsgCallback(pMsg->errType,hapi->errCbContext,&(pMsg->params));
            else
                printf("Callback Task: Unprocessed error message. Type=%d\n", pMsg->errType);
#else
            if (hapi->ErrorMsgCallback != NULL)
                (HapiErrCode)hapi->ErrorMsgCallback(pMsg->errType, hapi->context, &(pMsg->params));
            else {
			    DbgLogInfo(("Callback Task: Unprocessed error message. Type=%d\n", pMsg->errType));
			}
#endif
        }
        else
        {
            DbgLogError(("Error: unsupported message type=%d is seen in callbackQueue. Discard it.\n", pHeader->type));
        }
		//LOG_INFO(("mt to free item 0x%x\n",item));
		MemFree2Heap(__FILE__, __LINE__, (Uint8*)item);
	}

#ifndef DRIVER_BUILD//HAUPPAUGE
	LOG_INFO(("callbackThread exiting\n"));
#else
	DbgLogInfo(("callbackThread() exiting\n"));
#endif

	return;
}

//////////////////////////////////////////////////////////////////////////////////////////////

static 
Boolean isFractionalFrameRate(HAPI_VIDEO_OUTPUT_FRAME_RATE vfr)
{
    return (vfr == HAPI_VIDEO_OUTPUT_FRAME_RATE_23_98 ||
            vfr == HAPI_VIDEO_OUTPUT_FRAME_RATE_29_97 ||
            vfr == HAPI_VIDEO_OUTPUT_FRAME_RATE_59_94);
}

static 
Boolean isNonfractionalFrameRate(HAPI_VIDEO_OUTPUT_FRAME_RATE vfr)
{
    return (vfr == HAPI_VIDEO_OUTPUT_FRAME_RATE_24 ||
            vfr == HAPI_VIDEO_OUTPUT_FRAME_RATE_30 ||
            vfr == HAPI_VIDEO_OUTPUT_FRAME_RATE_60);
}

static 
HAPI_VIDEO_OUTPUT_FRAME_RATE getNonfractionalFrameRate(HAPI_VIDEO_OUTPUT_FRAME_RATE vfr)
{
    switch(vfr)
    {
        case HAPI_VIDEO_OUTPUT_FRAME_RATE_23_98:
            return HAPI_VIDEO_OUTPUT_FRAME_RATE_24;
        case HAPI_VIDEO_OUTPUT_FRAME_RATE_29_97:
            return HAPI_VIDEO_OUTPUT_FRAME_RATE_30;
        case HAPI_VIDEO_OUTPUT_FRAME_RATE_59_94:
            return HAPI_VIDEO_OUTPUT_FRAME_RATE_60;
        default:
            return vfr;
    }
}

static 
HAPI_VIDEO_OUTPUT_FRAME_RATE getFractionalFrameRate(HAPI_VIDEO_OUTPUT_FRAME_RATE vfr)
{
    switch(vfr)
    {
        case HAPI_VIDEO_OUTPUT_FRAME_RATE_24:
            return HAPI_VIDEO_OUTPUT_FRAME_RATE_23_98;
        case HAPI_VIDEO_OUTPUT_FRAME_RATE_30:
            return HAPI_VIDEO_OUTPUT_FRAME_RATE_29_97;
        case HAPI_VIDEO_OUTPUT_FRAME_RATE_60:
            return HAPI_VIDEO_OUTPUT_FRAME_RATE_59_94;
        default:
            return vfr;
    }
}

/** Adjust Video Capture(bInputFR=TRUE) or Output(bInputFR=FALSE) FrameRate accordingly, 
 *  i.e. both to be fractional or non-fractional, based on Video Capture & Output FrameRates
 */
static 
Boolean adjustVideoFrameRate(ENCODE_VIDEO_PARAMS *pVideoParams, Boolean bInputFR)
{
    if (isFractionalFrameRate(pVideoParams->VideoCapFrameRate) &&         // In : Frac
        isNonfractionalFrameRate(pVideoParams->VideoOutputFrameRate))     // Out: Non-Frac
    {
        if(bInputFR)
            pVideoParams->VideoCapFrameRate = getNonfractionalFrameRate(pVideoParams->VideoCapFrameRate);       // In : -> Non-Frac
        else
            pVideoParams->VideoOutputFrameRate = getFractionalFrameRate(pVideoParams->VideoOutputFrameRate);    // Out: -> Frac
        return TRUE; // Adjusted
    }
    else if (isNonfractionalFrameRate(pVideoParams->VideoCapFrameRate) && // In : Non-Frac
             isFractionalFrameRate(pVideoParams->VideoOutputFrameRate))   // Out: Frac
    {
        if(bInputFR)
            pVideoParams->VideoCapFrameRate = getFractionalFrameRate(pVideoParams->VideoCapFrameRate);          // In : -> Frac
        else
            pVideoParams->VideoOutputFrameRate = getNonfractionalFrameRate(pVideoParams->VideoOutputFrameRate); // Out: -> Non-Frac
        return TRUE; // Adjusted
    }

    return FALSE; // No Change
}

//////////////////////////////////////////////////////////////////////////////////////////////


HapiErrCode HAPI_Init(HAPIHandle * hapiHandle, HAPI_INIT_PARAM *chipInit)
{
	HAPIHandler hapi;

	LOG_API_ENTRANCE(("[HAPI_Init] chipID:0x%x, cmdBus:%p, dataBus:%p\n", 
					chipInit->chipID, chipInit->cmdBus, chipInit->dataBus));

#ifdef HAUPPAUGE
	if((hapiHandle == NULL) || (chipInit == NULL)){
		return HAPI_ERR_PARAMETER;
	}		
	*hapiHandle = NULL;
#endif
	hapi = (HAPIHandler)MemAllocFromHeap(__FILE__, __LINE__,  sizeof(HAPIStruct));

	if(hapi == NULL)
		return HAPI_ERR_MEMORY;

#ifdef HAUPPAUGE
	memset(hapi, 0, sizeof(HAPIStruct)); //FGR - BUGFIX - make sure all members start out 0
#endif

	hapi->chipID = chipInit->chipID;
	hapi->cmdBus = chipInit->cmdBus;
	hapi->dataBus = chipInit->dataBus;
#ifdef HAUPPAUGE
	hapi->context = chipInit->context;
#endif

	if(hapi->cmdBus->IF.boardInit(hapi->cmdBus->device, &chipInit->bkvConfig) == HWAPI_Fail)
	{
		DbgLogError(("HWAPI_BoardInit fail!!!\n"));
#ifdef HAUPPAUGE
		MemFree2Heap(__FILE__, __LINE__, hapi); 
#endif
		return HAPI_FAIL;
	}

	hapi->sendQueue = HAPICreateQueue(64, "sendQ");
	hapi->sendAndWaitQueue = HAPICreateQueue(16, "sendAndWaitQ");
	hapi->receiveQueue = HAPICreateQueue(16,"receiveQ");
	hapi->callbackQueue = HAPICreateQueue(16, "callbackQ");
	//hapi->waitResponseQueue = HAPICreateQueue(16);

	//LOG_DBG((" sendQ:0x%x \n send&WaitQ:0x%x \n receiveQ:0x%x\n",
	//	hapi->sendQueue, hapi->sendAndWaitQueue, hapi->receiveQueue));

	UtilSemCreate(&hapi->userCmdSem);
	DbgLogInfo(("hapi->userCmdSem = %p\n", hapi->userCmdSem));
	UtilSemTakeDbg(hapi->userCmdSem, 10, __LINE__); //FGR - BUGBUG - this seems odd ....

	UtilSemCreate(&hapi->sendQueueSem);
	DbgLogInfo(("hapi->sendQueueSem = %p\n", hapi->sendQueueSem));
	UtilSemGive(hapi->sendQueueSem);

	UtilSemCreate(&hapi->sendAndWaitQueueSem);
	DbgLogInfo(("hapi->sendAndWaitQueueSem = %p\n", hapi->sendAndWaitQueueSem));
	UtilSemGive(hapi->sendAndWaitQueueSem);

	UtilSemCreate(&hapi->receiveQueueSem);
	DbgLogInfo(("hapi->receiveQueueSem = %p\n", hapi->receiveQueueSem));
	UtilSemGive(hapi->receiveQueueSem);

	//UtilSemCreate(&hapi->waitResponseQueueSem);
	//UtilSemGive(hapi->waitResponseQueueSem);

	UtilSemCreate(&hapi->cmdBusSem);
	DbgLogInfo(("hapi->cmdBusSem = %p\n", hapi->cmdBusSem));
	UtilSemGive(hapi->cmdBusSem);

	UtilSemCreate(&hapi->cbQueueSem);
	DbgLogInfo(("hapi->cbQueueSem = %p\n", hapi->cbQueueSem));
	UtilSemGive(hapi->cbQueueSem);

#ifndef AV_ASI
	if(hapi->dataBus == hapi->cmdBus)
		hapi->dataBusSem = hapi->cmdBusSem;
	else
	{
		UtilSemCreate(&hapi->dataBusSem);
		DbgLogInfo(("hapi->dataBusSem = %p\n", hapi->dataBusSem));
		UtilSemGive(hapi->dataBusSem);
	}
#endif
	//if(UtilThreadStart(&hapi->cmdThread, cmdThreadFunc, hapi ) != DX_SUCCESS)
	//	return HAPI_FAIL;

	//if(UtilThreadStart(&hapi->dataThread, dataThreadFunc,hapi ) != DX_SUCCESS)
	//	return HAPI_FAIL;

	//if(UtilThreadStart(&hapi->mainThread, mainThreadFunc, hapi ) != DX_SUCCESS)
	//	return HAPI_FAIL;


	hapi->cookie = hapi->responseCookie = 0;
	hapi->dataSend = NULL;
	hapi->dataReceive = NULL;
	hapi->pMsgWaitingRsp = NULL;
    hapi->ErrorMsgCallback = NULL;
#ifndef DRIVER_BUILD//HAUPPAUGE - we already have a context
    hapi->errCbContext = NULL;
#endif
	hapi->exitCmdThread = 0;
	hapi->exitDataThread = 0;
	hapi->exitMainThread = 0;
	hapi->exitWriteThread = 0;
	hapi->exitCBThread = 0;
	*hapiHandle = hapi;

	hapi->state = HAPI_STATE_INIT;
	return HAPI_SUCCESS;

}

HWAPIHandle HAPI_commBusInit(Uint32 chipID, CommBusType busType, HWAPI_FUNCTIONS* pFunctions,hw_port_config *pHwPortConfig)
{
	HWAPI_STRUCT * hwapi;
	LOG_API_ENTRANCE(("[HAPI_commBusInit] chipID:0x%x, busType:%d\n", chipID, busType));

	hwapi = (HWAPIHandle)MemAllocFromHeap(__FILE__, __LINE__,  sizeof(HWAPI_STRUCT));
	if(hwapi == NULL)
		return NULL;

	hwapi->device = NULL;

	hwapi->busType = busType;
	hwapi->IF = *pFunctions;

	hwapi->device = hwapi->IF.commBusInit(chipID,pHwPortConfig);
	if(hwapi->device == NULL)
	{
		DbgLogError(("busType %d commBusInit() fail!!!\n", busType));
		MemFree2Heap(__FILE__, __LINE__, hwapi);
		return NULL;
	}

	return (HWAPIHandle)hwapi;
}


HapiErrCode HAPI_SetEndianSwap(HAPIHandle hChip, Uint32 swap)
{
    HAPIHandler handle = (HAPIHandler)hChip;
    
	LOG_API_ENTRANCE(("[HAPI_SetEndianSwap] hChip:%p, swap:%d\n", hChip, swap));

	handle->endianSwap = swap;

	return HAPI_SUCCESS;
}

HapiErrCode HAPI_GetBoardInfo(HWAPIHandle hBus, BOARD_INFO *pBoardInfo)
{
	HWAPIErrCode error;
	
	error = hBus->IF.getBoardInfo(hBus->device, pBoardInfo);

	if(error == HWAPI_Success)
		return HAPI_SUCCESS;
	else
		return HAPI_FAIL;
}

HapiErrCode HAPI_FWDownload(HAPIHandle hChip, FIRMWARE_FILE *fwFile)
{
    HAPIHandler handle = (HAPIHandler)hChip;
    
#ifndef DRIVER_BUILD//HAUPPAUGE
	LOG_API_ENTRANCE(("[%s] hChip:0x%x, mips:0x%x,%x,%x, sparc:0x%x,%x,%x\n", __FUNCTION__, 
                     (unsigned int)handle, (unsigned int)fwFile->mipsFile, fwFile->mipsBaseAddr, fwFile->mipsEntryAddr,
                     (unsigned int)fwFile->sparcFile, fwFile->sparcBaseAddr, fwFile->sparcEntryAddr));
#ifdef DOWNLOAD_BIN
	assert(fwFile->mipsFile);
	assert(fwFile->sparcFile);
#endif
#else
	LOG_API_ENTRANCE(("[HAPI_FWDownload] hChip:%p, mips:%x,%x, sparc:%x,%x\n",
				handle, fwFile->mipsBaseAddr, fwFile->mipsEntryAddr,
				fwFile->sparcBaseAddr, fwFile->sparcEntryAddr));
#endif

	if(handle->cmdBus->IF.binaryDownload(handle->cmdBus->device, fwFile) == HWAPI_Success)
		return HAPI_SUCCESS;
	else
	{
		DbgLogError(("IF.binaryDownload fail!!!\n"));
		return HAPI_FAIL;
	}
}

HapiErrCode HAPI_BoardBootup(HAPIHandle hChip, HAPI_BOOT_CONFIG *config)
{
    HAPIHandler handle = (HAPIHandler)hChip;

	HWAPI_MSG_INIT *msg = NULL;
	int headerSize = sizeof(HWAPI_MSG_HEADER);
	dxErrCode err;

	LOG_API_ENTRANCE(("[HAPI_BoardBootup] hChip:%p, AI:%d, VI:%d, AO:%d, VO:%d\n",
				handle, config->AudioInputPort, config->VideoInputPort, config->AudioOutputPort, config->VideoOutputPort));

	if(handle->cmdBus->IF.systemBootup(handle->cmdBus->device) == HWAPI_Fail)
	{
		DbgLogError(("IF.systemBootup fail!!!\n"));
		return HAPI_FAIL;
	}

	if(UtilThreadStart(&handle->cmdThread, cmdThreadFunc, handle, "HAPI-cmd" ) != DX_SUCCESS)
		return HAPI_FAIL;

	if(UtilThreadStart(&handle->mainThread, mainThreadFunc, handle, "HAPI-main" ) != DX_SUCCESS)
		return HAPI_FAIL;

	if(UtilThreadStart(&handle->callbackThread, callbackThreadFunc, handle, "HAPI-callback" ) != DX_SUCCESS)
		return HAPI_FAIL;
		
#ifndef AV_ASI
 #ifndef HAUPPAUGE
	if(UtilThreadStart(&handle->dataThread, dataThreadFunc,handle, "HAPI-data" ) != DX_SUCCESS)
		return HAPI_FAIL;
 #else
	//FGR - why have two threads using the same underlying USB interface
	if(handle->cmdBus != handle->dataBus)
	{
	  if(UtilThreadStart(&handle->dataThread, dataThreadFunc,handle, "HAPI-data" ) != DX_SUCCESS)
			return HAPI_FAIL;
	}
 #endif

 #ifdef USE_WRITE_THREAD
	if(UtilThreadStart(&handle->writeThread, writeThreadFunc, handle, "HAPI-write" ) != DX_SUCCESS)
		return HAPI_FAIL;
 #endif
#endif
	// construct message
	msg = (HWAPI_MSG_INIT *)MemAllocFromHeap(__FILE__, __LINE__,  sizeof(HWAPI_MSG_INIT));
	if(msg == NULL)
		return HAPI_ERR_MEMORY;
	
#ifdef HAUPPAUGE
	hcwGetRegistryDWORD("HAPI_MSG_RSV2_test", &dwHAPI_MSG_RSV2_test);
	hcwGetRegistryDWORD("HAPI_USER_CMD_TIME_OUT", &USER_CMD_TIME_OUT);
	if(USER_CMD_TIME_OUT < 3000){
		USER_CMD_TIME_OUT = 5000;//sanity check, known good value
	}
	
	DWORD dwHAPI_BoardBootupDelay = 350; //FGR - BUGBUG - what's a resonable value here (was 200)??
	hcwGetRegistryDWORD("HAPI_BoardBootupDelay", &dwHAPI_BoardBootupDelay);
	if(dwHAPI_BoardBootupDelay > 2000){
		dwHAPI_BoardBootupDelay = 2000;
	}
	UtilSleep(dwHAPI_BoardBootupDelay);
    DbgLogInfo((" after HAPI_BoardBootupDelay(%ums)\n", dwHAPI_BoardBootupDelay));
#endif

	msg->header.msgTag = HAPI_MSG_TAG;
	msg->header.msgVersion = HAPI_MSG_VERSION;
	msg->header.type = HWAPI_MESSAGE_INIT;
	msg->header.payloadSize = sizeof(HWAPI_MSG_INIT) - headerSize;
	msg->index = config->index;
	msg->inAudioPort = config->AudioInputPort;
	msg->inVideoPort = config->VideoInputPort;
	msg->outAudioPort = config->AudioOutputPort;
	msg->outVideoPort = config->VideoOutputPort;

	msg->bitMask = 0xffffffff;
	msg->checkCode = CRC32((unsigned char*)msg, headerSize + msg->header.payloadSize - 4);

	handle->userCmdResponseCode = HWAPI_MSG_RSP_FAIL;
	
	UtilSemTakeDbg(handle->sendAndWaitQueueSem, INFINITE, __LINE__);
	if(HAPIEnQueue(handle->sendAndWaitQueue, (QueueItem)msg)==1)
	{
	    DbgLogError(("HAPI_BoardBootup() HAPIEnQueue failed @line=%d\n", __LINE__));
		MemFree2Heap(__FILE__, __LINE__, msg); 
	    msg = NULL;
	    UtilSemGive(handle->sendAndWaitQueueSem);
	    return HAPI_FAIL;
	}    
	UtilSemGive(handle->sendAndWaitQueueSem);
	
	// wait for response
	err = UtilSemTakeDbg(handle->userCmdSem,USER_CMD_TIME_OUT + 500, __LINE__); // 

    if(err == DX_SUCCESS &&
       handle->userCmdResponseCode == HWAPI_MSG_RSP_PASS)
	{
		return HAPI_SUCCESS;
	}
	else
	{
		DbgLogError(("HWAPI_MESSAGE_INIT fail!!! sem err:%d, rspCode:0x%08x\n", err, handle->userCmdResponseCode));
		return HAPI_FAIL;
	}
}

HapiErrCode HAPI_I2CRead(HAPIHandle * hChip, HAPI_I2C_READ_PARAM *readParam)
{
    HAPIHandler handle = (HAPIHandler)hChip;
    HWAPI_MSG_I2C_READ *msg = NULL;
    int headerSize = sizeof(HWAPI_MSG_HEADER);
    dxErrCode err;

    LOG_API_ENTRANCE(("[HAPI_I2CRead] hChip:%p\n", handle));

    msg = (HWAPI_MSG_I2C_READ *)MemAllocFromHeap(__FILE__, __LINE__,  sizeof(HWAPI_MSG_I2C_READ));
    if(msg == NULL)
        return HAPI_ERR_MEMORY;

    msg->header.msgTag = HAPI_MSG_TAG;
    msg->header.msgVersion = HAPI_MSG_VERSION;
    msg->header.type = HWAPI_MESSAGE_I2C_READ;
    msg->header.payloadSize = sizeof(HWAPI_MSG_I2C_READ) - headerSize;
    msg->header.responseCode = 0x0;
    msg->checkCode = CRC32((unsigned char *)msg, headerSize + msg->header.payloadSize - 4);

    memcpy((void*)&msg->param, (void*)readParam, sizeof(HAPI_I2C_READ_PARAM));

    handle->userCmdResponseCode = HWAPI_MSG_RSP_FAIL;
    UtilSemTakeDbg(handle->sendAndWaitQueueSem, INFINITE, __LINE__);
    if(HAPIEnQueue(handle->sendAndWaitQueue, (QueueItem)msg)==1)
    {
	    DbgLogError(("HAPI_I2CRead() HAPIEnQueue failed @line=%d\n", __LINE__));
        MemFree2Heap(__FILE__, __LINE__, msg); 
        msg = NULL;
        UtilSemGive(handle->sendAndWaitQueueSem);
        return HAPI_FAIL;
    }    
    UtilSemGive(handle->sendAndWaitQueueSem);

	// wait for response
#ifdef HAUPPAUGE
	//FGR - INFINITE is just too long; if the FW dies, we die, forever ...
	err = UtilSemTakeDbg(handle->userCmdSem,USER_CMD_TIME_OUT + 500, __LINE__);
#else
	err = UtilSemTake(handle->userCmdSem,INFINITE);
#endif

    if(err == DX_SUCCESS && handle->userCmdResponseCode == HWAPI_MSG_RSP_PASS)
    {
        memcpy((void *)readParam, (void *)&handle->I2CReadParam, sizeof(HAPI_I2C_READ_PARAM));
        return HAPI_SUCCESS;
    }   
    else
    {
#ifndef DRIVER_BUILD
        fprintf(stderr,"HAPI_I2CRead fail: sem err:%d, responseCode:0x%08x\n", err, handle->userCmdResponseCode);
#else
		DbgLogError(("HAPI_I2CRead: sem err:%d, responseCode:0x%08x\n", err, handle->userCmdResponseCode));
#endif
        return HAPI_FAIL;
    }   
}

HapiErrCode HAPI_I2CWrite(HAPIHandle * hChip, HAPI_I2C_WRITE_PARAM *writeParam)
{
    HAPIHandler handle = (HAPIHandler)hChip;
    HWAPI_MSG_I2C_WRITE *msg = NULL;
    int headerSize = sizeof(HWAPI_MSG_HEADER);
    dxErrCode err;

    LOG_API_ENTRANCE(("[HAPI_I2CWrite] hChip:%p\n", handle));

    msg = (HWAPI_MSG_I2C_WRITE *)MemAllocFromHeap(__FILE__, __LINE__,  sizeof(HWAPI_MSG_I2C_WRITE));
    if(msg == NULL)
        return HAPI_ERR_MEMORY;

    msg->header.msgTag = HAPI_MSG_TAG;
    msg->header.msgVersion = HAPI_MSG_VERSION;
    msg->header.type = HWAPI_MESSAGE_I2C_WRITE;
    msg->header.payloadSize = sizeof(HWAPI_MSG_I2C_WRITE) - headerSize;
    msg->header.responseCode = 0x0;
    msg->checkCode = CRC32((unsigned char *)msg, headerSize + msg->header.payloadSize - 4);

    memcpy((void*)&msg->param, (void*)writeParam, sizeof(HAPI_I2C_WRITE_PARAM));

    handle->userCmdResponseCode = HWAPI_MSG_RSP_FAIL;
    UtilSemTakeDbg(handle->sendAndWaitQueueSem, INFINITE, __LINE__);
    if(HAPIEnQueue(handle->sendAndWaitQueue, (QueueItem)msg)==1)
    {
	    DbgLogError(("HAPI_I2CWrite() HAPIEnQueue failed @line=%d\n", __LINE__));
        MemFree2Heap(__FILE__, __LINE__, msg); 
        msg = NULL;
        UtilSemGive(handle->sendAndWaitQueueSem);
        return HAPI_FAIL;
    }    

    UtilSemGive(handle->sendAndWaitQueueSem);

	// wait for response
#ifdef HAUPPAUGE
	//FGR - INFINITE is just too long; if the FW dies, we die, forever ...
	err = UtilSemTakeDbg(handle->userCmdSem,USER_CMD_TIME_OUT + 500, __LINE__);
#else
	err = UtilSemTake(handle->userCmdSem,INFINITE);
#endif

	if(err == DX_SUCCESS
		&& handle->userCmdResponseCode == HWAPI_MSG_RSP_PASS)
		return HAPI_SUCCESS;
	else
	{
#ifndef DRIVER_BUILD
		fprintf(stderr,"HAPI_I2CWrite fail: sem err:%d, responseCode:0x%08x\n", err, handle->userCmdResponseCode);
#else
		DbgLogError(("HAPI_I2CWrite: sem err:%d, responseCode:0x%08x\n", err, handle->userCmdResponseCode));
#endif
		return HAPI_FAIL;
	}
}


HapiErrCode HAPI_GPIORead(HAPIHandle hChip, HAPI_GPIO_PIN_ID pin, Uint32 *pVal)
{
    HAPIHandler handle = (HAPIHandler)hChip;
    HWAPI_MSG_GPIO_READ *msg = NULL;
    int headerSize = sizeof(HWAPI_MSG_HEADER);
    dxErrCode err;

    LOG_API_ENTRANCE(("[HAPI_GPIORead] hChip:%p\n", handle));

    msg = (HWAPI_MSG_GPIO_READ *)MemAllocFromHeap(__FILE__, __LINE__,  sizeof(HWAPI_MSG_GPIO_READ));
    if(msg == NULL)
        return HAPI_ERR_MEMORY;

    msg->header.msgTag = HAPI_MSG_TAG;
    msg->header.msgVersion = HAPI_MSG_VERSION;
    msg->header.type = HWAPI_MESSAGE_GPIO_READ;
    msg->header.payloadSize = sizeof(HWAPI_MSG_GPIO_READ) - headerSize;
    msg->header.responseCode = 0x0;
    msg->checkCode = CRC32((unsigned char *)msg, headerSize + msg->header.payloadSize - 4);

    msg->pin = pin;
    
    handle->userCmdResponseCode = HWAPI_MSG_RSP_FAIL;
    UtilSemTakeDbg(handle->sendAndWaitQueueSem, INFINITE, __LINE__);
    if(HAPIEnQueue(handle->sendAndWaitQueue, (QueueItem)msg)==1)
    {
	    DbgLogError(("HAPI_GPIORead() HAPIEnQueue failed @line=%d\n", __LINE__));
        MemFree2Heap(__FILE__, __LINE__, msg); 
        msg = NULL;
        UtilSemGive(handle->sendAndWaitQueueSem);
        return HAPI_FAIL;
    }    
    UtilSemGive(handle->sendAndWaitQueueSem);

	// wait for response
#ifdef HAUPPAUGE
	//FGR - INFINITE is just too long; if the FW dies, we die, forever ...
	err = UtilSemTakeDbg(handle->userCmdSem,USER_CMD_TIME_OUT + 500, __LINE__);
#else
	err = UtilSemTake(handle->userCmdSem,INFINITE);
#endif

    if(err == DX_SUCCESS && handle->userCmdResponseCode == HWAPI_MSG_RSP_PASS)
    {
        //handle->GpioReturnVal = 0;
	    DbgLogTrace(("HAPI_GPIORead() gpio value=0x%x\n", handle->GpioReturnVal));
        *pVal = handle->GpioReturnVal;

        // DbgLogTrace(("**************gpio return value = %x\n",*pVal));
        return HAPI_SUCCESS;
    }   
    else
    {
	    DbgLogError(("HAPI_GPIORead() sem err:%d, responseCode:0x%08x\n", err, handle->userCmdResponseCode));
        return HAPI_FAIL;
    }   
}

HapiErrCode HAPI_GPIOWrite(HAPIHandle hChip, HAPI_GPIO_PIN_ID pin, Uint32 val)
{
    HAPIHandler handle = (HAPIHandler)hChip;
    HWAPI_MSG_GPIO_WRITE *msg = NULL;
    int headerSize = sizeof(HWAPI_MSG_HEADER);
    dxErrCode err;

    LOG_API_ENTRANCE(("[HAPI_GPIOWrite] hChip:%p\n", handle));

    msg = (HWAPI_MSG_GPIO_WRITE *)MemAllocFromHeap(__FILE__, __LINE__,  sizeof(HWAPI_MSG_GPIO_WRITE));
    if(msg == NULL)
        return HAPI_ERR_MEMORY;

    msg->header.msgTag = HAPI_MSG_TAG;
    msg->header.msgVersion = HAPI_MSG_VERSION;
    msg->header.type = HWAPI_MESSAGE_GPIO_WRITE;
    msg->header.payloadSize = sizeof(HWAPI_MSG_GPIO_WRITE) - headerSize;
    msg->header.responseCode = 0x0;
    msg->checkCode = CRC32((unsigned char *)msg, headerSize + msg->header.payloadSize - 4);
    msg->pin = pin;
    msg->val = val;
    handle->userCmdResponseCode = HWAPI_MSG_RSP_FAIL;
    
    UtilSemTakeDbg(handle->sendAndWaitQueueSem, INFINITE, __LINE__);
    if(HAPIEnQueue(handle->sendAndWaitQueue, (QueueItem)msg)==1)
    {
	    DbgLogError(("HAPI_GPIOWrite() HAPIEnQueue failed @line=%d\n", __LINE__));
        MemFree2Heap(__FILE__, __LINE__, msg); 
        msg = NULL;
        UtilSemGive(handle->sendAndWaitQueueSem);
        return HAPI_FAIL;
    }    

    UtilSemGive(handle->sendAndWaitQueueSem);

    // wait for response
#ifdef HAUPPAUGE
	//FGR - INFINITE is just too long; if the FW dies, we die, forever ...
	err = UtilSemTakeDbg(handle->userCmdSem,USER_CMD_TIME_OUT + 500, __LINE__);
#else
	err = UtilSemTake(handle->userCmdSem,INFINITE);
#endif

    if(err == DX_SUCCESS
		&& handle->userCmdResponseCode == HWAPI_MSG_RSP_PASS)
        return HAPI_SUCCESS;
    else
    {
	    DbgLogError(("HAPI_GPIOWrite() sem err:%d, responseCode:0x%08x\n", err, handle->userCmdResponseCode));
        return HAPI_FAIL;
    }
}

HapiErrCode HAPI_LogoConfig(HAPIHandle hChip, HAPI_LOGO_CONFIG_PARAM *config)
{
    HAPIHandler handle = (HAPIHandler)hChip;
    HWAPI_MSG_LOGO_CONFIG *msg = NULL;
    int headerSize = sizeof(HWAPI_MSG_HEADER);
    dxErrCode err;
    Uint32 msgSize = 0;
    Uint32 logoSize = 0;

    LOG_API_ENTRANCE(("[HAPI_LogoConfig] hChip:%p\n", handle));

    if ((config->width>MAX_LOGO_WIDTH)||(config->height>MAX_LOGO_HEIGHT)||(config->width*config->height>MAX_LOGO_SIZE)||(config->width*config->height==0)||(config->logoIndex>1))
    {
		DbgLogError(("HAPI_LogoConfig() bad params(%ux%u,%u\n",config->width,config->height,config->logoIndex));
        return HAPI_ERR_PARAMETER;
    }    

    logoSize = config->width*config->height*BYTE_PER_PIXEL;
    msgSize = sizeof(HWAPI_MSG_LOGO_CONFIG)-(MAX_LOGO_WIDTH*MAX_LOGO_HEIGHT*BYTE_PER_PIXEL)+logoSize;

#if 0//testing
	{
		DWORD dwAdjustLogoSize = 0;
		hcwGetRegistryDWORD("-HAPI_AdjustLogoSize", &dwAdjustLogoSize);
		if(dwAdjustLogoSize >= 512){
			msgSize /= 512;
			msgSize += dwAdjustLogoSize/512;
			msgSize *= 512;
			msgSize += dwAdjustLogoSize&0x1FF;
		} else {
			msgSize += dwAdjustLogoSize;
		}
	}
#endif
    DbgLogInfo(("sizeof(HWAPI_MSG_LOGO_CONFIG)=%u, msgSize=%u for logo=%ux%u\n",
		sizeof(HWAPI_MSG_LOGO_CONFIG), msgSize, config->width, config->height));
    
    msg = (HWAPI_MSG_LOGO_CONFIG *)MemAllocFromHeap(__FILE__, __LINE__, msgSize);
    if(msg == NULL)
        return HAPI_ERR_MEMORY;

    msg->header.msgTag = HAPI_MSG_TAG;
    msg->header.msgVersion = HAPI_MSG_VERSION;
    msg->header.type = HWAPI_MESSAGE_LOGO_CONFIG;
    msg->header.payloadSize = msgSize - headerSize;
    msg->header.responseCode = 0x0;
    msg->checkCode = CRC32((unsigned char *)msg, headerSize + msg->header.payloadSize - 4);

    msg->param.height = config->height;
    msg->param.width = config->width;
    msg->param.chIndex = config->chIndex;
    msg->param.logoIndex = config->logoIndex;
    msg->param.x = config->x;
    msg->param.y = config->y;

    memcpy(msg->param.logoData,config->logoData,logoSize);

    handle->userCmdResponseCode = HWAPI_MSG_RSP_FAIL;
    UtilSemTakeDbg(handle->sendAndWaitQueueSem, INFINITE, __LINE__);
    if(HAPIEnQueue(handle->sendAndWaitQueue, (QueueItem)msg)==1)
    {
	    DbgLogError(("HAPI_LogoConfig() HAPIEnQueue failed @line=%d\n", __LINE__));
        MemFree2Heap(__FILE__, __LINE__, msg); 
        msg = NULL;
        UtilSemGive(handle->sendAndWaitQueueSem);
        return HAPI_FAIL;
    }    

    UtilSemGive(handle->sendAndWaitQueueSem);
	// wait for response
#ifdef HAUPPAUGE
	//FGR - INFINITE is just too long; if the FW dies, we die, forever ...
	err = UtilSemTakeDbg(handle->userCmdSem,USER_CMD_TIME_OUT + 500, __LINE__);
#else
	err = UtilSemTake(handle->userCmdSem,INFINITE);
#endif

	if(err == DX_SUCCESS
		&& handle->userCmdResponseCode == HWAPI_MSG_RSP_PASS)
		return HAPI_SUCCESS;
	else
	{
	    DbgLogError(("HAPI_LogoConfig() sem err:%d, responseCode:0x%08x\n", err, handle->userCmdResponseCode));
		return HAPI_FAIL;
	}
}

HapiErrCode HAPI_LogoOnOff(HAPIHandle hChip, Uint32 index, Uint16 logoIndex, Uint8 on)
{
    HAPIHandler handle = (HAPIHandler)hChip;
    HWAPI_MSG_LOGO_ON_OFF *msg = NULL;
    int headerSize = sizeof(HWAPI_MSG_HEADER);
    dxErrCode err;

    LOG_API_ENTRANCE(("[HAPI_LogoOnOff] hChip:%p logoIndex=%d OnOff=%u\n", handle, logoIndex, on));

    if((logoIndex>1)||(on>1))
    {
	    DbgLogError(("HAPI_LogoOnOff() invalid param\n"));
        return HAPI_ERR_PARAMETER;
    }
    msg = (HWAPI_MSG_LOGO_ON_OFF *)MemAllocFromHeap(__FILE__, __LINE__,  sizeof(HWAPI_MSG_LOGO_ON_OFF));
    if(msg == NULL)
        return HAPI_ERR_MEMORY;

    msg->header.msgTag = HAPI_MSG_TAG;
    msg->header.msgVersion = HAPI_MSG_VERSION;
    msg->header.type = HWAPI_MESSAGE_LOGO_ON_OFF;
    msg->header.payloadSize = sizeof(HWAPI_MSG_LOGO_ON_OFF) - headerSize;
    msg->header.responseCode = 0x0;
    msg->checkCode = CRC32((unsigned char *)msg, headerSize + msg->header.payloadSize - 4);

    msg->chIndex = index;
    msg->logoIndex = logoIndex;
    msg->on =on;
    
    handle->userCmdResponseCode = HWAPI_MSG_RSP_FAIL;
    UtilSemTakeDbg(handle->sendAndWaitQueueSem, INFINITE, __LINE__);
    if(HAPIEnQueue(handle->sendAndWaitQueue, (QueueItem)msg)==1)
    {
	    DbgLogError(("HAPI_LogoOnOff() HAPIEnQueue failed @line=%d\n", __LINE__));
        MemFree2Heap(__FILE__, __LINE__, msg); 
        msg = NULL;
        UtilSemGive(handle->sendAndWaitQueueSem);
        return HAPI_FAIL;
    }    

    UtilSemGive(handle->sendAndWaitQueueSem);

	// wait for response
#ifdef HAUPPAUGE
	//FGR - INFINITE is just too long; if the FW dies, we die, forever ...
	err = UtilSemTakeDbg(handle->userCmdSem,USER_CMD_TIME_OUT + 500, __LINE__);
#else
	err = UtilSemTake(handle->userCmdSem,INFINITE);
#endif

	if(err == DX_SUCCESS
		&& handle->userCmdResponseCode == HWAPI_MSG_RSP_PASS)
		return HAPI_SUCCESS;
	else
	{
	    DbgLogError(("HAPI_LogoOnOff() sem err:%d, responseCode:0x%08x\n", err, handle->userCmdResponseCode));
		return HAPI_FAIL;
	}
}
HapiErrCode HAPI_I2CClockFreq(HAPIHandle hChip, Uint16 f_khz)
{
    HAPIHandler handle = (HAPIHandler)hChip;
    HWAPI_MSG_I2C_CLOCK_FREQ *msg = NULL;
    int headerSize = sizeof(HWAPI_MSG_HEADER);
    dxErrCode err;

    // construct message
    msg = (HWAPI_MSG_I2C_CLOCK_FREQ *)MemAllocFromHeap(__FILE__, __LINE__,  sizeof(HWAPI_MSG_I2C_CLOCK_FREQ));
    if(msg == NULL)
		return HAPI_ERR_MEMORY;
	
    msg->header.msgTag= HAPI_MSG_TAG;
    msg->header.msgVersion = HAPI_MSG_VERSION;
    msg->header.type = HWAPI_MESSAGE_I2C_SET_CLOCK_FREQ;
    msg->header.payloadSize = sizeof(HWAPI_MSG_I2C_CLOCK_FREQ) - headerSize;
    msg->checkCode = CRC32((unsigned char *)msg, headerSize + msg->header.payloadSize - 4);
    msg->f_khz = f_khz;
	
    handle->userCmdResponseCode = HWAPI_MSG_RSP_FAIL;
    UtilSemTakeDbg(handle->sendAndWaitQueueSem, INFINITE, __LINE__);
    if(HAPIEnQueue(handle->sendAndWaitQueue, (QueueItem)msg)==1)
    {
	    DbgLogError(("HAPI_I2CClockFreq() HAPIEnQueue failed @line=%d\n", __LINE__));
        MemFree2Heap(__FILE__, __LINE__, msg); 
        msg =NULL;
        UtilSemGive(handle->sendAndWaitQueueSem);
        return HAPI_FAIL;
    }
    UtilSemGive(handle->sendAndWaitQueueSem);
	
	// wait for response
    err = UtilSemTakeDbg(handle->userCmdSem,USER_CMD_TIME_OUT + 500, __LINE__);

    if(err == DX_SUCCESS
        && handle->userCmdResponseCode == HWAPI_MSG_RSP_PASS)
    {
        LOG_INFO(("\n set HAPI_I2CClockFreq success...\n"));
        return HAPI_SUCCESS;
    }
    else
    {
        DbgLogError(("HAPI_I2CClockFreqfail!!! sem err:%d, rspCode:0x%08x\n", err, handle->userCmdResponseCode));
        return HAPI_FAIL;
    }
}


HapiErrCode HAPI_I2CMonitorInstall(HAPIHandle hChip, HAPI_I2C_MONITOR_NUM monitorNum, HAPI_I2C_MONITOR_PARAM *monitorParam)
{
    HAPIHandler handle = (HAPIHandler)hChip;
    HWAPI_MSG_I2C_MONITOR_INSTALL *msg = NULL;
    int headerSize = sizeof(HWAPI_MSG_HEADER);
    dxErrCode err;

    // construct message
    msg = (HWAPI_MSG_I2C_MONITOR_INSTALL*)MemAllocFromHeap(__FILE__, __LINE__,  sizeof(HWAPI_MSG_I2C_MONITOR_INSTALL));
    if(msg == NULL)
		return HAPI_ERR_MEMORY;
	
    msg->header.msgTag= HAPI_MSG_TAG;
    msg->header.msgVersion = HAPI_MSG_VERSION;
    msg->header.type = HWAPI_MESSAGE_I2C_MONITOR_INSTALL;
    msg->header.payloadSize = sizeof(HWAPI_MSG_I2C_MONITOR_INSTALL) - headerSize;
    msg->checkcode= CRC32((unsigned char *)msg, headerSize + msg->header.payloadSize - 4);
    msg->monitorNum = monitorNum;

    memcpy((void*)&msg->param, (void*)monitorParam, sizeof(HAPI_I2C_MONITOR_PARAM));
	
    handle->userCmdResponseCode = HWAPI_MSG_RSP_FAIL;

    handle->I2CMonitorparams[monitorNum].Callback = monitorParam->Callback;
    UtilSemTakeDbg(handle->sendAndWaitQueueSem, INFINITE, __LINE__);
    if(HAPIEnQueue(handle->sendAndWaitQueue, (QueueItem)msg)==1)
    {
	    DbgLogError(("HAPI_I2CMonitorInstall() HAPIEnQueue failed @line=%d\n", __LINE__));
        MemFree2Heap(__FILE__, __LINE__, msg); 
        msg = NULL;
        UtilSemGive(handle->sendAndWaitQueueSem);
        return HAPI_FAIL;
    }
    UtilSemGive(handle->sendAndWaitQueueSem);
    
	// wait for response
#ifdef HAUPPAUGE
	//FGR - INFINITE is just too long; if the FW dies, we die, forever ...
	err = UtilSemTakeDbg(handle->userCmdSem,USER_CMD_TIME_OUT + 500, __LINE__);
#else
	err = UtilSemTake(handle->userCmdSem,INFINITE);
#endif

    if(err == DX_SUCCESS
        && handle->userCmdResponseCode == HWAPI_MSG_RSP_PASS)
    {
        LOG_INFO(("\nHAPI_I2CMonitorInstall ...\n"));
        return HAPI_SUCCESS;
    }
    else
    {
        DbgLogError(("HAPI_I2CMonitorInstall fail!!! sem err:%d, rspCode:0x%08x\n", err, handle->userCmdResponseCode));
        return HAPI_FAIL;
    }
    return HAPI_SUCCESS;
}

HapiErrCode HAPI_SetAVLDriver(HAPIHandle hChip, HAPI_SET_AVL_PARAM *avl)
{
    HAPIHandler handle = (HAPIHandler)hChip;
    HWAPI_MSG_SET_AVL *msg = NULL;
    int headerSize = sizeof(HWAPI_MSG_HEADER);
    dxErrCode err;

    // construct message
    msg = (HWAPI_MSG_SET_AVL*)MemAllocFromHeap(__FILE__, __LINE__,  sizeof(HWAPI_MSG_SET_AVL));
    if(msg == NULL)
        return HAPI_ERR_MEMORY;

    msg->header.msgTag= HAPI_MSG_TAG;
    msg->header.msgVersion = HAPI_MSG_VERSION;
    msg->header.type = HWAPI_MESSAGE_SET_AVL;
    msg->header.payloadSize = sizeof(HWAPI_MSG_SET_AVL) - headerSize;
    msg->checkCode = CRC32((unsigned char *)msg, headerSize + msg->header.payloadSize - 4);
    memcpy((void*)&msg->avl, (void*)avl, sizeof(HAPI_SET_AVL_PARAM));

    handle->userCmdResponseCode = HWAPI_MSG_RSP_FAIL;
    UtilSemTakeDbg(handle->sendAndWaitQueueSem, INFINITE, __LINE__);
    if(HAPIEnQueue(handle->sendAndWaitQueue, (QueueItem)msg)==1)
    {
	    DbgLogError(("HAPI_SetAVLDriver() HAPIEnQueue failed @line=%d\n", __LINE__));
        MemFree2Heap(__FILE__, __LINE__, msg);
        msg = NULL;
        UtilSemGive(handle->sendAndWaitQueueSem);
        return HAPI_FAIL;
    }
    UtilSemGive(handle->sendAndWaitQueueSem);

    // wait for response
#ifdef HAUPPAUGE
	//FGR - INFINITE is just too long; if the FW dies, we die, forever ...
	err = UtilSemTakeDbg(handle->userCmdSem,USER_CMD_TIME_OUT + 500, __LINE__);
#else
    err = UtilSemTake(handle->userCmdSem,INFINITE);
#endif

    if(err == DX_SUCCESS
        && handle->userCmdResponseCode == HWAPI_MSG_RSP_PASS)
    {
        LOG_INFO(("\nHAPI_SetAVLDriver ...\n"));
        return HAPI_SUCCESS;
    }
    else
    {
        DbgLogInfo(("HAPI_SetAVLDriver fail!!! sem err:%d, rspCode:0x%08x\n", err, handle->userCmdResponseCode));
        return HAPI_SUCCESS; //BUGBUG was HAPI_FAIL;
    }
}

HapiErrCode HAPI_ErrorMsgCallbackInstall(HAPIHandle hChip, HAPI_ErrorMsgCallback func)
{
    HAPIHandler handle = (HAPIHandler)hChip;

    if(func == NULL)
        return HAPI_ERR_PARAMETER;

    handle->ErrorMsgCallback = func;
#ifndef DRIVER_BUILD//HAUPPAUGE - we already have a context
    handle->errCbContext = context;
#endif
	return HAPI_SUCCESS;
}


HapiErrCode HAPI_PCRSet(HAPIHandle hChip, Uint64 pcr)
{
    HAPIHandler handle = (HAPIHandler)hChip;
    HWAPI_MSG_PCR_DATA *msg =NULL;
    int headerSize = sizeof(HWAPI_MSG_HEADER);
    dxErrCode err;

    LOG_API_ENTRANCE(("[HAPI_PCRSet] hChip:%p PCR=%llx\n", handle, pcr));
    msg = (HWAPI_MSG_PCR_DATA*)MemAllocFromHeap(__FILE__,__LINE__,sizeof(HWAPI_MSG_PCR_DATA));
    if (msg == NULL)
        return HAPI_ERR_MEMORY;

    msg->header.msgTag = HAPI_MSG_TAG;
    msg->header.msgVersion = HAPI_MSG_VERSION;
    msg->header.type = HWAPI_MESSAGE_SET_PCR;
    msg->header.payloadSize = sizeof(HWAPI_MSG_PCR_DATA)-headerSize;
    msg->header.responseCode = 0x0;

    msg->pcrLow= (Uint32)pcr;
    msg->pcrHigh= (Uint32)(pcr>>32);

    handle->userCmdResponseCode = HWAPI_MSG_RSP_FAIL;
    UtilSemTakeDbg(handle->sendAndWaitQueueSem, INFINITE, __LINE__);
    HAPIEnQueue(handle->sendAndWaitQueue, (QueueItem)msg);
    UtilSemGive(handle->sendAndWaitQueueSem);

	// wait for response
#ifdef HAUPPAUGE
	//FGR - INFINITE is just too long; if the FW dies, we die, forever ...
	err = UtilSemTakeDbg(handle->userCmdSem,USER_CMD_TIME_OUT + 500, __LINE__);
#else
    err = UtilSemTake(handle->userCmdSem,INFINITE);
#endif

	if(err == DX_SUCCESS
		&& handle->userCmdResponseCode == HWAPI_MSG_RSP_PASS)
		return HAPI_SUCCESS;
	else
	{
		DbgLogError(("HAPI_PCRSet fail: sem err:%d, responseCode:0x%08x\n", err, handle->userCmdResponseCode));
		return HAPI_FAIL;
	}
    return HAPI_SUCCESS;
}

HapiErrCode HAPI_ARSet(HAPIHandle hChip, Uint32 ch, HAPI_ASPECT_RATIO ar)
{
    HAPIHandler handle = (HAPIHandler)hChip;
    HWAPI_MSG_AR_DATA *msg =NULL;
    int headerSize = sizeof(HWAPI_MSG_HEADER);
    dxErrCode err;

    LOG_API_ENTRANCE(("[HAPI_ARSet] hChip:%p\n", handle));
    msg = (HWAPI_MSG_AR_DATA*)MemAllocFromHeap(__FILE__,__LINE__,sizeof(HWAPI_MSG_AR_DATA));
    if (msg == NULL)
        return HAPI_ERR_MEMORY;

    msg->header.msgTag = HAPI_MSG_TAG;
    msg->header.msgVersion = HAPI_MSG_VERSION;
    msg->header.type = HWAPI_MESSAGE_SET_AR;
    msg->header.payloadSize = sizeof(HWAPI_MSG_AR_DATA)-headerSize;
    msg->header.responseCode = 0x0;

    msg->ch = ch;
    msg->ar = ar;

    handle->userCmdResponseCode = HWAPI_MSG_RSP_FAIL;
    UtilSemTakeDbg(handle->sendAndWaitQueueSem, INFINITE, __LINE__);
    HAPIEnQueue(handle->sendAndWaitQueue, (QueueItem)msg);
    UtilSemGive(handle->sendAndWaitQueueSem);

	// wait for response
#ifdef HAUPPAUGE
	//FGR - INFINITE is just too long; if the FW dies, we die, forever ...
	err = UtilSemTakeDbg(handle->userCmdSem,USER_CMD_TIME_OUT + 500, __LINE__);
#else
    err = UtilSemTake(handle->userCmdSem,INFINITE);
#endif

	if(err == DX_SUCCESS
		&& handle->userCmdResponseCode == HWAPI_MSG_RSP_PASS)
		return HAPI_SUCCESS;
	else
	{
		DbgLogError(("HAPI_ARSet fail: sem err:%d, responseCode:0x%08x\n", err, handle->userCmdResponseCode));
		return HAPI_FAIL;
	}
    return HAPI_SUCCESS;
}

HapiErrCode HAPI_StatusQuery(HAPIHandle hChip, HAPI_QUERY_STRUCT *status)
{
    HAPIHandler handle = (HAPIHandler)hChip;
    HWAPI_MSG_QUERY_STATUS *msg =NULL;
    int headerSize = sizeof(HWAPI_MSG_HEADER);
    dxErrCode err;

    LOG_API_ENTRANCE(("[HAPI_StatusQuery] hChip:%p, %p\n", handle, status));
    msg = (HWAPI_MSG_QUERY_STATUS*)MemAllocFromHeap(__FILE__,__LINE__,sizeof(HWAPI_MSG_QUERY_STATUS));
    if (msg == NULL)
        return HAPI_ERR_MEMORY;

    msg->header.msgTag = HAPI_MSG_TAG;
    msg->header.msgVersion = HAPI_MSG_VERSION;
    msg->header.type = HWAPI_MESSAGE_STATUS_QUERY;
    msg->header.payloadSize = sizeof(HWAPI_MSG_QUERY_STATUS)-headerSize;
    msg->header.responseCode = 0x0;

    memcpy((void*)&msg->status,(void*)status,sizeof(HAPI_QUERY_STRUCT));
    handle->userCmdResponseCode = HWAPI_MSG_RSP_FAIL;
    UtilSemTakeDbg(handle->sendAndWaitQueueSem, INFINITE, __LINE__);
    HAPIEnQueue(handle->sendAndWaitQueue, (QueueItem)msg);
    UtilSemGive(handle->sendAndWaitQueueSem);

	// wait for response
#ifdef HAUPPAUGE
	//FGR - INFINITE is just too long; if the FW dies, we die, forever ...
	err = UtilSemTakeDbg(handle->userCmdSem,USER_CMD_TIME_OUT + 500, __LINE__);
#else
    err = UtilSemTake(handle->userCmdSem,INFINITE);
#endif

    if(err == DX_SUCCESS && handle->userCmdResponseCode == HWAPI_MSG_RSP_PASS)
    {
        memcpy((void *)status, (void *)&handle->queryStatus, sizeof(HAPI_QUERY_STRUCT));
        return HAPI_SUCCESS;
    }   
    else
    {
        DbgLogError(("HAPI_StatusQuery fail: sem err:%d, responseCode:0x%08x\n", err, handle->userCmdResponseCode));
        return HAPI_FAIL;
    }   
    return HAPI_SUCCESS;
}

HapiErrCode HAPI_ParamSet(HAPIHandle hChip, HAPI_SET_PARAM *param)
{
    HAPIHandler handle = (HAPIHandler)hChip;
    HWAPI_MSG_SET_PARAM *msg = NULL;
    int headerSize = sizeof(HWAPI_MSG_HEADER);
    //int paramSize = sizeof(HAPI_SET_PARAM);
    dxErrCode err;
	Boolean bResumeState = FALSE;

    LOG_API_ENTRANCE(("[HAPI_ParamSet] hChip:%p\n", handle));
/*
	if ((handle->state != HAPI_STATE_INIT) && (handle->state != HAPI_STATE_START))
	{
		DbgLogError(("%s() It is called in %d state!!!\n", __FUNCTION__, handle->state));
		return HAPI_FAIL;
	}
*/
    // construct message
    msg = (HWAPI_MSG_SET_PARAM *)MemAllocFromHeap(__FILE__, __LINE__,  sizeof(HWAPI_MSG_SET_PARAM));
    if(msg == NULL)
    	return HAPI_ERR_MEMORY;

	DbgLogInfo(("HAPI_ParamSet msg %p, param: %p, header %d\n", msg, &msg->param, sizeof(HWAPI_MSG_HEADER)));

    msg->header.msgTag = HAPI_MSG_TAG;
    msg->header.msgVersion = HAPI_MSG_VERSION;
    msg->header.type = HWAPI_MESSAGE_SET_PARAM;
    msg->header.payloadSize = sizeof(HWAPI_MSG_SET_PARAM) - headerSize;
    msg->header.responseCode = 0x0;
    memcpy((void*)&msg->param, (void*)param, sizeof(HAPI_SET_PARAM));

    msg->param.bitMask |= HWAPI_BM_MSG_SET_PARAM_INDEX;

    if (param->ParamType == HAPI_SET_PARAM_TYPE_TRANSCODER)//0-encode, 1-decode, 2-transcode
    {
        msg->param.params.transcodeParam.bitMask = HAPI_BM_XCODE_VIDEO_PARAMS 
                                                 | HAPI_BM_XCODE_AUDIO_PARAMS
                                                 | HAPI_BM_XCODE_LOG_PARAMS;

        msg->param.params.transcodeParam.LogParams.bitMask = HWAPI_BM_MSG_TRANSCODE_ERROR_LOG_ENABLE;

        msg->param.params.transcodeParam.VideoParams.StreamID = 1;
        msg->param.params.transcodeParam.AudioParams.StreamID = 1;
#ifndef DRIVER_BUILD//HAUPPAUGE
        printf("level: %d\n", msg->param.params.transcodeParam.VideoParams.Level);
#endif
    }
    else if(param->ParamType == HAPI_SET_PARAM_TYPE_ENCODER)//0-encode, 1-decode, 2-transcode
    {
        msg->param.params.encodeParam.bitMask = HAPI_BM_ENCODE_VIDEO_PARAMS 
                                              | HAPI_BM_ENCODE_AUDIO_PARAMS
                                              | HAPI_BM_ENCODE_LOG_PARAMS;

        msg->param.params.encodeParam.LogParams.bitMask = HWAPI_BM_MSG_ENCODE_ERROR_LOG_ENABLE;

#ifndef DRIVER_BUILD//HAUPPAUGE
        printf("\tencodeParam.bitMask = 0x%x\n",msg->param.params.encodeParam.bitMask);

//BUGBUG - FGR - we set bitmask for params we want to change; why are they always setting these???
        // Set the bitmask for the following parameters which will be updated by video resolution callback
        // printf("\t0: encodeParam.VideoParams.bitMask = 0x%x\n",msg->param.params.encodeParam.VideoParams.bitMask);
        msg->param.params.encodeParam.VideoParams.bitMask |= HWAPI_BM_MSG_ENCODE_VIDEO_CAPTURE_WIDTH;
        msg->param.params.encodeParam.VideoParams.bitMask |= HWAPI_BM_MSG_ENCODE_VIDEO_CAPTURE_HEIGHT;
        msg->param.params.encodeParam.VideoParams.bitMask |= HWAPI_BM_MSG_ENCODE_VIDEO_CAPTURE_FORMAT;
        msg->param.params.encodeParam.VideoParams.bitMask |= HWAPI_BM_MSG_ENCODE_VIDEO_CAPTURE_FRAME_RATE;
        msg->param.params.encodeParam.VideoParams.bitMask |= HWAPI_BM_MSG_ENCODE_VIDEO_OUTPUT_WIDTH;
        msg->param.params.encodeParam.VideoParams.bitMask |= HWAPI_BM_MSG_ENCODE_VIDEO_OUTPUT_HEIGHT;
        msg->param.params.encodeParam.VideoParams.bitMask |= HWAPI_BM_MSG_ENCODE_VIDEO_OUTPUT_MODE;
        msg->param.params.encodeParam.VideoParams.bitMask |= HWAPI_BM_MSG_ENCODE_VIDEO_OUTPUT_FRAME_RATE;
        msg->param.params.encodeParam.VideoParams.bitMask |= HWAPI_BM_MSG_ENCODE_VIDEO_CODING_MODE;
        msg->param.params.encodeParam.AudioParams.bitMask |= HWAPI_BM_MSG_ENCODE_AUDIO_CAPTURE_SAMPLE_RATE;
        msg->param.params.encodeParam.AudioParams.bitMask |= HWAPI_BM_MSG_ENCODE_AUDIO_OUTPUT_SAMPLE_RATE;
        printf("\t1: encodeParam.VideoParams.bitMask = 0x%x\n",msg->param.params.encodeParam.VideoParams.bitMask);

        // printf("\tVideoCapWidth=%d\n",  msg->param.params.encodeParam.VideoParams.VideoCapWidth);
        // printf("\tVIdeoCapHeight=%d\n",  msg->param.params.encodeParam.VideoParams.VIdeoCapHeight);
        // printf("\tVideoCapFormat=%d\n",  msg->param.params.encodeParam.VideoParams.VideoCapFormat);
        // printf("\tVideoCapFrameRate=%d\n",  msg->param.params.encodeParam.VideoParams.VideoCapFrameRate);
        // printf("\tVideoOutputWidth=%d\n",  msg->param.params.encodeParam.VideoParams.VideoOutputWidth);
        // printf("\tVideoOutputHeight=%d\n",  msg->param.params.encodeParam.VideoParams.VideoOutputHeight);
        // printf("\tVideoOutputMode=%d\n",  msg->param.params.encodeParam.VideoParams.VideoOutputMode);
        // printf("\tVideoOutputFrameRate=%d\n",  msg->param.params.encodeParam.VideoParams.VideoOutputFrameRate);
        // printf("\tCodingMode=%d\n",  msg->param.params.encodeParam.VideoParams.CodingMode);

        // msg->param.params.encodeParam.VideoParams.StreamID = 1;
        // msg->param.params.encodeParam.AudioParams.StreamID = 1;

        /* Adjust Video Capture(bInputFR=TRUE) or Output(bInputFR=FALSE) FrameRate accordingly, 
         * i.e. both to be fractional or non-fractional, based on Video Capture & Output FrameRates
         */
        if(adjustVideoFrameRate(&msg->param.params.encodeParam.VideoParams, FALSE)) // Adjust Video Output FrameRate
        {
            param->params.encodeParam.VideoParams.VideoCapFrameRate = msg->param.params.encodeParam.VideoParams.VideoCapFrameRate;
            param->params.encodeParam.VideoParams.VideoOutputFrameRate = msg->param.params.encodeParam.VideoParams.VideoOutputFrameRate;
            printf("\t-> VideoCapFrameRate=%d\n", msg->param.params.encodeParam.VideoParams.VideoCapFrameRate);
            printf("\t-> VideoOutputFrameRate=%d\n", msg->param.params.encodeParam.VideoParams.VideoOutputFrameRate);
        }
#else
		DWORD dwAdjustVideoFrameRate = 1;
		hcwGetRegistryDWORD("-HAPI_AdjustVideoFrameRate", &dwAdjustVideoFrameRate);
		if(dwAdjustVideoFrameRate){
			if(adjustVideoFrameRate(&msg->param.params.encodeParam.VideoParams, FALSE)) // Adjust Video Output FrameRate
			{
				//FGR - don't change input params, just the params passed to encoder
				//param->params.encodeParam.VideoParams.VideoCapFrameRate = msg->param.params.encodeParam.VideoParams.VideoCapFrameRate;
				//param->params.encodeParam.VideoParams.VideoOutputFrameRate = msg->param.params.encodeParam.VideoParams.VideoOutputFrameRate;
				DbgLogWarn((" VideoOutputFrameRate=%d changed to %d by adjustVideoFrameRate()\n",
					param->params.encodeParam.VideoParams.VideoOutputFrameRate,
					msg->param.params.encodeParam.VideoParams.VideoCapFrameRate));
			}
		}
#endif
    }

	//This could be a dynamic channel change. If it is, we want to set HAPI state to INIT state util the command returns.
	// This is to avoid sending data to DXT while DXT is experiencing channel change.
    if ((param->ParamType == HAPI_SET_PARAM_TYPE_TRANSCODER) && (handle->state == HAPI_STATE_START))
	{
		if (msg->param.params.transcodeParam.bitMask & HAPI_BM_XCODE_VIDEO_PARAMS)
		{
			if ((msg->param.bitMask & HWAPI_BM_MSG_SET_PARAM_INPUT_AUDIO_PID) &&
				(msg->param.bitMask & HWAPI_BM_MSG_SET_PARAM_INPUT_VIDEO_PID) &&
				(msg->param.bitMask & HWAPI_BM_MSG_SET_PARAM_INPUT_PCR_PID))
			{
				handle->state = HAPI_STATE_INIT;
				bResumeState = TRUE;	// The state is to be resumed.
			}
		}

	}

    handle->userCmdResponseCode = HWAPI_MSG_RSP_FAIL;
    UtilSemTakeDbg(handle->sendAndWaitQueueSem, INFINITE, __LINE__);
    if(HAPIEnQueue(handle->sendAndWaitQueue, (QueueItem)msg)==1)
    {
	    DbgLogError(("HAPI_ParamSet() HAPIEnQueue failed @line=%d\n", __LINE__));
        MemFree2Heap(__FILE__, __LINE__, msg); 
        msg = NULL;
        UtilSemGive(handle->sendAndWaitQueueSem);
        return HAPI_FAIL;
    }
    UtilSemGive(handle->sendAndWaitQueueSem);

    // wait for response
#ifdef HAUPPAUGE
	//FGR - why was this commented out; can some cmd REALLY take this long ...
	// and if the FW dies, we die, forever ...
	err = UtilSemTakeDbg(handle->userCmdSem,USER_CMD_TIME_OUT + 500, __LINE__);
#else
    //err = UtilSemTake(handle->userCmdSem,USER_CMD_TIME_OUT + 500);
    err = UtilSemTake(handle->userCmdSem,INFINITE);
#endif
	if (bResumeState)
		handle->state = HAPI_STATE_START;

    if(err == DX_SUCCESS && 
       handle->userCmdResponseCode == HWAPI_MSG_RSP_PASS)
        return HAPI_SUCCESS;
    else
    {
#ifndef DRIVER_BUILD//HAUPPAUGE
        fprintf(stderr,"HAPI_SET_PARAM fail: sem err:%d, responseCode:0x%08x\n", err, handle->userCmdResponseCode);
#else
		DbgLogError(("HAPI_SET_PARAM: sem err:%d, responseCode:0x%08x\n", err, handle->userCmdResponseCode));
#endif
        return HAPI_FAIL;
    }
}

#define FLASH_BLOCK_SIZE  65536

HapiErrCode HAPI_FWUpgrade(HAPIHandle hChip, HAPI_FWUPGRADE_PARAM *param)
{
#ifndef DRIVER_BUILD
	FILE	*fp=NULL;
#endif
	HAPIHandler handle = (HAPIHandler)hChip;
	HWAPI_MSG_FWUPGRADE	*msg=NULL;
	int headerSize = sizeof(HWAPI_MSG_HEADER);
	dxErrCode err;
	int	readLen=0;
	int count = 0;
	Uint32 address= 0;
	Uint32 length = 0;

#ifndef DRIVER_BUILD
	printf("HAPI_FWUpgrade Start: Path: %s addr=%x BPT:%d\n",param->filePath,param->targetAddress,param->bytesPerTransfer);

	fp  = fopen(param->filePath,"rb");
	if(fp == NULL)
	{
		printf("HAPI_FWUpgrade open upgrade file fail\n");
		return HAPI_FAIL;
	}
#else
	DbgLogError(("HAPI_FWUpgrade(%p, %p) not supported!!\n", hChip, param));//FGR - BUGBUG
	return HAPI_FAIL;
#endif
	
	address = param->targetAddress;
	length  = param->bytesPerTransfer;

	while(1)
	{
	
		msg = (HWAPI_MSG_FWUPGRADE *)MemAllocFromHeap(__FILE__, __LINE__,  sizeof(HWAPI_MSG_FWUPGRADE));
		if(msg == NULL)
		{
#ifndef DRIVER_BUILD
				printf("HAPI_FWUpgrade allocate memory fail\n");
#else
				DbgLogError(("HAPI_FWUpgrade() allocate memory fail\n"));
#endif
			return HAPI_ERR_MEMORY;
		}

		msg->index = 0;
		msg->addr = address;

		if((FLASH_BLOCK_SIZE-count) >= (HAPI_FWUPGRADE_MAXPAYLOADSIZE- 20))
		{
			msg->length = length;
			count += msg->length;
		}
		else
		{
			msg->length = FLASH_BLOCK_SIZE-count;
			count = 0;
		}

		readLen = 0;
		DbgLogError(("HAPI_FWUpgrade() reading firmware update NOT implemented\n")); //FGR - BUGBUG
		return HAPI_FAIL;

		msg->header.msgTag= HAPI_MSG_TAG;
		msg->header.msgVersion = HAPI_MSG_VERSION;
		msg->header.type = HWAPI_MESSAGE_FWUPGRADE;
		msg->header.payloadSize = HAPI_FWUPGRADE_MAXPAYLOADSIZE;
		msg->bitMask = 0xffffffff;
		msg->checkCode = CRC32((unsigned char*)msg, headerSize + msg->header.payloadSize - 4);
	
		handle->userCmdResponseCode = HWAPI_MSG_RSP_FAIL;
		UtilSemTakeDbg(handle->sendAndWaitQueueSem, INFINITE, __LINE__);
		if(HAPIEnQueue(handle->sendAndWaitQueue, (QueueItem)msg)==1)
		{
	    	DbgLogError(("HAPI_FWUpgrade() HAPIEnQueue failed @line=%d\n", __LINE__));
			MemFree2Heap(__FILE__, __LINE__, msg); 
			msg = NULL;
			UtilSemGive(handle->sendAndWaitQueueSem);
			return HAPI_FAIL;
		}
		UtilSemGive(handle->sendAndWaitQueueSem);
	
		// wait for response
		err = UtilSemTakeDbg(handle->userCmdSem,USER_CMD_TIME_OUT + 500, __LINE__);

		if(!(err == DX_SUCCESS && handle->userCmdResponseCode == HWAPI_MSG_RSP_PASS))
		{
			DbgLogError(("HAPI_FWUpgrade() Time out, HAPI_FWUpgrade Fail\n"));
			return HAPI_FAIL;
		}

		address += readLen; 
		
	}

#ifdef DRIVER_BUILD
	return HAPI_FAIL; //can't happen, but we need to return a value
#endif
}

HapiErrCode HAPI_ParamGet(HAPIHandle hChip, HAPI_GET_PARAM *param)
{
    HAPIHandler handle = (HAPIHandler)hChip;
	HWAPI_MSG_GET_PARAM_REQ *msg = NULL;
	int headerSize = sizeof(HWAPI_MSG_HEADER);
	dxErrCode err;

	LOG_API_ENTRANCE(("[HAPI_ParamGet] hChip:%p\n", hChip));

	// construct message
	msg = (HWAPI_MSG_GET_PARAM_REQ *)MemAllocFromHeap(__FILE__, __LINE__,  sizeof(HWAPI_MSG_GET_PARAM_REQ));
	if(msg == NULL)
		return HAPI_ERR_MEMORY;
	
	msg->header.msgTag= HAPI_MSG_TAG;
	msg->header.msgVersion = HAPI_MSG_VERSION;
	msg->header.type = HWAPI_MESSAGE_GET_PARAM_REQ;
	msg->header.payloadSize = sizeof(HWAPI_MSG_GET_PARAM_REQ) - headerSize;
	msg->bitMask = 0xffffffff;
	msg->index = param->index;
	msg->ParamType = param->ParamType;
	msg->checkCode = CRC32((unsigned char*)msg, headerSize + msg->header.payloadSize - 4);
	
	handle->userCmdResponseCode = HWAPI_MSG_RSP_FAIL;
	UtilSemTakeDbg(handle->sendAndWaitQueueSem, INFINITE, __LINE__);
	if(HAPIEnQueue(handle->sendAndWaitQueue, (QueueItem)msg)==1)
	{
    	DbgLogError(("HAPI_ParamGet() HAPIEnQueue failed @line=%d\n", __LINE__));
		MemFree2Heap(__FILE__, __LINE__, msg); 
		msg = NULL;
		UtilSemGive(handle->sendAndWaitQueueSem);
		return HAPI_FAIL;
	}
	UtilSemGive(handle->sendAndWaitQueueSem);
	
	// wait for response
	err = UtilSemTakeDbg(handle->userCmdSem,USER_CMD_TIME_OUT + 500, __LINE__);

	if(err == DX_SUCCESS
		&& handle->userCmdResponseCode == HWAPI_MSG_RSP_PASS)
	{
		memcpy((void *)param, (void *)&handle->GetParam, sizeof(HAPI_GET_PARAM));
		return HAPI_SUCCESS;
	}
	else
	{
		DbgLogError(("HWAPI_MESSAGE_GET_PARAM_REQ fail!!! sem err:%d, rspCode:0x%08x\n", err, handle->userCmdResponseCode));
		return HAPI_FAIL;
	}
}

HapiErrCode HAPI_Start (HAPIHandle hChip, Uint32 channel)
{
    HAPIHandler handle = (HAPIHandler)hChip;
	HWAPI_MSG_START *msg = NULL;
	int headerSize = sizeof(HWAPI_MSG_HEADER);
	dxErrCode err;

	LOG_API_ENTRANCE(("[HAPI_Start] hChip:%p channel:%d\n", handle, channel));
/*
	if (handle->state != HAPI_STATE_INIT)
	{
		DbgLogError(("%s() It is called in %d state!!!\n", __FUNCTION__, handle->state));
		return HAPI_FAIL;
	}
*/
	// construct message
	msg = (HWAPI_MSG_START *)MemAllocFromHeap(__FILE__, __LINE__,  sizeof(HWAPI_MSG_START));
	if(msg == NULL)
		return HAPI_ERR_MEMORY;

	msg->header.msgTag= HAPI_MSG_TAG;
	msg->header.msgVersion = HAPI_MSG_VERSION;
	msg->header.type = HWAPI_MESSAGE_START;
	msg->header.payloadSize = sizeof(HWAPI_MSG_START) - headerSize;
	msg->index = channel;
	msg->bitMask = 0xffffffff;
	msg->checkCode = CRC32((unsigned char *)msg, headerSize + msg->header.payloadSize - 4);
#ifdef HAUPPAUGE
	msg->encryptionEnable = 0; //FGR - BUGBUG was never set, might be non-0, but does it do anything??
#endif

	handle->userCmdResponseCode = HWAPI_MSG_RSP_FAIL;

#ifdef HAUPPAUGE
	usb_config_st *pUsbConfig = (usb_config_st*)handle->cmdBus->device;
	USBBootMChip_t *p_mchip = pUsbConfig->p_mchip;
	p_mchip->setSBPtimeout(1100); //improve reliablity when encoder is running
#endif

	UtilSemTakeDbg(handle->sendAndWaitQueueSem, INFINITE, __LINE__);
	if(HAPIEnQueue(handle->sendAndWaitQueue, (QueueItem)msg)==1)
	{
		DbgLogError(("HAPI_Start() HAPIEnQueue failed @line=%d\n", __LINE__));
		MemFree2Heap(__FILE__, __LINE__, msg); 
		msg = NULL;
		UtilSemGive(handle->sendAndWaitQueueSem);
		return HAPI_FAIL;
	}
	UtilSemGive(handle->sendAndWaitQueueSem);

	// wait for response
	err = UtilSemTakeDbg(handle->userCmdSem,USER_CMD_TIME_OUT + 500, __LINE__);

	if(err == DX_SUCCESS
		&& handle->userCmdResponseCode == HWAPI_MSG_RSP_PASS)
	{
	    LOG_INFO(("HAPI_Start returns OK\n"));
		handle->state = HAPI_STATE_START;
		return HAPI_SUCCESS;
	}
	else
	{
		DbgLogError(("HWAPI_MESSAGE_START fail!!! sem err:%d, rspCode:0x%08x\n", err, handle->userCmdResponseCode));
		return HAPI_FAIL;
	}
}


HapiErrCode HAPI_Stop (HAPIHandle hChip, Uint32 channel)
{
    HAPIHandler handle = (HAPIHandler)hChip;
	HWAPI_MSG_STOP *msg = NULL;
	int headerSize = sizeof(HWAPI_MSG_HEADER);
	dxErrCode err;

	LOG_API_ENTRANCE(("[HAPI_Stop] hChip:%p channel:%d\n", handle, channel));

 /*
	if (handle->state != HAPI_STATE_START)
	{
		DbgLogError(("%s() It is called in %d state!!!\n", __FUNCTION__, handle->state));
		return HAPI_FAIL;
	}
*/	
	// construct message
	msg = (HWAPI_MSG_STOP *)MemAllocFromHeap(__FILE__, __LINE__,  sizeof(HWAPI_MSG_STOP));
	if(msg == NULL)
		return HAPI_ERR_MEMORY;
	
	msg->header.msgTag= HAPI_MSG_TAG;
	msg->header.msgVersion = HAPI_MSG_VERSION;
	msg->header.type = HWAPI_MESSAGE_STOP;
	//msg->header.cookie = handle->cookie++;
	msg->header.payloadSize = sizeof(HWAPI_MSG_STOP) - headerSize;
	msg->index = channel;
	msg->bitMask = 0xffffffff;
	msg->checkCode = CRC32((unsigned char*)msg, headerSize + msg->header.payloadSize - 4);
	
	handle->state = HAPI_STATE_INIT;

	handle->userCmdResponseCode = HWAPI_MSG_RSP_FAIL;
	UtilSemTakeDbg(handle->sendAndWaitQueueSem, INFINITE, __LINE__);
	if(HAPIEnQueue(handle->sendAndWaitQueue, (QueueItem)msg)==1)
	{
		DbgLogError(("HAPI_Stop() HAPIEnQueue failed @line=%d\n", __LINE__));
		MemFree2Heap(__FILE__, __LINE__, msg); 
		msg = NULL;
		UtilSemGive(handle->sendAndWaitQueueSem);
		return HAPI_FAIL;
	}
	UtilSemGive(handle->sendAndWaitQueueSem);
	
	// wait for response
	err = UtilSemTakeDbg(handle->userCmdSem,USER_CMD_TIME_OUT + 500, __LINE__);

#ifdef HAUPPAUGE
	usb_config_st *pUsbConfig = (usb_config_st*)handle->cmdBus->device;
	USBBootMChip_t *p_mchip = pUsbConfig->p_mchip;
	p_mchip->setSBPtimeout(250); //improve responsiveness when encoder is stopped
#endif

	if(err == DX_SUCCESS
		&& handle->userCmdResponseCode == HWAPI_MSG_RSP_PASS)
	{
	    LOG_INFO(("HAPI_Stop completed\n"));
		return HAPI_SUCCESS;
	}
	else
	{
		DbgLogError(("HWAPI_MESSAGE_STOP fail!!! sem err:%d, rspCode:0x%08x\n", err, handle->userCmdResponseCode));
		return HAPI_FAIL;
	}
}
HapiErrCode HAPI_AVDataCallbackInstall(HAPIHandle hChip, HAPI_AV_CALLBACK_FUNC *func)
{
    HAPIHandler handle = (HAPIHandler)hChip;

	LOG_API_ENTRANCE(("[HAPI_AVDataCallbackInstall] hChip:%p avDataSend:%p, avDataReceive:%p\n", 
					handle, func->avDataSend, func->avDataReceive));

	if(func == NULL || func->avDataSend == NULL || func->avDataReceive == NULL)
		return HAPI_ERR_PARAMETER;

	handle->dataSend = func->avDataSend;
	handle->dataReceive = func->avDataReceive;

	return HAPI_SUCCESS;
}

HapiErrCode HAPI_Exit(HAPIHandle hChip)
{
    HAPIHandler handle = (HAPIHandler)hChip;

#ifndef HAUPPAUGE
	HWAPI_MSG_EXIT *msg = NULL;
	int headerSize = sizeof(HWAPI_MSG_HEADER);
#endif

	dxErrCode err;
#ifdef DRIVER_BUILD//HAUPPAUGE
	HapiErrCode ret_code = HAPI_SUCCESS;
#endif

	LOG_API_ENTRANCE(("[HAPI_Exit] hChip:%p \n", handle));
/*
	if (handle->state != HAPI_STATE_INIT)
	{
		DbgLogError(("%s() It is called in %d state!!!\n", __FUNCTION__, handle->state));
		return HAPI_FAIL;
	}
*/	
#ifdef HAUPPAUGE
	//FGR - we are going to power off the device now, I don't think we need to give it a heads up
	handle->userCmdResponseCode = HWAPI_MSG_RSP_FAIL;
	handle->state = HAPI_STATE_IDLE;
	
	ret_code = HAPI_FAIL;
	goto clean_up;
#else

	// construct message
	msg = (HWAPI_MSG_EXIT *)MemAllocFromHeap(__FILE__, __LINE__,  sizeof(HWAPI_MSG_EXIT));
	if(msg == NULL)
		return HAPI_ERR_MEMORY;

	memset(msg, 0, sizeof(HWAPI_MSG_EXIT)); //TODO: Check the value of msg->index (=channel) ???
	msg->header.msgTag= HAPI_MSG_TAG;
	msg->header.msgVersion = HAPI_MSG_VERSION;
	msg->header.type = HWAPI_MESSAGE_EXIT;
	msg->header.payloadSize = sizeof(HWAPI_MSG_EXIT) - headerSize;
	msg->bitMask = 0xffffffff;
	msg->checkCode = CRC32((unsigned char*)msg, headerSize + msg->header.payloadSize - 4);

	handle->userCmdResponseCode = HWAPI_MSG_RSP_FAIL;

	handle->state = HAPI_STATE_IDLE;

	UtilSemTakeDbg(handle->sendAndWaitQueueSem, INFINITE, __LINE__);
	if(HAPIEnQueue(handle->sendAndWaitQueue, (QueueItem)msg)==1)
	{
		DbgLogError(("HAPI_Exit() HAPIEnQueue failed @line=%d\n", __LINE__));
		MemFree2Heap(__FILE__, __LINE__, msg); 
		msg = NULL;
		UtilSemGive(handle->sendAndWaitQueueSem);
		ret_code = HAPI_FAIL;
		goto clean_up;//FGR Bugfix
	}
	UtilSemGive(handle->sendAndWaitQueueSem);

	// wait for response
	err = UtilSemTakeDbg(handle->userCmdSem,4000, __LINE__);

	if(err != DX_SUCCESS
		||handle->userCmdResponseCode != HWAPI_MSG_RSP_PASS)
	{
		DbgLogError(("HWAPI_MESSAGE_EXIT fail!!! sem err:%d, rspCode:0x%08x\n", err, handle->userCmdResponseCode));
		ret_code = HAPI_FAIL;//fall into cleanup below
	}
#endif

#ifdef DRIVER_BUILD
clean_up:
	if(ret_code == HAPI_FAIL){
		//FGR - we will flush the pending data, and we want(need) to contiue freeing reesources
		UtilSemTakeDbg(handle->sendAndWaitQueueSem, INFINITE, __LINE__);
		HAPIFlushQueue(handle->sendAndWaitQueue);
		UtilSemGive(handle->sendAndWaitQueueSem);
	}
#endif

#ifndef DRIVER_BUILD
	LOG_INFO(("clean up...\n"));
#else
	DbgLogInfo(("Stopping threads ...\n"));
#endif

	handle->exitCmdThread = 1;
	handle->exitMainThread = 1;
	handle->exitCBThread = 1;
#ifndef AV_ASI
	handle->exitDataThread = 1;
	handle->exitWriteThread = 1;
#endif

#ifndef DRIVER_BUILD
    UtilSleep(3000);
#else
    UtilSleep(300); //FGR - this was HUGE(3000) is 300 even needed!!
#endif


	UtilThreadStop(&handle->cmdThread);
	UtilThreadStop(&handle->mainThread);
	UtilThreadStop(&handle->callbackThread);
#ifndef AV_ASI
 #ifndef HAUPPAUGE
	UtilThreadStop(&handle->dataThread);
 #else
	//FGR - why have two threads using the same underlying USB interface
	if(handle->cmdBus != handle->dataBus)
	{
		UtilThreadStop(&handle->dataThread);
	}
 #endif
 #ifdef USE_WRITE_THREAD
	UtilThreadStop(&handle->writeThread);
 #endif
#endif


	HAPIDestroyQueue(handle->sendQueue);
	HAPIDestroyQueue(handle->sendAndWaitQueue);
	HAPIDestroyQueue(handle->receiveQueue);
	//HAPIDestroyQueue(handle->waitResponseQueue);
	HAPIDestroyQueue(handle->callbackQueue);

	UtilSemDestroy(&handle->sendQueueSem);
	UtilSemDestroy(&handle->sendAndWaitQueueSem);
	UtilSemDestroy(&handle->receiveQueueSem);
	//UtilSemDestroy(&handle->waitResponseQueueSem);
	UtilSemDestroy(&handle->cbQueueSem);


    handle->cmdBus->IF.exit(handle->cmdBus->device);

    UtilSemDestroy(&handle->cmdBusSem);
#ifndef AV_ASI    
	if(handle->cmdBus != handle->dataBus)
	{
		handle->dataBus->IF.exit(handle->dataBus->device);
		UtilSemDestroy(&handle->dataBusSem);
	}
	handle->cmdBus->device = NULL;
	handle->dataBus->device = NULL;
#endif

#ifdef HAUPPAUGE
    UtilSemDestroy(&handle->userCmdSem); //FGR - fix resource leak;

	memset(handle, 0xfe, sizeof(_HAPIStruct)); 
#endif

	MemFree2Heap(__FILE__, __LINE__, handle);

#ifndef DRIVER_BUILD
	return HAPI_SUCCESS;
#else
	return ret_code;
#endif
}
