// Uses GPIOs 10 to 17 (8 digits) 17 the msb and 10 the lsb
// GPIO 9 is the clock
// GPIOs 20 to 27 are the inputs for the keypad
// pins 20-23 -> X1-X4
// pins 24-27 -> Y1-Y4

// To Compile: gcc -o State_Machine State_Machine.c E4235_Read.s E4235_Write.s E4235_Delaynano.s -l E4235

// Revised the makefile to resolve the compilation and linking executable issues. Now, the keypad doesn't work anymore.
// Seemed to work again after using the wrong compilation command and then recompiling it correctly

#include "stdio.h"
#include <bcm2835.h>
#include "E4235.h"

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
	
	char rowOne [3];
	
	if (!bcm2835_init()) {
		return 1;
	} // BCM Initialize
	
	bcm2835_gpio_fsel(pin24, 0x00);
	bcm2835_gpio_fsel(pin25, 0x00);
	bcm2835_gpio_fsel(pin26, 0x00);
	bcm2835_gpio_fsel(pin27, 0x00);

	
	while(1) {
		
		pin20 = E4235_Write(20, 1);
		pin21 = E4235_Write(21, 1);
		pin22 = E4235_Write(22, 1);
		pin23 = E4235_Write(23, 1);
		
		pin24 = bcm2835_gpio_lev(24);
		pin25 = bcm2835_gpio_lev(25);
		pin26 = bcm2835_gpio_lev(26);
		pin27 = bcm2835_gpio_lev(27);
		
		printf("24: %d ", pin24);
		printf("25: %d ", pin25);
		printf("26: %d ", pin26);
		printf("27: %d\n", pin27);
		
		E4235_Delaynano(250000);
		
		//pin20 = E4235_Write(20, 0);
		//pin21 = E4235_Write(21, 0);
		//pin22 = E4235_Write(22, 0);
		//pin23 = E4235_Write(23, 0);
		
		E4235_Delaynano(250000);
	}	
			
	return 0;
}
