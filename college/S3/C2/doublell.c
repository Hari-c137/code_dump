
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node *head = NULL;

void insertBeginning(int x) {
    Node *n = malloc(sizeof(Node));
    if (!n) exit(EXIT_FAILURE);
    n->data = x;
    n->prev = NULL;
    n->next = head;
    if (head) head->prev = n;
    head = n;
}

void insertAfter(int key, int x) {
    Node *p = head;
    while (p && p->data != key) p = p->next;

    if (!p) {
        printf("Node not found\n");
        return;
    }

    Node *n = malloc(sizeof(Node));
    if (!n) exit(EXIT_FAILURE);
    n->data = x;
    n->prev = p;
    n->next = p->next;
    if (p->next) p->next->prev = n;
    p->next = n;
}

void insertEnd(int x) {
    Node *n = malloc(sizeof(Node));
    if (!n) exit(EXIT_FAILURE);
    n->data = x;
    n->next = NULL;

    if (!head) {
        n->prev = NULL;
        head = n;
        return;
    }

    Node *p = head;
    while (p->next) p = p->next;
    p->next = n;
    n->prev = p;
}

void deleteItem(int x) {
    Node *p = head;
    while (p && p->data != x) p = p->next;

    if (!p) {
        printf("Item not found\n");
        return;
    }

    if (p->prev) p->prev->next = p->next;
    else head = p->next;

    if (p->next) p->next->prev = p->prev;
    free(p);
    printf("Item deleted\n");
}

void deletePosition(int pos) {
    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }

    Node *p = head;
    for (int i = 1; p && i < pos; i++) p = p->next;

    if (!p) {
        printf("Invalid position\n");
        return;
    }

    if (p->prev) p->prev->next = p->next;
    else head = p->next;

    if (p->next) p->next->prev = p->prev;
    free(p);
    printf("Node deleted\n");
}

void display(void) {
    Node *p = head;
    if (!p) printf("List is empty");

    while (p) {
        printf("%d <-> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int main(void) {
    int ch, x, key, pos;

    do {
        printf("\n1.Insert Beginning\n2.Insert After Node\n");
        printf("3.Insert End\n4.Delete Item\n5.Delete Position\n");
        printf("6.Display\n7.Exit\nChoice: ");
        if (scanf("%d", &ch) != 1) break;

        switch (ch) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &x);
            insertBeginning(x);
            break;
        case 2:
            printf("Enter existing node value and new value: ");
            scanf("%d%d", &key, &x);
            insertAfter(key, x);
            break;
        case 3:
            printf("Enter value: ");
            scanf("%d", &x);
            insertEnd(x);
            break;
        case 4:
            printf("Enter item to delete: ");
            scanf("%d", &x);
            deleteItem(x);
            break;
        case 5:
            printf("Enter position (starting from 1): ");
            scanf("%d", &pos);
            deletePosition(pos);
            break;
        case 6:
            display();
            break;
        case 7:
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (ch != 7);

    while (head) {
        Node *p = head;
        head = head->next;
        free(p);
    }

    return 0;
}

