/*
 * PresenceDetection.h
 *
 *  Created on: 18 Feb 2020
 *      Author: cmprharr
 */

#ifndef SYSTEM_CHECKSTATES_CHECKPRESENCESTATE_PRESENCEDETECTION_H_
#define SYSTEM_CHECKSTATES_CHECKPRESENCESTATE_PRESENCEDETECTION_H_
#include "../EnumStates/PresenceState.h"
#include "../../ReadData/PIRSensor/PIRSensor.h"
#include "arduino.h"
class PresenceDetection {
public:
	PresenceDetection();
	virtual ~PresenceDetection();
	PresenceState checkState();
	long getTime();
private:

	PIRSensor pirsensor;
	PresenceState state;
	unsigned long pirTime;
	long pirDelay = 60000;
	bool timeDiff(unsigned long start);

};

#endif /* SYSTEM_CHECKSTATES_CHECKPRESENCESTATE_PRESENCEDETECTION_H_ */
