#include "mymalloc.h"
#include <stdio.h>

struct node *firstNode = NULL;

void *my_firstfit_malloc(int size){
	
	int brk;
	struct node *newNode, *curNode, *leftoverNode, *preNode;	

	if(size == 0){ return 0; }
	brk = (int) sbrk(size + sizeof(struct node));

	// creation of a new node to allocate to memory 
	printf("Allocation: Size %i: Start 0x%x: End 0x%x \n", size, brk, sbrk(0));

	newNode->size = size;
	newNode->start = brk;
	newNode->end = (int) sbrk(0);
	newNode->alo = 1;

	printf("[check] start: 0x%x end: %x \n", newNode->start, newNode->end)

	if(firstNode == NULL){
		firstNode = newNode;
		firstNode->next = NULL;
		return;
	}
	
	curNode = firstNode;

	////////////////
	// HEAD CASES //
	////////////////

	

	// if the next node after the first node is NULL
	// we are already at the end of the allocation chain
	if(curNode->next == NULL){

		// checks if the node is allocated yet
		if(curNode->alo){

			printf("HIT A");
			newNode->previous = curNode;
			curNode->next = newNode;
			newNode->next = NULL;
			return; // add node to end of curNode chain
					// points to end of chain

		// if this node is unallocated	
		}else{


			printf("HIT B");
			// new node is equal to unallocated segment
			if(curNode->size == newNode->size){

				curNode->alo = 1;
				firstNode = curNode;
				return;	// the space requested is available
						// so it is immediately allocated and
						// first node pointer is secured

			// new node is smaller than unallocated segment
			}else if(curNode->size >= newNode->size){

				leftoverNode->size = (curNode->size - newNode->size);
				leftoverNode->start = newNode->end;
				leftoverNode->end = curNode->end;
				leftoverNode->alo = 1;
				leftoverNode->next = NULL;

				newNode->next = leftoverNode;
				firstNode = newNode;
				leftoverNode->previous = newNode; 
				return;	// makes a leftover node of the remaining
						// size of the node to be allocated then
						// sets the starting and ending location
						// based on where the newNodes end(start) 
						// to the curNodes end(end) then changes
						// first node to newNode and connects
						// the leftover node accordingly

			// new node is too big for unallocated segment
			}else if(curNode->size <= newNode->size){

				newNode->next = NULL;
				firstNode = newNode;
				return;	// makes a new first node pointer 
						// of a bigger size due to this being
						// the end of the memory change
			}
		}

		
	}

	//////////////////
	// MIDDLE CASES //
	//////////////////

	// while there is still nodes in the chain 
	while(curNode->next != NULL){

		printf("MIDDLE");

		// checks if cur node is allocated or not
		if(curNode->alo){

			curNode = curNode->next;
			// precedes to next node because 
			//current node is allocated

		// else the cur node is not allocated	
		}else{

			// new node is equal to unallocated segment
			if(curNode->size == newNode->size){

				curNode->alo = 1;
				return;	// makes the curNode is now allocated
						// and nothing else needs changed

			// new node is smaller than unallocated segment
			}else if(curNode->size >= newNode->size){

				//  ...]<-->[      |       |      ]<-->[...
				//  ...]<-->[   |   |   ]<->[ | | ]<-->[...
				//  (prev)      (new)        (left)    (next)

				leftoverNode->size = (curNode->size - newNode->size);
				leftoverNode->start = newNode->end;
				leftoverNode->end = curNode->end;

				// checks just in case cur node is first node
				// in chain **this shouldnt be**
				if(curNode->previous == NULL){
					firstNode = newNode; 
				}else{
					newNode->previous = curNode->previous;
				}

				newNode->next = leftoverNode;
				leftoverNode->previous = newNode;
				leftoverNode->next = curNode->next; 
				return;	// makes a leftover node of the remaining
						// size of the node to be allocated then
						// sets the starting and ending location
						// based on where the newNodes end(start) 
						// to the curNodes end(end) then changes
						// first node to newNode and connects
						// the leftover node accordingly

			// new node is too big for unallocated segment
			}else if(curNode->size <= newNode->size){

				curNode = curNode->next;
				// moves on to the next node that may be bigger
			}
		}
	}

	//////////////////
	//  END CASES	//
	//////////////////


	// this would mean that the loop has itterated through
	// the whole memory chain and has hit the end
	if(curNode->next == NULL){

		printf("END");

		// check if final node is allocated or not
		if(curNode->alo){

			curNode->next = newNode;
			newNode->next = NULL;
			return;	// immediately allocated memory to end
					// of memory chain

		// else if the node is unallocated
		}else{

			// new node is equal to unallocated segment
			if(curNode->size == newNode->size){

				curNode = newNode;
				curNode->next = NULL;
				return;	// makes the curNode the newNode
						// and points to null 

			// new node is smaller than unallocated segment
			}else if(curNode->size >= newNode->size){

				leftoverNode->size = (curNode->size - newNode->size);
				leftoverNode->start = newNode->end;
				leftoverNode->end = curNode->end;

				// checks just in case cur node is first node
				// in chain **this shouldnt be**
				if(curNode->previous == NULL){
					firstNode = newNode; 
				}else{
					newNode->previous = curNode->previous;
				}

				newNode->next = leftoverNode;
				leftoverNode->previous = newNode;
				leftoverNode->next = NULL; 
				return;	// makes a leftover node of the remaining
						// size of the node to be allocated then
						// sets the starting and ending location
						// based on where the newNodes end(start) 
						// to the curNodes end(end) then changes
						// first node to newNode and connects
						// the leftover node accordingly

			// new node is too big for unallocated segment
			}else if(curNode->size <= newNode->size){

				curNode->next = newNode;
				newNode->next = NULL;
				return;
				// adds new node on tail end of memory chain
			}
		}
	}

	// if it hits this portion I believe the first node is lost
	printf("[ISSUE WITH FIRST NODE POINTER]\n");

}



void my_free(void *ptr){


	struct node *curNode, *leftoverNode;

	printf("ptr value: %i \n", (int) ptr);

	////////////////
	// HEAD CASES //
	////////////////
	
	if(firstNode == NULL){ 
		printf("NO NODES IN MEMORY CHAIN TO FREE\n");
		return; 
	}

	curNode = firstNode;

	//////////////////
	// MIDDLE CASES //
	//////////////////
	
	while(curNode->next != NULL){
		
		if(curNode->alo && curNode->start == (int) ptr){
			
			//deallocates the desired chunk of memory
			sbrk((curNode->end * -1));
			curNode->alo = 0;
			return;
			
		}else{
			
			printf("This chunk is already deallocated");
			
		}
		
	}
	
	///////////////
	// END CASES //
	///////////////

	if(curNode->next == NULL){
		
		printf("You have reached the end of the chain and the memory segment you are looking for is non-existent");
		return;
		
	}
	
}
