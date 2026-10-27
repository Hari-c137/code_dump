
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

void insertBegin(int x) {
    Node *n = malloc(sizeof(Node));
    if (!n) exit(EXIT_FAILURE);
    n->data = x;
    n->next = head;
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
    n->next = p->next;
    p->next = n;
}

void insertEnd(int x) {
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

void deleteItem(int x) {
    Node *p = head, *prev = NULL;

    while (p && p->data != x) {
        prev = p;
        p = p->next;
    }

    if (!p) {
        printf("Item not found\n");
        return;
    }

    if (prev) prev->next = p->next;
    else head = p->next;

    free(p);
    printf("Item deleted\n");
}

void deletePos(int pos) {
    if (pos < 1 || !head) {
        printf("Invalid position\n");
        return;
    }

    Node *p = head, *prev = NULL;

    for (int i = 1; p && i < pos; i++) {
        prev = p;
        p = p->next;
    }

    if (!p) {
        printf("Invalid position\n");
        return;
    }

    if (prev) prev->next = p->next;
    else head = p->next;

    free(p);
    printf("Node deleted\n");
}

void display(void) {
    Node *p = head;

    if (!p) printf("List is empty\n");

    while (p) {
        printf("%d -> ", p->data);
        p = p->next;
    }

    printf("NULL\n");
}

int main(void) {
    int ch, x, key, pos;

    do {
        printf("\n1.Insert Beginning\n2.Insert After Node\n");
        printf("3.Insert End\n4.Delete Item\n5.Delete Position\n");
        printf("6.Display\n7.Exit\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &x);
            insertBegin(x);
            break;

        case 2:
            printf("Enter existing value and new value: ");
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
            printf("Enter position: ");
            scanf("%d", &pos);
            deletePos(pos);
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
        Node *t = head;
        head = head->next;
        free(t);
    }

    return 0;
}

