int pirPin = 8;
int pirStat = 0;

void setup() {
  pinMode(pirPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  
  pirStat = digitalRead(pirPin);

  if (pirStat == HIGH){
    Serial.println("Ada Objek");
  }else {
    Serial.println("Tidak Ada Objek");
  }
}
