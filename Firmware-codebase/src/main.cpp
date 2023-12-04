#include <Arduino.h>
#include "led.h++"
#include "server.h++"


String serverName = "https://api.weather.gov/points";

String applePark = "/37.3344481,-122.0082942";

unsigned long lastTime = 0;
// Timer set to 10 minutes (600000)
// unsigned long timerDelay = 600000;
// Set timer to 5 seconds (5000)
unsigned long timerDelay = 5000;

void setup()
{
  Serial.begin(115200);
  Serial.println("Serial Began");

  // WiFi Setup
  wifi_setup();

  // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.begin();
  pixels.setBrightness(20); // not so bright

  // LED Shining for test purpose
  led_shine();
}

void loop()
{

  if (WiFi.status() == WL_CONNECTED)
  {
  HTTPClient http;

    // Serial.println(httpGETRequest(serverName));
    String get_req_name = serverName + applePark;
    // Serial.println(get_req_name);
    // httpGETRequest("https://api.weather.gov/points/37.3344481,-122.0082942");
  http.begin(serverName.c_str());

  int httpResponseCode = http.GET();
  String payload = "{}"; 
  
  if (httpResponseCode>0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  Serial.print(payload);
  // Free resources
  http.end();
  }
  else {
      Serial.println("WiFi Disconnected");
    }
  // clientHandle();

  // nothing
}