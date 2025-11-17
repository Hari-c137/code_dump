#include <avr/io.h> /*  header file for avr i/o opertions */
#include <util/delay.h>
#define F_CPU 16000000UL

int main(void) {
    DDRB = 0xFF;
    uint8_t x = 0x01;

    for(;;) { /* loop for x++ increments */
        PORTB = x;
        _delay_ms(300);
        x++;
        if(x == 0x00)
            x = 0x01; /* restarting after 0xFF rolls over to 0x00*/
    }
}
