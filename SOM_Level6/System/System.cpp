/*
 * System.cpp
 *
 *  Created on: 18 Feb 2020
 *      Author: cmprharr
 */

#include "System.h"

System::System() {
	// TODO Auto-generated constructor stub

}

System::~System() {
	// TODO Auto-generated destructor stub
}

void System::readSensors() {
	if (timeDiff(this->DHTLastChangeTime, this->DHTDelay)) {
		this->DHTLastChangeTime = millis();
		this->dht_.readDHT();
		this->heat = this->dht_.getHeat();
		this->humid = this->dht_.getHumidity();
	}

}

void System::writeData() {
	if (timeDiff(this->serialOutPutLastChange, this->serialOutPutDelay)) {
		this->serialOutPutLastChange = millis();
		this->heat = this->dht_.getHeat();
		this->humid = this->dht_.getHumidity();
		serialToString();
	}
}

void System::checkStates() {
	if (!this->heat.empty() && !this->humid.empty()) {
		this->sysDetection.checkStates(this->heat.back(), this->humid.back());
	}
}

bool System::timeDiff(unsigned long start, int specifiedDelay) {
	return (millis() - start >= specifiedDelay);
}

void System::serialToString() {
	Serial.print("Current heat:");
	Serial.print(this->heat.back());
	Serial.print(" Current Humidity:");
	Serial.println(this->humid.back());
}


