.data
	number: .word -1
	flag: .word 0
	
.text

main:
	lw $t0, number #enter number to be checked here
	lw $t1, flag
	
	#first we check if positive
	bgt $t0, 0, isPositive
	
	#then we check if zero
	beq $t0, 0, isZero
	
	#if neither positive nor zero its negative
	li $t1, -1
	j endProgram #defining a end program
	
isPositive:
	li $t1, 1 #setting desired value for positive integer
	j endProgram
	
isZero:
	li $t1, 0 #setting desired value for a zero
	j endProgram
	
endProgram:
	sw $t1, flag
	li $v0, 10
	syscall #exiting