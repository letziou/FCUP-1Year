#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int first,last,next,cont=0;

  scanf("%d %d",&first,&next);

  while(next != 0){
    if(next > first){
      cont += next;
      last = next;
    }else last = next;
    scanf("%d",&next);
  }

  if(cont != 0)
    printf("%d\n",cont);

  else if(first%last==0)
    printf("%d multiplo de %d\n",first,last);

  else printf("%d nao multiplo de %d\n",first,last);

  return 0;
}
