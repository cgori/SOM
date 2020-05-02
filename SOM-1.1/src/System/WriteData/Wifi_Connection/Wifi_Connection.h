#ifndef SYSTEM_WRITEDATA_WIFI_CONNECTION_WIFI_CONNECTION_H_
#define SYSTEM_WRITEDATA_WIFI_CONNECTION_WIFI_CONNECTION_H_
#include "Arduino.h"
class Wifi_Connection {
public:
    Wifi_Connection();
	virtual ~Wifi_Connection();
    void sendData(std::vector<float>,std::vector<float>, std::vector<long int>);
    long getTime();
    void printLocalTime();
    int concat(int, int);
    void setup();
private:
    unsigned long wifiTime;
    bool hasSetup = false;

};
#endif /* SYSTEM_WRITEDATA_RGB_RGB_H_ */
