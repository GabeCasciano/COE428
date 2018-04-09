#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//defines a boolean
typedef enum { FALSE, TRUE } boolean;

//part of the stack
extern char *  pop();
extern void push(char *);

//part of the hash
extern void add(char *);
extern int getCount();

void append(char * output, char input){
    output = realloc(output, strlen(output)+1);
    output[strlen(output)] = input;
}

int main(int argc, char * argv[])
{
    int ch;
    char * inputString = malloc(sizeof(char *));
    boolean toggle = FALSE;
    while ((ch = getchar()) != '\n') {//check ch is not at the end of the line
        if(ch == '<')
            toggle = FALSE;

        else if(ch == '/')
            toggle = TRUE;
        else if(ch == '>'){
            if(toggle == TRUE && strcmp(pop(), inputString) != 0) {
                printf("NOT VALID");
                exit(1);
            }
            else if(toggle == FALSE) {
                push(inputString);
                add(inputString);
            }
            free(inputString);
        }
        else if(isalpha(ch))
            append(inputString, ch);
    }
    getCount();
    exit(0);
}
