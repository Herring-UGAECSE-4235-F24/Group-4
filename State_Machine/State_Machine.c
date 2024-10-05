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
#include <bcm2835.h>
//#include "E4235.h"

//extern int E4235_Read(int); // GPIO
//extern int E4235_Write(int, int); // GPIO,value (on/off)
//extern void E4235_Delaynano(int); // time
// we need to make a clock so that it only samples on rising edges of the clock

// Looks for a high on the keypad when writing to that row
int readKeyPad(GPIONumber){
	
	int rowPushed = 0;
		
	E4235_Write(GPIONumber, 1);
	
	if (bcm2835_gpio_lev(GPIO24) == 1){
		rowPushed = 1;
	}
	if (bcm2835_gpio_lev(GPIO25) == 1){
		rowPushed = 2;
	}
	if (bcm2835_gpio_lev(GPIO26) == 1){
		rowPushed = 3;
	}
	if (bcm2835_gpio_lev(GPIO27) == 1){
		rowPushed = 4;
	}
	
	E4235_Write(GPIONumber, 0);
	
	return rowPushed;
	
} // readKeyPad



// Returns the Char that the keypad saw based on the Input at the time and column pushed
 translateNumber(GPIONumber, selectedNumber) {
	
	if (GPIONumber == 20) {
		if (selectedNumber == 1) {
			return '1';
		} else if (selectedNumber == 2) {
			return '2';
		} else if (selectedNumber == 3) {
			return '3';
		} else if (selectedNumber == 4) {
			return 'A';
		}
	 } 
	 
	 if (GPIONumber == 21) {
		if (selectedNumber == 1) {
			return '4';
		} else if (selectedNumber == 2) {
			return '5';
		} else if (selectedNumber == 3) {
			return '6';
		} else if (selectedNumber == 4) {
			return 'B';
		}
	 }
	
	if (GPIONumber == 22) {
		if (selectedNumber == 1) {
			return '7';
		} else if (selectedNumber == 2) {
			return '8';
		} else if (selectedNumber == 3) {
			return '9';
		} else if (selectedNumber == 4) {
			return 'C';
		}
	 } 
	
	if (GPIONumber == 23) {
		if (selectedNumber == 1) {
			return '*';
		} else if (selectedNumber == 2) {
			return '0';
		} else if (selectedNumber == 3) {
			return '#';
		} else if (selectedNumber == 4) {
			return 'D';
		}
	 } 
	 
	return 'L';
}

int lookForInput(){
	
	int stop = 0;
		
	stop = readKeyPad(20); 
	if (stop != 0) {
		return translateNumber(20, stop); 	
	}
	stop = readKeyPad(21);
	if (stop != 0) {
		return translateNumber(21, stop);
	}
	stop = readKeyPad(22);
	if (stop != 0) {
		return translateNumber(22, stop);
	}
	stop = readKeyPad(23);
	if (stop != 0) {
		return translateNumber(23, stop);
	}
				
	return stop;
			
} // Looking For Input


// Main Loop
int main(int argc, char **argv) {
	
	int row 			= 0;
	int selectedNumber 	= 0;
	int decodeOn 		= 0;
	
	if (!bcm2835_init()) {
		return 1;
	} // BCM Initialize
	
	bcm2835_gpio_fsel(24, 0x00);
	bcm2835_gpio_fsel(25, 0x00);
	bcm2835_gpio_fsel(26, 0x00);
	bcm2835_gpio_fsel(27, 0x00);
	
	// Infinite Loop
	while (1) {
		
		selectedNumber = 0; // Necessary to look for continuous input
		
		// Look for input and set it to anything but 0 if found
		while (selectedNumber == 0) {
			selectedNumber = lookForInput();
		}
		
		// When an input is read, enter this loop
		if (selectedNumber != 0) {
					
			printf("Output: %d\n", selectedNumber); // Used to test what is being received
			
		} // Input has been Read Loop 
		
	} // While(1)
				
	return 0;
} // Main
