/*
 * System.cpp
 *
 *  Created on: 18 Feb 2020
 *      Author: cmprharr
 */

#include "System.h"

System::System() {

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
void System::readButton(){
	btn.checkButtonState();

}


void System::alarm(){
	if(this->pirState == PresenceState::DETECTED && sysDetection.getSystemState() == SystemState::RED && this->timeDiff(this->lastChangeSystem, this->criticalDelay)){
		this->alarmOn = true;
		buzzer.turnBuzzerON();
		lastChangeSystem = millis();


	}else if(this->pirState == PresenceState::DETECTED && sysDetection.getSystemState() == SystemState::AMBER && this->timeDiff(this->lastChangeSystem, this->amberDelay)){
		Serial.println("Amber state delay 30s");
		this->alarmOn = true;
		buzzer.turnBuzzerON();
		lastChangeSystem = millis();
	}
	if(this->alarmOn && this->timeDiff(this->lastChangeSystem, this->alarmDelay)){
		buzzer.turnBuzzerOFF();
	}

}



void System::checkStates() {
	if (!this->heat.empty() && !this->humid.empty()) {
		this->sysDetection.checkStates(this->heat.back(), this->humid.back());
	}
	checkPresence();

}

void System::writeData() {
	if (timeDiff(this->serialOutPutLastChange, this->serialOutPutDelay)) {
		this->serialOutPutLastChange = millis();
		this->heat = this->dht_.getHeat();
		this->humid = this->dht_.getHumidity();
		serialToString();
	}
	alarm();
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

// PIRSensor

void System::checkPresence() {
	if (this->pirState == PresenceState::DETECTED
			&& timeDiff(presenceDetection.getTime(), this->PIRDelay)) {
		this->pirState = presenceDetection.checkState();

	} else if (this->pirState == PresenceState::EMPTY) {
		this->pirState = presenceDetection.checkState();
	}
}

