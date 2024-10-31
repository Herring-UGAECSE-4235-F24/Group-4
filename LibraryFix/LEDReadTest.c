// GPIOs 20 to 27 are the inputs for the keypad
// 20  to 23 will map to x1 to x4, 24 to 27 will map to y1 to y4

// To Compile: gcc -o LEDReadTest LEDReadTest.c -lc

// Compile Using:
// gcc -o LibraryFixBCM LibraryFixBCM.c E4235_Read.s E4235_Delaynano.s -l bcm2835
// Run Using:
// ./LibraryFixBCM

#include <stdio.h>
#include <bcm2835.h>
#include "E4235.h"

extern int E4235_Read(int);
extern void E4235_Delaynano(int);

int main(int argc, char **argv) {
	
	// pin20, pin21, pin22, pin23 -> X1-X4
	// pin24, pin25, pin26, pin27 -> Y1-Y4
	
	int pin20, pin21, pin22, pin23, pin24, pin25, pin26, pin27 = 0;
	
	if (!bcm2835_init()) {
      return 1;
	}

    // Set the pin to be an output
    bcm2835_gpio_fsel(20, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(21, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(22, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(23, BCM2835_GPIO_FSEL_OUTP);

	while(1) {
		
		bcm2835_gpio_write(20, 1);
		E4235_Delaynano(50000000);
		
		pin24 = E4235_Read(24);
		pin25 = E4235_Read(25);
		pin26 = E4235_Read(26);
		pin27 = E4235_Read(27);
		
		E4235_Delaynano(50000000);
		bcm2835_gpio_write(20, 0);
		E4235_Delaynano(50000000);
		printf("%d %d %d %d\n", pin24, pin25, pin26, pin27);
		bcm2835_gpio_write(21, 1);
		
		pin24 = E4235_Read(24);
		pin25 = E4235_Read(25);
		pin26 = E4235_Read(26);
		pin27 = E4235_Read(27);
		
		E4235_Delaynano(50000000);
		bcm2835_gpio_write(21, 0);
		E4235_Delaynano(50000000);
		printf("%d %d %d %d\n", pin24, pin25, pin26, pin27);
		bcm2835_gpio_write(22, 1);
		
		pin24 = E4235_Read(24);
		pin25 = E4235_Read(25);
		pin26 = E4235_Read(26);
		pin27 = E4235_Read(27);
		
		E4235_Delaynano(50000000);
		bcm2835_gpio_write(22, 0);
		E4235_Delaynano(50000000);
		printf("%d %d %d %d\n", pin24, pin25, pin26, pin27);
		bcm2835_gpio_write(23, 1);
		
		pin24 = E4235_Read(24);
		pin25 = E4235_Read(25);
		pin26 = E4235_Read(26);
		pin27 = E4235_Read(27);

		E4235_Delaynano(50000000);
		bcm2835_gpio_write(23, 0);
		E4235_Delaynano(50000000);
		
		printf("%d %d %d %d\n", pin24, pin25, pin26, pin27);
		
		}	// Main
		
		
	return 0;
}
