#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int value;
    struct Node*next;
}node;

typedef struct Stack{
    struct Node*head;
    unsigned int size;
}stack;

void push(stack*s, int value);
void pop(stack*s);
void print(stack*s);

int main()
{
    stack*s=malloc(sizeof(stack));
    s->head=NULL;
    s->size=0;
    push(s, 10);
    push(s, 17);
    print(s);
    pop(s);
    print(s);

}

void push(stack*s, int value)
{
    node*newnode=malloc(sizeof(node));
    newnode->value=value;
    newnode->next=s->head;
    s->head=newnode;
    s->size++;
}

void pop(stack*s)
{
    if (s->head==NULL)
    {
        return;
    }
    node*temp=s->head;
    s->head=temp->next;
    free(temp);
    s->size--;
}

void print(stack*s)
{
    node*current=s->head;
    while (current!=NULL)
    {
        printf("%d\n", current->value);
        current=current->next;
    }
}

