#include <DHT.h> #include <DHT U.h>
DHT dht (2, DHT11);
float temp, hume;
#define Photoresistor A0
void setup()
{
Serial.begin (9600);
dht.begin ();

}
void loop() {
delay(2000);
hume = dht.readHumidity ();
temp = dht.readTemperature () ;
int a_value = analogRead(Photoresistor);
int brillo = map(a_value,0,1000,0,100);
Serial.println ("Temperatura: " + String (temp) + " Humedad: " + String (hume) +" Nivel de Brillo: " + int(brillo));

}

