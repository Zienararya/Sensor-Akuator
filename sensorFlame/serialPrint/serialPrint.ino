const int sensorMin = 0;
const int sensorMax = 1024;

void setup() {
  Serial.begin(9600);

}

void loop() {
  int sensorReading = analogRead(A3);
  int range = map(sensorReading, sensorMin, SensorMax, 0, 3);
  Serial.println(sensorReading);
}
