#include <stdio.h>
#define g 9.8
int main(void) {
    double mass, height, velocity;
    printf("Enter a value for mass: ");
    scanf("%lf", &mass);
    printf("Enter a value for height: ");
    scanf("%lf", &height);
    printf("Enter a value for velocity: ");
    scanf("%lf", &velocity);
    //total energy=mgh+1/2mv^2
    printf("Total energy= %.2f J", mass*g*height+0.5*mass*velocity*velocity);
    return 0;
}