#include <stdio.h>
#include <stdlib.h>
// Define a structure for a node in the queue
struct Node {
   int data;
   struct Node *next;
};

struct Node* front = NULL; // Declare a pointer to the front of the queue
struct Node* rear = NULL; // Declare a pointer to the rear of the queue

void enqueue(int x);
void dequeue();
void display();

int main() {
    int n, m;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &m);
        enqueue(m);
    }
    dequeue();
    display();
    return 0; // Return from the main function
}

void enqueue (int x)
{
    struct Node* new=(struct Node*)malloc(sizeof(struct Node));
    new->data=x;
    new->next=NULL;
    if (front == NULL) 
    {
        front = rear = new;
    } 
    else 
    {
        rear->next = new;
        rear = new;
    }
}

void dequeue()
{
    struct Node*n1=front;
    front=n1->next;
    free(n1);
}

void display()
{ 
    struct Node*current=front;
    while(current!=NULL)
    {
        printf("%d ", current->data);
        current=current->next;
    }
}