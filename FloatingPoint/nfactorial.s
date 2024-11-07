@ nfactorial.s
@ Property of Group 4
@
@ Push Name: IT WORKS! - Fixed Zero Edge Case

.text
.global main
 
main:
	push {r0-r4, lr}
	ldr 	r0, =inputline  @ Load the Print Input String Location in R0
	bl 	printf	  	@ Print and wipe the Registers

	ldr r0, =format		@ Prepare what to read
	ldr r1, =inputINT	@ Prepare where to store it
	bl scanf		@ Poll the User

_initLogic: 
	ldr r1, =inputINT	@ Load the address of the =input variable
	vldr.f32 s15, [r1]	@ Read the data stored in the input variable into r1 
	
 	vmov.f32  s14, s15      @ Create a duplicate of s15
	
	ldr r2, =floatOne
	vldr.f32  s13, [r2]	@ Fill a register with 1
	
	ldr r2, =floatZero
	vldr.f32  s12, [r2]	@ Fill a register with 0
	
isItZero:
	vcmp.f32   s15, #0x00000000	@ THIS IS THE ONLY LINE NOT WORKING RN IM SO MAD
	vmrs       r10, FPSCR
	and	   r11, r10, #0x40000000
	cmp        r11, #0x40000000
  	beq        _print 		@ Exit if s14 equals 0
	
_topOfLoop:
  	vsub.f32  s14, s14, s13 	@ Subtract 1 from the counter
   	vcmp.f32  s14, #0x00000000	@ THIS IS THE ONLY LINE NOT WORKING RN IM SO MAD
	vmrs       r10, FPSCR
	and	   r11, r10, #0x40000000
	cmp        r11, #0x40000000
  	beq        _storeVar 		@ Exit if s14 equals 0
  	vmul.f32  s15, s15, s14 	@ if s14 != 0 then s15 = s15 * (s15 - 1)
 	b         _topOfLoop  		@ Back to the top of the loop

_storeVar:
	ldr 	  r0, =outputline 	@ Load the String Format Location in R0
  	ldr   	  r1, =inputINT  	@ Store the address of the float variable
  	vstr.f32  s15, [r1]		@ Store the Current Value in the variable
	
_print:
 	vldr.f32 s15, [r1]	 	@ Read the data stored in the input variable into r1 
 	vcvt.f64.f32 d7, s15 	@ Convert to a double
	ldr 	r0, =outputline @ Load the String Format Location in R0

	vmov 	r2, r3, d7	@ Mov to be printed
	bl 	printf			@ Print and wipe the Registers
	
_exit:
	pop {r0-r4, pc}
	mov r7, #1		@ Load the Exit Value
 	svc 0			@ Exit the Program

.data
floatZero:
	.float 0.000
floatOne:
	.float 1.000
inputINT:
	.float 0.000
inputline:
	.string "Enter n: "
format:
	.string "%f"
outputline:
	.string "You typed in: %f\n"
