

So now it is time to figure out what frequency we are really running.

The diagrams in the users manual for the PIC32MX4xxx family of parts
shows PBDIV controls a divider to PBCLK, and PBCLK can feed the
timers.  And the timers can have a divider.  There is an unlock
sequence described for modifying the oscillator control register, even
though we are not messing with the PLL, etc we need to go through the
motions to modivy the PBDIV.

The first thing to do would be to go for the max divisors divide by 8
on the PBCLK and divide by 256 on the timer.  Then count roll overs or
use other methods to monitor the timer and multiply that event until
you can blink the led in controlled, multiple second intervals.  Then
you can use a stopwatch or second hand on a clock/watch to figure out
how many seconds between state changes on the led.  Count up the
things you know, perhaps 8*256*65536 timer counts in so many seconds
and get a rough idea of what the clock is.  This part can go 80MHz and
through this trial and error I confirmed that (at least on my boards).

Then I left or at least insured that PBDIV was 1:1 and used the timer
in a divide by one to count to multiples of 80 million so that I could
control seconds worth of led blink and that is what you see in this
example.

At the end of this we know a few things, we know what the sysclk
frequency is, we know how to control PBCLK/PBDIV so we know what
PBCLK is so now if for example we want to control a uart we actually
know what rates we are running to program divisors based on PBCLK.

Even if you have a schematic and think you know how the chip powers
up or is configured if there is a bootloader, it is still a good idea
to verify using this kind of method.  If you operate soley on assumptions
you can spend an incredible amount of time with a 2x or 4x error because
you didnt know or realize there was a divisor you didnt know about
because you didnt read the right manual or paragraph because it was
hidden somewhere in a big document.  Very common problem, and blinking
an led like this is a very simple solution to verify assumptions.

