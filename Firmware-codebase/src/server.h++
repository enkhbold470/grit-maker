#include <WiFi.h>
#include "wifiCred.h++"
#include "FS.h"
#include "HTTPClient.h"
#include <ArduinoJson.h>
// Set web server port number to 80
// WiFiServer server(80);

const char *server = "40.112.165.245";
int port = 8000;

// Variable to store the HTTP request

int wifi_setup(){
  
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("ESP Mac Address: ");
  Serial.println(WiFi.macAddress());
  Serial.print("Subnet Mask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway IP: ");
  Serial.println(WiFi.gatewayIP());
  Serial.print("DNS: ");
  Serial.println(WiFi.dnsIP());
  Serial.print("Hostname: ");
  Serial.println(WiFi.getHostname());

    return 0;
}

void postRequest(int value, char* name, char* device_id){
  StaticJsonDocument<200> doc;
  doc["value"] = value;
  doc["name"] = name;
  doc["device_id"] = device_id;

  // Serialize the JSON object to a string
  String jsonStr;
  serializeJson(doc, jsonStr);

  // Make a POST request
  HTTPClient http;
  http.begin("http://" + String(server) + ":" + String(port) + "/api/sensor_data/");
  http.addHeader("Content-Type", "application/json");

  int httpResponseCode = http.POST(jsonStr);

  if (httpResponseCode > 0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);

    String response = http.getString();
    Serial.println(response);
  } else {
    Serial.print("HTTP Request failed. Error code: ");
    Serial.println(httpResponseCode);
  }

  http.end();

  delay(5000); // Send every 5 seconds
}