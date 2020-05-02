#ifndef SYSTEM_WRITEDATA_LCD_WRITE_LCD_WRITE_H_
#define SYSTEM_WRITEDATA_LCD_WIRTE_LCD_WRITE_H_
#include "Arduino.h"
#include <LiquidCrystal_I2C.h>
#include "../../CheckStates/EnumStates/SystemState.h"
class LCD_Write {
public:
    LCD_Write();
	virtual ~LCD_Write();
    void setup();
    void writeData(SystemState);
private:
    bool timeDiff(unsigned long, int);
    int lcdColumns = 16;
    int lcdRows = 2;
    bool hasSetup = false;
    int lcdDelay = 1000;
    unsigned int lastChangelcd =0;
    LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, lcdColumns, lcdRows);
    SystemState sysState;
};
#endif /* SYSTEM_WRITEDATA_RGB_RGB_H_ */
