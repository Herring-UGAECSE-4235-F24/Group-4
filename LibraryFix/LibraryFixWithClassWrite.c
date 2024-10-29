
// LibraryFixWithClassWrite
// 	The purpose of this file is to prove that the Class Library Function, E4235_Write(), DOES NOT work in its current state.
//	This is to be used with the keypad. The code verifies that X1 through X4 can correctly output with this one trick when compiling.
//
// In order to use this the class library functions:
// 1.) Plug GPIOS 20-23 into X1-X4 and GPIOS 24-27 into Y1-Y4 respectively.
// 2.) Place E4235_Read.s and E4235_Delaynano.s into the folder in which the file you want to use is in.
// 3.) Extern in the function outside of the main function:
// -> Both of the below statements must be included, or else the program cant 'see' the functions (already done for this file).
// 
// 	e.x. 
// 		extern int E4235_Read(int);
//		extern int E4235_Write(int, int);
//		extern void E4235_Delaynano(int);
//
// First Compile using: gcc -o LibraryFixWithClassWrite LibraryFixWithClassWrite.c -l E4235
// -> Allow the Seg Fault
// 
// Then Compile Using: gcc -o LibraryFixWithClassWrite LibraryFixWithClassWrite.c E4235_Read.s E4235_Write.s E4235_Delaynano.s -l E4235
// -> The function will correctly output highs to all channels, but will not output lows ever. 

#include <stdio.h>
#include "E4235.h"

extern int E4235_Read(int);
extern int E4235_Write(int, int);
extern void E4235_Delaynano(int);

int main(int argc, char **argv) {
	
	// pin20, pin21, pin22, pin23 -> X1-X4
	// pin24, pin25, pin26, pin27 -> Y1-Y4
	
	int pin20, pin21, pin22, pin23, pin24, pin25, pin26, pin27 = 0;
	
	while(1) {
		
		E4235_Write(20, 1);
		
		if (E4235_Read(24) != 0) {
			pin24 = E4235_Read(24);
		}
		if (E4235_Read(25) != 0) {
			pin25 = E4235_Read(25);
		}
		if (E4235_Read(26) != 0) {
			pin26 = E4235_Read(26);
		}
		if (E4235_Read(27) != 0) {
			pin27 = E4235_Read(27);
		}
		E4235_Write(20, 0);
		E4235_Delaynano(500000);
		E4235_Write(21, 1);
		
		if (E4235_Read(24) != 0) {
			pin24 = E4235_Read(24);
		}
		if (E4235_Read(25) != 0) {
			pin25 = E4235_Read(25);
		}
		if (E4235_Read(26) != 0) {
			pin26 = E4235_Read(26);
		}
		if (E4235_Read(27) != 0) {
			pin27 = E4235_Read(27);
		}
		
		E4235_Write(21, 0);
		E4235_Delaynano(500000);
		E4235_Write(22, 1);
		
		if (E4235_Read(24) != 0) {
			pin24 = E4235_Read(24);
		}
		if (E4235_Read(25) != 0) {
			pin25 = E4235_Read(25);
		}
		if (E4235_Read(26) != 0) {
			pin26 = E4235_Read(26);
		}
		if (E4235_Read(27) != 0) {
			pin27 = E4235_Read(27);
		}
		E4235_Write(22, 0);
		E4235_Delaynano(500000);
		E4235_Write(23, 1);
		
		if (E4235_Read(24) != 0) {
			pin24 = E4235_Read(24);
		}
		if (E4235_Read(25) != 0) {
			pin25 = E4235_Read(25);
		}
		if (E4235_Read(26) != 0) {
			pin26 = E4235_Read(26);
		}
		if (E4235_Read(27) != 0) {
			pin27 = E4235_Read(27);
		}
		E4235_Write(23, 0);
		
		printf("24: %d %d %d %d\n", pin24, pin25, pin26, pin27);
	
		pin24 = 0;
		pin25 = 0;
		pin26 = 0;
		pin27 = 0;
		
		}	
		
	return 0;
}
