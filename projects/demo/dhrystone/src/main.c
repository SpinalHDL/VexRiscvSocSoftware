#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#define TEST_COM_BASE ((volatile uint32_t*)(0xF00FFF00))
#include "testStdIo.h"


#ifdef __cplusplus
extern "C" {
#endif

extern void main2();

int main() {
	Uart_Config uartConfig;
	uartConfig.dataLength = 8;
	uartConfig.parity = NONE;
	uartConfig.stop = ONE;
	uartConfig.clockDivider = 50000000/8/115200-1;
	uart_applyConfig(UART,&uartConfig);


	interruptCtrl_init(TIMER_INTERRUPT);
	prescaler_init(TIMER_PRESCALER);
	timer_init(TIMER_A);

	TIMER_A->LIMIT = ~0;
	TIMER_A->CLEARS_TICKS = 0x00010001;
	main2();
}


void irq(){

}


int     times (){
  return TIMER_A->VALUE;
}
#include <time.h>
clock_t	clock(){
  return times();
}

#ifdef __cplusplus
}
#endif



