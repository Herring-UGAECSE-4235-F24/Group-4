# include <stdio.h>
# include <bcm2835.h>
# include <sys/time.h>
# include <time.h>

# define MODE_READ 1

// To Compile: gcc -o I2CRTC I2CRTC.c -l bcm2835
// To Run: sudo ./I2CRTC

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
	
int binaryStringSeconds(inputDiv) {
	
	int result;
	int dividend;
	int divisor;
	char binaryString[8];

	dividend = inputDiv;
	divisor = 2;
	
	for(int i = 0; i < 8; i++) {
			
		result = dividend % divisor;
		binaryString[i] = result;
		dividend = dividend / divisor;
	} // for
	
	printf("The Seconds Value is: ");
				
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
		
	printf("%i\n", total);
	
	return total;

} // Binary String Seconds
	
int binaryStringMinutes(inputDiv) {
	
	int result;
	int dividend;
	int divisor;
	char binaryString[8];

	dividend = inputDiv;
	divisor = 2;
	
	for(int i = 0; i < 8; i++) {
			
		result = dividend % divisor;
		binaryString[i] = result;
		dividend = dividend / divisor;
	} // for
	
	printf("The Minutes Value is: ");
				
	// Convert Minutes to Real
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
		
	printf("%i\n", total);
	
	return total;

} // Binary String Minutes
	
int binaryStringHours(inputDiv) {
	
	int result;
	int dividend;
	int divisor;
	char binaryString[8];

	dividend = inputDiv;
	divisor = 2;
	
	for(int i = 0; i < 8; i++) {
			
		result = dividend % divisor;
		binaryString[i] = result;
		dividend = dividend / divisor;
	} // for
	
	printf("The Hours Value is: ");
				
	// Convert Hours to Real
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
		total += 12;
	}
	//bit 6 is always going to be set to 1 in write to indicate 12-hour clock
		
	printf("%i\n", total);
	
	return total;

} // Binary String Hours
	
int binaryStringDays(inputDiv) {
	
	int result;
	int dividend;
	int divisor;
	char binaryString[8];

	dividend = inputDiv;
	divisor = 2;
	
	for(int i = 0; i < 8; i++) {
			
		result = dividend % divisor;
		binaryString[i] = result;
		dividend = dividend / divisor;
	} // for
	
	printf("The Days Value is: ");
				
	// Convert Days to Real
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
		
	printf("%i\n", total);
	
	return total;

} // Binary String Days
	
int binaryStringDate(inputDiv) {
	
	int result;
	int dividend;
	int divisor;
	char binaryString[8];

	dividend = inputDiv;
	divisor = 2;
	
	for(int i = 0; i < 8; i++) {
			
		result = dividend % divisor;
		binaryString[i] = result;
		dividend = dividend / divisor;
	} // for
	
	printf("The Date Value is: ");
				
	// Convert Date to Real
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
		
	printf("%i\n", total);
	
	return total;

} // Binary String Date

int binaryStringMonth(inputDiv) {
	
	int result;
	int dividend;
	int divisor;
	char binaryString[8];

	dividend = inputDiv;
	divisor = 2;
	
	for(int i = 0; i < 8; i++) {
			
		result = dividend % divisor;
		binaryString[i] = result;
		dividend = dividend / divisor;
	} // for
	
	printf("The Month Value is: ");
				
	// Convert Month to Real
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
		
	printf("%i\n", total);
	
	return total;

} // Binary String Month

int binaryStringYear(inputDiv) {
	
	int result;
	int dividend;
	int divisor;
	char binaryString[8];

	dividend = inputDiv;
	divisor = 2;
	
	for(int i = 0; i < 8; i++) {
			
		result = dividend % divisor;
		binaryString[i] = result;
		dividend = dividend / divisor;
	} // for
	
	printf("The Year Value is: ");
				
	// Convert Year to Real
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
	if (binaryString[7] == 1) {
		total += 80;
	}
		
	printf("%i\n", total);
	
	return total;

} // Binary String Year

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
	int sec;
	int min;
	int hour;
	int dayOfMonth; // mday
	int monthT; //month
	int yearT; // years since 1900
	int weekday; // mon, tues, etc
	
	struct tm * local;
	time_t t = time(NULL);
	
	local = localtime(&t);
	
	printf("Local time and date: %s\n", asctime(local));
	
	sec = local->tm_sec;
	printf("Seconds: %i\n", sec);
	
	min = local->tm_min;
	printf("Minutes: %i\n", min);
	
	hour = local->tm_hour;
	printf("Hours: %i\n", hour);
	
	dayOfMonth = local->tm_mday;
	printf("day of Month: %i\n", dayOfMonth);
	
	monthT = local->tm_mon;
	printf("monthT: %i\n", monthT);
	
	yearT = local->tm_year;
	//yearT += 1900;
	printf("yearT: %i\n", yearT);
	
	weekday = local->tm_wday;
	printf("weekday: %i\n", weekday);
	
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
	one[0] = 0x60; // Seconds

	char two[1];
	two[0] = 0x02;
	
	char three[1];
	three[0] = 0x03; // Set 6th bit to 1; for bit 5, 0 is AM and 1 is PM

	char four[1];
	four[0] = 0x7F;
	
	char five[1];
	five[0] = 0x7F; // Seconds

	char six[1];
	six[0] = 0x7F;
	
	char seven[1];
	seven[0] = 0x7F; // Seconds
	
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
	bcm2835_i2c_write(zero, 1); // Write Zeroes
	
	bcm2835_i2c_setSlaveAddress(0x68);
	bcm2835_i2c_write(one, 1); // Write Seconds

	bcm2835_i2c_setSlaveAddress(0x69);
	bcm2835_i2c_write(two, 1); // Write Minutes
	
	bcm2835_i2c_setSlaveAddress(0x70);
	bcm2835_i2c_write(three, 1); // Write Hours
	
	bcm2835_i2c_setSlaveAddress(0x71);
	bcm2835_i2c_write(four, 1); // Write Days

	bcm2835_i2c_setSlaveAddress(0x72);
	bcm2835_i2c_write(five, 1); // Write Date
	
	bcm2835_i2c_setSlaveAddress(0x73);
	bcm2835_i2c_write(six, 1); // Write Months
	
	bcm2835_i2c_setSlaveAddress(0x74);
	bcm2835_i2c_write(seven, 1); // Write Years

	printf("Original Value = %i\n", one[0]); // address	
	printf("Original Value = %i\n", two[0]); // address	
	printf("Original Value = %i\n", three[0]); // address	
	printf("Original Value = %i\n", four[0]); // address	
	printf("Original Value = %i\n", five[0]); // address	
	printf("Original Value = %i\n", six[0]); // address	
	printf("Original Value = %i\n", seven[0]); // address	
	

	while (1) {
	// seg faulting here
		bcm2835_i2c_setSlaveAddress(0x68);
		bcm2835_i2c_read_register_rs(seconds, one, 1);
		printf("%i ", one[0]); // address
		binaryStringSeconds(one[0]);
		
		bcm2835_i2c_read_register_rs(minutes, two, 1);
		printf("%i  ", two[0]);	
		binaryStringMinutes(two[0]);
		
		bcm2835_i2c_read_register_rs(hours, three, 1);
		printf("%i ", three[0]); // address
		binaryStringHours(three[0]);
		
		bcm2835_i2c_read_register_rs(days, four, 1);
		printf("%i  ", four[0]);
		binaryStringDays(four[0]);	
		
		bcm2835_i2c_read_register_rs(date, five, 1);
		printf("%i  ", five[0]); // address
		binaryStringDate(five[0]);
		
		bcm2835_i2c_read_register_rs(month, six, 1);
		printf("%i  ", six[0]);
		binaryStringMonth(six[0]);
		
		bcm2835_i2c_read_register_rs(year, seven, 1);
		printf("%i  ", seven[0]); // address	
		binaryStringYear(seven[0]);
		printf("\n");
		
		delay(1000);
	}
	
	
	
	bcm2835_i2c_end();  
	bcm2835_close();

	return 1;
	
}
