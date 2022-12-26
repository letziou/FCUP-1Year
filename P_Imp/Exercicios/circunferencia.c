#include "stdio.h"
int main() {
  int c,d,raio,x,y,n;

  printf("Indique onde está o centro da sua circunferência .\n" );
  scanf("%d %d",&c,&d);
  printf("Qual é o raio da sua circunferência ?\n");
  scanf("%d",&raio );
  printf("Indique quantos e as coordendas dos seus pontos. \n" );
      scanf("%d",&n );
      while ( n !=0){

        scanf("%d %d",&x,&y );
        if( (c-x)*(c-x)+(d-y)*(d-y) < raio*raio  ){
          printf("(%d,%d): no interior \n",x,y );
        }else if( (c-x)*(c-x)+(d-y)*(d-y) == raio*raio ){
          printf("(%d,%d): na fronteira\n" ,x,y);
        }else printf("(%d,%d): no exterior\n" ,x,y);

        n = n-1;
      }





  return 0;
}
