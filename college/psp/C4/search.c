#include <stdio.h>

int main() {

  int key, found;
  int arr[10];


  printf("enter the elements onto array [max 10]\n");
  for (int i = 0; i < 10; i ++) {
    scanf("%d", arr + i);
  }

  printf("enter the key to be searched: ");
  scanf("%d", &key);

  for (int i = 0; i < 10; i++) {
    if (key == arr[i]) {
      printf("key is found at the index %d\n", i);
      found = 1;
      break;
    }
  }

  if (!found) {
    printf("key not found!\n");
  }

}
