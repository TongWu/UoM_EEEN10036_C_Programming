#include <stdio.h>
//denfine the value of pi
#define PI 3.141593
int main(void) {
    double r;
    printf("Enter a value for the radius of the sphere: ");
    scanf("%lf", &r);
    printf("volume= %.2f", 4.0/3.0*PI*r*r*r);
    return 0;
}