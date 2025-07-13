#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Function to insert a node at the end of the linked list
void Insert(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete a node from the linked list
void Delete(int value) {
    struct Node *current, *prev;
    current = head;
    prev = NULL;

    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Element not found in the list.\n");
        return;
    }

    if (prev == NULL) {
        head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
}

// Function to check if the linked list is empty
int IsEmpty() {
    return head == NULL;
}

// Function to display the linked list
void Display() {
    struct Node* temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    // Inserting 5 elements into the linked list
    for (int i = 1; i <= 5; ++i) {
        Insert(i);
    }

    printf("Linked List: ");
    Display();

    // Deleting a node with value 3
    printf("Enter element to be deleted: \n");
    int L;
    scanf("%d", &L);
    Delete(L);
    printf("Linked List after deleting %d: ", L);
    Display();

    // Checking if the list is empty
    if (IsEmpty()) {
        printf("Linked List is empty.\n");
    } else {
        printf("Linked List is not empty.\n");
    }

    return 0;
}
