default_target: all
.PHONY : default_target

# Variables for Makefile

## Compiler flags

## Which toolchain to use
CROSS_COMPILE = arm-none-eabi-
## Compiler to use (arm-none-eabi-gcc)
CC = $(CROSS_COMPILE)gcc
## Compiler to use (arm-none-eabi-gcc)
LD = $(CROSS_COMPILE)ld
## Compiler to use (arm-none-eabi-gcc)
OBJCOPY = $(CROSS_COMPILE)objcopy
## Compiler to use (arm-none-eabi-gcc)
SIZE = $(CROSS_COMPILE)size

## Where the C files live
SRC_DIR = src
## Where to output from Make
BUILD_DIR = build

## CPU target
CFLAGS = -mcpu=cortex-m4

## F411 only supports Thumb-2 (16/32-bit mix instructions)
## reduces code size vs 32-bit ARM instructions
CFLAGS += -mthumb

## "soft" if no FPU, "hard" if FPU, "softfp" to use FPU but pass floats in integer registers
CFLAGS += -mfloat-abi=hard

## specify FPU type (single-precision, 16 double registers)
CFLAGS += -mfpu=fpv4-sp-d16

## "-Wall" enable all common warnings
## "-g" include debug symbols in the binary (for debugging with GDB/OpenOCD); increases .elf size but not final .bin size
## "-O0" Optmiziation level 0 (no optimization for easier debugging); use "-O2" (optimization level) or "-Os" (size) for prod
CFLAGS += -Wall -g -O0

# Linker flags

## "-nostdlib" don't use C stdlib (libc) while linking with no OS support on device
## "-T linker.ld" specifies the linker script file to use
LDFLAGS = -nostdlib -T linker.ld

## "wildcard" Make function for matching files
C_SRCS = $(wildcard $(SRC_DIR)/*.c)
ASM_SRCS = $(wildcard $(SRC_DIR)/*.s)

SRCS = $(C_SRCS) $(ASM_SRCS)

## Pattern subsitution to take C files in SRC_DIR (src/main.c) and replace pattern with object file (build/main.o)
## "%" is the wildcard for filename here
OBJS = $(C_SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o) $(ASM_SRCS:$(SRC_DIR)/%.s=$(BUILD_DIR)/%.o)

# Build Targets

## Target with multiple prerequisites
## Make builds prereqs first left to right, then runs SIZE cmd
all: $(BUILD_DIR)/firmware.elf $(BUILD_DIR)/firmware.bin
	$(SIZE) $(BUILD_DIR)/firmware.elf

# Linking

## Link all object files in executable
## "$^" all prereqs (.o files)
## "$@" target name (build/firmware.elf)
$(BUILD_DIR)/firmware.elf: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

## Extract raw binary from ELF
## "$<" first prereq
## "-0 binary" strip debug symbols and headers abd output .bin; .bin is what's flashed to MCU
$(BUILD_DIR)/firmware.bin: $(BUILD_DIR)/firmware.elf
	$(OBJCOPY) -O binary $< $@

## Compilation rule
## "%" wildcard - match any filename
## "-c" compile only - don't link
## "|" order-only prereq symbol
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.s | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

## creates build/ dir if it doesn't exist
## order-only - create once, but don't rebuild .o files just because dir timestamp changed
## "-p" no error if dir already exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)