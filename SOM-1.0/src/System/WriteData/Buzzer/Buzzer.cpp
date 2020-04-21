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

