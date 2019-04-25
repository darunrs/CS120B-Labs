/*
 * dseet001_lab5_part3.c
 *
 * Created: 4/19/2019 3:42:00 PM
 * Author : Darunrs
 */ 

#include <avr/io.h>


enum states{Start, Run, RunGFY, RunStop} state;
	
unsigned char num = 0x01;
unsigned char LR = 1;
unsigned char button = 0x00;
unsigned char light = 0x01;

void Tick() {
	switch (state) {
		case Start: 
			state = Run; 
			break;
		case Run: 
			if (~PINA & 0x01) {
				state = RunGFY;
			}
			break;
		case RunGFY:
			state = RunStop;
			break;
		case RunStop:
			if (PINA & 0x01) {
				state = Run;
			}
			break;
	}
	switch (state) {
		case Start: 
			break;
		case Run: 
			break;
		case RunGFY:
			if (num == 8) {
				LR = 2;
			}
			else if (num == 1) {
				LR = 1;
			}
			if (LR == 0) {
				break;
			}
			else if (LR == 1) {
				num = num << 1;
			}
			else if (LR == 2) {
				num = num >> 1;
			}
			PORTB = num;
			break;
		case RunStop: 
			break;
	}
}

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00; 
	light = 0x01;
	while(1)
	{
		Tick();
	}
}