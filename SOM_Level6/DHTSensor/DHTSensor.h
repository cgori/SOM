
/*
 * DHTSensor.h
 *
 *  Created on: 17 Feb 2020
 *      Author: cmprharr
 */

#ifndef INPUTS_DHTSENSOR_DHTSENSOR_H_
#define INPUTS_DHTSENSOR_DHTSENSOR_H_
#include <DHT.h>

class DHTSensor {
public:
	DHTSensor();
	virtual ~DHTSensor();
	void setupDHT();
	void readDHT();
	void GetHeat(float *q);
private:
	int lastPos = 0;
	float humidity[500];
	float temperature[500];
};

#endif /* INPUTS_DHTSENSOR_DHTSENSOR_H_ */
