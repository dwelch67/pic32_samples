
See the top level README for info on the tools being used.

The blinker01 example is assembly language only, very simple, blinks
an led.  Both the CUI32 and UBW32 boards have an led on RE0 (PORT E
bit 0).  Burns cycles counting to delay long enough to bee seen by the
human eye.

Clearing bit 0 in TRISE by writing a 1 to TRISECLR turns PORT RE0 into
an output.  Then PORTECLR and PORTESET to turn the led on and off.
