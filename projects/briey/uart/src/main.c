#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <briey.h>

void print(char *str){
	while(*str){
		uart_write(UART,*(str++));
	}
}

int main() {
	Uart_Config uartConfig;
	uartConfig.dataLength = 8;
	uartConfig.parity = NONE;
	uartConfig.stop = ONE;
	uartConfig.clockDivider = 50000000/8/115200-1;
	uart_applyConfig(UART,&uartConfig);

	print("Hello !\n");

	while(1){
		for(uint32_t idx = '0';idx <= '9';idx++){
			uart_write(UART, idx);
		}
		for(uint32_t idx = 'a';idx <= 'z';idx++){
			uart_write(UART, idx);
		}
		for(uint32_t idx = 'A';idx <= 'Z';idx++){
			uart_write(UART, idx);
		}
	}
}


void irqCallback(){

}
