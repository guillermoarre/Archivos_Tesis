#include "CuartoTC.h"
#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <Wire.h>
#include <SPI.h>
#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"
#include "esp_camera.h"
#include <ESP32QRCodeReader.h>

const int INTERNO = 33;
const int FLASH = 4;
const int out1 = 2;
const int out2 = 12;
const int out3 = 15;
const int sensor = 14;
uint8_t valor = 0;
uint8_t valor2 = 0;
int contador = 0;

ESP32QRCodeReader reader(CAMERA_MODEL_AI_THINKER);
String DatoQR;
// Nombre de la red y contraseña
const char* ssid     = "ARREDONDO2";
const char* password = "100precementero";
//Remplazar con el nombre del dominio
const char* serverName = "http://www.esp32tesis.ml/post-data-QR.php";
// Contraseña 
String apiKeyValue = "tPmAT5Ab3j7F9";

void onQrCodeTask(void *pvParameters){
  struct QRCodeData qrCodeData;
  while (true)
  {
    if (reader.receiveQrCode(&qrCodeData, 100))
    {
      Serial.println("Código QR encontrado");
      digitalWrite(FLASH,HIGH);
      if (qrCodeData.valid)
      {
        Serial.print("Payload: ");
        DatoQR = (const char *)qrCodeData.payload;
        Serial.println((const char *)qrCodeData.payload);
      }
      else
      {
        Serial.print("Invalido: ");
        Serial.println((const char *)qrCodeData.payload);
      }
    }
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
}

void enviaMedianteHTTP (String No_empleado){
//Verifica el estado de la conexion WIFI
  if(WiFi.status()== WL_CONNECTED){
      int httpResponseCode=0;
      WiFiClient client;
      HTTPClient http;
      //enviar hacia BD  
        // Esablece conexion con el dominio asigando
        http.begin(client, serverName);
        //Especifica el tipo de encabezado
        http.addHeader("Content-Type", "application/x-www-form-urlencoded");
        //Variable que almacena datos de los sensores
        String httpRequestData ="api_key=" + apiKeyValue + "&value1=" + No_empleado;
        Serial.print("httpRequestData: ");
        Serial.println(httpRequestData);  
      //Envia solicitud HTTP con metodo POST
        httpResponseCode = http.POST(httpRequestData);
    //imprime en la consola el estado de envio del paquete
    if (httpResponseCode>0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
    }
    else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
    //termina protocolo de comnicacion 
    http.end();
      
  }    
  else {
    Serial.println("WiFi Disconnected");
  }
}
void rutinaCerradura(){
  //valor2 = digitalRead(sensor);
  digitalWrite(FLASH,LOW);
  delay(8000);
  //datosEnviadosNANO("op1");
  do{
    Serial.println("Mantenimiento dentro del cuarto....");
    datosEnviadosNANO("op4");
    delay(1000);
    datosEnviadosNANO("op5");
    valor2 = digitalRead(sensor);
   }
   while(valor2 == HIGH);
    
}
void datosEnviadosNANO(String opcion){
  if(opcion == "op0"){
    //opcion 0 = todo apagado
    digitalWrite(out1, LOW);
    digitalWrite(out2, LOW);
    digitalWrite(out3, LOW);
    }
   else if (opcion == "op1"){
    //opcion 1 = LED ROJO
    digitalWrite(out1, HIGH);
    digitalWrite(out2, LOW);
    digitalWrite(out3, LOW);
    }
    else if (opcion == "op2"){
    //opcion 2 = LED VERDE
    digitalWrite(out1, LOW);
    digitalWrite(out2, HIGH);
    digitalWrite(out3, LOW);
    }
    else if (opcion == "op3"){
    //opcion 3 = LED AMARILLO
    digitalWrite(out1, HIGH);
    digitalWrite(out2, HIGH);
    digitalWrite(out3, LOW);
    }
    else if (opcion == "op4"){
    //opcion 4 = BUZZER
    digitalWrite(out1, LOW);
    digitalWrite(out2, LOW);
    digitalWrite(out3, HIGH);
    }
    else if (opcion == "op5"){
    //opcion 5 = CERRADURA
    digitalWrite(out1, HIGH);
    digitalWrite(out2, LOW);
    digitalWrite(out3, HIGH);
    }
    else if (opcion == "op6"){
    //opcion 6 = SALIDA6
    digitalWrite(out1, LOW);
    digitalWrite(out2, HIGH);
    digitalWrite(out3, HIGH);
    }
    else if (opcion == "op4"){
    //opcion 7 = SALIDA7
    digitalWrite(out1, HIGH );
    digitalWrite(out2, HIGH);
    digitalWrite(out3, HIGH);
    }
 }
void setup() {
  pinMode(FLASH,OUTPUT);
  pinMode(INTERNO,OUTPUT);
  pinMode(out1,OUTPUT);
  pinMode(out2,OUTPUT);
  pinMode(out3,OUTPUT);
  pinMode(sensor,INPUT);
  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0); 
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);  
  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    digitalWrite(INTERNO,HIGH);
    delay(500);
    digitalWrite(INTERNO,LOW);
  }
  Serial.println();
  Serial.print("ESP32-CAM IP Address: ");
  Serial.println(WiFi.localIP());
  reader.setup();
  Serial.println("Setup QRCode Reader");
  reader.beginOnCore(1);
  Serial.println("Begin on Core 1");
  xTaskCreate(onQrCodeTask, "onQrCode", 4 * 1024, NULL, 4, NULL);
  digitalWrite(INTERNO,LOW);
  datosEnviadosNANO("op0");
}


void loop() {
  valor = digitalRead(sensor);
  if(valor != HIGH){
      datosEnviadosNANO("op1");
      if (DatoQR == "101")
      {
        Serial.println("Encontrado 101...");
        Serial.println(DatoQR);
        datosEnviadosNANO("op2");
        delay(500);
        digitalWrite(FLASH,LOW);
        enviaMedianteHTTP(DatoQR);
        rutinaCerradura();
      }
      else if (DatoQR == "102")
      {
        Serial.println("Encontrado 102...");
        Serial.println(DatoQR);
        datosEnviadosNANO("op2");
        delay(500);
        digitalWrite(FLASH,LOW);
        enviaMedianteHTTP(DatoQR);
        rutinaCerradura();
      }
      else if (DatoQR == "103")
      {
        if(contador >2){
            contador=0;
            //contador reiniciado por admin principal
          }
        Serial.println("Encontrado 103...");
        Serial.println(DatoQR);
        datosEnviadosNANO("op2");
        delay(500);
        digitalWrite(FLASH,LOW);
        enviaMedianteHTTP(DatoQR);
        rutinaCerradura();
      }
      else if (DatoQR == "104")
      {
        Serial.println("Encontrado 103...");
        Serial.println(DatoQR);
        datosEnviadosNANO("op2");
        delay(500);
        digitalWrite(FLASH,LOW);
        enviaMedianteHTTP(DatoQR);
        rutinaCerradura();
      }
      else
      {
        Serial.println("Sin empleados...");
      }
 }
  else{
      contador ++;
      digitalWrite(FLASH,HIGH);
      datosEnviadosNANO("op3");
      Serial.println("Personal NO autorizado...");
      delay(1500);
      if(contador<2){
       enviaMedianteHTTP("999");
       delay(1000);
        }
  }
  DatoQR = ""; 
  digitalWrite(FLASH,LOW);
  delay(1000);  
}
