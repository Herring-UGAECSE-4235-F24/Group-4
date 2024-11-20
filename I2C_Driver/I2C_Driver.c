/* I2C_Driver.c
Property of Sam Brewster and Simline Gijo

Push: SDA and SCL Work! - Attempt made at Address Writing

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

extern void E4235_Select(int GPIO, int value);
extern int E4235_Read(int GPIO);
extern void E4235_delayMili(int time);

// User should be prompted to either be able to a) read the value of the rtc, b) write time to the RTC
char promptUser(){

  printf("Input 'r' to read the RTC or 'w' to write to the RTC:");
  //return scanf();

} // promptUser


// Function to define and setup the Two GPIOs that will be used or SDA and SCL
void gpioSetup(){

	// Why would we need to setup the GPIOs?

} // gpioSetup


// Sets the SDA pin to Read Only, making it into an input
void lowSDA() {

	E4235_Select(SDA, 0);
	
} // inputSDA


// Sets the SDA pin to Read Only, making it into an output
void highSDA() {

	E4235_Select(SDA, 1);
	
} // inputSDA


void fallingClock() {

	E4235_Select(SCL, 0);
	
} // inputSCL


void risingClock() {

	E4235_Select(SCL, 1);
	
} // inputSCL

void sendAddress(char * address){
	
	risingClock();
	
	if (address[7] == 0) {
		highSDA();
	} else {
		lowSDA();
	}
	
	E4235_Delaymilli(500);
	lowSDA();
	fallingClock();
	E4235_Delaymilli(500);
	risingClock();
	
	if (address[6] == 0) {
		highSDA();
	} else {
		lowSDA();
	}
	
	E4235_Delaymilli(500);
	lowSDA();
	fallingClock();
	E4235_Delaymilli(500);
	risingClock();
	
	if (address[5] == 0) {
		highSDA();
	} else {
		lowSDA();
	}
	
	E4235_Delaymilli(500);
	lowSDA();
	fallingClock();
	E4235_Delaymilli(500);
	risingClock();
	
	if (address[4] == 0) {
		highSDA();
	} else {
		lowSDA();
	}
	
	E4235_Delaymilli(500);
	lowSDA();
	fallingClock();
	E4235_Delaymilli(500);
	risingClock();
	
	if (address[3] == 0) {
		highSDA();
	} else {
		lowSDA();
	}
	
	E4235_Delaymilli(500);
	lowSDA();
	fallingClock();
	E4235_Delaymilli(500);
	risingClock();
	
	if (address[2] == 0) {
		highSDA();
	} else {
		lowSDA();
	}
	
	E4235_Delaymilli(500);
	lowSDA();
	fallingClock();
	E4235_Delaymilli(500);
	risingClock();
	
	if (address[1] == 0) {
		highSDA();
	} else {
		lowSDA();
	}
	
	E4235_Delaymilli(500);
	lowSDA();
	fallingClock();
	E4235_Delaymilli(500);
	risingClock();
	
	if (address[0] == 0) {
		highSDA();
	} else {
		lowSDA();
	}
	
	E4235_Delaymilli(500);
	lowSDA();
	fallingClock();
	E4235_Delaymilli(500);
	
	return;
	
} // sendAddress


// Function to write with address and data
void writeFunc(){

	char address[] = "10011100";

	sendAddress(address);
	risingClock();
	highSDA();
	
	
} // writeFunc


// Function to Read address with returned data
void readFunc(){

} // readFunc


// There is a function register that designates whether the gpio is an input or output

// Main Function for Logic
int main(int argc, char **argv) {

	//char userChoice;
  
	//userChoice = promptUser(); // Ask user to read or write
	
	while (1) {
		
		risingClock();
		lowSDA();
		
		E4235_Delaymilli(500);
		
		fallingClock();
		highSDA();
		
		E4235_Delaymilli(500);
		
	}
	
  
	// We will enable the driver to drive a low and disable it to drive a high
	// This will be done by setting it to an output or setting it to an input
	// We will most likely have to pull the GPIO high by setting the GPIO to an input and set it low by making it an output
  
} // Main
