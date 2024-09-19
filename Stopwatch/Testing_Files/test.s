@ to compile, use gcc -o stopwatch stopwatch.s -lc
	.text
    .global main
    .include "./E4235_KYBdeblock.s"

main:
    ldr r0, = inputform
    ldr r1, =input
    bl scanf
    ldr r1, =input

    ldr r1, [r1]
    

    mov r0, r1
    mov r0, #1
    bl  E4235_KYBdeblock
	b _Decipher_User_Input

@ check input against ascii characters
_Decipher_User_Input:
	cmp r1, #'R'    @ run the stopwatch
	beq _start
	cmp r1, #'C'    @ run the stopwatch
	beq main
	cmp r1, #'q'    @ quit
	beq exit
	b   _start

_start:	
	LDR 	R2, =iterations		@ Loads address of variables
	MOV 	R1, #0			
	STR 	R1, [R2, #4]		@ Sets Minutes Variable to Zero
	b 	print

l1:	LDR	R1, =8900000		@ R1 = 8,900,000 
l2:	SUBS	R1, R1, #1		@ R1 = R1 – 1, decrement R1 
	BNE	l2			@ repeat it until R1 = 0 
	B 	_h1

@ The _h1 function increments the centisecond variable until it reaches 10 and then branches to _h2.
_h1:
        LDR 	R1, =iterations		@ Loads the Address of the Variables into R1
        LDR 	R1, [R1, #20]		@ Loads the Centisecond Variable into R1
        ADDS 	R1, #0x1		@ Increments R1
        LDR 	R2, =iterations		
        STR 	R1, [R2, #20]           @ Stores the incremented value of R1 into the Centiseconds Variable
        
	CMP 	R1, #10			@ Compares to see if R1 and  10 are equal
        BEQ 	_h2			@ If so, branches to _h2.
        
        B	print			@ Prints

@ The _h2 function resets the centisecond variable, increments the decisecond variable until it reaches 10, and then branches to _s1.
_h2:
	MOV 	R1, #0			
	STR 	R1, [R2, #20]		@ Stores the value Zero in the Centiseconds Variable
	
	LDR 	R1, =iterations
        LDR 	R1, [R1, #16]		@ Loads the Decisecond into R1
        ADDS 	R1, #0x1
        LDR 	R2, =iterations
        STR 	R1, [R2, #16]           @ Stores the incremented value of R1 into the Deciseconds Variable
        
	CMP 	R1, #10
        BEQ 	_s1
	
	B	print

@ The _s1 function resets the decisecond variable, increments the second variable until it reaches 10, and then branches to _s2.
_s1:

	MOV 	R1, #0
	STR 	R1, [R2, #16]		@ Stores the value Zero in the Deciseconds Variable
	
	LDR 	R1, =iterations
        LDR 	R1, [R1, #12]		@ Loads the Second into R1
        ADDS 	R1, #0x1			
        LDR 	R2, =iterations
        STR 	R1, [R2, #12]            @ Stores the incremented value of R1 into the Seconds Variable
        
	CMP 	R1, #10
        BEQ 	_s2
	
	B	print

@ The _s2 function resets the second variable, increments the decasecond variable until it reaches 10, and then branches to _m1.
_s2:
	MOV 	R1, #0
	STR 	R1, [R2, #12]		@ Stores the value Zero in the Seconds Variable
	
	LDR 	R1, =iterations
        LDR 	R1, [R1, #8]		@ Loads the Decasecond into R1
        ADDS 	R1, #0x1			
        LDR 	R2, =iterations
        STR 	R1, [R2, #8]            @ Stores the incremented value of R1 into the Decaseconds Variable
        
	CMP 	R1, #6
        BEQ 	_m1
	
	B	print

@ The _m1 function resets the decasecond variable, increments the hectosecond variable until it reaches 10, and then branches to _start.
_m1:
	MOV 	R1, #0
	STR 	R1, [R2, #8]		@ Stores the value Zero in the Decaseconds Variable
	
	LDR 	R1, =iterations
        LDR 	R1, [R1, #4]		@ Loads the Hectosecond into R1
        ADDS 	R1, #0x1			
        LDR 	R2, =iterations
        STR 	R1, [R2, #4]            @ Stores the incremented value of R1 into the Hectoseconds Variable
        
	CMP 	R1, #2
        BEQ 	print_2_00_00		@ Branches to print  2_00_00 
	
	B	print

print:    

	LDR 	R0, =string         	@ Load the String Format Location in R0
        LDR 	R1, =iterations		@ Load Address of the Variables into R1
        LDR 	R1, [R1]            	@ Load the Decaminutes variable
        BL 	printf			@ Print and wipe the Registers
	
	LDR 	R0, =string         	
        LDR 	R1, =iterations		
        LDR 	R1, [R1, #4]        	@ Load the minutes variable
        BL 	printf

	LDR 	R0, =colon          	@ Load the Colon String in R0
        BL 	printf

	LDR 	R0, =string         	
        LDR 	R1, =iterations		
        LDR 	R1, [R1, #8]            @ Load the deaseconds variable
        BL 	printf
	
	LDR 	R0, =string         	
        LDR 	R1, =iterations		
        LDR 	R1, [R1, #12]           @ Load the seconds variable
        BL 	printf
	
	LDR 	R0, =colon         	@ Load the Colon String in R0
        BL 	printf
	
	LDR 	R0, =string         	
        LDR 	R1, =iterations		
        LDR 	R1, [R1, #16]           @ Load the deciseconds variable
        BL 	printf
	
	LDR 	R0, =string         	
        LDR 	R1, =iterations		
        LDR 	R1, [R1, #20]           @ Load the seconds variable
        BL 	printf

	LDR 	R0, =newline         	@ Load the newline character in R0
        BL 	printf
	
	b 	l1			@ Restart the Loop

print_2_00_00:    

	LDR 	R0, =string         	@ Load the String Format Location in R0
        LDR 	R1, =iterations		@ Load Address of the Variables into R1
        LDR 	R1, [R1]            	@ Load the Decaminutes variable
        BL 	printf			@ Print and wipe the Registers
	
	LDR 	R0, =string         	
        LDR 	R1, =iterations		
        LDR 	R1, [R1, #4]        	@ Load the minutes variable
        BL 	printf

	LDR 	R0, =colon          	@ Load the Colon String in R0
        BL 	printf

	LDR 	R0, =string         	
        LDR 	R1, =iterations		
        LDR 	R1, [R1, #8]            @ Load the deaseconds variable
        BL 	printf
	
	LDR 	R0, =string         	
        LDR 	R1, =iterations		
        LDR 	R1, [R1, #12]           @ Load the seconds variable
        BL 	printf
	
	LDR 	R0, =colon         	@ Load the Colon String in R0
        BL 	printf
	
	LDR 	R0, =string         	
        LDR 	R1, =iterations		
        LDR 	R1, [R1, #16]           @ Load the deciseconds variable
        BL 	printf
	
	LDR 	R0, =string         	
        LDR 	R1, =iterations		
        LDR 	R1, [R1, #20]           @ Load the seconds variable
        BL 	printf

	LDR 	R0, =newline         	@ Load the newline character in R0
        BL 	printf
	
	b 	_start			@ Restart the Loop

@ Used to exit but will never be reached	
_exit:
        mov R7, #1
        svc 0


@ Data and Variables
.data
string:
        .asciz "%d"			@ Printable Number Format
colon:
	.asciz ":"			@ Printable Colon
newline:
	.asciz "\n"			@ Printable New Line Character
iterations:
        .word 0, 0, 0, 0, 0, 0  	@ Variables for Clock in order of: MM:SS:HH
output: .ascii "xxxx\n"
inputform:
        .asciz "%d"
input:
        .word 0
