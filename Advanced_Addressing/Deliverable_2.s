	.text
	.global main
main:	 adr	r2, lookup	@ point to lookup 
	mov 	r9, #3		@ choose index for r9
	ldrb	r10, [r2, r9]	@ r10 = entry of lookup table index by r9
_stop:
	mov	r7,#1
	svc	0

lookup: .byte	3, 6, 11, 18, 27, 38, 51, 66, 83, 102 @ list of outputs for the function when x = r9
