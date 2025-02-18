XCFLAGS="-static" #-Ofast -mcmodel=medany -fipa-pta  -fno-tree-dominator-opts  -fno-caller-saves -fno-code-hoisting -freorder-blocks-and-partition"
TOOLCHAIN=/opt/riscv/bin/
FILE="simple_div/simple_div"
#$TOOLCHAIN/riscv32-unknown-linux-gnu-gcc  $XCFLAGS -c boot.S -o boot.o
#$TOOLCHAIN/riscv32-unknown-linux-gnu-gcc  $XCFLAGS -c start.S -o start.o
#$TOOLCHAIN/riscv32-unknown-linux-gnu-gcc  $XCFLAGS -c uart_send_char.S -o uart_send_char.o
#$TOOLCHAIN/riscv32-unknown-linux-gnu-gcc  $XCFLAGS -c ee_printf.c -o ee_printf.o
#$TOOLCHAIN/riscv32-unknown-linux-gnu-gcc  $XCFLAGS -c $FILE.c -o $FILE.o

#/opt/riscv/bin/riscv32-unknown-elf-gcc simple_sum.c -o simple_sum_rv32imafd_10000.elf -static -lc -lgcc

echo "-----Linking to create elf-------"
$TOOLCHAIN/riscv32-unknown-elf-gcc  $XCFLAGS  $FILE.c -o $FILE.elf -lc -lgcc -static #-march=rv32imac


echo "-----Creating disassembly-------"
$TOOLCHAIN/riscv32-unknown-elf-objdump -d  $FILE.elf > $FILE.dis
