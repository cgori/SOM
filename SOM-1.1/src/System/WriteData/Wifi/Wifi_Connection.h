#ifndef SYSTEM_WRITEDATA_Wifi_Connection_Wifi_Connection_H_
#define SYSTEM_WRITEDATA_Wifi_Connection_Wifi_Connection_H_
#include "Arduino.h"
class Wifi_Connection {
public:
    Wifi_Connection();
	virtual ~Wifi_Connection();
    void sendData(std::vector<float>,std::vector<float>, std::vector<long int>);
    long getTime();
    void printLocalTime();
    int concat(int, int);
private:
    unsigned long wifiTime;

};
#endif /* SYSTEM_WRITEDATA_RGB_RGB_H_ */
