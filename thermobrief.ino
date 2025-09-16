#include <dht11.h>

#include "display.h"

#define DHT11PIN 32

dht11 DHT11;

void setup() {
  Serial.begin(9600);

  pinMode(18, INPUT);
  pinMode(17, INPUT);
  pinMode(16, INPUT);

  initScreen();
}

void loop() {
    Serial.println();
    int chk = DHT11.read(DHT11PIN);

    Serial.print("Humidity (%): ");
    Serial.println((float)DHT11.humidity, 2);

    Serial.print("Temperature  (C): ");
    Serial.println((float)DHT11.temperature, 2);

    delay(2000);
}