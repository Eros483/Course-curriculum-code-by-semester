        .data
buffer:  .space 100                  # Reserve 100 bytes for the input string
count:   .space 104                  # Space for 26 character counts (4 bytes per count)
newline: .asciiz "\n"
colon:   .asciiz ": "                  
prompt:  .asciiz "Enter a string: "   # Prompt message

        .text
        .globl main

main:
        la $t0, count               
        li $t1, 0                   
        li $t2, 26                  
init_counts:
        sw $t1, 0($t0)              
        addi $t0, $t0, 4            
        subi $t2, $t2, 1            
        bgtz $t2, init_counts       

        jal read_string
        jal count_chars
        jal print_counts

        li $v0, 10                  
        syscall

read_string:
        # Print prompt to user
        li $v0, 4                   # Syscall to print string
        la $a0, prompt              # Load address of the prompt
        syscall

        # Read string from user input
        li $v0, 8                   # Syscall to read string
        la $a0, buffer              # Load address of the buffer
        li $a1, 100                 # Max length of the string
        syscall

        jr $ra                      

count_chars:
        la $t0, buffer               # Load the address of the user input string
        la $t1, count                # Load the address of the count array
count_loop:
        lb $t2, 0($t0)               # Load byte (character) from the string
        beqz $t2, end_count          # If null terminator, end the loop

        subi $t3, $t2, 97            # Convert 'a' to index 0, 'b' to 1, etc.

        bltz $t3, next_char          # If less than 'a', skip
        bge $t3, 26, next_char       # If greater than 'z', skip

        sll $t3, $t3, 2             # Multiply index by 4 (word size)
        add $t4, $t1, $t3           # Get the address of the correct count
        lw $t5, 0($t4)              # Load current count
        addi $t5, $t5, 1            # Increment the count
        sw $t5, 0($t4)              # Store the updated count

next_char:
        addi $t0, $t0, 1            # Move to the next character
        j count_loop                

end_count:
        jr $ra                      

print_counts:
        la $t0, count               
        li $t1, 0                   
print_loop:
        li $v0, 11                  # Syscall to print character
        addi $a0, $t1, 97           # Print the character ('a' + $t1)
        syscall

        li $v0, 4                   # Syscall to print ": "
        la $a0, colon               # Print ": "
        syscall

        li $v0, 1                   # Syscall to print integer (the count)
        lw $t2, 0($t0)              # Load the count
        move $a0, $t2               # Move count to $a0
        syscall

        li $v0, 4                   # Syscall to print newline
        la $a0, newline             
        syscall

        addi $t0, $t0, 4            # Move to the next count
        addi $t1, $t1, 1            # Increment character index
        li $t3, 26                  # Total 26 letters
        blt $t1, $t3, print_loop    # Loop for all 26 counts

        jr $ra
