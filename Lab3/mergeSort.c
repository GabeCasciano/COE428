//Gabriel Casciano, 500744076
#include "mySort.h"
#include "metrics.h"
#include <stdio.h>
#include <string.h>

void merge(int array[], int first, int middle, int last){
    int left[middle];
    int right[last - middle];

    for(int z = 0; z < middle; z++) {
        myCopy(&array[z], &left[z]);
        array[z] = 0;
    }
    for(int z = middle; z < last; z++) {
        myCopy(&array[z], &right[z]);
        array[z] = 0;
    }

    int i, j, k;

    i = 0;
    j = 0;
    k = 0;

    while(i < middle && j < last){
        if(myCompare(left[i],right[j]) <= 0){
            myCopy(&left[i], &array[k]);
            i++;
            k++;
        }
        else{
            myCopy(&right[j], &array[k]);
            j++;
            k++;
        }
    }

    for(int z = i; z < middle; z++) {
        myCopy(&left[z], &array[k]);
        k++;
    }
    for (int z = j; z < last - middle; z++){
        myCopy(&right[z], &array[k]);
        k++;
    }
}
void mySort(int array[], unsigned int first, unsigned int last){
	int middle = 0;
    if(last - first <= 2){
        middle  = (last + first) / 2;
        mySort(array, first, middle);
        mySort(array, middle, last);
        merge(array, first, middle, last);
    }
}
