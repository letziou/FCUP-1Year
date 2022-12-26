#include "stdio.h"
int main() {
  int n,r,numero,contador,soma;

contador = 0;
soma = 0;
r = 0;
  scanf("%d",&n);

    while ( n != 0 ){

      scanf("%d",&numero);

      if ( numero%2 == 0 && numero%3 ==0 ){
        contador = contador;
        soma = soma;
      } else if( numero%2 == 0 ) {
        contador = contador+1;
      }else if ( numero%3 ==0){
        soma = soma+1;
      }
      n = n-1;
    }
    r == soma + contador;
    printf ("Número de múltiplos ou de 2 ou de 3 = %d",r);

    return 0;

}
