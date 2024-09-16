    .text
    .global main
    .include "./E4235_KYBdeblock.s"

main:

_Wait_For_Input:
	b _Read_User_Input
	

@ read from stdin
_Read_User_Input:
	mov r0, #0	@ file descriptor for stdin
	mov r2, #4	@ allocates bytes to read
	mov r7, #3	@ svc read
	ldr r1, =input
	str r0, [r1]	@ reset input
	svc 0
	ldrb r1, [r1]	@ read byte in input
	b    _Decipher_User_Input

@ check input against ascii characters
_Decipher_User_Input:
	cmp r1, #'R'    @ run the stopwatch
	beq _Run
	cmp r1, #'C'    @ run the stopwatch
	beq _Clear
	cmp r1, #'b'    @ blocking
	beq block
	cmp r1, #'d'    @ deblocking
	beq deblock
	cmp r1, #'q'    @ quit
	beq quit
	b   print

_Clear:
	MOV 	R4, #0			
	STR 	R4, [R5]		@ Sets Minutes Variable to Zero
	STR 	R4, [R5, #4]		@ Sets Minutes Variable to Zero
	STR 	R4, [R5, #8]		@ Sets Minutes Variable to Zero
	STR 	R4, [R5, #12]		@ Sets Minutes Variable to Zero
	STR 	R4, [R5, #16]		@ Sets Minutes Variable to Zero
	STR 	R4, [R5, #20]		@ Sets Minutes Variable to Zero
	b	_Read_User_Input
	
_Run:
	LDR 	R5, =iterations		@ Loads address of variables
	MOV 	R4, #0			
	STR 	R4, [R5, #4]		@ Sets Minutes Variable to Zero
	b 	_Print_Time

l1:	LDR	R4, =8900000		@ R1 = 8,900,000 
l2:	SUBS	R4, R4, #1		@ R1 = R1 – 1, decrement R1 
	BNE	l2			@ repeat it until R1 = 0 
	B 	_h1

@ The _h1 function increments the centisecond variable until it reaches 10 and then branches to _h2.
_h1:
        LDR 	R4, =iterations		@ Loads the Address of the Variables into R1
        LDR 	R4, [R5, #20]		@ Loads the Centisecond Variable into R1
        ADDS 	R4, #0x1		@ Increments R1
        LDR 	R5, =iterations		
        STR 	R4, [R5, #20]           @ Stores the incremented value of R1 into the Centiseconds Variable
        
	CMP 	R4, #10			@ Compares to see if R1 and  10 are equal
        BEQ 	_h2			@ If so, branches to _h2.
        
        B	_Print_Time			@ Prints

@ The _h2 function resets the centisecond variable, increments the decisecond variable until it reaches 10, and then branches to _s1.
_h2:
	MOV 	R4, #0			
	STR 	R4, [R5, #20]		@ Stores the value Zero in the Centiseconds Variable
	
	LDR 	R4, =iterations
        LDR 	R4, [R4, #16]		@ Loads the Decisecond into R1
        ADDS 	R4, #0x1
        LDR 	R5, =iterations
        STR 	R4, [R5, #16]           @ Stores the incremented value of R1 into the Deciseconds Variable
        
	CMP 	R4, #10
        @BEQ 	_s1
	
	B	_Print_Time
	
_Print_Time:    
	
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
        LDR 	R1, [R1, #20]           @ Load the centiseconds variable
        BL 	printf

	LDR 	R0, =newline         	@ Load the newline character in R0
        BL 	printf
	
	b 	l1			@ Restart the Loop

@ change the terminal to blocking
block:
    mov r0, #0
    bl  E4235_KYBdeblock
    b   _Read_User_Input

@ change the terminal to nonblocking
deblock:
    mov r0, #1
    bl  E4235_KYBdeblock
    b   _Read_User_Input

@ print a string to the terminal
print:
    ldr r0, =string
    bl  printf
    ldr r1, =input
    b   _Read_User_Input

@ quit the program
quit:
    mov r7, #1
    svc 0

.data
input:
    .asciz "%c"
string:
    .asciz "%d"			@ Printable Number Format
colon:
    .asciz ":"			@ Printable Colon
newline:
    .asciz "\n"			@ Printable New Line Character
iterations:
    .word 0, 0, 0, 0, 0, 0  	@ Variables for Clock in order of: MM:SS:HH
