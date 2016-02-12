#include <stdio.h>
#include <stdlib.h>

struct list
{
	int numberOfEntries;
	struct node *firstNode;
};

struct node
{
	int data;
	struct node *next;
};

/* Allocates a chunk of memory the same size as struct list,
 * initializes the numberOfEntries to 0, initialize the fistNode
 * to NULL, and returns the address of type pointer to struct list.
 */
struct list *constructList()
{

	struct list *newList = (struct list *) malloc(sizeof(struct list));
	newList->numberOfEntries = 0;
	newList->firstNode = NULL;

	return newList;

}

/* Add newEntry to the end of of the given aList.
 */
void add(struct list *aList, int newEntry)
{

	struct node *currentNode, *newNode;

	// i make a new node in both cases so i allocated memory 
	// up here :)
	newNode = (struct node *) malloc(sizeof(struct node));
	currentNode = aList->firstNode;

		// the current node is the first node woohoo!
		if(currentNode == NULL){

			// make a new node
			newNode->data = newEntry;
			newNode->next = NULL;
			aList->firstNode = newNode;

		// add a node to the tail end of the list	
		}else{

			// cycle list to next available slot (a null node)
			// **checked both current and next to be sure (you know
			// how pointers are)**
			while(currentNode != NULL && currentNode->next != NULL){
				currentNode = currentNode->next;
			}

			// allocate memory to add to currentNodes next node 
			currentNode->next = (struct node *) malloc(sizeof(struct node));
			newNode->data = newEntry;
			// since this is at the end point newNode to null
			newNode->next = NULL;
			
			// and finall link current node to the new node
			currentNode->next = newNode;

		}

	// and of course increment the entry count
	aList->numberOfEntries++;

}

/* Returns the address of the node associate with the
 * given index of the given aList.
 */
struct node *getNodeAt(struct list *aList, int index)
{

	int i = 0;
	struct node *currentNode;
	currentNode = aList->firstNode;

	// cycle list to proper index 
	while(i != index){
		currentNode = currentNode->next;
		i++;
	}

	// return that puppy
	return currentNode;

}

/* Returns the data at the given index of the given aList.
 * DO NOT MODIFY THIS FUNCTION.
 */
int get(struct list *aList, int index)
{
	return getNodeAt(aList, index)->data;
}

/* Removes an entry at the given index from the give aList,
 * and returns the data from the removed index.
 */
int removeEntry(struct list *aList, int index)
{

	int i = 0, value;
	struct node *currentNode;

	// link to first node of list
	currentNode = aList->firstNode;

	// cycle through list to the node before index node
	while(i < index-1 && currentNode->next != NULL){

		currentNode = currentNode->next;
		i++;	
	}


		// removing first node
		if(index == 0){

			//printf("[FIRSTNODE]");

			//point first node to next node in list(if 
			// there is one) and stores data in value
			aList->firstNode = currentNode->next;
			value = currentNode->data;

		// removing last node	
		}else if(index == (aList->numberOfEntries-1)){

			//printf("[LASTNODE]");

			// store value of next node and then set current
			// node pointing to null 
			value = currentNode->next->data;
			currentNode->next = NULL;

		// simple remove node
		}else{
			
			//printf("[MIDDLENODES]");

			// store value of next node and the set the
			// next node to the node following the next one
			value = currentNode->next->data;
			currentNode->next = currentNode->next->next;

		}
	
	// decrement entry
	aList->numberOfEntries--;
	return value;

}

/* Print information and contents of a given aList.
 * DO NOT MODIFY THIS FUNCTION.
 */
void printList(struct list *aList)
{
	struct node *currentNode;
	currentNode = aList->firstNode;
	printf("The given list contains %i entries: ", aList->numberOfEntries);
	while(currentNode != NULL)
	{
		printf("%i ", currentNode->data);
		currentNode = currentNode->next;
	}
	printf("\n");
}

/* This is a simple test program. Note that you should write
 * your own test program when you are implementing above functions.
 * When you think that all your functions work correctly, use this
 * main function.
 */
int main(void)
{
	struct list *myList;
	int i;

	myList = constructList();

		// for readability
		printf("\n");

	for(i = 0; i < 5; i++)
	{
		printf("Adding %i\n", i);
		add(myList, i);
		printList(myList);
	}

	printf("\n");

	printf("Remove index 0 (first node on the link chain)\n");
	i = removeEntry(myList,0);
	printf("The function removeEntry returns %i.\n", i);
	printList(myList);

		// for readability
		printf("\n");

	printf("Remove index 3 (last node on the link chain)\n");
	i = removeEntry(myList,3);
	printf("The function removeEntry returns %i.\n", i);
	printList(myList);

		// for readability
		printf("\n");

	printf("Remove index 1 (middle node on the link chain)\n");
	i = removeEntry(myList,1);
	printf("The function removeEntry returns %i.\n", i);
	printList(myList);

		// for readability
		printf("\n");


		// man-o-day segmentation faults are the worst
		// oh well live and learn
	return 0;
}
