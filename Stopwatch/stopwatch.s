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

_start:	

	@mov	r2, #120		@ load 18 into r2 (outer loop count)
	LDR 	R2, =iterations
	MOV 	R1, #0
	STR 	R1, [R2, #4]

l1:	ldr	r1, =8900000	@ r1 = 8,700,000 (inner loop count) 
l2:	subs	r1, r1, #1		@ r1 = r1 – 1, decrement r1 (inner loop) 
	bne	l2			@ repeat it until r1 = 0 
	b 	_h1
	@subs	r2, r2, #1		@ r2 = r2 – 1, decrement r2 (outer loop) 
	@bne	l1			@ repeat it until r2 = 0 

_h1:
        LDR R1, =iterations
        LDR R1, [R1, #20]
        ADDS R1, #0x1			@ Iterate the Count
        LDR R2, =iterations
        STR R1, [R2, #20]            @ Stores the value in R1 into the memory address in R2
        
	CMP R1, #10
        BEQ _h2
        
        b 	print


_h2:
	MOV R1, #0
	STR R1, [R2, #20]
	
	LDR R1, =iterations
        LDR R1, [R1, #16]
        ADDS R1, #0x1			@ Iterate the Count
        LDR R2, =iterations
        STR R1, [R2, #16]            @ Stores the value in R1 into the memory address in R2
        
	CMP R1, #10
        BEQ _s1
	
	B	print

_s1:

	MOV R1, #0
	STR R1, [R2, #16]
	
	LDR R1, =iterations
        LDR R1, [R1, #12]
        ADDS R1, #0x1			@ Iterate the Count
        LDR R2, =iterations
        STR R1, [R2, #12]            @ Stores the value in R1 into the memory address in R2
        
	CMP R1, #10
        BEQ _s2
	
	B	print
	
_s2:
	MOV R1, #0
	STR R1, [R2, #12]
	
	LDR R1, =iterations
        LDR R1, [R1, #8]
        ADDS R1, #0x1			@ Iterate the Count
        LDR R2, =iterations
        STR R1, [R2, #8]            @ Stores the value in R1 into the memory address in R2
        
	CMP R1, #6
        BEQ _m1
	
	B	print
	
_m1:
	MOV R1, #0
	STR R1, [R2, #8]
	
	LDR R1, =iterations
        LDR R1, [R1, #4]
        ADDS R1, #0x1			@ Iterate the Count
        LDR R2, =iterations
        STR R1, [R2, #4]            @ Stores the value in R1 into the memory address in R2
        
	CMP R1, #2
        BEQ _start
	
	B	print

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
	
	b 	l1
	
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
        .word 0, 0, 0, 0, 0, 0  @ remaining loop iterations MM:SS:HH
