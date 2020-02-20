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

	SystemState TempState = this->sysState;
	checkHeatState(heat);
	checkHumidState(humid);
	if (this->heatState == SystemState::RED
			|| this->humidState == SystemState::RED) {
		this->sysState = SystemState::RED;
	} else if (this->heatState == SystemState::AMBER
			|| this->humidState == SystemState::AMBER) {
		this->sysState = SystemState::AMBER;
	} else {
		this->sysState = SystemState::GREEN;
		this->rgb.turnGreenLEDOn();
	}
	if (TempState != this->sysState) {
		this->rgb.LEDOFF();
		if (this->sysState == SystemState::RED) {
			Serial.println("System state changed to critical");
			this->rgb.turneRedLEDOn();
		} else if (this->sysState == SystemState::AMBER) {
			Serial.println("System state changed to amber");
			this->rgb.turneRedLEDOn();
			this->rgb.turnGreenLEDOn();
		} else {
			Serial.println("System is functioning normally");
			this->rgb.turnGreenLEDOn();
		}
	}
}

void SystemDetection::checkHeatState(int heat) {
	if (this->greenLow <= heat && this->greenHigh >= heat) {
		this->heatState = SystemState::GREEN;

	} else if (this->amberLow <= heat && this->amberHigh >= heat) {
		this->heatState = SystemState::AMBER;
	} else {
		this->heatState = SystemState::RED;
	}
}
void SystemDetection::checkHumidState(int humid) {
	if (this->humidGreenLow <= humid && this->humidGreenHigh >= humid) {
		this->humidState = SystemState::GREEN;

	} else if (this->humidAmberLow <= humid && this->humidAmberhigh >= humid) {
		this->humidState = SystemState::AMBER;
	} else {
		this->humidState = SystemState::RED;
	}
}
