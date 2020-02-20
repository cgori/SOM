/*
 * Button.cpp
 *
 *  Created on: 18 Feb 2020
 *      Author: cmprharr
 */

#include "Button.h"

Button::Button() {
	pinMode(buttonPin, INPUT);

}

Button::~Button() {
	// TODO Auto-generated destructor stub
}

int Button::checkButtonState(){
	int state = digitalRead(buttonPin);
	return state;
}

