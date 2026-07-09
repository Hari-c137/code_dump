/*
push button
ta1 = resistor + ground
ta2 = vcc 5v
tb1 = digitalpin no-pwm 8
*/

int LEDPIN = 13; // output led
int BUTPIN = 8; // input from button
int ledstatus = 0;
int button; // button input holding variable

void setup() {
  pinMode(LEDPIN, OUTPUT);
  pinMode(BUTPIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  button = digitalRead(BUTPIN);
  // we only need to handle button is pushed(1) case.. we dont have to handle the defualt state
  if (button == 1) {
    if (ledstatus == 1) { // ledstatus is set as 0 by default.. therefore if its 1, flip it and set it as High 
      ledstatus = 0;
      digitalWrite(LEDPIN, HIGH);
    }
    else if(ledstatus == 0) {
      ledstatus = 1;
      digitalWrite(LEDPIN, LOW);
    }
   delay(137);
  }
  Serial.println(ledstatus);
}


// clearlyopaque
