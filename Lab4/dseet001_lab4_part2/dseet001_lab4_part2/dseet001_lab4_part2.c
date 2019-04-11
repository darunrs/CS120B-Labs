/*
 * dseet001_lab4_part2.c
 *
 * Created: 4/10/2019 4:46:37 PM
 * Author : ucrcse
 */ 

#include <avr/io.h>

enum math {init, wait, inc, dec, wipe, none} maths;

void tick() {
	switch(maths) {
		case init:
			maths = none;
			break;
		case none: 
			if (PINA == 0x01) {
				maths = inc;
			} else if (PINA == 0x02) {
				maths = dec;
			} else if (PINA == 0x03) {
				maths = wipe;
			} else {
				maths = none;
			}
			break;
		case wait: 
			if (PINA == 0x03) {
				maths = wipe;
			} else if (PINA == 0x00) {
				maths = none;
			} else {
				maths = wait;
			}
			break;
		case inc: 
			if (PINA == 0x03) {
				maths = wipe;
			} else {
				maths = wait;
			}
			break;
		case dec: 
			if (PINA == 0x03) {
				maths = wipe;
			} else {
				maths = wait;
			}
			break;
		case wipe: 
			if (PINA == 0x03) {
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
			PORTC =  0x07;
			break;
		case wait:
			break;
		case none:
			break;
		case wipe:
			PORTC =  0x00;
			break;
		case inc:
			if (PORTC < 9) {
				PORTC++;
			}
			break;
		case dec:
			if (PORTC > 0) {
				PORTC--;
			}
			break;
		default:
			break;
	}
}

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x07;
	while (1)
	{
		tick();
	}
}