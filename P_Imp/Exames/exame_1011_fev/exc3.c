#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCH 9999
#define MAXEQ 9999

// anunciado muito mal executado :( 

void leResults(int ne,char equipas[][MAXCH],int res[][MAXEQ]);
int pontosGanhos(int ne,int ieq,int res[][MAXEQ],int Casa);

int main(int argc, char const *argv[]) {
  char equipas[5][MAXCH];
  int res[5][MAXEQ];
  leResults(5,equipas,res);
  return 0;
}

void leResults(int ne,char equipas[][MAXCH],int res[][MAXEQ]){
  int middle = 0;
  int q;
  for(int i=0;i<ne;i++){
    for(q=0; (equipas[i][q] = getchar()) != '\n';q++){};
    equipas[i][q] = '\0';
    for(int j=0;j<ne;j++){
      if(j==middle){
        res[i][j] = 0;
      }
      else scanf("%d\n",&res[i][j]);
    }
    middle++;
  }
}

int pontosGanhos(int ne,int ieq,int res[][MAXEQ],int Casa){

}
