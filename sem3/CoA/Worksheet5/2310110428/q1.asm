.data
fileName: .asciiz "Q1.txt"
buffer: .space 100
newFileName: .asciiz "A1.txt"
countString: .space 10

.text
main:
    li $v0, 13    # opening the file
    la $a0, fileName
    li $a1, 0
    li $a2, 0
    syscall
    move $s0, $v0
    
    li $v0, 14    # reading the file
    move $a0, $s0
    la $a1, buffer
    li $a2, 100
    syscall
    
    li $v0, 16
    move $a0, $s0
    syscall
    
    li $t0, 0
    la $a1, buffer
    
loop:
    lb $t1, 0($a1)
    beq $t1, $0, intToString
    addi $t0, $t0, 1
    addi $a1, $a1, 1
    j loop
        
intToString:
    li $t1, 10
    li $t5, 0  # counter for countString index
    
convertLoop:
    div $t0, $t1
    mflo $t2
    mfhi $t3
    li $t4, '0'
    add $t4, $t4, $t3
    sb $t4, countString($t5)
    addi $t5, $t5, 1
    beq $t2, $0, endConvert
    move $t0, $t2
    j convertLoop
    
endConvert:
    li $t4, '\n'
    sb $t4, countString($t5)
    addi $t5, $t5, 1
    
newFileInput:
    li $v0, 13
    la $a0, newFileName
    li $a1, 1
    li $a2, 0
    syscall
    move $s1, $v0
    
    li $v0, 15
    move $a0, $s1  
    la $a1, countString
    li $a2, 10
    syscall
    
fileTermination:
    li $v0, 10
    syscall