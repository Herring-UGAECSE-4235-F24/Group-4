# include <stdio.h>
# include <bcm2835.h>
# include <sys/time.h>

# define MODE_READ 1

void initialize() {
	
	uint16_t clk_div = BCM2835_I2C_CLOCK_DIVIDER_148;
	
	if (!bcm2835_init()) {
      printf("bcm2835_init failed. Are you running as root??\n");
      return;
    }
      
    // I2C begin if specified   
    if (!bcm2835_i2c_begin()) {
        printf("bcm2835_i2c_begin failed. Are you running as root??\n");
		return;
    }
	
	bcm2835_i2c_setClockDivider(clk_div);
	bcm2835_i2c_set_baudrate(100000);
	
	return;
}
	
int main(int argc, char **argv) {
	
	//open '/dev/i2c-0' to access i2c data
	// we can read the buffer to get the data we need
	// then print that specific data
	//begin
	
	initialize();
	//realTime();

	char zeroBuf[8];
	char oneBuf[8];
	char testBuf[8];
	char seconds[1];
	char minutes[1];
	
	char one[2];
	one[0] = 0x00; // Seconds
	one[1] = 0x7F; // Data in seconds
	
	char zero[2];
	zero[0] = 0x68;
	zero[1] = 0x00;
	
	seconds[0] = 0x00;
	minutes[0] = 0x01;

	for (int i = 0; i < 8; i++) {
		zeroBuf[i] = 0;
	}
	for (int i = 0; i < 8; i++) {
		oneBuf[i] = 1;
	}
	for (int i = 0; i < 1; i++) {
		testBuf[i] = 1;
	}
	
	bcm2835_i2c_setSlaveAddress(0x68);
	//bcm2835_i2c_write(zero, 2); // Write 0 to start writing process to i2c, second arg now works with a char array
	
	bcm2835_i2c_write(one, 2); // Write 0h

	// seg faulting here
	bcm2835_i2c_setSlaveAddress(0x68);
	one[0] = 0x00;
	one[1] = 0x00;
	printf("Read Result = %i\n", one[0]);
	printf("Read Result = %i\n", one[1]);
	bcm2835_i2c_read(one, 1);
	printf("Read Result = %i\n", one[0]);
	printf("Read Result = %i\n", one[1]);
	//printf("Read Result = %i\n", bcm2835_i2c_read_register_rs(seconds, minutes, 1));
	//printf("Read Result = %i\n", minutes);
	
	bcm2835_i2c_end();  
	bcm2835_close();

	return 1;
	
}
