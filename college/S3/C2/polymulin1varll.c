
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff, exp;
    struct Node *next;
} Node;

void insert(Node **p, int c, int e) {
    while (*p && (*p)->exp > e)
        p = &(*p)->next;

    if (*p && (*p)->exp == e) {
        (*p)->coeff += c;
        return;
    }

    Node *n = malloc(sizeof(Node));
    if (!n) exit(EXIT_FAILURE);
    *n = (Node){c, e, *p};
    *p = n;
}

void readPoly(Node **p) {
    int n, c, e;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d%d", &c, &e);
        insert(p, c, e);
    }
}

void multiply(Node *a, Node *b, Node **r) {
    for (Node *p = a; p; p = p->next)
        for (Node *q = b; q; q = q->next)
            insert(r, p->coeff * q->coeff, p->exp + q->exp);
}

void display(Node *p) {
    if (!p) {
        printf("0\n");
        return;
    }

    while (p) {
        printf("%dx^%d", p->coeff, p->exp);
        if (p->next) printf(" + ");
        p = p->next;
    }
    printf("\n");
}

int main(void) {
    Node *a = NULL, *b = NULL, *r = NULL;

    printf("First polynomial:\n");
    readPoly(&a);

    printf("Second polynomial:\n");
    readPoly(&b);

    multiply(a, b, &r);

    printf("\nFirst polynomial: ");
    display(a);
    printf("Second polynomial: ");
    display(b);
    printf("Product: ");
    display(r);

    return 0;
}
