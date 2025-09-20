#include "display.h"

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Initializes the screen
void initScreen() {
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);  // 1 = normal size (6x8 per char)
  
  // Splash screen
  String splashString = "ThermoBrief";
  int16_t x1, y1;
  uint16_t w, h;
  display.getTextBounds(splashString, 0, 0, &x1, &y1, &w, &h);
  int xPos = (SCREEN_WIDTH - w) / 2;
  int yPos = (SCREEN_HEIGHT - h) / 2;
  
  display.setCursor(xPos, yPos);
  display.println(splashString);
  display.display();

  delay(2000);
  display.clearDisplay();
}

// Displays wifi info
void displayWiFi(String ip, String SSID) {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(1); // normal font
  display.println("Connected to:");
  display.println(SSID);
  display.println("Local ESP32 IP:");
  display.println(ip);
  display.display();
}

// Display any string
void displayString(String string) {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(1);

  display.println(string);
  display.display();
}