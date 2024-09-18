@ to compile, use gcc -o stopwatch stopwatch.s -lc
	.text
    .global main
    .include "./E4235_KYBdeblock.s"

main:
    b _Deblock

_Deblock:  
    mov r0, #1
    bl  E4235_KYBdeblock
    b _Read
    
_Scan:
	ldr r0, =inputform
    ldr r1, =input
    bl scanf
    ldr r1, =input
    ldr r1, [r1]

_Read:
	mov r0, #0	@ file descriptor for stdin
	mov r2, #1	@ allocates bytes to read
	mov r7, #3	@ svc read
	ldr r1, =input
	str r0, [r1]	@ reset input
	svc 0
	ldrb r1, [r1]	@ read byte in input

_Check:
	cmp r1, #'b'    @ blocking
	beq _Print
	cmp r1, #'d'    @ deblocking
	beq _Print
    cmp r1, #'q'    @ quit
    beq _Print
	b   _Read

_Print:
	ldr r0, =string @Std Out
	bl printf
	
	LDR 	R0, =newline         	@ Load the newline character in R0
    BL 	printf
	
    @ldr r1, =output
    @mov r2, #1 @length of out string
    @mov r7, #4 @write sys call
    @svc 0
    b _Scan

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
