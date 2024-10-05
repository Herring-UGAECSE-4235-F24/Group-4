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
// simple parallel

#include "stdio.h"
#include "gpiotopin.h"
#include <bcm2835.h>

// 1000 delay is 1 kHz

int writeHexToLA(selectedNumber){
		
	if (selectedNumber == 48) {
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 1);
		bcm2835_gpio_write(12, 1);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 0);
		bcm2835_gpio_write(17, 0);
		bcm2835_gpio_write(18, 0);
	} else if (selectedNumber == 49) {
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 1);
		bcm2835_gpio_write(12, 1);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 0);
		bcm2835_gpio_write(17, 0);
		bcm2835_gpio_write(18, 1);
	} else if (selectedNumber == 50) {
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 1);
		bcm2835_gpio_write(12, 1);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 0);
		bcm2835_gpio_write(17, 1);
		bcm2835_gpio_write(18, 0);
	} else if (selectedNumber == 51) {
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 1);
		bcm2835_gpio_write(12, 1);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 0);
		bcm2835_gpio_write(17, 1);
		bcm2835_gpio_write(18, 1);
	} else if (selectedNumber == 52) {
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 1);
		bcm2835_gpio_write(12, 1);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 1);
		bcm2835_gpio_write(17, 0);
		bcm2835_gpio_write(18, 0);
	} else if (selectedNumber == 53) {
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 1);
		bcm2835_gpio_write(12, 1);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 1);
		bcm2835_gpio_write(17, 0);
		bcm2835_gpio_write(18, 1);
	} else if (selectedNumber == 54) {
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 1);
		bcm2835_gpio_write(12, 1);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 1);
		bcm2835_gpio_write(17, 1);
		bcm2835_gpio_write(18, 0);
	} else if (selectedNumber == 55) {
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 1);
		bcm2835_gpio_write(12, 1);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 1);
		bcm2835_gpio_write(17, 1);
		bcm2835_gpio_write(18, 1);
	} else if (selectedNumber == 56) {
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 1);
		bcm2835_gpio_write(12, 1);
		bcm2835_gpio_write(13, 1);
		bcm2835_gpio_write(16, 0);
		bcm2835_gpio_write(17, 0);
		bcm2835_gpio_write(18, 0);
	} else if (selectedNumber == 57) {
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 1);
		bcm2835_gpio_write(12, 1);
		bcm2835_gpio_write(13, 1);
		bcm2835_gpio_write(16, 0);
		bcm2835_gpio_write(17, 0);
		bcm2835_gpio_write(18, 1);
	} else if (selectedNumber == 40) {
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 1);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 1);
		bcm2835_gpio_write(16, 0);
		bcm2835_gpio_write(17, 0);
		bcm2835_gpio_write(18, 0);
	} else if (selectedNumber == 65) {
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 1);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 0);
		bcm2835_gpio_write(17, 0);
		bcm2835_gpio_write(18, 1);
	} else if (selectedNumber == 66) {
		bcm2835_gpio_write(10, 1);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 0);
		bcm2835_gpio_write(17, 1);
		bcm2835_gpio_write(18, 0);
	} else if (selectedNumber == 67) {
		bcm2835_gpio_write(10, 1);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 0);
		bcm2835_gpio_write(17, 1);
		bcm2835_gpio_write(18, 1);
	} else if (selectedNumber == 68) {
		bcm2835_gpio_write(10, 1);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 1);
		bcm2835_gpio_write(17, 0);
		bcm2835_gpio_write(18, 0);
	} 
	
	return 1;
} // Write Binary to LA

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



int lookForInput() {
	
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



int clockLoop() {
	
	int selectedNumber = 0;
	
	selectedNumber = lookForInput();
	writeHexToLA(selectedNumber);
	
	return 1;
	
}

// Main Loop
int main(int argc, char **argv) {

	int isOn = 0;
	int iterationsFor1kHz = 0;
	
	if (!bcm2835_init()) {
      return 1;
    }
	
	bcm2835_gpio_fsel(9, 0x01);
	bcm2835_gpio_fsel(10, 0x01);
	bcm2835_gpio_fsel(11, 0x01);
	bcm2835_gpio_fsel(12, 0x01);
	bcm2835_gpio_fsel(13, 0x01);
	bcm2835_gpio_fsel(16, 0x01);
	bcm2835_gpio_fsel(17, 0x01);
	bcm2835_gpio_fsel(18, 0x01);
	
	bcm2835_gpio_fsel(20, 0x01);
	bcm2835_gpio_fsel(21, 0x01);
	bcm2835_gpio_fsel(22, 0x01);
	bcm2835_gpio_fsel(23, 0x01);
	
	bcm2835_gpio_fsel(24, 0x00);
	bcm2835_gpio_fsel(25, 0x00);
	bcm2835_gpio_fsel(26, 0x00);
	bcm2835_gpio_fsel(27, 0x00);
	
	while(1) {
		

		if ((iterationsFor1kHz == 130000) && (isOn == 0)) {
			
			bcm2835_gpio_write(9, 1);
			iterationsFor1kHz = 0;
			isOn = 1;
			clockLoop();
		
			// print to screen
			
		} else if ((iterationsFor1kHz == 130000) && (isOn == 1)) {
		
			bcm2835_gpio_write(9, 0);
			iterationsFor1kHz = 0;
			isOn = 0;
			
		} // if/else
		
		iterationsFor1kHz = iterationsFor1kHz + 1;

	} // while
				
	return 0;
	
} // Main
