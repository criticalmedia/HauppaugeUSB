#ifndef __ENCODERDEV_DXT_H_
#define __ENCODERDEV_DXT_H_

#include "encoderDev.h"
#include "FX2Device.h"

class encoderDev_DXT_t: public encoderDev_t {
protected:
	FX2Device_t &m_fx2;
	void *m_mchip;
	void *m_hapi;

public:
	encoderDev_DXT_t(FX2Device_t &fx2): m_fx2(fx2), m_mchip(NULL), m_hapi(NULL) {}
	~encoderDev_DXT_t();

	bool init();
	bool showInfo();
	bool startCapture();
	bool stopCapture();

	bool setInputFormat(encoderSource_t source, encoderAudioInFormat_t audioFormat,
		unsigned width, unsigned height, bool interlaced, float vFreq, float aspectRatio,
		float audioSampleRate);

	bool setHDMIFormat(int hdmi_fmt, float audioSampleRate);
	bool setHDMIAR(float aspectRatio);
};

#endif
