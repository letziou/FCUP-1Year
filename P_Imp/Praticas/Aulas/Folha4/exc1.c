#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

void ler_seq(int x[],int n);
void escrever_seq(int x[],int n);
void copiar(int y[],int x[],int n);
int media_arred(int x[],int n);

int main(int argc, char const *argv[]) {

  int atual[MAX],maximo[MAX];
  int arrays,numbers,media,mediamax=0;
  scanf("%d %d",&arrays,&numbers);
  for(int i=0;i<arrays;i++){
    ler_seq(atual,numbers);
    media = media_arred(atual,numbers);
    if(media>mediamax){
      copiar(maximo,atual,numbers);
      mediamax = media;
    }
  }
  escrever_seq(maximo,numbers);
  printf("Media = %d\n",mediamax);
  return 0;
}

void ler_seq(int x[],int n){
  for(int i=0;i<n;i++)
    scanf("%d",&x[i]);
}

void escrever_seq(int x[],int n){
  printf("%d,",x[0]);
  for(int i=1;i<n-1;i++)
    printf("%d,",x[i]);
  printf("%d\n",x[n-1]);
}

void copiar(int y[],int x[],int n){
  for(int i=0;i<n;i++)
    y[i] = x[i];
}

int media_arred(int x[],int n){
  float cont=0;

  for(int i=0;i<n;i++)
    cont += x[i];

  cont /= n;
  cont += 0.5;
  cont = (int)cont;
  return cont;
}
