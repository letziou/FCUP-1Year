#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX 9999

int lerLinha(char lin[]);
int posicao(char lin[],char c);
char analisaLinha(char lin[]);

int main(int argc, char const *argv[]) {
  char x[NMAX];
  lerLinha(x);
  char i = analisaLinha(x);
  printf("%c\n",i );
  return 0;
}

int lerLinha(char lin[]){
  int i;
  for(i=0;(lin[i] = getchar()) != '\n';i++){};
    lin[i] = '\0';
  return i;
}

int posicao(char lin[],char c){
  int cont=0,pos;
  for(int i=0;i<strlen(lin);i++){
    if(lin[i]==c){
    cont++;
    pos = i;
  }
  }
  if(cont==1)
    return pos;
  return -1;
}

char analisaLinha(char lin[]){
  int cont,contesq = 0,contdir = 0;
  char contesqu[NMAX],contdire[NMAX];

  cont = posicao(lin,':');
  if(cont==-1) return 'N';

  for(int i=0;i<cont;i++){
    contesqu[i] = lin[i];
    contesq++;
  }

  for(int j=cont+1;j<strlen(lin);j++){
    contdire[j-cont-1] = lin[j];
    contdir++;
  }

  if(contdir>contesq) return 'D';
  if(contdir<contesq) return 'E';
  if(contdir==contesq && (strcmp(contdire,contesqu)==0)) return 'I';
  return 'C';
}
