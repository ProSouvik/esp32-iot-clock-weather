# ESP32 IoT Clock + Weather Display

A minimal ESP32 IoT project that connects to WiFi, synchronizes time using NTP, fetches weather data from the OpenWeather API, and displays the results on an OLED screen.

This repository focuses on a **clean reproducible baseline** before expanding the system into a larger IoT companion device.

---

## Features

* WiFi connection using ESP32
* Automatic time synchronization via NTP
* Weather data retrieval using OpenWeather API
* OLED display output (SSD1306 128x64)

---

## Hardware

* ESP32 DevKit
* SSD1306 OLED Display (I2C)

---

## Example Output

The OLED shows:

Time (HH:MM)

Temperature

Weather condition

Example:

22:48

Temp: 29.4 C
Weather: Clouds

---

## Folder Structure

```
esp32-iot-clock-weather
│
├── firmware
│   └── main
│       └── esp32_clock_weather.ino
│
├── docs
│   ├── setup.md
│   └── architecture.md
│
├── hardware
│   └── components.md
│
└── media
```

---

## Setup

Follow the setup instructions in:

```
docs/setup.md
```

---

## Future Improvements

Planned expansions:

* sensor integration
* animations
* emotion-based display
* ESP32-CAM visual input
* IoT dashboard
