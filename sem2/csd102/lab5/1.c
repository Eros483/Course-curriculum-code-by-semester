#include <stdio.h>
#include <stdlib.h>
int TOP;//as only top element can be interacted with in stack

void push(int i, int array[]);//declaring needed operations
void pop(int array[]);

int main(){
    int n;
    scanf("%d", &n);
    int*stack=(int*)malloc(n*sizeof(int));
    int*temp=(int*)malloc(n*sizeof(int));
    TOP=0;
    stack[TOP]=-1;
    for (int a=0; a<n; a++)
    {
        scanf("%d", &temp[a]);//inserting all necessary elements
        push(temp[a], stack);
    }
    for (int b=0; b<n; b++)
    {
        pop(stack);//removing and then displaying every element
    }
    free(stack);//freeing up storage
    free(temp);
    return 0;
}

void push(int i, int array[])//defining the functions
{
    ++TOP;
    array[TOP]=i;
}

void pop(int array[])//defining the functions
{
    if (TOP!=0)
    {
        printf("%d ", array[TOP]);
        --TOP;
    }
}