.data
	num1: .word 10 #choosing two numbers
	num2: .word 5
	
.text

main:
	lw $t0, num1 #loading in two numbers
	lw $t1, num2
	
	sub $t0, $t0, $t1
	add $t1, $t1, $t0 #basic arithmetic for swapping integers
	sub $t0, $t1, $t0
	
	sw $t0, num1 #storing the values back
	sw $t1, num2
	
	li $v0, 10
	syscall #exiting and closing the system