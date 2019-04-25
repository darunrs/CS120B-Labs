/*
 * dseet001_lab5_part2.c
 *
 * Created: 4/19/2019 4:09:11 PM
 * Author : Darunrs
 */ 

#include <avr/io.h>

enum math {init, wait, inc, dec, wipe, none} maths;

void tick(unsigned char A) {
	switch(maths) {
		case init:
			maths = none;
			break;
		case none: 
			if (A == 0x01) {
				maths = inc;
			} else if (A == 0x02) {
				maths = dec;
			} else if (A == 0x03) {
				maths = wipe;
			} else {
				maths = none;
			}
			break;
		case wait: 
			if (A == 0x03) {
				maths = wipe;
			} else if (A == 0x00) {
				maths = none;
			} else {
				maths = wait;
			}
			break;
		case inc: 
			if (A == 0x03) {
				maths = wipe;
			} else {
				maths = wait;
			}
			break;
		case dec: 
			if (A == 0x03) {
				maths = wipe;
			} else {
				maths = wait;
			}
			break;
		case wipe: 
			if (A == 0x03) {
				maths = wipe;
			} else {
				maths = wait;
			}
			break;
		default: 
			maths = init;
			break;
	}
	
	switch(maths) {
		case init:
			PORTB =  0x07;
			break;
		case wait:
			break;
		case none:
			break;
		case wipe:
			PORTB =  0x00;
			break;
		case inc:
			if (PORTB < 9) {
				PORTB++;
			}
			break;
		case dec:
			if (PORTB > 0) {
				PORTB--;
			}
			break;
		default:
			break;
	}
}

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x07;
	unsigned char tmpA;
	while (1)
	{
		tmpA = ~(PINA);
		tick(tmpA);
	}
}