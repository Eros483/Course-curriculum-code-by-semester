#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    scanf("%d", &n);

    int* array = (int*)malloc(n * sizeof(int));

    for (int x = 0; x < n; x++) 
    {
        scanf("%d", &array[x]);
    }

    struct Node* nodearray[n];//setting up linked list

    for (int j = 0; j < n; ++j) 
    {
        nodearray[j] = (struct Node*)malloc(sizeof(struct Node));
        nodearray[j]->data = array[j];
        nodearray[j]->next = NULL;

        if (j > 0) 
        {
            nodearray[j - 1]->next = nodearray[j];
        }
    }
    for (int a=0; a<(n/2); a++)
    {
        if (n%2==0)
        {
            int temp=nodearray[2*a]->data;
            nodearray[2*a]->data=nodearray[(2*a)+1]->data;
            nodearray[(2*a)+1]->data=temp;
        }
        else
        {
            if (2*a==n-1)
            {
                break;
            }
            else
            {
                int temp=nodearray[2*a]->data;
                nodearray[2*a]->data=nodearray[(2*a)+1]->data;
                nodearray[(2*a)+1]->data=temp;
            }
        }
    }
    struct Node* current = nodearray[0];

    while (current != NULL) 
    {
        printf("%d ", current->data);
        current = current->next;
    }

    free(array);
    // Free allocated memory
    for (int i = 0; i < n; i++) 
    {
        free(nodearray[i]);
    }

    return 0;
}