#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>


#define TEST_COM_BASE ((volatile uint32_t*)(0xF00FFF00))

extern void main2();

int main() {
	main2();

	TEST_COM_BASE[8] = 0;
}


void irqCallback(int irq){

}




