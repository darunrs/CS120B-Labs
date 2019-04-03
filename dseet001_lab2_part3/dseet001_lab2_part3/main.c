/*
 * dseet001_lab2_part3.c
 *
 * Created: 4/3/2019 4:43:01 PM
 * Author : ucrcse
 */ 

#include <avr/io.h>

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRC = 0xFF; PORTC = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
	unsigned char PAzero = 0x00;
	unsigned char PAone = 0x00;
	unsigned char PAtwo = 0x00;
	unsigned char PAthree = 0x00;
	unsigned char cntavail = 0x00;
	while(1)
	{
		// 1) Read input
		PAzero = PINA & 0x01;
		PAone = PINA & 0x02;
		PAtwo = PINA & 0x04;
		PAthree = PINA & 0x08;
		cntavail = 0x00;
		// 2) Perform computation
		if (PAzero == 0x00) { // True if PA0 is 1
			cntavail = cntavail + 0x01;
		}
		if (PAone == 0x00) { // True if PA0 is 1
			cntavail = cntavail + 0x01;
		}
		if (PAtwo == 0x00) { // True if PA0 is 1
			cntavail = cntavail + 0x01;
		}
		if (PAthree == 0x00) { // True if PA0 is 1
			cntavail = cntavail + 0x01;
		}
		// 3) Write output
		PORTC = (PORTC & 0xF0) | cntavail;
		if (cntavail == 0x00) {
			PORTC = (PORTC & 0x7F) | 0x80;
		} else {
			PORTC = (PORTC & 0x7F) | 0x00;
		}
	}
	return 0;
}


