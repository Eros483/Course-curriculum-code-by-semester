.data
    promptInteger: .asciiz "Enter desired integer\n"
    spaceForBinary: .space 33 # 32 bits + 1 for null terminator

.text

main:
    # Print prompt for integer input
    li $v0, 4
    la $a0, promptInteger
    syscall
    
    # Read the integer from user input
    li $v0, 5
    syscall
    move $t0, $v0 # Store integer in $t0

    # Initialize variables
    li $t1, 32      # Counter for bits (32 bits)
    la $a1, spaceForBinary # Starting address of string storage

    # If negative, convert to 2's complement
    bgez $t0, conversion # Skip negation if non-negative
    not $t0, $t0
    addi $t0, $t0, 1

conversion:
    # Convert to binary and store it in memory (LSB first)
    blez $t1, reverse # If all bits processed, move to reverse step
    
    andi $t2, $t0, 1  # Extract the LSB
    addi $t2, $t2, 48 # Convert to ASCII ('0' or '1')
    sb $t2, 0($a1)    # Store the character
    addi $a1, $a1, 1  # Move to the next byte

    srl $t0, $t0, 1   # Shift integer right for the next bit
    sub $t1, $t1, 1   # Decrease bit counter
    j conversion

reverse:
    # Reverse the string
    la $a1, spaceForBinary   # Pointer to start of the string
    addi $a2, $a1, 31        # Pointer to end of the binary (before null)
    
reverse_loop:
    bge $a1, $a2, print      # Stop when pointers meet or cross

    # Swap characters between $a1 and $a2
    lb $t3, 0($a1)  # Load byte at start
    lb $t4, 0($a2)  # Load byte at end
    sb $t4, 0($a1)  # Store byte from end to start
    sb $t3, 0($a2)  # Store byte from start to end

    addi $a1, $a1, 1 # Move start pointer forward
    addi $a2, $a2, -1 # Move end pointer backward
    j reverse_loop

print:
    # Print the reversed binary string
    la $a0, spaceForBinary
    li $v0, 4
    syscall

    # Exit
    li $v0, 10
    syscall
