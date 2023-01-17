#include <stdio.h>
int main(void) {
    printf("Enter the value x:");
    int x;
    scanf("%d", &x);
    //printf("0<x<100 evaluates to %d", x<100 && x>0);
    if (x<100 && x>0) {
    printf("The value of x lie on the limit between 0 to 100");
    }
    else if  (x>100) {
    printf("The value of x is bigger than 100");
    }
    else if (x<0) {
        printf("The value is smaller than 0");
    }
    else if (x==0) {
        printf("The value equal to 0");
    }
    else {
        printf("The value equal to 100");
    }
    return 0;
}