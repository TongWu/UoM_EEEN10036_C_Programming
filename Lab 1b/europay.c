#include <stdio.h>

int main(void) {
	int total = 93;
	int fifty = total / 50;
	int twenty = (total % 50)/20;
	int ten = (total % 50) % 20 / 10;
	int five = ((total %50) %20 ) %10 / 5;
	int one= (((total % 50) % 20) % 10) % 5 / 1;
	//first print the total amount of euro
	printf("Amount in euros: %d\n", total);
	//then print the amount of 50 euro notes
	printf("50 Euro notes: %d\n", fifty);
	printf("20 Euro notes: %d\n", twenty);
	printf("10 Euro notes: %d\n", ten);
	printf("5 Euro notes: %d\n", five);
	printf("1 Euro coins: %d\n", one);
	return 0;
}