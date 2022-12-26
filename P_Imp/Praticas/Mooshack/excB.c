#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int ano,mes,dia,a,b,c,d,e,total;

  scanf("%d %d %d",&ano,&mes,&dia);

  a = ano/100;
  b = a/4;

  if((ano>=1582 && mes>=10 && dia>=15) || ano>=1583){
    c = 2-a+b;
  }
  else c = 0;

  d = (365.25*(ano+4716));
  e = (30.6001*(mes+1));

  total = d + e + dia + c - 1524;

  printf("total: %d\n",total);

  return 0;
}
