/*
 * SystemDetection.cpp
 *
 *  Created on: 18 Feb 2020
 *      Author: cmprharr
 */

#include "SystemDetection.h"

SystemDetection::SystemDetection() {
	// TODO Auto-generated constructor stub

}

SystemDetection::~SystemDetection() {
	// TODO Auto-generated destructor stub
}

void SystemDetection::checkStates(int heat, int humid) {
	//Check the heat state first
	if (this->greenLow >= heat && this->greenHigh <= heat) {

	} else if (this->amberLow >= heat && this->amberHigh <= heat) {

	} else {

	}
	if (this->humidGreenLow >= heat && this->humidGreenHigh <= heat) {

	} else if (this->humidAmberLow >= heat && this->humidAmberhigh <= heat) {

	} else {

	}
}

