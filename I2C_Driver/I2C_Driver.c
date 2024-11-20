/* I2C_Driver.c
Property of Sam Brewster and Simline Gijo

Push: Kind of works with write, but it does respond with acks!

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



// Does nothing currently
void gpioSetup(){

} // gpioSetup



// Sets the SDA pin to Read Only, making it into a low
void highSDA() {

	E4235_Select(SDA, 0);
	
} // inputSDA



// Sets the SDA pin to Write Only, making it into a high
void lowSDA() {

	E4235_Select(SDA, 1);
	
} // inputSDA



// Causes a falling Edge for the clock
void risingClock() {

	E4235_Select(SCL, 0);
	
} // inputSCL



// Causes a rising Edge for the Clock
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
	printf("%c\n", address[0]);
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
	printf("%c\n", address[1]);
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
	printf("%c\n", address[2]);
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
	printf("%c\n", address[3]);
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
	printf("%c\n", address[4]);
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
	printf("%c\n", address[5]);
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
	printf("%c\n", address[6]);
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

	char * times[7];
	int seconds;
	int minutes;
	int hours;
	int days;
	int date;
	int month;
	int year;

	times[6] = "01111111";
	times[5] = "00111111";
	times[4] = "00011111";
	times[3] = "00001111";
	times[2] = "00000111";
	times[1] = "00000011";
	times[0] = "00000001";

	char address[] = "1101000"; // address for testing, must be 7 bits
	//char address[] = "1000110"; // address for testing, must be 7 bits

	// START CONDITION -------------------------------------------------

	startCondition(); 
	// SDA AND CLOCK NOW LOW

	// SLAVE ADDRESS SENDING -------------------------------------------

	sendAddress(address); // Sends the Address
	// SDA AND CLOCK NOW LOW, already waited
	printf("address sent\n");
	
	// READ BIT SENDING ------------------------------------------------
	
	// Writes low to SDA to let it know its a write
	lowSDA();
	risingClock();
	E4235_Delaymicro(clockPeriod);
	
	// Reset back to everything Low
	fallingClock();
	lowSDA();
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
	for(int i = 0; i <= 6; i++){
		writeSDA(times[i]);
		printf("write iteration %i done\n", i);
	}
		
	// SEND STOP CONDITION ---------------------------------------------
	
	stopCondition();

	// PRINT THE DATA --------------------------------------------------
	
	return 0;
	
} // writeFunc



// Reads the data on SDA and stores it into a 1 byte int arry
void writeSDA(char * inputString) {
	
	printf("Inside Write\n");
	
	// Writes bit 7
	E4235_Delaymicro(clockPeriod);
	if(inputString[0] == '1') {
		highSDA();
	} else {
		lowSDA();
	}
	risingClock();
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 6
	E4235_Delaymicro(clockPeriod);
	if(inputString[1] == '1') {
		highSDA();
	} else {
		lowSDA();
	}
	risingClock();
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 5
	E4235_Delaymicro(clockPeriod);
	if(inputString[2] == '1') {
		highSDA();
	} else {
		lowSDA();
	}
	risingClock();
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 4
	E4235_Delaymicro(clockPeriod);
	if(inputString[3] == '1') {
		highSDA();
	} else {
		lowSDA();
	}
	risingClock();
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 3
	E4235_Delaymicro(clockPeriod);
	if(inputString[4] == '1') {
		highSDA();
	} else {
		lowSDA();
	}
	risingClock();
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 2
	E4235_Delaymicro(clockPeriod);
	if(inputString[5] == '1') {
		highSDA();
	} else {
		lowSDA();
	}
	risingClock();
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 1
	E4235_Delaymicro(clockPeriod);
	if(inputString[6] == '1') {
		highSDA();
	} else {
		lowSDA();
	}
	risingClock();
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 0 (LSB)
	E4235_Delaymicro(clockPeriod);
	if(inputString[7] == '1') {
		highSDA();
	} else {
		lowSDA();
	}
	risingClock();
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	printf("%c", inputString[7]);
	printf("%c", inputString[6]);
	printf("%c", inputString[5]);
	printf("%c", inputString[4]);
	printf("%c", inputString[3]);
	printf("%c", inputString[2]);
	printf("%c", inputString[1]);
	printf("%c\n", inputString[0]);
	
	// Sends an ack to the slave
	E4235_Delaymicro(clockPeriod);
	highSDA(); // represents ack
	risingClock();
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	lowSDA();
	
	return;
}



// Function to Read address with returned data
void readFunc(){

	int * times[8];
	char address[] = "11001000"; // address for testing, must be 7 bits

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
	lowSDA();
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
	for(int i = 0; i <= 6; i++){
		// store returned read data into an array
		//times[i] = 
		readSDA();
		printf("iteration %i done\n", i);
	}
		
	// SEND STOP CONDITION ---------------------------------------------
	
	stopCondition();

	// PRINT THE DATA --------------------------------------------------
	
	return 0;
	
	// call the I2CRTC function here

} // readFunc

// Reads the data on SDA and stores it into a 1 byte int arry
void readSDA() {
	
	char * inputString[8];
	
	printf("Inside Read\n");

	// Stores bit 7 (MSB)
	E4235_Delaymicro(clockPeriod);
	inputString[7] = E4235_Read(SDA);
	risingClock();
	printf("%i", inputString[7]);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 6
	E4235_Delaymicro(clockPeriod);
	inputString[6] = E4235_Read(SDA);
	risingClock();
	printf("%i", inputString[6]);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 5
	E4235_Delaymicro(clockPeriod);
	inputString[5] = E4235_Read(SDA);
	risingClock();
	printf("%i", inputString[5]);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 4
	E4235_Delaymicro(clockPeriod);
	inputString[4] = E4235_Read(SDA);
	risingClock();
	printf("%i", inputString[4]);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 3
	E4235_Delaymicro(clockPeriod);
	inputString[3] = E4235_Read(SDA);
	risingClock();
	printf("%i", inputString[3]);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 2
	E4235_Delaymicro(clockPeriod);
	inputString[2] = E4235_Read(SDA);
	risingClock();
	printf("%i", inputString[2]);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 1
	E4235_Delaymicro(clockPeriod);
	inputString[1] = E4235_Read(SDA);
	risingClock();
	printf("%i", inputString[1]);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 0 (LSB)
	E4235_Delaymicro(clockPeriod);
	inputString[0] = E4235_Read(SDA);
	risingClock();
	printf("%i\n", inputString[0]);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Sends an ack to the slave
	E4235_Delaymicro(clockPeriod);
	highSDA(); // represents ack
	risingClock();
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	lowSDA();
	
	return;
	
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
