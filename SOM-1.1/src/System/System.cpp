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
	if(this->pirState == PresenceState::DETECTED && sysDetection.getSystemState() == SystemState::RED && this->timeDiff(this->lastChangeSystem, this->criticalDelay) && this->snoozeState == SnoozeState::RUNNING){
		this->alarmOn = true;
		buzzer.turnBuzzerON();
		lastChangeSystem = millis();


	}else if(this->pirState == PresenceState::DETECTED && sysDetection.getSystemState() == SystemState::AMBER && this->timeDiff(this->lastChangeSystem, this->amberDelay) && this->snoozeState == SnoozeState::RUNNING){
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
	checkSnooze();

}

void System::writeData() {
	if (timeDiff(this->serialOutPutLastChange, this->serialOutPutDelay)) {
		this->serialOutPutLastChange = millis();
		this->heat = this->dht_.getHeat();
		this->humid = this->dht_.getHumidity();
		serialToString();
	}
	alarm();
	//sendHTTPost();
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
void System::checkSnooze(){
	if (this->snoozeState == SnoozeState::SLEEPING
				&& timeDiff(snoozeDetection.getTime(), this->snoozeDelay)) {
	}else if (this->snoozeState == SnoozeState::RUNNING) {
		this->snoozeState = snoozeDetection.checkSnooze();
	}
}


void System::checkPresence() {
	if (this->pirState == PresenceState::DETECTED
			&& timeDiff(presenceDetection.getTime(), this->PIRDelay)) {
		this->pirState = presenceDetection.checkState();

	} else if (this->pirState == PresenceState::EMPTY) {
		this->pirState = presenceDetection.checkState();
	}
}

void System::sendHTTPost() {
	if(timeDiff(wifi.getTime(), this->wifiDelay)){
		wifi.sendData(dht_.getHeat(), dht_.getHumidity());
	}


}

void System::saveSD() {
	if(timeDiff(sd.getTime(), this->sdDelay)){
		wifi.sendData(dht_.getHeat(), dht_.getHumidity());
	}


}

