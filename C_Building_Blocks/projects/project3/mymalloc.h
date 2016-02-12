#include <unistd.h>

void *my_firstfit_malloc(int size);
void my_free(void *ptr);
// extra needed dependencies
struct node *requesting(struct node *last, size_t size);
struct node *free_chunk(struct node **last, size_t size);
struct node *get_chunk(void *ptr);

struct node{

	int size;
	int free;		// allocation: 0->unallocated 1->allocated
	struct node *next;
	struct node *previous;	

};

