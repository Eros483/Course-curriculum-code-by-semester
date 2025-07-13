.data
	out_string: .asciiz "\nHello world\n" #so basically i defined a string that i can call later to use, so a object

.text

main:
	li $v0, 4 #load in command to print a string?
	la $a0, out_string #entering the adress of the string i wanna print into a0 to call later
	syscall
	
	li $v0, 10 #aka closing and exitting
	syscall
	
