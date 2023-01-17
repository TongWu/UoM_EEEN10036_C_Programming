#include <stdio.h>
#define _use_math_defines
#include <math.h>
//#define M_PI 3.1415926535897933846 No need to be defined, use math.h or define the PI
//#define M_E 2.7182818284590452354 No need to be defined, use math.h or define the E
int main(void) {
    double x;
    printf("Enter a value: ");
    scanf("%lf", &x);
    printf("sin(%lf)= %.3f\n", x*M_PI, sin(x*M_PI));
    printf("cos(%lf)= %.3f\n", x*M_PI, cos(x*M_PI));
    printf("tan(%lf)= %.3f\n", x*M_PI, tan(x*M_PI));
    return 0;
}