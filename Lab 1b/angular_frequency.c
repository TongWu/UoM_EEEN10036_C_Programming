//angular frequency=2pif
#include <stdio.h>
int main(void) {
	double pi = 3.1415926;
	double f = 3.456;
	double omega = 2 * pi * f;
	printf("pi: %f, f: %f, angular frequency: %f", pi, f, omega);
	return 0;
}