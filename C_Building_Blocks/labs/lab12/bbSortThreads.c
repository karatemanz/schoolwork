#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>

#define NUMEL 10000


struct sortArgs{
	int *array;
	int elements;
};

/* bubbleSort(int *array, int n)
 *
 * Sort the first n elements of the array using
 * unoptimized bubble sort algorithm.
 */
void *bubbleSort(void *args)
{
	struct sortArgs *temp = (struct sortArgs *) args;
	int *array = (int *)temp->array;
	int n = (int)temp->elements;
	int i, j, tempN;

	for(i = 0; i < n - 1; i++)
	{
		for(j = 0; j < n - 1; j++)
		{
			if(array[j] > array[j + 1])
			{
				tempN = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tempN;
			}
		}
	}
}

/* genRandomIntArray(int numElements, int upperBound)
 *
 * Generates an array size numElements and fills the array
 * with random numbers between 0 (inclusive) to upperBound
 * (exclusive). Then returns the pointer to the array.
 */
int *genRandomIntArray(int numElements, int upperBound)
{
	int i;
	int * result = (int *) malloc(numElements * sizeof(int));

	for(i = 0; i < numElements; i++)
	{
		result[i] = rand() % upperBound;
	}

	return result;
}

/* getElapsedTime(struct timeval start, struct timeval stop)
 *
 * Get the elapsed time from start to stop in the form of struct timeval.
 */
struct timeval getElapsedTime(struct timeval start, struct timeval stop)
{
	struct timeval elapsedTime;
	elapsedTime.tv_sec = stop.tv_sec - start.tv_sec;
	elapsedTime.tv_usec = stop.tv_usec - start.tv_usec;
	if(elapsedTime.tv_usec < 0)
	{
		elapsedTime.tv_usec = elapsedTime.tv_usec + 1000000;
		elapsedTime.tv_sec = elapsedTime.tv_sec - 1;
	}
	return elapsedTime;
}


/* printArray(int *array, int numElements)
 *
 * Prints the first numElements of the array.
 */
void printArray(int *array, int numElements)
{
	int i;	

	for(i = 0; i < numElements; i++)
	{
		printf("%i ", array[i]);
	}
	printf("\n\n");
}

int main(void)
{
	int *array1;
	int *array2;
	int i;
	struct timeval startTime, endTime, elapsedTime;
	struct sortArgs s1Args, s2Args;
	pthread_t thread1, thread2;

	// Seed the random number generator

	srand(time(0));

	// Generate two integer array filled with random numbers
	// store arg1 and arg2 for the two threads

	array1 = genRandomIntArray(NUMEL,10000);
	array2 = genRandomIntArray(NUMEL,10000);

	s1Args.array = array1;
	s1Args.elements = NUMEL;

	s2Args.array = array2;
	s2Args.elements = NUMEL;

	// Sort two arrays simultaneously

	gettimeofday(&startTime, NULL);
	//bubbleSort(array1, NUMEL);
	//bubbleSort(array2, NUMEL);

	if(pthread_create(&thread1, NULL, bubbleSort, &s1Args)){
		printf("Error creating thread\n");
		return -1;
	}
	if(pthread_create(&thread2, NULL, bubbleSort, &s2Args)){
		printf("Error creating thread\n");
		return -1;
	}
	
	if(pthread_join(thread1, NULL)){
		printf("Error joining thread\n");
		return -1;
	}
	if(pthread_join(thread2, NULL)){
		printf("Error joining thread\n");
		return -1;
	}

	gettimeofday(&endTime, NULL);


	// Print the first 100 elements of each array

	printf("array1: ");
	printArray(array1, 100);
	printf("array2: ");
	printArray(array2, 100);

	// Show how long does it takes to sort two arrays

	elapsedTime = getElapsedTime(startTime, endTime);

	printf("Sorting Time: %li.%.6li seconds\n", elapsedTime.tv_sec, elapsedTime.tv_usec);

	return 0;
}
