#include <Wire.h>

/* (CZERWONE) --   A1   A2  A3  --  A0
 * (ŻÓŁTE)    D2   D3   D4  D5  D6  D7
 * (ZIELONE)  D8   D9   D10 D11 D12 D13
 */

String rec = "";
 
void setup() 
{
  Wire.begin(0x40);                 // Initialize Arduino as slave with addres 0x40
  Wire.onReceive(receiveEvent);     // Register event
  Serial.begin(9600);               // Start serial for debug

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);  
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A6, OUTPUT);
  //pinMode(A7, OUTPUT);
  
  digitalWrite(2,LOW);  
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  digitalWrite(A0,LOW);
  digitalWrite(A1,LOW);
  digitalWrite(A2,LOW);
  digitalWrite(A3,LOW);
  digitalWrite(A6,LOW);
  //digitalWrite(A7,HIGH);
}

void loop() 
{
  /* digitalWrite(A1,HIGH);
  delay(500);
  digitalWrite(A1,LOW);
  digitalWrite(A2,HIGH);
  delay(500);
  digitalWrite(A2,LOW);
  digitalWrite(A3,HIGH);
  delay(500);
  digitalWrite(A3,LOW);
  digitalWrite(A6,HIGH);
  delay(500);
  digitalWrite(A6,LOW);
  digitalWrite(A0,HIGH);
  delay(500);
  digitalWrite(A0,LOW);
  
  digitalWrite(2,HIGH);
  delay(500);
  digitalWrite(2,LOW); 
  digitalWrite(3,HIGH);
  delay(500);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  delay(500);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  delay(500);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  delay(500);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  delay(500);
  digitalWrite(7,LOW);
 
  digitalWrite(8,HIGH);
  delay(500);
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
  delay(500);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  delay(500);
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
  delay(500);
  digitalWrite(11,LOW);
  digitalWrite(12,HIGH);
  delay(500);
  digitalWrite(12,LOW);
  digitalWrite(13,HIGH);
  delay(500);
  digitalWrite(13,LOW); */ 
}

// function that executes whenever data is received from master

void receiveEvent(int howMany) 
{
  while (0 < Wire.available())              // loop through all but the last
  {  
    char cReceivedData = Wire.read();
    //Serial.print(cReceivedData);
    if('S' == cReceivedData) {
      enableLed(rec);
      Serial.println(rec);
      rec = "";
    }
    rec += cReceivedData;
  }
}

void enableLed(String s) {
    //if(s.indexOf('A')) { digitalWrite(A0,HIGH); } else { digitalWrite(A0,LOW); }
    if(s.indexOf('B')>0) { digitalWrite(A1,HIGH); } else { digitalWrite(A1,LOW); }
    if(s.indexOf('C')>0) { digitalWrite(A2,HIGH); } else { digitalWrite(A2,LOW); }
    if(s.indexOf('D')>0) { digitalWrite(A3,HIGH); } else { digitalWrite(A3,LOW); }
    if(s.indexOf('E')>0) { digitalWrite(A6,HIGH); } else { digitalWrite(A6,LOW); }
    if(s.indexOf('F')>0) { digitalWrite(A0,HIGH); } else { digitalWrite(A0,LOW); }

    if(s.indexOf('G')>0) { digitalWrite(2,HIGH); } else { digitalWrite(2,LOW); }
    if(s.indexOf('H')>0) { digitalWrite(3,HIGH); } else { digitalWrite(3,LOW); }
    if(s.indexOf('I')>0) { digitalWrite(4,HIGH); } else { digitalWrite(4,LOW); }
    if(s.indexOf('J')>0) { digitalWrite(5,HIGH); } else { digitalWrite(5,LOW); }
    if(s.indexOf('K')>0) { digitalWrite(6,HIGH); } else { digitalWrite(6,LOW); }
    if(s.indexOf('L')>0) { digitalWrite(7,HIGH); } else { digitalWrite(7,LOW); }

    if(s.indexOf('M')>0) { digitalWrite(8,HIGH); } else { digitalWrite(8,LOW); }
    if(s.indexOf('N')>0) { digitalWrite(9,HIGH); } else { digitalWrite(9,LOW); }
    if(s.indexOf('O')>0) { digitalWrite(10,HIGH); } else { digitalWrite(10,LOW); }
    if(s.indexOf('P')>0) { digitalWrite(11,HIGH); } else { digitalWrite(11,LOW); }
    if(s.indexOf('Q')>0) { digitalWrite(12,HIGH); } else { digitalWrite(12,LOW); }
    if(s.indexOf('R')>0) { digitalWrite(13,HIGH); } else { digitalWrite(13,LOW); } 
}
