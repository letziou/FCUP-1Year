#include "stdio.h"
int main() {
  float a,b,c;
  printf("Insere dois números positivos !\n");
  scanf("%f %f" ,&a,&b);
    if(a>0 && b>0){
      printf("Indique o valor de %f+%f\n",a,b );
      scanf("%f",&c );
      if (a+b == c) {
      printf("Parabéns!! %f+%f é %f\n",a,b,a+b );
    }else printf("Errou !!%f+%f não é %f\n",a,b,c );
          printf("Tente outra vez !\n" );




  }else printf("Os dados não satisfazem o pedido !\n");
  return 0;
}
