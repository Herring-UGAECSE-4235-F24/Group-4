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
	
	char one[2];
	one[0] = 0x00; // Seconds
	one[1] = 0x7F; // Data in seconds
	
	char zero[2];
	zero[0] = 0x68;
	zero[1] = 0x00;
	
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
	//bcm2835_i2c_write(zero, 2); // Write 0 to start writing process to i2c, second arg now works with a char array
	
	// if the time is 
	
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
	
	int result;
	int dividend;
	int divisor;
	int increment;
	increment = 0;
	dividend = one[0];
	divisor = 2;
	
	for(int i = 0; i < 8; i++) {
		
		result = dividend % divisor;
		binaryString[i] = result;
		dividend = dividend / divisor;
	}
	
	printf("The Binary String is: ");
	
	for(int i = 0; i < 8; i++) {
		
		printf("%i", binaryString[i]);
		
	}
	
	printf("\n");
	
	//printf("%i", translateSeconds(binaryString[]));
	
	
	// Convert Seconds to Real
	int total;
	total = 0;
	
	if (binaryString[0] == 1) {
		total += 1;
	}
	if (binaryString[1] == 1) {
		total += 2;
	}
	if (binaryString[2] == 1) {
		total += 4;
	} 
	if (binaryString[3] == 1) {
		total += 8;
	}
	if (binaryString[4] == 1) {
		total += 10;
	}
	if (binaryString[5] == 1) {
		total += 20;
	}
	if (binaryString[6] == 1) {
		total += 40;
	}
	
	printf("%i", total);
	
	bcm2835_i2c_end();  
	bcm2835_close();

	return 1;
	
}
