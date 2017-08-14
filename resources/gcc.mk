RISCV_NAME ?= riscv64-unknown-elf
RISCV_PATH ?= /opt/riscv/
RISCV_MULTI_TARGET_PACK ?= yes

ifeq ($(MULDIV),yes)
	MARCH=rv32im
	MABI=ilp32
endif
ifeq ($(MULDIV),no)
	MARCH=rv32i
	MABI=ilp32
endif

CFLAGS += -march=$(MARCH)  -mabi=$(MABI)
LDFLAGS += -march=$(MARCH)  -mabi=$(MABI)