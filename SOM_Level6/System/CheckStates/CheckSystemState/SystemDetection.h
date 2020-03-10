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
	void checkStates(double heat, double humid);
	void checkHeatState(double heat);
	void checkHumidState(double humid);
	void turnOnRGB();
	SystemState getSystemState();
private:
	RGB rgb;
	SystemState sysState;
	SystemState heatState;
	SystemState humidState;
	const double greenLow= 18;
	const double greenHigh=23;
	const double amberLow = 16;
	const double amberHigh = 27;
	const double humidGreenLow = 35;
	const double humidGreenHigh = 60;
	const double humidAmberLow=25;
	const double humidAmberhigh=75;
};

#endif /* SYSTEM_CHECKSTATES_CHECKSYSTEMSTATE_SYSTEMDETECTION_H_ */
