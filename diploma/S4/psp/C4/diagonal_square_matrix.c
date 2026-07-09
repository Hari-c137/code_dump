#include <stdio.h>

int main() {
  
  int matrix[10][10], n;

  printf("enter the size of sqaure matrix: ");
  scanf("%d", &n);

  printf("enter the elements into matrix:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &matrix[i][j]);
    }

    printf(" \n");
  }

  printf("the matrix is: \n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j ++) {
      printf("%d\t", matrix[i][j]);
    }
  }

  printf("primary diagonal: \n");
  for (int i = 0; i < n; i++) {
    printf("%d\n", matrix[i][i]);
  }

  printf("secondary diagonal: \n");
  for (int i = 0; i < n; i++) {
    printf("%d\n", matrix[i][n - i - 1]);
  }


}
