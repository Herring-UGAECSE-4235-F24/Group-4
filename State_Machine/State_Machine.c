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
extern int E4235_Write(int, int); // GPIO,value (on/off)
extern void E4235_Delaynano(int); // time
// we need to make a clock so that it only samples on rising edges of the clock

// compile command is gcc -o State_Machine State_Machine.c -l bcm2835

// Looks for a high on the keypad when writing to that row
int readKeyPad(int GPIONumber){
	
	int rowPushed = 0;
		
	if (GPIONumber == 20) {
		bcm2835_gpio_write(20, 1);
		bcm2835_gpio_write(21, 0);
		bcm2835_gpio_write(22, 0);
		bcm2835_gpio_write(23, 0);
	}
	
	if (GPIONumber == 21) {
		bcm2835_gpio_write(20, 0);
		bcm2835_gpio_write(21, 1);
		bcm2835_gpio_write(22, 0);
		bcm2835_gpio_write(23, 0);
	}
	
	if (GPIONumber == 22) {
		bcm2835_gpio_write(20, 0);
		bcm2835_gpio_write(21, 0);
		bcm2835_gpio_write(22, 1);
		bcm2835_gpio_write(23, 0);
	}
	
	if (GPIONumber == 23) {
		bcm2835_gpio_write(20, 0);
		bcm2835_gpio_write(21, 0);
		bcm2835_gpio_write(22, 0);
		bcm2835_gpio_write(23, 1);
	}
	
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
	
	bcm2835_gpio_write(GPIONumber, 0);
	
	return rowPushed;
	
} // readKeyPad



// Returns the Char that the keypad saw based on the Input at the time and column pushed
int translateNumber(int GPIONumber, int selectedNumber) {
	
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



void debounce() {
	
	int x = 40000000;
	
	while (x != 0) {
		x = x -1;
	} // while
	
	return;
	
} // debounce
	


int lookForInput(){
	
	int stop = 0;
		
	stop = readKeyPad(GPIO20); 
	if (stop != 0) {
		return translateNumber(GPIO20, stop); 	
	}
	stop = readKeyPad(GPIO21);
	if (stop != 0) {
		return translateNumber(GPIO21, stop);
	}
	stop = readKeyPad(GPIO22);
	if (stop != 0) {
		return translateNumber(GPIO22, stop);
	}
	stop = readKeyPad(GPIO23);
	if (stop != 0) {
		return translateNumber(GPIO23, stop);
	}
				
	return stop;
			
} // Looking For Input



int deciperCodeHex(selectedNumber){
	
	if (selectedNumber == 30) {
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 1);
		bcm2835_gpio_write(12, 1);
		bcm2835_gpio_write(13, 1);
		bcm2835_gpio_write(16, 1);
		bcm2835_gpio_write(17, 1);
		bcm2835_gpio_write(18, 0);
	} else if (selectedNumber == 31) {
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 1);
		bcm2835_gpio_write(12, 1);
		bcm2835_gpio_write(13, 1);
		bcm2835_gpio_write(16, 1);
		bcm2835_gpio_write(17, 1);
		bcm2835_gpio_write(18, 1);
	} else if (selectedNumber == 32) {
		bcm2835_gpio_write(10, 1);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 0);
		bcm2835_gpio_write(17, 0);
		bcm2835_gpio_write(18, 0);
	} else if (selectedNumber == 33) {
		bcm2835_gpio_write(10, 1);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 0);
		bcm2835_gpio_write(17, 0);
		bcm2835_gpio_write(18, 1);
	} else if (selectedNumber == 34) {
		bcm2835_gpio_write(10, 1);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 0);
		bcm2835_gpio_write(17, 1);
		bcm2835_gpio_write(18, 0);
	} else if (selectedNumber == 35) {
		bcm2835_gpio_write(10, 1);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 0);
		bcm2835_gpio_write(17, 1);
		bcm2835_gpio_write(18, 1);
	} else if (selectedNumber == 36) {
		bcm2835_gpio_write(10, 1);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 1);
		bcm2835_gpio_write(17, 0);
		bcm2835_gpio_write(18, 0);
	} else if (selectedNumber == 37) {
		bcm2835_gpio_write(10, 1);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 1);
		bcm2835_gpio_write(17, 0);
		bcm2835_gpio_write(18, 1);
	} else if (selectedNumber == 38) {
		bcm2835_gpio_write(10, 1);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 1);
		bcm2835_gpio_write(17, 1);
		bcm2835_gpio_write(18, 0);
	} else if (selectedNumber == 39) {
		bcm2835_gpio_write(10, 1);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 1);
		bcm2835_gpio_write(17, 1);
		bcm2835_gpio_write(18, 1);
	} else if (selectedNumber == 40) {
		bcm2835_gpio_write(10, 1);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 1);
		bcm2835_gpio_write(16, 0);
		bcm2835_gpio_write(17, 0);
		bcm2835_gpio_write(18, 0);
	} else if (selectedNumber == 41) {
		bcm2835_gpio_write(10, 1);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 1);
		bcm2835_gpio_write(16, 0);
		bcm2835_gpio_write(17, 0);
		bcm2835_gpio_write(18, 1);
	} else if (selectedNumber == 42) {
		bcm2835_gpio_write(10, 1);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 1);
		bcm2835_gpio_write(16, 0);
		bcm2835_gpio_write(17, 1);
		bcm2835_gpio_write(18, 0);
	} else if (selectedNumber == 43) {
		bcm2835_gpio_write(10, 1);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 1);
		bcm2835_gpio_write(16, 0);
		bcm2835_gpio_write(17, 1);
		bcm2835_gpio_write(18, 1);
	} else if (selectedNumber == 44) {
		bcm2835_gpio_write(10, 1);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 1);
		bcm2835_gpio_write(16, 1);
		bcm2835_gpio_write(17, 0);
		bcm2835_gpio_write(18, 0);
	} 
	
	return 1;
}

int deciperCodeDecimal(selectedNumber){
	
	if (selectedNumber == 30) {
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 0);
		bcm2835_gpio_write(17, 0);
		bcm2835_gpio_write(18, 0);
	} else if (selectedNumber == 31) {
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 0);
		bcm2835_gpio_write(17, 0);
		bcm2835_gpio_write(18, 1);
	} else if (selectedNumber == 32) {
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 0);
		bcm2835_gpio_write(17, 1);
		bcm2835_gpio_write(18, 0);
	} else if (selectedNumber == 33) {
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 0);
		bcm2835_gpio_write(17, 1);
		bcm2835_gpio_write(18, 1);
	} else if (selectedNumber == 34) {
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 1);
		bcm2835_gpio_write(17, 0);
		bcm2835_gpio_write(18, 0);
	} else if (selectedNumber == 35) {
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 1);
		bcm2835_gpio_write(17, 0);
		bcm2835_gpio_write(18, 1);
	} else if (selectedNumber == 36) {
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 1);
		bcm2835_gpio_write(17, 1);
		bcm2835_gpio_write(18, 0);
	} else if (selectedNumber == 37) {
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 1);
		bcm2835_gpio_write(17, 1);
		bcm2835_gpio_write(18, 1);
	} else if (selectedNumber == 38) {
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 1);
		bcm2835_gpio_write(16, 0);
		bcm2835_gpio_write(17, 0);
		bcm2835_gpio_write(18, 0);
	} else if (selectedNumber == 39) {
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 1);
		bcm2835_gpio_write(16, 0);
		bcm2835_gpio_write(17, 0);
		bcm2835_gpio_write(18, 1);
	} else if (selectedNumber == 40) {
		bcm2835_gpio_write(10, 1);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 1);
		bcm2835_gpio_write(16, 0);
		bcm2835_gpio_write(17, 0);
		bcm2835_gpio_write(18, 0);
	} else if (selectedNumber == 41) {
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 1);
		bcm2835_gpio_write(16, 0);
		bcm2835_gpio_write(17, 1);
		bcm2835_gpio_write(18, 0);
	} else if (selectedNumber == 42) {
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 1);
		bcm2835_gpio_write(16, 0);
		bcm2835_gpio_write(17, 1);
		bcm2835_gpio_write(18, 1);
	} else if (selectedNumber == 43) {
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 1);
		bcm2835_gpio_write(16, 1);
		bcm2835_gpio_write(17, 0);
		bcm2835_gpio_write(18, 0);
	} else if (selectedNumber == 44) {
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 1);
		bcm2835_gpio_write(16, 1);
		bcm2835_gpio_write(17, 0);
		bcm2835_gpio_write(18, 1);
	} 
	
	return 1;
}

// Main Loop
int main(int argc, char **argv) {
	
	int selectedNumber 	= 0;
	int decodeOn 		= 0;
	int lastVar			= 0;
	int curVar			= 40;
	int flashTimer 		= 0;
	int flash40 		= 0;
	
	if (!bcm2835_init()) {
		return 1;
	} // BCM Initialize
	
	bcm2835_gpio_fsel(9, 0x01);
	bcm2835_gpio_fsel(10, 0x01);
	bcm2835_gpio_fsel(11, 0x01);
	bcm2835_gpio_fsel(12, 0x01);
	bcm2835_gpio_fsel(13, 0x01);
	bcm2835_gpio_fsel(16, 0x01);
	bcm2835_gpio_fsel(17, 0x01);
	bcm2835_gpio_fsel(18, 0x01);
	
	//bcm2835_gpio_set_pud(9, 0x0094);
	//bcm2835_gpio_set_pud(10, 0x0094);
	//bcm2835_gpio_set_pud(11, 0x0094);
	//bcm2835_gpio_set_pud(12, 0x0094);
	//bcm2835_gpio_set_pud(13, 0x0094);
	//bcm2835_gpio_set_pud(16, 0x0094);
	//bcm2835_gpio_set_pud(17, 0x0094);
	//bcm2835_gpio_set_pud(18, 0x0094);
	
	bcm2835_gpio_fsel(20, 0x01);
	bcm2835_gpio_fsel(21, 0x01);
	bcm2835_gpio_fsel(22, 0x01);
	bcm2835_gpio_fsel(23, 0x01);
	
	bcm2835_gpio_fsel(24, 0x00);
	bcm2835_gpio_fsel(25, 0x00);
	bcm2835_gpio_fsel(26, 0x00);
	bcm2835_gpio_fsel(27, 0x00);
	
	printf("%d\n", 40); 
	// send @ to the logic analzyer
	
	flashTimer = 0;
	flash40 = 0;
	
	// Infinite Loop
	while (1) {
		
		selectedNumber = 0; // Necessary to look for continuous input
			
		// Look for input and set it to anything but 0 if found
		if (selectedNumber == 0) {
			selectedNumber = lookForInput();
		} // while
				
				// When an input is read, enter this loop
		if (selectedNumber != 0) {
			debounce();
			curVar = selectedNumber;
			
			printf("%d\n", selectedNumber); // Used to test what is being received					
		} // Input has been Read Loop

		if (flashTimer <= 50000) {
			if (decodeOn == 1) {
				printf("%d\n", 40); // Used to test what is being received
				deciperCodeHex(40); // Sends binary hex string to LA
			} else {
				printf("%d\n", 40); // Used to test what is being received
				deciperCodeDecimal(40);
				//deciperCodeBinary(curVar); // Sends binary hex string to LA
			}
			
		} else if (flashTimer == 200000) {
			flashTimer = 0;
		} else {
			printf("%d\n", curVar); // Used to test what is being received
			if (decodeOn == 1) {
				printf("%d\n", curVar); // Used to test what is being received
				deciperCodeHex(curVar); // Sends binary hex string to LA
			} else {
				printf("%d\n", curVar); // Used to test what is being received
				deciperCodeDecimal(curVar);
				//deciperCodeBinary(curVar); // Sends binary hex string to LA
			}
			// push curVar to FSM
		}
		
		// Decode Toggle
		if (selectedNumber == 23) {
			if (decodeOn == 1) {
				decodeOn = 0;
				printf("decode on!\n");
			} else {
				decodeOn = 1;
				printf("decode off!\n");
			}
		} 
		
		// Reset
		if (selectedNumber == 42) {
			printf("reset!\n");
			decodeOn = 0;
			curVar = 40;
		}
		
		flashTimer = flashTimer + 1;
		
	} // While(1)
				
	return 0;
} // Main
