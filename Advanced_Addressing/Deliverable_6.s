	.text
	.global main
	.extern printf
	
	@ write Enter angle if within range, so loop
	@ implement the 0 print case and the 1 print case 
	@ both sin and cos are off by one value??
	
main: 	
		ldr 	r0, =prompt
		bl 		printf
		
		ldr 	r0, =inputform
		ldr 	r1, =input
		bl 		scanf

checkValid:
		ldr 	r1, =input  
		ldr 	r1, [r1]   
		
		cmp		r1, #90
		beq print_cos_func1
		
		and 	r3, r1, #3
		cmp 	r3, #1
		beq		_end
		cmp 	r3, #2
		beq		_end
		cmp 	r3, #3
		beq		_end

print_cos_func1:
		ldr 	r0, =print_cos1  
		ldr 	r1, =input  
		ldr 	r1, [r1]   	
		bl   	printf

grab_cos_value:
		ldr 	r1, =input  
		ldr 	r1, [r1] 
		ldr 	r2, =cos		@ Grab the Address of Cos
		ldr 	r10, [r2, r1]	@ Grab the Cos value at the location

print_cos_func2:	
		mov 	r1, r10
		cmp 	r10, #1
		beq		print_1_cos
		cmp 	r10, #100
		bgt		print_cos_gt
		ldr 	r0, =print_cosLT 
		bl   	printf
		b 		print_sin_func1

print_1_cos:
		ldr 	r0, =print_1 
		bl   	printf
		b		print_sin_func1

print_cos_gt:
		ldr 	r0, =print_cosGT 
		bl   	printf

print_sin_func1:	
		ldr 	r0, =print_sin1  
		ldr 	r1, =input  
		ldr 	r1, [r1]     	
		bl   	printf
		
grab_sin_value:
		ldr 	r1, =input  
		ldr 	r1, [r1]
		cmp 	r1, #0
		beq		print_0_sin 
		cmp		r1, #90
		bne 	hardCode
		mov 	r1, #92
hardCode:
		ldr 	r2, =sin		@ Grab the Address of Sin
		ldr 	r10, [r2, r1]	@ Grab the Sin value at the location
		
print_sin_func2:	
		mov 	r1, r10
		cmp 	r10, #1
		beq		print_1_sin
		cmp 	r10, #100
		bgt		print_sin_gt
		ldr 	r0, =print_sinLT 
		bl   	printf
		b 		_stop

print_0_sin:
		ldr 	r0, =print_0 
		bl   	printf
		b		_stop	
		
print_1_sin:
		ldr 	r0, =print_1 
		bl   	printf
		b		_stop		
		
print_sin_gt:
		ldr 	r0, =print_sinGT 
		bl   	printf
		b		_stop
		
_stop:
		ldr		r0, =newline
		bl		printf
		
		b 	main
_end:		
		mov		r7,#1
		svc		0																																																																		

																																																																																								
sin:
	.word 0000, 70, 139, 208, 276, 342, 407, 470, 530, 588, 643, 695, 743, 788, 829, 866, 899, 927, 951, 970, 985, 995, 999, 1
cos:										
	.word 1, 998, 990, 978, 961, 940, 914, 883, 848, 809, 766, 719, 669, 616, 559, 500, 438, 375, 309, 242, 174, 105, 35, 0


.data
input:
	.word 0
		
inputform:
	.asciz "%i"

prompt: 
	.asciz "Enter Angle:"
		
print_cos1:
    .asciz "Cos of %i"			@ Printable Number Format

print_sin1:
    .asciz " and Sine of %i"	@ Printable Number Format

print_cosLT:
	.asciz " = 0.0%i"
		
print_cosGT:
	.asciz " = 0.%i"
		
print_sinLT:
	.asciz " = 0.0%i"
		
print_sinGT:
	.asciz " = 0.%i"
		
print_1:
	.asciz " = 1.000"
	
print_0:
	.asciz " = 0.000"
		
newline:
	.asciz "\n"
