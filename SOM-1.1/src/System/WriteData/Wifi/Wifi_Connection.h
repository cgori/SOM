/*
 * RGB.h
 *
 *  Created on: 18 Feb 2020
 *      Author: cmprharr
 */

#ifndef SYSTEM_WRITEDATA_Wifi_Connection_Wifi_Connection_H_
#define SYSTEM_WRITEDATA_Wifi_Connection_Wifi_Connection_H_
#include "Arduino.h"
class Wifi_Connection {
public:
    Wifi_Connection();
	virtual ~Wifi_Connection();
    void sendData(std::vector<float>,std::vector<float>);
    long getTime();
    int getEpoch();
private:
    unsigned long wifiTime;
    int epoch;

};
#endif /* SYSTEM_WRITEDATA_RGB_RGB_H_ */
