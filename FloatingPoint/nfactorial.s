@ nfactorial.s
@ Property of Group 4
@
@ Push Name: Scanf and Printf Working with Floats

.text
.global main
 
main:
	push {r0-r4, lr}
	ldr 	r0, =inputline  @ Load the Print Input String Location in R0
	bl 	printf	  	@ Print and wipe the Registers

	ldr r0, =format			@ Prepare what to read
	ldr r1, =inputINT		@ Prepare where to store it
	bl scanf				@ Poll the User

_initLogic: 
	
	ldr r0, =outputline    	@ Load the String Format Location in R0
	ldr r1, =inputINT		@ Load the address of the =input variable
	
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
inputINT:
    .float 0
inputline:
    .string "Enter n: "
format:
	.string "%f"
outputline:
    .string "You typed in: %f\n"
