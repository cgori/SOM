
/*
 * DHTSensor.cpp
 *
 *  Created on: 17 Feb 2020
 *      Author: cmprharr
 */

#include "DHTSensor.h"
#include <DHT.h>
#define DHTTYPE DHT22
const int DHTPIN = 14;
DHT dht(DHTPIN, DHTTYPE);

DHTSensor::DHTSensor() {
	dht.begin();
	readDHT();

	// TODO Auto-generated constructor stub

}

DHTSensor::~DHTSensor() {
	// TODO Auto-generated destructor stub
}
void DHTSensor::GetHeat(float *heat){
	for(int i =0; i < 500; i++){
		heat[0] = this->humidity[i];
	}

}

void DHTSensor::readDHT(){
	this->humidity[lastPos] = dht.readHumidity();
	this->temperature[lastPos++] = dht.readTemperature();


}
