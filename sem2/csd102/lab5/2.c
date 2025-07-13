#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node{
    char data;
    struct node*next;
}node;

typedef struct Stack{
    struct node*head;
    unsigned int size;
}Stack;

void print_stack(Stack*s);//initialising all stack adt functions
void print_stack_reverse(Stack*s);
void push(Stack*s, char val);
unsigned int count(Stack *s);
void pop(Stack *s);
char top(Stack *s);

int main(){
    Stack *s=malloc(sizeof(Stack));
    s->head=NULL;
    s->size=0;
    char temp[50];

    scanf("%s", temp);
    for (int i=0; i<50; i++){
        if (temp[i]=='\0')
            break;
        push(s, temp[i]);
    }
    pop(s);

    scanf("%s", temp);
    for (int i=0; i<50; i++){
        if (temp[i]=='\0')
            break;
        push(s, temp[i]);
    }

    print_stack_reverse(s);

    while (s->head != NULL) {
        pop(s);
    }
    free(s);

    return 0;
}

void push(Stack*s, char val)
{
    node *newNode=malloc(sizeof(node));
    newNode->data=val;
    newNode->next=s->head;
    s->head=newNode;
    s->size++;//sequentially inserting values as function is called
}

void pop(Stack* s) 
{
    if (s->head == NULL) 
    {
        return;
    }

    node* temp = s->head;
    s->head = temp->next;
    free(temp);//clearing up memory allocation
    s->size--;
}

char top(Stack* s) 
{
    if (s->head == NULL) //to handle exceptions that stack is empty
    {
        return '\0'; // or any error code
    }
    return s->head->data;
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
        printf("%d", temp->data);
        temp=temp->next;
    }
}

unsigned int count(Stack *s)
{
    printf("%d", s->size);
}