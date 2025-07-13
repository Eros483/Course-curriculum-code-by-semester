#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data;
    struct node *next;
} node;

typedef struct Stack {
    struct node *head;
    unsigned int size;
} Stack;

typedef struct String{
    unsigned int size;
    char *str;
}String;

void print_stack(Stack *s);
void print_stack_reverse(Stack *s);
void push(Stack *s, char val);
unsigned int count(Stack *s);
void pop(Stack *s);
char top(Stack *s);
int Parenmatch(String *par_str);

int main() {
    Stack *s = malloc(sizeof(Stack));
    s->head = NULL;
    s->size = 0;
    char temp[50];

    scanf("%s", temp);
    String *par_str = malloc(sizeof(String));
    par_str->size = 0;

    par_str->size = strlen(temp);
    par_str->str = malloc((par_str->size) + 1);
    for (int i = 0; i < par_str->size; i++) {
        par_str->str[i] = temp[i];
    }

    int match = Parenmatch(par_str);
    printf("%d\n", match);

    free(s);
    free(par_str->str);
    free(par_str);

    return 0;
}

void push(Stack *s, char val) {
    node *newNode = malloc(sizeof(node));
    newNode->data = val;
    newNode->next = s->head;
    s->head = newNode;
    s->size++;
}

void pop(Stack *s) {
    if (s->head == NULL) {
        return;
    }

    node *temp = s->head;
    s->head = temp->next;
    free(temp);
    s->size--;
}

char top(Stack *s) {
    if (s->head == NULL) {
        return '\0';
    }
    return s->head->data;
}

void print_stack_reverse(Stack *s) {
    char *array = malloc(s->size * sizeof(char));
    int i = 0;
    node *temp = s->head;
    while (temp != NULL) {
        array[i] = temp->data;
        temp = temp->next;
        i++;
    }

    for (i = (s->size) - 1; i >= 0; --i) {
        printf("%c", array[i]);
    }
}

void print_stack(Stack *s) {
    node *temp = s->head;
    while (temp != NULL) {
        printf("%c", temp->data);
        temp = temp->next;
    }
}

unsigned int count(Stack *s) {
    printf("%d", s->size);
}

int Parenmatch(String *par_str) {
    Stack *s = malloc(sizeof(Stack));
    s->head = NULL;
    s->size = 0;

    for (int k = 0; k < par_str->size; k++) {
        if (par_str->str[k] == '(' || par_str->str[k] == '{' || par_str->str[k] == '[') {
            push(s, par_str->str[k]);
        } else if (par_str->str[k] == ')' || par_str->str[k] == '}' || par_str->str[k] == ']') {
            if (s->size == 0 ||
                (par_str->str[k] == ')' && top(s) != '(') ||
                (par_str->str[k] == '}' && top(s) != '{') ||
                (par_str->str[k] == ']' && top(s) != '[')) {
                free(s);
                return 0; // Mismatched brackets
            }
            pop(s);
        }
    }

    int result = (s->size == 0) ? 1 : 0; // Check if the stack is empty

    free(s);
    return result;
}
