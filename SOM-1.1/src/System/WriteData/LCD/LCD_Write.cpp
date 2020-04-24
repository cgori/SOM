/*
 * RGB.cpp
 *
 *  Created on: 18 Feb 2020
 *      Author: cmprharr
 */


#include "LCD_Write.h"
#include "Wifi.h"

LCD_Write::LCD_Write(){
  tft.init();
  tft.fillScreen(TFT_BLACK);
  testdrawtext("Working LCD", TFT_WHITE);
}

LCD_Write::~LCD_Write() {

}

void LCD_Write::test() {
    tft.invertDisplay(true);
    tft.invertDisplay(false);
}
void LCD_Write::testdrawtext(char *text, uint16_t color) {
  tft.setCursor(0, 0);
  tft.setTextColor(color);
  tft.setTextWrap(true);
  tft.print(text);
}