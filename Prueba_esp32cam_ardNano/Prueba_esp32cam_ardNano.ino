#include "Arduino.h"
#define out1 12
#define out2 15



void setup() {
  // put your setup code here, to run once:
  pinMode(out1,OUTPUT);
  pinMode(out2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(out1,LOW);
  digitalWrite(out2,LOW);
  delay(2000);
  digitalWrite(out1,HIGH);
  digitalWrite(out2,LOW);
  delay(2000);
  digitalWrite(out1,LOW);
  digitalWrite(out2,HIGH);
  delay(2000);
  digitalWrite(out1,HIGH);
  digitalWrite(out2,HIGH);
  delay(2000);
}
