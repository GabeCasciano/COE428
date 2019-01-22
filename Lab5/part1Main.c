#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int pop();
extern void push(int);
extern int isEmpty();

int main(int argc, char * argv[]) {
    int ch;
    int previous_char;
    while ((ch = getchar()) != '\n') {
        if(ch == '<'|| ch == '/')
            previous_char = ch;
        else if(isalpha(ch)){
            if(previous_char != '/')
                push(ch);
            else if(pop() != ch){
                printf("NOT Valid");
                exit(1);
            }
        }
    }
    if(isEmpty() > 0){
        printf("NOT Valid");
        exit(1);
    }
    else
        printf("Valid");
    exit(0);
}
