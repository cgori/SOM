/*
 * PresenceDetection.cpp
 *
 *  Created on: 18 Feb 2020
 *      Author: cmprharr
 */

#include "PresenceDetection.h"



PresenceDetection::PresenceDetection() {


}

PresenceDetection::~PresenceDetection() {
	// TODO Auto-generated destructor stub
}

PresenceState PresenceDetection::checkState(){

	if(pirsensor.readPIR() == HIGH ){
		Serial.println("Someone detected 10min delay");
		this->pirTime = millis();
		return PresenceState::DETECTED;
	}
	else{
		return PresenceState::EMPTY;
	}

}

long PresenceDetection::getTime(){
	return this->pirTime;
}





