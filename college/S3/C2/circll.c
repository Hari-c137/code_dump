#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

void insert(int value) {
    Node *n = malloc(sizeof(Node));
    if (!n) exit(EXIT_FAILURE);
    n->data = value;

    if (!head) {
        head = n;
        n->next = head;
    } else {
        Node *p = head;
        while (p->next != head)
            p = p->next;
        p->next = n;
        n->next = head;
    }
}

void delete(int value) {
    if (!head) {
        printf("List is empty\n");
        return;
    }

    Node *p = head, *prev = NULL;

    do {
        if (p->data == value) {
            if (p == head && p->next == head)
                head = NULL;
            else {
                if (p == head) {
                    Node *last = head;
                    while (last->next != head)
                        last = last->next;
                    head = head->next;
                    last->next = head;
                } else
                    prev->next = p->next;
            }
            free(p);
            printf("Deleted %d\n", value);
            return;
        }
        prev = p;
        p = p->next;
    } while (p != head);

    printf("Value not found\n");
}

void display(void) {
    if (!head) {
        printf("List is empty\n");
        return;
    }

    Node *p = head;
    do {
        printf("%d -> ", p->data);
        p = p->next;
    } while (p != head);
    printf("(back to head)\n");
}

int main(void) {
    int choice, value;

    do {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insert(value);
            break;
        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            delete(value);
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 4);

    while (head)
        delete(head->data);

    return 0;
}

