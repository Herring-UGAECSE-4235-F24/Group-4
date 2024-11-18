/* I2C_Driver.c
Property of Sam Brewster and Simline Gijo

Push: Dr. Herring Update - We need to MANUALLY access the GPIO addresses

For Deliverables on ELC
1) What value did you use for the pullup resistor?  What is the total pullup resistor that the RP4 driver sees? 
2) Provide a flow chart or pseudo code for your driver.  
3) Document your functions that you defined and used for your driver (including those required above).  Your document should be of the same quality/form as the library components.
4) Describe the I2C bus driver protocal and how you implemented the spec in your design paying attention to the pull-up nature of the bus and how you used the available operations available for GPIOs in the RP4.
5) What was the most challenging aspect of this project?

https://www.ics.com/blog/how-control-gpio-hardware-c-or-c

 */

# include <stdio.h>
# include <bcm2835.h>
# include <sys/time.h>
# include <time.h>

#define SDA 23
#define SCL 24

#define SDA_BASE_ADDRESS 0x40022000  // Base Address for pin 23
#define SCL_BASE_ADDRESS 0x40022000  // Base Address for pin 24

// User should be prompted to either be able to a) read the value of the rtc, b) write time to the RTC
char promptUser(){

  printf("Input 'r' to read the RTC or 'w' to write to the RTC:");
  return scanf();

} // promptUser


// Function to define and setup the Two GPIOs that will be used or SDA and SCL
void gpioSetup(){

	// How can we access these specific GPIOs and 

} // gpioSetup


// Sets the SDA pin to Read Only, making it into an input
void inputSDA() {

	// How can we access this specific GPIO?
	int fd = open("/sys/class/gpio/export", O_RONLY);
	
	if (fd == -1) {
		printf("Error Opening File");
		return -1;
	} // if
	
} // inputSDA


// Sets the SDA pin to Read Only, making it into an output
void outputSDA() {

	// How can we access this specific GPIO?
	int fd = open("/sys/class/gpio/export", O_WONLY);
	
	if (fd == -1) {
		printf("Error Opening File");
		return -1;
	} // if
	
} // inputSDA


void inputSCL() {

	// GPIO_DIRN;	
	
} // inputSCL


// Function to write with address and data
void writeFunc(){

	
} // writeFunc


// Function to Read address with returned data
void readFunc(){

} // readFunc


// There is a function register that designates whether the gpio is an input or output

// Main Function for Logic
int main(int argc, char **argv) {

  // Initialize BCM and Setup GPIOs
  gpioSetup();
  
  // We will enable the driver to drive a low and disable it to drive a high
  // This will be done by setting it to an output or setting it to an input
  // We will most likely have to pull the GPIO high by setting the GPIO to an input and set it low by making it an output
  
} // Main
