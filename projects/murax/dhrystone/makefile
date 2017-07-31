PROJ_NAME=dhrystone
DEBUG=no
BENCH=yes
MULDIV=no



CFLAGS += -g -std=gnu99 -ffast-math -fno-common -funsigned-char -fno-inline -fno-builtin-printf 
LDFLAGS += -lc

CFLAGS +=  -DPREALLOCATE=1 -DHOST_DEBUG=0 -DMSC_CLOCK 


SRCS = 	$(wildcard src/*.c) \
				$(wildcard src/*.cpp)  \
				$(wildcard src/*.S)

INC += -I../../../libs/
INC += -I../libs/
LDSCRIPT = linker.ld


include ../../../resources/gcc.mk
include ../../../resources/subproject.mk


			
