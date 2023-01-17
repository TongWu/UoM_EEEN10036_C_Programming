#include <stdio.h>
int main(void) {
    double length, area, field, density;
    printf("Enter a value for length: ");
    scanf("%lf", &length);
    printf("Enter a value for cross-sectional area: ");
    scanf("%lf", &area);
    printf("Enter a value for electric field: ");
    scanf("%lf", &field);
    printf("Enter a value for current density: ");
    scanf("%lf", &density);
    printf("Resistivity: %.3f Ohm-meters.\n", field/density);
    printf("Resistance: %.3f Ohm.", (field/density)*length/area);
    return 0;
}