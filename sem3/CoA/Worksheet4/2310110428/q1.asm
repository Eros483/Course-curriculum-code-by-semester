.data
    word1: .ascii "Arnab"
    word2: .asciiz "Arnaba"
    promptIf1Greater2: .asciiz "Word 1 is greater\n"
    promptIf1Lesser2: .asciiz "Word 2 is greater\n"
    promptIfEqual: .asciiz "The words are same\n"
    
.text

main:
    la $t0, word1
    la $t1, word2
    
compare:
    lb $a0, 0($t0)
    lb $a1, 0($t1)
    
    beq $a0, $a1, byteEqual
    bgt $a0, $a1, OneGreaterTwo
    blt $a0, $a1, OneLesserTwo
    
byteEqual:
    beq $a0, $zero, wordEqual
    addi $t0, $t0, 1
    addi $t1, $t1, 1
    j compare
    
OneGreaterTwo:
    li $v0, 4
    la $a0, promptIf1Greater2
    syscall
    j termination
    
OneLesserTwo:
    li $v0, 4
    la $a0, promptIf1Lesser2
    syscall
    j termination
    
wordEqual:
    li $v0, 4
    la $a0, promptIfEqual
    syscall
    j termination
    
termination:
    li $v0, 10
    syscall
