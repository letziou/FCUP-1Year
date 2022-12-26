#include <stdio.h>

int main(int argc, char const *argv[]) {
  int first, new, count = 0, ult;

  scanf("%d %d",&first,&new);

  while(new != 0) {
    if(new > first) count += new;
    ult = new;
    scanf("%d",&new);
  }

  if(count != 0) printf("%d\n",count);
  else if(first%ult==0) printf("%d multiplo de %d\n",first,ult);
  else printf("%d nao multiplo de %d\n",first,ult);

  return 0;
}
