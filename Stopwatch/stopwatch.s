@This is a delay program.  Your RP4 either runs at 1.5 or 1.8GHZ.  Using the program determine what speed your PI appears to be running
@Deliverable 1:  Calculate your RP4 clock speed.  Show how.
@Now lets make a stopwatch.   Use RP9:RP8:RP7 for minutes:seconds:hundredths of seconds.  Output the free running time to the terminal.  At 2:00:00, the stopwatch should go back to 0:00:00 and keep running.  The display
@output should be as described.
@You should look at the printloop.s example for the use of the printf command.  You will probably need to investigate formating using the asciz data type.
@Deliverable 2: your code on github and in your writeup.  We will check in class and look at accuracy as well.

	.text
        .global main
        .func main

main:
        PUSH {LR}
        BAL print
        MOV R3, #0

_start:	

	mov	r2, #120		@ load 18 into r2 (outer loop count)
	MOV 	R3, #0

l1:	ldr	r1, =10000000	@ r1 = 1,000,000,0 (inner loop count) 
l2:	subs	r1, r1, #1		@ r1 = r1 – 1, decrement r1 (inner loop) 
	bne	l2			@ repeat it until r1 = 0 
	b	print
	subs	r2, r2, #1		@ r2 = r2 – 1, decrement r2 (outer loop) 
	@bne	l1			@ repeat it until r2 = 0 

print:    

	LDR 	R0, =string         @ Obtain the String Format Location in R0
        LDR 	R1, =iterations		
        LDR 	R1, [R1]            @ Obtain the Number in Iterations into R1
        BL 	printf
	
	LDR 	R0, =string         @ Obtain the String Format Location in R0
        LDR 	R1, =iterations		
        LDR 	R1, [R1, #4]            @ Obtain the Number in Iterations into R1
        BL 	printf

	LDR 	R0, =colon         @ Obtain the String Format Location in R0
        BL 	printf

	LDR 	R0, =string         @ Obtain the String Format Location in R0
        LDR 	R1, =iterations		
        LDR 	R1, [R1, #8]            @ Obtain the Number in Iterations into R1
        BL 	printf
	
	LDR 	R0, =string         @ Obtain the String Format Location in R0
        LDR 	R1, =iterations		
        LDR 	R1, [R1, #12]            @ Obtain the Number in Iterations into R1
        BL 	printf
	
	LDR 	R0, =colon         @ Obtain the String Format Location in R0
        BL 	printf
	
	LDR 	R0, =string         @ Obtain the String Format Location in R0
        LDR 	R1, =iterations		
        LDR 	R1, [R1, #16]            @ Obtain the Number in Iterations into R1
        BL 	printf
	
	LDR 	R0, =string         @ Obtain the String Format Location in R0
        LDR 	R1, =iterations		
        LDR 	R1, [R1, #20]            @ Obtain the Number in Iterations into R1
        BL 	printf

	LDR 	R0, =newline         @ Obtain the String Format Location in R0
        BL 	printf
	
_exit:
        POP {PC}
        MOV PC, LR

.data
string:
        .asciz "%d"		@ Printable Number Format
colon:
	.asciz ":"
newline:
	.asciz "\n"
iterations:
        .word 0, 1, 2, 3, 4, 5  @ remaining loop iterations MM:SS:HH
