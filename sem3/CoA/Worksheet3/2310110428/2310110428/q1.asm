.data
	promptNum: .asciiz "Enter desired number: "
	promptShift: .asciiz "Enter number of digits to be shifted  by: "
	
.text

main:
	li $v0, 4
	la $a0, promptNum
	syscall
		
	li $v0, 5
	syscall
	move $t0, $v0
	
	li $v0, 4
	la $a0, promptShift
	syscall
	
	li $v0, 5
	syscall
	move $t1, $v0
	
	sllv $t2, $t0, $t1
	
	move $a0, $t2
	li $v0, 1
	syscall
	
	li $v0, 10
	syscall