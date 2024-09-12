//#include <E4235.h>
#include <stdio.h>

extern void E4235_Write(int, int);
extern void E4235_Delaynano(int);

int main(int argc, char **argv)
{
	// 60 Hz is 7,450,000
	int delayTime;
	delayTime = 1;
	
	while(1) {
		
		E4235_Write(12, 1);
		E4235_Delaynano(delayTime);
		E4235_Write(12, 0);
		E4235_Delaynano(delayTime);
		
	}
}
