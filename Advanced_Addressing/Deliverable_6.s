	.text
	.global main
	.extern printf
	
	@ write Enter angle if within range, so loop
	@ implement the 0 print case and the 1 print case 
	@ both sin and cos are off by one value??
	
main: 	
		ldr 	r0, =prompt		@ Load Address of "Enter Angle"
		bl 		printf		@ Print
		
		ldr 	r0, =inputform		@ Load integer format Scanf
		ldr 	r1, =input		@ Load Variable Location for Scanf
		bl 		scanf		@ Call Scanf

checkValid:
		ldr 	r1, =input  		@ Grab the location of the scanned value
		ldr 	r1, [r1]   		@ Grab the scanned value
		
		cmp		r1, #90		@ Check if the read number is 90
		beq print_cos_func1		@ Branch to main logic
		
		and 	r3, r1, #3		@ Following block checks if the result is anything but mod 4 = 0
		cmp 	r3, #1
		beq		_end		@ Branches to end the program if not divisble by 4
		cmp 	r3, #2
		beq		_end
		cmp 	r3, #3
		beq		_end

print_cos_func1:
		ldr 	r0, =print_cos1  	@ Loads the format for printing Cos
		ldr 	r1, =input  		@ Grabs the Scanned Value
		ldr 	r1, [r1]   	
		bl   	printf			@ Prints

grab_cos_value:
		ldr 	r1, =input  		@ Grabs the Scanned Value
		ldr 	r1, [r1] 
		ldr 	r2, =cos		@ Grab the Address of Cos
		ldr 	r10, [r2, r1]		@ Grab the Cos value at the location

print_cos_func2:	
		mov 	r1, r10			
		cmp 	r10, #1			@ Check if the cos = 1
		beq		print_1_cos	@ go to print 1 for cos
		cmp 	r10, #100		
		bgt		print_cos_gt	@ Branches if the cos value is greater than .1
		ldr 	r0, =print_cosLT 	@ Inputs a special 2 digit print if less than .1
		bl   	printf			
		b 		print_sin_func1

print_1_cos:
		ldr 	r0, =print_1 		@ Load print format for 1
		bl   	printf
		b	print_sin_func1

print_cos_gt:
		ldr 	r0, =print_cosGT 	@ Load print format for when cos is greater than .1
		bl   	printf

print_sin_func1:	
		ldr 	r0, =print_sin1  	@ Load print format for when sin = 1
		ldr 	r1, =input  		
		ldr 	r1, [r1]     		@ Loads scanned value
		bl   	printf
		
grab_sin_value:
		ldr 	r1, =input  	
		ldr 	r1, [r1]		@ Loads scanned value
		cmp 	r1, #0			
		beq	print_0_sin 		@ Branches if the scanned value is 0
		cmp	r1, #90		
		bne 	hardCode		@ Branches if the case is not 90
		mov 	r1, #92			@ sets the data to 92 so it can properly access sin
hardCode:
		ldr 	r2, =sin		@ Grab the Address of Sin
		ldr 	r10, [r2, r1]		@ Grab the Sin value at the location
		
print_sin_func2:	
		mov 	r1, r10			
		cmp 	r10, #1			@ checks if sin = 1
		beq	print_1_sin		@ Branches if sin = 1
		cmp 	r10, #100		@ checks if sin is greater than .1
		bgt	print_sin_gt		@ branches if sin is greater than .1
		ldr 	r0, =print_sinLT 	@ loads a special two digit print
		bl   	printf			
		b 		_stop		@ branch to loop again

print_0_sin:
		ldr 	r0, =print_0 		@ loads a special 0 print case
		bl   	printf
		b		_stop		@ branch to loop again
		
print_1_sin:
		ldr 	r0, =print_1 		@ loads a special 1 print case
		bl   	printf
		b		_stop		@ branch to loop again
		
print_sin_gt:
		ldr 	r0, =print_sinGT 	@ normal print case if sin is greater than .1
		bl   	printf
		b		_stop		@ branch to loop again
		
_stop:
		ldr		r0, =newline	@ prints newline char
		bl		printf		
		
		b 	main			@ reloops
_end:					
		mov		r7,#1		
		svc		0		@ kills the program																																																														

																																																																																								
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
    .asciz "Cos of %i"			

print_sin1:
    .asciz " and Sine of %i"

print_cosLT:
	.asciz " = 0.0%i"			@ For numbers less than .1
		
print_cosGT:
	.asciz " = 0.%i"			@ For numbers greater than .1
		
print_sinLT:
	.asciz " = 0.0%i"			@ For numbers less than .1
		
print_sinGT:
	.asciz " = 0.%i" 			@ For numbers greater than .1
		
print_1:
	.asciz " = 1.000"
	
print_0:
	.asciz " = 0.000"
		
newline:
	.asciz "\n"
