//power=voltage*voltage/resistence
#include <stdio.h>

int main(void) {
	double voltage = 2.33;
	double resistence = 3.44;
	double power = voltage * voltage / resistence;
	printf("Voltage: %f, Resistence: %f, Power: %f", voltage, resistence, power);
	return 0;
}