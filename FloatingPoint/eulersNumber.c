/* eulersNumber.c
 Property of Group 4 - Sam Brewster and Simline Gijo
 Push: Can Read in Both Assembly Files
 
3) Now, lets use your two functions to calculate a e^x using series expansion
Write a C program that calls your two assembly functions to calculte the e^x (0 and positive reals are okay) out to the first 5 terms of the Taylor series
"Calculate e^x.  Enter x:"   and on completion, "e^x = ...."  (substitute the value entered for x)
e^x = 1 + x+ x^2/2! + x^3/3! + x^4/4! + x^5/5!

The program should ask for the value of x (we will only allow 0 and positive small reals) from the keyboard input.
Display the result to the terminal. 
We will check in class.

Helpful Notes - https://stackoverflow.com/questions/13901261/calling-assembly-function-from-c

*/ 
 
#include <stdio.h>

extern float nfactorial(float n);
extern float nexponential(float n, float x);

// Main Loop
int main(int argc, char **argv) {

  // Declare Variables
  float tempNF;
  tempNF = 0;
  float tempNE;
  tempNE = 0;
  float x;
  float eSum; 

  // Initial User Interaction
  printf("Calculate e^x.  Enter x:");
  scanf("%f", &x);

  eSum = 1;   // + 1

  eSum += x;  // + x

  // + x^2/2! + x^3/3! + x^4/4! + x^5/5!
  for (int i = 2; i < 6; i++) {

      tempNF = nfactorial(i);        // Get NFactorial Based on the Loop Iteration
      tempNE = nexponential(x, i);   // Get x^n Based on the Loop Iteration
      eSum += tempNE/tempNF;         // Add them and increment through until n = 6
    
  }

  // Output to the user
  printf("e^%d = %d", x, eSum);

  // Exit
  return 0;
  
} // main
