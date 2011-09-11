
void dummy ( unsigned int );
void PUT32 ( unsigned int, unsigned int );

#define TRISECLR 0xBF886104
#define PORTECLR 0xBF886114
#define PORTESET 0xBF886118

void dowait ( void )
{
    unsigned int ra;

    for(ra=0x40000;ra;ra--) dummy(ra);
}

void notmain ( void )
{
if(1) // CUI32 board
{
    PUT32(TRISECLR,0x1);
    PUT32(PORTESET,0x1);
    while(1)
    {
        PUT32(PORTECLR,0x1);
        dowait();
        PUT32(PORTESET,0x1);
        dowait();
    }
}
else // UBW32 board
{
    PUT32(TRISECLR,0xF);
    PUT32(PORTESET,0xF);
    while(1)
    {
        PUT32(PORTECLR,0x1);
        PUT32(PORTESET,0x2);
        dowait();
        PUT32(PORTECLR,0x2);
        PUT32(PORTESET,0x1);
        dowait();
        PUT32(PORTECLR,0x4);
        PUT32(PORTESET,0x2);
        dowait();
        PUT32(PORTECLR,0x8);
        PUT32(PORTESET,0x4);
        dowait();
        PUT32(PORTECLR,0x4);
        PUT32(PORTESET,0x8);
        dowait();
        PUT32(PORTECLR,0x2);
        PUT32(PORTESET,0x4);
        dowait();
    }
}
}


