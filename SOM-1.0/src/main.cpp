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

}
