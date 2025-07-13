#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to find the length of a linked list
int findLength(struct Node* head) {
    int length = 0;
    struct Node* current = head;

    while (current != NULL) {
        length++;
        current = current->next;
    }

    return length;
}

// Function to find the intersection point of two linked lists
struct Node* findIntersection(struct Node* list1, struct Node* list2) {
    int len1 = findLength(list1);
    int len2 = findLength(list2);

    // Traverse the longer list until the lengths are equal
    while (len1 > len2) {
        list1 = list1->next;
        len1--;
    }

    while (len2 > len1) {
        list2 = list2->next;
        len2--;
    }

    // Traverse both lists until the intersection point is found
    while (list1 != NULL && list2 != NULL) {
        if (list1 == list2) {
            return list1; // Intersection point found
        }
        list1 = list1->next;
        list2 = list2->next;
    }

    // No intersection point found
    return NULL;
}

int main() {
    int n1 = 5;
    int array1[] = {10, 20, 30, 40, 50};

    struct Node* nodearray1[n1];

    for (int j = 0; j < n1; ++j) {
        nodearray1[j] = (struct Node*)malloc(sizeof(struct Node));
        nodearray1[j]->data = array1[j];
        nodearray1[j]->next = NULL;

        if (j > 0) {
            nodearray1[j - 1]->next = nodearray1[j];
        }
    }

    int n2 = 3;
    int array2[] = {100, 200, 300};

    struct Node* nodearray2[n2];
    for (int k = 0; k < n2; ++k) {
        nodearray2[k] = (struct Node*)malloc(sizeof(struct Node));
        nodearray2[k]->data = array2[k];
        nodearray2[k]->next = NULL;

        if (k > 0) {
            nodearray2[k - 1]->next = nodearray2[k]; // Set the next pointer in nodearray2
        }

        // Set the intersection point for the last node in nodearray2
        if (k == n2 - 1) {
            nodearray2[k]->next = nodearray1[2];
        }
    }

    // Finding the intersection point
    struct Node* intersection = findIntersection(nodearray1[0], nodearray2[0]);

    // Printing the linked lists and intersection point
    printf("Linked List 1: ");
    struct Node* current = nodearray1[0];
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("NULL\n");

    printf("Linked List 2: ");
    struct Node* current2 = nodearray2[0];
    while (current2 != NULL) {
        printf("%d ", current2->data);
        current2 = current2->next;
    }
    printf("NULL\n");

    if (intersection != NULL) {
        printf("Intersection point at node with data: %d\n", intersection->data);
    } else {
        printf("No intersection point found.\n");
    }

    // Freeing allocated memory
    for (int i = 0; i < n1; ++i) {
        free(nodearray1[i]);
    }

    for (int i = 0; i < n2; ++i) {
        free(nodearray2[i]);
    }

    return 0;
}
