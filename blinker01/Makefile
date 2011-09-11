
MIPSGNU ?= mips-sde-elf

AOPS = -EL -G0 --warn --fatal-warnings

LDOPS = -EL -G0

all : blinker01.hex.hex

clean :
	rm -f *.hex
	rm -f *.o
	rm -f *.elf
	rm -f *.list
	rm -f ihex

ihex : ihex.c
	gcc ihex.c -o ihex


blinker01.o : blinker01.s
	$(MIPSGNU)-as $(AOPS) blinker01.s -o blinker01.o

blinker01.hex : memmap blinker01.o
	$(MIPSGNU)-ld $(LDOPS) -T memmap blinker01.o -o blinker01.elf
	$(MIPSGNU)-objdump -D blinker01.elf > blinker01.list
	$(MIPSGNU)-objcopy blinker01.elf -O ihex blinker01.hex
	
blinker01.hex.hex : blinker01.hex ihex
	./ihex blinker01.hex


