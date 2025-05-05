#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *left, *right; } Node;

Node* insert(Node* tree, int value) {
  if (!tree) return &(Node){value, 0, 0};
  if (value < tree->data) tree->left = insert(tree->left, value);
  else                    tree->right = insert(tree->right, value);
  return tree;
}

void traverse(Node* tree, int order) {
  if (!tree) return;
  if (order == 1) printf("%d ", tree->data);
  traverse(tree->left, order);
  if (order == 0) printf("%d ", tree->data);
  traverse(tree->right, order);
  if (order == 2) printf("%d ", tree->data);
}

int main() {
  Node *root = 0; int numElements, value;
  for (scanf("%d", &numElements); numElements--; ) scanf("%d", &value), root = insert(root, value);
  for (int i = 0; i < 3; i++, puts("")) traverse(root, i); // 0=in, 1=pre, 2=post
}
