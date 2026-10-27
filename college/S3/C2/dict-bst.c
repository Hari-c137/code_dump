
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char word[50], meaning[100];
    struct Node *left, *right;
} Node;

Node *insert(Node *root, char word[], char meaning[]) {
    if (!root) {
        Node *n = malloc(sizeof(Node));
        if (!n) exit(EXIT_FAILURE);
        strcpy(n->word, word);
        strcpy(n->meaning, meaning);
        n->left = n->right = NULL;
        return n;
    }

    int c = strcmp(word, root->word);
    if (c < 0)
        root->left = insert(root->left, word, meaning);
    else if (c > 0)
        root->right = insert(root->right, word, meaning);
    else
        strcpy(root->meaning, meaning);

    return root;
}

void search(Node *root, char word[]) {
    while (root) {
        int c = strcmp(word, root->word);
        if (c == 0) {
            printf("Meaning: %s\n", root->meaning);
            return;
        }
        root = (c < 0) ? root->left : root->right;
    }
    printf("Word not found\n");
}

void display(Node *root) {
    if (root) {
        display(root->left);
        printf("%s : %s\n", root->word, root->meaning);
        display(root->right);
    }
}

int main(void) {
    Node *root = NULL;
    int ch;
    char word[50], meaning[100];

    do {
        printf("\n1.Insert  2.Search  3.Display  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            printf("Enter word: ");
            scanf("%49s", word);
            printf("Enter meaning: ");
            scanf(" %99[^\n]", meaning);
            root = insert(root, word, meaning);
            break;

        case 2:
            printf("Enter word to search: ");
            scanf("%49s", word);
            search(root, word);
            break;

        case 3:
            printf("\nDictionary:\n");
            display(root);
            break;

        case 4:
            break;

        default:
            printf("Invalid choice\n");
        }
    } while (ch != 4);

    return 0;
}

