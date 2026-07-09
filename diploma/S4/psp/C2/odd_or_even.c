#include <stdio.h>

int main() {
  int n;

  
  printf("enter the number: ");
  scanf("%d", &n);

  if (n % 2 == 0)
    printf("even\n");
  else 
    printf("odd\n");

}
