#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX 9999

int ler_nome(char nome[]);
int compara_nomes(char x[],char y[]);

int main(int argc,char *argv[]) {

  int j = compara_nomes("O","a");
  printf("%d\n",j);
  return 0;
}

int ler_nome(char nome[]){
  int i;
  for(i=0; (nome[i] = getchar()) != '\n';i++){};
  nome[i] = '\0';

  for(int j=0;j<i;j++){
    if(nome[j]==' ' && nome[j+1]==' ')
      return 0;
  }
  return 1;
}

int compara_nomes(char x[],char y[]){
  for(int i=0;x[i]=='\0'||y[i]=='\0';i++){
    if((x[i]>'a') && (x[i]<'z')){
      x[i] -= 'a';printf("a\n");}
    else {x[i] -= 'A';printf("A\n");}

    if(x[i]<y[i])
      return -1;
    if(x[i]>y[i])
      return 1;
  }
  return 0;
}
