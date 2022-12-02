#define I2C_SDA 14
#define I2C_SCL 15
#include "Arduino.h"
#include "PCF8574.h"

//Coloca la direccion para I2C en HEX
//(address,SDA,SCL)

PCF8574 pcf8574(0x38,I2C_SDA,I2C_SCL);
//PCF8574 pcf8574(0x38);
void setup() {
  Serial.begin(115200);
  delay(1000);
  // put your setup code here, to run once:
  pcf8574.pinMode(P0,OUTPUT,LOW);
  pcf8574.pinMode(P1,OUTPUT,LOW);
  pcf8574.pinMode(P2,OUTPUT,LOW);
  
  Serial.print("Init pcf8574...");
  if (pcf8574.begin()){
    Serial.println("OK");
  }else{
    Serial.println("KO");
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  pcf8574.digitalWrite(P0,HIGH);
  delay(1000);
  pcf8574.digitalWrite(P1,HIGH);
  delay(1000);
  pcf8574.digitalWrite(P2,HIGH);
  delay(1000);
  pcf8574.digitalWrite(P2,LOW);
  delay(1000);
  pcf8574.digitalWrite(P1,LOW);
  delay(1000);
  pcf8574.digitalWrite(P0,LOW);
}
