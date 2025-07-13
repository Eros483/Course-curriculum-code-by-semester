.data

fileBomb: .asciiz "bomb.txt"
fileField: .asciiz "field.txt"
bufferBomb: .space 100
bufferField: .space 100
newline: .asciiz "\n"
space: .asciiz " "

.align 2
arrBomb: .space 100
.align 2
arrField: .space 100
.align 2
arrFinal: .space 100

dim: .word 0
numElements: .word 0

.text

# Open Bomb File
la $a0, fileBomb
li $a1, 0
li $a2, 0
li $v0, 13
syscall

# Read Bomb File and save to bufferBomb
move $a0, $v0
li $v0, 14
la $a1, bufferBomb
li $a2, 100
syscall

# Open Field File
la $a0, fileField
li $a1, 0
li $a2, 0
li $v0, 13
syscall

# Read Field File and save to bufferField
move $a0, $v0
li $v0, 14
la $a1, bufferField
li $a2, 100
syscall

# Print bufferBomb (temp)
la $a0, bufferBomb
li $v0, 4
syscall
la $a0, newline
li $v0, 4
syscall

# Determine and store dimension of array (temp)
la $a0, bufferBomb
jal len
li $v0, 1
move $a0, $t0
sw $t0, dim

mul $t0, $t0, $t0
sw $t0, numElements

# Store matrices in bomb.txt and field.txt into arrBomb and arrField
la $t0, arrBomb
li $s1, 0
li $a0, 0
la $a1, bufferBomb
jal loopOuter

la $t0, arrField
li $s1, 0
li $a0, 0
la $a1, bufferField
jal loopOuter

# Print arrField (for verification)
la $a0, arrField
lw $a1, dim
lw $a2, dim
jal ArrPrint

la $a0, newline
li $v0, 4
syscall

# Calculate sum of bomb cells
la $a0, arrBomb
la $a1, arrField
lw $s0, dim
lw $s1, dim
li $s2, 0
jal cycle_matrix

# Print result
li $v0, 1
move $a0, $s2
syscall

j exit

cycle_matrix:
    li $t0, 0              # Initialize row index (i) to 0

row_loop:
    bge $t0, $s0, end_cycle  # Exit loop if row index >= number of rows

    li $t1, 0               # Initialize column index (j) to 0

column_loop:
    bge $t1, $s1, next_row   # Exit inner loop if column index >= number of columns

    # Calculate address of matrix[i][j]
    mul $t2, $t0, $s1        # Row offset = i * num_columns
    add $t2, $t2, $t1        # Index = (i * num_columns) + j
    sll $t2, $t2, 2          # Multiply by 4 (assuming each element is a word)
    add $t3, $a0, $t2        # Address of matrix[i][j] in bomb grid

    # Load bomb grid value (0 or 1) into $t4
    lw $t4, 0($t3)
    
    # Check if there is a bomb at this location (if $t4 is 1)
    bnez $t4, add_bomb_value   # If $t4 == 1 (bomb present), jump to add_bomb_value

    addi $t1, $t1, 1          # Move to the next column (j + 1)
    j column_loop             # Repeat inner loop

add_bomb_value:
    # Calculate the address in field matrix for the same location
    add $t3, $a1, $t2
    lw $t4, 0($t3)            # Load the field value at this location
    add $s2, $s2, $t4         # Add to the cumulative sum

    addi $t1, $t1, 1          # Move to the next column (j + 1)
    j column_loop

next_row:
    addi $t0, $t0, 1          # Move to the next row (i + 1)
    j row_loop                # Repeat outer loop

end_cycle:
    jr $ra                    # Return from function

# Function to print Arrays
ArrPrint:
    li $s1, -1                  # Row Counter
    move $a3, $a0               # Base address
ArrPrintStart:
    la $a0, newline
    li $v0, 4
    syscall

    addi $s1, $s1, 1
    li $s2, 0                   # Column Counter
colPrint:
    li $t0, 0                   # TEMP for Address
    beq $s1, $a1, ArrPrintDone

    mul $t0, $s1, $a2
    add $t0, $t0, $s2
    mul $t0, $t0, 4
    add $t0, $t0, $a3

intPrint:
    lw $a0, 0($t0)
    li $v0, 1
    syscall

    addi $s2, $s2, 1
    beq $s2, $a2, ArrPrintStart

    la $a0, space
    li $v0, 4
    syscall
    j colPrint

ArrPrintDone:
    jr $ra

# Function to store matrices from a Matrix String
loopOuter:
    lb $s1, 0($a1)
    beqz $s1, endOfLoop
    beq $s1, 32, endOfNumber
    beq $s1, 10, endOfNumber
    beq $s1, 13, skip
    subi $s1, $s1, 48
    mul $a0, $a0, 10
    add $a0, $a0, $s1
    addi $a1, $a1, 1
    j loopOuter

skip:
    addi $a1, $a1, 1
    j loopOuter

endOfNumber:
    addi $a1, $a1, 1
    sw $a0, 0($t0)
    addi $t0, $t0, 4
    li $a0, 0
    j loopOuter

endOfLoop:
    addi $a1, $a1, 1
    sw $a0, 0($t0)
    addi $t0, $t0, 4
    li $a0, 0
    jr $ra

# Function to calculate length of matrix
len:
    li $t0, 0
inner:
    lb $t1, 0($a0)
    beq $t1, 10, end_of_len
    addi $a0, $a0, 1
    beq $t1, 32, incr
    j inner

incr:
    addi $t0, $t0, 1
    j inner

end_of_len:
    addi $t0, $t0, 1
    jr $ra

exit:
