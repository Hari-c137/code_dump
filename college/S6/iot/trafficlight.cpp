int G = 13;
int Y = 12;
int R = 8;

void setup() {
  pinMode(G, OUTPUT);
  pinMode(Y, OUTPUT);
  pinMode(R, OUTPUT);
  // all off at the start;
  digitalWrite(G, LOW);
  digitalWrite(Y, LOW);
  digitalWrite(R, LOW);
}

void loop() {
/* logic (left to right and right to left)
    green on, wait 10 seconds and green off
    yellow on, wait 5 seconds and yellow off
    red on, wait 10 seconds and red off
     (no to go back reverse)
   yellow on, wait 5 seconds and yellow off
*/

digitalWrite(G, HIGH); delay(10000); digitalWrite(G, LOW); 
digitalWrite(Y, HIGH); delay(5000); digitalWrite(Y, LOW); 
digitalWrite(R, HIGH); delay(10000); digitalWrite(R, LOW); 
digitalWrite(Y, HIGH); delay(5000); digitalWrite(Y, LOW); 
}

// clearlyopaque
