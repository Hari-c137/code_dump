#include <stdio.h>

int main() {
  
  float percent;

  printf("enter the percent of student: ");
  scanf("%f", &percent);

  if (percent < 75) {
    printf("user failed!");
  }
  else {
    printf("user passed!");
  }

}
