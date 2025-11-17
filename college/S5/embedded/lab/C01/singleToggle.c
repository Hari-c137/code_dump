#include <avr/io.h>
#include <util/delay.h>

int main(void) {
  DDRB |= (1 << 4);

  for(;;) {
    PORTB ^= (1 << 4);
    _delay_ms(1000);
  }
  return 0;
}
