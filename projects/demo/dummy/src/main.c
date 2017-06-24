#include <stdint.h>
#include <briey.h>
#include <uartStdIo.h>
#include <stdio.h>

int main() {
	Uart_Config uartConfig;
	uartConfig.dataLength = 8;
	uartConfig.parity = NONE;
	uartConfig.stop = ONE;
	uartConfig.clockDivider = 50000000/8/115200-1;
	uart_applyConfig(UART,&uartConfig);

	volatile float Dhrystones_Per_Second = 1.0f;
    printf ("%6.1f \n", Dhrystones_Per_Second);

	volatile float a = 1.0, b = 2.0;
	while(1){
		printf ("%6.1f \n", a);
		a *= 1.1;
	}
}


void irq(){

}




