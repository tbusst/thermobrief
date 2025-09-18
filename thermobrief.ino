#include <dht11.h>
#include "utils.h"
#include "display.h"

#define DHT11PIN 32

dht11 DHT11;

void setup() {
  //Serial.begin(9600);
  esp_log_level_set("*", ESP_LOG_NONE);
  pinMode(18, INPUT);
  pinMode(17, INPUT);
  pinMode(16, INPUT);

  initScreen();
  String ip = connectToWifi();
}

void loop() {
    int chk = DHT11.read(DHT11PIN);
    float humidity = DHT11.humidity;
    float temperature = DHT11.temperature;
}