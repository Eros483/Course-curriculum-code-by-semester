.data
	promptRows: .asciiz "Enter number of rows needed: "
	stars: .asciiz "*"
	space: .asciiz " "
	nextLine: .asciiz "\n"
	
.text

main:
	li $v0, 4
	la $a0, promptRows
	syscall
	
	li $v0, 5
	syscall
	move $t0, $v0
	
	li $t1, 0
	j Outerloop
	
Outerloop:
	addi $t1, $t1, 1
	bgt $t1, $t0, exitOuterLoop
	
	sub $t3, $t0, $t1
	j spacePrinter
	
spacePrinter:
	blez $t3, OuterloopCont
	
	li $v0, 4
	la $a0, space
	syscall
	
	subi $t3, $t3, 1
	j spacePrinter
	
OuterloopCont:
	add $t4, $t1, $t1
	subi $t4, $t4, 1
	
	j innerLoop
	
innerLoop:
	blez $t4, innerLoopExit
	
	li $v0, 4
	la $a0, stars
	syscall
	
	subi $t4, $t4, 1
	j innerLoop
	
innerLoopExit:
	li $v0, 4
	la $a0, nextLine
	syscall
	
	j Outerloop
	
exitOuterLoop:
	li $v0, 10
	syscall
