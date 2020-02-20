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

}

void System::checkStates() {
	int y = this->heat.size();
	int x = this->humid.size();
	if ((!this->heat.empty() && this->heat.back()==y) && (!this->humid.empty() && this->humid.back()==x))
	{
		this->sysDetection.checkStates(this->heat.back(),this->humid.back());
	}

}
boolean System::timeDiff(unsigned long start, int specifiedDelay) {
	return (millis() - start >= specifiedDelay);
}

