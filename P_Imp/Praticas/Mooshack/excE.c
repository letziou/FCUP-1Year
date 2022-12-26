#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int n,verde=0,azul=0,amarelo=0;

  scanf("%d",&n);

  while(n!=-1){
    if(n<11 && n>0)
    azul++;
    if(n<41 && n>24)
    amarelo++;
    if(n<24 && n>10)
    verde++;

    scanf("%d",&n );
  }

  printf("Contentor azul: %d\nContentor amarelo: %d\nContentor verde: %d\n",azul,amarelo,verde );
  return 0;
}
