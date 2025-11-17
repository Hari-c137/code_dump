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

char keys[4][4] = {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};

char keypad_read() {
    for(uint8_t row = 0; row < 4; row++) {
        PORTA = ~(1 << row);
        _delay_us(5);
        uint8_t col = (PINA >> 4) & 0x0F;
        if(col != 0x0F) {
            for(uint8_t c = 0; c < 4; c++) {
                if(!(col & (1 << c))) {
                    while(!( (PINA>>4) & (1<<c) ));
                    return keys[row][c];
                }
            }
        }
    }
    return 0;
}

int main(void) {
    DDRD = 0xFF;
    DDRC = 0xFF;
    DDRA = 0x0F;
    PORTA = 0xF0;

    w(0x38,0); w(0x0C,0); w(0x01,0); w(0x06,0);

    w('K',1); w('E',1); w('Y',1); w(':',1);

    while(1) {
        char k = keypad_read();
        if(k) w(k,1);
    }
}
