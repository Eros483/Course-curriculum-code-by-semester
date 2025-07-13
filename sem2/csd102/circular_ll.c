#include <stdio.h>
#include <stdlib.h>

struct node{
    int num;
    struct node*preptr;
    struct node*nextptr;
};

int main()
{
    int n;
    scanf("%d", &n);

    int*values=(int*)malloc(n*sizeof(int));

    for (int i=0; i<n; i++)
    {
        scanf("%d", &values[i]);
    }

    struct node*nodearray[n];

    for (int j = 0; j < n; ++j) 
    {
        nodearray[j] = (struct node*)malloc(sizeof(struct node));
        nodearray[j]->num = values[j];
        nodearray[j]->nextptr = NULL;
        nodearray[j]->preptr=NULL;

        if (j > 0) 
        {
            nodearray[j - 1]->nextptr = nodearray[j];
            nodearray[j]->preptr=nodearray[j-1];
        }
    }

    struct node*current=nodearray[n-1];
    while(current!=NULL)
    {
        printf("%d ", current->num);
        current=current->preptr;
    }

    free(values);
    for (int i = 0; i < n; i++) 
    {
        free(nodearray[i]);
    }    
}