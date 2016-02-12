#include "mymalloc.h"
#include <stdio.h>


int main(void){

	int data;

	printf("brk->before_malloc: %p\n", sbrk(0));

	data = (int) my_firstfit_malloc(sizeof(int));

	printf("brk->after_malloc: %p\n", sbrk(0));

	printf("Data %p \n", data);

	my_free(&data);

	printf("brk->after_free: %p\n", sbrk(0));


}
