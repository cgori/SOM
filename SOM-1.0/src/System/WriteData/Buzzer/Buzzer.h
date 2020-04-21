/*
 * Buzzer.h
 *
 *  Created on: 20 Feb 2020
 *      Author: cmprharr
 */

#ifndef SYSTEM_WRITEDATA_BUZZER_BUZZER_H_
#define SYSTEM_WRITEDATA_BUZZER_BUZZER_H_
#include "Arduino.h"
class Buzzer {
public:
	Buzzer();
	virtual ~Buzzer();
	void turnBuzzerON();
	void turnBuzzerOFF();
private:
	int buzzerPin = 26;
	int freq = 2000;
	int channel = 0;
	int resolution = 8;
};

#endif /* SYSTEM_WRITEDATA_BUZZER_BUZZER_H_ */
