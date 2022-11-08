
#include <ESP8266WiFi.h> 
#include <DHT.h> #include <DHT U.h>
DHT dht (2, DHT11);
float temp, hume;
#define Photoresistor A0
void setup()
{
  Serial.begin (4800);
  dht.begin ();
  connectToWiFi();
}
void loop() 
{
  delay(4000);
  hume = dht.readHumidity ();
  temp = dht.readTemperature () ;
  int a_value = analogRead(Photoresistor);
  int brillo = map(a_value,0,1000,0,100);
  Serial.println ("Temperatura: " + String (temp) + " Humedad: " + String (hume) +" Nivel de Sombra: " + int(brillo));
}

/*ADD YOUR PASSWORD BELOW*/
const char *ssid = "iPhone de Mike";
const char *password = "17112001";
WiFiClient client;

/*
* Connect your controller to WiFi
*/
void connectToWiFi() {
//Connect to WiFi Network
   Serial.println();
   Serial.print("Connecting to WiFi");
   Serial.println("...");
   WiFi.begin(ssid, password);
   int retries = 0;
while ((WiFi.status() != WL_CONNECTED) && (retries < 15)) {
   retries++;
   delay(500);
   Serial.print(".");
}
if (retries > 14) {
    Serial.println(F("WiFi connection FAILED"));
}
if (WiFi.status() == WL_CONNECTED) {
    Serial.println(F("WiFi connected!"));
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}
    Serial.println(F("Setup ready"));
}

/*
 * call connectToWifi() in setup()
 */


//Direccion MAC 48:55:19:C8:69:0E
