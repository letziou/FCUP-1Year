#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX 9999

int multi(int x,int times);

int main(int argc, char const *argv[]) {
  int x,m,n;

  scanf("%d %d %d",&x,&m,&n);
  printf(" k  x^k\n");
  printf("--------\n");
  for(int i=m;i<(n+1);i++){
    int j = multi(x,i);
    printf("%2d  %d\n",i,j);
  }
  return 0;
}

int multi(int x,int times){
  int cont = x;
  for(int i=1;i<times;i++){
    cont *= x;
  }
  return cont;
}
