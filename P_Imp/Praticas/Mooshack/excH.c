#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int a,b,cont=0,contmax=0;

  scanf("%d %d",&a,&b);
  while(a!=0 && b!=0){
    if(a==1 && b==1){
      cont++;
      while(a==1 && b==1){
        cont++;
        scanf("%d %d",&a,&b);
      }
      if(cont>contmax){
        contmax = cont;
        cont=0;
      }
    }
    if(a==1 && b==0){
      while(a==0){
        scanf("%d",&a);
      }
    }
    scanf("%d %d",&a,&b);
  }
  printf("%d\n",contmax);
  return 0;
}
