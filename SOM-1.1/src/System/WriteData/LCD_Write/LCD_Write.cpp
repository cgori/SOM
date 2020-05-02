
#include "LCD_Write.h"
#include <Arduino.h>
LCD_Write::LCD_Write(){
}

LCD_Write::~LCD_Write() {

}
void LCD_Write::setup(){
  if(this->hasSetup == false){
  	lcd.init();                    
  	lcd.backlight();
    this->hasSetup = true;
  }
}

bool LCD_Write::timeDiff(unsigned long start, int specifiedDelay) {
	return (millis() - start >= specifiedDelay);
}

void LCD_Write::writeData(SystemState sysState){
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
  if(sysState == SystemState::GREEN){
		lcd.setCursor(0,1);
		lcd.print("System Green");
	}else if(sysState == SystemState::AMBER){
		lcd.setCursor(0,1);
		lcd.print("System Amber");
	}else if(sysState == SystemState::RED){
		lcd.setCursor(0,1);
		lcd.print("System Critical");
	}else{
		lcd.setCursor(0,1);
		lcd.print("System Unknown");
	}
	lastChangelcd = millis();
	}
}