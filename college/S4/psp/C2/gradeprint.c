#include <stdio.h>

int main() {

  int mark;

  printf("enter the mark of student: ");
  scanf("%d", &mark);


  if (mark <= 30) {

    printf("grade is C\n");

  }
  else if (mark <= 50) {

    printf("grade is B\n");

  }
  else {

    printf("grade is A\n");

  }
}
