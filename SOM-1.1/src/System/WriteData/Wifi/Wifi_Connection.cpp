
#include "Wifi_Connection.h"
#include "WiFi.h"
#include "ArduinoJson.h"
#include <HTTPClient.h>
#include <Arduino.h>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

String serverName = "http://51.38.71.106/api/DHT";
String token = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJ1c2VyIjp7Il9pZCI6IjVlYTFhOTdlYTc2ZGEwNDUyNDg0MjVlNiIsInVzZXJuYW1lIjoiYWRtaW4iLCJwYXNzd29yZCI6IjA5NzliZjZjMTE3NjI2ZmJiOGJlMjFmZjY1OTBkMjIzIiwiX192IjowfSwiaWF0IjoxNTg3NjUzMTEwLCJleHAiOjE2NzQwNTMxMTB9.M--ry9qOxbbyO48p17eWa3VKjNi92qLwNXrtkYMWCqU";
//Your Domain name with URL path or IP address with path

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastTime = 0;
// Timer set to 10 minutes (600000)
//unsigned long timerDelay = 600000;
// Set timer to 5 seconds (5000)
unsigned long timerDelay = 5000;

Wifi_Connection::Wifi_Connection(){
}

Wifi_Connection::~Wifi_Connection() {

}
void Wifi_Connection::sendData(std::vector<float> humidity, std::vector<float> temperature){

    if (WiFi.status() == WL_CONNECTED)
    {
      // generate document
      StaticJsonDocument<200> doc;
      JsonArray data = doc.createNestedArray("results");
      for (int i = 0; i < temperature.size(); i++)
      {
        JsonObject nested = data.createNestedObject();
        nested["humidity"] = humidity[i];
        nested["temperature"] = temperature[i];
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
        String payload = http.getString();
        Serial.println(payload);
        this->epoch = payload.toInt();

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

int Wifi_Connection::getEpoch(){
  return this->epoch;
}