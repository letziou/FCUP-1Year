#include <stdio.h>
#include <string.h>
#include <stdlib.h>


  FILE* abre_fich(char*s){
    FILE *fich;
    fich = fopen(s,"r");
    if(fich == NULL){
      return NULL;
    }
    return fich;
  }

  void mensagem(char* m){
    printf("%s\n",m);
    exit(0);
  }

  char* palavra(FILE *f){     // erro não sei obter a palavra
    char *buff = malloc(999*sizeof(char));
    fscanf(f,"%s",buff);
    return buff;
  }


int main(int argc, char* argv[]){

  FILE *fich;
  char *pal;

  if(argc != 2){
    mensagem("Uso: ./palavras ficheiro");
  }

  fich = abre_fich(argv[1]);


  while((pal = palavra(fich)) != NULL){
    printf("-----------\n");
    printf("%s\n", pal);
    free(pal);
  }
  return 0;
}
