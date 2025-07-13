#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

void PrintNode(struct node *p, int node_index)
{
    printf("Node - %d\n", node_index);
    printf("%3d, %p\n", p->value, p->next);
}

void PrintList(struct node *p)
{
    int i;
    for (i=0; i<=5; i++)
    {
        PrintNode(p, i);
        p=p->next;
    }
}

int main()
{
    struct node *node0=NULL;
    struct node *node1=NULL;
    struct node *node2=NULL;
    struct node *node3=NULL;
    struct node *node4=NULL;

    node0=(struct node*)malloc(sizeof(struct node));
    node1=(struct node*)malloc(sizeof(struct node));
    node2=(struct node*)malloc(sizeof(struct node));
    node3=(struct node*)malloc(sizeof (struct node));
    node4=(struct node*)malloc(sizeof(struct node));

    node0->value=0;
    node1->value=0;
    node2->value=0;
    node3->value=0;
    node4->value=0;

    node0->next=node1;
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=NULL;

    char operation;
    struct node*current=node0;
    int node_index=0;
    while (1)
    {
        printf("OPERATIONS AVAILABLE ON LINKED LIST\n1 Update Value of node\n2 Go to next node\n3 Print Node\n4 Print list\n");
        switch(operation=getchar())
        {
            case '1':
            {
                printf("Enter integral value: \n");
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
                PrintNode(current, node_index);
                break;
            }
            case '4':
            {
                PrintList(current);
                break;
            }
        }
    }
}