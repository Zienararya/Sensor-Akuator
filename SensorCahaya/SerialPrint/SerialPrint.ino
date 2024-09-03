void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int aSensorReading = analogRead(A0);
  bool dSensorReading = digitalRead(2);

  Serial.print(aSensorReading);
  Serial.print(" ");
  Serial.print(dSensorReading);
}
