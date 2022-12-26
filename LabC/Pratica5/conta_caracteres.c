#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc , char* argv[]){          // não usar r+ !!!!!!! 

  FILE* buf;
  FILE* demo;
  int count = 0;

  demo = fopen(argv[1],"r");
  buf = fopen(argv[2],"w");

  while(fgetc(demo) != EOF){
    count++;
  }

  fclose(demo);

  fprintf(buf,"O ficheiro tem %d caracteres !!\n",count);

  fclose(buf);

  return 0;
}
