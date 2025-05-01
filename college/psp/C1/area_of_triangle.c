#include <stdio.h>

int main() {

  int area, height, base;

  printf("enter the base of triangle: ");
  scanf("%d", &base);
  printf("enter the height of triangle: ");
  scanf("%d", &height);

  area = (height * base) / 2;
  printf("the area of triangle is: %d", area);
}
