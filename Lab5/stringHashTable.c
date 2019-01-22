//  
//
//
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define HASH_TABLE_SIZE 1057
typedef struct Entry Entry, *EntryPtr;
struct Entry {
  char * string;
  int count;
};
Entry hash_table[HASH_TABLE_SIZE];

//static int hash_indexs[HASH_TABLE_SIZE];
//static int counter = 0;

void _init_(){
    for(int i = 0; i < HASH_TABLE_SIZE ; i++){
        hash_table[i].string = malloc(sizeof(char*));
        strcpy(hash_table[i].string, "");
    }
}

int hasher(char * tag){//implements the djb2 hashing algo
    int hash = 5381;
    int c = 0;

    while (c == *tag++){
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	}
    return hash % HASH_TABLE_SIZE; //minor modification, so that the values would map to the table
}
int search(char * tag){
    int hashVal = hasher(tag);
    for (int i = 0; i < HASH_TABLE_SIZE; ++i) {
        if (hash_table[hashVal].count == 0)
            return 0;
        else if (strcmp(hash_table[hashVal+i].string, "") != 0 && strcmp(hash_table[hashVal+i].string, tag) == 0)
            return hashVal+i;
    }
    return -1;

}
int findOpen(char * tag){
    int hashVal = hasher(tag);
    for (int i = HASH_TABLE_SIZE-hashVal; i < HASH_TABLE_SIZE; ++i) {
        if (hash_table[hashVal].count == 0)
            return hashVal;
        else if(strcmp(hash_table[hashVal+i].string, tag) !=0 && hash_table[hashVal+i].count == 0)
            return hashVal+i;
    }
    return 0;
}

void getCount(){
    for(int i = 0; i < HASH_TABLE_SIZE; i++){
        if(hash_table[i].count != 0)
            printf("<%s> , %d \n", hash_table[i].string, hash_table[i].count);
    }
}

void add(char * tag) {
    int check = search(tag);
    int openIndex;
    if(check != 0)
        hash_table[check].count++;
    else {
        openIndex = findOpen(tag);
        hash_table[openIndex].string = realloc(hash_table[openIndex].string, sizeof(char*)*strlen(tag));
        strcpy(hash_table[openIndex].string, tag);
        hash_table[openIndex].count++;
    }
}
