
.globl _start
_start:

    lui $v0,0xBF88
    li  $v1,1
    sw  $v1,0x6104($v0)

top:
    sw  $v1,0x6114($v0)
    lui $a1,0x10
l00:
    addiu $a1, $a1,-1
    bnez  $a1,l00
    nop
    sw   $v1,0x6118($v0)
    lui  $a1,0x10
l01:
    addiu $a1, $a1,-1
    bnez  $a1,l01
    nop
    j top
    nop




