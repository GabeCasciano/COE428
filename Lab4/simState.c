#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct node{
    char state;
    int pos; //pos will be used to identify which values are still accessible
    struct node* zero;
    struct node* one;
}node_t;

void garbage(node_t* garbage_list, node_t* current){//TODO: figure out how to do me
    //could do a checksum based on the new sum compared to the og sum we can determine which has been deleted
    //create a list of garbage
}
void _delete(node_t* deleted_list, node_t* current){//TODO: copy me from that tutorial
    //keep a list of deleted states to use for other methods
}
void change(int input_state, char node, node_t* current){//TODO: I should be a fun one

}
void print(node_t* current){//TODO: Copy me from that tutorial

}
void updateCurrent(int input, node_t* current){//think about how to migrate the list //TODO: might have to use multiple lists

}
void buildList(node_t* current){//TODO: do this the shitty way

}

int main(int argc, char * argv[])
{
    bool loop = true;
    char* input;
    while(loop){
        printf("Enter your command:");
        scanf('%c', input);
        switch (*input){//use the switch statment to determine which method to call
            case 'c': //change
                break;
            case 'g': //garbage
                break;
            case 'd': //delete
                break;
            case 'P': //print
                break;
            case '0': //update
            case '1':
                break;
            case 'e': //exit
                loop = false;
                break;
            default:
                printf("Please enter a valid command");
                break;
        }

    }
    exit(0);
}

