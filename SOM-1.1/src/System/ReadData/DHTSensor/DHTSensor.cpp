/*
 * DHTSensor.cpp
 *
 *  Created on: 18 Feb 2020
 *      Author: cmprharr
 */

#include "DHTSensor.h"
#include <DHT.h>
#include <ctime>
#define DHTTYPE DHT22
const int DHTPIN = 33;
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

float DHTSensor::getTempHeat(){
	return this->tempHeat;

}
float DHTSensor::getTempHumidity(){
	return this->tempHumid;
}

std::vector<long int> DHTSensor::getTime(){
	return this->time;
}

void DHTSensor::saveDHT(){
	if(isnan(dht.readHumidity())){
		Serial.println("not working");
		}else{
			std::time_t temp = std::time(nullptr);
			this->time.push_back(temp);
			this->heat.push_back(dht.readTemperature());
			this->humid.push_back(dht.readHumidity());
		}
}

void DHTSensor::readDHT(){
	if(isnan(dht.readHumidity())){
		Serial.println("not working");
		}else{
			this->tempHeat = dht.readTemperature();
			this->tempHumid = dht.readHumidity();
	}
}

void DHTSensor::wipe(){
	this->time.clear();
	this->heat.clear();
	this->humid.clear();
}
