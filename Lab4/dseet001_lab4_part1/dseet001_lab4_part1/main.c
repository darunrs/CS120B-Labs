/*
 * dseet001_lab4_part1.c
 *
 * Created: 4/10/2019 4:01:07 PM
 * Author : ucrcse
 */ 

#include <avr/io.h>

enum light {l_init, l_one, l_one_int, l_zero, l_zero_int} lights;
	
void tick() {
	switch(lights) {
		case l_init:
			lights = l_zero;
			break;
		case l_zero:
			if (PINA & 0x01) {
				lights = l_one_int;
			} else {
				lights = l_zero;
			}
			break;
		case l_zero_int: 
			if (PINA & 0x01) {
				lights = l_zero_int;
			} else {
				lights = l_zero;
			}
			break;
		case l_one:
			if (PINA & 0x01) {
				lights = l_zero_int;
			} else {
				lights = l_one;
			}
			break;
		case l_one_int:
			if (PINA & 0x01) {
				lights = l_one_int;
			} else {
				lights = l_one;
			}
			break;
		default: 
			lights = l_init;
			break;
	}
	
	switch(lights) {
		case l_init: 
			PORTB =  0x01;
			break;
		case l_zero: 
			PORTB =  0x01;
			break;
		case l_zero_int: 
			PORTB =  0x01;
			break;
		case l_one:
			PORTB =  0x02;
			break;
		case l_one_int:
			PORTB =  0x02;
			break;
		default: 
			break;
	}
	PINA = 0x00;
}

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
    while (1) 
    {
		tick();
    }
}