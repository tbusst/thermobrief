#include "display.h"

int x = 0;
unsigned long lastXIncrease = 0;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
U8G2_FOR_ADAFRUIT_GFX u8g2Fonts;

void initScreen() {
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  u8g2Fonts.begin(display);

  // Splash screen
  display.clearDisplay();
  display.setTextColor(WHITE);
  u8g2Fonts.setFont(u8g2_font_9x15_mf);
  String splashString = "ThermoBrief";
  int splashWidth = u8g2Fonts.getUTF8Width(splashString.c_str());
  int xPos = (SCREEN_WIDTH - splashWidth)/2;
  int yPos = (SCREEN_HEIGHT+15)/2;
  u8g2Fonts.setCursor(xPos, yPos);
  u8g2Fonts.println(splashString);
  display.display(); 

  delay(2000);
  display.clearDisplay();

  u8g2Fonts.setFont(u8g2_font_5x8_mf);
  u8g2Fonts.setCursor(0, 10);
}

void displayWiFi(String ip, String SSID) {
  u8g2Fonts.setFont(u8g2_font_6x10_mf);
  u8g2Fonts.setCursor(0, 0);
  u8g2Fonts.println("Connected to");
  u8g2Fonts.println(SSID);
  u8g2Fonts.println("Local ESP32 IP: ");
  u8g2Fonts.println(ip);
  display.display();
}