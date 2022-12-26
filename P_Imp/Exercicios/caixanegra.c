#include <stdio.h>
int main() {

int n,bits,soma,prim,segun;

scanf("%d %d %d",&n,&prim,&segun);

n = n-2;
soma = 0;

while (n != 0){
  scanf("%d",&bits);

    if(segun > 2*prim && segun > 2*bits){
      soma++;
    }

    prim = segun;
    segun = bits;
    n--;
}

printf("%d\n",soma);

  return 0;
}
