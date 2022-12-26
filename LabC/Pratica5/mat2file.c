#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc,char* argv[]){

  FILE* f;
  int k=0;

  f = fopen(argv[3],"w");

  fprintf(f, "%s %s\n",argv[1],argv[2] );

  for(int j=4;j<argc;j++){
    fprintf(f, "%s ",argv[j]);
    k++;
    if(k == atoi(argv[2])){
      fprintf(f, "\n" );
      k=0;
    }
  }

  fclose(f);

  return 0;
}
