#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX 9999
#define MAXESPS 9999
#define MAXTRATS 9999
#define MAXANIMS 9999

typedef struct{
  int registo;
  int especie;
  int nascimento;  //ano mes dia
  char pais[NMAX];
  int bitratador;
}ANIMAL;

typedef struct{
  char nome[NMAX];
  int vida;
}ESPECIE;

typedef struct{
  int bi;
  int nasc;
  int tele;
  char nome[NMAX];
  char morada[NMAX];
}TRATADOR;

void carregaDados();
void contactar(int dataref);
int procura_tratador(int bi);

ESPECIE Especie[MAXESPS];
TRATADOR Tratador[MAXTRATS];
ANIMAL Animal[MAXANIMS];
int Ne,Nt,Na;

int main(int argc, char const *argv[]) {

  carregaDados();
  contactar(20120121);

  return 0;
}

void carregaDados(){}
int procura_tratador(int bi){
  for(int i=0;i<Nt;i++){
    if(Tratador[i].bi == bi)
      return i;
  }
  return -1;
}

void contactar(int dataref){
  int anos,t;
  for(int i=0;i<Na;i++){
    anos = idade_anos(Animal[i].nascimento,dataref);
    if(anos>Especie[Animal[i].especie].vida){
      t = procura_tratador(Animal[i].bitratador);
    }
    printf("%s %d %d",Tratador[t].nome,Tratador[t].tele,Animal[i].registo);
  }
}
