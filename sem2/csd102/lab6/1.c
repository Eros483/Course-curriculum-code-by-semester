#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* detectLoopStart(struct Node* head);//initialising function that checks for loop based on Floyd's cycle detection algorithm

int main() {
    int n = 7;
    int array[] = {10, 20, 30, 40, 50, 60, 70};

    struct Node* nodearray[n]; // setting up linked list

    for (int j = 0; j < n; ++j) {
        nodearray[j] = (struct Node*)malloc(sizeof(struct Node));
        nodearray[j]->data = array[j];
        nodearray[j]->next = NULL;

        if (j > 0) {
            nodearray[j - 1]->next = nodearray[j];
        }
    }

    // Introducing a loop for testing
    nodearray[n - 1]->next = nodearray[4];

    struct Node* loopStart = detectLoopStart(nodearray[0]);

    if (loopStart != NULL) {
        printf("Loop starts at node with data: %d\n", loopStart->data);
        loopStart->next=NULL;
    } else {
        printf("No loop found in the linked list.\n");
    }

    printf("After removing loop, linked list is: \n");

    struct Node*current=nodearray[0];
    while (current!=NULL)
    {
        printf("%d ", current->data);
        current=current->next;
    }
    printf("\n");

    for (int u=0; u<n; u++)
    {
        free(nodearray[u]);
    }
    return 0;
}

struct Node* detectLoopStart(struct Node* head) {//initialising two pointers, one that moves twice as fast as the other, they'll end up on a common node at some point, similiar to HCF or GCD
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Loop detected, find the starting point
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow; // or fast, they are both at the starting point
        }
    }

    // No loop
    return NULL;
}