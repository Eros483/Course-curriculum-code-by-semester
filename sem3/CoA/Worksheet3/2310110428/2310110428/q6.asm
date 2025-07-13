.data
inputStr: .asciiz "   "
outputPalindrome: .asciiz "The string is a palindrome.\n"
outputNotPalindrome: .asciiz "The string is not a palindrome.\n"

.text
.globl main

main:
    la $a0, inputStr

    li $t1, 0
    la $t0, inputStr

findLength:
    lb $t2, 0($t0)
    beqz $t2, doneLength
    addi $t1, $t1, 1
    addi $t0, $t0, 1
    j findLength

doneLength:
    move $t2, $t1
    la $a0, inputStr

    move $t3, $a0
    add $t4, $a0, $t2
    addi $t4, $t4, -1

checkPalindrome:
    ble $t3, $t4, doneCheckPalindrome
    lb $t5, 0($t3)
    lb $t6, 0($t4)
    beq $t5, $t6, continueCheck
    j notPalindrome

continueCheck:
    addi $t3, $t3, 1
    addi $t4, $t4, -1
    j checkPalindrome

doneCheckPalindrome:
    la $a0, outputPalindrome
    li $v0, 4
    syscall
    j exit

notPalindrome:
    la $a0, outputNotPalindrome
    li $v0, 4
    syscall

exit:
    li $v0, 10
    syscall
