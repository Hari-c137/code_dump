#include <stdio.h>

void main() {

  int area, length, breath;

  printf("enter the length of rectangle: ");
  scanf("%d", &length);
  printf("enter the breath of rectangle: ");
  scanf("%d", &breath);

  area = length * breath;
  printf("the area of rectangle is: %d", area);
}
