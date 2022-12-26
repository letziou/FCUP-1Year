#include <stdio.h>
#include <string.h>
#define MAX_LISTA 1000


  struct pessoa{
    char* nome;
    char* telefone;
  };

  typedef struct pessoa PESSOA;

  PESSOA lista[MAX_LISTA] = {{"rui","226664441"},
                             {"ana","214444444"}};
  int n = 2;


  int pesquisa(char *pal){
    for(int i=0 ;i<n; i++){
      if(strstr(lista[i].nome, pal) != NULL)
      return i;
    }
    return -1;
  }

  int pesqui(int j, char* pal){
    for (int i=j ;j<n; j++){
      if(strstr(lista[i].nome, pal) != NULL)
      return i;
    }
    return -1;
  }

  


  int main(int argc, char const *argv[]) {



    return 0;
  }
