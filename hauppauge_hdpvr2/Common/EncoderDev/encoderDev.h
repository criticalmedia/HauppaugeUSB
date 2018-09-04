#ifndef __ENCODERDEV_H_
#define __ENCODERDEV_H_

#include "AVOutput.h"

typedef enum {
	ENCS_AUTO = 0,
	ENCS_CVBS,
	ENCS_COMP,
	ENCS_HDMI
} encoderSource_t;

typedef enum {
    ENCAIF_AUTO = 0,
    ENCAIF_PCM,
    ENCAIF_AC3
} encoderAudioInFormat_t;

class encoderDev_t {
protected:
	DataTransfer m_dt;

public:
	encoderDev_t() {}
	virtual ~encoderDev_t() {}

	bool setOutputFile(const char *fn) {
		return m_dt.setFile(fn);
	}

	void setOutputFD(int fd) {
		m_dt.setFD(fd);
	}

	void setWriteCallback(DataTransfer::callback_t & cb) {
	        m_dt.setCB(cb);
	}

	virtual bool init() = 0;
	virtual bool showInfo() = 0;
	virtual bool startCapture() = 0;
	virtual bool stopCapture() = 0;

	virtual bool setInputFormat(encoderSource_t source, encoderAudioInFormat_t audioFormat,
		unsigned width, unsigned height, bool interlaced, float vFreq, float aspectRatio,
		float audioSampleRate) = 0;

	virtual bool setHDMIFormat(int hdmi_fmt, float audioSampleRate) = 0;
	virtual bool setHDMIAR(float aspectRatio) = 0;
};

#endif
