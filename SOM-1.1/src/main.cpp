#include "Arduino.h"
#include "System/System.h"
#include "System/WriteData/LCD/LCD_Write.h"

System sys;
void setup() {
	Serial.begin(115200);

}
LCD_Write temp;

void loop() {
	
	sys.readSensors();
	sys.checkStates();
	sys.writeData();
	temp.test();
}
