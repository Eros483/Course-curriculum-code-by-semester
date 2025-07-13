#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

void printNode(struct node *p, int node_index) {
    printf("Node - %d\n", node_index+1);
    printf("+-----+----------+\n| %3d | %p |\n+-----+----------+\n", p->data, p->link);
}

void printList(struct node *p) {
    for (int i = 0; i < 5; i++) {
        printNode(p, i);
        p = p->link;
    }
}

int main() {

    // Initialise Nodes
    struct node *node0 = NULL;
    struct node *node1 = NULL;
    struct node *node2 = NULL;
    struct node *node3 = NULL;
    struct node *node4 = NULL;

    // Allocate Memory
    node0 = (struct node *)malloc(sizeof(struct node));
    node1 = (struct node *)malloc(sizeof(struct node));
    node2 = (struct node *)malloc(sizeof(struct node));
    node3 = (struct node *)malloc(sizeof(struct node));
    node4 = (struct node *)malloc(sizeof(struct node));

    // Initializing Nodes to 0
    node0 -> data = 0;
    node1 -> data = 0;
    node2 -> data = 0;
    node3 -> data = 0;
    node4 -> data = 0;
   
    // Connect Nodes
    node0 -> link = node1;
    node1 -> link = node2;
    node2 -> link = node3;
    node3 -> link = node4;
    node4 -> link = NULL;


    printf("-----LINKED-LIST-----\n(A) - Update Value\n(B) - Next Node\n(C) - Print Node\n(D) - Print List\n");
    char c;
    struct node *current = node0;
    int node_index = 0;
    while (1) {
        switch (c = getchar()){
            case 'A':
                // printf("Enter new value (int) > "); scanf("%d", &temp);
                // current -> data = temp;
                printf("Enter new value (int) > "); scanf("%d", &current->data);
                break;
            case 'B':
                if (current->link == NULL){
                    printf("END OF LINKED LIST. GOING TO FIRST ELEMENT\n");
                    current = node0;
                    node_index = 0;
                    break;
                }
                current = current->link;
                node_index += 1;
                break;
            case 'C':
                printNode(current, node_index);
                break;
            case 'D':
                printList(node0);
                break;
            case '\n':
                break;
            default:
                printf("INVALID INPUT");
                break;
        }   
    }

}