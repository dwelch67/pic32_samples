

.globl _start
_start:

    lui $sp,0x8000
    .set    noreorder
    jal notmain
    ori $sp,$sp,0x2000
    .set    reorder
hang:
    j hang
    nop

.globl PUT32
PUT32:
    .set    noreorder
    jr $ra
    sw $a1,0($a0)
    .set    reorder

.globl GET32
GET32:
    .set    noreorder
    jr $ra
    lw $v0,0($a0)
    .set    reorder

.globl dummy
dummy:
    jr $ra
    nop
