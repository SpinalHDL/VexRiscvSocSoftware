#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#define PERIPH    ((volatile uint32_t*)(0x90000000))


#define UART_BASE      ((volatile uint32_t*)(0xF0010000))

enum UartParity {NONE = 0,EVEN = 1,ODD = 2};
enum UartStop {ONE = 0,TWO = 1};

uint32_t writeAvailability(){
	return (UART_BASE[1] >> 16) & 0xFF;
}
uint32_t readOccupancy(){
	return UART_BASE[1] >> 24;
}


void write(uint32_t data){
	while(writeAvailability() == 0);
	UART_BASE[0] = data;
}
void setClockDivider(uint32_t value){
	UART_BASE[2] = value;
}

void setFrameConfig(uint32_t dataLength,enum UartParity parity,enum UartStop stop){
	UART_BASE[3] = ((dataLength-1) << 0) | (parity << 8) | (stop << 16);
}





int main() {
	uint32_t a = 1,b = 2,c = 3;
	uint32_t z;
	z = a + b + c;
	z++;

	setClockDivider(50000000/8/115200-1);
	setFrameConfig(8,NONE,ONE);
	write('1');

	while(1){
		for(uint32_t idx = '0';idx <= '9';idx++)
			write(idx);
	}
}



