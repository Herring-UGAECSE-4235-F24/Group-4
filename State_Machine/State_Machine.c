// Uses GPIOs 10 to 17 (8 digits) 17 the msb and 10 the lsb
// GPIO 9 is the clock
// GPIOs 20 to 27 are the inputs for the keypad
// pins 20-23 -> X1-X4
// pins 24-27 -> Y1-Y4

// To Compile: gcc -o State_Machine State_Machine.c E4235_Read.s E4235_Write.s E4235_Delaynano.s -l E4235

// Revised the makefile to resolve the compilation and linking executable issues. Now, the keypad doesn't work anymore.
// Seemed to work again after using the wrong compilation command and then recompiling it correctly

#include "stdio.h"
#include "gpiotopin.h"
//#include "E4235.h"

extern int E4235_Read(int); // GPIO
extern int E4235_Write(int, int); // GPIO,value (on/off)
extern void E4235_Delaynano(int); // time

int main(int argc, char **argv) {
	
	int pin20 = 0;
	int pin21 = 0;
	int pin22 = 0;
	int pin23 = 0;
	int pin24 = 0;
	int pin25 = 0;
	int pin26 = 0;
	int pin27 = 0;
	int stop = 1;
	
	while(stop != 0) {
		
		pin24 = readKeyPad(GPIO20);
		printf("24: %d\n", pin24);
	}
				
	return 0;
} // Main



int readKeyPad(gpioNumber){
		
	E4235_Write(gpioNumber, 1);
	
	if (E4235_Read(GPIO24) == 1){
		return 1;
	}
	if (E4235_Read(GPIO25) == 1){
		return 2;
	}
	if (E4235_Read(GPIO26) == 1){
		return 3;
	}
	if (E4235_Read(GPIO27) == 1){
		return 4;
	}
	
	return 0;
	
} // readKeyPad
