
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

void insert(int x) {
    Node *n = malloc(sizeof(Node)), *p = head;
    if (!n) exit(EXIT_FAILURE);
    n->data = x;
    n->next = NULL;

    if (!head) {
        head = n;
        return;
    }

    while (p->next) p = p->next;
    p->next = n;
}

void display(void) {
    Node *p = head;
    while (p) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

void reverse(void) {
    Node *prev = NULL, *curr = head, *next;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}

int main(void) {
    insert(10);
    insert(20);
    insert(30);
    insert(40);

    printf("Original List: ");
    display();

    reverse();

    printf("Reversed List: ");
    display();

    while (head) {
        Node *t = head;
        head = head->next;
        free(t);
    }

    return 0;
}

