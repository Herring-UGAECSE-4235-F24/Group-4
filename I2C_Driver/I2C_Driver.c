/* I2C_Driver.c
Property of Sam Brewster and Simline Gijo

Push - Created Initializations and Skeleton Functions

For Deliverables on ELC
1) What value did you use for the pullup resistor?  What is the total pullup resistor that the RP4 driver sees? 
2) Provide a flow chart or pseudo code for your driver.  
3) Document your functions that you defined and used for your driver (including those required above).  Your document should be of the same quality/form as the library components.
4) Describe the I2C bus driver protocal and how you implemented the spec in your design paying attention to the pull-up nature of the bus and how you used the available operations available for GPIOs in the RP4.
5) What was the most challenging aspect of this project?
 */

# include <stdio.h>
# include <bcm2835.h>
# include <sys/time.h>
# include <time.h>

#define SDA 23
#define SCL 24


// User should be prompted to either be able to a) read the value of the rtc, b) write time to the RTC
char promptUser(){

  printf("Input 'r' to read the RTC or 'w' to write to the RTC:");
  return scanf();

} // promptUser


// Function to define and setup the Two GPIOs that will be used or SDA and SCL
void gpioSetup(){

  uint16_t clk_div = BCM2835_I2C_CLOCK_DIVIDER_148;
  
  // Initializes the BCM Library
   if (!bcm2835_init())
        return 1;
 
  // Sets the SDA and SCL pins as Inputs
  bcm2835_gpio_fsel(SDA, BCM2835_GPIO_FSEL_INPT);
  bcm2835_gpio_fsel(SCL, BCM2835_GPIO_FSEL_INPT);

  // Sets the Clock Divider to 100000
  bcm2835_i2c_setClockDivider(clk_div);
	bcm2835_i2c_set_baudrate(100000);
  
} // gpioSetup


// Function to write with address and data
void writeFunc(){

} // writeFunc


// Function to Read address with returned data
void readFunc(){

} // readFunc





// Main Function for Logic
int main(int argc, char **argv) {

  // Initialize BCM and Setup GPIOs
  gpioSetup();
  
  // We will enable the driver to drive a low and disable it to drive a high
  // This will be done by setting it to an output or setting it to an input
  // We will most likely have to pull the GPIO high by setting the GPIO to an input and set it low by making it an output
  
} // Main
