.data
	prompt: .asciiz "Enter required integer: "
	ZeroHero: .asciiz "Integer is zero"
	Positive: .asciiz "Integer is positive"
	Negative: .asciiz "Integer is negative"
	
.text

main:
	li $v0, 4
	la $a0, prompt
	syscall
	
	li $v0, 5
	syscall
	move $t0, $v0
	
	bgt $t0, 0, isPositive #determines if number is positive
	blt $t0, 0, isNegative #determines if number is negative
	
	li $v0, 4
	la $a0, ZeroHero #as if its not positive or negative, it must be zero
	syscall
	j endProgram
	
isPositive:
	li $v0, 4
	la $a0, Positive
	syscall
	j endProgram
	
isNegative:
	li $v0, 4
	la $a0, Negative
	syscall
	j endProgram
	
endProgram:
	li $v0, 10
	syscall

	