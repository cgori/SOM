
#include "Wifi_Connection.h"
#include "WiFi.h"
#include "ArduinoJson.h"
#include <HTTPClient.h>
#include <Arduino.h>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "time.h"
String serverName = "http://51.38.71.106/api/DHT";
String token = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJ1c2VyIjp7Il9pZCI6IjVlYTFhOTdlYTc2ZGEwNDUyNDg0MjVlNiIsInVzZXJuYW1lIjoiYWRtaW4iLCJwYXNzd29yZCI6IjA5NzliZjZjMTE3NjI2ZmJiOGJlMjFmZjY1OTBkMjIzIiwiX192IjowfSwiaWF0IjoxNTg3NjUzMTEwLCJleHAiOjE2NzQwNTMxMTB9.M--ry9qOxbbyO48p17eWa3VKjNi92qLwNXrtkYMWCqU";
const char *ssid = "VM-guest4587444"; // change this
const char *password = "s$h9SyHRaa5m9b"; // change this
const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 3600;
const int   daylightOffset_sec = 0;


Wifi_Connection::Wifi_Connection() {

}

Wifi_Connection::~Wifi_Connection() {

}
void Wifi_Connection::sendData(std::vector<float> temperature, std::vector<float> humidity, std::vector<long int> time){
    if (WiFi.status() == WL_CONNECTED)
    {

      // generate document
      StaticJsonDocument<2000> doc;
      JsonArray data = doc.createNestedArray("results");
      for (int i = 0; i < temperature.size(); i++)
      {
        JsonObject nested = data.createNestedObject();
        nested["recorded"] = time[i];
        nested["temperature"] = temperature[i];
        nested["humidity"] = humidity[i];
      }
      String x;
      serializeJsonPretty(doc, x);
      // create http client
      HTTPClient http;
      http.begin(serverName);
      http.addHeader("Content-Type", "application/json");
      http.addHeader("token", token, false, false);
      // Send HTTP POST request
      int httpResponseCode = http.POST(x);

      // Handle response data
      if (httpResponseCode > 0)
      {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
      }
      else
      {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
      }
      // Free resources
      http.end();
    }
    else
    {
      Serial.println("WiFi Disconnected");
    }
    this->wifiTime = millis();
}

long Wifi_Connection::getTime(){
	return this->wifiTime;
}

void Wifi_Connection::printLocalTime()
{
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return;
  }
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
}

void Wifi_Connection::setup(){
  if(this->hasSetup == false){
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
  this->hasSetup = true;
  }
}