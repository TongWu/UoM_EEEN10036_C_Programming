//material's resistivity=electric field/current density
#include <stdio.h>
int main(void) {
	double E=2.3;
	double J=3.44;
	double resistivity=E/J;
	printf("Resistivity: %.3f Ohm-meters", resistivity);
	return 0;
}