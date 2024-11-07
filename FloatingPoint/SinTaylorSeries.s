@ THIS IS A GROUP PROJECT
@This is from the book "Modern Assembly Language Programming with the ARM Processor" 1st edition
@This is written as a subroutine call (note the last instruction).  You may need to make changes for a stand-alone program.
@This calculates sin(x) (assumes x is passed in S0) by summing the first six terms of the Taylor series.
@First, change the program with a valid value for x in S0.
@Show, this working with a photo of the output
@Second, add a keyboard input for the x value to load into s0 with result to monitor.  We will check this in class.
@We will check code on Github.  
@@@ ---------------------------------------------------------------

.text
.align 2
.global main

main:
	@push {lr}
	@ldr r1, =piNumber
	@vldr.f32 s0, [r1] @ move a valid value into s0
	vmov.f32 s0, #1.0
	vmov.f32 s2, #1.0

_sin_v_f: 
	@@ set runfast mode and rounding to nearest
	vmrs r1, fpscr 		@ get FPSCR contents in r1
	bic r2, r1, #(0b1111<<23)
	orr r2, r2, #(0b1100<<23)
	vmsr fpscr, r2 		@ store settings in FPSCR
	vmul.f32 s1,s0,s0 	@ s1 = x^2
	ldr r0,=ctab @ get address of coefficients
	vldmia r0!,{s16-s20} 	@ load all coefficients into Bank 2
	vmul.f32 s8,s0,s1 	@ s8 = x^3
	vmul.f32 s9,s8,s1 	@ s9 = x^5
	vmul.f32 s10,s9,s1 	@ s10 = x^7
	vmul.f32 s11,s10,s1 	@ s11 = x^9
	vmul.f32 s12,s11,s1 	@ s12 = x^11
 
@@ Set VFP for vector mode
	bic r2, r2, #(0b11111<<16) @ set rounding, stride to 1,
	orr r2, r2, #(0b00100<<16) @ and vector length to 5
	vmsr fpscr, r2 @ store settings in FPSCR
	vmul.f32 s24,s8,s16 @ VECTOR operation x^(2n+1) * coeff[n]
	vmsr fpscr, r1 @ restore original FPSCR

@@ Add terms in Bank 3 to the result in s0
	vadd.f32 s24,s24,s25
	vadd.f32 s26,s26,s27
	vadd.f32 s0,s0,s24
	vadd.f32 s26,s26,s28
	vadd.f32 s0,s0,s26
	@bx lr		@can also use bx lr
	
_printConvert:
  	ldr 			r0, =outputline1    	@ Load the String Format Location in R0
 	vcvt.f64.f32 	d7, s2			@ Convert to a double
  	vmov		r2, r3, d7		@ Move to be printed
	bl 			printf			@ Print and wipe the Registers	
	
	ldr 			r0, =outputline2    	@ Load the String Format Location in R0
 	vcvt.f64.f32 	d7, s0			@ Convert to a double
  	vmov		r2, r3, d7		@ Move to be printed
	bl 			printf			@ Print and wipe the Registers	

_exit:
	@pop {lr}
	mov r7, #1		@ Load the Exit Value
 	svc 0			@ Exit the Program

.data
.align 6 @ Align to cache
ctab: 
	.word 0xBE2AAAAB @ -1.666667e-01
	.word 0x3C088889 @ 8.333334e-03
	.word 0xB9500D01 @ -1.984127e-04
	.word 0x3638EF1D @ 2.755732e-06
	.word 0xB2D7322B @ -2.505211e-08
piNumber: 
	.float 3.141593
outputline1:
    .string "Sin of %f"
outputline2:
    .string " Equals = %f\n"
