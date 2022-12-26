#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
  for(int i=1;i<argc;i++){
    printf("%s -> %ld\n",argv[i],strlen(argv[i]));
  }
  return 0;
}