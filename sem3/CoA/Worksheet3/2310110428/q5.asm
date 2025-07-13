.data
agePrompt:    .asciiz "Enter age: "
idPrompt:     .asciiz "Enter 1 if you have a voter ID card, 0 otherwise: "
eligibleMsg:  .asciiz "You are eligible to vote."
notEligibleMsg: .asciiz "You are not eligible to vote."

.text
main:
    li $v0, 4
    la $a0, agePrompt
    syscall

    li $v0, 5
    syscall
    move $t0, $v0

    blt $t0, 18, notEligible

    li $v0, 4
    la $a0, idPrompt
    syscall

    li $v0, 5
    syscall
    move $t1, $v0

    beq $t1, 1, eligible

    j notEligible

eligible:
    li $v0, 4
    la $a0, eligibleMsg
    syscall
    j exit

notEligible:
    li $v0, 4
    la $a0, notEligibleMsg
    syscall

exit:
    li $v0, 10
    syscall
