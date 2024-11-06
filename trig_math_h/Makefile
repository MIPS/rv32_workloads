# Define the compiler
CC = /projects/mipssw/toolchains/riscv-elf/v3.01/bin/riscv32-mti-elf-gcc

# Define the source file
SRC = trig_bench.c

# Define the flags
CFLAGS = -lm

# Targets and their respective commands
all: trig_ATAN.elf trig_COS.elf trig_SIN.elf

trig_ATAN.elf: $(SRC)
	$(CC) -o $@ $< -DATAN=1 $(CFLAGS)

trig_COS.elf: $(SRC)
	$(CC) -o $@ $< -DCOS=1 $(CFLAGS)

trig_SIN.elf: $(SRC)
	$(CC) -o $@ $< -DSIN=1 $(CFLAGS)

# Clean up the generated files
clean:
	rm -f trig_ATAN.elf trig_COS.elf trig_SIN.elf

