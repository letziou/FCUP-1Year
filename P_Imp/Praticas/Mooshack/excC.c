#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

  int horas,a,b,c,d,start,end,diff;

  scanf("%d %d %d %d %d",&horas,&a,&b,&c,&d);

  if(b <= c){
    printf("Impossivel\n");
    exit(0);
  }

  if(a < c) start = c;
  else start = a;

  if(b < d) end = b;
  else end = d;

  diff = end - start;

  if(diff==horas){
    printf("%d\n",start);
    exit(0);
  }

  printf("%d %d\n",start,end-horas);



  return 0;
}
