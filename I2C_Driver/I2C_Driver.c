/* I2C_Driver.c
Property of Sam Brewster and Simline Gijo

Push: Can Properly Write Address and Tries to Read Data in - Why is it all Zeroes? Works on paper

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


// Function to define and setup the Two GPIOs that will be used or SDA and SCL
void gpioSetup(){

} // gpioSetup


// Sets the SDA pin to Read Only, making it into an input
void lowSDA() {

	E4235_Select(SDA, 0);
	
} // inputSDA


// Sets the SDA pin to Read Only, making it into an output
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

void sendAddress(char * address){
	
	risingClock();
	
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


// Reads one Byte from SDA
int ** readSDA() {
	
	int * inputString[8];
	
	printf("Inside Read\n");

	// Writes high to let it know its a read
	risingClock();
	inputString[8] = E4235_Read(SDA);
	printf("%i", inputString[8]);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	E4235_Delaymicro(clockPeriod);
	risingClock();
	inputString[7] = E4235_Read(SDA);
	printf("%i", inputString[7]);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	E4235_Delaymicro(clockPeriod);
	risingClock();
	inputString[6] = E4235_Read(SDA);
	printf("%i", inputString[6]);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	E4235_Delaymicro(clockPeriod);
	risingClock();
	inputString[5] = E4235_Read(SDA);
	printf("%i", inputString[5]);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	E4235_Delaymicro(clockPeriod);
	risingClock();
	inputString[4] = E4235_Read(SDA);
	printf("%i", inputString[4]);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	E4235_Delaymicro(clockPeriod);
	risingClock();
	inputString[3] = E4235_Read(SDA);
	printf("%i", inputString[3]);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	E4235_Delaymicro(clockPeriod);
	risingClock();
	inputString[2] = E4235_Read(SDA);
	printf("%i", inputString[2]);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	E4235_Delaymicro(clockPeriod);
	risingClock();
	inputString[1] = E4235_Read(SDA);
	printf("%i", inputString[1]);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	E4235_Delaymicro(clockPeriod);
	risingClock();
	inputString[0] = E4235_Read(SDA);
	printf("%i\n", inputString[0]);
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	
	E4235_Delaymicro(clockPeriod);
	risingClock();
	highSDA();
	E4235_Delaymicro(clockPeriod);
	fallingClock();
	lowSDA();
	
	return inputString;
}


// Function to Read address with returned data
void readFunc(){

	char address[] = "1101000"; // must be 7 bits

	// Sends the Address
	sendAddress(address);

	printf("address sent\n");
	
	// Writes high to let it know its a read
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


void testSDASCL() {
	
	while (1) {
		
		risingClock();
		lowSDA();
		
		E4235_Delaymicro(clockPeriod);
		
		fallingClock();
		highSDA();
		
		E4235_Delaymicro(clockPeriod);
		
	}
} // testSDASCL


// Main Function for Logic
int main(int argc, char **argv) {

	char userChoice;
  
	//userChoice = promptUser(); // Ask user to read or write
	
	//printf("%c\n", userChoice);
	
	readFunc();
	
	

  
	// We will enable the driver to drive a low and disable it to drive a high
	// This will be done by setting it to an output or setting it to an input
	// We will most likely have to pull the GPIO high by setting the GPIO to an input and set it low by making it an output
  
} // Main
