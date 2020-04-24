/*
 * RGB.h
 *
 *  Created on: 18 Feb 2020
 *      Author: cmprharr
 */

#ifndef SYSTEM_WRITEDATA_LCD_Write_LCD_Write_H_
#define SYSTEM_WRITEDATA_LCD_Write_LCD_Write_H_
#include "Arduino.h"
#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>
class LCD_Write {
// ==============================================================
// EDIT USER_SETUP.H FOR TFT_eSPI TO SET CORRECT PINS AND MODULES
// ==============================================================

public:
    LCD_Write();
	virtual ~LCD_Write();
    TFT_eSPI tft = TFT_eSPI();
    void testdrawtext(char *, uint16_t);
    void test();
private:

};
#endif /* SYSTEM_WRITEDATA_RGB_RGB_H_ */
