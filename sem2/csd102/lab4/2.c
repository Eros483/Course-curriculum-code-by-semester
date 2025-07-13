#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, k;
    scanf("%d", &n);

    int* array = (int*)malloc(n * sizeof(int));

    for (int x = 0; x < n; x++) 
    {
        scanf("%d", &array[x]);
    }

    scanf("%d", &k);

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

    // Rotate the linked list
    for (int a = 0; a < k; a++) 
    {
        int temp = nodearray[n - 1]->data;
        for (int b = n - 1; b > 0; b--) 
        {
            nodearray[b]->data = nodearray[b - 1]->data;
        }
        nodearray[0]->data = temp;
    }

    struct Node* current = nodearray[0];

    while (current != NULL) 
    {
        printf("%d ", current->data);
        current = current->next;
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) 
    {
        free(nodearray[i]);
    }

    free(array);

    return 0;
}
