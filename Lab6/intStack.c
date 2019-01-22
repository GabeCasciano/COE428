//Gabriel Casciano, 500744076
#include <stdio.h>
#include <stdlib.h>
static int top = 0;
static int stack[1000];

int pop()
{
	int temp = stack[top];
	top --;
	return temp;
}

/**
 *  push(thing2push) adds the "thing2push" to the top of the stack.
 *
 *  If there is no more space available on the Stack, an error
 *  message is printed to stderr.
 */
void push(int thing2push)
{
	if(top == 999){
		printf("exceeded size");
		exit(1);
	}
	stack[top+1] = thing2push;
	top ++;
}

/**
 * isEmpty() returns a non-zero integer (not necessarily 1) if the
 * stack is empty; otherwise, it returns 0 (zero).
 *
 */
int isEmpty()
{
	if(top == 0)
		return 1;
	return 0;
}


void printStack(){
	int i;
	for(i=0; i<top; i++)
		printf("%d\n",stack[i]);

}

