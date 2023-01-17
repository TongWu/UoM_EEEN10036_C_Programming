//k.e=1/2*m*v*v
#include <stdio.h>
int main(void) {
	double mass = 2.4;
	double velocity = 5.88;
	double ke = 0.5 * mass * velocity * velocity;
	printf("Mass: %f Velocity: %f ke: %f", mass, velocity, ke);
	return 0;
}