#include <stdio.h>

int add(int x, int y) {

  int sum = x + y;
  return sum;
}


void main() {

 int n1, n2;

  printf("enter the first number: ");
  scanf("%d", &n1);
  printf("enter the second number: ");
  scanf("%d", &n2);

  int final = add(n1,n2);
  printf("the sum is %d\n", final);
}
