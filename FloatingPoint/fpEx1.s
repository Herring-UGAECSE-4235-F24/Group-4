@ fpEx1.s 
@ Property of Group 4 - Sam Brewster and Simline Gijo
@ Push: Logic Works on Paper - Test Later
@
@ Group assignment
@ This program calculates the area of a circle
@ use gdb info all-registers  or i all-r
@ Change the code to print the results to the monitor in correct format.
@ We will check in class.  Be ready to change the radius value and re-run


.text
.global main
 
main:
	vmov.f32	s0,#0.125		
	vmul.f32 	s0, s0, s0
	ldr		r2,=piNumber
	vldr		s1, [r2]
	vmul.f32	s0, s0, s1

_printConvert:
  	ldr 		r0, =outputline    	@ Load the String Format Location in R0
 	vcvt.f64.f32 	d0, s0 			@ Convert to a double
  	vmov 		r1, r2, d0		@ Move to be printed
    	bl 		printf			@ Print and wipe the Registers

	
_infiniteLoop:	
	b	_inifiteLoop

 _exit:
	mov r7, #1		@ Load the Exit Value
 	svc 0			@ Exit the Program

.data
piNumber: 
	.float 3.141593
inputline:
    	.asciz "Enter n:"
outputline:
    	.asciz "n! = %f"
	
