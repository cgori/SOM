/*
 * Buzzer.cpp
 *
 *  Created on: 20 Feb 2020
 *      Author: cmprharr
 */

#include "Buzzer.h"

Buzzer::Buzzer() {
	// TODO Auto-generated constructor stub
	ledcSetup(channel, freq, resolution);
	ledcAttachPin(buzzerPin, channel);
}

Buzzer::~Buzzer() {
	// TODO Auto-generated destructor stub
}

void Buzzer::turnBuzzerON(){
	ledcWriteTone(channel, 100);
}
void Buzzer::turnBuzzerOFF(){
	ledcWriteTone(channel, 0);
}


SnoozeState Buzzer::checkSnooze(){
	if(this->btn.checkState() == ButtonState::ON){
		Serial.println("Button pressed 2min sleep");
		this->time = millis();
		this->snoozeState = SnoozeState::SLEEPING;

	}else{
		this->snoozeState = SnoozeState::RUNNING;
	}
	return this->snoozeState;
}

long Buzzer::getTime(){
	return this->time;
}
