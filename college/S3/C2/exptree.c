
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node {
    char data;
    struct Node *left, *right;
} Node;

Node *stack[100];
int top = -1;

void push(Node *n) {
    stack[++top] = n;
}

Node *pop(void) {
    return stack[top--];
}

Node *create(char c) {
    Node *n = malloc(sizeof(Node));
    if (!n) exit(EXIT_FAILURE);
    n->data = c;
    n->left = n->right = NULL;
    return n;
}

int main(void) {
    char exp[100];
    Node *root = NULL;

    printf("Enter postfix expression: ");
    scanf("%99s", exp);

    for (int i = 0; exp[i]; i++) {
        Node *n = create(exp[i]);

        if (isalnum((unsigned char)exp[i])) {
            push(n);
        } else {
            n->right = pop();
            n->left = pop();
            push(n);
        }
    }

    root = pop();

    printf("Prefix: ");
    // Preorder traversal
    Node *s[100];
    int t = -1;
    s[++t] = root;

    while (t >= 0) {
        Node *n = s[t--];
        printf("%c", n->data);
        if (n->right) s[++t] = n->right;
        if (n->left) s[++t] = n->left;
    }

    printf("\nPostfix: ");
    // Postorder traversal using two stacks
    Node *s1[100], *s2[100];
    int t1 = -1, t2 = -1;
    s1[++t1] = root;

    while (t1 >= 0) {
        Node *n = s1[t1--];
        s2[++t2] = n;
        if (n->left) s1[++t1] = n->left;
        if (n->right) s1[++t1] = n->right;
    }

    while (t2 >= 0)
        printf("%c", s2[t2--]->data);

    printf("\n");
    return 0;
}
