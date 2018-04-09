#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern char *  pop();
extern void push(char *);
extern void isEmpty();

int main(int argc, char * argv[])
{
  int ch;
  while ((ch = getchar()) != EOF) {
    if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
      continue;
    //
    
    
    
  }
  exit(0);
}
