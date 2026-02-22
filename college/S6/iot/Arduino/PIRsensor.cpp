int DUMB = 11;
int SLYY = 7; // PIR
int idmog;

void setup() {
  pinMode(DUMB, OUTPUT);
  pinMode(SLYY, INPUT);
  Serial.begin(9600);
}

void loop() {
  analogWrite(DUMB, 80);
  idmog = digitalRead(SLYY);
  
  if (idmog==1) {
    analogWrite(DUMB, 255);
    Serial.println(idmog);
    delay(5000);
    analogWrite(DUMB, 80);
    Serial.println(idmog);
  }
  delay(137);
}
