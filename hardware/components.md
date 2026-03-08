# Hardware Components

## Components

ESP32 DevKit
SSD1306 OLED Display (128x64 I2C)

---

## OLED Wiring

| OLED Pin | ESP32 Pin |
| -------- | --------- |
| VCC      | 3.3V      |
| GND      | GND       |
| SDA      | GPIO2     |
| SCL      | GPIO15    |

---

## Notes

The firmware uses custom I2C initialization:

```
Wire.begin(2, 15);
```

This assigns:

SDA → GPIO2
SCL → GPIO15
