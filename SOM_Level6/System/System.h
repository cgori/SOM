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
#include "WriteData/Buzzer/Buzzer.h"
#include "CheckStates/EnumStates/SnoozeState.h"
#include "ReadData/Button/Button.h"

class System {
public:
	System();
	virtual ~System();
	void readSensors();
	void writeData();
	void checkStates();
	bool timeDiff(unsigned long start, int specifiedDelay);
	void serialToString();
	void checkSnooze();

private:
	SnoozeState snoozeState = SnoozeState:: RUNNING;
	PresenceDetection presenceDetection;
	SnoozeDetection snoozeDetection;
	SystemDetection sysDetection;
	std::vector<float> heat;
	std::vector<float> humid;
	// Component delays
	int DHTDelay = 1000;
	int PIRDelay = 500;
	int BuzzerDelay = 120000;
	void alarm();
	void readButton();
	bool DHT_State = true;
	Button btn;

	//States
	PresenceState pirState = PresenceState::EMPTY;


	// Component objects
	DHTSensor dht_;
	PIRSensor pir;
	Buzzer buzzer;
	long snoozeDelay = 120000;
	bool alarmOn = false;
	long alarmDelay = 1000;
	unsigned long DHTLastChangeTime;
	long criticalDelay = 5000;
	const long amberDelay = 30000;
	unsigned long lastChangeSystem;
	unsigned buzzerDelay = 1000;

	unsigned long serialOutPutLastChange;
	const int serialOutPutDelay = 5000;
	void checkPresence();
};

#endif /* SYSTEM_SYSTEM_H_ */
