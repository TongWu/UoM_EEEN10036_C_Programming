/*Calculate resistence by resistence=(resistivity*length)/area*/
#include <stdio.h>

int main(void) {
    /*use double*/
	double resistivity = 1.3;
	double length = 3.4;
	double area = 3.4;
	double resistence = (resistivity * length) / area;
	printf("Resistivity: %.1f Length: %.1f Area: %.1f Resistence: %f", resistivity, length, area, resistence);
	return 0;
}