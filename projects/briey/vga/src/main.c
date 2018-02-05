#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#include <briey.h>

#define RES_X 640
#define RES_Y 480

//#define RES_X 160
//#define RES_Y 120

//#define RES_X 48
//#define RES_Y 32

__attribute__ ((section (".noinit"))) __attribute__ ((aligned (4*8))) uint16_t vgaFramebuffer[RES_Y][RES_X];

extern void flushDataCache(uint32_t dummy);

int main() {
	Uart_Config uartConfig;
	uartConfig.dataLength = 8;
	uartConfig.parity = NONE;
	uartConfig.stop = ONE;
	uartConfig.clockDivider = 50000000/8/115200-1;
	uart_applyConfig(UART,&uartConfig);


    vga_stop(VGA_BASE);
    VGA_BASE->TIMING = vga_h640_v480_r60;  // vga_simRes   vga_h640_v480_r60 vga_simRes_h160_v120
    VGA_BASE->FRAME_SIZE = RES_X*RES_Y*2-1;
    VGA_BASE->FRAME_BASE = (uint32_t)vgaFramebuffer;
    vga_run(VGA_BASE);

    uint16_t offset = 0;
    while(1){
    	uint16_t *ptr = &vgaFramebuffer[0][0];
    	for(uint32_t y = 0;y < RES_Y;y++){
    		uint16_t c = (((y + offset) & 0x1F) << 6);
        	for(uint32_t x = 0;x < RES_X;x++){
        		*ptr = ((uint16_t)(x & 0x1F)) + c;
        		ptr++;
        	}
    	}
    	offset+=4;
    	flushDataCache(0);
    	uart_write(UART, '\n');
    }
}


void irqCallback(){

}


