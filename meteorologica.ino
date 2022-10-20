#include <DHT.h> #include <DHT U.h>
DHT dht (2, DHT11);
float temp, hume;
void setup()
 {
Serial.begin (9600);
dht.begin ();}
void loop() {
hume = dht.readHumidity ();
temp = dht.readTemperature () ;
Serial.println ("Temperatura: " + String (temp) + " Humedad: " + String (hume) );
delay(1200);
}