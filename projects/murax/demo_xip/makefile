PROJ_NAME=demo_xip
DEBUG=yes
BENCH=no
MULDIV=no
COMPRESSED=no


SRCS = 	$(wildcard src/*.c) \
		$(wildcard src/*.cpp)  \
		$(wildcard src/*.S)


INC += -I../../../libs/
INC += -I../libs/
LDSCRIPT = ../libs/linker_xip.ld

include ../../../resources/gcc.mk
include ../../../resources/subproject.mk


			
