
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *front = NULL, *rear = NULL;

void enqueue(int x) {
    Node *n = malloc(sizeof(Node));
    if (!n) exit(EXIT_FAILURE);
    n->data = x;
    n->next = NULL;

    if (!rear) front = rear = n;
    else rear = rear->next = n;

    printf("%d inserted\n", x);
}

void dequeue(void) {
    if (!front) {
        printf("Queue is empty\n");
        return;
    }

    Node *t = front;
    printf("Deleted: %d\n", t->data);
    front = front->next;
    if (!front) rear = NULL;
    free(t);
}

void display(void) {
    Node *p = front;
    if (!p) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    while (p) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int main(void) {
    int ch, x;

    do {
        printf("\n1.Enqueue  2.Dequeue  3.Display  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &x);
            enqueue(x);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (ch != 4);

    while (front) dequeue();
    return 0;
}
