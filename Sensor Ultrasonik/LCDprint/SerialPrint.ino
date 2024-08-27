#include <Wire.h>

const int pingPin = 7;

void setup() {
 Serial.begin(9600);

}

void loop() {
 long duration, inches, cm, mm;

 pinMode(pingPin, OUTPUT);
 digitalWrite(pingPin, LOW);
 delayMicroseconds(2);
 digitalWrite(pingPin, HIGH);
 delayMicroseconds(5);
 digitalWrite(pingPin, LOW);

 pinMode(pingPin, INPUT);
 duration = pulseIn(pingPin, HIGH);

 inches = microsecondsToInches(duration);
 cm = microsecondsToCentimeters(duration);
 mm = cm * 10;

 Serial.print(inches);
 Serial.print("inc, ");
 Serial.print(cm);
 Serial.print("cm, ");
 Serial.print(mm);
 Serial.print("mm");
 Serial.println();

 delay(1000);
}

long  microsecondsToInches(long microseconds) {
  return microseconds/74/2;
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds/29/2;
}

