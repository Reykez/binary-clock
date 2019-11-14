#include <ESP8266WiFi.h>
#include <Wire.h>
#include <time.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

#define BIT(n,i) (n>>i&1)

const char* ssid = "WIFI-SSID";
const char* password = "WIFI-PASSWD";

const long utcOffsetInSeconds = 3600;

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);

/* (CZERWONE) A B C D E F
 * (ŻÓŁTE)    G H I J K L
 * (ZIELONE)  M N O P Q R
 */

void setup() 
{
  pinMode(D7, OUTPUT);
  Serial.begin(9600);               // Initialize Serial communication at 9600 baud

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("\nConnecting to WiFi");
  while(WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  timeClient.begin();
  Wire.begin();                     // Initialize Arduino as Master
}

void loop() 
{
  timeClient.update();
  Serial.print("I:");
  Serial.print(timeClient.getHours());
  Serial.print(":");
  Serial.print(timeClient.getMinutes());
  Serial.print(":");
  Serial.println(timeClient.getSeconds());
  /*char h = timeClient.getHours();
  char m = timeClient.getMinutes();
  char s = timeClient.getSeconds(); */
    int ReceivedInt = timeClient.getHours();
    if(BIT(ReceivedInt,1) == 1) {
      digitalWrite(D7,HIGH);
    } else { digitalWrite(D7,LOW); }
   
    if(BIT(ReceivedInt,5) == 1) {
      Wire.beginTransmission(0x40);
      Wire.write('A');
      Wire.endTransmission();
    } 
    if(BIT(ReceivedInt,4) == 1) {
      Wire.beginTransmission(0x40);
      Wire.write('B');
      Wire.endTransmission();
    } 
    if(BIT(ReceivedInt,3) == 1) {
      Wire.beginTransmission(0x40);
      Wire.write('C');
      Wire.endTransmission();  
    } 
    if(BIT(ReceivedInt,2) == 1) {
      Wire.beginTransmission(0x40);
      Wire.write('D');
      Wire.endTransmission();
    } 
    if(BIT(ReceivedInt,1) == 1) {
      Wire.beginTransmission(0x40);
      Wire.write('E');
      Wire.endTransmission();
    } 
    if(BIT(ReceivedInt,0) == 1) {
      Wire.beginTransmission(0x40);
      Wire.write('F');
      Wire.endTransmission();
    } 

    ReceivedInt = timeClient.getMinutes();
    if(BIT(ReceivedInt,5) == 1) {
      Wire.beginTransmission(0x40);
      Wire.write('G');
      Wire.endTransmission();
    } 
    if(BIT(ReceivedInt,4) == 1) {
      Wire.beginTransmission(0x40);
      Wire.write('H');
      Wire.endTransmission();
    } 
    if(BIT(ReceivedInt,3) == 1) {
      Wire.beginTransmission(0x40);
      Wire.write('I');
      Wire.endTransmission();   
    } 
    if(BIT(ReceivedInt,2) == 1) {
      Wire.beginTransmission(0x40);
      Wire.write('J');
      Wire.endTransmission();
    } 
    if(BIT(ReceivedInt,1) == 1) {
      Wire.beginTransmission(0x40);
      Wire.write('K');
      Wire.endTransmission();
    } 
    if(BIT(ReceivedInt,0) == 1) {
      Wire.beginTransmission(0x40);
      Wire.write('L');
      Wire.endTransmission();
    }

    ReceivedInt = timeClient.getSeconds();
    if(BIT(ReceivedInt,5) == 1) {
      Wire.beginTransmission(0x40);
      Wire.write('M');
      Wire.endTransmission();

    } 
    if(BIT(ReceivedInt,4) == 1) {
      Wire.beginTransmission(0x40);
      Wire.write('N');
      Wire.endTransmission();
    } 
    if(BIT(ReceivedInt,3) == 1) {
      Wire.beginTransmission(0x40);
      Wire.write('O');
      Wire.endTransmission();     
    } 
    if(BIT(ReceivedInt,2) == 1) {
      Wire.beginTransmission(0x40);
      Wire.write('P');
      Wire.endTransmission();
    } 
    if(BIT(ReceivedInt,1) == 1) {
      Wire.beginTransmission(0x40);
      Wire.write('Q');
      Wire.endTransmission();
    } 
    if(BIT(ReceivedInt,0) == 1) {
      Wire.beginTransmission(0x40);
      Wire.write('R');
      Wire.endTransmission();
    } 
    Wire.beginTransmission(0x40);
    Wire.write('S');
    Wire.endTransmission();
    delay(1000);
    /* delay(200);
    if(ReceivedInt == 1)
    {
      Wire.beginTransmission(0x40);    // Transmit to Slave device #0x40
      Wire.write('1');                 // Sends one byte as '1'
      Wire.endTransmission();          // End transmition
      delay(100);
    }
    else if(ReceivedInt == 2)
    {
      Wire.beginTransmission(0x40);
      Wire.write('2');
      Wire.endTransmission();
      delay(100);
    } 
    else if(ReceivedInt == 3)
    {
      Serial.println("LED 2 ON");
      Wire.beginTransmission(0x40);    // Transmit to Slave device #0x40
      Wire.write('3');                 // Sends one byte as '3'
      Wire.endTransmission();          // End transmition
      delay(100);
    }
    else if(ReceivedInt == 4)
    {
      Wire.beginTransmission(0x40);    // Transmit to Slave device #0x40
      Wire.write('4');                 // Sends one byte as '4'
      Wire.endTransmission();          // End transmition
      delay(100);
    } */
}
