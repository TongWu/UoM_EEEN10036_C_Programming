#include <stdio.h>
int main(void) {
    int year;
    printf("Enter a year to test: ");
    scanf("%d", &year);
    if (year%4==0) {
        if (year%100==0){
            if (year%400==0) {
                printf("%d IS a leap year", year);
            }
            else {
                printf("%d is not a leap year", year);
            }
        }
        else {
            printf("%d IS a leap year", year);
        }
    }
    else {
        printf("%d is not a leap year", year);
    }
    return 0;
}