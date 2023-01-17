//combine the resistance and the resistivity into one program
#include <stdio.h>
int main(void) {
    double E=2.3;
	double J=3.44;
	double material_resistivity=E/J;
	printf("Material's Resistivity: %.3f Ohm-meters\n", material_resistivity);
    double resistivity = 211.312;
	double length = 323.424;
	double area = 3.476;
	double resistance = (resistivity * length) / area;
	printf("Resistance: %.3f Ohms", resistance);
	return 0;
}