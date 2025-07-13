.data:
	num: .word 2 #enter word as needed
	flag: .word 0
	
	
	
.text: 

main:
	lw $t0, num
	lw $t1, flag
	rem $t2,$t0, 2
	beq $t2, 0, isEven
	
	#if not even, it must be odd
	li $t1, 0
	j endProgram
	
isEven:
	li $t1, 1
	j endProgram 
	
endProgram:
	sw $t1, flag
	li $v0, 10
	syscall #exiting statement
	