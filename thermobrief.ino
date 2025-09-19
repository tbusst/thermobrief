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

  // // Set display inputs
  pinMode(18, INPUT);
  pinMode(17, INPUT);
  pinMode(16, INPUT);

  pinMode(BUTTON, INPUT);

  // Init
  initScreen();
  String ip = connectToWifi();
  displayWiFi(ip, SSID);
  
  // // Test chat-gpt intergration
  // String reply = contactApi("this is an api test!");
  // Serial.print(reply);
}



void loop() {
    // Read sensor data
    int chk = DHT11.read(DHT11PIN);
    float humidity = DHT11.humidity;
    float temperature = DHT11.temperature;

    // Debounce
    if (digitalRead(BUTTON) == 1 && !buttonPressed) {
      buttonPressed = true;
      Serial.println("pressed");
    } else if (digitalRead(BUTTON) != 1) {
      buttonPressed = false;
    }
}