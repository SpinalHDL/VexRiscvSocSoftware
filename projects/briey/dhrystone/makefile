PROJ_NAME=dhrystone
DEBUG=no
BENCH=yes
MULDIV=yes



CFLAGS += -fno-inline -fno-common 
LDFLAGS += -lc

CFLAGS +=  -DPREALLOCATE=1 -DHOST_DEBUG=0 -DMSC_CLOCK 


SRCS = 	src/main.c src/dhry_1.c src/dhry_2.c src/crt.S  src/stdlib.c 
LDFLAGS += -lc #Used to get memcpy/strcmp stuff only

INC += -I../../../libs/
INC += -I../libs/
LDSCRIPT = ../libs/linker.ld


include ../../../resources/gcc.mk
include ../../../resources/subproject.mk


			
