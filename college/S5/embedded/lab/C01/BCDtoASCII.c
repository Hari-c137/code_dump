#include <avr/io.h>
#include <util/delay.h>

int main(void) {
  DDRA = DDRB = 0xFF;
  unsigned char x, y;
  unsigned char z = 0x39;

  for(;;) {
    x = (z & 0x0F) + '0';
    PORTA = x;

    y = ((z >> 4) & 0x0F) + '0';
    PORTB = y;
    _delay_ms(1000);
  }
  return 0;
}
