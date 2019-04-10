/*
 * dseet001_lab3_part4.c
 *
 * Created: 4/9/2019 9:58:45 PM
 * Author : Darunrs
 */ 

#include <avr/io.h>


int main(void)
{
    DDRA = 0x00; PORTA = 0x00;
	DDRB = 0x00; PORTB = 0x00;
	DDRC = 0x00; PORTC = 0x00;
	unsigned char upperA;
	unsigned char lowerA;
    while (1) 
    {
		upperA = PORTA & 0xF0;
		lowerA = PORTA & 0x0F;
		
		PORTB = upperA >> 4;
		PORTC = lowerA << 4;
    }
}

