/*Calculate resistence by resistence=(resistivity*length)/area*/
#include <stdio.h>

int main(void) {
    /*use double*/
	double resistivity = 211.312;
	double length = 323.424;
	double area = 3.476;
	double resistence = (resistivity * length) / area;
	printf("Resistivity: %.3f Length: %.3f Area: %.1f Resistence: %2.3f", resistivity, length, area, resistence);
	return 0;
}