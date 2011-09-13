
MIPSGNU ?= mips-sde-elf


COPS = -EL -march=m4k -G0 -Wall -O2 -nostdlib -nostartfiles -ffreestanding

AOPS = -EL -G0 --warn --fatal-warnings

LDOPS = -EL -G0

CLOPS = -Wall -m32 -emit-llvm

LLCOPS = -march=mipsel -mcpu=4ke -relocation-model=static
LLCOPSx = -march=mipsel -mcpu=4ke -relocation-model=dynamic-no-pic

OOPS = -std-compile-opts

#-relocation-model                   - Choose relocation model
#    =default                          -   Target default relocation model
#    =static                           -   Non-relocatable code
#    =pic                              -   Fully relocatable, position independent code
#    =dynamic-no-pic                   -   Relocatable external ref

#  4ke      - Select the 4ke processor.
#  allegrex - Select the allegrex processor.
#  mips1    - Select the mips1 processor.
#  mips2    - Select the mips2 processor.
#  r2000    - Select the r2000 processor.
#  r3000    - Select the r3000 processor.
#  r6000    - Select the r6000 processor.


all : blinker03.32.hex.hex blinker03.16.hex.hex blinker03.llvm.norm.hex.hex blinker03.llvm.opt.hex.hex


clean :
	rm -f *.hex
	rm -f *.o
	rm -f *.elf
	rm -f *.list
	rm -f *.bc
	rm -f *.norm.s
	rm -f *.opt.s
	rm -f ihex

ihex : ihex.c
	gcc ihex.c -o ihex

startup.o : startup.s
	$(MIPSGNU)-as $(AOPS) startup.s -o startup.o

blinker03.32.o : blinker03.c
	$(MIPSGNU)-gcc $(COPS) -c blinker03.c -o blinker03.32.o

blinker03.32.hex : memmap startup.o blinker03.32.o
	$(MIPSGNU)-ld $(LDOPS) -T memmap startup.o blinker03.32.o -o blinker03.32.elf
	$(MIPSGNU)-objdump -D blinker03.32.elf > blinker03.32.list
	$(MIPSGNU)-objcopy blinker03.32.elf -O ihex blinker03.32.hex
	
blinker03.32.hex.hex : blinker03.32.hex ihex
	./ihex blinker03.32.hex



blinker03.16.o : blinker03.c
	$(MIPSGNU)-gcc $(COPS) -mips16 -c blinker03.c -o blinker03.16.o

blinker03.16.hex : memmap startup.o blinker03.16.o
	$(MIPSGNU)-ld $(LDOPS) -T memmap startup.o blinker03.16.o -o blinker03.16.elf
	$(MIPSGNU)-objdump -D blinker03.16.elf > blinker03.16.list
	$(MIPSGNU)-objcopy blinker03.16.elf -O ihex blinker03.16.hex
	
blinker03.16.hex.hex : blinker03.16.hex ihex
	./ihex blinker03.16.hex



blinker03.llvm.bc : blinker03.c
	clang $(CLOPS) -c blinker03.c -o blinker03.llvm.bc

blinker03.llvm.norm.hex : memmap startup.o blinker03.llvm.bc
	llc $(LLCOPS) blinker03.llvm.bc -o blinker03.llvm.norm.s
	$(MIPSGNU)-as $(AOPS) blinker03.llvm.norm.s -o blinker03.llvm.norm.o
	$(MIPSGNU)-ld $(LDOPS) -o blinker03.llvm.norm.elf -T memmap startup.o blinker03.llvm.norm.o
	$(MIPSGNU)-objdump -D blinker03.llvm.norm.elf > blinker03.llvm.norm.list
	$(MIPSGNU)-objcopy blinker03.llvm.norm.elf -O ihex blinker03.llvm.norm.hex

blinker03.llvm.norm.hex.hex : blinker03.llvm.norm.hex ihex
	./ihex blinker03.llvm.norm.hex

blinker03.llvm.opt.hex : memmap startup.o blinker03.llvm.bc
	opt $(OOPS) blinker03.llvm.bc -o blinker03.llvm.opt.bc
	llc $(LLCOPS) blinker03.llvm.opt.bc -o blinker03.llvm.opt.s
	$(MIPSGNU)-as $(AOPS) blinker03.llvm.opt.s -o blinker03.llvm.opt.o
	$(MIPSGNU)-ld $(LDOPS) -o blinker03.llvm.opt.elf -T memmap startup.o blinker03.llvm.opt.o
	$(MIPSGNU)-objdump -D blinker03.llvm.opt.elf > blinker03.llvm.opt.list
	$(MIPSGNU)-objcopy blinker03.llvm.opt.elf -O ihex blinker03.llvm.opt.hex

blinker03.llvm.opt.hex.hex : blinker03.llvm.opt.hex ihex 
	./ihex blinker03.llvm.opt.hex


