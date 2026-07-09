#include <stdio.h>

int main() {

  int n;

  printf("enter the number: ");
  scanf("%d", &n);

  if ( n == 0) {
    printf("zero\n");
  }
  else if (n < 0) {
    printf("negative\n");
  }
  else {
    printf("positive\n");
  }


}
