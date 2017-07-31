#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include "timer.h"
#include "prescaler.h"
#include "interrupt.h"
#include "gpio.h"

#ifdef __cplusplus
extern "C" {
#endif

extern void main2();

#define GPIO_A_BASE    ((Gpio_Reg*)(0xF0000000))


#define TIMER_PRESCALER ((Prescaler_Reg*)0xF0020000)
#define TIMER_INTERRUPT ((InterruptCtrl_Reg*)0xF0020010)
#define TIMER_A ((Timer_Reg*)0xF0020040)
#define TIMER_B ((Timer_Reg*)0xF0020050)





int close(int fd) {
	return 0;
}

int fstat(int fd, struct _stat *buffer) {
	return 0;
}

int isatty(int fd) {
	return 0;
}

long lseek(int fd, long offset, int origin) {
	return 0;
}

int read(int fd, void *buffer, unsigned int count) {
	return 0;
}


void writeChar(char value) {
	//uart_write(UART,value);
}

void writeChars(char* value) {
	while (*value) {
		writeChar(*(value++));
	}
}

int write(int fd, const void *buffer, unsigned int count) {
	for (int idx = 0; idx < count; idx++) {
		writeChar(((char*) buffer)[idx]);
	}
	return count;
}


int main() {
	/*Uart_Config uartConfig;
	uartConfig.dataLength = 8;
	uartConfig.parity = NONE;
	uartConfig.stop = ONE;
	uartConfig.clockDivider = 50000000/8/115200-1;
	uart_applyConfig(UART,&uartConfig);*/

	TIMER_PRESCALER->LIMIT = 99;
	interruptCtrl_init(TIMER_INTERRUPT);
	prescaler_init(TIMER_PRESCALER);
	timer_init(TIMER_A);

	TIMER_A->LIMIT = ~0;
	TIMER_A->CLEARS_TICKS = 0x00010002;

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



