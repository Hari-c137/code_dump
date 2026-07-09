/*
#include <avr/io.h>
#include <util/delay.h>

#define D PORTC
#define C PORTD
#define EN 2
#define RS 0

void lcd_cmd(char c){ D = c; C = (0 << RS) | (1 << EN); _delay_ms(2); C=0; }
void lcd_data(char d){D = d; C = (1 << RS) | (1 << EN); _delay_ms(2); C=0; }

int main(void) {
  DDRD = DDRC = 0xFF;
  _delay_ms(20);

  lcd_cmd(0x38); lcd_cmd(0x0C); lcd_cmd(0x01); _delay_ms(20); lcd_cmd(0x06);
  char *s = "Harry";
  while(*s) lcd_data(*s++);
  while(1);
}


#include <avr/io.h>
#include <util/delay.h>

#define PS PCO
#define ENPC 2

void lcmd(char x) {
  PORTD = x;
  PORTC &= ~ (1 << RS);
  PORTC |= (1 << EN);
  _delay_ms(1);
  PORTC &= ~(1 << EN);
}

void ldata(char x) {
  PORTD = x;
  PORTC |= (1 << RS);
  PORTC |= (1 << EN);
  _delay_ms(1);
  PORTC &= ~(1 << EN);
  _delay_ms(100);
}

int main(void) {
  DDRD = DDRC = 0xFF;
  lcmd(0x38); lcmd(0x0C); lcmd(0x0F); lcmd(0x01); lcmd(0x06); lcmd(0x80);

  char i;
  char str[16] =  "Harry Ded" ;

  for (i=0; str[i] != '\0'; i++) {
    ldata(str[i]);
  }
  while(1);
}

*/

#include <avr/io.h>
#include <util/delay.h>

#define RS PC0
#define EN PC2

void pulse_enable() {
    PORTC |= (1<<EN);
    _delay_us(1);             // EN pulse width
    PORTC &= ~(1<<EN);
    _delay_ms(2);             // command execution time
}

void lcmd(unsigned char x) {
    PORTD = x;
    PORTC &= ~(1<<RS);        // RS = 0 (command)
    pulse_enable();
}

void ldata(unsigned char x) {
    PORTD = x;
    PORTC |= (1<<RS);         // RS = 1 (data)
    pulse_enable();
}

int main(void) {
    DDRD = 0xFF;              // PORTD as output
    DDRC = 0xFF;              // PORTC as output

    _delay_ms(50);            // LCD power-up

    // LCD initialization
    lcmd(0x38);               // 8-bit, 2-line
    lcmd(0x0C);               // Display ON
    lcmd(0x01);               // Clear display
    _delay_ms(2);             // required!
    lcmd(0x06);               // Entry mode

    char str[] = "Harry Ded";

    for (int i = 0; str[i] != '\0'; i++) {
        ldata(str[i]);
    }

    while (1);
}
