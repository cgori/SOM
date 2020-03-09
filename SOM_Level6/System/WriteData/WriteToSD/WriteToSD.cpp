/*
 * WriteToSD.cpp
 *
 *  Created on: 3 Mar 2020
 *      Author: cmpimard
 */

#include "WriteToSD.h"
#include <SD.h>
#include <SPI.h>

File file;
const int CS_Pin = 5;

WriteToSD::WriteToSD() {
//		  file.close();
//		  SD.end();
}

WriteToSD::~WriteToSD() {
	// TODO Auto-generated destructor stub
}

bool WriteToSD::WritingSD(std::vector<float> heat,
		std::vector<float> humidity) {
	if(!SD.begin(CS_Pin)){
		Serial.println("Failed to open");
		while(1);
	}
	File file = SD.open("data.txt", FILE_WRITE);

	// TODO Auto-generated constructor stub

	if (!file) {
		Serial.println("File doens't exist");
	}
	// if the file didn't open, print an error:
	else {
		Serial.println("SD CARD OPENED");
		for (auto const& value : heat) {
			if (file.print(int(value))) {
				Serial.println("File written");
			} else {
				Serial.println("Write failed");
			}
		}
		file.flush(); //saving the file
		file.close();
		SD.end();
	}

	return true;
}
