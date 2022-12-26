#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int idade_anos(int dnas,int dref);

int main(int argc, char const *argv[]) {

  int dnas,dref;
  scanf("%d %d",&dnas,&dref);
  int anos = idade_anos(dnas,dref);
  printf("%d\n",anos );

  return 0;
}

int idade_anos(int dnas,int dref){
   int ano1 = dnas/10000;
   int ano2 = dref/10000;
   int mes1 = (dnas%10000)/100;
   int mes2 = (dref%10000)/100;
   int dia1 = dnas%100;
   int dia2 = dref%100;

   if(mes1==mes2){
     if(dia1>dia2)
      return (ano2-ano1-1);
     else return(ano2-ano1);
   }

   else if(mes1>mes2) return(ano2-ano1-1);

   else return(ano2-ano1);
}
