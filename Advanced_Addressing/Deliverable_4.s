	.text
	.global main
main:	 adr	r2, lookup	@ point to lookup 
	mov 	r9, #3		@ choose index for r9
	mul 	r10, r9, r9	@ do x^2
	add	r10, r10, r9	@ first step of +2x
	add	r10, r10, r9	@ second step of +2x
	add 	r10, r10, #3	@ add 3
_stop:
	mov	r7,#1
	svc	0

lookup: .byte	3, 6, 11, 18, 27, 38, 51, 66, 83, 102 
