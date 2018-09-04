//=============================================================================
//  File Name: SwapEndian.c
//
//  Copyright 2010 Magnum Semiconductor Inc. All rights reserved.
//
//  Description:
//      switch big endian and little endian.
//
//
//=============================================================================

#include "Hapi.h"
#include "HapiBaseType.h"
#include "SwapEndian.h"

#ifdef DRIVER_BUILD
inline void do_SWAP16(unsigned char *p_value)
{
	unsigned char tmp = p_value[0];
	p_value[0] = p_value[1];
	p_value[1] = tmp;
}

inline void do_SWAP32(unsigned char *p_value)
{
	unsigned char tmp = p_value[0];
	p_value[0] = p_value[3];
	p_value[3] = tmp;
	
	tmp = p_value[1];
	p_value[1] = p_value[2];
	p_value[2] = tmp;

}
#endif

Uint64 SWAP64(Uint64 ull)
{
#ifndef DRIVER_BUILD
        ull =(         (ull <<56) |(ull>>56) | 
        ((ull<<40) & 0x00FF000000000000ULL) | ((ull>>40) & 0x000000000000FF00ULL) | 
        ((ull<<24) & 0x0000FF0000000000ULL) | ((ull>>24) & 0x0000000000FF0000ULL) | 
        ((ull<<8) & 0x000000FF00000000ULL) | ((ull>>8) & 0x00000000FF000000ULL)    ); 
#else
		unsigned char *p_value = (unsigned char *)&ull;
		unsigned char tmp = p_value[0];
		p_value[0] = p_value[7];
		p_value[7] = tmp;
		
		tmp = p_value[1];
		p_value[1] = p_value[6];
		p_value[6] = tmp;

		tmp = p_value[2];
		p_value[2] = p_value[5];
		p_value[5] = tmp;

		tmp = p_value[3];
		p_value[3] = p_value[4];
		p_value[4] = tmp;

#endif
		return ull;
}

void swapHeader(HWAPI_MSG_HEADER *pHeader)
{
  //printf("swapHeader\n");
  SWAP32(pHeader->msgTag);
  SWAP32(pHeader->msgVersion);
  SWAP32(pHeader->type);
  //printf("swapped type:%d\n", pHeader->type);
  SWAP32(pHeader->cookie);
  SWAP32(pHeader->payloadSize);
  SWAP32(pHeader->responseCode);
  SWAP32(pHeader->reserved1);
  SWAP32(pHeader->reserved2);
}

void swapXCODE_VIDEO_PARAMS(XCODE_VIDEO_PARAMS *pMsg)
{
	SWAP32(pMsg->bitMask);
	SWAP32(pMsg->CodingMode);
	SWAP32(pMsg->OutputPID);
	SWAP32(pMsg->RateControl);
	SWAP32(pMsg->StreamID);
	SWAP32(pMsg->VideoCodecInputFormat);
	SWAP32(pMsg->VideoCodecOutputFormat);
	SWAP32(pMsg->VideoOutputBitrate);
	SWAP32(pMsg->VideoOutputFrameRate);
	SWAP32(pMsg->VideoOutputHeight);
	SWAP32(pMsg->VideoOutputMode);
	SWAP32(pMsg->VideoOutputWidth);
	SWAP32(pMsg->VBRMin);
	SWAP32(pMsg->VBRMax);
	SWAP32(pMsg->Profile);
	SWAP32(pMsg->Level);
	SWAP32(pMsg->TSBitrate);
	SWAP32(pMsg->Latency);
    SWAP32(pMsg->bCabacCoding);
    SWAP32(pMsg->bDeblockFilter);
    SWAP32(pMsg->bInsertIFrame);
    SWAP16(pMsg->NumBFrames);
    SWAP32(pMsg->bIasIDR);
    SWAP32(pMsg->PMTVersion);
	SWAP32(pMsg->bAdaptiveSmoothing);
	SWAP32(pMsg->HorizontalSmoothingOffset);
	SWAP32(pMsg->VerticalSmoothingOffset);
	SWAP32(pMsg->GOPSize);
}

void swapENCODE_VIDEO_PARAMS(ENCODE_VIDEO_PARAMS *pMsg)
{
	SWAP32(pMsg->bitMask);
	SWAP32(pMsg->CodingMode);
	SWAP32(pMsg->Latency);
	SWAP32(pMsg->Level);
	SWAP32(pMsg->OutputPID);
	SWAP32(pMsg->Profile);
	SWAP32(pMsg->RateControl);
	SWAP32(pMsg->StreamID);
	SWAP32(pMsg->TSBitrate);
	SWAP32(pMsg->VBRMax);
	SWAP32(pMsg->VBRMin);
	SWAP32(pMsg->VideoCapFormat);
	SWAP32(pMsg->VideoCapFrameRate);
	SWAP32(pMsg->VIdeoCapHeight);
	SWAP32(pMsg->VideoCapWidth);
	SWAP32(pMsg->VideoCapSource);
	SWAP32(pMsg->VideoCodecOutputFormat);
	SWAP32(pMsg->VideoOutputBitrate);
	SWAP32(pMsg->VideoOutputFrameRate);
	SWAP32(pMsg->VideoOutputHeight);
	SWAP32(pMsg->VideoOutputWidth);
	SWAP32(pMsg->VideoOutputMode);
	SWAP32(pMsg->bCabacCoding);
	SWAP32(pMsg->bDeblockFilter);
	SWAP32(pMsg->bInsertIFrame);
	SWAP16(pMsg->NumBFrames);
    SWAP32(pMsg->bIasIDR);	
    SWAP32(pMsg->PMTVersion);
	SWAP32(pMsg->bAdaptiveSmoothing);
	SWAP32(pMsg->HorizontalSmoothingOffset);
	SWAP32(pMsg->VerticalSmoothingOffset);
	SWAP32(pMsg->GOPSize);
}

void swapXCODE_AUDIO_PARAMS(XCODE_AUDIO_PARAMS *pMsg)
{
	SWAP32(pMsg->StreamID);
	SWAP32(pMsg->OutputPID);
	SWAP32(pMsg->AudioCodecInputFormat);
	SWAP32(pMsg->AudioCodecOutputFormat);
	SWAP32(pMsg->AudioOutputBitrate);
	SWAP32(pMsg->AudioOutputMode);
	SWAP32(pMsg->AudioOutputSamplingRate);
	SWAP32(pMsg->bAudioPassthru);
	SWAP32(pMsg->bitMask);
	SWAP32(pMsg->bAGCEnable);
	SWAP16(pMsg->MaxSample);
}

void swapENCODE_AUDIO_PARAMS(ENCODE_AUDIO_PARAMS *pMsg)
{
	SWAP32(pMsg->StreamID);
	SWAP32(pMsg->OutputPID);
    
	SWAP32(pMsg->StreamID_1);
	SWAP32(pMsg->OutputPID_1);
    
	SWAP32(pMsg->AudioCapMode);
    SWAP32(pMsg->AudioCapMode_1);
        
	SWAP32(pMsg->AudioCapSampleRate);
	SWAP32(pMsg->AudioCapSource);
	SWAP32(pMsg->AudioCapSPDIFInput);
	SWAP32(pMsg->AudioCodecOutputFormat);
	SWAP32(pMsg->AudioOutputBitrate);
	SWAP32(pMsg->AudioOutputMode);
	SWAP32(pMsg->AudioOutputSamplingRate);

    SWAP32(pMsg->AudioCodecOutputFormat_1);
	SWAP32(pMsg->AudioOutputBitrate_1);
	SWAP32(pMsg->AudioOutputMode_1);
	SWAP32(pMsg->AudioOutputSamplingRate_1);

	SWAP32(pMsg->bAudioPassthru);
    SWAP32(pMsg->bAudioPassthru_1);
	SWAP32(pMsg->bitMask);
	SWAP32(pMsg->bAGCEnable);
	SWAP16(pMsg->MaxSample);
}


void swapSYS_LOG_PARAMS(SYS_LOG_PARAMS *pMsg)
{
	//SWAP32(pMsg->activityLoggingEnable);
	SWAP32(pMsg->bitMask);
	SWAP32(pMsg->errorLoggingEnable);
	//SWAP32(pMsg->errorPrintingEnable);
}

void swapHAPI_TRANSCODE_PARAMS(HAPI_TRANSCODE_PARAMS *pMsg)
{
	swapXCODE_AUDIO_PARAMS(&pMsg->AudioParams);
	swapXCODE_VIDEO_PARAMS(&pMsg->VideoParams);
	swapSYS_LOG_PARAMS(&pMsg->LogParams);
	SWAP32(pMsg->bitMask);
}

void swapHAPI_ENCODE_PARAMS(HAPI_ENCODE_PARAMS *pMsg)
{
	swapENCODE_AUDIO_PARAMS(&pMsg->AudioParams);
	swapENCODE_VIDEO_PARAMS(&pMsg->VideoParams);
	swapSYS_LOG_PARAMS(&pMsg->LogParams);
	SWAP32(pMsg->bitMask);
}

void swapHAPI_Param(HAPI_GET_PARAM *pMsg, Uint32 direction)
{
	Uint32 paramType;

	if(direction == 0)
	{
		paramType = pMsg->ParamType;
	}
	else
	{
		paramType = pMsg->ParamType;
		SWAP32(paramType);
	}

	SWAP32(pMsg->bitMask);
	SWAP32(pMsg->index);
	SWAP32(pMsg->InputAudioPID);
	SWAP32(pMsg->InputVideoPID);
	SWAP32(pMsg->InputPCRPID);
	SWAP32(pMsg->SubtitlePID);
	SWAP32(pMsg->TeletextPID);
	SWAP32(pMsg->OutputPCRPID);
	SWAP32(pMsg->bTSSerial);
	SWAP32(pMsg->bChMsbFirst);

	if(paramType == HAPI_SET_PARAM_TYPE_TRANSCODER) // transcoding param
	{
	    swapHAPI_TRANSCODE_PARAMS(&pMsg->params.transcodeParam);
	}
	else if(paramType == HAPI_SET_PARAM_TYPE_ENCODER) // encode param
	{
	    swapHAPI_ENCODE_PARAMS(&pMsg->params.encodeParam);
	}

	SWAP32(pMsg->ParamType);
}

void swapSET_PARAM(HWAPI_MSG_SET_PARAM *pMsg, Uint32 direction)
{
	//SWAP32(pMsg->bitMask);
	SWAP32(pMsg->checkCode);
	swapHAPI_Param((HAPI_SET_PARAM*)&pMsg->param, direction);
}

void swapGET_PARAM_RSP(HWAPI_MSG_GET_PARAM_RSP *pMsg, Uint32 direction)
{
	SWAP32(pMsg->bitMask);
	SWAP32(pMsg->checkCode);
	SWAP32(pMsg->errCode);
	swapHAPI_Param((HAPI_GET_PARAM*)&pMsg->param, direction);
}

void swapGET_PARAM_REQ(HWAPI_MSG_GET_PARAM_REQ *pMsg)
{
	SWAP32(pMsg->bitMask);
	SWAP32(pMsg->checkCode);
	SWAP32(pMsg->index);
	SWAP32(pMsg->ParamType);
}

void swapSET_PARAM_RSP(HWAPI_MSG_SET_PARAM_RSP* pMsg)
{
	//SWAP32(pMsg->bitMask);
	SWAP32(pMsg->checkCode);
	SWAP32(pMsg->errCode);
}

void swapSTART(HWAPI_MSG_START* pMsg)
{
	SWAP32(pMsg->bitMask);
	SWAP32(pMsg->checkCode);
	SWAP32(pMsg->encryptionEnable);
	SWAP32(pMsg->index);
}

void swapSTART_RSP(HWAPI_MSG_START_RSP* pMsg)
{
	SWAP32(pMsg->bitMask);
	SWAP32(pMsg->checkCode);
	SWAP32(pMsg->errCode);
	SWAP32(pMsg->index);
}

void swapSTOP(HWAPI_MSG_STOP* pMsg)
{
	SWAP32(pMsg->bitMask);
	SWAP32(pMsg->checkCode);
	SWAP32(pMsg->index);
}

void swapSTOP_RSP(HWAPI_MSG_STOP_RSP* pMsg)
{
	SWAP32(pMsg->bitMask);
	SWAP32(pMsg->checkCode);
	SWAP32(pMsg->errCode);
}

void swapINIT(HWAPI_MSG_INIT* pMsg)
{
	SWAP32(pMsg->bitMask);
	SWAP32(pMsg->checkCode);
	SWAP32(pMsg->inAudioPort);
	SWAP32(pMsg->index);
	SWAP32(pMsg->inVideoPort);
	SWAP32(pMsg->outAudioPort);
	SWAP32(pMsg->outVideoPort);
}

void swapINIT_RSP(HWAPI_MSG_INIT_RSP* pMsg)
{
	SWAP32(pMsg->bitMask);
	SWAP32(pMsg->BuildVersion);
	SWAP32(pMsg->checkCode);
	SWAP32(pMsg->MajorVer);
	SWAP32(pMsg->MinorVer);
	SWAP32(pMsg->ProductID);
}

void swapEXIT(HWAPI_MSG_EXIT* pMsg)
{
	SWAP32(pMsg->bitMask);
	SWAP32(pMsg->checkCode);
	SWAP32(pMsg->index);
}

void swapEXIT_RSP(HWAPI_MSG_EXIT_RSP* pMsg)
{
	SWAP32(pMsg->bitMask);
	SWAP32(pMsg->checkCode);
}

void swapSTREAM_INPUT_DATA(HWAPI_MSG_STREAM_INPUT_DATA* pMsg)
{
	SWAP32(pMsg->bitMask);
	SWAP32(pMsg->dataLength);
}

void swapSTREAM_INPUT_DATA_RSP(HWAPI_MSG_STREAM_INPUT_DATA_RSP* pMsg)
{
	SWAP32(pMsg->bitMask);
	SWAP32(pMsg->checkCode);
	SWAP32(pMsg->errCode);
}
void swapSTREAM_DATA_REQUEST(HWAPI_MSG_STREAM_DATA_REQUEST* pMsg)
{
	SWAP32(pMsg->bitMask);
	SWAP32(pMsg->checkCode);
	SWAP32(pMsg->dataLength);
}

void swapSTREAM_DATA_REQUEST_RSP(HWAPI_MSG_STREAM_DATA_REQUEST_RSP* pMsg)
{
	SWAP32(pMsg->bitMask);
	SWAP32(pMsg->checkCode);
	SWAP32(pMsg->dataLength);
}

void swapSTREAM_OUTPUT_DATA(HWAPI_MSG_STREAM_OUTPUT_DATA* pMsg)
{
	SWAP32(pMsg->bitMask);
	SWAP32(pMsg->dataLength);
}

void swapSTREAM_OUTPUT_DATA_RSP(HWAPI_MSG_STREAM_OUTPUT_DATA_RSP* pMsg)
{
	SWAP32(pMsg->bitMask);
	SWAP32(pMsg->checkCode);
	SWAP32(pMsg->errorCode);
}

void swapAV_UPDATE(HWAPI_MSG_AV_UPDATE* pMsg)
{
    SWAP32(pMsg->bitMask);
    SWAP32(pMsg->checkCode);

    SWAP32(pMsg->inVideoWidth);
    SWAP32(pMsg->inVideoHeight);
    SWAP32(pMsg->outVideoWidth);
    SWAP32(pMsg->outVideoHeight);
    SWAP32(pMsg->inFrameRate);
    SWAP32(pMsg->outFrameRate);
    SWAP32(pMsg->inVideoBitRate);
    SWAP32(pMsg->outVideoBitRate);
    SWAP32(pMsg->inAudioSampleRate);
    SWAP32(pMsg->outAudioSampleRate);
    SWAP32(pMsg->inAudioBitRate);
    SWAP32(pMsg->outAudioBitRate);

}



void swapFW_UPDATE(HWAPI_MSG_FWUPGRADE* pMsg)
{
	DbgLogTrace(("Target addr=%x  length=%d\n",pMsg->addr,pMsg->length));

	SWAP32(pMsg->bitMask);
	SWAP32(pMsg->index);
	SWAP32(pMsg->addr);
	SWAP32(pMsg->length);
	SWAP32(pMsg->checkCode);
}

void swapFW_UPDATE_RSP(HWAPI_MSG_FWUPGRADE_RSP* pMsg)
{
	SWAP32(pMsg->index);
	SWAP32(pMsg->bitMask);
	SWAP32(pMsg->checkCode);
}

void swapHAPI_AVL_SUPPORT(HAPI_AVL_SUPPORT *pMsg)
{
    switch(pMsg->type)
    {
        case HAPI_AVL_DEVICE_CTRL_TYPE_I2C:
            SWAP32(pMsg->ctrl.i2c.bus);
            SWAP32(pMsg->ctrl.i2c.addr);
            break;
        case HAPI_AVL_DEVICE_CTRL_TYPE_SPI:
            SWAP32(pMsg->ctrl.spi.cs);
            SWAP32(pMsg->ctrl.spi.gpio);
            break;
        case HAPI_AVL_DEVICE_CTRL_TYPE_GPIO:
        default:
            break;
    }

    SWAP32(pMsg->dev);
    SWAP32(pMsg->type);
}

void swapHAPI_SET_AVL_PARAM(HAPI_SET_AVL_PARAM *pMsg)
{
    int i;

    for(i=0;i<pMsg->nDevs;i++)
    {
        swapHAPI_AVL_SUPPORT(&pMsg->avlDev[i]);
    }
    SWAP16(pMsg->nDevs);
    SWAP16(pMsg->i2cBus);
    SWAP16(pMsg->gpioSCL);
    SWAP16(pMsg->gpioSDA);
}
    
void swapSET_AVL(HWAPI_MSG_SET_AVL *pMsg)
{
    SWAP32(pMsg->checkCode);
    swapHAPI_SET_AVL_PARAM(&pMsg->avl);
}

void swapSET_AVL_RSP(HWAPI_MSG_SET_AVL_RSP* pMsg)
{
    SWAP32(pMsg->errCode);
    SWAP32(pMsg->checkCode);
}

void swapHAPI_LOGO_CONFIG_PARAM(HAPI_LOGO_CONFIG_PARAM *param)
{
    SWAP32(param->chIndex);
    SWAP32(param->logoIndex);
    SWAP32(param->width);
    SWAP32(param->height);
    SWAP32(param->x);
    SWAP32(param->y);
}
void swapLOGO_CONFIG(HWAPI_MSG_LOGO_CONFIG* pMsg)
{
    swapHAPI_LOGO_CONFIG_PARAM(&pMsg->param);
    SWAP32(pMsg->checkCode);
}
void swapLOGO_CONFIG_RSP(HWAPI_MSG_LOGO_CONFIG_RSP* pMsg)
{
    SWAP32(pMsg->checkcode);
    SWAP32(pMsg->errorCode);
}

void  swapLOGO_ON_OFF(HWAPI_MSG_LOGO_ON_OFF* pMsg)
{
    SWAP32(pMsg->chIndex);
    SWAP16(pMsg->logoIndex);
    SWAP16(pMsg->on);    
    SWAP32(pMsg->checkCode);
}

void swapLOGO_ON_OFF_RSP(HWAPI_MSG_LOGO_ON_OFF_RSP* pMsg)
{
    SWAP32(pMsg->checkcode);
    SWAP32(pMsg->errorCode);
}
void swapSET_I2C_READ_PARAM(HAPI_I2C_READ_PARAM *pMsg)
{
    SWAP16(pMsg->addr);
    SWAP16(pMsg->subAddrLen);
    SWAP16(pMsg->datalen);
}

void swapSET_I2C_READ(HWAPI_MSG_I2C_READ *pMsg)
{
    SWAP32(pMsg->checkCode);
    swapSET_I2C_READ_PARAM(&(pMsg->param));
}

void swapSET_I2C_READ_RSP(HWAPI_MSG_I2C_READ_RSP*pMsg)
{
    SWAP32(pMsg->checkCode);
    SWAP32(pMsg->errCode);
    swapSET_I2C_READ_PARAM(&(pMsg->param));
}
void swapSET_I2C_WRITE_PARAM(HAPI_I2C_WRITE_PARAM *pMsg)
{
    SWAP16(pMsg->addr);
    SWAP16(pMsg->subAddrLen);
    SWAP16(pMsg->datalen);
}

void swapSET_I2C_WRITE(HWAPI_MSG_I2C_WRITE *pMsg)
{
    SWAP32(pMsg->checkCode);
    swapSET_I2C_WRITE_PARAM(&(pMsg->param));
}
void swapSET_I2C_WRITE_RSP(HWAPI_MSG_I2C_WRITE_RSP *pMsg)
{
    SWAP32(pMsg->errCode);
    SWAP32(pMsg->checkCode);
}

void swapSET_GPIO_READ(HWAPI_MSG_GPIO_READ *pMsg)
{
    SWAP32(pMsg->pin);
    SWAP32(pMsg->checkCode);
}
void swapSET_GPIO_READ_RSP(HWAPI_MSG_GPIO_READ_RSP *pMsg)
{
    SWAP32(pMsg->Val);
    SWAP32(pMsg->checkCode);
    SWAP32(pMsg->errCode);
}

void swapSET_GPIO_WRITE(HWAPI_MSG_GPIO_WRITE *pMsg)
{
    SWAP32(pMsg->pin);
    SWAP32(pMsg->val);
    SWAP32(pMsg->checkCode);
}
void swapSET_GPIO_WRITE_RSP(HWAPI_MSG_I2C_WRITE_RSP *pMsg)
{
    SWAP32(pMsg->errCode);
    SWAP32(pMsg->checkCode);
}

void swapSET_I2C_CLOCK_FREQ(HWAPI_MSG_I2C_CLOCK_FREQ *pMsg)
{
    SWAP32(pMsg->checkCode);
    SWAP16(pMsg->f_khz);
}

void swapSET_I2C_CLOCK_FREQ_RSP(HWAPI_MSG_I2C_CLOCK_FREQ_RSP* pMsg)
{
    SWAP32(pMsg->checkCode);
    SWAP32(pMsg->errCode);
}

void swapI2C_MONITOR_INSTALL_PARAM(HAPI_I2C_MONITOR_PARAM *pMsg)
{
    int i;
    SWAP16(pMsg->addr);
    SWAP16(pMsg->subAddrLen);
    SWAP16(pMsg->dataLen);
    SWAP32(pMsg->mask);
    SWAP32(pMsg->numMonitoredVal);
    SWAP32(pMsg->ch);

    for(i=0;i<4;i++)
    SWAP32(pMsg->monitoredValues[i]);

    SWAP32(pMsg->action);
   // SWAP32((Uint32)pMsg->Callback);
    
}
void swapI2C_MONITOR_INSTALL(HWAPI_MSG_I2C_MONITOR_INSTALL *pMsg)
{
    SWAP32(pMsg->checkcode);
    swapI2C_MONITOR_INSTALL_PARAM(&(pMsg->param));
    SWAP32(pMsg->monitorNum);
}

void swapI2C_MONITOR_INSTALL_RSP(HWAPI_MSG_I2C_MONITOR_INSTALL_RSP *pMsg)
{
    SWAP32(pMsg->checkCode);
    SWAP32(pMsg->errCode);
}

void swapI2C_MONITOR_I2C_CALLBACK_PARAM(HAPI_I2C_CALLBACK_PARAM *pMsg)
{
    SWAP16(pMsg->addr);
    SWAP16(pMsg->subAddrLen);
    SWAP16(pMsg->dataLen);
    SWAP32(pMsg->action);
    SWAP32(pMsg->ch);
}
void swapI2C_MONITOR_OUTPUT_DATA(HWAPI_MSG_I2C_OUTPUT_MONITOR_DATA *pMsg)
{
    SWAP32(pMsg->checkcode);
    SWAP32(pMsg->monitorNum);
    swapI2C_MONITOR_I2C_CALLBACK_PARAM(&(pMsg->Param));
}

void swapSET_AR_DATA(HWAPI_MSG_AR_DATA *pMsg)
{
    SWAP32(pMsg->ar);
    SWAP32(pMsg->ch);
}

void swapSET_AR_DATA_RSP(HWAPI_MSG_AR_DATA_RSP *pMsg)
{
    SWAP32(pMsg->checkCode);
    SWAP32(pMsg->errCode);
}
void swapSET_PCR_DATA(HWAPI_MSG_PCR_DATA *pMsg)
{
    SWAP32(pMsg->pcrHigh);
    SWAP32(pMsg->pcrLow);
}

void swapSET_PCR_DATA_RSP(HWAPI_MSG_PCR_DATA_RSP *pMsg)
{
    SWAP32(pMsg->checkCode);
    SWAP32(pMsg->errCode);
}

void swap_MSG_ERR_UPDATE(HWAPI_MSG_ERR_UPDATE *pMsg)
{
    SWAP32(pMsg->errType);
    switch(pMsg->errType)
    {
        case HAPI_ERR_PROC_ASSERT:
            SWAP32(pMsg->params.assertErr.Reserved1);
            SWAP32(pMsg->params.assertErr.Reserved2);
            break;
        case HAPI_ERR_AUD_CODEC_MISMATCH:
            SWAP32(pMsg->params.audCodecMismatch.codecReceived);
            SWAP32(pMsg->params.audCodecMismatch.codecSelected);
            SWAP32(pMsg->params.audCodecMismatch.Reserved);
            break;
        case HAPI_ERR_AUD_LEVEL_ALARM:
            SWAP32(pMsg->params.audLevel.bOverflow);
            SWAP32(pMsg->params.audLevel.Reserved1);
            SWAP32(pMsg->params.audLevel.Reserved2);
            break;
        case HAPI_ERR_PCR_MISSING:
            SWAP32(pMsg->params.pcrMiss.pcrPID);
            SWAP32(pMsg->params.pcrMiss.Reserved1);
            SWAP32(pMsg->params.pcrMiss.Reserved2);
            break;
        case HAPI_ERR_UNSUPPORTED_CODEC:
            SWAP32(pMsg->params.unSupportedCodec.audCodec);
            SWAP32(pMsg->params.unSupportedCodec.vidCodec);
            SWAP32(pMsg->params.unSupportedCodec.Reserved);
            break;
         case HAPI_ERR_FRAME_COUNTER_0:
            SWAP32(pMsg->params.frCounter0.seconds);
            SWAP16(pMsg->params.frCounter0.vInCount);
            SWAP16(pMsg->params.frCounter0.vResCount);
            SWAP16(pMsg->params.frCounter0.vEncCount);
            SWAP32(pMsg->params.frCounter0.Reserved);
            break;
        default:
            break;
    }
}

void swap_MSG_STATUS_QUERY(HWAPI_MSG_QUERY_STATUS *pMsg)
{
    SWAP32(pMsg->status.index);
    SWAP32(pMsg->status.bitMask);
/*  no need to swap the values below. No outgoing value to DXT.
	SWAP32(pMsg->status.ar);
    pMsg->status.pcr = SWAP64(pMsg->status.pcr);
    SWAP32(pMsg->status.inFrameCount);
    SWAP32(pMsg->status.outFrameCount);
    SWAP16(pMsg->status.state);
    SWAP16(pMsg->status.frameRate);
*/
}


void swap_MSG_STATUS_QUERY_RSP(HWAPI_MSG_QUERY_STATUS_RSP *pMsg)
{
    SWAP32(pMsg->checkCode);
    SWAP32(pMsg->errorCode);
    SWAP32(pMsg->status.index);
    SWAP32(pMsg->status.bitMask);
    SWAP32(pMsg->status.ar);
    pMsg->status.pcr=SWAP64(pMsg->status.pcr);
    SWAP32(pMsg->status.inFrameCount);
    SWAP32(pMsg->status.outFrameCount);
    SWAP16(pMsg->status.state);
    SWAP16(pMsg->status.frameRate);
}    
//
// direction: 
//		0: from host to slave,
//		1: from slave to host
//
int swapMessage(HWAPI_MSG_HEADER * pHeader, int direction)
{
	HWAPI_MSG_TYPE type;

	if(direction == 0)
	{
		type = pHeader->type;
		swapHeader(pHeader);
	}
	else
	{
		swapHeader(pHeader);
		type = pHeader->type;
	}	
	switch(type)
	{
		case HWAPI_MESSAGE_SET_PARAM:
			if(direction == 0) // set param
				swapSET_PARAM((HWAPI_MSG_SET_PARAM*) pHeader, direction);
			else // set param rsp
				swapSET_PARAM_RSP((HWAPI_MSG_SET_PARAM_RSP*) pHeader);
			break;

		case HWAPI_MESSAGE_GET_PARAM_REQ:
			if(direction == 0) 
				swapGET_PARAM_REQ((HWAPI_MSG_GET_PARAM_REQ*)pHeader);
			else
			    swapGET_PARAM_RSP((HWAPI_MSG_GET_PARAM_RSP *)pHeader, direction);
			break;

		case HWAPI_MESSAGE_START:
			if(direction == 0) 
				swapSTART((HWAPI_MSG_START*)pHeader);
			else
				swapSTART_RSP((HWAPI_MSG_START_RSP*)pHeader);				
			break;

		case HWAPI_MESSAGE_STOP:
			if(direction == 0)
				swapSTOP((HWAPI_MSG_STOP *)pHeader);
			else
				swapSTOP_RSP((HWAPI_MSG_STOP_RSP*)pHeader);
			break;

		case HWAPI_MESSAGE_INIT:
			if(direction == 0)
				swapINIT((HWAPI_MSG_INIT*)pHeader);
			else
				swapINIT_RSP((HWAPI_MSG_INIT_RSP*) pHeader);	
			break;

		case HWAPI_MESSAGE_EXIT:
			if(direction == 0)
				swapEXIT((HWAPI_MSG_EXIT*) pHeader);
			else
				swapEXIT_RSP((HWAPI_MSG_EXIT_RSP*) pHeader);
			break;

		case HWAPI_MESSAGE_STREAM_INPUT_DATA:
			if(direction == 0)
				swapSTREAM_INPUT_DATA((HWAPI_MSG_STREAM_INPUT_DATA*) pHeader);
			else
				swapSTREAM_INPUT_DATA_RSP((HWAPI_MSG_STREAM_INPUT_DATA_RSP*) pHeader);
			break;

		case HWAPI_MESSAGE_ERROR:
			swap_MSG_ERR_UPDATE((HWAPI_MSG_ERR_UPDATE*) pHeader);
			break;

		case HWAPI_MESSAGE_STREAM_DATA_REQ:
			if(direction == 1)
				swapSTREAM_DATA_REQUEST((HWAPI_MSG_STREAM_DATA_REQUEST*) pHeader);		
			else
				swapSTREAM_DATA_REQUEST_RSP((HWAPI_MSG_STREAM_DATA_REQUEST_RSP*) pHeader);
			break;

		case HWAPI_MESSAGE_STREAM_OUTPUT_DATA:
			if(direction == 1)
				swapSTREAM_OUTPUT_DATA((HWAPI_MSG_STREAM_OUTPUT_DATA*) pHeader);
			else
				swapSTREAM_OUTPUT_DATA_RSP((HWAPI_MSG_STREAM_OUTPUT_DATA_RSP*) pHeader);
			break;

        case HWAPI_MESSAGE_AV_UPDATE:
            swapAV_UPDATE((HWAPI_MSG_AV_UPDATE*) pHeader);
        break;

		case HWAPI_MESSAGE_FWUPGRADE:
			if(direction == 0)
				swapFW_UPDATE((HWAPI_MSG_FWUPGRADE*) pHeader);
			else
				swapFW_UPDATE_RSP((HWAPI_MSG_FWUPGRADE_RSP *) pHeader);
			break;

        case HWAPI_MESSAGE_SET_AVL:
            if(direction == 0)
                swapSET_AVL((HWAPI_MSG_SET_AVL*) pHeader);
            else
                swapSET_AVL_RSP((HWAPI_MSG_SET_AVL_RSP *) pHeader);
            break;

		case HWAPI_MESSAGE_LOGO_CONFIG:
            if(direction ==0)
                swapLOGO_CONFIG((HWAPI_MSG_LOGO_CONFIG*)pHeader);
            else
                swapLOGO_CONFIG_RSP((HWAPI_MSG_LOGO_CONFIG_RSP*)pHeader);
            break;

        case HWAPI_MESSAGE_LOGO_ON_OFF:
            if(direction ==0)
                swapLOGO_ON_OFF((HWAPI_MSG_LOGO_ON_OFF*) pHeader);
            else
                swapLOGO_ON_OFF_RSP((HWAPI_MSG_LOGO_ON_OFF_RSP*)pHeader);
            break;

        case HWAPI_MESSAGE_I2C_READ:
            if(direction == 0)
                swapSET_I2C_READ((HWAPI_MSG_I2C_READ*) pHeader);
            else
                swapSET_I2C_READ_RSP((HWAPI_MSG_I2C_READ_RSP*) pHeader);
            break;
        case HWAPI_MESSAGE_I2C_WRITE:
            if(direction == 0)
                swapSET_I2C_WRITE((HWAPI_MSG_I2C_WRITE*) pHeader);
            else
                swapSET_I2C_WRITE_RSP((HWAPI_MSG_I2C_WRITE_RSP*) pHeader);
            break;

        case HWAPI_MESSAGE_GPIO_READ:
            if (direction == 0)
                swapSET_GPIO_READ((HWAPI_MSG_GPIO_READ *) pHeader);
            else
                swapSET_GPIO_READ_RSP((HWAPI_MSG_GPIO_READ_RSP*) pHeader);
            break;
        case HWAPI_MESSAGE_GPIO_WRITE:
            if (direction == 0)
                swapSET_GPIO_WRITE((HWAPI_MSG_GPIO_WRITE*) pHeader);
            else
                swapSET_GPIO_WRITE_RSP((HWAPI_MSG_I2C_WRITE_RSP*) pHeader);
            break;

        case  HWAPI_MESSAGE_I2C_SET_CLOCK_FREQ:
            if(direction == 0)
                swapSET_I2C_CLOCK_FREQ((HWAPI_MSG_I2C_CLOCK_FREQ*)pHeader);
            else
                swapSET_I2C_CLOCK_FREQ_RSP((HWAPI_MSG_I2C_CLOCK_FREQ_RSP*)pHeader);
            break;
        case  HWAPI_MESSAGE_I2C_MONITOR_INSTALL:
            if(direction == 0)
            	swapI2C_MONITOR_INSTALL((HWAPI_MSG_I2C_MONITOR_INSTALL*)pHeader);
            else
            	swapI2C_MONITOR_INSTALL_RSP((HWAPI_MSG_I2C_MONITOR_INSTALL_RSP*)pHeader);
            break;
        case HWAPI_MESSAGE_I2C_OUTPUT_MONITOR_DATA:
            swapI2C_MONITOR_OUTPUT_DATA((HWAPI_MSG_I2C_OUTPUT_MONITOR_DATA*)pHeader);
            break;
        case HWAPI_MESSAGE_SET_AR:
            if (direction == 0)
            	swapSET_AR_DATA((HWAPI_MSG_AR_DATA*)pHeader);
            else
            	swapSET_AR_DATA_RSP((HWAPI_MSG_AR_DATA_RSP*)pHeader);
            break;
        case HWAPI_MESSAGE_SET_PCR:
            if (direction == 0)
            	swapSET_PCR_DATA((HWAPI_MSG_PCR_DATA*)pHeader);
            else
            	swapSET_PCR_DATA_RSP((HWAPI_MSG_PCR_DATA_RSP*)pHeader);
            break;
        case HWAPI_MESSAGE_STATUS_QUERY:
            if(direction == 0)
            	swap_MSG_STATUS_QUERY((HWAPI_MSG_QUERY_STATUS*)pHeader);
            else
            	swap_MSG_STATUS_QUERY_RSP((HWAPI_MSG_QUERY_STATUS_RSP*)pHeader);
            break;
		default:
			DbgLogError(("swapMessage: invalid msg type:%d\n", pHeader->type));
			break;
	}

	//DbgLogInfo(("swapMessage end\n"));

	return 0;
}
