// main.c
#include <stdio.h>
#include "simpleMath.h"

int main(void) {

	float r, result;

	printf("Enter a radius: ");
	scanf("%f", &r);
	
	result = circleArea(r);
	printf("The area is %.2f.\n", result);

return 0;
}