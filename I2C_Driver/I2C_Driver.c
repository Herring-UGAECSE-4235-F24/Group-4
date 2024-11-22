/* I2C_Driver.c
Property of Sam Brewster and Simline Gijo

Push: Its Disgusting

For Deliverables on ELC
1) What value did you use for the pullup resistor?  What is the total pullup resistor that the RP4 driver sees? 
2) Provide a flow chart or pseudo code for your driver.  
3) Document your functions that you defined and used for your driver (including those required above).  Your document should be of the same quality/form as the library components.
4) Describe the I2C bus driver protocal and how you implemented the spec in your design paying attention to the pull-up nature of the bus and how you used the available operations available for GPIOs in the RP4.
5) What was the most challenging aspect of this project?

https://www.ics.com/blog/how-control-gpio-hardware-c-or-c

 */

#include <stdio.h>
#include <bcm2835.h>
#include <sys/time.h>
#include <time.h>

#define SDA 23
#define SCL 24

// Allows for an easy change to all clock cycles.
// In order to use the standard I2C rate, we need 10 microseconds per on/off cycle
#define clockPeriod 10

extern void E4235_Select(int GPIO, int value);
extern int E4235_Read(int GPIO);
extern void E4235_delayMili(int time);
extern void E4235_Delaymicro(int time);

// User should be prompted to either be able to a) read the value of the rtc, b) write time to the RTC
char promptUser(){

	char * responseFormat = "%c";
	char responseList[1];

	printf("Input 'r' to read the RTC or 'w' to write to the RTC:");
	scanf(responseFormat, responseList);
	return responseList[0];

} // promptUser

int promptUserSeconds(){

	char * responseFormat = "%i";
	char responseList[1];

	printf("How many Seconds?(0-59):");
	scanf(responseFormat, responseList);
	return responseList[0];

} // promptUser

int promptUserMinutes(){

	char * responseFormat = "%i";
	char responseList[1];

	printf("How many Minutes?(0-59):");
	scanf(responseFormat, responseList);
	return responseList[0];

} // promptUser

int promptUserHours(){

	char * responseFormat = "%i";
	char responseList[1];

	printf("How many Hours?(0-11):");
	scanf(responseFormat, responseList);
	return responseList[0];

} // promptUser

int promptUserDays(){

	char * responseFormat = "%i";
	char responseList[1];

	printf("What Day of the Week?(Sun[1] to Sat[7]):");
	scanf(responseFormat, responseList);
	return responseList[0];

} // promptUser

int promptUserDate(){

	char * responseFormat = "%i";
	char responseList[1];

	printf("What Day of the Month?(1-31):");
	scanf(responseFormat, responseList);
	return responseList[0];

} // promptUser

int promptUserMonth(){

	char * responseFormat = "%i";
	char responseList[1];

	printf("How many Months?(1-12):");
	scanf(responseFormat, responseList);
	return responseList[0];

} // promptUser

char translateSeconds(int secVar) {
	
	char returnedChar = 0;
	printf("\nsecVar = %i\n", secVar);
	
	
	// Bitwise
	returnedChar = (secVar % 10); // XXXX 0101
	returnedChar = returnedChar | ((secVar/10) << 4); // XXXX 0010 -> 0010 0101
	
	/*
	int returnedVar;
	returnedVar = 0x00;

	if (secVar >= 40) {
		secVar -= 40;
		returnedChar = returnedChar | 0x40; //0100
	}
	printf("Quick Check %i\n", returnedChar);
	if (secVar >= 20) {
		secVar -= 20;
		returnedChar = returnedChar | 0x20; //0010 0000
	}
	printf("Quick Check %i\n", returnedChar);
	if (secVar >= 10) {
		secVar -= 10;
		returnedChar = returnedChar | 0x10; //0001 0000
	}
	printf("Quick Check %i\n", returnedChar);
	if (secVar >= 8) {
		secVar -= 8;
		returnedChar = returnedChar | 0x08; //0000 1000
	}
	printf("Quick Check %i\n", returnedChar);
	if (secVar >= 4) {
		secVar -= 4;
		returnedChar = returnedChar | 0x04;
	}
	printf("Quick Check %i\n", returnedChar);
	if (secVar >= 2) {
		secVar -= 2;
		returnedChar = returnedChar | 0x02;
	}
	printf("Quick Check %d\n", returnedChar);
	if (secVar >= 1) {
		secVar -= 1;
		returnedChar = returnedChar | 0x01;
	}
	*/
	printf("Quick Check %d\n", returnedChar);
	
	return returnedChar;
}

char translateMinutes(int minVar) {
	
	char returnedChar;
	printf("\nminVar = %i\n", minVar);
	
	// Bitwise
	returnedChar = minVar % 10;
	returnedChar = returnedChar | (minVar/10 << 4);
	
	printf("Quick Check %d\n", returnedChar);
	
	return returnedChar;
	
}

char translateHours(int hourVar) {
	
	char returnedChar = 0x40;
	printf("\nhourVar = %i\n", hourVar);
	
	if (hourVar>=12) {
		returnedChar = returnedChar | 0x20; // set AM/PM bit
		hourVar -= 12;
	}
	
	// Bitwise
	returnedChar = returnedChar | hourVar % 10; // Fill the bottom 4 bits
	returnedChar = returnedChar | (hourVar/10 << 4); // Fill the 5th bit

	printf("Quick Check %d\n", returnedChar);
	
	return returnedChar;
}

char translateDays(int dayVar) {
	
	char returnedChar = 0x00;
	printf("\ndayVar = %i\n", dayVar);
	
	// Bitwise
	returnedChar = returnedChar | dayVar % 10; // Fill the bottom 4 bits

	printf("Quick Check %d\n", returnedChar);
	
	return returnedChar;
}

char translateDate(int dateVar) {
	
	char returnedChar = 0x00;
	printf("\ndateVar = %i\n", dateVar);
	
	// Bitwise
	returnedChar = returnedChar | dateVar % 10; // Fill the bottom 4 bits
	returnedChar = returnedChar | (dateVar/10 << 4); // Fill the 5th bit

	printf("Quick Check %d\n", returnedChar);
	
	return returnedChar;
}

char translateMonth(int monthVar) {
	
	char returnedChar = 0x00;
	printf("\nmonthVar = %i\n", monthVar);
	
	// Bitwise
	returnedChar = returnedChar | monthVar % 10; // Fill the bottom 4 bits
	returnedChar = returnedChar | (monthVar/10 << 4); // Fill the 5th bit

	printf("Quick Check %d\n", returnedChar);
	
	return returnedChar;
}

char translateYears(int yearVar) {
	
	char returnedChar = 0x00;
	printf("\nyearVar = %i\n", yearVar);
	
	// Bitwise
	returnedChar = returnedChar | yearVar % 10; // Fill the bottom 4 bits
	returnedChar = returnedChar | (yearVar/10 << 4); // Fill the 5th bit

	printf("Quick Check %d\n", returnedChar);
	
	return returnedChar;
}


// Sets the SDA pin to Read Only, making it into a low
void highSDA() {

	E4235_Select(SDA, 0);
	
} // inputSDA



// Sets the SDA pin to Write Only, making it into a high
void lowSDA() {

	E4235_Select(SDA, 1);
	
} // inputSDA



// Causes a rising Edge for the clock
void risingClock() {

	E4235_Select(SCL, 0);
	
} // inputSCL



// Causes a falling Edge for the Clock
void fallingClock() {

	E4235_Select(SCL, 1);
	
} // inputSCL

// Changes SDA from HIGH to LOW when the Clock is HIGH
// Inspiration from bitbanging.space
void startCondition(){
	
	highSDA();
	risingClock();
	E4235_Delaymicro(clockPeriod);
	lowSDA();
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	E4235_Delaymicro(clockPeriod);
	
	// Ends with the CLOCK and SDA at LOW
	
	return;
	
} // startCondition



// Changes SDA from LOW to HIGH when the Clock is HIGH
// Inspiration from bitbanging.space
void stopCondition(){
	
	lowSDA();
	E4235_Delaymicro(clockPeriod);
	risingClock();
	E4235_Delaymicro(clockPeriod);
	highSDA();
	E4235_Delaymicro(clockPeriod);
	
	return;
	
} // startCondition



// Sends a 7 bit address to the slave
void sendAddress(char * address){
	
	// If the bit is high, output a high on SDA, and vice versa
	if (address[0] == '1') {
		highSDA();
	} else {
		lowSDA();
	}
	
	risingClock(); // rising Clock edge
	E4235_Delaymicro(clockPeriod); // allow clock cycle
	
	// force everything low
	fallingClock();
	lowSDA();
	E4235_Delaymicro(clockPeriod);
	
	
	// Same Logic as above but for 2nd MSB
	if (address[1] == '1') {
		highSDA();
	} else {
		lowSDA();
	}
	
	risingClock(); // new cycle
	E4235_Delaymicro(clockPeriod); // allow clock cycle
	
	// force everything low
	fallingClock();
	lowSDA();
	E4235_Delaymicro(clockPeriod);
	
	// Same Logic as above but for 3rd MSB
	if (address[2] == '1') {
		highSDA();
	} else {
		lowSDA();
	}
	
	risingClock(); // new cycle
	E4235_Delaymicro(clockPeriod); // allow clock cycle
	
	// force everything low
	fallingClock();
	lowSDA();
	E4235_Delaymicro(clockPeriod);
		
	// Same Logic as above but for 4th MSB
	if (address[3] == '1') {
		highSDA();
	} else {
		lowSDA();
	}
	
	risingClock(); // new cycle
	E4235_Delaymicro(clockPeriod); // allow clock cycle
	
	// force everything low
	fallingClock();
	lowSDA();
	E4235_Delaymicro(clockPeriod);
		
	// Same Logic as above but for 5th MSB
	if (address[4] == '1') {
		highSDA();
	} else {
		lowSDA();
	}
	
	risingClock(); // new cycle
	E4235_Delaymicro(clockPeriod); // allow clock cycle
	
	// force everything low
	fallingClock();
	lowSDA();
	E4235_Delaymicro(clockPeriod);
		
	// Same Logic as above but for 6th MSB
	if (address[5] == '1') {
		highSDA();
	} else {
		lowSDA();
	}
	
	risingClock(); // new cycle
	E4235_Delaymicro(clockPeriod); // allow clock cycle
	
	// force everything low
	fallingClock();
	lowSDA();
	E4235_Delaymicro(clockPeriod);
		
	// Same Logic as above but for LSB
	if (address[6] == '1') {
		highSDA();
	} else {
		lowSDA();
	}
	
	risingClock(); // new cycle
	E4235_Delaymicro(clockPeriod); // allow clock cycle
	
	// force everything low
	fallingClock();
	lowSDA();
	E4235_Delaymicro(clockPeriod);
	
	// End with LOW EVERYTHING and has waited
	
	return;
	
} // sendAddress



// Function to write with address and data
void writeFunc(){

	int seconds;
	int minutes;
	int hours;
	int days;
	int date;
	int month;
	int year;
	
	struct tm * local;
	time_t t = time(NULL);
	
	local = localtime(&t);
	
	printf("Local time and date: %s\n", asctime(local));
	
	seconds = local->tm_sec;
	printf("Seconds: %i\n", seconds);
	
	minutes = local->tm_min;
	printf("Minutes: %i\n", minutes);
	
	hours = local->tm_hour;
	printf("Hours: %i\n", hours);
	
	date = local->tm_mday;
	printf("day of Month: %i\n", date);
	
	month = local->tm_mon;
	printf("monthT: %i\n", month);
	
	year = local->tm_year;
	printf("yearT: %i\n", year);
	
	days = local->tm_wday;
	printf("weekday: %i\n", days);

	char address[] = "1101000"; // address
	
	// START CONDITION -------------------------------------------------

	startCondition(); 
	// SDA AND CLOCK NOW LOW

	// SLAVE ADDRESS SENDING -------------------------------------------

	sendAddress(address); // Sends the Address
	// SDA AND CLOCK NOW LOW, already waited
	
	// READ BIT SENDING ------------------------------------------------
	
	// Writes low to SDA to let it know its a write
	lowSDA();
	risingClock();
	E4235_Delaymicro(clockPeriod);
	
	// Reset back to everything Low
	fallingClock();
	lowSDA();
	E4235_Delaymicro(clockPeriod);
	
	// RECEIVE THE ACK -------------------------------------------------
	
	// Extra Clock pulse to receive the Ack
	risingClock();
	E4235_Delaymicro(clockPeriod);
	
	// Clock to low to start next cycle
	fallingClock();
	E4235_Delaymicro(clockPeriod);
	
	// DATA READ ROUNDS 1-7 --------------------------------------------
	
	// iterate 7 times so to get all 7 strings of data needed
	writeSDA(translateSeconds(seconds));
	writeSDA(translateMinutes(minutes));
	writeSDA(translateHours(hours));
	writeSDA(translateDays(days));
	writeSDA(translateDate(date));
	writeSDA(translateMonth(month));
	writeSDA(translateYears(year));
		
	// SEND STOP CONDITION ---------------------------------------------
	
	stopCondition();

	// PRINT THE DATA --------------------------------------------------
	
	return 0;
	
} // writeFunc



// Reads the data on SDA and stores it into a 1 byte int arry
void writeSDA(char inputString) {
	
	printf("What should it print in hex %d\n", inputString);
	
	// Writes bit 7
	E4235_Delaymicro(clockPeriod);
	if ((inputString & 0x80) == 0x80) {
		highSDA(); // print 1
	} else {
		lowSDA(); // print 0
	}
	
	risingClock();
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 6
	E4235_Delaymicro(clockPeriod);
	if((inputString & 0x40) == 0x40) {
		highSDA();
	} else {
		lowSDA();
	}
	
	risingClock();
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 5
	E4235_Delaymicro(clockPeriod);
	if((inputString & 0x20) == 0x20) {
		highSDA();
	} else {
		lowSDA();
	}
	
	risingClock();
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 4
	E4235_Delaymicro(clockPeriod);
	if((inputString & 0x10) == 0x10) {
		highSDA();
	} else {
		lowSDA();
	}
	
	risingClock();
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 3
	E4235_Delaymicro(clockPeriod);
	if((inputString & 0x08) == 0x08) {
		highSDA();
	} else {
		lowSDA();
	}
	
	risingClock();
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 2
	E4235_Delaymicro(clockPeriod);
	if((inputString & 0x04) == 0x04) {
		highSDA();
	} else {
		lowSDA();
	}
	
	risingClock();
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 1
	E4235_Delaymicro(clockPeriod);
	if((inputString & 0x02) == 0x02) {
		highSDA();
	} else {
		lowSDA();
	}
	
	risingClock();
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 0 (LSB)
	E4235_Delaymicro(clockPeriod);
	if((inputString & 0x01) == 0x01) {
		highSDA();
	} else {
		lowSDA();
	}
	
	risingClock();
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Sends an ack to the slave
	lowSDA();
	E4235_Delaymicro(clockPeriod);
	//highSDA(); // represents ack
	risingClock();
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	lowSDA();
	
	return;
}



// Function to Read address with returned data
void readFunc(){

	char seconds;
	char minutes;
	char hours;
	char days;
	char date;
	char month;
	char year;

	int * times[7];
	char address[] = "1101000"; // address for testing, must be 7 bits

	// START CONDITION -------------------------------------------------

	startCondition(); 
	// SDA AND CLOCK NOW LOW

	// SLAVE ADDRESS SENDING -------------------------------------------

	sendAddress(address); // Sends the Address
	// SDA AND CLOCK NOW LOW, already waited
	printf("address sent\n");
	
	// READ BIT SENDING ------------------------------------------------
	
	// Writes high to SDA to let it know its a read
	highSDA();
	risingClock();
	E4235_Delaymicro(clockPeriod);
	
	// Reset back to everything Low
	fallingClock();
	//lowSDA();
	E4235_Delaymicro(clockPeriod);
	printf("rising edge so its a read sent\n");
	
	// RECEIVE THE ACK -------------------------------------------------
	
	// Extra Clock pulse to receive the Ack
	printf("%i: Ack received\n", E4235_Read(SDA));
	risingClock();
	E4235_Delaymicro(clockPeriod);
	
	// Clock to low to start next cycle
	fallingClock();
	E4235_Delaymicro(clockPeriod);
	
	// DATA READ ROUNDS 1-7 --------------------------------------------
	
	// iterate 7 times so to get all 7 strings of data needed
	//seconds = readSDA();
	char secondString;
	
	highSDA();

	// Stores bit 7 (MSB)
	E4235_Delaymicro(clockPeriod);
	secondString = secondString | (E4235_Read(SDA) << 7);
	risingClock();
	//inputString[7] = E4235_Read(SDA);
	printf("%d\n", secondString);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 6
	E4235_Delaymicro(clockPeriod);
	secondString = secondString | (E4235_Read(SDA) << 6);
	risingClock();
	//inputString[6] = E4235_Read(SDA);
	printf("%d\n", secondString);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 5
	E4235_Delaymicro(clockPeriod);
	secondString = secondString | (E4235_Read(SDA) << 5);
	risingClock();
	//inputString[5] = E4235_Read(SDA);
	printf("%d\n", secondString);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 4
	E4235_Delaymicro(clockPeriod);
	secondString = secondString | (E4235_Read(SDA) << 4);
	risingClock();
	//inputString[4] = E4235_Read(SDA);
	printf("%d\n", secondString);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 3
	E4235_Delaymicro(clockPeriod);
	secondString = secondString | (E4235_Read(SDA) << 3);
	risingClock();
	//inputString[3] = E4235_Read(SDA);
	printf("%d\n", secondString);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 2
	E4235_Delaymicro(clockPeriod);
	secondString = secondString | (E4235_Read(SDA) << 2);
	risingClock();
	//inputString[2] = E4235_Read(SDA);
	printf("%d\n", secondString);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 1
	E4235_Delaymicro(clockPeriod);
	secondString = secondString | (E4235_Read(SDA) << 1);
	risingClock();
	//inputString[1] = E4235_Read(SDA);
	printf("%d\n", secondString);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 0 (LSB)
	E4235_Delaymicro(clockPeriod);
	secondString = secondString | (E4235_Read(SDA));
	risingClock();
	//inputString[0] = E4235_Read(SDA);
	printf("%d\n\n", secondString);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Sends an ack to the slave
	E4235_Delaymicro(clockPeriod);
	
	printf("seconds %d\n", secondString);
	lowSDA();
	risingClock();
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	lowSDA();
	// -----------------------------------------------------------------
	
	minutes = readSDA();
	char minutesString;
	
	highSDA();

	// Stores bit 7 (MSB)
	E4235_Delaymicro(clockPeriod);
	minutesString = minutesString | (E4235_Read(SDA) << 7);
	risingClock();
	//inputString[7] = E4235_Read(SDA);
	printf("%d\n", minutesString);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 6
	E4235_Delaymicro(clockPeriod);
	minutesString = minutesString | (E4235_Read(SDA) << 6);
	risingClock();
	//inputString[6] = E4235_Read(SDA);
	printf("%d\n", minutesString);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 5
	E4235_Delaymicro(clockPeriod);
	minutesString = minutesString | (E4235_Read(SDA) << 5);
	risingClock();
	//inputString[5] = E4235_Read(SDA);
	printf("%d\n", minutesString);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 4
	E4235_Delaymicro(clockPeriod);
	minutesString = minutesString | (E4235_Read(SDA) << 4);
	risingClock();
	//inputString[4] = E4235_Read(SDA);
	printf("%d\n", minutesString);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 3
	E4235_Delaymicro(clockPeriod);
	minutesString = minutesString | (E4235_Read(SDA) << 3);
	risingClock();
	//inputString[3] = E4235_Read(SDA);
	printf("%d\n", minutesString);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 2
	E4235_Delaymicro(clockPeriod);
	minutesString = minutesString | (E4235_Read(SDA) << 2);
	risingClock();
	//inputString[2] = E4235_Read(SDA);
	printf("%d\n", minutesString);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 1
	E4235_Delaymicro(clockPeriod);
	minutesString = minutesString | (E4235_Read(SDA) << 1);
	risingClock();
	//inputString[1] = E4235_Read(SDA);
	printf("%d\n", minutesString);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 0 (LSB)
	E4235_Delaymicro(clockPeriod);
	minutesString = minutesString | (E4235_Read(SDA));
	risingClock();
	//inputString[0] = E4235_Read(SDA);
	printf("%d\n\n", minutesString);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Sends an ack to the slave
	E4235_Delaymicro(clockPeriod);
	
	printf("minutes %d\n", minutesString);
	lowSDA();
	risingClock();
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	lowSDA();
	//------------------------------------------------------------------
	//hours = readSDA();
	char hoursString;
	
	highSDA();

	// Stores bit 7 (MSB)
	E4235_Delaymicro(clockPeriod);
	hoursString = hoursString | (E4235_Read(SDA) << 7);
	risingClock();
	//inputString[7] = E4235_Read(SDA);
	printf("%d\n", hoursString);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 6
	E4235_Delaymicro(clockPeriod);
	hoursString = hoursString | (E4235_Read(SDA) << 6);
	risingClock();
	//inputString[6] = E4235_Read(SDA);
	printf("%d\n", hoursString);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 5
	E4235_Delaymicro(clockPeriod);
	hoursString = hoursString | (E4235_Read(SDA) << 5);
	risingClock();
	//inputString[5] = E4235_Read(SDA);
	printf("%d\n", hoursString);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 4
	E4235_Delaymicro(clockPeriod);
	hoursString = hoursString | (E4235_Read(SDA) << 4);
	risingClock();
	//inputString[4] = E4235_Read(SDA);
	printf("%d\n", hoursString);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 3
	E4235_Delaymicro(clockPeriod);
	hoursString = hoursString | (E4235_Read(SDA) << 3);
	risingClock();
	//inputString[3] = E4235_Read(SDA);
	printf("%d\n", hoursString);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 2
	E4235_Delaymicro(clockPeriod);
	hoursString = hoursString | (E4235_Read(SDA) << 2);
	risingClock();
	//inputString[2] = E4235_Read(SDA);
	printf("%d\n", hoursString);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 1
	E4235_Delaymicro(clockPeriod);
	hoursString = hoursString | (E4235_Read(SDA) << 1);
	risingClock();
	//inputString[1] = E4235_Read(SDA);
	printf("%d\n", hoursString);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 0 (LSB)
	E4235_Delaymicro(clockPeriod);
	hoursString = hoursString | (E4235_Read(SDA));
	risingClock();
	//inputString[0] = E4235_Read(SDA);
	printf("%d\n\n", hoursString);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Sends an ack to the slave
	E4235_Delaymicro(clockPeriod);
	printf("hours %d\n", hoursString);
	lowSDA();
	risingClock();
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	lowSDA();
	//-----------------------------------------------------------------
	
	//days = readSDA();
	char daysString;
	
	highSDA();

	// Stores bit 7 (MSB)
	E4235_Delaymicro(clockPeriod);
	daysString = daysString | (E4235_Read(SDA) << 7);
	risingClock();
	//inputString[7] = E4235_Read(SDA);
	printf("%d\n", daysString);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 6
	E4235_Delaymicro(clockPeriod);
	daysString = daysString | (E4235_Read(SDA) << 6);
	risingClock();
	//inputString[6] = E4235_Read(SDA);
	printf("%d\n", daysString);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 5
	E4235_Delaymicro(clockPeriod);
	daysString = daysString | (E4235_Read(SDA) << 5);
	risingClock();
	//inputString[5] = E4235_Read(SDA);
	printf("%d\n", daysString);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 4
	E4235_Delaymicro(clockPeriod);
	daysString = daysString | (E4235_Read(SDA) << 4);
	risingClock();
	//inputString[4] = E4235_Read(SDA);
	printf("%d\n", daysString);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 3
	E4235_Delaymicro(clockPeriod);
	daysString = daysString | (E4235_Read(SDA) << 3);
	risingClock();
	//inputString[3] = E4235_Read(SDA);
	printf("%d\n", daysString);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 2
	E4235_Delaymicro(clockPeriod);
	daysString = daysString | (E4235_Read(SDA) << 2);
	risingClock();
	//inputString[2] = E4235_Read(SDA);
	printf("%d\n", daysString);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 1
	E4235_Delaymicro(clockPeriod);
	daysString = daysString | (E4235_Read(SDA) << 1);
	risingClock();
	//inputString[1] = E4235_Read(SDA);
	printf("%d\n", daysString);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 0 (LSB)
	E4235_Delaymicro(clockPeriod);
	daysString = daysString | (E4235_Read(SDA));
	risingClock();
	//inputString[0] = E4235_Read(SDA);
	printf("%d\n\n", daysString);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Sends an ack to the slave
	E4235_Delaymicro(clockPeriod);
	
	printf("days %d\n", daysString);
	lowSDA();
	risingClock();
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	lowSDA();
	//-----------------------------------------------------------------
	date = readSDA();
	printf("date %d\n", date);
	lowSDA();
	risingClock();
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	lowSDA();
	
	month = readSDA();
	printf("month %d\n", month);
	lowSDA();
	risingClock();
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	lowSDA();
	
	// Last one to close it off
	year = readSDA();
	printf("year %d\n", year);
	highSDA();
	risingClock();
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	lowSDA();
		
	// SEND STOP CONDITION ---------------------------------------------
	
	stopCondition();

	// PRINT THE DATA --------------------------------------------------
	
	return;
	
	// call the I2CRTC function here

} // readFunc



// Reads the data on SDA and stores it into a 1 byte int arry
void readSDA() {
	
	char inputString;
	
	highSDA();

	// Stores bit 7 (MSB)
	E4235_Delaymicro(clockPeriod);
	inputString = inputString | (E4235_Read(SDA) << 7);
	risingClock();
	//inputString[7] = E4235_Read(SDA);
	printf("%d\n", inputString);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 6
	E4235_Delaymicro(clockPeriod);
	inputString = inputString | (E4235_Read(SDA) << 6);
	risingClock();
	//inputString[6] = E4235_Read(SDA);
	printf("%d\n", inputString);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 5
	E4235_Delaymicro(clockPeriod);
	inputString = inputString | (E4235_Read(SDA) << 5);
	risingClock();
	//inputString[5] = E4235_Read(SDA);
	printf("%d\n", inputString);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 4
	E4235_Delaymicro(clockPeriod);
	inputString = inputString | (E4235_Read(SDA) << 4);
	risingClock();
	//inputString[4] = E4235_Read(SDA);
	printf("%d\n", inputString);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 3
	E4235_Delaymicro(clockPeriod);
	inputString = inputString | (E4235_Read(SDA) << 3);
	risingClock();
	//inputString[3] = E4235_Read(SDA);
	printf("%d\n", inputString);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 2
	E4235_Delaymicro(clockPeriod);
	inputString = inputString | (E4235_Read(SDA) << 2);
	risingClock();
	//inputString[2] = E4235_Read(SDA);
	printf("%d\n", inputString);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 1
	E4235_Delaymicro(clockPeriod);
	inputString = inputString | (E4235_Read(SDA) << 1);
	risingClock();
	//inputString[1] = E4235_Read(SDA);
	printf("%d\n", inputString);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 0 (LSB)
	E4235_Delaymicro(clockPeriod);
	inputString = inputString | (E4235_Read(SDA));
	risingClock();
	//inputString[0] = E4235_Read(SDA);
	printf("%d\n\n", inputString);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Sends an ack to the slave
	E4235_Delaymicro(clockPeriod);
	
	// will have to nack the last byte
	
	return inputString;
	
} // readSDA



// Main Function for Logic
int main(int argc, char **argv) {

	// checks if the user wants to read or write to the RTC
	char userChoice;
	userChoice = 'r'; // for testing, remove later
	userChoice = promptUser(); // Ask user to read or write
	
	// Determines whether the user wants to read or write
	if (userChoice == 'r') {
		readFunc();
	} else if (userChoice == 'w') {		
		writeFunc();
	}
  
	return 0; // exit
  
	// We will enable the driver to drive a low and disable it to drive a high
	// This will be done by setting it to an output or setting it to an input
	// We will most likely have to pull the GPIO high by setting the GPIO to an input and set it low by making it an output
  
} // Main
