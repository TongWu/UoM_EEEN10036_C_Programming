#include <stdio.h>

int main(void) {
	float distance = 22, time = 5.2;
	float speed;
	speed = distance / time;
		printf("Distance: %.0f, Time: %.0f, Speed: %.1f", distance, time, speed);
		return 0;
}