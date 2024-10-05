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

//extern int E4235_Read(int); // GPIO
//extern int E4235_Write(int, int); // GPIO,value (on/off)
//extern void E4235_Delaynano(int); // time

// dec to char: 
// 49 -> 1, 50 -> 2, 51 -> 3, 65 -> 4
// 42 -> *, 48 -> 0, 35 -> #, 68 -> D


int readKeyPad(GPIONumber){
	
	int rowPushed = 0;
		
	E4235_Write(GPIONumber, 1);
	
	if (E4235_Read(GPIO24) == 1){
		rowPushed = 1;
		printf("1st row\n");
	}
	if (E4235_Read(GPIO25) == 1){
		rowPushed = 2;
		printf("2nd row\n");
	}
	if (E4235_Read(GPIO26) == 1){
		rowPushed = 3;
		printf("3rd row\n");
	}
	if (E4235_Read(GPIO27) == 1){
		rowPushed = 4;
		printf("4th row\n");
	}
	
	E4235_Write(GPIONumber, 0); // may need to move this down to translateNumber() as the last line
	
	return rowPushed;
	
} // readKeyPad

int translateNumber(GPIONumber, selectedNumber) {
	
	if (GPIONumber == 20) {
		if (selectedNumber == 1) {
			printf("1 dumbo\n");
			return '1';
		} else if (selectedNumber == 2) {
			printf("2 dumbo\n");
			return '2';
		} else if (selectedNumber == 3) {
			printf("3 dumbo\n");
			return '3';
		} else if (selectedNumber == 4) {
			printf("4 dumbo\n");
			return 'A';
		}
	 } 
	 
	 if (GPIONumber == 21) {
		if (selectedNumber == 1) {
			printf("4 dumbo\n");
			return '4';
		} else if (selectedNumber == 2) {
			printf("5 dumbo\n");
			return '5';
		} else if (selectedNumber == 3) {
			printf("6 dumbo\n");
			return '6';
		} else if (selectedNumber == 4) {
			printf("B dumbo\n");
			return 'B';
		}
	 }
	
	if (GPIONumber == 22) {
		if (selectedNumber == 1) {
			printf("7 dumbo\n");
			return '7';
		} else if (selectedNumber == 2) {
			printf("8 dumbo\n");
			return '8';
		} else if (selectedNumber == 3) {
			printf("9 dumbo\n");
			return '9';
		} else if (selectedNumber == 4) {
			printf("C dumbo\n");
			return 'C';
		}
	 }
	 
	 if (GPIONumber == 23) {
		if (selectedNumber == 1) {
			printf("* dumbo\n");
			return '*';
		} else if (selectedNumber == 2) {
			printf("0 dumbo\n");
			return '0';
		} else if (selectedNumber == 3) {
			printf("# dumbo\n");
			return '#';
		} else if (selectedNumber == 4) {
			printf("D dumbo\n");
			return 'D';
		}
	 }
	//E4235_Write(GPIONumber, 0);
	return 'L';
}

int lookForInput(){
	
	int stop = 0;
	int yes = 0;
		
	stop = readKeyPad(20); // may need to move E4235_Write(GPIONumber, 0); to right after this line
	if (stop != 0) {
		return translateNumber(20, stop); // this may be returning a character instead of an int
	}
	stop = readKeyPad(21);
	if (stop != 0) {
		yes = translateNumber(21, stop);
		printf("GPIO21:\n", yes);
		return yes;
	}
	stop = readKeyPad(22);
	if (stop != 0) {
		return translateNumber(22, stop);
	}
	stop = readKeyPad(23);
	if (stop != 0) {
		yes = translateNumber(23, stop);
		printf("23!!!\n", yes);
		return yes;
	}
				
	return stop;
			
} // Looking For Input


int main(int argc, char **argv) {
	
	char selectedNumber = 0; // original was int
	
	while (1) {
		
		selectedNumber = 0; 
		
		while (selectedNumber == 0) {
			selectedNumber = lookForInput(); 
		}
		
		if (selectedNumber != 0) {
			
			printf("Output: %c\n", selectedNumber); //original was decimal
		}
	}
				
	return 0;
} // Main
