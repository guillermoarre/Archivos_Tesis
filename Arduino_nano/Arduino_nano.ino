#define in1 2
#define in2 3
#define out1 4
#define out2 5
#define out3 6
#define out4 7



void setup() {
  Serial.begin(115200);
  delay(1000);
  // put your setup code here, to run once:
  pinMode(in1, INPUT);
  pinMode(in2, INPUT);
  pinMode(out1, OUTPUT);
  pinMode(out2, OUTPUT);
  pinMode(out3, OUTPUT);
  pinMode(out4, OUTPUT);
  digitalWrite(out1,LOW);
  digitalWrite(out2,LOW);
  digitalWrite(out3,LOW);
  digitalWrite(out4,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Leyendo...");
  digitalWrite(out1,LOW);
  digitalWrite(out2,LOW);
  digitalWrite(out3,LOW);
  digitalWrite(out4,LOW);
  uint8_t val1 = digitalRead(in1);
  uint8_t val2 = digitalRead(in2);
  if(val1 == LOW && val2 == LOW){
    digitalWrite(out1,HIGH);
    Serial.println("op1");
  }
  else if(val1 == HIGH && val2 == LOW){
    digitalWrite(out2,HIGH);
    Serial.println("op2");
    Serial.println(out1);
    Serial.println(val1);
  }
  else if(val1 == LOW && val2 == HIGH){
    digitalWrite(out3,HIGH);
    Serial.println("op3");
  }
  else if(val1 == HIGH && val2 == HIGH){
    digitalWrite(out4,HIGH);
    Serial.println("op4");
  }
  delay(500);
}
