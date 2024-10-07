// State_Machine
//
// ECSE 4235 - Embedded Systems II
// Property of Samuel Brewster and Simline Gijo	
// Created 19SEP2024
// Finished 03OCT2024
// To Compile: gcc -o State_Machine State_Machine.c -l bcm2835

#include "stdio.h"
#include "gpiotopin.h"
#include <bcm2835.h>

// Outputs the decoded hex number through GPIOs into the Logic Analyzer.
int decodeOnOutput(selectedNumber){

	// GPIO 10 is the MSB and 18 is the LSB
	// The GPIOS follow this 7-bit format
	// 0+0+0 0+0+0+0 -> 10+11+12 13+16+17+18
	
	if (selectedNumber == 48) { //  0x30 - 011 0000
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 1);
		bcm2835_gpio_write(12, 1);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 0); 
		bcm2835_gpio_write(17, 0); 
		bcm2835_gpio_write(18, 0);
	} else if (selectedNumber == 49) { // 0x31 - 011 0001
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 1);
		bcm2835_gpio_write(12, 1);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 0);
		bcm2835_gpio_write(17, 0);
		bcm2835_gpio_write(18, 1);
	} else if (selectedNumber == 50) { // 0x32 - 011 0010
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 1);
		bcm2835_gpio_write(12, 1);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 0);
		bcm2835_gpio_write(17, 1);
		bcm2835_gpio_write(18, 0);
	} else if (selectedNumber == 51) { // 0x33 - 011 0011
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 1);
		bcm2835_gpio_write(12, 1);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 0);
		bcm2835_gpio_write(17, 1);
		bcm2835_gpio_write(18, 1);
	} else if (selectedNumber == 52) { // 0x34 - 011 0100
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 1);
		bcm2835_gpio_write(12, 1);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 1);
		bcm2835_gpio_write(17, 0);
		bcm2835_gpio_write(18, 0);
	} else if (selectedNumber == 53) { // 0x35 - 011 0101
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 1);
		bcm2835_gpio_write(12, 1);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 1);
		bcm2835_gpio_write(17, 0);
		bcm2835_gpio_write(18, 1);
	} else if (selectedNumber == 54) { // 0x36 - 011 0110
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 1);
		bcm2835_gpio_write(12, 1);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 1);
		bcm2835_gpio_write(17, 1);
		bcm2835_gpio_write(18, 0);
	} else if (selectedNumber == 55) { // 0x37 - 011 0111
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 1);
		bcm2835_gpio_write(12, 1);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 1);
		bcm2835_gpio_write(17, 1);
		bcm2835_gpio_write(18, 1);
	} else if (selectedNumber == 56) { // 0x38 - 011 1000
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 1);
		bcm2835_gpio_write(12, 1);
		bcm2835_gpio_write(13, 1);
		bcm2835_gpio_write(16, 0);
		bcm2835_gpio_write(17, 0);
		bcm2835_gpio_write(18, 0);
	} else if (selectedNumber == 57) { // 0x39 - 011 1001
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 1);
		bcm2835_gpio_write(12, 1);
		bcm2835_gpio_write(13, 1);
		bcm2835_gpio_write(16, 0);
		bcm2835_gpio_write(17, 0);
		bcm2835_gpio_write(18, 1);
	} else if (selectedNumber == 40) { // 0x40 - 100 0000
		bcm2835_gpio_write(10, 1);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 0);
		bcm2835_gpio_write(17, 0);
		bcm2835_gpio_write(18, 0);
	} else if (selectedNumber == 65) { // 0x41 - 100 0001
		bcm2835_gpio_write(10, 1);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 0);
		bcm2835_gpio_write(17, 0);
		bcm2835_gpio_write(18, 1);
	} else if (selectedNumber == 66) { // 0x42 - 100 0010
		bcm2835_gpio_write(10, 1);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 0);
		bcm2835_gpio_write(17, 1);
		bcm2835_gpio_write(18, 0);
	} else if (selectedNumber == 67) { // 0x43 - 100 0011
		bcm2835_gpio_write(10, 1);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 0);
		bcm2835_gpio_write(17, 1);
		bcm2835_gpio_write(18, 1);
	} else if (selectedNumber == 68) { // 0x44 - 100 0100
		bcm2835_gpio_write(10, 1);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 1);
		bcm2835_gpio_write(17, 0);
		bcm2835_gpio_write(18, 0);
	} 
	
	return 1;
} // decodeOnOutput 


// Outputs the binary equivalent of the ascii choice through GPIOs into the Logic Analyzer.
int decodeOffOutput(selectedNumber){

	// GPIO 10 is the MSB and 18 is the LSB
	// The GPIOS follow this 7-bit format
	// 0+0+0 0+0+0+0 -> 10+11+12 13+16+17+18
	
	if (selectedNumber == 48) { // Should output 0 
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 0); 
		bcm2835_gpio_write(16, 0); 
		bcm2835_gpio_write(17, 0); 
		bcm2835_gpio_write(18, 0); 
	} else if (selectedNumber == 49) { // 1
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 0);
		bcm2835_gpio_write(17, 0);
		bcm2835_gpio_write(18, 1);
	} else if (selectedNumber == 50) { // 2
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 0);
		bcm2835_gpio_write(17, 1);
		bcm2835_gpio_write(18, 0);
	} else if (selectedNumber == 51) { // 3
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 0);
		bcm2835_gpio_write(17, 1);
		bcm2835_gpio_write(18, 1);
	} else if (selectedNumber == 52) { // 4
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 1);
		bcm2835_gpio_write(17, 0);
		bcm2835_gpio_write(18, 0);
	} else if (selectedNumber == 53) { // 5
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 1);
		bcm2835_gpio_write(17, 0);
		bcm2835_gpio_write(18, 1);
	} else if (selectedNumber == 54) { // 6
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 1);
		bcm2835_gpio_write(17, 1);
		bcm2835_gpio_write(18, 0);
	} else if (selectedNumber == 55) { // 7
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 1);
		bcm2835_gpio_write(17, 1);
		bcm2835_gpio_write(18, 1);
	} else if (selectedNumber == 56) { // 8
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 1);
		bcm2835_gpio_write(16, 0);
		bcm2835_gpio_write(17, 0);
		bcm2835_gpio_write(18, 0);
	} else if (selectedNumber == 57) { // 9
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 1);
		bcm2835_gpio_write(16, 0);
		bcm2835_gpio_write(17, 0);
		bcm2835_gpio_write(18, 1);
	} else if (selectedNumber == 40) { // @ (64 in decimal)
		bcm2835_gpio_write(10, 1);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 0);
		bcm2835_gpio_write(16, 0);
		bcm2835_gpio_write(17, 0);
		bcm2835_gpio_write(18, 0);
	} else if (selectedNumber == 65) { // A = 10
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 1);
		bcm2835_gpio_write(16, 0);
		bcm2835_gpio_write(17, 1);
		bcm2835_gpio_write(18, 0);
	} else if (selectedNumber == 66) { // B = 11
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 1);
		bcm2835_gpio_write(16, 0);
		bcm2835_gpio_write(17, 1);
		bcm2835_gpio_write(18, 1);
	} else if (selectedNumber == 67) { // C = 12
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 1);
		bcm2835_gpio_write(16, 1);
		bcm2835_gpio_write(17, 0);
		bcm2835_gpio_write(18, 0);
	} else if (selectedNumber == 68) { // D = 13
		bcm2835_gpio_write(10, 0);
		bcm2835_gpio_write(11, 0);
		bcm2835_gpio_write(12, 0);
		bcm2835_gpio_write(13, 1);
		bcm2835_gpio_write(16, 1);
		bcm2835_gpio_write(17, 0);
		bcm2835_gpio_write(18, 1);
	} 
	
	return 1;
} // decodeOffOutput

// Looks for a high on the keypad when writing to that row
int readKeyPad(int GPIONumber){
	
	int rowPushed = 0;

	// Writes High to GPIO 20 and sets each other GPIO to Low
	if (GPIONumber == 20) {
		bcm2835_gpio_write(20, 1);
		bcm2835_gpio_write(21, 0);
		bcm2835_gpio_write(22, 0);
		bcm2835_gpio_write(23, 0);
	}
		
	// Writes High to GPIO 21 and sets each other GPIO to Low
	if (GPIONumber == 21) {
		bcm2835_gpio_write(20, 0);
		bcm2835_gpio_write(21, 1);
		bcm2835_gpio_write(22, 0);
		bcm2835_gpio_write(23, 0);
	}

	// Writes High to GPIO 22 and sets each other GPIO to Low
	if (GPIONumber == 22) {
		bcm2835_gpio_write(20, 0);
		bcm2835_gpio_write(21, 0);
		bcm2835_gpio_write(22, 1);
		bcm2835_gpio_write(23, 0);
	}

	// Writes High to GPIO 23 and sets each other GPIO to Low
	if (GPIONumber == 23) {
		bcm2835_gpio_write(20, 0);
		bcm2835_gpio_write(21, 0);
		bcm2835_gpio_write(22, 0);
		bcm2835_gpio_write(23, 1);
	}

	// Reads the Output of the Keypad and Sets the Ouput accordingly
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

	// Turns off the Keypad input
	bcm2835_gpio_write(GPIONumber, 0);
	
	return rowPushed;
	
} // readKeyPad



// Returns the value of column that was selected by the keypad read based on the GPIO Input used.
int translateNumber(int GPIONumber, int selectedNumber) {

	// Selects which value is selected in row 1
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
	
	 // Selects which value is selected in row 2
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

	// Selects which value is selected in row 3
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

	// Selects which value is selected in row 4
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
	 
	return 'L'; // Test Case that is never reached
}



// Calls each keypad input and reads the output from it. If a value is returned, it returns its char equivalent via the translateNumber function.
int lookForInput() {
	
	int stop = 0;

	stop = readKeyPad(20); // Reads the output from sending an input to row 1
	if (stop != 0) {
		return translateNumber(20, stop); // translates if a row 1 output is received	
	}
	stop = readKeyPad(21); // Reads the output from sending an input to row 2
	if (stop != 0) {
		return translateNumber(21, stop); // translates if a row 2 output is received
	}
	stop = readKeyPad(22); // Reads the output from sending an input to row 3
	if (stop != 0) {
		return translateNumber(22, stop); // translates if a row 3 output is received
	}
	stop = readKeyPad(23); // Reads the output from sending an input to row 4
	if (stop != 0) {
		return translateNumber(23, stop); // translates if a row 4 output is received
	}
				
	return stop;
			
} // Looking For Input



// A simple debouncing function that causes a delay by counting computer iterations.
void debounce() {
	
	int x = 40000000;
	
	while (x != 0) {
		x = x -1;
	} // while
	
	return;
	
} // debounce



// Main Loop
int main(int argc, char **argv) {

	// Initialize Variables
	int isOn = 0;
	int iterationsFor1kHz = 0;
	int selectedNumber = 0;
	int decodeOn = 0;
	int curVar = 40;
	int timerToBlink = 0;
	int lastBlinked40 = 0;		

	// Initialize the BCM Library
	if (!bcm2835_init()) {
      		return 1;
    	}

	// Set the following Pins to Outputs (Logic Analyzers)
	bcm2835_gpio_fsel(9, 0x01);
	bcm2835_gpio_fsel(10, 0x01);
	bcm2835_gpio_fsel(11, 0x01);
	bcm2835_gpio_fsel(12, 0x01);
	bcm2835_gpio_fsel(13, 0x01);
	bcm2835_gpio_fsel(16, 0x01);
	bcm2835_gpio_fsel(17, 0x01);
	bcm2835_gpio_fsel(18, 0x01);

	// Set the following Pins to Outputs (Keypad)
	bcm2835_gpio_fsel(20, 0x01);
	bcm2835_gpio_fsel(21, 0x01);
	bcm2835_gpio_fsel(22, 0x01);
	bcm2835_gpio_fsel(23, 0x01);

	// Set the following Pins to Inputs (Keypad)
	bcm2835_gpio_fsel(24, 0x00);
	bcm2835_gpio_fsel(25, 0x00);
	bcm2835_gpio_fsel(26, 0x00);
	bcm2835_gpio_fsel(27, 0x00);

	// Initializes the program by Outputting 40 to the Logic Analyzer
	decodeOffOutput(40);

	// Main While Loop
	while(1) {
		
		// Clock Switch Case Loop - When entering If, the program is on a rising edge
		if ((iterationsFor1kHz == 130000) && (isOn == 0)) {

			bcm2835_gpio_write(9, 1); 	// Writes a high to the clock
			iterationsFor1kHz = 0;		// Resets the clock counter
			isOn = 1;			// Sets the clock to be on so it can switch cases
	
			selectedNumber = lookForInput();	// Looks for user input
			
			// If user input is selected...
			if (selectedNumber != 0) {
				// Check if the user input is anything but the #
				if (selectedNumber != 35) {
					curVar = selectedNumber;
				}
				// Output based on if the Decode is On or Off
				if (decodeOn == 1) {
					decodeOnOutput(curVar); // Output the decoded input
				} else { 
					decodeOffOutput(curVar); // Output the non-decoded input
				}
				timerToBlink = 0; // Reset the variable that counts for the 2 on + 1/2 off
			} // Input has been Read Loop

			// If the User presses the *, output 40 and look for user input
			if (selectedNumber == 42) {
				printf("reset!\n");
				decodeOn = 0;
				curVar = 40;
			}

			// If the User presses the #, switch whether or not the decode is on
			if (selectedNumber == 35) {
				if (decodeOn == 1) {
					decodeOn = 0;
					printf("decode on!\n");
				} else {
					decodeOn = 1;
					printf("decode off!\n");
				}
				debounce(); // Debounce so it doesnt read this input more than once
			} 
			
			// 2 on 1/2 off
			if ((timerToBlink >= 400000000) && (lastBlinked40 == 0)) {
				// Ouput 40/@ based on the decode status
				if (decodeOn == 1) {
					decodeOnOutput(40);
				} else { 
					decodeOffOutput(40);
				}
				timerToBlink = 0; // reset the timer for blinking			
				lastBlinked40 = 1; // switch the blink case
				printf("%d\n", 40); // Used to test what is being received	
			} else if ((timerToBlink >= 100000000) && (lastBlinked40 == 1)) {
				// Ouput the keypad choice based on the decode status
				if (decodeOn == 1) {
					decodeOnOutput(curVar);
				} else { 
					decodeOffOutput(curVar);
				}
				lastBlinked40 = 0; // reset the timer for blinking
				timerToBlink = 0; // switch the blink case			
				printf("%d\n", curVar); // Used to test what is being received
			}	
			
		} else if ((iterationsFor1kHz == 130000) && (isOn == 1)) {
		
			bcm2835_gpio_write(9, 0); 	// Falling Edge for the clock
			iterationsFor1kHz = 0;		// Reset the lcock timer
			isOn = 0;			// Update the switch Case
			
		} // if/else

		// Used to keep time for the clock and blinking function
		iterationsFor1kHz = iterationsFor1kHz + 1;
		timerToBlink = timerToBlink + 1;

	} // while
				
	return 0; // Never Reached
	
} // Main
