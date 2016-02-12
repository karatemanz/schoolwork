#include <stdio.h>

int addInt(int, int);
int subInt(int, int);

int main(){

int x = 10, y = 5;
printf("%i + %i = %i.\n", x, y, addInt(x,y));
printf("%i - %i = %i.\n", x, y, subInt(x,y));
return 0;

}
