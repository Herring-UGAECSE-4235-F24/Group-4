@ fpEx1.s 
@ Property of Group 4 - Sam Brewster and Simline Gijo
@ Push: IT WORKS! - Successfully Prints by using r2 + r3, d7, and s14 + s15
@
@ Group assignment
@ This program calculates the area of a circle
@ use gdb info all-registers  or i all-r
@ Change the code to print the results to the monitor in correct format.
@ We will check in class.  Be ready to change the radius value and re-run


.text
.global main
 
main:
	push {r0-r4, lr}
	
	vmov.f32	s14,#0.125		
	vmul.f32 	s14, s14, s14
	ldr		r2,=piNumber
	vldr.f32	s15, [r2]
	vmul.f32	s14, s14, s15

_printConvert:

  	ldr 			r0, =outputline    	@ Load the String Format Location in R0
 	vcvt.f64.f32 		d7, s14			@ Convert to a double
  	vmov			r2, r3, d7		@ Move to be printed
	bl 			printf			@ Print and wipe the Registers
	
_infiniteLoop:	
	@b	_infiniteLoop

 _exit:
	pop {r0-r4, lr}
	mov r7, #1		@ Load the Exit Value
 	svc 0			@ Exit the Program

.data
piNumber: 
	.float 3.141593
outputline:
    	.string "Area = %f\n"
