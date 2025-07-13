#include <stdlib.h>
#include <stdio.h>

struct node
{
    int value;
    struct node* next;
};

void Print_Node(struct node*p, int node_no)
{
    printf("node number: %d\n", node_no);
    printf("value is %d, next node is at %p\n", p->value, p->next);
}

void Print_List(struct node*p)
{
    int i;
    for (i=0; i<=5; i++)
    {
        Print_Node(p, i);
        p=p->next;
    }
}

int main()
{
    struct node* node0=NULL;
    struct node* node1=NULL;
    struct node* node2=NULL;
    struct node* node3=NULL;
    struct node* node4=NULL;

    node0=(struct node*)malloc(sizeof(struct node));
    node1=(struct node*)malloc(sizeof(struct node));
    node2=(struct node*)malloc(sizeof(struct node));
    node3=(struct node*)malloc(sizeof(struct node));
    node4=(struct node*)malloc(sizeof(struct node)); 

    node0->next=node1;
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=NULL;

    node0->value=0;
    node1->value=0;
    node2->value=0;
    node3->value=0;
    node4->value=0;

    char operation;
    struct node*current=node0;
    int node_index=0;
    printf("Operations that can be performed\n1 update value\n2 next node\n3 print  node\n4 print list\n");
    while (1)
    {
        switch(operation=getchar())
        {
            case '1':
            {
                printf("Enter value: ");
                scanf("%d", &current->value);
                break;
            }

            case '2':
            {
                current=current->next;
                node_index++;
                break;
            }

            case '3':
            {
                Print_Node(current, node_index);
                break;
            }

            case '4':
            {
                Print_List(current);
                break;
            }
        }
    }
}