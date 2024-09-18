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


        
_start:	
	LDR 	R2, =iterations		@ Loads address of variables
	MOV 	R1, #0			
	STR 	R1, [R2, #4]		@ Sets Minutes Variable to Zero

l1:	LDR	R1, =8900000		@ R1 = 8,900,000 
l2:	SUBS	R1, R1, #1		@ R1 = R1 – 1, decrement R1 
	BNE	l2			@ repeat it until R1 = 0 
	
	bl _Read
	
	@ print read in char
	ldr r0, =string @Std Out
	bl printf
	LDR 	R0, =newline @ Load the newline character in R0
    BL 	printf
    
    @ print time
    LDR 	R0, =string         	
    LDR 	R1, =iterations		
    LDR 	R1, [R1, #20]           @ Load the seconds variable
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
