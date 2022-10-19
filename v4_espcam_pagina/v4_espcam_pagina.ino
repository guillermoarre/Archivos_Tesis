
#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <Wire.h>
#include <SPI.h>
#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"
#include "esp_camera.h"
#include <ESP32QRCodeReader.h>

//Variables para envio de mensajes
String apiKey = "2868930";
String phone_number = "5215520217523";
String url;

const int INTERNO = 33;
const int FLASH = 4;

const int rojo = 15;
const int cerradura = 12;
const int buzzer = 2;
const int sensor = 14;
int valor = 0;
int valor2 = 0;
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
      Serial.println("Found QRCode");
      digitalWrite(FLASH,HIGH);
      if (qrCodeData.valid)
      {
        Serial.print("Payload: ");
        DatoQR = (const char *)qrCodeData.payload;
        //Serial.println((const char *)qrCodeData.payload);
      }
      else
      {
        Serial.print("Invalid: ");
        Serial.println((const char *)qrCodeData.payload);
      }
    }
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
}


void enviaMedianteHTTP (String No_empleado, int opcion){
  //
//Verifica el estado de la conexion WIFI
  if(WiFi.status()== WL_CONNECTED){
    int httpResponseCode;
    WiFiClient client;
    HTTPClient http;
      //enviar hacia BD
      if(opcion == 1){   
        //Declaración de varibles
        
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
      }
      else if (opcion == 2){
        //Enviar Whatsapp
        url = "https://api.callmebot.com/whatsapp.php?phone=5215520217523&apikey=2868930&text=+Intruso+en+CT";
        http.begin(url);
        httpResponseCode = http.POST(url);
        Serial.print("URL para Whatsapp: ");
        Serial.println(url);  
      }
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
  valor2 = digitalRead(sensor);
  digitalWrite(buzzer, HIGH);
  digitalWrite(cerradura,HIGH);
  delay(10000);
  digitalWrite(buzzer, LOW);
  digitalWrite(cerradura, LOW);
  while(valor2 == HIGH){
      Serial.println("Mantenimiento dentro del cuarto....");
      delay(500);
    }
}

void setup() {
  pinMode(rojo,OUTPUT);
  pinMode(FLASH,OUTPUT);
  pinMode(INTERNO,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(cerradura,OUTPUT);
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
  digitalWrite(buzzer,LOW);
}


void loop() {
  valor = digitalRead(sensor);
  
  if(valor != HIGH){
      digitalWrite(buzzer,LOW);
      if (DatoQR == "101")
      {
        Serial.println("Encontrado 101...");
        Serial.println(DatoQR);
        digitalWrite(rojo,LOW);
        delay(500);
        digitalWrite(FLASH,LOW);
        enviaMedianteHTTP(DatoQR,1);
        rutinaCerradura();
      }
      else if (DatoQR == "102")
      {
        Serial.println("Encontrado 102...");
        Serial.println(DatoQR);
        digitalWrite(rojo,LOW);
        delay(500);
        digitalWrite(FLASH,LOW);
        enviaMedianteHTTP(DatoQR,1);
        rutinaCerradura();
        
      }
      else if (DatoQR == "103")
      {
        Serial.println("Encontrado 103...");
        Serial.println(DatoQR);
        digitalWrite(rojo,LOW); 
        delay(500);
        digitalWrite(FLASH,LOW);
        enviaMedianteHTTP(DatoQR,1);
        rutinaCerradura();
      }
      else
      {
        Serial.println("Sin empleados...");
      }
      digitalWrite(rojo,HIGH);
 }
  else{
    
      contador ++;
      digitalWrite(FLASH,HIGH);
      digitalWrite(buzzer,HIGH);
      Serial.println("Personal NO autorizado...");
      delay(1500);
      if(contador<2){
       enviaMedianteHTTP("999",1);
        delay(1000);
       enviaMedianteHTTP("Whatsapp",2);
        }
      //digitalWrite(FLASH,LOW);  
  }
  DatoQR = ""; 
  digitalWrite(FLASH,LOW);
  delay(1000);  
}
