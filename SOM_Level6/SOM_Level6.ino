#include "Arduino.h"
#include "System/ReadData/DHTSensor/DHTSensor.h"
#include "System/System.h"
#include <iostream>
#include <vector>
#include <SD.h>
DHTSensor dht_;
System sys;
#define CS_pin = 15;

void setup() {
	SD.begin(115200);
	File file = SD.open("data.txt", FILE_WRITE);
	file.println("The file is prepared");
	file.close();
	SD.end();
//	delay(200);
//	    while(! SD.begin(15)){
//	    }
//	    Serial.println("SD OK");
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
