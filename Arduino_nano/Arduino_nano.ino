#define in1 2
#define in2 3
#define in3 4
#define ledrojo 5
#define ledverde 6
#define ledamarillo 7
#define buzzer 8
#define cerradura 9
#define out6 10
#define out7 11

void setup() {
  Serial.begin(115200);
  delay(1000);
  // put your setup code here, to run once:
  pinMode(in1, INPUT);
  pinMode(in2, INPUT);
  pinMode(in3, INPUT);
  pinMode(ledverde, OUTPUT);
  pinMode(ledrojo, OUTPUT);
  pinMode(ledamarillo, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(cerradura, OUTPUT);
  pinMode(out6, OUTPUT);
  pinMode(out7, OUTPUT);
  digitalWrite(ledrojo,LOW);
  digitalWrite(ledverde,LOW);
  digitalWrite(ledamarillo,LOW);
  digitalWrite(buzzer,LOW);
  digitalWrite(cerradura,LOW);
  digitalWrite(out6,LOW);
  digitalWrite(out7,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Leyendo...");
  uint8_t val1 = digitalRead(in1);
  uint8_t val2 = digitalRead(in2);
  uint8_t val3 = digitalRead(in3);
  if(val1 == LOW && val2 == LOW && val3 == LOW){
    digitalWrite(ledrojo,LOW);
    digitalWrite(ledamarillo,LOW);
    digitalWrite(ledverde,LOW);
    digitalWrite(buzzer,LOW);
    digitalWrite(cerradura,LOW);
    digitalWrite(out6,LOW);
    digitalWrite(out7,LOW);
    Serial.println("op0");
  }
  else if(val1 == HIGH && val2 == LOW && val3 == LOW){
    //opcion 1, led rojo on
    digitalWrite(ledrojo,HIGH);
    digitalWrite(ledamarillo,LOW);
    digitalWrite(ledverde,LOW);
    digitalWrite(buzzer,LOW);
    digitalWrite(cerradura,LOW);
    Serial.println("op1");
    Serial.println("LED rojo prendido");
  }
  else if(val1 == LOW && val2 == HIGH && val3 == LOW){
    //opcion 2, led verde on, buzzer on, ceradura on
    digitalWrite(ledrojo,LOW);
    digitalWrite(ledamarillo,LOW);
    digitalWrite(ledverde,HIGH);
    digitalWrite(buzzer,HIGH);
    digitalWrite(cerradura,HIGH);
    Serial.println("op2");
  }
  else if(val1 == HIGH && val2 == HIGH && val3 == LOW){
    //opcion 2, buzzer on, amarillo on
    digitalWrite(ledrojo,LOW);
    digitalWrite(ledamarillo,HIGH);
    digitalWrite(ledverde,LOW);
    digitalWrite(buzzer,HIGH);
    digitalWrite(cerradura,LOW);
    Serial.println("op3");
  }
  else if(val1 == LOW && val2 == LOW && val3 == HIGH){
    //digitalWrite(out4,HIGH);
    Serial.println("op4");
  }
  else if(val1 == HIGH && val2 == LOW && val3 == HIGH){
    //digitalWrite(out5,HIGH);
    Serial.println("op5");
  }
  else if(val1 == LOW && val2 == HIGH && val3 == HIGH){
    digitalWrite(out6,HIGH);
    Serial.println("op6");
  }
  else if(val1 == HIGH && val2 == HIGH && val3 == HIGH){
    digitalWrite(out7,HIGH);
    Serial.println("op7");
  }
  delay(500);
}
