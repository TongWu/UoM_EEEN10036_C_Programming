#include <stdio.h>
#define g 9.8
int main(void) {
    double mass, height;
    //let user input values of mass and height
    printf("Enter a value for mass: ");
    scanf("%lf", &mass);
    printf("Enter a value for height: ");
    scanf("%lf", &height);
    //potential energy=mass*g*height
    printf("Potential energy=%.2f J", mass*g*height);
    return 0;
}