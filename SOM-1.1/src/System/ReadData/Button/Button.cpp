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
	pinMode(buttonSerialChangeTime, INPUT);
}

Button::~Button() {
	// TODO Auto-generated destructor stub
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

void Button::check(){
	ButtonState now = ButtonState::OFF;
	if(digitalRead(buttonSerialChangeTime)){
		now = ButtonState::ON;
		if(previousState == now){
			if(timeDiff(lastChangeTime, buttonDelay)){
				ChangeTime();
			}
		}else{
			lastChangeTime = millis();
			previousState= ButtonState::ON;
		}
	}else{
		previousState= ButtonState::OFF;
	}
}
int Button::getSerialTime(){
	return serialDelay*1000;
}

void Button::ChangeTime(){
	switch(serialDelay) {
  	case 5:
    	Serial.println("Serial output time increased from 5 seconds to 10");
		serialDelay = 10;
    	break;
  	case 10:
	  Serial.println("Serial output time increased from 10 seconds to 30");
	  serialDelay = 30;
    	break;
	case 30:
		Serial.println("Serial output time increased from 30 seconds to 60");
		serialDelay = 60;
    	break;
	case 60:
		Serial.println("Serial output time increased from 60 seconds to 120");
		serialDelay = 120;
    	break;
	case 120:
		Serial.println("Serial output time increased from 120 seconds to 300");
		serialDelay = 300;
    	break;
	case 300:
		Serial.println("Serial output time decreased from 300 seconds to 5");
		serialDelay =5;
    	break;
}

}
bool Button::timeDiff(unsigned long start, int specifiedDelay) {
	return (millis() - start >= specifiedDelay);
}
