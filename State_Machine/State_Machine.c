// Uses GPIOs 10 to 17 (8 digits) 17 the msb and 10 the lsb
// GPIO 9 is the clock
// GPIOs 20 to 27 are the inputs for the keypad
// 20  to 23 will map to x1 to x4, 24 to 27 will map to y1 to y4

// To Compile: gcc -o State_Machine State_Machine.c -l E4235
// To Compile: gcc -o State_Machine State_Machine.c E4235_Read.s E4235_Write.s E4235_Delaynano.s-l E4235
// Not deallocating memory so we need to fix that and it might affect the read function, do next time


#include <stdio.h>
#include "gpiotopin.h"

extern int E4235_Read(int);
extern int E4235_Write(int, int);
extern void E4235_Delaynano(int);

int main(int argc, char **argv) {
	
	// pin20, pin21, pin22, pin23 -> X1-X4
	// pin24, pin25, pin26, pin27 -> Y1-Y4
	
	int pin20, pin21, pin22, pin23, pin24, pin25, pin26, pin27 = 0;
	
	while(1) {
		
		pin20 = E4235_Write(GPIO20, 1);
		
		pin24 = E4235_Read(GPIO24);
		
		printf("24: %d\n", pin24);
	
		E4235_Delaynano(500000);
		
		//printf("20: %d" pin20, pin21, pin22, pin23, pin24, pin25, pin26, pin27);
		}	
		
		
	return 0;
}
