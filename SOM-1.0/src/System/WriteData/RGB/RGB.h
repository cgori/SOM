/*
 * RGB.h
 *
 *  Created on: 18 Feb 2020
 *      Author: cmprharr
 */

#ifndef SYSTEM_WRITEDATA_RGB_RGB_H_
#define SYSTEM_WRITEDATA_RGB_RGB_H_
#include "Arduino.h"
class RGB {
public:
	RGB();
	virtual ~RGB();
	void turneRedLEDOn();
	void turnGreenLEDOn();
	void LEDOFF();

private:
	int greenPin = 12;
	int redPin = 27;
};
#endif /* SYSTEM_WRITEDATA_RGB_RGB_H_ */
