/*
 * Button.cpp
 *
 *  Created on: 18 Feb 2020
 *      Author: cmprharr
 */

#include "Button.h"

Button::Button() {
	pinMode(buttonPin, INPUT);
	this->lastChange = 0;
}

Button::~Button() {
	// TODO Auto-generated destructor stub
}

int Button::checkButtonState(){
	int state = digitalRead(buttonPin);
	return state;
}

ButtonState Button::checkState(){
	ButtonState now = ButtonState::OFF;
	if(digitalRead(buttonPin)){
		now = ButtonState::ON;
	}

	if(now != bouncedState){
		lastChange = millis();
		bouncedState = now;
	}
	if((millis() - lastChange) >= BOUNCE_DELAY_MS)
		debouncedState = now;
	return debouncedState;
}

