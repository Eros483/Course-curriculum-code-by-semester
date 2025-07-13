.data
matrixA: .space 36
matrixB: .space 36
matrixC: .space 36

.text
main:
    jal read_matrix
    jal read_matrixB
    jal multiply_matrix
    jal print_matrix
    li $v0, 10
    syscall

read_matrix:
    li $t0, 0
    li $t1, 0
loop_read:
    beq $t0, 3, end_read
    beq $t1, 3, next_row_read
    la $t2, matrixA
    mul $t3, $t0, 12
    add $t3, $t3, $t1
    mul $t3, $t3, 4
    add $t3, $t2, $t3
    li $v0, 5
    syscall
    move $t4, $v0
    sw $t4, 0($t3)
    addi $t1, $t1, 1
    j loop_read
next_row_read:
    li $t1, 0
    addi $t0, $t0, 1
    j loop_read
end_read:
    jr $ra

read_matrixB:
    li $t0, 0
    li $t1, 0
loop_readB:
    beq $t0, 3, end_readB
    beq $t1, 3, next_row_readB
    la $t2, matrixB
    mul $t3, $t0, 12
    add $t3, $t3, $t1
    mul $t3, $t3, 4
    add $t3, $t2, $t3
    li $v0, 5
    syscall
    move $t4, $v0
    sw $t4, 0($t3)
    addi $t1, $t1, 1
    j loop_readB
next_row_readB:
    li $t1, 0
    addi $t0, $t0, 1
    j loop_readB
end_readB:
    jr $ra

multiply_matrix:
    li $t0, 0
    li $t1, 0
    li $t2, 0
loop_multiply:
    beq $t0, 3, end_multiply
    beq $t1, 3, next_row_multiply
    beq $t2, 3, next_column_multiply
    la $t3, matrixA
    mul $t4, $t0, 12
    add $t4, $t4, $t2
    mul $t4, $t4, 4
    add $t4, $t3, $t4
    lw $t5, 0($t4)
    la $t3, matrixB
    mul $t4, $t2, 12
    add $t4, $t4, $t1
    mul $t4, $t4, 4
    add $t4, $t3, $t4
    lw $t6, 0($t4)
    mul $t7, $t5, $t6
    la $t3, matrixC
    mul $t4, $t0, 12
    add $t4, $t4, $t1
    mul $t4, $t4, 4
    add $t4, $t3, $t4
    lw $t8, 0($t4)
    add $t8, $t8, $t7
    sw $t8, 0($t4)
    addi $t2, $t2, 1
    j loop_multiply
next_column_multiply:
    li $t2, 0
    addi $t1, $t1, 1
    j loop_multiply
next_row_multiply:
    li $t1, 0
    addi $t0, $t0, 1
    j loop_multiply
end_multiply:
    jr $ra

print_matrix:
    li $t0, 0
    li $t1, 0
loop_print:
    beq $t0, 3, end_print
    beq $t1, 3, next_row_print
    la $t2, matrixC
    mul $t3, $t0, 12
    add $t3, $t3, $t1
    mul $t3, $t3, 4
    add $t3, $t2, $t3
    lw $t4, 0($t3)
    li $v0, 1
    move $a0, $t4
    syscall
    li $v0, 11
    li $a0, 32
    syscall
    addi $t1, $t1, 1
    j loop_print
next_row_print:
    li $t1, 0
    addi $t0, $t0, 1
    li $v0, 11
    li $a0, 10
    syscall
    j loop_print
end_print:
    jr $ra
