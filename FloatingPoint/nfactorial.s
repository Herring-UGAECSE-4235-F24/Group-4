@ nfactorial.s
@ Property of Group 4
@
@ Push Name: Updated to New Print Idea
@ 
@ The Idea is to print the input line, read the input, then convert to a float and do the operations, then print the output line.
@ Factorial Logic: CMP if variable is 0, if so, load 1 and branch to exit. 
@                  If not, r1 and r2 are the same, sub 1 from r2 and mul to r1. Repeat until r2 is 0. Branch to exit.

	.text
	.global _start
 
_start:
  b     printInputLine    @ Begin by Printing 'Enter n:'

_printInputLine:
  ldr 	r0, =inputline    @ Load the Print Input String Location in R0
  bl 	  printf			      @ Print and wipe the Registers

_read:
	mov r0, #0				@ Input the file descriptor for STDIN
	mov r2, #1				@ Allocates the data to be read as 1 byte
	mov r7, #3				@ Load the svc code for read
	ldr r1, =input		@ Load the address of the =input variable
	str r0, [r1]			@ Clear the Input Variable (make it equal 0)
	svc 0             @ Call the System Call
	ldrb r1, [r1]			@ Read the data stored in the input variable into r1 

_initLogic: 
	vmov.f32	s0, r1            @ Convert r1 to a float
  vmov.f32  s1, s0            @ Create a duplicate of r1
  
_topOfLoop:
  vsubs.f32 s1, #1            @ Subtract 1 from the counter
  beq        _storeVar @ Exit if s1 equals 0
  vmul.f32  s0, s0, s1        @ r1 = r1 * (r1 - 1)
  b         topOfLoop

_storeVar:
  	ldr   r2, =outputFLOAT
	vldr		s1, [r2]

_printOutputLine:
  	ldr 	r0, =outputline    @ Load the String Format Location in R0
	ldr 	r1, =outputFLOAT		@ Load Address of the Variables into R1
	ldr 	r1, [r1]            	@ Load the Decaminutes variable
 	vcvt.f64.f32 d0, s0 Need to convert to a double before we print
  	vmov 	r1, r2, d0
    	bl 	printf			    @ Print and wipe the Registers

inputINT:
    .word 0
outputFLOAT:
    .float 0
inputline:
    .asciz "Enter n:"
outputline:
    .asciz "n! = %f"
