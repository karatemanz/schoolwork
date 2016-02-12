#include <stdio.h>
#include <stdlib.h>


struct data{

char type[4];
int x;
short int y;

};


int main(){

char file[] = "data.dat";
char c[4];
int x;
short int y;
struct data a[2];
FILE *fp = fopen("file", "r");

fread(&a, sizeof(struct data), 2, fp);
printf("type: %s\n", a[0].type);
printf("x: %i\n", a[0].x);
printf("y: %i\n", a[0].y);

fseek(fp, -2, SEEK_CUR);

printf("type: %s\n", a[1].type);
printf("x: %i\n", a[1].x);
printf("y: %i\n", a[1].y);


fclose(fp);

return 0;
}
