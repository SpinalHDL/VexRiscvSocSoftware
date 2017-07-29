#include <stdint.h>

#include "timer.h"
#include "prescaler.h"
#include "interrupt.h"
#include "gpio.h"

#define GPIO_A_BASE    ((Gpio_Reg*)(0xF0000000))


#define TIMER_PRESCALER ((Prescaler_Reg*)0xF0020000)
#define TIMER_INTERRUPT ((InterruptCtrl_Reg*)0xF0020010)
#define TIMER_A ((Timer_Reg*)0xF0020040)
#define TIMER_B ((Timer_Reg*)0xF0020050)






int main() {
	volatile uint32_t a = 1, b = 2, c = 3;
	uint32_t result = 0;

	interruptCtrl_init(TIMER_INTERRUPT);
	prescaler_init(TIMER_PRESCALER);
	timer_init(TIMER_A);

	TIMER_PRESCALER->LIMIT = 12000-1; //1 ms rate

	TIMER_A->LIMIT = 100-1;
	TIMER_A->CLEARS_TICKS = 0x00010002;

	TIMER_INTERRUPT->PENDINGS = 0xF;
	TIMER_INTERRUPT->MASKS = 0x1;

	GPIO_A_BASE->OUTPUT_ENABLE = 0x000000FF;
	GPIO_A_BASE->OUTPUT = 0x00000000;

	while(result < 0xF0000000){
		result += a;
		result += b + c;
		for(uint32_t idx = 0;idx < 50000;idx++){
			asm("nop");
		}
		GPIO_A_BASE->OUTPUT = (GPIO_A_BASE->OUTPUT & ~0x3F) | ((GPIO_A_BASE->OUTPUT + 1) & 0x3F);
	}
	return result;
}

void irq(){

	GPIO_A_BASE->OUTPUT ^= 0x80;
	TIMER_INTERRUPT->PENDINGS = 1;
}



