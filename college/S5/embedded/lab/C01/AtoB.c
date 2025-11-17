#include<avr/io.h>
int main(void)
{
DDRB = 0x00;
DDRC = 0xFF;
unsigned char x;
while(1)
{
x = PINB;
PORTC = x;
}
return 0;
}
