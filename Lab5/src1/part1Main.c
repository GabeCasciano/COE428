//Gabriel Casciano, 500744076, Lab 5
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//Imports from intStack.c
extern int pop();
extern void push(int);
extern int isEmpty();

int main(int argc, char * argv[]) {
    int ch;
    int previous_char; //used as a temp var
    while ((ch = getchar()) != '\n') {//check ch is not at the end of the line
        if(ch == '<'|| ch == '/')
            previous_char = ch;
        else if(isalpha(ch)){
            if(previous_char != '/')//push to stack
                push(ch);
            else if(pop() != ch){//pop from stack and check
                printf("NOT Valid");
                exit(1);
            }
        }
    }
    if(isEmpty() > -1){//if the stack is not empty a character was not terminated, Not valid
        printf("NOT Valid");
        exit(1);
    }
    else
        printf("Valid");
    exit(0);
}
