// Uses GPIOs 10 to 17 (8 digits) 17 the msb and 10 the lsb
// GPIO 9 is the clock
// GPIOs 20 to 27 are the inputs for the keypad
// 20  to 23 will map to x1 to x4, 24 to 27 will map to y1 to y4

// To Compile: gcc -o State_Machine State_Machine.c -lc

#include <stdio.h>
#include <bcm2835.h>
#include "gpiotopin.h"
#include "E4235.h"

int main()
{
	printf("This is the start of our state machine!\n");
	return 0;
}
