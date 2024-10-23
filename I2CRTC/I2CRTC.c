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
	seconds[0] = 0x00; 	// Address of seconds
	char minutes[1];
	minutes[0] = 0x01; 	// Address of Minutes
	char hours[1];
	hours[0] = 0x02;	// Address of Hours
	char days[1];
	days[0] = 0x03;		// Address of Days
	char date[1];
	date[0] = 0x04;		// Address of Date
	char month[1];
	month[0] = 0x05;	// Address of Months
	char year[1];
	year[0] = 0x06;		// Address of Years
	
	char zero[1];
	zero[0] = 0x00;
	
	char one[1];
	one[0] = 0x11; // Seconds

	char two[1];
	two[0] = 0x01;
	
	char binaryString[8];

	for (int i = 0; i < 8; i++) {
		zeroBuf[i] = 0;
		binaryString[i] = 0;
	}
	for (int i = 0; i < 8; i++) {
		oneBuf[i] = 1;
	}
	for (int i = 0; i < 1; i++) {
		testBuf[i] = 1;
	}
	
	bcm2835_i2c_setSlaveAddress(0x68);
	bcm2835_i2c_write(zero, 1); // Write 0 to start writing process to i2c, second arg now works with a char array
	
	bcm2835_i2c_setSlaveAddress(0x68);
	bcm2835_i2c_write(one, 1); // Write 0 to start writing process to i2c, second arg now works with a char array
	
	// if the time is 
	bcm2835_i2c_setSlaveAddress(0x69);
	bcm2835_i2c_write(two, 1); // Write 0h
	//bcm2835_i2c_write(, 1); // Write 0h

	printf("Read Result = %i\n", one[0]); // address	
	printf("Read Result = %i\n", two[0]); // address

	while (1) {
	// seg faulting here
		bcm2835_i2c_setSlaveAddress(0x68);
		bcm2835_i2c_read_register_rs(seconds, one, 1);
		printf("%i   ", one[0]); // address
		bcm2835_i2c_read_register_rs(minutes, two, 1);
		printf("%i\n", two[0]);	
		delay(1000);
	}
	
	bcm2835_i2c_end();  
	bcm2835_close();

	return 1;
	
}
