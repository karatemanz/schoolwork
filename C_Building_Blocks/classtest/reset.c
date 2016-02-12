#include <stdio.h>


void reset(int *x);

int main(){

int data = 10;
reset(&data);
printf("The value of data: %i.\n", data);



return 0;
}

void reset(int  *x){
	*x = 0;
}
