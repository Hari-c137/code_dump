#include <stdio.h>

int main() {


  int m,n,o;

  printf("enter the first number: \n");
  scanf("%d", &m);
  printf("enter the second number: \n");
  scanf("%d", &n);
  printf("enter the third number: \n");
  scanf("%d", &o);

  if (m > n && m > o) {
    printf("largest is %d\n", m);
  }
  else if (n > m && n > o) {
    printf("largest is %d\n", n);
  }
  else {
    printf("largest is %d\n", o);
  }


}
