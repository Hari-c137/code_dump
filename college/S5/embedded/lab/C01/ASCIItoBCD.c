#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL

int main(void) {
  DDRA = 0xFF;

  unsigned char x = '4';
  unsigned char y = '7';
  unsigned char z;

  x = x - '0';
  y = y - '0';
  x = x << 4;
   z = x | y;

   for(;;) {
     PORTA = z;
     _delay_ms(1000);
   }
   return 0;
}
