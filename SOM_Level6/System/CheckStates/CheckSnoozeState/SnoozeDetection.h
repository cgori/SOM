/*
 * SnoozeDetection.h
 *
 *  Created on: 18 Feb 2020
 *      Author: cmprharr
 */

#ifndef SYSTEM_CHECKSTATES_CHECKSNOOZESTATE_SNOOZEDETECTION_H_
#define SYSTEM_CHECKSTATES_CHECKSNOOZESTATE_SNOOZEDETECTION_H_
#include "../enumstates/SnoozeState.h"
#include "../../ReadData/Button/Button.h"

class SnoozeDetection {
public:
	SnoozeDetection();
	virtual ~SnoozeDetection();
private:
	SnoozeState checkSnooze();
	SnoozeState snoozeState = SnoozeState::RUNNING;
	Button btn;

};

#endif /* SYSTEM_CHECKSTATES_CHECKSNOOZESTATE_SNOOZEDETECTION_H_ */
