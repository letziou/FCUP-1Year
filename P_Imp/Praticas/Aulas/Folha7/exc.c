#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAXDISC 100
#define MAXALUNOS 1000
#define MAXNOME 100
#define MAX 11

typedef struct aluno {
  char nome[MAXNOME], codigo[MAX];
  int disc[MAX], nd;
} ALUNO;


typedef struct disciplina {
  char nome[MAXNOME];
  int ano;
} DISCIPLINA;

#include "dados.h"

void nome(char nome[]);
void procura(char palavranome[]);
int codigo2Aluno(char codigo[]);
int disciplinas_de_Aluno(char nome[]);
int alunos_de_disciplina(char disciplina[]);
int numero_medio(char curso[]);      
int muitas_disciplinas(char curso[],int n);
int numero_maximo(char cursoano[]);
int numero_disc(int posaluno,int ano);
int varios_anos(int posaluno);

int main(int argc, char const *argv[]) {
  char x[MAXNOME];
  nome(x);

  int j = alunos_de_disciplina(x);
  printf("%s\n",x );
  return 0;
}

void nome(char nome[]){
  int i;
  for(i=0; (nome[i]= getchar()) != '\n';i++){};
    nome[i] = '\0';

}

void procura(char palavranome[]){
  printf("Alunos cujo nome inclui %s\n\n",palavranome );
  for(int i=0;i<NAlunos;i++){
    if(strstr(Aluno[i].nome,palavranome) != NULL)
      printf("%s %s\n",Aluno[i].codigo,Aluno[i].nome);
  }
}

int codigo2Aluno(char codigo[]){
  for(int i=0;i<NAlunos;i++){
    if(strcmp(Aluno[i].codigo,codigo)==0)
      return 1;
  }
  return 0;
}

int disciplinas_de_Aluno(char nome[]){
  for(int i=0;i<NAlunos;i++){
    if(strcmp(Aluno[i].nome,nome)==0){
      printf("%s está inscrito a:\n\n",Aluno[i].nome);
      for(int j=0;j<Aluno[i].nd;j++){
        printf("%s\n",Disc[Aluno[i].disc[j]-1].nome);
      }
      return Aluno[i].nd;
    }
  }
  return -1;
}

int alunos_de_disciplina(char disciplina[]){
  int number,cont=0;
  for(int a=0;a<NDisc;a++){
    if(strcmp(disciplina,Disc[a].nome)==0)
      number = a+1;
  }
  if(number!=0) printf("Os alunos que estão inscritos em %s são:\n",disciplina);
  for(int i=0;i<NAlunos;i++){
    for(int j=0;j<Aluno[i].nd;j++){
      if(Aluno[i].disc[j]==number){
        printf("%s\n",Aluno[i].nome);
        cont++;
      }
    }
  }
  printf("\n");
  return cont;
}

int numero_medio(char curso[]){
  float cont = 0;
  int contpessoas = 0;
  for(int i=0;i<NAlunos;i++){
    if(strstr(Aluno[i].codigo,curso) != NULL){
      cont += Aluno[i].nd;
      contpessoas++;
    }
  }
  cont /= contpessoas;
  cont = (int)cont;
  return cont;
}

int muitas_disciplinas(char curso[],int n){
  int cont=0;
  for(int i=0;i<NAlunos;i++){
    if(Aluno[i].nd > n && (strstr(Aluno[i].codigo,curso) != NULL)){
      cont++;
      printf("%s\n",Aluno[i].nome);
    }
  }
  return cont;
}

int numero_maximo(char cursoano[]){
  int contmax = 0;
  for(int i=0;i<NAlunos;i++){
    if(strstr(Aluno[i].codigo,cursoano) != NULL)
      if(contmax<Aluno[i].nd)
        contmax = Aluno[i].nd;
  }
  return contmax;
}

int numero_disc(int posaluno,int ano){
  int cont = 0;
  for(int i=0;i<Aluno[posaluno].nd;i++){
    if(Disc[Aluno[posaluno].disc[i]-1].ano == ano){
      cont++;
      printf("%s\n",Disc[Aluno[posaluno].disc[i]-1].nome );
      }
    }
  return cont;
}

int varios_anos(int posaluno){
  int cont;
  cont = Disc[Aluno[posaluno].disc[0]].ano;
  for(int i=1;i<Aluno[posaluno].nd;i++){
    if(Disc[Aluno[posaluno].disc[i]-1].ano != cont)
      return 1;
  }
  return 0;
}
