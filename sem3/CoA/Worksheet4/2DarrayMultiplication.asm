.data
matrixA: .space 36          # Allocate 36 bytes for matrixA (3x3 integers, 4 bytes each)
matrixB: .space 36          # Allocate 36 bytes for matrixB
matrixC: .space 36          # Allocate 36 bytes for matrixC (result matrix)

.text
main:
    jal read_matrix          # Jump and link to read_matrix to read matrixA
    jal read_matrixB         # Jump and link to read_matrixB to read matrixB
    jal multiply_matrix      # Jump and link to multiply_matrix to compute matrixC = matrixA * matrixB
    jal print_matrix         # Jump and link to print_matrix to display matrixC
    li $v0, 10               # Load immediate value 10 into $v0 (exit syscall)
    syscall                  # Make syscall to exit the program

# Function to read matrixA from user input
read_matrix:
    li $t0, 0                # Initialize column counter ($t0) to 0
    li $t1, 0                # Initialize row counter ($t1) to 0
loop_read:
    beq $t0, 3, end_read     # If column counter is 3, end reading
    beq $t1, 3, next_row_read# If row counter is 3, move to next row
    la $t2, matrixA          # Load address of matrixA into $t2
    mul $t3, $t0, 12         # Calculate byte offset for the current column ($t0 * 12)
    add $t3, $t3, $t1        # Add row counter to get the linear index
    mul $t3, $t3, 4          # Multiply by 4 to get byte address (word size)
    add $t3, $t2, $t3        # Add base address of matrixA to get the target address
    li $v0, 5                # Load syscall code 5 (read integer) into $v0
    syscall                  # Make syscall to read an integer
    move $t4, $v0            # Move the read integer from $v0 to $t4
    sw $t4, 0($t3)           # Store the integer into the calculated address in matrixA
    addi $t1, $t1, 1         # Increment row counter
    j loop_read              # Jump back to loop_read
next_row_read:
    li $t1, 0                # Reset row counter to 0 for the next column
    addi $t0, $t0, 1         # Increment column counter
    j loop_read              # Jump back to loop_read
end_read:
    jr $ra                   # Return from read_matrix

# Function to read matrixB from user input
read_matrixB:
    li $t0, 0                # Initialize column counter ($t0) to 0
    li $t1, 0                # Initialize row counter ($t1) to 0
loop_readB:
    beq $t0, 3, end_readB    # If column counter is 3, end reading
    beq $t1, 3, next_row_readB# If row counter is 3, move to next row
    la $t2, matrixB          # Load address of matrixB into $t2
    mul $t3, $t0, 12         # Calculate byte offset for the current column ($t0 * 12)
    add $t3, $t3, $t1        # Add row counter to get the linear index
    mul $t3, $t3, 4          # Multiply by 4 to get byte address (word size)
    add $t3, $t2, $t3        # Add base address of matrixB to get the target address
    li $v0, 5                # Load syscall code 5 (read integer) into $v0
    syscall                  # Make syscall to read an integer
    move $t4, $v0            # Move the read integer from $v0 to $t4
    sw $t4, 0($t3)           # Store the integer into the calculated address in matrixB
    addi $t1, $t1, 1         # Increment row counter
    j loop_readB             # Jump back to loop_readB
next_row_readB:
    li $t1, 0                # Reset row counter to 0 for the next column
    addi $t0, $t0, 1         # Increment column counter
    j loop_readB             # Jump back to loop_readB
end_readB:
    jr $ra                   # Return from read_matrixB

# Function to multiply matrixA and matrixB, storing the result in matrixC
multiply_matrix:
    li $t0, 0                # Initialize outer row counter ($t0) to 0
    li $t1, 0                # Initialize inner column counter ($t1) to 0
    li $t2, 0                # Initialize summation counter ($t2) to 0
loop_multiply:
    beq $t0, 3, end_multiply         # If outer row counter is 3, end multiplication
    beq $t1, 3, next_row_multiply    # If inner column counter is 3, move to next row
    beq $t2, 3, next_column_multiply # If summation counter is 3, move to next column
    la $t3, matrixA                   # Load address of matrixA into $t3
    mul $t4, $t0, 12                  # Calculate byte offset for row ($t0 * 12)
    add $t4, $t4, $t2                 # Add summation counter to get column index
    mul $t4, $t4, 4                   # Multiply by 4 to get byte address
    add $t4, $t3, $t4                 # Add base address of matrixA to get element address
    lw $t5, 0($t4)                     # Load element from matrixA into $t5
    la $t3, matrixB                   # Load address of matrixB into $t3
    mul $t4, $t2, 12                  # Calculate byte offset for column ($t2 * 12)
    add $t4, $t4, $t1                 # Add inner column counter to get row index
    mul $t4, $t4, 4                   # Multiply by 4 to get byte address
    add $t4, $t3, $t4                 # Add base address of matrixB to get element address
    lw $t6, 0($t4)                     # Load element from matrixB into $t6
    mul $t7, $t5, $t6                 # Multiply matrixA element and matrixB element, store in $t7
    la $t3, matrixC                   # Load address of matrixC into $t3
    mul $t4, $t0, 12                  # Calculate byte offset for result row ($t0 * 12)
    add $t4, $t4, $t1                 # Add inner column counter to get column index
    mul $t4, $t4, 4                   # Multiply by 4 to get byte address
    add $t4, $t3, $t4                 # Add base address of matrixC to get element address
    lw $t8, 0($t4)                     # Load current value of matrixC element into $t8
    add $t8, $t8, $t7                 # Add the product to the current value
    sw $t8, 0($t4)                     # Store the updated value back into matrixC
    addi $t2, $t2, 1                   # Increment summation counter
    j loop_multiply                    # Jump back to loop_multiply
next_column_multiply:
    li $t2, 0                # Reset summation counter to 0
    addi $t1, $t1, 1         # Increment inner column counter
    j loop_multiply          # Jump back to loop_multiply
next_row_multiply:
    li $t1, 0                # Reset inner column counter to 0
    addi $t0, $t0, 1         # Increment outer row counter
    j loop_multiply          # Jump back to loop_multiply
end_multiply:
    jr $ra                   # Return from multiply_matrix

# Function to print matrixC
print_matrix:
    li $t0, 0                # Initialize row counter ($t0) to 0
    li $t1, 0                # Initialize column counter ($t1) to 0
loop_print:
    beq $t0, 3, end_print        # If row counter is 3, end printing
    beq $t1, 3, next_row_print   # If column counter is 3, move to next row
    la $t2, matrixC               # Load address of matrixC into $t2
    mul $t3, $t0, 12              # Calculate byte offset for row ($t0 * 12)
    add $t3, $t3, $t1             # Add column counter to get linear index
    mul $t3, $t3, 4               # Multiply by 4 to get byte address
    add $t3, $t2, $t3             # Add base address of matrixC to get element address
    lw $t4, 0($t3)                 # Load element from matrixC into $t4
    li $v0, 1                     # Load syscall code 1 (print integer) into $v0
    move $a0, $t4                 # Move the integer to print into $a0
    syscall                        # Make syscall to print the integer
    li $v0, 11                    # Load syscall code 11 (print character) into $v0
    li $a0, 32                    # Load ASCII code for space (' ') into $a0
    syscall                        # Make syscall to print a space
    addi $t1, $t1, 1               # Increment column counter
    j loop_print                   # Jump back to loop_print
next_row_print:
    li $t1, 0                # Reset column counter to 0 for the next row
    addi $t0, $t0, 1         # Increment row counter
    li $v0, 11               # Load syscall code 11 (print character) into $v0
    li $a0, 10               # Load ASCII code for newline ('\n') into $a0
    syscall                    # Make syscall to print newline
    j loop_print               # Jump back to loop_print
end_print:
    jr $ra                     # Return from print_matrix
