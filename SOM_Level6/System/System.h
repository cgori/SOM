/*
 * System.h
 *
 *  Created on: 18 Feb 2020
 *      Author: cmprharr
 */

#ifndef SYSTEM_SYSTEM_H_
#define SYSTEM_SYSTEM_H_
#include "ReadData/DHTSensor/DHTSensor.h"
#include "Arduino.h"
#include "CheckStates/CheckSystemState/SystemDetection.h"
#include "CheckStates/CheckPresenceState/PresenceDetection.h"
#include "CheckStates/CheckSnoozeState/SnoozeDetection.h"
class System {
public:
	System();
	virtual ~System();
	void readSensors();
	void writeData();
	void checkStates();
	bool timeDiff(unsigned long start, int specifiedDelay);
private:
	DHTSensor dht_;
	PresenceDetection presenceDetection;
	SnoozeDetection snoozeDetection;
	SystemDetection sysDetection;
	std::vector<float> heat;
	std::vector<float> humid;
	int DHTDelay = 1000;
	unsigned long DHTLastChangeTime;
};

#endif /* SYSTEM_SYSTEM_H_ */
