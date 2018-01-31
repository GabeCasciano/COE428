#include <stdlib.h>
#include <stdio.h>
#include "towers.h"

int main(int argc, char **argv)
{
	int n = 3;
	int from = 1, dest = 2;
	int temp;
	if(argc == 2)
		n = atoi(argv[1]);
	else if(argc >= 3){
		n = atoi(argv[1]);
		from = atoi(argv[2]);
		temp = atoi(argv[3]);
		if(temp != from)
			dest = temp;
		else{
			fprintf(stderr,"INCORRECT INPUT");
			exit(0);
		}
	}
	towers(n, from, dest);
    	exit(0);
}

