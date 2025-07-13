Name: Arnab Mandal
Roll: 2310110428
snu id: am483

q1->
.data
	out_string: .asciiz "\nHello world\n" #so basically i defined a string that i can call later to use, so a object

.text

main:
	li $v0, 4 #load in command to print a string?
	la $a0, out_string #entering the adress of the string i wanna print into a0 to call later
	syscall
	
	li $v0, 10 #aka closing and exitting
	syscall
	

q2->
.data
	num1: .word 10 #choosing two numbers
	num2: .word 5
	
.text

main:
	lw $t0, num1 #loading in two numbers
	lw $t1, num2
	
	sub $t0, $t0, $t1
	add $t1, $t1, $t0 #basic arithmetic for swapping integers
	sub $t0, $t1, $t0
	
	sw $t0, num1 #storing the values back
	sw $t1, num2
	
	li $v0, 10
	syscall #exiting and closing the system

q3->
.data 
	num1: .word 10 #choosing two numbers and initialising sum and differeence
	num2: .word 20
	sum: .word 0
	difference: .word 0
	
.text

main:
	lw $t0, num1
	lw $t1, num2
	lw $t2, sum
	lw $t3, difference #loading in all necessary values
	
	add $t2, $t0, $t1
	sub $t3, $t0, $t1 #carrying out necessary operations and inputting values into required variables
	
	sw $t2, sum
	sw $t3, difference #storing the values back
	
	li $v0, 10
	syscall #exiting the system

q4->
.data
	number: .word -1
	flag: .word 0
	
.text

main:
	lw $t0, number #enter number to be checked here
	lw $t1, flag
	
	#first we check if positive
	bgt $t0, 0, isPositive
	
	#then we check if zero
	beq $t0, 0, isZero
	
	#if neither positive nor zero its negative
	li $t1, -1
	j endProgram #defining a end program
	
isPositive:
	li $t1, 1 #setting desired value for positive integer
	j endProgram
	
isZero:
	li $t1, 0 #setting desired value for a zero
	j endProgram
	
endProgram:
	sw $t1, flag
	li $v0, 10
	syscall #exiting

q5->
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
	

q6->
.data
	number: .word 0 #initialising variable
	
.text

main:
	li $t0, 25
	sw $t0, number
	
	lw $t1, number #carrying out necessary transfers
	
	li $v0, 10
	syscall #exiting the system

