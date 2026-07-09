#include <stdio.h>

void main() {

  int row = 5;


  for (int i = 0; i < row; i++) {
    for (int j = 0; j <= i; j++) {
      printf("* ");
    }
      printf("\n");
  }
}
