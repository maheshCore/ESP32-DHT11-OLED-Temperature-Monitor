# ESP32 DHT11 Temperature Monitoring System

## Project Overview

This project uses an ESP32 with a DHT11 sensor to measure
temperature and humidity. The values are displayed on a
1.3-inch I2C SH1106 OLED display.

Three LEDs indicate the temperature level.

## Components

- ESP32
- DHT11
- 1.3-inch I2C SH1106 OLED
- 3 LEDs
- 3 × 220Ω resistors
- Breadboard
- Jumper wires

## Pin Connections

| Component | ESP32 Pin |
|---|---|
| DHT11 DATA | GPIO 4 |
| OLED SDA | GPIO 21 |
| OLED SCL | GPIO 22 |
| LED 1 | GPIO 18 |
| LED 2 | GPIO 19 |
| LED 3 | GPIO 23 |

## Features

- Temperature monitoring
- Humidity monitoring
- OLED display
- 3-level LED temperature indication
- Serial Monitor output

## Author

Mahesh Kumar
