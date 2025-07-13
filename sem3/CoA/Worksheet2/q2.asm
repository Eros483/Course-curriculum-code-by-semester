.data
	promptNum1: .asciiz "Enter first number: "
	promptNum2: .asciiz "Enter second number: "
	promptOperator: .asciiz "Enter symbol of operation to be carried out: "
	nextLine: .asciiz "\n"
	result: .word 0
	
.text

main:
	lw $t3, result
	
	li $v0, 4
	la $a0, promptNum1
	syscall
	li $v0, 5
	syscall
	move $t0, $v0
	
	li $v0, 4
	la $a0, promptNum2
	syscall
	li $v0, 5
	syscall
	move $t1, $v0
	
	li $v0, 4
	la $a0, promptOperator
	syscall
	li $v0, 12
	syscall
	move $t2, $v0
	
	li $t4, 43
	beq $t2, $t4, Addition
	
	li $t4, 45
	beq $t2, $t4, Subtraction
	
	li $t4, 42
	beq $t2, $t4, Product
	
	li $t4, 47
	beq $t2, $t4, Division
	
Addition:
	li $v0, 4
	la $a0, nextLine
	syscall 
	add $t3, $t0, $t1
	move $a0, $t3
	li $v0, 1
	syscall
	j endProgram
	
Subtraction:
	li $v0, 4
	la $a0, nextLine
	syscall
	sub $t3, $t0, $t1
	move $a0, $t3
	li $v0, 1
	syscall
	j endProgram
	
Division:
	li $v0, 4
	la $a0, nextLine
	syscall
	div $t0, $t1
	mflo $t3
	move $a0, $t3
	li $v0, 1
	syscall
	j endProgram
	
Product:
	li $v0, 4
	la $a0, nextLine
	syscall
	mul $t3, $t0, $t1
	move $a0, $t3
	li $v0, 1
	syscall
	j endProgram
	
endProgram:
	li $v0, 10
	syscall