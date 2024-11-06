@ nfactorial.s
@ Property of Group 4
@
@ Push Name: Not Properly Reading User Input - Lets try Scanf
@ 
@ The Idea is to print the input line, read the input, then convert to a float and do the operations, then print the output line.
@ Factorial Logic: CMP if variable is 0, if so, load 1 and branch to exit. 
@                  If not, r1 and r2 are the same, sub 1 from r2 and mul to r1. Repeat until r2 is 0. Branch to exit.

.text
.global main
 
main:
	push {r0-r4, lr}
	ldr 	r0, =inputline  @ Load the Print Input String Location in R0
	bl 	printf	  	@ Print and wipe the Registers
	b _scan

_read:
	mov r0, #0		@ Input the file descriptor for STDIN
	mov r2, #1		@ Allocates the data to be read as 1 byte
	mov r7, #3		@ Load the svc code for read
	ldr r1, =inputINT		@ Load the address of the =input variable
	str r0, [r1]		@ Clear the Input Variable (make it equal 0)
	svc 0             	@ Call the System Call

_scan:
	ldr r1, =inputINT		@ Load the address of the =input variable
	bl scanf

_initLogic: 
  	vldr.f32 s15, [r1]	@ Read the data stored in the input variable into r1 
s1:
 	vcvt.f64.f32 d7, s15 		@ Convert to a double
s2:
	ldr 	r0, =outputline    	@ Load the String Format Location in R0
	vmov 	r2, r3, d7		@ Mov to be printed
s3:
	bl 	printf			@ Print and wipe the Registers

_exit:
	pop {r0-r4, pc}
	mov r7, #1		@ Load the Exit Value
 	svc 0			@ Exit the Program

.data
inputINT:
    .word 0
outputFLOAT:
    .float 0
inputline:
    .string "Enter n:"
outputline:
    .string "\nn! = %f\n"
