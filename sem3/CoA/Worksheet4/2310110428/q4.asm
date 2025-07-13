.data
prompt: .asciiz "Enter the number of Fibonacci numbers to generate: "
result: .asciiz "Fibonacci sequence: "

.text
.globl main

main:
    li $v0, 4
    la $a0, prompt
    syscall
    
    li $v0, 5
    syscall
    move $t0, $v0
    
    li $v0, 4
    la $a0, result
    syscall

    li $t1, 0
    li $t2, 0
    li $t3, 1
    
printFib:
    beq $t1, $t0, end
    
    move $a0, $t2
    li $v0, 1
    syscall
    
    li $v0, 11
    li $a0, 32
    syscall
    
    move $a0, $t2
    move $t2, $t3
    add $t3, $a0, $t2
    
    addi $t1, $t1, 1
    j printFib

end:
    li $v0, 10
    syscall
