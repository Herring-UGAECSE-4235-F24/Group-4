@ nfactorial.s
@ Property of Group 4
@
@ Push Name: Scan F Works
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

	ldr r0, =format
	ldr r1, =inputINT
	bl scanf

_initLogic: 
	
	ldr 	r0, =outputline    	@ Load the String Format Location in R0
	ldr r1, =inputINT		@ Load the address of the =input variable
	ldr r1, [r1]
s1:
	bl 	printf			@ Print and wipe the Registers

_exit:
	pop {r0-r4, pc}
	mov r7, #1		@ Load the Exit Value
 	svc 0			@ Exit the Program

.data
inputINT:
    .word 0
inputline:
    .string "Enter n:"
format:
	.string "%i"
outputline:
    .string "\nn! = %i\n"
