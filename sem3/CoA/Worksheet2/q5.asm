.data
	sentence: .asciiz "Fibonacci Series up to 10 terms: "
	space: .asciiz " "
	
.text

main:
	li $t0, 10
	li $t1, 0 #first
	li $t2, 1 #second
	li $t4, 0 #i
	
loopStart:
	bgt $t4, $t0, loopEnd
	
	ble $t4, 1, printNext
	add $t3, $t1, $t2
	move $t1, $t2
	move $t2, $t3
	
	move $a0, $t3
	li $v0, 1
	syscall
	
	li $v0, 4
	la $a0, space
	syscall
	
	addi $t4, $t4, 1
	j loopStart
	
printNext:
	move $a0, $t4
	li $v0, 1
	syscall
	
	li $v0, 4
	la $a0, space
	syscall
	
	addi $t4, $t4, 1
	j loopStart
	
loopEnd:
	li $v0, 10
	syscall