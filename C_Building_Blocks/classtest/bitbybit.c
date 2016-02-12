#include <stdio.h>

struct foo{

char c1, c2;
int x;

}

int main(){

	FILE *fp;

	struct foo x;

	fp = fopen("data.txt", "r");

	fread(&x, sizeof(struct foo), 1, fp);

	printf("%c\n", x.c1);
	printf("%c\n", x.c2);
	printf("%i\n", x.x);
	

	fclose(fp);	
return 0;
}
