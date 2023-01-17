#include <stdio.h>
#define RESISTIVITY 0.036

int main(void) {
  double length=5.55;
  double area=0.0022;
  printf("Resistance=%.2f\n", RESISTIVITY*length/area);
  return 0;
}