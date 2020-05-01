#include "Arduino.h"
#include "System/System.h"
#include <Wire.h>
System sys;
void setup() {
	Serial.begin(115200);
}

void loop() {
	sys.readSensors();
	sys.checkStates();
	sys.writeData();
}