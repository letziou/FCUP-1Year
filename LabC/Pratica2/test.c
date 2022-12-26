#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decompor(int total, int *horas, int *min, int *seg);    // 2.6

int main(int argc, char *argv[]) {

  int total, *horas, *min, *seg;
  scanf("%d",&total);
  decompor(total,horas,min,seg);
  printf("%d == %ls %ls %ls\n",total,horas,min,seg);

  return 0;
}

void decompor(int total, int *horas, int *min, int *seg){
  int h=0, m=0, s;
  while(total >=3600){
    total -= 3600;
    h++;
  }
  while(total >= 60){
    total -= 60;
    m++;
  }
  s = total;
  horas = h;
  min = m;
  seg = s;
}
