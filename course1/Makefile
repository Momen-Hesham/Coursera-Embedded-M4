
#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM= HOST

# Architectures Specific Flags
LINKER_FILE = msp432p401r.lds
CPU =cortex-m4
ARCH =armv7e-m
SPECS =nosys.specs
FPU =fpv4-sp-d16
FBABL =hard

TARGET=c1m2

# Compiler Flags and Defines
ifeq ($(PLATFORM), HOST)
CC = gcc
LD = ld
LDFLAGS = -Wl,-Map=$(TARGET).map
CFLAGS =-DHOST -Wall -Werror -g -O0 -std=c99
CPPFLAGS =$(INCLUDES)
OBJ= objdump
else
CC=arm-none-eabi-gcc
LD=arm-none-eabi-ld
LDFLAGS=-Wl,-Map=$(TARGET).map -T../$(LINKER_FILE)
CFLAGS=-DMSP432 -Wall -Werror -g -O0 -std=c99 -mcpu=$(CPU) -march=$(ARCH) --specs=$(SPECS) -mthumb -mfpu=$(FPU) -mfloat-abi=$(FBABL)
CPPFLAGS=$(INCLUDES)
OBJ=arm-none-ebai-objdump
endif

OBJS=$(SOURCES:.c=.o)
ASM=$(SOURCES:.c=.asm)
PRE=$(SOURCES:.c=.i)
DEP=$(SOURCES:.c=.d)

%.i: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -E $^ -o $@

%.asm: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -S $^ -o $@ 

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $^ -o $@
%.d: %.c
	@set -e; rm -f $@; \
         $(CC) -MM $(CPPFLAGS) -D$(PLATFORM) $< > $@.$$$$; \
         sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
         rm -f $@.$$$$
$(TARGET).out : $(OBJS) $(DEP)
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@ 
.PHONY: build
build: $(TARGET).out
.PHONY: compile-all
compile-all: $(OBJS)
.PHONY: clean
clean:
	rm -f $(OBJS) $(ASM) $(PRE) $(DEP) $(TARGET).out $(TARGET).map

