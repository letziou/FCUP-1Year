#include <stdio.h>
int main() {
  int a,b,c,max;

  scanf("%d %d %d",&a,&b,&c);

  max = a;

  if( b > a){
    max = b;

      if(c > b){max = c;}

  }else if(c > a){max = c;}

  printf("%d\n",max);

  return 0;

}
