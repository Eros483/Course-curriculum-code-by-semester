#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
void remover(struct Node*x);//function to remove duplicates

int main(){
    int n;
    scanf("%d", &n);
    int*array=(int*)malloc(n*sizeof(int));//allocating memory for values to be inserted into array
    for (int x=0; x<n; x++)
    {
        scanf("%d", &array[x]);
    }
    struct Node*nodearray[n];//initialising linked list
    for (int j=0; j<n; ++j)//creating linked list
    {
        nodearray[j]=(struct Node*)malloc(sizeof(struct Node));
        nodearray[j]->data=array[j];
        nodearray[j]->next=NULL;
        if (j>0)
        {
            nodearray[j-1]->next=nodearray[j];
        }
    }
    struct Node*top=nodearray[0];
    remover(top);

    struct Node*travel=nodearray[0];
    while (travel!=NULL)//printing linked list
    {
        printf("%d ", travel->data);
        travel=travel->next;
    }

    return 0;
}

void remover(struct Node*x)
{
    struct Node*current=x;

    while (current!=NULL)//setting up loop for each element of the linked list
    {
        struct Node*current2=current;
        while (current2->next!=NULL)//setting up loop for each element to be checked one by one against each element of the list
        {
            if (current2->next->data==current->data)//checking duplicate values
            {
                struct Node*temp=current2->next;
                current2->next=current2->next->next;
                free(temp);//removing duplicate nodes
            }
            else
            {
                current2=current2->next;
            }
        }
        current=current->next;
    }
}