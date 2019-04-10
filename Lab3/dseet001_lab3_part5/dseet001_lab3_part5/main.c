/*
 * dseet001_lab3_part5.c
 *
 * Created: 4/9/2019 10:02:05 PM
 * Author : Darunrs
 */ 

#include <avr/io.h>


int main(void)
{
	DDRB = 0x00; PORTB = 0x00;
    DDRD = 0x00; PORTD = 0x00;
	unsigned char tmpD;
	unsigned char tmpB;
	unsigned short weight; 
    while (1) 
    {
		tmpB = PINB & 0x01;
		tmpD = PIND;
		weight = (tmpD * 2) + tmpB;
		tmpB = 0x00;
		if (weight >= 70) {
			tmpB = 0x02;
		} else if (weight >= 5) {
			tmpB = 0x04;
		}
		PORTB = tmpB;
    }
}

