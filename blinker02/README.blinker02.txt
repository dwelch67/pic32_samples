
See the top level README for info on the tools being used.

The blinker02 example is C based with a little assembler for support.
Same as blinker01 basically, turn the led on, use a counter to wait
for a bit, then turn it off, wait for a bit, repeat.  I have multiple
reasons for using small assembler routines (PUT32, GET32, etc) for
reading/writing hardcoded registers/memory rather than doing the
volatile pointer manipulation thing.  The dummy() function is there
to prevent the optimizer from optimizing out the counter loop.

As described in the top level README, both gcc and LLVM (clang) are
used as compilers.

