#include <Arduino.h>
#include "led.h++"
#include "server.h++"


unsigned long lastTime = 0;
// Timer set to 10 minutes (600000)
// unsigned long timerDelay = 600000;
// Set timer to 5 seconds (5000)
unsigned long timerDelay = 5000;

void setup()
{
  Serial.begin(9600);
  Serial.println("Serial Started");

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

postRequest(1, "yellow-button", "John David");

}