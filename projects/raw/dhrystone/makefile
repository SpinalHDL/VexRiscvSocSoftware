PROJ_NAME=dhrystone
DEBUG=no
BENCH=no
MULDIV?=yes
COMPRESSED?=yes


CFLAGS += -fno-inline -fno-common 
CFLAGS +=  -DPREALLOCATE=1 -DHOST_DEBUG=0 -DMSC_CLOCK -DCORE_HZ=100000000


SRCS = 	src/main.c src/dhry_1.c src/dhry_2.c src/crt.S src/stdlib.c 
LDFLAGS += -lc #Used to get memcpy/strcmp stuff only

LDSCRIPT = ../libs/simple.ld
INC += -I../../../libs/
INC += -I../libs/


include ../../../resources/gcc.mk
include ../../../resources/subproject.mk


			
