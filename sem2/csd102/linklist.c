#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    struct node*next;
    int value;
}node;

node*head;

void create(node **head, int value);
void print(node **head);

int main()
{
    create(&head, 5);
    create(&head, 17);
    print(&head);
}

void create(node **head, int value)
{
    node*newnode=malloc(sizeof(node));
    newnode->next=NULL;
    newnode->value=value;

    if (*head==NULL)
    {
        (*head)=newnode;
    }

    else
    {
        node*temp=*head;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

void print(node**head)
{
    node*current=(*head);
    while (current!=NULL)
    {
        printf("%d\n", current->value);
        current=current->next;
    }
}