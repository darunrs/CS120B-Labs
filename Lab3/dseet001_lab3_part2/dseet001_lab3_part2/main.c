/*
 * dseet001_lab3_part2.c
 *
 * Created: 4/9/2019 9:38:25 PM
 * Author : Darunrs
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
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0x00; PORTC = 0x00; 
	unsigned char tmpA = 0x00;
	unsigned short fuel = 0x00;
	while (1)
	{
		tmpA = PINA & 0x0F;
		fuel = 0x40;
		if (tmpA >= 1) {
			fuel = fuel | 0x20;
		}
		if (tmpA >= 3) {
			fuel = fuel | 0x10;
		}
		if (tmpA >= 5) {
			fuel = fuel | 0x08;
			fuel = fuel & 0xBF;
		}
		if (tmpA >= 7) {
			fuel = fuel | 0x04;
		}
		if (tmpA >= 10) {
			fuel = fuel | 0x02;
		}
		if (tmpA >= 13) {
			fuel = fuel | 0x01;
		}
		PORTC = fuel;
	}
}
