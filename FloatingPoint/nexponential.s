@ nexponential.s
@ Property of Group 4
@
@ Push Name: IT WORKS - Both X and N Zero Edge Cases Covered

.text
.global main
 
main:
	push {r0-r4, lr}

_printInputLineX:
  	ldr   r0, =inputlineX    	@ Load the Print Input String Location in R0
  	bl 	  printf				@ Print and wipe the Registers

_readX:
	
	ldr r0, =format			@ Prepare what to read
	ldr r1, =inputXFLOAT	@ Prepare where to store it
	bl scanf				@ Poll the User

_printOutputLineX:
 
	ldr 	r1, =inputXFLOAT		@ Load Address of the Variables into R1	
	vldr.f32 s14, [r1]	 	@ Read the data stored in the input variable into r1 

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

_printInputLineN:
  	ldr   r0, =inputlineN    	@ Load the Print Input String Location in R0
  	bl 	  printf				@ Print and wipe the Registers

_readN:
	
	ldr r0, =format			@ Prepare what to read
	ldr r1, =inputNFLOAT	@ Prepare where to store it
	bl scanf				@ Poll the User

_printOutputLineN:
 
	ldr 	r1, =inputNFLOAT		@ Load Address of the Variables into R1	
	vldr.f32 s15, [r1]	 	@ Read the data stored in the input variable into r1 

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

_initLogic:
	vmov.f32  s13, s14      @ Create a duplicate of X
	
	ldr r2, =floatZero
	vldr.f32  s11, [r2]	@ Fill a register with 0
	
	ldr r2, =floatOne
	vldr.f32  s12, [r2]	@ Fill a register with 1
	
_isNZero:
	vcmp.f32   s15, #0x00000000	@ N
	vmrs       r10, FPSCR
	and	       r11, r10, #0x40000000
	cmp        r11, #0x40000000
  	bne        _isXZero 		@ Exit if s14 equals 0
  	ldr r1, =outputFLOAT
	vstr.f32  s12, [r1]	@ Fill a register with 1
  	b 			_print

_isXZero:
	vcmp.f32   s14, #0x00000000	@ X
	vmrs       r10, FPSCR
	and	       r11, r10, #0x40000000
	cmp        r11, #0x40000000
  	bne        _topOfLoop 		@ Exit if s14 equals 0
  	ldr r1,    =outputFLOAT
	vstr.f32   s11, [r1]	@ Fill a register with 0
  	b 		   _print

_topOfLoop:
  	vsub.f32  s15, s15, s12 	@ Subtract 1 from the N
   	vcmp.f32  s15, #0x00000000	@ THIS IS THE ONLY LINE NOT WORKING RN IM SO MAD
	vmrs      r10, FPSCR
	and	   	  r11, r10, #0x40000000
	cmp       r11, #0x40000000
  	beq       _storeVar 		@ Exit if s14 equals 0
  	vmul.f32  s13, s14, s13 	@ if s14 != 0 then s15 = s15 * (s15 - 1)
 	b         _topOfLoop  		@ Back to the top of the loop
	
_storeVar:
  	ldr   	  r1, =outputFLOAT  	@ Store the address of the float variable
  	vstr.f32  s13, [r1]		@ Store the Current Value in the variable
  
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  
_print:
 	vldr.f32 s13, [r1]	 	@ Read the data stored in the input variable into r1 
 	vcvt.f64.f32 d5, s13 	@ Convert to a double
	ldr 	r0, =outputline @ Load the String Format Location in R0

	vmov 	r2, r3, d5	@ Mov to be printed
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
inputXFLOAT:
    .float 0
inputNFLOAT:
    .float 0
outputFLOAT:
    .float 0
inputlineX:
    .string "Calculate x^n.  Enter x:"
inputlineN:
    .string "Enter n:"
outputline:
    .string "x^n = %f\n"
format:
	.string "%f"
