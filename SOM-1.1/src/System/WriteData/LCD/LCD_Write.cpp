#include "LCD_Write.h"
#include "LiquidCrystal_I2C.h"
LiquidCrystal_I2C lcd(0x27, 16, 2); 
LCD_Write::LCD_Write(){
    lcd.init();                  
    lcd.backlight();
}
LCD_Write::~LCD_Write() {
}
void LCD_Write::displayStatus(){
  // set cursor to first column, first row
  lcd.setCursor(0, 0);
  // print message
  lcd.print("Hello, World!");
  delay(1000);
  // clears the display to print new message
  lcd.clear();
}