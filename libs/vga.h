/*
 * vga.h
 *
 *  Created on: Jul 8, 2017
 *      Author: spinalvm
 */

#ifndef VGA_H_
#define VGA_H_
#include <stdint.h>

typedef struct {
	uint32_t hSyncStart ,hSyncEnd;
	uint32_t hColorStart,hColorEnd;

	uint32_t vSyncStart ,vSyncEnd;
	uint32_t vColorStart,vColorEnd;
}Vga_Timing;

const Vga_Timing vga_h640_v480_r60 = {
    .hSyncStart  = 96,
    .hSyncEnd    = 800,
    .hColorStart = 96 + 16,
    .hColorEnd   = 800 - 48,
    .vSyncStart  = 2,
    .vSyncEnd 	 = 525,
    .vColorStart = 2 + 10,
    .vColorEnd 	 = 525 - 33
};

const Vga_Timing vga_simRes = {
    .hSyncStart  = 8,
    .hSyncEnd    = 70,
    .hColorStart = 16,
    .hColorEnd   = 64,
    .vSyncStart  = 2,
    .vSyncEnd 	 = 48,
    .vColorStart = 8,
    .vColorEnd 	 = 40
};

typedef struct
{
  volatile uint32_t  STATUS;
  volatile uint32_t  FRAME_SIZE;
  volatile uint32_t  FRAME_BASE;
  volatile uint32_t  DUMMY0[13];
  volatile Vga_Timing TIMING;
} Vga_Reg;

uint32_t vga_isBusy(Vga_Reg *reg){
	return (reg->STATUS & 2) != 0;
}

void vga_run(Vga_Reg *reg){
	reg->STATUS  = 1;
}

void vga_stop(Vga_Reg *reg){
	reg->STATUS  = 0;
	while(vga_isBusy(reg));
}


#endif /* VGA_H_ */


