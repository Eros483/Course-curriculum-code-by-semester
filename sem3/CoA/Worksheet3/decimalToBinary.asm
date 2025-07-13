.data
buffer:         .space 33         # Space to store the binary string (32 bits + null terminator)
prompt:         .asciiz "Enter an integer: "
newline:        .asciiz "\n"

.text
.globl main

main:
    # Print prompt
    li      $v0, 4
    la      $a0, prompt
    syscall

    # Read integer from user
    li      $v0, 5
    syscall
    move    $t0, $v0              # Store user input in $t0

    # Initialize buffer index
    la      $a0, buffer            # Load address of buffer
    li      $t1, 32                # Set $t1 to 32 (for 32 bits)
    addi    $a0, $a0, 32           # Point to the end of the buffer
    sb      $zero, 0($a0)          # Null terminator

convert:
    addi    $a0, $a0, -1           # Move buffer pointer left
    andi    $t2, $t0, 1            # Extract LSB of the number
    li      $t3, 48                # ASCII '0'
    add     $t2, $t2, $t3          # Convert bit to ASCII
    sb      $t2, 0($a0)            # Store the character in buffer
    sra     $t0, $t0, 1            # Arithmetic right shift the number
    subi    $t1, $t1, 1            # Decrement bit counter
    bgtz    $t1, convert           # Repeat until all bits are processed

    # Print binary string
    li      $v0, 4
    la      $a0, buffer
    syscall

    # Print newline
    li      $v0, 4
    la      $a0, newline
    syscall

    # Exit
    li      $v0, 10
    syscall
