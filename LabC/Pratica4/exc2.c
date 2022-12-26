#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
  int count = 0;
  for(int i=1;i<argc;i++){
    count += atoi(argv[i]);
  }
  printf("%d\n",count);
  return 0;
}