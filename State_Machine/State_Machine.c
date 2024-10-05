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

int readKeyPad(gpioNumber){
	
	int rowPushed = 0;
		
	E4235_Write(gpioNumber, 1);
	
	if (E4235_Read(GPIO24) == 1){
		rowPushed = 1;
	}
	if (E4235_Read(GPIO25) == 1){
		rowPushed = 2;
	}
	if (E4235_Read(GPIO26) == 1){
		rowPushed = 3;
	}
	if (E4235_Read(GPIO27) == 1){
		rowPushed = 4;
	}
	
	E4235_Write(gpioNumber, 0);
	
	return rowPushed;
	
} // readKeyPad

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
	
	return 'L';
}

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
	int selectedNumber;
	int returnedChar;

	char rowOne [3];
	rowOne [0] = '1';
	rowOne [1] = '2';
	rowOne [2] = '3';
	rowOne [3] = 'A';
	
	while(stop != 0) {
		
		selectedNumber = 0;
		returnedChar = '0';
		
		selectedNumber = readKeyPad(GPIO20, rowOne);
		if (selectedNumber != 0) {
			returnedChar = translateNumber(GPIO20, selectedNumber);
		}
		
		printf("24: %c\n", returnedChar);
		
	}
				
	return 0;
} // Main
