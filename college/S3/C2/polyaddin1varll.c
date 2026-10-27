
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

void addPoly(Node *a, Node *b, Node **r) {
    while (a) {
        insert(r, a->coeff, a->exp);
        a = a->next;
    }
    while (b) {
        insert(r, b->coeff, b->exp);
        b = b->next;
    }
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
    Node *a = NULL, *b = NULL, *sum = NULL;

    printf("First polynomial:\n");
    readPoly(&a);

    printf("Second polynomial:\n");
    readPoly(&b);

    addPoly(a, b, &sum);

    printf("\nFirst polynomial: ");
    display(a);
    printf("Second polynomial: ");
    display(b);
    printf("Sum: ");
    display(sum);

    return 0;
}
