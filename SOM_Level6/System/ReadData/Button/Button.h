/*
 * Button.h
 *
 *  Created on: 18 Feb 2020
 *      Author: cmprharr
 */

#ifndef SYSTEM_READDATA_BUTTON_BUTTON_H_
#define SYSTEM_READDATA_BUTTON_BUTTON_H_
#include "Arduino.h"
class Button {
public:
	Button();
	virtual ~Button();
	int checkButtonState();

private:
	int buttonPin = 25;
};

#endif /* SYSTEM_READDATA_BUTTON_BUTTON_H_ */
