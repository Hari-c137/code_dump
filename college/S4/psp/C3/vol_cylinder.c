#include <stdio.h>

  float volume(int r, int h) {
    
    float vol = 3.14 * (r*r) * h;
    return vol;

  }




int main() {
 
  int r, h;
  float vol;

  printf("enter the height: ");
  scanf("%d", &h);
  printf("enter the radius: ");
  scanf("%d", &r);

  vol = volume(r,h);
  printf("%f\n", vol);


}
