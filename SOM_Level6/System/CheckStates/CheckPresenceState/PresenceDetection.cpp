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

	/**
	 * Returns the state, being detected or empty.
	 * @return PresenceState
	 */
	if(pirsensor.readPIR() == HIGH ){
		Serial.println("Someone detected 10min delay");
		this->pirTime = millis();
		return PresenceState::DETECTED;
	}
	else{
		return PresenceState::EMPTY;
	}

}
/*
 * @return pirTime
 */
long PresenceDetection::getTime(){
	return this->pirTime;
}





