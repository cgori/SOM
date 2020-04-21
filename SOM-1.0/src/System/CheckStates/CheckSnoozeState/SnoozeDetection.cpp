/*
 * SnoozeDetection.cpp
 *
 *  Created on: 18 Feb 2020
 *      Author: cmprharr
 */

#include "SnoozeDetection.h"

SnoozeDetection::SnoozeDetection() {
	// TODO Auto-generated constructor stub

}

SnoozeDetection::~SnoozeDetection() {
	// TODO Auto-generated destructor stub
}

SnoozeState SnoozeDetection::checkSnooze(){
	if(this->btn.checkState() == ButtonState::ON){
		Serial.println("Button pressed 2min sleep");
		this->time = millis();
		this->snoozeState = SnoozeState::SLEEPING;

	}else{
		this->snoozeState = SnoozeState::RUNNING;
	}
	return this->snoozeState;
}

long SnoozeDetection::getTime(){
	return this->time;
}

