# include <stdio.h>
# include <bcm2835.h>

# define MODE_READ 1

void initialize() {
	
	printf("before seg fault");
	if (!bcm2835_init()) {
		printf("not initialized");
	}
	
	printf("before seg fault");
	if (!bcm2835_i2c_begin()) {
		printf("not begin");
	}
	
	printf("before seg fault");
	bcm2835_i2c_setSlaveAddress(0x68);
	//bcm2835_i2c_setClockDivider(32000);
	printf("before seg fault");
	bcm2835_i2c_set_baudrate(100000);
	
	return;
}


int main(int argc, char **argv) {
	
	//open '/dev/i2c-0' to access i2c data
	// we can read the buffer to get the data we need
	// then print that specific data
	//begin
	
	initialize();

	//uint8_t data;
	
	printf("before seg fault");
	bcm2835_i2c_setSlaveAddress(0x68);
	printf("before seg fault");
	//data = bcm2835_i2c_write(0x00, 1);
	
	// seg faulting here
    //data = bcm2835_i2c_read(buf, len);
    //printf("Read Result = %d\n", data);   
    
	bcm2835_i2c_end();  
	bcm2835_close();

	return 1;
	
}

