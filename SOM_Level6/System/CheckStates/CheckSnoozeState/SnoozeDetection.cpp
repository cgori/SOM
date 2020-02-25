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
		this->snoozeState = SnoozeState::SLEEPING;

	}
	return this->snoozeState;
}

