#include <stdio.h>

int main()  {

  int m,n;

  printf("enter the first number: ");
  scanf("%d", &m);
  printf("enter the second number: ");
  scanf("%d", &n);

  if (m > n) {
    printf("%d is larger\n", m);
  }
  else {
    printf("%d is larger\n", n);
  }

}
