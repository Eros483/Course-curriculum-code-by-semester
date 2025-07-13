.data
	sentence: .asciiz "Sum of even numbers from 1 to 10: "
	
.text

main:
	li $t0, 0
	li $t1, 1
	li $t2, 2
	
loopStart:
	bgt $t1, 10, loopEnd
	
	div  $t1, $t2
	mfhi $t3
	beq $t3, 0, loopOperation
	
	addi $t1, $t1, 1
	j loopStart

loopOperation:
	add $t0, $t0, $t1
	
	addi $t1, $t1, 1
	j loopStart
	
loopEnd:
	li $v0, 4
	la $a0, sentence
	syscall
	
	move $a0, $t0
	li $v0, 1
	syscall
	
	li $v0, 10
	syscall
	