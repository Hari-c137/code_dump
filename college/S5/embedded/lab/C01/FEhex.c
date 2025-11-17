#include <avr/io.h>
#include <util/delay.h>

int main(void) {
  DDRB = DDRC = DDRD = 0xFF;
  unsigned char x = 0xFE; /* 254 */

  for(;;) {
    PORTB = x / 100;
    PORTC = (x/10) % 10;
    PORTD = x % 10;
    _delay_ms(1000);
  }
  return 0;
}
