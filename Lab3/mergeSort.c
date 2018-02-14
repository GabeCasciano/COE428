//Gabriel Casciano, 500744076
#include "mySort.h"
#include <limits.h>
#include "metrics.h"

void merge(int array[], int first, int last, int middle){
	int leftIndex =  last - first + 1;
	int rightIndex = middle - last;

	int leftArray[leftIndex + 1];
	int rightArray[rightIndex + 1];

	for(int i = 0; i < leftIndex; i++)
		myCopy(&array[first + i - 1], &leftArray[i]);
	for(int i = 0; i < rightIndex; i++)
		myCopy(&array[last + i], &rightArray[i]);
	
	leftArray[leftIndex + 1] = INT_MAX;
	rightArray[rightIndex + 1] = INT_MAX;

	int i=1, j=1;
	
	for(int k = first - 1; k < middle; k++){
		if(myCompare(leftArray[i], rightArray[j]) <= 0){
			myCopy(&leftArray[i], &array[k]);
			i++;
		}
		else if(myCompare(array[k], rightArray[j]) == 0){
			myCopy(&rightArray[j], &array[k]);
			j++;
		}
	}
}
void mySort(int array[], unsigned int first, unsigned int last){
	int doSort = 0;
	for(int i = 0; i < last - 1; i++)
		if(myCompare(array[i],array[i+1])>0){ doSort = 1; } 
	if(first < last && doSort == 1){
		int  middle = (first + last)/2;
		mySort(array, first, middle);
		mySort(array, middle + 1, last);
		merge(array, first, last, middle);
	}    
}
