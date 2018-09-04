#ifndef __RECEIVER_ADV7842_H_
#define __RECEIVER_ADV7842_H_

#include "receiver.h"
#include "FX2Device.h"

class receiver_ADV7842_t: public receiver_t {
protected:
	FX2Device_t &m_fx2;

	bool _isInit;

	receiverInput_t _input;
	receiverOutputBusMode_t _outputBusMode;
	const void *_EDIDPtr;
	unsigned _EDIDLen;
	unsigned _EDIDSPAOffset;

	bool _initHDMI();
	bool _initCVBS();
	bool _initComp();
	bool _setOutputBusMode();
	bool _setEDID();
	bool _showInfoHDMI();
	bool _showInfoSDP();
	bool _enableColorMode();
	bool _showInfoCP();

public:
	receiver_ADV7842_t(FX2Device_t &fx2): m_fx2(fx2),
		_isInit(false),
		_input(RXI_NONE),
		_outputBusMode(RXOBM_422_10x2), _EDIDPtr(NULL), _EDIDLen(0), _EDIDSPAOffset(0) {}
	bool init();
	bool setInput(receiverInput_t input);

	bool setOutputBusMode(receiverOutputBusMode_t mode);
	bool setEDID(const void *ptr, unsigned len, unsigned SPAOffset);

	bool hasInputSignal();
	bool getOutputParams(receiverOutputParams_t *ret);

	bool getAudioParams(receiverAudioParams_t *ret);

	bool getHDMIParams(receiverHDMIParams_t *ret);
	int getHDMIFormat();

	bool showInfo();
};

#endif
