#include <stdio.h>

int main() {

  int n;
  int fac = 1;

  printf("enter the number: ");
  scanf("%d", &n);

  for(int i = 1; i <= n; i++) {
    fac = fac * i; 
  }

  printf("the factorial of %d is %d\n", n, fac);
}
