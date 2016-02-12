#include <stdio.h>

int main(){

int x = 10;
int y = 20;
int *yptr;

printf("The value of X is %i.\n", x);
printf("X variable address is %p.\n", &x);

yptr = &y;

printf("The value of Y is %i.\n", y);
printf("Y variable address is %p.\n", yptr);

*yptr = 22;

printf("New dereference Y equals: %i.\n", y);

y = 32;

printf("New Y equals: %i.\n", y);


}
