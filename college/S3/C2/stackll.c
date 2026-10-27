
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *top = NULL;

void push(int x) {
    Node *n = malloc(sizeof(Node));
    if (!n) exit(EXIT_FAILURE);
    n->data = x;
    n->next = top;
    top = n;
    printf("%d pushed\n", x);
}

void pop(void) {
    if (!top) {
        printf("Stack is empty\n");
        return;
    }
    Node *t = top;
    printf("Popped: %d\n", t->data);
    top = top->next;
    free(t);
}

void display(void) {
    Node *p = top;
    if (!p) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack (Top to Bottom): ");
    while (p) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int main(void) {
    int ch, x;

    do {
        printf("\n1.Push  2.Pop  3.Display  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &x);
            push(x);
            break;
        case 2:
            pop();
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

    while (top) {
        Node *t = top;
        top = top->next;
        free(t);
    }

    return 0;
}

