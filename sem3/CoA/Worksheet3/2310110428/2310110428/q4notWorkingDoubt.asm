.data
	promptInteger: .asciiz "Enter desired integer\n"
	spaceForBinary: .space 33 #32 bits + one bit for signed?
	
.text

main:
	li $v0, 4
	la $a0, promptInteger
	syscall
	
	li $v0, 5
	syscall
	move $t0, $v0
	
	#t0 contains integer
	#t1 contains counter for bits assigned assuming fits in 32
	#t2 stores individual lsb's
	#t4 contains counter for bits for reversing the given string from rear
	#t5 is temp variable for assisting in swap
	#t6 contains counter for bits for reveersing the given string from front
	#t7 always 32
	
	li $t7, 32
	li $t4, 32
	li $t1, 32 #counter for bits
	la $a0, spaceForBinary
	la $a1, spaceForBinary
	la $a2, spaceForBinary
	
	bge $t0, $0, conversion #aka positive integer jumps to conversion to string

negative:
	#negative integer first converted to 2s complement and then conversion
	not $t0, $t0
	addi $t0, $t0, 1
	
conversion:
	ble $t1,$0, reverseString
	andi $t2, $t0, 1
	beq $t2, 1, bitIsOne
	beq $t2, 0, bitIsZero

bitIsOne:
	addi $t2, $t2, 48
	sb $t2, 0($a0)
	addi $a0, $a0, 1
	sub $t1, $t1, 1
	srl $t0, $t0, 1
	j conversion
	
bitIsZero:
	addi $t2, $t2, 48
	sb $t2, 0($a0)
	addi $a0, $a0, 1
	sub $t1, $t1, 1
	srl $t0, $t0, 1
	j conversion

addingNullTerminator:
	li $t3, 0
	sb $t3, 0($a0)


reversing:
	la $a1, spaceForBinary
	li $t6, 31
	la $a2, spaceForBinary
	add $a2, $a2, $t6
	
reverseString:
	ble $t4, $0, termination
	lb $t5, 0($a1)
	lb $t6, 0($a2)
	
	sb $t5, 0($a2)
	sb $t6, 0($a1)
	
	addi $a1, $a1, 1
	subi $a2, $a2, 1
	sub $t4, $t4, 2
	j reverseString
	
	
termination:
	la $a0, spaceForBinary
	li $v0, 4
	syscall
	
	li $v0, 10
	syscall