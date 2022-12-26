#include <stdio.h>

int main() {

  #define MAXCHAR 1000
  char x[MAXCHAR];int cont=0;
  for(int i=0;i<MAXCHAR && (x[i] =getchar()) != '\n';i++) {

    if(x[i]=='p' || x[i]== 'P'){
      cont++;
    }
  }

  printf("%d\n",cont);

  return 0;



}
