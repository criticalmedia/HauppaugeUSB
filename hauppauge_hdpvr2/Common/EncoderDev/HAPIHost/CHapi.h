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

#ifndef C_HAPI_H
#define C_HAPI_H


#include "winwrap.h"
#include "baseif.h"

#include "Hapi.h"
#include "HapiBaseType.h"
#include "Hwapi.h"

#include "mchip.h"

#include "colossus/EncoderIF.h"
#include "colossus/Exeapi.h"


typedef struct _HCW_LOGO_CONFIG_PARAM 
{ 
    Uint32	magic; //'HCW1'
    Uint32	width; 
    Uint32	height; 
    Int32	x; //a negative number means that many pixels back from width of encoded stream
    Int32	y; //a negative number means that many pixels back from height of encoded stream 
	Uint8	logoData[MAX_LOGO_WIDTH*MAX_LOGO_HEIGHT*BYTE_PER_PIXEL]; 
}HCW_LOGO_CONFIG_PARAM; 


typedef enum _BOARD_BUS_TYPE
{
    plankton    = 0,
    llama       = 1,
    llama_usb   = 2,
#ifdef HAUPPAUGE
    siena       = 3,
#else
    pci         = 3,
    host_bus    = 4,
#endif
    BOARD_MAX,
}BOARD_BUS_TYPE;


class CHapi {
public:
	CHapi(USBBootMChip_t *p_mchip);
	~CHapi();

private:
	USBBootMChip_t *p_mchip;
	
	CommBusType gCommBusType;
	HWAPI_FUNCTIONS gHapiFunc;
	hw_port_config gHwPortConfig;
	HWAPIHandle gHWapiHandle;
	HAPI_INIT_PARAM gInitParam;
	BOARD_INFO boardInfo;
	HAPIHandle gHapi;
	BOARD_BUS_TYPE gBoard_bus;
	HapiErrCode hapiErr;

private:
	void	HapiAPIInit();
	void	HapiFWDownload();
	void	HapiFWBoot();
	void	HapiExit();
public:
	Uint32	HapiStart();
	Uint32	HapiStop();
	Uint32  HapiResume();

	bool	powerUp();
	void	powerDown();
	bool	DeviceIsReady();
private:
	void	powerDownHW();
	Uint32	hapiStart();
	Uint32	hapiStop();
	void    hapiResetHW();

public:
	//update_DXT();
	Uint32	HapiParamGet(HAPI_SET_PARAM *pParam);
	Uint32	HapiParamSet(HAPI_SET_PARAM *pParam);
	Uint32	HapiAspectSet(HAPI_ASPECT_RATIO ar);
	Uint32	HapiStatusQuery(HAPI_QUERY_STRUCT *p_status);

	void	set_param(HAPI_SET_PARAM *pParam, const char* param_name, Uint32 value);
	Uint32	get_param(HAPI_SET_PARAM *pParam, const char* param_name);
	Uint32	is_param_dirty(HAPI_SET_PARAM *pParam);
	Uint32	get_custom_defaults(HAPI_SET_PARAM *pParam, unsigned width, unsigned height, bool interlaced, float vFreq);
	Uint32	get_std_defaults(HAPI_SET_PARAM *pParam);
	Uint32	get_audenc_defaults(HAPI_SET_PARAM *pParam);
	Uint32	get_scaler_defaults(HAPI_SET_PARAM *pParam);
	Uint32  setScalerSettings(ScalerSettings *pScaler);
//	Uint32  getScalerSettings(ScalerSettings *pScaler); //moved to EncoderSettings
	Uint32	setAudEncSettings(AudEncSettings *pAudEnc);
//	Uint32	getAudEncSettings(AudEncSettings *pAudEnc); //moved to EncoderSettings
	void	setHDMIformat(DWORD hdmi_fmt);
	bool	HapiRunning();
	Uint32  get_logo_data(HAPI_SET_PARAM *pParam);
	Uint32	HapiGetEncStatus(pEncStatus pStatus);
private:
	Uint32	cvt_OUTPUT_FRAME_RATE(HAPI_VIDEO_OUTPUT_FRAME_RATE value);
	Uint32	cvt_AUDIO_BITRATE(HAPI_AUDIO_BITRATE value);
	Uint32	cvt_AUDIO_SAMPLE_RATE(HAPI_AUDIO_SAMPLE_RATE value);

private:
	Uint64	read_logo_data();
	void	reset_logo_data();

private:

	DWORD	_hdmi_fmt;
	DWORD	_last_good_hdmi_fmt;
	DWORD	_bling_options;
	DWORD	_bling_count;
	DWORD	_errCountdown;
	DWORD	_LED_state;

	bool	_isStarted;
	bool	_isPaused;
	bool	_API_ok;
	Uint64	_last_PCR;

	DWORD	_last_payload_time;
	DWORD	_last_payload_delta;
	DWORD	_first_payload_time;
	DWORD	_first_payload_delta; //time, in ms, from HAPI_Start to recieve first data packet

	ExtCapParams m_extcapParams;

public://Callbacks; context==this CHapi
	static	HapiErrCode AVDataRequest(HAPI_AV_DATA_INFO *info, void *context);//to DXT
	static	HapiErrCode AVDataTransfer(HAPI_AV_DATA_INFO *info, void *context);//from DXT
	static	HapiErrCode ErrorMsgCallback(HAPI_ERROR_MSG_TYPE errorType, void *context, HAPI_ERR_PARAM *param);
	void	setDataTransfer(PVOID p_data_transfer) { _p_data_transfer = p_data_transfer; }
private:
	PVOID	_p_data_transfer;

private:
	void	set_param_bitmask(HAPI_SET_PARAM *pParam, const char* param_name);
	Uint32	get_param_bitmask(HAPI_SET_PARAM *pParam, const char* param_name);
	void	clear_param_bitmasks(HAPI_SET_PARAM *pParam);

private:
	void set_transcode_a7_1080i_to_h264_1920x544(HAPI_SET_PARAM *pParam);
	void set_transcode_1080i_to_480i_h264(HAPI_SET_PARAM *pParam);
	void set_encode_1080i60_h264(HAPI_SET_PARAM *pParam);
	void set_encode_1080p60_h264(HAPI_SET_PARAM *pParam);
	void set_encode_720p60_h264(HAPI_SET_PARAM *pParam);
	void set_encode_480p60_h264(HAPI_SET_PARAM *pParam);
	void set_encode_480i60_h264(HAPI_SET_PARAM *pParam);


#if DBG
private:
	const char *str_HAPI_SET_PARAM_TYPE(Uint32 value);
	const char *str_HAPI_VIDEO_CODEC(Uint32 value);
	const char *str_HAPI_VIDEO_OUTPUT_MODE(Uint32 value);
	const char *str_HAPI_VIDEO_OUTPUT_FRAME_RATE(Uint32 value);
	const char *str_HAPI_RATE_CONTROL(Uint32 value);
	const char *str_HAPI_CODING_MODE(Uint32 value);
	const char *str_HAPI_VIDEO_PROFILE(Uint32 value);
	const char *str_HAPI_LATENCY(Uint32 value);
	const char *str_HAPI_VIDEO_CAPTURE_SOURCE(Uint32 value);
	const char *str_HAPI_H264_LEVEL(Uint32 value);
	const char *str_HAPI_AUDIO_CODEC(Uint32 value);
	const char *str_HAPI_AUDIO_SAMPLE_RATE(Uint32 value);
	const char *str_HAPI_AUDIO_BITRATE(Uint32 value);
	const char *str_HAPI_AUDIO_OUTPUT_MODE(Uint32 value);
	const char *str_HAPI_AUDIO_CAPTURE_SOURCE(Uint32 value);
	void	printParam(HAPI_SET_PARAM *pParam);
	void	verify_type_sizes();

public:
	void	HapiTest(DWORD hdmi_fmt);
private:

	HANDLE	prv_open_file(char *filename, int mode, Uint32* size);
	ULONG_PTR prv_read_file(HANDLE fileHandle, BYTE *buf, Uint32 size);
	ULONG_PTR prv_write_file(HANDLE fileHandle, BYTE *buf, Uint32 size);
	void	prv_close_file(HANDLE &fileHandle);
	Uint64    prv_get_mod_time(HANDLE fileHandle);
	HANDLE inFileHandle;
	HANDLE outFileHandle;
	void	prv_init_transcode_files();
	void	prv_init_encode_outfile();
#endif//DBG

//#define HAPI_POWER_THREAD 1

#ifdef HAPI_POWER_THREAD
public:
	NTSTATUS	startPowerThread();
	VOID		stopPowerThread();
private:
	static VOID	static_doPowerChk(CHapi* p_CHapi);
	VOID		doPowerChk();
	PVOID		_polling_thread_object;    
	KEVENT		_polling_event_object;
	DWORD		_power_down_delay;
	DWORD		_power_time_left;
	bool		_powered_up;
#endif//HAPI_POWER_THREAD

public:
    VOID		lock();
    VOID		unlock();
private:
    wrapMutex_t _mutex;

private:
	//FGR - use these to optimize out need to set params when they are not changed
	HAPI_SET_PARAM         _lastParam;
	HAPI_ASPECT_RATIO      _lastAR;

	HCW_LOGO_CONFIG_PARAM  _logo;
	Uint64                 _logo_mod_time;
	Int32                  _logo_x_pos;
	Int32                  _logo_y_pos;
	Int32                  _logo_used;
	char                   _logo_name[256];
	DWORD                  _serialNo;
public:
	void		setSerial(DWORD dwSerialNo) { _serialNo = dwSerialNo;} 
};

#endif//C_HAPI_H
