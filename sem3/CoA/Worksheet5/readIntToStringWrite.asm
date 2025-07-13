.data
fileName: .asciiz "Q1.txt"    # Name of the file to read from
buffer: .space 100            # Buffer to store the file contents
newFileName: .asciiz "A1.txt" # Name of the file to write to
countString: .space 10        # Space to store the converted count as a string

.text
main:
    li $v0, 13                # syscall to open a file
    la $a0, fileName          # load the address of the input file name
    li $a1, 0                 # open for reading only (flag = 0)
    li $a2, 0                 # mode (not relevant for read-only files)
    syscall                   # perform the open operation
    move $s0, $v0             # save the file descriptor in $s0

    li $v0, 14                # syscall to read from the file
    move $a0, $s0             # pass the file descriptor
    la $a1, buffer            # load the address of the buffer to store contents
    li $a2, 100               # number of bytes to read (100 bytes)
    syscall                   # perform the read operation

    li $v0, 16                # syscall to close the file
    move $a0, $s0             # pass the file descriptor
    syscall                   # close the file

    li $t0, 0                 # initialize counter ($t0) to zero
    la $a1, buffer            # load the address of the buffer to $a1
    
loop:
    lb $t1, 0($a1)            # load the next byte from the buffer
    beq $t1, $0, intToString   # if null byte (end of string), go to conversion
    addi $t0, $t0, 1          # increment the counter (count number of bytes)
    addi $a1, $a1, 1          # move to the next byte in the buffer
    j loop                    # repeat until end of buffer

intToString:
    li $t1, 10                # load divisor (10) for converting integer to string
    li $t5, 0                 # index for countString (to store the result)
    
convertLoop:
    div $t0, $t1              # divide counter by 10
    mflo $t2                  # quotient (used for the next iteration)
    mfhi $t3                  # remainder (used to form the digit)
    li $t4, '0'               # base ASCII value for '0'
    add $t4, $t4, $t3         # convert remainder to its ASCII character
    sb $t4, countString($t5)  # store the character in countString
    addi $t5, $t5, 1          # move to the next index in countString
    beq $t2, $0, endConvert   # if quotient is 0, conversion is complete
    move $t0, $t2             # update counter with the quotient for the next iteration
    j convertLoop             # repeat the conversion process
    
endConvert:
    li $t4, '\n'              # load newline character
    sb $t4, countString($t5)  # store newline at the end of countString
    addi $t5, $t5, 1          # increment index

newFileInput:
    li $v0, 13                # syscall to open a new file
    la $a0, newFileName       # load the address of the new file name
    li $a1, 1                 # open for writing (flag = 1)
    li $a2, 0                 # mode (not relevant here)
    syscall                   # perform the open operation
    move $s1, $v0             # save the new file descriptor in $s1

    li $v0, 15                # syscall to write to a file
    move $a0, $s1             # pass the new file descriptor
    la $a1, countString       # load the address of countString
    li $a2, 10                # length of the string to write (including newline)
    syscall                   # perform the write operation

fileTermination:
    li $v0, 10                # syscall to exit
    syscall                   # terminate the program
