#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#include <briey.h>

#define RES_X 640
#define RES_Y 480

//#define RES_X 48
//#define RES_Y 32

__attribute__ ((section (".noinit"))) __attribute__ ((aligned (4*8))) uint16_t vgaFramebuffer[RES_Y][RES_X];

extern void flushDataCache(uint32_t dummy);

int main() {
    vga_stop(VGA_BASE);
    VGA_BASE->TIMING = vga_h640_v480_r60;  // vga_simRes   vga_h640_v480_r60
    VGA_BASE->FRAME_SIZE = RES_X*RES_Y*2;
    VGA_BASE->FRAME_BASE = (uint32_t)vgaFramebuffer;
    vga_run(VGA_BASE);

    uint32_t offset = 0;
    while(1){
    	uint16_t *ptr = &vgaFramebuffer[0][0];
    	for(uint32_t y = 0;y < RES_Y;y++){
        	for(uint32_t x = 0;x < RES_X;x++){
        		*ptr = (x & 0x1F) + ((y & 0x1F) << 6) + (offset << 11);
        		ptr++;
        	}
    	}
    	offset+=16;
    	flushDataCache(0);
    }
}


void irq(){

}


