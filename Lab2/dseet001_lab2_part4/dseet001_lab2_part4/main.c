/*
 * dseet001_lab2_part4.c
 *
 * Created: 4/6/2019 9:04:06 AM
 * Author : Darunrs
 */ 

#include <avr/io.h>
typedef unsigned char reg; 

int main(void)
{
    DDRA = 0x00; PORTA = 0x00;
    DDRB = 0x00; PORTB = 0x00;
    DDRC = 0x00; PORTC = 0x00;
    DDRD = 0xFF; PORTD = 0x00;
	reg tempA = 0;
	reg tempB = 0;
	reg tempC = 0;
	reg tempD = 0;
	reg diff = 0;
	unsigned long sum = 0;
	
    while (1) 
    {
		tempA = PORTA; 
		tempB = PORTB;
		tempC = PORTC;
		sum = tempA + tempB + tempC;
		
		if (tempA > tempC) {
			diff = tempA - tempC;
		} else {
			diff = tempC - tempA;
		}
		
		if (sum > 140) {
			tempD = tempD | 0x01;
		}
		if (diff > 80) {
			tempD = tempD | 0x02;
		}
		
		PORTD = (sum & 0xFC) | tempD;
    }
}

