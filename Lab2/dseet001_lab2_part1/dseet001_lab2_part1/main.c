/*
 * dseet001_lab2_part1.c
 *
 * Created: 4/3/2019 3:56:51 PM
 * Author : ucrcse
 */ 

#include <avr/io.h>

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
	unsigned char PAz = 0x00; 
	unsigned char PAo = 0x00; 
	unsigned char PBz = 0x00;
	while(1)
	{
		// 1) Read input
		PAz = PINA & 0x01;
		PAo = PINA & 0x02;
		// 2) Perform computation
		if (PAz == 0x01 && PAo == 0x00) { // True if PA0 is 1
			PBz = (PBz & 0xFC) | 0x01; // Sets tmpB to bbbbbb01
			// (clear rightmost 2 bits, then set to 01)
		}
		else {
			PBz = (PBz & 0xFC) | 0x00; // Sets tmpB to bbbbbb00
			// (clear rightmost 2 bits, then set to 00)
		}
		// 3) Write output
		PORTB = PBz;
	}
	return 0;
}



