#define BLYNK_TEMPLATE_ID ""
#define BLYNK_TEMPLATE_NAME ""
#define BLYNK_AUTH_TOKEN ""

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h> 
#include <BlynkSimpleEsp8266.h>
#include <dht.h>

dht DHT;

#define DHT11_PIN 2




char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "";  // type your wifi name
char pass[] = "";  // type your wifi password

BlynkTimer timer;




void sendSensor()
{
  /*int soilmoisturevalue = analogRead(A0);
   soilmoisturevalue = map(soilmoisturevalue, 0, 1023, 0, 100);*/
 
    int chk = DHT.read11(DHT11_PIN);
            


  // You can send any value at any time.
  // Please don't send more that 10 values per second.
    
    Blynk.virtualWrite(V6, DHT.temperature);
    Blynk.virtualWrite(V5, DHT.humidity);
    Serial.print("Temperature = ");
    Serial.println(DHT.temperature);
    Serial.print("Humidity = ");
    Serial.println(DHT.humidity);
    delay(1000);

}
void setup()
{   
  
  Serial.begin(9600);
  pinMode(D0,OUTPUT);

  

  Blynk.begin(auth, ssid, pass);
    timer.setInterval(100L, sendSensor);
 
  }

void loop()
{
  Blynk.run();
  timer.run();
 }