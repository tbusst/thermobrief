#include "utils.h"

String connectToWifi() {
  WiFi.mode(WIFI_STA); // Optional
  WiFi.begin(SSID, PASSWORD);
  Serial.println("\nConnecting");

  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(100);
  }

  Serial.println("\nConnected to the WiFi network");
  return WiFi.localIP().toString();
}