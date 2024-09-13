//#include <E4235.h>
#include <stdio.h>

extern void E4235_Write(int, int);
extern void E4235_Delaynano(int);

int main(int argc, char **argv)
{
	// 60 Hz is 7,450,000
	int delayTime;
	delayTime = 1;

	// Loop to create Square Wave
	while(1) {
		
		E4235_Write(12, 1); 		// Make GPIO High
		E4235_Delaynano(delayTime); 	// Wait
		E4235_Write(12, 0); 		// Make GPIO Low
		E4235_Delaynano(delayTime);	// Wait
		
	}
}
