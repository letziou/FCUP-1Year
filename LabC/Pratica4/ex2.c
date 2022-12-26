#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

  int soma,a;

  for(int i=1;i<argc;i++){
    a = atoi(argv[i]);      // atoi() é uma função que transforma strings de numeros em ints
    soma += a;
  }

  printf("%d\n",soma);

  return 0;
}
