#include <stdio.h>
#include <stdlib.h>

int troca(int vmoeda[],int dmoeda[],int n,int q);

int main(int argc, char const *argv[]) {
  int moedas[] = {200,100,50,20,10,5,2,1};
  int nmoedas[8];
  int valor;

  for(int i=0;i<8;i++)
    scanf("%d",&nmoedas[i]);

  scanf("%d",&valor);
  printf("%d\n",troca(moedas,nmoedas,8,valor));
  return 0;
}

int troca(int vmoeda[],int dmoeda[],int n,int q){
  int aux;

  for(int i=0;i<n && q>0;i++){
      aux = q/vmoeda[i];

      if(dmoeda[i]<aux)
        aux = dmoeda[i];

      q = q - aux*vmoeda[i];
  }
  return q;
}
