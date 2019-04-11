/*
 * vamat001_lab3_part4.c
 *
 * Created: 4/10/2019 3:07:44 PM
 * Author : vamat
 */ 

#include <avr/io.h>

// Bit-access function
unsigned char SetBit(unsigned char x, unsigned char k, unsigned char b) {
	return (b ? x | (0x01 << k) : x & ~(0x01 << k));
}
unsigned char GetBit(unsigned char x, unsigned char k) {
	return ((x & (0x01 << k)) != 0);
}

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00; // Configure port B's 8 pins as outputs,
	// initialize to 0s
	unsigned char tmpC; // intermediate variable used for port updates 
	unsigned char tmpB;
	while(1)
	{
		tmpB = (PINA & 0xF0) >> 4; 
		tmpC = (PINA & 0x0F) << 4;
		PORTB = tmpB; 
		PORTC = tmpC; 
	}
}

