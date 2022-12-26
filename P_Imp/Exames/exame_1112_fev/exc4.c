#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXD 9999

typedef struct{
  int ndisc;
  float media;
  double desvio;
}STATS;

void resultados_disc(int disc,int na,int dnotas[][MAXD]);
void carrega(int na,char nomes[][MAXD],int nd,int dnotas[][MAXD]);
int melhores_notas(int disc,int na,int dnotas[][MAXD],int ipos[]);
void estatisticas(int na,int nd,int dnotas[][MAXD],STATS stats[]);

STATS stats[6];

int main(int argc, char const *argv[]) {
  char nomes[100][MAXD];
  int  dnotas[100][MAXD];

  int ipos[MAXD]={-1,-1,-1,-1,-1,-1,-1};

  carrega(6,nomes,7,dnotas);
  // resultados_disc(0,6,dnotas);


  for(int i=0;i<7;i++){
    melhores_notas(i,6,dnotas,ipos);
    printf("Disciplina -> %d\n",i);
    for(int k=0;ipos[k]>-1;k++){
      printf("%s",nomes[ipos[k]]);
    }
  }

  return 0;
}

void resultados_disc(int disc,int na,int dnotas[][MAXD]){
  int contadores[]={0,0,0,0,0};
  char *Niveis[5] ={"Excelente","Muito Bom","Bom","Suficiente","Nao realizou"};

  for(int i=0;i<na;i++){
    if(dnotas[i][disc]>17)
      contadores[0]++;

    else if(dnotas[i][disc]>15 && dnotas[i][disc]<18)
      contadores[1]++;

    else if(dnotas[i][disc]>13 && dnotas[i][disc]<16)
      contadores[2]++;

    else if(dnotas[i][disc]<14 && dnotas[i][disc]>9)
      contadores[3]++;

    else contadores[4]++;
  }

  printf("           #Alunos\n");
  printf("------------------\n");
  for(int j=0;j<4;j++)
    printf("%-13s %d\n",Niveis[j],contadores[j]);

  printf("------------------\n");
  printf("%-13s %d\n",Niveis[4],contadores[4]);

}

int melhores_notas(int disc,int na,int dnotas[][MAXD],int ipos[]){
  int max=0,cont=0,k=0;
  for(int l=0;l<7;l++)
    ipos[l]=-1;

  for(int i=0;i<na;i++)
    if(dnotas[i][disc] > max)
      max = dnotas[i][disc];


  for(int j=0;j<na;j++){
    if(dnotas[j][disc]==max){
      cont++;
      ipos[k]=j;
      k++;
    }
  }

  return cont;
}

void carrega(int na,char nomes[][MAXD],int nd,int dnotas[][MAXD]){
  int j;
  for(int i=0;i<na;i++){
    for(j=0;(nomes[i][j] = getchar()) != '\n';j++){};
      j='\0';
    }
  for(int l=0;l<na;l++){
    for(int k=0;k<nd;k++){
      scanf("%d\n",&dnotas[l][k]);

    }
  }

}

void estatisticas(int na,int nd,int dnotas[][MAXD],STATS stats[]){
  int cont=0;
  float media=0;
  double quadmedia=0;
  for(int i=0;i<na;i++){
    for(int j=0;j<nd;j++){
      if(dnotas[i][j] != -1){
        cont++;
        media += dnotas[i][j];
      }
    }
    media /= cont;

    stats[i].ndisc = cont;
    stats[i].media = media;

    cont = 0;
    media = 0;
  }

  for(int l=0;l<na;l++){
    for(int k=0;k<nd;k++){
      quadmedia += (dnotas[l][k] -stats[l].media)*(dnotas[l][k] -stats[l].media);
    }
    quadmedia = sqrt(quadmedia);
    stats[l].desvio = quadmedia;
  }
}
