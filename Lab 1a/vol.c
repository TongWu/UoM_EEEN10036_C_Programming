#include <stdio.h>

int main(void) {
	/*declare and initialise variables*/
	int height = 22, length = 5, width = 2, volume;
	/*calculate volume*/
	volume = height * length * width;
	/*print variables and result*/
	printf("Height: %d Length: %d Width: %d Volume: %d", height, length, width, volume);
	return 0;
}