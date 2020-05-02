#include "FS.h"
#include "SD.h"
#include "SPI.h"
#include <Arduino.h>
#include "SD_Write.h"
#include <fstream>
#include <string>

#include <iostream>     // std::cout
#include <iterator>     // std::ostream_iterator
#include <vector>       // std::vector
#include <algorithm>    // std::copy

SD_Write::SD_Write(){
}

SD_Write::~SD_Write() {
}

long SD_Write::getTime(){
	return this->sdTime;
}
void SD_Write::setup(){
    if(this->hasSetup == false){
    if(!SD.begin()){
        Serial.println("Card Mount Failed");
        return;
    }
    this->hasSetup=true;
    }
}

void SD_Write::writeFile(std::vector<float> temperature, std::vector<float> humidity, std::vector<long int> time){
    File file = SD.open("/data.txt", FILE_WRITE);
    if(!file){
        Serial.println("Failed to open file for writing");
        return;
    }else{
        String output = "";
        for(int i =0; i < temperature.size(); i++){
            output +="temp: ";
            output += String(temperature[i]);
            output += ", humid: ";
            output += String(humidity[i]);
            output +=", epoch: ";
            output +=String(time[i]);
            file.println(output);
            output= "";
        }
    }
    file.close();
}
void SD_Write::appendFile(){
    File file = SD.open("/data.txt", FILE_APPEND);
    if(!file){
        Serial.println("Failed to open file for appending");
        return;
    }
    if(file.print("message")){
        Serial.println("Message appended");
    } else {
        Serial.println("Append failed");
    }
    file.close();
}

void SD_Write::readFile(){
    myFile = SD.open("/data.txt");
  if (myFile) {
    while (myFile.available()) {
    	Serial.write(myFile.read());
    }
    myFile.close();
  } else {
  	// if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
}