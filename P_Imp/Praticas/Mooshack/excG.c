#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int numbers,first,second,next,cont=0;

  scanf("%d %d %d",&numbers,&first,&second);

  for(int i=0;i<numbers-2;i++){
    scanf("%d",&next);

    if(((next!=first && next!=second) && second%next==0) || ((next!=first && next!=second) && next>first))
      cont += next;
  }

  if(cont==0)
    printf("Resposta G - nenhum valor satisfaz\n");

  else printf("Resposta G - soma: %d\n",cont);
  return 0;
}
