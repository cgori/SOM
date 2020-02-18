#include "Arduino.h"
#include "./DHTSensor/DHTSensor.h"
DHTSensor dht_;
boolean timeDiff(unsigned long start, int specifiedDelay) {
	return (millis() - start >= specifiedDelay);
}

void setup() {
	//dht_.
	dht_.readDHT();
	Serial.begin(115200);

}





void loop() {
	dht_.readDHT();

	float heat[500];
	dht_.GetHeat(heat);
	for(int i =0; i<500; i++){
		Serial.println(heat[i]);
	}

}
