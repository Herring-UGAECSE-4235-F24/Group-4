/* eulersNumber.c
 Property of Group 4 - Sam Brewster and Simline Gijo
 Push: Can Call Both Functions
*/ 
 
#include <stdio.h>

extern float nfactorialCCALL(float);
extern float nexponentialCCALL(float, float);

// Main Loop
int main(int argc, char **argv) {

  // Declare Variables
  float x;
  float eSum; 
  eSum = 4;

  // Initial User Interaction
  printf("Calculate e^x.  Enter x:");
  scanf("%f", &x);
  
  float tempNF = nfactorialCCALL(x);        // Get NFactorial Based on the Loop Iteration
  printf("Second:%f\n", tempNF);
  
  float tempNE = nexponentialCCALL(3, 2);        // Get NFactorial Based on the Loop Iteration
  printf("Second:%f\n", tempNE);

  // Exit
  return 0;
  
} // main
