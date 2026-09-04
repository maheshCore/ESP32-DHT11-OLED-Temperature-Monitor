#include "DHT.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define DHTPIN 4
#define DHTTYPE DHT11

#define OLED_SDA 21
#define OLED_SCL 22

DHT dht(DHTPIN, DHTTYPE);

// 3 LEDs
int leds[] = {18, 19, 23};

// 1.3" OLED - usually SH1106
Adafruit_SH1106G display = Adafruit_SH1106G(128, 64, &Wire);

void setup() {

  Serial.begin(115200);

  dht.begin();

  // LEDs
  for (int i = 0; i < 3; i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);
  }

  // OLED
  Wire.begin(OLED_SDA, OLED_SCL);

  if (!display.begin(0x3C, true)) {
    Serial.println("OLED not found!");
    while (1);
  }

  display.clearDisplay();
  display.setTextColor(SH110X_WHITE);

  display.setTextSize(2);
  display.setCursor(10, 10);
  display.println("DHT11");

  display.display();
  delay(2000);
}

void loop() {

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("DHT11 ERROR");

    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(10, 20);
    display.println("DHT ERROR");
    display.display();

    delay(2000);
    return;
  }

  // Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" C   Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");


  // =========================
  // 3 LED TEMPERATURE CONTROL
  // =========================

  // Turn OFF all LEDs
  for (int i = 0; i < 3; i++) {
    digitalWrite(leds[i], LOW);
  }

  if (temperature >= 32.0) {

    // 3 LEDs
    digitalWrite(leds[0], HIGH);
    digitalWrite(leds[1], HIGH);
    digitalWrite(leds[2], HIGH);

  }
  else if (temperature >= 30.0) {

    // 2 LEDs
    digitalWrite(leds[0], HIGH);
    digitalWrite(leds[1], HIGH);

  }
  else {

    // 1 LED
    digitalWrite(leds[0], HIGH);
  }


  // =========================
  // OLED DISPLAY
  // =========================

  display.clearDisplay();

  display.setTextColor(SH110X_WHITE);

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("TEMPERATURE");

  display.setTextSize(2);
  display.setCursor(10, 15);
  display.print(temperature, 1);
  display.println(" C");

  display.setTextSize(1);
  display.setCursor(0, 45);
  display.print("Humidity: ");

  display.print(humidity, 1);
  display.println(" %");

  display.display();

  delay(2000);
}