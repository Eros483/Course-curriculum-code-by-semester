#include <stdio.h> 
#include <stdlib.h>

struct Node
{
    int data;
    struct Node*next;
};

struct Node*head=NULL; //initially no head

void Insert(int value)
{
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;

    if (head==NULL)
    {
        head=newNode;
    }
    else
    {
        struct Node*temp=head;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
    }
}

void Delete(int value)
{
    struct Node *current, *prev;
    current=head;
    prev=NULL;

    while(current!=NULL && current->data!=value)
    {
        prev=current;
        current=current->next;
    }

    if (current==NULL)
    {
        printf("Element not found in list\n");
        return;
    }

    if (prev==NULL)
    {
        head=current->next;
    }
    else
    {
        prev->next=current->next;
    }

    free(current);
}

int isEmpty()
{
    return head==NULL;
}

void Display()
{
    struct Node*temp=head;
    while(temp!=NULL)
    {
        printf("%d-> ", temp->data);
        temp=temp->next;
    }

    printf("NULL\n");
}

int main()
{
    int i;
    for (i=1; i<=5; i++)
    {
        Insert(i);
    }

    printf("Linked List: ");
    Display();

    printf("Enter element to be deleted: \n");
    int L;
    scanf("%d", &L);
    Delete(L);
    printf("List after %d is deleted: \n", L);
    Display();

    if (isEmpty())
    {
        printf("Linked list is empty.\n");
    }
    else
    {
        printf("List is not empty.\n");
    }

    return 0;
}