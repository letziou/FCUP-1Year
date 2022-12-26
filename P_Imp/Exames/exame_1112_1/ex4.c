#include <stdio.h>

int main(){

  int times;
  scanf("%d",&times);

  while(times > 0){
    int n;
    scanf("%d",&n);
    int number = n;
    int first = 0;
    int second = 0;
    int pos = 2;
    while(n!=-1){
      scanf("%d",&n);
      if((n < number) && (n%2!=0) && (first!=0) && (second==0) && (n!=-1))
        second = pos;
      if((n < number) && (n%2!=0) && (first==0) && (n!=-1))
        first = pos;
      pos++;
    }

    if(first==0 && second==0)
      printf("* *\n");
    if(first!=0 && second==0)
      printf("%d *\n",first);
    if(first!=0 && second!=0)
      printf("%d %d\n",first,second);

    times--;
  }
  return 0;
}
