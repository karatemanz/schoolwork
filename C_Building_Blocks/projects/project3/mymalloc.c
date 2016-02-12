#include "mymalloc.h"
#include <stdio.h>

struct node *firstNode = NULL;
// TO DO: size_t running_size; // global size_t to eliminate call

void *my_firstfit_malloc(int size){
	
	struct node *new;

	if(size <= 0){ return NULL; }

	////////////////
	// HEAD CASE  //
	////////////////

	// if this is the first request
	if(firstNode == NULL){

		// !! the last chunk will be null in this case
		new = requesting(NULL, size);
		//printf("next %i\n", new->next == NULL);
		//printf("size %i\n", new->size);
		//printf("free %i\n", new->free);


		// if this is NULL the allocation was unsuccesfull
		if(!new){ return NULL; }

		// keep track of that first pointer will yah
		firstNode = new;

	return;

	/////////////////////////
	// MIDDLE / END CASES  //	
	/////////////////////////	

	}else{

		struct node *current = firstNode;
		//printf("%i\n", firstNode == NULL);
		if(firstNode == NULL){
			new = free_chunk(&current, size);
		}

		// if free_chunk can't find a free chunk
		if(!new){

			// request a chunk
			new = requesting(current, size);

			// if there is not enough memory
			if(!new){ return NULL; }

		// you find an existing free chunk
		}else{
			new->free = 0;
		}

		// returns the address of new block
		return (new + 1);
	}
}	

void my_free(void *ptr){

	if(!ptr){
		return;
	}

	int decrement;
	struct node *current_ptr = get_chunk(ptr);

	// catches a null node location
	if(current_ptr == NULL){ return; }
	// catches a node that's already free
	if(current_ptr->free == 1){ return; }

	decrement = (current_ptr->size + sizeof(struct node));
	void *dealloc = sbrk(-decrement);
	
	// deallocation unsuccessful
	if(dealloc == (void *) -1){ return; }

	//printf("[dec] %p\n", (int) &dealloc);
	//printf("%i\n", current_ptr->previous == NULL);
	//printf("%p\n", sbrk(0));

	if(current_ptr->next == NULL){
		current_ptr = NULL;
	}else{
		current_ptr->next = current_ptr->previous;
		current_ptr->free = 1;
	}

}

struct node *requesting(struct node *last, size_t size){

	struct node *new;
	int increment = size + sizeof(struct node);

	new = sbrk(0);
	void *alloc = sbrk(increment);

	// unsuccesfull memory allocation
	if(alloc == (void *) -1){ return NULL; }
	
	new = (struct node *) alloc;
	new->size = size;
	new->next = NULL;
	new->previous = last;
	new->free = 0;
	
	return new;

}


struct node *free_chunk(struct node **last, size_t size){

	struct node *current = firstNode;

	while(current || !(current->free && current->size >= size)){
		*last = current;
		current->previous = *last;
		current = current->next;
	}

	if(current == NULL){
		return NULL;
	}

	return current;

}

struct node *get_chunk(void *ptr){

	struct node *find = (struct node*) ptr;

	if(find == NULL){ return NULL; }

	return find;

}

