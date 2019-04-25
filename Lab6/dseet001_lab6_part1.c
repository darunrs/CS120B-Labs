/*
 * vamat001_lab6_part2.c
 *
 * Created: 4/24/2019 11:57:36 AM
 * Author : Vivek Amatya
 * Partner: Darun Seetamagari
 */

#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned char TimerFlag = 0; 
unsigned long _avr_timer_M = 1; 
unsigned long _avr_timer_cntcurr = 0; 

void TimerOn() {
	TCCR1B = 0x0B;
	OCR1A = 125;	
	TIMSK1 = 0x02; 
	TCNT1=0;
	_avr_timer_cntcurr = _avr_timer_M;
	SREG |= 0x80;
}

void TimerOff() {
	TCCR1B = 0x00; 
}

void TimerISR() {
	TimerFlag = 1;
}


ISR(TIMER1_COMPA_vect) {
	_avr_timer_cntcurr--; 
	if (_avr_timer_cntcurr == 0) { 
		TimerISR(); 
		_avr_timer_cntcurr = _avr_timer_M;
	}
}

void TimerSet(unsigned long M) {
	_avr_timer_M = M;
	_avr_timer_cntcurr = _avr_timer_M;
}

enum BL_States { BL_Start, BL_LED } BL_State; 
unsigned char cnt = 0x01;

void TickFct() {
	switch ( BL_State ) { //Transitions
      case BL_Start:
         BL_State = BL_LED; 
         break;
      case BL_LED: 
		 BL_State = BL_LED;  
		 break;  
      default:
         BL_State = BL_Start;
         break;
   }

   switch (BL_State ) {
      case BL_Start: 
		 cnt = 0x01; 
		 PORTB = cnt;
         break;
      case BL_LED: 
		 cnt = cnt << 1; 
		 if(cnt > 4) {
			 cnt = 0x01;
		 }
         PORTB = cnt; 
         break; 
      default:
         break;
   }
}

int main()
{
	DDRB = 0xFF; PORTB = 0x00;
	TimerSet(1000);
	TimerOn();
	BL_State = BL_Start;
	while(1) {
		TickFct();
		while (!TimerFlag);
		TimerFlag = 0;
	} 
	return 0;
}


