/*
 * RGB.cpp
 *
 *  Created on: 18 Feb 2020
 *      Author: cmprharr
 */

#include "RGB.h"

RGB::RGB() {
	pinMode(greenPin, OUTPUT);
	pinMode(redPin, OUTPUT);

}

RGB::~RGB() {
}

void RGB::turneRedLEDOn() {

	digitalWrite(redPin, HIGH);
}

void RGB::turnGreenLEDOn() {
	digitalWrite(greenPin, HIGH);
}

void RGB::LEDOFF() {
	digitalWrite(redPin, LOW);
	digitalWrite(greenPin, LOW);
}

