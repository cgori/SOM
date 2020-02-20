/*
 * SystemDetection.h
 *
 *  Created on: 18 Feb 2020
 *      Author: cmprharr
 */

#ifndef SYSTEM_CHECKSTATES_CHECKSYSTEMSTATE_SYSTEMDETECTION_H_
#define SYSTEM_CHECKSTATES_CHECKSYSTEMSTATE_SYSTEMDETECTION_H_
#include "EnumStates/SystemState.h"

class SystemDetection {
public:
	SystemDetection();
	virtual ~SystemDetection();
	void checkStates(int heat, int humid);
private:
	SystemState sysState;
	SystemState heatState;
	SystemState humidState;
	const int greenLow= 18;
	const int greenHigh=23;
	const int amberLow = 16;
	const int amberHigh = 27;
	const int humidGreenLow = 35;
	const int humidGreenHigh = 60;
	const int humidAmberLow=25;
	const int humidAmberhigh=75;
};

#endif /* SYSTEM_CHECKSTATES_CHECKSYSTEMSTATE_SYSTEMDETECTION_H_ */
