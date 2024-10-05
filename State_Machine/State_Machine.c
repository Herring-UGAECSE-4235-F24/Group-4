// Uses GPIOs 10 to 17 (8 digits) 17 the msb and 10 the lsb
// GPIO 9 is the clock
// GPIOs 20 to 27 are the inputs for the keypad
// pins 20-23 -> X1-X4
// pins 24-27 -> Y1-Y4

// To Compile: gcc -o State_Machine State_Machine.c E4235_Read.s E4235_Write.s E4235_Delaynano.s -l E4235

// Revised the makefile to resolve the compilation and linking executable issues. Now, the keypad doesn't work anymore.
// Seemed to work again after using the wrong compilation command and then recompiling it correctly

// 1 Khz in class library is 1,000,000 iterations total, 500,000 on/off
// By testing, 1 kHz is about 860,000 iterations total or 430,000 on/off.

#include "stdio.h"
#include "gpiotopin.h"
#include <bcm2835.h>

extern int E4235_Write(int, int); // GPIO,value (on/off)
extern void E4235_Delaynano(int); // time

int bintohex()
{
	int len = str(binary);
}


// Main Loop
int main(int argc, char **argv) {
	
	int isOn = 0;
	char binar[100];
	int num = 40;
	
	//power up and displaying hex 40 (while assuming decode is off) and logic analyzer should display hex 40
	
	// waiting for keypress
	if (E4235_Write(20, 1) && (bcm2835_gpio_lev(GPIO24) == 1)){
		rowPushed = 1;
	}
	
	//replace who translateNumber() with my hex printf line
	
	while(1) {
		if (isOn == 0) {
			
			E4235_Write(9, 1);
			E4235_Delaynano(430000);
			isOn = 1;
		
		} else {
		
			E4235_Write(9, 0);
			E4235_Delaynano(430000);
			isOn = 0;
		}

	} // while
	
	while(keypress == 1)
	{
		if (E4235_Write(20, 1) && (bcm2835_gpio_lev(GPIO24) == 1)){
			//output of logic analyzer gets converted to hex here
			printf("Output: %X", num);
		}
	}
				
	return 0;
	
} // Main
