#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAXDISC 100
#define MAXALUNOS 1000
#define MAXNOME 100
#define MAX 11
//#define LETRA(C) (((C) >= 'a'&& (C)<= 'z')|| ((C)>= 'A' && (C)<= 'Z'))

typedef struct aluno {
  char nome[MAXNOME], codigo[MAX];
  int disc[MAX], nd;
} ALUNO;

typedef struct disciplina {
  char nome[MAXNOME];
  int ano;
} DISCIPLINA;


#include "dados.h"

// --------------------   Protótipos ---------------------------------------
int numero_medio(char curso[]);
// retorna número médio de disciplinas a que os alunos de um curso estão inscritos (arrendondado por defeito)

void disciplinas_de_Aluno(char codigoAluno[]);
// escreve a lista de disciplinas a que um aluno está inscrito

bool aluno_do_curso(char codigo[],char curso[]);
// verifica se o codigo dado é de um aluno do curso dado

int id_disciplina(char nomeDisc[]);
// retorna id de uma disciplina indicada (id = (1+índice no vector Disc) )
// ou -1 se não existir

int alunos_de_disciplina(char disciplina[], int indices[]);
// obtem índices das fichas dos alunos que estão inscritos à disciplina
// indicada e retorna o número de alunos nessas condições

void escr_disciplinas_mais_alunos(char curso[]);
// apresentar a lista de disciplinas que têm mais alunos dum dado curso.

// --------------------   Definição das funções ---------------------------
bool  aluno_do_curso(char codigo[],char curso[]){
  int i;
 
  for (i=0;i<3;i++)
    if (codigo[4+i] != curso[i]) 
      return false;

  return true;
}

int numero_medio(char curso[]) {
  int soma = 0, i, n = 0;

  for (i=0; i < NAlunos; i++) 
    if (aluno_do_curso(Alunos[i].codigo,curso)) {
      soma = soma + Alunos[i].nd;
      n++;
    }
  if (n == 0) return 0;
  return soma/n;
}

void disciplinas_de_Aluno(char codigoAluno[]) {
  int i,j;

  for(i=0; i<NAlunos; i++)
    if (strcmp(Alunos[i].codigo,codigoAluno)==0) { // ou usar my_strcmp implementada nas aulas
      printf("%s inscrito a:\n\n",Alunos[i].nome);
      for (j=0; j<Alunos[i].nd; j++) 
        //  int d = Alunos[i].disc[j]   -  1; 
	printf("%s\n",Disc[Alunos[i].disc[j]-1].nome);
      break;  // interrompe ciclo for
    }
}

int id_disciplina(char nomeDisc[]) {
  int j;
  for (j=0; j<NDisc; j++)
    if (strcmp(Disc[j].nome,nomeDisc)==0)
      return j+1;
  return -1;
}

int alunos_de_disciplina(char disciplina[], int indices[]){
  int i, na = 0, id, j;
  id = id_disciplina(disciplina);
  if (id != -1) 
    for (i=0; i<NAlunos; i++) 
      for (j=0; j < Alunos[i].nd; j++)
	if (Alunos[i].disc[j] == id) {
	  indices[na] = i;
	  na++;
	}
  return na;
}

void escr_disciplinas_mais_alunos(char curso[]){
  int contadores[MAXDISC+1] = {0}, maximo = 0, i, j, n;
  
  for(i=0; i<NAlunos; i++) 
    if (aluno_do_curso(Alunos[i].codigo,curso)) 
      for (j=0; j < Alunos[i].nd; j++) {
	contadores[Alunos[i].disc[j]]++;
	if (contadores[Alunos[i].disc[j]] > maximo)
	  maximo = contadores[Alunos[i].disc[j]];
      }

  if (maximo == 0) return;   // em alternativa, dar msg de erro

  printf("Disciplinas com mais alunos do curso %s\n\n",curso);
  n= 0;
  for(j=1; j <= NDisc; j++) 
    if (contadores[j] == maximo) {
      printf("%s\n",Disc[j-1].nome);
      n++;
    }
  printf("\nTotal = %d Maximo = %d\n",n,maximo);
}


//---------------------------- Exemplos de utilização ---------------------
void print_linha(char c,int n);

int main() {

  print_linha('*',30);

  escr_disciplinas_mais_alunos("018");

  print_linha('*',30);

  char codigo[MAX];
  printf("Indicar codigo de aluno: ");
  scanf("%s",codigo);
  disciplinas_de_Aluno(codigo);

  print_linha('*',30);

  int posicaoAlunos[NAlunos], na;
  na = alunos_de_disciplina("Programacao Imperativa",posicaoAlunos);
  printf("Numero de inscritos a Programacao Imperativa: %d\n",na);

  return 0;
}
  
void print_linha(char c, int n) {
  putchar(10);  putchar(10);
  while (n-- > 0) putchar(c);
  putchar(10);  putchar(10);
}
