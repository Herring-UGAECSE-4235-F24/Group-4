@ nexponential.s
@ Property of Group 4
@
@ Push Name: Initial Push - Lets see what we can work with
@ 
@ The Idea is to print the input line, read the input, then convert to a float and do the operations, then print the output line.

	.text
	.global _start
 
_start:
  b     printInputLineX    @ Begin by Printing 'Calculate x^n.  Enter x:'

_printInputLineX:
  ldr 	r0, =inputlineX    @ Load the Print Input String Location in R0
  bl 	  printf			      @ Print and wipe the Registers

_readX:
	mov r0, #0				    @ Input the file descriptor for STDIN
	mov r2, #1				    @ Allocates the data to be read as 1 byte
	mov r7, #3				    @ Load the svc code for read
	ldr r1, =inputXINT		@ Load the address of the =inputXINT variable
	str r0, [r1]			    @ Clear the Input Variable (make it equal 0)
	svc 0                 @ Call the System Call
	ldrb r2, [r1]			    @ Read the data stored in the input variable into r1 

_printInputLineN:
  ldr 	r0, =inputlineN    @ Load the Print Input String Location in R0
  bl 	  printf			      @ Print and wipe the Registers

_readN:
	mov r0, #0				    @ Input the file descriptor for STDIN
	mov r2, #1				    @ Allocates the data to be read as 1 byte
	mov r7, #3				    @ Load the svc code for read
	ldr r1, =inputNINT		@ Load the address of the =inputXINT variable
	str r0, [r1]			    @ Clear the Input Variable (make it equal 0)
	svc 0                 @ Call the System Call
	ldrb r3, [r1]			    @ Read the data stored in the input variable into r1 

_initLogic: 
	vmov.f32	s0, r2            @ Convert the X Value in r2 to a float
  vmov.f32	s0, r3            @ Convert the N Value in r3 to a float
  
_topOfLoop:
  cmp       r3, #0       @ Check if n is 0
  beq        nIsZero   @ Exit if s1 equals 0
  vmul.f32  s0, s0, s1   @ r1 = r1 * (r1 - 1)
  b         topOfLoop

_nIsZero:
  ldr     r2, =outputFLOAT
	vldr		s1, [r2]

_printOutputLine:
  	ldr 	r0, =outputline    @ Load the String Format Location in R0
    ldr 	r1, =outputFLOAT		@ Load Address of the Variables into R1
    ldr 	r1, [r1]            	@ Load the Decaminutes variable
    bl 	    printf			    @ Print and wipe the Registers

inputXINT:
    .word 0
inputNINT:
    .word 0
outputFLOAT:
    .float 0
inputlineX:
    .asciz "Calculate x^n.  Enter x:"
inputlineN:
    .asciz "Enter n:"
outputline:
    .asciz "x^n = %f"
