# include <stdio.h>
# include <bcm2835.h>
# include <sys/time.h>

# define MODE_READ 1

void initialize() {
	
	if (!bcm2835_init()) {
      printf("bcm2835_init failed. Are you running as root??\n");
      return;
    }
      
    // I2C begin if specified   
    if (!bcm2835_i2c_begin()) {
        printf("bcm2835_i2c_begin failed. Are you running as root??\n");
		return;
    }
	

	//bcm2835_i2c_setClockDivider(32000);
	bcm2835_i2c_set_baudrate(100000);
	
	return;
}

void realTime() {
	
	time_t * curTime;
	
	
		
	printf("%s", gettimeofday(&curTime, NULL));
}
	
int main(int argc, char **argv) {
	
	//open '/dev/i2c-0' to access i2c data
	// we can read the buffer to get the data we need
	// then print that specific data
	//begin
	
	initialize();
	realTime();

	char zeroBuf[8];
	char oneBuf[8];
	char testBuf[8];
	
	char one[1];
	one[0] = 1;
	
	char zero[1];
	zero[0] = 0;

	for (int i = 0; i < 8; i++) {
		zeroBuf[i] = 0;
	}
	for (int i = 0; i < 8; i++) {
		oneBuf[i] = 1;
	}
	//0x68? -> 01101000 -> 1101000X -> (C1) (C0)
	bcm2835_i2c_setSlaveAddress(0x68);
	bcm2835_i2c_write(zero, 1); // Write 0 to start writing process to i2c, second arg now works with a char array
	
	for (int i = 0; i < 1; i++) {
		testBuf[i] = 1;
	}
	bcm2835_i2c_write(testBuf, 1); // Write 0 to start writing process to i2c, for some reason, second arg has to be 0?
	bcm2835_i2c_setSlaveAddress(0x68);
	bcm2835_i2c_write(one, 1); // Write 0 to start writing process to i2c, second arg now works with a char array
	
	// seg faulting here
	bcm2835_i2c_read(testBuf, 1);
    printf("Read Result = %d\n", testBuf); 
    
	bcm2835_i2c_end();  
	bcm2835_close();

	return 1;
	
}
