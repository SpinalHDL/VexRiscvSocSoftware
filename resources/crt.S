.macro retirq
custom0 0,0,0,0
.endm

.macro readtIrq rd
custom0 \rd,0,0,1
.endm

.macro writetIrqMask rs
custom0 0,\rs,0,2
.endm

.macro readtIrqMask rd
custom0 \rd,0,0,3
.endm


.global  trap_entry
trap_entry:
  nop
  addi sp,sp,-128

  sw gp,   0*4(sp)
  sw x1,   1*4(sp)
  sw x2,   2*4(sp)
  sw x3,   3*4(sp)
  sw x4,   4*4(sp)
  sw x5,   5*4(sp)
  sw x6,   6*4(sp)
  sw x7,   7*4(sp)
  sw x8,   8*4(sp)
  sw x9,   9*4(sp)
  sw x10, 10*4(sp)
  sw x11, 11*4(sp)
  sw x12, 12*4(sp)
  sw x13, 13*4(sp)
  sw x14, 14*4(sp)
  sw x15, 15*4(sp)
  sw x16, 16*4(sp)
  sw x17, 17*4(sp)
  sw x18, 18*4(sp)
  sw x19, 19*4(sp)
  sw x20, 20*4(sp)
  sw x21, 21*4(sp)
  sw x22, 22*4(sp)
  sw x23, 23*4(sp)
  sw x24, 24*4(sp)
  sw x25, 25*4(sp)
  sw x26, 26*4(sp)
  sw x27, 27*4(sp)
  sw x28, 28*4(sp)
  sw x29, 29*4(sp)
  sw x30, 30*4(sp)
  sw x31, 31*4(sp)
  nop
  readtIrq a0
  jal ra, irqCpp
  nop
  nop
  nop

  lw x1,   1*4(sp)
  lw x3,   3*4(sp)
  lw x4,   4*4(sp)
  lw x5,   5*4(sp)
  lw x6,   6*4(sp)
  lw x7,   7*4(sp)
  lw x8,   8*4(sp)
  lw x9,   9*4(sp)
  lw x10, 10*4(sp)
  lw x11, 11*4(sp)
  lw x12, 12*4(sp)
  lw x13, 13*4(sp)
  lw x14, 14*4(sp)
  lw x15, 15*4(sp)
  lw x16, 16*4(sp)
  lw x17, 17*4(sp)
  lw x18, 18*4(sp)
  lw x19, 19*4(sp)
  lw x20, 20*4(sp)
  lw x21, 21*4(sp)
  lw x22, 22*4(sp)
  lw x23, 23*4(sp)
  lw x24, 24*4(sp)
  lw x25, 25*4(sp)
  lw x26, 26*4(sp)
  lw x27, 27*4(sp)
  lw x28, 28*4(sp)
  lw x29, 29*4(sp)
  lw x30, 30*4(sp)
  lw x31, 31*4(sp)
  addi sp,sp,128
  retirq
  nop
  .text

  .align 9
  .globl _start
_start:
  li  x10,0x00
  writetIrqMask x10

  la sp, _stack_start


bss_init:
  la a0, _bss_start
  la a1, _bss_end
bss_loop:
  beq a0,a1,bss_done
  sw zero,0(a0)
  add a0,a0,4
  j bss_loop
bss_done:


data_init:
  la a0, _sdata
  la a1, _edata
  la a2, _copy_section
data_loop:
  beq a0,a1,data_done
  lw a3,0(a2)
  sw a3,0(a0)
  add a2,a2,4
  add a0,a0,4
  j data_loop
data_done:

ctors_init:
  la a0, _ctors_start
  addi sp,sp,-4
ctors_loop:
  la a1, _ctors_end
  beq a0,a1,ctors_done
  lw a3,0(a0)
  add a0,a0,4
  sw a0,0(sp)
  jalr  a3
  lw a0,0(sp)
  j ctors_loop
ctors_done:
  addi sp,sp,4


  jal ra, main

infinitLoop:
  j infinitLoop

