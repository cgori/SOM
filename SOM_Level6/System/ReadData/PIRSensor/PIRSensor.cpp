/*
 * PIRSensor.cpp
 *
 *  Created on: 18 Feb 2020
 *      Author: cmprharr
 */

#include "PIRSensor.h"
#include "Arduino.h"
PIRSensor::PIRSensor() {
	// TODO Auto-generated constructor stub
	pinMode(PIRPin, INPUT);
}

PIRSensor::~PIRSensor() {
	// TODO Auto-generated destructor stub
}

int PIRSensor::readPIR(){
	int val = digitalRead(PIRPin);
	return val;
}

PresenceState PIRSensor::checkState(){

	if(this->readPIR() == HIGH ){
		Serial.println("Someone detected 10min delay");
		this->pirTime = millis();
		return PresenceState::DETECTED;
	}
	else{
		return PresenceState::EMPTY;
	}

}

long PIRSensor::getTime(){
	return this->pirTime;
}


