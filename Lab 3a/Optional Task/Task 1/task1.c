#include <stdio.h>
int main(void) {
    int i, j;
    printf("Enter the value of i:");
    scanf("%d", &i);
    printf("Enter the value of j:");
    scanf("%d", &j);
    if ((-i)/j==-(i/j)) {
        printf("The value (-i)/j is equal to the value -(i/j)");
    }
    else {
        printf("The value (-i)/j is not equal to the value -(i/j)");
    }
    return 0;
}