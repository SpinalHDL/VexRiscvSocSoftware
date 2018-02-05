#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#include <briey.h>

int main() {
	interruptCtrl_init(TIMER_INTERRUPT);
	prescaler_init(TIMER_PRESCALER);
	timer_init(TIMER_A);

	TIMER_PRESCALER->LIMIT = 7;

	TIMER_A->LIMIT = 100;
	TIMER_A->CLEARS_TICKS = 0x00010002;

	TIMER_INTERRUPT->PENDINGS = 0xF;
	TIMER_INTERRUPT->MASKS = 0x1;
}


void irqCallback(){
	TIMER_INTERRUPT->PENDINGS = 1;
}


