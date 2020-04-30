#include "Arduino.h"
#include "System/System.h"
#include <Wire.h>
#include <WiFi.h>
#include "time.h"
const char *ssid = ""; // change this
const char *password = ""; // change this
const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 3600;
const int   daylightOffset_sec = 0;
System sys;
void setup() {
	Serial.begin(115200);
	WiFi.begin(ssid, password);
  	Serial.println("Connecting");
  	while (WiFi.status() != WL_CONNECTED)
  	{
    	delay(500);
    	Serial.print(".");
  	}
  	Serial.println("");
  	Serial.print("Connected to WiFi network with IP Address: ");
  	Serial.println(WiFi.localIP());
	configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
}

void loop() {
	sys.readSensors();
	sys.checkStates();
	sys.writeData();
}