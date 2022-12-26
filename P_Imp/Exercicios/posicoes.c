#include <stdio.h>

void posicao(int a,int b,int c,int d){
  if(a<c){printf("esquerda ");}
  else printf("direita ");

  if(b<d) printf("abaixo\n");
  else printf("acima\n");

  if(a=c)printf("");
  if(b=d)printf("\n");
}

int main(){
  int a,b,c,d;
  scanf("%d %d %d %d",&a,&b,&c,&d);

  posicao(a,b,c,d);

  return 0;
}
