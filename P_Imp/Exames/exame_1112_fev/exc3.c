#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  int xcasa,ycasa,xpp,ypp,xdd,ydd,xmov,ymov;
  int cont = 0;

  scanf("%d %d",&xcasa,&ycasa);
  scanf("%d %d",&xpp,&ypp);
  scanf("%d %d",&xdd,&ydd);

  xmov = xpp;
  ymov = ypp;

  if(xcasa==xpp && ycasa==ypp)
    cont++;

  while((xdd!=0) || (ydd!=0)){
    xmov += xdd;
    ymov += ydd;
    printf("%d %d\n",xmov,ymov );

    if(xmov==xcasa && ymov==ycasa)
      cont++;

    scanf("%d %d",&xdd,&ydd);
  }

  printf("#vezes empresa: %d\n",cont);

  if(xmov==xpp && ymov==ypp){
    printf("Terminou no local de partida\n");
  }

  else printf("Terminou em (%d,%d)\n",xmov,ymov);

  return 0;
}
