int LED = 6; // this is a PWM compatible pin (output) [can represent 0 to 255]
hint POT = A0; // this is the analog input pin (input) [can read 0 to 1023]

int raw_point;
int normalized_point;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  raw_point = analogRead(POT);
  // the value recieved from POT using analogRead uses the range 0 - 1023
  // and we need to normalize that value under 0 - 255 for outputing at LED
  // thats cause PWM pin 6 can only handle 0 to 255

  normalized_point = raw_point / 4;
  Serial.print(raw_point);
  Serial.print("-->");
  Serial.print(normalized_point);
  analogWrite(LED, normalized_point);
}


// clearlyopaque
