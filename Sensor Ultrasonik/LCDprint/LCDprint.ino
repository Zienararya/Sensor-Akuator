#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);
const int pingPin = 7;

void setup(){
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Distance Measurement");
}

void loop(){
  long duration,inches,cm;
  pinMode(pingPin,OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  pinMode(pingPin, INPUT);
  duration=pulseIn(pingPin,HIGH);
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Inches : ");
  lcd.print(inches);
  lcd.setCursor(0, 1);
  lcd.print("Centimeters: ");
  lcd.print(cm);

  delay("100");
}


long microsecondsToInches(long microseconds){
  return microseconds /74/2;
}

long microsecondsToCentimeters(long microseconds){
  return microseconds /29/2;
}