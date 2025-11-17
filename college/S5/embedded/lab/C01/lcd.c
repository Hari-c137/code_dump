#include <avr/io.h>
#include <util/delay.h>

#define RS PC0
#define EN PC2

void w(uint8_t v, uint8_t rs) {
    PORTD = v;
    if(rs) PORTC |=  (1<<RS);
    else   PORTC &= ~(1<<RS);
    PORTC |=  (1<<EN);
    _delay_ms(1);
    PORTC &= ~(1<<EN);
    if(rs) _delay_ms(2);
}

int main(void) {
    DDRD = DDRC = 0xFF;

    w(0x38,0);
    w(0x0C,0);
    w(0x01,0);
    w(0x06,0);

    char s[]="EMBEDDED SYSTEM";
    for(uint8_t i=0; s[i]; i++)
        w(s[i],1);

    while(1);
}
