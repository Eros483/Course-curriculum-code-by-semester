#include <stdio.h>
#include <string.h>

#define MAX 10
int TOP;
int LIFO[MAX];

void push(int i);
void pop();
void Overflow();
void Underflow();

int main()
{
    TOP=0;
    LIFO[TOP]=-1;
    char operation;
    int end=0;
    while (end==0)
    {
        printf("What operation would you like to carry out?\n1. push\n2. pop\n3. Overflow\n4. Underflow\n5. print\n");
        switch(operation=getchar())
        {
            case '1':
            {
                int x;
                printf("Enter value to be pushed\n");
                scanf("%d", &x);
                push(x);
                printf("Would you like to end operations?\n0. No\n1. Yes\n");
                scanf("%d", &end);
                break;
            }
            case '2':
            {
                pop(); 
                printf("Would you like to end operations?\n0. No\n1. Yes\n");
                scanf("%d", &end);
                break;
            }
            case '3':
            {
                Overflow();
                printf("Would you like to end operations?\n0. No\n1. Yes\n");
                scanf("%d", &end);
                break;
            }
            case '4':
            {
                Underflow();
                printf("Would you like to end operations?\n0. No\n1. Yes\n");
                scanf("%d", &end);
                break;
            }
            case '5':
            {
                printf("LIFO[TOP]=%d, TOP=%d\n", LIFO[TOP], TOP);
                printf("Would you like to end operations?\n0. No\n1. Yes\n");
                scanf("%d", &end);
                break;
            }
        }
    }
}
void push(int i)
{
    ++TOP;
    LIFO[TOP]=i;
}
void pop()
{
    if (TOP==0)
    {
        ;
    }
    else
    {
        --TOP;
    }
}
void Overflow()
{
    if (TOP==(MAX-1))
    {
        printf("THE STACK IS FULL\n");
    }
    else
    {
        printf("Non Full stack\n");
    }
}
void Underflow()
{
    if (LIFO[TOP]==-1)
    {
        printf("Empty stack\n");
    }
    else
    {
        printf("Non-Empty stack\n");
    }
}