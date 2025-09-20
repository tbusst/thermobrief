#include <dht11.h>
#include "utils.h"
#include "display.h"
#include "gpt_api.h"

#define DHT11PIN 32
#define BUTTON 33

dht11 DHT11;

bool buttonPressed = false;

void setup() {
  Serial.begin(9600);

  // Set display inputs
  pinMode(18, INPUT);
  pinMode(17, INPUT);
  pinMode(16, INPUT);

  pinMode(BUTTON, INPUT);

  // Init
  initScreen();
  String ip = connectToWifi();
  displayWiFi(ip, SSID);
}

void loop() {
    // Read sensor data
    int chk = DHT11.read(DHT11PIN);
    float humidity = DHT11.humidity;
    float temperature = DHT11.temperature;

    // Generated with ChatGPT
    char requestBody[700];
    snprintf(requestBody, sizeof(requestBody),
      "{\"model\":\"gpt-4o-mini\",\"messages\":[{\"role\":\"user\",\"content\":"
      "\"You are writing a fun climate summary for a 128x64 OLED display. "
      "You will be given temperature (C) and humidity (%%). "
      "Produce a short, playful 5-line report that fits neatly on the screen. "
      "Each line should be under 20 characters. "
      "ONLY use plain ASCII characters (A-Z, a-z, 0-9, punctuation). "
      "Do not use emojis, special quotes, or symbols. "
      "Temperature: %dC, Humidity: %d%%\"}]}",
      (int)temperature, (int)humidity
    );

    // Debounce
    if (digitalRead(BUTTON) == 1 && !buttonPressed) {
      buttonPressed = true;
      displayString("Waiting for response...");
      String response = contactApi(requestBody);
      displayString(response);
    } else if (digitalRead(BUTTON) != 1) {
      buttonPressed = false;
    }
}