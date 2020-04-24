#include "Arduino.h"
#include "System/System.h"
#include "WiFi.h"

System sys;
void setup() {
	Serial.begin(115200);
}

void loop() {
	sys.readSensors();
	sys.checkStates();
	sys.writeData();
}