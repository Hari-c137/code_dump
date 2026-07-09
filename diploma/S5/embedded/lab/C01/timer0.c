#include <avr/io.h>

void myDelay() {
  TCCR0 = (1 << CS02) | (1 << CS00);
  TCNT0 = 0;
  TIFR |= (1 << TOV0);
  while ((TIFR & (1 << TOV0)) == 0)
    ;
  TCCR0 = 0;
}

int main(void) {
  DDRB |= (1 << 4);
  for(;;) {
    PORTB ^= (1 << 4);
    myDelay();
  }
}
