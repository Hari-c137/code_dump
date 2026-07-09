#define F_CPU 1000000UL // i think we can also pass frequency as compiler argument but that method still
                        // caused error with leksmi's proteus system, so declaring here is safer

#include <avr/io.h>
#include <util/delay.h>

// blinking PORTC

int main(void) {
    DDRC |= (1 << PC0);

    while (1) {
        PORTC |= (1 << PC0);
        _delay_ms(500);

        PORTC &= ~(1 << PC0);
        _delay_ms(500);
    }
}
