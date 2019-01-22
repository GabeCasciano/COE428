//Gabriel Casciano, 500744076
#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

int size = 0;
int heap[1000];

/**
 *  addHeap(thing2add) adds the "thing2add" to the Heap.
 *
 */
void addHeap(int thing2add)
{
	heap[size] = thing2add;
	size++;
}

void sortHeap(int p)
{
	int temp;
	int left = (2*p) + 1;
	int right = (2*p) + 2;
	int max = p;

	if((left < size) && (heap[left] > heap[max]))
		max = left;

	if((right < size) && (heap[right] > heap[max]))
		max = right;

	if(max != p) {
		temp = heap[max];
		heap[max] = heap[p];
		heap[p] = temp;
		sortHeap(max);
	}
}


int heapDelete(){
	int temp;
	size--;
	temp = heap[0];
	heap[0] = heap[size];
	heap[size] = temp;
	sortHeap(0);
	printf("%d\n",heap[size]);
	return heap[size];
}

void printTree(int p){
	int left = (2*p) + 1;
	int right = (2*p) + 2;

	printf("<node id='%d'>", heap[p]);
	if(left<size)
		printTree(left);

	if(right<size)
		printTree(right);

	printf("</node>");
}

int getSize()
{
  return size;
}
