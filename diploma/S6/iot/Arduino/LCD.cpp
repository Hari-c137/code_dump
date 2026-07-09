#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);
int dataFromA0;
float voltage;
float temperature;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Starting...");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temperature: ");
}

void loop() {
  dataFromA0 = analogWrite(A0);
  voltage = 5.0 * dataFromA0 / 1023;
  temperature = (voltage - 0.5) * 100;

  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print(temperature);
  lcd.print(" C");
  delay(1000);
}
