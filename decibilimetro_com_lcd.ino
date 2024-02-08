#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const byte sensorSOM = A2;
int som = 0;

void setup() {
  Serial.begin(9500);
  pinMode(sensorSOM, INPUT);
  lcd.begin(16, 2);
}

void loop() {
  som = 512 - abs(analogRead(A0));
  Serial.println(som);
  if (som > 130) {
    lcd.setCursor(3, 0);
    lcd.print("VOCE ESTA");
    lcd.setCursor(3, 1);
    lcd.print("FALANDO ALTO!");
    delay(5000);
    lcd.clear();
  }
}
