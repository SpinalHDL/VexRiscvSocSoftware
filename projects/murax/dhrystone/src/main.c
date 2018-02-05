#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <murax.h>


extern void main2();

int main() {
	Uart_Config uartConfig;
	uartConfig.dataLength = 8;
	uartConfig.parity = NONE;
	uartConfig.stop = ONE;
	uartConfig.clockDivider = 12000000/UART_SAMPLE_PER_BAUD/115200-1;
	uart_applyConfig(UART,&uartConfig);


	interruptCtrl_init(TIMER_INTERRUPT);
	prescaler_init(TIMER_PRESCALER);
	timer_init(TIMER_A);

	TIMER_PRESCALER->LIMIT = 99;

	TIMER_A->LIMIT = ~0;
	TIMER_A->CLEARS_TICKS = 0x00010002;

	main2();
}


void irqCallback(){

}

#include <time.h>
clock_t	clock(){
	return TIMER_A->VALUE;
}



