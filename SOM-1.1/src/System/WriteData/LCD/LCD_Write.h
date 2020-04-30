#ifndef SYSTEM_WRITEDATA_LCD_Write_LCD_Write_H_
#define SYSTEM_WRITEDATA_LCD_Write_LCD_Write_H_
#include "Arduino.h"
#include <SPI.h>

class LCD_Write {
// ==============================================================
// EDIT USER_SETUP.H FOR TFT_eSPI TO SET CORRECT PINS AND MODULES
// ==============================================================

public: 
    LCD_Write();
	virtual ~LCD_Write();
    void testdrawtext(char *, uint16_t);
    void displayStatus();
private:


};
#endif /* SYSTEM_WRITEDATA_RGB_RGB_H_ */