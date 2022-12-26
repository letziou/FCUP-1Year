#include <stdio.h>

#define CMAX 251

int ler_seq(int x[]){

  int i,valor;

  scanf("%d",&valor);
  for(i=0;valor != 0;i++){
  x[i] = valor;
  scanf("%d",&valor);
}
return i;
}

int main() {
  int x[CMAX],i,n,alvo,cont=0,contmenos=0;

  int comprimento = ler_seq(x);

  scanf("%d",&n);
  scanf("%d",&alvo);
    while (n != 0){

      for(i=0;i<comprimento;i++){

        if(alvo%x[i] == 0){
          cont++;
          if(x[i]<0){
            contmenos++;
        }
      }
    }

      printf("Resp: Numero de divisores de %d na sequencia = %d\n",alvo,cont);
      printf("      Numero dos negativos = %d\n",contmenos);






      scanf("%d",&alvo);
      cont = 0;
      contmenos = 0;
      n--;
    }
    return 0 ;
}
