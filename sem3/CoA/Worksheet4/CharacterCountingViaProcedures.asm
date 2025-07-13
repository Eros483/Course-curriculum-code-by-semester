        .data
buffer:  .space 100                  # Reserve 100 bytes for the input string
count:   .space 104                  # Space for 26 character counts (4 bytes per count)
newline: .asciiz "\n"                # Newline character for printing
colon:   .asciiz ": "                # Colon followed by space, used in print formatting
prompt:  .asciiz "Enter a string: "  # Prompt message for the user input

        .text
        .globl main                  # Declare main function as global

main:
        la $t0, count                # Load address of the count array into $t0
        li $t1, 0                    # Set $t1 to 0 (initial count for each character)
        li $t2, 26                   # Set $t2 to 26 (for 26 letters in the alphabet)
init_counts:
        sw $t1, 0($t0)               # Store 0 in the current position of count array
        addi $t0, $t0, 4             # Move to the next position in the count array (word size)
        subi $t2, $t2, 1             # Decrement counter ($t2) by 1
        bgtz $t2, init_counts        # If $t2 > 0, repeat initialization

        jal read_string              # Jump to read_string subroutine
        jal count_chars              # Jump to count_chars subroutine
        jal print_counts             # Jump to print_counts subroutine

        li $v0, 10                   # Exit syscall
        syscall

read_string:
        # Print prompt to user
        li $v0, 4                   # Syscall code for printing string
        la $a0, prompt              # Load address of the prompt message into $a0
        syscall

        # Read string from user input
        li $v0, 8                   # Syscall code for reading string input
        la $a0, buffer              # Load address of the buffer to store the input string
        li $a1, 100                 # Set $a1 to 100 (maximum input length)
        syscall

        jr $ra                      # Return to the calling function

count_chars:
        la $t0, buffer              # Load the address of the input string into $t0
        la $t1, count               # Load the address of the count array into $t1
count_loop:
        lb $t2, 0($t0)              # Load a byte (character) from the string into $t2
        beqz $t2, end_count         # If the byte is null terminator, end loop

        subi $t3, $t2, 97           # Convert character to its corresponding index ('a' becomes 0)

        bltz $t3, next_char         # If character is before 'a', skip this character
        bge $t3, 26, next_char      # If character is beyond 'z', skip this character

        sll $t3, $t3, 2             # Multiply index by 4 (to find the corresponding word in count array)
        add $t4, $t1, $t3           # Get the address of the correct count for this character
        lw $t5, 0($t4)              # Load current count for this character
        addi $t5, $t5, 1            # Increment the count by 1
        sw $t5, 0($t4)              # Store the updated count back

next_char:
        addi $t0, $t0, 1            # Move to the next character in the input string
        j count_loop                # Jump back to process the next character

end_count:
        jr $ra                      # Return to the calling function

print_counts:
        la $t0, count               # Load the address of the count array into $t0
        li $t1, 0                   # Initialize index (for character 'a') to 0
print_loop:
        li $v0, 11                  # Syscall code for printing a single character
        addi $a0, $t1, 97           # Set $a0 to character value ('a' + $t1)
        syscall

        li $v0, 4                   # Syscall code for printing a string
        la $a0, colon               # Load address of the colon string into $a0
        syscall

        li $v0, 1                   # Syscall code for printing an integer
        lw $t2, 0($t0)              # Load the count value for the current character
        move $a0, $t2               # Move the count value into $a0
        syscall

        li $v0, 4                   # Syscall code for printing a string
        la $a0, newline             # Load address of newline character into $a0
        syscall

        addi $t0, $t0, 4            # Move to the next count in the array
        addi $t1, $t1, 1            # Increment index for the next character
        li $t3, 26                  # Total of 26 letters in the alphabet
        blt $t1, $t3, print_loop    # If $t1 < 26, continue printing

        jr $ra                      # Return to the calling function
