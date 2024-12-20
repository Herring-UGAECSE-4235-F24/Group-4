// State_Machine_BCM
// 	The point of this program is to prove that the State Machine works BEFORE we change the read function 
//	from the one in the BCM Library to the function in the Class Library.
//
// In order to use this with the BCM library functions:
// 1.) Plug GPIOS 20-23 into X1-X4 and GPIOS 24-27 into Y1-Y4 respectively.
// 2.) Be sure to have the BCM library downloaded.
//
// Expected Output: 40 will be displayed on screen until a number on the keypad is pressed.
//		
// To Compile: 	gcc -o State_Machine_BCM State_Machine_BCM.c E4235_Read.s E4235_Write.s E4235_Delaynano.s -l bcm2835
// To Run: 	./State_Machine_BCM

#include "stdio.h"
#include "gpiotopin.h"
#include <bcm2835.h>

// 1000 delay is 1 kHz
int decodeOnOutput(int selectedNumber){
		
	if (selectedNumber == 48) { // Should output 30 
		bcm2835_gpio_write(10, 0); // msb
		bcm2835_gpio_write(11, 1); //
		bcm2835_gpio_write(12, 1); //
		bcm2835_gpio_write(13, 0); 		//
		bcm2835_gpio_write(16, 0); 		//
		bcm2835_gpio_write(17, 0); 		//
		bcm2835_gpio_write(18, 0); 		// lsb

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
} // Write Binary to LA

int decodeOffOutput(int selectedNumber){
		
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

void debounce() {
	
	int x = 40000000;
	
	while (x != 0) {
		x = x -1;
	} // while
	
	return;
	
} // debounce

int clockLoop() {
	
	int selectedNumber = 0;
	
	selectedNumber = lookForInput();
	printf("%d\n", selectedNumber); // Used to test what is being received
	decodeOffOutput(selectedNumber);
	//decodeOnOutput(selectedNumber);

	return 1;
	
}

// Main Loop
int main(int argc, char **argv) {

	int isOn = 0;
	int iterationsFor1kHz = 0;
	int selectedNumber = 0;
	int decodeOn = 0;
	int curVar = 40;
	int timerToBlink = 0;
	int lastBlinked40 = 0;		
	
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
	
	decodeOffOutput(40);
	
	while(1) {
		

		if ((iterationsFor1kHz == 130000) && (isOn == 0)) {
			
			bcm2835_gpio_write(9, 1);
			iterationsFor1kHz = 0;
			isOn = 1;
	
			selectedNumber = lookForInput();
			
			// poll for user input
			if (selectedNumber != 0) {
				if (selectedNumber != 35) {
					curVar = selectedNumber;
				}
				if (decodeOn == 1) {
					decodeOnOutput(curVar);
				} else { 
					decodeOffOutput(curVar);
				}
				timerToBlink = 0;	
			} // Input has been Read Loop
			
			if (selectedNumber == 42) {
				printf("reset!\n");
				decodeOn = 0;
				curVar = 40;
			}
			
			if (selectedNumber == 35) {
				if (decodeOn == 1) {
					decodeOn = 0;
					printf("decode on!\n");
				} else {
					decodeOn = 1;
					printf("decode off!\n");
				}
				debounce();
			} 
			
			// 2 on 1/2 off
			if ((timerToBlink >= 400000000) && (lastBlinked40 == 0)) {
				if (decodeOn == 1) {
					decodeOnOutput(40);
				} else { 
					decodeOffOutput(40);
				}
				timerToBlink = 0;			
				lastBlinked40 = 1;
				printf("%d\n", 40); // Used to test what is being received	
			} else if ((timerToBlink >= 100000000) && (lastBlinked40 == 1)) {
				if (decodeOn == 1) {
					decodeOnOutput(curVar);
				} else { 
					decodeOffOutput(curVar);
				}
				lastBlinked40 = 0;
				timerToBlink = 0;			
				printf("%d\n", curVar); 
			}	
			
		} else if ((iterationsFor1kHz == 130000) && (isOn == 1)) {
		
			bcm2835_gpio_write(9, 0);
			iterationsFor1kHz = 0;
			isOn = 0;
			
		} // if/else
		
		iterationsFor1kHz = iterationsFor1kHz + 1;
		timerToBlink = timerToBlink + 1;

	} // while
				
	return 0;
	
} // Main
