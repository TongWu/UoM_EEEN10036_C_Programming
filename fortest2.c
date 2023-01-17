#include <stdio.h>
int main(void) {
    int n;
    printf("Enter a value for n:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
{
    printf("%d", i); /* legal: i is visible inside loop */
} /* end for loop  */
}