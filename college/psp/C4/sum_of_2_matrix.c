#include <stdio.h>

int main() {

  int a[3][3], b[3][3], c[3][3]; // intialize matrx a.b and their sum
  int i,j; // for for loops haha


  //read first matrix
  printf("enter the elements in first matrix: ");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  // read second matrix
  printf("enter the elements is second matrix: ");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      scanf("%d", &b[i][j]);
    }
  }

  // adding matrix a and b into sum
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      c[i][j] = a[i][j] + b[i][j];
    }
  }

  printf("the sum of matrixs are: \n");
   for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf("%d\t", c[i][j]);
    }
   }


}
