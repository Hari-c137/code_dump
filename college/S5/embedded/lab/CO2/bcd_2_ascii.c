#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 8000000UL

void cvt(uint8_t b, char* a) {
  uint8_t h = (b >> 4) & 0x0F;
  uint8_t l =  b & 0x0F;
  a[0] = h + '0';
  a[1] = l + '0';
}

int main(void) {
  DDRA = DDRB = 0xFF;
  uint8_t b = 0x25;
  char d[2];

  cvt(b,d); // for the illiterate this is dereferencing a pointer

  for(;;) {
    PORTA = d[0]; 
    _delay_ms(1000);
    PORTB = d[1];
    _delay_ms(1000);
  }
}
