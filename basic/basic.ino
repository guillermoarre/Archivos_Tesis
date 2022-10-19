#include <Arduino.h>
#include <ESP32QRCodeReader.h>
const int LEDROJOINTERNO = 33;
const int FLASH = 4;
const int rojo = 15;
const int azul = 2;
const int buzzer = 12;

ESP32QRCodeReader reader(CAMERA_MODEL_AI_THINKER);
String DatoQR;

void onQrCodeTask(void *pvParameters)
{
  struct QRCodeData qrCodeData;

  while (true)
  {
    if (reader.receiveQrCode(&qrCodeData, 100))
    {
      Serial.println("Found QRCode");
      if (qrCodeData.valid)
      {
        //Serial.print("Payload: ");
        DatoQR = (const char *)qrCodeData.payload;
        //Serial.println((const char *)qrCodeData.payload);
      }
      else
      {
        //Serial.print("Invalid: ");
        //Serial.println((const char *)qrCodeData.payload);
      }
    }
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
}

void setup()
{
  pinMode(rojo,OUTPUT);
  pinMode(azul,OUTPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(115200);
  Serial.println();
  reader.setup();
  Serial.println("Setup QRCode Reader");
  reader.beginOnCore(1);
  Serial.println("Begin on Core 1");
  xTaskCreate(onQrCodeTask, "onQrCode", 4 * 1024, NULL, 4, NULL);
}

void loop()
{
  //digitalWrite(buzzer,HIGH);
  if (DatoQR == "101")
  {
    Serial.println("Encontrado 101...");
    Serial.println(DatoQR);
    digitalWrite(azul,HIGH);
    digitalWrite(rojo,LOW);
    delay(1000);
  }
  else if (DatoQR == "102")
  {
    Serial.println("Encontrado 102...");
    Serial.println(DatoQR);
    digitalWrite(azul,HIGH);
    digitalWrite(rojo,LOW);
    delay(4000);
  }
  else if (DatoQR == "103")
  {
    Serial.println("Encontrado 103...");
    Serial.println(DatoQR);
    digitalWrite(azul,HIGH);
    digitalWrite(rojo,LOW);
    delay(4000);
  }
  else
  {
    Serial.println("Sin empleados...");
  }
  digitalWrite(azul,LOW);
  digitalWrite(rojo,HIGH);
  
  DatoQR = "";
  delay(2000);
}
