#include "Arduino.h"
#include "System/ReadData/DHTSensor/DHTSensor.h"
#include <iostream>
#include <vector>
DHTSensor dht_;
boolean timeDiff(unsigned long start, int specifiedDelay) {
	return (millis() - start >= specifiedDelay);
}

void setup() {
	//dht_.
	Serial.begin(115200);

}





void loop() {
	dht_.readDHT();
	std::vector<float> heat = dht_.getHeat();
	std::vector<float> humid = dht_.getHumidity();
	std::cout << "contains:";
	for (std::vector<float>::iterator i1 = heat.begin() ; i1 != heat.end(); ++i1)
	    std::cout << ' ' << *i1;
	  std::cout << '\n';

	std::cout << "contains:";
	for (std::vector<float>::iterator i2 = humid.begin() ; i2 != humid.end(); ++i2)
		std::cout << ' ' << *i2;
	  std::cout << '\n';


}
