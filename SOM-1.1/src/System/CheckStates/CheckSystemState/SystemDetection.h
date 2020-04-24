/*
 * SystemDetection.h
 *
 *  Created on: 18 Feb 2020
 *      Author: cmprharr
 */

#ifndef SYSTEM_CHECKSTATES_CHECKSYSTEMSTATE_SYSTEMDETECTION_H_
#define SYSTEM_CHECKSTATES_CHECKSYSTEMSTATE_SYSTEMDETECTION_H_
#include "../EnumStates/SystemState.h"
#include "Arduino.h"
#include "../../WriteData/RGB/RGB.h"
class SystemDetection {
public:
	SystemDetection();
	virtual ~SystemDetection();
	void checkStates(int heat, int humid);
	void checkHeatState(int heat);
	void checkHumidState(int humid);
	void turnOnRGB();
	SystemState getSystemState();
private:
	RGB rgb;
	SystemState sysState;
	SystemState heatState;
	SystemState humidState;
	const int greenLow= 18;
	const int greenHigh=25;
	const int amberLow = 16;
	const int amberHigh = 27;
	const int humidGreenLow = 35;
	const int humidGreenHigh = 60;
	const int humidAmberLow=25;
	const int humidAmberhigh=75;
};

#endif /* SYSTEM_CHECKSTATES_CHECKSYSTEMSTATE_SYSTEMDETECTION_H_ */
