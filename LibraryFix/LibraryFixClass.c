// First Compile using: 
// gcc -o LibraryFixClass LibraryFixClass.c -l E4235
// Allow the Seg Fault

// Then Compile Using:
// gcc -o LibraryFixClass LibraryFixClass.c E4235_Read.s E4235_Write.s E4235_Delaynano.s -l E4235

#include <stdio.h>
#include <bcm2835.h>
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
