#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX_SIZE 8
#define ADD_FOR_CHAR 65;

typedef struct node{
    int state; //pos will be used to identify which values are still accessible
    int zero;
    int one;
}node_t;

node_t** state_machine;
node_t* current;
node_t** garbage;
int** counter;

int ASCIIAdder(int val){ return val + ADD_FOR_CHAR; }

void garbage_collector(){
    int count[2] = {0,0};
    int temp;
    for(int i = 0; i < MAX_SIZE; i++){
        count[0] += state_machine[i]->zero;
        count[1] += state_machine[i]->one;
    }
    if(count[0] != *counter[0] && count[1] != *counter[0]){
        temp = *counter[0] - count[0];
        garbage[*counter[2]]-> state = temp;
        *counter[2]++;
    }
}
void change(int input, int state_change){
    if(state_change == 1)
        current->one =  input;
    else if(state_change == 0)
        current->zero = input;
    state_machine[current->state] = current;
    garbage_collector();
}
void print(){
    for(int i = 0; i < MAX_SIZE; i++)
        printf("%c %c %c \n", ASCIIAdder(state_machine[i]->state), ASCIIAdder(state_machine[i]->zero) , ASCIIAdder(state_machine[i]->one) );
}

void updateCurrent(int input){//think about how to migrate the list //TODO: might have to use multiple lists
    if(input == 1) {
        current = state_machine[current->one];
    }
    else if(input == 0){
        current = state_machine[current->zero];
    }
    printf("%c \n", ASCIIAdder(current->state));
}

void buildList(){
    *state_machine = calloc(sizeof(node_t), MAX_SIZE);
    *garbage = calloc(sizeof(node_t), MAX_SIZE);
    *counter = calloc(sizeof(int), 3);
    int zeros[MAX_SIZE] = {4,2,2,0,1,6,5,4};
    int ones[MAX_SIZE] = {6,3,7,5,3,1,2,0};
    for(int i = 0; i < MAX_SIZE; i++) {
        state_machine[i] = malloc(sizeof(node_t));
        garbage[i] = malloc(sizeof(node_t));
    }
    for(int i = 0; i < MAX_SIZE; i++){
        state_machine[i]->state = i;
        state_machine[i]->zero = zeros[i];
        state_machine[i]->one = ones[i];
        *counter[0] += zeros[i];
        *counter[1] += ones[i];
    }
}

int main(int argc, char * argv[])
{
    bool loop = true;
    char input[10];
    buildList();
    current = state_machine[7];
    printf(ASCIIAdder(current->state));
    while(loop){
        printf("Enter your command:");
        scanf("%s", input);
        switch (input[0]){//use the switch statment to determine which method to call
            case 'c': //change
                change(input[4]-MAX_SIZE, input[2]-MAX_SIZE);
                break;
            case 'g': //garbage
                break;
            case 'd': //delete
                break;
            case 'P': //print
                print();
                break;
            case '0': //update
            case '1':
                updateCurrent(atoi(input));
                break;
            case 'e': //exit
                loop = false;
                break;
            default:
                printf("Please enter a valid  \n");
                break;
        }

    }
    exit(0);
}

