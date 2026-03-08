# Setup Guide

Follow these steps to run the project.

---

## 1. Install Arduino IDE

Install the latest Arduino IDE.

---

## 2. Install ESP32 Board Package

Add this URL to the Arduino board manager:

```
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
```

Then install **ESP32 by Espressif Systems**.

---

## 3. Install Required Libraries

Install the following libraries using the Arduino Library Manager.

Adafruit SSD1306
Adafruit GFX
ArduinoJson

---

## 4. Configure WiFi and API

Open:

```
firmware/main/esp32_clock_weather.ino
```

Update these fields:

```
const char* ssid     = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

String apiKey        = "YOUR_OPENWEATHER_API_KEY";
```

You can obtain a free API key from:

https://openweathermap.org/api

---

## 5. Upload Firmware

Select the board:

```
ESP32 Dev Module
```

Upload the firmware.

---

## 6. Expected Behavior

After boot:

1. OLED displays boot screen
2. ESP32 connects to WiFi
3. Time sync occurs via NTP
4. Weather data is fetched every 60 seconds
5. OLED displays time and weather
