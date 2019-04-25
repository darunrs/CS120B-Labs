/*
 * dseet001_lab3_part3.c
 *
 * Created: 4/9/2019 9:53:01 PM
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
	DDRC = 0xFF; PORTC = 0x00;
	unsigned char gas = 0x00;
	unsigned char safety = 0x00;
	unsigned short fuel = 0x00;
	while (1)
	{
		gas = PINA & 0x0F;
		safety = PINA & 0xF0;
		fuel = 0x40;
		if (gas >= 1) {
			fuel = fuel | 0x20;
		}
		if (gas >= 3) {
			fuel = fuel | 0x10;
		}
		if (gas >= 5) {
			fuel = fuel | 0x08;
			fuel = fuel & 0xBF;
		}
		if (gas >= 7) {
			fuel = fuel | 0x04;
		}
		if (gas >= 10) {
			fuel = fuel | 0x02;
		}
		if (gas >= 13) {
			fuel = fuel | 0x01;
		}
		
		if (safety == 0x30) {
			fuel = fuel | 0x80;
		}
		PORTC = fuel;
	}
}