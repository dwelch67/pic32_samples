
void dummy ( unsigned int );
void PUT32 ( unsigned int, unsigned int );
unsigned int GET32 ( unsigned int );

#define TRISECLR 0xBF886104
#define PORTECLR 0xBF886114
#define PORTESET 0xBF886118

#define T1CON 0xBF800600
#define TMR1  0xBF800610
#define PR1   0xBF800620

#define OSCCON    0xBF80F000
#define OSCCONCLR 0xBF80F004
#define OSCCONSET 0xBF80F008
#define SYSKEY    0xBF80F230

void dowait ( void )
{
    unsigned int ra;
    unsigned int rb;
    unsigned int rc;

    rb=GET32(TMR1)&0xFFFF;
    for(ra=24414;ra;ra--)
    {
        while(1)
        {
            rc=GET32(TMR1)&0xFFFF;
            if((rc-rb)>=0x4000) break;
        }
        rb=rc;
    }
}

//PBDIV is set to divide by 1, the timer set to divide by 1
//dowait is wanting the timer to count 0x4000 some number of times
//if the bootloader has left us with 80Mhz then
// 80M / (1*1*0x4000) = 4882.8125 dowait loops per second
// 4882.8215 * 5seconds = 24414 loops
//using a second hand/stop watch it is 5 seconds between led state
//changes so the bootloader has left us running at 80MHz.

void notmain ( void )
{
    PUT32(TRISECLR,0x1);
    PUT32(PORTESET,0x1);

    //insure PBDIV is 1:1
    PUT32(SYSKEY,0xAA996655);
    PUT32(SYSKEY,0x556699AA);
    PUT32(OSCCONCLR,0x180000);
    PUT32(SYSKEY,0x33333333);

    //use timer1 and set to divide by 1
    PUT32(T1CON,0x0000);
    PUT32(TMR1,0x0000);
    PUT32(PR1,0xFFFF);
    PUT32(T1CON,0x8000);

    while(1)
    {
        PUT32(PORTECLR,0x1);
        dowait();
        PUT32(PORTESET,0x1);
        dowait();
    }
}


