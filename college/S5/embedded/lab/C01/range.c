#include <util/delay.h>
#include <avr/io.h>

int main(void) {
  DDRB = 0xFF;
  for(int8_t i = -4; i <= 4; i++) {
    PORTB = (uint8_t)i;
    _delay_ms(1000);
  }
}
