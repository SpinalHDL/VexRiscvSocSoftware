RISCV_NAME = riscv32-unknown-elf

ifeq ($(MULDIV),yes)
	CFLAGS += -march=rv32im  -mabi=ilp32
	RISCV_PATH=/opt/rv32im/
endif
ifeq ($(MULDIV),no)
	CFLAGS += -march=rv32i   -mabi=ilp32
	RISCV_PATH=/opt/rv32i/
endif


