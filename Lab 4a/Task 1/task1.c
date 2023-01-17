#include <stdio.h>
int main(void) {
    double number;
    double greatest;
    while (number > 0)
    {
        printf("Enter a value to compare: ");
        scanf("%lf", &number);
        if (number > greatest) {
            greatest=number;
        }
    }
    printf("The greatest number is %lf", greatest);
    return 0;
}