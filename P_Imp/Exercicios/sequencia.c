#include <stdio.h>

void ler_seq(int x[],int n){

int valor,i;

  for(i=0;i<n;i++){
    scanf("%d",&valor);
    x[i] = valor;
}
}

void escrever_seq(int y[],int n){
  int i;
  printf("%d",y[0]);

  for(i=1;i<n;i++)
      printf(" %d",y[i]);
}

void copiar(int y[],int x[],int n){
  int i;
  for(i=0;i<n;i++)
    y[i] = x[i];
}

int media_arred(int x[],int n){
  int soma,i;
  soma = 0.0;
  for(i=0;i<n;i++){
    soma += x[i];
  }
    soma = soma/n;
    soma = soma + 0.5;

  return soma;
}

int main(){

int m,n,mediamax,media;
int x[n],y[n];
  mediamax = 0;

  scanf("%d %d",&m,&n);

  while (m != 0){

    ler_seq(x,n);
    media = media_arred(x,n);

    if(media > mediamax){
      mediamax = media;
      copiar(y,x,n);
    }

    m--;
  }

  escrever_seq(y,n);
  printf("\nMedia = %d\n",mediamax);

  return 0;
}
