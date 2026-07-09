#include <avr/io.h>

int main(void) {
  DDRB = 0x00;
  DDRC = DDRD = 0xFF;

  unsigned char x;
  for(;;) {
    x = PINB;
    if(x > 100)
      PORTC = x;
    else
      PORTD = x;
  }
  return 0;
}
