/* I2C_Driver.c
Property of Sam Brewster and Simline Gijo

Push: Can Properly Write Address and Tries to Read Data in - Added Comments and Cleaned it up

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

// In order to use the standard I2C rate, we need 10 microseconds per on/off cycle
#define clockPeriod 10

extern void E4235_Select(int GPIO, int value);
extern int E4235_Read(int GPIO);
extern void E4235_delayMili(int time);
extern void E4235_delayMicro(int time);

// User should be prompted to either be able to a) read the value of the rtc, b) write time to the RTC
char promptUser(){

	char * responseFormat = "%c";
	char responseList[1];

	printf("Input 'r' to read the RTC or 'w' to write to the RTC:");
	scanf(responseFormat, responseList);
	return responseList[0];

} // promptUser


// Does nothing currently
void gpioSetup(){

} // gpioSetup



// Sets the SDA pin to Read Only, making it into a low
void lowSDA() {

	E4235_Select(SDA, 0);
	
} // inputSDA



// Sets the SDA pin to Write Only, making it into a high
void highSDA() {

	E4235_Select(SDA, 1);
	
} // inputSDA



// Causes a falling Edge for the clock
void fallingClock() {

	E4235_Select(SCL, 0);
	
} // inputSCL



// Causes a rising Edge for the Clock
void risingClock() {

	E4235_Select(SCL, 1);
	
} // inputSCL



// Sends a 7 bit address to the slave
void sendAddress(char * address){
	
	risingClock(); // start high for some reason
	
	// If the bit is high, output a high on SDA, and vice versa
	printf("%c\n", address[0]);
	if (address[0] == '0') {
		highSDA();
	} else {
		lowSDA();
	}
	
	E4235_Delaymicro(clockPeriod);
	lowSDA();
	fallingClock();
	E4235_Delaymicro(clockPeriod);
	risingClock();

	// Same Logic as above but for 2nd MSB
	printf("%c\n", address[1]);
	if (address[1] == '0') {
		highSDA();
	} else {
		lowSDA();
	}
	
	E4235_Delaymicro(clockPeriod);
	lowSDA();
	fallingClock();
	E4235_Delaymicro(clockPeriod);
	risingClock();
	
	// Same Logic as above but for 3rd MSB
	printf("%c\n", address[2]);
	if (address[2] == '0') {
		highSDA();
	} else {
		lowSDA();
	}
	
	E4235_Delaymicro(clockPeriod);
	lowSDA();
	fallingClock();
	E4235_Delaymicro(clockPeriod);
	risingClock();
	
	// Same Logic as above but for 4th MSB
	printf("%c\n", address[3]);
	if (address[3] == '0') {
		highSDA();
	} else {
		lowSDA();
	}
	
	E4235_Delaymicro(clockPeriod);
	lowSDA();
	fallingClock();
	E4235_Delaymicro(clockPeriod);
	risingClock();
	
	// Same Logic as above but for 5th MSB
	printf("%c\n", address[4]);
	if (address[4] == '0') {
		highSDA();
	} else {
		lowSDA();
	}
	
	E4235_Delaymicro(clockPeriod);
	lowSDA();
	fallingClock();
	E4235_Delaymicro(clockPeriod);
	risingClock();
	
	// Same Logic as above but for 6th MSB
	printf("%c\n", address[5]);
	if (address[5] == '0') {
		highSDA();
	} else {
		lowSDA();
	}
	
	E4235_Delaymicro(clockPeriod);
	lowSDA();
	fallingClock();
	E4235_Delaymicro(clockPeriod);
	risingClock();
	
	// Same Logic as above but for LSB
	printf("%c\n", address[6]);
	if (address[6] == '0') {
		highSDA();
	} else {
		lowSDA();
	}
	
	E4235_Delaymicro(clockPeriod);
	lowSDA();
	fallingClock();
	E4235_Delaymicro(clockPeriod);
	
	//return;
	
} // sendAddress



// Function to write with address and data
void writeFunc(){

	char address[] = "1101000"; // must be 7 bits

	// Sends the Address
	sendAddress(address);

	
	// Writes low to let it know its a write
	risingClock();
	lowSDA();
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	E4235_Delaymicro(clockPeriod);
	
	// Extra Clock pulse to receive the Ack
	risingClock();
	lowSDA();
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	E4235_Delaymicro(clockPeriod);
	
	return;
	
} // writeFunc



// Reads the data on SDA and stores it into a 1 byte int arry
int ** readSDA() {
	
	int * inputString[8];
	
	printf("Inside Read\n");

	// Stores bit 8 (MSB)
	risingClock();
	inputString[8] = E4235_Read(SDA);
	printf("%i", inputString[8]);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 7
	E4235_Delaymicro(clockPeriod);
	risingClock();
	inputString[7] = E4235_Read(SDA);
	printf("%i", inputString[7]);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 6
	E4235_Delaymicro(clockPeriod);
	risingClock();
	inputString[6] = E4235_Read(SDA);
	printf("%i", inputString[6]);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 5
	E4235_Delaymicro(clockPeriod);
	risingClock();
	inputString[5] = E4235_Read(SDA);
	printf("%i", inputString[5]);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 4
	E4235_Delaymicro(clockPeriod);
	risingClock();
	inputString[4] = E4235_Read(SDA);
	printf("%i", inputString[4]);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 3
	E4235_Delaymicro(clockPeriod);
	risingClock();
	inputString[3] = E4235_Read(SDA);
	printf("%i", inputString[3]);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 2
	E4235_Delaymicro(clockPeriod);
	risingClock();
	inputString[2] = E4235_Read(SDA);
	printf("%i", inputString[2]);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 1
	E4235_Delaymicro(clockPeriod);
	risingClock();
	inputString[1] = E4235_Read(SDA);
	printf("%i", inputString[1]);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Stores bit 0 (LSB)
	E4235_Delaymicro(clockPeriod);
	risingClock();
	inputString[0] = E4235_Read(SDA);
	printf("%i\n", inputString[0]);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	// Sends an ack to the slave
	E4235_Delaymicro(clockPeriod);
	risingClock();
	highSDA(); // represents ack
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	lowSDA();
	
	return inputString;
}



// Function to Read address with returned data
void readFunc(){

	char address[] = "1101000"; // address for testing, must be 7 bits

	// Sends the Address
	sendAddress(address);

	printf("address sent\n");
	
	// Writes high to SDA to let it know its a read
	risingClock();
	highSDA();
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	E4235_Delaymicro(clockPeriod);
	
	printf("rising edge so its a read sent\n");
	
	// Extra Clock pulse to receive the Ack
	risingClock();
	//lowSDA();
	E4235_Delaymicro(clockPeriod);
	printf("%i: Ack received\n", E4235_Read(SDA));
	fallingClock();
	E4235_Delaymicro(clockPeriod);
		
	// readSDA
	readSDA();
	printf("sda read\n");
	
	return;

} // readFunc



// Main Function for Logic
int main(int argc, char **argv) {

	// checks if the user wants to read or write to the RTC
	char userChoice;
	userCoice = 'r'; // for testing, remove later
	//userChoice = promptUser(); // Ask user to read or write
	
	
	// Determines whether the user wants to read or write
	if (userChoice == 'r') {
		readFunc();
	} else if (userChoice == 'w') {
		writeFunc();
	}
  
	// We will enable the driver to drive a low and disable it to drive a high
	// This will be done by setting it to an output or setting it to an input
	// We will most likely have to pull the GPIO high by setting the GPIO to an input and set it low by making it an output
  
} // Main
