#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node*next;
};

struct node*head;
struct node*one;

int main()
{
    head=malloc(sizeof(struct node));
    one=malloc(sizeof(struct node));
    head->data=1;
    head->next=one;
}
