int LED = 13;

void setup() {
  pinMode(LED, OUTPUT); // pinMode determines if a digital pin acts as a input or an output 
  }

void loop() {
  digitalWrite(LED, HIGH); // write to the digital pin a High(1) or a Low(0) value
  delay(1000); 
  digitalWrite(LED, LOW);
  delay(1000); // inbuilt adruino delay_fn -> millisecond factor 
}


// clearlyopaque
