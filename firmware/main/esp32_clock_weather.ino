#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include "time.h"

// =============================
// USER CONFIGURATION
// =============================

const char* ssid     = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

String apiKey        = "YOUR_OPENWEATHER_API_KEY";
String city          = "Mumbai";
String countryCode   = "IN";

// =============================
// TIME CONFIGURATION
// =============================

const char* ntpServer = "pool.ntp.org";
const long gmtOffset_sec = 19800; // IST
const int daylightOffset_sec = 0;

// =============================
// OLED CONFIGURATION
// =============================

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_SDA 2
#define OLED_SCL 15

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// =============================
// SETUP
// =============================

void setup() {

  Serial.begin(115200);

  Wire.begin(OLED_SDA, OLED_SCL);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED initialization failed");
    while(true);
  }

  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(15,15);
  display.println("HELLO");

  display.setTextSize(1);
  display.setCursor(15,40);
  display.println("Connecting...");
  display.display();

  // WiFi Connection
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  // Time Sync
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);

  display.clearDisplay();
  display.setCursor(15,25);
  display.println("ONLINE & SYNCED");
  display.display();

  delay(1500);
}

// =============================
// LOOP
// =============================

void loop() {

  if (WiFi.status() == WL_CONNECTED) {

    HTTPClient http;

    String url = "http://api.openweathermap.org/data/2.5/weather?q=" 
                + city + "," + countryCode 
                + "&APPID=" + apiKey 
                + "&units=metric";

    http.begin(url);

    int httpCode = http.GET();

    display.clearDisplay();

    // TIME DISPLAY
    struct tm timeinfo;

    if(getLocalTime(&timeinfo)) {

      display.setTextSize(3);
      display.setCursor(20,8);

      display.printf("%02d:%02d",
      timeinfo.tm_hour,
      timeinfo.tm_min);

    }

    display.drawLine(0,38,128,38,WHITE);

    // WEATHER DISPLAY
    if (httpCode > 0) {

      String payload = http.getString();

      StaticJsonDocument<1024> doc;

      deserializeJson(doc, payload);

      float temp = doc["main"]["temp"];

      const char* weatherDesc =
      doc["weather"][0]["main"];

      display.setTextSize(1);

      display.setCursor(10,45);
      display.printf("Temp: %.1f C", temp);

      display.setCursor(10,55);
      display.print("Weather: ");
      display.print(weatherDesc);

    }

    display.display();

    http.end();
  }

  delay(60000);
}