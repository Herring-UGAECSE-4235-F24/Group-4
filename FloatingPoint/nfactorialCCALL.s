@ nfactorial.s
@ Property of Group 4
@
@ Push Name: Scanf and Printf Working with Floats

.text
.global nfactorialCCALL
 
nfactorialCCALL:
	push {lr}
	
	vmov.f32 s15, s0
	
_initLogic: 
 	vmov.f32  s14, s15      @ Create a duplicate of s15
	
	ldr r10, =floatOne
	vldr.f32  s13, [r10]	@ Fill a register with 1
	
	ldr r10, =floatZero
	vldr.f32  s12, [r10]	@ Fill a register with 0
	
_topOfLoop:
  	vsub.f32  s14, s14, s13 	
   	vcmp.f32  s14, #0x00000000	@ THIS IS THE ONLY LINE NOT WORKING RN IM SO MAD
	vmrs      r0, FPSCR
	and	      r1, r0, #0x40000000
	cmp       r1, #0x40000000
  	beq       _storeVar 		@ Exit if s14 equals 0
  	vmul.f32  s15, s15, s14 	@ if s14 != 0 then s15 = s15 * (s15 - 1)
 	b         _topOfLoop  		@ Back to the top of the loop
	
_storeVar:
 	vmov.f32  s0, s15      @ Create a duplicate of s15
	
_exit:
	pop {lr}
	bx lr

.data
floatZero:
	.float 0.000
floatOne:
	.float 1.000
inputINT:
	.float 0.000
