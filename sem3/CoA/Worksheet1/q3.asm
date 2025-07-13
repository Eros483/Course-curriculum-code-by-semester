.data 
	num1: .word 10 #choosing two numbers and initialising sum and differeence
	num2: .word 20
	sum: .word 0
	difference: .word 0
	
.text

main:
	lw $t0, num1
	lw $t1, num2
	lw $t2, sum
	lw $t3, difference #loading in all necessary values
	
	add $t2, $t0, $t1
	sub $t3, $t0, $t1 #carrying out necessary operations and inputting values into required variables
	
	sw $t2, sum
	sw $t3, difference #storing the values back
	
	li $v0, 10
	syscall #exiting the system