#include "stdio.h"
int main() {
  int maior, menor, valor, novo;
  scanf("%d",&valor);
  scanf("%d",&novo );
    maior = 0;
    menor = 30;
    while (novo != 0){
      valor=novo;
      if (novo > maior){
        maior = novo;
      }else if (novo < menor ){
        menor = novo;
      }
      scanf("%d",&novo );
    }
      if ( maior == menor) {
        printf("Maior = Menor = %d \n",maior );
      } else {
        printf("Maior = %d e Menor = %d \n",maior, menor );
      }
    return 0;
}
