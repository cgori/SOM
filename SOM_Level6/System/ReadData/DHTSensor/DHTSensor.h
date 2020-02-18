/*
 * DHTSensor.h
 *
 *  Created on: 18 Feb 2020
 *      Author: cmprharr
 */

#ifndef SYSTEM_READDATA_DHTSENSOR_DHTSENSOR_H_
#define SYSTEM_READDATA_DHTSENSOR_DHTSENSOR_H_

class DHTSensor {
public:
	DHTSensor();
	virtual ~DHTSensor();
	void getHeat(float *heat);
	void getHumidity(float *humidity);
	void readDHT();

private:
	int lastPos =0;
	float humidity[500];
	float temperature[500];
};

#endif /* SYSTEM_READDATA_DHTSENSOR_DHTSENSOR_H_ */
