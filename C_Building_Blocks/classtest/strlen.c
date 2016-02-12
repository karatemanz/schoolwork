#include <stdio.h>
#include <string.h>

int main(){

	char str[] = "Hello World";
	char cpy[100];
	int length;

	length = strlen(str);

	strcpy(cpy, str);

	printf("Length: %i\n", length);
	printf("Copy: %s\n", cpy);


return 0;
}
