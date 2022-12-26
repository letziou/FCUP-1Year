#include "stdio.h"
int main() {
  int a,b,c;
  printf("Insira três números positivos\n" );
  scanf("%d %d %d",&a,&b,&c );
    if ( a>0 && b>0 && c>0) {
      if (b^2-4*a*c > 0){
        printf("A equação tem duas raízes distintas! \n");
      }else if (b^2-4*a*c == 0){
        printf("A equação tem uma raiz dupla!\n" );
      }else printf("A equação não tem raizes!\n" );
    }else printf("Os números são inválidos !\n" );

  return 0;
}
