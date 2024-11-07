/* eulersNumber.c
 Property of Group 4 - Sam Brewster and Simline Gijo
 Push: IT WORKS! - Need to Check for Edge Cases
*/ 
 
#include <stdio.h>

extern float nfactorialCCALL(float);
extern float nexponentialCCALL(float, float);

// Main Loop
int main(int argc, char **argv) {

  // Declare Variables
  float x;
  float eSum; 
  float tempNF;
  float tempNE;
  eSum = 0;

  // Initial User Interaction
  printf("Calculate e^x.  Enter x:");
  scanf("%f", &x);
  
  eSum = 1;   // + 1
  //printf("eSum = %f\n", eSum);
  eSum += x;  // + x
  //printf("eSum = %f\n", eSum);

  // + x^2/2! + x^3/3! + x^4/4! + x^5/5!
  for (int i = 2; i < 6; i++) {

	  tempNE = nexponentialCCALL(x, i);   // Get x^n Based on the Loop Iteration
	  //printf("tempNE for %i = %f\n",i, tempNE);
      tempNF = nfactorialCCALL(i);        // Get NFactorial Based on the Loop Iteration
      //printf("tempNF for %i = %f\n",i, tempNF);
      eSum += tempNE/tempNF;         // Add them and increment through until n = 6
	  //printf("eSum = %f\n", eSum);
	  
  } // for

  // Output to the user
  printf("e^%f = %f\n", x, eSum);


  // Exit
  return 0;
  
} // main
