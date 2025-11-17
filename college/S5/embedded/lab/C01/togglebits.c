#include <util/delay.h>
#include <avr/io.h>
#define F_CPU 16000000UL

int main(void) {
  DDRB = 0xFF;
  PORTB = 0x00; /* initially setting PORTA as LOW */

  for(;;) {
    PORTB ^= 0xFF; /* XOR with 0xFF to flip all bits */
    _delay_ms(1000);
  }
}
