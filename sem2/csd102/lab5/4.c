#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>//all estabilished libraries
#include <ctype.h>

typedef struct node{
    char data;
    struct node* next;
}node;

typedef struct Stack{
    struct node* head;
    unsigned int size;
}Stack;

//Stack ADT
// Use the code from Q2 for below functions
void print_stack(Stack* s);
void print_stack_reverse(Stack* s);
void push(Stack* s, char val);
unsigned int count(Stack *s);
void pop(Stack *s);
char top(Stack *s);

int precedence(char operator);//giving priority to operators as per infix postfix
    
typedef struct String{
    unsigned int size;
    char *str;
}String;


void InfixToPostfix(String *infix, String *postfix);


int main(){

    Stack *s = malloc(sizeof(Stack));
    s->head = NULL;
    s->size = 0;
    char temp[50];

    scanf("%s",temp);
    String *infix = malloc(sizeof(String));
    infix->size = 0;
    // Read the temp into infix structure
    
    infix->size = strlen(temp);
    infix->str = malloc((infix->size) * 2 + 1);  // Allocate enough space for potential extra spaces

    for (int i = 0; i < infix->size; i++) {
        infix->str[i * 2] = temp[i];
        infix->str[i * 2 + 1] = ' ';  // Add a space after each character or number
    }
    //adding spaces into the stacks and strings themselves instead of modifying printing operators

    String *postfix = malloc(sizeof(String));
    postfix->size = 0;
    postfix->str = NULL;
    // Save the postfix expressions in postfix string
    InfixToPostfix(infix, postfix);

    //checking for extra spaces if present according to infix postfix
    if (postfix->size > 0 && postfix->str[postfix->size - 1] == ' ') 
    {
        postfix->str[postfix->size - 1] = '\0';
        postfix->size--;
    }
    
    printf("%s\n",postfix->str);
    return 0;
}

void push(Stack *s, char val) 
{
    node *newNode = malloc(sizeof(node));
    newNode->data = val;
    newNode->next = s->head;
    s->head = newNode;
    s->size++; // sequentially inserting values as function is called
}

void pop(Stack *s) 
{
    if (s->head == NULL) {
        return;
    }

    node *temp = s->head;
    s->head = temp->next;
    free(temp); // clearing up memory allocation
    s->size--;
}

char top(Stack *s) 
{
    if (s->head == NULL) {
        return '\0'; // to handle exceptions that the stack is empty
    }
    return s->head->data;
}

int precedence(char operator) 
{
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void InfixToPostfix(String* infix, String* postfix) 
{
    Stack* operatorStack = malloc(sizeof(Stack));
    operatorStack->head = NULL;
    operatorStack->size = 0;

    postfix->str = malloc((infix->size) * 2 + 1);  // Allocate enough space for potential extra spaces
    int postfixIndex = 0;

    for (int i = 0; i < infix->size; i++) {
        char currentChar = infix->str[i * 2];

        if (isdigit(currentChar)) 
        {
            // If the current character is a digit, it's part of a multi-digit number
            int j = i;
            while (j < infix->size && isdigit(infix->str[j * 2])) {
                postfix->str[postfixIndex++] = infix->str[j * 2];
                j++;
            }
            i = j - 1;  // Move i to the last digit of the current number
            postfix->str[postfixIndex++] = ' ';  // Add a space after each operand
        } else if (isalnum(currentChar)) 
        {
            // If alphanumeric, it's an operand
            postfix->str[postfixIndex++] = currentChar;
            postfix->str[postfixIndex++] = ' ';  // Add a space after each operand
        } else if (currentChar == '(') 
        {
            // Opening parenthesis, push onto stack
            push(operatorStack, currentChar);
        } else if (currentChar == ')') 
        {
            // Closing parenthesis, pop operators from stack to output
            while (top(operatorStack) != '\0' && top(operatorStack) != '(') 
            {
                postfix->str[postfixIndex++] = top(operatorStack);
                postfix->str[postfixIndex++] = ' ';  // Add a space after each operator
                pop(operatorStack);
            }
            pop(operatorStack);
        } else 
        {
            // Operator
            while (top(operatorStack) != '\0' && precedence(top(operatorStack)) >= precedence(currentChar)) 
            {
                // Pop operators from stack to output if precedence is higher or equal
                postfix->str[postfixIndex++] = top(operatorStack);
                postfix->str[postfixIndex++] = ' ';  // Add a space after each operator
                pop(operatorStack);
            }
            push(operatorStack, currentChar); // Push the current operator onto the stack
        }
    }

    // Pop any remaining operators from the stack to the output
    while (top(operatorStack) != '\0') 
    {
        postfix->str[postfixIndex++] = top(operatorStack);
        postfix->str[postfixIndex++] = ' ';  // Add a space after each operator
        pop(operatorStack);
    }

    postfix->str[postfixIndex] = '\0';
    //basically to achieve formatting instead of editing printing parts, add the spaces into the stacks and the strings themself
    // Free the memory allocated for the stack
    free(operatorStack);
}

void print_stack_reverse(Stack* s) 
{
    char *array=malloc(s->size*sizeof(char));
    int i=0;
    node* temp = s->head;
    while (temp!=NULL)//taking all values present in stack so as to print them in reverse
    {
        array[i]=temp->data;
        temp = temp->next;
        i++;
    }

    for (i=(s->size)-1;i>=0; --i)
    {
        printf("%c", array[i]);
    }
}

void print_stack(Stack *s)
{
    node *temp=s->head;
    while (temp!=NULL)
    {
        printf("%c", temp->data);
        temp=temp->next;
    }
}

