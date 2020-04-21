/*
 * DHTSensor.cpp
 *
 *  Created on: 18 Feb 2020
 *      Author: cmprharr
 */

#include "DHTSensor.h"
#include <DHT.h>
#define DHTTYPE DHT22
const int DHTPIN = 14;
DHT dht(DHTPIN, DHTTYPE);
DHTSensor::DHTSensor() {
	dht.begin(55);
	// TODO Auto-generated constructor stub

}

DHTSensor::~DHTSensor() {
	// TODO Auto-generated destructor stub
}
std::vector<float> DHTSensor::getHeat(){
	return this->heat;

}
std::vector<float> DHTSensor::getHumidity(){
	return this->humid;
}

void DHTSensor::readDHT(){
	if(isnan(dht.readHumidity())){
		Serial.println("not working");
		}else{
			this->heat.push_back(dht.readTemperature());
			this->humid.push_back(dht.readHumidity());
		}
}
