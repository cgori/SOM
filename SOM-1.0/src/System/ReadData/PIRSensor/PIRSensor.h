/*
 * PIRSensor.h
 *
 *  Created on: 18 Feb 2020
 *      Author: cmprharr
 */

#ifndef SYSTEM_READDATA_PIRSENSOR_PIRSENSOR_H_
#define SYSTEM_READDATA_PIRSENSOR_PIRSENSOR_H_

class PIRSensor {
public:
	PIRSensor();
	virtual ~PIRSensor();
	int readPIR();
private:
	int PIRPin = 4;
};

#endif /* SYSTEM_READDATA_PIRSENSOR_PIRSENSOR_H_ */
