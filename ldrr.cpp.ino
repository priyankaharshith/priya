#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>

const char*ssid="ugh";
const char*password="12345678";
int val;
int LDRpin=A0;
WiFiClient client;
unsigned long myChannelNumber =1234;
const char*myWriteAPIkey="qwertyui";

void setup()
{
  Serial.begin(9600);
  delay(10);
  WiFi.begin(ssid,password);
  ThingSpeak. begin(client);
}

 void loop()
 {
  val=analogRead(LDRpin);
  Serial.print(val);
  delay(1000);
  ThingSpeak.writeField(myChannelNumber,1,val,myWriteAPIkey);
  delay(100);
 }
