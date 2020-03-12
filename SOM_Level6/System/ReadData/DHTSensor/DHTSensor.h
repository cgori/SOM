/*
 * DHTSensor.h
 *
 *  Created on: 18 Feb 2020
 *      Author: cmprharr
 */

#ifndef SYSTEM_READDATA_DHTSENSOR_DHTSENSOR_H_
#define SYSTEM_READDATA_DHTSENSOR_DHTSENSOR_H_
#include <vector>
class DHTSensor {
public:
	DHTSensor();
	virtual ~DHTSensor();
	std::vector<float> getHeat();
	std::vector<float> getHumidity();
	void readDHT();
	long getTime();



private:
	std::vector<float> heat;
	std::vector<float> humid;
	unsigned long time;

};

#endif /* SYSTEM_READDATA_DHTSENSOR_DHTSENSOR_H_ */
