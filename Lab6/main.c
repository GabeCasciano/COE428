//Gabriel Casciano, 500744076
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

extern int pop();
extern void push(int);
extern void addHeap(int);
extern int getSize();
extern void printTree(int);
extern int heapDelete();
extern void printStack();
extern void sortHeap(int);

int main(int argc, char * argv[]) {
	char value[100];
	int start, i, tagCnt = 0;
	fgets(value, 100, stdin);//scanf was giving me a hardtime so I
	//switched to this.
	while (strcmp(value , "-d\n") != 0) {//checks for the ending char 
		addHeap(atoi(value));
		tagCnt++;
		fgets(value, 100, stdin);
	}

	start = (getSize() - 1) / 2;

	for (i = start; i >= 0; i--)
		sortHeap(i);

	printf("\n");
	printTree(0);
	printf("\n");

	for (i = 0; i < tagCnt; i++) {
		int deleted = heapDelete();
		push(deleted);
	}
	printf("\n");

	for(i = 0; i<tagCnt; i++)
		printf("%d\n", pop());
	printf("\n");

	printStack();
  	exit(0);
}
