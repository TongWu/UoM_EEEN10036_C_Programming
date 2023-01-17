#include <stdio.h>
int main(void) {
    printf("Use decimal format to display 86 and 1040:\n");
    printf("%6d,%4d\n", 86, 1040);
    printf("Use exponential format to display 30.253: \n");
    printf("%12.5e\n", 30.253);
    printf("Use fixed decimal format to display 83.612: \n");
    printf("%.4f\n", 83.612);
    printf("Use either exponential format or fixed decimal format to display 0.0000001: \n");
    printf("%-6.2g", 0.000001);
    return 0;
}
