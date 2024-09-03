#include "DHT.h"
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.printIn("DHT11!");
  dht.begin();
}

void loop() {
  delay(2000);
  //Pembacaan untuk data kelembapan
  float humidity_1 = dht.readHumidity();
  //Pembacaan dalam format celcius (c)
  float celcius_1 = dht.readTemperature();
  //Pembacaan dalam format Fahrenheit
  float fahrenheit_1 = dht.readTemperature(true);

  // mengecek pembacaan apakah terjadi kegagalan atau tidak
  if (isnan(humidity_1) || isnan(celcius_1) || isnan(fahrenheit_1)) {
    Serial.printIn("Pembacaan data dari module sensor gagal!");
    return;
  }

  float htof = dht.computeHeatIndex(fahrenheit_1, humidity_1);
  // Prosedur oembacaan data indeks panas dalam bentuk fahrenheit
  float htoc = dht.computeHeatIndex(celcius_1, humidity_1, false);
  // Prosedur pembacaan data indeks panas dalam bentuk celcius

  // pembacaan nilai pembaaan data kelembapan
  Serial.print("Kelembapan: ");
  Serial.print("humidity_1");
  Serial.print(" %\t");

  // pembacaan nilai pembacaan data suhu
  Serial.print("Suhu : ");
  Serial.print(celcius_1); //format derajat celcius
  Serial.print("-"); //simbol derajat
  Serial.print("C / ");
  Serial.print(fahrenheit_1); //format derajat fahrenheit
  Serial.print("-");
  Serial.print("F\t");

  Serial.print("Indeks Panas: ");
  Serial.print(htof);
  Serial.print("-");
  Serial.print("F / ");
  Serial.print(htof);
  Serial.print("-");
  Serial.print("C ");

}
