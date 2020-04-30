#include "Arduino.h"
#include "System/System.h"
#include <Wire.h>
#include <WiFi.h>
#include "time.h"
#include <LiquidCrystal_I2C.h>
const char *ssid = "VM-guest4587444"; // change this
const char *password = "s$h9SyHRaa5m9b"; // change this
const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 3600;
const int   daylightOffset_sec = 0;
int lcdColumns = 16;
int lcdRows = 2;
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  
System sys;
int lcdDelay = 1000;
unsigned int lastChangelcd =0;
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

	lcd.init();                    
  	lcd.backlight();
}

bool timeDiff(unsigned long start, int specifiedDelay) {
	return (millis() - start >= specifiedDelay);
}

void loop() {
	sys.readSensors();
	sys.checkStates();
	sys.writeData();
	// set cursor to first column, first row

	if (timeDiff(lastChangelcd, lcdDelay)) {
	lcd.clear(); 
	struct tm timeinfo;
  	if(!getLocalTime(&timeinfo)){
    return;
  	}else{
  		lcd.setCursor(0, 0);
  		lcd.print(&timeinfo, "%d %B %H:%M");
	}
	SystemState temp = sys.getSysState();
	if(temp == SystemState::GREEN){
		lcd.setCursor(0,1);
		lcd.print("System Green");
	}else if(temp == SystemState::AMBER){
		lcd.setCursor(0,1);
		lcd.print("System Amber");
	}else if(temp == SystemState::RED){
		lcd.setCursor(0,1);
		lcd.print("System Critical");
	}else{
		lcd.setCursor(0,1);
		lcd.print("System Unknown");
	}
	lastChangelcd = millis();
	}
}