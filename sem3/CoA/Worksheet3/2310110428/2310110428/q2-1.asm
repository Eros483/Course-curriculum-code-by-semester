.data
	promptRows: .asciiz "Enter number of rows needed: "
	stars: .asciiz "*"
	nextLine: .asciiz "\n"
	
.text

main:
	li $v0, 4
	la $a0, promptRows
	syscall
	
	li $v0, 5
	syscall
	move $t0, $v0 #number of rows
	
	li $t1, 0
	j outerLoop
	
outerLoop:
	addi $t1, $t1, 1
	bgt $t1, $t0, outerLoopExit
	move $t2, $t1 #t2 number of stars in that row
	j innerLoop
	
innerLoop:
	ble $t2, 0, innerLoopExit
	
	li $v0, 4
	la $a0, stars
	syscall
	
	sub $t2, $t2, 1
	j innerLoop
	
innerLoopExit:
	li $v0, 4
	la $a0, nextLine
	syscall
	j outerLoop
	
outerLoopExit:
	li $v0, 10
	syscall
	
	