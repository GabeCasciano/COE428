//Gabriel Casciano, 500740076, Lab 5
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//Include from intStack.c
extern int pop();
extern void push(int);
extern int isEmpty();

int main(int argc, char * argv[]) {
    int ch;
    int previous_char = 0;
    int counter [2][100];//counts how many of each ch have been used

    for(int i = 0; i < 100; i++) { //init the array with all zeros
        counter[0][i] = 0;
        counter[1][i] = 0;
    }

    while ((ch = getchar()) != '\n') {
        if(ch == '<'|| ch == '/')
            previous_char = ch;
        else if(isalpha(ch)){
            if(previous_char != '/') {
                for (int i = 0; i < 100; i++){//counts all of the elements in the array
                    if(counter[0][i] == ch) {//if it already finds that the current element exists
                        counter[1][i]++;//it increases the count for that element
                        break;
                    }
                    else if(counter[0][i] == 0){//if the current element of the array is 0, then the current char does not exist in it yet
                        counter[0][i] = ch; //adds the char
                        counter[1][i]++; //increases the count
                        break;
                    }
                }
                push(ch);
            }
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
    else {
        printf("Valid \n");
        for (int i = 0; i < 100; i++){//prints the array until it finds a zero (empty index)
            if(counter[0][i] != 0)
                printf("%c %d \n", counter[0][i], counter[1][i]);
            else
                break;
        }
    }
    exit(0);
}
