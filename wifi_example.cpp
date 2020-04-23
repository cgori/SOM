#include "WiFi.h"
#include "ArduinoJson.h"
#include <HTTPClient.h>
#include <Arduino.h>
const char *ssid = "";
const char *password = "";
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

void setup()
{
  Serial.begin(9600);

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

  Serial.println("Timer set to 5 seconds (timerDelay variable), it will take 5 seconds before publishing the first reading.");
}

void loop()
{
  //Send an HTTP POST request every 10 minutes
  if ((millis() - lastTime) > timerDelay)
  {
    //Check WiFi connection status
    if (WiFi.status() == WL_CONNECTED)
    {
      // Create the payload
      int vector_size = 5;
      StaticJsonDocument<200> doc;
      JsonArray data = doc.createNestedArray("data");
      for (int i = 0; i < vector_size; i++)
      {
        JsonObject nested = data.createNestedObject();
        nested["humidity"] = "insert humidity data";
        nested["temperature"] = "insert temperature data";
      }

      serializeJsonPretty(doc, Serial);

      HTTPClient http;
      // Your Domain name with URL path or IP address with path
      http.begin(serverName);
      http.addHeader("token", token, false, false);
      // Send HTTP GET request
      int httpResponseCode = http.POST("POST STRING DATA HERE");

      if (httpResponseCode > 0)
      {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        String payload = http.getString();
        Serial.println(payload);
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
    lastTime = millis();
  }
}