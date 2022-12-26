#include <stdio.h>

void divisores(int n){

int d;

printf("1 %d\n",n);
for (d = 2; d <= n/2; d++)
  if(n % d == 0)
    printf("%d %d\n",d, n/d);
}

int main() {
int n;
scanf("%d",&n);
divisores(n);

return 0;



}
