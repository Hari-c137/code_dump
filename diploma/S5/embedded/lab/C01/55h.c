#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL

int main(void) {
  DDRC |= (1 << 3);
  unsigned char x = 0x55;

  for(uint8_t i = 0; i < 8; i++) {
    if(x & 0x01)
      PORTC |= (1 << 3);
    else
      PORTC &= ~(1 << 3);

    _delay_ms(1000);
    x >>= 1; // right shift 011 -> 001
  }
  return 0;
}
