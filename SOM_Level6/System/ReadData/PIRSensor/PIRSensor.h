/*
 * PIRSensor.h
 *
 *  Created on: 18 Feb 2020
 *      Author: cmprharr
 */

#ifndef SYSTEM_READDATA_PIRSENSOR_PIRSENSOR_H_
#define SYSTEM_READDATA_PIRSENSOR_PIRSENSOR_H_
#include "PresenceState.h"
class PIRSensor {
public:
	PIRSensor();
	virtual ~PIRSensor();
	int readPIR();
	PresenceState checkState();
	long getTime();
private:
	int PIRPin = 4;
	PresenceState state;
	unsigned long pirTime = 0;
	long pirDelay = 60000;
	bool timeDiff(unsigned long start);
};

#endif /* SYSTEM_READDATA_PIRSENSOR_PIRSENSOR_H_ */
