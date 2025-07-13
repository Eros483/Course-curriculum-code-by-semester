        .data
input_file:    .asciiz "Q2.txt"  # Input file to read
output_file:   .asciiz "A2.txt"   # Output file to write vowel count
vowel_msg:     .asciiz "Vowel Count: "
newline:       .asciiz "\n"
char_buffer:   .space 1                    # Buffer to store one character
num_buffer:    .space 12                   # Buffer to store the string for the vowel count
file_open_error:  .asciiz "Couldn't open the file"
        .text
        .globl main
main:
        # Open the input file in read mode
        li   $v0, 13                      # Syscall for opening a file
        la   $a0, input_file              # Address of the input file string
        li   $a1, 0                       # 0 for read-only mode
        li   $a2, 0                       # No special flags
        syscall                           # Execute syscall
        move $t0, $v0                     # Save file descriptor in $t0

        # Check if file opened successfully
        bltz $t0, file_open_error          # If file descriptor is negative, error

        # Initialize vowel count to 0
        li   $t1, 0                       # $t1 will hold the vowel count

read_loop:
        # Read one byte (character) from the file
        li   $v0, 14                      # Syscall for reading a file
        move $a0, $t0                     # File descriptor in $a0
        la   $a1, char_buffer             # Buffer address in $a1
        li   $a2, 1                       # Read 1 byte
        syscall                           # Execute syscall

        # Check if the end of the file is reached
        beq  $v0, 0, end_read             # If $v0 == 0, end of file reached

        # Load the character from the buffer
        lb   $t2, 0($a1)                  # Load the byte (character) into $t2

        # Check if the character is a lowercase or uppercase vowel
        li   $t3, 'a'                     # Check for 'a'
        beq  $t2, $t3, is_vowel
        li   $t3, 'e'                     # Check for 'e'
        beq  $t2, $t3, is_vowel
        li   $t3, 'i'                     # Check for 'i'
        beq  $t2, $t3, is_vowel
        li   $t3, 'o'                     # Check for 'o'
        beq  $t2, $t3, is_vowel
        li   $t3, 'u'                     # Check for 'u'
        beq  $t2, $t3, is_vowel
        li   $t3, 'A'                     # Check for 'A'
        beq  $t2, $t3, is_vowel
        li   $t3, 'E'                     # Check for 'E'
        beq  $t2, $t3, is_vowel
        li   $t3, 'I'                     # Check for 'I'
        beq  $t2, $t3, is_vowel
        li   $t3, 'O'                     # Check for 'O'
        beq  $t2, $t3, is_vowel
        li   $t3, 'U'                     # Check for 'U'
        beq  $t2, $t3, is_vowel

        # If not a vowel, continue reading
        j    read_loop

is_vowel:
        # Increment the vowel count
        addi $t1, $t1, 1                  # Increment vowel count by 1
        j    read_loop                    # Continue reading

end_read:
        # Close the input file
        li   $v0, 16                      # Syscall for closing a file
        move $a0, $t0                     # File descriptor in $a0
        syscall                           # Execute syscall

        # Open the output file in write mode (create if it doesn't exist)
        li   $v0, 13                      # Syscall for opening a file
        la   $a0, output_file             # Address of the output file string
        li   $a1, 1                       # 1 for write-only mode
        li   $a2, 0                       # No special flags
        syscall                           # Execute syscall
        move $t0, $v0                     # Save file descriptor in $t0

        # Write the message "Vowel Count: " to the output file
        li   $v0, 15                      # Syscall for writing to a file
        move $a0, $t0                     # File descriptor in $a0
        la   $a1, vowel_msg               # Address of the message string
        li   $a2, 13                      # Length of the message string
        syscall                           # Execute syscall

        # Convert the vowel count to a string and write to output
        move $a0, $t1                     # Move vowel count to $a0
        la   $a1, num_buffer              # Address of the buffer to store the string
        jal  int_to_string                # Call function to convert integer to string

        # Write the vowel count string to the output file
        li   $v0, 15                      # Syscall for writing to a file
        move $a0, $t0                     # File descriptor in $a0
        la   $a1, num_buffer              # Address of the string buffer
        li   $a2, 12                      # Max length of the string
        syscall                           # Execute syscall

        # Write a newline to the output file
        li   $v0, 15                      # Syscall for writing to a file
        move $a0, $t0                     # File descriptor in $a0
        la   $a1, newline                 # Address of newline string
        li   $a2, 1                       # Length of the newline
        syscall                           # Execute syscall

        # Close the output file
        li   $v0, 16                      # Syscall for closing a file
        move $a0, $t0                     # File descriptor in $a0
        syscall                           # Execute syscall

        # Exit the program
        li   $v0, 10                      # Syscall for program exit
        syscall

# Function to convert integer to string
int_to_string:
        li   $t4, 10                      # Initialize divisor (10 for base-10 numbers)
        la   $a1, num_buffer + 11         # Start writing digits from the end of buffer
        sb   $zero, 0($a1)                # Null-terminate the string
        subi $a1, $a1, 1

convert_loop:
        div  $a0, $t4                     # Divide the integer by 10
        mfhi $t5                          # Get the remainder (the digit)
        addi $t5, $t5, '0'                # Convert digit to ASCII
        sb   $t5, 0($a1)                  # Store ASCII digit in buffer
        subi $a1, $a1, 1                  # Move to the next buffer position
        mflo $a0                          # Update the integer with quotient
        bnez $a0, convert_loop            # Continue until integer is 0
        jr   $ra                          # Return to caller
