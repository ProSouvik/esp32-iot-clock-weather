# System Architecture

The system consists of an ESP32 microcontroller connected to WiFi.
It communicates with external services to retrieve time and weather information.

---

## Data Flow

```
Internet
   |
   |------ NTP Server
   |
   |------ OpenWeather API
   |
  ESP32
   |
   |------ OLED Display
```

---

## System Operation

1. ESP32 boots
2. OLED shows startup message
3. WiFi connection is established
4. NTP synchronization sets system time
5. HTTP request retrieves weather data
6. Time and weather are rendered on the OLED display

---

## Update Cycle

Weather data is refreshed every:

```
60 seconds
```
