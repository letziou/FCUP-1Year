#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int h1,m1,h2,m2,diff;

  scanf("%d %d %d %d",&h1,&m1,&h2,&m2);

  while(h1!=0){
    m1 += +60;
    h1--;
  }

  while(h2!=0){
    m2 += +60;
    h2--;
  }

  diff = m2-m1;
  printf("Passaram apenas %d minutos!\n",diff );

  if(diff < 60){
    printf("De facto!\n");
    exit(0);
  }

  while(diff>59){
    h1++;
    diff -= 60;
  }
  if(h1==1 && diff==0)
    printf("Queres dizer, 1 hora?!\n");

  if(h1==1 && diff==1)
    printf("Queres dizer, 1 hora e 1 minuto?!\n");

  if(h1!=1 && diff==0)
    printf("Queres dizer, %d horas?!\n",h1);

  if(h1!=1 && diff==1)
    printf("Queres dizer, %d horas e 1 minuto?!\n",h1);

  if(h1==1 && diff>1)
    printf("Queres dizer, 1 hora e %d minutos?!\n",diff);

  if(h1!=1 && diff>1)
    printf("Queres dizer, %d horas e %d minutos\n",h1,diff);

  return 0;
}
