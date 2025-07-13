.data
	sentence: .asciiz "Factorial of 5 is: "
	
.text

main:
	li $t0, 5
	li $t1, 1
loopStart:
	beq $t0, 0, return1
	beq $t0, 1, return1
	mul $t1, $t1, $t0
	sub $t0, $t0, 1
	j loopStart 
	
return1:
	li $v0, 4
	la $a0, sentence
	syscall
	
	move $a0, $t1
	li $v0, 1
	syscall
	
	li $v0, 10
	syscall