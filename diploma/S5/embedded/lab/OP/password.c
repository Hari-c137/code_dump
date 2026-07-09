#include <avr/io.h>
#include <util/delay.h>
#include <string.h>

#define RS PD0
#define EN PD1

void lcd(uint8_t d, uint8_t rs) {
  PORTD = (PORTD & 0x0F) | (d & 0xF0);
  if(rs) PORTD |= (1<<RS); else PORTD &= ~(1<<RS);
  PORTD |= (1<<EN); _delay_us(1); PORTD &= ~(1<<EN);
  PORTD = (PORTD & 0x0F) | (d<<4);
  PORTD |= (1<<EN); _delay_us(1); PORTD &= ~(1<<EN);
  _delay_ms(2);
}

char get_key() {
  char m[4][4]={{'1','2','3','A'},{'4','5','6','B'},{'7','8','9','C'},{'*','0','#','D'}};
  for(uint8_t r=0;r<4;r++) {
    DDRC=(1<<r);PORTC=~(1<<r);_delay_us(5);
    for(uint8_t c=0;c<4;c++)
      if(!(PINC&(1<<(c+4)))) {
        while(!(PINC&(1<<(c+4))));
        return m[r][c];
      }
  }
  return 0;
}

int main() {
  DDRD=0xF3;DDRC=0x0F;PORTC=0xFF;
  _delay_ms(15);
  lcd(0x28,0);lcd(0x0C,0);lcd(0x01,0);

  char code[5],k,i=0;
  while(1) {
    if((k=get_key())) {
      if(k=='#') {
        code[i]=0; lcd(0x01,0);
        char*msg=strcmp(code,"123A")?"LOCKED":"UNLOCKED";
        while(*msg)lcd(*msg++,1);
        _delay_ms(2000);lcd(0x01,0); i=0;
      } else if(i<4) code[i++]=k;
    }
  }
}

