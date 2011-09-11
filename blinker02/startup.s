
.globl _start
_start:

    lui $sp,0x8000
    ori $sp,$sp,0x2000
    jal notmain
    nop
hang:
    j hang
    nop

.globl PUT32
PUT32:
    sw $a1,0($a0)
    jr $ra
    nop

.globl dummy
dummy:
    jr $ra
    nop
