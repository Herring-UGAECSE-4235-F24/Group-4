// Uses GPIOs 10 to 17 (8 digits) 17 the msb and 10 the lsb
// GPIO 9 is the clock
// GPIOs 20 to 27 are the inputs for the keypad
// pins 20-23 -> X1-X4
// pins 24-27 -> Y1-Y4

// To Compile: gcc -o State_Machine State_Machine.c E4235_Read.s E4235_Write.s E4235_Delaynano.s -l E4235

// Revised the makefile to resolve the compilation and linking executable issues. Now, the keypad doesn't work anymore.


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
	
	while(1) {
		
		pin20 = E4235_Write(GPIO20, 1);
		pin24 = E4235_Read(GPIO24);
		//pin23 = E4235_Read(GPIO25);
		//pin25 = E4235_Read(GPIO26);
		//pin27 = E4235_Read(GPIO27);
		E4235_Delaynano(500000);
		//pin20 = E4235_Write(GPIO20, 0);
		
		printf("24: %d\n ", pin24);
		//printf("25: %d ", pin25);
		//printf("26: %d ", pin26);
		//printf("27: %d\n", pin27);
		
		//E4235_Delaynano(500000);
		
		
	}	
			
	return 0;
}
