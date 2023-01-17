#include <stdio.h>
#include <complex.h>
#include <math.h>
int main(void) {
    double complex z1=1.0+2.0*I;
    double complex z2=1.0-4.0*I;
    printf("z1=%.2f+(%.2fi)\n", creal(z1), cimag(z1));
    printf("z2=%.2f+(%.2fi)\n", creal(z2), cimag(z2));
    printf("z1+z2= %.2f+(%.2fi)\n", creal(z1)+creal(z2), cimag(z1)+cimag(z2));
    printf("z1*z2= %.2f+(%.2fi)", creal(z1)-(cimag(z1)*cimag(z2)), creal(z1)*cimag(z2)+cimag(z1)*creal(z2));
    return 0;
}