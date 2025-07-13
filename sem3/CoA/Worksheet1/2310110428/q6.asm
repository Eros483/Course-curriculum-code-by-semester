.data
	number: .word 0 #initialising variable
	
.text

main:
	li $t0, 25
	sw $t0, number
	
	lw $t1, number #carrying out necessary transfers
	
	li $v0, 10
	syscall #exiting the system