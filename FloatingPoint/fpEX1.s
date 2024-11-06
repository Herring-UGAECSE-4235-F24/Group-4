@ Group assignment
@ This program calculates the area of a circle
@ use gdb info all-registers  or i all-r
@ Change the code to print the results to the monitor in correct format.
@ We will check in class.  Be ready to change the radius value and re-run


	.text
	.global _start
_start:
	vmov.f32	s0,#0.125
	vmul.f32 	s0, s0, s0
	ldr	r2,=piNumber
	vldr		s1, [r2]
	vmul.f32	s0, s0, s1
	
here:	b	here

piNumber: .float 3.141593
