#ifndef __RECEIVER_H_
#define __RECEIVER_H_

#include <stdint.h>

typedef struct {
	unsigned width;
	unsigned height;
	unsigned hLinesTotal;
	unsigned vLinesTotal;
	float TMDSFreq;
	float hFreq;
	float vFreq;
	bool interlaced;
	unsigned pixelRepetitionFactor; // 1 - no repetition
	float aspectRatio;
} receiverHDMIParams_t;

typedef struct {
	unsigned width;
	unsigned height;
	float vFreq;
	bool interlaced;
	float aspectRatio;
} receiverOutputParams_t;

typedef struct {
	float sampleRate;
} receiverAudioParams_t;

typedef enum {
	RXOBM_422_10x2,
	RXOBM_656_10,
	RXOBM_656_10_DC
} receiverOutputBusMode_t;

typedef enum {
	RXI_NONE = 0,
	RXI_HDMI,
	RXI_CVBS,
	RXI_COMP
} receiverInput_t;

class receiver_t {
public:
	virtual ~receiver_t() {}

	virtual bool init() = 0;
	virtual bool setInput(receiverInput_t input) = 0;

	virtual bool setOutputBusMode(receiverOutputBusMode_t mode) = 0;
	virtual bool setEDID(const void *ptr, unsigned len, unsigned SPAOffset) = 0;

	virtual bool hasInputSignal() = 0;
	virtual bool getOutputParams(receiverOutputParams_t *ret) = 0;

	virtual bool getAudioParams(receiverAudioParams_t *ret) = 0;

	virtual bool getHDMIParams(receiverHDMIParams_t *ret) = 0;
	virtual int getHDMIFormat() = 0;

	virtual bool showInfo() = 0;
};

#endif
