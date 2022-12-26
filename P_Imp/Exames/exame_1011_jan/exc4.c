#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 9999

void dados(int na,char nomes[][MAXN],int dnotas[][7]);
void nivelNota(int media,char nivel[]);

int main(int argc, char const *argv[]) {
  char nomes[4][MAXN];
  char nivel[MAXN];
  int dnotas[4][7];

  dados(4,nomes,dnotas);
  nivelNota(12,nivel);
  printf("%s<-\n",nivel);

  return 0;
}

void dados(int na,char nomes[][MAXN],int dnotas[][7]){
  int i,j;
  for(i=0;i<na;i++){
    for(j=0;(nomes[i][j] = getchar()) != '\n';j++){};
    nomes[i][j] = '\0';
    for(int k=0;k<5;k++){
      scanf("%d\n",&dnotas[i][k]);
      dnotas[i][5] += dnotas[i][k];
    }
  dnotas[i][5] = ((dnotas[i][5]/5)+0.5);
    for(int x=0;x<5;x++){
      dnotas[i][6] += ((dnotas[i][x]-dnotas[i][5])*(dnotas[i][x]-dnotas[i][5]));
    }
  }
}

void nivelNota(int media,char nivel[]){
  if(media>9 && media<14)
    nivel = "Suficiente";
  if(media>13 && media<17)
    nivel = "Bom";
  if(media>18)
    nivel = "Muito Bom";
}
