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
	void changeSerialTime();
	void keyPress();
	void keyRelease();
	void check();
	void ChangeTime();
	int getSerialTime();
	bool timeDiff(unsigned long, int);
private:
	const long buttonDelay = 1000;
	unsigned long lastChangeTime;
	ButtonState previousState;
	int serialDelay =5;
	const int BOUNCE_DELAY_MS = 5;
	int buttonPin = 25;
	int buttonSerialChangeTime = 14;
	ButtonState debouncedState = ButtonState::OFF;
	ButtonState bouncedState = ButtonState::OFF;
	long lastChange;
	void deBounce();
	unsigned long keyPrevMillis = 0;
	const unsigned long keySampleIntervalMs = 20;
	byte longKeyPressCountMax = 50;    // 80 * 25 = 2000 ms
	byte longKeyPressCount = 0;
	byte prevKeyState = HIGH;         // button is active low

};

#endif /* SYSTEM_READDATA_BUTTON_BUTTON_H_ */
