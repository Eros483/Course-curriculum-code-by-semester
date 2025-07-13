.data
	inputNum1Prompt: .asciiz "Please enter first integer: "
	inputNum2Prompt: .asciiz "Please enter second integer: "
	nextLine: .asciiz "\n"
	
	outputProductPrompt: .asciiz "Product of two numbers is: "
	outputSumPrompt: .asciiz "Sum of two numbers is: "
	outputDifferencePrompt: .asciiz "Difference of two numbers is: "
	
.text
.globl main

main:
	li $v0, 4
	la $a0, inputNum1Prompt
	syscall
	
	li $v0, 5
	syscall
	move $t0, $v0 # Store first input in $t0

	li $v0, 4
	la $a0, inputNum2Prompt
	syscall
	
	li $v0, 5
	syscall
	move $t1, $v0 # Store second input in $t1

	move $a0, $t0
	move $a1, $t1
	
	jal funcADD
	sw $v0, 0($sp)
	
	jal funcMUL
	sw $v0, -4($sp)
	
	jal funcSUB
	sw $v0, -8($sp)
	
	li $v0, 4
	la $a0, outputProductPrompt
	syscall
	
	lw $a0, -4($sp)
	li $v0, 1
	syscall
	
	li $v0, 4
	la $a0, nextLine
	syscall

	li $v0, 4
	la $a0, outputSumPrompt
	syscall
	
	lw $a0, 0($sp)
	li $v0, 1
	syscall
	
	li $v0, 4
	la $a0, nextLine
	syscall
	
	li $v0, 4
	la $a0, outputDifferencePrompt
	syscall
	
	lw $a0, -8($sp)
	li $v0, 1
	syscall

	li $v0, 4
	la $a0, nextLine
	syscall

	li $v0, 10
	syscall
			
funcADD:
	add $v0, $a0, $a1
	jr $ra
	
funcMUL:
	mul $v0, $a0, $a1
	jr $ra

funcSUB:
	sub $v0, $a0, $a1
	jr $ra
