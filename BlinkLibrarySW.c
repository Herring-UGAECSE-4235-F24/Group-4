#include <E4235.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	//int test[0];
	//test[0] = 12;
	int test = 12;
	int *ptr = (int*)test;
	
	while (1) {
		printf("Iterate\n");
		E4235_multiwrite(ptr, 1, 1);
		//4235_Write(12, 1);
		E4235_delayNano(100);
		//printf("go dawgs!\n");
		//E4235_multiwrite(test[0], 1, 0);
		E4235_Write(12, 0);
		//E4235_delayNano(100);
		//printf("sic' em\n");
		//return 0;
	}
}
