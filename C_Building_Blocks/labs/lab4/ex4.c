#inlcude <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node{

int data;
struct node *next;

};

struct stack{

struc node *firstNode;

};

void push(int data, struct stack *aStack){

struct node *newNode = (struct node *) malloc(sizeof(struct node));

// fill new node with appropriate data and stacks original first node
tempNode->data = data;
tempNode->next = aStack->firstNode;

aStack->firstNode = *newNode;

}

struct node pop(){



}

int main(void){

// STACK (linked list) //
struct stack *myStack;

myStack = (struct stack *) mallock(sizeof(struct stack));
myStack->firstNode = NULL: // used for pointers



return 0;
}
