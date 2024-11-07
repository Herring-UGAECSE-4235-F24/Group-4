@ nexponential.s
@ Property of Group 4
@
@ Push Name: Reads and Prints X
@ 
@ 2) For x^n
@ Take input from the keyboard for x (0 and positive reals are okay) and for n (0 and small integers only).  "Calculate x^n.  Enter x:"  followed by "Enter n:"
@ Use f32 floating point to calculate the answer x^n and return answer to monitor.  "x^n = ...." (substitute the x and n values)

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

_printOutputLine:
 
	ldr 	r1, =inputXFLOAT		@ Load Address of the Variables into R1	
	vldr.f32 s15, [r1]	 	@ Read the data stored in the input variable into r1 
 	vcvt.f64.f32 d7, s15 	@ Convert to a double
	ldr 	r0, =outputline @ Load the String Format Location in R0

	vmov 	r2, r3, d7	@ Mov to be printed
	
	bl 	    printf			    @ Print and wipe the Registers

_exit:
	pop {r0-r4, pc}
	mov r7, #1		@ Load the Exit Value
 	svc 0			@ Exit the Program

.data
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
