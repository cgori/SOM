/*
 * RGB.h
 *
 *  Created on: 18 Feb 2020
 *      Author: cmprharr
 */

#ifndef SYSTEM_WRITEDATA_SD_Write_SD_Write_H_
#define SYSTEM_WRITEDATA_SD_Write_SD_Write_H_
#include "Arduino.h"
#include <SPI.h>
#include "FS.h"
#include "SD.h"
#include "SPI.h"
class SD_Write {
public:
    SD_Write();
	virtual ~SD_Write();
    long getTime();
    void setup();
    void writeFile(std::vector<float>,std::vector<float>,std::vector<long int>);
    void appendFile();
    void readFile();
private:
    unsigned long sdTime;
    File myFile;
    bool hasSetup = false;

};
#endif /* SYSTEM_WRITEDATA_RGB_RGB_H_ */
