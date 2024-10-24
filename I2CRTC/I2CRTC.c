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
	
int binaryStringSeconds(int inputDiv) {
	
	int result;
	int dividend;
	int divisor;
	char binaryString[8];

	dividend = inputDiv;
	divisor = 2;
	
	for(int i = 0; i < 8; i++) {
			
		result = dividend % divisor;
		printf("%i", result);
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
	
int binaryStringMinutes(int inputDiv) {
	
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
		
	return total;

} // Binary String Minutes
	
int binaryStringHours(int inputDiv) {
	
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
	
	return total;

} // Binary String Hours
	
int binaryStringDays(int inputDiv) {
	
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
	
int binaryStringDate(int inputDiv) {
	
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
	
	return total;

} // Binary String Date

int binaryStringMonth(int inputDiv) {
	
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

int binaryStringYear(int inputDiv) {
	
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

int translateSeconds(int secVar) {
	
	int returnedVar;
	returnedVar = 0x00;
	
	if (secVar >= 40) {
		secVar -= 40;
		returnedVar += 0x40;//0100
	}
	if (secVar >= 20) {
		secVar -= 20;
		returnedVar += 0x20;//0010
	}
	if (secVar >= 10) {
		secVar -= 10;
		returnedVar += 0x10;//0001 0000
	}
	if (secVar >= 8) {
		secVar -= 8;
		returnedVar += 0x08;//0000 1000
	}
	if (secVar >= 4) {
		secVar -= 4;
		returnedVar += 0x04;
	}
	if (secVar >= 2) {
		secVar -= 2;
		returnedVar += 0x02;
		printf("2: %i\n", returnedVar);
	}
	if (secVar >= 1) {
		secVar -= 1;
		returnedVar += 0x01;
		printf("1: %i\n", returnedVar);
	}
	
	return returnedVar;
}

int translateMinutes(int minVar) {
	
	int returnedVar;
	returnedVar = 0x00;
	
	if (minVar >= 40) {
		minVar -= 40;
		returnedVar += 0x40;//0100
	}
	if (minVar >= 20) {
		minVar -= 20;
		returnedVar += 0x20;//0010
	}
	if (minVar >= 10) {
		minVar -= 10;
		returnedVar += 0x10;//0001 0000
	}
	if (minVar >= 8) {
		minVar -= 8;
		returnedVar += 0x08;//0000 1000
	}
	if (minVar >= 4) {
		minVar -= 4;
		returnedVar += 0x04;
	}
	if (minVar >= 2) {
		minVar -= 2;
		returnedVar += 0x02;
	}
	if (minVar >= 1) {
		minVar -= 1;
		returnedVar += 0x01;
	}
	
	return returnedVar;
}

int translateHours(int hourVar) {
	
	int returnedVar;
	returnedVar = 0x40; // set bit 5
	
	if (hourVar >= 10) {
		hourVar = hourVar - 10;
		returnedVar += 0x10;
	}
	if (hourVar >= 8) {
		hourVar -= 8;
		returnedVar += 0x08;
	}
	if (hourVar >= 4) {
		hourVar -= 4;
		returnedVar += 0x04;
	}
	if (hourVar >= 2) {
		hourVar -= 2;
		returnedVar += 0x02;
	}	
	if (hourVar >= 1) {
		hourVar -= 1;
		returnedVar += 0x01;
	}	
		
	return returnedVar;
}

int translateDate(int dateVar) {
	
	int returnedVar;
	returnedVar = 0x00;
	
	if (dateVar >= 20) {
		dateVar = dateVar - 20;
		returnedVar += 0x20;
	}
	
	if (dateVar >= 10) {
		dateVar = dateVar - 10;
		returnedVar += 0x10;
	}
	if (dateVar >= 8) {
		dateVar -= 8;
		returnedVar += 0x08;
	}
	if (dateVar >= 4) {
		dateVar -= 4;
		returnedVar += 0x04;
	}
	if (dateVar >= 2) {
		dateVar -= 2;
		returnedVar += 0x02;
	}	
	if (dateVar >= 1) {
		dateVar -= 1;
		returnedVar += 0x01;
	}	
	printf("DateVar: %i\n", returnedVar);
	
	return returnedVar;

}

int translateMonth(int monthVar) {
	
	int returnedVar;
	returnedVar = 0x00; // set bit 5
	
	if (monthVar >= 10) {
		monthVar -= 10;
		returnedVar += 0x10;
	}
	if (monthVar >= 8) {
		monthVar -= 8;
		returnedVar += 0x08;
	}
	if (monthVar >= 4) {
		monthVar -= 4;
		returnedVar += 0x04;
	}
	if (monthVar >= 2) {
		monthVar -= 2;
		returnedVar += 0x02;
	}	
	if (monthVar >= 1) {
		monthVar -= 1;
		returnedVar += 0x01;
	}	
	
	//returnedVar += 0x01;
	
	return returnedVar;
}

int translateYears(int yearVar) {
	
	int returnedVar;
	returnedVar = 0x00;

	if (yearVar >= 80) {
		yearVar -= 80;
		returnedVar += 0x80;//0100
	}	
	if (yearVar >= 40) {
		yearVar -= 40;
		returnedVar += 0x40;//0100
	}
	if (yearVar >= 20) {
		yearVar -= 20;
		returnedVar += 0x20;//0010
	}
	if (yearVar >= 10) {
		yearVar -= 10;
		returnedVar += 0x10;//0001 0000
	}
	if (yearVar >= 8) {
		yearVar -= 8;
		returnedVar += 0x08;//0000 1000
	}
	if (yearVar >= 4) {
		yearVar -= 4;
		returnedVar += 0x04;
	}
	if (yearVar >= 2) {
		yearVar -= 2;
		returnedVar += 0x02;
	}
	if (yearVar >= 1) {
		yearVar -= 1;
		returnedVar += 0x01;
	}
	
	return returnedVar;
}

void printDay(int dayVar) {
	
	if (dayVar == 1) {
		printf("SUN ");
	} else if (dayVar == 2) {
		printf("MON ");
	} else if (dayVar == 3) {
		printf("TUE ");
	} else if (dayVar == 4) {
		printf("WED ");
	} else if (dayVar == 5) {
		printf("THU ");
	} else if (dayVar == 6) {
		printf("FRI ");
	} else if (dayVar == 7) {
		printf("SAT ");
	} 
	
	return;
}

// Prints Using the Int Value Given by Int
void printMonth(int monthVar) {
	
	if (monthVar == 0) {
		printf("Jan ");
	} else if (monthVar == 1) {
		printf("Feb ");
	} else if (monthVar == 2) {
		printf("Mar ");
	} else if (monthVar == 3) {
		printf("Apr ");
	} else if (monthVar == 4) {
		printf("May ");
	} else if (monthVar == 5) {
		printf("Jun ");
	} else if (monthVar == 6) {
		printf("Jul ");
	} else if (monthVar == 7) {
		printf("Aug ");
	} else if (monthVar == 8) {
		printf("Sep ");
	} else if (monthVar == 9) {
		printf("Oct ");
	} else if (monthVar == 10) {
		printf("Nov ");
	} else if (monthVar == 11) {
		printf("Dec ");
	}
	
	return;
}

// Changes I2C Hex to Int and Prints
void printDate(int dateVar) {
	
	printf("%i ", binaryStringDate(dateVar));
	return;
	
}

void printHours(int hourVar) {

	printf("%i", binaryStringHours(hourVar));
	return;
}

void printMins(int minVar) {

	printf("%i", binaryStringMinutes(minVar));
	return;
}

void printAll(int weekday, int month, int date, int hour, int min, int sec, int year) {
	
	printDay(weekday);
	printMonth(month);
	printDate(date);
	printHours(hour);
	printf(":");
	printMins(min);
	printf(":");
	//printSec(sec);
	//printyear(year);
	printf("\n");
	
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
	int isPM;
	int sec;
	int min;
	int hour;
	int DOM; // mday
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
	
	DOM = local->tm_mday;
	printf("day of Month: %i\n", DOM);
	
	monthT = local->tm_mon;
	printf("monthT: %i\n", monthT);
	
	yearT = local->tm_year;
	//yearT += 1900;
	printf("yearT: %i\n", yearT);
	
	weekday = local->tm_wday;
	printf("weekday: %i\n", weekday);
	
	sec = translateSeconds(sec);
	min = translateMinutes(min);
	
	if (hour > 12) {
		isPM = 1;
		hour -= 12;
		printf("isPM\n");
	} else {
		isPM = 0;
		printf("isnt PM\n");
	}
	
	printf("\n");
	
	hour = translateHours(hour);
	DOM = translateDate(DOM);
	printDate(DOM);
	
	printf("before: %i\n", yearT);
	monthT = translateMonth(monthT);
	yearT = translateYears(yearT);
	printf("after: %x\n", yearT);
	
	//printAll(weekday, monthT, date, hour, min, sec, yearT);
	
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
	
	char zero[2];
	zero[0] = 0x00;
	zero[0] = 0x00;
	
	char one[2];
	one[0] = 0x00;
	one[1] = sec;

	char two[2];
	two[0] = 0x01;
	two[1] = min;
	
	char three[2];
	three[0] = 0x02; 	// hours Set 6th bit to 1; for bit 5, 0 is AM and 1 is PM
	three[1] = hour;

	char four[2];		// days
	four[0] = 0x03;
	four[1] = weekday;
	
	char five[2];
	five[0] = 0x04; 	// date
	five[1] = DOM;

	char six[2];		// month
	six[0] = 0x05;
	six[1] = monthT;
	
	char seven[2];
	seven[0] = 0x06; 	// year
	seven[1] = yearT;
	
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
	
	//bcm2835_i2c_setSlaveAddress(0x68);
	bcm2835_i2c_write(one, 2); // Write Seconds

	//bcm2835_i2c_setSlaveAddress(0x69);
	bcm2835_i2c_write(two, 2); // Write Minutes
	
	//bcm2835_i2c_setSlaveAddress(0x70);
	bcm2835_i2c_write(three, 2); // Write Hours
	
	//bcm2835_i2c_setSlaveAddress(0x71);
	bcm2835_i2c_write(four, 2); // Write Days

	//bcm2835_i2c_setSlaveAddress(0x72);
	bcm2835_i2c_write(five, 2); // Write Date
	
	//bcm2835_i2c_setSlaveAddress(0x73);
	bcm2835_i2c_write(six, 2); // Write Months
	
	//bcm2835_i2c_setSlaveAddress(0x74);
	bcm2835_i2c_write(seven, 2); // Write Years

	printf("Original Value = %x\n", one[0]); // address	
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
		printf("%i ", two[0]);	
		binaryStringMinutes(two[0]);
		
		bcm2835_i2c_read_register_rs(hours, three, 1);
		printf("%i ", three[0]); // address
		binaryStringHours(three[0]);
		
		bcm2835_i2c_read_register_rs(days, four, 1);
		printf("%i ", four[0]);
		binaryStringDays(four[0]);	
		
		bcm2835_i2c_read_register_rs(date, five, 1);
		printf("%i ", five[0]); // address
		binaryStringDate(five[0]);
		
		bcm2835_i2c_read_register_rs(month, six, 1);
		printf("%i ", six[0]);
		binaryStringMonth(six[0]);
		
		bcm2835_i2c_read_register_rs(year, seven, 1);
		printf("%i ", seven[0]); // address	
		binaryStringYear(seven[0]);
		printf("\n");
		printAll(four[0], six[0], five[0], three[0], two[0], one[0], seven[0]);
		
		delay(1000);
	}
	
	
	
	bcm2835_i2c_end();  
	bcm2835_close();

	return 1;
	
}
