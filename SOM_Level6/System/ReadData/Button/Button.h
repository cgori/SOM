/*
 * Button.h
 *
 *  Created on: 18 Feb 2020
 *      Author: cmprharr
 */

#ifndef SYSTEM_READDATA_BUTTON_BUTTON_H_
#define SYSTEM_READDATA_BUTTON_BUTTON_H_
#include "Arduino.h"
enum class ButtonState {
	ON, OFF
};

class Button {
public:
	Button();
	virtual ~Button();
	int checkButtonState();
	ButtonState checkState();
private:
	const int BOUNCE_DELAY_MS = 5;
	int buttonPin = 25;
	ButtonState debouncedState = ButtonState::OFF;
	ButtonState bouncedState = ButtonState::OFF;
	long lastChange;
	void deBounce();

};

#endif /* SYSTEM_READDATA_BUTTON_BUTTON_H_ */
