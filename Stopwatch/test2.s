@ to compile, use gcc -o stopwatch stopwatch.s -lc
	.text
    .global main
    .include "./E4235_KYBdeblock.s"

main:
    b _Deblock

_Deblock:  
    mov r0, #1
    bl  E4235_KYBdeblock
    b _Scan
    
_Scan:
	ldr r0, = inputform
    ldr r1, =input
    bl scanf
    ldr r1, =input

    ldr r1, [r1]

_Print:
	mov r0, #1 @Std Out
    ldr r1, =output
    mov r2, #5 @length of out string
    mov r7, #4 @write sys call
    svc 0
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
