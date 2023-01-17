#include <stdio.h>
#define pi 3.141593
#define epsilon 8.85e-12
int main(void) {
    double charge1;
    double charge2;
    double radius;
    printf("Enter a value for Q1: \n");
    scanf("%f", &charge1);
    printf("Enter a value for Q2: \n");
    scanf("%f", &charge2);
    printf("Enter a value for radius: \n");
    scanf("%f", &radius);
    printf("Coulomb force= %.2f", charge1*charge2/(4*pi*epsilon*radius*radius));
    return 0;
}
