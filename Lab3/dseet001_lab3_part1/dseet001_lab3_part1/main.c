/*
 * dseet001_lab3_part1.c
 *
 * Created: 4/8/2019 4:03:42 PM
 * Author : ucrcse
 */ 

#include <avr/io.h>

unsigned char SetBit(unsigned char x, unsigned char k, unsigned char b) {
	return (b ? x | (0x01 << k) : x & ~(0x01 << k));
}
unsigned char GetBit(unsigned char x, unsigned char k) {
	return ((x & (0x01 << k)) != 0);
}

int main(void)
{
    DDRA = 0x00; PINA = 0x00; // Configure port A's 8 pins as inputs
	DDRB = 0x00; PINB = 0x00; // Configure port A's 8 pins as inputs
    DDRC = 0x00; PINC = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
	unsigned short cnt = 0x00;
    while (1) 
    {
		tmpA = PINA;
		tmpB = PINB;
		cnt = 0x00;
		for (unsigned short i = 0; i < 8; i++) {
			if (GetBit(tmpA, i) == 0x01) {
				cnt++;
			}
			if (GetBit(tmpB, i) == 0x01) {
				cnt++;
			}
		}
		PORTC = cnt;
    }
}

