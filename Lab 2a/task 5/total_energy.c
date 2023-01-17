#include <stdio.h>
#define PE 500
//define potential energy as a constant 500
int main(void) {
    double mass=2.4;
    double velocity;
    printf("Enter a value for velocity: ");
    scanf("%lf", &velocity);
    //ke=1/2*m*v*v
    printf("Kinetic energy= %lf\n", 0.5*mass*velocity*velocity);\
    //Total energy=ke+pe
    printf("Total energy= %.2f", 0.5*mass*velocity*velocity+PE);
    return 0;
}