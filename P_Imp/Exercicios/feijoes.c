#include <stdio.h>

int ler_seq(int x[], int m){

  int i,valor;

  for(i=0;i<m;i++){
  scanf("%d",&valor);
  x[i] = valor;
}
  return i;
}


int main() {

  int m,a,b,valor,k,l,cont;
  scanf("%d",&m);
  int x[m];

l = m-1;
a = 0;
b = 0;
k = 0;
cont = 0;
  int comprimento = ler_seq(x,m);

  while(valor != comprimento){
    if(valor%2 ==0){
          if(x[k]>x[l]){
            a += x[k];
            k++;
          }else{
          a += x[l];
          l--;
        }
    }else if(valor%2 !=0 && cont%2 == 0){
      if(x[k]<x[l]){
        b += x[k];
        k++;
      }else{
        b += x[l];
        l--;
      }
      cont ++;
    }else if(valor%2 !=0 && cont%2 != 0){
      if(x[k]>x[l]){
        b += x[k];
        k++;
      }else{
      b += x[l];
      l--;
      }
      cont++;
    }
    valor++;
  }
  if( a > b)printf("Alex ganha com %d contra %d\n",a,b);
  if( a < b)printf("Bela ganha com %d contra %d\n",b,a);
  if( a == b)printf("Alex e Bela empatam a %d\n",a);

  return 0;
}
