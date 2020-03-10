#include "Arduino.h"
#include "System/ReadData/DHTSensor/DHTSensor.h"
#include "System/System.h"
#include <iostream>
#include <vector>
DHTSensor dht_;
System sys;
void setup() {
	Serial.begin(115200);


}


void loop() {
	sys.readSensors();
	sys.checkStates();
	sys.writeData();


	/*dht_.readDHT();
	std::vector<float> heat = dht_.getHeat();*/
	/*for (std::vector<float>::iterator i1 = heat.begin() ; i1 != heat.end(); ++i1)
	    std::cout << ' ' << *i1;
	  std::cout << '\n';*/

	//Serial.println(heat.back());


}
