#include <stdio.h>
int main() {

int valor,n,soma,diff,ult;

soma = 0;

scanf("%d %d",&valor,&n);

  while(n != 0){
    if(n > valor){
      soma = soma + n;
      ult = n;
    }else ult = n;
    scanf("%d",&n);
  }

  if(soma != 0){
    printf("%d\n",soma);
  }else{

  diff = valor%ult;

  if(diff == 0){
    printf("%d multiplo de %d\n",valor,ult);
  }else printf("%d nao multiplo de %d\n",valor,ult);

}
  return 0;
}
