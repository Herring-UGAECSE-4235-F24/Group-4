@ to compile, use gcc -o stopwatch stopwatch.s -lc
	.text
    .global main
    .include "./E4235_KYBdeblock.s"

main:
    b _Deblock

_Deblock:  
    mov r0, #1
    bl  E4235_KYBdeblock
    b _start

_Read:
	mov r0, #0	@ file descriptor for stdin
	mov r2, #1	@ allocates bytes to read
	mov r7, #3	@ svc read
	ldr r1, =input
	str r0, [r1]	@ reset input
	svc 0
	ldrb r1, [r1]	@ read byte in input
	bx lr
       
_Check:
	cmp r1, #'r'    @ blocking
	beq _exit
	cmp r1, #'l'    @ deblocking
	beq _lap
    cmp r1, #'s'    @ quit
    beq _exit
    cmp r1, #'c'    @ quit
    beq _exit
    cmp r1, #'q'    @ quit
    beq _exit
	bx   lr
      
_lap:
    cmp r6, #1
	BEQ _lap1
	mov r6, #1		@ move a 1 into the lap register
	bx   lr
_lap1:
	mov r6, #0
	bx lr
        
_start:	
	LDR 	R4, =iterations		@ Loads address of variables
	MOV 	R3, #0			
	STR 	R3, [R4, #4]		@ Sets Minutes Variable to Zero

l1:	LDR	R3, =8900000		@ R3 = 8,900,000 
l2:	SUBS	R3, R3, #1		@ R3 = R3 – 1, decrement R1 
	BNE	l2			@ repeat it until R3 = 0 
	
	bl _Read
	bl _Check
   
@ The _h1 function increments the centisecond variable until it reaches 10 and then branches to _h2.
_h1:
        LDR 	R3, =iterations		@ Loads the Address of the Variables into R1
        LDR 	R3, [R3, #20]		@ Loads the Centisecond Variable into R1
        ADDS 	R3, #0x1		@ Increments R1
        LDR 	R4, =iterations		
        STR 	R3, [R4, #20]           @ Stores the incremented value of R1 into the Centiseconds Variable
        
		CMP 	R3, #10			@ Compares to see if R1 and  10 are equal
        BEQ 	_h2			@ If so, branches to _h2.
        
        cmp r6, #1
		BEQ l1
        B	l3			@ Prints 
        
@ The _h2 function resets the centisecond variable, increments the decisecond variable until it reaches 10, and then branches to _s1.
_h2:
	MOV 	R3, #0			
	STR 	R3, [R4, #20]		@ Stores the value Zero in the Centiseconds Variable
	
	cmp r6, #1
	BEQ l1
	B	l3       
	

l3: 
@ print time

    LDR 	R0, =string         	
    LDR 	R1, =iterations		
    LDR 	R1, [R1, #20]           @ Load the centiseconds variable
    BL 	printf
    
	LDR 	R0, =newline         	@ Load the newline character in R0
    BL 	printf
    
	B 	l1


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
